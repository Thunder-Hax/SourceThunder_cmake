#pragma once

#include <string>
#include <vector>

std::string ExePathA(bool lastSlash = false);
std::wstring ExePathW(bool lastSlash = false);


#ifdef _UNICODE
#define ExePath ExePathW
#else
#define ExePath ExePathA
#endif


enum class Pathff
{
	RootDir,
	ThunderMenu,
	Vehicle,
	Outfit,
	Spooner,
	Audio,
	Graphics,
	Speedo,
	Youtube,
	WeaponsLoadout
};

std::wstring GetPathffW(Pathff type, bool lastSlash = false);
std::string GetPathffA(Pathff type, bool lastSlash = false);
#ifdef _UNICODE
#define GetPathff GetPathffW
#else
#define GetPathffe GetPathffA
#endif

bool does_file_exist(const std::string& path);

//void get_all_filenames_with_extension(const std::string& directory, const std::string& extension, std::vector<std::string>& results, bool withExtension);

std::string GetClipboardTextA();

