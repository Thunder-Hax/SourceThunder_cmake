#ifndef __NATIVE_INVOKER_H__
#define __NATIVE_INVOKER_H__

#pragma once

//class scrNativeCallContext {
//protected:
//
//	void* m_pReturn;
//	uint32_t	m_nArgCount;
//	void* m_pArgs;
//	uint32_t	m_nDataCount;
//	std::uint32_t m_data[48];
//	//alignas(uintptr_t)uint8_t m_vectorSpace[192];
//
//public:
//
//	template<typename T>
//	inline T GetArgument(int idx) {
//
//		intptr_t* arguments = (intptr_t*)m_pArgs;
//		return *(T*)&arguments[idx];
//	}
//
//	template<typename T>
//	inline void SetResult(int idx, T value) {
//
//		intptr_t* returnValues = (intptr_t*)m_pReturn;
//		*(T*)&returnValues[idx] = value;
//	}
//
//	inline int GetArgumentCount() {
//
//		return m_nArgCount;
//	}
//
//	template<typename T>
//	inline T GetResult() {
//
//		intptr_t* returnValues = (intptr_t*)m_pReturn;
//		return *(T*)&returnValues;
//	}
//
//	template <typename T>
//	//constexpr void push_arg(T&& value)
//	inline void push_arg(T&& value)
//	{
//		static_assert(sizeof(T) <= sizeof(std::uint64_t));
//		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_pArgs) + (m_nArgCount++)) = std::forward<T>(value);
//	}
//
//	template <typename T>
//	constexpr T& get_arg(std::size_t index)
//	{
//		static_assert(sizeof(T) <= sizeof(std::uint64_t));
//		return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_pArgs) + index);
//	}
//
//	template <typename T>
//	constexpr void set_arg(std::size_t index, T&& value)
//	{
//		static_assert(sizeof(T) <= sizeof(std::uint64_t));
//		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_pArgs) + index) = std::forward<T>(value);
//	}
//
//	template <typename T>
//	/*constexpr T* get_return_value()*/
//	inline T* get_return_value()
//	{
//		return reinterpret_cast<T*>(m_pReturn);
//	}
//
//	template <typename T>
//	constexpr void set_return_value(T&& value)
//	{
//		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_pReturn) = std::forward<T>(value);
//	}
//	static void(*SetVectorResults)(scrNativeCallContext*);
//};
//#include "../Source/reclass/GTAV-Classes/rage/vector.hpp"
//#include "../Source/reclass/GTAV-Classes/script/scrProgram.hpp"


class scrNativeCallContext
{
public:

	/*constexpr void reset()*/
	inline void reset()
	{
		m_arg_count = 0;
		m_data_count = 0;
	}

	//template <typename T>
	///*constexpr void push_arg(T&& value)*/
	//inline void push_arg(T&& value)
	//{
	//	static_assert(sizeof(T) <= sizeof(std::uint64_t));
	//	*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + (m_arg_count++)) = std::forward<T>(value);
	//}

	template <typename T>
	constexpr void push_arg(T&& value)
	{
		static_assert(sizeof(T) <= sizeof(std::uint64_t));
		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + (m_arg_count++)) = std::forward<T>(value);
	}

	//template <typename T>
	///*constexpr T& get_arg1(std::size_t index)*/
	//inline T& get_arg1(std::size_t index)
	//{
	//	static_assert(sizeof(T) <= sizeof(std::uint64_t));
	//	return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_args) + index);
	//}

	template <typename T>
	constexpr T& get_arg(std::size_t index)
	{
		static_assert(sizeof(T) <= sizeof(std::uint64_t));
		return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_args) + index);
	}

	//template <typename T>
	///*constexpr void set_arg(std::size_t index, T&& value)*/
	//inline void set_arg(std::size_t index, T&& value)
	//{
	//	static_assert(sizeof(T) <= sizeof(std::uint64_t));
	//	*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + index) = std::forward<T>(value);
	//}

	template <typename T>
	constexpr void set_arg(std::size_t index, T&& value)
	{
		static_assert(sizeof(T) <= sizeof(std::uint64_t));
		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + index) = std::forward<T>(value);
	}


	//template <typename T>
	///*constexpr T* get_return_value()*/
	//inline T* get_return_value()
	//{
	//	return reinterpret_cast<T*>(m_return_value);
	//}

	template <typename T>
	constexpr T* get_return_value()
	{
		return reinterpret_cast<T*>(m_return_value);
	}

	//template <typename T>
	///*constexpr void set_return_value(T&& value)*/
	//inline void set_return_value(T&& value)
	//{
	//	*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
	//}

	template <typename T>
	constexpr void set_return_value(T&& value)
	{
		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
	}
	void* m_return_value;
	std::uint32_t m_arg_count;
	void* m_args;
	std::int32_t m_data_count;
	/*std::uint32_t m_data[48];*/

	//
	std::uint32_t m_data[8];
	//
	/*rage::scrValue* m_orig[4];
	rage::fvector4 m_buffer[4];*/
	//
	static void(*SetVectorResults)(scrNativeCallContext*);
	///*rage::*/scrValue2* m_orig[4];
	//rage::fvector4 m_buffer[4];

};
using scrNativeHash = std::int64_t;
using scrNativePair = std::pair<scrNativeHash, scrNativeHash>;
using scrNativeHandler = void(*)(scrNativeCallContext*);
class NativeContext : public scrNativeCallContext {
private:

	// Configuration
	enum {
		/*MaxNativeParams = 16,
		ArgSize = 8,*/
		MaxNativeParams = 32,
		ArgSize = sizeof(void*),
	};

	// Anything temporary that we need
	uint8_t m_TempStack[MaxNativeParams * ArgSize];

public:
	inline void Reset()
	{
		/*m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStack;
		m_nArgCount = 0;
		m_nDataCount = 0;*/
		/*m_pArgs = &m_TempStack;
		m_pReturn = &m_TempStack;
		m_nArgCount = 0;
		m_nDataCount = 0;*/
		m_args = &m_TempStack;
		m_return_value = &m_TempStack;
		m_arg_count = 0;
		m_data_count = 0;
		/*using namespace rage;*/
		//std::fill(std::begin(void(*rage::scrNativeCallContext::SetVectorResults)), std::end(void(*rage::scrNativeCallContext::SetVectorResults)), '\0');//m_VectorSpace
		//std::fill(std::begin(m_TempStack), std::end(m_TempStack), 0);
		memset(m_TempStack, 0, sizeof(m_TempStack));
	}

	inline NativeContext() {

		//m_pArgs = &m_TempStack;
		//m_pReturn = &m_TempStack;		// It's okay to point both args and return at
		//// the same pointer. The game should handle this.
		//m_nArgCount = 0;
		//m_nDataCount = 0;
		m_args = &m_TempStack;
		m_return_value = &m_TempStack;
		m_arg_count = 0;
		m_data_count = 0;
	}

	template <typename T>
	inline void Push(T value) {

		if (sizeof(T) > ArgSize) {
			throw "Argument has an invalid size";
		}
		else if (sizeof(T) < ArgSize) {
			// Ensure we don't have any stray data
			/**reinterpret_cast<uintptr_t*>(m_TempStack + ArgSize * m_nArgCount) = 0;*/
			*reinterpret_cast<uintptr_t*>(m_TempStack + ArgSize * m_arg_count) = 0;
		}

		/**reinterpret_cast<T*>(m_TempStack + ArgSize * m_nArgCount) = value;*/
		*reinterpret_cast<T*>(m_TempStack + ArgSize * m_arg_count) = value;
		/*m_nArgCount++;*/
		m_arg_count++;
	}

	inline void Reverse() {

		uintptr_t tempValuesb[MaxNativeParams];
		/*uintptr_t* args = (uintptr_t*)m_pArgs;

		for (uint32_t i = 0; i < m_nArgCount; i++) {

			int target = m_nArgCount - i - 1;*/
		uintptr_t* args = (uintptr_t*)m_args;

		for (uint32_t i = 0; i < m_arg_count; i++) {

			int target = m_arg_count - i - 1;
			tempValuesb[target] = args[i];
		}

		memcpy(m_TempStack, tempValuesb, sizeof(m_TempStack));
	}

	/*
	template <typename T>
	inline T GetResult() {

		return *reinterpret_cast<T*>(m_TempStack);
	}*/
	/*template<typename T>
	inline T GetResult() {

		intptr_t* returnValues = (intptr_t*)m_pReturn;
		return *(T*)&returnValues;
	}*/
	template <typename T>
	inline T* GetResult()
	{
		return reinterpret_cast<T*>(m_return_value);
	}
};
//class NativeContext : public scrNativeCallContext {
//private:
//
//	// Configuration
//	enum {
//		/*MaxNativeParams = 16,*/
//		MaxNativeParams = 32,
//		/*ArgSize = 8,*/
//		ArgSize = sizeof(void*),
//	};
//
//	// Anything temporary that we need
//	uint8_t m_TempStack[MaxNativeParams * ArgSize];
//
//public:
//
//	inline NativeContext() {
//
//		m_pArgs = &m_TempStack;
//		m_pReturn = &m_TempStack;		// It's okay to point both args and return at
//		// the same pointer. The game should handle this.
//		m_nArgCount = 0;
//		m_nDataCount = 0;
//	}
//
//	template <typename T>
//	inline void Push(T value) {
//
//		if (sizeof(T) > ArgSize) {
//			throw "Argument has an invalid size";
//		}
//		else if (sizeof(T) < ArgSize) {
//			// Ensure we don't have any stray data
//			*reinterpret_cast<uintptr_t*>(m_TempStack + ArgSize * m_nArgCount) = 0;
//		}
//
//		*reinterpret_cast<T*>(m_TempStack + ArgSize * m_nArgCount) = value;
//		m_nArgCount++;
//	}
//
//	inline void Reverse() {
//
//		uintptr_t tempValuesb[MaxNativeParams];
//		uintptr_t* args = (uintptr_t*)m_pArgs;
//
//		for (uint32_t i = 0; i < m_nArgCount; i++) {
//
//			int target = m_nArgCount - i - 1;
//			tempValuesb[target] = args[i];
//		}
//
//		memcpy(m_TempStack, tempValuesb, sizeof(m_TempStack));
//	}
//
//	template <typename T>
//	inline T GetResult() {
//
//		return *reinterpret_cast<T*>(m_TempStack);
//	}
//};

struct pass {
	template<typename ...T> pass(T...) {}
};

class NativeManagerContext : public NativeContext {
public:

	NativeManagerContext()
		: NativeContext() {
	}

	void Reset() {
		/*m_nArgCount = 0;
		m_nDataCount = 0;*/
		m_arg_count = 0;
		m_data_count = 0;
	}

	inline void* GetResultPointer() {
		/*return m_pReturn;*/
		return m_return_value;
	}
};

void nativeInit(UINT64 hash);

void nativePush64(UINT64 val);

PUINT64 nativeCall();

#endif // __NATIVE_INVOKER_H__