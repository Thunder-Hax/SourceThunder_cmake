#include "stdafx.h"
#include "base64.h"
#include "base64caller.h"
#include "menu.h"
#include <iostream> 
#include <string> 
#include <sstream>
#include <fstream> 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <functional>

#include <vector>
#include <array>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <memory>
#include <iterator>
#include <algorithm>
#include "pugixml.h"
#include "dirent.h"
//#include <transact.h>
#include "Menu.h"
#include "Gui.h"
//#include "..\source\Natives\natives.h"
//#include "..\source\Natives\natives2.h"

#include "..\source\Auth\Networking\sha512.hh"
#include "..\source\Auth\Networking\Web2.0.h"

//#include "..\source\Util\FileLogger.h"

#include "Support.h"

#include <tchar.h>
#include <stdlib.h>

#include "MD5.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
//bool firsttimesetting = true;

#pragma execution_character_set("utf-8")

std::string load::namechanger = "";
bool load::namechangers = 0;

float Settings2::menuX = 0.17f;
float Settings2::menuY = 0.00f;
float Settings2::timesX = /*0.17f*/0.110f;
float Settings2::timesX2 = /*0.17f*/0.110f;

int FeaturesOnline::dixhuit2 = 18;
float FeaturesOnline::zeropointdeuxcentvingthuit2 = 0.228f;
float FeaturesOnline::zeropointcentsoixantequinze2 = 0.175f;
float FeaturesOnline::zeropointcentsoixantequinze = 0.175f;
float FeaturesOnline::zeropointcentvingt = -0.106300f;
float FeaturesOnline::zeropointcentvingt2 = 0.053700f; //0.055f
float FeaturesOnline::zeropointdeuxcentvingthuit = 0.228f;
float FeaturesOnline::zeropointcentvingttrois = 0.003000f; //0.123f
float FeaturesOnline::zeropointcentvingttrois2 = 0.793000f;/*0.011000f*/
int FeaturesOnline::dixhuit = 18;

void Menu1::AddSmallInfoTimes(char* text, short line)
{
	if (Settings2::timesX < 0.78f)
	{
		if (line == 1) {
			Menu::Drawing::Rect(Menu::Settings::optionRect, { Settings2::timesX + FeaturesOnline::zeropointcentsoixantequinze, ((FeaturesOnline::dixhuit * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, FeaturesOnline::dixhuit * 0.035f + -0.193f });
		}
		Menu::Drawing::Text(text, Menu::Settings::count, { Settings2::timesX + FeaturesOnline::zeropointcentvingt, (line * 0.020f) + FeaturesOnline::zeropointcentvingttrois }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Menu::Drawing::Rect(Menu::Settings::optionRect, { Settings2::timesX - FeaturesOnline::zeropointcentsoixantequinze, ((FeaturesOnline::dixhuit * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, FeaturesOnline::dixhuit * 0.035f + -0.193f });
		}
		Menu::Drawing::Text(text, Menu::Settings::count, { Settings2::timesX - FeaturesOnline::zeropointdeuxcentvingthuit, (line * 0.020f) + FeaturesOnline::zeropointcentvingttrois }, { 0.375f, 0.375f }, false);
	}
}

void Menu1::AddSmallInfoTimes2(char* text, short line)
{
	if (Settings2::timesX2 < 0.78f)
	{
		if (line == 1) {
			Menu::Drawing::Rect(Menu::Settings::optionRect, { Settings2::timesX2 + FeaturesOnline::zeropointcentsoixantequinze2, ((FeaturesOnline::dixhuit2 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, FeaturesOnline::dixhuit2 * 0.035f + -0.193f });
		}
		Menu::Drawing::Text(text, Menu::Settings::count, { Settings2::timesX2 + FeaturesOnline::zeropointcentvingt2, (line * 0.020f) + FeaturesOnline::zeropointcentvingttrois2 }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Menu::Drawing::Rect(Menu::Settings::optionRect, { Settings2::timesX2 - FeaturesOnline::zeropointcentsoixantequinze2, ((FeaturesOnline::dixhuit2 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, FeaturesOnline::dixhuit2 * 0.035f + -0.193f });
		}
		Menu::Drawing::Text(text, Menu::Settings::count, { Settings2::timesX2 - FeaturesOnline::zeropointdeuxcentvingthuit2, (line * 0.020f) + FeaturesOnline::zeropointcentvingttrois2 }, { 0.375f, 0.375f }, false);
	}
}
time_t mktime(struct tm* timeptr);
bool timer::realtime222 = false;
void timer::realtimes()
{
	/*if (firsttimesetting)
	{
	FeaturesOnline::zeropointcentvingt = -0.106300f;
	FeaturesOnline::zeropointcentvingttrois = 0.011000f;
	firsttimesetting = false;
	}*/
	char buffer[80];
	time_t rawtime;
	struct tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
	Menu1::AddSmallInfoTimes(buffer, 0);
	//2080-12-25 05:04:17
	//MjA4MC0xMi0yNSAwNTowNDoxNw==
}

void makeusersfolderLogin2() {
	std::string users101 = getenv("appdata");
	std::string usersnames1 = users101 + "\\ThunderMenu\\Login\\";
#include <windows.h>
	std::wstring ssusersnames1 = functions::s2ws(usersnames1);
	LPCWSTR sssusersnames1 = ssusersnames1.c_str();
	if (CreateDirectoryW(sssusersnames1, NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}

void makeusersfolderThunderMenu() {
	std::string thunderfolder = "ThunderMenu\\";
#include <windows.h>
	std::wstring ssthunderfolder = functions::s2ws(thunderfolder);
	LPCWSTR sssthunderfolder = ssthunderfolder.c_str();
	if (CreateDirectoryW(sssthunderfolder, NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}


void notification2::notifyMap2(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	CHooking::draw_notification(FALSE, FALSE);
}	void notifyMap2(std::string str) { notifyMap2(&str[0]); }

char timebuffer[80];
std::string timesbuffer = "";

void getrealtimes()
{
	time_t rawtime;
	struct tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(timebuffer, 80, "%Y-%m-%d %H:%M:%S", info);
	authentification2::realtimes1 = timebuffer;
}

std::string authentification2::realtimes1 = "";
std::string verifydatentimes = "";
bool earlier = 0;
void comparetimes() {
	char* date11 = new char[authentification2::keytimesbase64.length() + 1];
	strcpy(date11, authentification2::keytimesbase64.c_str());

	char* date22 = new char[authentification2::realtimes1.length() + 1];
	strcpy(date22, authentification2::realtimes1.c_str());
	notification2::notifyMap2(date11);
	notification2::notifyMap2(date22);
	struct std::tm tm1;
	std::istringstream ss1(authentification2::keytimesbase64.c_str());
	ss1 >> std::get_time(&tm1, "%Y-%m-%d %H:%M:%S");
	std::time_t d1 = mktime(&tm1);
	struct std::tm tm2;
	std::istringstream ss2(authentification2::realtimes1.c_str());
	ss2 >> std::get_time(&tm2, "%Y-%m-%d %H:%M:%S");
	std::time_t d2 = mktime(&tm2);

	if (d1 == d2) {
		notification2::notifyMap2("equal");
		verifydatentimes = "equal";
		earlier = 1;
		//std::string encode1121 = getenv("appdata");
		//std::ofstream encode3121(encode1121 + "\\ThunderMenu\\equal.encoded"); //write
		//encode3121 << "equal";
	}
	if (d2 > d1) {
		notification2::notifyMap2("later");
		verifydatentimes = "later";
		earlier = 0;
		//std::string encode11213 = getenv("appdata");
		//std::ofstream encode31213(encode11213 + "\\ThunderMenu\\later.encoded"); //write
		//encode31213 << "later";
	}
	if (d2 < d1) {
		notification2::notifyMap2("earlier");
		verifydatentimes = "earlier";
		earlier = 1;
		//std::string encode11212 = getenv("appdata");
		//std::ofstream encode31212(encode11212 + "\\ThunderMenu\\earlier.encoded"); //write
		//encode31212 << "earlier";
	}
}

void login2::loginin() {
	/*std::string gettext11 = getenv("appdata");
	std::ifstream gets41;
	gets41.open(gettext11 + "\\ThunderMenu\\Login\\user.Thunder");
	if (!gets41)
	{
		makeusersfolderLogin();
	}*/
	std::ifstream getsthunder;
	getsthunder.open("ThunderMenu\\");
	if (!getsthunder)
	{
		makeusersfolderThunder();
	}
	notification2::notifyMap2("Please Enter Your Username");
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Username", "", "", "", "", "", 32);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
	{
		authentification2::username2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	}
	notification2::notifyMap2("Please Enter Your Password");
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Password", "", "", "", "", "", 32);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
	{
		authentification2::password2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	}
	/*authentification2::username2 = "Thunder";
	authentification2::password2 = "Menu";*/

	if (!authentification2::username_password2) {
		authentification2::username2 = "Thunder";
		authentification2::password2 = "Menu";
	}
	authentification2::is_user_authed2();
	WAIT(500);
	/*if (!authentification2::username_password2) {
		AUDIO::PLAY_SOUND_FRONTEND(-1, "Hack_Failed", "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 1);
		notification2::notifyMap2("Please Enter Your Username");
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Username", "", "", "", "", "", 32);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
		{
			authentification2::username2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		}
		notification2::notifyMap2("Please Enter Your Password");
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Password", "", "", "", "", "", 32);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
		{
			authentification2::password2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		}
		authentification2::is_user_authed2();
		WAIT(500);
		if (!authentification2::username_password2) {
			AUDIO::PLAY_SOUND_FRONTEND(-1, "Hack_Failed", "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 1);
			WAIT(2000);
			WinExec("Taskkill /F /IM gta5.exe /F", false);
			Log::Fatal("User Error 404: Not Found");
			if (authentification2::username_password2 == false) {
				Features::vipplus = false;
			}
		}
	}*/
	if (authentification2::username_password2) {
		/*char Auth2[1];
		std::string Authstring;
		std::string Authpath2344;
		Authpath2344 = getenv("appdata");
		std::ifstream Auth234;
		Auth234.open(Authpath2344 + "\\ThunderMenu\\AuthsSounds.Thunder");
		if (Auth234) {
			Auth234 >> Auth2;
			Authstring = Auth2;
			if (Authstring.length() == NULL) {*/
			if (Features::Sounds1 == "")
			{
				/*AUDIO::PLAY_SOUND_FRONTEND(-1, "RANK_UP", "HUD_AWARDS", 1);*/
				AUDIO::PLAY_SOUND_FRONTEND(-1, "RANK_UP", "HUD_AWARDS", 0);
			}
			else {
			/*initialize::soundsauth(Authstring);*/
			initialize::soundsauth(Features::Sounds1);
			char* sSounds1 = new char[initialize::Sounds1.length() + 1];
			strcpy(sSounds1, initialize::Sounds1.c_str());
			char* sSounds2 = new char[initialize::Sounds2.length() + 1];
			strcpy(sSounds2, initialize::Sounds2.c_str());
			/*AUDIO::PLAY_SOUND_FRONTEND(-1, sSounds1, sSounds2, 1);*/
			AUDIO::PLAY_SOUND_FRONTEND(-1, sSounds1, sSounds2, 0);
		}
		//else {
		//	/*AUDIO::PLAY_SOUND_FRONTEND(-1, "Success", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);*/
		//	AUDIO::PLAY_SOUND_FRONTEND(-1, "Success", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
		//}
		/*std::string path;
		path = getenv("appdata");
		std::ifstream good;
		good.open(path + "\\ThunderMenu\\login\\user.thunder");
		if (good) {
			char user[1];
			char password[2];
			good >> user;
			good >> password;
			notification2::notifyMap2(user);
			notification2::notifyMap2(password, 2);*/
			/*if (authentification2::username2 == "")
			{
				login2::loginin();
			}
			else
			{*/
			char* username1 = const_cast<char*>(authentification2::username2.c_str());
			char* password1 = const_cast<char*>(authentification2::password2.c_str());

			/*authentification2::username2 = "Thunder";
			authentification2::password2 = "Menu";*/

			notification2::notifyMap2(username1);
			notification2::notifyMap2(password1);

			if (authentification2::username_password2 == true) {
				Features::vipplus = true;
			}
			PCHAR section_haxValues = "Thunder-Menu";/////////
			auto& ini = MenuConfig::iniFile;
			ini.SetValue(section_haxValues, "user", authentification2::username2.c_str());
			ini.SetValue(section_haxValues, "pass", authentification2::password2.c_str());
			//save
			ini.SaveFile((GetPathffA(Pathff::ThunderMenu, true) + "ThunderConfig.ini").c_str());
		//}
	}
}

void login2::loginin2() {
	/*notification2::notifyMap2("Login");
	std::string gettext11 = getenv("appdata");
	std::ifstream gets41;
	gets41.open(gettext11 + "\\ThunderMenu\\Login\\user.Thunder");
	if (!gets41)
	{
		makeusersfolderLogin();
	}*/
	std::ifstream getsthunder;
	getsthunder.open("ThunderMenu\\");
	if (!getsthunder)
	{
		makeusersfolderThunder();
	}

	auto& ini = MenuConfig::iniFile;
	PCHAR section_haxValues = "hax-values";/////////
	authentification2::username2 = ini.GetValue(section_haxValues, "user", authentification2::username2.c_str());
	authentification2::password2 = ini.GetValue(section_haxValues, "pass", authentification2::password2.c_str());
	/*authentification2::username2 = "Thunder";
	authentification2::password2 = "Menu";*/
	if (!authentification2::username_password2) {
		authentification2::username2 = "Thunder";
		authentification2::password2 = "Menu";
	}
	authentification2::is_user_authed2();
	WAIT(500);
	//if (!authentification2::username_password2) {
	//	AUDIO::PLAY_SOUND_FRONTEND(-1, "Hack_Failed", "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 1);
	//	/*AUDIO::PLAY_SOUND_FRONTEND(-1, "Hack_Failed", "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);*/
	//	notification2::notifyMap2("Please Enter Your Username");
	//	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Username", "", "", "", "", "", 32);
	//	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	//	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
	//	{
	//		authentification2::username2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	//	}
	//	notification2::notifyMap2("Please Enter Your Password");
	//	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Password", "", "", "", "", "", 32);
	//	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	//	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
	//	{
	//		authentification2::password2 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
	//	}
	//	authentification2::is_user_authed2();
	//	WAIT(1);
	//	if (!authentification2::username_password2) {
	//		AUDIO::PLAY_SOUND_FRONTEND(-1, "Hack_Failed", "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 1);
	//		/*AUDIO::PLAY_SOUND_FRONTEND(-1, "Hack_Failed", "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);*/
	//		WAIT(2000);
	//		WinExec("Taskkill /F /IM gta5.exe /F", false);
	//		Log::Fatal("User Error 404: Not Found");
	//		/*if (authentification2::username_password2 == false) {*/
	//		Features::vipplus = false;
	//		/*}*/
	//	}
	//}
	if (authentification2::username_password2) {
		/*char Auth2[1];
		std::string Authstring;
		std::string Authpath2344;
		Authpath2344 = getenv("appdata");
		std::ifstream Auth234;
		Auth234.open(Authpath2344 + "\\ThunderMenu\\AuthsSounds.Thunder");
		if (Auth234) {
			Auth234 >> Auth2;
			Authstring = Auth2;
			if (Authstring.length() == NULL) {*/
		if (Features::Sounds1 == "")
		{
			AUDIO::PLAY_SOUND_FRONTEND(-1, "RANK_UP", "HUD_AWARDS", 1);
		}
		else if (Features::Sounds1 != "")
		{
			/*initialize::soundsauth(Authstring);*/
			initialize::soundsauth(Features::Sounds1);
			char* sSounds1 = new char[initialize::Sounds1.length() + 1];
			strcpy(sSounds1, initialize::Sounds1.c_str());
			char* sSounds2 = new char[initialize::Sounds2.length() + 1];
			strcpy(sSounds2, initialize::Sounds2.c_str());
			/*WAIT(500);*/
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			/*AUDIO::PLAY_SOUND_FRONTEND(-1, sSounds1, sSounds2, 1);*/
			AUDIO::PLAY_SOUND_FRONTEND(-1, sSounds1, sSounds2, 1);
		}
		//else {
		//	AUDIO::PLAY_SOUND_FRONTEND(-1, "Success", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 1);
		//	/*AUDIO::PLAY_SOUND_FRONTEND(-1, "Success", "DLC_HEIST_HACKING_SNAKE_SOUNDS", 0);*/
		//}
	//	std::string  Notifpath;
	//	Notifpath = getenv("appdata");
	//	std::ifstream Notifications0001;
	//	Notifications0001.open(Notifpath + "\\ThunderMenu\\Notifications.Thunder");
	//	if (Notifications0001) {
	//	}
	//	else
	//	{
	//		std::string  STRIPpath;
	//		STRIPpath = getenv("appdata");
	//		std::ofstream Notifications0002(STRIPpath + "\\ThunderMenu\\Notifications.Thunder");
	//		Notifications0002 << "CHAR_STRIPPER_CHEETAH";
	//	/*}*/
	//}
		if (Features::Notify == "") {
			std::string s;
			std::stringstream csc;
			csc << "CHAR_STRIPPER_CHEETAH";
			csc >> Features::Notify;
			UI::SET_TEXT_OUTLINE();
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Thunder Menu\n  ~r~Ultimate Version: 2.2\r\n");
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Thunder Menu\n", "~r~Ultimate Version: 2.2\r\n", 1, "~w~Thunder Menu\n ~r~Ultimate Version: 2.2\r\n", 9, 1);
			CHooking::draw_notification(false, false);
		}
		if (Features::Notify != "") {
			UI::SET_TEXT_OUTLINE();
			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Thunder Menu VIP\n  ~r~Ultimate Version: 2.2 Fair Use\r\n");
			/*Notifications2 >> data;*/
			char* data = const_cast<char*>(Features::Notify.c_str());
			/*WAIT(500);*/
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2((char*)data, (char*)data, 1, 8, "~w~Thunder Menu VIP\n", "~r~Ultimate Version: 2.2 Fair Use\r\n", 1, "~w~Thunder Menu VIP\n ~r~Ultimate Version: 2.2 Fair Use\r\n", 9, 1);
			CHooking::draw_notification(false, false);
		}

		//char data[32];
		//std::string  path2;
		//path2 = getenv("appdata");
		//std::ifstream Notifications2;
		//Notifications2.open(path2 + "\\ThunderMenu\\Notifications.Thunder");
		//if (Notifications2) {
		//	UI::SET_TEXT_OUTLINE();
		//	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		//	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Thunder Menu VIP\n  ~r~Ultimate Version: 2.2 Fair Use\r\n");
		//	Notifications2 >> data;
		//	/*WAIT(500);*/
		//	std::this_thread::sleep_for(std::chrono::milliseconds(1));
		//	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2((char*)data, (char*)data, 1, 8, "~w~Thunder Menu VIP\n", "~r~Ultimate Version: 2.2 Fair Use\r\n", 1, "~w~Thunder Menu VIP\n ~r~Ultimate Version: 2.2 Fair Use\r\n", 9, 1);
		//	CHooking::draw_notification(false, false);
		//}
		//else
		//{
		//	UI::SET_TEXT_OUTLINE();
		//	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		//	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Thunder Menu\n  ~r~Ultimate Version: 2.2\r\n");
		//	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Thunder Menu\n", "~r~Ultimate Version: 2.2\r\n", 1, "~w~Thunder Menu\n ~r~Ultimate Version: 2.2\r\n", 9, 1);
		//	CHooking::draw_notification(false, false);
		//}
		/*if (authentification2::username2 == "")
		{
			login2::loginin();
		}
		else
		{*/
			char* username1 = const_cast<char*>(authentification2::username2.c_str());
			char* password1 = const_cast<char*>(authentification2::password2.c_str());
			notification2::notifyMap2(username1);
			notification2::notifyMap2(password1);
			if (authentification2::username_password2 == true) {
				Features::vipplus = true;
			}
		//}
	}
}
//void loaded::users()
//{
//	//WAIT(1);
//	//std::this_thread::sleep_for(std::chrono::milliseconds(1));
//	if (authentification2::username2 != "")
//	{
//		char* username1 = const_cast<char*>(authentification2::username2.c_str());
//		char* password1 = const_cast<char*>(authentification2::password2.c_str());
//		/*char* username1 = new char[authentification::username1.size() + 1];
//		std::copy(authentification::username1.begin(), authentification::username1.end(), username1);
//		char* password1 = new char[authentification::password1.size() + 1];
//		std::copy(authentification::password1.begin(), authentification::password1.end(), password1);*/
//
//		notification2::notifyMap2((char*)username1);
//		notification2::notifyMap2((char*)password1);
//		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
//		login2::loginin2();
//		Log::Msg("log2");
//	}
//	else
//		if (authentification2::username2 == "")
//		{
//			login2::loginin();
//			Log::Msg("log1");
//		}
//}
//void initialize2::userpassword2() {
//	notification2::notifyMap2("~r~Thunder Ultimate function loaded");
//	/*char ThunderMenu[255];
//	strcpy_s(ThunderMenu, "ThunderMenu/");
//	strcat_s(ThunderMenu, "Thunder.ytd");
//	int textureID = -1;
//	Hooking::pRegisterFile(&textureID, ThunderMenu, true, "Thunder.ytd", false);
//	if (textureID != -1)
//	{
//		Log::Msg("ThunderMenu register OK");
//	}
//	else
//		Log::Msg("Failed to register ThunderMenu %s", ThunderMenu);*/
//	/*char Spacey[255];
//	strcpy_s(Spacey, "ThunderMenu/");
//	strcat_s(Spacey, "Spacey.ytd");
//	int SpaceyID = -1;
//	Hooking::pRegisterFile(&SpaceyID, Spacey, true, "Spacey.ytd", false);
//	if (SpaceyID != -1)
//	{
//		Log::Msg("Spacey register OK");
//	}
//	else
//		Log::Msg("Failed to register Spacey %s", Spacey);*/
//	//std::string userpath;
//	//userpath = getenv("appdata");
//	//std::ifstream good;
//	//good.open(userpath + "\\ThunderMenu\\login\\user.thunder");
//	//notification2::notifyMap2("User Verification ");
//	//if (good) {
//	//	char user[32];
//	//	char password[32];
//	//	good >> user;
//	//	good >> password;
//
//	//	/*WAIT(500);*/
//	//	std::this_thread::sleep_for(std::chrono::milliseconds(1));
//
//	//	notification2::notifyMap2(user);
//	//	notification2::notifyMap2(password, 2);
//
//	//	authentification2::username2 = user;
//	//	authentification2::password2 = password, 2;
//
//	//	/*WAIT(500);*/
//	//	std::this_thread::sleep_for(std::chrono::milliseconds(1));
//
//	//	login2::loginin2();
//	//}
//
//DWORD ticks = GetTickCount64();
//DWORD milliseconds = ticks % 1000;
//ticks /= 1000;
//DWORD seconds = ticks % 60;
//int getTimer = seconds;
//	if (getTimer % 1 == 0)
//	{
//		/*if (!authentification2::username_password2) {
//			if (getTimer % 1 == 0)
//			{*/
//				loaded::users();
//			/*}
//		}
//		else {
//			if (authentification2::username_password2) {
//				loaded::users();
//			}*/
//		//}
//	}
//}


int stringtochararray(string s)
{
	// assigning value to string s
	// declaring character array : p
	char* p = new char[s.length() + 1];
	strcpy(p, s.c_str());
	int i;
	for (i = 0; i < sizeof(p); i++) {
		p[i] = s[i];
		cout << p[i];
	}
	return (char)p;
}

int numletter;
std::string EnterMessages;
class X {
public:
	char message[255];
	char ch;
	int i;
	int key;
	int array;
	int lens;
};
X x{};
char* mytest2;
std::string textconvert;
int ceasarcipherencode(std::string messages)
{
	std::string newline = "\n";
	messages = messages + newline;
	x.message[messages.length() + 1];
	strcpy(x.message, messages.c_str());
	numletter = strlen(x.message);
	if (numletter > 1)
	{
		x.key = +1;
	}
	if (numletter > 80)
	{
		x.key = +2;
	}
	for (x.i = 0; x.message[x.i] != '\0'; ++x.i) {
		x.ch = x.message[x.i];
		if (x.ch >= 'a' && x.ch <= 'z') {
			x.ch = x.ch + x.key;
			if (x.ch > 'z') {
				x.ch = x.ch - 'z' + 'a' - 1;
			}
			x.message[x.i] = x.ch;
		}
		else if (x.ch >= 'A' && x.ch <= 'Z') {
			x.ch = x.ch + x.key;
			if (x.ch > 'Z') {
				x.ch = x.ch - 'Z' + 'A' - 1;
			}
			x.message[x.i] = x.ch;
		}
	}

	mytest2 = x.message;
	textconvert = x.message;
	//std::cout << "Encrypted message: " << x.message << std::endl;
	/*return (char)mytest2;*/
	return 0;
}
int ceasarcipherdecode(std::string messages)
{
	std::string newline = "\n";
	messages = messages + newline;
	x.message[messages.length() + 1];
	strcpy(x.message, messages.c_str());
	numletter = strlen(x.message);
	if (numletter > 1)
	{
		x.key = +1;
	}
	if (numletter > 10)
	{
		x.key = +1;
	}
	if (numletter > 80)
	{
		x.key = +2;
	}
	for (x.i = 0; x.message[x.i] != '\0'; ++x.i) {
		x.ch = x.message[x.i];
		if (x.ch >= 'a' && x.ch <= 'z') {
			x.ch = x.ch - x.key;
			if (x.ch < 'a') {
				x.ch = x.ch + 'z' - 'a' + 1;
			}
			x.message[x.i] = x.ch;
		}
		else if (x.ch >= 'A' && x.ch <= 'Z') {
			x.ch = x.ch - x.key;
			if (x.ch > 'a') {
				x.ch = x.ch + 'Z' - 'A' + 1;
			}
			x.message[x.i] = x.ch;
		}
	}
	/*std::cout << "Decrypted message: " << x.message << std::endl;*/
	textconvert = x.message;
	return 0;
}

DWORD serialnumber = 0, maxcomponentlen = 0, filesystemflags = 0;
DWORD sizez;
std::string ConvertToString(DWORD value) { std::stringstream ss;    ss << std::hex << value;    return ss.str(); }


//#define MAX_size 255
//char systemfile[MAX_size];
//std::string numberserial;
//std::string componentlenmax;
//
//std::string md;
//
//int hwidinfo()
//{
//	char hwid[4096];
//	// total physical memory
//	MEMORYSTATUSEX statex;
//	statex.dwLength = sizeof(statex);
//	GlobalMemoryStatusEx(&statex);
//	sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);
//	TCHAR volumename[MAX_PATH + 1] = { 0 };
//	TCHAR filesystemname[MAX_PATH + 1] = { 0 };
//	// volume information	
//	GetVolumeInformation(_T("C:\\"), volumename, ARRAYSIZE(volumename), &serialnumber, &maxcomponentlen, &filesystemflags, filesystemname, ARRAYSIZE(filesystemname));
//	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
//	sizez = sizeof(computerName) / sizeof(computerName[0]);
//	GetComputerName(computerName, &sizez);
//	numberserial = (char*)ConvertToString(serialnumber).c_str();
//	componentlenmax = (char*)ConvertToString(maxcomponentlen).c_str();
//	wcstombs(systemfile, filesystemname, wcslen(filesystemname) + 1);
//	std::string addall = hwid + numberserial + systemfile + componentlenmax + "\n";
//	//printf((char*)addall.c_str());
//	//std::cout/* << "md5: " + addall + " "*/ << md5(addall) << std::endl;
//	md = md5(addall) + "\n";
//	/*system("pause");*/
//	return 0;
//}

#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#define MAX_size 255

char systemfile[MAX_size];
std::string numberserial;
std::string componentlenmax;
std::string md;

// Variables fictives pour compilation
//DWORD serialnumber = 0;
//DWORD maxcomponentlen = 0;
//DWORD filesystemflags = 0;

// Déclaration de ta vraie fonction MD5
std::string md5(const std::string& input);

int hwidinfo()
{
	// Total physical memory
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);

	char hwid[4096];
	sprintf_s(hwid, "%I64i", statex.ullTotalPhys / 1024);

	// Volume information
	TCHAR volumename[MAX_PATH + 1] = { 0 };
	TCHAR filesystemname[MAX_PATH + 1] = { 0 };
	GetVolumeInformation(_T("C:\\"), volumename, ARRAYSIZE(volumename),
		&serialnumber, &maxcomponentlen, &filesystemflags,
		filesystemname, ARRAYSIZE(filesystemname));

	// Computer name
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD sizez = ARRAYSIZE(computerName);
	GetComputerName(computerName, &sizez);

	// Convertir valeurs numériques
	numberserial = ConvertToString(serialnumber);
	componentlenmax = ConvertToString(maxcomponentlen);

#ifdef _UNICODE
	// Unicode -> ANSI
	wcstombs(systemfile, filesystemname, MAX_size);
#else
	// ANSI -> ANSI
	strncpy(systemfile, filesystemname, MAX_size);
	systemfile[MAX_size - 1] = '\0';
#endif

	// Concaténer toutes les informations
	std::string addall = std::string(hwid) + numberserial + systemfile + componentlenmax + "\n";

	// Calculer le MD5
	//md = md5(addall) + "\n";

	return 0;
}


#include <iostream>
#include <cstring>

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <codecvt>

#include <iostream>
#include <cstring>

// Convert const wchar_t* to wchar_t*
wchar_t* constWcharToWchar(const wchar_t* constStr) {
	size_t length = wcslen(constStr);
	wchar_t* wcharStr = new wchar_t[length + 1];
	wcscpy(wcharStr, constStr);
	return wcharStr;
}

//int main123() {
//	const wchar_t* constStr = L"Hello";
//	wchar_t* wcharStr = constWcharToWchar(constStr);
//	std::wcout << wcharStr << std::endl;
//	delete[] wcharStr; // Remember to free memory
//	return 0;
//}


//// Convert std::string to std::wstring
//std::wstring s2ws(const std::string& str) {
//	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
//	return converter.from_bytes(str);
//}
//
//wchar_t* wchart(const std::string& hello) {
//	// Convert std::string to std::wstring
//	std::wstring wstr = s2ws(hello);
//
//	// Allocate memory for a new wchar_t* string
//	wchar_t* mutableString = new wchar_t[wstr.length() + 1];
//
//	// Copy the const string to the mutable string
//	wcsncpy(mutableString, wstr.c_str(), wstr.length());
//
//	// Null-terminate the mutable string
//	mutableString[wstr.length()] = L'\0';
//
//	// Now you have a mutable copy of the const string
//	return mutableString;
//}
//
//int main321() {
//	std::string input = "hello";
//	wchar_t* result = wchart(input);
//	std::wcout << L"Mutable string: " << result << std::endl;
//	delete[] result; // Don't forget to free the allocated memory
//	return 0;
//}

//int wchart(std::string hello) {
//	// Example const wchar_t* string
//	const wchar_t* constString = L"hello";
//
//	// Get the length of the string
//	size_t length = wcslen(constString);
//
//	// Allocate memory for a new wchar_t* string
//	wchar_t* mutableString = new wchar_t[length + 1];
//
//	// Copy the const string to the mutable string
//	wcsncpy(mutableString, constString, length);
//
//	// Null-terminate the mutable string
//	mutableString[length] = L'\0';
//
//	// Now you have a mutable copy of the const string
//	//std::wcout << L"Mutable string: " << mutableString << std::endl;
//
//	// Don't forget to free the allocated memory
//	//delete[] mutableString;
//
//	return mutableString;
//}
//
//
//int main3() {
//	// Assuming urlbase64 and username2 are defined in authentification2 namespace
//	std::string users = authentification2::urlbase64 + authentification2::username2;
//
//	// Convert users to wstring
//	std::wstring ssUsers(users.begin(), users.end());
//
//	// Define ThunderMenu2 as a wide string
//	//const wchar_t* ThunderMenu2 = L"ssUsers";
//	const wchar_t ThunderMenu2[] = L"ssUsers"; // Example user agent
//	// Create net::requests object with ThunderMenu2 as the parameter
//	net::requests m_request(ThunderMenu2, false);
//
//	// Perform the Get2 operation and store the answer in a wstring
//	std::wstring answer = m_request.Get2(false, ssUsers);
//
//	// Convert the answer to a string
//	std::string sites(answer.begin(), answer.end());
//
//	// Assuming sit3s is defined in authentification2 namespace
//	authentification2::sit3s = sites;
//
//	return 0;
//}
namespace authentification2 {
	std::string authentification2::username2 = "";
	std::string authentification2::password2 = "";
	std::string authentification2::keydecodebase64 = "";
	std::string authentification2::keytimesbase64 = "";

	std::string authentification2::urldecodebase64 = "";
	std::string authentification2::urlbase64 = "";

	std::string authentification2::sit3s = "";
	bool authentification2::username_password2 = false;
	bool authentification2::is_user_authed2()
	{
		notification2::notifyMap2("~w~Authentication Verification");
		//std::string users = "https://raw.githubusercontent.com/3xploitch3ats/Thunder/master/" + authentification::username1;
		/*std::string users = "https://raw.githubusercontent.com/ThunderMenu/Users/master/" + authentification::username1;*/
		/*std::string users = "https://raw.githubusercontent.com/Thund3rM3nu/Usr/master/" + authentification2::username2;*/ //Thund3rM3nu
		std::string thunderuser = "aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL1RodW5kM3JNM251L1Vzci9tYXN0ZXIv";
		authentification2::urldecodebase64 = thunderuser;
		callerbase64::urlbase64caller();
		std::string users = authentification2::urlbase64 + authentification2::username2;
		std::wstring ssUsers;
		std::wstring sUsers(users.begin(), users.end());
		ssUsers = sUsers;
//#define ThunderMenu2 L"ssUsers"
		wchar_t* ThunderMenu2 = L"ssUsers";
		net::requests m_request(ThunderMenu2, false);
		std::wstring answer = m_request.Get2(false, ssUsers);
		std::string sites(answer.begin(), answer.end());
		authentification2::sit3s = sites;
		//string users10 = getenv("appdata");
		//ofstream users220(users10 + "\\ThunderMenu\\Login\\Password.txt"); //write
		//users220 << sites;
		int intone = atoi(authentification2::password2.c_str());
		int inttwo = atoi(authentification2::sit3s.c_str());
		if (intone == inttwo)
		{
			if (inttwo == 404)
			{
				notification2::notifyMap2("~r~Bad Username or Password");
				return 0;
			}
			else {
				/*std::string gettext11 = getenv("appdata");
				std::ifstream gets41;
				gets41.open(gettext11 + "\\ThunderMenu\\Login");
				if (!gets41)
				{
					makeusersfolderLogin();
				}
				std::string users1;
				users1 = getenv("appdata");
				std::ofstream users22(users1 + "\\ThunderMenu\\Login\\user.Thunder");
				users22 << "";
				users22 << authentification2::username2 + "\n";
				users22 << authentification2::password2 + "\n";*/

				std::string line;
				std::stringstream lines;
				lines << 2;
				lines >> line;
				std::istringstream stream(authentification2::sit3s.c_str());
				std::string linescode;
				std::getline(stream, line) >> linescode;
				//std::string encode1120= getenv("appdata");
				//std::ofstream encode3120(encode1120 + "\\ThunderMenu\\linescode.encoded"); //write
				//encode3120 << linescode;
				authentification2::keydecodebase64 = linescode;
				callerbase64::mainbase64caller();
				getrealtimes();
				comparetimes();

				/*WAIT(500);*/
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
				if (earlier)
				{
					authentification2::username_password2 = true;
					notification2::notifyMap2("~w~SuccessFully");
				}
			}
		}
		return 0;
	}
}

void callerbase64::mainbase64caller() {
	//-https://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp
		/*const std::string s = "";*/
		/*GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your key", "", "", "", "", "", 32);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
		{
			authentification::keydecodebase64 = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
		}*/

		/*const std::string s =
			"René Nyffenegger\n"
			"http://www.renenyffenegger.ch\n"
			"passion for data\n";*/

			/*std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(authentification::keydecodebase64.c_str()), authentification::keybase64.length());*/
	std::string decoded = base64_decode((authentification2::keydecodebase64.c_str()));

	/*std::cout << "encoded: " << std::endl << encoded << std::endl << std::endl;*/
	std::cout << "decoded: " << std::endl << decoded << std::endl;

	//std::string encode10 = getenv("appdata");
	//std::ofstream encode30(encode10 + "\\ThunderMenu\\encoded.encoded"); //write
	//encode30 << encoded + "\n";
	authentification2::keytimesbase64 = decoded;

	//std::string encode11 = getenv("appdata");
	//std::ofstream encode31(encode11 + "\\ThunderMenu\\decoded.encoded"); //write
	//encode31 << authentification::keytimesbase64;
}

void callerbase64::urlbase64caller() {
	/*std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(authentification::keydecodebase64.c_str()), authentification::keybase64.length());*/
	std::string decoded = base64_decode((authentification2::urldecodebase64.c_str()));
	/*std::cout << "encoded: " << std::endl << encoded << std::endl << std::endl;*/
	std::cout << "decoded: " << std::endl << decoded << std::endl;
	authentification2::urlbase64 = decoded;
}
bool firstdixsecondesettings = true;
bool timer::dixsecondebool = false;
void timer::dixsecondetimer() {
	if (firstdixsecondesettings)
	{
		/*FeaturesOnline::zeropointcentvingt2 = 0.057f;
		FeaturesOnline::zeropointcentvingttrois2 = 0.78f;*/
		FeaturesOnline::zeropointcentvingttrois2 = 0.793000f;/*0.011000f*/
		FeaturesOnline::zeropointcentvingt2 = 0.053700f; //0.055f
		firstdixsecondesettings = false;
	}
	char buffer[80];
	time_t rawtime;
	struct tm* info;
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
	Menu1::AddSmallInfoTimes2(buffer, 0);
	Timer t = Timer();
	t.setTimeout([&]() {
		timer::dixsecondebool = false;
		t.stop();
		}, 17000);
}
//link-https://www.fluentcpp.com/2018/12/28/timer-cpp/
template<typename Function>
void Timer::setTimeout(Function function, int delay) {
	this->clear = false;
	std::thread t([=]() {
		if (this->clear) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear) return;
		function();
		});
	t.detach();
}
template<typename Function>
void Timer::setInterval(Function function, int interval) {
	this->clear = false;
	std::thread t([=]() {
		while (true) {
			if (this->clear) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear) return;
			function();
		}
		});
	t.detach();
}

void Timer::stop() {
	this->clear = true;
}



//void ReaLTimes::timesreal()
//{
//	string  users021;
//	users021 = getenv("appdata");
//	ofstream users0222(users021 + "\\ThunderMenu\\Times.Thunder");
//
//}

string converter::float2string(float f)
{
	ostringstream os;
	os << f;
	return os.str();
}

std::wstring converter::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	std::wstring r(len, L'\0');
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
	return r;
}

std::string converter::ws2s(const std::wstring& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
	std::string r(len, '\0');
	WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, &r[0], len, 0, 0);
	return r;
}
char* converter::string2char(string xs)
{
	char* ca = new char[xs.size() + 1];
	strcpy(ca, xs.c_str());
	/*std::copy(xs.begin(), xs.end(), ca);*/
	ca[xs.length()] = '\0';
	/*ca[xs.size()] = '\0';*/
	for (int i = 0; i < xs.length(); i++)
		cout << ca[i] << "\n";
	return ca;
}

//string converter::char2string(char cc)
//{
//std::stringstream sss;
//std::string targets;
//sss << cc;
//sss >> targets;
//return targets.c_str();
//}


//char* converter::string2char2(std::string header)
//{
//	char cVar231[254];
//	std::string str(header);
//	std::size_t length = str.copy(cVar231, 254);
//	cVar231[length] = '\0';
//	char* charPointer = cVar231;
//	return charPointer;
//}

void checking::savetimes()
{
//	char Times1[1];
//	char Times2[2];
//	char Times3[3];
//string Timesstring;
//string Timespath2344;
//Timespath2344 = getenv("appdata");
//ifstream Times234;
//Times234.open(Timespath2344 + "\ThunderMenu\Times.Thunder");
//if (Times234) {
//	Times234 >> Times1;
//	Times234 >> Times2, 2;
//	Times234 >> Times3, 3;
//timer::realtime222 = Times1;
//FeaturesOnline::zeropointcentvingt = (char)Times2, 2;
//FeaturesOnline::zeropointcentvingttrois = (char)Times3, 3;
//}
}
bool MenuConfig::bSaveAtIntervals = true;
CSimpleIniA MenuConfig::iniFile;
SI_Error MenuConfig::ConfigInit()
{
	MenuConfig::iniFile.SetUnicode(true);
	MenuConfig::iniFile.SetMultiKey(false);
	MenuConfig::iniFile.SetMultiLine(false);
	SetFileAttributesW(GetPathffW(Pathff::ThunderMenu, false).c_str(), GetFileAttributesW(GetPathffW(Pathff::ThunderMenu, false).c_str()) & ~FILE_ATTRIBUTE_READONLY);
	return MenuConfig::iniFile.LoadFile((GetPathffA(Pathff::ThunderMenu, true) + "ThunderConfig.ini").c_str());
}

//bool MenuConfig::bSaveAtIntervals1 = false;
//CSimpleIniA MenuConfig::iniFileAll;
//SI_Error MenuConfig::ConfigInitAll ()
//{
//	MenuConfig::iniFileAll.SetUnicode(true);
//	MenuConfig::iniFileAll.SetMultiKey(false);
//	MenuConfig::iniFileAll.SetMultiLine(false);
//	SetFileAttributesW(GetPathffW(Pathff::Outfit, false).c_str(), GetFileAttributes(GetPathffW(Pathff::Outfit, false).c_str()) & ~FILE_ATTRIBUTE_READONLY);
//	/*return MenuConfig::iniFile.LoadFile((GetPathffA(Pathff::ThunderMenu, true) + "ThunderConfig.ini").c_str());*/
//	return MenuConfig::iniFileAll.LoadFile((GetPathffA(Pathff::Outfit, true) + "OutFit.ini").c_str());
//}

//bool readpicback = true;
void MenuConfig::ConfigRead()
{
	PCHAR section_haxValues = "Thunder-Menu";
	auto& ini = MenuConfig::iniFile;
//bool	
	Features::walkinairvisible = ini.GetBoolValue(section_haxValues, "walkinairvisible", Features::walkinairvisible);
	Features::ifwalkorincar = ini.GetBoolValue(section_haxValues, "ifwalkorincar", Features::ifwalkorincar);
	walkonwall::wall_walkingbool = ini.GetBoolValue(section_haxValues, "WalkonWall", walkonwall::wall_walkingbool);
	Silent_persist::boolautolistaction = ini.GetBoolValue(section_haxValues, "SilentRidCrash", Silent_persist::boolautolistaction);
	g_Settings.m_ChatSpammer = ini.GetBoolValue(section_haxValues, "ChatSpam", g_Settings.m_ChatSpammer);
	m_features::FastRespawnbool = ini.GetBoolValue(section_haxValues, "FastRespawnbool", m_features::FastRespawnbool);
	Menu_Settings2::spoof_username = ini.GetBoolValue(section_haxValues, "spoofUser", Menu_Settings2::spoof_username);
	Menu_Settings2::spoof_ip = ini.GetBoolValue(section_haxValues, "spoofIP", Menu_Settings2::spoof_ip);
	Menu_Settings2::spoof_rockstar_id = ini.GetBoolValue(section_haxValues, "spoofRID", Menu_Settings2::spoof_rockstar_id);
	GiveVehicle::norepeat = ini.GetBoolValue(section_haxValues, "antiSpam", GiveVehicle::norepeat);
	Features::maxspeed = ini.GetBoolValue(section_haxValues, "maxspeed", Features::maxspeed);
	GiveVehicle::activatemoney = ini.GetBoolValue(section_haxValues, "moneybool", GiveVehicle::activatemoney);
	GiveVehicle::activateblame = ini.GetBoolValue(section_haxValues, "blamebool", GiveVehicle::activateblame);
	GiveVehicle::activatecrash = ini.GetBoolValue(section_haxValues, "crashbool", GiveVehicle::activatecrash);
	GiveVehicle::activatekick = ini.GetBoolValue(section_haxValues, "Kickbool", GiveVehicle::activatekick);
	GiveVehicle::activatebike = ini.GetBoolValue(section_haxValues, "PutOnBikebool", GiveVehicle::activatebike);
	GiveVehicle::activatebounty = ini.GetBoolValue(section_haxValues, "SendBountybool", GiveVehicle::activatebounty);
	GiveVehicle::activateland = ini.GetBoolValue(section_haxValues, "sendtoislandbool", GiveVehicle::activateland);
	GiveVehicle::activatevehicle = ini.GetBoolValue(section_haxValues, "CommandChatVehicle", GiveVehicle::activatevehicle);
	Features::screeneffect = ini.GetBoolValue(section_haxValues, "ScreenEffect", Features::screeneffect);
	Features::featureWalk1 = ini.GetBoolValue(section_haxValues, "DriveInTheyAir", Features::featureWalk1);
	Features::mpglobalbool3 = ini.GetBoolValue(section_haxValues, "PlayerInfo2", Features::mpglobalbool3);
	/*tmrig::startsupportinvboolt1 = ini.GetBoolValue(section_haxValues, "SupportInvx1", tmrig::startsupportinvboolt1);*/
	/*tmrig::startsupportinvboolt21 = ini.GetBoolValue(section_haxValues, "SupportInvx2", tmrig::startsupportinvboolt21);*/
	/*tmrig::startsupportinvbool = ini.GetBoolValue(section_haxValues, "SupportInvx7", tmrig::startsupportinvbool);*/
	/*tmrig::tmsupportbool = ini.GetBoolValue(section_haxValues, "SupportConsolex7", tmrig::tmsupportbool);*/
	Menu2::Darkside = ini.GetBoolValue(section_haxValues, "Darkside", Menu2::Darkside);
	Hooking::protect = ini.GetBoolValue(section_haxValues, "protects", Hooking::protect);
	Hooking::redirectAll = ini.GetBoolValue(section_haxValues, "redirectall", Hooking::protect);
	Features::mainprotection = ini.GetBoolValue(section_haxValues, "urMainProtect", Features::mainprotection);
	Hooking::geteventdata = ini.GetBoolValue(section_haxValues, "geteventdata", Hooking::geteventdata);
	Features::titleRect = ini.GetBoolValue(section_haxValues, "titleRect", Features::titleRect);
	Features::optionRect = ini.GetBoolValue(section_haxValues, "optionRect", Features::optionRect);
	Features::RGBSCROLLER = ini.GetBoolValue(section_haxValues, "RGBSCROLLER", Features::RGBSCROLLER);
	Features::RGBTITLE = ini.GetBoolValue(section_haxValues, "RGBTITLE", Features::RGBTITLE);
	Features::RGBTEXTE = ini.GetBoolValue(section_haxValues, "RGBTEXTE", Features::RGBTEXTE);
	MenuConfig::bSaveAtIntervals = ini.GetBoolValue(section_haxValues, "sync_with_config_at_intervals", MenuConfig::bSaveAtIntervals);
	timer::realtime222 = ini.GetBoolValue(section_haxValues, "real_times", timer::realtime222);
	load::namechangers = ini.GetBoolValue(section_haxValues, "namechanger", load::namechangers);
	/*Features::header02 = ini.GetBoolValue(section_haxValues, "titleRect1", Features::header02);
	Features::header012 = ini.GetBoolValue(section_haxValues, "optionRect1", Features::header012);
	Features::optionText1bool = ini.GetBoolValue(section_haxValues, "RGBTEXTE1", Features::optionText1bool);
	Features::titlestextbool = ini.GetBoolValue(section_haxValues, "RGBTITLE1", Features::titlestextbool);
	Features::scroller0bool = ini.GetBoolValue(section_haxValues, "RGBSCROLLER1", Features::scroller0bool);*/
	Features::MobileRadio = ini.GetBoolValue(section_haxValues, "mbradio", Features::MobileRadio);
	Features::spawnincar = ini.GetBoolValue(section_haxValues, "SpawnInCar", Features::spawnincar);
	Features::spawnmaxed = ini.GetBoolValue(section_haxValues, "SpawnMax", Features::spawnmaxed);
	Features::Neverwanted = ini.GetBoolValue(section_haxValues, "Neverwanted", Features::Neverwanted);
	Features::antiafk = ini.GetBoolValue(section_haxValues, "Anti-AFK", Features::antiafk);
	Features::fastswim = ini.GetBoolValue(section_haxValues, "FastSwim", Features::fastswim);
	Features::SonicRun = ini.GetBoolValue(section_haxValues, "FastRun", Features::SonicRun);
	Features::osk = ini.GetBoolValue(section_haxValues, "oneshoot", Features::osk);
	Features::playerGodMode = ini.GetBoolValue(section_haxValues, "GodMode", Features::playerGodMode);
	Features::playersuperjump = ini.GetBoolValue(section_haxValues, "SuperJump", Features::playersuperjump);
	/*Features::wallrunbool = ini.GetBoolValue(section_haxValues, "walkwall", Features::wallrunbool);*/
	Features::Staminabool = ini.GetBoolValue(section_haxValues, "Stamina", Features::Staminabool);
	/*Features::boostbool = ini.GetBoolValue(section_haxValues, "hornbost", Features::boostbool);*/
	Features::boostboolb = ini.GetBoolValue(section_haxValues, "hornbostb", Features::boostboolb);
	Features::AutoClear = ini.GetBoolValue(section_haxValues, "ClearAllReport", Features::AutoClear);
	Features::Seat = ini.GetBoolValue(section_haxValues, "SeatBelts", Features::Seat);
	Features::infammo = ini.GetBoolValue(section_haxValues, "Infinite-Ammo", Features::infammo);
	Features::Speedometerbool = ini.GetBoolValue(section_haxValues, "Speedometer", Features::Speedometerbool);
	Features::cargodmodebool = ini.GetBoolValue(section_haxValues, "CarGodMode", Features::cargodmodebool);
	Features::vehiclegun = ini.GetBoolValue(section_haxValues, "VehicleGun", Features::vehiclegun);
	Features::flyingcars_ = ini.GetBoolValue(section_haxValues, "FlyingCars", Features::flyingcars_);
	Features::free_cam = ini.GetBoolValue(section_haxValues, "FreeCam", Features::free_cam);
	Features::meleedamage = ini.GetBoolValue(section_haxValues, "MeleDamage", Features::meleedamage);
	Features::weaponsdamage = ini.GetBoolValue(section_haxValues, "WeapDamage", Features::weaponsdamage);
	Features::Flex0 = ini.GetBoolValue(section_haxValues, "ExpMele", Features::Flex0);
	Features::headlightbool = ini.GetBoolValue(section_haxValues, "HeadLightBool", Features::headlightbool);
	Features::brakebool = ini.GetBoolValue(section_haxValues, "Brake", Features::brakebool);
	Features::enginealwaysonbool = ini.GetBoolValue(section_haxValues, "enginealwayson", Features::enginealwaysonbool);
	Features::GeoLocation = ini.GetBoolValue(section_haxValues, "Geo", Features::GeoLocation);
	Features::sp_vehicle_bypass = ini.GetBoolValue(section_haxValues, "mpinsp", Features::sp_vehicle_bypass);
	Features::infoplayer = ini.GetBoolValue(section_haxValues, "PlayerInfo", Features::infoplayer);
	Features::waveban = ini.GetBoolValue(section_haxValues, "wveWaveBan", Features::waveban);
	Features::CustomCar = ini.GetBoolValue(section_haxValues, "CustomCars", Features::CustomCar);
	Features::ptfx2car = ini.GetBoolValue(section_haxValues, "Alien2", Features::ptfx2car);
	Features::ptfx2car01 = ini.GetBoolValue(section_haxValues, "ClownAppears", Features::ptfx2car01);
	Features::ptfx2car02 = ini.GetBoolValue(section_haxValues, "Firework1", Features::ptfx2car02);
	Features::ptfx2car03 = ini.GetBoolValue(section_haxValues, "Firework2", Features::ptfx2car03);
	Features::ptfx2car04 = ini.GetBoolValue(section_haxValues, "Firework3", Features::ptfx2car04);
	Features::ptfx2car05 = ini.GetBoolValue(section_haxValues, "Banknotes", Features::ptfx2car05);
	Features::ptfx2car06 = ini.GetBoolValue(section_haxValues, "TruckCrash", Features::ptfx2car06);
	Features::ptfx2car07 = ini.GetBoolValue(section_haxValues, "Alien1", Features::ptfx2car07);
	Features::ptfx2car08 = ini.GetBoolValue(section_haxValues, "ElectricBox", Features::ptfx2car08);
	Features::ptfx2car09 = ini.GetBoolValue(section_haxValues, "WaterSplash", Features::ptfx2car09);
	Features::ptfx2car12 = ini.GetBoolValue(section_haxValues, "SniperImpact", Features::ptfx2car12);
	Features::ptfx2car13 = ini.GetBoolValue(section_haxValues, "DirtThrow", Features::ptfx2car13);
	Features::ptfx2car14 = ini.GetBoolValue(section_haxValues, "BloodStab", Features::ptfx2car14);
	Features::ptfx2car15 = ini.GetBoolValue(section_haxValues, "PedSliced", Features::ptfx2car15);
	Features::ptfx2car16 = ini.GetBoolValue(section_haxValues, "Camera", Features::ptfx2car16);
	Features::ptfx2car17 = ini.GetBoolValue(section_haxValues, "MethSmoke", Features::ptfx2car17);
	Features::ptfx2car18 = ini.GetBoolValue(section_haxValues, "BurialDirt", Features::ptfx2car18);
	Features::rapidfirer = ini.GetBoolValue(section_haxValues, "Rapidfire", Features::rapidfirer);
	Features::orbool2 = ini.GetBoolValue(section_haxValues, "OffRadar", Features::orbool2);
	Features::showall = ini.GetBoolValue(section_haxValues, "showall", Features::showall);
	Features::ZoneStreetbool = ini.GetBoolValue(section_haxValues, "ZoneAndStreet", Features::ZoneStreetbool);
	Features::Drift = ini.GetBoolValue(section_haxValues, "Drift", Features::Drift);
	Features::burnout = ini.GetBoolValue(section_haxValues, "burnout", Features::burnout);
	Features::Rneon = ini.GetBoolValue(section_haxValues, "rainbowneons", Features::Rneon);
	Features::Rainb = ini.GetBoolValue(section_haxValues, "tyresmoke", Features::Rainb);
	Features::smoketyrebool = ini.GetBoolValue(section_haxValues, "SmokeTyre", Features::smoketyrebool);
	Features::Rainb2 = ini.GetBoolValue(section_haxValues, "Rainb2", Features::Rainb2);
	Features::Rcolor2 = ini.GetBoolValue(section_haxValues, "Rcolor2", Features::Rcolor2);
	Features::Rneon2 = ini.GetBoolValue(section_haxValues, "Rneon2", Features::Rneon2);
	Features::showback = ini.GetBoolValue(section_haxValues, "showback", Features::showback);
	Features::noragsdoll = ini.GetBoolValue(section_haxValues, "noragdoll", Features::noragsdoll);
	/*Features::vkdecimal = ini.GetBoolValue(section_haxValues, "VKDecimal", Features::vkdecimal);
	Features::vkadd = ini.GetBoolValue(section_haxValues, "VKAdd", Features::vkadd);
	Features::vkdivide = ini.GetBoolValue(section_haxValues, "VKDivide", Features::vkdivide);
	Features::vkcontrol = ini.GetBoolValue(section_haxValues, "VKControl", Features::vkcontrol);
	Features::vksubstract = ini.GetBoolValue(section_haxValues, "VKSubstract", Features::vksubstract);
	Features::vkf1 = ini.GetBoolValue(section_haxValues, "VKF1", Features::vkf1);
	Features::vkf2 = ini.GetBoolValue(section_haxValues, "VKF2", Features::vkf2);
	Features::vkf3 = ini.GetBoolValue(section_haxValues, "VKF3", Features::vkf3);
	Features::vkf4 = ini.GetBoolValue(section_haxValues, "VKF4", Features::vkf4);
	Features::vkf5 = ini.GetBoolValue(section_haxValues, "VKF5", Features::vkf5);
	Features::vkf6 = ini.GetBoolValue(section_haxValues, "VKF6", Features::vkf6);
	Features::vkf7 = ini.GetBoolValue(section_haxValues, "VKF7", Features::vkf7);
	Features::vkf8 = ini.GetBoolValue(section_haxValues, "VKF8", Features::vkf8);
	Features::vkf9 = ini.GetBoolValue(section_haxValues, "VKF9", Features::vkf9);
	Features::vkf10 = ini.GetBoolValue(section_haxValues, "VKF10", Features::vkf10);
	Features::vkf11 = ini.GetBoolValue(section_haxValues, "VKF11", Features::vkf11);
	Features::vkf12 = ini.GetBoolValue(section_haxValues, "VKF12", Features::vkf12);
	Features::vkmenu = ini.GetBoolValue(section_haxValues, "VKMENU", Features::vkmenu);
	Features::vknumpad1 = ini.GetBoolValue(section_haxValues, "VKNUMPAD1", Features::vknumpad1);
	Features::vknumpad3 = ini.GetBoolValue(section_haxValues, "VKNUMPAD3", Features::vknumpad3);
	Features::vknumpad7 = ini.GetBoolValue(section_haxValues, "VKNUMPAD7", Features::vknumpad7);
	Features::vknumpad9 = ini.GetBoolValue(section_haxValues, "VKNUMPAD9", Features::vknumpad9);
	Features::vkback = ini.GetBoolValue(section_haxValues, "VKBACK", Features::vkback);*/
	Features::menucolors = ini.GetBoolValue(section_haxValues, "ColorSave", Features::menucolors);
	Features::dropbool = ini.GetBoolValue(section_haxValues, "Dropsbool", Features::dropbool);
	Features::selecArrow = ini.GetBoolValue(section_haxValues, "Selectbool", Features::selecArrow);
	Features::DisplayFPS = ini.GetBoolValue(section_haxValues, "DisplayFPS", Features::DisplayFPS);
	Features::NameESP = ini.GetBoolValue(section_haxValues, "ESPName", Features::NameESP);
	Features::esper = ini.GetBoolValue(section_haxValues, "ESPLine", Features::esper);
	Features::dowbool = ini.GetBoolValue(section_haxValues, "driveonwater", Features::dowbool);
	Features::vehjump = ini.GetBoolValue(section_haxValues, "vehjump", Features::vehjump);	
	Features::header02 = ini.GetBoolValue(section_haxValues, "header02", Features::header02);
	Features::header012 = ini.GetBoolValue(section_haxValues, "header012", Features::header012);
	Features::optionText1bool = ini.GetBoolValue(section_haxValues, "optionText1bool0", Features::optionText1bool);
	Features::scroller0bool = ini.GetBoolValue(section_haxValues, "scroller0bool", Features::scroller0bool);
	Features::titlestextbool = ini.GetBoolValue(section_haxValues, "titlestextbool0", Features::titlestextbool);
	Features::menucolors = ini.GetBoolValue(section_haxValues, "menucolors", Features::menucolors);
	Hooking::dump = ini.GetBoolValue(section_haxValues, "dump", Hooking::dump);
	/*Features::ThunderLog = ini.GetBoolValue(section_haxValues, "loghashmap", Features::ThunderLog);*/
	droptimer::picbackbool2 = ini.GetBoolValue(section_haxValues, "headerchanger", droptimer::picbackbool2);
	droptimer::picbackbool = ini.GetBoolValue(section_haxValues, "backgroundchanger", droptimer::picbackbool);
//int

	Menu::Settings::keyPressDelay = ini.GetLongValue(section_haxValues, "keyPressDelay", Menu::Settings::keyPressDelay); // Délai lorsque vous appuyez brièvement sur un bouton
	Menu::Settings::keyHoldDelay = ini.GetLongValue(section_haxValues, "keyHoldDelay", Menu::Settings::keyHoldDelay); // Délai lorsque vous maintenez un bouton enfoncé
	Menu::Settings::keyPressCooldown = ini.GetLongValue(section_haxValues, "keyPressCooldown", Menu::Settings::keyPressCooldown); // Temps de refroidissement entre les pressions successives

	g_Settings.m_ChatSpammerTimer = ini.GetLongValue(section_haxValues, "TimerChatSpam", g_Settings.m_ChatSpammerTimer);
	Features::tireSmokeColor1 = ini.GetLongValue(section_haxValues, "tireSmokeColor1", Features::tireSmokeColor1);
	Features::tireSmokeColor2 = ini.GetLongValue(section_haxValues, "tireSmokeColor2", Features::tireSmokeColor2);
	Features::tireSmokeColor3 = ini.GetLongValue(section_haxValues, "tireSmokeColor3", Features::tireSmokeColor3);
	/*Features::pearlescentColor = ini.GetLongValue(section_haxValues, "pearlescentColor", Features::pearlescentColor);
	Features::wheelColor = ini.GetLongValue(section_haxValues, "wheelColor", Features::wheelColor);*/
	Menu2::BoostBackKey = ini.GetLongValue(section_haxValues, "BoostBackKey", Menu2::BoostBackKey);
	flyingcars::up = ini.GetLongValue(section_haxValues, "FlyingCarsUp", flyingcars::up);
	flyingcars::down = ini.GetLongValue(section_haxValues, "FlyingCarsDown", flyingcars::down);
	flyingcars::open = ini.GetLongValue(section_haxValues, "FlyingCarsOpen", flyingcars::open);
	noclips::open = ini.GetLongValue(section_haxValues, "FreeCamOpen", noclips::open);
	Features::travelSpeed = ini.GetLongValue(section_haxValues, "TravelSpeed", Features::travelSpeed);
	Features::vehicleheadlight = ini.GetLongValue(section_haxValues, "HeadLightColor", Features::vehicleheadlight);
	Menu2::DriftKey = ini.GetLongValue(section_haxValues, "DriftKey", Menu2::DriftKey);
	Menu2::OpenMenu = ini.GetLongValue(section_haxValues, "OpenMenu", Menu2::OpenMenu);
	Menu2::OpenMenu8 = ini.GetLongValue(section_haxValues, "OpenMenu8", Menu2::OpenMenu8);
	Menu2::OpenMenu6 = ini.GetLongValue(section_haxValues, "OpenMenu6", Menu2::OpenMenu6);
	Menu2::OpenMenu5 = ini.GetLongValue(section_haxValues, "OpenMenu5", Menu2::OpenMenu5);
	Menu2::OpenMenu4 = ini.GetLongValue(section_haxValues, "OpenMenu4", Menu2::OpenMenu4);
	Menu2::OpenMenu2 = ini.GetLongValue(section_haxValues, "OpenMenu2", Menu2::OpenMenu2);
	Menu2::OpenMenu0 = ini.GetLongValue(section_haxValues, "OpenMenu0", Menu2::OpenMenu0);
	Features::rr = ini.GetLongValue(section_haxValues, "rr", Features::rr);
	Features::gg = ini.GetLongValue(section_haxValues, "gg", Features::gg);
	Features::bb = ini.GetLongValue(section_haxValues, "bb", Features::bb);
	Features::rr5 = ini.GetLongValue(section_haxValues, "rr5", Features::rr5);
	Features::gg5 = ini.GetLongValue(section_haxValues, "gg5", Features::gg5);
	Features::bb5 = ini.GetLongValue(section_haxValues, "bb5", Features::bb5);
	Features::rw2 = ini.GetLongValue(section_haxValues, "rw2", Features::rw2);
	Features::gw2 = ini.GetLongValue(section_haxValues, "gw2", Features::gw2);
	Features::bw2 = ini.GetLongValue(section_haxValues, "bw2", Features::bw2);
	Features::optionText6 = ini.GetLongValue(section_haxValues, "optionText6", Features::optionText6);
	Features::optionText7 = ini.GetLongValue(section_haxValues, "optionText7", Features::optionText7);
	Features::rw = ini.GetLongValue(section_haxValues, "rw", Features::rw);
	Features::gw = ini.GetLongValue(section_haxValues, "gw", Features::gw);
	Features::bw = ini.GetLongValue(section_haxValues, "bw", Features::bw);
	Features::Scroller4 = ini.GetLongValue(section_haxValues, "Scroller4", Features::Scroller4);
	Features::rw1 = ini.GetLongValue(section_haxValues, "rw1", Features::rw1);
	Features::gw1 = ini.GetLongValue(section_haxValues, "gw1", Features::gw1);
	Features::bw1 = ini.GetLongValue(section_haxValues, "bw1", Features::bw1);
	Features::title4 = ini.GetLongValue(section_haxValues, "title4", Features::title4);
	Features::title5 = ini.GetLongValue(section_haxValues, "title5", Features::title5);
	Features::redint = ini.GetLongValue(section_haxValues, "RedLine", Features::redint);
	Features::greenint = ini.GetLongValue(section_haxValues, "GreenLine", Features::greenint);
	Features::blueint = ini.GetLongValue(section_haxValues, "BlueLine", Features::blueint);
	Features::alphaint = ini.GetLongValue(section_haxValues, "AlphaLine", Features::alphaint);
	Features::bennystypeok = ini.GetLongValue(section_haxValues, "WheelType", Features::bennystypeok);
	Features::bennysok = ini.GetLongValue(section_haxValues, "Wheel", Features::bennysok);
	Features::paintcolor01 = ini.GetLongValue(section_haxValues, "paintcolor01", Features::paintcolor01);
	Features::paintcolor02 = ini.GetLongValue(section_haxValues, "paintcolor02", Features::paintcolor02);
	Features::paintcolor03 = ini.GetLongValue(section_haxValues, "paintcolor03", Features::paintcolor03);
	Features::chrome = ini.GetLongValue(section_haxValues, "Chrome", Features::chrome);
	Features::hornsound = ini.GetLongValue(section_haxValues, "HornSound", Features::hornsound);
	droptimer::timertimes = ini.GetLongValue(section_haxValues, "timertimes", droptimer::timertimes);
	droptimer::timertimes2 = ini.GetLongValue(section_haxValues, "timertimes2", droptimer::timertimes2);
	timesback::lastpicid = ini.GetLongValue(section_haxValues, "lastpicid", timesback::lastpicid);
	timesback::lastpicid2 = ini.GetLongValue(section_haxValues, "lastpicid2", timesback::lastpicid2);
	timesback::id = ini.GetLongValue(section_haxValues, "picid", timesback::id);
	timesback::id2 = ini.GetLongValue(section_haxValues, "picid2", timesback::id2);
//float
	FeaturesOnline::zeropointcentvingt = (float)ini.GetDoubleValue(section_haxValues, "times_x", FeaturesOnline::zeropointcentvingt);
	FeaturesOnline::zeropointcentvingttrois = (float)ini.GetDoubleValue(section_haxValues, "times_y", FeaturesOnline::zeropointcentvingttrois);
	Features::zeropointquarantecinq = (float)ini.GetDoubleValue(section_haxValues, "menutextsize", Features::zeropointquarantecinq);
	Features::zeropointtrentedeux = (float)ini.GetDoubleValue(section_haxValues, "menutextfloatsize", Features::zeropointtrentedeux);
	Features::centvingt = (float)ini.GetDoubleValue(section_haxValues, "speedometerleftright", Features::centvingt);
	Features::zeroundeuxtrois = (float)ini.GetDoubleValue(section_haxValues, "speedometerupdown", Features::zeroundeuxtrois);
	Features::zerotroiscentsoixantequinze = (float)ini.GetDoubleValue(section_haxValues, "speedometerbiggest", Features::zerotroiscentsoixantequinze);
	Features::xzerovingt = (float)ini.GetDoubleValue(section_haxValues, "displayfpsx", Features::xzerovingt);
	Features::yzerodix = (float)ini.GetDoubleValue(section_haxValues, "displayfpsy", Features::yzerodix);
	Menu::Settings::menuX = (float)ini.GetDoubleValue(section_haxValues, "menuxposition", Menu::Settings::menuX);
	Menu::Settings::menuY = (float)ini.GetDoubleValue(section_haxValues, "menuyposition", Menu::Settings::menuY);
	Features::menuXPositionX = (float)ini.GetDoubleValue(section_haxValues, "menuxheaderposition", Features::menuXPositionX);
	Features::zeropointcentvingtf = (float)ini.GetDoubleValue(section_haxValues, "zoneandstreetleftright", Features::zeropointcentvingtf);
	Features::zeropointundeuxtroisf = (float)ini.GetDoubleValue(section_haxValues, "zoneandstreetupdown", Features::zeropointundeuxtroisf);
	Features::zeropointtroiscentsoixantequinzef = (float)ini.GetDoubleValue(section_haxValues, "zoneandstreetbiggest", Features::zeropointtroiscentsoixantequinzef);
	Features::zeropointhuitcent = (float)ini.GetDoubleValue(section_haxValues, "headerleftright", Features::zeropointhuitcent);
	Features::zeropointmillecentsoixantequinze = (float)ini.GetDoubleValue(section_haxValues, "headerupdown", Features::zeropointmillecentsoixantequinze);
	Features::zeropointvingtetun = (float)ini.GetDoubleValue(section_haxValues, "headerwidth", Features::zeropointvingtetun);
	Features::zeropointhuitcenttt = (float)ini.GetDoubleValue(section_haxValues, "backgroundleftright", Features::zeropointhuitcenttt);
	Features::zeropointmillecentsoixantequinzettt = (float)ini.GetDoubleValue(section_haxValues, "backgroundupdown", Features::zeropointmillecentsoixantequinzettt);
	Features::zeropointvingtetunttt = (float)ini.GetDoubleValue(section_haxValues, "backgroundwidth", Features::zeropointvingtetunttt);
	Features::zeropointzeroquatrevingtcinq = (float)ini.GetDoubleValue(section_haxValues, "backgroundheight", Features::zeropointzeroquatrevingtcinq);
	Features::deuxzerosepthuit = (float)ini.GetDoubleValue(section_haxValues, "picturex", Features::deuxzerosepthuit);
	Features::zerounquatredeux = (float)ini.GetDoubleValue(section_haxValues, "picturey", Features::zerounquatredeux);
	Features::deuxzeroquinze = (float)ini.GetDoubleValue(section_haxValues, "pictureheight", Features::deuxzeroquinze);
	Features::deuxzerodeuxsept = (float)ini.GetDoubleValue(section_haxValues, "picturewidth", Features::deuxzerodeuxsept);
	Features::screenX = (float)ini.GetDoubleValue(section_haxValues, "screenx", Features::screenX);
	Features::screenY = (float)ini.GetDoubleValue(section_haxValues, "screeny", Features::screenY);
	Features::width = (float)ini.GetDoubleValue(section_haxValues, "widthscreen", Features::width);
	Features::height = (float)ini.GetDoubleValue(section_haxValues, "heightscreen", Features::height);
	Features::heading = (float)ini.GetDoubleValue(section_haxValues, "headingscreen", Features::heading);
	Features::nameespsize = (float)ini.GetDoubleValue(section_haxValues, "ESPSize", Features::nameespsize);
	/*Features::titleRectrr = (float)ini.GetDoubleValue(section_haxValues, "titleRectrr", Features::titleRectrr);
	Features::titleRectgg = (float)ini.GetDoubleValue(section_haxValues, "titleRectgg", Features::titleRectgg);
	Features::titleRectbb = (float)ini.GetDoubleValue(section_haxValues, "titleRectbb", Features::titleRectbb);
	Features::titleRectaa = (float)ini.GetDoubleValue(section_haxValues, "titleRectaa", Features::titleRectaa);
	Features::titleRectrrr = (float)ini.GetDoubleValue(section_haxValues, "titleRectrrr", Features::titleRectrrr);
	Features::titleRectggg = (float)ini.GetDoubleValue(section_haxValues, "titleRectggg", Features::titleRectggg);
	Features::titleRectbbb = (float)ini.GetDoubleValue(section_haxValues, "titleRectbbb", Features::titleRectbbb);
	Features::titleRectaaa = (float)ini.GetDoubleValue(section_haxValues, "titleRectaaa", Features::titleRectaaa);
	Features::optionsRectrr5 = (float)ini.GetDoubleValue(section_haxValues, "optionsRectrr5", Features::optionsRectrr5);
	Features::optionsRectgg5 = (float)ini.GetDoubleValue(section_haxValues, "optionsRectgg5", Features::optionsRectgg5);
	Features::optionsRectbb5 = (float)ini.GetDoubleValue(section_haxValues, "optionsRectbb5", Features::optionsRectbb5);
	Features::optionsRectrr2 = (float)ini.GetDoubleValue(section_haxValues, "optionsRectrr2", Features::optionsRectrr2);
	Features::optionsRectgg2 = (float)ini.GetDoubleValue(section_haxValues, "optionsRectgg2", Features::optionsRectgg2);
	Features::optionsRectbb2 = (float)ini.GetDoubleValue(section_haxValues, "optionsRectbb2", Features::optionsRectbb2);
	Features::optionsRectaa2 = (float)ini.GetDoubleValue(section_haxValues, "optionsRectaa2", Features::optionsRectaa2);
	Features::optionTextrw2 = (float)ini.GetDoubleValue(section_haxValues, "optionTextrw2", Features::optionTextrw2);
	Features::optionTextgw2 = (float)ini.GetDoubleValue(section_haxValues, "optionTextgw2", Features::optionTextgw2);
	Features::optionTextbw2 = (float)ini.GetDoubleValue(section_haxValues, "optionTextbw2", Features::optionTextbw2);
	Features::optionText33 = (float)ini.GetDoubleValue(section_haxValues, "optionText33", Features::optionText33);
	Features::optionText44 = (float)ini.GetDoubleValue(section_haxValues, "optionText44", Features::optionText44);
	Features::optionText55 = (float)ini.GetDoubleValue(section_haxValues, "optionText55", Features::optionText55);
	Features::optionText66 = (float)ini.GetDoubleValue(section_haxValues, "optionText66", Features::optionText66);
	Features::optionText77 = (float)ini.GetDoubleValue(section_haxValues, "optionText77", Features::optionText77);
	Features::Scrollerrw = (float)ini.GetDoubleValue(section_haxValues, "Scrollerrw", Features::Scrollerrw);
	Features::Scrollergw = (float)ini.GetDoubleValue(section_haxValues, "Scrollergw", Features::Scrollergw);
	Features::Scrollerbw = (float)ini.GetDoubleValue(section_haxValues, "Scrollerbw", Features::Scrollerbw);
	Features::Scroller11 = (float)ini.GetDoubleValue(section_haxValues, "Scroller11", Features::Scroller11);
	Features::Scroller22 = (float)ini.GetDoubleValue(section_haxValues, "Scroller22", Features::Scroller22);
	Features::Scroller33 = (float)ini.GetDoubleValue(section_haxValues, "Scroller33", Features::Scroller33);
	Features::Scroller44 = (float)ini.GetDoubleValue(section_haxValues, "Scroller44", Features::Scroller44);
	Features::titleTextrw1 = (float)ini.GetDoubleValue(section_haxValues, "titleTextrw1", Features::titleTextrw1);
	Features::titleTextgw1 = (float)ini.GetDoubleValue(section_haxValues, "titleTextgw1", Features::titleTextgw1);
	Features::titleTextbw1 = (float)ini.GetDoubleValue(section_haxValues, "titleTextbw1", Features::titleTextbw1);
	Features::titleText1 = (float)ini.GetDoubleValue(section_haxValues, "titleText1", Features::titleText1);
	Features::titleText2 = (float)ini.GetDoubleValue(section_haxValues, "titleText2", Features::titleText2);
	Features::titleText3 = (float)ini.GetDoubleValue(section_haxValues, "titleText3", Features::titleText3);
	Features::titleText4 = (float)ini.GetDoubleValue(section_haxValues, "titleText4", Features::titleText4);
	Features::titleText5 = (float)ini.GetDoubleValue(section_haxValues, "titleText5", Features::titleText5);*/
//text
	g_Settings.m_ChatMessageInput = (char*)ini.GetValue(section_haxValues, "ChatMessage", g_Settings.m_ChatMessageInput);
	Features::nameEffect = (char*)ini.GetValue(section_haxValues, "nameEffect", Features::nameEffect);
	timesback::filechoosen = ini.GetValue(section_haxValues, "Filechoosen", timesback::filechoosen.c_str());
	timesback::filechoosen2 = ini.GetValue(section_haxValues, "Filechoosen2", timesback::filechoosen2.c_str());
	Features::HeaderMenu = ini.GetValue(section_haxValues, "HeaderMenu", Features::HeaderMenu.c_str());
	Features::HeaderMenu2 = ini.GetValue(section_haxValues, "HeaderMenu2", Features::HeaderMenu2.c_str());
	headers::Background = ini.GetValue(section_haxValues, "Background", headers::Background.c_str());
	headers::Background2 = ini.GetValue(section_haxValues, "Background2", headers::Background2.c_str());
	timesback::backgroundfile = ini.GetValue(section_haxValues, "Design", timesback::backgroundfile.c_str());
	Features::hudcolor1 = ini.GetValue(section_haxValues, "hudcolor1", Features::hudcolor1.c_str());
	Features::hudcolor2 = ini.GetValue(section_haxValues, "hudcolor2", Features::hudcolor2.c_str());
	Features::username = ini.GetValue(section_haxValues, "username", Features::username.c_str());
	Features::Sounds1 = ini.GetValue(section_haxValues, "AuthSound", Features::Sounds1.c_str());
	Features::Notify = ini.GetValue(section_haxValues, "AuthNotify", Features::Notify.c_str());
	authentification2::username2 = ini.GetValue(section_haxValues, "user", authentification2::username2.c_str());
	authentification2::password2 = ini.GetValue(section_haxValues, "pass", authentification2::password2.c_str());
	Hookings::IDSpoof = ini.GetValue(section_haxValues, "IDSpoof", Hookings::IDSpoof.c_str());
	Hookings::IPSpoof = ini.GetValue(section_haxValues, "IPSpoof", Hookings::IPSpoof.c_str());
	Hookings::m_Name = ini.GetValue(section_haxValues, "NamesSpoof", Hookings::m_Name.c_str());
	//langage::rawchar2 = (char*)ini.GetValue(section_haxValues, "lang", langage::rawchar2);
}

void MenuConfig::ConfigSave()
{
	PCHAR section_haxValues = "Thunder-Menu";/////////
	auto& ini = MenuConfig::iniFile;
//bool
	ini.SetBoolValue(section_haxValues, "walkinairvisible", Features::walkinairvisible);
	ini.SetBoolValue(section_haxValues, "ifwalkorincar", Features::ifwalkorincar);
	ini.SetBoolValue(section_haxValues, "WalkonWall", walkonwall::wall_walkingbool);
	ini.SetBoolValue(section_haxValues, "SilentRidCrash", Silent_persist::boolautolistaction);
	ini.SetBoolValue(section_haxValues, "ChatSpam", g_Settings.m_ChatSpammer);
	ini.SetBoolValue(section_haxValues, "FastRespawnbool", m_features::FastRespawnbool);
	ini.SetBoolValue(section_haxValues, "spoofUser", Menu_Settings2::spoof_username);
	ini.SetBoolValue(section_haxValues, "spoofIP", Menu_Settings2::spoof_ip);
	ini.SetBoolValue(section_haxValues, "spoofRID", Menu_Settings2::spoof_rockstar_id);
	ini.SetBoolValue(section_haxValues, "antiSpam", GiveVehicle::norepeat);
	ini.SetBoolValue(section_haxValues, "maxspeed", Features::maxspeed);
	ini.SetBoolValue(section_haxValues, "moneybool", GiveVehicle::activatemoney);
	ini.SetBoolValue(section_haxValues, "blamebool", GiveVehicle::activateblame);
	ini.SetBoolValue(section_haxValues, "crashbool", GiveVehicle::activatecrash);
	ini.SetBoolValue(section_haxValues, "Kickbool", GiveVehicle::activatekick);
	ini.SetBoolValue(section_haxValues, "PutOnBikebool", GiveVehicle::activatebike);
	ini.SetBoolValue(section_haxValues, "SendBountybool", GiveVehicle::activatebounty);
	ini.SetBoolValue(section_haxValues, "sendtoislandbool", GiveVehicle::activateland);
	ini.SetBoolValue(section_haxValues, "CommandChatVehicle", GiveVehicle::activatevehicle);
	ini.SetBoolValue(section_haxValues, "ScreenEffect", Features::screeneffect);
	ini.SetBoolValue(section_haxValues, "DriveInTheyAir", Features::featureWalk1);
	ini.SetBoolValue(section_haxValues, "PlayerInfo2", Features::mpglobalbool3);	
	/*ini.SetBoolValue(section_haxValues, "SupportInvx1", tmrig::startsupportinvboolt1);*/
	/*ini.SetBoolValue(section_haxValues, "SupportInvx2", tmrig::startsupportinvboolt21);*/
	/*ini.SetBoolValue(section_haxValues, "SupportInvx7", tmrig::startsupportinvbool);
	ini.SetBoolValue(section_haxValues, "SupportConsolex7", tmrig::tmsupportbool);*/
	ini.SetBoolValue(section_haxValues, "Darkside", Menu2::Darkside);
	ini.SetBoolValue(section_haxValues, "titleRect", Features::titleRect);
	ini.SetBoolValue(section_haxValues, "optionRect", Features::optionRect);
	ini.SetBoolValue(section_haxValues, "RGBSCROLLER", Features::RGBSCROLLER);
	ini.SetBoolValue(section_haxValues, "RGBTITLE", Features::RGBTITLE);
	ini.SetBoolValue(section_haxValues, "RGBTEXTE", Features::RGBTEXTE);
	ini.SetBoolValue(section_haxValues, "sync_with_config_at_intervals", MenuConfig::bSaveAtIntervals);
	ini.SetBoolValue(section_haxValues, "real_times", timer::realtime222);
	ini.SetBoolValue(section_haxValues, "namechanger", load::namechangers);
	//ini.SetBoolValue(section_haxValues, "titleRect1", Features::header02);
	//ini.SetBoolValue(section_haxValues, "optionRect1", Features::header012);
	//ini.SetBoolValue(section_haxValues, "RGBTEXTE1", Features::optionText1bool);
	//ini.SetBoolValue(section_haxValues, "RGBTITLE1", Features::titlestextbool);
	//ini.SetBoolValue(section_haxValues, "RGBSCROLLER1", Features::scroller0bool);
	ini.SetBoolValue(section_haxValues, "mbradio", Features::MobileRadio);
	ini.SetBoolValue(section_haxValues, "SpawnInCar", Features::spawnincar);
	ini.SetBoolValue(section_haxValues, "SpawnMax", Features::spawnmaxed);
	ini.SetBoolValue(section_haxValues, "Neverwanted", Features::Neverwanted);
	ini.SetBoolValue(section_haxValues, "Anti-AFK", Features::antiafk);
	ini.SetBoolValue(section_haxValues, "FastSwim", Features::fastswim);
	ini.SetBoolValue(section_haxValues, "FastRun", Features::SonicRun);
	ini.SetBoolValue(section_haxValues, "oneshoot", Features::osk);
	ini.SetBoolValue(section_haxValues, "GodMode", Features::playerGodMode);
	ini.SetBoolValue(section_haxValues, "noragdoll", Features::noragsdoll);
	ini.SetBoolValue(section_haxValues, "SuperJump", Features::playersuperjump);
	/*ini.SetBoolValue(section_haxValues, "walkwall", Features::wallrunbool);*/
	ini.SetBoolValue(section_haxValues, "Stamina", Features::Staminabool);
	/*ini.SetBoolValue(section_haxValues, "hornbost", Features::boostbool);*/
	ini.SetBoolValue(section_haxValues, "hornbostb", Features::boostboolb);
	ini.SetBoolValue(section_haxValues, "ClearAllReport", Features::AutoClear);
	ini.SetBoolValue(section_haxValues, "SeatBelts", Features::Seat);
	ini.SetBoolValue(section_haxValues, "Infinite-Ammo", Features::infammo);
	ini.SetBoolValue(section_haxValues, "Speedometer", Features::Speedometerbool);
	ini.SetBoolValue(section_haxValues, "CarGodMode", Features::cargodmodebool);
	ini.SetBoolValue(section_haxValues, "VehicleGun", Features::vehiclegun);
	ini.SetBoolValue(section_haxValues, "FlyingCars", Features::flyingcars_);
	ini.SetBoolValue(section_haxValues, "FreeCam", Features::free_cam);
	ini.SetBoolValue(section_haxValues, "MeleDamage", Features::meleedamage);
	ini.SetBoolValue(section_haxValues, "WeapDamage", Features::weaponsdamage);
	ini.SetBoolValue(section_haxValues, "ExpMele", Features::Flex0);
	ini.SetBoolValue(section_haxValues, "HeadLightBool", Features::headlightbool);
	ini.SetBoolValue(section_haxValues, "Brake", Features::brakebool);
	ini.SetBoolValue(section_haxValues, "enginealwayson", Features::enginealwaysonbool);
	ini.SetBoolValue(section_haxValues, "Geo", Features::GeoLocation);
	ini.SetBoolValue(section_haxValues, "mpinsp", Features::sp_vehicle_bypass);
	ini.SetBoolValue(section_haxValues, "PlayerInfo", Features::infoplayer);
	ini.SetBoolValue(section_haxValues, "wveWaveBan", Features::waveban);
	ini.SetBoolValue(section_haxValues, "CustomCars", Features::CustomCar);
	ini.SetBoolValue(section_haxValues, "Alien2", Features::ptfx2car);
	ini.SetBoolValue(section_haxValues, "ClownAppears", Features::ptfx2car01);
	ini.SetBoolValue(section_haxValues, "Firework1", Features::ptfx2car02);
	ini.SetBoolValue(section_haxValues, "Firework2", Features::ptfx2car03);
	ini.SetBoolValue(section_haxValues, "Firework3", Features::ptfx2car04);
	ini.SetBoolValue(section_haxValues, "Banknotes", Features::ptfx2car05);
	ini.SetBoolValue(section_haxValues, "TruckCrash", Features::ptfx2car06);
	ini.SetBoolValue(section_haxValues, "Alien1", Features::ptfx2car07);
	ini.SetBoolValue(section_haxValues, "ElectricBox", Features::ptfx2car08);
	ini.SetBoolValue(section_haxValues, "WaterSplash", Features::ptfx2car09);
	ini.SetBoolValue(section_haxValues, "SniperImpact", Features::ptfx2car12);
	ini.SetBoolValue(section_haxValues, "DirtThrow", Features::ptfx2car13);
	ini.SetBoolValue(section_haxValues, "BloodStab", Features::ptfx2car14);
	ini.SetBoolValue(section_haxValues, "PedSliced", Features::ptfx2car15);
	ini.SetBoolValue(section_haxValues, "Camera", Features::ptfx2car16);
	ini.SetBoolValue(section_haxValues, "MethSmoke", Features::ptfx2car17);
	ini.SetBoolValue(section_haxValues, "BurialDirt", Features::ptfx2car18);
	ini.SetBoolValue(section_haxValues, "Rapidfire", Features::rapidfirer);
	ini.SetBoolValue(section_haxValues, "OffRadar", Features::orbool2);
	ini.SetBoolValue(section_haxValues, "showall", Features::showall);
	ini.SetBoolValue(section_haxValues, "ZoneAndStreet", Features::ZoneStreetbool);
	ini.SetBoolValue(section_haxValues, "Drift", Features::Drift);
	ini.SetBoolValue(section_haxValues, "burnout", Features::burnout);
	ini.SetBoolValue(section_haxValues, "rainbowneons", Features::Rneon);
	ini.SetBoolValue(section_haxValues, "tyresmoke", Features::Rainb);
	ini.SetBoolValue(section_haxValues, "SmokeTyre", Features::smoketyrebool);
	ini.SetBoolValue(section_haxValues, "Rainb2", Features::Rainb2);
	ini.SetBoolValue(section_haxValues, "Rcolor2", Features::Rcolor2);
	ini.SetBoolValue(section_haxValues, "Rneon2", Features::Rneon2);
	/*ini.SetBoolValue(section_haxValues, "VKDecimal", Features::vkdecimal);
	ini.SetBoolValue(section_haxValues, "VKAdd", Features::vkadd);
	ini.SetBoolValue(section_haxValues, "VKDivide", Features::vkdivide);
	ini.SetBoolValue(section_haxValues, "VKControl", Features::vkcontrol);
	ini.SetBoolValue(section_haxValues, "VKSubstract", Features::vksubstract);
	ini.SetBoolValue(section_haxValues, "VKF1", Features::vkf1);
	ini.SetBoolValue(section_haxValues, "VKF2", Features::vkf2);
	ini.SetBoolValue(section_haxValues, "VKF3", Features::vkf3);
	ini.SetBoolValue(section_haxValues, "VKF4", Features::vkf4);
	ini.SetBoolValue(section_haxValues, "VKF5", Features::vkf5);
	ini.SetBoolValue(section_haxValues, "VKF6", Features::vkf6);
	ini.SetBoolValue(section_haxValues, "VKF7", Features::vkf7);
	ini.SetBoolValue(section_haxValues, "VKF8", Features::vkf8);
	ini.SetBoolValue(section_haxValues, "VKF9", Features::vkf9);
	ini.SetBoolValue(section_haxValues, "VKF10", Features::vkf10);
	ini.SetBoolValue(section_haxValues, "VKF11", Features::vkf11);
	ini.SetBoolValue(section_haxValues, "VKF12", Features::vkf12);
	ini.SetBoolValue(section_haxValues, "VKMENU", Features::vkmenu);
	ini.SetBoolValue(section_haxValues, "VKNUMPAD1", Features::vknumpad1);
	ini.SetBoolValue(section_haxValues, "VKNUMPAD3", Features::vknumpad3);
	ini.SetBoolValue(section_haxValues, "VKNUMPAD7", Features::vknumpad7);
	ini.SetBoolValue(section_haxValues, "VKNUMPAD9", Features::vknumpad9);
	ini.SetBoolValue(section_haxValues, "VKBACK", Features::vkback);*/
	ini.SetBoolValue(section_haxValues, "ColorSave", Features::menucolors);
	ini.SetBoolValue(section_haxValues, "Dropsbool", Features::dropbool);
	ini.SetBoolValue(section_haxValues, "Selectbool", Features::selecArrow);
	ini.SetBoolValue(section_haxValues, "DisplayFPS", Features::DisplayFPS);
	ini.SetBoolValue(section_haxValues, "ESPName", Features::NameESP);
	ini.SetBoolValue(section_haxValues, "ESPLine", Features::esper);
	ini.SetBoolValue(section_haxValues, "driveonwater", Features::dowbool);
	ini.SetBoolValue(section_haxValues, "vehjump", Features::vehjump);
	ini.SetBoolValue(section_haxValues, "header02", Features::header02);
	ini.SetBoolValue(section_haxValues, "header012", Features::header012);
	ini.SetBoolValue(section_haxValues, "optionText1bool", Features::optionText1bool);
	ini.SetBoolValue(section_haxValues, "scroller0bool", Features::scroller0bool);
	ini.SetBoolValue(section_haxValues, "titlestextbool0", Features::titlestextbool);
	ini.SetBoolValue(section_haxValues, "menucolors", Features::menucolors);
	ini.SetBoolValue(section_haxValues, "dump", Hooking::dump);
	ini.SetBoolValue(section_haxValues, "protect", Hooking::protect);
	ini.SetBoolValue(section_haxValues, "redirectall", Hooking::redirectAll);
	ini.SetBoolValue(section_haxValues, "urMainProtect", Features::mainprotection);
	ini.SetBoolValue(section_haxValues, "geteventdata", Hooking::geteventdata);
	/*ini.SetBoolValue(section_haxValues, "loghashmap", Features::ThunderLog);*/
	ini.SetBoolValue(section_haxValues, "headerchanger", droptimer::picbackbool2);
	ini.SetBoolValue(section_haxValues, "backgroundchanger", droptimer::picbackbool);
//int

	ini.SetLongValue(section_haxValues, "keyPressDelay", Menu::Settings::keyPressDelay);
	ini.SetLongValue(section_haxValues, "keyHoldDelay", Menu::Settings::keyHoldDelay);
	ini.SetLongValue(section_haxValues, "keyPressCooldown", Menu::Settings::keyPressCooldown);


	ini.SetLongValue(section_haxValues, "TimerChatSpam", g_Settings.m_ChatSpammerTimer);
	ini.SetLongValue(section_haxValues, "tireSmokeColor1", Features::tireSmokeColor1);
	ini.SetLongValue(section_haxValues, "tireSmokeColor2", Features::tireSmokeColor2);
	ini.SetLongValue(section_haxValues, "tireSmokeColor3", Features::tireSmokeColor3);
	/*ini.SetLongValue(section_haxValues, "pearlescentColor", Features::pearlescentColor);
	ini.SetLongValue(section_haxValues, "wheelColor", Features::wheelColor);*/
	ini.SetLongValue(section_haxValues, "BoostBackKey", Menu2::BoostBackKey);
	ini.SetLongValue(section_haxValues, "FlyingCarsUp", flyingcars::up);
	ini.SetLongValue(section_haxValues, "FlyingCarsDown", flyingcars::down);
	ini.SetLongValue(section_haxValues, "FlyingCarsOpen", flyingcars::open);
	ini.SetLongValue(section_haxValues, "FreeCamOpen", noclips::open);
	ini.SetLongValue(section_haxValues, "TravelSpeed", Features::travelSpeed);
	ini.SetLongValue(section_haxValues, "HeadLightColor", Features::vehicleheadlight);
	ini.SetLongValue(section_haxValues, "DriftKey", Menu2::DriftKey);
	ini.SetLongValue(section_haxValues, "OpenMenu", Menu2::OpenMenu);
	ini.SetLongValue(section_haxValues, "OpenMenu8", Menu2::OpenMenu8);
	ini.SetLongValue(section_haxValues, "OpenMenu6", Menu2::OpenMenu6);
	ini.SetLongValue(section_haxValues, "OpenMenu5", Menu2::OpenMenu5);
	ini.SetLongValue(section_haxValues, "OpenMenu4", Menu2::OpenMenu4);
	ini.SetLongValue(section_haxValues, "OpenMenu2", Menu2::OpenMenu2);
	ini.SetLongValue(section_haxValues, "OpenMenu0", Menu2::OpenMenu0);
	ini.SetLongValue(section_haxValues, "rr", Features::rr);
	ini.SetLongValue(section_haxValues, "gg", Features::gg);
	ini.SetLongValue(section_haxValues, "bb", Features::bb);
	ini.SetLongValue(section_haxValues, "rr5", Features::rr5);
	ini.SetLongValue(section_haxValues, "gg5", Features::gg5);
	ini.SetLongValue(section_haxValues, "bb5", Features::bb5);
	ini.SetLongValue(section_haxValues, "rw2", Features::rw2);
	ini.SetLongValue(section_haxValues, "gw2", Features::gw2);
	ini.SetLongValue(section_haxValues, "bw2", Features::bw2);
	ini.SetLongValue(section_haxValues, "optionText6", Features::optionText6);
	ini.SetLongValue(section_haxValues, "optionText7", Features::optionText7);
	ini.SetLongValue(section_haxValues, "rw", Features::rw);
	ini.SetLongValue(section_haxValues, "gw", Features::gw);
	ini.SetLongValue(section_haxValues, "bw", Features::bw);
	ini.SetLongValue(section_haxValues, "Scroller4", Features::Scroller4);
	ini.SetLongValue(section_haxValues, "rw1", Features::rw1);
	ini.SetLongValue(section_haxValues, "gw1", Features::gw1);
	ini.SetLongValue(section_haxValues, "bw1", Features::bw1);
	ini.SetLongValue(section_haxValues, "title4", Features::title4);
	ini.SetLongValue(section_haxValues, "title5", Features::title5);
	ini.SetLongValue(section_haxValues, "RedLine", Features::redint);
	ini.SetLongValue(section_haxValues, "GreenLine", Features::greenint);
	ini.SetLongValue(section_haxValues, "BlueLine", Features::blueint);
	ini.SetLongValue(section_haxValues, "AlphaLine", Features::alphaint);
	ini.SetLongValue(section_haxValues, "WheelType", Features::bennystypeok);
	ini.SetLongValue(section_haxValues, "Wheel", Features::bennysok);
	ini.SetLongValue(section_haxValues, "paintcolor01", Features::paintcolor01);
	ini.SetLongValue(section_haxValues, "paintcolor02", Features::paintcolor02);
	ini.SetLongValue(section_haxValues, "paintcolor03", Features::paintcolor03);
	ini.SetLongValue(section_haxValues, "Chrome", Features::chrome);
	ini.SetLongValue(section_haxValues, "HornSound", Features::hornsound);
	ini.SetLongValue(section_haxValues, "timertimes", droptimer::timertimes);
	ini.SetLongValue(section_haxValues, "timertimes2", droptimer::timertimes2);
	ini.SetLongValue(section_haxValues, "lastpicid", timesback::lastpicid);
	ini.SetLongValue(section_haxValues, "lastpicid2", timesback::lastpicid2);
	ini.SetLongValue(section_haxValues, "picid", timesback::id);
	ini.SetLongValue(section_haxValues, "picid2", timesback::id2);
//float
	ini.SetDoubleValue(section_haxValues, "times_x", FeaturesOnline::zeropointcentvingt);
	ini.SetDoubleValue(section_haxValues, "times_y", FeaturesOnline::zeropointcentvingttrois);
	ini.SetDoubleValue(section_haxValues, "menutextsize", Features::zeropointquarantecinq);
	ini.SetDoubleValue(section_haxValues, "menutextfloatsize", Features::zeropointtrentedeux);
	ini.SetDoubleValue(section_haxValues, "speedometerleftright", Features::centvingt);
	ini.SetDoubleValue(section_haxValues, "speedometerupdown", Features::zeroundeuxtrois);
	ini.SetDoubleValue(section_haxValues, "speedometerbiggest", Features::zerotroiscentsoixantequinze);
	ini.SetDoubleValue(section_haxValues, "displayfpsx", Features::xzerovingt);
	ini.SetDoubleValue(section_haxValues, "displayfpsy", Features::yzerodix);
	ini.SetDoubleValue(section_haxValues, "menuxposition", Menu::Settings::menuX);
	ini.SetDoubleValue(section_haxValues, "menuyposition", Menu::Settings::menuY);
	ini.SetDoubleValue(section_haxValues, "menuxheaderposition", Features::menuXPositionX);
	ini.SetDoubleValue(section_haxValues, "zoneandstreetleftright", Features::zeropointcentvingtf);
	ini.SetDoubleValue(section_haxValues, "zoneandstreetupdown", Features::zeropointundeuxtroisf);
	ini.SetDoubleValue(section_haxValues, "zoneandstreetbiggest", Features::zeropointtroiscentsoixantequinzef);
	ini.SetDoubleValue(section_haxValues, "headerleftright", Features::zeropointhuitcent);
	ini.SetDoubleValue(section_haxValues, "headerupdown", Features::zeropointmillecentsoixantequinze);
	ini.SetDoubleValue(section_haxValues, "headerwidth", Features::zeropointvingtetun);
	ini.SetDoubleValue(section_haxValues, "backgroundleftright", Features::zeropointhuitcenttt);
	ini.SetDoubleValue(section_haxValues, "backgroundupdown", Features::zeropointmillecentsoixantequinzettt);
	ini.SetDoubleValue(section_haxValues, "backgroundwidth", Features::zeropointvingtetunttt);
	ini.SetDoubleValue(section_haxValues, "backgroundheight", Features::zeropointzeroquatrevingtcinq);
	ini.SetDoubleValue(section_haxValues, "picturex", Features::deuxzerosepthuit);
	ini.SetDoubleValue(section_haxValues, "picturey", Features::zerounquatredeux);
	ini.SetDoubleValue(section_haxValues, "pictureheight", Features::deuxzeroquinze);
	ini.SetDoubleValue(section_haxValues, "picturewidth", Features::deuxzerodeuxsept);
	ini.SetDoubleValue(section_haxValues, "screenx", Features::screenX);
	ini.SetDoubleValue(section_haxValues, "screeny", Features::screenY);
	ini.SetDoubleValue(section_haxValues, "widthscreen", Features::width);
	ini.SetDoubleValue(section_haxValues, "heightscreen", Features::height);
	ini.SetDoubleValue(section_haxValues, "headingscreen", Features::heading);
	ini.SetDoubleValue(section_haxValues, "ESPSize", Features::nameespsize);
	/*ini.SetDoubleValue(section_haxValues, "titleRectrr", Features::titleRectrr);
	ini.SetDoubleValue(section_haxValues, "titleRectgg", Features::titleRectgg);
	ini.SetDoubleValue(section_haxValues, "titleRectbb", Features::titleRectbb);
	ini.SetDoubleValue(section_haxValues, "titleRectaa", Features::titleRectaa);
	ini.SetDoubleValue(section_haxValues, "titleRectrrr", Features::titleRectrrr);
	ini.SetDoubleValue(section_haxValues, "titleRectggg", Features::titleRectggg);
	ini.SetDoubleValue(section_haxValues, "titleRectbbb", Features::titleRectbbb);
	ini.SetDoubleValue(section_haxValues, "titleRectaaa", Features::titleRectaaa);
	ini.SetDoubleValue(section_haxValues, "optionsRectrr5", Features::optionsRectrr5);
	ini.SetDoubleValue(section_haxValues, "optionsRectgg5", Features::optionsRectgg5);
	ini.SetDoubleValue(section_haxValues, "optionsRectbb5", Features::optionsRectbb5);
	ini.SetDoubleValue(section_haxValues, "optionsRectgg2", Features::optionsRectgg2);
	ini.SetDoubleValue(section_haxValues, "optionsRectbb2", Features::optionsRectbb2);
	ini.SetDoubleValue(section_haxValues, "optionsRectaa2", Features::optionsRectaa2);
	ini.SetDoubleValue(section_haxValues, "optionTextrw2", Features::optionTextrw2);
	ini.SetDoubleValue(section_haxValues, "optionTextgw2", Features::optionTextgw2);
	ini.SetDoubleValue(section_haxValues, "optionTextbw2", Features::optionTextbw2);
	ini.SetDoubleValue(section_haxValues, "optionText33", Features::optionText33);
	ini.SetDoubleValue(section_haxValues, "optionText44", Features::optionText44);
	ini.SetDoubleValue(section_haxValues, "optionText55", Features::optionText55);
	ini.SetDoubleValue(section_haxValues, "optionText66", Features::optionText66);
	ini.SetDoubleValue(section_haxValues, "optionText77", Features::optionText77);
	ini.SetDoubleValue(section_haxValues, "Scrollerrw", Features::Scrollerrw);
	ini.SetDoubleValue(section_haxValues, "Scrollergw", Features::Scrollergw);
	ini.SetDoubleValue(section_haxValues, "Scrollerbw", Features::Scrollerbw);
	ini.SetDoubleValue(section_haxValues, "Scroller11", Features::Scroller11);
	ini.SetDoubleValue(section_haxValues, "Scroller22", Features::Scroller22);
	ini.SetDoubleValue(section_haxValues, "Scroller33", Features::Scroller33);
	ini.SetDoubleValue(section_haxValues, "Scroller44", Features::Scroller44);
	ini.SetDoubleValue(section_haxValues, "titleTextrw1", Features::titleTextrw1);
	ini.SetDoubleValue(section_haxValues, "titleTextgw1", Features::titleTextgw1);
	ini.SetDoubleValue(section_haxValues, "titleTextbw1", Features::titleTextbw1);
	ini.SetDoubleValue(section_haxValues, "titleText1", Features::titleText1);
	ini.SetDoubleValue(section_haxValues, "titleText2", Features::titleText2);
	ini.SetDoubleValue(section_haxValues, "titleText3", Features::titleText3);
	ini.SetDoubleValue(section_haxValues, "titleText4", Features::titleText4);
	ini.SetDoubleValue(section_haxValues, "titleText5", Features::titleText5);*/
//text
	ini.SetValue(section_haxValues, "ChatMessage", g_Settings.m_ChatMessageInput);
	ini.SetValue(section_haxValues, "nameEffect", Features::nameEffect);
	ini.SetValue(section_haxValues, "HeaderMenu", Features::HeaderMenu.c_str());
	ini.SetValue(section_haxValues, "HeaderMenu2", Features::HeaderMenu2.c_str());
	ini.SetValue(section_haxValues, "Background", headers::Background.c_str());	
	ini.SetValue(section_haxValues, "Background2", headers::Background2.c_str());
	ini.SetValue(section_haxValues, "Filechoosen", timesback::filechoosen.c_str());
	ini.SetValue(section_haxValues, "Filechoosen2", timesback::filechoosen2.c_str());
	ini.SetValue(section_haxValues, "Design", timesback::backgroundfile.c_str());
	ini.SetValue(section_haxValues, "hudcolor1", Features::hudcolor1.c_str());
	ini.SetValue(section_haxValues, "hudcolor2", Features::hudcolor2.c_str());
	ini.SetValue(section_haxValues, "username", Features::username.c_str());
	ini.SetValue(section_haxValues, "AuthSound", Features::Sounds1.c_str());
	ini.SetValue(section_haxValues, "AuthNotify", Features::Notify.c_str());
	ini.SetValue(section_haxValues, "user", authentification2::username2.c_str());
	ini.SetValue(section_haxValues, "pass", authentification2::password2.c_str());
	ini.SetValue(section_haxValues, "IDSpoof", Hookings::IDSpoof.c_str());
	ini.SetValue(section_haxValues, "IPSpoof", Hookings::IPSpoof.c_str());
	ini.SetValue(section_haxValues, "NamesSpoof", Hookings::m_Name.c_str());
	//ini.SetValue(section_haxValues, "lang", langage::rawchar2);	
//save
	ini.SaveFile((GetPathffA(Pathff::ThunderMenu, true) + "ThunderConfig.ini").c_str());
}
bool firstread = 1;
//bool firstread2 = 1;
bool loaded::FirstTimer = 0;

void ThreadThunderConfig()
{
	//for (UINT8 configT = 0; MenuConfig::ConfigInit() < 0 && configT < 10; configT++)
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	bool bConfigHasNotBeenRead = true;
	DWORD _programTick = 0U;
	//if (!firstread)

	//std::this_thread::sleep_for(std::chrono::seconds(1));


	for (;;)
	{
		//if (!firstread)
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		_programTick++;
		if (firstread)
		{
			if (_programTick % 1000 == 0 && MenuConfig::bSaveAtIntervals)
			{
				//MenuConfig::ConfigInit();
				MenuConfig::ConfigSave();
			}
			firstread = 0;
		}
		if (!firstread)
		{
			if (_programTick % 30000 == 0 && MenuConfig::bSaveAtIntervals)
			{
				//MenuConfig::ConfigInit();
				MenuConfig::ConfigSave();
			}
		}
		if (bConfigHasNotBeenRead)
		{
			if (MenuConfig::ConfigInit() < 0)
			{
				string mainconfig = converter::ws2s(GetPathffW(Pathff::ThunderMenu, true));
				/*ige::myLog << ige::LogType::LOG_ERROR << "Failed to load ThunderConfig from " << mainconfig << "ThunderConfig.ini.";*/
			}
			else
			{
				//MenuConfig::ConfigInit();
				MenuConfig::ConfigRead();
				/*if (firstread)
				{*/
				//firstloading();
					loaded::FirstTimer = 1;

				//}
			}
			bConfigHasNotBeenRead = false;
		}

	}
}

