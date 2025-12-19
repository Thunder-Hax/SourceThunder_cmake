//dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Functions.h"
#include "thread"

#include <iostream>
#include <iomanip>
#include <memory>


#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

#include <iostream>
#include <iomanip>
#include <memory>

#include <thread>
#include <chrono>


#include <stdint.h>
#include <stdlib.h>

#include <any>
#include <optional>
#include <variant>
#include <cinttypes>
#include <cstddef>
#include <cstdint>

#include <chrono>
#include <ctime>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <atomic>
#include <mutex>
#include <thread>

#include <memory>
#include <new>

#include <sstream>
#include <string>
#include <string_view>

#include <algorithm>
#include <functional>
#include <utility>

#include <stack>
#include <vector>

#include <typeinfo>
#include <type_traits>

#include <exception>
#include <stdexcept>

#include <stdint.h>

#include <iostream>
#include <chrono>
#include <thread>

DWORD WINAPI ControlThread(LPVOID lpParam)
{
	Hooking::Start((HMODULE)lpParam);
	/*returngamefunction();*/
	return 0;
}
//DWORD WINAPI botsilent(LPVOID lpParam)
//{
//	Silent_persist::autolistaction();
//	return 0;
//}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	/*if (ModMenu::unload)
	{*/
		switch (ul_reason_for_call)
		{
		case DLL_PROCESS_ATTACH:
		{
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread, hModule, NULL, NULL);
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadThunderConfig, NULL, 0, NULL);
			/*CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Hooking::onTickInit2, NULL, 0, NULL);*/
			//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Silent_persist::autolistaction, NULL, 0, NULL);
		}
		break;
		case DLL_THREAD_ATTACH:
		{
		}
		break;
		case DLL_THREAD_DETACH:
		{
		}
		break;
		case DLL_PROCESS_DETACH:
		{
			Hooking::Cleanup();
		}
		break;
		}
		return TRUE;
	//}
	/*else
	{
		return FALSE;
	}*/
}


