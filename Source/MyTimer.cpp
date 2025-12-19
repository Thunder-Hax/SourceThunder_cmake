#include "stdafx.h"
#include "MyTimer.h"
#include "Header.h"

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
#include <Windows.h>

int droptimer::timertimes = 200;
int droptimer::timertimes2 = 25;

bool droptimer::backbool2 = true;
bool droptimer::boolback2 = true;

bool droptimer::picbackbool2 = false;
void droptimer::backgroundpicture2()
{
if (droptimer::boolback2)
{
DWORD ticks = GetTickCount64();
DWORD milliseconds = ticks % 1000;
//ticks /= 1000;
//DWORD seconds = ticks % 60;
//ticks /= 60;
//DWORD minutes = ticks % 60;
//ticks /= 60;
//DWORD hours = ticks; // may exceed 24 hours.
		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
		int getTimer = milliseconds;
		if (getTimer % droptimer::timertimes2 == 0)
		{
			timesback::anybacktime2();
			droptimer::backbool2 = 1;
			droptimer::boolback2 = 0;
			droptimer::backgb2 = 1;
		}
		/*Timer4 t4 = Timer4();
		t4.Timer4::setTimeout4([&]() {
			droptimer::backbool2 = 1;
			droptimer::boolback2 = 0;
			droptimer::backgb2 = 1;
			t4.stop4();
			}, droptimer::timertimes2);*/
	}
	if (!droptimer::picbackbool2)
	{
		droptimer::backbool2 = 1;
		droptimer::boolback2 = 1;
	}
}

bool droptimer::backgb2 = true;
void droptimer::backgvoid22() {
	if (droptimer::backgb2)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		/*int getmilli = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
		int getmilli = milliseconds;
		if (getmilli % droptimer::timertimes2 == 0)
		{
			droptimer::backgb2 = 0;
			droptimer::boolback2 = 1;
		}
		/*Timer3 t3 = Timer3();
		t3.setTimeout3([&]() {
			droptimer::backgb2 = 0;
			droptimer::boolback2 = 1;
			t3.stop3();
			}, droptimer::timertimes2);*/
	}
}

bool droptimer::picbackbool = false;
void droptimer::backgroundpicture()
{
	if (droptimer::boolback)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		/*int getTimes = TIME::GET_CLOCK_MINUTES();*/
		int getTimes = milliseconds;
		if (getTimes % droptimer::timertimes == 0)
		{
			timesback::anybacktime();
			droptimer::backbool = 1;
			droptimer::boolback = 0;
			droptimer::backgrbool = 1;
		}
		/*Timer2 t2 = Timer2();
		t2.Timer2::setTimeout2([&]() {
			droptimer::backbool = 1;
			droptimer::boolback = 0;
			droptimer::backgrbool = 1;
			t2.stop2();
			}, droptimer::timertimes);*/
	}
	if (!droptimer::picbackbool)
	{
		droptimer::backbool = 1;
		droptimer::boolback = 1;
	}
}

bool droptimer::backbool = 1;
bool droptimer::boolback = true;
bool droptimer::backgrbool = true;
void droptimer::backgvoid2() {
	if (droptimer::backgrbool)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		/*int getmin = TIME::GET_CLOCK_MINUTES();*/
		int getmin = milliseconds;
		if (getmin % droptimer::timertimes == 0)
		{
			droptimer::backgrbool = 0;
			droptimer::boolback = 1;
		}
		/*Timer1 t1 = Timer1();
		t1.setTimeout1([&]() {
			droptimer::backgrbool = 0;
			droptimer::boolback = 1;
			t1.stop1();
			}, droptimer::timertimes);*/
	}
}

bool droptimer::mrpb1 = false;
//bool droptimer::mrpb11 = true;
bool droptimer::mrpv2 = false;
//bool droptimer::mrpv22 = false;
int timermoves = 10000;
void droptimer::mvp1() {
	if (droptimer::mrpb1)
	{
		DWORD ticks0 = GetTickCount64();
		DWORD milliseconds0 = ticks0 % 1000;
		int getmin0 = milliseconds0;
		if (getmin0 % timermoves == 0)
		{
			droptimer::mrpv2 = 1;
			droptimer::mrpb1 = 0;
		}
	}
}

void droptimer::mvp2() {
	if (droptimer::mrpv2)
	{
		DWORD ticks1 = GetTickCount64();
		DWORD milliseconds1 = ticks1 % 1000;
		int getmin0 = milliseconds1;
		if (getmin0 % timermoves == 0)
		{
			droptimer::mrpb1 = 1;
			droptimer::mrpv2 = 0;
		}
	}
}

bool droptimer::dixsecondedropbool = false;
bool droptimer::dixsecondedropbool2 = false;

void droptimer::dixsecondedroptimer() {
	if (droptimer::dixsecondedropbool)
	{
		Timer00 t00 = Timer00();
		t00.setTimeout00([&]() {
			droptimer::dixsecondedropbool = 0;
			droptimer::dixsecondedropbool2 = 1;
			t00.stop00();
			}, 10000);
	}
}

void droptimer::dixsecondedroptimer2() {
	if (droptimer::dixsecondedropbool2)
	{
		Timer0 t = Timer0();
		t.setTimeout0([&]() {
			droptimer::dixsecondedropbool = 1;
			droptimer::dixsecondedropbool2 = 0;
			t.stop0();
			}, 10000);
	}
}

template<typename Function00>
void Timer00::setTimeout00(Function00 function, int delay) {
	this->clear00 = false;
	std::thread t00([=]() {
		if (this->clear00) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear00) return;
		function();
		});
	t00.detach();
}
template<typename Function00>
void Timer00::setInterval00(Function00 function, int interval) {
	this->clear00 = false;
	std::thread t00([=]() {
		while (true) {
			if (this->clear00) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear00) return;
			function();
		}
		});
	t00.detach();
}

void Timer00::stop00() {
	this->clear00 = true;
}

template<typename Function0>
void Timer0::setTimeout0(Function0 function, int delay) {
	this->clear0 = false;
	std::thread t0([=]() {
		if (this->clear0) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear0) return;
		function();
		});
	t0.detach();
}
template<typename Function0>
void Timer0::setInterval0(Function0 function, int interval) {
	this->clear0 = false;
	std::thread t0([=]() {
		while (true) {
			if (this->clear0) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear0) return;
			function();
		}
		});
	t0.detach();
}

void Timer0::stop0() {
	this->clear0 = true;
}

template<typename Function11>
void Timer11::setTimeout11(Function11 function, int delay) {
	this->clear11 = false;
	std::thread t11([=]() {
		if (this->clear11) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear11) return;
		function();
		});
	t11.detach();
}
template<typename Function11>
void Timer11::setInterval11(Function11 function, int interval) {
	this->clear11 = false;
	std::thread t11([=]() {
		while (true) {
			if (this->clear11) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear11) return;
			function();
		}
		});
	t11.detach();
}

void Timer11::stop11() {
	this->clear11 = true;
}

template<typename Function12>
void Timer12::setTimeout12(Function12 function, int delay) {
	this->clear12 = false;
	std::thread t12([=]() {
		if (this->clear12) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear12) return;
		function();
		});
	t12.detach();
}
template<typename Function12>
void Timer12::setInterval12(Function12 function, int interval) {
	this->clear12 = false;
	std::thread t12([=]() {
		while (true) {
			if (this->clear12) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear12) return;
			function();
		}
		});
	t12.detach();
}

void Timer12::stop12() {
	this->clear12 = true;
}

template<typename Function1>
void Timer1::setTimeout1(Function1 function, int delay) {
	this->clear1 = false;
	std::thread t1([=]() {
		if (this->clear1) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear1) return;
		function();
		});
	t1.detach();
}
template<typename Function1>
void Timer1::setInterval1(Function1 function, int interval) {
	this->clear1 = false;
	std::thread t1([=]() {
		while (true) {
			if (this->clear1) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear1) return;
			function();
		}
		});
	t1.detach();
}

void Timer1::stop1() {
	this->clear1 = true;
}

template<typename Function2>
void Timer2::setTimeout2(Function2 function, int delay) {
	this->clear2 = false;
	std::thread t2([=]() {
		if (this->clear2) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear2) return;
		function();
		});
	t2.detach();
}
template<typename Function2>
void Timer2::setInterval2(Function2 function, int interval) {
	this->clear2 = false;
	std::thread t2([=]() {
		while (true) {
			if (this->clear2) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear2) return;
			function();
		}
		});
	t2.detach();
}

void Timer2::stop2() {
	this->clear2 = true;
}

template<typename Function3>
void Timer3::setTimeout3(Function3 function, int delay) {
	this->clear3 = false;
	std::thread t3([=]() {
		if (this->clear3) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear3) return;
		function();
		});
	t3.detach();
}
template<typename Function3>
void Timer3::setInterval3(Function3 function, int interval) {
	this->clear3 = false;
	std::thread t3([=]() {
		while (true) {
			if (this->clear3) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear3) return;
			function();
		}
		});
	t3.detach();
}

void Timer3::stop3() {
	this->clear3 = true;
}

template<typename Function4>
void Timer4::setTimeout4(Function4 function, int delay) {
	this->clear4 = false;
	std::thread t4([=]() {
		if (this->clear4) return;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		if (this->clear4) return;
		function();
		});
	t4.detach();
}
template<typename Function4>
void Timer4::setInterval4(Function4 function, int interval) {
	this->clear4 = false;
	std::thread t4([=]() {
		while (true) {
			if (this->clear4) return;
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (this->clear4) return;
			function();
		}
		});
	t4.detach();
}

void Timer4::stop4() {
	this->clear4 = true;
}

bool blackhole::backbool = false;
int blackhole::id = 0;
int blackhole::lastid = 2;
bool blackhole::blackhole()
{
	if (blackhole::backbool)
	{
		if (timesback::id < blackhole::lastid)
		{
			int timesreturn = blackhole::id + 1;
			blackhole::id = timesreturn;
			blackhole::backbool = false;
		}
		else
			if (blackhole::id = blackhole::lastid)
			{
				blackhole::id = 0;
			blackhole::backbool = false;
			}
	}
	return 0;
}

int blackhole::anyblackhole()
{
	blackhole::backbool = true;
	blackhole::blackhole();
	myblack::myblackhole2();
	return 0;
}

int blackhole::timeblackhole = 100;

bool blackhole::blackbool = true;
bool blackhole::boolblack = true;

bool blackhole::blacktimerbool = false;
void blackhole::blackholetimer1()
{
	if (blackhole::boolblack)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		int getTimer = milliseconds;
		if (getTimer % blackhole::timeblackhole == 0)
		{
			blackhole::anyblackhole();
			blackhole::blackbool = 1;
			blackhole::boolblack = 0;
			blackhole::blackbool2 = 1;
		}
	}
	if (!blackhole::blacktimerbool)
	{
		blackhole::blackbool = 1;
		blackhole::boolblack = 1;
	}
}

bool blackhole::blackbool2 = true;
void blackhole::blackholetimer2() {
	if (blackhole::blackbool2)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		int getmilli = milliseconds;
		if (getmilli % blackhole::timeblackhole == 0)
		{
			blackhole::blackbool2 = 0;
			blackhole::boolblack = 1;
		}
	}
}
int target2 = 0;

//#define NeverWanted01 1893551
//#define NeverWanted02 599
//#define NeverWanted03 510

//#define NeverWanted01 1887305
//#define NeverWanted02 610
//#define NeverWanted03 512
#define NeverWanted01 1888737
#define NeverWanted02 611
#define NeverWanted03 513
//above 1541018842 //return Global_1888737[plParam0 /*611*/].f_513;

#define Freemode_Give_Off_The_Radar2 OffTheRadar /*-162943635*//*-391633760*/ //-397188359 //Var0.f_3 = get_network_time(); //giveoff

//int offradar::offradarvoid3()
//{
//	for (int i = 0; i <= 32; i++)
//	{
//		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
//		if (Handle != PLAYER::PLAYER_PED_ID())
//		{
//			target2 = i;
//			if ((timeGetTime() - Features::Time_Send_OTR) > 5000)
//			{
//				uint64_t args[7] =
//				{
//					Freemode_Give_Off_The_Radar2, target2,
//					NETWORK::GET_NETWORK_TIME() + 0x3C, NETWORK::GET_NETWORK_TIME() + 0x3C, 1, 1,
//					globalHandle(NeverWanted01).At(target2, NeverWanted02).At(NeverWanted03).As<int>()
//				};
//				Hooking::trigger_script_event(1, &args[0], 7, 1 << target2);
//				Features::Time_Send_OTR = GetTickCount();
//			}
//		}
//	}
//	return 0;
//}
#define Freemode_Give_Off_The_Radar_Global2 globalHandle(NeverWanted01).At(target2, NeverWanted02).At(NeverWanted03).As<int>()
int offradar::offradarvoid3()
{
	for (int i = 0; i <= 32; i++)
	{
		int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
		if (Handle != PLAYER::PLAYER_PED_ID())
		{
			target2 = i;
			/*if ((timeGetTime() - Features::Time_Send_OTR) > 5000)
			{*/
				int unk1 = NETWORK::GET_NETWORK_TIME() + 0x3C;
				int unk2 = NETWORK::GET_NETWORK_TIME() + 0x3C; /*60*/
				int unk6 = Freemode_Give_Off_The_Radar_Global2;
				DWORD64 args[8] = { Freemode_Give_Off_The_Radar2, Handle, Handle, unk2, unk1, 1, 1, unk6 };
				/*NETWORK::TriggerScriptEvent(1, args, 7, 1 << target2);*/
				Hooking::trigger_script_event(1, &args[0], 8, 1 << target2, unk6);
				/*Features::Time_Send_OTR = timeGetTime();
			}*/
		}
	}
	return 0;
}

bool offradar::offradarbool1 = true;
bool offradar::offradarbool2 = true;

bool offradar::offradarbool4 = true;
int offradar::offradarint = 5;


bool offradar::offradarbool3 = false;

void offradar::offradarvoid1()
{
	if (offradar::offradarbool2)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		int getTimer = milliseconds;

		if (getTimer % offradar::offradarint == 0)
		{
			offradar::offradarvoid3();
			offradar::offradarbool1 = 1;
			offradar::offradarbool2 = 0;
			offradar::offradarbool4 = 1;
		}
	}
	if (!offradar::offradarbool3)
	{
		offradar::offradarbool1 = 1;
		offradar::offradarbool2 = 1;
	}
}

void offradar::offradarvoid() {
	if (offradar::offradarbool4)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		int getmilli = milliseconds;
		if (getmilli % offradar::offradarint == 0)
		{
			offradar::offradarbool4 = 0;
			offradar::offradarbool2 = 1;
		}
	}
}


