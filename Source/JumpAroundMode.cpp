#include "stdafx.h"
#include "JumpAroundMode.h"

#include "macros.h"
//
//#include "..\Menu\Routine.h"
//
#include "GTAmath.h"
//#include "..\Natives\types.h" // RgbS
#include "GTAentity.h"
#include "natives.h"
#include "GTAped.h"
#include "Raycast.h"
#include "World.h"
#include "ExePath.h"
#include "FileLogger.h"

RgbS g_fadedRGB(255, 0, 0);
Vehicle g_myVeh = 0;

#pragma comment(lib, "Winmm.lib")
#include <Windows.h>
#include <vector>
#include <string>

namespace _JumpAroundMode_
{
	bool bEnabled = false;
	bool jumpAround_on = 0;
	bool jumpAround_off = 0;
	int jumpstart1 = 40;
	int jumpend1 = 90;
	/*float jumpstart2 = 0.6f;*/
	float jumpstart2 = 1.0f;
	float jumpend2 = 1.14f;
	float lightrange = 3.2f;
	float lightintensity = 1.2f;
	float discolightangle = 360.0f;
	/*float lightrange1 = 6.2f;*/
	float lightrange1 = 360.0f;
	/*float lightrange2 = 3.0f;*/
	float lightrange2 = 2.0f;
	float lightposition = 240.0f;

	struct DiscoLight { float angle; RgbS colour; };
	std::vector<DiscoLight> discoLights
	{
		{ 0, RgbS(0, 255, 255) },
		{ 180, RgbS(255, 50, 0) }
	};
	inline void DrawDiscoLights()
	{
		GTAped myPed = PLAYER::PLAYER_PED_ID();
		int& lvalue();
		Vector31& myPos = myPed.Position_get();
		int i;
		DiscoLight* dlight;
		RaycastResult ray;
		for (i = 0; i < discoLights.size(); i++)
		{
			dlight = &discoLights[i];
			dlight->angle += 0.0001f;
			if (dlight->angle > _JumpAroundMode_::discolightangle) dlight->angle = 0.0f;
			Vector31& lightPos = myPos.PointOnCircle(_JumpAroundMode_::lightposition, dlight->angle);
			ray = RaycastResult::Raycast(myPos + Vector31(0, 0, 2.0f), lightPos, IntersectOptions::Everything);
			if (ray.DidHitAnything())
			{
				lightPos = ray.HitCoords();
				World::DrawLightWithRange(lightPos, dlight->colour, _JumpAroundMode_::lightrange1, _JumpAroundMode_::lightrange2);
				World::DrawLightWithRange(lightPos, dlight->colour, -_JumpAroundMode_::lightrange1, -_JumpAroundMode_::lightrange2);
			}
		}
	}

	void Tick()
	{
		float jumpForce = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(_JumpAroundMode_::jumpstart2, _JumpAroundMode_::jumpend2);
		for (auto& ped : _nearbyPeds)
		{
			if (ENTITY::IS_ENTITY_ATTACHED(ped) || !PED::IS_PED_ON_FOOT(ped) || ENTITY::IS_ENTITY_IN_AIR(ped))
				continue;
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(ped);
			AI::TASK_JUMP(ped, true);
			ENTITY::APPLY_FORCE_TO_ENTITY(ped, 1, 0, 0, jumpForce, 0, 0, 0, false, false, true, true, false, true);
			AUDIO::STOP_PED_SPEAKING(ped, true);

			/*if (!ped.IsOnFoot() || ped.IsInAir()) continue;
			ped.RequestControlOnce();
			ped.Task().Jump();
			ped.Euphoria_get().BodyWrithe().Start(1000);
			ped.Euphoria_get().BodyWrithe().KneeAmplitude(0.3f);

			ped.ApplyForce(Vector31(0, 0, jumpForce));
			STOP_PED_SPEAKING(ped.Handle(), true);*/
		}

		auto& neonRGB = g_fadedRGB;
		jumpForce = GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(_JumpAroundMode_::jumpstart1, _JumpAroundMode_::jumpend1);
		for (auto& vehicle : _nearbyVehicles)
		{
			if (vehicle == g_myVeh || ENTITY::IS_ENTITY_ATTACHED(vehicle))
				continue;

			Vector3& Pos = ENTITY::GET_ENTITY_COORDS(vehicle, 1);
			//if (GET_GAME_TIMER() >= Menu::delayedTimer)
			//{
			//neonRGB = { GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255), GET_RANDOM_INT_IN_RANGE(0, 255) };
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 0, true);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 1, true);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 2, true);
			VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 3, true);
			VEHICLE::_SET_VEHICLE_NEON_LIGHTS_COLOUR(vehicle, neonRGB.R, neonRGB.G, neonRGB.B);
			//}
			/*GRAPHICS::DRAW_LIGHT_WITH_RANGE(Pos.x, Pos.y, Pos.z, neonRGB.R, neonRGB.G, neonRGB.B, _JumpAroundMode_::lightrange, _JumpAroundMode_::lightintensity);
			GRAPHICS::DRAW_LIGHT_WITH_RANGE(Pos.x, Pos.y, Pos.z, neonRGB.R, neonRGB.G, neonRGB.B, -_JumpAroundMode_::lightrange, -_JumpAroundMode_::lightintensity);*/
			GRAPHICS::DRAW_LIGHT_WITH_RANGE(Pos.x, Pos.y, Pos.z, neonRGB.R, neonRGB.G, neonRGB.B, _JumpAroundMode_::lightrange, _JumpAroundMode_::lightintensity);
			GRAPHICS::DRAW_LIGHT_WITH_RANGE(Pos.x, Pos.y, Pos.z, neonRGB.R, neonRGB.G, neonRGB.B, -_JumpAroundMode_::lightrange, -_JumpAroundMode_::lightintensity);
			/*GRAPHICS::_DRAW_LIGHT_WITH_RANGE_AND_SHADOW(Pos.x, Pos.y, Pos.z, neonRGB.R, neonRGB.G, neonRGB.B, _JumpAroundMode_::lightrange, _JumpAroundMode_::lightintensity, 0);
			GRAPHICS::_DRAW_LIGHT_WITH_RANGE_AND_SHADOW(Pos.x, Pos.y, Pos.z, neonRGB.R, neonRGB.G, neonRGB.B, -_JumpAroundMode_::lightrange, -_JumpAroundMode_::lightintensity, 0);*/
			//if (IS_ENTITY_IN_AIR(vehicle)) continue;
			if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(vehicle))
			{
				NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehicle);
				VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 0, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 1, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 2, 1); VEHICLE::_SET_VEHICLE_NEON_LIGHT_ENABLED(vehicle, 3, 1);
				ENTITY::APPLY_FORCE_TO_ENTITY(vehicle, 0, 0.0f, 0.0f, jumpForce, 0.0f, 0.0f, 0.0f, false, false, true, true, false, true); // 68.f
			}
		}
		DrawDiscoLights();
	}

	std::string szAlias = "JumpAroundMode";
	std::string szAlias2 = "JumpAroundMode";
	int stop()
	{
		std::string szCommand;
		szCommand = "stop " + szAlias;
		mciSendStringA(szCommand.c_str(), NULL, 0, 0);

		szCommand = "close " + szAlias;
		mciSendStringA(szCommand.c_str(), NULL, 0, 0);
		_JumpAroundMode_::BgMusic(false);
		return 0;
	}

	int start()
	{
		BgMusic(_JumpAroundMode_::jumpAround_off);
		return 1;
	}
	void _JumpAroundMode_::startmusicdownloadsmp3(const std::string title) {
		szAlias = title;
	}
	void _JumpAroundMode_::startmusicdownloads2(const std::string title) {
		szAlias2 = title;
	}

	void BgMusic2(bool enable)
	{
		std::string szCommand;
		/*try
		{*/
			if (enable)
			{
				szCommand = "open \"" + Menu2::RadioStation  + "\\" + szAlias2 + ".awc" + "\" type MPEGVideo" + " alias " + szAlias2;
				mciSendStringA(szCommand.c_str(), NULL, 0, 0);

				szCommand = "play " + szAlias2 + " from 0 repeat";
				mciSendStringA(szCommand.c_str(), NULL, 0, 0);

				szCommand = "setaudio " + szAlias2 + " volume to 400";
				mciSendStringA(szCommand.c_str(), NULL, 0, 0);
			}
			else
			{
				szCommand = "stop " + szAlias2;
				mciSendStringA(szCommand.c_str(), NULL, 0, 0);

				szCommand = "close " + szAlias2;
				mciSendStringA(szCommand.c_str(), NULL, 0, 0);
			}
		/*}*/
		//catch (std::exception& e)
		//{
		//	/*ige::myLog << ige::LogType::LOG_ERROR << szAlias2 + " countered an exception -> " << e.what();*/
		//}
	}

	void BgMusic(bool enable)
	{
			std::string szCommand;
			/*try
			{*/
				if (enable)
				{ 

						szCommand = "open \"" + GetPathffA(Pathff::ThunderMenu, true) + szAlias + ".mp3" + "\" type MPEGVideo" + " alias " + szAlias;
						mciSendStringA(szCommand.c_str(), NULL, 0, 0);

						std::string quoteyoutube = "\\ThunderMenu\\Youtube\\";
						std::string doublequote = "\"";
						std::string getdirectory = Directory::get_current_dir() + quoteyoutube;
						std::ofstream files(getdirectory + "testd2.txt");
						std::string newline = "\n";
						files << szCommand << newline;

						szCommand = "play " + szAlias + " from 0 repeat";
						mciSendStringA(szCommand.c_str(), NULL, 0, 0);

						szCommand = "setaudio " + szAlias + " volume to 400";
						mciSendStringA(szCommand.c_str(), NULL, 0, 0);
				}
				else
				{
						szCommand = "stop " + szAlias;
						mciSendStringA(szCommand.c_str(), NULL, 0, 0);

						szCommand = "close " + szAlias;
						mciSendStringA(szCommand.c_str(), NULL, 0, 0);
				}
			/*}*/
			//catch (std::exception & e)
			//{
			//	/*ige::myLog << ige::LogType::LOG_ERROR << szAlias + " countered an exception -> " << e.what();*/
			//}
		}

	void StartJumping(bool enable)
	{
		if (_JumpAroundMode_::jumpAround_off)
		{ 
		BgMusic(enable);
		}
		int i;
		for (i = 0; i < discoLights.size(); i++)
		{
			discoLights[i].colour = RgbS(rand() % 256, rand() % 256, rand() % 256);
		}
	}
}

namespace massacremode
{
bool bmassEnabled = false;

void set_massacre_mode_tick()
{
	float tempCoords1[3];
	//Hash tempHash;
	Ped tempPed = PLAYER::PLAYER_PED_ID();
	//int i;
	//bool tick = 0;

	//Vector3(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS((tempPed, GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f))).ToArray(tempCoords1);

	// Apply force to nearby vehicles
	//std::vector<Vehicle>& allVehicles = get_all_nearby_vehicles(tempPed, 50);
	auto& allVehicles = _nearbyVehicles;
	for (GTAentity veh : allVehicles)
	{
		if (veh.Equals(g_myVeh))
			continue;
		veh.RequestControlOnce();
		ENTITY::APPLY_FORCE_TO_ENTITY(veh.Handle(), 1, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(1.0f, 9.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(1.0f, 9.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(1.0f, 6.0f), 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
	}

	// Apply force to nearby peds
	//std::vector<Ped>& allPeds = get_all_nearby_peds(tempPed, 50);
	auto& allPeds = _nearbyPeds;
	for (GTAped ped : allPeds)
	{
		ped.RequestControlOnce();
		ped.GiveNM(NMString::nm0286_handCuffsBehindBack);
		PED::SET_PED_RAGDOLL_FORCE_FALL(ped.Handle());
		ENTITY::APPLY_FORCE_TO_ENTITY(ped.Handle(), 1, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(1.0f, 9.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(1.0f, 9.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(1.0f, 6.0f), 5.0f, 13.0f, 6.5f, 1, 1, 1, 1, 0, 1);
	}

	// Water hydrants and explosions
	if (rand() % 2)
	{
		Vector31(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS1(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(25.0f, 50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(25.0f, 50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f))).ToArray(tempCoords1);
		Hooking::ExplosionBypass(1);
		FIRE::ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], EXPLOSION::TRAIN, 0.2f, 0, 0, 0.05f);
		Hooking::ExplosionBypass(0);
		Vector31(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS1(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(25.0f, 50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-25.0f, -50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f))).ToArray(tempCoords1);
		Hooking::ExplosionBypass(1); 
		FIRE::ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], EXPLOSION::TRAIN, 0.2f, 0, 0, 0.05f);
		Hooking::ExplosionBypass(0);
		//Vector3(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(tempPed, GET_RANDOM_FLOAT_IN_RANGE(9.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f))).ToArray(tempCoords1);
		//ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], EXPLOSION::DIR_WATER_HYDRANT, 8.0f, 1, 0, 0.0f);
	}
	else
	{
		Vector31(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS1(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-25.0f, -50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(25.0f, 50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f))).ToArray(tempCoords1);
		Hooking::ExplosionBypass(1); 
		FIRE::ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], EXPLOSION::TRAIN, 4.0f, 0, 0, 0.15f);
		Hooking::ExplosionBypass(0); 
		Vector31(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS1(tempPed, GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-25.0f, -50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(-25.0f, -50.0f), GAMEPLAY::GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f))).ToArray(tempCoords1);
		Hooking::ExplosionBypass(1); 
		FIRE::ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], EXPLOSION::TRAIN, 4.0f, 0, 0, 0.15f);
		Hooking::ExplosionBypass(0);
		//Vector3(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(tempPed, GET_RANDOM_FLOAT_IN_RANGE(-9.0f, -25.0f), GET_RANDOM_FLOAT_IN_RANGE(5.0f, 25.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 20.0f))).ToArray(tempCoords1);
		//ADD_EXPLOSION(tempCoords1[0], tempCoords1[1], tempCoords1[2], EXPLOSION::DIR_WATER_HYDRANT, 8.0f, 1, 0, 0.0f);
	}
	// Zombies
	/*tempHash = PedHash::Zombie01;
	if (GET_GAME_TIMER() >= Menu::delayedTimer)
	{
	if (!HAS_MODEL_LOADED(tempHash)) REQUEST_MODEL(tempHash);
	else
	{
	Vector3(GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(tempPed, GET_RANDOM_FLOAT_IN_RANGE(25.0f, 50.0f), GET_RANDOM_FLOAT_IN_RANGE(25.0f, 50.0f), GET_RANDOM_FLOAT_IN_RANGE(0.4f, 5.0f))).ToArray(tempCoords1);
	tempPed = CREATE_PED(PedType::Human, 2890614022, tempCoords1[0], tempCoords1[1], tempCoords1[2], GET_RANDOM_FLOAT_IN_RANGE(0.0f, 360.0f), 1, 1);
	SET_NETWORK_ID_CAN_MIGRATE(PED_TO_NET(tempPed), 1);
	SET_PED_COMBAT_ABILITY(tempPed, 100);
	TASK_COMBAT_PED(tempPed, PLAYER_PED_ID(), 0, 16);
	TASK_COMBAT_HATED_TARGETS_AROUND_PED(tempPed, 400.0f, 0);
	SET_PED_AS_NO_LONGER_NEEDED(&tempPed);
	}
	}*/

}
}