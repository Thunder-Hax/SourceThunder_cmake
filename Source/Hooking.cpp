//Hooking.cpp
#pragma once
#include "stdafx.h"
#include "Features.h"

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

#include "Memory.h"
#include "Functions.h"
#include "Hooking.h"
#include "Spoof.h"

#include <iostream>
#include <iomanip>
#include <memory>

#include "PersistOutfit.h"

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

//#include "reclass/CNetGamePlayer.hpp"
//#include "reclass/CNetworkPlayerMgr.hpp"
#include "reclass/GTAV-Classes/network/CNetGamePlayer.hpp"
#include "reclass/GTAV-Classes/network/CNetworkPlayerMgr.hpp"
#include <stdint.h>

#include <iostream>
#include <chrono>
#include <thread>

#include <memoryapi.h>
#include <winnt.h>

#include "nativeCaller.h"
#include "CrossMapping.h"
#include "Functions.h"

std::optional<std::chrono::high_resolution_clock::time_point> m_wake_time;
using namespace CallerNative;

using namespace Memory;
//using namespace Big;
//ScriptThread*(*GetActiveThread)() = nullptr;
GtaThread* (*GetActiveThread)() = nullptr;

HMODULE Hooking::_hmoduleDLL;
HANDLE mainFiber;
DWORD wakeAt;
HANDLE mainFiber2;
HANDLE m_main_fiber;

DWORD wakeAt2;

typedef unsigned char BYTES;
std::vector<LPVOID>		Hooking::m_hooks;
uint64_t*				Hooking::m_frameCount;
fpIsDLCPresent			Hooking::is_DLC_present;
//fpSetName			    Hooking::SetName;
fpTriggerScriptEvent	Hooking::trigger_script_event;
fpSetLobbyWeather	    Hooking::set_lobby_weather;
fpGetEventData	        Hooking::get_event_data;
fpIncrementStatHook	    Hooking::increment_stat_hook;
twoBytes* CHooking::m_ownedExplosionBypass;
//BYTE* CHooking::m_ownedExplosionBypass;
fpDrawRect							CHooking::draw_rect;
//fpDrawLine							CHooking::draw_line;
fpDrawNotification					CHooking::draw_notification;
fpGetNetworkTime					CHooking::get_network_time;
fpCreateVehicle						CHooking::create_vehicle;

Vehicle cVehicleBypass::CVehBypass(Hash model, Vector3* pos, float heading, BOOL networked, BOOL unk2)
{
	BypassPatch::ModelSpawnBypass(true);
	Vehicle veh = CHooking::create_vehicle(model, pos, heading, networked, unk2);
	BypassPatch::ModelSpawnBypass(false);
	return veh;
}
//MemoryPool**			CHooking::m_entityPool;
//MemoryPool**			CHooking::m_pedPool;
//threeBytes*				CHooking::m_infAmmo;
//threeBytes*				CHooking::m_noReload;
fpSetVehicleFixed					CHooking::set_vehicle_fixed;
fpSetModelAsNoLongerNeeded CHooking::Set_Model_As_No_Longer_Needed;

//fpspoofer				CHooking::spoofer;
//fpSetVehicleDeformationFixed		CHooking::set_vehicle_deformation_fixed;
//fpNetworkRequestControlOfEntity		CHooking::network_request_control_of_entity;
fpAddOwnedExplosion     Hooking::add_owned_explosion;
//fpGetPlayerPed          Hooking::get_player_ped;
fpGetPlayerAddress		Hooking::GetPlayerAddress;
fpAddressToEntity		Hooking::AddressToEntity;
fpGetPlayerName          Hooking::get_player_name;

//sub7FF71339282C Hooking::sub_7FF71339282C;

fpNetworkIsSessionStarted  Hooking::network_is_session_started;
//Receive Hooking::m_ChatReceive;
//ChatPlayerID Hooking::m_GetChatPlayerID;
//__int64* Hooking::m_ChatReceive;
//GetChatPlayerID* Hooking::m_GetChatPlayerID;
fpChatMessage                           Hooking::get_message;
fpGetSender*							hook_sender::get_sender = nullptr;
//GameVariables1						GameVariables1::get_sender = nullptr;

//fpGetPlayerPedScriptIndex          Hooking::get_player_ped_script_index;
fpSetLobbyTime          Hooking::set_lobby_time;
//fpIsPedShooting         Hooking::is_ped_shooting;
fpSendMessage2           Hooking::send_message2;
fpAddTextCompSubstrPlayerName Hooking::add_text_comp_substr_playername;
fpEndTextCmdDisplayText       Hooking::end_text_cmd_display_text;
fpBeginTextCmdDisplayText     Hooking::begin_text_cmd_display_text;
fpCreateAmbientPickup            Hooking::create_ambient_pickup;
//fpCreateAmbientPickup2            Hooking::create_ambient_pickup2;
fpREQUESTMODEL					Hooking::request_model;
//fpHASMODELLOADED					Hooking::has_model_loaded;
fpISMODELAVEHICLE					Hooking::is_model_a_vehicle;
//fpSTARTPARTICLEFXNONLOOPEDONENTITY2            Hooking::_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2;
fpStatSetInt						Hooking::stat_set_int;
fpStatGetInt						Hooking::stat_get_int;
fpStatSetFloat						Hooking::stat_set_float;
fpStatSetBool						Hooking::stat_set_bool;
fpFileRegister						 Hooking::pRegisterFile;
//fpPlayerId						 Hooking::player_id;
//fpNetworkShopBeginService			Hooking::network_shop_begin_service;
//fp_CreateObject						Hooking::create_object;
void* Hooking::invoker_return_address;
void* Hooking::pickupdrop;
fpreplay							 Hooking::replay_interface;
fplaylist							 Hooking::player_list;
fpunkmodel							 Hooking::unk_model;

fpRemoveWeapons        Hooking::RemoveWeapons;
//fpmstartgetsessionbygamerhandle Hooking::m_start_get_session_by_gamer_handle;
fpmsendinviteacceptedpresenceevent Hooking::m_send_invite_accepted_presence_event;
fpmpresencestruct Hooking::m_presence_struct;

fpDisableErrorScreen        Hooking::DisableErrorScreen;
//fpRIDJoinFriends      Hooking::RIDJoinFriends;
////fpRIDJoinFriendsV2      Hooking::RIDJoinFriendsV2;
//fpRIDJoinHandle        Hooking::RIDJoinHandle;

fpRIDJoinFriendsHandler        Hooking::RIDJoinFriendsHandler;
//
//
//fpRIDInviteFriends      Hooking::RIDInviteFriends;
//fpRIDInviteHandle        Hooking::RIDInviteHandle;

fpSpectatorCheck        Hooking::SpectatorCheck;
SETVEHICLEFORWARDSPEED Hooking::SET_VEHICLE_FORWARD_SPEED;

//fpNetworkSessionKickPlayer              Hooking::network_session_kick_player;

//fpNetworkCreateSynchronisedScene        SyncScene::create_synchronised_scene;
//fpNetworkAddPedToSynchronisedScene      SyncScene::add_ped_to_synchronised_scene;
//fpNetworkStartSynchronisedScene         SyncScene::start_synchronised_scene;

static char* HashKick[] = {
"502129530", //kick
"-795380017", //kick
"-1544474774", //kick
"1456052554", //kick
"-786817413", //kick
"1016286404", //kick
"-1423341094", //kick
"209861916", //kick
"1789200508", //kick
"1279400152", //kick
"-2056857136", //kick
"230874362", //kick
"290989781", //kick
"879177392", //kick
"-1247985006", //kick
"421832664", //kick
"-1770641691", //kick
"1789363239", //kick
"1408207199", //kick
"243072129", //kick
"-508465573", //kick
"1810531023", //kick
"2119903152", //kick
"564609617", //kick
"463008662" //kick
};

uint Weaps[] = {
0x99B507EA, 0x678B81B1, 0x4E875F73, 0x958A4A8F, 0x440E4788, 0x84BD7BFD, 0x1B06D571, 0x5EF9FEC4, 0x22D8FE39, 0x99AEEB3B, 0x13532244, 0x2BE6766B, 0xEFE7E2DF, 0xBFEFFF6D, 0x83BF0278, 0xAF113F99, 0x9D07F764, 0x7FD62962, 0x1D073A89, 0x7846A318, 0xE284C527, 0x9D61E50F, 0x3656C8C1, 0x05FC3C11, 0x0C472FE2, 0x33058E22, 0xA284510B, 0x4DD2DC56, 0xB1CA77B1, 0x687652CE, 0x42BF8A85, 0x93E220BD, 0x2C3731D9, 0xFDBC8A50, 0x24B17070, 0x060EC506, 0x34A67B97, 0xFDBADCED, 0x23C9F95C, 0x497FACC3, 0xF9E6AA4B, 0x61012683, 0xC0A3098D, 0xD205520E, 0xBFD21232, 0x7F229F94, 0x92A27487, 0x083839C4, 0x7F7497E5, 0xA89CB99E, 0x3AABBBAA, 0xC734385A, 0x787F0BB, 0x47757124, 0xD04C944D, 0x3813FC08,
0xA2719263, 0x8BB05FD7, 0xF9DCBF2D, 0xD8DF3C3C, 0xDD5DF8D9, 0xDFE37640, 0x19044EE0, 0xCD274149, 0x94117305, 0x3813FC08, 0xBFE256D4, 0x88374054, 0x83839C4, 0xDC4DB296, 0xC1B3C3D1, 0xCB96392F, 0x97EA20B8, 0x2BE6766B, 0x0A3D4D34, 0xDB1AA450, 0xBD248B55, 0x555AF99A, 0xEF951FBB, 0x12E82D3D, 0x394F415C, 0xFAD1F1C9, 0x969C3D67, 0x84D6FAFD, 0x624FE830, 0xDBBD7280, 0xA914799, 0x6A6C02E0, 0x6D544C99, 0x63AB0442, 0x0781FE4A, 0xA0973D5E, 0xAB564B93, 0xBA45E8B8, 0xFBAB5776, 0x060EC506, 0xAF3696A1, 0xD7DBF707, 0x476BF155, 0xB62D1F67, 0xF38A0747, 0x167C5572, 0x2C9CA024, 0xA991DAE8, 0xD6678401, 0x6AA85572, 0x6056AC20, 0x2B5EF5EC, 0xBA536372, 0x917F6C8C, 0x5A96BA4, 0x57A4368C, 0x9D1F17E6
};

//Vector2* m_WaypointCoords;

int playerSelected = 0;
void badstuffcode::desyncPlayer()
{
	//static CNetGamePlayer* selectedPlayer;

	/*if (ImGui::ListBoxHeader("##PlayerList", ImVec2(200.f, 250.f))) {
		auto plyrMgr = *g_Pointers->m_NetworkPlayerMgr;
		if (plyrMgr != nullptr) {
			for (auto plyr : plyrMgr->m_player_list) {
				if (plyr != nullptr) {
					if (plyr->is_valid()) {
						if (ImGui::Selectable(plyr->get_name(), (selectedPlayer == plyr))) {
							selectedPlayer = plyr;
							g_SelectedPlayer = plyr->m_player_id;
						}
					}
				}
			}
		}
		else {
			ImGui::Text("No valid players!");
		}
		ImGui::ListBoxFooter();
	}*/


	//for (int i = 0; i < 32; ++i) {
	//if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {
	//	std::string heil_harald = /*PLAYER::GET_PLAYER_NAME*/Hooking::get_player_name(i);
	//	bool frnd;
	//	if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == i/* && USER::HAS_XFORCE(i)*/) {
	//		heil_harald.append(" ~w~[ME] ~r~[HOST]"/* + USER::XFORCE_TAG(i)*/);
	//		const char* cstr = heil_harald.c_str();
	//		if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
	//			Menu::MenuOptionint(cstr, blame_player) ? Features::Online::blamePlayer = i : NULL;
	//			Features::playerme = i;
	//			Features::onlineplayer = true;
	//			Blaming::blameplayer(Features::Online::blamePlayer);
	//		}
	//	}
	//}
	//}
//for (int i = 0; i < 32; ++i) {
//	if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i))) {

//char* cstr = /*PLAYER::GET_PLAYER_NAME*/Hooking::get_player_name(i);
//				if (NETWORK::NETWORK_IS_SIGNED_ONLINE() && PLAYER::IS_PLAYER_ONLINE() && NETWORK::NETWORK_GET_NUM_CONNECTED_PLAYERS() > 1) {
//					Menu::MenuOptionint(cstr, desync_player) ? Features::Online::blamePlayer = i : NULL;
//					Features::onlineplayer = true;
//					Blaming::blameplayer(Features::Online::blamePlayer);
//				}
//	}
//}
	/*selectedPlayer = (CNetGamePlayer*)Features::Online::selectedPlayer;

	auto cPed = selectedPlayer->m_player_info->m_ped;
	auto pPed = g_GameVariables->m_ConvertHandle(cPed);
	(*g_GameVariables->m_NetworkPlayerMgr)->RemovePlayer(selectedPlayer);
	WEAPON::REMOVE_ALL_PED_WEAPONS(pPed, true);*/

	//playerSelected = Features::Online::selectedPlayer;
	/*CNetGamePlayer* netPlayer = (CNetGamePlayer*)m_GetNetPlayer(fosp);*/
	/*auto player = g_GameVariables->m_GetNetPlayer(playerSelected);
	if (player != nullptr && playerSelected != PlayerID)
		(*g_GameVariables->m_NetworkPlayerMgr)->RemovePlayer(player);*/

		//for (int i = 0; i < (sizeof(Weaps) / 4); i++)
		//{
		//	Hooking::RemoveWeapons(Features::Online::selectedPlayer, Weaps[i]);
		//	//WEAPON::REMOVE_ALL_PED_WEAPONS(selectedPlayer, true);
		//}
}

//CNetworkPlayerMgr** m_NetworkPlayerMgr;
//typedef CNetworkPlayerMgr** CNetworkPlayerMgr2;
//using CNetworkPlayerMgr2 = CNetworkPlayerMgr**;
//CNetworkPlayerMgr2 m_NetworkPlayerMgr2;

//typedef void(GetNetPlayer)(CNetGamePlayer*(std::int8_t PlayerIndex));

//using NetworkPlayerMgr = int64_t(__fastcall*)(NetworkPlayerMgr** index);
//CNetworkPlayerMgr2 m_NetworkPlayerMgr2;
//using GetNetPlayer = int64_t(__fastcall*)(int32_t index);
//using GetNetPlayer = CNetGamePlayer*(std::int8_t PlayerIndex);
//GetNetPlayer m_GetNetPlayer;
//CNetworkPlayerMgr2 m_NetworkPlayerMgr;
//std::uint32_t g_SelectedPlayer{};
#define PlayerID PLAYER::PLAYER_ID()
#define pgppsifosp PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer)
#define fosp Features::Online::selectedPlayer
#define pm Features::playerme

//CNetGamePlayer* CNetworkPlayerMgr(int playerIndex)
//{
//	return getPlayerFromNetGame(playerIndex);
//}
// 

//#include <glib.h>


//class script_global
//{
//public:
//	explicit script_global(std::size_t index);
//
//	script_global at(std::ptrdiff_t index);
//	script_global at(std::ptrdiff_t index, std::size_t size);
//
//	template <typename T>
//	std::enable_if_t<std::is_pointer_v<T>, T> as()
//	{
//		return static_cast<T>(get());
//	}
//
//	template <typename T>
//	std::enable_if_t<std::is_lvalue_reference_v<T>, T> as()
//	{
//		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
//	}
//private:
//	void* get();
//	std::size_t m_index;
//};
//
//namespace Big
//{
//	script_global::script_global(std::size_t index) :
//		m_index(index)
//	{
//	}
//
//	script_global script_global::at(std::ptrdiff_t index)
//	{
//		return script_global(m_index + index);
//	}
//
//	script_global script_global::at(std::ptrdiff_t index, std::size_t size)
//	{
//		return script_global(m_index + 1 + (index * size));
//	}
//
//	void* script_global::get()
//	{
//		return g_GameVariables->m_GlobalBase[m_index >> 0x12 & 0x3F] + (m_index & 0x3FFFF);
//	}
//}

//script_global::script_global(std::size_t index) :
//	m_index(index)
//{
//}

//script_global script_global::at(std::ptrdiff_t index)
//{
//	return script_global(m_index + index);
//}
//
//script_global script_global::at(std::ptrdiff_t index, std::size_t size)
//{
//	return script_global(m_index + 1 + (index * size));
//}

//template <typename T>
//std::enable_if_t<std::is_pointer_v<T>, T> script_global::as() const
//{
//	return static_cast<T>(get());
//}
//
//template <typename T>
//std::enable_if_t<std::is_lvalue_reference_v<T>, T> script_global::as() const
//{
//	return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
//}
//template<typename T>
//std::enable_if_t<std::is_pointer_v<T>, T> script_global::as() const
//{
//	return static_cast<T>(get());
//}
//
//template<typename T>
//std::enable_if_t<std::is_lvalue_reference_v<T>, T> script_global::as() const
//{
//	return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
//}

void* script_global::get() const
{
	return g_GameVariables->m_script_globals[m_index >> 0x12 & 0x3F] + (m_index & 0x3FFFF);
}

//void* script_global::get() const
//{
//	return g_GameVariables->m_script_globals[m_index >> 0x12 & 0x3F] + (m_index & 0x3FFFF);
//}

inline auto player_global = script_global(2689224);
inline auto mechanic_global = script_global(2810701);
inline auto vehicle_global = script_global(1585853);
enum eVehicleFlags
{
	TRIGGER_SPAWN_TOGGLE = 1 << 0,
	DESTROYED = 1 << 1,
	HAS_INSURANCE = 1 << 2,
	_UNK0 = 1 << 3,
	IMPOUNDED = 1 << 6,
	_UNK1 = 1 << 10,
	SPAWN_AT_MORS_MUTUAL = 1 << 11,
	_UNK2 = 1 << 16
};

namespace mors_mutual
{
	inline bool fix_index(int veh_idx, bool spawn_veh = false)
	{
		bool can_be_fixed = misc::has_bits_set(
			vehicle_global.at(veh_idx, 142).at(103).as<int*>(),
			eVehicleFlags::DESTROYED | eVehicleFlags::HAS_INSURANCE
		);

		if (can_be_fixed)
		{
			misc::clear_bits(
				vehicle_global.at(veh_idx, 142).at(103).as<int*>(),
				eVehicleFlags::DESTROYED | eVehicleFlags::IMPOUNDED | eVehicleFlags::_UNK2
			);

			if (spawn_veh)
			{
				misc::set_bits(
					vehicle_global.at(veh_idx, 142).at(103).as<int*>(),
					eVehicleFlags::TRIGGER_SPAWN_TOGGLE | eVehicleFlags::SPAWN_AT_MORS_MUTUAL
				);
			}
		}
		return can_be_fixed;
	}

	inline int fix_all()
	{
		int fixed_count = 0;

		const int arr_size = *vehicle_global.as<int*>();
		for (int i = 0; i < arr_size; i++)
			if (fix_index(i, true))
				fixed_count++;

		return fixed_count;
	}
}

namespace self
{
	inline Ped ped;
	inline Player id;
	inline Vector3 pos;
	inline Vehicle veh;
}

namespace util
{
	int get_current_personal_vehicle(); // forward declare
	inline void despawn_current_personal_vehicle()
	{
		misc::clear_bits(
			vehicle_global.at(get_current_personal_vehicle(), 142).at(103).as<int*>(),
			eVehicleFlags::TRIGGER_SPAWN_TOGGLE
		);
	}

	inline int get_current_personal_vehicle()
	{
		return *script_global(2359296).at(0, 5559).at(675).at(2).as<int*>();
	}
}

namespace lester
{
	inline void off_radar(bool toggle)
	{
		*player_global.at(PLAYER::GET_PLAYER_INDEX(), 451).at(207).as<int*>() = toggle;
		*script_global(2703660).at(56).as<int*>() = NETWORK::GET_NETWORK_TIME() + 1;
	}
}
script_local::script_local(scrThread* thread, std::size_t index) :
	m_index(index), m_stack(thread->m_stack)
{
}
script_local::script_local(PVOID stack, std::size_t index) :
	m_index(index), m_stack(stack)
{
}

script_local script_local::at(std::ptrdiff_t index)
{
	return script_local(m_stack, m_index + index);
}

script_local script_local::at(std::ptrdiff_t index, std::size_t size)
{
	return script_local(m_stack, m_index + 1 + (index * size));
}

void* script_local::get()
{
	return reinterpret_cast<uintptr_t*>((uintptr_t)m_stack + (m_index * sizeof(uintptr_t)));
}

namespace mechanic
{
	inline void summon_vehicle_by_index(int veh_idx)
	{
		if (*mechanic_global.at(958).as<int*>() != -1)
			return g_notification_service->push_warning("Vehicle", "Mechanic is not ready to deliver a vehicle right now.");

		if (g2->vehicle.pv_teleport_into && self::veh)
			AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());

		// despawn current veh
		util::despawn_current_personal_vehicle();
		mors_mutual::fix_index(veh_idx);

		//script::get_current()->yield(100ms);

		*mechanic_global.at(924).as<int*>() = 1; // disable vehicle node distance check
		*mechanic_global.at(911).as<int*>() = 1; // tell freemode to spawn our vehicle
		*mechanic_global.at(961).as<int*>() = 0; // required
		*mechanic_global.at(958).as<int*>() = veh_idx;

		//script::get_current()->yield(100ms);

		//GtaThread* freemode_thread = gta_util::find_script_thread(RAGE_JOAAT("freemode"));
		//if (freemode_thread)
		//	*script_local(freemode_thread, 18196).at(176).as<int*>() = 0; // spawn vehicle instantly

		//// blocking call till vehicle is delivered
		//notify::busy_spinner("Delivering vehicle...", mechanic_global.at(958).as<int*>(), -1);

		//if (g->vehicle.pv_teleport_into)
		//	vehicle::bring(globals::get_personal_vehicle(), self::pos);
	}
}

bool Settings::m_RIDJoiner = 0;
int Settings::m_RIDJoinerTarget = 0;
void* OriginalPTR::RIDJOINPLAYER = nullptr;

void* OriginalPTR::m_OriginalWriteVehicleProximityMigrationDataNode = nullptr;
void* OriginalPTR::m_OriginalNetworkInfo = nullptr;
//void* m_OriginalRIDJoinHandle/*{}*/ = nullptr;
//void* m_OriginalRIDJoinFriends/*{}*/ = nullptr;
//void* m_OriginalRIDJoinFriendsV2/*{}*/ = nullptr;
void* m_OriginalChatReceive = nullptr;
void* m_OriginalSenderReceive = nullptr;
bool Settings::m_RIDInviter = 0;
int Settings::m_RIDInviterTarget = 0;

void* m_OriginalRIDInviteHandle/*{}*/ = nullptr;
void* m_OriginalRIDInviteFriends/*{}*/ = nullptr;


//std::unique_ptr<GameVariables1> g_GameVariables;
//std::unique_ptr<GameFunctions1> g_GameFunctions;

//GameVariables1* g_GameVariables;
//GameFunctions1* g_GameFunctions;

int64_t* m_RIDJoinFriendsHandler;
int64_t* m_RIDJoinFriendsFrontEndMenu/*{}*/ = 0;




char* CharKeyboardJoin2(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	WAIT(50);

	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return ""; //200
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

int ThunderHooks::ridjoin = 0;
int ThunderHooks::ridplayer = 0;
//std::string ThunderHooks::ridplayerstring = "";

//hook_g::g_HOOK g_;
//int hook_g::g_HOOK::m_RIDJoinerTarget2 = 0;
//bool hook_g::g_HOOK::m_RIDJoiner2 = 0;
//bool hook_g::g_HOOK::loadplayerlist2 = 0;


void ThunderHooks::RIDFunction()
{
	std::string joinsessions(CharKeyboardJoin2());
	//Hooking::JoinPatterns();
	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
	char* joinsession = new char[joinsessions.length() + 1];
	strcpy(joinsession, joinsessions.c_str());
	/*Settings::m_RIDJoinerTarget = atoi(joinsession);*/
	Settings::m_RIDJoinerTarget = stoi(joinsession);
	Menu::MenuLevelHandler::MoveMenu(SubMenus::mainmenu);
	WAIT(100);
	m_features::JoinByRockstarID(static_cast<uint64_t>(Settings::m_RIDJoinerTarget), 0);
	//if (m_RIDJoinFriendsFrontEndMenu)
	//{
	//	do
	//	{
	//		UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
	//		WAIT(1000);
	//		if (*m_RIDJoinFriendsFrontEndMenu)
	//		{
	//			int hash = 0xDA4858C1;//Join
	//			int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
	//			RIDJoinFriends(&ptr, &hash);
	//		}
	//	} while (!*m_RIDJoinFriendsFrontEndMenu);
	//}
}
//
//bool ThunderHooks::RIDJoinFriends(int64_t* a1, int* hash)
//	{
//		Settings::m_RIDJoiner = 1;
//		auto res = static_cast<decltype(&RIDJoinFriends)>(m_OriginalRIDJoinFriends)(a1, hash);
//		Settings::m_RIDJoiner = 0;
//		return res;
//	}

//bool ThunderHooks::RIDJoinFriendsV2(int* a1, __int64 a2, int* a3)
//{
//	//Settings::m_RIDJoiner = 1;
//	auto res = static_cast<decltype(&RIDJoinFriendsV2)>(m_OriginalRIDJoinFriendsV2)(a1, a2, a3);
//	//Settings::m_RIDJoiner = 0;
//	return res;
//}

//int64_t* ThunderHooks::RIDJoinHandle(int32_t friendIndex)
//	{
//		auto rid = static_cast<decltype(&RIDJoinHandle)>(m_OriginalRIDJoinHandle)(friendIndex);
//
//			if (Settings::m_RIDJoiner)
//			{
//				if (Settings::m_RIDJoinerTarget != 0)
//				{
//					*rid = Settings::m_RIDJoinerTarget;
//					Settings::m_RIDJoinerTarget = 0;
//				}
//			}
//		return rid;
//	}
//last 1.67
//  
//char ThunderHooks::RIDInviteHandle(int metric_manager, rlGamerHandle* handles, int count, rlSessionByGamerTaskResult* result, int unk, bool* success, int* state)
//{
//	auto rid2 = static_cast<decltype(&RIDInviteHandle)>(m_OriginalRIDInviteHandle)(metric_manager, handles, count, result, unk, success, state);
//
//	if (Settings::m_RIDInviter)
//	{
//		if (Settings::m_RIDInviterTarget != 0)
//		{
//			rid2 = Settings::m_RIDInviterTarget;
//			Settings::m_RIDInviterTarget = 0;
//		}
//	}
//	return rid2;
//}
//
//char ThunderHooks::RIDInviteFriends(void* presenceStruct, rlPresenceEventInviteAccepted* invite, int flags)
//{
//	Settings::m_RIDInviter = 1;
//	auto res2 = static_cast<decltype(&RIDInviteFriends)>(RIDInviteFriends)(presenceStruct, invite, flags);
//	Settings::m_RIDInviter = 0;
//	return res2;
//}




char* joinsessionp;
char* CharKeyboardJoin22(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	WAIT(50);
	std::string gnirts = std::to_string(Settings::m_RIDJoinerTarget);
	int lengthh = gnirts.length();
	maxInput = lengthh;
	joinsessionp = new char[gnirts.length() + 1];
	strcpy(joinsessionp, gnirts.c_str());
	defaultText = joinsessionp;
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return "0";
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}


//void ThunderHooks::RIDFunction2()
//{
//		std::string joinsessions(CharKeyboardJoin22());
//		Settings::m_RIDJoinerTarget = 0;
//		Hooking::JoinPatterns();
//		char* joinsession = new char[joinsessions.length() + 1];
//		strcpy(joinsession, joinsessions.c_str());
//		Settings::m_RIDJoinerTarget = atoi(joinsession);
//		notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//		WAIT(100);
//		if (m_RIDJoinFriendsFrontEndMenu)
//		{
//			do
//			{
//				UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//				WAIT(1000);
//				if (*m_RIDJoinFriendsFrontEndMenu)
//				{
//					int hash = 0xDA4858C1;//Join
//					int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//					//ThunderHooks::RIDJoinFriendsV2(reinterpret_cast<int*>(a1), reinterpret_cast<__int64>(hash), reinterpret_cast<int*>(a1));
//					//int ptrInt = static_cast<int>(ptr);
//					////Log::Msg("1");
//					//auto joinPTR = Memory::pattern("E8 44 96 C4 00");//89 8D 20 01 ? ? 48 8D 8D 30 01
//
//					//int64_t convertedResult;
//					//std::memcpy(&convertedResult, &joinPTR, sizeof(int64_t));
//					//*(int64_t*)convertedResult = ptr;
//
//									//auto joinPTR = Memory::pattern("48 89 5C 24 10 57 48 83 EC 40 8B 01 49 8B F8 48 8B DA 3D 84");//89 8D 20 01 ? ? 48 8D 8D 30 01
//				//int* a1, __int64 a2, int* a3
//					//Hooking::sub_7FF71339282C(ptr, hash, (int*)ptr/*, (int*)ptr*/);
//
//					/*DWORD64* d_location = (DWORD64*)joinPTR.count(1).get(0).get<DWORD64*>(0);
//					DWORD64 base_address = DWORD64(GetModuleHandleA(nullptr));
//					DWORD64 offset = reinterpret_cast<DWORD64>(d_location) - base_address;
//					DWORD64 dword64Value = static_cast<DWORD64>(ptr);
//					offset = dword64Value;*/
//
//					RIDJoinFriends(&ptr, &hash);
//					/*Log::Msg("2");
//					Hooking::RIDJoinFriendsV2(&ptrInt, static_cast<long long>(hash), &ptrInt);
//					Log::Msg("3");*/
//				}
//			} while (!*m_RIDJoinFriendsFrontEndMenu);
//		}
//}
//
//void ThunderHooks::RIDFunction3()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xBFCCA007;//spectate
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//
////JoinPlayer = 0xDA4858C1,
////Spectate = 0xBFCCA007,
////ViewProfile = 0xE24ACCA0,
////FriendRequest = 0xF1384765
//void ThunderHooks::RIDFunction4()
//{
//	notifyMap("Please Wait 10 seconde thanks");
//	std::string joinsessions(CharKeyboardJoin22());
//	if (joinsessions != "")
//	{
//	uint64_t value;
//	std::istringstream iss((char*)joinsessions.c_str());
//	iss >> value;
//	KickByRID(value);
//	//Settings::m_RIDJoinerTarget = 0;
//	//Hooking::JoinPatterns();
//	//char* joinsession = new char[joinsessions.length() + 1];
//	//strcpy(joinsession, joinsessions.c_str());
//	//Settings::m_RIDJoinerTarget = atoi(joinsession);
//	//notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	//WAIT(100);
//	//if (m_RIDJoinFriendsFrontEndMenu)
//	//{
//	//	do
//	//	{
//	//		UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//	//		WAIT(1000);
//	//		if (*m_RIDJoinFriendsFrontEndMenu)
//	//		{
//	//			int hash = 0xE24ACCA0; //View Profile
//	//			int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//	//			RIDJoinFriends(&ptr, &hash);
//	//		}
//	//	} while (!*m_RIDJoinFriendsFrontEndMenu);
//	//}
//	}
//}
//void ThunderHooks::RIDFunction5()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x265C0624; //Finish Intro
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction6()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xCC6AD7DA; //Spectate 2
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction7()
//{
//	notifyMap("Please Wait 10 seconde thanks");
//	std::string joinsessions(CharKeyboardJoin22());
//	if (joinsessions != "")
//	{
//		ridcrash(joinsessions);
//	}
//	//std::string joinsessions(CharKeyboardJoin22());
//	//Settings::m_RIDJoinerTarget = 0;
//	//Hooking::JoinPatterns();
//	//char* joinsession = new char[joinsessions.length() + 1];
//	//strcpy(joinsession, joinsessions.c_str());
//	//Settings::m_RIDJoinerTarget = atoi(joinsession);
//	//notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	//WAIT(100);
//	//if (m_RIDJoinFriendsFrontEndMenu)
//	//{
//	//	do
//	//	{
//	//		UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//	//		WAIT(1000);
//	//		if (*m_RIDJoinFriendsFrontEndMenu)
//	//		{
//	//			int hash = 0xF1384765; //FriendRequest
//	//			int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//	//			RIDJoinFriends(&ptr, &hash);
//	//		}
//	//	} while (!*m_RIDJoinFriendsFrontEndMenu);
//	//}
//}
//void ThunderHooks::RIDFunction8()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xF1DF07D9; //Report
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction9()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x1CC65C37; //Report 2
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
////void ThunderHooks::RIDFunction10()
////{
////	std::string joinsessions(CharKeyboardJoin22());
////	Settings::m_RIDJoinerTarget = 0;
////	Hooking::JoinPatterns();
////	char* joinsession = new char[joinsessions.length() + 1];
////	strcpy(joinsession, joinsessions.c_str());
////	Settings::m_RIDJoinerTarget = atoi(joinsession);
////	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
////	WAIT(100);
////	if (m_RIDJoinFriendsFrontEndMenu)
////	{
////		do
////		{
////			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
////			WAIT(1000);
////			if (*m_RIDJoinFriendsFrontEndMenu)
////			{
////				int hash = 0xE1E8D5DC; //Invite
////				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
////				RIDInviteFriends(&ptr, (rlPresenceEventInviteAccepted*)&hash, 0);
////			}
////		} while (!*m_RIDJoinFriendsFrontEndMenu);
////	}
////}
//void ThunderHooks::RIDFunction11()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xF806E810; //Finish Intro
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction12()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xEEC9B656; //Recommander
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction13()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x84643284; //Expulse
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction14()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xC6C189EA; //Expulse 2
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction15()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x298BCD1F; //Recommander 2
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction16()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = -498414432; //Profile
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction17()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xD892E535; //Profile
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction18()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x2636DDA8;
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//
//void ThunderHooks::RIDFunction19()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0x82623A4, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x7266E8B2;
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction20()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = -2073808252; //expulse
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction21()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x76CDEF83;
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction22()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = -237041703; //Signaler
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction23()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = -288770474; //Recommander
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction24()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = -960394774; //expulse
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction25()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = -247969947; //FriendsRequests
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//
//
//void ThunderHooks::RIDFunction26()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xCC5B6C80; //
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//
//void ThunderHooks::RIDFunction27()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xA57AF0C2; //
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction28()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x413B4109; //
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction29()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0x27C36328; //
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}
//void ThunderHooks::RIDFunction30()
//{
//	std::string joinsessions(CharKeyboardJoin22());
//	Settings::m_RIDJoinerTarget = 0;
//	Hooking::JoinPatterns();
//	char* joinsession = new char[joinsessions.length() + 1];
//	strcpy(joinsession, joinsessions.c_str());
//	Settings::m_RIDJoinerTarget = atoi(joinsession);
//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
//	WAIT(100);
//	if (m_RIDJoinFriendsFrontEndMenu)
//	{
//		do
//		{
//			UI::ACTIVATE_FRONTEND_MENU(0x5C13A9B2, 0, 2);
//			WAIT(1000);
//			if (*m_RIDJoinFriendsFrontEndMenu)
//			{
//				int hash = 0xE3A55663; //F1384765 Crash
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				RIDJoinFriends(&ptr, &hash);
//			}
//		} while (!*m_RIDJoinFriendsFrontEndMenu);
//	}
//}


void* IntPtr::ToPointer()
{
};
void WriteFloat(IntPtr address, float value)
{
	var data = *(float*)address.ToPointer();
	data = value;
}
float ReadFloat(IntPtr address)
{
	return *(float*)address.ToPointer();
}

fphandlingindex Hooking::handling_index;

fphandlingIndexOffset Hooking::handlingIndexOffsetInModelInfo;

fphandlinghash Hooking::handling_hash;


fpPedPoolAddress Hooking::PedPoolAddress;
fpObjectPoolAddress Hooking::ObjectPoolAddress;
fpEntityPoolAddress Hooking::EntityPoolAddress;
fpVehiclePoolAddress Hooking::VehiclePoolAddress;
fpPickupObjectPoolAddress Hooking::PickupObjectPoolAddress;

fpvehicleClassOffset Hooking::vehicleClassOffset;
fpmodelNum1 Hooking::modelNum1;
fpmodelNum2 Hooking::modelNum2;
fpmodelNum3 Hooking::modelNum3;
fpmodelNum4 Hooking::modelNum4;
fpmodelHashTable Hooking::modelHashTable;
fpmodelHashEntries Hooking::modelHashEntries;

patternglobal Hooking::globalpattern;
listblip Hooking::bliplist;
patternworld Hooking::worldpattern;

//void*					Hooking::m_onlineName;
fpGetLabelText          Hooking::GetLabelText = nullptr;


////CNetworkIncrementStatEvent          Hooking::NetworkIncrementStatEvent = nullptr;

static uint64_t												m_handling_index;
static eGameState* 											m_gameState;
static uint64_t												m_worldPtr;
static uint64_t												world_Ptr;
static BlipList*											m_blipList;
static Hooking::NativeRegistrationNew**						m_registrationTable;
static std::unordered_map<uint64_t, Hooking::NativeHandler>	m_handlerCache;
static std::vector<LPVOID>									m_hookedNative;
static __int64**                                            m_globalPtr;

//const int EVENT_COUNT = 85;
const int EVENT_COUNT = REVENT_EVENT_END;
static std::vector<void*> EventPtr;
static unsigned char EventRestore[REVENT_EVENT_END] = { 0 };
//static unsigned char EventRestore[EVENT_COUNT] = { };

//typedef char* (__stdcall* joinses)(__int64 a1, int a2);
//typedef __int64* (__stdcall* ridHk)(int rid);
//
//std::unique_ptr<int> g_rid = std::make_unique<int>(0);
//
//ridHk ridfunc;
//ridHk oRidHK;
//joinses joinsecfunc;
//joinses origJoinSes;

fpGetLabelText ogGetLabelText = nullptr;
const char* __cdecl hkGetLabelText(void* this_, const char* label)
{
	if (std::strcmp(label, "HUD_JOINING") == 0)
	{
		Features::onlineplayer = true;
		return "Loading Online With Thunder-Menu.com";
	}
	if (std::strcmp(label, "HUD_QUITTING") == 0)
	{
		Features::onlineplayer = false;
		return "Leave Online With Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_QUIT_MP") == 0)
	{
		Features::onlineplayer = false;
		return "Leave Online with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_ENTER_MP") == 0)
	{
		Features::onlineplayer = true;
		return "Join Online with Thunder-Menu.com";
	}	
	if (std::strcmp(label, "PM_EXIT_GAME") == 0)
	{
		Features::onlineplayer = false;
		return "Exit Game with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_GO") == 0)
	{
		Features::onlineplayer = true;
		return "GO Online with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_GOTO_STORE") == 0)
	{
		return "GOTO STORE with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_FRIEND_FM") == 0)
	{
		Features::onlineplayer = true;
		return "Join Friend with Thunder-Menu.com";
	}
	if (std::strcmp(label, "PM_FIND_SESS") == 0)
	{
		Features::onlineplayer = true;
		return "Find New Session with Thunder-Menu.com";
	}
	return ogGetLabelText(this_, label);
}


//bool Menu::Settings::enablerid = false;
//
//
//void* __stdcall HK_RID(int ind)
//{
//	if (Menu::Settings::enablerid)
//	{
//		auto rid = oRidHK(ind);
//		*rid = (__int64)*g_rid.get();
//		return (void*)rid;
//	}
//
//	return oRidHK(ind);
//}
//
//
//void Hooking::rid_main(int rid)
//{
//	g_rid = std::make_unique<int>(rid);
//	Menu::Settings::enablerid = false;
//}

//bool Hooking::loadmods = true;
/* Start Hooking */


//DWORD WINAPI ControlThread2(LPVOID lpParam)
//{
//	std::unique_ptr<NativeHooks> native_hook;
//	native_hook = std::make_unique<NativeHooks>();
//	return 0;
//}


void Hooking::Start(HMODULE hmoduleDLL)
{
	/*if (Hooking::loadmods) {*/
	Hooking::_hmoduleDLL = hmoduleDLL;
	Log::Init(hmoduleDLL);
	Log::chat(hmoduleDLL);

		FindPatterns();
		//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ControlThread2, hmoduleDLL, NULL, NULL);
		if (!InitializeHooks()) Cleanup();
	/*}*/
}
BOOL Hooking::InitializeHooks()
{
	BOOL returnVal = TRUE;
	/*if (Hooking::loadmods) {*/
		if (!iHook.Initialize()) {
			Log::Error("Failed to initialize InputHook");
			returnVal = FALSE;
		}
		if (MH_Initialize() != MH_OK) {
			Log::Error("MinHook failed to initialize");
			returnVal = FALSE;
		}
		if (!Hooking::HookNatives()) {

			Log::Error("Failed to initialize NativeHooks");
			returnVal = FALSE;
		}
	/*}*/
	return returnVal;
}

//bool	threeBytes::empty()
//{
//	bool	r = true;
//	for (int i = 0; i < 3; ++i)
//		if (this->byte[i] != 0)
//		{
//			r = false;
//			break;
//		}
//	return r;
//}

bool	twoBytes::empty()
{
	bool	r = true;
	for (int i = 0; i < 2; ++i)
		if (this->bytes[i] != 0)
		{
			r = false;
			break;
		}
	return r;
}

template <typename T>
bool Native(DWORD64 hash, LPVOID hookFunction, T** trampoline)
{
	/*if (Hooking::loadmods) {*/
		if (*reinterpret_cast<LPVOID*>(trampoline) != NULL)
			return true;
		auto originalFunction = Hooking::GetNativeHandler(hash);
		if (originalFunction != 0) {
			MH_STATUS createHookStatus = MH_CreateHook(originalFunction, hookFunction, reinterpret_cast<LPVOID*>(trampoline));
			if (((createHookStatus == MH_OK) || (createHookStatus == MH_ERROR_ALREADY_CREATED)) && (MH_EnableHook(originalFunction) == MH_OK))
			{
				m_hookedNative.push_back((LPVOID)originalFunction);
				DEBUGMSG("Hooked Native 0x%#p", hash);
				return true;
			}
		}
	/*}*/
	return false;
}


uint64_t CMetaData::m_begin = 0;
uint64_t CMetaData::m_end = 0;
DWORD CMetaData::m_size = 0;

uint64_t CMetaData::begin()
{
	return m_begin;
}
uint64_t CMetaData::end()
{
	return m_end;
}
DWORD CMetaData::size()
{
	return m_size;
}

void CMetaData::init()
{
	/*if (Hooking::loadmods) {*/
		if (m_begin && m_size)
			return;
		m_begin = (uint64_t)GetModuleHandleA(nullptr);
		const IMAGE_DOS_HEADER*	headerDos = (const IMAGE_DOS_HEADER*)m_begin;
		const IMAGE_NT_HEADERS*	headerNt = (const IMAGE_NT_HEADERS64*)((const BYTE*)headerDos + headerDos->e_lfanew);
		m_size = headerNt->OptionalHeader.SizeOfCode;
		m_end = m_begin + m_size;
	/*}*/
	return;
}

fpIsDLCPresent OG_IS_DLC_PRESENT = nullptr;

fpsIncrementStatEvent Increment_StatEvent = nullptr;

BOOL __cdecl HK_IS_DLC_PRESENT(std::uint32_t dlcHash)
{
	/*if (Hooking::loadmods) {*/
		static uint64_t	last = 0;
		uint64_t		cur = *Hooking::m_frameCount;
		//uint64_t* resultPointer;
		//uint64_t result = GetTickCount64();


		////DWORD ticks10 = GetTickCount64();
		//uint64_t milliseconds10 = result % 1000;

		//int getTimer10 = milliseconds10;
		//if (getTimer10 % 1 == 0)
		//{

		//	// Assign the address of 'result' to the pointer
		//	/*resultPointer = &result;*/
		//	resultPointer = &milliseconds10;

		//	uint64_t		cur = *resultPointer;
			//uint64_t		cur = *g_GameVariables->m_FrameCount;
			if (last != cur)
			{
				last = cur;
				Hooking::onTickInit();
			}
		//}
		/*else
			return OG_IS_DLC_PRESENT(dlcHash);*/
	/*}*/
	return 0;
		//return static_cast<decltype(&HK_IS_DLC_PRESENT)>(OG_IS_DLC_PRESENT)(dlcHash);
}

//fpIsDLCPresent	OG_IS_DLC_PRESENT = nullptr;
//BOOL __cdecl HK_IS_DLC_PRESENT(Hash dlcHash)
//{
//	static uint64_t	last = 0;
//	uint64_t		cur = *Hooking::m_frameCount;
//	if (last != cur)
//	{
//		last = cur;
//		Hooking::onTickInit();
//	}
//	else
//		return OG_IS_DLC_PRESENT();
//}

Hooking::NativeHandler ORIG_WAIT = NULL;
void* __cdecl MY_WAIT(NativeContext *cxt)
{
	/*if (Hooking::loadmods) {*/
		static int lastThread = 0;
		int threadId = SCRIPT::GET_ID_OF_THIS_THREAD();
		if (!lastThread)
		{
			char* name = SCRIPT::_GET_NAME_OF_THREAD(threadId);
			if (strcmp(name, "main_persistent") == 0)
			{
				lastThread = threadId;
				Log::Msg("Hooked Script NAME: %s ID: %i", name, threadId);
			}
		}
		if (threadId == lastThread)
		{
			Hooking::onTickInit();
		}
		ORIG_WAIT(cxt);
	/*}*/
	return cxt;
}

Hooking::NativeHandler  ORIG_NETWORK_SESSION_KICK_PLAYER = NULL;
void *__cdecl MY_NETWORK_SESSION_KICK_PLAYER(NativeContext* cxt)
{	
	//Player player = cxt->get_arg1<int>(0);
	Player player = cxt->get_arg<int>(0);
	//Player player = cxt->GetArgument<int>(0);
		if (player == Features::Online::selectedPlayer)
	{
		ORIG_NETWORK_SESSION_KICK_PLAYER(cxt);
	}
	return nullptr;
}


Hooking::NativeHandler  ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE = NULL;
void *__cdecl MY_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(NativeContext* cxt)
{
	//Player player = cxt->get_arg1<int>(0);
	Player player = cxt->get_arg<int>(0);
	//Player player = cxt->GetArgument<int>(0);
	if (player == Features::Online::selectedPlayer)
	{
		ORIG_NETWORK_ADD_PED_TO_SYNCHRONISED_SCENE(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler  ORIG_ATTACH_ENTITY_TO_ENTITY = NULL;
void *__cdecl MY_ATTACH_ENTITY_TO_ENTITY(NativeContext* cxt)
{
	Player player = cxt->get_arg<int>(0);
	//Player player = cxt->GetArgument<int>(0);
	if (player == Features::Online::selectedPlayer)
	{
		ORIG_ATTACH_ENTITY_TO_ENTITY(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS_IMMEDIATELY = NULL;
void *__cdecl MY_CLEAR_PED_TASKS_IMMEDIATELY(NativeContext *cxt)
{
	if (cxt->get_arg<Ped>(0) != PLAYER::PLAYER_PED_ID())
	//if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS_IMMEDIATELY(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_TASKS = NULL;
void *__cdecl MY_CLEAR_PED_TASKS(NativeContext *cxt)
{
	if (cxt->get_arg<Ped>(0) != PLAYER::PLAYER_PED_ID())
		//if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_TASKS(cxt);
	}

	return nullptr;
}

Hooking::NativeHandler ORIG_CLEAR_PED_SECONDARY_TASK = NULL;
void *__cdecl MY_CLEAR_PED_SECONDARY_TASK(NativeContext *cxt)
{
	if (cxt->get_arg<Ped>(0) != PLAYER::PLAYER_PED_ID())
		//if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLEAR_PED_SECONDARY_TASK(cxt);
	}
	return nullptr;
}

Hooking::NativeHandler ORIG_CLONE_PED = NULL;
void *__cdecl MY_CLONE_PED(NativeContext *cxt)
{
	if (cxt->get_arg<Ped>(0) != PLAYER::PLAYER_PED_ID())
		//if (cxt->GetArgument<Ped>(0) != PLAYER::PLAYER_PED_ID())
	{
		ORIG_CLONE_PED(cxt);
	}
	return nullptr;
}

void Hooking::patchEvent(RockstarEvent event, bool toggle) {
	if (EventPtr.size() == 0) return;
	static const BYTE ret = 0xC3;
	BYTE* ptr = (BYTE*)EventPtr[event];
	if (toggle) {
		if (EventRestore[event] == 0) EventRestore[event] = ptr[0];
		*ptr = ret;
	}
	else
	{
		if (EventRestore[event] != 0)
			* ptr = EventRestore[event];
	}
}

void Hooking::defuseEvent(RockstarEvent event, bool toggle)
{
	static const unsigned char retn = 0xC3;
	char* p = (char*)EventPtr[event];
	if (toggle)
	{
		if (EventRestore[event] == 0)
			EventRestore[event] = p[0];
		*p = retn;
	}
	else
	{
		if (EventRestore[event] != 0)
			* p = EventRestore[event];
	}
}

//void Hooking::ownedExplosionBypass(bool toggle)
//{
//	constexpr twoBytes patched = { 0x39, 0xDB };
//	/*constexpr twoBytes patched = { 0xE990, 0x9090 };*/
//	/*constexpr twoBytes restore = { 0x3B, 0xD8 };*/
//	constexpr twoBytes restore = { 0x3B, 0xF8 };
//	/*constexpr twoBytes restore = { 0x0F, 0x85 };*/
//	/*constexpr twoBytes patched = { 0xE990, 0x9090 };
//	constexpr twoBytes restore = { 0x850F, 0x0F74 };*/
//	if (CHooking::m_ownedExplosionBypass == nullptr) return;
//	*CHooking::m_ownedExplosionBypass = toggle ? patched : restore;
//}

//inline void patch_blame(bool toggle)
//{
//	*(unsigned short*)g_GameVariables->m_blame_explode = toggle ? 0xE990 : 0x850F;
//}
//
//int blame()
//{
//	g_GameVariables->m_blame_explode;
//	return 0;
//}

//* (BYTE*)m_addExplosionBypass = 0xEB; // Patch
//*(BYTE*)m_addExplosionBypass = 0x74; // Restore

void Hooking::ExplosionBypass(bool toggle)
{
	constexpr BYTE patched2 = { 0xEB };
	constexpr BYTE restore2 = { 0x74 };
	if (g_GameVariables->m_ExplosionBypass == nullptr)
		return;
	*(BYTE*)g_GameVariables->m_ExplosionBypass = toggle ? patched2 : restore2;
}

void Hooking::ownedExplosionBypass(bool toggle)
{
	constexpr twoBytes patched = { 0x39, 0xDB };
	constexpr twoBytes restore = { 0x3B, 0xD8 };
	if (CHooking::m_ownedExplosionBypass == nullptr) return;
	*CHooking::m_ownedExplosionBypass = toggle ? patched : restore;
	Hooking::ExplosionBypass(toggle);
}

//7FF7AB8EF3A6
// 7FF7A9170000
// 277 F3A6
// dword_7FF7AB00A394 = 1E9 A394
// byte_7FF7AB196288 = 202 6288
// 
//m_ExplosionBypass(Signature("48 8B F1 74 56").Scan().Add(3).As<PVOID>())
void AntiCheatBypass(bool b = true)
{
	Hooking::ownedExplosionBypass(b);
}

//int redirect() {
//	char redirectboolean2[1];
//	string redirectbooleanstring;
//	string redirect234;
//	redirect234 = getenv("appdata");
//	ifstream redirectboolean234;
//	redirectboolean234.open(redirect234 + "\\ThunderMenu\\redirect.Thunder");
//	redirectboolean234 >> redirectboolean2;
//	redirectbooleanstring = redirectboolean2;
//	bool redirectbooleanStatus;
//	if (redirectbooleanstring.length() == NULL) {
//		redirectbooleanStatus = false;
//	}
//	else {
//		redirectbooleanStatus = true;
//	}
//	return redirectbooleanStatus;
//}
bool Hooking::protect = false/* && redirect()*/;
bool Hooking::nonhostkicks = 0;
bool Hooking::noteleports = 0;
bool Hooking::nosoundspams = 0;
bool Hooking::ceokicks = 0;
bool Hooking::missionsend = 0;
bool Hooking::errortransaction = 0;
bool Hooking::bounties = 0;
bool Hooking::notifications = 0;
bool Hooking::wantedlevels = 0;
bool Hooking::dump = false;
void* m_OriginalGetEventData = nullptr;
bool Hooking::redirectAll = false;
bool checkresult = 0;
bool Hooking::GED(int eventGroup, int eventIndex, __int64* argStruct, int argStructSize)
{
	int argsstructs1 = (int)argStruct[1];
	int argsstructs0 = (int)argStruct[0];
	//char* name = Hooking::get_player_name(argsstructs1);
	char* name = PLAYER::GET_PLAYER_NAME(argsstructs1);
	/*char buf[30];*/
	char id[30];
	char sender[30];
	/*string redirectboolean1;
	redirectboolean1 = getenv("appdata");
	ofstream redirectboolean22(redirectboolean1 + "\\ThunderMenu\\redirect.Thunder");*/
	/*redirectboolean22 << "true";*/
		std::string	r = "**Invalid**";
	auto result = static_cast<decltype(&GED)>(m_OriginalGetEventData)(eventGroup, eventIndex, argStruct, argStructSize);
	if (Features::onlineplayer)
	{
		if (Hooking::redirectAll)
		{
	if ((name != (char*)r.c_str()))
	{
		if ((argsstructs0) != 0)
		{
			snprintf(id, sizeof(id), "ID: %i", argsstructs0);
			if ((id) != 0)
			{
				checkresult = 1;
			}
		}
	}
	if (id == 0)
	{
		checkresult = 0;
	}
	if ((argsstructs0) == 0)
		{
			checkresult = 0;
		}
	if ((name == (char*)r.c_str()))
	{
		checkresult = 0;
	}
	if (checkresult ? 1 : 0 != 0 ||
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_5 || //non-host-kick story
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_3 || //non-host-kick new-session
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_1 || //non-host-kick new-session
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_4 || //non-host-kick new-session
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_6 || //non-host-kick new-session
		result && Hooking::protect&& Hooking::nonhostkicks&& argStruct[0] == Kick_2 || //non-host-kick new-session
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_7 || //non-host-kick new-session
		result && Hooking::protect&& Hooking::nonhostkicks&& argStruct[0] == Crash1 || //Crash
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Crash2 || //Crash
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Crash3 || //Crash
		result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Crash4 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 936332224 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 839452587 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 589285912 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1271206400 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1271228480 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 589295040 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -351465844 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1701835040 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -800312339 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471469632 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1701825992 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 921195243 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1925046697 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1504695802 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1932558939 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471469632 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1269949700 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471472128 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471486144 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 548471420 || //Crash
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 915462795 || //NetworkKick
		//result && Hooking::protect&& Hooking::nonhostkicks&& argStruct[0] == -1256086189 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 601184540 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1066279757 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == BountyEvent || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 765043249 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1962078946 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 502129530 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 495813132 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -270957098 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1553386096 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 423750914 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1858744609 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -490124271 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 113023613 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 502129530 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -795380017 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1544474774 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -786817413 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1016286404 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1423341094 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 209861916 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1789200508 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1279400152 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -2056857136 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 230874362 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 290989781 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 879177392 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1247985006 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 421832664 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1770641691 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1789363239 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1408207199 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 243072129 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 564609617 || //NetworkKick
		//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 463008662 || //NetworkKick
		result && Hooking::protect && Hooking::ceokicks && argStruct[0] == CEOBan || //ceo-ban
		result && Hooking::protect && Hooking::ceokicks && argStruct[0] == CEOKick || //ceo-kick
		result && Hooking::protect && Hooking::nosoundspams && argStruct[0] == BountyEvent || //BountyEvent
		result && Hooking::protect && Hooking::noteleports && argStruct[0] == SendToLocation || //teleport
		result && Hooking::protect && Hooking::noteleports && argStruct[0] == MCTeleport || //MCTeleport
		result && Hooking::protect && Hooking::noteleports && argStruct[0] == TeleportToWarehouse || //SendToIsland
		result && Hooking::protect && Hooking::noteleports && argStruct[0] == eRemoteEvent::ScriptFreeze2 || //MCTeleport
		result && Hooking::protect && Hooking::noteleports && argStruct[0] == SendToIsland || //SendToIsland
		result && Hooking::protect && Hooking::noteleports && argStruct[0] == SendToApartment || //SendToIsland
		result && Hooking::protect && Hooking::missionsend && argStruct[0] == SendToJob2 || //SendToJob 
		result && Hooking::protect && Hooking::missionsend && argStruct[0] == SendToCutscene || //SendToCutscene
		//result && Hooking::protect && Hooking::missionsend && argStruct[0] == 1858712297 || //SendToCutscene
		result && Hooking::protect && Hooking::bounties && argStruct[0] == BountyEvent || //bounty
		result && Hooking::protect && Hooking::errortransaction && argStruct[0] == TransactionError || //transaction-error
		//result && Hooking::protect && Hooking::errortransaction && argStruct[0] == -1428749433 || //transaction-error
		result && Hooking::protect && Hooking::wantedlevels && argStruct[0] == ClearWantedLevel)
		//result && Hooking::protect && Hooking::wantedlevels && argStruct[0] == ClearWantedLevel || //clear-wanted-level
		//result && Hooking::protect && Hooking::notifications && argStruct[0] == 548471420) //show-banner
	{
		if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(argsstructs1) != PLAYER::PLAYER_PED_ID()) {
			unsigned int Bit = (1 << argStruct[1]);
			if ((argsstructs0) != 0)
			{
				if ((name != (char*)r.c_str()))
				{
					Hooking::trigger_script_event(1, argStruct, argStructSize, Bit, argsstructs1);
					snprintf(id, sizeof(id), "ID: %i", argsstructs0);
					snprintf(sender, sizeof(sender), "Sender: %s", name);
					protectionNotify(name, "Blocked & Redirected", sender);
					protectionNotify(id, "Blocked & Redirected", sender);
					Log::Msg("===============================");
					Log::Msg("Blocked event sent by %s", name);
					Log::Msg("Blocked event sent by %s", id);
					Log::Msg("Script event group: %i", eventGroup);
					Log::Msg("Script event index: %i", eventIndex);
					Log::Msg("Script event argcount: %i", argStructSize);


					for (int i = 0; i < eventIndex; i++)
					{
						std::string newline = "\n";
						std::string argcount = std::to_string(argStruct[i]) + ": % i";
						std::string eventcount3 = "Script eventIndex_argStruct " + std::to_string(i);
						std::string eventcount2 = eventcount3 + newline;
						std::string eventcount1 = eventcount2 + argcount;
						Log::Msg((char*)eventcount1.c_str(), std::to_string(argStruct[i]));
					}

					for (int i = 0; i < argStructSize; i++)
					{
						std::string newline = "\n";
						std::string argcount = std::to_string(argStruct[i]) + ": % i";
						std::string eventcount3 = "Script argStructSize_argStruct " + std::to_string(i);
						std::string eventcount2 = eventcount3 + newline;
						std::string eventcount1 = eventcount2 + argcount;
						Log::Msg((char*)eventcount1.c_str(), std::to_string(argStruct[i]));
					}

					for (std::uint32_t i = 0; i < argStructSize; ++i) {
						Log::Msg("Script event argStructSize32 [%u] : %i", argStruct[i]);
					}
					for (std::uint32_t i = 0; i < eventIndex; ++i) {
						Log::Msg("Script event eventIndex32 [%u] : %i", argStruct[i]);
					}
				}
			}
			//Log::Msg("-------------------------------");
			//Log::Msg("Trigger script event");
		//	for (std::uint32_t i = 0; i < argStructSize; ++i) {
				//Log::Msg("Hooking::tse(1, %i,  %i, Bit);", argStruct[i], argStructSize);
			////linkhttps://www.unknowncheats.me/forum/grand-theft-auto-v/144028-gta-reversal-thread-218.html
			//}
		}
		return false;
	}
	else if (result && Hooking::dump) // checks if theres a result and that dump is true if so then logs the events
	{
		Log::Msg("===============================");
		Log::Msg("Logged event");
		Log::Msg("Script event group: %i", eventGroup);
		Log::Msg("Script event index: %i", eventIndex);
		Log::Msg("Script event argcount: %i", argStructSize);

		for (std::uint32_t i = 0; i << argStructSize; ++i) {
			Log::Msg("Script event args32 [%u] : %i", argStruct[i]);
		}
		return result;
	}
		}
		if (Hooking::protect)
		{
		if (result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_5 || //non-host-kick story
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_3 || //non-host-kick new-session
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_1 || //non-host-kick new-session
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_4 || //non-host-kick new-session
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_6 || //non-host-kick new-session
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_2 || //non-host-kick new-session
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Kick_7 || //non-host-kick new-session
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Crash1 || //Crash
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Crash2 || //Crash
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Crash3 || //Crash
			result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == Crash4 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 936332224 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 839452587 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 589285912 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1271206400 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1271228480 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 589295040 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -351465844 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1701835040 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -800312339 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471469632 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1701825992 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 921195243 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1925046697 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1504695802 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1932558939 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471469632 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1269949700 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471472128 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 471486144 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 548471420 || //Crash
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 915462795 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1256086189 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 601184540 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1066279757 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == BountyEvent || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 765043249 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1962078946 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 502129530 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 495813132 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -270957098 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1553386096 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 423750914 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1858744609 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -490124271 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 113023613 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 502129530 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -795380017 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1544474774 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -786817413 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1016286404 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1423341094 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 209861916 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1789200508 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1279400152 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -2056857136 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 230874362 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 290989781 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 879177392 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1247985006 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 421832664 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == -1770641691 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1789363239 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 1408207199 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 243072129 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 564609617 || //NetworkKick
			//result && Hooking::protect && Hooking::nonhostkicks && argStruct[0] == 463008662 || //NetworkKick
			result && Hooking::protect && Hooking::ceokicks && argStruct[0] == CEOBan || //ceo-ban
			result && Hooking::protect && Hooking::ceokicks && argStruct[0] == CEOKick || //ceo-kick
			result && Hooking::protect && Hooking::nosoundspams && argStruct[0] == BountyEvent || //BountyEvent
			result && Hooking::protect && Hooking::noteleports && argStruct[0] == SendToLocation || //teleport
			result && Hooking::protect && Hooking::noteleports && argStruct[0] == SendToApartment || //teleport
			result && Hooking::protect && Hooking::noteleports && argStruct[0] == SendToIsland || //SendToIsland
			result && Hooking::protect && Hooking::noteleports && argStruct[0] == MCTeleport || //MCTeleport
			result && Hooking::protect && Hooking::missionsend && argStruct[0] == SendToJob2 || //SendToJob 
			result && Hooking::protect && Hooking::missionsend && argStruct[0] == SendToCutscene || //SendToCutscene
			result && Hooking::protect && Hooking::bounties && argStruct[0] == BountyEvent || //bounty
			result && Hooking::protect && Hooking::errortransaction && argStruct[0] == TransactionError || //transaction-error
			//result && Hooking::protect && Hooking::errortransaction && argStruct[0] == -1428749433 || //transaction-error
			result && Hooking::protect && Hooking::wantedlevels && argStruct[0] == ClearWantedLevel) //clear-wanted-level
			//result && Hooking::protect && Hooking::wantedlevels && argStruct[0] == ClearWantedLevel || //clear-wanted-level
			//result && Hooking::protect && Hooking::notifications && argStruct[0] == -795380017) //show-banner
		{
			if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(argsstructs1) != PLAYER::PLAYER_PED_ID()) {
				unsigned int Bit = (1 << argStruct[1]);
				if ((argsstructs0) != 0)
				{
					if ((name != (char*)r.c_str()))
					{
						Hooking::trigger_script_event(1, argStruct, argStructSize, Bit, argsstructs1);
						snprintf(id, sizeof(id), "ID: %i", argsstructs0);
						snprintf(sender, sizeof(sender), "Sender: %s", name);
						protectionNotify(name, "Blocked & Redirected", sender);
						protectionNotify(id, "Blocked & Redirected", sender);
						Log::Msg("===============================");
						Log::Msg("Blocked event sent by %s", name);
						Log::Msg("Blocked event sent by %s", id);
						Log::Msg("Script event group: %i", eventGroup);
						Log::Msg("Script event index: %i", eventIndex);
						Log::Msg("Script event argcount: %i", argStructSize);
						for (int i = 0; i < eventIndex; i++)
						{
							std::string newline = "\n";
							std::string argcount = std::to_string(argStruct[i]) + ": % i";
							std::string eventcount3 = "Script eventIndex_argStruct " + std::to_string(i);
							std::string eventcount2 = eventcount3 + newline;
							std::string eventcount1 = eventcount2 + argcount;
							Log::Msg((char*)eventcount1.c_str(), std::to_string(argStruct[i]));
						}

						for (int i = 0; i < argStructSize; i++)
						{
							std::string newline = "\n";
							std::string argcount = std::to_string(argStruct[i]) + ": % i";
							std::string eventcount3 = "Script argStructSize_argStruct " + std::to_string(i);
							std::string eventcount2 = eventcount3 + newline;
							std::string eventcount1 = eventcount2 + argcount;
							Log::Msg((char*)eventcount1.c_str(), std::to_string(argStruct[i]));
						}
						for (std::uint32_t i = 0; i < argStructSize; ++i) {
							Log::Msg("Script event args32 [%u] : %i", argStruct[i]);
						}
						for (std::uint32_t i = 0; i < eventIndex; ++i) {
							Log::Msg("Script event eventIndex32 [%u] : %i", argStruct[i]);
						}
					}
				}
				//Log::Msg("-------------------------------");
				//Log::Msg("Trigger script event");
			//	for (std::uint32_t i = 0; i < argStructSize; ++i) {
					//Log::Msg("Hooking::tse(1, %i,  %i, Bit);", argStruct[i], argStructSize);
				////linkhttps://www.unknowncheats.me/forum/grand-theft-auto-v/144028-gta-reversal-thread-218.html
				//}
			}
			return false;
		}
		else if (result && Hooking::dump) // checks if theres a result and that dump is true if so then logs the events
		{
			Log::Msg("===============================");
			Log::Msg("Logged event");
			Log::Msg("Script event group: %i", eventGroup);
			Log::Msg("Script event index: %i", eventIndex);
			Log::Msg("Script event argcount: %i", argStructSize);
			for (std::uint32_t i = 0; i << argStructSize; ++i) {
				Log::Msg("Script event args [%u] : %i", argStruct[i]);
			}
			return result;
		}
		}
	}
	/*else
	{ 
		redirectboolean22 << "";
	}*/
	/*return 0;*/
	return result;
}

//int redirects() {
//	char redirectbooleans[1];
//	std::string redirectbooleanstrings;
//	std::string redirects;
//	redirects = getenv("appdata");
//	std::ifstream sredirectbooleans;
//	sredirectbooleans.open(redirects + "\\ThunderMenu\\redirects.Thunder");
//	sredirectbooleans >> redirectbooleans;
//	redirectbooleanstrings = redirectbooleans;
//	bool redirectbooleanStatuss;
//	if (redirectbooleanstrings.length() == NULL) {
//		redirectbooleanStatuss = false;
//	}
//	else {
//		redirectbooleanStatuss = true;
//	}
//	return redirectbooleanStatuss;
//}
//bool Hooking::protectsr = true && redirects() ;
//
//CNetworkIncrementStatEvent OF_NetworkIncrementStatEvent = nullptr;
//BOOL __cdecl HK_NetworkIncrementStatEvent(int64_t a1_Event, int64_t a2_sender)
//{
//	std::string redirectbooleans;
//	redirectbooleans = getenv("appdata");
//	std::ofstream sredirectbooleanss(redirectbooleans + "\\ThunderMenu\\redirects.Thunder");
//	if (Hooking::protectsr == true)
//	{
//		sredirectbooleanss << "true";
//		BYTE sender_ID = *reinterpret_cast<BYTE*>(a2_sender + 45);
//		if (((int)sender_ID < 32) && (0 <= (int)sender_ID))
//		{
//			char* sender_name = Hooking::get_player_name((int)sender_ID);
//			unsigned int v2 = *reinterpret_cast<unsigned int*>(a1_Event + 48);
//			//Log::Msg("[NISEvent] sender_name  %s  event %llu", sender_name, v2);
//			if (v2 == 1837041753 ||//MPPLY_EXPLOITS
//				v2 == -872610652 ||//MPPLY_GAME_EXPLOITS
//				v2 == -1619412469 ||//MPPLY_EXPLOITS 
//				v2 == 242250445 ||//MPPLY_VC_HATE
//				v2 == 1982830996 ||//MPPLY_TC_ANNOYINGME
//				v2 == -1222453568)//MPPLY_TC_HATE
//			{
//				Log::Msg("[NISEvent] return true   sender_name  %s  event %llu", sender_name, v2);
//				protectionNotify(sender_name, "Blocked & Redirected", v2);
//				return true;
//			}
//		}
//	}
//	if (!Hooking::protectsr)
//	{
//		sredirectbooleanss << " ";
//	}
//	return OF_NetworkIncrementStatEvent(a1_Event, a2_sender);
//}
bool Hooking::geteventdata = false;

//int Join = 0;
//bool Joiner;
//void* Hooking::m_OriginalJoinPlayer = {};
//int Hooks::JoinPlayer(__int64 a1, int a2, __int64* a3, int a4) {
//	if (Joiner)
//	{
//		if (a3 == 0)
//		{
//			return static_cast<decltype(&JoinPlayer)>(g_Hooking->m_OriginalJoinPlayer)(a1, a2, a3, a4);
//		}
//		*a3 = Join;
//
//	}
//	return static_cast<decltype(&JoinPlayer)>(g_Hooking->m_OriginalJoinPlayer)(a1, a2, a3, a4);
//}

void* m_OriginalDisableErrorScreen{};
bool ThunderHooks::simple_drop_g_SelectedPlayer = 0;

void __cdecl ThunderHooks::DisableErrorScreen(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background)
{
	if (SCRIPT::GET_HASH_OF_THIS_SCRIPT_NAME() == $("shop_controller") && ThunderHooks::simple_drop_g_SelectedPlayer)
	{
		return;
	}
	return static_cast<decltype(&DisableErrorScreen)>(m_OriginalDisableErrorScreen/*Hooking::DisableErrorScreen*/)(entryHeader, entryLine1, instructionalKey, entryLine2, p4, p5, p6, p7, background);
}

//fpRIDJoinFriends*     ogRIDJoinFriends = nullptr;
//fpRIDJoinHandle*     ogRIDJoinHandle = nullptr;

std::string GetSecondWord3(std::string a1)
{
	size_t pos = a1.find_last_of(' '); //last
	return a1.substr(pos + 1);
}
std::string GetSecondWord(std::string a1)
{
	std::string s = a1;

	size_t pos1 = s.find(' ');
	size_t pos2 = s.find(' ', pos1 + 1);
	return s.substr(pos1 + 1, pos2 - pos1);
}

bool CommandCheck(std::string str, std::string check)
{
	for (int i = 0; i < str.size(); i++)
		str[i] = tolower(str[i]);

	std::size_t found = str.find_first_of(' ');
	if (found != std::string::npos)
	{
		if (str.substr(0, found) == check)
		{
			str = str.substr(found + 1, str.size());
			return true;
		}
	}
	else
	{
		if (str == check)
			return true;
	}
	return false;
}

//int playername = 0;
//
//int getplayer(const char* nameplayer)
//{
//	for (int i = 0; i < 32; i++)
//	{
//		if (nameplayer == PLAYER::GET_PLAYER_NAME(i))
//		{
//			playername = i;
//		}
//	}
//	return playername;
//}
std::string previous_chatMessage = "";
bool GiveVehicle::norepeat = 0;
bool GiveVehicle::activatemoney = 0;
bool GiveVehicle::activatebike = 0;
bool GiveVehicle::activatebounty = 0;
bool GiveVehicle::activateland = 0;
bool GiveVehicle::activatekick = 0;
bool GiveVehicle::activatevehicle = 0;
bool GiveVehicle::activatecrash = 0;
bool GiveVehicle::activateblame = 0;
bool GiveVehicle::activateblametoggle = 0;
bool GiveVehicle::kickhost = 0;
int GiveVehicle::hostkick()
{
	for (int i = 0; i < 32; i++)
	{
		if (i != Features::playerme)
		{
			if (m_features::IsHost(i))
			{
				for (int zi = 0; zi < 25; zi++)
				{
					unsigned int playerBit = (1 << i);
					int splay = i;
					uint64_t sssplay = (uint64_t)splay;
					int bigshashs = atoi(HashKick[zi]);
					uint64_t bigshash = (uint64_t)bigshashs;
					uint64_t kicksp[4] = { bigshash, sssplay, 0, 0 }; ///*994306218*/423635655
					RtlSecureZeroMemory(kicksp, sizeof(kicksp));
					kicksp[0] = bigshash;
					kicksp[1] = sssplay;
					kicksp[2] = 0;
					kicksp[3] = 0;
					Hooking::trigger_script_event(1, &kicksp[0], 4, playerBit, bigshashs);
				}
			}
			if (m_features::IsScriptHost(i))
			{
				for (int zi = 0; zi < 25; zi++)
				{
					unsigned int playerBit = (1 << i);
					int splay = i;
					uint64_t sssplay = (uint64_t)splay;
					int bigshashs = atoi(HashKick[zi]);
					uint64_t bigshash = (uint64_t)bigshashs;
					uint64_t kicksp[4] = { bigshash, sssplay, 0, 0 }; ///*994306218*/423635655
					RtlSecureZeroMemory(kicksp, sizeof(kicksp));
					kicksp[0] = bigshash;
					kicksp[1] = sssplay;
					kicksp[2] = 0;
					kicksp[3] = 0;
					Hooking::trigger_script_event(1, &kicksp[0], 4, playerBit, bigshashs);
				}
			}
		}
	}
	return 0;
}
std::string GetFirstWord1(std::string a1)
{
	size_t pos = a1.find(' '); //last
	return a1.substr(pos + 1);
}
std::string GetSecondWord2(std::string a1)
{
	size_t pos = a1.find(' '); //last
	return a1.substr(pos + 1);
}
std::string GetThirdWord3(std::string a1)
{
	size_t pos = a1.find_last_of(' '); //last
	return a1.substr(pos + 1);
}

std::string GiveVehicle::WordBlame1 = "";
std::string GiveVehicle::WordBlame2 = "";
std::string GiveVehicle::WordBlame3 = "";

std::string GiveVehicle::BlameWord1[] = { "" };
std::string GiveVehicle::BlameWord2[] = { "" };
std::string GiveVehicle::BlameWord3[] = { "" };

std::string GiveVehicle::MoneyWord1[] = { "" };
std::string GiveVehicle::MoneyWord2[] = { "" };
std::string GiveVehicle::MoneyWord3[] = { "" };

std::string GiveVehicle::WordMoney1 = "";
std::string GiveVehicle::WordMoney2 = "";
std::string GiveVehicle::WordMoney3 = "";

std::string  GiveVehicle::MoneyWord[] = { "" };
std::string StopRepeat001 = "";
std::string StopRepeat002 = "";
std::string StopRepeat003 = "";
std::string StopRepeat004 = "";
std::string StopRepeat005 = "";
std::string StopRepeat006 = "";
std::string StopRepeat007 = "";
std::string StopRepeat008 = "";
std::string StopRepeat009 = "";
std::string StopRepeat01 = "";
std::string StopRepeat02 = "";
std::string StopRepeat03 = "";
std::string StopRepeat04 = "";
std::string StopRepeat05 = "";
std::string StopRepeat06 = "";
std::string StopRepeat07 = "";
std::string StopRepeat08 = "";
std::string StopRepeat09 = "";
std::string StopRepeat1 = "";
std::string StopRepeat2 = "";
std::string StopRepeat3 = "";
std::string StopRepeat4 = "";
std::string StopRepeat5 = "";
std::string StopRepeat6 = "";
std::string StopRepeat7 = "";
std::string StopRepeat8 = "";
std::string StopRepeat9 = "";
bool SpamRepeatbool[32] = {};
int SpamRepeatint1;
int SpamRepeatint2;
//int SpamRepeatint3;
int numrepeat = 0;

bool notrepeat = 0;
std::string nomore[] = { "" };

int playerwriter;
std::string player_Names = "";

int maxrepeat = 3;
int net_playerm_player_id; 
//int dontrepeat(std::string playerNames)
//{
//	if (notrepeat)
//	{
//		Hash playerHash = HASH::GET_HASH_KEY(playerNames);
//		int Hashplayer = reinterpret_cast<int>((char*)playerHash);
//		for (int i = 0; i < 32; i++)
//		{
//			nomore[i] = PLAYER::GET_PLAYER_NAME(i);
//			Hash hsah = HASH::GET_HASH_KEY(nomore[i]);
//			int hex1 = reinterpret_cast<int>((char*)hsah);
//			if (hex1 != 0) {
//				if (Hashplayer == hex1) {
//					Log::Msg("+++++++++++++++");
//					playerwriter = i;
//					Log::Msg((char*)nomore[i].c_str());
//					Log::Msg((char*)std::to_string(playerwriter).c_str());
//					Log::Msg("Player Chat");
//					/*getplayeridvoidm3();*/
//					/*GiveVehicle::boolmoney = 1;*/
//					Log::Msg("Anti Spam Event Send");
//					notrepeat = 0;
//				}
//			}
//		}
//	}
//	return 0;
//}

int errorsendInt = 0;
bool Features::errorsend[32] = {};
//void errorsendnumberplayer()
//{
//	for (int i = 0; i < 32; i++)
//	{
//		if (errorsendInt == i)
//		{
//			Features::errorsend[i] = !Features::errorsend[i];
//		}
//		if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
//		{
//		}
//		else {
//			Features::errorsend[i] = 0;
//		}
//	}
//}

bool antispamming[32] = { 0 };

int GiveVehicle::transactionerror()
{
	DWORD ticks10 = GetTickCount64();
	DWORD milliseconds10 = ticks10 % 1000;
	ticks10 /= 1000;
	DWORD seconds10 = ticks10 % 60;
	int getTimer10 = seconds10;
	if (getTimer10 % 1 == 0)
	{
		for (int i = 0; i < 32; i++)
		{
			if (Features::errorsend[i])
			{
				if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
				{
					unsigned int playerBit = (1 << i);
					auto var0 = globalHandle(1894573 + 1 + i * 608 + 510).As<std::uint64_t>();
					auto var1 = globalHandle(BountyTransaction + 9).As<std::uint64_t>();
					int ssplay = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
					int zero0 = TransactionError;
					int numberzero = 0;
					int tenk = 10000;
					uint64_t zerofoo = (uint64_t)numberzero;
					uint64_t kten = (uint64_t)tenk;
					uint64_t sssplay = (uint64_t)ssplay;
					uint64_t foozero = (uint64_t)zero0;
					uint64_t errortransaction[8] = { foozero, sssplay, kten, zerofoo, zerofoo, var0, var1, var1 };
					RtlSecureZeroMemory(errortransaction, sizeof(errortransaction));
					errortransaction[0] = foozero;
					errortransaction[1] = sssplay;
					errortransaction[2] = kten;
					errortransaction[3] = zerofoo;
					errortransaction[4] = zerofoo;
					errortransaction[5] = var0;
					errortransaction[6] = var1;
					errortransaction[7] = var1;
					Hooking::trigger_script_event(1, &errortransaction[0], 8, playerBit, (int)TransactionError);
				}
				else {
					Features::errorsend[i] = 0;
				}
			}
		}
	}
	return 0;
}

#include <iostream>
#include <cstdint>
#include <limits>

int convertUint64ToInt(std::uint64_t value) {
	return static_cast<int>(value); // Conversion directe sans vérification
}

bool GiveVehicle::antispambool = 0;
int GiveVehicle::antispam()
{
	std::uint64_t crash_args_1[3] = { Crash1, net_playerm_player_id, 1 };
	std::uint64_t crash_args_2[3] = { 879177392, net_playerm_player_id, 1 };
	std::uint64_t crash_args_3[3] = { SendToApartment, net_playerm_player_id, 1 };
	std::uint64_t crash_args_4[3] = { Crash2, net_playerm_player_id, 1 };
	std::uint64_t crash_args_5[3] = { Crash3, net_playerm_player_id, 1 };
	std::uint64_t crash_args_6[3] = { Crash1, net_playerm_player_id, 1 };
	std::uint64_t crash_args_7[10] = { Crash1, net_playerm_player_id, 0,  1229879414 , 1742796505 , -1794944145 , -480124848 , 439776191 , -2062014584 , 2120444344 };
	std::uint64_t crash_args_8[12] = { 879177392, net_playerm_player_id, -72614, 63007, 59027, -12012, -26996, 33398, 33398, 63007, -72614, 59027 };
	std::uint64_t crash_args_9[46] = { Crash1, net_playerm_player_id, -2147483647, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534 };
	std::uint64_t crash_args_10[46] = { 879177392, net_playerm_player_id, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 2147483647, 65534, 65534,65534, 65534, 65534, 65534, 2147483647, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, 65534, -2147483647, 65534, 65534, 65534, -2147483647 };
	std::uint64_t crash_args_11[46] = { 548471420, net_playerm_player_id, Crash1, -989654618, 879177392, -2113023004, 548471420, 1249026189, 1033875141, 315658550, Crash3, -601625146 - 2043109205, -989654618, 879177392, -2113023004, 548471420, 1249026189, 1033875141, 315658550, -877212109, -601625146 - 2043109205, -989654618, 879177392, -2113023004, 548471420, 1249026189, 1033875141, 315658550, Crash3, -601625146 - 2043109205, -989654618, 879177392, -1881357102, 548471420, 1249026189, 1033875141, 315658550, Crash3, -601625146 };
	std::uint64_t crash_args_12[46] = { 879177392, net_playerm_player_id, 868904806, 262276366, -747991709, 1545080914, -51510646, 1790326295, 389113600, -617567498, -601391132, -564503258, -601625146 - 2043109205, -989654618, 879177392, -2113023004, 548471420, 1249026189, 1033875141, 315658550, -601625146 - 2043109205, -989654618, 879177392, -2113023004, 548471420, 1249026189, 1033875141, 315658550 };
	
	int intValue1 = 0;
	int intValue2 = 0;
	int intValue3 = 0;
	int intValue4 = 0;
	int intValue5 = 0;
	int intValue6 = 0;
	int intValue7 = 0;
	int intValue8 = 0;
	int intValue9 = 0;
	int intValue10 = 0;
	int intValue11 = 0;
	int intValue12 = 0;

	for (size_t i = 0; i < 3; ++i) {
		intValue1 = convertUint64ToInt(crash_args_1[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue2 = convertUint64ToInt(crash_args_2[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue3 = convertUint64ToInt(crash_args_3[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue4 = convertUint64ToInt(crash_args_4[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue5 = convertUint64ToInt(crash_args_5[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue6 = convertUint64ToInt(crash_args_6[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue7 = convertUint64ToInt(crash_args_7[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue8 = convertUint64ToInt(crash_args_8[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue9 = convertUint64ToInt(crash_args_9[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue10 = convertUint64ToInt(crash_args_10[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue11 = convertUint64ToInt(crash_args_11[i]);
	}
	for (size_t i = 0; i < 3; ++i) {
		intValue12 = convertUint64ToInt(crash_args_12[i]);
	}

	Hooking::trigger_script_event(1, crash_args_1, 3, 1 << net_playerm_player_id, intValue1);
	Hooking::trigger_script_event(1, crash_args_2, 3, 1 << net_playerm_player_id, intValue2);
	Hooking::trigger_script_event(1, crash_args_3, 3, 1 << net_playerm_player_id, intValue3);
	Hooking::trigger_script_event(1, crash_args_4, 3, 1 << net_playerm_player_id, intValue4);
	Hooking::trigger_script_event(1, crash_args_5, 3, 1 << net_playerm_player_id, intValue5);
	Hooking::trigger_script_event(1, crash_args_6, 3, 1 << net_playerm_player_id, intValue6);
	Hooking::trigger_script_event(1, crash_args_7, 10, 1 << net_playerm_player_id, intValue7);
	Hooking::trigger_script_event(1, crash_args_8, 12, 1 << net_playerm_player_id, intValue8);
	Hooking::trigger_script_event(1, crash_args_9, 46, 1 << net_playerm_player_id, intValue9);
	Hooking::trigger_script_event(1, crash_args_10, 46, 1 << net_playerm_player_id, intValue10);
	Hooking::trigger_script_event(1, crash_args_11, 46, 1 << net_playerm_player_id, intValue11);
	Hooking::trigger_script_event(1, crash_args_12, 46, 1 << net_playerm_player_id, intValue12);
	//Features::kick_sp(net_playerm_player_id);
	GiveVehicle::antispambool = 0;
	Log::Msg("Anti Spam");
	if (!Features::errorsend[net_playerm_player_id])
	Features::errorsend[net_playerm_player_id] = !Features::errorsend[net_playerm_player_id];
	GiveVehicle::transactionerror();
	//BreakupKick(net_playerm_player_id);
	Features::nonhostkickns(net_playerm_player_id);
	Log::Msg("Event Send Complet");
	return 0;
}

int StringToInteger3(string NumberAsString)
{
	int NumberAsInteger = 0;
	for (int i = 0; i < NumberAsString.size(); i++)
		NumberAsInteger = NumberAsInteger * 10 + (NumberAsString[i] - '0');

	return NumberAsInteger;
}

std::vector<std::string> splitText(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}
int activeantispam()
{
	GiveVehicle::antispambool = 1;
	return 0;
}
int cleanrepeat()
{
	StopRepeat01 = "";
	StopRepeat02 = "";
	StopRepeat03 = "";
	StopRepeat04 = "";
	StopRepeat001 = "";
	StopRepeat002 = "";
	StopRepeat003 = "";
	StopRepeat004 = "";
	StopRepeat1 = "";
	StopRepeat2 = "";
	StopRepeat3 = "";
	StopRepeat4 = "";
	return 0;
}
string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}
#pragma execution_character_set("utf-8")
bool checkword = 1;
__int64* ReceiveChat::ChatReceive(__int64 a1, __int64 a2, __int64 sender, const char* msg, bool is_team)
{
	Log::MsgChat("===============");
	CNetGamePlayer2* net_player = g_sender->get_sender(sender);
	const auto player_name = net_player->get_name();

	Log::MsgChat((char*)player_name);
	Log::MsgChat(msg);

	if (net_player != nullptr)
	{
		if (Features::onlineplayer)
		{
			if (GiveVehicle::norepeat)
			{

				net_playerm_player_id = net_player->m_player_id;
				numrepeat = numrepeat + 1;

				if (numrepeat == 1)
				{
					SpamRepeatint1 = net_playerm_player_id;
					char a[] = { (char)msg };
					int a_size = sizeof(a) / sizeof(char);
					string cs = convertToString(a, a_size);
					std::string sprogram = " ";
					std::string::size_type ig = cs.find(sprogram);
					if (ig != std::string::npos)
					{
						std::vector<std::string> words = splitText(msg, ' ');
						if (words[0] != "")
						{
							StopRepeat1 = words[0];
						}
						if (words[1] != "")
						{
							checkword = 1;
							StopRepeat2 = words[1];
						}
						if (words[1] == "")
						{
							checkword = 0;
							goto endantispam;
						}
						if (checkword)
						{
							if (words[2] != "")
							{
								StopRepeat3 = words[2];
							}
							if (words[2] == "")
							{
								checkword = 0;
								goto endantispam;
							}
							if (words[3] != "")
							{
								StopRepeat4 = words[3];
							}
							if (words[3] == "")
							{
								checkword = 0;
								goto endantispam;
							}
						}
					}
					else
					{
						checkword = 0;
						goto endantispam;
					}
				}
				if (numrepeat == 2)
				{
					SpamRepeatint2 = net_playerm_player_id;
					if (SpamRepeatint1 == SpamRepeatint2)
					{
						char a[] = { (char)msg };
						int a_size = sizeof(a) / sizeof(char);
						string cs = convertToString(a, a_size);
						std::string sprogram = " ";
						std::string::size_type ig = cs.find(sprogram);
						if (ig != std::string::npos)
						{
							std::vector<std::string> words = splitText(msg, ' ');
							if (words[0] != "")
							{
								StopRepeat01 = words[0];
							}
							if (words[1] != "")
							{
								checkword = 1;
								StopRepeat02 = words[1];
							}
							if (words[1] == "")
							{
								checkword = 0;
								goto endantispam;
							}
							if (checkword)
							{
								if (words[2] != "")
								{
									StopRepeat03 = words[2];
								}
								if (words[2] == "")
								{
									goto endantispam;
								}
								if (words[3] != "")
								{
									StopRepeat04 = words[3];
								}
								if (words[3] == "")
								{
									goto endantispam;
								}
							}
						}
						else
						{
							checkword = 0;
							goto endantispam;
						}
					}
					if (SpamRepeatint1 != SpamRepeatint2)
					{
						checkword = 0;
						goto endantispam;
					}
				}
				if (numrepeat == 3)
				{
					SpamRepeatint2 = net_playerm_player_id;
					if (SpamRepeatint1 == SpamRepeatint2)
					{
						char a[] = { (char)msg };
						int a_size = sizeof(a) / sizeof(char);
						string cs = convertToString(a, a_size);
						std::string sprogram = " ";
						std::string::size_type ig = cs.find(sprogram);
						if (ig != std::string::npos)
						{
							std::vector<std::string> words = splitText(msg, ' ');
							if (words[0] != "")
							{
								StopRepeat001 = words[0];
								if ((char*)StopRepeat001.c_str() != (char*)StopRepeat01.c_str())
								{
									goto endantispam;
								}
							}
							if (words[1] != "")
							{
								StopRepeat002 = words[1];
								if ((char*)StopRepeat002.c_str() != (char*)StopRepeat02.c_str())
								{
									checkword = 1;
									goto endantispam;
								}
							}
							if ((char*)StopRepeat002.c_str() == "")
							{
								checkword = 0;
								goto endantispam;
							}
							if (words[1] == "")
							{
								checkword = 0;
								goto endantispam;
							}
							if (checkword)
							{
								if (words[2] != "")
								{
									StopRepeat003 = words[3];
									if ((char*)StopRepeat003.c_str() != (char*)StopRepeat03.c_str())
									{
										goto endantispam;
									}
								}
								if (words[2] == "")
								{
									checkword = 0;
									/*goto endantispam;*/
								}
								if (words[3] != "")
								{
									StopRepeat004 = words[4];
									if ((char*)StopRepeat004.c_str() != (char*)StopRepeat04.c_str())
									{
										goto endantispam;
									}
									if ((char*)StopRepeat004.c_str() == (char*)StopRepeat04.c_str())
									{
										activeantispam();
										goto endantispam;
									}
								}
								if (words[3] == "")
								{
									checkword = 0;
									goto endantispam;
								}
							}
						}
						else
						{
							checkword = 0;
							goto endantispam;
						}
					}
					if (SpamRepeatint1 != SpamRepeatint2)
					{
						goto endantispam;
					}
				}
			endantispam:
				{
					cleanrepeat();
					numrepeat = 0;
				}
			}
		}
		if (GiveVehicle::activatevehicle)
		{
		if (CommandCheck(msg, "/vehicle"))
		{
			GiveVehicle::vehiclewanted = (char*)GetSecondWord(msg).c_str();
			GiveVehicle::playerwantcar = net_player->m_player_id;
			GiveVehicle::GiveAVehicle();
		}
		}
		if (GiveVehicle::activatebike)
		{
		if (CommandCheck(msg, "/putonbike"))
		{
			GiveVehicle::vehiclewanted = (char*)GetSecondWord(msg).c_str();
			GiveVehicle::PutOnBikeint();
		}
		}
		if (GiveVehicle::activatebounty)
		{
		if (CommandCheck(msg, "/sendbounty"))
		{
			GiveVehicle::vehiclewanted = (char*)GetSecondWord(msg).c_str();
			GiveVehicle::SendBountyint();
		}
		}
		if (GiveVehicle::activateland)
		{
		if (CommandCheck(msg, "/sendtoisland"))
		{
			GiveVehicle::vehiclewanted = (char*)GetSecondWord(msg).c_str();
			GiveVehicle::sendtoislandint();
		}
		}
		if (GiveVehicle::activatekick)
		{
		if (CommandCheck(msg, "/kick"))
		{
			GiveVehicle::vehiclewanted = (char*)GetSecondWord(msg).c_str();
			GiveVehicle::Kickint();
		}
		}
		if (GiveVehicle::activatecrash)
		{
		if (CommandCheck(msg, "/crash"))
		{
			GiveVehicle::vehiclewanted = (char*)GetSecondWord(msg).c_str();
			GiveVehicle::crashint();
		}
		}
		if (GiveVehicle::activateblame)
		{
		if (CommandCheck(msg, "/blame"))
		{
			GiveVehicle::blame1 = (char*)GetSecondWord(msg).c_str();
			GiveVehicle::blame2 = (char*)GetSecondWord3(msg).c_str();
			std::string sprogram = " ";
			std::string sprograms = "";
			std::string::size_type ig = GiveVehicle::blame1.find(sprogram);
			if (ig != std::string::npos)
				GiveVehicle::blame1.replace(ig, sprogram.length(), sprograms);
			std::string::size_type ig2 = GiveVehicle::blame2.find(sprogram);
			if (ig2 != std::string::npos)
				GiveVehicle::blame2.replace(ig2, sprogram.length(), sprograms);
			Log::Msg("blame");
			Log::Msg((char*)GiveVehicle::blame1.c_str());
			Log::Msg((char*)GiveVehicle::blame2.c_str());
			Log::Msg("___");
			if ((char*)GetSecondWord3(msg).c_str() != "")
			{
				GiveVehicle::blame2 = (char*)GetSecondWord(GetSecondWord2(msg)).c_str();
				std::string::size_type ig4 = GiveVehicle::blame2.find(sprogram);
				if (ig4 != std::string::npos)
					GiveVehicle::blame2.replace(ig4, sprogram.length(), sprograms);
				GiveVehicle::WordBlame1 = (char*)GetSecondWord(msg).c_str();
				GiveVehicle::WordBlame2 = (char*)GetSecondWord(GetSecondWord2(msg)).c_str();
				GiveVehicle::WordBlame3 = (char*)GetThirdWord3(msg).c_str();
				Log::Msg((char*)GetSecondWord(msg).c_str());
				Log::Msg((char*)GetSecondWord(GetSecondWord2(msg)).c_str());
				Log::Msg((char*)GetThirdWord3(msg).c_str());
				Log::Msg((char*)GiveVehicle::WordBlame1.c_str());
				Log::Msg((char*)GiveVehicle::WordBlame2.c_str());
				Log::Msg((char*)GiveVehicle::WordBlame3.c_str());
			GiveVehicle::activateblametoggle = 1;
			Log::Msg("___");
			}
			else
				GiveVehicle::activateblametoggle = 0;
			GiveVehicle::blameint();
		}
		}

		if (GiveVehicle::activatemoney)
		{
			if (CommandCheck(msg, "/moneydrop"))
			{
				GiveVehicle::MoneyDrop1 = (char*)GetSecondWord(msg).c_str();
				GiveVehicle::MoneyDrop2 = (char*)GetSecondWord3(msg).c_str();
				std::string sprogram = " ";
				std::string sprograms = "";
				std::string::size_type ig = GiveVehicle::MoneyDrop1.find(sprogram);
				if (ig != std::string::npos)
					GiveVehicle::MoneyDrop1.replace(ig, sprogram.length(), sprograms);
				std::string::size_type ig2 = GiveVehicle::MoneyDrop2.find(sprogram);
				if (ig2 != std::string::npos)
					GiveVehicle::MoneyDrop2.replace(ig2, sprogram.length(), sprograms);
				Log::Msg("moneydrop");
				Log::Msg((char*)GiveVehicle::MoneyDrop1.c_str());
				Log::Msg((char*)GiveVehicle::MoneyDrop2.c_str());
				Log::Msg("___");
				if ((char*)GetSecondWord3(msg).c_str() != "")
				{
					GiveVehicle::MoneyDrop2 = (char*)GetSecondWord(GetSecondWord2(msg)).c_str();
					std::string::size_type ig4 = GiveVehicle::MoneyDrop2.find(sprogram);
					if (ig4 != std::string::npos)
						GiveVehicle::MoneyDrop2.replace(ig4, sprogram.length(), sprograms);
					GiveVehicle::WordMoney1 = (char*)GetSecondWord(msg).c_str();
					GiveVehicle::WordMoney2 = (char*)GetSecondWord(GetSecondWord2(msg)).c_str();
					/*GiveVehicle::WordMoney3 = (char*)GetThirdWord3(msg).c_str();*/
					Log::Msg((char*)GetSecondWord(msg).c_str());
					Log::Msg((char*)GetSecondWord(GetSecondWord2(msg)).c_str());
					Log::Msg((char*)GetThirdWord3(msg).c_str());
					Log::Msg((char*)GiveVehicle::WordMoney1.c_str());
					Log::Msg((char*)GiveVehicle::WordMoney2.c_str());
					GiveVehicle::MoneyDrop = GiveVehicle::MoneyDrop2;
					Log::Msg((char*)GiveVehicle::MoneyDrop.c_str());
					/*Log::Msg((char*)GiveVehicle::WordMoney3.c_str());*/
					/*GiveVehicle::MoneyDroptoggle = 1;*/
					Log::Msg("___");
				}
				/*else
				{
					GiveVehicle::MoneyDroptoggle = 0;
					GiveVehicle::MoneyDrop = "off";
				}*/

				GiveVehicle::MoneyDropint();
			}
			//if (CommandCheck(msg, "/moneydrop"))
			//{
			//	GiveVehicle::MoneyDrop1 = (char*)GetSecondWord(msg).c_str();
			//	GiveVehicle::MoneyDrop2 = (char*)GetSecondWord3(msg).c_str();
			//	std::string sprogram = " ";
			//	std::string sprograms = "";
			//	std::string::size_type ig = GiveVehicle::MoneyDrop1.find(sprogram);
			//	if (ig != std::string::npos)
			//		GiveVehicle::MoneyDrop1.replace(ig, sprogram.length(), sprograms);
			//	std::string::size_type ig2 = GiveVehicle::MoneyDrop2.find(sprogram);
			//	if (ig2 != std::string::npos)
			//		GiveVehicle::MoneyDrop2.replace(ig2, sprogram.length(), sprograms);
			//	Log::Msg("Money");
			//	Log::Msg((char*)GiveVehicle::MoneyDrop1.c_str());
			//	Log::Msg((char*)GiveVehicle::MoneyDrop2.c_str());
			//	Log::Msg("___");
			//	if ((char*)GetSecondWord3(msg).c_str() != "")
			//	{
			//		GiveVehicle::MoneyDrop2 = (char*)GetSecondWord(GetSecondWord2(msg)).c_str();
			//		std::string::size_type ig4 = GiveVehicle::MoneyDrop2.find(sprogram);
			//		if (ig4 != std::string::npos)
			//			GiveVehicle::MoneyDrop2.replace(ig4, sprogram.length(), sprograms);
			//		Log::Msg("Money1");
			//		GiveVehicle::MoneyDrop1 = (char*)GetSecondWord(msg).c_str();
			//		GiveVehicle::MoneyDrop2 = (char*)GetSecondWord(GetSecondWord2(msg)).c_str();
			//		/*GiveVehicle::WordBlame3 = (char*)GetThirdWord3(msg).c_str();*/
			//		Log::Msg((char*)GetSecondWord(msg).c_str());
			//		Log::Msg((char*)GetSecondWord(GetSecondWord2(msg)).c_str());
			//		Log::Msg((char*)GetThirdWord3(msg).c_str());
			//		Log::Msg((char*)GiveVehicle::MoneyDrop1.c_str());
			//		Log::Msg((char*)GiveVehicle::MoneyDrop2.c_str());
			//		/*Log::Msg((char*)GiveVehicle::WordBlame3.c_str());*/
			//		Log::Msg("Money2");
			//		GiveVehicle::MoneyDroptoggle = 1;
			//		Log::Msg("___");
			//	}
			//	else
			//		GiveVehicle::MoneyDroptoggle = 0;
			//	GiveVehicle::MoneyDropint();
			//}
		}
	}
	return static_cast<decltype(&ChatReceive)>(m_OriginalChatReceive)(a1, a2, sender, msg, is_team);
}

//void Hooks::GamerHandleSerialize(rage::rlGamerHandle& hnd, rage::datBitBuffer& buf)
//{
//	constexpr int PC_PLATFORM = 3;
//	buf.Write<uint8_t>(PC_PLATFORM, 8);
//	buf.WriteInt64(*(int64_t*)&hnd.m_rockstar_id, 64);
//	buf.Write<uint8_t>(hnd.unk_0009, 8);
//}
//
//int Hooks::NetfilterHandleMessage(__int64 filter, char* message, int flags)
//{
//	int* features = (int*)(filter + 0x24);
//	int old = *features;
//	*features = 0;
//	auto id = static_cast<decltype(&NetfilterHandleMessage)>(g_Hooking->m_OriginalNetfilterHandleMessage)(filter, message, flags);
//	*features = old;
//	return id;
//}
//
//bool Hooks::SendChatMessage(void* team_mgr, rage::rlGamerInfo* local_gamer_info, char* message, bool is_team)
//{
//	packet msg{};
//	msg.write_message(eNetMessage::MsgTextMessage);
//	msg.m_buffer.WriteString(message, 256);
//	Hooks::GamerHandleSerialize(GetNetPlayer(PlayerID)->get_net_data()->m_gamer_handle, msg.m_buffer);
//	msg.write<bool>(is_team, 1);
//
//	for (int i = 0; i < 32; i++)
//	{
//		if (GetNetPlayer(i))
//			msg.send(GetNetPlayer(i)->m_msg_id);
//	}
//	return true;
//}
//
//void m_function::SendChatMessage(char* a1, int color)
//{
//	if (*g_GameVariables->m_IsSessionStarted)
//	{
//		if (const auto net_game_player = GetNetworkPlayerMgr()->m_local_net_player; net_game_player)
//		{
//			if (static_cast<decltype(&Hooks::SendChatMessage)>(g_Hooking->m_OriginalSendChatMessage)(*g_GameFunctions->m_SendChatPointer, net_game_player->get_net_data(), a1, false))
//				m_function::DrawChatScaleform(a1, net_game_player->get_name(), color);
//		}
//	}
//}

//void WriteString(char* string, int max_len)
//{
//	auto len = std::min(max_len, (int)strlen(string) + 1);
//	bool extended = len > 127;
//	Write<bool>(extended, 1);
//	Write<int>(len, extended ? 15 : 7);
//	WriteArray(string, 8 * len);
//}

//void getnativehook()
//{
//	std::unique_ptr<NativeHooks> native_hook;
//	native_hook = std::make_unique<NativeHooks>();
//}

//NativeHooks* getnativehook()
//{
//	return new NativeHooks(); // Adjust based on your actual implementation
//}


bool GetLabelText_checked = 0;
bool is_DLC_present_checked = 0;
bool DisableErrorScreen_checked = 0;
bool get_message_checked = 0;

bool Hooking::HookNatives()
{
	/*if (Hooking::loadmods) {*/
	//bool is_DLC_present_check = checkpattern("48 89 5C 24 ? 57 48 83 EC 20 81 F9 ? ? ? ?");
	if (is_DLC_present_checked)
	{
		MH_STATUS status = MH_CreateHook(Hooking::is_DLC_present, HK_IS_DLC_PRESENT, (void**)&OG_IS_DLC_PRESENT);
		if ((status != MH_OK && status != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::is_DLC_present) != MH_OK)
			return false;
		Hooking::m_hooks.push_back(Hooking::is_DLC_present);
	}

	if (Hooking::geteventdata)
	{
	MH_STATUS status1 = MH_CreateHook(Hooking::get_event_data, &Hooking::GED, &m_OriginalGetEventData);
	if ((status1 != MH_OK && status1 != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::get_event_data) != MH_OK)
	{
		Log::Msg("Hook Status1 %s", MH_StatusToString(status1));
		return false;
	}
	Log::Msg("Hook Succeed Status1 %s", MH_StatusToString(status1));
	/*Hooking::m_hooks.push_back(Hooking::get_event_data);*/
	}


	/*MH_STATUS status2 = MH_CreateHook(Hooking::increment_stat_hook, &ThunderHooks::IncrementStatEvent, (void**)&Increment_StatEvent);
	if ((status2 != MH_OK && status2 != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::increment_stat_hook) != MH_OK)
	{
		Log::Msg("Hook status2 %s", MH_StatusToString(status2));
		return false;
	}
	Log::Msg("Hook Succeed Status2 %s", MH_StatusToString(status2));
	Hooking::m_hooks.push_back(Hooking::increment_stat_hook);*/

	//bool GetLabelText_check = checkpattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8");
	if (GetLabelText_checked)
	{

		MH_STATUS status3 = MH_CreateHook(Hooking::GetLabelText, &hkGetLabelText, (void**)&ogGetLabelText);
		if ((status3 != MH_OK && status3 != MH_ERROR_ALREADY_CREATED) || MH_EnableHook(Hooking::GetLabelText) != MH_OK)
		{
			Log::Msg("Hook Status3 %s", MH_StatusToString(status3));
			return false;
		}
		Log::Msg("Hook Succeed Status3 %s", MH_StatusToString(status3));
		Hooking::m_hooks.push_back(Hooking::GetLabelText);

	}
	//bool DisableErrorScreen_check = checkpattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 60 4C 8B F2 48 8B 94 24 ? ? ? ? 33 DB");
	if (DisableErrorScreen_checked)
	{
		MH_CreateHook(Hooking::DisableErrorScreen, &ThunderHooks::DisableErrorScreen, (void**)&m_OriginalDisableErrorScreen);
	}
	/*if (!Settings::m_RIDInviter)
	{*/ 
		//MH_CreateHook(Hooking::RIDJoinFriendsV2, &ThunderHooks::RIDJoinFriendsV2, (void**)&m_OriginalRIDJoinFriendsV2);
		/*MH_CreateHook(Hooking::RIDJoinFriends, &ThunderHooks::RIDJoinFriends, (void**)&m_OriginalRIDJoinFriends);
		MH_CreateHook(Hooking::RIDJoinHandle, &ThunderHooks::RIDJoinHandle, (void**)&m_OriginalRIDJoinHandle);*/
	/*}*/
		MH_CreateHook(g_GameVariables->m_NetworkInfo, &Hooks::send_net_info_to_lobby, (void**)&OriginalPTR::m_OriginalNetworkInfo);
		//g_GameVariables->m_NetworkInfo

	/*if (Settings::m_RIDInviter)
	{
		MH_CreateHook(Hooking::Hooking::m_send_invite_accepted_presence_event, &ThunderHooks::RIDInviteFriends, (void**)&m_OriginalRIDInviteFriends);
		MH_CreateHook(Hooking::Hooking::m_start_get_session_by_gamer_handle, &ThunderHooks::RIDInviteHandle, (void**)&m_OriginalRIDInviteHandle);
	}*/
		//bool get_message_check = checkpattern("4D 85 C9 0F 84 ? ? ? ? 48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 54 41 55 41 56 41 57 48 8D A8");
		if (get_message_checked)
		{
			MH_CreateHook(Hooking::get_message, &ReceiveChat::ChatReceive, (void**)&m_OriginalChatReceive);
		}
		/*MH_CreateHook(Hooking::get_sender, &ReceiveChat::SenderReceive, (void**)&m_OriginalSenderReceive);*/

		/*MH_CreateHook(g_GameVariables->m_ChatReceive, &ReceiveChat::ChatReceive, &m_OriginalChatReceive);*/
		/*MH_CreateHook(g_GameVariables->shitter_crash, &hkcrash::hk_nigger_crash, (void**)&OriginalPTR::CrashPTR);*/
	
		MH_CreateHook(g_GameVariables->m_WriteVehicleProximityMigrationDataNode, &Hooks::WriteVehicleProximityMigrationDataNode, (void**)&OriginalPTR::m_OriginalWriteVehicleProximityMigrationDataNode);

		/*MH_CreateHook(reinterpret_cast<LPVOID>(getnativehook()), &Hooks::NetworkSessionHost, (void**)&OriginalPTR::RIDJOINPLAYER);*/
		/*MH_CreateHook(
			reinterpret_cast<LPVOID>(getnativehook()),
			reinterpret_cast<LPVOID*>(&Hooks::NetworkSessionHost),
			reinterpret_cast<void**>(&OriginalPTR::RIDJOINPLAYER)
		);*/

		MH_CreateHook(g_GameVariables->m_TimecycleOverride, &G_Hooking::TimecycleOverride, &OriginalPTR::m_OriginalTimecycleOverride);

		//MH_CreateHook(g_GameVariables->PVOID_RainMain, &G_Hooking::RainOverride, &OriginalPTR::m_OriginalRainOverride);

		MH_EnableHook(MH_ALL_HOOKS);

	Log::Msg("Hook Successfully!");
	/*}*/
	return true;
}

//int returngamefunction()
//{
//	g_GameFunctions = /*std::make_unique<GameFunctions1>()*/reinterpret_cast<GameFunctions1>;
//	return 0;
//}
//void GameVariables1::RequestControlBypass(bool toggle)
//{
//	*(unsigned short*)g_GameVariables->m_SpectatorCheck = toggle ? 0x6A75 : 0x9090;
//}

void __stdcall ScriptFunction(LPVOID lpParameter)
{
	try
	{
		ScriptMain();

	}
	catch (...)
	{
		Log::Fatal("Failed scriptFiber");
	}
}

//ExplotDll VOID WINAPI winbase::SwitchToFiber2(_In_ LPVOID lpFiber)
//{
//	return (VOID)lpFiber;
//}
//ExplotDll _Ret_maybenull_ LPVOID WINAPI winbase::ConvertThreadToFiber2(_In_opt_ LPVOID lpParameter)
//{
//	return lpParameter;
//}
//ExplotDll _Ret_maybenull_ LPVOID WINAPI winbase::CreateFiber2(_In_ SIZE_T dwStackSize, _In_ LPFIBER_START_ROUTINE lpStartAddress, _In_opt_ LPVOID lpParameter)
//{
//	return dwStackSize, lpStartAddress, lpParameter;
//}
//
//int timerget;
////
//void ScriptMain2()
//{
//	srand(GetTickCount64());
//	timerget = timeGetTime();
//}
//void __stdcall ScriptFunction2(LPVOID lpParameter)
//{
//	try
//	{
//		ScriptMain2();
//	}
//	catch (...)
//	{
//		Log::Fatal("Failed scriptFiber");
//	}
//}

//void Hooking::onTickInit2()
//{
//	if (m_main_fiber == nullptr)
//		m_main_fiber = winbase::ConvertThreadToFiber2(nullptr);
//	if (timeGetTime() < wakeAt2)
//		return;
//
//	static void* scriptFibers;
//
//	if (scriptFibers)
//		winbase::SwitchToFiber2(scriptFibers);
//	else
//		scriptFibers = winbase::CreateFiber2(NULL, ScriptFunction, nullptr);
//}
int LastFrame = 0;
int getFrame()
{
	if (LastFrame != GAMEPLAY::GET_FRAME_COUNT())
	{
		LastFrame = GAMEPLAY::GET_FRAME_COUNT();
	}
	return 0;
}

void Hooking::onTickInit()
{
	/*if (Hooking::loadmods) {*/
		if (mainFiber == nullptr)
			mainFiber = ConvertThreadToFiber(nullptr);

		if (timeGetTime() < wakeAt)
			return;

		static HANDLE scriptFiber;

		if (scriptFiber)
			SwitchToFiber(scriptFiber);
		else
			scriptFiber = CreateFiber(NULL, ScriptFunction, nullptr);

	/*}*/
		// Boucle non bloquante pour le temps d'attente
		/*while (timeGetTime() < wakeAt)
		{
			SwitchToFiber(mainFiber);
		}*/
}

void Hooking::FailPatterns(const char* name)
{
	char buf[4096];
	sprintf_s(buf, "finding %s", name);
	Log::Error(buf);
	Cleanup();
}

/*
//CPatternResult
*/

CPatternResult::CPatternResult(void* pVoid) :
	m_pVoid(pVoid)
{}
CPatternResult::CPatternResult(void* pVoid, void* pBegin, void* pEnd) :
	m_pVoid(pVoid),
	m_pBegin(pBegin),
	m_pEnd(pEnd)
{}
CPatternResult::~CPatternResult() {}

/*
//CPattern Public
*/

CPattern::CPattern(char* szByte, char* szMask) :
	m_szByte(szByte),
	m_szMask(szMask),
	m_bSet(false)
{}
CPattern::~CPattern() {}

CPattern&	CPattern::find(int i, uint64_t startAddress)
{
	match(i, startAddress, false);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPattern&	CPattern::virtual_find(int i, uint64_t startAddress)
{
	match(i, startAddress, true);
	if (m_result.size() <= i)
		m_result.push_back(nullptr);
	return *this;
}

CPatternResult	CPattern::get(int i)
{
	if (m_result.size() > i)
		return m_result[i];
	return nullptr;
}

/*
//CPattern Private
*/
bool	CPattern::match(int i, uint64_t startAddress, bool virt)
{
	if (m_bSet)
		return false;
	uint64_t	begin = 0;
	uint64_t	end = 0;
	if (!virt)
	{
		CMetaData::init();
		begin = CMetaData::begin() + startAddress;
		end = CMetaData::end();
		if (begin >= end)
			return false;
	}
	int		j = 0;
	do
	{
		if (virt)
			begin = virtual_find_pattern(startAddress, (BYTE*)m_szByte, m_szMask) + 1;
		else
			begin = find_pattern(begin, end, (BYTE*)m_szByte, m_szMask) + 1;
		if (begin == NULL)
			break;
		j++;
	} while (j < i);

	m_bSet = true;
	return true;
}

bool	CPattern::byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++btMask)
		if (*szMask == 'x' && *pData != *btMask)
			break;
	if ((*szMask) != 0)
		return false;
	return true;
}


uint64_t	CPattern::find_pattern(uint64_t address, uint64_t end, BYTE *btMask, char *szMask)
{
	size_t len = strlen(szMask) + 1;
	for (uint64_t i = 0; i < (end - address - len); i++)
	{
		BYTE*	ptr = (BYTE*)(address + i);
		if (byte_compare(ptr, btMask, szMask))
		{
			m_result.push_back(CPatternResult((void*)(address + i)));
			return address + i;
		}
	}
	return NULL;
}

uint64_t	CPattern::virtual_find_pattern(uint64_t address, BYTE *btMask, char *szMask)
{
	MEMORY_BASIC_INFORMATION mbi;
	char*	pStart = nullptr;
	char*	pEnd = nullptr;
	char*	res = nullptr;
	size_t	maskLen = strlen(szMask);

	while (res == nullptr && sizeof(mbi) == VirtualQuery(pEnd, &mbi, sizeof(mbi)))
	{
		pStart = pEnd;
		pEnd += mbi.RegionSize;
		if (mbi.Protect != PAGE_READWRITE || mbi.State != MEM_COMMIT)
			continue;

		for (int i = 0; pStart < pEnd - maskLen && res == nullptr; ++pStart)
		{
			if (byte_compare((BYTE*)pStart, btMask, szMask))
			{
				m_result.push_back(CPatternResult((void*)pStart, mbi.BaseAddress, pEnd));
				res = pStart;
			}
		}

		mbi = {};
	}
	return (uint64_t)res;
}

void	failPat(const char* name)
{
	Log::Fatal("Failed to find %s pattern.", name);
	exit(0);
}

template <typename T>
void	setPat
(
	const char*	name,
	char*		pat,
	char*		mask,
	T**			out,
	bool		rel,
	int			offset = 0,
	int			deref = 0,
	int			skip = 0
)
{
	T*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	if (rel)
		ptr = pattern.get(skip).get_rel<T>(offset);
	else
		ptr = pattern.get(skip).get<T>(offset);

	while (true)
	{
		if (ptr == nullptr)
			failPat(name);

		if (deref <= 0)
			break;
		ptr = *(T**)ptr;
		--deref;
	}

	*out = ptr;
	return;
}

template <typename T>
void	setFn
(
	const char*	name,
	char*		pat,
	char*		mask,
	T*			out,
	int			skip = 0
)
{
	char*	ptr = nullptr;

	CPattern pattern(pat, mask);
	pattern.find(1 + skip);
	ptr = pattern.get(skip).get<char>(0);

	if (ptr == nullptr)
		failPat(name);

	*out = (T)ptr;
	return;
}



bool Hooking::spectateplayer = 1;
void Hooking::setinspectatormode(BOOL toggle, Ped playerPed) {
	Features::playerid();
	if (!ENTITY::DOES_ENTITY_EXIST(playerPed) || PLAYER::IS_PLAYER_DEAD(Features::playerme))//PlayerID
	{
		UI::KEY_HUD_COLOUR(false, -1);
		*ScriptGlobal::ScriptGlobal(SpectateDeathPatchGlobal[0]).Add(SpectateDeathPatchGlobal[1]).As<int*>() = false;
		return;
	}
	if (!PLAYER::IS_PLAYER_DEAD(Features::playerme))//PlayerID
	{
	static auto spectated = reinterpret_cast<void(*)(BOOL, Ped)>(pattern("48 89 5C 24 ? 57 48 83 EC 20 41 8A F8 84 C9").count(1).get(0).get<void>(0));
	spectated(toggle, playerPed);
	UI::KEY_HUD_COLOUR(true, playerPed);
	*ScriptGlobal::ScriptGlobal(SpectateDeathPatchGlobal[0]).Add(SpectateDeathPatchGlobal[1]).As<int*>() = true;
	}
}

//static bool SpectateReset = true;
//void m_features::Spectate()
//{
//	const Ped target = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(g_SelectedPlayer);
//
//	if (!ENTITY::DOES_ENTITY_EXIST(target) || !g_Settings.m_Spectate || PLAYER::IS_PLAYER_DEAD(PlayerID))
//	{
//		if (g_Settings.m_Spectate) g_Settings.m_Spectate = false;
//
//		if (!SpectateReset)
//		{
//			SpectateReset = true;
//			g_GameFunctions->m_NetworkSpectatorMode(false, -1);
//			HUD::SET_MINIMAP_IN_SPECTATOR_MODE(false, -1);
//			*ScriptGlobal::ScriptGlobal(SpectateDeathPatchGlobal[0]).Add(SpectateDeathPatchGlobal[1]).As<int*>() = false;
//		}
//
//		return;
//	}
//	g_GameFunctions->m_NetworkSpectatorMode(true, target);
//	HUD::SET_MINIMAP_IN_SPECTATOR_MODE(true, target);
//	*ScriptGlobal::ScriptGlobal(SpectateDeathPatchGlobal[0]).Add(SpectateDeathPatchGlobal[1]).As<int*>() = true;
//	SpectateReset = false;
//}


void Hooking::settime(int Hours, int Minutes, int Seconds) {

	static auto timeschange = reinterpret_cast<void(*)(int, int, int)>(pattern("80 3D ? ? ? ? ? ? ? 8B 05 ? ? ? ? C6").count(1).get(0).get<void>(0));
	timeschange(Hours, Minutes, Seconds);
}

//CPed2* cp2;
//CPedFactory* cpf;
void CHooking::m_JmpRbx(){}
//interreplay* inter;
//bool replaybool = 1;

// CPed* get_local_ped()
//{
//	if (auto ped_factory = cpf->m_ped_factory)
//	{
//		ped_factory->CPedFactory::m_local_ped;
//		return 0;
//	}
//	return nullptr;
//}
//
// CPlayerInfo* get_local_playerinfo()
//{
//	if (auto ped_factory = cpf->m_ped_factory)
//	{
//		ped_factory->CPedFactory::m_local_ped;
//		if (auto ped = ped_factory->CPedFactory::m_local_ped)
//		{
//			ped->CPed2::m_playerinfo;
//			return 0;
//		}
//	}
//
//	return nullptr;
//}
//bool functionss::bMiscJoinRid = false;
//BOOL Hooking::hk_ridJoiner(int64_t* a1, int* hash)
//{
//	functionss::bMiscJoinRid = true;
//	auto res = functionss::o_ridJoiner(a1, hash);
//	functionss::bMiscJoinRid = false;
//	return res;
//}

void ThunderHooks::RequestControlBypass(bool toggle)
{
	*(unsigned short*)Hooking::SpectatorCheck = toggle ? 0x6A75 : 0x9090;
}

void Hooking::JoinPatterns()
{
	if (Hooking::RIDJoinFriendsHandler != NULL)
	{
		m_RIDJoinFriendsFrontEndMenu = (int64_t*)((int64_t)Hooking::RIDJoinFriendsHandler + 0xA0);
	}
}

Vector3 addVector11(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
double DegreeToRadian11(double n) {
	return n * 0.017453292519943295;
}

Vector3 RotationToDirection11(Vector3 rot) {
	double num = DegreeToRadian11(rot.z);
	double num2 = DegreeToRadian11(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}
bool Get_Entity_From_RayCast_Hit(Entity* target)
{
	Ped player = PLAYER::PLAYER_PED_ID();
	Vector3 CamCrd = CAM::GET_GAMEPLAY_CAM_COORD(); Vector3 CamRot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 CamCoords = PED::GET_PED_BONE_COORDS(player, SKEL_Head, 0.f, 0.f, 0.f);
	Vector3 FarCoords = add(&CamCrd, &multiply(&RotationToDirection11(CamRot), 1000.f));
	int RayHandle = WORLDPROBE::_START_SHAPE_TEST_RAY(CamCoords.x, CamCoords.y, CamCoords.z, FarCoords.x, FarCoords.y, FarCoords.z, -1, player, 7);
	BOOL RayCastHit; Vector3 RayHitCoords, surfaceNormalVector; Entity EntityHandle;
	int RayResult = WORLDPROBE::GET_SHAPE_TEST_RESULT(RayHandle, &RayCastHit, &RayHitCoords, &surfaceNormalVector, &EntityHandle);
	//Rays in color
	//rayVector
	GRAPHICS::DRAW_LINE(CamCoords.x, CamCoords.y, CamCoords.z, FarCoords.x, FarCoords.y, FarCoords.z, 255, 0, 0, 255);
	//surfaceNormalVector
	Vector3 NormalVector = add(&RayHitCoords, &multiply(&surfaceNormalVector, 5.f));
	GRAPHICS::DRAW_LINE(RayHitCoords.x, RayHitCoords.y, RayHitCoords.z, NormalVector.x, NormalVector.y, NormalVector.z, 0, 0, 255, 255);
	//
	if (RayCastHit)
	{
		int EntityType = ENTITY::GET_ENTITY_TYPE(EntityHandle);
		if (EntityType == 1/*peds*/ || EntityType == 2/*vehicles*/ || EntityType == 3 /*objects/props*/)
		{
			*target = EntityHandle;
			return true;
		}
	}
	else
	{
		EntityHandle = Entity();
		*target = NULL;
		return false;
	}
}

GlobalBase* hook_sender::baseGlobal;

//template<size_t N>
//bool checkpattern(const char(&thepattern)[N])
//{
//	auto getnative = pattern(thepattern);
//	//DWORD64* d_location = (DWORD64*)getnative.count(1).get(0).get<std::size_t>(0);
//	DWORD64* d_location = (DWORD64*)getnative.count(1).get(0).get<DWORD64*>(0);
//	return (d_location != nullptr);
//}

template<size_t N>
bool checkpattern(const char(&thepattern)[N])
{
	auto getnative = pattern(thepattern);
	size_t matchCount = getnative.size();

	if (matchCount == 1)
	{
		void* address = getnative.get(0).get<void*>(0);
		if (address)
		{
			Log::Msg("FOUND: %s", thepattern);
			return true;
		}
	}

	Log::Msg("NOT FOUND: %s", thepattern);
	return false;
}



void Hooking::FindPatterns()
{
	Log::Msg("Find Patterns...");
	HANDLE steam = GetModuleHandleA("steam_api64.dll");

	Log::Msg("GameFunctions1...");
	g_GameFunctions = std::make_unique<GameFunctions1>();
	Log::Msg("GameVariables1...");
	g_GameVariables = std::make_unique<GameVariables1>();
	/*Log::Msg("BattleyeState...");
	g_GameVariables3 = std::make_unique<GameVariables3>();*/
	Log::Msg("Vector...");
	auto p_activeThread = pattern("E8 ? ? ? ? 48 8B 88 ? 01 00 00 ? 02"); //E8 ? ? ? ? 48 8B 88 10 01 00 00
	auto p_blipList = pattern("4C 8D 05 ? ? ? ? 0F B7 C1");
	auto p_fixVectorResult = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");

	/*auto p_fixVectorResult = pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18 48 63 4A 18 48 8D 41 04 48 8B 4C CA");*/


	auto p_gameLegals = pattern("72 1F E8 ? ? ? ? 8B 0D");
	auto p_gameLogos = pattern("70 6C 61 74 66 6F 72 6D 3A");
	auto p_gameState = pattern("83 3D ? ? ? ? ? 75 17 8B 43 20 25");/*83 3D ? ? ? ? ? 8A D9 74 0A*/
	auto p_nativeTable = pattern("76 32 48 8B 53 40 48 8D 0D");
	//auto p_worldPtr = pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
	auto p_globalPtr = pattern("4C 8D 05 ? ? ? ? 4D 8B 08 4D 85 C9 74 11");
	auto p_eventHook = pattern("48 83 EC 28 E8 ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 0D ? ? ? ? 4C 8D 05 ? ? ? ? BA 03");
	
	//m_GameState(Signature(xorstr_("83 3D ? ? ? ? ? 75 17 8B 43 20 25"), xorstr_("GameState")).Scan().Add(2).Rip().Add(1).As<decltype(m_GameState)>()),//48 85 C9 74 4B 83 3D 
	Log::Msg("Find global 1...");
	Hooking::globalpattern = reinterpret_cast<patternglobal>(&p_globalPtr);
	Hooking::bliplist = reinterpret_cast<listblip>(&p_blipList);
	//Hooking::worldpattern = reinterpret_cast<patternworld>(&p_worldPtr);
	Log::Msg("Find spoof 2...");
	auto spoofpattern = Memory::pattern("FF 23");
	/*auto spoofpattern = Memory::pattern("FF E3");*/
	void* r_location = nullptr;
	r_location = spoofpattern.count(1).get(0).get<void>(0);
	if (r_location != nullptr) invoker_return_address = (r_location);
	/*for (int i = 0, end = spoofpattern.size(); i < end; ++i)
	{
		auto addr = spoofpattern.get(i).get<void>();

		MEMORY_BASIC_INFORMATION mbi{};
		if (VirtualQuery(addr, &mbi, sizeof(mbi)) == sizeof(mbi))
		{
			if (mbi.Protect == PAGE_EXECUTE_READWRITE)
			{
				invoker_return_address = addr;
				break;
			}
		}
	}*/


Log::Msg("Find label 3...");

bool GetLabelText_check1 = checkpattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8");
if (GetLabelText_check1)
{ 
	GetLabelText_checked = 1;
	Hooking::GetLabelText = static_cast<fpGetLabelText>(Memory::pattern("48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8").count(1).get(0).get<void>(0));
	Log::Msg("GetLabelText 48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8");
}
else
{
	bool GetLabelText_check2 = checkpattern("48 C1 E0 06 48 03 C1 C6 00 00 48 8B 5C 24");
	if (GetLabelText_check2)
	{
		GetLabelText_checked = 1;
		Hooking::GetLabelText = static_cast<fpGetLabelText>(Memory::pattern("48 C1 E0 06 48 03 C1 C6 00 00 48 8B 5C 24 - 0x44").count(1).get(0).get<void>(0));
		Log::Msg("Alternative 2 GetLabelText 48 C1 E0 06 48 03 C1 C6 00 00 48 8B 5C 24 - 0x44");
	}
	else
	{
		bool GetLabelText_check3 = checkpattern("48 8D 0D B0 50 96 01");
		if (GetLabelText_check3)
		{
			GetLabelText_checked = 1;
			Hooking::GetLabelText = static_cast<fpGetLabelText>(Memory::pattern("48 8D 0D B0 50 96 01 - 3E").count(1).get(0).get<void>(0));
			Log::Msg("Alternative 3 GetLabelText 48 8D 0D B0 50 96 01 - 3E");
		}
	}
}

bool RemoveWeapons_check = checkpattern("48 89 5C 24 08 57 48 83 EC 20 8B FA E8 ? ? ? ? 33 DB 48 85 C0 74");
if (RemoveWeapons_check)
{
	setFn<fpRemoveWeapons>("RemoveWeapons",
		"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x8B\xFA\xE8\x00\x00\x00\x00\x33\xDB\x48\x85\xC0\x74",
		"xxxxxxxxxxxxx????xxxxxx",
		&Hooking::RemoveWeapons);
}

	bool DisableErrorScreen_check = checkpattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 60 4C 8B F2 48 8B 94 24 ? ? ? ? 33 DB");
	if (DisableErrorScreen_check)
	{
		DisableErrorScreen_checked = 1;
		setFn<fpDisableErrorScreen>("DisableErrorScreen",
			"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x83\xEC\x60\x4C\x8B\xF2\x48\x8B\x94\x24\x00\x00\x00\x00\x33\xDB",
			"xxxx?xxxx?xxxx?xxxxxxxxxxxxxxxx????xx",
			&Hooking::DisableErrorScreen);
	}

	bool SpectatorCheck_check = checkpattern("48 89 5C 24 ? 57 48 83 EC 20 8B D9 E8 ? ? ? ? ? ? ? ? 8B CB");
	if (SpectatorCheck_check)
	{
		setFn<fpSpectatorCheck>("SpectatorCheck",
			"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x00\x00\x00\x00\x8B\xCB + 0x14",//0x13
			"xxxx?xxxxxxxx????????xx",
			&Hooking::SpectatorCheck);
	}
	//setFn<fpRIDJoinFriends>("RIDJoinFriends",
	//	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x55\x57\x41\x54\x41\x56\x41\x57\x48\x8D\xAC\x24\x00\x00\x00\x00\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\xD9", //48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B D9
	//	"xxxx?xxxx?xxxxxxxxxxxx????xxx????xxx",
	//	&Hooking::RIDJoinFriends);


	//setFn<sub7FF71339282C>("sub7FF71339282C",
	//	"\x48\x89\x5C\x24\x10\x57\x48\x83\xEC\x40\x8B\x01\x49\x8B\xF8\x48\x8B\xDA\x3D\x84",
	//	"xxxxxxxxxxxxxxxxxxxx",
	//	/*"\x48\x03\x7C\x30\x08\x48\x8B\x03\x48\x8B\xCB\xFF\x90\x10\x02\x00 + 68",
	//	"xxxxxxxxxxxxxxx?",*/
	//	//"\xE8\xF3\x15\x00\x00\x84\xC0\x74\x07\xB0\x01\xE9\x0D\x05\x00\x00",
	//	//"xxx??xxxxxxxxx??",
	//	&Hooking::sub_7FF71339282C); //48 89 5C 24 10 57 48 83 EC 40 8B 01 49 8B F8 48 8B DA 3D 84

	//setFn<fpRIDJoinFriendsV2>("RIDJoinFriendsV2",
	//	"\x48\x89\x5C\x24\x10\x57\x48\x83\xEC\x40\x8B\x01\x49\x8B\xF8\x48\x8B\xDA\x3D\x84",
	//	"xxxxxxxxxxxxxxxxxxxx",
	//	/*"\x48\x03\x7C\x30\x08\x48\x8B\x03\x48\x8B\xCB\xFF\x90\x10\x02\x00 + 68",
	//	"xxxxxxxxxxxxxxx?",*/
	//	//"\xE8\xF3\x15\x00\x00\x84\xC0\x74\x07\xB0\x01\xE9\x0D\x05\x00\x00",
	//	//"xxx??xxxxxxxxx??",
	//	&Hooking::RIDJoinFriendsV2);

	//setFn<fpRIDJoinHandle>("RIDJoinHandle",
	//	"\x40\x53\x48\x83\xEC\x20\x8B\xD9\x83\xF9\xFE\x75\x1C\xE8\x00\x00\x00\x00\x48\x85", //40 53 48 83 EC 20 8B D9 83 F9 FE 75 1C E8 ? ? ? ? 48 85
	//	"xxxxxxxxxxxxxx????xx",
	//	&Hooking::RIDJoinHandle);

	//setFn<fpRIDJoinFriendsHandler>("RIDJoinFriendsHandler",
	//	"\x48\x8B\x0D\x00\x00\x00\x00\x48\x03\xD2\x48\x8B\x0C\xD1\x48\x85\xC9",
	//	"xxx????xxxxxxxxxx",
	//	//"\x48\x8B\x0D\x00\x00\x00\x00\x48\x03\xD2\x48\x8B\x0C\xD1\x33\xD2\xE8", //48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1 33 D2 E8
	//	//"xxx????xxxxxxxxxx",
	//	&Hooking::RIDJoinFriendsHandler);
	//////48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1 48 85 C9

	//Hooking::JoinPatterns();
	//m_RIDJoinFriendsHandler(Signature(xorstr_("48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1"), xorstr_("RIDJoinFriendsHandler")).Scan().Add(3).Rip().As<int64_t*>()),



	//setFn<fpRIDInviteFriends>("RIDInviteFriends",
	//	"\x40\x53\x48\x83\xEC\x40\x8B\x01\x48\x8B\xDA\x3D\x84\x32\x64\x84", //40 53 48 83 EC 40 8B 01 48 8B DA 3D 84 32 64 84
	//	"xxxxxxxxxxxxxxxx",
	//	&Hooking::RIDInviteFriends);
	//setFn<fpRIDInviteHandle>("RIDInviteHandle",
	//	"\x48\x89\x5C\x24\x10\x48\x89\x74\x24\x18\x48\x89\x7C\x24\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x6C\x24\x80\x48\x81\xEC\x80\x01\x00\x00\x48\x8B\xD9\x48\x8B\x89\x18\x08\x00\x00\x45\x33\xED\x4C\x8B\xF2\x48\x85\xC9", //48 89 5C 24 10 48 89 74 24 18 48 89 7C 24 20 55 41 54 41 55 41 56 41 57 48 8D 6C 24 80 48 81 EC 80 01 00 00 48 8B D9 48 8B 89 18 08 ? ? 45 33 ED 4C 8B F2 48 85 C9
	//	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx??xxxxxxxx??xxxxxxxxx",
	//	&Hooking::RIDInviteHandle);



	//setFn<fpmstartgetsessionbygamerhandle>("m_start_get_session_by_gamer_handle",
	//	"\xE8\x00\x00\x00\x00\x84\xC0\x0F\x84\x00\x00\x00\x00\x8B\x05\x00\x00\x00\x00\x48\x8D\x4C\x24\x50",
	//	"x????xxxx????xx????xxxxx",
	//	&Hooking::m_start_get_session_by_gamer_handle);

	//setFn<fpmsendinviteacceptedpresenceevent>("m_start_get_session_by_gamer_handle",
	//	"\xE8\x00\x00\x00\x00\xE9\x00\x00\x00\x00\xC6\x05\x00\x00\x00\x00\x00\xE9\x32",
	//	"x????x????xx?????xx",
	//	&Hooking::m_send_invite_accepted_presence_event);

	//setFn<fpmpresencestruct>("m_presence_struct",
	//	"\x48\x8D\x0D\x00\x00\x00\x00\x41\x83\xE0\x10\xE8\x00\x00\x00\x00\x44\x38\x3D\x00\x00\x00\x00\x0F\x85\x00\x00\x00\x00\x48\x8D\x4C\x24\x20\xE8\x88",
	//	"xxx????xxxxx????xxx????xx????xxxxxxx",
	//	&Hooking::m_presence_struct);

	/*setFn<GetNetPlayer>("m_GetNetPlayer",
		"\x48\x83\xEC\x28\x33\xC0\x38\x05\x00\x00\x00\x00\x74\x0A",
		"xxxxxxxx????xx",
		&m_GetNetPlayer);

	setFn<CNetworkPlayerMgr2>("m_NetworkPlayerMgr",
		"\x48\x8B\x0D\x00\x00\x00\x00\x8A\xD3\x48\x8B\x01\xFF\x50\x00\x4C\x8B\x07\x48\x8B\xCF\x48\x8B\xD0",
		"xxx????xxxxxxx?xxxxxxxxx",
		&m_NetworkPlayerMgr);*/


	//main_batch.add("SGSBGH", "E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24", [this](memory::handle ptr) //E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24 50
	//	{
	//		m_start_get_session_by_gamer_handle = ptr.add(1).rip().as<functions::start_get_session_by_gamer_handle>();
	//	});

	//// Presence Structure
	//main_batch.add("PS", "48 8D 0D ? ? ? ? 41 83 E0 10 E8 ? ? ? ? 44 38 3D ? ? ? ? 0F 85 ? ? ? ? 48 8D 4C 24", [this](memory::handle ptr)
	//	{
	//		m_presence_struct = ptr.add(3).rip().as<PVOID>();
	//	});

	//// Send Invite Accepted Presence Event
	//main_batch.add("SIAPE", "E8 ? ? ? ? E9 ? ? ? ? C6 05 ? ? ? ? ? E9", [this](memory::handle ptr)
	//	{
	//		 = ptr.add(1).rip().as<functions::send_invite_accepted_presence_event>();
	//	});

	/*auto p_RIDJoinHandle = pattern("40 53 48 83  EC 20 8B D9 83 F9 FE 75 1C E8 ? ? ? ? 48 85");
	auto p_RIDJoinFriends = pattern("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B D9");
	auto p_RIDJoinFriendsHandler = pattern("48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1 33 D2 E8");*/
	//m_RIDJoinFriendsHandler(Signature("48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1 33 D2 E8").Scan().As<int64_t*>()),
//m_RIDJoinHandle(Signature("40 53 48 83  EC 20 8B D9 83 F9 FE 75 1C E8 ? ? ? ? 48 85").Scan().As<decltype(m_RIDJoinHandle)>()),
//m_RIDJoinFriends(Signature("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B D9").Scan().As<decltype(m_RIDJoinFriends)>())
	/*auto p_NetworkInfo = pattern("44 8B 6C 24 ? 45 8B C6 48 8D 4E 70 41 8B D5 45 2B C5 4C 8D 4C 24 ? 03 D5 44 2B C5 49 03 D4 E8 ? ? ? ? 84 C0 74 69 - 0x64");*/
bool is_model_a_vehicle_check = checkpattern("40 53 48 83 EC 20 48 8D 54 24 ? 33 DB C7 44 24 ? ? ? ? ? E8 ? ? ? ? 48 85 C0 74 15 8A 80 9D ? ? ? 0F B6 DB BA 01 ? ? ? 24 1F 3C 05 0F");
if (is_model_a_vehicle_check)
{
	setFn<fpISMODELAVEHICLE>("is_model_a_vehicle",
		"\x40\x53\x48\x83\xEC\x20\x48\x8D\x54\x24\x00\x33\xDB\xC7\x44\x24\x00\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x15\x8A\x80\x9D\x00\x00\x00\x0F\xB6\xDB\xBA\x01\x00\x00\x00\x24\x1F\x3C\x05\x0F",
		"xxxxxxxxxx?xxxxx?????x????xxxxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::is_model_a_vehicle);
}
	/*setFn<fpHASMODELLOADED>("has_model_loaded",
		"\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x20\x8B\x45\x18\xBF",
		"xxxx?xxxxxxxxxxxx",
		&Hooking::has_model_loaded);*/

	bool request_model_check = checkpattern("48 89 5C 24 ? 48 89 7C 24 ? 55 48 8B EC 48 83 EC 50 8B 45 18");
	if (request_model_check)
	{
		setFn<fpREQUESTMODEL>("request_model",
			"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
			"xxxx?xxxx?xxxxxxxxxxx",
			&Hooking::request_model);
	}

	bool draw_rect_check = checkpattern("48 8B C4 48 89 58 08 57 48 83 EC 70 48 63 0D ? ? ? ? 0F");
	if (draw_rect_check)
	{
		//draw_rect
		setFn<fpDrawRect>("draw_rect",
			"\x48\x8B\xC4\x48\x89\x58\x08\x57\x48\x83\xEC\x70\x48\x63\x0D\x00\x00\x00\x00\x0F",
			"xxxxxxxxxxxxxxx????x",
			&CHooking::draw_rect);
	}

	////draw_line
	//setFn<fpDrawLine>("draw_line",
	//	"\x40\x53\x48\x83\xEC\x40\xF3\x0F\x10\x09\xF3\x0F\x10\x41\x00\xF3\x0F\x10\x51\x00\x45\x8B\xD0\xBB",
	//	"xxxxxxxxxxxxxx?xxxx?xxxx",
	//	&CHooking::draw_line, 
	//	1);	//skip 1, first one is draw_box

	bool draw_notification_check = checkpattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 83 3D ? ? ? ? ? 41 8A D8");
	if (draw_notification_check)
	{
		//draw_notification
		setFn<fpDrawNotification>("draw_notification",
			"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x81\xEC\x00\x00\x00\x00\x83\x3D\x00\x00\x00\x00\x00\x41\x8A\xD8",
			"xxxx?xxxx?xxxx????xx?????xxx",
			&CHooking::draw_notification);
	}

	bool get_network_time_check = checkpattern("40 53 48 83 EC 20 48 8B 0D ? ? ? ? E8 ? ? ? ? 84 C0 74 19 E8 ? ? ? ? 48 8D 15 ? ? ? ? 8B");
	if (get_network_time_check)
	{
		//get_network_time
		setFn<fpGetNetworkTime>("get_network_time",
			"\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19\xE8\x00\x00\x00\x00\x48\x8D\x15\x00\x00\x00\x00\x8B",
			"xxxxxxxxx????x????xxxxx????xxx????x",
			/*"\x40\x53\x48\x83\xEC\x20\x48\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x84\xC0\x74\x19",
			"xxxxxxxxx????x????xxxx",*/
			&CHooking::get_network_time);
	}
	bool create_ambient_pickup_check = checkpattern("48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8D 68 C1 48 81 EC 90 ? ? ? 45 8B F9 41 8B F0 4C 8B EA");
	if (create_ambient_pickup_check)
	{
		setFn<fpCreateAmbientPickup>("create_ambient_pickup",
			//"\x40\x53\x48\x83\xEC\x20\x48\x8B\xD9\x48\x8B\xCA\xE8\x00\x00\x00\x00\x3A\x43\x40\x0F\x94\xC0", //40 53 48 83 EC 20 48 8B D9 48 8B CA E8 ? ? ? ? 3A 43 40 0F 94 C0
			//"xxxxxxxxxxxxx????xxxxxx",
			"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x48\x89\x78\x20\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\x68\xC1\x48\x81\xEC\x90\x00\x00\x00\x45\x8B\xF9\x41\x8B\xF0\x4C\x8B\xEA",
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx???xxxxxxxxx",
			&Hooking::create_ambient_pickup);//48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8D 68 C1 48 81 EC 90 ? ? ? 45 8B F9 41 8B F0 4C 8B EA
	}
	/*setFn<SETVEHICLEFORWARDSPEED>("SET_VEHICLE_FORWARD_SPEED",
		"\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x10\x48\x89\x74\x24\x18\x57\x48\x83\xEC\x20\x0F\xB6\x42\x28",
		"xxxxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::SET_VEHICLE_FORWARD_SPEED);*/

	/*setFn<fpCreateAmbientPickup2>("create_ambient_pickup2",
		"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00",
		"xxxx?xxxxxxxxxxx????",
		&Hooking::create_ambient_pickup2);*/

	//setFn<fpSTARTPARTICLEFXNONLOOPEDONENTITY2>("_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2",
	//	"\xFB\xB8\x00\x00\x00\x00\x09\xF5", 
	//	"xx????xx",
	//	&Hooking::_START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2);
		// Check if the result is null


	bool stat_set_float_check = checkpattern("49 8B 80 ? ? ? ? 48 85 C0 74 0C F6 80 ? ? ? ? ? 75 03");
	if (stat_set_float_check)
	{
		//stat_set_float
		setFn<fpStatSetFloat>("stat_set_float",
			"\x49\x8B\x80\x00\x00\x00\x00\x48\x85\xC0\x74\x0C\xF6\x80\x00\x00\x00\x00\x00\x75\x03",
			"xxx????xxxxxxx?????xx",
			/*"\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40",
			"xxxx?xxxxx?xxxxx",*/
			&Hooking::stat_set_float);
	}

	else
	{		
			setFn<fpStatSetFloat>("stat_set_float",
				"\x48\x8B\xC8\xE8\xDC\x86\x00\x00 - 0x7C",
				"xxxxxx??",
				&Hooking::stat_set_float);
	}

	bool stat_set_bool_check = checkpattern("48 89 5C 24 ? F3 0F 11 4C 24 ? 57 48 83 EC 40");
	if (stat_set_bool_check)
	{
		//stat_set_bool
		setFn<fpStatSetBool>("stat_set_bool",
			"\x48\x89\x5C\x24\x00\xF3\x0F\x11\x4C\x24\x00\x57\x48\x83\xEC\x40",
			"xxxx?xxxxx?xxxxx",
			/*"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x57\x48\x83\xEC\x30\x48\x8B\xF2",
			"xxxxxxxxxxxxxxxxxxx",*/
			&Hooking::stat_set_bool);
	}
	bool stat_set_int_check = checkpattern("89 54 24 10 55 53 56 57 41 57");
	if (stat_set_int_check)
	{
		//stat_set_int
		setFn<fpStatSetInt>("stat_set_int",
			"\x89\x54\x24\x10\x55\x53\x56\x57\x41\x57",
			"xxxxxxxxxx",
			/*"\x48\x89\x5C\x24\x00\x88\x54\x24\x10\x57\x48\x83\xEC\x40",
			"xxxx?xxxxxxxxx",*/
			&Hooking::stat_set_int);
	}
	bool stat_get_int_check = checkpattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 05 ? ? ? ? 4C 8B D1");
	if (stat_get_int_check)
	{
		//stat_get_int
		setFn<fpStatGetInt>("stat_get_int",
			"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1",
			"xxxx?xxxx?xxxx?xxxxxxx????xxx",
			/*"\x48\x81\xEC\x00\x00\x00\x00\x80\x3D\x00\x00\x00\x00\x00\x74\x17",
			"xxx????xx?????xx",*/
			/*"\x48\x89\x5C\x24\x00\x48\x89\x7C\x24\x00\x55\x48\x8B\xEC\x48\x83\xEC\x50\x8B\x45\x18",
			"xxxx?xxxx?xxxxxxxxxxx",*/
			/*"\x48\x8B\xC4\x48\x89\x58\x10\x48\x89\x70\x18\x57\x48\x83\xEC\x30\x48\x8B\xF2",
			"xxxxxxxxxxxxxxxxxxx",*/
			&Hooking::stat_get_int);
	}
	bool trigger_script_event_check = checkpattern("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 56 41 57 48 8D A8 68 ? ? ? ? 81 EC 80 02 ? ? 45 8B");
	if (trigger_script_event_check)
	{
	setFn<fpTriggerScriptEvent>("trigger_script_event",
		//48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 56 41 57 48 8D A8 68 ? ? ? ? 81 EC 80 02 ? ? 45 8B
		/*"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x48\x8B\xE9",*/
		/*"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x68\x10\x48\x89\x70\x18\x48\x89\x78\x20\x41\x56\x48\x81\xEC\x00\x00\x00\x00\x45\x8B\xF0\x41\x8B\xF9",*/
		/*"xxxxxxxxxxxxxxxxxxxxxxxx????xxxxxx",*/
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x56\x41\x57\x48\x8D\xA8\x68\x00\x00\x00\x00\x81\xEC\x80\x02\x00\x00\x45\x8B",
		"xxxxxxxxxxxxxxxxxxxxxxxx????xxxx??xx",
		&Hooking::trigger_script_event);
	}
	//setFn<fpSetLobbyWeather>("set_lobby_weather",
	//	"\x48\x89\x5C\x24\x08\x48\x89\x74\x24\x10\x57\x48\x83\xEC\x20\x8B\xF1\x48\x8B\x0D\x00\x00\x00\x00\x8B\xFA\xB2\x01\x41\x8B\xD8",
	//	"xxxxxxxxxxxxxxxxxxxx????xxxxxxx",
	//	/*"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x40\x8A\xEA",
	//	"xxxx?xxxx?xxxx?xxxxxxxx",*/
	//	&Hooking::set_lobby_weather);
	//m_ScriptedGameEvents(Signature("40 53 48 81 EC ? ? ? ? 44 8B 81 ? ? ? ? 4C 8B CA 41 8D 40 FF 3D ? ? ? ? 77 42", "ScriptedGameEvents").Scan().As<decltype(m_ScriptedGameEvents)>()),
	
	bool get_event_data_check = checkpattern("48 89 5C 24 08 57 48 83 EC 20 49 8B F8 4C 8D 05 ? ? ? ? 41 8B D9 E8");
	if (get_event_data_check)
	{
	setFn<fpGetEventData>("get_event_data",
		/*"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x84\xA2\xD4\x00\x41\x8B\xD9\xE8\x04\xC7\x02\x00\x48\x85\xC0",
		"xxxxxxxxxxxxxxxxxxx?xxxxxxx?xxx",*/
		/*"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x24\xAD\xD6\x00\x41\x8B\xD9\xE8\xCC\xAE\x02\x00",
		"xxxxxxxxxxxxxxxxxxx?xxxxxxx?",*/
		"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\x00\x00\x00\x00\x41\x8B\xD9\xE8",
		"xxxxxxxxxxxxxxxx????xxxx",
		/*"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x49\x8B\xF8\x4C\x8D\x05\xD0\x58\xD5\x00\x41\x8B\xD9\xE8\xDC\xAB\x02\x00",
		"xxxxxxxxxxxxxxxxxxx?xxxxxxx?",*/
		&Hooking::get_event_data);
	//48 85 C0 74 14 4C 8B 10

	bool m_frameCount_check = checkpattern("8B 15 ? ? ? ? 41 FF CF");
	if (m_frameCount_check)
	{
	setPat<uint64_t>("frame count",
		"\x8B\x15\x00\x00\x00\x00\x41\xFF\xCF",
		"xx????xxx",
		&Hooking::m_frameCount,
		true,
		2);
	//8B 15 ? ? ? ? 41 FF CF").Scan().Add(2)
	}
	}
	bool is_DLC_present_check = checkpattern("48 89 5C 24 ? 57 48 83 EC 20 81 F9 ? ? ? ?");
	//bool is_DLC_present_check = checkpattern("84 C0 74 0D 8D 53 0C");
	if (is_DLC_present_check)
	{
		is_DLC_present_checked = 1;
		setFn<fpIsDLCPresent>("is_DLC_present",
			"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x81\xF9\x00\x00\x00\x00",
			"xxxx?xxxxxxx????",
			&Hooking::is_DLC_present);
		Log::Msg("dlc hook");		
	}
	else
	{
		is_DLC_present_checked = 1;
		setFn<fpIsDLCPresent>("is_DLC_present",
			"\x84\xC0\x74\x0D\x8D\x53\x0C - 0x3F",//63
			"xxxxxxx",
			&Hooking::is_DLC_present);
		Log::Msg("dlc 0x3F hook");
	}
	//m_IsDlcPresent(Signature("IDP", "84 C0 74 0D 8D 53 0C").Scan().Sub(63).As<decltype(m_IsDlcPresent)>()),

	bool create_vehicle_check = checkpattern("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 50 F3 0F 10 02");
	if (create_vehicle_check)
	{
		//create_vehicle
		setFn<fpCreateVehicle>("create_vehicle",
			"\x48\x89\x5C\x24\x00\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x50\xF3\x0F\x10\x02",
			"xxxx?xxxxxxxxxxxxxxxxxxxxxx",
			&CHooking::create_vehicle);//48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 50 F3 0F 10 02
	}
	//setFn<fpSetName>("SetName",
	//	"\x48\x8B\x05\x00\x00\x00\x00\xC3\x8A\xD1",
	//	"xxx????xxx",
	//	&Hooking::SetName);

	//setFn<fpIncrementStatHook>("increment_stat_hook",
	//	"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x48\x89\x7C\x24\x20\x55\x48\x8B\xEC\x48\x83\xEC\x60\x8B\x79\x30",//48 89 5C 24 ? 48 89 74 24 ? 55 57 41 55 41 56 41 57 8B EC 48 83 EC 60 8B 79 30 
	//	"xxxx?xxxx?xxxxxxxxxxxxxxxx",
	//	//"\x59\x98\x4D\x35\x00\x59\x98\x65\x35\x00\x44\x46\x50\x44\x50\x47\x50\x46\x59\x9A\xFD\x59\x92\xFD\x71\x9A\x68\x21",//48 89 5C 24 ? 48 89 74 24 ? 55 57 41 55 41 56 41 57 8B EC 48 83 EC 60 8B 79 30 
	//	//"xxxx?xxxx?xxxxxxxxxxxxxxxxxx",
	//	//"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x55\x57\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x60\x8B\x79\x30",//48 89 5C 24 ? 48 89 74 24 ? 55 57 41 55 41 56 41 57 8B EC 48 83 EC 60 8B 79 30 
	//	//"xxxx?xxxx?xxxxxxxxxxxxxxxxxx",
	//	&Hooking::increment_stat_hook);


	//48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8D 68 C1 48 81 EC ? ? ? ? 45 8B F9 41 8B F0 4C 8B EA E8 ? ? ? ? 0F B7 0D ? ? ? ? 33 FF 44 8B C7 44 8B D7 44 8B E0 85 C9 7E 1C 48 8B 1D

	//setFn<fpIsPedShooting>("is_ped_shooting",
	//	"\x48\x83\xEC\x28\xE9\x00\x00\x00\x00\x48\x8B\x45\x20", "xxxxx????xxxx",
	//	&Hooking::is_ped_shooting);

	//setFn<fpAddOwnedExplosion>("add_owned_explosion",
	//	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x70\x20\x55\x48\x8D\x6C\x24\x80\x48\x81\xEC\x80\x01\x00\x00\x0F\x29\x70\xE8\x41\x8B\xD8\x48\x8B\xF2\x0F\x28\xF3\x8B\xF9",
	//	"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx??xxxxxxxxxxxxxxx",
	//	&Hooking::add_owned_explosion);

	/*bool add_owned_explosion_check = checkpattern("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 56 41 57 48 8D 6C 24 80 48 81 EC 80 01 ? ? 0F 29 70 D8 41 8B F8 48 8B DA 0F 28 F3 8B F1");*/
	bool add_owned_explosion_check = checkpattern("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 60 20 55 41 56 41 57 48 8D 6C 24 80 48 81 EC 80 01 ? ? 0F 29 70 D8 41 8B F8 4C 8B FA 0F 28 F3 44 8B F1");
	if (add_owned_explosion_check)
	{
		setFn<fpAddOwnedExplosion>("add_owned_explosion",
			"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x60\x20\x55\x41\x56\x41\x57\x48\x8D\x6C\x24\x80\x48\x81\xEC\x80\x01\x00\x00\x0F\x29\x70\xD8\x41\x8B\xF8\x4C\x8B\xFA\x0F\x28\xF3\x44\x8B\xF1",
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx??xxxxxxxxxxxxxxxx",
			//"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x56\x41\x57\x48\x8D\x6C\x24\x80\x48\x81\xEC\x80\x01\x00\x00\x0F\x29\x70\xD8\x41\x8B\xF8\x48\x8B\xDA\x0F\x28\xF3\x8B\xF1",
			//"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx??xxxxxxxxxxxxxxx",
			&Hooking::add_owned_explosion);
	}
	// 48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 70 20 55 48 8D 6C 24 80 48 81 EC 80 01 ? ? 0F 29 70 E8 41 8B D8 48 8B F2 0F 28 F3 8B F9
	////40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C

	/*setPat<twoBytes>("m_ownedExplosionBypass",
		"\x74\x0F\x48\x8D\x4C\x24\x00\x45\x33\xC0",
		"xxxxxx?xxx",
		&CHooking::m_ownedExplosionBypass,
		false);*/

	//49 8B 80 ? ? ? ? 48 85 C0 74 0C F6 80 ? ? ? ? ? 75 03
	//B2 01 48 8B CD 45 8A E0 4D 0F 45 F9 E8 //aspire


	//setFn<fpGetPlayerPed>("get_player_ped",
	//	"\x48\x83\xEC\x28\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x1C\x8A\x88\x00\x00\x00\x00\xF6\xC1\x01\x75\x05\xF6\xC1\x02\x75\x0C",
	//	"xxxxxxx????xxxxxxx????xxxxxxxxxx",
	//	&Hooking::get_player_ped);
	bool GetPlayerAddress_check = checkpattern("40 53 48 83 EC 20 33 DB 38 1D ? ? ? ? 74 1C");
	if (GetPlayerAddress_check)
	{
		setFn<fpGetPlayerAddress>("GetPlayerAddress",
			"\x40\x53\x48\x83\xEC\x20\x33\xDB\x38\x1D\x00\x00\x00\x00\x74\x1C",
			"xxxxxxxxxx????xx",
			&Hooking::GetPlayerAddress);
	}
	/*48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07*/

	bool AddressToEntity_check = checkpattern("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 15 ? ? ? ? 48 8B F9 48 83 C1 10 33 DB");
	if (AddressToEntity_check)
	{
		setFn<fpAddressToEntity>("AddressToEntity",
			"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x15\x00\x00\x00\x00\x48\x8B\xF9\x48\x83\xC1\x10\x33\xDB",
			"xxxx?xxxx?xxxxxxx????xxxxxxxxx",
			&Hooking::AddressToEntity);
	}
	bool get_player_name_check = checkpattern("40 53 48 83 EC 20 80 3D ? ? ? ? ? 8B D9 74 22");
	if (get_player_name_check)
	{
		setFn<fpGetPlayerName>("get_player_name",
			"\x40\x53\x48\x83\xEC\x20\x80\x3D\x00\x00\x00\x00\x00\x8B\xD9\x74\x22",
			"xxxxxxxx?????xxxx",
			&Hooking::get_player_name);//40 53 48 83 EC 20 80 3D ? ? ? ? ? 8B D9 74 22
	}
	/*setFn<CNetworkIncrementStatEvent>("NetworkIncrementStatEvent",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x55\x57\x41\x55\x41\x56\x41\x57\x48\x8B\xEC\x48\x83\xEC\x60\x8B\x79\x30",
		"xxxx?xxxx?xxxxxxxxxxxxxxxxxx",
		&Hooking::NetworkIncrementStatEvent);*/

	

	//	//player name
	//setPat<void>("name changer",
	//	"\x48\x8B\x05\x00\x00\x00\x00\xC3\x8A\xD1",
	//	"xxx????xxx",
	//	&Hooking::m_onlineName,
	//	true,
	//	3,
	//	1);

	//setFn<fpGetPlayerPedScriptIndex>("get_player_ped_script_index",
	//	"\x48\x8b\x0d\x00\x00\x00\x00\xe8\x00\x00\x00\x00\x48\x8b\xc8\xe8\x00\x00\x00\x00\x48\x8b\xcf",
	//	"xxx????x????xxxx????xxx",
	//	&Hooking::get_player_ped_script_index);

	bool set_lobby_time_check = checkpattern("E8 ? ? ? ? 48 8B 4F 60 48 85 C9 0F 84");
	if (set_lobby_time_check)
	{
		setFn<fpSetLobbyTime>("set_lobby_time",
			"\xE8\x00\x00\x00\x00\x48\x8B\x4F\x60\x48\x85\xC9\x0F\x84",
			"x????xxxxxxxxx",
			/*"\x48\x89\x5C\x24\x08\x57\x48\x83\xEC\x20\x8B\xF9\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\xDA\x33\xD2\xE9\x00\x00\x00\x00",
			"xxxxxxxxxxxxxxx????xxxxxx????",*/
			/*"\x48\x8D\x0D\x00\x00\x00\x00\x8B\xFA\xE8\x00\x00\x00\x00\x44\x8D\x0C\x5B",
			"xxX????xxx????xxxx",*/
			/*"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xF9\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\xDA\x33\xD2",
			"xxxx?xxxxxxxxxx????xxxxx",*/
			&Hooking::set_lobby_time);
	}

	bool send_message2_check = checkpattern("48 89 5C 24 ? 57 48 83 EC 30 48 8B F9 48 8D 4C 24 ? 48 8B DA E8 ? ? ? ? 48 8D 4C 24 ? 41 B8 ? ? ? ? 48 8B D3 E8 ? ? ? ? 84 C0 74 14 48 8B 0D ? ? ? ? 4C 8D 44 24 ? 48 8B D7 E8 ? ? ? ? 32 C0 48 8B 5C 24 ?");
	if (send_message2_check)
	{
		setFn<fpSendMessage2>("send_message2",
			"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x30\x48\x8B\xF9\x48\x8D\x4C\x24\x00\x48\x8B\xDA\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\x41\xB8\x00\x00\x00\x00\x48\x8B\xD3\xE8\x00\x00\x00\x00\x84\xC0\x74\x14\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x44\x24\x00\x48\x8B\xD7\xE8\x00\x00\x00\x00\x32\xC0\x48\x8B\x5C\x24\x00",
			"xxxx?xxxxxxxxxxxx?xxxx????xxxx?xx????xxxx????xxxxxxx????xxxx?xxxx????xxxxxx?",
			&Hooking::send_message2);
	}


	bool pRegisterFile_check = checkpattern("48 89 5C 24 08 48 89 6C 24 18 48 89 7C 24 20 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9 B2 01 48 8B CD 45 8A E0 4D 0F 45 F9");
	if (pRegisterFile_check)
	{

		setFn<fpFileRegister>("pRegisterFile",
			"\x48\x89\x5C\x24\x08\x48\x89\x6C\x24\x18\x48\x89\x7C\x24\x20\x41\x54\x41\x56\x41\x57\x48\x83\xEC\x50\x48\x8B\xEA\x4C\x8B\xFA\x48\x8B\xD9\x4D\x85\xC9\xB2\x01\x48\x8B\xCD\x45\x8A\xE0\x4D\x0F\x45\xF9",
			"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
			&Hooking::pRegisterFile);
	}
	/*setFn<fpFileRegister>("pRegisterFile",
		"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x7C\x24\x00\x41\x54\x41\x56\x41\x57\x48\x83\xEC\x50\x48\x8B\xEA\x4C\x8B\xFA\x48\x8B\xD9\x4D\x85\xC9",
		"xxxx?xxxx?xxxx?xxxxxxxxxxxxxxxxxxxxxx",
		&Hooking::pRegisterFile);*/
	bool AddTextCompSubstrPlayerName_check = checkpattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 05 ? ? ? ? 4C 8B D1");
	if (AddTextCompSubstrPlayerName_check)
	{
		//add_text_comp_substr_playername
		setFn<fpAddTextCompSubstrPlayerName>("AddTextCompSubstrPlayerName",
			"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x20\x8B\x05\x00\x00\x00\x00\x4C\x8B\xD1",
			"xxxx?xxxx?xxxx?xxxxxxx????xxx",
			&Hooking::add_text_comp_substr_playername);
	}
	bool EndTextCmdDisplayText_check = checkpattern("40 53 48 83 EC 40 0F 29 74 24 ? 0F 29 7C 24 ? 41 8B D8");
	if (EndTextCmdDisplayText_check)
	{
		//end_text_cmd_display_text
		setFn<fpEndTextCmdDisplayText>("EndTextCmdDisplayText",
			"\x40\x53\x48\x83\xEC\x40\x0F\x29\x74\x24\x00\x0F\x29\x7C\x24\x00\x41\x8B\xD8",
			"xxxxxxxxxx?xxxx?xxx",
			&Hooking::end_text_cmd_display_text);
	}
	bool BeginTextCmdDisplayText_check = checkpattern("48 83 EC 28 E8 ? ? ? ? E8 ? ? ? ? 33 C9 48 85 C0");
	if (BeginTextCmdDisplayText_check)
	{
		//begin_text_cmd_display_text
		setFn<fpBeginTextCmdDisplayText>("BeginTextCmdDisplayText",
			"\x48\x83\xEC\x28\xE8\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xC9\x48\x85\xC0",
			"xxxxx????x????xxxxx",
			&Hooking::begin_text_cmd_display_text);
	}
	//setFn<fp_CreateObject>("create_object",
	//	"\xE9\x00\x00\x00\x00\x48\x85\xC0\x55\x48\xBD\xD8\x00\x00\x00\x00\x00\x00\x00\x48\x87\x2C\x24\x53\x50\x48\x8B\x5C\x24\x10\x48\xB8\x00\x00\x00\x00\x00\x00\x00\x00\x48\x0F\x44\xD8\x48\x89\x5C\x24\x10\x58\x5B\xC3\xE9\x00\x00\x00\x00\x6E\x15\x00\x00\x00\x00\xE8", "x????xxxxxxx???????xxxxxxxxxxxxx????????xxxxxxxxxxxxx????xx????x",
	//	&Hooking::create_object);

	//	//entity pool
	//setPat<MemoryPool*>("entity pool",
	//	"\x4C\x8B\x0D\x00\x00\x00\x00\x44\x8B\xC1\x49\x8B\x41\x08",
	//	"xxx????xxxxxxx",
	//	&CHooking::m_entityPool,
	//	true,
	//	3);

	////ped pool
	//setPat<MemoryPool*>("ped pool",
	//	"\x48\x8B\x05\x00\x00\x00\x00\x41\x0F\xBF\xC8\x0F\xBF\x40\x10", //48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 15 ? ? ? ? 48 8B F9 48 83 C1 10 33 DB
	//	"xxx????xxxxxxxx",
	//	&CHooking::m_pedPool,
	//	true,
	//	3);

	//setPat<threeBytes>("infinite ammo",
	//	"\x41\x2B\xD1\xE8",
	//	"xxxx",
	//	&CHooking::m_infAmmo,
	//	false);

	////no reload
	//setPat<threeBytes>("no reload",
	//	"\x41\x2B\xC9\x3B\xC8\x0F",
	//	"xxxxxx",
	//	&CHooking::m_noReload,
	//	false);

	bool set_vehicle_fixed_check = checkpattern("40 53 48 83 EC 20 E8 ? ? ? ? 48 8B D8 48 85 C0 74 28 4C 8B 10");
	if (set_vehicle_fixed_check)
	{
		//set_vehicle_fixed
		setFn<fpSetVehicleFixed>("set_vehicle_fixed",
			"\x40\x53\x48\x83\xEC\x20\xE8\x00\x00\x00\x00\x48\x8B\xD8\x48\x85\xC0\x74\x28\x4C\x8B\x10",
			"xxxxxxx????xxxxxxxxxxx",
			&CHooking::set_vehicle_fixed);
	}

	//setFn<fpNetworkShopBeginService>("network_shop_begin_service",
	//	"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x83\x0A\xFF",
	//	"xxxx?xxxx?xxxx?xxxxxxxx",
	//	&Hooking::network_shop_begin_service);

	////network_request_control_of_entity
	//setFn<fpNetworkRequestControlOfEntity>("network_request_control_of_entity",
	//	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x20\x8B\xD9\xE8\x00\x00\x00\x00\x84\xC0",
	//	"xxxx?xxxxxxxx????xx",
	//	&CHooking::network_request_control_of_entity);

	////set_vehicle_deformation_fixed
	//setFn<fpSetVehicleDeformationFixed>("set_vehicle_deformation_fixed",
	//	"\x48\x89\x5C\x24\x00\x57\x48\x83\xEC\x40\x48\x83\xB9\x00\x00\x00\x00\x00\x48\x8B\xD9",
	//	"xxxx?xxxxxxxx?????xxx",
	//	&CHooking::set_vehicle_deformation_fixed);

	//setFn<fpPlayerId>("player_id",
	//	"\x48\x83\xEC\x28\x80\x3D\x00\x00\x00\x00\x00\x74\x12\x48\x8B\x0D\x00\x00\x00\x00\xE8",
	//	"xxxxxx?????xxxxx????x",
	//	&Hooking::player_id);

	/*ridfunc = (ridHk)pattern("E9 ? ? ? ? 48 8B 0D ? ? ? ? 8B 51 20 E8 ? ? ? ? 4C 8B C0 48 85 C0 74 26 85 DB 78 22 0F B6 90 ? ? ? ? 48 6B D2 68 0F B7 4C 02 ? 3B D9 7D 0E 48 8B C3 48 C1 E0 04 4A 03 44 02 ? EB 07 48 8D 05 ? ? ? ? 48 83 C4 20 5B C3").count(1).get(0).get<decltype(ridfunc)>(-0x24);
	//joinsecfunc = (joinses)(pattern("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B D9 48 8B 0D ? ? ? ? 4C 8B FA 8B 51 20 45 33 E4 45 8A F4 E8 ? ? ? ? 8A 4B 76 48 8B F0 84 C9 75 25 48 85 C0 0F 84 ? ? ? ? 0F B6 80 ? ? ? ? 48 6B C0 68 0F B7 44 30 ? 39 83 ? ? ? ? 0F 8D").count(1).get(0).get<void*>());*/
	//new
	//m_JoinPattern(Signature("48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 48 89 48 08 55 41 54 41 55 41 56 41 57 48 8D 68 A8").Scan().As<decltype(m_JoinPattern)>()),
	bool Set_Model_As_No_Longer_Needed_check = checkpattern("40 53 48 83 EC 30 48 8D 54 24 ? 8B D9");
	if (Set_Model_As_No_Longer_Needed_check)
	{
		setFn<fpSetModelAsNoLongerNeeded>("Set_Model_As_No_Longer_Needed",
			"\x40\x53\x48\x83\xEC\x30\x48\x8D\x54\x24\x00\x8B\xD9", //40 53 48 83 EC 30 48 8D 54 24 ? 8B D9
			"xxxxxxxxxx?xx",
			&CHooking::Set_Model_As_No_Longer_Needed);
	}

	bool get_message_check = checkpattern("4D 85 C9 0F 84 ? ? ? ? 48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 54 41 55 41 56 41 57 48 8D A8");
	if (get_message_check)
	{
		get_message_checked = 1;
		setFn<fpChatMessage>("get_message",
			"\x4D\x85\xC9\x0F\x84\x00\x00\x00\x00\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\xA8",
			/*"\x4D\x85\xC9\x0F\x84\x00\x00\x00\x00\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x4C\x89\x48\x20",*/
			"xxxxx????xxxxxxxxxxxxxxxxxxxxxxxxxxx",
			&Hooking::get_message); //4D 85 C9 0F 84 ? ? ? ? 48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 54 41
		//4D 85 C9 0F 84 ? ? ? ? 48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 54 41 55 41 56 41 57 48 8D A8
	}

	/*bool get_sender_check = checkpattern("E8 ? ? ? ? 48 85 C0 0F 84 49 02 ? ? 48 8B 10 48 8B C8 FF 52 68");*/
	bool get_sender_check = checkpattern("E8 ? ? ? ? 48 85 C0 0F 84 45 02 ? ? 48 8B 10 48 8B C8 FF 52 68");

	if (get_sender_check)
	{
	setPat<fpGetSender>("get_sender",
		"\xE8\x00\x00\x00\x00\x48\x85\xC0\x0F\x84\x45\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x68",
		/*"\xE8\x00\x00\x00\x00\x48\x85\xC0\x0F\x84\x49\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x68",*/
		//"\xE8\x00\x00\x00\x00\x48\x85\xC0\x0F\x84\x3F\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x68",
		/*"\xE8\x00\x00\x00\x00\x48\x8B\x0D\x00\x00\x00\x00\x48\x8B\xF0\xE8\x00\x00\x00\x00\x33\xFF\x48\x89\x44\x24\x00",
		"x????xxx????xxxx????xxxxxx?",*/
		//"\xE8\x00\x00\xDC\x00\x48\x85\xC0\x0F\x84\x3F\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x68",
		/*"\xE8\x00\x00\xDB\x00\x48\x85\xC0\x0F\x84\x3F\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x60",*/
		//"\xE8\x00\x00\xDB\x00\x48\x85\xC0\x0F\x84\x11\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x60",
		//"x??x?xxxxxxx??xxxxxxxxx",
		"x????xxxxxxx??xxxxxxxxx",
		//"x????xxxxx?x??xxxxxxxxx", //49 02 00 or ? 02 ?
		//"\xE8\x9A\x24\xDB\x00\x48\x85\xC0\x0F\x84\x11\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x60",
		//"xxxx?xxxxxxx??xxxxxxxxx",
		/*"\xE8\xBA\x58\xDA\x00\x48\x85\xC0\x0F\x84\x11\x02\x00\x00\x48\x8B\x10\x48\x8B\xC8\xFF\x52\x60",
		"xxxx?xxxxxxx??xxxxxxxxx",*/
		/*"\xE8\xBE\x9A\x0F\x01\x48\x8B\x05\xFB\x26\x66\x02\x83\xB8\xA0\x1F\x02\x00\x04\x0F\x85\xD9",
		"xxxxxxxxxxxxxxxxx?xxxx",*/
		&hook_sender::get_sender,
		true,
		1);//MP_CHAT_TEAM //E8 BA 58 DA ? 48 85 C0 0F 84 11 02 ? ? 48 8B 10 48 8B C8 FF 52 60
	}

	//E8 9A 24 DB ? 48 85 C0 0F 84 11 02 ? ? 48 8B 10 48 8B C8 FF 52 60
	//E8 ? ? DB ? 48 85 C0 0F 84 3F 02 ? ? 48 8B 10 48 8B C8 FF 52 60
	// 
	//GlobalBase hook_sender::baseGlobal;
	/*m_GlobalBase(Signature("4C 8D 4D 08 48 8D 15 ? ? ? ? 4C 8B C0", "GlobalBase").Scan().Add(7).Rip().As<decltype(m_GlobalBase)>()),
		std::uint64_t** m_GlobalBase;*/

	/*setPat<GlobalBase>("baseGlobal",
		"\x4C\x8D\x4D\x08\x48\x8D\x15\x00\x00\x00\x00\x4C\x8B\xC0",
		"xxxxxxx????xxx",
		&hook_sender::baseGlobal,
		true,
		7);*/


	/*GameVariables1::GameVariables1();*/
	/*setFn<fpNetworkSessionKickPlayer>("m_GetChatPlayerID",
		"\x48\x83\xEC\x38\xB2\x01\xE8\x00\x00\x00\x00\x48\x85\xC0\x74\x21",
		"xxxxxxx????xxxxx",
		&Hooking::network_session_kick_player);*/



	//setFn<fpNetworkIsSessionStarted>("network_is_session_started",
//	"\x40\x38\x35\x00\x00\x00\x00\x75\x0E\x4C\x8B\xC3\x49\x8B\xD7\x49\x8B\xCE",
//	"xxx????xxxxxxxxxxx",
//	&Hooking::network_is_session_started);


	/*setFn<fpNetworkCreateSynchronisedScene>("create_synchronised_scene",
		"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x48\x89\x78\x18\x55\x48\x8D\x68\xC1",
		"xxxxxxxxxxxxxxxxxxxx",
		&SyncScene::create_synchronised_scene);

	setFn<fpNetworkAddPedToSynchronisedScene>("add_ped_to_synchronised_scene",
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x50\x49\x8B\xD9",
		"xxxx?xxxx?xxxxxxxx",
		&SyncScene::add_ped_to_synchronised_scene);

	setFn<fpNetworkStartSynchronisedScene>("start_synchronised_scene",
		"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x8B\xD9\x44\x8B\xC1\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x85\xDB\x78\x12",
		"xxxxx????xxxxxxxx????xxxx?x????xxxx",
		&SyncScene::start_synchronised_scene);*/
	/*setFn<fpNetworkStartSynchronisedScene>("start_synchronised_scene",
		"\x40\x53\x48\x81\xEC\x00\x00\x00\x00\x8B\xD9\x44\x8B\xC1\x48\x8D\x15\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x85\xDB\x78\x12\x8B\xCB\xE8\xD6\x7C\x39\x00\x84\xC0\x74\x07\x8B\xCB",
		"xxxxx????xxxxxxxx????xxxx?x????xxxxxxxxxx?xxxxxx",
		&SyncScene::start_synchronised_scene);*/
	Log::Msg("Location...");
	char * c_location = nullptr;
	void * v_location = nullptr;

//_START_SHAPE_TEST_RAY  = 41 8B CE C7 85 ?? ?? ?? ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? B2 - 0xFE
	//_GET_RAYCAST_RESULT = 48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 56 41 57 48 8B EC 48 83 EC 60 33 DB
	
	/*bool* b_location = nullptr;
	auto sessionstart = Memory::pattern("40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE");
	b_location = (bool*)sessionstart.count(3).get(0).get<bool*>(0);
	Hooking::network_is_session_started = reinterpret_cast<fpNetworkIsSessionStarted>((bool)b_location);*/

	/*Log::Msg("ExplosionBypass...");*/
	auto p_bypass = Memory::pattern("3B F8 40 0F 94 C7");
	/*auto p_bypass = Memory::pattern("0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8");*/
	c_location = p_bypass.count(1).get(0).get<char>(0);
	CHooking::m_ownedExplosionBypass = (twoBytes*)c_location;

	//48 83 EC 48 48 8B 49 10 33

	//c_location = p_bypass.count(1).get(0).get<char>(0);
	//CHooking::m_ownedExplosionBypass = (twoBytes*)c_location;

	//auto p_bypass = Memory::pattern("48 8B F1 74 56");
	///*auto p_bypass = Memory::pattern("0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8");*/
	//c_location = p_bypass.count(1).get(0).get<char>(0);
	//CHooking::m_ownedExplosionBypass = (BYTE*)c_location;

	Sleep(5000);
	Log::Msg("Getting Game State...");
	c_location = p_gameState.count(1).get(0).get<char>(2);
	c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);

	//c_location = p_gameState.count(1).get(0).get<char>(0);
	//c_location == nullptr ? FailPatterns("gameState") : m_gameState = reinterpret_cast<decltype(m_gameState)>(c_location + *(int32_t*)c_location + 5);
	//m_GameState
	//m_gameState = p_gameState.Memory::add(2).rip().add(1).as<GameState*>();

	/*char m_gameState1[100];
	sprintf_s(m_gameState1, (char*)"0x%#p 0x%llX", (char*)m_gameState - Memory::get_base());
	Log::Msg(m_gameState1);*/

	Log::Msg("Getting vector3 result fixer func...");
	v_location = p_fixVectorResult.count(1).get(0).get<void>(0);
	/*if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);*/
	if (v_location != nullptr) scrNativeCallContext::SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);
	//if (v_location != nullptr) SetVectorResults = (void(*)(scrNativeCallContext*))(v_location);
	//char SetVectorResults2[100];
	///*sprintf_s(SetVectorResults2, (char*)"0x%#p 0x%llX", (char*)scrNativeCallContext::SetVectorResults - Memory::get_base());*/
	//sprintf_s(SetVectorResults2, (char*)"0x%#p 0x%llX", (char*)rage::scrNativeCallContext::SetVectorResults - Memory::get_base());
	//Log::Msg(SetVectorResults2);

	Log::Msg("Getting native registration table...");
	c_location = p_nativeTable.count(1).get(0).get<char>(9);
	c_location == nullptr ? FailPatterns("native registration table") : m_registrationTable = reinterpret_cast<decltype(m_registrationTable)>(c_location + *(int32_t*)c_location + 4);

	/*char m_registrationTable2[100];
	sprintf_s(m_registrationTable2, (char*)"0x%#p 0x%llX", (char*)m_registrationTable - Memory::get_base());
	Log::Msg(m_registrationTable2);*/

	/*Log::Msg("Getting World Pointer...");
	c_location = p_worldPtr.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("world Pointer") : m_worldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;*/

	/*char m_worldPtr2[100];
	sprintf_s(m_worldPtr2, (char*)"0x%#p 0x%llX", (char*)m_worldPtr - Memory::get_base());
	Log::Msg(m_worldPtr2);*/

	/*mg_GlobalBase->GlobalBase(Signature("4C 8D 4D 08 48 8D 15 ? ? ? ? 4C 8B C0").Scan().Add(7).Rip().As<decltype(mg_GlobalBase->GlobalBase)>());*/

	Log::Msg("Getting Blip List...");
	c_location = p_blipList.count(1).get(0).get<char>(0);
	c_location == nullptr ? FailPatterns("blip List") : m_blipList = (BlipList*)(c_location + *reinterpret_cast<int*>(c_location + 3) + 7);

	/*char m_blipList2[100];
	sprintf_s(m_blipList2, (char*)"0x%#p 0x%llX", (char*)m_blipList - Memory::get_base());
	Log::Msg(m_blipList2);*/

	//uintptr_t base_address = uintptr_t(GetModuleHandleA(0));
	//auto ptr = reinterpret_cast<char*>(base_address + 0xCE5EB5); // 48 85 C0 0F 84 00 00 00 00 8B 48 50
	//ptr == nullptr ? Log::Error("Failed to find modelCheck_pattern") : /*Memory::nop(ptr, 24)*/ptr;

	bool pattern_modelCheck_check = checkpattern("48 85 C0 0F 84 ? ? ? ? 8B 48 50");
	if (pattern_modelCheck_check)
	{
		Log::Msg("Model Check..");
		CPattern pattern_modelCheck("\x48\x85\xC0\x0F\x84\x00\x00\x00\x00\x8B\x48\x50", "xxxxx????xxx");
		auto ptr = pattern_modelCheck.find(0).get(0).get<char>(0);
		ptr == nullptr ? Log::Error("Failed to find modelCheck_pattern") : Memory::nop(ptr, 24);
	}
	else
	{
		Log::Msg("Alternative Model Check.. 48 85 C0 74 21 E8 44 - 0x22");
		//48 85 C0 74 21 E8 44 - 0x22
		CPattern pattern_modelCheck("\x48\x85\xC0\x74\x21\xE8\x44 - 0x22", "xxxxxxx");
		auto ptr = pattern_modelCheck.find(0).get(0).get<char>(0);
		ptr == nullptr ? Log::Error("Failed to find modelCheck_pattern") : Memory::nop(ptr, 24);
	}
	bool pattern_modelSpawn_check = checkpattern("48 8B C8 FF 52 30 84 C0 74 05 48");
	if (pattern_modelSpawn_check)
	{
		Log::Msg("Bypassing Object restrictions..");
		CPattern pattern_modelSpawn("\x48\x8B\xC8\xFF\x52\x30\x84\xC0\x74\x05\x48", "xxxxxxxxxxx");
		auto ptr2 = pattern_modelSpawn.find(0).get(0).get<char>(8);
		ptr2 == nullptr ? Log::Error("Failed to find modelSpawn_pattern") : Memory::nop(ptr2, 2);
	}
	else
	{
		Log::Msg("Alternative Bypassing Object restrictions.. 48 83 EC 28 80 3D B1 79 - 0x22");
		CPattern pattern_modelSpawn("\x48\x83\xEC\x28\x80\x3D\xB1\x79 - 0x22", "xxxx?xxx");
		auto ptr2 = pattern_modelSpawn.find(0).get(0).get<char>(8);
		ptr2 == nullptr ? Log::Error("Failed to find modelSpawn_pattern") : Memory::nop(ptr2, 2);
	}
	//48 8B C8 FF 52 30 84 C0 74 05 48

	/*Log::Msg("Getting active script thread...");
	c_location = p_activeThread.count(1).get(0).get<char>(1);
	c_location == nullptr ? FailPatterns("Active Script Thread") : GetActiveThread = reinterpret_cast<decltype(GetActiveThread)>(c_location + *(int32_t*)c_location + 4);*/
	
	/*char GetActiveThread2[100];
	sprintf_s(GetActiveThread2, (char*)"0x%#p 0x%llX", (char*)GetActiveThread - Memory::get_base());
	Log::Msg(GetActiveThread2);*/

	Log::Msg("Getting World Pointer...");
	c_location = p_globalPtr.count(1).get(0).get<char>(0);
	__int64 patternAddr = NULL;
	c_location == nullptr ? FailPatterns("globalTable") : patternAddr = reinterpret_cast<decltype(patternAddr)>(c_location);
	m_globalPtr = (__int64**)(patternAddr + *(int*)(patternAddr + 3) + 7);

	/*char m_globalPtr2[100];
	sprintf_s(m_globalPtr2, (char*)"0x%#p 0x%llX", (char*)m_globalPtr - Memory::get_base());
	Log::Msg(m_globalPtr2);*/

	/*auto WaypointCoords = Memory::pattern("74 1F F3 0F 10 05 ? ? ? ? F3 0F 11 03");
	c_location = WaypointCoords.count(6).get(0).get<char>(0);
	WayPointCoords::m_WaypointCoords = (Vector2*)c_location;*/

	Log::Msg("Getting Event Hook...");
	if ((c_location = p_eventHook.count(1).get(0).get<char>(0)))
	{
		int i = 0, j = 0, matches = 0, found = 0;
		char* pattern = "\x4C\x8D\x05";
		while (found != EVENT_COUNT)
		{
			if (c_location[i] == pattern[j])
			{
				if (++matches == 3)
				{
					EventPtr.push_back((void*)(reinterpret_cast<uint64_t>(c_location + i - j) + *reinterpret_cast<int*>(c_location + i + 1) + 7));
					found++;
					j = matches = 0;
				}
				j++;
			}
			else
			{
				matches = j = 0;
			}
			i++;
		}
	}

	Log::Msg("Initializing natives...");
	CrossMapping::initNativeMap();



	//g_NativeInvoker = std::make_unique<NativeInvoker>();

	//Log::Msg("After CacheHandlersImpl");
	//g_NativeHooks = std::make_unique<NativeHooks>();

	//g_NativeHooks = new NativeHooks;

	//Log::Msg("Before native_hook");

	Log::Msg("Before CacheHandlersImpl");
	g_NativeInvoker->CacheHandlersImpl();

	std::unique_ptr<NativeHooks> native_hook;
	native_hook = std::make_unique<NativeHooks>();

	/*std::unique_ptr<ScriptHook> script_hook;
	script_hook = std::make_unique<ScriptHook>();*/

	/*std::unique_ptr<NativeHooks> native_hook1 = std::make_unique<NativeHooks>();
	std::unique_ptr<NativeHooks> native_hook2 = std::make_unique<NativeHooks>();*/

	Log::Msg("After native_hook");

	//std::unique_ptr<NativeHooks> native_hook = std::make_unique<NativeHooks>();
	//std::unique_ptr<NativeHooks> native_hook = std::make_unique<NativeHooks>();

	//g_NativeHooks = std::make_unique<NativeHooks>().get();


	g_CallbackScript = std::make_shared<CallbackScript>();

	//g_scriptManager->AddScript(g_CallbackScript);
	/**m_gameState*/
	/*GameStatePlaying*/

	Log::Msg("Checking if GTA V is ready...");
	/*while (*g_GameVariables->m_GameState != (int32_t)eGameState::Playing) {*/
	while (*m_gameState != eGameState::Playing) {
		Sleep(200);
	}
	Log::Msg("GTA V ready!");
}

static Hooking::NativeHandler _Handler(uint64_t origHash)
{
	uint64_t newHash = CrossMapping::MapNative(origHash);
	if (newHash == 0)
	{
		return nullptr;
	}

	Hooking::NativeRegistrationNew * table = m_registrationTable[newHash & 0xFF];

	for (; table; table = table->getNextRegistration())
	{
		for (uint32_t i = 0; i < table->getNumEntries(); i++)
		{
			if (newHash == table->getHash(i))
			{
				return table->handlers[i];
			}
		}
	}
	return nullptr;
}

Hooking::NativeHandler Hooking::GetNativeHandler(uint64_t origHash)
{
	auto& handler = m_handlerCache[origHash];

	if (handler == nullptr)
	{
		handler = _Handler(origHash);
	}

	return handler;
}

eGameState Hooking::GetGameState()
{
	return *m_gameState;
}

uint64_t Hooking::getWorldPtr()
{
	return g_GameVariables->m_WorldBase;
	//return m_worldPtr;
}
void WAIT(DWORD ms)
{
	wakeAt = timeGetTime() + ms;
	SwitchToFiber(mainFiber);
}

//void script::tick2()
//{
//		script st;
//		st.tick();
//}
void script::tick()
{
	m_main_fiber = GetCurrentFiber();
	if (!m_wake_time.has_value() || m_wake_time.value() <= std::chrono::high_resolution_clock::now())
	{
		SwitchToFiber(m_script_fiber);
	}
}
script* script::get_current()
{
	return static_cast<script*>(GetFiberData());
}

//void little_sleep(std::chrono::microseconds us)
//{
//	auto start = std::chrono::high_resolution_clock::now();
//	auto end = start + us;
//	do {
//		std::this_thread::yield();
//	} while (std::chrono::high_resolution_clock::now() < end);
//}

void script::yield(std::optional<std::chrono::high_resolution_clock::duration> time)
{
	//script::tick();
	////std::this_thread::sleep_for(std::chrono::milliseconds(1));
	//if (time.has_value())
	//{
	//	m_wake_time = std::chrono::high_resolution_clock::now() + time.value();
	//}
	//else
	//{
	//	m_wake_time = std::nullopt;
	//}

	//SwitchToFiber(m_main_fiber);
	/*auto start = std::chrono::high_resolution_clock::now();

	little_sleep(std::chrono::microseconds(1000));*/

	/*auto elapsed = std::chrono::high_resolution_clock::now() - start;
	std::cout << "waited for "
		<< std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
		<< " microseconds\n";*/
}

//void WAIT2(DWORD ms)
//{
//	wakeAt2 = timeGetTime() + ms;
//	if (m_main_fiber == nullptr)
//		m_main_fiber = winbase::ConvertThreadToFiber2(nullptr);
//	winbase::SwitchToFiber2(m_main_fiber);
//	if (timeGetTime() < wakeAt2)
//		return;
//
//	static HANDLE scriptFibers;
//
//	if (scriptFibers)
//		winbase::SwitchToFiber2(scriptFibers);
//	else
//		scriptFibers = winbase::CreateFiber2(NULL, ScriptFunction, nullptr);
//
//
//}
DWORD WINAPI CleanupThread(LPVOID lpParam)
{
	for (int i = 0; i < Hooking::m_hooks.size(); i++)
		MH_QueueDisableHook(Hooking::m_hooks[i]);
	MH_ApplyQueued();
	MH_Uninitialize();
	iHook.Remove();
	FreeLibraryAndExitThread(Hooking::_hmoduleDLL, 0);
}
void Hooking::Cleanup()
{
	Log::Msg("Cleaning up hooks");
	CreateThread(nullptr, THREAD_ALL_ACCESS, CleanupThread, nullptr, NULL, nullptr);
}

__int64** Hooking::getGlobalPtr()
{
	return m_globalPtr;
}

__int64 * Hooking::getGlobalPatern(int index)
{
	return &m_globalPtr[index >> 0x12 & 0x3F][index & 0x3FFFF];
}

Ped Hooking::get_player_ped(Player player)
{
	const auto addr = Hooking::GetPlayerAddress(player);

	if (addr) {
		return Hooking::AddressToEntity(addr);
	}

	return NULL;
}

//GameFunctions::GameFunctions() :
//	m_JoinPattern(Signature("48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 48 89 48 08 55 41 54 41 55 41 56 41 57 48 8D 68 A8").Scan().As<decltype(m_JoinPattern)>())
//{
//}



//link-https://x64dbg.com/#start //attach+Symboles+Scylla+dump
//link-http://openiv.com/ //save-content
//link--GTA5Epic\GTAV\update\update.rpf\x64\levels\gta5\script\script_rel.rpf\ or search freemode.ysc

//link-https://github.com/zorg93/GTA-V-Script-Decompiler


//link-https://cheatengine.org/
//link-https://github.com/ajkhoury/SigMaker-x64/releases
//link-https://www.unknowncheats.me/forum/grand-theft-auto-v/241414-tool-sigconvert-v1-0-a.html
//link-https://www.unknowncheats.me/forum/downloads.php?do=file&id=21645

//link-https://www.unknowncheats.me/forum/grand-theft-auto-v/291574-gta5-ida-native-name-plugin.html#post2190332
//link-https://www.unknowncheats.me/forum/downloads.php?do=file&id=24186

//link-http://dev-c.com/nativedb/
//link-http://dev-c.com/nativedb/natives.h
//link-https://alloc8or.re/gta5/nativedb/
//link-https://github.com/TsudaKageyu/minhook
//linkhttps://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
//linkhttps://www.mediafire.com/file/mlejm942ls4fl1g/-reclass-.zip/file
//OpenMenu = 106
//OpenMenu8 = 104
//OpenMenu6 = 102
//OpenMenu5 = 101
//OpenMenu4 = 100
//OpenMenu2 = 98
//OpenMenu0 = 96
//linkhttps://www.gta-modding.com/iv/tutorials/virtual_key_codes.html
//OpenMenu = 123 //f12
//OpenMenu8 = 38 //up arrow
//OpenMenu6 = 39 //right arrow
//OpenMenu5 = 13 //enter
//OpenMenu4 = 37 //left arrow 
//OpenMenu2 = 40 //down arrow
//OpenMenu0 = 8 //backspace

//linkhttps://gtaforums.com/topic/795245-v-control-codes-for-gamepads/
//A - 73 - 70 - 21 - 18
//X - 99 - 22
//Y - 75 - 56 - 53 - 49 - 23
//B - 80 - 45
//L3 - 86 - 28
//R3 - 79 - 93 - 50 - 29 - 26
//LB - 68 - 89 - 38 - 37
//RB - 69 - 76 - 90 - 55 - 44
//LT - 77 - 72 - 88 - 91 - 25 - 15 - 10
//RT - 78 - 71 - 87 - 92 - 46 - 24 - 14 - 11
//DPUP - 42 - 27
//DPDN - 48 - 43 - 20 - 19
//DPLT - 85 - 58 - 52 - 47
//DPRT - 74 - 54 - 51
//RSRT - 66 - 13 - 6
//RSLT - 5
//RSUP - 3
//RSDN - 67 - 12 - 4 - 2
//LSRT - 64 - 59 - 35 - 30 - 9 - 1
//LSLT - 63 - 34
//LSUP - 61 - 40 - 32
//LSDN - 60 - 41 - 39 - 33 - 31 - 8
//CTRL - 62 - 36

//link-https://www.unknowncheats.me/forum/red-dead-redemption-2-a/368296-rdr2-ida-native-name-script.html
//link-https://www.unknowncheats.me/forum/grand-theft-auto-v/314122-crosstable.html
//link-http://www.mediafire.com/file/mlejm942ls4fl1g/-reclass-.zip
//link-https://www.unknowncheats.me/forum/grand-theft-auto-v/149574-patch-own-script-hook.html

//link-https://stackoverflow.com/questions/41308933/how-to-enable-c17-compiling-in-visual-studio
//for compile with /std:c++17 clear the "default" in Properties > C/C++ > Language

//kick player
//vVar0.x = -442306200;
//vVar0.y = unk_0x460153A63B9477BC();
//iVar1 = 0;
//while (iVar1 < *iParam1)
//
//	vVar0.x = -1559754940;
//vVar0.y = unk_0x460153A63B9477BC();
//iVar1 = 0;
//while (iVar1 < *iParam1)
//
//	vVar0.x = -1252906024;
//vVar0.y = unk_0x460153A63B9477BC();
//iVar1 = 0;
//while (iVar1 < *iParam1)
//
//	vVar0.x = -1890951223;
//vVar0.y = unk_0x460153A63B9477BC();
//iVar1 = 0;
//while (iVar1 < *iParam1)










//vVar0.x = -508465573;
//vVar0.y = unk_0x1146A9AE09CE2B14();
//iVar1 = 0;
//while (iVar1 < *iParam1)
//
//	vVar0.x = 1456052554;
//vVar0.y = unk_0x1146A9AE09CE2B14();
//iVar1 = 0;
//while (iVar1 < *iParam1)
//
//	vVar0.x = -1382676328;
//vVar0.y = unk_0x1146A9AE09CE2B14();
//iVar1 = 0;
//while (iVar1 < *iParam1)
//
//	vVar0.x = 1810531023;
//vVar0.y = unk_0x1146A9AE09CE2B14();
//iVar1 = 0;
//while (iVar1 < *iParam1)

//bool Hooks::increment_stat_event(CNetworkIncrementStatEvent* event_struct, CNetGamePlayer* sender, int64_t a3)
//{
//	const auto hash = *reinterpret_cast<DWORD*>(event_struct + 0x30);
//	auto sender_id = *reinterpret_cast<std::int8_t*>(sender + 0x2D);
//	auto sender_name = PLAYER::GET_PLAYER_NAME(sender_id);
//
//	Log::Msg("Blocked event sent by %s", sender_name, stat);
//	protectionNotify(sender_name, "Blocked", sender_name);
//
//	switch (hash)
//	{
//	case 0xcbfd04a4 /* MPPLY_GAME_EXPLOITS */:
//	case 0x0e7072cd /* MPPLY_VC_HATE */:
//	case 0x9f79ba0b /* MPPLY_EXPLOITS */:
//	case 0x762f9994 /* MPPLY_TC_ANNOYINGME */:
//	case 0xb722d6c0 /* MPPLY_TC_HATE */:
//
//		/*LOG(INFO) << "Blocked report from %", sender_name;*/
//
//		return false;
//	default:
//		break;
//	}
//
//	return true;
//}

//bool Hooks::IncrementStatEvent(uint64_t net_event_struct, int64_t sender, int64_t unk)
//{
//	const auto hash = *reinterpret_cast<DWORD*>(net_event_struct + 0x30);
//	auto sender_id = *reinterpret_cast<std::int8_t*>(sender + 33);
//	auto sender_name = PLAYER::GET_PLAYER_NAME(sender_id);
//
//	switch (hash)
//	{
//	case 0x9C6A0C42: //MPPLY_GRIEFING
//	case 0x62EB8C5A: //MPPLY_VC_ANNOYINGME
//	case 0x0E7072CD: //MPPLY_VC_HATE
//	case 0x762F9994: //MPPLY_TC_ANNOYINGME
//	case 0xB722D6C0: //MPPLY_TC_HATE
//	case 0x3CDB43E2: //MPPLY_OFFENSIVE_LANGUAGE
//	case 0xE8FB6DD5: //MPPLY_OFFENSIVE_TAGPLATE
//	case 0xF3DE4879: //MPPLY_OFFENSIVE_UGC
//	case 0xAA238FF0: //MPPLY_BAD_CREW_NAME
//	case 0x03511A79: //MPPLY_BAD_CREW_MOTTO
//	case 0x3B566D5C: //MPPLY_BAD_CREW_STATUS
//	case 0x368F6FD9: //MPPLY_BAD_CREW_EMBLEM
//	case 0xCBFD04A4: //MPPLY_GAME_EXPLOITS
//	case 0x9F79BA0B: //MPPLY_EXPLOITS
//
//		/*if (Hooking::report_protection)
//		{
//			if (Hooking::notify_all_network_event)
//				Hooks::ProtectionNotification(Obfuscate("Protection"), (char*)Obfuscate("Event: Report\nStatus: Blocked\nFrom: %s"), sender_name);
//
//
//			if (redirect_report_received_int == 1)
//			{
//				if (Hooking::notify_all_network_event)
//					Hooks::ProtectionNotification(Obfuscate("Protection"), (char*)Obfuscate("Event: Kick\nStatus: Redirecting\nTo: %s"), sender_name);
//				g_FiberScript->addTask([sender_id]() { m_remote::InstantKick(sender_id); });
//			}
//			return true;
//		}*/
//	/*default:
//		break;*/
//	}


//bool __cdecl ThunderHooks2::IncrementStatEvent(CNetworkIncrementStatEvent* net_event, CNetGamePlayer2* sender)
//{
//			const auto hash = *reinterpret_cast<DWORD*>(net_event + 0x30);
//		auto sender_id = *reinterpret_cast<std::int8_t*>(sender + 33);
//		auto sender_name = PLAYER::GET_PLAYER_NAME(sender_id);
//		stringstream ss;
//		ss << sender_name;
//		std::string mapnotify = "~w~ Kick " + ss.str();
//	switch (net_event->m_stat)
//	{
//	case RAGE_JOAAT("MPPLY_BAD_CREW_STATUS"):
//	case RAGE_JOAAT("MPPLY_BAD_CREW_MOTTO"):
//	case RAGE_JOAAT("MPPLY_BAD_CREW_NAME"):
//	case RAGE_JOAAT("MPPLY_BAD_CREW_EMBLEM"):
//	case RAGE_JOAAT("MPPLY_EXPLOITS"):
//	case RAGE_JOAAT("MPPLY_GAME_EXPLOITS"):
//	case RAGE_JOAAT("MPPLY_TC_ANNOYINGME"):
//	case RAGE_JOAAT("MPPLY_TC_HATE"):
//	case RAGE_JOAAT("MPPLY_VC_ANNOYINGME"):
//	case RAGE_JOAAT("MPPLY_VC_HATE"):
//					notifyMap(mapnotify);
//					BreakupKick(sender->m_player_id);
//					BreakupKick(sender_id);
//			
//
//		/*g.reactions.report.process(g_player_service->get_by_id(sender->m_player_id));*/
//		return true;
//	}
//
//	return false;
//}

bool __cdecl ThunderHooks::IncrementStatEvent(uint64_t net_event_struct, int64_t sender, int64_t unk)
	{
		const auto hash = *reinterpret_cast<DWORD*>(net_event_struct + 0x30);
		auto sender_id = *reinterpret_cast<std::int8_t*>(sender + 33);
		auto sender_name = PLAYER::GET_PLAYER_NAME(sender_id);
		stringstream ss;
		ss << sender_name;
		std::string mapnotify = "report blocked from: " + ss.str();
		switch (hash)
		{
	//case RAGE_JOAAT("MPPLY_BAD_CREW_STATUS"):
	//case RAGE_JOAAT("MPPLY_BAD_CREW_MOTTO"):
	//case RAGE_JOAAT("MPPLY_BAD_CREW_NAME"):
	//case RAGE_JOAAT("MPPLY_BAD_CREW_EMBLEM"):
	//case RAGE_JOAAT("MPPLY_EXPLOITS"):
	//case RAGE_JOAAT("MPPLY_GAME_EXPLOITS"):
	//case RAGE_JOAAT("MPPLY_TC_ANNOYINGME"):
	//case RAGE_JOAAT("MPPLY_TC_HATE"):
	//case RAGE_JOAAT("MPPLY_VC_ANNOYINGME"):
	//case RAGE_JOAAT("MPPLY_VC_HATE"):
		case 0x9C6A0C42: //MPPLY_GRIEFING
		{
			std::string notifyinfo = mapnotify + "GRIEFING";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0x62EB8C5A: //MPPLY_VC_ANNOYINGME
		{
			std::string notifyinfo = mapnotify + " VC_ANNOYINGME";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;		
		case 0x0E7072CD: //MPPLY_VC_HATE
		{
			std::string notifyinfo = mapnotify + " VC_HATE";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0x762F9994: //MPPLY_TC_ANNOYINGME
		{
			std::string notifyinfo = mapnotify + " TC_ANNOYINGME";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0xB722D6C0: //MPPLY_TC_HATE
		{
			std::string notifyinfo = mapnotify + " TC_HATE";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0x3CDB43E2: //MPPLY_OFFENSIVE_LANGUAGE
		{
			std::string notifyinfo = mapnotify + " OFFENSIVE_LANGUAGE";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0xE8FB6DD5: //MPPLY_OFFENSIVE_TAGPLATE
		{
			std::string notifyinfo = mapnotify + " OFFENSIVE_TAGPLATE";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0xF3DE4879: //MPPLY_OFFENSIVE_UGC
		{
			std::string notifyinfo = mapnotify + " OFFENSIVE_UGC";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0xAA238FF0: //MPPLY_BAD_CREW_NAME
		{
			std::string notifyinfo = mapnotify + " BAD_CREW_NAME";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0x03511A79: //MPPLY_BAD_CREW_MOTTO
		{
			std::string notifyinfo = mapnotify + " BAD_CREW_MOTTO";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0x3B566D5C: //MPPLY_BAD_CREW_STATUS
		{
			std::string notifyinfo = mapnotify + " BAD_CREW_STATUS";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0x368F6FD9: //MPPLY_BAD_CREW_EMBLEM
		{
			std::string notifyinfo = mapnotify + " BAD_CREW_EMBLEM";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0xCBFD04A4: //MPPLY_GAME_EXPLOITS
		{
			std::string notifyinfo = mapnotify + " GAME_EXPLOITS";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		case 0x9F79BA0B: //MPPLY_EXPLOITS
		{
			std::string notifyinfo = mapnotify + " EXPLOITS";
			notifyMap(notifyinfo);
			//BreakupKick(sender_id);
			Features::kick_sp(sender_id);
			m_function::SendChatMessage((char*)std::string(notifyinfo).c_str());
			//Log::Msg((char*)std::string(notifyinfo).c_str());
			//Features::kick_(sender_id);
		}
		break;
		/*Features::nonhostkickns(int selectedPlayer)
			Features::kicksingles(int selectedPlayer)*/
			/*default:*/
			/*break;*/

		}

		return 0;
	}


	/*void m_function::RIDSendMessage(int a1, const char* a2)
	{
		int handle[13];
		NETWORK::NETWORK_HANDLE_FROM_MEMBER_ID(&std::to_string(a1)[0], &handle[0], 13);
		if (!NETWORK::NETWORK_IS_HANDLE_VALID(&handle[0], 13))
			Features::notify_custom(140, (char*)Obfuscate("Information"), (char*)Obfuscate("Invalid Network Handle."));
		NETWORK::NETWORK_SEND_TEXT_MESSAGE(a2, &handle[0]);
	}*/

	//void ThunderHooks::join__id()
	//{

	//	std::string joinsessions(CharKeyboardJoin22());
	//	Settings::m_RIDInviterTarget = 0;
	//	Hooking::JoinPatterns();
	//	char* joinsession = new char[joinsessions.length() + 1];
	//	strcpy(joinsession, joinsessions.c_str());
	//	Settings::m_RIDInviterTarget = atoi(joinsession);
	//	notifyMap("and if you dont have friend you can add you as friend for have one friend ");
	//	WAIT(100);
	//	if (m_RIDJoinFriendsFrontEndMenu)
	//	{
	//		do
	//		{
	//			UI::ACTIVATE_FRONTEND_MENU(0xD528C7E2, 0, 2);
	//			WAIT(1000);
	//			if (*m_RIDJoinFriendsFrontEndMenu)
	//			{

	//				//int hash = 0x1CC65C37; //Report 2
	//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
	//				/*RIDJoinFriends(&ptr, &hash);*/

	//				//ThunderHooks::join_by_rockstar_id(ptr);
	//			}
	//		} while (!*m_RIDJoinFriendsFrontEndMenu);
	//	}
	//}


	char* uParam;
	Param1* uParam1;

	int nc::dancenightclub(int iParam0)
	{ //am_mp_nightclub.c and am_mp_island.c 
		switch (iParam0)
		{
		case 0:
			uParam = "PIMNCLDANSTY0";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@FEMALE@VAR_A";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@FEMALE@VAR_A@";
			break;

		case 1:
			uParam = "PIMNCLDANSTY1";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@FEMALE@VAR_B";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@FEMALE@VAR_B@";
			break;

		case 2:
			uParam = "PIMNCLDANSTY2";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@MALE@VAR_B";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@MALE@VAR_B@";
			break;

		case 3:
			uParam = "PIMNCLDANSTY3";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@MALE@VAR_A";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@MALE@VAR_A@";
			break;

		case 4:
			uParam = "PIMNCLDANSTY4";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@JUMPER";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@JUMPER@";
			break;

		case 5:
			uParam = "PIMNCLDANSTY5";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@TECHNO_MONKEY";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@TECHNO_MONKEY@";
			break;

		case 6:
			uParam = "PIMNCLDANSTY6";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@SHUFFLE";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@SHUFFLE@";
			break;

		case 7:
			uParam = "PIMNCLDANSTY7";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@TECHNO_KARATE";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@TECHNO_KARATE@";
			break;

		case 8:
			uParam = "PIMNCLDANSTY8";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@BEACH_BOXING";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@BEACH_BOXING@";
			break;

		case 9:
			uParam = "PIMNCLDANSTY9";
			uParam1->f_1 = "NIGHTCLUB@DANCE_MINIGAME@DANCE_SOLO@SAND_TRIP";
			uParam1->f_2 = "ANIM@AMB@NIGHTCLUB@MINI@DANCE@DANCE_SOLO@SAND_TRIP@";
			break;

		default:
			return 0;
		}
	}




	/*inline void join_by_rockstar_id(uint64_t rid)
	{
		rage::rlGamerHandle player_handle(rid);
		rage::rlSessionByGamerTaskResult result;
		bool success = false;
		int state = 0;
		if (g_pointers->m_start_get_session_by_gamer_handle(0, &player_handle, 1, &result, 1, &success, &state))
		{
			while (state == 1)
				script::get_current()->yield();

			if (state == 3 && success)
			{
				rage::rlPresenceEventInviteAccepted presence_invite(g_local_player->m_player_info->m_net_player_data, result.m_session_info, result.m_gamer_handle);
				g_pointers->m_send_invite_accepted_presence_event(g_pointers->m_presence_struct, &presence_invite, 0);
				return;
			}
		}

		notify::above_map("RID Joiner", "RID join failed", NotificationType::DANGER);
	}*/

//	/*inline */void ThunderHooks::join_by_rockstar_id(uint64_t rid)
//	{
//
//		rlGamerHandle player_handle(rid);
//		rlSessionByGamerTaskResult result;
//		bool success = false;
//		int state = 0;
//		if (Hooking::m_start_get_session_by_gamer_handle(0, &player_handle, 1, &result, 1, &success, &state))
//		{
//			string redirectboolean1;
//			redirectboolean1 = getenv("appdata");
//			ofstream redirectboolean22(redirectboolean1 + "\\ThunderMenu\\m_start_get_session_by_gamer_handle.Thunder");
//			redirectboolean22 << Hooking::m_start_get_session_by_gamer_handle(0, &player_handle, 1, &result, 1, &success, &state);
//			while (state == 1)
//				yield;
//			//{
//			//	string redirectbooleanstate1;
//			//	redirectbooleanstate1 = getenv("appdata");
//			//	ofstream redirectbooleanstate22(redirectbooleanstate1 + "\\ThunderMenu\\state.Thunder");
//			//	redirectbooleanstate22 << state;
//
//			//	WAIT(100);
//			//	/*std::this_thread::sleep_for(std::chrono::milliseconds(1));
//			//	DWORD ticks = GetTickCount64();
//			//	DWORD milliseconds = ticks % 1000;
//			//	int getTimer = milliseconds;
//			//	int mytimer = 50;
//			//	if (getTimer % mytimer == 0)
//			//	{
//			//		WAIT(50);
//			//	}*/
//			//}
//			if (state == 3 && success)
//			{
//
//				int hash = 0xE1E8D5DC; //Invite
//				int64_t ptr = *m_RIDJoinFriendsFrontEndMenu;
//				rlPresenceEventInviteAccepted presence_invite(g_player->m_player_info->m_net_player_data, result.m_session_info, result.m_gamer_handle);
//				Hooking::m_send_invite_accepted_presence_event(&Hooking::m_presence_struct, &presence_invite, 0x21);
//
//				string redirectbooleanstate21;
//				redirectbooleanstate21 = getenv("appdata");
//				ofstream redirectbooleanstate222(redirectbooleanstate21 + "\\ThunderMenu\\success.Thunder");
//				redirectbooleanstate222 << success;
//
//				/*rage::rlPresenceEventInviteAccepted presence_invite(g_local_player->m_player_info->m_net_player_data, result.m_session_info, result.m_gamer_handle);
//				g_pointers->m_send_invite_accepted_presence_event(g_pointers->m_presence_struct, &presence_invite, 0);*/
//
//				return;
//			}
//		}
//
//
//
//		/*script::get_current()->yield();*/
//
//
//
///*notify::above_map("RID Joiner", "RID join failed", NotificationType::DANGER);*/
//	}
//namespace big::native_hook
//{
//	void NETWORK_SESSION_HOST(rage::scrNativeCallContext* src)
//	{
//		if (g->session_join_queued)
//		{
//			g_pointers->m_join_session_by_info(*g_pointers->m_network, &g->session_info, 0, 0, nullptr, 0);
//			g->session_join_queued = false;
//			src->set_return_value<BOOL>(TRUE);
//		}
//		else
//		{
//			src->set_return_value<BOOL>(NETWORK::NETWORK_SESSION_HOST(src->get_arg<int>(0), src->get_arg<int>(1), src->get_arg<BOOL>(2)));
//		}
//	};
//}
//
//{$(maintransition),
//	{
//		{ 0x6F3D4ED9BEE4E61D, &NETWORK_SESSION_HOST }
//}}

//#pragma pack(push, 1)
//class Obf32
//{
//	std::uint32_t a;
//	std::uint32_t b;
//	std::uint32_t c;
//	std::uint32_t d;
//
//public:
//	inline void operator=(std::uint32_t val)
//	{
//		a = val & d;
//		b = val & ~d;
//	}
//
//	inline operator std::uint32_t()
//	{
//		return (a & d) | (b & ~d);
//	}
//};
//static_assert(sizeof(Obf32) == 0x10);
//#pragma pack(pop)
//#pragma pack(push, 1)
//namespace rage
//{
//	class snPlayer
//	{
//	public:
//		uint64_t m_msg_id; //0x0000
//		class rage::netPlayerData m_player_data; //0x0008
//	}; //Size: 0x00A0
//	static_assert(sizeof(rage::snPlayer) == 0xA0);
//
//	class snPeer
//	{
//	public:
//		class rage::netPlayerData m_peer_data; //0x0000
//		char pad_0098[40]; //0x0098
//	}; //Size: 0x00C0
//	static_assert(sizeof(rage::snPeer) == 0xC0);
//
//	class rlRemoteGamer
//	{
//	public:
//		rage::rlGamerHandle m_handle;
//		char pad_0010[4]; //0x0010
//		uint32_t m_timeout_time; //0x0014
//		uint32_t m_time_unk; //0x0018
//		char pad_001C[4]; //0x001C
//	}; //Size: 0x0020
//	static_assert(sizeof(rage::rlRemoteGamer) == 0x20);
//
//
//	class rlSession
//	{
//	public:
//		char pad_0008[168]; //0x0008
//		class rage::rlSessionInfo m_session_info; //0x00B0
//		char pad_0120[288]; //0x0120
//		uint64_t m_session_id; //0x0240
//		char pad_0248[1648]; //0x0248
//
//		virtual ~rlSession() = default;
//	}; //Size: 0x08B8
//	static_assert(sizeof(rage::rlSession) == 0x8B8);
//
//	class rlSessionDetail
//	{
//	public:
//		class rage::netPlayerData m_net_player_data;
//		class rage::rlSessionInfo m_session_info; //0x0098
//		char pad_0108[308]; //0x0108
//		uint8_t m_matchmaking_property_ids[32]; //0x023C
//		char pad_025C[5]; //0x025C
//		uint8_t m_mental_state; //0x0261
//		char pad_0262[342]; //0x0262
//	}; //Size: 0x03B8
//	static_assert(sizeof(rage::rlSessionDetail) == 0x3B8);
//
//
//	class rlMatchmakingFindResult
//	{
//	public:
//		class rage::rlSessionDetail m_result_session_details[15]; //0x0000
//		char pad_37C8[168]; //0x37C8
//	}; //Size: 0x3870
//	static_assert(sizeof(rage::rlMatchmakingFindResult) == 0x3870);
//
//	class netGamePlayerData
//	{
//	public:
//		class rlGamerHandle m_handle;
//		bool m_is_activity_spectator; //0x0010
//		char pad_0011[7]; //0x0011
//		uint64_t m_crew_id; //0x0018
//		uint16_t m_rank; //0x0020
//		uint16_t m_debug_unk; //0x0022
//		char pad_0024[4]; //0x0024
//		uint32_t m_nat_type; //0x0028
//		bool m_is_rockstar_dev; //0x002C
//		char pad_002D[3]; //0x002D
//	}; //Size: 0x0030
//	static_assert(sizeof(rage::netGamePlayerData) == 0x30);
//
//
//	class snSession
//	{
//	public:
//		rage::sysMemAllocator* m_memory_allocator; //0x0000
//		char pad_0008[64]; //0x0008
//		void* m_net_connection_mgr; //0x0048
//		char pad_0050[48]; //0x0050
//		class rage::rlSession m_rline_session; //0x0080
//		class rage::snPlayer m_local_player; //0x0938
//		uint64_t m_host_token; //0x09D8
//		char pad_09E0[144]; //0x09E0
//		class rage::snPeer m_peer_storage[32]; //0x0A70
//		char pad_2270[24]; //0x2270
//		class rage::snPeer* m_peers[32]; //0x2288
//		uint32_t m_peer_count; //0x2388
//		char pad_238C[4]; //0x238C
//		class rage::snPlayer m_player_storage[32]; //0x2390
//		char pad_3790[24]; //0x3790
//		class rage::snPlayer* m_players[32]; //0x37A8
//		int32_t m_player_count; //0x38A8
//		char pad_38AC[4]; //0x38AC
//		class rage::rlRemoteGamer m_remote_gamers[32]; //0x38B0
//		uint32_t m_num_remote_gamers; //0x3CB0
//		bool m_player_joining; //0x3CB4
//		char pad_3CB5[107]; //0x3CB5
//		uint32_t m_connection_identifier; //0x3D20
//		char pad_3D24[8]; //0x3D24
//		char m_token_key[64]; //0x3D2C
//		char m_id_key[64]; //0x3D6C
//		char m_info_key[64]; //0x3DAC
//		char m_host_key[64]; //0x3DEC
//		char m_join_key[64]; //0x3E2C
//		char pad_3E6C[4]; //0x3E6C
//
//		inline bool is_host()
//		{
//			return m_local_player.m_player_data.m_host_token == m_host_token;
//		}
//
//	}; //Size: 0x3E70
//	static_assert(sizeof(rage::snSession) == 0x3E70);
//
//namespace rage
//{
//	class snMsgRemoveGamersFromSessionCmd
//	{
//	public:
//		uint64_t m_session_id; //0x0000
//		uint64_t m_peer_ids[32]; //0x0008
//		int32_t m_unk = -1; //0x0108
//		uint32_t m_num_peers; //0x010C
//	}; //Size: 0x0110
//	//static_assert(sizeof(rage::snMsgRemoveGamersFromSessionCmd) == 0x110);
//}

class CScriptedGameEvent : public rage2::netGameEvent
{
public:
	char m_padding[0x40];      // 0x30
	std::int64_t m_args[54];   // 0x70
	std::uint32_t m_bitset;    // 0x220
	std::uint32_t m_args_size; // 0x224
};

//class CPlayerGameStateDataNode
//{
//public:
//	char pad_0000[192]; //0x0000
//	uint32_t m_player_state; //0x00C0
//	bool m_controls_disabled_by_script; //0x00C4
//	bool m_is_max_armor_and_health_default; //0x00C5
//	bool unk_000C6; //0x00C6
//	bool m_is_spectating; //0x00C7
//	bool m_is_antagonistic_to_another_player; //0x00C8
//	bool m_never_target; //0x00C9
//	bool m_use_kinematic_physics; //0x00CA
//	bool m_has_tutorial_data; //0x00CB
//	bool m_pending_tutorial_change; //0x00CC
//	bool unk_00CD; //0x00CD
//	bool m_respawning; //0x00CE
//	bool m_will_jack_any_player; //0x00CF
//	bool m_will_jack_wanted_players; //0x00D0
//	bool m_dont_drag_from_car; //0x00D1
//	bool m_random_peds_flee; //0x00D2
//	bool m_every_ped_back_away; //0x00D3
//	bool m_has_microphone; //0x00D4
//	bool m_is_invincible; //0x00D5
//	bool unk_00D6; //0x00D6
//	bool unk_00D7; //0x00D7
//	bool m_seatbelt; //0x00D8
//	bool unk_00D9; //0x00D9
//	bool m_bullet_proof; //0x00DA
//	bool m_fire_proof; //0x00DB
//	bool m_explosion_proof; //0x00DC
//	bool m_collision_proof; //0x00DD
//	bool m_melee_proof; //0x00DE
//	bool m_water_proof; //0x00DF
//	bool m_steam_proof; //0x00E0
//	bool unk_00E1; //0x00E1
//	bool unk_00E2; //0x00E2
//	bool unk_00E3; //0x00E3
//	bool unk_00E4; //0x00E4
//	bool unk_00E5; //0x00E5
//	bool unk_00E6; //0x00E6
//	bool unk_00E7; //0x00E7
//	bool unk_00E8; //0x00E8
//	bool unk_00E9; //0x00E9
//	bool unk_00EA; //0x00EA
//	bool unk_00EB; //0x00EB
//	bool unk_00EC; //0x00EC
//	bool unk_00ED; //0x00ED
//	bool unk_00EE; //0x00EE
//	bool unk_00EF; //0x00EF
//	bool unk_00F0; //0x00F0
//	bool unk_00F1; //0x00F1
//	bool unk_00F2; //0x00F2
//	bool unk_00F3; //0x00F3
//	bool unk_00F4; //0x00F4
//	bool unk_00F5; //0x00F5
//	bool unk_00F6; //0x00F6
//	bool unk_00F7; //0x00F7
//	bool unk_00F8; //0x00F8
//	bool unk_00F9; //0x00F9
//	bool unk_00FA; //0x00FA
//	bool unk_00FB; //0x00FB
//	uint32_t unk_00FC; //0x00FC
//	uint32_t m_mobile_ring_state; //0x0100
//	int32_t m_player_team; //0x0104
//	float m_air_drag_multiplier; //0x0108
//	uint32_t m_max_health; //0x010C
//	uint32_t m_max_armor; //0x0110
//	uint32_t m_jack_speed; //0x0114
//	uint16_t m_player_is_targetable_by_team; //0x0118
//	uint32_t m_override_receive_chat; //0x011C
//	uint32_t m_override_send_chat; //0x0120
//	bool unk_0124; //0x0124
//	bool unk_0125; //0x0125
//	bool unk_0126; //0x0126
//	bool unk_0127; //0x0127
//	uint16_t m_spectating_net_id; //0x0128
//	uint8_t m_antagonistic_to_player_id; //0x012C
//	uint8_t m_tutorial_index; //0x012B
//	uint8_t m_tutorial_instance_id; //0x012C
//	char pad_012D[2]; //0x012D
//	float m_microphone_volume; //0x0130
//	uint32_t m_voice_channel; //0x0134
//	bool m_is_overriding_voice_proximity; //0x0138
//	char pad_0139[7]; //0x0139
//	float m_voice_proximity_x; //0x0140
//	float m_voice_proximity_y; //0x0144
//	float m_voice_proximity_z; //0x0148
//	float m_voice_proximity_radius_maybe; //0x014C
//	uint32_t unk_0150; //0x0150
//	uint32_t m_vehicle_weapon_index; //0x0154
//	bool m_has_vehicle_weapon_index; //0x0158
//	uint32_t m_decor_count; //0x015C
//	uint32_t m_decor_type[3]; // 0x0160
//	uint32_t m_decor_value[3]; // 0x016C
//	uint32_t m_decor_name_hash[3]; // 0x0178
//	bool m_friendly_fire_allowed; //0x0184
//	bool unk_0185; //0x0185
//	uint8_t m_current_garage_instance_index; //0x0186
//	uint8_t m_current_property_id; //0x0187
//	uint8_t unk_0188; //0x0188
//	uint8_t unk_0189; //0x0189
//	bool m_battle_aware; //0x018A
//	bool m_vehicle_jump_down; //0x018B
//	float m_weapon_defence_modifier; //0x018C
//	float m_weapon_defence_modifier_2; //0x0190
//	bool m_is_overriding_population_control_sphere; //0x0194
//	char pad_0195[11]; //0x0195
//	float m_population_control_sphere_x; //0x01A0
//	float m_population_control_sphere_y; //0x01A4
//	float m_population_control_sphere_z; //0x01A8
//	uint16_t unk_01AC; //0x01AC
//	uint16_t unk_01AE; //0x01AE
//	uint16_t unk_01B0; //0x01B0
//	bool pad_01B2; //0x01B2
//	bool unk_01B3; //0x01B3
//	bool m_no_collision; //0x01B4
//	bool unk_01B5; //0x01B5
//	bool unk_01B6; //0x01B6
//	bool m_super_jump; //0x01B7
//	bool unk_01B8; //0x01B8
//	bool unk_01B9; //0x01B9
//	uint16_t unk_01BA; //0x01BA
//	uint32_t unk_01BC; //0x01BC
//	float unk_01C0; //0x01C0
//	float m_weapon_damage_modifier;  //0x01C4 Divisor: 0x3F800000
//	float m_melee_weapon_damage_modifier;  //0x01C8 Divisor: 0x3F800000
//	float unk_01CC; //0x01CC
//	bool unk_01D0; //0x01D0
//	char pad_01D1[15]; //0x01D1
//	float unk_01E0; //0x01E0
//	float unk_01E4; //0x01E4
//	float unk_01E8; //0x01E8
//	uint32_t unk_01EC; //0x01EC
//	uint8_t unk_01F0; //0x01F0
//	uint8_t unk_01F1; //0x01F1
//	bool unk_01F2; //0x01F2
//	uint8_t unk_01F3; //0x01F3
//	bool unk_01F4; //0x01F4
//	bool unk_01F5; //0x01F5
//}; //Size: 0x01F8
//static_assert(sizeof(CPlayerGameStateDataNode) == 0x1F8);


//
//class MetricSessionMigrated : public rage::rlMetric
//{
//public:
//	char pad_0008[804]; //0x0008
//	uint32_t m_num_players; //0x032C
//}; //Size: 0x0330
//static_assert(sizeof(MetricSessionMigrated) == 0x330);
//
//class NetworkGameConfig
//{
//public:
//	char pad_0000[48]; //0x0000
//	uint32_t m_public_slots; //0x0030
//	uint32_t m_private_slots; //0x0034
//	char pad_0038[272]; //0x0038
//}; //Size: 0x0148
//static_assert(sizeof(NetworkGameConfig) == 0x148);
//
//class NetworkGameFilter
//{
//public:
//	char pad_0000[16]; //0x0000
//	char m_game_mode[24]; //0x0010
//	char pad_0028[8]; //0x0028
//	uint32_t m_attribute_values[8]; //0x0030
//	char m_attribute_names[8][24]; //0x0050
//	char pad_0110[564]; //0x0110
//}; //Size: 0x0344
//static_assert(sizeof(NetworkGameFilter) == 0x344);
//
//class SessionInfoBackup
//{
//public:
//	class rage::rlSessionInfo m_session_info;
//	uint32_t m_unk; //0x0070
//	char pad_0074[4]; //0x0074
//	uint32_t m_flags; //0x0078
//}; //Size: 0x007C
//static_assert(sizeof(SessionInfoBackup) == 0x7C);
//
//class MatchmakingSessionResult
//{
//public:
//	class rage::rlSessionDetail m_detail;
//	char pad_03B8[24]; //0x03B8
//}; //Size: 0x03D0
//static_assert(sizeof(MatchmakingSessionResult) == 0x3D0);
//
//class CNetRemoteComplaint
//{
//public:
//	uint64_t m_complainer_token; //0x0000
//	uint64_t m_complainee_token; //0x0008
//	uint32_t m_flags; //0x0010
//	uint32_t m_time; //0x0014
//}; //Size: 0x0018
//static_assert(sizeof(CNetRemoteComplaint) == 0x18);
//
//class CNetComplaintMgr
//{
//public:
//	uint64_t m_host_token; //0x0000
//	uint32_t m_host_peer_id; //0x0008
//	char pad_000C[4]; //0x000C
//	void* m_net_connection_mgr; //0x0010
//	char pad_0018[64]; //0x0018
//	uint64_t m_host_tokens_in_scope[64]; //0x0058
//	uint32_t m_num_tokens_in_scope; //0x0258
//	char pad_025C[4]; //0x025C
//	class CNetRemoteComplaint m_remote_complaints[64]; //0x0260
//	uint32_t m_num_remote_complaints; //0x0860
//	char pad_0864[4]; //0x0864
//	uint64_t m_host_tokens_complained[64]; //0x0868
//	uint32_t m_num_tokens_complained; //0x0A68
//	char pad_0A6C[520]; //0x0A6C
//	uint32_t m_connection_identifier; //0x0C74
//	uint32_t m_last_resend_time; //0x0C78
//	char pad_0C7C[4]; //0x0C7C
//	uint32_t m_time_to_resend; //0x0C80
//	uint32_t m_flags; //0x0C84
//	char pad_0C88[16]; //0x0C88
//
//	inline bool has_local_complaint(uint64_t host_token)
//	{
//		for (auto i = 0; i < m_num_tokens_complained; i++)
//			if (m_host_tokens_complained[i] == host_token)
//				return true;
//
//		return false;
//	}
//
//	inline void raise_complaint(uint64_t host_token)
//	{
//		if (has_local_complaint(host_token))
//			return;
//
//		m_host_tokens_complained[m_num_tokens_complained++] = host_token;
//
//		// This is the "breakup" kick? Can't kick host so doubt it
//		// Target gets a "unknown network error" after 10 seconds, this does not appear to be a desync kick
//		big::g_pointers->m_raise_network_complaint(this, host_token); // find the pattern yourselves skids lol
//	}
//
//	inline void remove_complaint(uint64_t host_token)
//	{
//		if (!has_local_complaint(host_token))
//			return;
//
//		for (auto i = 0; i < m_num_tokens_complained; i++)
//			if (m_host_tokens_complained[i] == host_token)
//				m_host_tokens_complained[i] = m_host_tokens_complained[m_num_tokens_complained - 1];
//
//		m_num_tokens_complained--;
//	}
//
//}; //Size: 0x0C98
//static_assert(sizeof(CNetComplaintMgr) == 0xC98);
//
//class PlayerNameMapNode
//{
//public:
//	char m_name[24]; //0x0000
//	class rage::rlGamerHandle m_handle; //0x0018
//	class PlayerNameMapNode* m_next; //0x0028
//	class PlayerNameMapNode* m_prev; //0x0030
//}; //Size: 0x0038
//static_assert(sizeof(PlayerNameMapNode) == 0x38);
//
//class JoiningPlayerNameMap
//{
//public:
//	class PlayerNameMapNode m_names[100]; //0x0000
//	char pad_15E0[40]; //0x15E0
//	uint32_t m_num_name_nodes; //0x1608
//	char pad_160C[796]; //0x160C
//}; //Size: 0x1928
//static_assert(sizeof(JoiningPlayerNameMap) == 0x1928);
//
//class CNetBlacklistNode : public rage::rlGamerHandle
//{
//public:
//	bool m_block_rejoin; //0x0010
//	char pad_0011[3]; //0x0011
//	uint32_t m_added_time; //0x0014
//	class CNetBlacklistNode* m_next; //0x0018
//	class CNetBlacklistNode* m_prev; //0x0020
//}; //Size: 0x0028
//static_assert(sizeof(CNetBlacklistNode) == 0x28);
//
//class CNetBlacklist
//{
//public:
//	class CNetBlacklistNode m_nodes[16]; //0x0000
//	class CNetBlacklistNode* m_head; //0x0280
//	class CNetBlacklistNode* m_tail; //0x0288
//	uint32_t m_free_nodes; //0x0290
//	char pad_0294[4]; //0x0294
//	class CNetBlacklistNode* m_start; //0x0298
//	char pad_02A0[24]; //0x02A0
//}; //Size: 0x02B8
//static_assert(sizeof(CNetBlacklist) == 0x2B8);
//
//class RemotePlayerData
//{
//public:
//	class rage::netGamePlayerData m_data[32]; //0x0000
//	uint32_t m_count; //0x0600
//	char pad_0604[4]; //0x0604
//}; //Size: 0x0608
//static_assert(sizeof(RemotePlayerData) == 0x608);
//
//class InvitedGamer
//{
//public:
//	class rage::rlGamerHandle m_handle;
//	char pad_0010[12]; //0x0010
//	uint32_t m_flags; //0x001C
//}; //Size: 0x0020
//static_assert(sizeof(InvitedGamer) == 0x20);
//
//class InvitedGamers
//{
//public:
//	class InvitedGamer m_invited_gamers[100]; //0x0000
//	uint32_t m_num_invited_gamers; //0x0C80
//	char pad_0C84[4]; //0x0C84
//}; //Size: 0x0C88
//static_assert(sizeof(InvitedGamers) == 0xC88);
//
//class Network
//{
//public:
//	class Obf32 m_num_diput8_instances;
//	class Obf32 m_last_time_dinput8_checked; //0x0010
//	class rage::snSession* m_game_session_ptr; //0x0020
//	class rage::snSession* m_transition_session_ptr; //0x0028
//	char pad_0030[24]; //0x0030
//	class rage::snSession m_game_session; //0x0048
//	class rage::snSession m_transition_session; //0x3EB8
//	char pad_7D28[16]; //0x7D28
//	class NetworkGameConfig m_network_game_config; //0x7D38
//	class NetworkGameConfig m_network_transition_config; //0x7E80
//	bool m_session_attributes_dirty; //0x7FC8
//	char pad_7FC9[19]; //0x7FC9
//	uint32_t m_session_visibility_flags; //0x7FDC
//	uint32_t m_transition_visibility_flags; //0x7FE0
//	char pad_7FE4[36]; //0x7FE4
//	class MetricSessionMigrated m_metric_session_migrated; //0x8008
//	bool m_migrated_metric_enabled; //0x8338
//	char pad_8339[3]; //0x8339
//	uint32_t m_game_session_state; //0x833C
//	class NetworkGameFilter m_network_game_filter; //0x8340
//	char pad_8684[33]; //0x8684
//	bool m_was_invited; //0x86A5
//	char pad_86A6[757]; //0x86A6
//	bool m_need_host_change; //0x899B
//	char pad_899C[2620]; //0x899C
//	class rage::rlSessionDetail m_joining_session_detail; //0x93D8
//	class SessionInfoBackup m_last_joined_session; //0x9790
//	char pad_980C[40]; //0x980C
//	uint32_t m_current_matchmaking_group; //0x9834
//	uint32_t m_matchmaking_group_max_players[5]; //0x9838
//	uint32_t m_num_active_matchmaking_groups; //0x984C
//	char pad_9850[8]; //0x9850
//	uint8_t m_matchmaking_property_id; //0x9858
//	uint8_t m_matchmaking_mental_state; //0x9859
//	char pad_985A[374]; //0x985A
//	class rage::rlMatchmakingFindResult m_game_session_matchmaking[3]; //0x99D0
//	char pad_14320[40]; //0x14320
//	class MatchmakingSessionResult m_game_matchmaking_session_results[10]; //0x14348
//	char pad_16968[320]; //0x16968
//	class rage::rlGamerHandle m_transition_creator_handle; //0x16AA8
//	char pad_16AB8[24]; //0x16AB8
//	bool m_local_player_info_dirty; //0x16AD0
//	char pad_16AD1[495]; //0x16AD1
//	class rage::rlGamerHandle m_inviter_handle; //0x16CC0
//	class CNetComplaintMgr m_game_complaint_mgr; //0x16CD0
//	class CNetComplaintMgr m_transition_complaint_mgr; //0x17968
//	char pad_18600[32]; //0x18600
//	class JoiningPlayerNameMap m_unused_joining_player_name_map; //0x18620
//	char pad_19F48[8]; //0x19F48
//	class CNetBlacklist m_blacklist; //0x19F50
//	char pad_1A208[8]; //0x1A208
//	class InvitedGamers m_game_invited_gamers; //0x1A210
//	char pad_1AE98[56]; //0x1AE98
//	class SessionInfoBackup m_last_joined_transition; //0x1AED0
//	char pad_1AF4C[4]; //0x1AF4C
//	uint32_t m_activity_spectator_max_players; //0x1AF50
//	char pad_1AF54[56]; //0x1AF54
//	bool m_is_activity_session; //0x1AF8C
//	char pad_1AF8D[35]; //0x1AF8D
//	class RemotePlayerData m_remote_player_data; //0x1AFB0
//	char pad_1B5B8[8]; //0x1B5B8
//	class rage::netGamePlayerData m_local_net_game_player_data; //0x1B5C0
//	char pad_1B5F0[600]; //0x1B5F0
//	class rage::rlMatchmakingFindResult m_transition_matchmaking[4]; //0x1B848
//	class NetworkGameFilter m_transition_filters[4]; //0x29A08
//	char pad_2A718[20]; //0x2A718
//	uint32_t m_transition_quickmatch_group_handle_count; //0x2A72C
//	class rage::rlGamerHandle m_transition_quickmatch_group_handles[32]; //0x2A730
//	char pad_2A930[8]; //0x2A930
//	class rage::rlSessionInfo m_transition_to_activity_session_info; //0x2A938
//	char pad_2A9A8[48]; //0x2A9A8
//	class MatchmakingSessionResult m_transition_matchmaking_session_results[10]; //0x2A9D8
//	char pad_2CFF8[8]; //0x2CFF8
//	class InvitedGamers m_transition_invited_gamers; //0x2D000
//	char pad_2DC88[16]; //0x2DC88
//	class rage::rlGamerHandle m_transition_to_game_handle; //0x2DC98
//	class rage::rlSessionInfo m_transition_to_game_session_info; //0x2DCA8
//	char pad_2DD18[4]; //0x2DD18
//	uint32_t m_transition_to_game_session_participant_count; //0x2DD1C
//	class rage::rlGamerHandle m_transition_to_game_session_participants[32]; //0x2DD20
//	char pad_2DF20[72]; //0x2DF20
//	class rage::rlGamerHandle m_follower_handles[32]; //0x2DF68
//	uint32_t m_follower_count; //0x2E168
//	char pad_2E16C[628]; //0x2E16C
//}; //Size: 0x2E3E0
//static_assert(sizeof(Network) == 0x2E3E0);
//#pragma pack(pop)
//
//// updated 
//
//namespace rage::netConnection
//{
//	class InFrame
//	{
//	public:
//		virtual ~InFrame() = default;
//
//		virtual void destroy() = 0;
//		virtual uint32_t get_type() = 0;
//		virtual uint32_t _0x18() = 0;
//
//		char pad_0008[56]; //0x0008
//		uint32_t m_msg_id; //0x0040
//		uint32_t m_connection_identifier; //0x0044
//		InFrame* m_this; //0x0048
//		uint64_t m_peer_id; //0x0050
//		char pad_0050[32]; //0x0058
//		uint32_t m_length; //0x0078
//		char pad_007C[4]; //0x007C
//		void* m_data; //0x0080
//	};
//	static_assert(sizeof(rage::netConnection::InFrame) == 0x88);
//}

ScriptLocal::ScriptLocal(scrThread* thread, std::size_t index) :
	m_index(index), m_stack(thread->m_stack)
{
}
ScriptLocal::ScriptLocal(PVOID stack, std::size_t index) :
	m_index(index), m_stack(stack)
{
}

ScriptLocal ScriptLocal::Add(std::ptrdiff_t index)
{
	return ScriptLocal(m_stack, m_index + index);
}

ScriptLocal ScriptLocal::Add(std::ptrdiff_t index, std::size_t size)
{
	return ScriptLocal(m_stack, m_index + 1 + (index * size));
}
void* ScriptLocal::get()
{
	return reinterpret_cast<uintptr_t*>((uintptr_t)m_stack + (m_index * sizeof(uintptr_t)));
}

//void m_features::BlackHole()
//{
//	double multiplier = 3.0;
//	const int ElementAmount = 20;
//	static Vector3 entity_location;
//	const int Size = ElementAmount * 2 + 2;
//	Vehicle* vehicle = new Vehicle[Size];
//	vehicle[0] = ElementAmount;
//	int VehicleFound = PED::GET_PED_NEARBY_VEHICLES(PlayerPedID, vehicle);
//
//	if (g_Settings.m_BlackHoleMarker && blackhole_location.z != 0)
//		GRAPHICS::DRAW_MARKER(28, blackhole_location.x, blackhole_location.y, blackhole_location.z - 1.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0, 0.0f, 2.f, 2.f, 2.f, 255, 255, 255, 120, 1, 1, 1, 0, 0, 0, 0);
//
//	if (g_Settings.m_BlackHoleExplode && blackhole_location.z != 0)
//	{
//		static int timer;
//		if ((GetTickCount() - timer) > 400)
//		{
//			FIRE::ADD_EXPLOSION(blackhole_location.x, blackhole_location.y, blackhole_location.z, 6, 1000.f, true, false, g_Settings.m_BlackHoleShake);
//			timer = GetTickCount();
//		}
//	}
//
//	for (int i = 0; i < VehicleFound; i++)
//	{
//		int ID = i * 2 + 2;
//		if (vehicle[ID] == 0)
//		{
//			if (raycast(&vehicle[ID]))
//			{
//				if (ENTITY::IS_ENTITY_A_PED(vehicle[ID]) && PED::IS_PED_A_PLAYER(vehicle[ID]))
//					vehicle[ID] = 0;
//				else
//				{
//					entity_location = ENTITY::GET_ENTITY_COORDS(vehicle[ID], true);
//					if (take_control_of(vehicle[ID]))
//						AI::SET_HIGH_FALL_TASK(vehicle[ID], 0, 0, 0);
//
//				}
//			}
//			else
//			{
//				vehicle[ID] = 0;
//			}
//		}
//
//		if (ENTITY::DOES_ENTITY_EXIST(vehicle[ID]) && blackhole_location.z != 0)
//		{
//			if (!take_control_of(vehicle[ID]))
//				vehicle[ID] = 0;
//
//			ENTITY::SET_ENTITY_COLLISION(vehicle[ID], true, false);
//			entity_location = ENTITY::GET_ENTITY_COORDS(vehicle[ID], true);
//			Vector3 velocity;
//			velocity.x = blackhole_location.x - entity_location.x;
//			velocity.y = blackhole_location.y - entity_location.y;
//			velocity.z = blackhole_location.z - entity_location.z;
//			ENTITY::SET_ENTITY_VELOCITY(vehicle[ID], velocity.x * (float)multiplier, velocity.y * (float)multiplier, velocity.z * (float)multiplier);
//
//		}
//	}
//}
Vector3 m_features::blackhole_location;
static bool BlackHoleReset = true;
bool m_features::BlackHolebool = 0;
bool m_features::m_BlackHoleExplode = 0;

void m_features::BlackHole()
{
	double multiplier = 3.0;
	if (!m_features::BlackHolebool)
	{
	if (m_features::BlackHolebool) m_features::BlackHolebool = false;
	if (!BlackHoleReset)
	{
		BlackHoleReset = true;
		target_entities.clear();
	}
	return;
}
	get_entities();

	for (auto entity : target_entities)
	{
		if (blackhole_location.z != 0)
		{
			RequestControlOfEnt(entity);
			auto entity_coord = ENTITY::GET_ENTITY_COORDS(entity, true);
			Vector3 velocity;
			velocity.x = blackhole_location.x - entity_coord.x;
			velocity.y = blackhole_location.y - entity_coord.y;
			velocity.z = blackhole_location.z - entity_coord.z;
			ENTITY::SET_ENTITY_VELOCITY(entity, velocity.x * (float)multiplier, velocity.y * (float)multiplier, velocity.z * (float)multiplier);

		}
	}
		if (m_features::m_BlackHoleExplode && blackhole_location.z != 0)
	{
		static int timer;
		if ((GetTickCount() - timer) > 400)
		{
			Hooking::ExplosionBypass(1);
			FIRE::ADD_EXPLOSION(blackhole_location.x, blackhole_location.y, blackhole_location.z, 6, 1000.f, true, false, m_features::m_BlackHoleExplode);
			Hooking::ExplosionBypass(0);
			timer = GetTickCount();
		}
	}
		target_entities.clear();
		BlackHoleReset = false;
}
