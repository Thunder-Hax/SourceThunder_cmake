#include "stdafx.h"

#include "GTAmath.h"
#include "GTAentity.h"
#include "natives.h"
#include "GTAped.h"
#include "Raycast.h"
#include "World.h"
#include "ExePath.h"
#include "FileLogger.h"

#define ShellExecute  ShellExecuteW

// Windows Library Files:
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")
#include <windows.h>
#include <Mmsystem.h>
#include <mciapi.h>
#include <timeapi.h>
#include <time.h>
#include <cassert>
#include <iterator>
#include <shlobj.h>
#include <Shlwapi.h> //PathRemoveFileSpecA banner
#pragma comment(lib, "shlwapi.lib")//banner
#include <objbase.h>
#include <cstdint>
#include <algorithm>
#include <unordered_map>
#include <mutex>
#include <bitset>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
#include <shellapi.h>
#include <iomanip>
#include <numeric>
#include <direct.h>
#define GetCurrentDir _getcwd
#include <wchar.h>
#include <errno.h>
#include <tchar.h>
#include <dinput.h>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <memory>
#include <array>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <functional>
#include <stdint.h>
#include <mciapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <regex>
#include <vector>
bool ifsaved = 0;
bool firstdowncheck = 1;
std::string yd::szAlias = "";
//#define ShellExecute  ShellExecuteW
std::string yd::youtubelink = "";
std::string yd::outputname = "";
bool yd::youtubebool = 0;
namespace youdown
{
	void to_json(nlohmann::json& j, const youdown::downyou& downyou) {
		j = nlohmann::json{ {"youtubelink", downyou.ytl},
							{"namesaved", downyou.ytn} };
	}
	void from_json(const nlohmann::json& j, youdown::downyou& downyou) {
		downyou.ytl = j["youtubelink"].get<std::string>();
		downyou.ytn = j["namesaved"].get<std::string>();
	}
};

bool yd::timerffmpegbool = 0;
int yd::timerffmpegconvert(std::string ffmpegname)
{
	if (timerffmpegbool)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		int getTimer = milliseconds;
		if (getTimer % 2500 == 0)
		{
			yd::convertto96k(ffmpegname);
			timerffmpegbool = 0;
		}
	}
	return 0;
}

int yd::convertint = 124;
bool yd::converted = 0;
int yd::renameffmpeg1()
{
	std::ifstream ffmpeg;
	ffmpeg.open(Directory::get_current_dir() + "\\ffmpeg.exe");
	if (ffmpeg)
	{
		std::string doubleslash = "\\";
		std::string doublequote = "\"";
		std::string getdirectory = Directory::get_current_dir() + doubleslash;
		std::string getdirectories = doublequote + getdirectory;
		std::string renameffmpeg = getdirectories + "ffmpeg.exe";
		std::string renameffmpeg11 = renameffmpeg + doublequote;
		std::string renameffmpeg10 = renameffmpeg11 + " ffmpeg_.exe";
		std::string renameffmpeg1 = "rename " + renameffmpeg10;
		std::string cmd = "c:\\windows\\system32\\cmd.exe";
		std::string taskdirectory1 = " cmd /c " + renameffmpeg1;
		std::wstring progpath = functions::s2ws(cmd);
		LPCWSTR lpprogpath = progpath.c_str();
		std::wstring commandd = functions::s2ws(taskdirectory1);
		LPCWSTR lpcommand = commandd.c_str();
		ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	}
	ffmpeg.close();
	return 0;
}
int yd::renameffmpeg2()
{
	std::ifstream ffmpeg;
	ffmpeg.open(Directory::get_current_dir() + "\\ffmpeg_.exe");
	if (ffmpeg)
	{
		std::string doubleslash = "\\";
		std::string doublequote = "\"";
		std::string getdirectory = Directory::get_current_dir() + doubleslash;
		std::string getdirectories = doublequote + getdirectory;
		std::string renameffmpeg = getdirectories + "ffmpeg_.exe";
		std::string renameffmpeg11 = renameffmpeg + doublequote;
		std::string renameffmpeg10 = renameffmpeg11 + " ffmpeg.exe";
		std::string renameffmpeg1 = "rename " + renameffmpeg10;
		std::string cmd = "c:\\windows\\system32\\cmd.exe";
		std::string taskdirectory1 = " cmd /c " + renameffmpeg1;
		std::wstring progpath = functions::s2ws(cmd);
		LPCWSTR lpprogpath = progpath.c_str();
		std::wstring commandd = functions::s2ws(taskdirectory1);
		LPCWSTR lpcommand = commandd.c_str();
		ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	}
	ffmpeg.close();
	return 0;
}

int yd::convertto96k(std::string ffmpegname)
{
	//ffmpeg -i test33.mp3 -b:v 1m -b:a 96k output.mp3
	std::string quote = "\\";
	std::string doublequote = "\"";
	std::string getdirectory = Directory::get_current_dir() + quote;
	std::string getdirectories = doublequote + getdirectory;
	std::string Prog = "ffmpeg.exe ";
	std::string getdirectory2 = getdirectories + Prog;
	std::string myi = "-i ";
	std::string youtubedirectory4 = getdirectories + "ThunderMenu\\Youtube\\";
	std::string youtubedirectory3 = myi + youtubedirectory4;
	std::string youtubedirectory2 = youtubedirectory3 + ffmpegname;
	std::string youtubedirectory1 = "";	
	if (converted)
	{
		youtubedirectory1 = youtubedirectory2 + ".mp3";
	}
	if (!converted)
	{
		youtubedirectory1 = youtubedirectory2 + ".tmp";
	}
	std::string youtubedirectory0 = youtubedirectory1 + doublequote;
	std::string youtubedirectory5 = youtubedirectory0 + " -b:v 1M -b:a ";
	std::string youtubedirectory55 = youtubedirectory5 + to_string(convertint);
	std::string youtubedirectory56 = youtubedirectory55 + "k ";
	std::string youtubedirectory6 = youtubedirectory56 + youtubedirectory4;
	std::string youtubedirectory7 = youtubedirectory6 + yd::outputname;
	std::string youtubedirectory77 = "";
	std::string youtubedirectory777 = "";
	std::string youtubedirectory8 = "";
	if (converted)
	{
		youtubedirectory77 = youtubedirectory7 + "Converted";
		youtubedirectory777 = youtubedirectory77 + to_string(convertint);
		youtubedirectory8 = youtubedirectory777 + ".mp3";
	}
	if (!converted)
	{
		youtubedirectory8 = youtubedirectory7 + ".mp3";
	}
	std::string youtubedirectory = youtubedirectory8 + doublequote;
	std::wstring progpath = functions::s2ws(Prog);
	LPCWSTR lpprogpath = progpath.c_str();
	std::wstring commandd = functions::s2ws(youtubedirectory);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE);
	return 0;
}
int yd::youtubeDownloader(std::string link, std::string name)
{
	std::string quote = "\\";
	std::string doublequote = "\"";
	std::string getdirectory = Directory::get_current_dir() + quote;
	std::string getdirectories = doublequote + getdirectory;
	std::string Prog = "youtube-dl.exe ";
	std::string getdirectory2 = getdirectories + Prog;
	std::string youtubelnks = getdirectories + "ThunderMenu\\Youtube\\";
	std::string savednames = youtubelnks + yd::outputname;
	std::string linkurl = "https://www.youtube.com/watch?v=" + yd::youtubelink;
	std::string savednames2 = " -x --audio-format mp3 --output " + savednames;
	std::string savednames3 = savednames2 + ".tmp";
	std::string savednames4 = savednames3 + doublequote;
	std::string program = linkurl + savednames4;
	std::wstring progpath = functions::s2ws(Prog);
	LPCWSTR lpprogpath = progpath.c_str();
	std::wstring commandd = functions::s2ws(program);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE);
	DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;
	int getTimer = milliseconds;
	if (getTimer % 1500 == 0)
	{
		yd::timerffmpegbool = 1;
		yd::timerffmpegconvert(name);
	}
	return 0;
}

void youtube_persist::save_location2(std::string link, std::string name)
{
	youdown::downyou downyou;
	downyou.ytl = link;
	downyou.ytn = name;
	yd::youtubeDownloader(link, name);
	save2(downyou, name);
}

int loadname()
{
	yd::youtubebool = true;
	yd::szAlias = yd::outputname;
	yd::startmusicdownloadsmp3(yd::outputname);
	yd::start();
	yd::youtubebool = false;
	return 0;
}

void youtube_persist::load_location2(std::string name)
{
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	auto model_attachment = locations[name].get<youdown::downyou>();
	yd::youtubelink = model_attachment.ytl;
	yd::outputname = model_attachment.ytn;
	loadname();
}

void youtube_persist::delete_location2(std::string name)
{
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json2(locations);
}

std::vector<std::string> youtube_persist::list_locations2()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json2();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}
int resultpos222 = 0;


std::string enterurl = "Enter Url Watch?v=";
std::string namesave = "Save Name";


char* CharKeyboardsavename(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	WAIT(50);
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return ""; //Thunder
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

std::string urlstring = "";
void urleyboard()
{
	string savedkey = CharKeyboardsavename();
	if (savedkey != "")
	{
		urlstring = savedkey;
	}
	else
	{
	}
}

std::string outputnamestring = "";
void nameoutputleyboard()
{
	string savekey1 = CharKeyboardsavename();
	if (savekey1 != "")
	{
		outputnamestring = savekey1;
	}
	else
	{
	}
}

void yd::startmusicdownloadsmp3(const std::string title) {
	yd::szAlias = title;
}

int yd::stop()
{
	std::string szCommand;
	szCommand = "stop " + yd::szAlias;
	mciSendStringA(szCommand.c_str(), NULL, 0, 0);
	szCommand = "close " + yd::szAlias;
	mciSendStringA(szCommand.c_str(), NULL, 0, 0);
	yd::BgMusic(false);
	yd::youtubebool = false;
	return 0;
}

int yd::start()
{
	yd::BgMusic(yd::youtubebool);
	return 1;
}

std::wstring yd::s2ws2(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

int yd::pause()
{
	std::string szCommand;
	szCommand = "pause " + yd::szAlias;
	mciSendStringA(szCommand.c_str(), NULL, 0, 0);
	return 0;
}

int yd::resumeplay()
{
	std::string szCommand;
	szCommand = "resume " + yd::szAlias;
	mciSendStringA(szCommand.c_str(), NULL, 0, 0);
	return 0;
}

//To open* .mp3:
//
//mciSendString("open \"*.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
//To play* .mp3:
//
//mciSendString("play mp3", NULL, 0, NULL);
//To playand wait until the* .mp3 has finished playing :
//
//mciSendString("play mp3 wait", NULL, 0, NULL);
//To replay(play again from start) the* .mp3:
//
//mciSendString("play mp3 from 0", NULL, 0, NULL);
//To replayand wait until the* .mp3 has finished playing :
//
//mciSendString("play mp3 from 0 wait", NULL, 0, NULL);
//To play the* .mp3and replay it every time it ends like a loop :
//
//mciSendString("play mp3 repeat", NULL, 0, NULL);


void yd::BgMusic(bool enable)
{
	std::string szCommand;
	if (enable)
	{
			std::string quoteyoutube = "\\ThunderMenu\\Youtube\\";
			std::string doublequote = "\"";
			std::string getdirectory = Directory::get_current_dir() + quoteyoutube;
			//szCommand = "open \"" + GetPathffA(Pathff::ThunderMenu, true) + szAlias + ".mp3" + "\" type MPEGVideo" + " alias " + szAlias;
			szCommand = "open \"" + /*GetPathffA(Pathff::Youtube, true)*/getdirectory + yd::szAlias + ".mp3" + "\" type MPEGVideo" + " alias " + yd::szAlias;
		mciSendStringA(szCommand.c_str(), NULL, 0, 0);
		szCommand = "play " + yd::szAlias + " from 0 repeat";
		mciSendStringA(szCommand.c_str(), NULL, 0, 0);
		szCommand = "setaudio " + yd::szAlias + " volume to 400";
		mciSendStringA(szCommand.c_str(), NULL, 0, 0);
	}
}
bool vectorlist = 0;
void youtube_persist::do_presentation_layer2()
{
	if (firstdowncheck)
	{
		dlyoutube::downloading();
		std::ifstream ffmpeg;
		ffmpeg.open(Directory::get_current_dir() + "\\ffmpeg.exe");
		if (ffmpeg)
		{
			firstdowncheck = 0;
		}
		else
		{
			dlyoutube::downloading2();
		}
		ffmpeg.close();
	}
	auto youtube_locations = list_locations2();
	static std::string selected_youtube2;
	int xi = 0;
	std::vector<char*> charVec2(youtube_locations.size(), nullptr);
	for (int i = 0; i < youtube_locations.size(); i++) {
		charVec2[i] = &youtube_locations[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec2, resultpos222)) {
			char* result2 = charVec2[resultpos222];
			selected_youtube2 = result2;
		}
		vectorlist = 1;
	}
	if (!ifsaved)
	{
		if (Menu::Option("Save"))
		{

			ifsaved = 1;
			if (vectorlist)
			{
				backgrounds::casetwo();
			}
			if (!vectorlist)
			{
				backgrounds::caseone();
			}
		}
	}
	if (ifsaved)
	{
		if (Menu::Option((char*)enterurl.c_str()))
		{
			urleyboard();
			enterurl = urlstring;
			yd::youtubelink = urlstring;
		}
		if (Menu::Option((char*)namesave.c_str()))
		{
			nameoutputleyboard();
			namesave = outputnamestring;
			yd::outputname = outputnamestring;
		}
		if (Menu::Option("Add to Playlist"))
		{
			save_location2(urlstring, outputnamestring);
			enterurl = "Enter Url";
			namesave = "Save Name";
			ifsaved = 0;
		}
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_youtube2.empty())
			{
				load_location2(selected_youtube2);
				yd::outputname = selected_youtube2;
				selected_youtube2.clear();
			}
		}
		if (Menu::Option("Stop"))
		{
			yd::stop();
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_youtube2.empty())
			{
				delete_location2(selected_youtube2);
				selected_youtube2.clear();
			}
		}
		if (Menu::Option("pause"))
		{
			yd::pause();
		}
		if (Menu::Option("Resume"))
		{
			yd::resumeplay();
		}
		Menu::Toggle("Converted", yd::converted);
		if (yd::converted)
		{
			if (Menu::Option("Rename Ffmpeg_"))
			{
				yd::renameffmpeg1();
			}
			Menu::Int("Bitrate", yd::convertint, 1, 178);
			if (Menu::Option("Rename Ffmpeg"))
			{
				yd::renameffmpeg2();
			}
			if (Menu::Option("Convert"))
			{
				yd::convertto96k(yd::outputname);
			}
		}
	}
	if (yd::converted)
	{
		backgrounds::casetwelve();
	}
	if (!yd::converted)
	{
		if (!vectorlist && ifsaved)
		{
			backgrounds::casethree();
		}
		if (vectorlist && ifsaved)
		{
			backgrounds::caseseven();
		}
		if (vectorlist && !ifsaved)
		{
			backgrounds::caseeight();
		}
		if (!vectorlist && !ifsaved)
		{
			backgrounds::caseone();
		}
	}
}

void youtube_persist::save2(youdown::downyou downyou, std::string name)
{
	auto json = get_locations_json2();
	json[name] = downyou;
	save_json2(json);
}

void youtube_persist::save_json2(nlohmann::json json)
{
	auto file_path = get_locations_config2();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json youtube_persist::get_locations_json2()
{
	auto file_path = get_locations_config2();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string youtube_persist::get_locations_config2()
{
	YoutubeFolder::FolderYoutube();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Youtube\\";
	file_path += "YouTubeListe.json";
	return file_path;
}

std::string gplzip1;
std::string gplzip22;
std::string dlyoutube::youtubedl;
int ReadLinegplzip22()
{
	std::istringstream file(gplzip1);

	std::string gpl = "youtube-dl.exe";
	std::string lpg = "releases/download";
	std::regex e("\\b(" + lpg + ")([^ ]*)" + "\\b(" + gpl + ")([& ]*)");
	std::string gpll;
	while (std::getline(file, gpll))
	{
		if (regex_search(gpll, e))
			gplzip22 = gpll + "\n";
	}
	return 0;
}
bool checkfordownload = 1;
int ReadLinegplzip1()
{
	std::string doublequote = "\"";
	std::ifstream file(Directory::get_current_dir() + "\\youtubedl.txt");
	std::string gpl = "youtube-dl.exe" + doublequote;
	std::string lpg = "releases/download";
	std::regex e("\\b(" + lpg + ")([^ ]*)" + "\\b(" + gpl + ")([& ]*)");
	std::string gpll;
	std::smatch m;
	std::string result;
	while (std::getline(file, gpll))
	{
		/*if (regex_search(gpll, e))
			gplzip1 = gpll + "\n";*/
		std::sregex_iterator next(gpll.begin(), gpll.end(), e);
		std::sregex_iterator end;
		while (next != end) {
			std::smatch match = *next;
			std::cout << match.str() << "\n";
			if (checkfordownload)
			{
				gplzip1 = gpll;
				checkfordownload = 0;
			}
			next++;
		}
	}
	file.close();
	return 0;
}

int ReadLinegplzip33()
{
	std::istringstream file(dlyoutube::youtubedl);
	std::string lpg = "youtube-dl.exe";
	std::regex e{ "\\b" + lpg + "\\b" };
	/*std::regex e("\\b(" + lpg + ")([^ ]*)");*/
	std::string gpll;
	while (std::getline(file, gpll))
	{
		if (regex_search(gpll, e))
			dlyoutube::youtubedl = gpll + "\n";
	}
	return 0;
}
int dlyoutube::downloading()
{
	std::ifstream youtubedll;
	youtubedll.open(Directory::get_current_dir() + "\\youtube-dl.exe");
	if (!youtubedll)
	{
		////https://github.com/ytdl-org/youtube-dl/releases/download/2021.04.17/youtube-dl.exe
		//std::string dwnld_URL = "https://github.com/ytdl-org/youtube-dl/releases/download/2021.02.10/youtube-dl.exe";
		std::string dwnld_URL = "https://github.com/ytdl-org/youtube-dl/releases/";
		/*std::string savepath = Directory::get_current_dir() + "\\ffmpeg.zip";*/
		std::string savepath = Directory::get_current_dir() + "\\youtubedl.txt";
		std::wstring downloadfile = functions::s2ws(dwnld_URL);
		LPCWSTR downloadingfile = downloadfile.c_str();
		std::wstring savefile = functions::s2ws(savepath);
		LPCWSTR savingfile = savefile.c_str();
		/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
		URLDownloadToFileW(NULL, downloadingfile, savingfile, 0, NULL);
		ReadLinegplzip1();
		std::string taskdirectory2 = Directory::get_current_dir() + "\\youtubedlurl.txt";
		std::ofstream repbegtext(taskdirectory2);
		if (repbegtext.is_open())
		{
			std::string doublequote = "\"";
			std::string ahref = "<a href=" + doublequote;
			std::string https = " https";
			std::string githubcom = https + "://github.com";
			std::string::size_type rep = gplzip1.find(ahref);
			if (rep != std::string::npos)
				gplzip1.replace(rep, ahref.length(), githubcom);
			std::string newline = "\n";
			size_t pos = gplzip1.find(doublequote);
			while (pos != std::string::npos)
			{
				gplzip1.replace(pos, doublequote.size(), newline);
				pos = gplzip1.find(doublequote, pos + newline.size());
			}
			ReadLinegplzip22();
			repbegtext << gplzip22;
		}
		repbegtext.close();
		std::string dwnld_URL2 = gplzip22;
		std::string savepath2 = Directory::get_current_dir() + "\\youtube-dl.exe";
		std::wstring downloadfile2 = functions::s2ws(dwnld_URL2);
		LPCWSTR downloadingfile2 = downloadfile2.c_str();
		std::wstring savefile2 = functions::s2ws(savepath2);
		LPCWSTR savingfile2 = savefile2.c_str();
		URLDownloadToFileW(NULL, downloadingfile2, savingfile2, 0, NULL);
	}
	youtubedll.close();
	return 0;
}

bool checkfordownload2 = 1;
std::string gplzip;
int ReadLinegplzip()
{
	std::ifstream file(Directory::get_current_dir() + "\\ffmpeg.txt");
	std::string gpl = "-win64-gpl.zip";
	std::string lpg = "releases/download/autobuild-";
	std::regex e("\\b(" + lpg + ")([^ ]*)" + "\\b(" + gpl + ")([& ]*)");
	std::string gpll;
	while (std::getline(file, gpll))
	{
		std::sregex_iterator next(gpll.begin(), gpll.end(), e);
		std::sregex_iterator end;
		while (next != end) {
			std::smatch match = *next;
			std::cout << match.str() << "\n";
			if (checkfordownload2)
			{
				gplzip = gpll;
				checkfordownload2 = 0;
			}
			next++;
		}
	}

	file.close();
	return 0;
}

std::string gplzip2;
int ReadLinegplzip2()
{
	std::istringstream file(gplzip);
	std::string gpl = "-win64-gpl.zip";
	std::string lpg = "releases/download/autobuild-";
	std::regex e("\\b(" + lpg + ")([^ ]*)" + "\\b(" + gpl + ")([& ]*)");
	std::string gpll;
	while (std::getline(file, gpll))
	{
		if (regex_search(gpll, e))
			gplzip2 = gpll + "\n";
	}
	return 0;
}

std::string ffmpeg::gplzip3;
int ReadLinegplzip3()
{
	std::istringstream file(ffmpeg::gplzip3);
	std::string lpg = "ffmpeg-N-";
	std::regex e{ "\\b" + lpg + "\\b" };
	std::string gpll;
	while (std::getline(file, gpll))
	{
		if (regex_search(gpll, e))
			ffmpeg::gplzip3 = gpll + "\n";
	}
	return 0;
}

int deleteforlderffmpeg()
{
	std::string doubleslash = "\\";
	std::string doublequote = "\"";
	std::string taskdirectory = Directory::get_current_dir() + doubleslash;
	std::string cmd = "c:\\windows\\system32\\cmd.exe";
	std::string taskdirectory1 = " /c rmdir /s /q " + doublequote;
	std::string taskdirectory2 = taskdirectory1 + taskdirectory;
	std::string taskdirectory3 = "ffmpeg\\" + doublequote;
	std::string taskdirectory4 = taskdirectory2 + taskdirectory3;
	std::wstring progpath = functions::s2ws(cmd);
	LPCWSTR lpprogpath = progpath.c_str();
	std::wstring commandd = functions::s2ws(taskdirectory4);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	return 0;
}
int deletearchiveffmpeg()
{
	std::string doubleslash = "\\";
	std::string doublequote = "\"";
	std::string taskdirectory = Directory::get_current_dir() + doubleslash;
	std::string cmd = "c:\\windows\\system32\\cmd.exe";
	std::string taskdirectory1 = " /c del /s /q ";
	std::string taskdirectory2 = taskdirectory1 + taskdirectory;
	std::string taskdirectory3 = "ffmpeg.zip";
	std::string taskdirectory4 = taskdirectory2 + taskdirectory3;
	std::wstring progpath = functions::s2ws(cmd);
	LPCWSTR lpprogpath = progpath.c_str();
	std::wstring commandd = functions::s2ws(taskdirectory4);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	deleteforlderffmpeg();
	return 0;
}
int powershellExecutionPolicy()
{
	std::string doubleslash = "\\";
	std::string doublequote = "\"";
	std::string taskdirectory = Directory::get_current_dir() + doubleslash;
	std::string cmd = "c:\\windows\\system32\\cmd.exe";
	std::string taskdirectory1 = " cmd /c powershell Set-ExecutionPolicy -Scope CurrentUser Unrestricted && exit";
	std::wstring progpath = functions::s2ws(cmd);
	LPCWSTR lpprogpath = progpath.c_str();
	std::wstring commandd = functions::s2ws(taskdirectory1);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	return 0;
}

int extractffmpeg()
{
	powershellExecutionPolicy();
	std::string doubleslash = "\\";
	std::string doublequote = "\"";
	std::string taskdirectory = Directory::get_current_dir() + doubleslash;
	std::string cmd = "c:\\windows\\system32\\cmd.exe";
	std::string taskdirectory2 = " /c powershell Expand-Archive -Path " + taskdirectory;
	std::string taskdirectory3 = taskdirectory2 + "ffmpeg.zip ";
	std::wstring progpath = functions::s2ws(cmd);
	LPCWSTR lpprogpath = progpath.c_str();
	std::string namesfiles0 = "-DestinationPath " + taskdirectory;
	std::string namesfiles1 = namesfiles0 + "ffmpeg\\";
	std::string namesandfiles = taskdirectory3 + namesfiles1;
	std::wstring commandd = functions::s2ws(namesandfiles);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE);
	return 0;
}

int moveffmpeg()
{
	std::string zipgpl = "";
	std::ifstream ffmpeg;
	ffmpeg.open(Directory::get_current_dir() + "\\ffmpegfolder.txt");
	if (ffmpeg)
	{
		ffmpeg >> zipgpl;
	}
	ffmpeg.close();
	std::string doubleslash = "\\";
	std::string doublequote = "\"";
	std::string taskdirectory = Directory::get_current_dir() + doubleslash;
	std::string cmd = "c:\\windows\\system32\\cmd.exe";
	std::string taskdirectory2 = " /c move " + taskdirectory;
	std::string taskdirectory3 = taskdirectory2 + "ffmpeg\\";
	std::string taskdirectory4 = taskdirectory3 + zipgpl;
	std::string taskdirectory5 = taskdirectory4 + "\\bin\\ffmpeg.exe ";
	std::wstring progpath = functions::s2ws(cmd);
	LPCWSTR lpprogpath = progpath.c_str();
	std::string namesandfiles = taskdirectory5 + taskdirectory;
	std::wstring commandd = functions::s2ws(namesandfiles);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	return 0;
}

int moveffplay()
{
	std::string zipgpl = "";
	std::ifstream ffmpeg;
	ffmpeg.open(Directory::get_current_dir() + "\\ffmpegfolder.txt");
	if (ffmpeg)
	{
		ffmpeg >> zipgpl;
	}
	ffmpeg.close();
	std::string doubleslash = "\\";
	std::string doublequote = "\"";
	std::string taskdirectory = Directory::get_current_dir() + doubleslash;
	std::string cmd = "c:\\windows\\system32\\cmd.exe";
	std::string taskdirectory2 = " /c move " + taskdirectory;
	std::string taskdirectory3 = taskdirectory2 + "ffmpeg\\";
	std::string taskdirectory4 = taskdirectory3 + zipgpl;
	std::string taskdirectory5 = taskdirectory4 + "\\bin\\ffplay.exe ";
	std::wstring progpath = functions::s2ws(cmd);
	LPCWSTR lpprogpath = progpath.c_str();
	std::string namesandfiles = taskdirectory5 + taskdirectory;
	std::wstring commandd = functions::s2ws(namesandfiles);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	return 0;
}

int moveffprobe()
{
	std::string zipgpl = "";
	std::ifstream ffmpeg;
	ffmpeg.open(Directory::get_current_dir() + "\\ffmpegfolder.txt");
	if (ffmpeg)
	{
		ffmpeg >> zipgpl;
	}
	ffmpeg.close();
	std::string doubleslash = "\\";
	std::string doublequote = "\"";
	std::string taskdirectory = Directory::get_current_dir() + doubleslash;
	std::string cmd = "c:\\windows\\system32\\cmd.exe";
	std::string taskdirectory2 = " /c move " + taskdirectory;
	std::string taskdirectory3 = taskdirectory2 + "ffmpeg\\";
	std::string taskdirectory4 = taskdirectory3 + zipgpl;
	std::string taskdirectory5 = taskdirectory4 + "\\bin\\ffprobe.exe ";
	std::wstring progpath = functions::s2ws(cmd);
	LPCWSTR lpprogpath = progpath.c_str();
	std::string namesandfiles = taskdirectory5 + taskdirectory;
	std::wstring commandd = functions::s2ws(namesandfiles);
	LPCWSTR lpcommand = commandd.c_str();
	ShellExecuteW(0, L"open", lpprogpath, lpcommand, 0, SW_HIDE/*SW_SHOW*/);
	return 0;
}

bool boolyd1 = 1;
bool yd::loopbool = 0;
int yd::looptimer()
{
	if (yd::loopbool)
	{
	if (boolyd1)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		int getTimer = milliseconds;
		if (getTimer % 1500 == 0)
		{
			extractffmpeg();
			boolyd1 = 0;
		}
	}
	if (!boolyd1)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		int getTimer = milliseconds;
		if (getTimer % 2000 == 0)
		{
			moveffmpeg();
			moveffplay();
			moveffprobe();
			yd::loopbool = 0;
		}
	}
	}
	return 0;
}

int moveffprog()
{
	yd::loopbool = 1;
	if (yd::loopbool)
	{
		yd::looptimer();
	}
	return 0;
}

int dlyoutube::downloading2()
{
	std::ifstream ffmpeg;
	ffmpeg.open(Directory::get_current_dir() + "\\ffmpeg.zip");
	if (!ffmpeg)
	{
		/*std::string dwnld_URL = "https://github.com/BtbN/FFmpeg-Builds/releases/download/autobuild-2021-04-09-12-38/ffmpeg-N-101901-gb593abda6c-win64-gpl.zip";*/
		std::string dwnld_URL = "https://github.com/BtbN/FFmpeg-Builds/releases";
		std::string savepath = Directory::get_current_dir() + "\\ffmpeg.txt";
		std::wstring downloadfile = functions::s2ws(dwnld_URL);
		LPCWSTR downloadingfile = downloadfile.c_str();
		std::wstring savefile = functions::s2ws(savepath);
		LPCWSTR savingfile = savefile.c_str();
		URLDownloadToFileW(NULL, downloadingfile, savingfile, 0, NULL);
		ReadLinegplzip();
		std::string taskdirectory2 = Directory::get_current_dir() + "\\ffmpegurl.txt";
		std::ofstream repbegtext(taskdirectory2);
		if (repbegtext.is_open())
		{
			std::string doublequote = "\"";
			std::string ahref = "<a href=" + doublequote;
			std::string https = " https";
			std::string githubcom = https + "://github.com";
			std::string::size_type rep = gplzip.find(ahref);
			if (rep != std::string::npos)
				gplzip.replace(rep, ahref.length(), githubcom);
			std::string newline = "\n";
			size_t pos = gplzip.find(doublequote);
			while (pos != std::string::npos)
			{
				gplzip.replace(pos, doublequote.size(), newline);
				pos = gplzip.find(doublequote, pos + newline.size());
			}
			ReadLinegplzip2();
			repbegtext << gplzip2;
		}
		repbegtext.close();
		std::string dwnld_URL2 = gplzip2;
		std::string savepath2 = Directory::get_current_dir() + "\\ffmpeg.zip";
		std::wstring downloadfile2 = functions::s2ws(dwnld_URL2);
		LPCWSTR downloadingfile2 = downloadfile2.c_str();
		std::wstring savefile2 = functions::s2ws(savepath2);
		LPCWSTR savingfile2 = savefile2.c_str();
		URLDownloadToFileW(NULL, downloadingfile2, savingfile2, 0, NULL);
		std::string line = "\n";
		std::string ffmpegn = "ffmpeg-N";
		std::string ffmpegnew = line + "ffmpeg-N";
		std::string wingpl = "-win64-gpl" + line;
		std::string wingplzip = "-win64-gpl.zip";
		ffmpeg::gplzip3 = gplzip2;
		std::string::size_type rep1 = ffmpeg::gplzip3.find(ffmpegn);
		if (rep1 != std::string::npos)
			ffmpeg::gplzip3.replace(rep1, ffmpegn.length(), ffmpegnew);

		std::string::size_type rep2 = ffmpeg::gplzip3.find(wingplzip);
		if (rep2 != std::string::npos)
			ffmpeg::gplzip3.replace(rep2, wingplzip.length(), wingpl);
		std::string taskdirectory3 = Directory::get_current_dir() + "\\ffmpegfolder.txt";
		std::ofstream repbegtext2(taskdirectory3);
		if (repbegtext2.is_open())
		{
			ReadLinegplzip3();
			repbegtext2 << ffmpeg::gplzip3;
		}
		repbegtext2.close();
	}
	ffmpeg.close();
	moveffprog();
	return 0;
}
