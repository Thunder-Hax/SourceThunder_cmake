#pragma once
#include "stdafx.h"
#include <chrono>
#include <ctime>
////namespace otherinclude {
////#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
////#include <cstdint>
////#include <stdlib.h>
////#include <stdio.h>
////#include <string>
////#include <sstream>
////#include <string>
////#include <string_view>
////#include <algorithm>
////#include <utility>
////#include <stack>
////#include <vector>
////#include <typeinfo>
////#include <type_traits>
////// Windows Library Files:
////#pragma comment(lib, "ws2_32.lib")
////#pragma comment(lib, "Winmm.lib")
////#include <sstream>
////#include <Shlwapi.h>
////#pragma comment(lib, "Shlwapi.lib")
////#include <iostream>
////#include <string>
////#include <tuple>
////#include <vector>
////#include <array>
////#include <cstring>
////#include <cstdio>
////#include <stdio.h>
////#include <memory>
////#include <array>
////
////#include <string>
////#include <string.h>
////#include <WinUser.h>
////#include <xutility>
////#include <KnownFolders.h>
////#include <ShlObj.h>
////#include <comutil.h>
//////#include <filesystem2>
////#include <fstream2>
////#include <intrin.h>
////#include <xstring>
////#include <functional>
////#include <experimental/filesystem>
////
////	namespace fs = std::experimental::filesystem;
////	/*namespace fs = std::filesystem;*/
////}
//
//namespace loadsave
//{
//    extern char outfitbuffer[255];
//	extern void savenootherlineoutfit(std::string file, std::string outfitofstream2);
//	extern void savelineoutfit(std::string file, std::string outfitofstream2);
//    extern void loadoutfit(std::string file, std::string outfitifstream);
//    extern void listxml();
//	extern std::string findAndReplaceAll(std::string& data, std::string toSearch, std::string replaceStr);
//    //extern bool loadfromfile(const std::string& filePath);
//	extern std::string replaced(std::string phrase, std::string replace, std::string replacement);
//}
//
//class Ini
//{
//private:
//	std::string inifile;
//public:
//	Ini(std::string file)
//	{
//		this->inifile = file;
//	}
//	void WriteString(std::string string, std::string app, std::string key)
//	{
//		WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), this->inifile.c_str());
//	}
//	std::string GetString(std::string app, std::string key)
//	{
//		char buf[100];//100
//		GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, this->inifile.c_str());//100
//		return (std::string)buf;
//	}
//	void WriteInt(int value, std::string app, std::string key)
//	{
//		WriteString(std::to_string(value), app, key);
//	}
//	int GetInt(std::string app, std::string key)
//	{
//		return std::stoi(GetString(app, key));
//	}
//	void WriteFloat(float value, std::string app, std::string key)
//	{
//		WriteString(std::to_string(value), app, key);
//	}
//	float GetFloat(std::string app, std::string key)
//	{
//		return std::stof(GetString(app, key));
//	}
//};
namespace Outfit
{
//	extern std::string playeroutfit;
//	/*extern void ConfigReadOutFit();
//	extern void ConfigSaveOutFit();*/
//	extern std::string getplayername;
//	extern void AllOutFit();
//	/*extern void LoadOutfit();
//extern void SaveOutfit();*/
//	extern int testa1;
//	extern int testb1;
//	extern int testc1;
//	extern int testd1;
//	extern int teste1;
//	extern int testf1;
//	extern int testg1;
//	extern int testh1;
//	extern int testi1;
//	extern int testj1;
//	extern int testk1;
//	extern int testl1;
//	extern int testm1;
//	extern int testn1;
//	extern int testo1;
//	//extern char* listoutfit[];
	extern char* outfitlist[];
	extern void savedoutfits();
//	extern void loadoutfits();
	extern std::string OutfitName;
	extern std::string outfitnamesaved;
	extern int Face;
	extern int Head;
	extern int Hair;
	extern int Torso;
	extern int Legs;
	extern int Hands;
	extern int Feet;
	extern int Eyes;
	extern int Accessories;
	extern int Tasks;
	extern int Textures;
	extern int Torso2;
	extern int HeadProp;
	extern int EyeProp;
	extern int EarProp;
	extern void checkoutfitfolder();

}
namespace Directory
{
extern std::string get_current_dir();
}

namespace Teleport
{
	extern std::string teleportName;
	extern void teleportfolder();
	extern std::string Teleportnamesaved;
	extern void savedTeleport();
}

namespace YoutubeFolder
{
	extern void FolderYoutube();
}
namespace OverSeeing
{
	extern void Overseefolder();
	extern void addPlayerfolder();
}
