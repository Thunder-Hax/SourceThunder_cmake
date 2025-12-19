
#include "stdafx.h"

//#include <stdint.h>

#include <vector>
#include <optional>
#include <chrono>

#pragma once
//Disable Warings
#pragma warning(disable : 4996)
//Window Includes
#include <Windows.h>
#include <vadefs.h>
#include <stack>
#include <winsdkver.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#include <sdkddkver.h>
#include <winternl.h>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <Psapi.h>
#include <timeapi.h>
#include <time.h>
#include <xstring>
#include <functional>
#include <cassert>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <type_traits>
#pragma comment(lib, "ws2_32.lib")

#include <cstdint>
#include <ctime>
#include <cstring>

#include <cstdint>
#include <utility>
#include <array>

#ifndef __CROSS_MAPPING_H__
#define __CROSS_MAPPING_H__

#pragma once

typedef std::unordered_map<uint64_t, uint64_t> nMap;
static std::vector<uint64_t> nativeFailedVec;

struct CrossMappingEntry
{
	uint64_t first;
	uint64_t second;
};

class CrossMapping
{
public:
	static void initNativeMap();
	static uint64_t MapNative(uint64_t inNative);
	static void dumpNativeMappingCache();
	static bool searchMap(nMap map, uint64_t inNative, uint64_t *outNative);
};
















//#include "stdafx.h"
//#include <mmsystem.h>
//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <iterator>
//#include <sstream>
//
//#include "stdio.h"
//#include <map>
//
//#pragma comment(lib, "ws2_32.lib")
//#pragma comment(lib, "Winmm.lib")
//
//// Windows Header Files:
//#include <windows.h>
//#include <Mmsystem.h>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <fstream>
//#include <iostream>
//nMap nativeCache;
////static ::std::unordered_map<uint64_t, uint64_t> nativeHashMap = { { 0, 0 } };
//static std::map<uint64_t, uint64_t> nativeHashMap = { { 0, 0 } };
////static std::map<uint64_t, uint64_t> hash_table = { { 0, 0 } };
// //uint64_t __HASHMAPDATA[] = { 0, 0 };


//bool CrossMapping::searchMap(nMap map, uint64_t inNative, uint64_t* outNative)
//{
//	bool found = false;
//	for (nMap::const_iterator it = map.begin(); it != map.end(); ++it)
//	{
//		found = (inNative == it->first);
//		if (found) {
//			*outNative = it->second;
//			break;
//		}
//	}
//
//	return found;
//
//}
//
//uint64_t CrossMapping::MapNative(uint64_t inNative)
//{
//	uint64_t currentNative, outNative;
//	bool found = false;
//
//	currentNative = inNative;
//	found = CrossMapping::searchMap(nativeCache, currentNative, &outNative);
//	if (found) return outNative;
//	found = CrossMapping::searchMap(nativeHashMap, currentNative, &outNative);
//	if (found) {
//		nativeCache[inNative] = outNative;
//		return outNative;
//	}
//
//	found = std::find(nativeFailedVec.begin(), nativeFailedVec.end(), inNative) != nativeFailedVec.end();
//	if (found) {
//		return NULL;
//	}
//	else nativeFailedVec.push_back(inNative);
//	return NULL;
//}

//typedef std::map<uint64_t, uint64_t> nMap;
////typedef std::unordered_map<uint64_t, uint64_t> nMap;

//typedef void(__cdecl* Handler)(Context* context);
//template<class Retn = uint64_t, class... Args>
//static Retn invoke_(Handler fn, Args... args)
//{
//	static const void* jmp_rbx = (void*)memory::find_signature(0, "\xFF\x23", "xx");
//	static Context ctx;
//
//	if (!fn) return Retn();
//
//	ctx.Reset();
//
//	if constexpr (sizeof...(Args) > 0)
//		ctx.Push(args...);
//
//	spoof_call(jmp_rbx, fn, &ctx);
//
//	return ctx.Result<Retn>();
//}
//template<class Retn = uint64_t, class... Args>
//static Retn invoke(uint64_t hashName, Args... args) {
//	return invoke_<Retn>(get_handler(hashName), args...);
//}
//
//Log::Msg("Initializing natives...");
//CrossMapping::initNativeMap();





//#include <bcrypt.h>
//#include "CrossMapping.cpp"
//typedef enum _MEMORY_INFORMATION_CLASS {
//	MemoryBasicInformation
//} MEMORY_INFORMATION_CLASS;
//
//typedef NTSTATUS(NTAPI* NtQueryVirtualMemory_fn)(HANDLE ProcessHandle,
//	PVOID BaseAddress, MEMORY_INFORMATION_CLASS MemoryInformationClass,
//	PVOID Buffer, ULONG Length, PULONG ResultLength);
//#define STATUS_ACCESS_DENIED             ((NTSTATUS)0xC0000022L)
//NTSTATUS NTAPI NtQueryVirtualMemory_hook(
//	IN HANDLE ProcessHandle,
//	IN PVOID BaseAddress,
//	IN MEMORY_INFORMATION_CLASS MemoryInformationClass,
//	OUT PVOID Buffer,
//	IN ULONG Length,
//	OUT PULONG ResultLength OPTIONAL)
//{
//	return STATUS_ACCESS_DENIED;
//}

//static Handler get_handler(uintptr_t hash_) {
//	static const void* jmp_rbx = (void*)memory4::find_signature(0, "\xFF\x23", "xx");
//
//	static auto get_native_address = reinterpret_cast<uintptr_t(*)(uint64_t)>((uintptr_t(GetModuleHandleW(0))) + 0x3A99FEE); //48 8D 05 0B905DFF 48 89 45 60 33 C0 89 45 30 89 45 00 
// 48 8D 05 0B 90 5D FF

//	Handler call_function = nullptr;
//	auto it = nativeHashMap.find(hash_);
//	if (it == nativeHashMap.end()) {
//		auto address = spoof_call(jmp_rbx, get_native_address, hash_);
//		if (address) {
//			nativeHashMap.insert(std::pair<uint64_t, uint64_t>(hash_, address));
//			call_function = (Handler)(address);
//		}
//	}
//	else {
//		if (it->first == hash_)
//			call_function = (Handler)(it->second);
//	}
//	return call_function;
//}
//BOOL __fastcall does_cam_exist_hook(__int64 a1, __int64 a2) {
//}




//MH_STATUS status3 = MH_CreateHookApi(L"ntdll.dll", "NtQueryVirtualMemory", NtQueryVirtualMemory_hook, reinterpret_cast<void**>(&original::o_ntqvm));
//auto does_cam_exist = (void*)get_handler(0xA7A932170592B50E);
//if ((status3 != MH_OK && status3 != MH_ERROR_ALREADY_CREATED) || MH_CreateHook(does_cam_exist, does_cam_exist_hook, reinterpret_cast<void**>(&original::o_does_cam_exist)) != MH_OK)
//{
//	Log::Msg("Hook Status3 %s", MH_StatusToString(status3));
//	return false;
//}

//static std::map<uint64_t, uint64_t> hash_table = { { 0, 0 } };
//static Handler get_handler(uintptr_t hash_) {
//	static const void* jmp_rbx = (void*)memory4::find_signature(0, "\xFF\x23", "xx");
//
//	static auto get_native_address = reinterpret_cast<uintptr_t(*)(uint64_t)>((uintptr_t(GetModuleHandleW(0))) + 0x3A99FEE); //48 8d 05 0B 90 5D FF
//	Handler call_function = nullptr;
//	auto it = hash_table.find(hash_);
//	if (it == hash_table.end()) {
//		auto address = spoof_call(jmp_rbx, get_native_address, hash_);
//		if (address) {
//			hash_table.insert(std::pair<uint64_t, uint64_t>(hash_, address));
//			call_function = (Handler)(address);
//		}
//	}
//	else {
//		if (it->first == hash_)
//			call_function = (Handler)(it->second);
//	}
//	return call_function;
//}







class CrossMapping2
{
public:
	static int MakeCrossmap();
	static int hashtable1();
};

struct native_dumper_t
{
	std::string name;
	uint64_t hash;
};


namespace memories
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


namespace memories
{
	class range;
	class pattern_batch;
	class pattern
	{
		friend pattern_batch;
		friend range;
	public:
		pattern(std::string_view ida_sig);
		explicit pattern(const void* bytes, std::string_view mask);

		inline pattern(const char* ida_sig) :
			pattern(std::string_view(ida_sig))
		{}

		std::vector<std::optional<std::uint8_t>> m_bytes;
	};
	class range
	{
	public:
		range(handle base, std::size_t size);

		handle begin();
		handle end();
		std::size_t size();

		bool contains(handle h);

		handle scan(pattern const& sig);
		std::vector<handle> scan_all(pattern const& sig);
	protected:
		handle m_base;
		std::size_t m_size;
	};
}



namespace memories
{
	class module : public range
	{
	public:
		explicit module(const std::string_view name);

		/**
		 * @brief Get the export address of the current module given a symbol name
		 *
		 * @param symbol_name
		 * @return memory::handle
		 */
		//memories::handle get_export(std::string_view symbol_name);

		bool loaded() const;
		/**
		 * @brief Waits till the given module is loaded.
		 *
		 * @param time Time to wait before giving up.
		 * @return true
		 * @return false
		 */
		bool wait_for_module(std::optional<std::chrono::high_resolution_clock::duration> time = std::nullopt);

	protected:
		bool try_get_module();

	private:
		const std::string_view m_name;
		bool m_loaded;

	};
}


namespace big
{
	using scrNativeHash = std::uint64_t;

	constexpr auto NATIVE_COUNT = 6494;
	using crossmap = std::array<std::pair<scrNativeHash, scrNativeHash>, NATIVE_COUNT>;
	extern const crossmap g_crossmap;
}




#endif // __CROSS_MAPPING_H__
