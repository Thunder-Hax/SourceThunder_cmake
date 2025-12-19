#pragma once

#ifdef __DEBUG
#define DEBUGOUT( X, ... ) Log::Debug( X, __VA_ARGS__ )
#else
#define DEBUGOUT( X, ... )
#endif

#if _DEBUG
#define DEBUGMSG Log::Debug
#else
#define DEBUGMSG //
#endif

class Log
{
public:
	static void Init(HMODULE hModule);
	static void chat(HMODULE hModule);
#ifdef _DEBUG
	static void Debug(const char* fmt, ...);
#endif
	static void Msg(const char* fmt, ...);
	static void Error(const char* fmt, ...);
	static void Fatal(const char* fmt, ...);
	static void MsgChat(const char* fmt, ...);
	static void Error2(const char* fmt, ...);
	static void Fatal2(const char* fmt, ...);
};