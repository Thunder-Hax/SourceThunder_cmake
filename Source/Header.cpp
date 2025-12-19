#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <functional>

#include <algorithm>

#include "MyTimer.h"

#include <Shlwapi.h> //PathRemoveFileSpecA banner
#pragma comment(lib, "shlwapi.lib")//banner

#include <iomanip>
#include <vector>
#include <numeric>

#include <Windows.h>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

#include "base64caller.h"
#include "Features.h"

using namespace std;
int headers::StringToInteger2(string NumberAsString)
{
	int NumberAsInteger = 0;
	for (int i = 0; i < NumberAsString.size(); i++)
		NumberAsInteger = NumberAsInteger * 10 + (NumberAsString[i] - '0');

	return NumberAsInteger;
}
float headers::timesdelays = 25;
int headers::randomlytimesbool1 = 14, headers::randomlytimesbool2 = 0, headers::randomlytimesbool3 = 14;
void headers::randomlyvoid()
{
	if ((timeGetTime() - Features::RandomlyTimes) > headers::timesdelays)
	{
		if (headers::randomlytimesbool1 > 0 && headers::randomlytimesbool3 == 14) {
			if ((timeGetTime() - Features::RandomlyTimes) > headers::timesdelays)
			{
				headers::randomlytimesbool1--;
				headers::randomlytimesbool2++;
			}
		}
		if (headers::randomlytimesbool2 > 0 && headers::randomlytimesbool1 == 0) {
			if ((timeGetTime() - Features::RandomlyTimes) > headers::timesdelays)
			{
				headers::randomlytimesbool2--;
				headers::randomlytimesbool3++;
			}
		}
		if (headers::randomlytimesbool3 > 0 && headers::randomlytimesbool2 == 0) {
			if ((timeGetTime() - Features::RandomlyTimes) > headers::timesdelays)
			{
				headers::randomlytimesbool1++;
				headers::randomlytimesbool3--;
			}
		}
	}
	Features::RandomlyTimes = timeGetTime();
}

std::string headers::Background = "";
std::string headers::Background2 = "";
bool headers::randomtimerbool = false;
bool headers::randomtimerbool2 = false;
bool headers::boolrandomlytimes() {
	/*string backgrounddata2;
	string backgrounddatas2;
	string  backgroundpath22;
	backgroundpath22 = getenv("appdata");
	ifstream headermenu22;
	headermenu22.open(backgroundpath22 + "\\ThunderMenu\\Background.Thunder");
	if (headermenu22) {
		headermenu22 >> backgrounddata2, 1;
		headermenu22 >> backgrounddatas2, 2;*/
	if (headers::Background != "")
	{
		/*string none = "none";
		int nones = headers::StringToInteger2(none);*/
		/*int backgrounddatass = headers::StringToInteger2(backgrounddatas2);*/
		int backgrounddatass = headers::StringToInteger2(headers::Background);
		/*if (backgrounddatass == nones) {
		}*/
		string random = "random";
		int randoms = headers::StringToInteger2(random);
		if (backgrounddatass == randoms) {
			headers::randomlyvoid();
			if (headers::randomlytimesbool1 == 0) {
				//Menu::Drawing::Spriter2(backgrounddata2, "Thunder1", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
				Menu::Drawing::Spriter2(headers::Background, "Thunder0", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 1) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder1", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 2) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder2", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 3) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder3", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 4) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder4", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 5) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder5", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 6) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder6", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 7) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder7", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 8) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder8", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 9) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder9", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 10) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder10", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 11) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder11", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 12) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder12", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 13) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder13", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 14) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder14", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 15) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder15", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 15) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder16", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool1 == 15) {
				Menu::Drawing::Spriter2(headers::Background, "Thunder17", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			headers::randomtimerbool = true;
			return (bool)headers::boolrandomlytimes;
		}
		else {
			headers::randomtimerbool = false;
		}
	}
	headers::randomtimerbool = false;
	return 0;
}
bool headers::boolrandomlytimes2() {
	/*string ddata2;
	string ddatas2;
	string  headpath22;
	headpath22 = getenv("appdata");
	ifstream headermenu22;
	headermenu22.open(headpath22 + "\\ThunderMenu\\HeaderMenu.Thunder");
	if (headermenu22) {
		headermenu22 >> ddata2, 1;
		headermenu22 >> ddatas2, 2;*/
	if (Features::HeaderMenu != "")
	{
		/*string none = "none";
		int nones = headers::StringToInteger2(none);*/
		/*int ddatass = headers::StringToInteger2(ddatas2);*/
		int ddatass = headers::StringToInteger2(Features::HeaderMenu);
		/*if (ddatass == nones) {
		}*/
		string random = "random";
		int randoms = headers::StringToInteger2(random);
		if (ddatass == randoms) {
			headers::randomlyvoid();
			if (headers::randomlytimesbool2 == 0) {
				//Menu::Drawing::Spriter2(ddata2, "Thunder1", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder0", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 1) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder1", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 2) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder2", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 3) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder3", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 4) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder4", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 5) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder5", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 6) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder6", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 7) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder7", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 8) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder8", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 9) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder9", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 10) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder10", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 11) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder11", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 12) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder12", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 13) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder13", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 14) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder14", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 15) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder15", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 15) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder16", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			if (headers::randomlytimesbool2 == 15) {
				Menu::Drawing::Spriter2(Features::HeaderMenu, "Thunder17", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			}
			headers::randomtimerbool2 = true;
			return (bool)headers::boolrandomlytimes2;
		}
		else {
			headers::randomtimerbool2 = false;
		}
	}
	headers::randomtimerbool2 = false;
	return 0;
}
int headers::thunderheaders() {
	/*string data2;
	string type2;
	string  path22;
	path22 = getenv("appdata");
	ifstream headermenu22;
	headermenu22.open(path22 + "\\ThunderMenu\\HeaderMenu.Thunder");
	if (headermenu22) {
		headermenu22 >> data2, 1;
		headermenu22 >> type2, 2;*/
	if (Features::HeaderMenu != "")
	{
		string none = "none";
		int nones = headers::StringToInteger2(none);
		/*int types = headers::StringToInteger2(type2);*/
		/*int types = headers::StringToInteger2(Features::HeaderMenu2);*/
		int types = headers::StringToInteger2(Features::HeaderMenu);
		if (types == nones) {
			if (headers::randomtimerbool2) {
				headers::randomtimerbool2 = false;
			}
			return 0;
		}
		string random = "random";
		int randoms2 = headers::StringToInteger2(random);
		if (types == randoms2) {
			boolrandomlytimes2();
		}
		else {
			if (headers::randomtimerbool2) {
				headers::randomtimerbool2 = false;
			}
		}
		Menu::Drawing::Spriter(Features::HeaderMenu, Features::HeaderMenu2, Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
		//Menu::Drawing::NATIVE_DRAW_SPRITE(converter::string2char(Features::HeaderMenu), converter::string2char(Features::HeaderMenu2), Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
	}
	else {
		Menu::Drawing::Spriter("11_a_sext_taxiliz", "11_a_sext_taxiliz", Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
	}
	return 0;
}
int headers::thunderbackgrounds() {
	if (headers::Background != "")
	{
		string none = "none";
		int nones = headers::StringToInteger2(none);
		int backgrounddatass = headers::StringToInteger2(headers::Background);
		if (backgrounddatass == nones) {
			if (headers::randomtimerbool) {
				headers::randomtimerbool = false;
			}
			return 0;
		}
		string random = "random";
		int randoms = headers::StringToInteger2(random);
		if (backgrounddatass == randoms) {
			headers::boolrandomlytimes();
		}
		else {
			if (headers::randomtimerbool) {
				headers::randomtimerbool = false;
			}
		}
		Menu::Drawing::Spriter2(headers::Background, headers::Background2, Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
	}
	else {
		Menu::Drawing::Spriter2("11_a_sext_taxiliz", "11_a_sext_taxiliz", Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
	}
	return 0;
}

int timesback::id2 = 1;
int timesback::lastpicid2 = 5;

bool timesback::imagebool2()
{
	if (droptimer::backbool2)
	{
		if (timesback::id2 < timesback::lastpicid2)
		{
			int timesreturn = timesback::id2 + 1;
			timesback::id2 = timesreturn;
			string thundermenu3 = (char*)"Thunder";
			string thundermenu23 = (char*)"Thunder0" + to_string(timesback::id2);
			Features::HeaderMenu = thundermenu3;
			Features::HeaderMenu2 = thundermenu23;
			/*Menu::Drawing::Header(Features::HeaderMenu, Features::HeaderMenu2, Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);*/
			Menu::Drawing::NATIVE_DRAW_SPRITE1((char*)Features::HeaderMenu.c_str(), (char*)Features::HeaderMenu2.c_str(), Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			droptimer::backbool2 = false;
		}
		else
			if (timesback::id2 = timesback::lastpicid2)
			{
				timesback::id2 = 1;
				string thundermenu3 = (char*)"Thunder";
				string thundermenu23 = (char*)"Thunder0" + to_string(timesback::id2);
				Features::HeaderMenu = thundermenu3;
				Features::HeaderMenu2 = thundermenu23;
				Menu::Drawing::NATIVE_DRAW_SPRITE1((char*)Features::HeaderMenu.c_str(), (char*)Features::HeaderMenu2.c_str(), Features::zeropointhuitcent, Features::zeropointmillecentsoixantequinze, Features::zeropointvingtetun, 0.085f, 0, 50, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
				droptimer::backbool2 = false;
			}
	}
	return 0;
}
int timesback::anybacktime2()
{
	if (!Menu::Settings::menuclosed)
	{
	}
	else
	{
		timesback::imagebool2();
	}
	return 0;
}

int timesback::id = 1;
int timesback::lastpicid = 18;
bool timesback::boolThor21 = 0;
bool timesback::boolThor1 = 1;
bool timesback::boolThor6 = 0;
bool timesback::boolThor5 = 0;
bool timesback::boolThor2 = 0;

bool timesback::boolThor0 = 0;
bool timesback::boolThor20 = 0;
bool timesback::boolThor03 = 0;
bool timesback::boolThor23 = 0;
bool timesback::boolThor04 = 0;
bool timesback::boolThor24 = 0;

bool timesback::Darkside1 = 0;
bool timesback::Darkside2 = 0;
bool timesback::Darkside3 = 0;
bool timesback::Darkside32 = 0;
bool timesback::Darkside4 = 0;
bool timesback::Darkside5 = 0;
bool timesback::Darkside6 = 0;
bool timesback::Darkside7 = 0;
bool timesback::Darkside8 = 0;
bool timesback::Darkside82 = 0;
bool timesback::Darkside9 = 0;
bool timesback::Darkside10 = 0;
bool timesback::Darkside11 = 0;
bool timesback::Darkside12 = 0;
bool timesback::Darkside22 = 0;
bool timesback::Darkside13 = 0;
bool timesback::Darkside14 = 0;
bool timesback::Darkside142 = 0;
bool timesback::Darkside15 = 0;
bool timesback::Darkside16 = 0;
bool timesback::Darkside17 = 0;
bool timesback::Darkside18 = 0;
bool timesback::Darkside19 = 0;
bool timesback::Darkside20 = 0;
bool timesback::Darkside21 = 0;

bool boolactive::activebool1 = 1;
bool boolactive::activebool2 = 1;
bool boolactive::activebool3 = 1;
bool boolactive::activebool4 = 1;
bool boolactive::activebool5 = 1;
bool boolactive::activebool6 = 1;
bool boolactive::activebool7 = 1;
bool boolactive::activebool8 = 1;
bool boolactive::activebool9 = 1;
bool boolactive::activebool10 = 1;
bool boolactive::activebool11 = 1;
bool boolactive::activebool12 = 1;
bool boolactive::activebool13 = 1;
bool boolactive::activebool14 = 1;
bool boolactive::activebool15 = 1;
bool boolactive::activebool16 = 1;
bool boolactive::activebool17 = 1;
bool boolactive::activebool18 = 1;
bool boolactive::activebool19 = 1;
bool boolactive::activebool20 = 1;
bool boolactive::activebool21 = 1;
bool boolactive::activeboold21 = 1;
bool boolactive::activebool22 = 1;
bool boolactive::activebool23 = 1;
bool boolactive::activebool = 1;


bool boolactive::blackhole1 = 1;
bool boolactive::blackhole2 = 1;
bool boolactive::blackhole3 = 1;
bool boolactive::blackhole4 = 1;
bool boolactive::blackhole5 = 1;
bool boolactive::blackhole6 = 1;
bool boolactive::blackhole7 = 1;
bool boolactive::blackhole8 = 1;
bool boolactive::blackhole9 = 1;
bool boolactive::blackhole10 = 1;
bool boolactive::blackhole11 = 1;
bool boolactive::blackhole12 = 1;
bool boolactive::blackhole13 = 1;
bool boolactive::blackhole14 = 1;
bool boolactive::blackhole15 = 1;
bool boolactive::blackhole16 = 1;
bool boolactive::blackhole17 = 1;
bool boolactive::blackhole18 = 1;
bool boolactive::blackhole19 = 1;
bool boolactive::blackhole20 = 1;
bool boolactive::blackhole21 = 1;
bool boolactive::blackhole22 = 1;
bool boolactive::blackhole23 = 1;
bool boolactive::blackhole24 = 1;
bool boolactive::blackhole25 = 1;
bool boolactive::blackhole26 = 1;
bool boolactive::blackhole27 = 1;
bool boolactive::blackhole272 = 1;
bool boolactive::blackhole28 = 1;
bool boolactive::blackhole29 = 1;
bool boolactive::blackhole30 = 1;
bool boolactive::blackhole31 = 1;
bool boolactive::blackhole32 = 1;
bool boolactive::blackhole33 = 1;
bool boolactive::blackhole333 = 1;
bool boolactive::blackhole34 = 1;
bool boolactive::blackhole35 = 1;
bool boolactive::blackhole36 = 1;
bool boolactive::blackhole37 = 1;
bool boolactive::blackhole38 = 1;
bool boolactive::blackhole39 = 1;
bool boolactive::blackhole40 = 1;
bool boolactive::blackhole41 = 1;
bool boolactive::blackhole42 = 1;
bool boolactive::blackhole43 = 1;
bool boolactive::blackhole44 = 1;
bool boolactive::blackhole45 = 1;
bool boolactive::blackhole46 = 1;
bool boolactive::blackhole47 = 1;
bool boolactive::blackhole48 = 1;
bool boolactive::blackhole49 = 1;
bool boolactive::blackhole50 = 1;
bool boolactive::blackhole51 = 1;
bool boolactive::blackhole52 = 1;
bool boolactive::blackhole53 = 1;
bool boolactive::blackhole54 = 1;
bool boolactive::blackhole55 = 1;
bool boolactive::blackhole56 = 1;
bool boolactive::blackhole57 = 1;
bool boolactive::blackhole58 = 1;
bool boolactive::blackhole59 = 1;
bool boolactive::blackhole60 = 1;
bool boolactive::blackhole61 = 1;
bool boolactive::blackhole62 = 1;
bool boolactive::blackhole63 = 1;
bool boolactive::blackhole64 = 1;
bool boolactive::blackhole65 = 1;
bool boolactive::blackhole66 = 1;
bool boolactive::blackhole67 = 1;
bool boolactive::blackhole68 = 1;
bool boolactive::blackhole69 = 1;
bool boolactive::blackhole70 = 1;
bool boolactive::blackhole71 = 1;
bool boolactive::blackhole72 = 1;
bool boolactive::blackhole73 = 1;
bool boolactive::blackhole74 = 1;
bool boolactive::blackhole75 = 1;
bool boolactive::blackhole76 = 1;
bool boolactive::blackhole502 = 1;
bool boolactive::blackhole352 = 1;
bool boolactive::blackhole552 = 1;
bool boolactive::blackhole622 = 1;
bool boolactive::blackhole392 = 1;

std::string timesback::backgroundfile = (char*)"Thunder";
std::string timesback::filechoosen = (char*)"Thunder";
std::string timesback::filechoosen2 = (char*)"";
std::string timesback::thundermenu = (char*)"Thunder";

bool timesback::blackhole1 = 0;
bool blackhole2 = 0;
bool blackhole3 = 0;
bool blackhole4 = 0;
bool blackhole5 = 0;
bool blackhole6 = 0;
bool blackhole7 = 0;
bool blackhole8 = 0;
bool blackhole9 = 0;
bool blackhole10 = 0;
bool blackhole11 = 0;
bool blackhole12 = 0;
bool blackhole13 = 0;
bool blackhole14 = 0;
bool blackhole15 = 0;
bool blackhole16 = 0;
bool blackhole17 = 0;
bool blackhole18 = 0;
bool blackhole19 = 0;
bool blackhole20 = 0;
bool blackhole21 = 0;
bool blackhole22 = 0;
bool blackhole23 = 0;
bool timesback::blackhole232 = 0;
bool blackhole24 = 0;
bool blackhole25 = 0;
bool blackhole26 = 0;
bool blackhole27 = 0;
bool blackhole272 = 0;
bool blackhole28 = 0;
bool blackhole29 = 0;
bool blackhole30 = 0;
bool blackhole31 = 0;
bool blackhole32 = 0;
bool blackhole352 = 0;
bool blackhole33 = 0;
bool blackhole333 = 0;
bool blackhole34 = 0;
bool blackhole342 = 0;
bool blackhole35 = 0;
bool blackhole36 = 0;
bool blackhole37 = 0;
bool blackhole38 = 0;
bool blackhole39 = 0;
bool timesback::blackhole392 = 0;
bool blackhole40 = 0;
bool blackhole41 = 0;
bool blackhole42 = 0;
bool blackhole43 = 0;
bool blackhole44 = 0;
bool blackhole45 = 0;
bool blackhole46 = 0;
bool blackhole47 = 0;
bool blackhole48 = 0;
bool blackhole49 = 0;
bool blackhole50 = 0;
bool blackhole502 = 0;
bool blackhole51 = 0;
bool blackhole52 = 0;
bool blackhole53 = 0;
bool blackhole54 = 0;
bool blackhole55 = 0;
bool blackhole56 = 0;
bool blackhole57 = 0;
bool blackhole58 = 0;
bool blackhole59 = 0;
bool blackhole60 = 0;
bool blackhole61 = 0;
bool blackhole62 = 0;
bool timesback::blackhole63 = 0;
bool blackhole64 = 0;
bool blackhole65 = 0;
bool blackhole66 = 0;
bool blackhole67 = 0;
bool blackhole68 = 0;
bool blackhole69 = 0;
bool blackhole70 = 0;
bool blackhole71 = 0;
bool blackhole72 = 0;
bool blackhole73 = 0;
bool blackhole74 = 0;
bool blackhole75 = 0;
bool blackhole76 = 0;
bool blackhole552 = 0;
bool blackhole622 = 0;

//int headers::readbackground()
//{
//	MenuConfig::ConfigInit();
//	PCHAR section_haxValues = "Thunder-Menu";
//	auto& ini = MenuConfig::iniFile;
//
//	/*droptimer::timertimes = ini.GetLongValue(section_haxValues, "timertimes", droptimer::timertimes);
//	droptimer::timertimes2 = ini.GetLongValue(section_haxValues, "timertimes2", droptimer::timertimes2);
//	timesback::lastpicid = ini.GetLongValue(section_haxValues, "lastpicid", timesback::lastpicid);
//	timesback::lastpicid2 = ini.GetLongValue(section_haxValues, "lastpicid2", timesback::lastpicid2);
//	timesback::id = ini.GetLongValue(section_haxValues, "picid", timesback::id);
//	timesback::id2 = ini.GetLongValue(section_haxValues, "picid2", timesback::id2);
//	Features::HeaderMenu = ini.GetValue(section_haxValues, "HeaderMenu", Features::HeaderMenu.c_str());
//	Features::HeaderMenu2 = ini.GetValue(section_haxValues, "HeaderMenu2", Features::HeaderMenu2.c_str());
//	headers::Background = ini.GetValue(section_haxValues, "Background", headers::Background.c_str());
//	headers::Background2 = ini.GetValue(section_haxValues, "Background2", headers::Background2.c_str());
//	timesback::backgroundfile = ini.GetValue(section_haxValues, "Design", timesback::backgroundfile.c_str());*/
//	return 0;
//}
bool headers::filesearch = 1;
int headers::searchfile()
{
	DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;
	ticks /= 1000;
	DWORD seconds = ticks % 60;
	//ticks /= 60;
	//DWORD minutes = ticks % 60;
	//ticks /= 60;
	//DWORD hours = ticks; // may exceed 24 hours.
	/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
	int getTimer = milliseconds;
	if (getTimer % 200 == 0)
	{
		char* charThunderGround1 = new char[timesback::filechoosen2.length() + 1];
		strcpy(charThunderGround1, timesback::filechoosen2.c_str());

		if (charThunderGround1 == "Thunder")
		{
			timesback::backgroundfile = ((char*)"Thunder");
			timesback::thundermenu = (char*)"Thunder";
			timesback::filechoosen = "Thunder";
			timesback::id = 1;
			timesback::lastpicid = 18;
			droptimer::timertimes = 200;
			Menu2::Darkside = 0;
		}
		if (charThunderGround1 == "Space")
		{
			timesback::backgroundfile = ((char*)"Space_");
			timesback::id = 1;
			timesback::lastpicid = 49;
			timesback::filechoosen = "Space";
			timesback::thundermenu = (char*)"Thunder";
			droptimer::timertimes = 1;
			Menu2::Darkside = 0;
		}
		if (charThunderGround1 == "Dark")
		{
			timesback::backgroundfile = ((char*)"frame_");
			timesback::filechoosen = "Dark";
			timesback::id = 0;
			timesback::lastpicid = 88;
			timesback::thundermenu = (char*)"Thunder";
			timesback::backgroundfile = (char*)"frame_";
			droptimer::timertimes = 1;
			Menu2::Darkside = 0;
		}
		if (charThunderGround1 == "Darkside")
		{
			Menu::Loading::registerswitch(LDarkside1);
			timesback::backgroundfile = ((char*)"Darkside");
			timesback::id = 1248;
			timesback::lastpicid = 1324;
			droptimer::timertimes = 1;
			timesback::filechoosen = "Darkside";
			timesback::thundermenu = (char*)"Darkside1-GTA5";
			timesback::backgroundfile = (char*)"Darkside";
			timesback::Darkside1 = 1;
			Menu2::Darkside = 1;
		}
		if (charThunderGround1 == "Thor")
		{
			Menu::Loading::registerswitch(Thor21);
			timesback::boolThor21 = 1;
			timesback::id = 717;
			timesback::lastpicid = 793;
			timesback::thundermenu = (char*)"Thor21";
			timesback::filechoosen = "Thor";
			timesback::backgroundfile = (char*)"Thor"; //namepicture thundermenu
			droptimer::timertimes = 1;
			Menu2::Darkside = 1;
		}
		if (charThunderGround1 == "Thor2")
		{
			Menu::Loading::registerswitch(Thor);
			timesback::boolThor0 = 1;
			timesback::id = 4999;
			timesback::lastpicid = 5086;
			timesback::thundermenu = (char*)"Thor";
			timesback::filechoosen = "Thor2";
			timesback::backgroundfile = (char*)"Thor";
			droptimer::timertimes = 1;
			Menu2::Darkside = 1;
		}
		if (charThunderGround1 == "Blackhole")
		{
			Menu::Loading::registerswitch(Blackhole1);
			timesback::backgroundfile = (char*)"Blackhole";
			timesback::id = 8597;
			timesback::lastpicid = 8673;
			droptimer::timertimes = 1;
			timesback::thundermenu = (char*)"Blackhole1";
			timesback::filechoosen = "Blackhole";
			timesback::filechoosen2 = "Blackhole";
			timesback::blackhole1 = 1;
			Menu2::Darkside = 1;
		}
		if (charThunderGround1 == "Blackhole1")
		{
			Menu::Loading::registerswitch(Blackhole39);
			timesback::backgroundfile = (char*)"Blackhole";
			timesback::id = 18498;
			timesback::lastpicid = 18515;
			droptimer::timertimes = 1;
			timesback::thundermenu = (char*)"Blackhole39";
			timesback::filechoosen = "Blackhole1";
			timesback::filechoosen2 = "Blackhole1";
			timesback::blackhole1 = 1;
			Menu2::Darkside = 1;
		}
		if (charThunderGround1 == "Blackhole2")
		{
			Menu::Loading::registerswitch(Blackhole23);
			timesback::id = 10349;
			timesback::lastpicid = 10367;
			timesback::thundermenu = (char*)"Blackhole23";
			timesback::backgroundfile = (char*)"Blackhole";
			timesback::blackhole232 = 1;			
			droptimer::timertimes = 1;
			timesback::filechoosen = "Blackhole2";
			timesback::filechoosen2 = "Blackhole2";
			Menu2::Darkside = 1;
		}

		if (charThunderGround1 == "Blackhole3")
		{
			Menu::Loading::registerswitch(Blackhole63);
			timesback::id = 6430;
			timesback::lastpicid = 6506;
			timesback::thundermenu = (char*)"Blackhole63";
			timesback::backgroundfile = (char*)"Blackhole";
			timesback::blackhole63 = 1;
			droptimer::timertimes = 1;
			timesback::filechoosen = "Blackhole3";
			timesback::filechoosen2 = "Blackhole3";
			Menu2::Darkside = 1;
		}
		if (charThunderGround1 == "none")
		{
			timesback::backgroundfile = ((char*)"");
			droptimer::picbackbool = false;
			timesback::id = 1;
			droptimer::backbool = 1;
			droptimer::boolback = 1;
			Menu2::Darkside = 0;
		}
		headers::filesearch = 0;
	}
	return 0;
}
bool timesback::imagebool()
{
	if (boolactive::activebool23)
	{
		headers::filesearch = 1;
		boolactive::activebool23 = 0;
	}
	if (boolactive::activebool)
	{
		boolactive::activebool1 = 1;
		boolactive::activebool2 = 1;
		boolactive::activebool3 = 1;
		boolactive::activebool4 = 1;
		boolactive::activebool5 = 1;
		boolactive::activebool6 = 1;
		boolactive::activebool7 = 1;
		boolactive::activebool8 = 1;
		boolactive::activebool9 = 1;
		boolactive::activebool10 = 1;
		boolactive::activebool11 = 1;
		boolactive::activebool12 = 1;
		boolactive::activebool13 = 1;
		boolactive::activebool14 = 1;
		boolactive::activebool15 = 1;
		boolactive::activebool16 = 1;
		boolactive::activebool17 = 1;
		boolactive::activebool18 = 1;
		boolactive::activebool19 = 1;
		boolactive::activebool20 = 1;
		boolactive::activebool21 = 1;
		boolactive::activebool22 = 1;
	}
	if (!headers::filesearch)
	{
	if (droptimer::backbool)
	{
		/*if (timesback::id < timesback::lastpicid)
		{
			int timesreturn = timesback::id + 1;
			timesback::id = timesreturn;
			string thundermenu = (char*)"Thunder";
			string thundermenu2 = timesback::backgroundfile + to_string(timesback::id);
			headers::Background = thundermenu;
			headers::Background2 = thundermenu2;
			Menu::Drawing::NATIVE_DRAW_SPRITE2((char*)headers::Background.c_str(), (char*)headers::Background2.c_str(), Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			droptimer::backbool = false;
		}
		else
			if (timesback::id = timesback::lastpicid)
			{
				timesback::id = 1;
				string thundermenu = (char*)"Thunder";
				string thundermenu2 = timesback::backgroundfile + to_string(timesback::id);
				headers::Background = thundermenu;
				headers::Background2 = thundermenu2;
				Menu::Drawing::NATIVE_DRAW_SPRITE2((char*)headers::Background.c_str(), (char*)headers::Background2.c_str(), Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
				droptimer::backbool = false;
			}*/
		if (timesback::id < timesback::lastpicid)
		{
			int timesreturn = timesback::id + 1;
			timesback::id = timesreturn;
			if (timesback::filechoosen == "Thor")
			{
				if (boolThor1)
				{
					timesback::thundermenu = (char*)"Thor1";
					timesback::backgroundfile = (char*)"Thor"; //namepicture
				}
				if (boolThor6)
				{
					timesback::thundermenu = (char*)"Thor22";
					timesback::backgroundfile = (char*)"Thor"; //namepicture
				}
				if (boolThor5)
				{
					timesback::thundermenu = (char*)"Thor2";
					timesback::backgroundfile = (char*)"Thor";
				}
				if (boolThor21)
				{
					timesback::thundermenu = (char*)"Thor21";
					timesback::backgroundfile = (char*)"Thor";
				}
			}
			if (timesback::filechoosen == "Thor2")
			{
				if (boolThor0)
				{
					timesback::thundermenu = (char*)"Thor";
					timesback::backgroundfile = (char*)"Thor";
				}
				if (boolThor20)
				{
					timesback::thundermenu = (char*)"Thor20";
					timesback::backgroundfile = (char*)"Thor";
				}
				if (boolThor03)
				{

					timesback::thundermenu = (char*)"Thor3";
					timesback::backgroundfile = (char*)"Thor";
				}
				if (boolThor23)
				{
					timesback::thundermenu = (char*)"Thor23";
					timesback::backgroundfile = (char*)"Thor";
				}
				if (boolThor04)
				{
					timesback::thundermenu = (char*)"Thor4";
					timesback::backgroundfile = (char*)"Thor";
				}
				if (boolThor24)
				{
					timesback::thundermenu = (char*)"Thor24";
					timesback::backgroundfile = (char*)"Thor";
				}
			}
			if (timesback::filechoosen == "Dark")
			{
				timesback::thundermenu = (char*)"Thunder";
				timesback::backgroundfile = (char*)"frame_";
			}
			if (timesback::filechoosen == "Thunder")
			{
				timesback::thundermenu = (char*)"Thunder";
				timesback::backgroundfile = (char*)"Thunder";
			}
			if (timesback::filechoosen == "Darkside")
			{
				if (timesback::Darkside1)
				{
					timesback::thundermenu = (char*)"Darkside1-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside2)
				{
					timesback::thundermenu = (char*)"Darkside2-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside3)
				{
					timesback::thundermenu = (char*)"Darkside3-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside32)
				{
					timesback::thundermenu = (char*)"Darkside3-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside4)
				{
					timesback::thundermenu = (char*)"Darkside4-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside5)
				{
					timesback::thundermenu = (char*)"Darkside5-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside6)
				{
					timesback::thundermenu = (char*)"Darkside6-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside7)
				{
					timesback::thundermenu = (char*)"Darkside7-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside8)
				{
					timesback::thundermenu = (char*)"Darkside8-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside82)
				{
					timesback::thundermenu = (char*)"Darkside8-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside9)
				{
					timesback::thundermenu = (char*)"Darkside9-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside10)
				{
					timesback::thundermenu = (char*)"Darkside10-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside11)
				{
					timesback::thundermenu = (char*)"Darkside11-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside13)
				{
					timesback::thundermenu = (char*)"Darkside13-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside14)
				{
					timesback::thundermenu = (char*)"Darkside14-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside142)
				{
					timesback::thundermenu = (char*)"Darkside14-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside15)
				{
					timesback::thundermenu = (char*)"Darkside15-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside16)
				{
					timesback::thundermenu = (char*)"Darkside16-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside17)
				{
					timesback::thundermenu = (char*)"Darkside17-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside18)
				{
					timesback::thundermenu = (char*)"Darkside18-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside19)
				{
					timesback::thundermenu = (char*)"Darkside19-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside20)
				{
					timesback::thundermenu = (char*)"Darkside20-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside21)
				{
					timesback::thundermenu = (char*)"Darkside21-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside22)
				{
					timesback::thundermenu = (char*)"Darkside22-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
				if (timesback::Darkside12)
				{
					timesback::thundermenu = (char*)"Darkside12-GTA5";
					timesback::backgroundfile = (char*)"Darkside";
				}
			}
			if (timesback::filechoosen == "Space")
			{
				timesback::thundermenu = (char*)"Thunder";
				timesback::backgroundfile = (char*)"Space_";
			}
			if (timesback::filechoosen == "Blackhole")
			{
				if (timesback::blackhole1)
				{
					timesback::thundermenu = (char*)"Blackhole1";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole2)
				{
					timesback::thundermenu = (char*)"Blackhole2";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole3)
				{
					timesback::thundermenu = (char*)"Blackhole3";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole4)
				{
					timesback::thundermenu = (char*)"Blackhole4";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole5)
				{
					timesback::thundermenu = (char*)"Blackhole5";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole6)
				{
					timesback::thundermenu = (char*)"Blackhole6";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole7)
				{
					timesback::thundermenu = (char*)"Blackhole7";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole8)
				{
					timesback::thundermenu = (char*)"Blackhole8";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole9)
				{
					timesback::thundermenu = (char*)"Blackhole9";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole10)
				{
					timesback::thundermenu = (char*)"Blackhole10";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole11)
				{
					timesback::thundermenu = (char*)"Blackhole11";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole12)
				{
					timesback::thundermenu = (char*)"Blackhole12";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole13)
				{
					timesback::thundermenu = (char*)"Blackhole13";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole14)
				{
					timesback::thundermenu = (char*)"Blackhole14";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole15)
				{
					timesback::thundermenu = (char*)"Blackhole15";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole16)
				{
					timesback::thundermenu = (char*)"Blackhole16";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole17)
				{
					timesback::thundermenu = (char*)"Blackhole17";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole18)
				{
					timesback::thundermenu = (char*)"Blackhole18";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole19)
				{
					timesback::thundermenu = (char*)"Blackhole19";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole20)
				{
					timesback::thundermenu = (char*)"Blackhole20";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole21)
				{
					timesback::thundermenu = (char*)"Blackhole21";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole22)
				{
					timesback::thundermenu = (char*)"Blackhole22";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole23)
				{
					timesback::thundermenu = (char*)"Blackhole23";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				}
			if (timesback::filechoosen == "Blackhole2")
				{
				if (blackhole232)
				{
					timesback::thundermenu = (char*)"Blackhole23";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole24)
				{
					timesback::thundermenu = (char*)"Blackhole24";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole25)
				{
					timesback::thundermenu = (char*)"Blackhole25";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole26)
				{
					timesback::thundermenu = (char*)"Blackhole26";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole27)
				{
					timesback::thundermenu = (char*)"Blackhole27";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole272)
				{
					timesback::thundermenu = (char*)"Blackhole272";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole28)
				{
					timesback::thundermenu = (char*)"Blackhole28";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole29)
				{
					timesback::thundermenu = (char*)"Blackhole29";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole30)
				{
					timesback::thundermenu = (char*)"Blackhole30";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole31)
				{
					timesback::thundermenu = (char*)"Blackhole31";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole32)
				{
					timesback::thundermenu = (char*)"Blackhole32";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole33)
				{
					timesback::thundermenu = (char*)"Blackhole33";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole333)
				{
					timesback::thundermenu = (char*)"Blackhole333";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole34)
				{
					timesback::thundermenu = (char*)"Blackhole34";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole342)
				{
					timesback::thundermenu = (char*)"Blackhole333";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole35)
				{
					timesback::thundermenu = (char*)"Blackhole35";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole36)
				{
					timesback::thundermenu = (char*)"Blackhole36";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole37)
				{
					timesback::thundermenu = (char*)"Blackhole37";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole38)
				{
					timesback::thundermenu = (char*)"Blackhole38";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole39)
				{
					timesback::thundermenu = (char*)"Blackhole39";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				}
			if (timesback::filechoosen == "Blackhole1")
			{
				if (blackhole392)
				{
					timesback::thundermenu = (char*)"Blackhole39";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}

				if (blackhole40)
				{
					timesback::thundermenu = (char*)"Blackhole40";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole41)
				{
					timesback::thundermenu = (char*)"Blackhole41";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole42)
				{
					timesback::thundermenu = (char*)"Blackhole42";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole43)
				{
					timesback::thundermenu = (char*)"Blackhole43";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole44)
				{
					timesback::thundermenu = (char*)"Blackhole44";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole45)
				{
					timesback::thundermenu = (char*)"Blackhole45";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole46)
				{
					timesback::thundermenu = (char*)"Blackhole46";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole47)
				{
					timesback::thundermenu = (char*)"Blackhole47";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole48)
				{
					timesback::thundermenu = (char*)"Blackhole48";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole49)
				{
					timesback::thundermenu = (char*)"Blackhole49";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole50)
				{
					timesback::thundermenu = (char*)"Blackhole50";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole51)
				{
					timesback::thundermenu = (char*)"Blackhole51";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole52)
				{
					timesback::thundermenu = (char*)"Blackhole52";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole53)
				{
					timesback::thundermenu = (char*)"Blackhole53";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole54)
				{
					timesback::thundermenu = (char*)"Blackhole54";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole55)
				{
					timesback::thundermenu = (char*)"Blackhole55";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole56)
				{
					timesback::thundermenu = (char*)"Blackhole56";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole57)
				{
					timesback::thundermenu = (char*)"Blackhole57";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole58)
				{
					timesback::thundermenu = (char*)"Blackhole58";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole59)
				{
					timesback::thundermenu = (char*)"Blackhole59";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole60)
				{
					timesback::thundermenu = (char*)"Blackhole60";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole61)
				{
					timesback::thundermenu = (char*)"Blackhole61";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole62)
				{
					timesback::thundermenu = (char*)"Blackhole62";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				}
			if (timesback::filechoosen == "Blackhole3")
				{
				if (blackhole63)
				{
					timesback::thundermenu = (char*)"Blackhole63";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole64)
				{
					timesback::thundermenu = (char*)"Blackhole64";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole65)
				{
					timesback::thundermenu = (char*)"Blackhole65";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole66)
				{
					timesback::thundermenu = (char*)"Blackhole66";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole67)
				{
					timesback::thundermenu = (char*)"Blackhole67";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole68)
				{
					timesback::thundermenu = (char*)"Blackhole68";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole69)
				{
					timesback::thundermenu = (char*)"Blackhole69";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole70)
				{
					timesback::thundermenu = (char*)"Blackhole70";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole71)
				{
					timesback::thundermenu = (char*)"Blackhole71";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole72)
				{
					timesback::thundermenu = (char*)"Blackhole72";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole73)
				{
					timesback::thundermenu = (char*)"Blackhole73";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole74)
				{
					timesback::thundermenu = (char*)"Blackhole74";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole75)
				{
					timesback::thundermenu = (char*)"Blackhole75";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
				if (blackhole76)
				{
					timesback::thundermenu = (char*)"Blackhole76";
					timesback::backgroundfile = (char*)"Blackhole"; //namepicture
				}
			}
			if (Menu2::Darkside)
			{
				std::string thundermenu2 = std::to_string(timesback::id) + timesback::backgroundfile;
				headers::Background = thundermenu;
				headers::Background2 = thundermenu2;
			}
			else
			if (!Menu2::Darkside)
				{
					std::string thundermenu2 = timesback::backgroundfile + std::to_string(timesback::id);
					headers::Background = thundermenu;
					headers::Background2 = thundermenu2;
				}
			Menu::Drawing::Spriter2((char*)headers::Background.c_str(), (char*)headers::Background2.c_str(), Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
			droptimer::backbool = false;
		}
		else
			if (timesback::id = timesback::lastpicid)
			{
				if (timesback::filechoosen == "Blackhole")
				{
					if (timesback::id == 10348)
					{
						if (boolactive::blackhole1)
						{
							Menu::Loading::registerswitch(Blackhole1);
							boolactive::blackhole1 = 0;
						}
						timesback::id = 8597;
						timesback::lastpicid = 8673;
						timesback::thundermenu = (char*)"Blackhole1";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 1;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 8673)
					{
						if (boolactive::blackhole2)
						{
							Menu::Loading::registerswitch(Blackhole2);
							boolactive::blackhole2 = 0;
						}
						timesback::id = 8674;
						timesback::lastpicid = 8750;
						timesback::thundermenu = (char*)"Blackhole2";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 1;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 8750)
					{
						if (boolactive::blackhole3)
						{
							Menu::Loading::registerswitch(Blackhole3);
							boolactive::blackhole3 = 0;
						}
						timesback::id = 8751;
						timesback::lastpicid = 8827;
						timesback::thundermenu = (char*)"Blackhole3";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 1;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 8827)
					{
						if (boolactive::blackhole4)
						{
							Menu::Loading::registerswitch(Blackhole4);
							boolactive::blackhole4 = 0;
						}
						timesback::id = 8828;
						timesback::lastpicid = 8904;
						timesback::thundermenu = (char*)"Blackhole4";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 1;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 8904)
					{
						if (boolactive::blackhole5)
						{
							Menu::Loading::registerswitch(Blackhole5);
							boolactive::blackhole5 = 0;
						}
						timesback::id = 8905;
						timesback::lastpicid = 8981;
						timesback::thundermenu = (char*)"Blackhole5";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 1;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 8981)
					{
						if (boolactive::blackhole6)
						{
							Menu::Loading::registerswitch(Blackhole6);
							boolactive::blackhole6 = 0;
						}
						timesback::id = 8982;
						timesback::lastpicid = 9058;
						timesback::thundermenu = (char*)"Blackhole6";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 1;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9058)
					{
						if (boolactive::blackhole7)
						{
							Menu::Loading::registerswitch(Blackhole7);
							boolactive::blackhole7 = 0;
						}
						timesback::id = 9059;
						timesback::lastpicid = 9135;
						timesback::thundermenu = (char*)"Blackhole7";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 1;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9135)
					{
						if (boolactive::blackhole8)
						{
							Menu::Loading::registerswitch(Blackhole8);
							boolactive::blackhole8 = 0;
						}
						timesback::id = 9136;
						timesback::lastpicid = 9212;
						timesback::thundermenu = (char*)"Blackhole8";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 1;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9212)
					{
						if (boolactive::blackhole9)
						{
							Menu::Loading::registerswitch(Blackhole9);
							boolactive::blackhole9 = 0;
						}
						timesback::id = 9213;
						timesback::lastpicid = 9289;
						timesback::thundermenu = (char*)"Blackhole9";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 1;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9289)
					{
						if (boolactive::blackhole10)
						{
							Menu::Loading::registerswitch(Blackhole10);
							boolactive::blackhole10 = 0;
						}
						timesback::id = 9290;
						timesback::lastpicid = 9366;
						timesback::thundermenu = (char*)"Blackhole10";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 1;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9366)
					{
						if (boolactive::blackhole11)
						{
							Menu::Loading::registerswitch(Blackhole11);
							boolactive::blackhole11 = 0;
						}
						timesback::id = 9367;
						timesback::lastpicid = 9443;
						timesback::thundermenu = (char*)"Blackhole11";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 1;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9443)
					{
						if (boolactive::blackhole12)
						{
							Menu::Loading::registerswitch(Blackhole12);
							boolactive::blackhole12 = 0;
						}
						timesback::id = 9444;
						timesback::lastpicid = 9520;
						timesback::thundermenu = (char*)"Blackhole12";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 1;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9520)
					{
						if (boolactive::blackhole13)
						{
							Menu::Loading::registerswitch(Blackhole13);
							boolactive::blackhole13 = 0;
						}
						timesback::id = 9521;
						timesback::lastpicid = 9597;
						timesback::thundermenu = (char*)"Blackhole13";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 1;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9597)
					{
						if (boolactive::blackhole14)
						{
							Menu::Loading::registerswitch(Blackhole14);
							boolactive::blackhole14 = 0;
						}
						timesback::id = 9598;
						timesback::lastpicid = 9674;
						timesback::thundermenu = (char*)"Blackhole14";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 1;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9674)
					{
						if (boolactive::blackhole15)
						{
							Menu::Loading::registerswitch(Blackhole15);
							boolactive::blackhole15 = 0;
						}
						timesback::id = 9675;
						timesback::lastpicid = 9751;
						timesback::thundermenu = (char*)"Blackhole15";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 1;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9751)
					{
						if (boolactive::blackhole16)
						{
							Menu::Loading::registerswitch(Blackhole16);
							boolactive::blackhole16 = 0;
						}
						timesback::id = 9752;
						timesback::lastpicid = 9828;
						timesback::thundermenu = (char*)"Blackhole16";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 1;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9828)
					{
						if (boolactive::blackhole17)
						{
							Menu::Loading::registerswitch(Blackhole17);
							boolactive::blackhole17 = 0;
						}
						timesback::id = 9829;
						timesback::lastpicid = 9905;
						timesback::thundermenu = (char*)"Blackhole17";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 1;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9905)
					{
						if (boolactive::blackhole18)
						{
							Menu::Loading::registerswitch(Blackhole18);
							boolactive::blackhole18 = 0;
						}
						timesback::id = 9906;
						timesback::lastpicid = 9982;
						timesback::thundermenu = (char*)"Blackhole18";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 1;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 9982)
					{
						if (boolactive::blackhole19)
						{
							Menu::Loading::registerswitch(Blackhole19);
							boolactive::blackhole19 = 0;
						}
						timesback::id = 9983;
						timesback::lastpicid = 10058;
						timesback::thundermenu = (char*)"Blackhole19";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 1;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10058)
					{
						if (boolactive::blackhole20)
						{
							Menu::Loading::registerswitch(Blackhole20);
							boolactive::blackhole20 = 0;
						}
						timesback::id = 10060;
						timesback::lastpicid = 10136;
						timesback::thundermenu = (char*)"Blackhole20";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 1;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10136)
					{
						if (boolactive::blackhole21)
						{
							Menu::Loading::registerswitch(Blackhole21);
							boolactive::blackhole21 = 0;
						}
						timesback::id = 10137;
						timesback::lastpicid = 10213;
						timesback::thundermenu = (char*)"Blackhole21";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 1;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10213)
					{
						if (boolactive::blackhole22)
						{
							Menu::Loading::registerswitch(Blackhole22);
							boolactive::blackhole22 = 0;
						}
						timesback::id = 10214;
						timesback::lastpicid = 10290;
						timesback::thundermenu = (char*)"Blackhole22";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 1;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10290)
					{
						if (boolactive::blackhole23)
						{
							Menu::Loading::registerswitch(Blackhole23);
							boolactive::blackhole23 = 0;
						}
						timesback::id = 10291;
						timesback::lastpicid = 10348;
						timesback::thundermenu = (char*)"Blackhole23";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 1;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					}
				if (timesback::filechoosen == "Blackhole2")
					{
						if (timesback::id == 13408)
						{
							if (boolactive::blackhole23)
							{
								Menu::Loading::registerswitch(Blackhole23);
								boolactive::blackhole23 = 0;
							}
							timesback::id = 10349;
							timesback::lastpicid = 10367;
							timesback::thundermenu = (char*)"Blackhole23";
							timesback::backgroundfile = (char*)"Blackhole";
							blackhole1 = 0;
							blackhole2 = 0;
							blackhole3 = 0;
							blackhole4 = 0;
							blackhole5 = 0;
							blackhole6 = 0;
							blackhole7 = 0;
							blackhole8 = 0;
							blackhole9 = 0;
							blackhole10 = 0;
							blackhole11 = 0;
							blackhole12 = 0;
							blackhole13 = 0;
							blackhole14 = 0;
							blackhole15 = 0;
							blackhole16 = 0;
							blackhole17 = 0;
							blackhole18 = 0;
							blackhole19 = 0;
							blackhole20 = 0;
							blackhole21 = 0;
							blackhole22 = 0;
							blackhole23 = 0;
							blackhole232 = 1;
							blackhole24 = 0;
							blackhole25 = 0;
							blackhole26 = 0;
							blackhole27 = 0;
							blackhole272 = 0;
							blackhole28 = 0;
							blackhole29 = 0;
							blackhole30 = 0;
							blackhole31 = 0;
							blackhole32 = 0;
							blackhole33 = 0;
							blackhole333 = 0;
							blackhole34 = 0;
							blackhole35 = 0;
							blackhole352 = 0;
							blackhole36 = 0;
							blackhole37 = 0;
							blackhole38 = 0;
							blackhole39 = 0;
							blackhole392 = 0;
							blackhole40 = 0;
							blackhole41 = 0;
							blackhole42 = 0;
							blackhole43 = 0;
							blackhole44 = 0;
							blackhole45 = 0;
							blackhole46 = 0;
							blackhole47 = 0;
							blackhole48 = 0;
							blackhole49 = 0;
							blackhole50 = 0;
							blackhole502 = 0;
							blackhole51 = 0;
							blackhole52 = 0;
							blackhole53 = 0;
							blackhole54 = 0;
							blackhole55 = 0;
							blackhole552 = 0;
							blackhole56 = 0;
							blackhole57 = 0;
							blackhole58 = 0;
							blackhole59 = 0;
							blackhole60 = 0;
							blackhole61 = 0;
							blackhole62 = 0;
							blackhole622 = 0;
							blackhole63 = 0;
							blackhole64 = 0;
							blackhole65 = 0;
							blackhole66 = 0;
							blackhole67 = 0;
							blackhole68 = 0;
							blackhole69 = 0;
							blackhole70 = 0;
							blackhole71 = 0;
							blackhole72 = 0;
							blackhole73 = 0;
							blackhole74 = 0;
							blackhole75 = 0;
							blackhole76 = 0;
						}
					if (timesback::id == 10367)
					{
						if (boolactive::blackhole24)
						{
							Menu::Loading::registerswitch(Blackhole24);
							boolactive::blackhole24 = 0;
						}
						timesback::id = 10368;
						timesback::lastpicid = 10444;
						timesback::thundermenu = (char*)"Blackhole24";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole232 = 0;
						blackhole24 = 1;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10444)
					{
						if (boolactive::blackhole25)
						{
							Menu::Loading::registerswitch(Blackhole25);
							boolactive::blackhole25 = 0;
						}
						timesback::id = 10445;
						timesback::lastpicid = 10521;
						timesback::thundermenu = (char*)"Blackhole25";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole232 = 0;
						blackhole24 = 0;
						blackhole25 = 1;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10521)
					{
						if (boolactive::blackhole26)
						{
							Menu::Loading::registerswitch(Blackhole26);
							boolactive::blackhole26 = 0;
						}
						timesback::id = 10522;
						timesback::lastpicid = 10598;
						timesback::thundermenu = (char*)"Blackhole26";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole232 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 1;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10598)
					{
						if (boolactive::blackhole27)
						{
							Menu::Loading::registerswitch(Blackhole27);
							boolactive::blackhole27 = 0;
						}
						timesback::id = 10599;
						timesback::lastpicid = 10653;
						timesback::thundermenu = (char*)"Blackhole27";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole232 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 1;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10653)
					{
						if (boolactive::blackhole272)
						{
							Menu::Loading::registerswitch(Blackhole272);
							boolactive::blackhole272 = 0;
						}
						timesback::id = 10654;
						timesback::lastpicid = 10702;
						timesback::thundermenu = (char*)"Blackhole272";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole232 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 1;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10702)
					{
						if (boolactive::blackhole28)
						{
							Menu::Loading::registerswitch(Blackhole28);
							boolactive::blackhole28 = 0;
						}
						timesback::id = 10703;
						timesback::lastpicid = 10764;
						timesback::thundermenu = (char*)"Blackhole28";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole232 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 1;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10764)
					{
						if (boolactive::blackhole29)
						{
							Menu::Loading::registerswitch(Blackhole29);
							boolactive::blackhole29 = 0;
						}
						timesback::id = 10765;
						timesback::lastpicid = 10829;
						timesback::thundermenu = (char*)"Blackhole29";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole232 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 1;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10829)
					{
						if (boolactive::blackhole30)
						{
							Menu::Loading::registerswitch(Blackhole30);
							boolactive::blackhole30 = 0;
						}
						timesback::id = 10830;
						timesback::lastpicid = 10906;
						timesback::thundermenu = (char*)"Blackhole30";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 1;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10906)
					{
						if (boolactive::blackhole31)
						{
							Menu::Loading::registerswitch(Blackhole31);
							boolactive::blackhole31 = 0;
						}
						timesback::id = 10907;
						timesback::lastpicid = 10983;
						timesback::thundermenu = (char*)"Blackhole31";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 1;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 10983)
					{
						if (boolactive::blackhole32)
						{
							Menu::Loading::registerswitch(Blackhole32);
							boolactive::blackhole32 = 0;
						}
						timesback::id = 10984;
						timesback::lastpicid = 11060;
						timesback::thundermenu = (char*)"Blackhole32";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 1;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 11060)
					{
						if (boolactive::blackhole33)
						{
							Menu::Loading::registerswitch(Blackhole33);
							boolactive::blackhole33 = 0;
						}
						timesback::id = 11061;
						timesback::lastpicid = 11115;
						timesback::thundermenu = (char*)"Blackhole33";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 1;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 11115)
					{
						if (boolactive::blackhole333)
						{
							Menu::Loading::registerswitch(Blackhole333);
							boolactive::blackhole333 = 0;
						}
						timesback::id = 11116;
						timesback::lastpicid = 11137;
						timesback::thundermenu = (char*)"Blackhole333";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 1;
						blackhole34 = 0;
						blackhole342 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 11137)
					{
						if (boolactive::blackhole34)
						{
							Menu::Loading::registerswitch(Blackhole34);
							boolactive::blackhole34 = 0;
						}
						timesback::id = 11138;
						timesback::lastpicid = 11194;
						timesback::thundermenu = (char*)"Blackhole34";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 1;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 11194)
					{
						timesback::id = 11195;
						timesback::lastpicid = 11214;
						timesback::thundermenu = (char*)"Blackhole333";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole342 = 1;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 11214)
					{
						if (boolactive::blackhole35)
						{
							Menu::Loading::registerswitch(Blackhole35);
							boolactive::blackhole35 = 0;
						}
						timesback::id = 11215;
						timesback::lastpicid = 11242;
						timesback::thundermenu = (char*)"Blackhole35";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole342 = 0;
						blackhole35 = 1;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 11242)
					{
						if (boolactive::blackhole352)
						{
							Menu::Loading::registerswitch(Blackhole35);
							boolactive::blackhole352 = 0;
						}
						timesback::id = 13071;
						timesback::lastpicid = 13119;
						timesback::thundermenu = (char*)"Blackhole35";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole342 = 0;
						blackhole35 = 0;
						blackhole352 = 1;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 13119)
					{
						if (boolactive::blackhole36)
						{
							Menu::Loading::registerswitch(Blackhole36);
							boolactive::blackhole36 = 0;
						}
						timesback::id = 13120;
						timesback::lastpicid = 13196;
						timesback::thundermenu = (char*)"Blackhole36";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 1;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 13196)
					{
						if (boolactive::blackhole37)
						{
							Menu::Loading::registerswitch(Blackhole37);
							boolactive::blackhole37 = 0;
						}
						timesback::id = 13197;
						timesback::lastpicid = 13273;
						timesback::thundermenu = (char*)"Blackhole37";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 1;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 13273)
					{
						if (boolactive::blackhole38)
						{
							Menu::Loading::registerswitch(Blackhole38);
							boolactive::blackhole38 = 0;
						}
						timesback::id = 13274;
						timesback::lastpicid = 13350;
						timesback::thundermenu = (char*)"Blackhole38";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 1;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 13350)
					{
						if (boolactive::blackhole39)
						{
							Menu::Loading::registerswitch(Blackhole39);
							boolactive::blackhole39 = 0;
						}
						timesback::id = 13351;
						timesback::lastpicid = 13408;
						timesback::thundermenu = (char*)"Blackhole39";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 1;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					}
				if (timesback::filechoosen == "Blackhole1")
					{
					if (timesback::id == 6429)
					{
						if (boolactive::blackhole392)
						{
							Menu::Loading::registerswitch(Blackhole39);
							boolactive::blackhole392 = 0;
						}
						timesback::id = 18497;
						timesback::lastpicid = 18515;
						timesback::thundermenu = (char*)"Blackhole39";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 1;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 18515)
					{
						if (boolactive::blackhole40)
						{
							Menu::Loading::registerswitch(Blackhole40);
							boolactive::blackhole40 = 0;
						}
						timesback::id = 18516;
						timesback::lastpicid = 18592;
						timesback::thundermenu = (char*)"Blackhole40";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 1;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 18592)
					{
						if (boolactive::blackhole41)
						{
							Menu::Loading::registerswitch(Blackhole41);
							boolactive::blackhole41 = 0;
						}
						timesback::id = 18593;
						timesback::lastpicid = 18669;
						timesback::thundermenu = (char*)"Blackhole41";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 1;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 18669)
					{
						if (boolactive::blackhole42)
						{
							Menu::Loading::registerswitch(Blackhole42);
							boolactive::blackhole42 = 0;
						}
						timesback::id = 18670;
						timesback::lastpicid = 18746;
						timesback::thundermenu = (char*)"Blackhole42";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 1;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 18746)
					{
						if (boolactive::blackhole43)
						{
							Menu::Loading::registerswitch(Blackhole43);
							boolactive::blackhole43 = 0;
						}
						timesback::id = 18747;
						timesback::lastpicid = 18823;
						timesback::thundermenu = (char*)"Blackhole43";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 1;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 18823)
					{
						if (boolactive::blackhole44)
						{
							Menu::Loading::registerswitch(Blackhole44);
							boolactive::blackhole44 = 0;
						}
						timesback::id = 18824;
						timesback::lastpicid = 18900;
						timesback::thundermenu = (char*)"Blackhole44";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 1;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 18900)
					{
						if (boolactive::blackhole45)
						{
							Menu::Loading::registerswitch(Blackhole45);
							boolactive::blackhole45 = 0;
						}
						timesback::id = 18901;
						timesback::lastpicid = 18977;
						timesback::thundermenu = (char*)"Blackhole45";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 1;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 18977)
					{
						if (boolactive::blackhole46)
						{
							Menu::Loading::registerswitch(Blackhole46);
							boolactive::blackhole46 = 0;
						}
						timesback::id = 18978;
						timesback::lastpicid = 19054;
						timesback::thundermenu = (char*)"Blackhole46";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 1;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 19054)
					{
						if (boolactive::blackhole47)
						{
							Menu::Loading::registerswitch(Blackhole47);
							boolactive::blackhole47 = 0;
						}
						timesback::id = 19055;
						timesback::lastpicid = 19131;
						timesback::thundermenu = (char*)"Blackhole47";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 1;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 19131)
					{
						if (boolactive::blackhole48)
						{
							Menu::Loading::registerswitch(Blackhole48);
							boolactive::blackhole48 = 0;
						}
						timesback::id = 19132;
						timesback::lastpicid = 19208;
						timesback::thundermenu = (char*)"Blackhole48";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 1;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 19208)
					{
						if (boolactive::blackhole49)
						{
							Menu::Loading::registerswitch(Blackhole49);
							boolactive::blackhole49 = 0;
						}
						timesback::id = 19209;
						timesback::lastpicid = 19285;
						timesback::thundermenu = (char*)"Blackhole49";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 1;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 19285)
					{
						if (boolactive::blackhole50)
						{
							Menu::Loading::registerswitch(Blackhole50);
							boolactive::blackhole50 = 0;
						}
						timesback::id = 19286;
						timesback::lastpicid = 19346;
						timesback::thundermenu = (char*)"Blackhole50";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 1;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 19346)
					{
						if (boolactive::blackhole502)
						{
							Menu::Loading::registerswitch(Blackhole50);
							boolactive::blackhole502 = 0;
						}
						timesback::id = 20191;
						timesback::lastpicid = 20206;
						timesback::thundermenu = (char*)"Blackhole50";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 1;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 20206)
					{
						if (boolactive::blackhole51)
						{
							Menu::Loading::registerswitch(Blackhole51);
							boolactive::blackhole51 = 0;
						}
						timesback::id = 20207;
						timesback::lastpicid = 20283;
						timesback::thundermenu = (char*)"Blackhole51";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 1;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 20283)
					{
						if (boolactive::blackhole52)
						{
							Menu::Loading::registerswitch(Blackhole52);
							boolactive::blackhole52 = 0;
						}
						timesback::id = 20284;
						timesback::lastpicid = 20360;
						timesback::thundermenu = (char*)"Blackhole52";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 1;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 20360)
					{
						if (boolactive::blackhole53)
						{
							Menu::Loading::registerswitch(Blackhole53);
							boolactive::blackhole53 = 0;
						}
						timesback::id = 20361;
						timesback::lastpicid = 20437;
						timesback::thundermenu = (char*)"Blackhole53";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 1;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 20437)
					{
						if (boolactive::blackhole54)
						{
							Menu::Loading::registerswitch(Blackhole54);
							boolactive::blackhole54 = 0;
						}
						timesback::id = 20438;
						timesback::lastpicid = 20514;
						timesback::thundermenu = (char*)"Blackhole54";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 1;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 20514)
					{
						if (boolactive::blackhole55)
						{
							Menu::Loading::registerswitch(Blackhole55);
							boolactive::blackhole55 = 0;
						}
						timesback::id = 20515;
						timesback::lastpicid = 20554;
						timesback::thundermenu = (char*)"Blackhole55";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 1;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 20554)
					{
						if (boolactive::blackhole552)
						{
							Menu::Loading::registerswitch(Blackhole55);
							boolactive::blackhole552 = 0;
						}
						timesback::id = 22061;
						timesback::lastpicid = 22097;
						timesback::thundermenu = (char*)"Blackhole55";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 1;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22097)
					{
						if (boolactive::blackhole56)
						{
							Menu::Loading::registerswitch(Blackhole56);
							boolactive::blackhole56 = 0;
						}
						timesback::id = 22098;
						timesback::lastpicid = 22174;
						timesback::thundermenu = (char*)"Blackhole56";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 1;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22174)
					{
						if (boolactive::blackhole57)
						{
							Menu::Loading::registerswitch(Blackhole57);
							boolactive::blackhole57 = 0;
						}
						timesback::id = 22175;
						timesback::lastpicid = 22251;
						timesback::thundermenu = (char*)"Blackhole57";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 1;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22251)
					{
						if (boolactive::blackhole58)
						{
							Menu::Loading::registerswitch(Blackhole58);
							boolactive::blackhole58 = 0;
						}
						timesback::id = 22252;
						timesback::lastpicid = 22328;
						timesback::thundermenu = (char*)"Blackhole58";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 1;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22328)
					{
						if (boolactive::blackhole59)
						{
							Menu::Loading::registerswitch(Blackhole59);
							boolactive::blackhole59 = 0;
						}
						timesback::id = 22329;
						timesback::lastpicid = 22405;
						timesback::thundermenu = (char*)"Blackhole59";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 1;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22405)
					{
						if (boolactive::blackhole60)
						{
							Menu::Loading::registerswitch(Blackhole60);
							boolactive::blackhole60 = 0;
						}
						timesback::id = 22406;
						timesback::lastpicid = 22482;
						timesback::thundermenu = (char*)"Blackhole60";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 1;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22482)
					{
						if (boolactive::blackhole61)
						{
							Menu::Loading::registerswitch(Blackhole61);
							boolactive::blackhole61 = 0;
						}
						timesback::id = 22483;
						timesback::lastpicid = 22559;
						timesback::thundermenu = (char*)"Blackhole61";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 1;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22559)
					{
						if (boolactive::blackhole62)
						{
							Menu::Loading::registerswitch(Blackhole62);
							boolactive::blackhole62 = 0;
						}
						timesback::id = 22560;
						timesback::lastpicid = 22584;
						timesback::thundermenu = (char*)"Blackhole62";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 1;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 22584)
					{
						if (boolactive::blackhole622)
						{
							Menu::Loading::registerswitch(Blackhole62);
							boolactive::blackhole622 = 0;
						}
						timesback::id = 6403;
						timesback::lastpicid = 6429;
						timesback::thundermenu = (char*)"Blackhole62";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 1;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					}
					if (timesback::filechoosen == "Blackhole3")
					{
					if (timesback::id == 7564)
					{
						if (boolactive::blackhole63)
						{
							Menu::Loading::registerswitch(Blackhole63);
							boolactive::blackhole63 = 0;
						}
						timesback::id = 6430;
						timesback::lastpicid = 6506;
						timesback::thundermenu = (char*)"Blackhole63";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						timesback::blackhole63 = 1;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 6506)
					{
						if (boolactive::blackhole64)
						{
							Menu::Loading::registerswitch(Blackhole64);
							boolactive::blackhole64 = 0;
						}
						timesback::id = 6507;
						timesback::lastpicid = 6583;
						timesback::thundermenu = (char*)"Blackhole64";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 1;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 6583)
					{
						if (boolactive::blackhole65)
						{
							Menu::Loading::registerswitch(Blackhole65);
							boolactive::blackhole65 = 0;
						}
						timesback::id = 6584;
						timesback::lastpicid = 6660;
						timesback::thundermenu = (char*)"Blackhole65";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 1;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 6660)
					{
						if (boolactive::blackhole66)
						{
							Menu::Loading::registerswitch(Blackhole66);
							boolactive::blackhole66 = 0;
						}
						timesback::id = 6661;
						timesback::lastpicid = 6737;
						timesback::thundermenu = (char*)"Blackhole66";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 1;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 6737)
					{
						if (boolactive::blackhole67)
						{
							Menu::Loading::registerswitch(Blackhole67);
							boolactive::blackhole67 = 0;
						}
						timesback::id = 6738;
						timesback::lastpicid = 6814;
						timesback::thundermenu = (char*)"Blackhole67";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 1;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 6814)
					{
						if (boolactive::blackhole68)
						{
							Menu::Loading::registerswitch(Blackhole68);
							boolactive::blackhole68 = 0;
						}
						timesback::id = 6815;
						timesback::lastpicid = 6968;
						timesback::thundermenu = (char*)"Blackhole68";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 1;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 6968)
					{
						if (boolactive::blackhole69)
						{
							Menu::Loading::registerswitch(Blackhole69);
							boolactive::blackhole69 = 0;
						}
						timesback::id = 6969;
						timesback::lastpicid = 7045;
						timesback::thundermenu = (char*)"Blackhole69";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 1;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 7045)
					{
						if (boolactive::blackhole70)
						{
							Menu::Loading::registerswitch(Blackhole70);
							boolactive::blackhole70 = 0;
						}
						timesback::id = 7046;
						timesback::lastpicid = 7122;
						timesback::thundermenu = (char*)"Blackhole70";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 1;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 7122)
					{
						if (boolactive::blackhole71)
						{
							Menu::Loading::registerswitch(Blackhole71);
							boolactive::blackhole71 = 0;
						}
						timesback::id = 7123;
						timesback::lastpicid = 7199;
						timesback::thundermenu = (char*)"Blackhole71";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 1;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 7199)
					{
						if (boolactive::blackhole72)
						{
							Menu::Loading::registerswitch(Blackhole72);
							boolactive::blackhole72 = 0;
						}
						timesback::id = 7200;
						timesback::lastpicid = 7276;
						timesback::thundermenu = (char*)"Blackhole72";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 1;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 7276)
					{
						if (boolactive::blackhole73)
						{
							Menu::Loading::registerswitch(Blackhole73);
							boolactive::blackhole73 = 0;
						}
						timesback::id = 7277;
						timesback::lastpicid = 7353;
						timesback::thundermenu = (char*)"Blackhole73";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 1;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 7353)
					{
						if (boolactive::blackhole74)
						{
							Menu::Loading::registerswitch(Blackhole74);
							boolactive::blackhole74 = 0;
						}
						timesback::id = 7354;
						timesback::lastpicid = 7430;
						timesback::thundermenu = (char*)"Blackhole74";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 1;
						blackhole75 = 0;
						blackhole76 = 0;
					}
					if (timesback::id == 7430)
					{
						if (boolactive::blackhole75)
						{
							Menu::Loading::registerswitch(Blackhole75);
							boolactive::blackhole75 = 0;
						}
						timesback::id = 7431;
						timesback::lastpicid = 7507;
						timesback::thundermenu = (char*)"Blackhole75";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 1;
						blackhole76 = 0;
					}
					if (timesback::id == 7507)
					{
						if (boolactive::blackhole76)
						{
							Menu::Loading::registerswitch(Blackhole76);
							boolactive::blackhole76 = 0;
						}
						timesback::id = 7508;
						timesback::lastpicid = 7564;
						timesback::thundermenu = (char*)"Blackhole76";
						timesback::backgroundfile = (char*)"Blackhole";
						blackhole1 = 0;
						blackhole2 = 0;
						blackhole3 = 0;
						blackhole4 = 0;
						blackhole5 = 0;
						blackhole6 = 0;
						blackhole7 = 0;
						blackhole8 = 0;
						blackhole9 = 0;
						blackhole10 = 0;
						blackhole11 = 0;
						blackhole12 = 0;
						blackhole13 = 0;
						blackhole14 = 0;
						blackhole15 = 0;
						blackhole16 = 0;
						blackhole17 = 0;
						blackhole18 = 0;
						blackhole19 = 0;
						blackhole20 = 0;
						blackhole21 = 0;
						blackhole22 = 0;
						blackhole23 = 0;
						blackhole24 = 0;
						blackhole25 = 0;
						blackhole26 = 0;
						blackhole27 = 0;
						blackhole272 = 0;
						blackhole28 = 0;
						blackhole29 = 0;
						blackhole30 = 0;
						blackhole31 = 0;
						blackhole32 = 0;
						blackhole33 = 0;
						blackhole333 = 0;
						blackhole34 = 0;
						blackhole35 = 0;
						blackhole352 = 0;
						blackhole36 = 0;
						blackhole37 = 0;
						blackhole38 = 0;
						blackhole39 = 0;
						blackhole392 = 0;
						blackhole40 = 0;
						blackhole41 = 0;
						blackhole42 = 0;
						blackhole43 = 0;
						blackhole44 = 0;
						blackhole45 = 0;
						blackhole46 = 0;
						blackhole47 = 0;
						blackhole48 = 0;
						blackhole49 = 0;
						blackhole50 = 0;
						blackhole502 = 0;
						blackhole51 = 0;
						blackhole52 = 0;
						blackhole53 = 0;
						blackhole54 = 0;
						blackhole55 = 0;
						blackhole552 = 0;
						blackhole56 = 0;
						blackhole57 = 0;
						blackhole58 = 0;
						blackhole59 = 0;
						blackhole60 = 0;
						blackhole61 = 0;
						blackhole62 = 0;
						blackhole622 = 0;
						blackhole63 = 0;
						blackhole64 = 0;
						blackhole65 = 0;
						blackhole66 = 0;
						blackhole67 = 0;
						blackhole68 = 0;
						blackhole69 = 0;
						blackhole70 = 0;
						blackhole71 = 0;
						blackhole72 = 0;
						blackhole73 = 0;
						blackhole74 = 0;
						blackhole75 = 0;
						blackhole76 = 1;
					}
				}
				if (timesback::filechoosen == "Thor")
				{
					if (timesback::id == 6141)
					{
						if (boolactive::activebool21)
						{
							Menu::Loading::registerswitch(Thor21);
							boolactive::activebool21 = 0;
						}
						timesback::id = 717;
						timesback::lastpicid = 793;
						timesback::thundermenu = (char*)"Thor21";
						timesback::backgroundfile = (char*)"Thor";
						boolThor1 = 0;
						boolThor5 = 0;
						boolThor6 = 0;
						boolThor21 = 1;
					}
					if (timesback::id == 793)
					{
						if (boolactive::activebool2)
						{
							Menu::Loading::registerswitch(Thor1);
							boolactive::activebool2 = 0;
						}
						timesback::id = 5934;
						timesback::lastpicid = 6021;
						timesback::thundermenu = (char*)"Thor1";
						timesback::backgroundfile = (char*)"Thor"; //namepicture
						boolThor21 = 0;
						boolThor5 = 0;
						boolThor6 = 0;
						boolThor1 = 1;
					}

					if (timesback::id == 6021)
					{
						if (boolactive::activebool3)
						{
							Menu::Loading::registerswitch(Thor22);
							boolactive::activebool3 = 0;
						}
						timesback::id = 6022;
						timesback::lastpicid = 6059;
						thundermenu = (char*)"Thor22";
						timesback::backgroundfile = (char*)"Thor";
						boolThor1 = 0;
						boolThor21 = 0;
						boolThor5 = 0;
						boolThor6 = 1;
					}
					if (timesback::id == 6059)
					{
						if (boolactive::activebool4)
						{
							Menu::Loading::registerswitch(Thor2);
							boolactive::activebool4 = 0;
						}
						timesback::id = 6060;
						timesback::lastpicid = 6141;
						timesback::thundermenu = (char*)"Thor2";
						timesback::backgroundfile = (char*)"Thor";
						boolThor1 = 0;
						boolThor21 = 0;
						boolThor6 = 0;
						boolThor5 = 1;
					}
				}
				if (timesback::filechoosen == "Thor2")
				{
					if (boolactive::activebool5)
					{
						Menu::Loading::registerswitch(Thor);
						boolactive::activebool5 = 0;
					}

					if (timesback::id == 7140)
					{
						timesback::id = 4999;
						timesback::lastpicid = 5086;
						timesback::thundermenu = (char*)"Thor";
						timesback::backgroundfile = (char*)"Thor";
						boolThor0 = 1;
						boolThor03 = 0;
						boolThor04 = 0;
						boolThor20 = 0;
						boolThor23 = 0;
						boolThor24 = 0;
					}

					if (timesback::id == 5086)
					{
						if (boolactive::activebool6)
						{
							Menu::Loading::registerswitch(Thor20);
							boolactive::activebool6 = 0;
						}
						timesback::id = 5087;
						timesback::lastpicid = 5124;
						timesback::thundermenu = (char*)"Thor20";
						timesback::backgroundfile = (char*)"Thor";
						boolThor0 = 0;
						boolThor03 = 0;
						boolThor04 = 0;
						boolThor20 = 1;
						boolThor23 = 0;
						boolThor24 = 0;
					}

					if (timesback::id == 5124)
					{
						if (boolactive::activebool7)
						{
							Menu::Loading::registerswitch(Thor3);
							boolactive::activebool7 = 0;
						}
						timesback::id = 6889;
						timesback::lastpicid = 6967;
						timesback::thundermenu = (char*)"Thor3";
						timesback::backgroundfile = (char*)"Thor";
						boolThor0 = 0;
						boolThor03 = 1;
						boolThor04 = 0;
						boolThor20 = 0;
						boolThor23 = 0;
						boolThor24 = 0;
					}

					if (timesback::id == 6967)
					{
						if (boolactive::activebool8)
						{
							Menu::Loading::registerswitch(Thor23);
							boolactive::activebool8 = 0;
						}
						timesback::id = 6968;
						timesback::lastpicid = 7014;
						timesback::thundermenu = (char*)"Thor23";
						timesback::backgroundfile = (char*)"Thor";
						boolThor0 = 0;
						boolThor03 = 0;
						boolThor04 = 0;
						boolThor20 = 0;
						boolThor23 = 1;
						boolThor24 = 0;
					}

					if (timesback::id == 7014)
					{
						if (boolactive::activebool9)
						{
							Menu::Loading::registerswitch(Thor4);
							boolactive::activebool9 = 0;
						}
						timesback::id = 7015;
						timesback::lastpicid = 7102;
						timesback::thundermenu = (char*)"Thor4";
						timesback::backgroundfile = (char*)"Thor";
						boolThor0 = 0;
						boolThor03 = 0;
						boolThor04 = 1;
						boolThor20 = 0;
						boolThor23 = 0;
					}

					if (timesback::id == 7102)
					{
						if (boolactive::activebool10)
						{
							Menu::Loading::registerswitch(Thor24);
							boolactive::activebool10 = 0;
						}
						timesback::id = 7103;
						timesback::lastpicid = 7140;
						timesback::thundermenu = (char*)"Thor24";
						timesback::backgroundfile = (char*)"Thor";
						boolThor0 = 0;
						boolThor03 = 0;
						boolThor04 = 0;
						boolThor20 = 0;
						boolThor23 = 0;
						boolThor24 = 1;
					}
				}
				if (timesback::filechoosen == "Dark")
				{
					timesback::id = 0;
					timesback::lastpicid = 88;
					timesback::thundermenu = (char*)"Thunder";
					timesback::backgroundfile = (char*)"frame_";
				}
				if (timesback::filechoosen == "Thunder")
				{
					timesback::id = 1;
					timesback::lastpicid = 18;
					timesback::thundermenu = (char*)"Thunder";
					timesback::backgroundfile = (char*)"Thunder";
				}
				if (timesback::filechoosen == "Darkside")
				{
					if (timesback::id == 4988)
					{
						if (boolactive::activebool1)
						{
							Menu::Loading::registerswitch(LDarkside1);
							boolactive::activebool1 = 0;
						}
						timesback::id = 1248;
						timesback::lastpicid = 1324;
						timesback::thundermenu = (char*)"Darkside1-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 1;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 1324)
					{
						if (boolactive::activebool2)
						{
							Menu::Loading::registerswitch(LDarkside2);
							boolactive::activebool2 = 0;
						}
						timesback::id = 1325;
						timesback::lastpicid = 1401;
						timesback::thundermenu = (char*)"Darkside2-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 1;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 1401)
					{
						if (boolactive::activebool3)
						{
							Menu::Loading::registerswitch(LDarkside3);
							boolactive::activebool3 = 0;
						}
						timesback::id = 1402;
						timesback::lastpicid = 1475;
						timesback::thundermenu = (char*)"Darkside3-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 1;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 1475)
					{
						timesback::id = 3053;
						timesback::lastpicid = 3055;
						timesback::thundermenu = (char*)"Darkside3-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 1;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3055)
					{
						if (boolactive::activebool4)
						{
							Menu::Loading::registerswitch(LDarkside4);
							boolactive::activebool4 = 0;
						}
						timesback::id = 3056;
						timesback::lastpicid = 3132;
						timesback::thundermenu = (char*)"Darkside4-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 1;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3132)
					{
						if (boolactive::activebool5)
						{
							Menu::Loading::registerswitch(LDarkside5);
							boolactive::activebool5 = 0;
						}
						timesback::id = 3133;
						timesback::lastpicid = 3209;
						timesback::thundermenu = (char*)"Darkside5-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 1;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3209)
					{
						if (boolactive::activebool6)
						{
							Menu::Loading::registerswitch(LDarkside6);
							boolactive::activebool6 = 0;
						}
						timesback::id = 3210;
						timesback::lastpicid = 3286;
						timesback::thundermenu = (char*)"Darkside6-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 1;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3286)
					{
						if (boolactive::activebool7)
						{
							Menu::Loading::registerswitch(LDarkside7);
							boolactive::activebool7 = 0;
						}
						timesback::id = 3287;
						timesback::lastpicid = 3363;
						timesback::thundermenu = (char*)"Darkside7-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 1;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3363)
					{
						if (boolactive::activebool8)
						{
							Menu::Loading::registerswitch(LDarkside8);
							boolactive::activebool8 = 0;
						}
						timesback::id = 3364;
						timesback::lastpicid = 3379;
						timesback::thundermenu = (char*)"Darkside8-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 1;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3379)
					{
						timesback::id = 3498;
						timesback::lastpicid = 3558;
						timesback::thundermenu = (char*)"Darkside8-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 1;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3558)
					{
						if (boolactive::activebool9)
						{
							Menu::Loading::registerswitch(LDarkside9);
							boolactive::activebool9 = 0;
						}
						timesback::id = 3559;
						timesback::lastpicid = 3635;
						timesback::thundermenu = (char*)"Darkside9-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 1;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3635)
					{
						if (boolactive::activebool10)
						{
							Menu::Loading::registerswitch(LDarkside10);
							boolactive::activebool10 = 0;
						}
						timesback::id = 3636;
						timesback::lastpicid = 3712;
						timesback::thundermenu = (char*)"Darkside10-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 1;
						Darkside11 = 0;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3712)
					{
						if (boolactive::activebool11)
						{
							Menu::Loading::registerswitch(LDarkside11);
							boolactive::activebool11 = 0;
						}
						timesback::id = 3713;
						timesback::lastpicid = 3789;
						timesback::thundermenu = (char*)"Darkside11-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 1;
						Darkside12 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 3789)
					{
						if (boolactive::activebool22)
						{
							Menu::Loading::registerswitch(LDarkside22);
							boolactive::activebool22 = 0;
						}
						timesback::id = 3790;
						timesback::lastpicid = 3834;
						timesback::thundermenu = (char*)"Darkside22-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside12 = 0;
						Darkside11 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
						Darkside22 = 1;
					}
					if (timesback::id == 3834)
					{
						if (boolactive::activebool12)
						{
							Menu::Loading::registerswitch(LDarkside12);
							boolactive::activebool12 = 0;
						}
						timesback::id = 4169;
						timesback::lastpicid = 4200;
						timesback::thundermenu = (char*)"Darkside12-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside12 = 1;
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4200)
					{
						if (boolactive::activebool13)
						{
							Menu::Loading::registerswitch(LDarkside13);
							boolactive::activebool13 = 0;
						}
						timesback::id = 4201;
						timesback::lastpicid = 4277;
						timesback::thundermenu = (char*)"Darkside13-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 1;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4277)
					{
						if (boolactive::activebool14)
						{
							Menu::Loading::registerswitch(LDarkside14);
							boolactive::activebool14 = 0;
						}
						timesback::id = 4278;
						timesback::lastpicid = 4322;
						timesback::thundermenu = (char*)"Darkside14-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 1;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4322)
					{
						timesback::id = 4389;
						timesback::lastpicid = 4420;
						timesback::thundermenu = (char*)"Darkside14-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 1;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4420)
					{
						if (boolactive::activebool15)
						{
							Menu::Loading::registerswitch(LDarkside15);
							boolactive::activebool15 = 0;
						}
						timesback::id = 4421;
						timesback::lastpicid = 4497;
						timesback::thundermenu = (char*)"Darkside15-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 1;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4497)
					{
						if (boolactive::activebool16)
						{
							Menu::Loading::registerswitch(LDarkside16);
							boolactive::activebool16 = 0;
						}
						timesback::id = 4498;
						timesback::lastpicid = 4574;
						timesback::thundermenu = (char*)"Darkside16-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 1;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4574)
					{
						if (boolactive::activebool17)
						{
							Menu::Loading::registerswitch(LDarkside17);
							boolactive::activebool17 = 0;
						}
						timesback::id = 4575;
						timesback::lastpicid = 4623;
						timesback::thundermenu = (char*)"Darkside17-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 1;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4623)
					{
						if (boolactive::activebool18)
						{
							Menu::Loading::registerswitch(LDarkside18);
							boolactive::activebool18 = 0;
						}
						timesback::id = 4684;
						timesback::lastpicid = 4760;
						timesback::thundermenu = (char*)"Darkside18-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 1;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4760)
					{
						if (boolactive::activebool19)
						{
							Menu::Loading::registerswitch(LDarkside19);
							boolactive::activebool19 = 0;
						}
						timesback::id = 4761;
						timesback::lastpicid = 4837;
						timesback::thundermenu = (char*)"Darkside19-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 1;
						Darkside20 = 0;
						Darkside21 = 0;
					}
					if (timesback::id == 4837)
					{
						if (boolactive::activebool20)
						{
							Menu::Loading::registerswitch(LDarkside20);
							boolactive::activebool20 = 0;
						}
						timesback::id = 4838;
						timesback::lastpicid = 4914;
						timesback::thundermenu = (char*)"Darkside20-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 1;
						Darkside21 = 0;
					}
					if (timesback::id == 4914)
					{
						if (boolactive::activeboold21)
						{
							Menu::Loading::registerswitch(LDarkside21);
							boolactive::activeboold21 = 0;
						}
						timesback::id = 4915;
						timesback::lastpicid = 4988;
						timesback::thundermenu = (char*)"Darkside21-GTA5";
						timesback::backgroundfile = (char*)"Darkside";
						Darkside1 = 0;
						Darkside2 = 0;
						Darkside3 = 0;
						Darkside32 = 0;
						Darkside4 = 0;
						Darkside5 = 0;
						Darkside6 = 0;
						Darkside7 = 0;
						Darkside8 = 0;
						Darkside82 = 0;
						Darkside9 = 0;
						Darkside10 = 0;
						Darkside11 = 0;
						Darkside22 = 0;
						Darkside12 = 0;
						Darkside13 = 0;
						Darkside14 = 0;
						Darkside142 = 0;
						Darkside15 = 0;
						Darkside16 = 0;
						Darkside17 = 0;
						Darkside18 = 0;
						Darkside19 = 0;
						Darkside20 = 0;
						Darkside21 = 1;
					}
				}
				if (timesback::filechoosen == "Space")
				{
					timesback::id = 1;
					timesback::lastpicid = 49;
					timesback::thundermenu = (char*)"Thunder";
					timesback::backgroundfile = (char*)"Space_";
				}
				if (Menu2::Darkside)
				{
					std::string thundermenu2 = std::to_string(timesback::id) + timesback::backgroundfile;
					headers::Background = thundermenu;
					headers::Background2 = thundermenu2;
				}
				else
					if (!Menu2::Darkside)
					{
						std::string thundermenu2 = timesback::backgroundfile + std::to_string(timesback::id);
						headers::Background = thundermenu;
						headers::Background2 = thundermenu2;
					}
				Menu::Drawing::Spriter2((char*)headers::Background.c_str(), (char*)headers::Background2.c_str(), Features::zeropointhuitcenttt, Features::zeropointmillecentsoixantequinzettt, Features::zeropointvingtetunttt, Features::zeropointzeroquatrevingtcinq, Features::zerooo, Features::cinquanteee, Features::deuxcentcinquantecinqun, Features::deuxcentcinquantecinqdeux, Features::deuxcentcinquantecinqtrois);
				droptimer::backbool = false;
			}
	}
	}
	return 0;
}
int timesback::anybacktime()
{
	if (!Menu::Settings::menuclosed || !Features::onlinemenuplayerlist == !Features::showback)
	{
	}
	else
	{ 
		timesback::imagebool();
		/*std::this_thread::sleep_for(std::chrono::milliseconds(1));*/
	}
	return 0;
}
#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <fstream>
#include <string>

// Inclure les bibliothèques nécessaires
#pragma comment(lib, "wininet.lib")

bool DownloadFileWinINet(const std::string& url, const std::string& filePath) {
	// Ouvre une session WinINet
	HINTERNET hInternet = InternetOpenA("WinINet Example/1.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	if (!hInternet) {
		return false;
	}

	// Ouvre une connexion HTTP/HTTPS
	HINTERNET hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_SECURE, 0);
	if (!hConnect) {
		InternetCloseHandle(hInternet);
		return false;
	}

	// Crée un fichier local pour enregistrer le contenu téléchargé
	std::ofstream outFile(filePath, std::ios::binary);
	if (!outFile) {
		InternetCloseHandle(hConnect);
		InternetCloseHandle(hInternet);
		return false;
	}

	// Télécharge les données en blocs
	char buffer[4096];
	DWORD bytesRead;
	bool downloadSuccess = true;

	while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
		outFile.write(buffer, bytesRead);
		if (outFile.fail()) {
			downloadSuccess = false;
			break;
		}
	}

	// Ferme le fichier et les connexions
	outFile.close();
	InternetCloseHandle(hConnect);
	InternetCloseHandle(hInternet);

	return downloadSuccess;
}

int Github::downloading() {
	// URL du fichier à télécharger
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/header/Thunder.ytd";

	// Chemin local pour enregistrer le fichier
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thunder.ytd";

	// Téléchargement
	if (DownloadFileWinINet(dwnld_URL, savepath)) {
		return 0; // Succès
	}
	else {
		return -1; // Échec
	}
}

//int Github::downloading()
//{
//	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/header/Thunder.ytd";
//	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thunder.ytd";
//	std::wstring downloadfile = functions::s2ws(dwnld_URL);
//	LPCWSTR downloadingfile = downloadfile.c_str();
//	std::wstring savefile = functions::s2ws(savepath);
//	LPCWSTR savingfile = savefile.c_str();
//	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
//	URLDownloadToFile(NULL, downloadingfile, savingfile, 0, NULL);
//	return 0;
//}

int hashedcode::a1;
int hashedcode::r1;
int hashedcode::g1;
int hashedcode::b1;

int hashedcode::a2;
int hashedcode::r2;
int hashedcode::g2;
int hashedcode::b2;

DWORD hashedcode::value;
RGBA01 hashedcode::valuecode;
std::string hashedcode::hexcolor = "";
DWORD hashedcode::colorhex;

std::string hashedcode::hexcolorstring = "";

void hashedcode::CODEHASH()
{
	hashedcode::value = ((hashedcode::a1 & 0xFF) << 24) + ((hashedcode::r1 & 0xFF) << 16) + ((hashedcode::g1 & 0xFF) << 8) + (hashedcode::b1 & 0xFF);
	stringstream hcolor;
	hcolor << hex << hashedcode::value;
	hashedcode::hexcolor = hcolor.str();
}

void hashedcode::HASHCOLOR()
{
	hashedcode::valuecode.A = (hashedcode::value & 0xFF000000) >> 24;
	hashedcode::valuecode.R = (hashedcode::value & 0x00FF0000) >> 16;
	hashedcode::valuecode.G = (hashedcode::value & 0x0000FF00) >> 8;
	hashedcode::valuecode.B = (hashedcode::value & 0x000000FF);
}

