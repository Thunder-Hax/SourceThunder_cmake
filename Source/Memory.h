#ifndef __MEMORY_H__
#define __MEMORY_H__

#pragma once

// from boost libraries
template <uint64_t FnvPrime, uint64_t OffsetBasis>
struct basic_fnv_1 {

	uint64_t operator()( std::string const& text ) const {

		uint64_t hash = OffsetBasis;
		for ( std::string::const_iterator it = text.begin(), end = text.end(); it != end; ++it ) {

			hash *= FnvPrime;
			hash ^= *it;
		}

		return hash;
	}
};

const uint64_t fnv_prime = 1099511628211u;
const uint64_t fnv_offset_basis = 14695981039346656037u;

typedef basic_fnv_1<fnv_prime, fnv_offset_basis> fnv_1;

namespace Memory {

	void TransformPattern( const std::string & pattern, std::string & data, std::string & mask );

	class executable_meta {
	private:

		uintptr_t	m_begin;
		uintptr_t	m_end;
		DWORD		m_size;
	public:

		executable_meta()
			: m_begin( 0 ), m_end( 0 ) {
		}

		void EnsureInit();

		inline uintptr_t begin() { return m_begin; }
		inline uintptr_t end() { return m_end; }
		inline DWORD size() { return m_size; }
	};

	class pattern_match {
	private:

		void * m_pointer;

	public:

		inline pattern_match( void * pointer ) {

			m_pointer = pointer;
		}

		template<typename T>
		T * get( int offset ) {

			if ( m_pointer == nullptr ) {
				return nullptr;
			}

			char * ptr = reinterpret_cast<char*>( m_pointer );
			return reinterpret_cast<T*>( ptr + offset );
		}

		template<typename T>
		T * get() {

			return get<T>( 0 );
		}
	};

	typedef std::vector<pattern_match> matchVec;

	class pattern {
	private:

		std::string			m_bytes;
		std::string			m_mask;

		uint64_t			m_hash;

		size_t				m_size;

		matchVec			m_matches;

		bool				m_matched;

	private:

		void Initialize( const char* pattern, size_t length );

		bool ConsiderMatch( uintptr_t offset );

		void EnsureMatches( int maxCount );

	public:
		void* ptr;
		template <typename T>
		inline std::enable_if_t<std::is_pointer_v<T>, T> as()
		{
			return static_cast<T>(ptr);
		}

		template<size_t Len>
		pattern( const char( &pattern )[Len] ) {

			Initialize( pattern, Len );
		}

		inline pattern & count( int expected ) {

			if ( !m_matched ) {
				EnsureMatches( expected );
			}

			return *this;
		}

		inline size_t size() {

			if ( !m_matched ) {
				EnsureMatches( INT_MAX );
			}

			return m_matches.size();
		}

		inline pattern_match & get( int index ) {

			if ( !m_matched ) {
				EnsureMatches( INT_MAX );
			}

			if ( m_matches.size() == 0 ) {

				m_matches.push_back( pattern_match( nullptr ) );
				return m_matches[0];
			}

			return m_matches[index];
		}

	public:
		// define a hint
		static void hint( uint64_t hash, uintptr_t address );
	};

	// for link /DYNAMICBASE executables
	static ptrdiff_t baseAddressDifference;

	// sets the base address difference based on an obtained pointer
	inline void set_base(uintptr_t address)
	{
#ifdef _M_IX86
		uintptr_t addressDiff = (address - 0x400000);
#elif defined(_M_AMD64)
		uintptr_t addressDiff = (address - 0x140000000);
#endif

		// pointer-style cast to ensure unsigned overflow ends up copied directly into a signed value
		baseAddressDifference = *(ptrdiff_t*)&addressDiff;
	}

	// gets the main base of the process
	uintptr_t get_base();
	DWORD get_size();
	// gets the main base of the process with Offset
	uintptr_t get_base_offsetted(DWORD offset);
	
	// gets a multilayer pointer address
	uintptr_t get_multilayer_pointer(uintptr_t base_address, std::vector<DWORD> offsets);

	// sets the base to the process main base
	inline void set_base()
	{
		set_base((uintptr_t)GetModuleHandle(NULL));
	}

	// adjusts the address passed to the base as set above
	template<typename T>
	inline void adjust_base(T& address)
	{
		*(uintptr_t*)&address += baseAddressDifference;
	}

	// returns the adjusted address to the stated base
	template<typename T>
	inline uintptr_t get_adjusted(T address)
	{
		return (uintptr_t)address + baseAddressDifference;
	}

	template<typename ValueType, typename AddressType>
	inline void put(AddressType address, ValueType value)
	{
		adjust_base(address);

		memcpy((void*)address, &value, sizeof(value));
	}

	template<typename ValueType, typename AddressType>
	inline void putVP(AddressType address, ValueType value)
	{
		adjust_base(address);

		DWORD oldProtect;
		VirtualProtect((void*)address, sizeof(value), PAGE_EXECUTE_READWRITE, &oldProtect);

		memcpy((void*)address, &value, sizeof(value));

		VirtualProtect((void*)address, sizeof(value), oldProtect, &oldProtect);
	}

	template<typename AddressType>
	inline void nop(AddressType address, size_t length)
	{
		adjust_base(address);

		memset((void*)address, 0x90, length);
	}

	template<typename AddressType>
	inline void return_function(AddressType address, uint16_t stackSize = 0)
	{
		if (stackSize == 0)
		{
			put<uint8_t>(address, 0xC3);
		}
		else
		{
			put<uint8_t>(address, 0xC2);
			put<uint16_t>((uintptr_t)address + 1, stackSize);
		}
	}

	template<typename T>
	inline T* getRVA(uintptr_t rva)
	{
#ifdef _M_IX86
		return (T*)(baseAddressDifference + 0x400000 + rva);
#elif defined(_M_AMD64)
		return (T*)(0x140000000 + rva);
#endif
	}

	template<typename T, typename AT>
	inline void jump(AT address, T func)
	{
		put<uint8_t>(address, 0xE9);
		put<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
	}

	template<typename T, typename AT>
	inline void call(AT address, T func)
	{
		put<uint8_t>(address, 0xE8);
		put<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
	}

	template<typename T>
	inline T get_call(T address)
	{
		intptr_t target = *(uintptr_t*)(get_adjusted(address) + 1);
		target += (get_adjusted(address) + 5);

		return (T)target;
	}

	template<typename TTarget, typename T>
	inline void set_call(TTarget* target, T address)
	{
		*(T*)target = get_call(address);
	}

	namespace vp
	{
		template<typename T, typename AT>
		inline void jump(AT address, T func)
		{
			putVP<uint8_t>(address, 0xE9);
			putVP<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
		}

		template<typename T, typename AT>
		inline void call(AT address, T func)
		{
			putVP<uint8_t>(address, 0xE8);
			putVP<int>((uintptr_t)address + 1, (intptr_t)func - (intptr_t)get_adjusted(address) - 5);
		}
	}

	std::vector<DWORD64> get_string_addresses(std::string str);

	template <typename T>
	T get_value(std::vector<DWORD> offsets) {

		uintptr_t Addr = get_multilayer_pointer(Hooking::getWorldPtr(), offsets);
		if (Addr == NULL) {
			return NULL;
		}

		return *((T*)Addr);
	}

	template <typename T>
	void set_value(std::vector<DWORD> offsets, T value) {
		uintptr_t Addr = get_multilayer_pointer(Hooking::getWorldPtr(), offsets);
		if (Addr == NULL) {
			return;
		}

		*reinterpret_cast<T*>(Addr) = value;
	}

}
#endif // __MEMORY_H__

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace memory2
{
	class handle
	{
	public:
		handle(void* ptr = nullptr);
		explicit handle(std::uintptr_t ptr);

		template <typename T>
		std::enable_if_t<std::is_pointer_v<T>, T> as();

		template <typename T>
		std::enable_if_t<std::is_lvalue_reference_v<T>, T> as();

		template <typename T>
		std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> as();

		template <typename T>
		handle add(T offset);

		template <typename T>
		handle sub(T offset);

		handle rip();

		explicit operator bool();

		friend bool operator==(handle a, handle b);
		friend bool operator!=(handle a, handle b);
	private:
		void* ptr;
	};

	inline handle::handle(void* ptr) :
		ptr(ptr)
	{}

	inline handle::handle(std::uintptr_t ptr) :
		ptr(reinterpret_cast<void*>(ptr))
	{}

	template <typename T>
	inline std::enable_if_t<std::is_pointer_v<T>, T> handle::as()
	{
		return static_cast<T>(ptr);
	}

	template <typename T>
	inline std::enable_if_t<std::is_lvalue_reference_v<T>, T> handle::as()
	{
		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(ptr);
	}

	template <typename T>
	inline std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> handle::as()
	{
		return reinterpret_cast<std::uintptr_t>(ptr);
	}

	template <typename T>
	inline handle handle::add(T offset)
	{
		return handle(as<std::uintptr_t>() + offset);
	}

	template <typename T>
	inline handle handle::sub(T offset)
	{
		return handle(as<std::uintptr_t>() - offset);
	}

	inline handle handle::rip()
	{
		return add(as<std::int32_t&>()).add(4);
	}

	inline bool operator==(handle a, handle b)
	{
		return a.ptr == b.ptr;
	}

	inline bool operator!=(handle a, handle b)
	{
		return a.ptr != b.ptr;
	}

	inline handle::operator bool()
	{
		return ptr != nullptr;
	}
}

class VirtualRegion
{
public:
	VirtualRegion(BYTE* base, std::size_t size, BYTE* pointer) :
		m_Size(size), m_Pointer(pointer), m_Base(base) {}

	BYTE* Pointer() const { return m_Pointer; }
	BYTE* Base() const { return m_Base; }
	BYTE* End() const { return m_Base + m_Size; }

protected:
	std::size_t m_Size{};
	BYTE* m_Pointer{};
	BYTE* m_Base{};
};



//namespace unique
//{
///*inline */static std::unique_ptr<GameFunctions> g_GameFunctions;
//}


//class Signature
//{
//public:
//	struct Element
//	{
//		std::uint8_t m_Data{};
//		bool m_Wildcard{};
//	};
//
//	explicit Signature(const char* pattern)
//	{
//		auto toUpper = [](char c) -> char
//		{
//			return c >= 'a' && c <= 'z' ? static_cast<char>(c + ('A' - 'a')) : static_cast<char>(c);
//		};
//
//		auto isHex = [&](char c) -> bool
//		{
//			switch (toUpper(c))
//			{
//			case '0':
//			case '1':
//			case '2':
//			case '3':
//			case '4':
//			case '5':
//			case '6':
//			case '7':
//			case '8':
//			case '9':
//			case 'A':
//			case 'B':
//			case 'C':
//			case 'D':
//			case 'E':
//			case 'F':
//				return true;
//			default:
//				return false;
//			}
//		};
//
//		do
//		{
//			if (*pattern == ' ')
//				continue;
//			if (*pattern == '?')
//			{
//				m_Elements.push_back(Element{ {}, true });
//				continue;
//			}
//
//			if (*(pattern + 1) && isHex(*pattern) && isHex(*(pattern + 1)))
//			{
//				char str[3] = { *pattern, *(pattern + 1), '\0' };
//				auto data = std::strtol(str, nullptr, 16);
//
//				m_Elements.push_back(Element{ static_cast<std::uint8_t>(data), false });
//			}
//		} while (*(pattern++));
//	}
//	VirtualRegion VirtualScan(BYTE* startAddress = nullptr)
//	{
//		auto compareMemory = [](const std::uint8_t* data, Element* elem, std::size_t num) -> bool
//		{
//			for (std::size_t i = 0; i < num; ++i)
//				if (!elem[i].m_Wildcard)
//					if (data[i] != elem[i].m_Data)
//						return false;
//			return true;
//		};
//
//		MEMORY_BASIC_INFORMATION mbi{};
//		auto&& baseOffset = startAddress;
//
//		auto&& mask = PAGE_READWRITE;
//
//		while (VirtualQuery(baseOffset, &mbi, sizeof mbi) > 0)
//		{
//			if (mbi.State == MEM_COMMIT && mbi.Protect & mask && !(mbi.Protect & PAGE_GUARD))
//			{
//				auto start = baseOffset;
//				auto end = start + (mbi.RegionSize - m_Elements.size());
//
//				for (auto&& i = start; i < end; ++i)
//					if (compareMemory(i, m_Elements.data(), m_Elements.size()))
//						return VirtualRegion(baseOffset, mbi.RegionSize, i + 4);
//			}
//
//			baseOffset += mbi.RegionSize;
//			mbi = {};
//		}
//
//		return VirtualRegion(nullptr, 0, nullptr);
//	}
//	MemoryHandle Scan(MemoryRegion region = Module(nullptr))
//	{
//		auto compareMemory = [](std::uint8_t* data, Element* elem, std::size_t num) -> bool
//		{
//			for (std::size_t i = 0; i < num; ++i)
//			{
//				if (!elem[i].m_Wildcard)
//					if (data[i] != elem[i].m_Data)
//						return false;
//			}
//
//			return true;
//		};
//
//		for (std::uintptr_t i = region.Base().As<std::uintptr_t>(), end = region.End().As<std::uintptr_t>(); i != end; ++i)
//		{
//			if (compareMemory(reinterpret_cast<std::uint8_t*>(i), m_Elements.data(), m_Elements.size()))
//			{
//				return MemoryHandle(i);
//			}
//		}
//
//		return {};
//	}
//private:
//	std::vector<Element> m_Elements;
//};
