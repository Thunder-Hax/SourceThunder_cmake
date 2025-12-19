#pragma once
#include <memory>
#include "xstring"
#include "Memory.h"
#include "Functions.h"
//#include "reclass/netPlayerData.hpp"
//#include "reclass/CNetGamePlayer.hpp"
//#include "reclass/CNetworkPlayerMgr.hpp"

#include "reclass/GTAV-Classes/network/CNetGamePlayer.hpp"
#include "reclass/GTAV-Classes/network/CNetworkPlayerMgr.hpp"
#include "reclass/GTAV-Classes/script/scriptHandler.hpp"
#include "reclass/GTAV-Classes/network/netObject.hpp"

#include <stdio.h>
#include <stdint.h>

#define __int64 long long

class simpletime2 {
private:
	std::uint64_t mreadyat;
	bool mtick;
public:
	void start(std::uint64_t ticks) {
		if (this->mtick) {
			this->mreadyat = GetTickCount64() + ticks;
			this->mtick = false;
		}
	}
	bool is_ready() {
		return GetTickCount64() > this->mreadyat;
	}
	void reset() {
		this->mtick = true;
	}
};


// 
//#define PlayerIndex uint32_t PlayerIndex
//typedef int                PlayerIndex;

//typedef void(__cdecl* GetNetPlayer2)(CNetGamePlayer* (uint32_t PlayerIndex));
//typedef void(__cdecl* NetworkPlayerMgr2)(CNetworkPlayerMgr**);


//typedef void(__cdecl* GetNetPlayer2)(CNetGamePlayer* (uint32_t PlayerIndex));
//typedef void(__cdecl* CNetworkPlayerMgr2)(CNetworkPlayerMgr**);

class G_Hooking
{
public:
	static void RainOverride(int64_t timecycle_manager, RainRGBColor* timecycle_data);
	static void TimecycleOverride(int64_t timecycle_manager, TimecycleData* timecycle_data);
	//static void* m_OriginalTimecycleOverride;

	/*static NetworkPlayerMgr2 m_NetworkPlayerMgr;
	static GetNetPlayer2 m_GetNetPlayer;*/
};

//class rlGamerHandle2
//{
//public:
//	uint64_t m_rockstar_id;
//	uint64_t m_unk;
//
//	inline rlGamerHandle2(uint64_t rockstar_id) :
//		m_rockstar_id(rockstar_id),
//		m_unk(3)
//	{
//	}
//};
//
//class rlSessionInfo2
//{
//public:
//	uint64_t m_unk;
//	uint64_t m_session_token;
//
//	// contains a subset of netPlayerData. host's data?
//	char pad_0000[8]; //0x0000
//	uint64_t m_rockstar_id; //0x0008
//	char pad_0010[52]; //0x0010
//	class rage::netAddress m_relay_ip; //0x0044
//	uint16_t m_relay_port; //0x0048
//	char pad_004A[2]; //0x004A
//	class rage::netAddress m_external_ip; //0x004C
//	uint16_t m_external_port; //0x0050
//	char pad_0052[2]; //0x0052
//	class rage::netAddress m_internal_ip; //0x0054
//	uint16_t m_internal_port; //0x0058
//	char pad_005A[6]; //0x005A
//};
//
//class rlSessionByGamerTaskResult2
//{
//public:
//	rlGamerHandle2 m_gamer_handle{ 0 };
//	rlSessionInfo2 m_session_info{};
//};
//
//class rlPresenceEventInviteAccepted2
//{
//public:
//	void* m_vft;
//	rlPresenceEventInviteAccepted2* m_self;
//	rage::netPlayerData m_local_data;
//	rlSessionInfo2 m_session_info;
//	rlGamerHandle2 m_some_handle;
//
//	rlPresenceEventInviteAccepted2(rage::netPlayerData& local_player_data, rlSessionInfo2& session_info, rlGamerHandle2& handle) :
//		m_local_data(local_player_data),
//		m_session_info(session_info),
//		m_some_handle(handle)
//	{
//		m_self = this;
//	}
//};
//class rlPresenceEventInviteAccepted2
//{
//public:
//	void* m_vft;
//	rlPresenceEventInviteAccepted2* m_self;
//	rage2::netPlayerData m_local_data;
//	rlSessionInfo2 m_session_info;
//	rlGamerHandle2 m_some_handle;
//
//	rlPresenceEventInviteAccepted2(rage2::netPlayerData& local_player_data, rlSessionInfo2& session_info, rlGamerHandle2& handle) :
//		m_local_data(local_player_data),
//		m_session_info(session_info),
//		m_some_handle(handle)
//	{
//		m_self = this;
//	}
//};

//typedef bool(__cdecl* fpIsDLCPresent)();
//typedef BOOL(__fastcall* tADD_OWNED_EXPLOSION)(Ped ped, Vector3 coords, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake);
//static BOOL ADD_OWNED_EXPLOSION(Ped ped, Vector3 coords, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake) { static tADD_OWNED_EXPLOSION oADD_OWNED_EXPLOSION = (tADD_OWNED_EXPLOSION)(Memory::pattern("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 70 20 55 48 8D 68 B9 48 81 EC ? ? ? ? 0F 29 70 E8 41 8B D8").count(1).get(0).get<void>()); return oADD_OWNED_EXPLOSION(ped, coords, explosionType, damageScale, isAudible, isInvisible, cameraShake); }

typedef int(__cdecl* fpNetworkCreateSynchronisedScene)(Vector3* pos, Vector3* rot, int unk0, int unk1, int unk2, float unk3, float unk4, float unk5);
typedef int(__cdecl* fpNetworkAddPedToSynchronisedScene)(Ped ped, int scene, char* dict, char* anim, float speed, float speedMult, int duration, int flag, float playRate, int unk1, int unk2);
typedef int(__cdecl* fpNetworkStartSynchronisedScene)(int scene);

class SyncScene
{
public:
	static fpNetworkCreateSynchronisedScene        create_synchronised_scene;
	static fpNetworkAddPedToSynchronisedScene      add_ped_to_synchronised_scene;
	static fpNetworkStartSynchronisedScene         start_synchronised_scene;
};

typedef void(__cdecl* patternglobal)(uintptr_t globalpattern);
typedef void(__cdecl* listblip)(uintptr_t bliplist);
typedef void(__cdecl* patternworld)(uintptr_t worldpattern);
typedef void(__cdecl* fpreplay)(uintptr_t replay);
typedef void(__cdecl* fplaylist)(uintptr_t playlist);

typedef void(__cdecl* fpunkmodel)(uintptr_t modelunk);

typedef unsigned long  uintptr;

class interreplay
{
public:
	uintptr ADDRESS_REPLAY_INTERFACE2;
	BYTE m_replayInterface,
		m_dwpReplayInterfaceBase,
		m_dwpPedInterface,
		m_dwpPedList,
		m_dwpPickUpInterface,
		m_dwpPickUpList;
};

typedef void(__cdecl* fphandlingindex)(uintptr_t index);
typedef void(__cdecl* fphandlinghash)(uintptr_t hash);



typedef void(__cdecl* fpPedPoolAddress)(uintptr_t PedPoolAddress);
typedef void(__cdecl* fpObjectPoolAddress)(uintptr_t ObjectPoolAddress);
typedef void(__cdecl* fpEntityPoolAddress)(uintptr_t EntityPoolAddress);
typedef void(__cdecl* fpVehiclePoolAddress)(uintptr_t VehiclePoolAddress);
typedef void(__cdecl* fpPickupObjectPoolAddress)(uintptr_t PickupObjectPoolAddress);


typedef void(__cdecl* fpvehicleClassOffset)(uintptr_t vehicleClassOffset);
typedef void(__cdecl* fpmodelNum1)(uintptr_t modelNum1);
typedef void(__cdecl* fpmodelNum2)(uintptr_t modelNum2);
typedef void(__cdecl* fpmodelNum3)(uintptr_t modelNum3);
typedef void(__cdecl* fpmodelNum4)(uintptr_t modelNum4);
typedef void(__cdecl* fpmodelHashTable)(uintptr_t modelHashTable);
typedef void(__cdecl* fpmodelHashEntries)(uintptr_t modelHashEntries);


struct UInt32
{
public:
};
struct UInt64
{
public:
};
struct UInt16
{
public:
};
struct IntPtr
{
public:
	static void* ToPointer();
};
typedef int var;


typedef void(__cdecl* fphandlingIndexOffset)(uintptr_t info);


typedef int Iterator;
//struct IntPtr
//{
//public:
//};
//class Type
//{
//public:
//};
//typedef unsigned int GetDelegateForFunctionPointer;
//typedef unsigned int mytest;
//static mytest GetDelegateForFunctionPointer(IntPtr ptr, Type t);
//
//typedef unsigned int GetHandlingDataByHashDelegate;
//typedef unsigned int GetHandlingDataByIndexDelegate;
//
//static GetHandlingDataByHashDelegate GetHandlingDataByHash;
//static GetHandlingDataByIndexDelegate GetHandlingDataByIndex;

//namespace GF
//{
/*struct*/namespace/*class*/ ThunderHooks
{
	/*public:*/
	extern bool loadplayerlist;
	extern int ridjoin;
	extern int ridplayer;
	/*extern std::string ridplayerstring;*/
	extern void RequestControlBypass(bool toggle);
	extern void RIDFunction();
	extern void RIDFunction2();
	extern void RIDFunction3();
	extern void RIDFunction4();
	extern void RIDFunction5();
	extern void RIDFunction6();
	extern void RIDFunction7();
	extern void RIDFunction8();
	extern void RIDFunction9();
	extern void RIDFunction10();
	extern void RIDFunction11();
	extern void RIDFunction12();
	extern void RIDFunction13();
	extern void RIDFunction14();
	extern void RIDFunction15();
	extern void RIDFunction16();
	extern void RIDFunction17();
	extern void RIDFunction18();
	extern void RIDFunction19();
	extern void RIDFunction20();
	extern void RIDFunction21();
	extern void RIDFunction22();
	extern void RIDFunction23();
	extern void RIDFunction24();
	extern void RIDFunction25();
	extern void RIDFunction26();
	extern void RIDFunction27();
	extern void RIDFunction28();
	extern void RIDFunction29();
	extern void RIDFunction30();

	extern void join_by_rockstar_id(uint64_t rid);
	extern 	void join__id();
	extern bool RIDJoinFriends(int64_t* a1, int* hash);
	extern bool RIDJoinFriendsV2(int* a1, __int64 a2, int* a3);
	extern int64_t* RIDJoinHandle(int32_t friendIndex);

	extern char RIDInviteFriends(void* presenceStruct, rlPresenceEventInviteAccepted* invite, int flags);
	extern char RIDInviteHandle(int metric_manager, rage::rlGamerHandle* handles, int count, rage::rlSessionByGamerTaskResult* result, int unk, bool* success, int* state);

	extern bool IncrementStatEvent(uint64_t net_event_struct, int64_t sender, int64_t unk);
	extern void DisableErrorScreen(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background);
	extern bool simple_drop_g_SelectedPlayer;
}/*;*/

//class ThunderHooking
//{
//public:
//	friend struct ThunderHooks;
//	/*void* m_OriginalRIDJoinHandle{};
//	void* m_OriginalRIDJoinFriends{};*/
//private:
//};
/*static std::unique_ptr<ThunderHooking> g_Hooking;*/
//}
	/*__declspec(selectany) int global_int = 0;*/

typedef bool(__cdecl* fpIsDLCPresent)(std::uint32_t dlcHash);
//typedef bool(__cdecl* fpsIncrementStatEvent)(uint64_t net_event_struct, int64_t sender, int64_t unk);
//typedef bool(__cdecl* fpsIncrementStatEvent)(__int64 a1, __int64 a2, float a3);
typedef bool(__cdecl* fpsIncrementStatEvent)(__int64 a1, __int64 a2, __int64 a3);
//using increment_stat_event = bool(uint64_t net_event_struct, int64_t sender, int64_t a3);

typedef __int64(__cdecl* fpGetPlayerAddress)(Player);
typedef Entity(__cdecl* fpAddressToEntity)(__int64);
//typedef bool(__cdecl* fpSetName)();
typedef bool(__cdecl* fpTriggerScriptEvent)(int, void*, int, int, int);
typedef bool(__cdecl* fpSetLobbyWeather)(int, int, int, __int64);
//typedef bool(__cdecl* fpIncrementStatHook)(uint64_t net_event_struct, int64_t sender, int64_t unk);
//typedef bool(__cdecl* fpIncrementStatHook)(__int64 a1, __int64 a2, float a3);
typedef bool(__cdecl* fpIncrementStatHook)(__int64 a1, __int64 a2, __int64 a3);
//typedef void(__cdecl* fpAddOwnedExplosion)(Ped ped, float x, float y, float z, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake);
typedef void(__cdecl* fpAddOwnedExplosion)(Ped ped, Vector3* pos, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake);

typedef bool(__cdecl* fpAddTextCompSubstrPlayerName)(char* text);
typedef bool(__cdecl* fpEndTextCmdDisplayText)(float x, float y);
typedef bool(__cdecl* fpBeginTextCmdDisplayText)(char* text);
//typedef bool(__cdecl* fpIsPedShooting)(Ped ped);
typedef bool(__cdecl* fpSetLobbyTime)(int, int, int);
//typedef bool(__cdecl* fpGetPlayerPed)(Player player);
typedef char* (__cdecl* fpGetPlayerName)(Player player);

typedef BOOL(__cdecl* fpNetworkIsSessionStarted)();
//typedef void(__cdecl* Receive)(__int64* Received);
//typedef void(__cdecl* ChatPlayerID)(CNetGamePlayer*(__int64 ChatPlayer));
//typedef __int64(__cdecl* Receive)(__int64*);
//typedef __int64(__cdecl* ChatPlayerID)(CNetGamePlayer*(__int64));

//typedef BOOL(__cdecl* CNetworkIncrementStatEvent)(int64_t a1_Event, int64_t a2_sender);
//typedef char*(__cdecl* fpGetOnlineName)(Player player);
//typedef Ped(__cdecl* fpGetPlayerPedScriptIndex)(Player player);
typedef bool(__cdecl* fpSendMessage2)(char* message, int* networkHandle);
typedef void(__cdecl* fpSetVehicleFixed)(Vehicle vehicle);

typedef void(__cdecl* fpSetModelAsNoLongerNeeded)(Hash model);

//typedef void(__cdecl* fpspoofer)(spoofing spoof);

typedef bool(__cdecl* fpGED)(int eventGroup, int eventIndex, __int64* argStruct, int argStructSize);
//typedef bool(__cdecl*	fpNetworkRequestControlOfEntity)(Entity entity);
//typedef void(__cdecl* fpSetVehicleDeformationFixed)(Vehicle vehicle);
//typedef bool(_cdecl* fpFileRegister)(int*, const char*, bool, const char*, bool);
typedef uint32_t(__cdecl* fpFileRegister)(int* textureID, const char* fullPath, bool _true, const char* fileName, bool _false);
typedef BOOL(_cdecl* fpGetEventData)(int eventGroup, int eventIndex, uint64_t* argStruct, int argStructSize);
//using GetEventData = bool(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
//GetEventData* m_GetEventData;

typedef BOOL(_cdecl* fpStatSetInt)(Hash statName, int value, BOOL save);
typedef BOOL(_cdecl* fpStatGetInt)(Hash statHash, int* outValue, int p2);
typedef BOOL(_cdecl* fpStatSetFloat)(Hash statName, float value, BOOL save);
typedef BOOL(_cdecl* fpStatSetBool)(Hash statName, BOOL value, BOOL save);
typedef void(__cdecl* fpREQUESTMODEL)(Hash model);
//typedef BOOL(__cdecl* fpHASMODELLOADED)(Hash model);
typedef BOOL(__cdecl* fpISMODELAVEHICLE)(Hash model);

//typedef void(__cdecl* twoBytes)(float x, float y, float z, int explosionType, float damageScale, BOOL isAudible, BOOL isInvisible, float cameraShake);
//typedef SHORT twoBytes;
typedef void(__cdecl* fpDrawRect)(float x, float y, float width, float height, int r, int g, int b, int a);
//typedef void(__cdecl*	fpDrawLine)(float x1, float y1, float z1, float x2, float y2, float z2, int red, int green, int blue, int alpha); //(Vector3* pos1, Vector3* pos2, int r, int g, int b, int a);
typedef BOOL(__cdecl* fpDrawNotification)(BOOL blink, BOOL showInBrief);
typedef uint64_t(__cdecl* fpGetNetworkTime)();
//typedef BOOL(__cdecl* fpSTARTPARTICLEFXNONLOOPEDONENTITY2)(char* effectName, Entity entity, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ, float scale, BOOL axisX, BOOL axisY, BOOL axisZ);
//typedef Object(__cdecl*	fp_CreateObject)(Hash modelHash, Vector3* pos, BOOL isNetwork, BOOL thisScriptCheck, BOOL dynamic);
//typedef BOOL(__cdecl* fpNetworkShopBeginService)(int* netshop, int p2, int p3, int p4, int amount, int bankVal);

typedef Pickup(_cdecl* fpCreateAmbientPickup)(DWORD pickupHash, Vector3* pos, int unk0, int value, DWORD modelHash, bool unk1, bool unk2);
//typedef void(__cdecl* fpCreateAmbientPickup2)(Hash pickupHash, float pos, float pos2, float pos3, int flag, int value, Hash modelHash, BOOL returnHandle, BOOL p8);
typedef void(_cdecl* SETVEHICLEFORWARDSPEED)(Vehicle vehicle, float speed);

typedef Vehicle(__cdecl* fpCreateVehicle)(Hash model, Vector3* pos, float heading, BOOL networked, BOOL unk2);

namespace cVehicleBypass
{
	extern Vehicle CVehBypass(Hash model, Vector3* pos, float heading, BOOL networked, BOOL unk2);
}
//typedef Player(__cdecl*	fpPlayerId)();
using fpGetLabelText = const char* (*) (void* this_, const char* label);

//using fpDisableErrorScreen = void(*)(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background);

typedef void(__cdecl* fpRemoveWeapons)(Ped ped, Hash weaponHash);
//typedef bool(__cdecl* fpmstartgetsessionbygamerhandle)(int metric_manager, rlGamerHandle* handles, int count, rlSessionByGamerTaskResult* result, int unk, bool* success, int* state);
//typedef void(__cdecl* fpmsendinviteacceptedpresenceevent)(void* presenceStruct, rlPresenceEventInviteAccepted* invite, int flags);
typedef void(__cdecl* fpmpresencestruct)(PVOID);

using fpmstartgetsessionbygamerhandle = bool(*)(int metric_manager, rage::rlGamerHandle* handles, int count, rage::rlSessionByGamerTaskResult* result, int unk, bool* success, int* state);

using fpmsendinviteacceptedpresenceevent = void(*)(void* presenceStruct, rlPresenceEventInviteAccepted* invite, int flags);





typedef void(__cdecl* fpDisableErrorScreen)(void(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background));
typedef void(__cdecl* fpRIDJoinFriends)(bool(int64_t* a1, int* hash));
//typedef void(__cdecl* fpRIDJoinFriendsV2)(bool(int* a1, __int64 a2, int* a3));
typedef void(__cdecl* fpRIDJoinFriendsV2)(int* a1, __int64 a2, int* a3);

typedef void(__cdecl* fpRIDJoinHandle)(std::int64_t* (int32_t friendIndex));
typedef void(__cdecl* fpRIDJoinFriendsHandler)(int64_t*);

typedef void(__cdecl* fpSpectatorCheck)(PUSHORT);


typedef void(__cdecl* fpRIDInviteFriends)(char(void* presenceStruct, rlPresenceEventInviteAccepted* invite, int flags));
typedef void(__cdecl* fpRIDInviteHandle)(char(int metric_manager, rage::rlGamerHandle* handles, int count, rage::rlSessionByGamerTaskResult* result, int unk, bool* success, int* state));

typedef void(__cdecl* fpNetworkSessionKickPlayer)(Player player, bool unk);

//using fpRIDJoinFriendsHandler = int64_t*;
//using fpRIDJoinHandle = std::int64_t* (int32_t friendIndex);
//using fpRIDJoinFriends = bool (int64_t* a1, int* hash);
namespace GameFunctions
{
	/*explicit GameFunctions();
	~GameFunctions() noexcept = default;
	GameFunctions(GameFunctions const&) = delete;
	GameFunctions(GameFunctions&&) = delete;
	GameFunctions& operator=(GameFunctions const&) = delete;
	GameFunctions& operator=(GameFunctions&&) = delete;*/
	static std::uint64_t** GlobalBase;


	/*static std::uint64_t** BaseGlobal;*/
	/*using pJoinPattern = int(__int64 a1, int a2, __int64* a3, int a4);
	pJoinPattern* m_JoinPattern;
	struct clockTime {
		int hour, minute, second;
	};
	clockTime* m_ClockTime;
	using SessionTime = void(int hour, int min);
	SessionTime* m_SessionTime;*/
}

//class MemoryHandle
//{
//public:
//	constexpr MemoryHandle(void* p = nullptr) :
//		m_Ptr(p)
//	{}
//
//	constexpr explicit MemoryHandle(std::uintptr_t p) :
//		m_Ptr(reinterpret_cast<void*>(p))
//	{}
//
//	template <typename T>
//	constexpr std::enable_if_t<std::is_pointer_v<T>, T> As()
//	{
//		return static_cast<T>(m_Ptr);
//	}
//
//	template <typename T>
//	constexpr std::enable_if_t<std::is_lvalue_reference_v<T>, T> As()
//	{
//		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(m_Ptr);
//	}
//
//	template <typename T>
//	constexpr std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> As()
//	{
//		return reinterpret_cast<T>(m_Ptr);
//	}
//
//	template <typename T>
//	constexpr MemoryHandle Add(T offset)
//	{
//		return MemoryHandle(As<std::uintptr_t>() + offset);
//	}
//
//	template <typename T>
//	constexpr MemoryHandle Sub(T offset)
//	{
//		return MemoryHandle(As<std::uintptr_t>() - offset);
//	}
//
//	constexpr MemoryHandle Rip()
//	{
//		if (!m_Ptr)
//			return nullptr;
//		return Add(As<std::int32_t&>()).Add(4U);
//	}
//
//	constexpr explicit operator bool() noexcept
//	{
//		return m_Ptr;
//	}
//protected:
//	void* m_Ptr;
//};

//class MemoryHandle
//{
//public:
//	constexpr MemoryHandle(void* p = nullptr) :
//		m_Ptr(p)
//	{}
//
//	/*constexpr */explicit MemoryHandle(std::uintptr_t p) :
//		m_Ptr(reinterpret_cast<void*>(p))
//	{}
//
//	template <typename T>
//	constexpr std::enable_if_t<std::is_pointer_v<T>, T> As()
//	{
//		return static_cast<T>(m_Ptr);
//	}
//
//	template <typename T>
//	constexpr std::enable_if_t<std::is_lvalue_reference_v<T>, T> As()
//	{
//		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(m_Ptr);
//	}
//
//	template <typename T>
//	constexpr std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> As()
//	{
//		return reinterpret_cast<T>(m_Ptr);
//	}
//
//	template <typename T>
//	constexpr MemoryHandle Add(T offset)
//	{
//		return MemoryHandle(As<std::uintptr_t>() + offset);
//	}
//
//	template <typename T>
//	constexpr MemoryHandle Sub(T offset)
//	{
//		return MemoryHandle(As<std::uintptr_t>() - offset);
//	}
//
//	constexpr MemoryHandle Rip()
//	{
//		if (!m_Ptr)
//			return nullptr;
//		return Add(As<std::int32_t&>()).Add(4U);
//	}
//
//	constexpr explicit operator bool() noexcept
//	{
//		return m_Ptr;
//	}
//protected:
//	void* m_Ptr;
//};
////////////////////////////////////////////////////////////////////////////////////////////////////////
//class MemoryHandle
//{
//public:
//	/**
//	 * \brief Constructs the object with a pointer
//	 * \param p The pointer to initialize the object with, optional
//	 */
//	constexpr MemoryHandle(void* p = nullptr) :
//		m_Ptr(p)
//	{}
//
//	/**
//	 * \brief Constructs the object with an integral pointer
//	 * \param p The integral pointer to initialize the object with
//	 */
//	explicit MemoryHandle(std::uintptr_t p) :
//		m_Ptr(reinterpret_cast<void*>(p))
//	{}
//
//	/**
//	 * \brief Retrieves the pointer as a pointer
//	 * \return A pointer
//	 */
//	template <typename T>
//	constexpr std::enable_if_t<std::is_pointer_v<T>, T> As()
//	{
//		return static_cast<T>(m_Ptr);
//	}
//
//	/**
//	 * \brief Retrieves the pointer as a reference
//	 * \return A pointer
//	 */
//	template <typename T>
//	constexpr std::enable_if_t<std::is_lvalue_reference_v<T>, T> As()
//	{
//		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(m_Ptr);
//	}
//
//	/**
//	 * \brief Retrieves the pointer as an integral pointer
//	 * \return An integral pointer
//	 */
//	template <typename T>
//	constexpr std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> As()
//	{
//		return reinterpret_cast<T>(m_Ptr);
//	}
//
//	/**
//	 * \brief Adds an offset to the pointer
//	 * \param offset The offset to be added
//	 * \return MemoryHandle
//	 */
//	template <typename T>
//	constexpr MemoryHandle Add(T offset)
//	{
//		return MemoryHandle(As<std::uintptr_t>() + offset);
//	}
//
//	/**
//	 * \brief Subtracted an offset to the pointer
//	 * \param offset The offset to be subtracted
//	 * \return MemoryHandle
//	 */
//	template <typename T>
//	constexpr MemoryHandle Sub(T offset)
//	{
//		return MemoryHandle(As<std::uintptr_t>() - offset);
//	}
//
//	/**
//	 * \brief Gets the relative displacement of the pointer
//	 * \return MemoryHandle
//	 */
//	constexpr MemoryHandle Rip()
//	{
//		if (!m_Ptr)
//			return nullptr;
//		return Add(As<std::int32_t&>()).Add(4U);
//	}
//
//	/**
//	 * \brief Checks if the stored pointer is valid
//	 * \return bool
//	 */
//	constexpr explicit operator bool() noexcept
//	{
//		return m_Ptr;
//	}
//protected:
//	void* m_Ptr;
//};
//
//class MemoryRegion
//{
//public:
//	constexpr explicit MemoryRegion(MemoryHandle base, std::size_t size) :
//		m_Base(base),
//		m_Size(size)
//	{}
//
//	constexpr MemoryHandle Base()
//	{
//		return m_Base;
//	}
//
//	constexpr MemoryHandle End()
//	{
//		return m_Base.Add(m_Size);
//	}
//
//	constexpr std::size_t Size()
//	{
//		return m_Size;
//	}
//
//	constexpr bool Contains(MemoryHandle p)
//	{
//		if (p.As<std::uintptr_t>() < m_Base.As<std::uintptr_t>())
//			return false;
//		if (p.As<std::uintptr_t>() > m_Base.Add(m_Size).As<std::uintptr_t>())
//			return false;
//
//		return true;
//	}
//protected:
//	MemoryHandle m_Base;
//	std::size_t m_Size;
//};
//
//class Module : public MemoryRegion
//{
//public:
//	explicit Module(std::nullptr_t) :
//		Module(static_cast<char*>(nullptr))
//	{}
//
//	explicit Module(const char* name) :
//		Module(GetModuleHandleA(name))
//	{
//	}
//
//	Module(HMODULE hmod) :
//		MemoryRegion(hmod, 0)
//	{
//		auto dosHeader = m_Base.As<IMAGE_DOS_HEADER*>();
//		auto ntHeader = m_Base.Add(dosHeader->e_lfanew).As<IMAGE_NT_HEADERS64*>();
//		m_Size = ntHeader->OptionalHeader.SizeOfImage;
//	}
//
//	template <typename TReturn, typename TOffset>
//	TReturn GetRVA(TOffset rva)
//	{
//		return m_Base.Add(rva).As<TReturn>();
//	}
//
//	IMAGE_DOS_HEADER* GetDosHeaders()
//	{
//		return m_Base.As<IMAGE_DOS_HEADER*>();
//	}
//
//	IMAGE_NT_HEADERS64* GetNtHeaders()
//	{
//		return m_Base.Add(m_Base.As<IMAGE_DOS_HEADER*>()->e_lfanew).As<IMAGE_NT_HEADERS64*>();
//	}
//};

class MemoryHandle
{
public:
	constexpr MemoryHandle(void* p = nullptr) :
		m_Ptr(p)
	{}
	/*constexpr explicit MemoryHandle(std::uintptr_t p) :*/
	explicit MemoryHandle(std::uintptr_t p) :
		m_Ptr(reinterpret_cast<void*>(p))
	{}

	template <typename T>
	constexpr std::enable_if_t<std::is_pointer_v<T>, T> As()
	{
		return static_cast<T>(m_Ptr);
	}

	template <typename T>
	constexpr std::enable_if_t<std::is_lvalue_reference_v<T>, T> As()
	{
		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(m_Ptr);
	}

	template <typename T>
	constexpr std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> As()
	{
		return reinterpret_cast<T>(m_Ptr);
	}

	template <typename T>
	constexpr MemoryHandle Add(T offset)
	{
		return MemoryHandle(As<std::uintptr_t>() + offset);
	}

	template <typename T>
	constexpr MemoryHandle Sub(T offset)
	{
		return MemoryHandle(As<std::uintptr_t>() - offset);
	}

	constexpr MemoryHandle Rip()
	{
		if (!m_Ptr)
			return nullptr;
		return Add(As<std::int32_t&>()).Add(4U);
	}

	constexpr explicit operator bool() noexcept
	{
		return m_Ptr;
	}
protected:
	void* m_Ptr;
};

class MemoryRegion
{
public:
	constexpr explicit MemoryRegion(MemoryHandle base, std::size_t size) :
		m_Base(base),
		m_Size(size)
	{}

	constexpr MemoryHandle Base()
	{
		return m_Base;
	}

	constexpr MemoryHandle End()
	{
		return m_Base.Add(m_Size);
	}

	constexpr std::size_t Size()
	{
		return m_Size;
	}

	constexpr bool Contains(MemoryHandle p)
	{
		if (p.As<std::uintptr_t>() < m_Base.As<std::uintptr_t>())
			return false;
		if (p.As<std::uintptr_t>() > m_Base.Add(m_Size).As<std::uintptr_t>())
			return false;

		return true;
	}
protected:
	MemoryHandle m_Base;
	std::size_t m_Size;
};

class Module : public MemoryRegion
{
public:
	explicit Module(std::nullptr_t) :
		Module(static_cast<char*>(nullptr))
	{}

	explicit Module(const char* name) :
		Module(GetModuleHandleA(name))
	{
	}

	Module(HMODULE hmod) :
		MemoryRegion(hmod, 0)
	{
		auto dosHeader = m_Base.As<IMAGE_DOS_HEADER*>();
		auto ntHeader = m_Base.Add(dosHeader->e_lfanew).As<IMAGE_NT_HEADERS64*>();
		m_Size = ntHeader->OptionalHeader.SizeOfImage;
	}

	template <typename TReturn, typename TOffset>
	TReturn GetRVA(TOffset rva)
	{
		return m_Base.Add(rva).As<TReturn>();
	}

	IMAGE_DOS_HEADER* GetDosHeaders()
	{
		return m_Base.As<IMAGE_DOS_HEADER*>();
	}

	IMAGE_NT_HEADERS64* GetNtHeaders()
	{
		return m_Base.Add(m_Base.As<IMAGE_DOS_HEADER*>()->e_lfanew).As<IMAGE_NT_HEADERS64*>();
	}
};

class Signature
{
public:
	struct Element
	{
		std::uint8_t m_Data{};
		bool m_Wildcard{};
	};

	explicit Signature(const char* pattern, const char* patternlog)
	{
		Log::Msg(patternlog);

		auto toUpper = [](char c) -> char
		{
			return c >= 'a' && c <= 'z' ? static_cast<char>(c + ('A' - 'a')) : static_cast<char>(c);
		};

		auto isHex = [&](char c) -> bool
		{
			switch (toUpper(c))
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				return true;
			default:
				return false;
			}
		};

		do
		{
			if (*pattern == ' ')
				continue;
			if (*pattern == '?')
			{
				m_Elements.push_back(Element{ {}, true });
				continue;
			}

			if (*(pattern + 1) && isHex(*pattern) && isHex(*(pattern + 1)))
			{
				char str[3] = { *pattern, *(pattern + 1), '\0' };
				auto data = std::strtol(str, nullptr, 16);

				m_Elements.push_back(Element{ static_cast<std::uint8_t>(data), false });
			}
		} while (*(pattern++));
	}

	MemoryHandle Scan(MemoryRegion region = Module(nullptr))
	{
		auto compareMemory = [](std::uint8_t* data, Element* elem, std::size_t num) -> bool
		{
			for (std::size_t i = 0; i < num; ++i)
			{
				if (!elem[i].m_Wildcard)
					if (data[i] != elem[i].m_Data)
						return false;
			}

			return true;
		};

		for (std::uintptr_t i = region.Base().As<std::uintptr_t>(), end = region.End().As<std::uintptr_t>(); i != end; ++i)
		{
			if (compareMemory(reinterpret_cast<std::uint8_t*>(i), m_Elements.data(), m_Elements.size()))
			{
				return MemoryHandle(i);
			}
		}

		return {};
	}
private:
	std::vector<Element> m_Elements;
};


class CNetGamePlayer2 : public rage::netPlayer
{
public:
	CPlayerInfo* m_player_info; //0x00A0
	uint32_t m_matchmaking_group; //0x0008
	bool m_is_spectating; //0x000C
	char pad_00AD[3]; //0x000AD
	uint64_t unk_00B0; //0x00B0
	char unk_00B8; //0x00B8
	char pad_00B9[3]; //0x00B9
	uint32_t unk_00BC; //0x00BC
	uint32_t unk_00C0; //0x00C0
	char pad_00C4[4]; //0x00C4
	ClanData m_clan_data; //0x00C8
	char m_crew_rank_title[25]; //0x0180
	bool m_is_rockstar_dev; //0x0199
	bool m_is_rockstar_qa; //0x019A
	bool m_is_cheater; //0x019B
	uint32_t unk_019C; //0x019C
	uint16_t unk_01A0; //0x01A0
	char unk_01A2; //0x01A2
	char pad_01A3; //0x01A3
	uint32_t m_phone_explosion_vehicle_net_id; //0x01A4
	uint16_t unk_01A8; //0x01A8
	bool m_has_started_transition; //0x01AA
	char pad_01AB[5]; //0x01AB
	rage::rlSessionInfo m_transition_session_info; //0x01A3
	char pad_022D[16]; //0x022D
	uint64_t unk_0230; //0x0230
	uint64_t unk_0238; //0x0238
	uint32_t m_mute_count; //0x0240
	uint32_t m_mute_talkers_count; //0x0244
	char pad_0248[5]; //0x0248
	bool m_have_communication_privileges; //0x024D
	uint16_t unk_024E; //0x024E
	uint16_t unk_0250; //0x0250
	char pad_0252[2]; //0x0252
	uint32_t m_cheat_report_ids[20]; //0x0254
	uint32_t m_num_cheat_reports; //0x02A4
	uint8_t unk_02A8; //0x02A8
	char pad_02A9[3]; //0x02A9
	uint32_t unk_02AC; //0x02AC
	char unk_02B0; //0x02B0
	char pad_02B1[3]; //0x02B1
	uint32_t unk_02B4; //0x02B4
	uint32_t m_account_id; //0x02B4
	uint32_t m_unk_02BC; //0x02BC
}; //Size: 0x02C0

typedef long long int64__;
typedef void(__cdecl* fpChatMessage)(__int64 a1, __int64 a2, __int64 a3, char* message);
using fpGetSender = CNetGamePlayer2*(__int64);


typedef void(__cdecl* GlobalBase)(std::uint64_t** m_GlobalBase);
class hook_sender
{
public:
	explicit hook_sender();
	~hook_sender() noexcept = default;
	hook_sender(hook_sender const&) = delete;
	hook_sender(hook_sender&&) = delete;
	hook_sender& operator=(hook_sender const&) = delete;
	hook_sender& operator=(hook_sender&&) = delete;
	static fpGetSender* get_sender;
	static GlobalBase* baseGlobal;
};
inline std::unique_ptr<hook_sender> g_sender;

typedef char* (__cdecl* sub7FF71339282C)(int* a1, __int64 a2, int* a3);
//char __fastcall 

class Hooking
{
private:
	static BOOL InitializeHooks();
	/*void fileregistermax();*/
	static void FindPatterns();
	static void FailPatterns(const char* name);
public:
	static void JoinPatterns();
	static sub7FF71339282C sub_7FF71339282C;
	/*static BOOL hk_ridJoiner(int64_t* a1, int* hash);*/
	static HMODULE _hmoduleDLL;
	static patternglobal globalpattern;
	static listblip bliplist;
	static patternworld worldpattern;
	static void* invoker_return_address;
	static PVOID m_native_return;
	static void* pickupdrop;
	static fpreplay			replay_interface;
	static fplaylist player_list;
	static fpunkmodel unk_model;

	static fphandlingindex handling_index;
	static fphandlinghash handling_hash;
	static fphandlingIndexOffset handlingIndexOffsetInModelInfo;
	static fpPedPoolAddress PedPoolAddress;
	static fpObjectPoolAddress ObjectPoolAddress;
	static fpEntityPoolAddress EntityPoolAddress;
	static fpVehiclePoolAddress VehiclePoolAddress;
	static fpPickupObjectPoolAddress PickupObjectPoolAddress;



	static fpvehicleClassOffset vehicleClassOffset;
	static fpmodelNum1 modelNum1;
	static fpmodelNum2 modelNum2;
	static fpmodelNum3 modelNum3;
	static fpmodelNum4 modelNum4;
	static fpmodelHashTable modelHashTable;
	static fpmodelHashEntries modelHashEntries;

	//static fpSTARTPARTICLEFXNONLOOPEDONENTITY2            _START_PARTICLE_FX_NON_LOOPED_ON_ENTITY_2;
	/*static void*					m_onlineName;*/
	/*static void rid_main(int rid);*/
	static bool Hooking::protect;
	static bool Hooking::redirectAll;
	/*static bool Hooking::protectsr;*/
	static bool Hooking::nonhostkicks;
	static bool Hooking::noteleports;
	static bool Hooking::nosoundspams;
	static bool Hooking::ceokicks;
	static bool Hooking::missionsend;
	static bool Hooking::errortransaction;
	static bool Hooking::bounties;
	static bool Hooking::notifications;
	static bool Hooking::wantedlevels;
	static bool Hooking::dump;
	static bool Hooking::GED(int eventGroup, int eventIndex, __int64* argStruct, int argStructSize);
	static fpFileRegister            pRegisterFile;
	static bool Hooking::spectateplayer;
	static void Hooking::setinspectatormode(BOOL toggle, Ped playerPed);
	static void Hooking::settime(int Hours, int Minutes, int Seconds);
	static std::vector<LPVOID>		m_hooks;
	static uint64_t* m_frameCount;
	static fpIsDLCPresent			is_DLC_present;
	static fpsIncrementStatEvent	IncrementStatEvent;
	//static fpSetName			    SetName;
	static fpAddOwnedExplosion      add_owned_explosion;
	static void						ExplosionBypass(bool toggle);
	static void						ownedExplosionBypass(bool toggle);
	static fpTriggerScriptEvent	    trigger_script_event;
	static fpSetLobbyWeather	    set_lobby_weather;
	static fpGetEventData	        get_event_data;
	static fpIncrementStatHook	    increment_stat_hook;
	static fpSetLobbyTime	        set_lobby_time;
	static fpSendMessage2	        send_message2;
	/*static fpGetPlayerPed	        get_player_ped;*/
	static fpGetPlayerAddress       GetPlayerAddress;
	static fpAddressToEntity		AddressToEntity;
	static fpGetPlayerName	        get_player_name;
	static fpNetworkIsSessionStarted	network_is_session_started;
	/*static Receive						m_ChatReceive;
	static ChatPlayerID					m_GetChatPlayerID;*/
	/*static __int64* m_ChatReceive;*/
	static fpChatMessage                           get_message;

	static fpNetworkSessionKickPlayer              network_session_kick_player;
	/*static GetChatPlayerID* m_GetChatPlayerID;*/

	/*static CNetworkIncrementStatEvent	NetworkIncrementStatEvent;*/
	/*static fpGetPlayerPedScriptIndex	        get_player_ped_script_index;*/
	static fpAddTextCompSubstrPlayerName	    add_text_comp_substr_playername;
	static fpEndTextCmdDisplayText	    end_text_cmd_display_text;
	static fpBeginTextCmdDisplayText	    begin_text_cmd_display_text;
	/*static fpIsPedShooting	        is_ped_shooting;*/
	static fpStatSetInt							stat_set_int;
	static fpStatGetInt							stat_get_int;
	static fpStatSetFloat						stat_set_float;
	static fpStatSetBool						stat_set_bool;
	static fpCreateAmbientPickup				create_ambient_pickup;
	static SETVEHICLEFORWARDSPEED				SET_VEHICLE_FORWARD_SPEED;
	/*static fpCreateAmbientPickup2				create_ambient_pickup2;*/
	static fpREQUESTMODEL				request_model;
	/*static fpHASMODELLOADED				has_model_loaded;*/
	static fpISMODELAVEHICLE			is_model_a_vehicle;
	//static fp_CreateObject						create_object;
	//static fpNetworkShopBeginService		network_shop_begin_service;
	static void Start(HMODULE hmoduleDLL);
	static void Cleanup();
	static eGameState GetGameState();
	static uint64_t getWorldPtr();
	static void onTickInit();
	static void onTickInit2();
	static bool HookNatives();
	/*static bool HookGetEvent(int eventGroup, int eventIndex, uint64_t * argStruct, int argStructSize);*/
	static __int64** getGlobalPtr();
	/*static __int64* getGlobalPtr1(int index);
	static __int64* setTunable(int Tunable);*/
	static void defuseEvent(RockstarEvent e, bool toggle);
	static void patchEvent(RockstarEvent e, bool toggle);

	static __int64* getGlobalPatern(int index);
	/*static bool loadmods;*/
	static Ped get_player_ped(Player player);
	/*static fpPlayerId							player_id;*/
	// Native function handler type
	typedef void(__cdecl* NativeHandler)(scrNativeCallContext* context);

	static fpGetLabelText GetLabelText;
	using fpGetLabelText = const char* (*) (void* this_, const char* label);

	static fpRemoveWeapons RemoveWeapons;
	static fpmstartgetsessionbygamerhandle m_start_get_session_by_gamer_handle;
	static fpmsendinviteacceptedpresenceevent m_send_invite_accepted_presence_event;
	using fpmstartgetsessionbygamerhandle = bool(*)(int metric_manager, rage::rlGamerHandle* handles, int count, rage::rlSessionByGamerTaskResult* result, int unk, bool* success, int* state);
	using fpmsendinviteacceptedpresenceevent = void(*)(void* presenceStruct, rlPresenceEventInviteAccepted* invite, int flags);

	static fpmpresencestruct m_presence_struct;

	static fpDisableErrorScreen DisableErrorScreen;
	//using fpDisableErrorScreen = void(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background);
	static fpRIDJoinFriends RIDJoinFriends;
	static fpRIDJoinFriendsV2 RIDJoinFriendsV2;
	static fpRIDJoinHandle RIDJoinHandle;
	//using fpRIDJoinFriendsHandler = int64_t*;
	static fpRIDJoinFriendsHandler RIDJoinFriendsHandler;
	static fpSpectatorCheck SpectatorCheck;

	static fpRIDInviteFriends      RIDInviteFriends;
	static fpRIDInviteHandle        RIDInviteHandle;

	/*using fpRIDJoinHandle = std::int64_t* (int32_t friendIndex);
	using fpRIDJoinFriends = bool (int64_t* a1, int* hash);*/

	struct NativeRegistrationNew
	{
		uint64_t nextRegistration1;
		uint64_t nextRegistration2;
		Hooking::NativeHandler handlers[7];
		uint32_t numEntries1;
		uint32_t numEntries2;
		uint64_t hashes;

		inline NativeRegistrationNew* getNextRegistration()
		{
			uintptr_t result;
			auto v5 = reinterpret_cast<uintptr_t>(&nextRegistration1);
			auto v12 = 2i64;
			auto v13 = v5 ^ nextRegistration2;
			auto v14 = (char*)&result - v5;
			do
			{
				*(DWORD*)&v14[v5] = (DWORD)v13 ^ *(DWORD*)v5;
				v5 += 4i64;
				--v12;
			} while (v12);

			return reinterpret_cast<NativeRegistrationNew*>(result);
		}

		inline uint32_t getNumEntries()
		{
			return (reinterpret_cast<uintptr_t>(&numEntries1)) ^ numEntries1 ^ numEntries2;
		}
		/*inline void setNumEntries(uint32_t entries)
		{
			numEntries1 = (uint32_t)& numEntries1 ^ entries;
			numEntries2 = 0;
		}*/
		inline uint64_t getHash(uint32_t index)
		{
			auto naddr = 16 * index + reinterpret_cast<uintptr_t>(&nextRegistration1) + 0x54;
			auto v8 = 2i64;
			uint64_t nResult;
			auto v11 = (char*)&nResult - naddr;
			auto v10 = naddr ^ *(DWORD*)(naddr + 8);
			do
			{
				*(DWORD*)&v11[naddr] = (DWORD)v10 ^ *(DWORD*)(naddr);
				naddr += 4i64;
				--v8;
			} while (v8);

			return nResult;
		}
	};
	static NativeHandler GetNativeHandler(uint64_t origHash);

	static bool geteventdata;
	static void* m_OriginalJoinPlayer;
};


void WAIT(DWORD ms);
void WAIT2(DWORD ms);

//enum eThreadState
//{
//	ThreadStateIdle = 0x0,
//	ThreadStateRunning = 0x1,
//	ThreadStateKilled = 0x2,
//	ThreadState3 = 0x3,
//	ThreadState4 = 0x4,
//};
//
//struct scrThreadContext
//{
//	int ThreadID;
//	int ScriptHash;
//	eThreadState State;
//	int _IP;
//	int FrameSP;
//	int _SPP;
//	float TimerA;
//	float TimerB;
//	int TimerC;
//	int _mUnk1;
//	int _mUnk2;
//	int _f2C;
//	int _f30;
//	int _f34;
//	int _f38;
//	int _f3C;
//	int _f40;
//	int _f44;
//	int _f48;
//	int _f4C;
//	int _f50;
//	int pad1;
//	int pad2;
//	int pad3;
//	int _set1;
//	int pad[17];
//};

//struct scrThread
//{
//	void *vTable;
//	scrThreadContext m_ctx;
//	void *m_pStack;
//	void *pad;
//	void *pad2;
//	const char *m_pszExitMessage;
//};
//


/*
//CPatternResult
*/

class CPatternResult
{
public:
	CPatternResult(void* pVoid);
	CPatternResult(void* pVoid, void* pBegin, void* pEnd);
	~CPatternResult();

	template <typename rT>
	rT* get(int offset = 0)
	{
		rT* ret = nullptr;
		if (m_pVoid != nullptr)
			ret = reinterpret_cast<rT*>(reinterpret_cast<char*>(m_pVoid) + offset);
		return ret;
	}

	template <typename rT>
	rT* get_rel(int offset = 0)
	{
		rT* result = nullptr;
		int32_t	rel;
		char* ptr = get<char>(offset);

		if (ptr == nullptr)
			goto LABEL_RETURN;

		rel = *(int32_t*)ptr;
		result = reinterpret_cast<rT*>(ptr + rel + sizeof(rel));

	LABEL_RETURN:
		return result;
	}

	template <typename rT>
	rT* section_begin()
	{
		return reinterpret_cast<rT*>(m_pBegin);
	}

	template <typename rT>
	rT* section_end()
	{
		return reinterpret_cast<rT*>(m_pEnd);
	}

protected:
	void* m_pVoid = nullptr;
	void* m_pBegin = nullptr;
	void* m_pEnd = nullptr;
};

class CMetaData
{
public:
	static uint64_t	begin();
	static uint64_t	end();
	static DWORD	size();
	static void		init();
private:
	static uint64_t	m_begin;
	static uint64_t	m_end;
	static DWORD	m_size;
};

struct twoBytes
{
	BYTE	bytes[2];

	bool	empty();
};

class CBlip
{
public:
	__int32 iID; //0x0000 
	__int8 iID2; //0x0004 
	char _0x0005[3];
	BYTE N000010FB; //0x0008 (80 = moves with player, some values will turn icon into map cursor and break it)
	char _0x0009[7];
	Vector3 v3Pos;
	char _0x001C[6];
	BYTE btFocused; //0x0022   (Focused? 0100 0000)
	char _0x0023[5];
	char* szMessage; //0x0028 If not null, contains the string of whatever the blip says when selected.
	char _0x0030[16];
	int iIcon; //0x0040
	char _0x0044[4];
	DWORD dwColor; //0x0048 (Sometimes works?)
	char _0x004C[4];
	float fScale; //0x0050 
	__int16 iRotation; //0x0054 Heading
	BYTE btInfoIDType; //0x0056 GET_BLIP_INFO_ID_TYPE
	BYTE btZIndex; //0x0057 
	BYTE btDisplay; //0x0058  Also Visibility 0010
	BYTE btAlpha; //0x0059
};//Size=0x005A

/*
//CPattern
*/
typedef	std::vector<CPatternResult>	vec_result;
class CPattern
{
public:
	CPattern(char* szByte, char* szMask);
	~CPattern();

	CPattern& find(int i = 0, uint64_t startAddress = 0);		//scans for i patterns
	CPattern& virtual_find(int i = 0, uint64_t startAddress = 0);
	CPatternResult	get(int i);				//returns result i

protected:
	char* m_szByte;
	char* m_szMask;
	bool			m_bSet;
	vec_result		m_result;

	bool		match(int i = 0, uint64_t startAddress = 0, bool virt = false);
	bool		byte_compare(const BYTE* pData, const BYTE* btMask, const char* szMask);
	uint64_t	find_pattern(uint64_t i64Address, uint64_t end, BYTE* btMask, char* szMask);
	uint64_t	virtual_find_pattern(uint64_t address, BYTE* btMask, char* szMask);
};
class CHooking
{
public:
	static twoBytes* m_ownedExplosionBypass;
	/*static BYTE* m_ownedExplosionBypass;*/
	static fpDrawRect							draw_rect;
	//static fpDrawLine							draw_line;
	static fpDrawNotification					draw_notification;
	static fpGetNetworkTime						get_network_time;
	/*static MemoryPool**				m_entityPool;*/
	/*static MemoryPool**				m_pedPool;*/
	static fpSetVehicleFixed					set_vehicle_fixed;
	static fpSetModelAsNoLongerNeeded Set_Model_As_No_Longer_Needed;
	/*static fpspoofer					spoofer;*/

	static fpCreateVehicle						create_vehicle;
	//static threeBytes*				m_infAmmo;
	//static threeBytes*				m_noReload;
	//static fpSetVehicleDeformationFixed			set_vehicle_deformation_fixed;
	//static fpNetworkRequestControlOfEntity		network_request_control_of_entity;
	static void m_JmpRbx();
};

//typedef int CNetworkIncrementStatEvent;
//typedef int CNetGamePlayer;
//struct


//struct MemoryPool
//{
//	uintptr_t ListAddr;
//	char* BoolAdr;
//	int MaxCount;
//	int ItemSize;
//};

//#pragma pack(push, 1)
//struct threeBytes
//{
//	BYTE	byte[3];
//
//	bool	empty();
//};

struct rockstar_events
{
	std::string name;
	uint64_t ptr;
	unsigned char buffer;
	bool enabled;
};

class ScriptGlobal
{
public:
	constexpr explicit ScriptGlobal(std::size_t index) :
		m_Index(index)
	{}

	constexpr ScriptGlobal Add(std::size_t index)
	{
		return ScriptGlobal(m_Index + index);
	}

	constexpr ScriptGlobal Add(std::size_t index, std::size_t x)
	{
		return Add(1 + (index * x));
	}

	template <typename T>
	std::enable_if_t<std::is_pointer<T>::value, T> As() const
	{
		return reinterpret_cast<T>(IndexToPtr(m_Index));
	}

	template <typename T>
	std::enable_if_t<std::is_lvalue_reference<T>::value, T> As() const
	{
		return *reinterpret_cast<std::add_pointer_t<std::remove_reference_t<T>>>(IndexToPtr(m_Index));
	}

	template <typename T>
	std::enable_if_t<std::is_same<T, std::uintptr_t>::value, T> As() const
	{
		return reinterpret_cast<std::uintptr_t>(As<void*>());
	}
private:
	static void* IndexToPtr(std::size_t index)
	{
		/*g_GameVariables->m_GlobalBase = reinterpret_cast<std::uint64_t**>(hook_sender::baseGlobal);*/
		return (g_GameVariables->m_GlobalBase[index >> 0x12 & 0x3F]) + (index & 0x3FFFF);
		//return (GameFunctions::GlobalBase[index >> 0x12 & 0x3F]) + (index & 0x3FFFF);
	}

	std::uintptr_t m_Index;
};
//class ScriptGlobal
//{
//public:
//	constexpr explicit ScriptGlobal(std::size_t index) :
//		m_Index(index)
//	{}
//
//	constexpr ScriptGlobal Add(std::size_t index)
//	{
//		return ScriptGlobal(m_Index + index);
//	}
//
//	constexpr ScriptGlobal Add(std::size_t index, std::size_t x)
//	{
//		return Add(1 + (index * x));
//	}
//
//	template <typename T>
//	std::enable_if_t<std::is_pointer<T>::value, T> As() const
//	{
//		return reinterpret_cast<T>(IndexToPtr(m_Index));
//	}
//
//	template <typename T>
//	std::enable_if_t<std::is_lvalue_reference<T>::value, T> As() const
//	{
//		return *reinterpret_cast<std::add_pointer_t<std::remove_reference_t<T>>>(IndexToPtr(m_Index));
//	}
//
//	template <typename T>
//	std::enable_if_t<std::is_same<T, std::uintptr_t>::value, T> As() const
//	{
//		return reinterpret_cast<std::uintptr_t>(As<void*>());
//	}
//private:
//	static void* IndexToPtr(std::size_t index)
//	{
//		return (GameFunctions::GlobalBase[index >> 0x12 & 0x3F]) + (index & 0x3FFFF);
//		/*return (&Hooking::getGlobalPtr()[index >> 0x12 & 0x3F]) + (index & 0x3FFFF);*/
//	}
//	std::uintptr_t m_Index;
//};


namespace Settings
{
	extern bool m_RIDJoiner;
	extern int m_RIDJoinerTarget;
	extern bool m_RIDInviter;
	extern int m_RIDInviterTarget;
};


//class Settings
//{
//public:
//	int m_RIDJoiner;
//	int m_RIDJoinerTarget;
//};
//extern Settings g_Settings;
//struct Hkg
//{
//	void* m_OriginalRIDJoinHandle{};
//	void* m_OriginalRIDJoinFriends{};
//};

//using SendNetworkInfo = bool (*)(netPlayerData* player, int64_t a2, int64_t a3, DWORD* a4);
//SendNetworkInfo* m_NetworkInfo;
//
//using RIDJoinHandle = std::int64_t* (int32_t friendIndex);
//RIDJoinHandle* m_RIDJoinHandle;
//using RIDJoinFriends = bool (int64_t a1, int* hash);
//RIDJoinFriends* m_RIDJoinFriends;
//
//
//using RIDJoinFriendsHandler = bool (int64_t* a1, int* hash);
//RIDJoinFriendsHandler* m_RIDJoinFriendsHandler;
//
//	/*using RIDJoinHandle = bool (*)(std::int64_t* (int32_t friendIndex));
//	RIDJoinHandle* m_RIDJoinHandle;
//	using RIDJoinFriends = bool (*)(int64_t* a1, int* hash);
//	RIDJoinFriends* m_RIDJoinFriends;
//	using RIDJoinFriendsHandler = bool (*)(int64_t* a1, int* hash);*/
//
//
//


//#include <xkeycheck.h>
//
//class TeleportWaypoint
//{
//public:
//	explicit TeleportWaypoint(std::int32_t entity, float x, float y) :
//			m_Entity(entity),
//			m_CoordX(x),
//			m_CoordY(y)
//		{
//		}
//		bool IsDone()/* override*/
//		{
//			return (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(m_CoordX, m_CoordY, 1000.f, &m_Ground, false) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(m_Entity));
//		}
//		void OnSuccess()/* override*/
//		{
//			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(m_Entity, m_CoordX, m_CoordY, m_Ground + 2.f, FALSE, FALSE, FALSE);
//		}
//		void OnFailure()/* override*/
//		{
//			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(m_Entity);
//			STREAMING::REQUEST_COLLISION_AT_COORD(m_CoordX, m_CoordY, m_CoordZ);
//			if (m_CoordZ <= 0.f)
//				m_CoordZ = 1000.f;
//			m_CoordZ -= 100.f;
//		}
//private:
//			float m_CoordX;
//			float m_CoordY;
//			float m_CoordZ = 1000.f;
//			float m_Ground = 0.f;
//			std::int32_t m_Entity;
//			std::function<void()> m_Action;
//};
//
//struct Vector2
//{
//	float x{};
//	float y{};
//};
//namespace WayPointCoords
//{
//	Vector2* m_WaypointCoords;
//}
namespace badstuffcode
{
	extern void desyncPlayer();
}

class script_global
{
public:
	constexpr script_global(std::size_t index) :
		m_index(index)
	{
	}

	constexpr script_global at(std::ptrdiff_t index) const
	{
		return m_index + index;
	}
	constexpr script_global at(std::ptrdiff_t index, std::size_t size) const
	{
		return m_index + 1 + (index * size);
	}

	template<typename T>
	std::enable_if_t<std::is_pointer_v<T>, T> as() const
	{
		return static_cast<T>(get());
	}

	template<typename T>
	std::enable_if_t<std::is_lvalue_reference_v<T>, T> as() const
	{
		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
	}

private:
	void* get() const;
	std::size_t m_index;
};

//class script_global
//{
//public:
//	explicit script_global(std::size_t index);
//
//	script_global at(std::ptrdiff_t index);
//	script_global at(std::ptrdiff_t index, std::size_t size);
//
//	template <typename T>
//	std::enable_if_t<std::is_pointer_v<T>, T> as() const
//	{
//		return static_cast<T>(get());
//	}
//
//	template <typename T>
//	std::enable_if_t<std::is_lvalue_reference_v<T>, T> as() const
//	{
//		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
//	}
//private:
//	void* get() const;
//	std::size_t m_index;
//};

struct ImVec4
{
	float                                                     x, y, z, w;
	constexpr ImVec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
	constexpr ImVec4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) { }
};
//#define IM_MSVC_RUNTIME_CHECKS_RESTORE  __pragma(runtime_checks("",restore)) __pragma(check_stack())    __pragma(strict_gs_check(pop))
//
//IM_MSVC_RUNTIME_CHECKS_RESTORE

enum class NotificationType {
	INFO,
	SUCCESS,
	WARNING,
	DANGER,
};

struct notification
{
	NotificationType type;
	const std::string title;
	const std::string message;
	const std::chrono::time_point<std::chrono::system_clock> created_on;
	const float destroy_in;
	float alpha;
};

class notification_service final
{
	std::unordered_map<std::size_t, notification> notifications;

public:
	notification_service();
	virtual ~notification_service();

	void push(notification);
	void push(std::string, std::string);
	void push_warning(std::string, std::string);
	void push_error(std::string, std::string);
	std::vector<notification> get();

	std::map<NotificationType, ImVec4> notification_colors = {
		{NotificationType::INFO, ImVec4(0.80f, 0.80f, 0.83f, 1.00f)},
		{NotificationType::SUCCESS, ImVec4(0.29f, 0.69f, 0.34f, 1.00f)},
		{NotificationType::WARNING, ImVec4(0.69f ,0.49f, 0.29f, 1.00f) },
		{NotificationType::DANGER, ImVec4(0.69f, 0.29f , 0.29f, 1.00f)},
	};

};

inline notification_service* g_notification_service{};

namespace nc
{
	extern 	int dancenightclub(int iParam0);
}
class Param1
{
public:

	char* f_1;
	char* f_2;
};


namespace rage
{


	//class scriptHandler
	//{
	//public:
	//	class atDScriptObjectNode : public atDNode<scriptHandlerObject*>
	//	{
	//	};
	//public:
	//	virtual ~scriptHandler() = default;                                                                   //  0 (0x00)

	//	virtual bool _0x08() = 0;                                                                             //  1 (0x08)

	//	virtual void _0x10() = 0;                                                                             //  2 (0x10)

	//	virtual void cleanup_objects() = 0;                                                                   //  3 (0x18)

	//	virtual scriptId* _0x20() = 0;                                                                        //  4 (0x20)

	//	virtual scriptId* get_id() = 0;                                                                       //  5 (0x28)

	//	// Returns whether the script handler belongs to a networked script.
	//	virtual bool is_networked() = 0;                                                                      //  6 (0x30)

	//	// Initializes the network component for the script handler.
	//	virtual void init_net_component() = 0;                                                                //  7 (0x38)

	//	// Deletes the script handler's network component, if it exists.
	//	virtual void reset_net_component() = 0;                                                               //  8 (0x40)

	//	// Destroys the script handler.
	//	virtual bool destroy() = 0;                                                                           //  9 (0x48)

	//	// Adds the object to the script handler's list of objects.
	//	virtual void add_object(scriptHandlerObject*, bool is_network, bool is_network_and_scriptcheck) = 0; // 10 (0x50)

	//	// Something related to reservations.
	//	virtual void _0x58(void*) = 0;                                                                        // 11 (0x58)

	//	virtual void register_resource(scriptResource*, void*) = 0;                                           // 12 (0x60)

	//	virtual void _0x68() = 0;                                                                             // 13 (0x68)

	//	virtual void _0x70() = 0;                                                                             // 14 (0x70)

	//	virtual void _0x78() = 0;                                                                             // 15 (0x78)

	//	virtual void _0x80() = 0;                                                                             // 16 (0x80)

	//	virtual void _0x88() = 0;                                                                             // 17 (0x88)

	//	virtual void _0x90() = 0;                                                                             // 18 (0x90)

	//	virtual void _0x98() = 0;                                                                             // 19 (0x98)
	//public:
	//	void* m_0x08;                                // 0x08
	//	void* m_0x10;                                // 0x10
	//	scrThread* m_script_thread;                  // 0x18
	//	atDList<atDScriptObjectNode> m_objects;      // 0x20
	//	scriptResource* m_resource_list_head;        // 0x30
	//	scriptResource* m_resource_list_tail;        // 0x38
	//	void* m_0x40;                                // 0x40
	//	scriptHandlerNetComponent* m_net_component;  // 0x48
	//	std::uint32_t m_0x50;                        // 0x50
	//	std::uint32_t m_0x54;                        // 0x54
	//	std::uint32_t m_0x58;                        // 0x58
	//	std::uint32_t m_0x60;                        // 0x5C
	//};

	//class scriptHandlerMgr
	//{
	//public:
	//	virtual ~scriptHandlerMgr() = default;

	//	// Initializes some scripting-related pools.
	//	virtual bool initialize() = 0;                                                          // 1 (0x08)

	//	// Called every tick.
	//	virtual void _0x10() = 0;                                                               // 2 (0x10)

	//	// Frees some scripting-related pools.
	//	virtual void shutdown() = 0;                                                            // 3 (0x18)

	//	virtual void _0x20() = 0;                                                               // 4 (0x20)
	//	virtual void _0x28() = 0;                                                               // 5 (0x28)
	//	virtual void _0x30() = 0;                                                               // 6 (0x30)

	//	// Generates a rage::scriptId from the thread and copies it over to a global structure.
	//	virtual void _0x38(scrThread*) = 0;                                                     // 7 (0x38)

	//	// Allocates and constructs a script handler.
	//	virtual scriptHandler* create_script_handler() = 0;                                     // 8 (0x40)

	//	// Finds the script handler for a given script id.
	//	virtual scriptHandler* get_script_handler(scriptId*) = 0;                               // 9 (0x48)

	//	// Attaches a script thread.
	//	virtual void attach_thread(scrThread*) = 0;                                             // 10 (0x50)

	//	// Detaches a script thread.
	//	virtual void detach_thread(scrThread*) = 0;                                             // 11 (0x58)

	//	// Called when a player joins.
	//	virtual void on_player_join(rage::netPlayer*) = 0;                                            // 12 (0x60)

	//	// Called when a player leaves.
	//	virtual void on_player_left(rage::netPlayer*) = 0;                                            // 13 (0x68)

	//	virtual std::int32_t _0x70() = 0;                                                       // 14 (0x70)
	//	virtual void* _0x78() = 0;                                                              // 15 (0x78)
	//public:
	//	char m_padding1[0x28];                         // 0x08
	//	bool m_initialized;                            // 0x30
	//	bool m_initialized2;                           // 0x31
	//	char m_padding2[0x0E];                         // 0x32
	//	rage::netLoggingInterface* m_logger;           // 0x40
	//};
	//class sysMemAllocator
	//{
	//public:
	//	virtual ~sysMemAllocator() = 0;

	//	virtual void SetQuitOnFail(bool) = 0;
	//	virtual void* Allocate(size_t size, size_t align, int subAllocator) = 0;

	//	inline void* allocate(size_t size, size_t align, int subAllocator)
	//	{
	//		return Allocate(size, align, subAllocator);
	//	}

	//	virtual void* TryAllocate(size_t size, size_t align, int subAllocator) = 0;

	//	virtual void Free(void* pointer) = 0;

	//	virtual void free(void* pointer)
	//	{
	//		return Free(pointer);
	//	}

	//	virtual void TryFree(void* pointer) = 0;

	//	virtual void Resize(void* pointer, size_t size) = 0;

	//	virtual sysMemAllocator* GetAllocator(int allocator) const = 0;

	//	virtual sysMemAllocator* GetAllocator(int allocator) = 0;

	//	virtual sysMemAllocator* GetPointerOwner(void* pointer) = 0;

	//	virtual size_t GetSize(void* pointer) const = 0;

	//	virtual size_t GetMemoryUsed(int memoryBucket) = 0;

	//	virtual size_t GetMemoryAvailable() = 0;

	//public:

	//	static sysMemAllocator* sysMemAllocator::UpdateAllocatorValue()
	//	{
	//		//B9 ? ? ? ? 48 8B 0C 01 45 33 C9 49 8B D2 48
	//		auto g_gtaTlsEntry = *(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8); //This has been 0xC8 since 323, I'm not adding this signature to pointers...

	//		/*if (g_gtaTlsEntry == nullptr)
	//			LOG(FATAL) << "Failed to find tlsEntry within GTA5.exe via __readgsqword";*/

	//		*(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8) = g_gtaTlsEntry;
	//		*(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8 - 8) = g_gtaTlsEntry;

	//		return g_gtaTlsEntry;
	//	}
	//};

	//inline sysMemAllocator* GetAllocator()
	//{
	//	sysMemAllocator* allocator = *(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8);

	//	if (!allocator)
	//	{
	//		return sysMemAllocator::UpdateAllocatorValue();
	//	}

	//	return allocator;
	//}
	////tlsContext has changed
	//class tlsContext
	//{
	//public:
	//	char m_padding1[0xC8]; // 0x00
	//	sysMemAllocator* m_allocator; // 0xC8
	//	char m_padding2[0x778]; // 0xD0
	//	scrThread* m_script_thread; // 0x848
	//	bool m_is_script_thread_active; // 0x850

	//	static tlsContext* get()
	//	{
	//		return *reinterpret_cast<tlsContext**>(__readgsqword(0x58));
	//	}
	//};
	/*static_assert(sizeof(tlsContext) == 0x858);*/

	//class CPed : public rage::fwEntity
	//{
	//public:
	//	uint8_t m_hostility; //0x018C
	//	char pad_018D[243]; //0x018D
	//	float m_health; //0x0280
	//	float m_maxhealth; //0x0284
	//	char pad_0288[152]; //0x0288
	//	rage::fvector3 m_velocity; //0x0320
	//	char pad_032C[2532]; //0x032C
	//	class CAutomobile* m_vehicle; //0x0D10
	//	char pad_0D18[912]; //0x0D18
	//	class CPlayerInfo* m_player_info; //0x10A8
	//	char pad_10B0[8]; //0x10B0
	//	class CPedWeaponManager* m_weapon_manager; //0x10B8
	//	char pad_10C0[939]; //0x10C0
	//	uint8_t m_ped_task_flag; //0x146B
	//	char pad_146C[160]; //0x146C
	//	float m_armor; //0x150C
	//}; //Size: 0x1510
	/*static_assert(sizeof(CPed) == 0x1510);*/
	//class tlsContext
	//{
	//public:
	//	char m_padding1[0xC8]; // 0x00
	//	sysMemAllocator* m_allocator; // 0xC8
	//	char m_padding2[0x770]; // 0xD0
	//	scrThread* m_script_thread; // 0x828
	//	bool m_is_script_thread_active; // 0x830

	//	static tlsContext* get()
	//	{
	//		return *reinterpret_cast<tlsContext**>(__readgsqword(0x58));
	//	}
	//};
	//class scrThread
	//{
	//public:
	//	virtual ~scrThread() = default;                                                                 // 0 (0x00)
	//	virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
	//	virtual eThreadState run() = 0;                                                                 // 2 (0x10)
	//	virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
	//	virtual void kill() = 0;                                                                        // 4 (0x20)
	//	/*static scrThread* get()
	//	{
	//		return (scrThread*)rage::tlsContext::get()->m_script_thread;
	//	}*/
	//public:
	//	scrThreadContext m_context;                 // 0x08
	//	void* m_stack;                              // 0xB0
	//	char m_padding[0x18];                       // 0xB8
	//	const char* m_exit_message;                 // 0xC8
	//	char m_name[0x40];                          // 0xD0
	//	scriptHandler* m_handler;                   // 0x110
	//	scriptHandlerNetComponent* m_net_component; // 0x118
	//};
	// 
	
	//class scrThread
	//{
	//public:
	//	virtual ~scrThread() = default;                                                                 // 0 (0x00)
	//	virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
	//	virtual eThreadState run() = 0;                                                                 // 2 (0x10)
	//	virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
	//	virtual void kill() = 0;                                                                        // 4 (0x20)

	//	/*inline static scrThread* get()
	//	{
	//		return rage::tlsContext::get()->m_script_thread;
	//	}*/
	//public:
	//	scrThreadContext m_context;                      // 0x08
	//	void* m_stack;                                   // 0xB0
	//	char m_padding[0x4];                             // 0xB8
	//	uint32_t m_arg_size;                             // 0xBC
	//	uint32_t m_arg_loc;                              // 0xC0
	//	char m_padding2[0x4];                            // 0xC4
	//	const char* m_exit_message;                      // 0xC8
	//	std::uint32_t m_name_hash;                       // 0xCC
	//	char m_name[0x40];                               // 0xD4
	//	scriptHandler* m_handler;                        // 0x114
	//	CGameScriptHandlerNetComponent* m_net_component; // 0x11C
	//	rage::joaat_t m_script_hash;                // 0x128
	//};

	//class scrThread
	//{
	//public:
	//	virtual ~scrThread() = default;                                                                 // 0 (0x00)
	//	virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
	//	virtual eThreadState run() = 0;                                                                 // 2 (0x10)
	//	virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
	//	virtual void kill() = 0;                                                                        // 4 (0x20)
	//
	//	static scrThread* get()
	//	{
	//		return rage::tlsContext::get()->m_script_thread;
	//	}
	//public:
	//	scrThreadContext m_context;                 // 0x08
	//	void* m_stack;                              // 0xB0
	//	char m_padding[0x4];                        // 0xB8
	//	uint32_t m_arg_size;                        // 0xBC
	//	uint32_t m_arg_loc;                         // 0xC0
	//	char m_padding2[0x4];                       // 0xC4
	//	const char* m_exit_message;                 // 0xC8
	//	char m_pad[0x4];							// 0xD0
	//	char m_name[0x40];                          // 0xD4
	//	scriptHandler* m_handler;                   // 0x114
	//	scriptHandlerNetComponent* m_net_component; // 0x11C
	//};
	//static_assert(sizeof(scrThread) == 0x120);
}
//class GtaThread : public rage::scrThread
//{
//public:
//	rage::joaat_t m_script_hash;                // 0x120
//	char m_padding3[0x14];                      // 0x124
//	std::int32_t m_instance_id;                 // 0x138
//	char m_padding4[0x04];                      // 0x13C
//	std::uint8_t m_flag1;                       // 0x140
//	bool m_safe_for_network_game;               // 0x141
//	char m_padding5[0x02];                      // 0x142
//	bool m_is_minigame_script;                  // 0x144
//	char m_padding6[0x02];                      // 0x145
//	bool m_can_be_paused;                       // 0x147
//	bool m_can_remove_blips_from_other_scripts; // 0x148
//	char m_padding7[0x0F];                      // 0x149
//};



class menu_settingsz
{
public:
	/*nlohmann::json default_options;
	nlohmann::json options;*/

	struct vehicle {
		bool pv_teleport_into = false;
	};
	vehicle vehicle{};
};
inline menu_settingsz* g2{};

class script_local
{
public:
	explicit script_local(scrThread* thread, std::size_t index);
	explicit script_local(PVOID stack, std::size_t index);

	script_local at(std::ptrdiff_t index);
	script_local at(std::ptrdiff_t index, std::size_t size);

	template <typename T>
	std::enable_if_t<std::is_pointer_v<T>, T> as()
	{
		return static_cast<T>(get());
	}

	template <typename T>
	std::enable_if_t<std::is_lvalue_reference_v<T>, T> as()
	{
		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
	}
private:
	void* get();
	std::size_t m_index;
	PVOID m_stack;
};

namespace misc
{
	extern void clear_bit(int* address, int pos);
	extern int clear_bit2(int address, int pos);
	/*{
		*address &= ~(1 << pos);
	}*/

	extern void clear_bits(int* address, int bits);
	/*{
		*address &= ~(bits);
	}*/

	extern bool has_bit_set(int* address, int pos);
	/*{
		return *address & 1 << pos;
	}*/

	extern bool has_bits_set(int* address, int bits);
	/*{
		return (*address & bits) == bits;
	}*/

	/*inline void set_bit(int* address, int pos)
	{
		*address |= 1 << pos;
	}*/


	extern int set_bit(int address, int pos);
	/*{
		return address |= 1 << pos;
	}*/

	extern void set_bits(int* address, int bits);
	/*{
		*address |= bits;
	}*/
}
namespace ReceiveChat
{
	extern __int64* ChatReceive(__int64 a1, __int64 a2, __int64 sender, const char* msg, bool is_team);
	extern __int64* SenderReceive(__int64 a1, __int64 a2, __int64 sender);

}
class ScriptLocal
{
public:
	explicit ScriptLocal(scrThread* thread, std::size_t index);
	explicit ScriptLocal(PVOID stack, std::size_t index);
	ScriptLocal Add(std::ptrdiff_t index);
	ScriptLocal Add(std::ptrdiff_t index, std::size_t size);
	template <typename T>
	std::enable_if_t<std::is_pointer_v<T>, T> As()
	{
		return static_cast<T>(get());
	}
	template <typename T>
	std::enable_if_t<std::is_lvalue_reference_v<T>, T> As()
	{
		return *static_cast<std::add_pointer_t><std::remove_reference_t<T>> > (get());
	}
private:
	void* get();
	std::size_t m_index;
	PVOID m_stack;
};


namespace rage_helper
{
	inline GtaThread* find_script_thread(rage::joaat_t hash)
	{
		/*for (auto thread : *g_GameVariables->script_threads)*/
		for (auto thread : *g_GameVariables->m_scriptThreads)
		{
			if (thread
				&& thread->m_context.m_thread_id
				&& thread->m_handler
				&& thread->m_script_hash == hash)
			{
				/*return (GtaThread*)thread;*/
				return thread;
			}
		}
		return nullptr;
	}
}

namespace OriginalPTR
{
	extern void* m_OriginalRainOverride;
	extern void* m_OriginalTimecycleOverride;
	extern void* RIDJOINPLAYER;
	extern void* m_OriginalWriteVehicleProximityMigrationDataNode;
	extern void* m_OriginalNetworkInfo;
	extern void* CrashPTR;
}


class script
{
	public:
		static script* get_current();
		static void tick2();
		void tick();
		void* m_main_fiber;
		void* m_script_fiber;
		void yield(std::optional<std::chrono::high_resolution_clock::duration> time = std::nullopt);
};
static void KickByRID(uint64_t rid)
{
	/*g_FiberScript->addTask([=]()
		{*/


	rage::rlGamerHandle player_handle(rid);
	rage::rlScHandle socialclub_handle(rid);
	WAIT(1000);
	rage::rlSessionByGamerTaskResult get_session_result;
	bool get_session_success = false;
	rage::rlTaskStatus get_session_state{};

	rage::snConnectToPeerTaskData connect_to_peer_data{};
	rage::snConnectToPeerTaskResult connect_to_peer_result{};
	rage::rlTaskStatus connect_to_peer_status{};

	rage::rlQueryPresenceAttributesContext query_presence_attributes_context{};
	rage::rlTaskStatus query_presence_attributes_status{};
	rage::rlGamerInfoBase peer_address{};

	query_presence_attributes_context.m_presence_attibute_type = 3; // string
	strcpy(query_presence_attributes_context.m_presence_attribute_key, "peeraddr");

	if (!g_GameVariables->m_StartGetPresenceAttributes(0, &socialclub_handle, &query_presence_attributes_context, 1, &query_presence_attributes_status))
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Cannot start the query presence attributes rline task");
		return;
	}

	while (query_presence_attributes_status.status == 1)
	{
		WAIT(4000);
		/*DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		ticks /= 1000;
		DWORD seconds = ticks % 60;
		int getTimer = seconds;
		if (getTimer % 4 == 0)
		{
		}*/
	}
	/*g_FiberScript->Wait(4000);*/

	if (query_presence_attributes_status.status != 3)
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Querying presence attributes failed");
		return;
	}

	g_GameVariables->m_DecodePeerInfo(&peer_address, query_presence_attributes_context.m_presence_attribute_value, nullptr);

	if (!g_GameVariables->m_StartGetSessionByGamerHandle(0, &player_handle, 1, &get_session_result, 1, &get_session_success, &get_session_state))
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Cannot start the get session by gamer handle task");
		return;
	}

	while (get_session_state.status == 1)
	{
		WAIT(4000);
		/*DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		ticks /= 1000;
		DWORD seconds = ticks % 60;
		int getTimer = seconds;
		if (getTimer % 4 == 0)
		{
		}*/
	}
	/*g_FiberScript->Wait(4000);*/

	if (get_session_state.status != 3 || !get_session_success)
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Getting session info failed");
		return;
	}

	connect_to_peer_data.m_unk = 0;
	connect_to_peer_data.m_reason = 5;
	connect_to_peer_data.m_session_token = 0; // get_session_result.m_session_info.m_session_token; still works?

	if (!g_GameVariables->m_ConnectToPeer(GetNetwork()->m_game_session.m_net_connection_mgr, &peer_address, &connect_to_peer_data, &connect_to_peer_result, &connect_to_peer_status))
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Failed to start a connection with player");
		return;
	}

	//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Connecting to player...");
	while (connect_to_peer_status.status == 1)
	{
		WAIT(4000);
		/*DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		ticks /= 1000;
		DWORD seconds = ticks % 60;
		int getTimer = seconds;
		if (getTimer % 4 == 0)
		{
		}*/
	}
	/*g_FiberScript->Wait(4000);*/

	if (connect_to_peer_status.status != 3)
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Failed to connect to player, not attempting to send gamer instruction kick");
	}
	else
	{
		// you can send a MsgTransitionLaunchNotify with an invalid connection ID to crash the player instead (remove the session obtaining code above to make it work in SP)
		rage2::packet msg;
		msg.write_message(eNetMessage::MsgTransitionGamerInstruction);
		GamerHandleSerialize(player_handle, msg.m_buffer); // src
		GamerHandleSerialize(player_handle, msg.m_buffer); // target
		msg.write<bool>(false, 1); // string extend
		msg.write<int>(0, 7); // string length
		msg.write<int>(8, 32); // instruction type
		msg.write<int>(0, 32);
		msg.write<int>(0, 32);
		msg.send(connect_to_peer_result.m_peer_id, GetNetwork()->m_transition_session_ptr->m_connection_identifier);
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Sent gamer instruction kick");
	}

	memset(&connect_to_peer_result, 0, sizeof(connect_to_peer_result));
	connect_to_peer_status.status = 0;

	if (!g_GameVariables->m_ConnectToPeer(GetNetwork()->m_game_session.m_net_connection_mgr, &get_session_result.m_session_info.m_net_player_data, &connect_to_peer_data, &connect_to_peer_result, &connect_to_peer_status))
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Failed to start a connection with the host");
		return;
	}
	//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Connecting to host...");

	while (connect_to_peer_status.status == 1)
	{
		WAIT(4000);
		/*DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		ticks /= 1000;
		DWORD seconds = ticks % 60;
		int getTimer = seconds;
		if (getTimer % 4 == 0)
		{
		}*/
	}
	/*g_FiberScript->Wait(4000);*/

	if (connect_to_peer_status.status != 3)
	{
		//g_Logger->Info(ConsoleColor::RED, "RID Kick", "Failed to connect to the host");
		return;
	}

	rage2::packet msg{};
	msg.write_message(eNetMessage::MsgLostConnectionToHost);
	msg.write<uint64_t>(get_session_result.m_session_info.m_unk, 64);
	GamerHandleSerialize(player_handle, msg);
	msg.send(connect_to_peer_result.m_peer_id, GetNetwork()->m_game_session_ptr->m_connection_identifier);
	/*g_Logger->Info(ConsoleColor::RED, "RID Kick", "Sent lost connection kick");
		});*/
}

static void Ridkickplayer(int player)
{
	uint64_t value;
	std::istringstream iss((char*)m_function::GetPlayerRID(player).c_str());
	iss >> value;
	KickByRID(value);
}

static void crashbyrockstarid(uint64_t rid)
{
	WAIT(1000);
	rage::rlGamerHandle player_handle(rid);
	rage::rlScHandle socialclub_handle(rid);
	WAIT(1000);
	rage::snConnectToPeerTaskData connect_to_peer_data{};
	rage::snConnectToPeerTaskResult connect_to_peer_result{};
	rage::rlTaskStatus connect_to_peer_status{};

	rage::rlQueryPresenceAttributesContext query_presence_attributes_context{};
	rage::rlTaskStatus query_presence_attributes_status{};
	rage::rlGamerInfoBase peer_address{};

	query_presence_attributes_context.m_presence_attibute_type = 3; // string
	strcpy(query_presence_attributes_context.m_presence_attribute_key, "peeraddr");
	WAIT(1000);
	if (!g_GameVariables->m_StartGetPresenceAttributes(0, &socialclub_handle, &query_presence_attributes_context, 1, &query_presence_attributes_status))
	{
		//g_notification_service->push_error("RID Crash", "Cannot start the query presence attributes rline task");
		return;
	}

	while (query_presence_attributes_status.status == 1)
		/*script::get_current()->yield();*/
	{
		WAIT(4000);
	}

	if (query_presence_attributes_status.status != 3)
	{
		//g_notification_service->push_error("RID Crash", "Querying presence attributes failed");
		return;
	}

	connect_to_peer_data.m_unk = 0;
	connect_to_peer_data.m_reason = 5;
	connect_to_peer_data.m_session_token = 0;

	g_GameVariables->m_DecodePeerInfo(&peer_address, query_presence_attributes_context.m_presence_attribute_value, nullptr);
	if (!g_GameVariables->m_ConnectToPeer(GetNetwork()->m_game_session.m_net_connection_mgr, &peer_address, &connect_to_peer_data, &connect_to_peer_result, &connect_to_peer_status))
		//if (!g_GameVariables->m_ConnectToPeer(gta_util::get_network()->m_game_session.m_net_connection_mgr, &peer_address, &connect_to_peer_data, &connect_to_peer_result, &connect_to_peer_status))
	{
		//g_notification_service->push_error("RID Crash", "Failed to start a connection with player");
		return;
	}

	//g_notification_service->push("RID Crash", "Connecting to player...");

	while (connect_to_peer_status.status == 1)
		/*script::get_current()->yield();*/
	{
		WAIT(4000);
	}

	if (connect_to_peer_status.status != 3)
	{
		//g_notification_service->push_error("RID Crash", "Failed to connect to player");
		return;
	}

	rage2::packet msg;
	msg.write_message(eNetMessage::MsgTransitionLaunch);
	msg.send(connect_to_peer_result.m_peer_id, 7);
	//g_notification_service->push("RID Crash", "Sent transition launch crash");
}



//#include <WinBase.h>
//#include <winnt.h>
//#include <apisetcconv.h>
//#define DllExport   __declspec( dllexport )
//#define ExplotDll DllExport
////#define DECLSPEC_IMPORT2 __declspec(dllimport)
////#define WINBASEAPI2 DECLSPEC_IMPORT
////#define VOID2 void
////#define WINAPI2      __stdcall
//namespace winbase
//{
//	ExplotDll VOID WINAPI SwitchToFiber2(_In_ LPVOID lpFiber);
//	ExplotDll _Ret_maybenull_ LPVOID WINAPI ConvertThreadToFiber2(_In_opt_ LPVOID lpParameter);
//	ExplotDll _Ret_maybenull_ LPVOID WINAPI CreateFiber2(_In_ SIZE_T dwStackSize,_In_ LPFIBER_START_ROUTINE lpStartAddress, _In_opt_ LPVOID lpParameter);
//}
static void crashbyrockstarids(uint64_t rid)
{
	rage::rlGamerHandle player_handle(rid);
	rage::rlScHandle socialclub_handle(rid);
	WAIT(1000);
		rage::snConnectToPeerTaskData connect_to_peer_data{};
		rage::snConnectToPeerTaskResult connect_to_peer_result{};
		rage::rlTaskStatus connect_to_peer_status{};

		rage::rlQueryPresenceAttributesContext query_presence_attributes_context{};
		rage::rlTaskStatus query_presence_attributes_status{};
		rage::rlGamerInfoBase peer_address{};

		query_presence_attributes_context.m_presence_attibute_type = 3; // string
		strcpy(query_presence_attributes_context.m_presence_attribute_key, "peeraddr");
		WAIT(1000);
		if (!g_GameVariables->m_StartGetPresenceAttributes(0, &socialclub_handle, &query_presence_attributes_context, 1, &query_presence_attributes_status))
		{
			//g_notification_service->push_error("RID Crash", "Cannot start the query presence attributes rline task");
			return;
		}

		while (query_presence_attributes_status.status == 1)
			/*script::get_current()->yield();*/
		{
			/*simpletime2 simpltime;
			simpltime.start(4000);*/
				WAIT(4000);
		}

		if (query_presence_attributes_status.status != 3)
		{
			//g_notification_service->push_error("RID Crash", "Querying presence attributes failed");
			return;
		}

		connect_to_peer_data.m_unk = 0;
		connect_to_peer_data.m_reason = 5;
		connect_to_peer_data.m_session_token = 0;

		g_GameVariables->m_DecodePeerInfo(&peer_address, query_presence_attributes_context.m_presence_attribute_value, nullptr);
		if (!g_GameVariables->m_ConnectToPeer(GetNetwork()->m_game_session.m_net_connection_mgr, &peer_address, &connect_to_peer_data, &connect_to_peer_result, &connect_to_peer_status))
			//if (!g_GameVariables->m_ConnectToPeer(gta_util::get_network()->m_game_session.m_net_connection_mgr, &peer_address, &connect_to_peer_data, &connect_to_peer_result, &connect_to_peer_status))
		{
			//g_notification_service->push_error("RID Crash", "Failed to start a connection with player");
			return;
		}

		//g_notification_service->push("RID Crash", "Connecting to player...");

		while (connect_to_peer_status.status == 1)
			/*script::get_current()->yield();*/
		{
			/*simpletime2 simpltime;
			simpltime.start(4000);*/
				WAIT(4000);
		}

		if (connect_to_peer_status.status != 3)
		{
			//g_notification_service->push_error("RID Crash", "Failed to connect to player");
			return;
		}

		rage2::packet msg;
		msg.write_message(eNetMessage::MsgTransitionLaunch);
		msg.send(connect_to_peer_result.m_peer_id, 7);
	//}
	//g_notification_service->push("RID Crash", "Sent transition launch crash");
}

static void RidCrashplayer(int player)
{
	uint64_t value;
	std::istringstream iss((char*)m_function::GetPlayerRID(player).c_str());
	iss >> value;
	crashbyrockstarid(value);
}

static void ridcrash(std::string joinsessions)
{
	uint64_t value;
	std::istringstream iss((char*)joinsessions.c_str());
	iss >> value;
	crashbyrockstarid(value);
}

//void AddInfraction(CNetGamePlayer* player, std::string event, std::string protection_type, bool notify, bool temp_block)
//{
//	if (temp_block)
//		UserDB::SetBlock(player, protection_type);
//
//	std::stringstream log; log << event << "blocked from " << player->get_name();
//	std::stringstream notif; notif << "Event: " << event << "\nStatus: Blocked\nFrom: " << player->get_name();
//
//	if (notify)
//		Features::notify_custom(6, (char*)"Protection", const_cast<char*>(notif.str().c_str()));
//	g_Logger->Info(ConsoleColor::RED, "Protection", const_cast<char*>(log.str().c_str()));
//
//	if (g_Settings.m_ReactionAnounceChat)
//	{
//		std::stringstream log1; log1 << "Blocked " << event << " from -> " << player->get_name();
//		g_Settings.m_MessageToAnounceInChat = const_cast<char*>(log1.str().c_str());
//		g_Settings.m_AnounceInChat = true;
//	}
//
//	if (g_Settings.m_ReactionAddDatabase)
//		g_SpectralSaveDatabase.AutoAddToDatabase(player->get_name(), m_function::GetPlayerRID(player->m_player_id), m_function::GetPlayerIP(player->m_player_id), m_function::GetTime(), event);
//
//	if (g_Settings.m_ReactionKick)
//	{
//		if (notify)
//			Features::notify_custom(6, (char*)"Protection", "Trying to kick player...");
//		g_Logger->Info(ConsoleColor::RED, "Protection", "Trying to kick player...");
//		Kick::BreakupKick(player->m_player_id);
//	}
//}
//namespace rage2
//{
//class netGameEvent
//{
//public:
//	virtual ~netGameEvent() = default;
//
//	virtual const char* get_name() { return 0; };
//	virtual bool is_in_scope(netPlayer* player) { return 0; };
//	virtual bool time_to_resend(std::uint32_t time) { return 0; };
//	virtual bool can_change_scope() { return 0; };
//
//	virtual void prepare_data(datBitBuffer* buffer, netPlayer* source_player, netPlayer* target_player) {};
//	virtual void handle_data(datBitBuffer* buffer, netPlayer* source_player, netPlayer* target_player) {};
//
//	virtual bool decide(netPlayer* source_player, netPlayer* target_player) { return 0; };
//
//	virtual void prepare_reply(datBitBuffer* buffer, netPlayer* reply_player) {};
//	virtual void handle_reply(datBitBuffer* buffer, netPlayer* souce_player) {};
//
//	virtual void prepare_extra_data(datBitBuffer* buffer, bool is_reply, netPlayer* player, netPlayer* player2) {};
//	virtual void handle_extra_data(datBitBuffer* buffer, bool is_reply, netPlayer* player, netPlayer* player2) {};
//
//private:
//	virtual void unk_0x60() {};
//	virtual void unk_0x68() {};
//	virtual void unk_0x70() {};
//	virtual void unk_0x78() {};
//public:
//	virtual bool operator==(netGameEvent const& other) { return 0; };
//	virtual bool operator!=(netGameEvent const& other) { return 0; };
//
//	virtual bool must_persist() { return 0; };
//	virtual bool must_persist_when_out_of_scope() { return 0; };
//	virtual bool has_timed_out() { return 0; };
//public:
//	std::uint16_t m_id;          // 0x08
//	bool m_requires_reply;       // 0x0A
//private:
//	char m_padding1[0x05];       // 0x0B
//public:
//	netPlayer* m_source_player;  // 0x10
//	netPlayer* m_target_player;  // 0x18
//	std::uint32_t m_resend_time; // 0x20
//private:
//	std::uint16_t m_0x24;        // 0x24
//	std::uint8_t m_0x26;         // 0x26
//	std::uint8_t m_0x27;         // 0x27
//	std::uint32_t m_0x28;        // 0x28
//	char m_padding2[0x04];
//};
//}
//
//class CNetworkIncrementStatEvent : public rage2::netGameEvent
//{
//public:
//	Hash m_stat;    // 0x30
//	std::uint32_t m_amount; // 0x34
//};

#include "nlohmann/json.hpp"

class api_service
{
public:
	api_service();
	~api_service();

	// Returns true if an valid profile matching his username has been found
	bool get_rid_from_username(std::string_view username, uint64_t& result);

	// Returns true if an valid profile matching his rid has been found
	bool get_username_from_rid(uint64_t rid, std::string& result);

	// Returns true if the message has been successfully sended to the target 
	bool send_socialclub_message(uint64_t rid, std::string_view message);

	// Returns true if the job data query was successfully
	bool get_job_details(std::string_view job_link, nlohmann::json& result);

	// Returns true if the job metadata was successfully downloaded
	bool download_job_metadata(std::string_view content_id, int f1, int f0, int lang);
private:
	const std::vector<std::string> languages = { "unset", "en", "fr", "de", "it", "es", "pt", "pl", "ru", "es-mx" };

	inline std::string get_ticket()
	{
		return g_GameVariables->m_sc_info->m_ticket;
	}
};

inline api_service* g_api_service;

static bool get_rid_from_username(std::string_view username, uint64_t& result);
inline void join_by_username(std::string username)
{
	/*g_thread_pool->push([username]
		{*/
			uint64_t rid;
	if (g_api_service->get_rid_from_username(username, rid))
	{
		/*g_fiber_pool->queue_job([rid]
			{*/
				//join_by_rockstar_id(rid);
			//});
		return;
	}
	//g_notification_service->push_error("RID Joiner", "Target player is offline?");
		/*});*/
}

inline void kick_by_username(std::string username)
{
	/*g_thread_pool->push([username]
		{*/
			uint64_t rid;
	if (g_api_service->get_rid_from_username(username, rid))
	{
		/*g_fiber_pool->queue_job([rid]
			{*/
				//kick_by_rockstar_id(rid);
			/*});*/
		return;
	}
	//g_notification_service->push_error("RID Kick", "Target player is offline?");
		//});
}

enum class Infraction
{
	DESYNC_PROTECTION,
	BREAKUP_KICK_DETECTED,
	LOST_CONNECTION_KICK_DETECTED,
	SPOOFED_ROCKSTAR_ID,
	TRIGGERED_ANTICHEAT,
	TRIED_CRASH_PLAYER,
	TRIED_KICK_PLAYER,
	BLAME_EXPLOSION_DETECTED,
	ATTACKING_WITH_GODMODE
};
#include <unordered_set>
struct persistent_player
{
	std::string name;
	std::uint64_t rockstar_id = 0;
	bool block_join = false;
	int block_join_reason = 1;
	bool is_modder = false;
	std::unordered_set<int> infractions;
	std::optional<CommandAccessLevel> command_access_level = std::nullopt;
};

class player_database_service
{
	std::unordered_map<std::uint64_t, persistent_player> m_players;
	persistent_player* m_selected = nullptr;

public:
	std::filesystem::path m_file_path;
	player_database_service();
	~player_database_service();

	void save();
	void load();

	std::unordered_map<std::uint64_t, persistent_player>& get_players();
	persistent_player* get_player_by_rockstar_id(std::uint64_t rockstar_id);
	persistent_player* get_or_create_player(player::player_ptr player);
	void update_rockstar_id(std::uint64_t old, std::uint64_t _new);
	void remove_rockstar_id(std::uint64_t rockstar_id);

	void set_selected(persistent_player* selected);
	persistent_player* get_selected();
};

inline player_database_service* g_player_database_service;

//inline void add_infraction(player_ptr player, Infraction infraction)
//{
//	auto plyr = g_player_database_service->get_or_create_player(player);
//	if (!plyr->infractions.contains((int)infraction))
//	{
//		plyr->is_modder = true;
//		player->is_modder = true;
//		plyr->infractions.insert((int)infraction);
//		g_player_database_service->save();
//	}
//}


static void LostConnectionKick(int player)
{
	uint64_t value;
	std::istringstream iss((char*)m_function::GetPlayerRID(player).c_str());
	iss >> value;
	rage::rlGamerHandle player_handle(value);
	WAIT(1000);
	rage::rlSessionByGamerTaskResult get_session_result;
	rage::snConnectToPeerTaskResult connect_to_peer_result{};
	rage2::packet msg{};
	msg.write_message(eNetMessage::MsgLostConnectionToHost);
	//msg.write<uint64_t>(get_session_result.m_session_info.m_unk, 64);
	msg.write<uint64_t>(gta_util::get_network()->m_game_session_ptr->m_rline_session.m_session_id, 64);
	//msg.write<uint64_t>(GetNetwork()->m_game_session_ptr->m_rline_session.m_session_id, 64);
	//GamerHandleSerialize(player_handle, msg);
	gamer_handle_serialize(g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle, msg);

	for (auto& [_, plyr] : g_player_service->players())
	{
		if (plyr->is_host())
		{
			msg.send(plyr->get_session_player()->m_msg_id);
			break;
		}
	}

	/*WAIT(1000);

	msg.send(connect_to_peer_result.m_peer_id, GetNetwork()->m_game_session_ptr->m_connection_identifier);*/
	//GamerHandleSerialize((*(rage2::rlGamerHandle*)(&g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle_2.m_rockstar_id)), msg);
	/*for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
	{
		if (g_GameVariables->m_GetNetPlayer(i)->is_host())
		{
			msg.send(i, GetNetwork()->m_game_session_ptr->m_connection_identifier);
			break;
		}
	}*/
}
static void freemodeKick(int player)
{
	/*if (auto freemode = gta_util::find_script_thread(RAGE_JOAAT("freemode")))
	{*/
	//	rage2::packet msg{};
	//	msg.write_message(eNetMessage::MsgScriptMigrateHost);
	//	freemode->m_handler->get_id()->serialize(&msg.m_buffer);
	//	msg.write<int>(0, 16);
	//	msg.write<int>(0, 32);
	//	auto msg_id = g_GameVariables->m_GetNetPlayer(player)->m_msg_id;
	//	//auto msg_id = player->get_net_game_player()->m_msg_id;
	//	for (int j = 0; j < 2100; j++)
	//	{
	//		msg.send(msg_id);
	//	}
	//}

	if (auto freemode = gta_util::find_script_thread(RAGE_JOAAT("freemode")))
	{
		rage2::packet msg;
		msg.write_message(eNetMessage::MsgScriptMigrateHost);
		freemode->m_handler->get_id()->serialize(&msg.m_buffer);
		msg.write<int>(0, 16);
		msg.write<int>(0, 32);
		auto msg_id = g_GameVariables->m_GetNetPlayer(player)->m_msg_id;
		gamer_handle_serialize(g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle, msg);
		WAIT(1000);
		for (int j = 0; j < 2100; j++)
		{
			msg.send(msg_id);
		}
	}
}
//class networked2
//{
//public:
//	static GtaThread* findNetworked2(std::uint32_t hash)
//	{
//		for (auto thread : *g_GameVariables->m_script_threads)
//		{
//			if (!thread)
//			{
//				continue;
//			}
//			if (thread->m_context.m_state != eThreadState::running)
//			{
//				continue;
//			}
//			if (thread->m_context.m_script_hash != hash)
//			{
//				continue;
//			}
//			return (GtaThread*)thread;
//		}
//		return nullptr;
//	}
//};

//extern void waiting(DWORD time);

inline bool ForceHost(joaat_t hash)
{
	/*if (auto launcher = findscriptthread::findscriptthread2(hash); launcher && launcher->m_net_component)*/
	if (auto launcher = gta_util::find_script_thread(hash); launcher && launcher->m_net_component)
	{
		for (int i = 0; !launcher->m_net_component->is_local_player_host(); i++)
		{
			if (i > 200)
				return false;

			((CGameScriptHandlerNetComponent*)launcher->m_net_component)->send_host_migration_event(g_GameVariables->m_GetNetPlayer(PLAYER::PLAYER_ID()));
			/*g_FiberScript->addTask([] { g_FiberScript->Wait(10); });*/
			WAIT(100);
			if (!launcher->m_stack || !launcher->m_net_component)
				return false;
		}
	}

	return true;
}
