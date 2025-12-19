/*
THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
(C) Alexander Blade 2017
*/
//external call
#pragma once
extern bool wallDrive;
extern bool Walldrive;
void ScriptMain();

namespace VirtualKey {
	enum VirtualKey : int;
}
namespace storageVeh
{
	extern int bitsetnumber;
	extern int storevehicle(int vehiclestore);
	extern int storevehicleme(int vehiclestore);
}