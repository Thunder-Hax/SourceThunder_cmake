#pragma once
#include <cstddef>
#include <cstdint>
#include <utility>
//namespace rage
//{
//	struct scrNativeCallContext
//	{
//	public:
//		void reset()
//		{
//			m_ArgCount = 0;
//			m_DataCount = 0;
//		}
//
//		template <typename T>
//		void push_arg(T&& value)
//		{
//			static_assert(sizeof(T) <= sizeof(std::uint64_t));
//			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_Args) + (m_ArgCount++)) = std::forward<T>(value);
//		}
//
//		template <typename T>
//		T& get_arg(std::size_t index)
//		{
//			static_assert(sizeof(T) <= sizeof(std::uint64_t));
//			return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_Args) + index);
//		}
//
//		template <typename T>
//		void set_arg(std::size_t index, T&& value)
//		{
//			static_assert(sizeof(T) <= sizeof(std::uint64_t));
//			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_Args) + index) = std::forward<T>(value);
//		}
//
//		template <typename T>
//		T* get_return_value()
//		{
//			return reinterpret_cast<T*>(m_Return);
//		}
//
//		template <typename T>
//		void set_return_value(T&& value)
//		{
//			*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_Return) = std::forward<T>(value);
//		}
//	protected:
//		void* m_Return;
//		std::uint32_t m_ArgCount;
//		char padding[4];
//		void* m_Args;
//		std::uint32_t m_DataCount;
//		char padding1[4];
//		alignas(std::uintptr_t) std::uint8_t m_VectorSpace[192];
//		static void(*SetVectorResults)(scrNativeCallContext*);
//	};
//
//	using scrNativeHash = std::int64_t;
//	using scrNativePair = std::pair<scrNativeHash, scrNativeHash>;
//	using scrNativeHandler = void(*)(scrNativeCallContext*);
//}

//namespace rage
//{
//    class scrNativeCallContext
//    {
//    public:
//        void reset()
//        {
//            m_arg_count = 0;
//            m_data_count = 0;
//        }
//
//        template <typename T>
//        void push_arg(T &&value)
//        {
////             static_assert(sizeof(T) <= sizeof(std::uint64_t));
//            *reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + (m_arg_count++)) = std::forward<T>(value);
//        }
//
//        template <typename T>
//        T &get_arg(std::size_t index)
//        {
////             static_assert(sizeof(T) <= sizeof(std::uint64_t));
//            return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_args) + index);
//        }
//
//        template <typename T>
//        void set_arg(std::size_t index, T &&value)
//        {
////             static_assert(sizeof(T) <= sizeof(std::uint64_t));
//            *reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + index) = std::forward<T>(value);
//        }
//
//        template <typename T>
//        T *get_return_value()
//        {
//            return reinterpret_cast<T*>(m_return_value);
//        }
//
//        template <typename T>
//        void set_return_value(T &&value)
//        {
//            *reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
//        }
//    protected:
//        void *m_return_value;
//        std::uint32_t m_arg_count;
//        void *m_args;
//        std::int32_t m_data_count;
//        std::uint32_t m_data[48];
//    };
////     static_assert(sizeof(scrNativeCallContext) == 0xE0);
//
//    using scrNativeHash = std::int64_t;
//    using scrNativePair = std::pair<scrNativeHash, scrNativeHash>;
//    using scrNativeHandler = void(*)(scrNativeCallContext*);
//}
