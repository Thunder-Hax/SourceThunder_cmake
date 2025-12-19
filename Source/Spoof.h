#include <cstddef>
#include <type_traits>

namespace detail
{
	extern "C" void* _spoofer_stub();

	template <typename Ret, typename... Args>
	static inline auto shellcode_stub_helper(
		const void* shell,
		Args... args
	) -> Ret
	{
		auto fn = (Ret(*)(Args...))(shell);
		return fn(args...);
	}

	template <std::size_t Argc, typename>
	struct argument_remapper
	{
		// At least 5 params
		template<
			typename Ret,
			typename First,
			typename Second,
			typename Third,
			typename Fourth,
			typename... Pack
		>
			static auto do_call(
				const void* shell,
				void* shell_param,
				First first,
				Second second,
				Third third,
				Fourth fourth,
				Pack... pack
			) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*,
				Pack...
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr,
				pack...
				);
		}
	};

	template <std::size_t Argc>
	struct argument_remapper<Argc, std::enable_if_t<Argc <= 4>>
	{
		// 4 or less params
		template<
			typename Ret,
			typename First = void*,
			typename Second = void*,
			typename Third = void*,
			typename Fourth = void*
		>
			static auto do_call(
				const void* shell,
				void* shell_param,
				First first = First{},
				Second second = Second{},
				Third third = Third{},
				Fourth fourth = Fourth{}
			) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr
				);
		}
	};
}
extern "C" void	_call_asm(void* context, void* function, void* ret);

template <typename Ret, typename... Args>
static inline auto spoof_call(
	const void* trampoline,
	Ret(*fn)(Args...),
	Args... args
) -> Ret
{
	struct shell_params
	{
		const void* trampoline;
		void* function;
		void* rdi;
	};

	shell_params p{ trampoline, reinterpret_cast<void*>(fn) };
	using mapper = detail::argument_remapper<sizeof...(Args), void>;
	return mapper::template do_call<Ret, Args...>((const void*)&detail::_spoofer_stub, &p, args...);
}


//class scrNativeCallContext2
//{
//public:
//	void reset()
//	{
//		m_arg_count = 0;
//		m_data_count = 0;
//	}
//
//	template <typename T>
//	void push_arg(T&& value)
//	{
//		static_assert(sizeof(T) <= sizeof(std::uint64_t));
//		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + (m_arg_count++)) = std::forward<T>(value);
//	}
//
//	template <typename T>
//	T& get_arg(std::size_t index)
//	{
//		static_assert(sizeof(T) <= sizeof(std::uint64_t));
//		return *reinterpret_cast<T*>(reinterpret_cast<std::uint64_t*>(m_args) + index);
//	}
//
//	template <typename T>
//	void set_arg(std::size_t index, T&& value)
//	{
//		static_assert(sizeof(T) <= sizeof(std::uint64_t));
//		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(reinterpret_cast<std::uint64_t*>(m_args) + index) = std::forward<T>(value);
//	}
//
//	template <typename T>
//	T* get_return_value()
//	{
//		return reinterpret_cast<T*>(m_return_value);
//	}
//
//	template <typename T>
//	void set_return_value(T&& value)
//	{
//		*reinterpret_cast<std::remove_cv_t<std::remove_reference_t<T>>*>(m_return_value) = std::forward<T>(value);
//	}
//protected:
//	void* m_return_value;
//	std::uint32_t m_arg_count;
//	void* m_args;
//	std::int32_t m_data_count;
//	std::uint32_t m_data[48];
//};
//
//using fix_vectors_t = void(scrNativeCallContext2);
//fix_vectors_t* m_fix_vectors{};
//using fix_vectors_t = void(rage::scrNativeCallContext);
//fix_vectors_t* m_fix_vectors{};
//using fix_vectors_t = void(rage::scrNativeCallContext);
//fix_vectors_t* m_fix_vectors{};
/*
PUBLIC _spoofer_stub

.code

_spoofer_stub PROC
pop r11
pop r10
mov rax, [rsp + 24]

mov r10, [rax]
mov[rsp], r10

mov r10, [rax + 8]
mov[rax + 8], r11

mov[rax + 16], rbx
lea rbx, fixup
mov[rax], rbx
mov rbx, rax

jmp r10

fixup :
sub rsp, 16
mov rcx, rbx
mov rbx, [rcx + 16]
jmp QWORD PTR[rcx + 8]
_spoofer_stub ENDP

END
*/

/*

PUBLIC _spoofer_stub
.DATA
	return_address	dq	0
	real_rbx		dq	0
.CODE
_spoofer_stub PROC
		mov real_rbx, rbx
		mov r9, [rsp]
		mov return_address, r9
		lea rbx, _ret_asm
		mov [rsp], r8
		jmp rdx
_spoofer_stub ENDP
_ret_asm PROC
		mov rbx, real_rbx
		mov rcx, return_address
		jmp rcx
_ret_asm ENDP
END

*/