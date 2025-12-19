#pragma once
#include <span>

#include <concepts>
#include <stdexcept>
#include <type_traits>
#include <xkeycheck.h>

#include "stdafx.h"
#include "Hooking.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include "Memory.h"

#include <memory>
#include <stdexcept>



#include "reclass/GTAV-Classes/base/atRTTI.hpp"
#include "reclass/GTAV-Classes/base/CBaseModelInfo.hpp"
#include "reclass/GTAV-Classes/base/CNavigation.hpp"
#include "reclass/GTAV-Classes/base/CObject.hpp"
#include "reclass/GTAV-Classes/base/datBase.hpp"
#include "reclass/GTAV-Classes/base/fwArchetype.hpp"
#include "reclass/GTAV-Classes/base/fwArchetypeDef.hpp"
#include "reclass/GTAV-Classes/base/fwExtensibleBase.hpp"
#include "reclass/GTAV-Classes/base/fwExtension.hpp"
#include "reclass/GTAV-Classes/base/fwExtensionContainer.hpp"
#include "reclass/GTAV-Classes/base/fwRefAwareBase.hpp"
#include "reclass/GTAV-Classes/base/fwRefAwareBaseImpl.hpp"
#include "reclass/GTAV-Classes/base/HashTable.hpp"
#include "reclass/GTAV-Classes/base/pgBase.hpp"
#include "reclass/GTAV-Classes/base/phArchetype.hpp"
#include "reclass/GTAV-Classes/base/phBound.hpp"
#include "reclass/GTAV-Classes/base/phBoundCapsule.hpp"
#include "reclass/GTAV-Classes/base/phBoundComposite.hpp"
#include "reclass/GTAV-Classes/camera/CCameraAngles.hpp"
#include "reclass/GTAV-Classes/camera/CCameraManagerAngles.hpp"
#include "reclass/GTAV-Classes/camera/CGameCameraAngles.hpp"
#include "reclass/GTAV-Classes/draw_handlers/CEntityDrawHandler.hpp"
#include "reclass/GTAV-Classes/draw_handlers/CObjectDrawHandler.hpp"
#include "reclass/GTAV-Classes/draw_handlers/CPedDrawHandler.hpp"
#include "reclass/GTAV-Classes/draw_handlers/CVehicleDrawHandler.hpp"
#include "reclass/GTAV-Classes/draw_handlers/fwDrawData.hpp"
#include "reclass/GTAV-Classes/entities/CAttackers.hpp"
#include "reclass/GTAV-Classes/entities/CDynamicEntity.hpp"
#include "reclass/GTAV-Classes/entities/CEntity.hpp"
#include "reclass/GTAV-Classes/entities/CPhysical.hpp"
#include "reclass/GTAV-Classes/entities/fwEntity.hpp"
#include "reclass/GTAV-Classes/enums/eExplosionTag.hpp"
#include "reclass/GTAV-Classes/enums/eHandlingType.hpp"
#include "reclass/GTAV-Classes/misc/CTunables.hpp"
#include "reclass/GTAV-Classes/netsync/CProjectBaseSyncDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/CProjectSyncTree.hpp"
#include "reclass/GTAV-Classes/netsync/netSyncDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/netSyncNodeBase.hpp"
#include "reclass/GTAV-Classes/netsync/netSyncParentNode.hpp"
#include "reclass/GTAV-Classes/netsync/netSyncTree.hpp"
#include "reclass/GTAV-Classes/netsync/NodeCommonDataOperations.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/automobile/CAutomobileCreationNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/CPedComponents.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/door/CDoorCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/door/CDoorMovementDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/door/CDoorScriptGameStateDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/door/CDoorScriptInfoDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/dynamic_entity/CDynamicEntityGameStateDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/entity/CEntityOrientationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/entity/CEntityScriptGameStateDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/entity/CEntityScriptInfoDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/object/CObjectCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedAIDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedAppearanceDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedAttachDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedComponentReservationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedGameStateDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedHealthDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedInventoryDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedMovementDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedOrientationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedScriptCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/ped/CPedTaskSpecificDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/physical/CPhysicalAngVelocityDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/physical/CPhysicalAttachDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/physical/CPhysicalHealthDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/physical/CPhysicalMigrationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/physical/CPhysicalScriptMigrationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/physical/CPhysicalVelocityDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/pickup/CPickupCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/pickup_placement/CPickupPlacementCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/player/CPlayerAppearanceDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/player/CPlayerCameraDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/player/CPlayerCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/player/CPlayerGamerDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/player/CPlayerGameStateDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/player/CPlayerSectorPosNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/proximity_migrateable/CGlobalFlagsDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/proximity_migrateable/CMigrationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/proximity_migrateable/CSectorDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/proximity_migrateable/CSectorPositionDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/task/ClonedTakeOffPedVariationInfo.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/train/CTrainGameStateDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/vehicle/CVehicleCreationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/vehicle/CVehicleGadgetDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/nodes/vehicle/CVehicleProximityMigrationDataNode.hpp"
#include "reclass/GTAV-Classes/netsync/trees/CDynamicEntitySyncTreeBase.hpp"
#include "reclass/GTAV-Classes/netsync/trees/CEntitySyncTreeBase.hpp"
#include "reclass/GTAV-Classes/netsync/trees/CPhysicalSyncTreeBase.hpp"
#include "reclass/GTAV-Classes/netsync/trees/CProximityMigrateableSyncTreeBase.hpp"
#include "reclass/GTAV-Classes/network/CCommunications.hpp"
#include "reclass/GTAV-Classes/network/ChatData.hpp"
#include "reclass/GTAV-Classes/network/CJoinRequestContext.hpp"
#include "reclass/GTAV-Classes/network/ClanData.hpp"
#include "reclass/GTAV-Classes/network/CMsgJoinResponse.hpp"
#include "reclass/GTAV-Classes/network/CMsgTextMessage.hpp"
#include "reclass/GTAV-Classes/network/CNetComplaintMgr.hpp"
#include "reclass/GTAV-Classes/network/CNetGamePlayer.hpp"
#include "reclass/GTAV-Classes/network/CNetGamePlayerDataMsg.hpp"
#include "reclass/GTAV-Classes/network/CNetworkPlayerMgr.hpp"
#include "reclass/GTAV-Classes/network/netObject.hpp"
#include "reclass/GTAV-Classes/network/netPlayer.hpp"
#include "reclass/GTAV-Classes/network/netPlayerMgrBase.hpp"
#include "reclass/GTAV-Classes/network/netTime.hpp"
#include "reclass/GTAV-Classes/network/Network.hpp"
#include "reclass/GTAV-Classes/network/RemoteGamerInfoMsg.hpp"
#include "reclass/GTAV-Classes/network/snConnectToPeerTask.hpp"
#include "reclass/GTAV-Classes/network/snSession.hpp"
#include "reclass/GTAV-Classes/ped/CPed.hpp"
#include "reclass/GTAV-Classes/ped/CPedBoneInfo.hpp"
#include "reclass/GTAV-Classes/ped/CPedFactory.hpp"
#include "reclass/GTAV-Classes/ped/CPedIntelligence.hpp"
#include "reclass/GTAV-Classes/ped/CPedInventory.hpp"
#include "reclass/GTAV-Classes/ped/CPedModelInfo.hpp"
#include "reclass/GTAV-Classes/ped/CPedWeaponManager.hpp"
#include "reclass/GTAV-Classes/player/CNonPhysicalPlayerData.hpp"
#include "reclass/GTAV-Classes/player/CPlayerAngles.hpp"
#include "reclass/GTAV-Classes/player/CPlayerInfo.hpp"
#include "reclass/GTAV-Classes/rage/atArray.hpp"
#include "reclass/GTAV-Classes/rage/atSingleton.hpp"
#include "reclass/GTAV-Classes/rage/joaat.hpp"
#include "reclass/GTAV-Classes/rage/rlGamerHandle.hpp"
#include "reclass/GTAV-Classes/rage/rlGamerInfo.hpp"
#include "reclass/GTAV-Classes/rage/rlGamerInfoBase.hpp"
#include "reclass/GTAV-Classes/rage/rlMetric.hpp"
#include "reclass/GTAV-Classes/rage/rlQueryPresenceAttributesContext.hpp"
#include "reclass/GTAV-Classes/rage/rlScHandle.hpp"
#include "reclass/GTAV-Classes/rage/rlSessionByGamerTaskResult.hpp"
#include "reclass/GTAV-Classes/rage/rlSessionInfo.hpp"
#include "reclass/GTAV-Classes/rage/rlTaskStatus.hpp"
#include "reclass/GTAV-Classes/rage/sysMemAllocator.hpp"
#include "reclass/GTAV-Classes/rage/vector.hpp"
#include "reclass/GTAV-Classes/script/dataList.hpp"
#include "reclass/GTAV-Classes/script/globals/GlobalPlayerBD.hpp"
#include "reclass/GTAV-Classes/script/globals/GPBD_FM.hpp"
#include "reclass/GTAV-Classes/script/globals/GPBD_FM_3.hpp"
#include "reclass/GTAV-Classes/script/globals/GPBD_Kicking.hpp"
#include "reclass/GTAV-Classes/script/globals/GPBD_MissionName.hpp"
#include "reclass/GTAV-Classes/script/globals/GSBD.hpp"
#include "reclass/GTAV-Classes/script/globals/GSBD_BlockB.hpp"
#include "reclass/GTAV-Classes/script/globals/GSBD_FM.hpp"
#include "reclass/GTAV-Classes/script/globals/GSBD_Kicking.hpp"
#include "reclass/GTAV-Classes/script/globals/GSBD_PropertyInstances.hpp"
#include "reclass/GTAV-Classes/script/globals/g_AMC_playerBD.hpp"
#include "reclass/GTAV-Classes/script/CGameScriptObjInfo.hpp"
#include "reclass/GTAV-Classes/script/GtaThread.hpp"
#include "reclass/GTAV-Classes/script/HudColor.hpp"
#include "reclass/GTAV-Classes/script/MPScriptData.hpp"
#include "reclass/GTAV-Classes/script/scriptHandler.hpp"
#include "reclass/GTAV-Classes/script/scriptHandlerMgr.hpp"
#include "reclass/GTAV-Classes/script/scriptHandlerNetComponent.hpp"
#include "reclass/GTAV-Classes/script/scriptId.hpp"
#include "reclass/GTAV-Classes/script/scriptIdBase.hpp"
#include "reclass/GTAV-Classes/script/scriptResource.hpp"
#include "reclass/GTAV-Classes/script/scrNativeHandler.hpp"
#include "reclass/GTAV-Classes/script/scrNativeRegistration.hpp"
#include "reclass/GTAV-Classes/script/scrNativeRegistrationTable.hpp"
#include "reclass/GTAV-Classes/script/scrProgram.hpp"
#include "reclass/GTAV-Classes/script/scrProgramTable.hpp"
#include "reclass/GTAV-Classes/script/scrProgramTableEntry.hpp"
#include "reclass/GTAV-Classes/script/scrThread.hpp"
#include "reclass/GTAV-Classes/script/scrThreadContext.hpp"
#include "reclass/GTAV-Classes/script/scrVector.hpp"
#include "reclass/GTAV-Classes/script/Timer.hpp"
#include "reclass/GTAV-Classes/script/tlsContext.hpp"
#include "reclass/GTAV-Classes/script/types.hpp"
#include "reclass/GTAV-Classes/security/ObfVar.hpp"
#include "reclass/GTAV-Classes/security/RageSecurity.hpp"
#include "reclass/GTAV-Classes/socialclub/FriendInfo.hpp"
#include "reclass/GTAV-Classes/socialclub/FriendRegistry.hpp"
#include "reclass/GTAV-Classes/socialclub/ScInfo.hpp"
#include "reclass/GTAV-Classes/stats/CPlayerCardStats.hpp"
#include "reclass/GTAV-Classes/stats/CStatsSerializationContext.hpp"
#include "reclass/GTAV-Classes/vehicle/CAdvancedData.hpp"
#include "reclass/GTAV-Classes/vehicle/CBaseSubHandlingData.hpp"
#include "reclass/GTAV-Classes/vehicle/CCarHandlingData.hpp"
#include "reclass/GTAV-Classes/vehicle/CHandlingData.hpp"
#include "reclass/GTAV-Classes/vehicle/CHandlingObject.hpp"
#include "reclass/GTAV-Classes/vehicle/CVehicle.hpp"
#include "reclass/GTAV-Classes/vehicle/CVehicleModelInfo.hpp"
#include "reclass/GTAV-Classes/weapon/CAmmoInfo.hpp"
#include "reclass/GTAV-Classes/weapon/CAmmoProjectileInfo.hpp"
#include "reclass/GTAV-Classes/weapon/CAmmoRocketInfo.hpp"
#include "reclass/GTAV-Classes/weapon/CAmmoThrownInfo.hpp"
#include "reclass/GTAV-Classes/weapon/CHomingRocketParams.hpp"
#include "reclass/GTAV-Classes/weapon/CItemInfo.hpp"
#include "reclass/GTAV-Classes/weapon/CWeaponBoneId.hpp"
#include "reclass/GTAV-Classes/weapon/CWeaponInfo.hpp"


// add your classes here

#pragma once
//Disable Warings
#pragma warning(disable : 4996)
//Window Includes
#include <Windows.h>
#include <vadefs.h>
#include <stack>
#include <winsdkver.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#include <sdkddkver.h>
#include <winternl.h>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <Psapi.h>
#include <timeapi.h>
#include <time.h>
#include <xstring>
#include <functional>
#include <cassert>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <type_traits>
#pragma comment(lib, "ws2_32.lib")

#include <cstdint>
#include <ctime>
#include <cstring>

#include <cstdint>


#include "pugixml.h"
//#include "reclass/netObject.hpp"

#include "ScreenPed.h"

class CMoveObjectPooledObject;
#include <cstdint>
//#include "../Functions.h"
#include "Log.h"
#include "enums.h"
#include <array>

#include <cstdint>

#include <random>
#include <cmath>
#include <iostream>
#include <cstring>

class GameDataHash
{
public:
	bool m_is_japanese_version;
	std::array<rage::Obf32, 16> m_data;
};


namespace rage
{
#define DEFINE_RAGE_RTTI(className)    private:\
								virtual void* _0x00() = 0;\
								virtual void* _0x08() = 0;\
								virtual uint32_t _0x10() = 0;\
								virtual className* _0x18(void*) = 0;\
								virtual bool _0x20(void*) = 0;\
								virtual bool _0x28(void**) = 0;\
								virtual void destructor() = 0;\
								public:
}

template <typename T>
class fwRefAwareBaseImpl : public T
{
private:
	void* m_ref; // 0x08
};

namespace rage
{
	class datBitBuffer;
	class netSyncDataNode;
}

namespace rage
{
	class netSyncData;
	class netObject;
}

class netSyncTree
{
public:
	virtual ~netSyncTree() = default;

	char pad_0008[8]; //0x0008
	rage::netSyncNodeBase* m_next_sync_node; //0x0010
	rage::netSyncNodeBase* m_last_sync_node; //0x0018
	uint32_t m_child_node_count; //0x0020
	uint32_t m_unk_array_count; //0x0024
	char pad_0028[8]; //0x0028
	rage::netSyncNodeBase* m_child_nodes[42]; //0x0030
	uint32_t m_child_node_max_count; //0x0180
	rage::netSyncNodeBase* m_unk_array[32]; //0x0188
	uint32_t m_unk_array_max_count; //0x0288
	char pad_0290[560]; //0x0290
}; //Size: 0x0030

class netSyncTreeNode
{
public:
	char pad_0000[192]; //0x0000
	uint32_t m_player_model; //0x00C0
	uint32_t m_ped_model; //0x00C4
	uint32_t m_vehicle_model; //0x00C8
	char pad_00CC[84]; //0x00CC
	uint32_t m_pickup_model; //0x0120
	char pad_0124[44]; //0x0124
	uint32_t m_object_model; //0x0150
	char pad_0154[692]; //0x0154
}; //Size: 0x0408

namespace rage
{
	template<typename T>
	union vector5
	{
		T data[3];
		struct { T x, y, z; };
	};

	typedef vector5<float> fvector5;
}

struct sjrm
{
	static bool serialize_join_request_message(RemoteGamerInfoMsg* info, void* data, int size, int* bits_serialized);
};

class hookingz
{
public:
	template<auto detour_function>
	static auto get_original()
	{
		return detourhookhelper::hook_to_detourhookhelper<detour_function>::m_detour_hook.get_original<decltype(detour_function)>();
	}
};
inline hookingz* g_hookz{};

class detour_hook
{
public:
	explicit detour_hook();
	/*explicit detour_hook(std::string name, void* detour);
	explicit detour_hook(std::string name, void* target, void* detour);*/
	explicit detour_hook(const std::string& name, void* detour);
	explicit detour_hook(const std::string& name, void* target, void* detour);
	~detour_hook() noexcept;

	detour_hook(detour_hook&& that) = delete;
	detour_hook& operator=(detour_hook&& that) = delete;
	detour_hook(detour_hook const&) = delete;
	detour_hook& operator=(detour_hook const&) = delete;

	void set_instance(const std::string& name, void* detour);
	void set_instance(const std::string& name, void* target, void* detour);

	void set_target_and_create_hook(void* target);

	void enable();
	void disable();

	template <typename T>
	T get_original()
	{
		return static_cast<T>(m_original);
	}

	void fix_hook_address();

private:
	void create_hook();

	std::string m_name;
	void* m_original{};
	void* m_target{};
	void* m_detour{};
};
class detourhookhelper
{
	friend hookingz;

	using ret_ptr_fn = std::function<void* ()>;

	ret_ptr_fn m_on_hooking_available = nullptr;

	detour_hook* m_detour_hook;

	void enablehookifhookingisalreadyrunning();

	template<auto detour_function>
	struct hook_to_detourhookhelper
	{
		static inline detour_hook m_detour_hook;
	};

public:
	template<auto detour_function>
	static void add(const std::string& name, void* target)
	{
		hook_to_detourhookhelper<detour_function>::m_detour_hook.set_instance(name, target, detour_function);

		detourhookhelper d{};
		d.m_detour_hook = &hook_to_detourhookhelper<detour_function>::m_detour_hook;

		d.enablehookifhookingisalreadyrunning();

		m_detourhookhelpers.push_back(d);
	}

	template<auto detour_function>
	static void* add_lazy(const std::string& name, detourhookhelper::ret_ptr_fn on_hooking_available)
	{
		hook_to_detourhookhelper<detour_function>::m_detour_hook.set_instance(name, detour_function);

		detourhookhelper d{};
		d.m_detour_hook = &hook_to_detourhookhelper<detour_function>::m_detour_hook;
		d.m_on_hooking_available = on_hooking_available;

		d.enablehookifhookingisalreadyrunning();

		m_detourhookhelpers.push_back(d);

		return nullptr;
	}

	~detourhookhelper();
	/*template<auto detour_function>
	static auto get_original()
	{
		return detourhookhelper::hook_to_detourhookhelper<detour_function>::m_detour_hook.get_original<decltype(detour_function)>();
	}*/

private:
	bool m_enabled{};
	static inline std::vector<detourhookhelper> m_detourhookhelpers;
};

class vmt_hook
{
public:
	explicit vmt_hook(void* obj, std::size_t num_funcs);
	~vmt_hook();

	vmt_hook(vmt_hook&& that) = delete;
	vmt_hook& operator=(vmt_hook&& that) = delete;
	vmt_hook(vmt_hook const&) = delete;
	vmt_hook& operator=(vmt_hook const&) = delete;

	void hook(std::size_t index, void* func);
	void unhook(std::size_t index);

	template <typename T>
	T get_original(std::size_t index);

	void enable();
	void disable();

	class detour_hook_helper
	{
		friend vmt_hook;

		using ret_ptr_fn = std::function<void* ()>;

		ret_ptr_fn m_on_hooking_available = nullptr;

		detour_hook* m_detour_hook = nullptr;

		~detour_hook_helper();

		void enable_hook_if_hooking_is_already_running();

		template <auto detour_function>
		struct hook_to_detour_hook_helper
		{
			static inline detour_hook* m_detour_hook;
		};

		template <auto detour_function>
		static detour_hook_helper* add_internal(detour_hook* dh)
		{
			auto d = new detour_hook_helper();
			d->m_detour_hook = dh;

			m_detour_hook_helpers.push_back(d);
			hook_to_detour_hook_helper<detour_function>::m_detour_hook = dh;

			return d;
		}

	public:
		template <auto detour_function>
		static void add(const std::string& name, void* target)
		{
			auto d = add_internal<detour_function>(new detour_hook(name, target, detour_function));

			d->enable_hook_if_hooking_is_already_running();
		}

		template <auto detour_function>
		static void* add_lazy(const std::string& name, detour_hook_helper::ret_ptr_fn on_hooking_available)
		{
			auto d = add_internal<detour_function>(new detour_hook(name, detour_function));
			d->m_on_hooking_available = on_hooking_available;

			d->enable_hook_if_hooking_is_already_running();

			return nullptr;
		}
	};

	template <auto detour_function>
	static auto get_original()
	{
		return detour_hook_helper::hook_to_detour_hook_helper<detour_function>::m_detour_hook->get_original<decltype(detour_function)>();
	}

private:
	/*minhook_keepalive m_minhook_keepalive;*/

	/*vmt_hook m_swapchain_hook;*/

	WNDPROC m_og_wndproc = nullptr;

	static inline std::vector<detour_hook_helper*> m_detour_hook_helpers;

	void*** m_object;
	std::size_t m_num_funcs;

	void** m_original_table;
	std::unique_ptr<void* []> m_new_table;
};
template<typename T>
inline T vmt_hook::get_original(std::size_t index)
{
	return static_cast<T>(m_original_table[index]);
}

//class Hookings
class Hookings
{
public:
	/*explicit Hookings();
	~Hookings() noexcept;*/
	Hookings(Hookings const&) = delete;
	Hookings(Hookings&&) = delete;
	Hookings& operator=(Hookings const&) = delete;
	Hookings& operator=(Hookings&&) = delete;
	//	void enable();
	//	void disable();
	//
	static std::string m_Name;
	static std::string IDSpoof;
	static std::string IPSpoof;
	static std::string IPSpoofarray[];

	void Hook();
	void Unhook();

	friend struct Hooks;
	bool m_enabled{};
private:
	void* m_OriginalScriptVM{};
};


inline std::unique_ptr<Hookings> g_hooking2;

class rlPresenceEventInviteAccepted
{
public:
	void* m_vft;
	rlPresenceEventInviteAccepted* m_self;
	rage::rlGamerInfo m_local_data;
	rage::rlSessionInfo m_session_info;
	rage::rlGamerHandle m_some_handle;

	rlPresenceEventInviteAccepted(rage::rlGamerInfo& local_player_data, rage::rlSessionInfo& session_info, rage::rlGamerHandle& handle) :
		m_local_data(local_player_data),
		m_session_info(session_info),
		m_some_handle(handle)
	{
		m_self = this;
	}
};

class CPed;

extern rage::fmatrix44 m_transformation_matrix2;
extern void model_to_world2(const rage::fvector3& model_coords, rage::fvector3& world_coords);

template <typename T>
class atArray
{
public:
	atArray() :
		m_data(nullptr),
		m_size(0),
		m_count(0)
	{

	}

	atArray(void* data_ptr, std::uint16_t size, std::uint16_t count) :
		m_data(data_ptr),
		m_size(size),
		m_count(count)
	{

	}

	T* begin() const
	{
		return &m_data[0];
	}

	T* end() const
	{
		return &m_data[m_size];
	}

	T* data() const
	{
		return m_data;
	}

	std::uint16_t size() const
	{
		return m_size;
	}

	std::uint16_t count() const
	{
		return m_count;
	}

	T& operator[](std::uint16_t index) const
	{
		return m_data[index];
	}

	friend std::ostream& operator<<(std::ostream& o, const atArray<T>& j)
	{
		o << "Array Size: " << j.size() << std::endl;
		for (int i = 0; i < j.size(); i++)
		{
			T item = j[i];
			if (std::is_pointer<T>())
				o << "\tArray Pointer: " << std::hex << std::uppercase << item << std::nouppercase << std::dec << " Item: [" << std::hex << std::uppercase << (*(T*)item) << std::nouppercase << std::dec << "]";
			else
				o << "\tArray Item: " << item;
			if (i != j.size() - 1)
				o << std::endl;
		}
		return o;
	}

private:
	T* m_data;
	std::uint16_t m_size;
	std::uint16_t m_count;
};
class CPedOxygenInfo
{
public:
	char pad_0000[632]; //0x0000
	float m_oxygen_time; //0x0278
}; //Size: 0x027C

class BusinessMoney
{
public:
	char pad_0000[0x128];
	int32_t total_money;//0x0128
};


struct Vector02
{
	float x{};
	float y{};
};

namespace menu::screen::ped {
	/*void draw_on_screen_ped(CPed* ped, Vector02 pos, Vector02 scale, Vectorz position_offset = { 0.00f, -2.00f, 0.40f });*/
	void draw_on_screen_ped(CPed* ped, Vector02 pos, Vector02 scale, Vectorz position_offset = { 0.00f, -2.00f, 0.40f });
}

//=================
// PED FUNCTIONS
//=================

extern int Levels[8000];

//bools
//void inner_force(bool toggle);

Ped ClonePed(Ped ped);
Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle);

void SetStatMax(char* hashname, int value);

void SetStat(char* hashname, int value);

//Animations
void LoadAnim(char* dict);
void playAnimation(Ped ped, bool loop, char* dict, char* anim);
//SKINS
bool applyChosenSkin(std::string skinName);

//CONTROL
void RequestControlOfEnt(Entity entity);
void RequestNetworked(Vehicle veh);

//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z);

////GOD MODE
//void GodMode(bool toggle);

void RestrictedArea(Player Ped);

//CALM PEDS
void set_all_nearby_peds_to_calm();

//NEARBY PEDS
std::set<Ped> getNearbyPeds();
void update_nearby_peds(Ped playerPed, int count);

//VEHICLE
bool get_vehicle_keyboard_result(uint* outModel);

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str);

//Converts Radians to Degrees
float degToRad(float degs);

//quick function to get-coords-of-entity:
Vector3 coordsOf(Entity entity);

//quick function to get distance between 2 points:
float distanceBetween(Vector3 A, Vector3 B);

//quick "get random int in range 0-x" function:
int rndInt(int start, int end);

//TELEPORTATION
Vector3 get_blip_marker();
namespace TELEPORT {
	void teleport_to_marker();
	void teleport_to_objective();
	void teleport_to_marker(Player player);
	void teleport_to_objective(Player player);
}
void teleport_to_coords(Entity e, Vector3 coords);

//KEYBOARD
std::string show_keyboard(char* title_id, char* prepopulated_text);

//VECTOR/FLOAT
Vector3 rot_to_direction(Vector3* rot);
Vector3 add(Vector3* vectorA, Vector3* vectorB);
Vector3 multiply(Vector3* vector, float x);
float get_distance(Vector3* pointA, Vector3* pointB);
float get_vector_length(Vector3* vector);

//NOTIFICATION
void notifyBottom(char* fmt, ...);
void notifyBottom(std::string str);
void notifyMap(char* fmt, ...);
void notifyMap(std::string str);
void protectionNotify(char* fmt, ...);
void protectionNotify(std::string str);
void notifyCenter(char* fmt, ...);
void notifyCenter(std::string str);
void update_status_text();

//DRAWING FUNCTIONS
void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7);
void draw_menu_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);

Object SpawnObject(char* name, Vector3 coords);

void AttachThingToThing(Any p0, Any p1, float x, float y, float z, float rx, float ry, float rz);

//namespace

namespace Vehiclee {
	void Walldrive();
	void NativeHandler();
	void ScriptEngine();
}
//void makelogin();
void disclaimer();
//void kicknigga();
//void kickPlayerNonHost(int player);
void thundermenu();
//void backgroundcustom();
void discord();
void newInjector();
void CopOutfit2(int player);
void CopyOutfit(Player player);
void JoinCrew2(Player player);
//void hostKickLoop();

void EXTRASUNNY();

void CLEAR();

void CLOUDS();

void SMOG();

void FOGGY();

void OVERCAST();

void RAIN();

void THUNDER();

void CLEARING();

void NEUTRAL();

void SNOW();

void BLIZZARD();

void SNOWLIGHT();

void XMAS();

void HALLOWEEN();

void BLACKOUT();

void stressthem();
void makeusersfolder();
void makeusersfolderLogin();
void makeusersfolderThunder();
void makeoutfitfolder();
void maketeleportfolder();
void makeyoutubefolder();
void makeoverseefolder();
void makeaddPlayerfolder();

namespace functions {
	std::wstring s2ws(const std::string& s);
}


namespace Github
{
	extern void ThunderMenufolder();
	extern int Thunderytd();
	extern int Thor();
	extern int Thor1();
	extern int Thor2();
	extern int Thor21();
	extern int Thor22();
	extern int Thor3();
	extern int Thor4();
	extern int Thor20();
	extern int Thor23();
	extern int Thor24();

	extern int darkside1();
	extern int darkside2();
	extern int darkside3();
	extern int darkside4();
	extern int darkside5();
	extern int darkside6();
	extern int darkside7();
	extern int darkside8();
	extern int darkside9();
	extern int darkside10();
	extern int darkside11();
	extern int darkside12();
	extern int darkside13();
	extern int darkside14();
	extern int darkside15();
	extern int darkside16();
	extern int darkside17();
	extern int darkside18();
	extern int darkside19();
	extern int darkside20();
	extern int darkside21();
	extern int darkside22();
	extern int downloading();






	extern int Blackhole1();
	extern int Blackhole2();
	extern int Blackhole3();
	extern int Blackhole4();
	extern int Blackhole5();
	extern int Blackhole6();
	extern int Blackhole7();
	extern int Blackhole8();
	extern int Blackhole9();
	extern int Blackhole10();
	extern int Blackhole11();
	extern int Blackhole12();
	extern int Blackhole13();
	extern int Blackhole14();
	extern int Blackhole15();
	extern int Blackhole16();
	extern int Blackhole17();
	extern int Blackhole18();
	extern int Blackhole19();
	extern int Blackhole20();
	extern int Blackhole21();
	extern int Blackhole22();
	extern int Blackhole23();
	extern int Blackhole24();
	extern int Blackhole25();
	extern int Blackhole26();
	extern int Blackhole27();
	extern int Blackhole272();
	extern int Blackhole28();
	extern int Blackhole29();
	extern int Blackhole30();
	extern int Blackhole31();
	extern int Blackhole32();
	extern int Blackhole33();
	extern int Blackhole333();
	extern int Blackhole34();
	extern int Blackhole35();
	extern int Blackhole36();
	extern int Blackhole37();
	extern int Blackhole38();
	extern int Blackhole39();
	extern int Blackhole40();
	extern int Blackhole41();
	extern int Blackhole42();
	extern int Blackhole43();
	extern int Blackhole44();
	extern int Blackhole45();
	extern int Blackhole46();
	extern int Blackhole47();
	extern int Blackhole48();
	extern int Blackhole49();
	extern int Blackhole50();
	extern int Blackhole51();
	extern int Blackhole52();
	extern int Blackhole53();
	extern int Blackhole54();
	extern int Blackhole55();
	extern int Blackhole56();
	extern int Blackhole57();
	extern int Blackhole58();
	extern int Blackhole59();
	extern int Blackhole60();
	extern int Blackhole61();
	extern int Blackhole62();
	extern int Blackhole63();
	extern int Blackhole64();
	extern int Blackhole65();
	extern int Blackhole66();
	extern int Blackhole67();
	extern int Blackhole68();
	extern int Blackhole69();
	extern int Blackhole70();
	extern int Blackhole71();
	extern int Blackhole72();
	extern int Blackhole73();
	extern int Blackhole74();
	extern int Blackhole75();
	extern int Blackhole76();
}

namespace rage
{
#pragma warning(disable : 4324)

	using joaat_t = std::uint32_t;

	inline constexpr char joaat_to_lower(char c)
	{
		return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
	}

	template <std::size_t CharCount>
	struct constexpr_joaat
	{
		char data[CharCount];

		template <std::size_t... Indices>
		constexpr constexpr_joaat(const char* str, std::index_sequence<Indices...>) :
			data{ (str[Indices])... }
		{
		}

		constexpr joaat_t operator()()
		{
			joaat_t hash = 0;

			for (std::size_t i = 0; i < CharCount; ++i)
			{
				hash += joaat_to_lower(data[i]);
				hash += (hash << 10);
				hash ^= (hash >> 6);
			}

			hash += (hash << 3);
			hash ^= (hash >> 11);
			hash += (hash << 15);

			return hash;
		}
	};

	inline joaat_t joaat(std::string_view str)
	{
		joaat_t hash = 0;

		for (char c : str)
		{
			hash += joaat_to_lower(c);
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}

		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

		return hash;
	}

	inline joaat_t joaat(const char* str)
	{
		joaat_t hash = 0;

		while (*str)
		{
			hash += joaat_to_lower(*(str++));
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}

		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

		return hash;
	}

	/*class scrNativeRegistrationTable
	{
		scrNativeRegistration* m_entries[0xFF];
		std::uint32_t m_unk;
		bool m_initialized;
	};*/

}

#define RAGE_JOAAT_IMPL(str) (::rage::constexpr_joaat<sizeof(str) - 1>((str), std::make_index_sequence<sizeof(str) - 1>())())
#define RAGE_JOAAT(str) (std::integral_constant<rage::joaat_t, RAGE_JOAAT_IMPL(str)>::value) //CONSTEXPR_JOAAT

using joaat_t = std::uint32_t;

//class scrThread
//{
//public:
//	virtual ~scrThread() = default;                                                                 // 0 (0x00)
//	virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
//	virtual eThreadState run() = 0;                                                                 // 2 (0x10)
//	virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
//	virtual void kill() = 0;                                                                        // 4 (0x20)
//
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
//	//rage::joaat_t m_script_hash;                // 0x128
//};
class scrThread
{
public:
	virtual ~scrThread() = default;                                                                 // 0 (0x00)
	virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
	virtual eThreadState run() = 0;                                                                 // 2 (0x10)
	virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
	virtual void kill() = 0;

public:
	scrThreadContext m_context;                 // 0x08
	rage::scrValue* m_stack;                              // 0xB0
	char m_padding[0x4];                        // 0xB8
	uint32_t m_arg_size;                        // 0xBC
	uint32_t m_arg_loc;                         // 0xC0
	char m_padding2[0x4];                       // 0xC4
	const char* m_exit_message;                 // 0xC8
	char m_pad[0x4];
	char m_name[0x40];                          // 0xD4
	scriptHandler* m_handler;                   // 0x114
	CGameScriptHandlerNetComponent* m_net_component; // 0x11C
};
class netLoggingInterface;

class scriptHandlerMgr
{
public:
	virtual ~scriptHandlerMgr() = default;

	// Initializes some scripting-related pools.
	virtual bool initialize() = 0;                                                          // 1 (0x08)

	// Called every tick.
	virtual void _0x10() = 0;                                                               // 2 (0x10)

	// Frees some scripting-related pools.
	virtual void shutdown() = 0;                                                            // 3 (0x18)

	virtual void _0x20() = 0;                                                               // 4 (0x20)
	virtual void _0x28() = 0;                                                               // 5 (0x28)
	virtual void _0x30() = 0;                                                               // 6 (0x30)

	// Generates a rage::scriptId from the thread and copies it over to a global structure.
	virtual void _0x38(scrThread*) = 0;                                                     // 7 (0x38)

	// Allocates and constructs a script handler.
	virtual scriptHandler* create_script_handler() = 0;                                     // 8 (0x40)

	// Finds the script handler for a given script id.
	virtual scriptHandler* get_script_handler(scriptId*) = 0;                               // 9 (0x48)

	// Attaches a script thread.
	virtual void attach_thread(scrThread*) = 0;                                             // 10 (0x50)

	// Detaches a script thread.
	virtual void detach_thread(scrThread*) = 0;                                             // 11 (0x58)

	// Called when a player joins.
	virtual void on_player_join(rage::netPlayer*) = 0;                                            // 12 (0x60)

	// Called when a player leaves.
	virtual void on_player_left(rage::netPlayer*) = 0;                                            // 13 (0x68)

	virtual std::int32_t _0x70() = 0;                                                       // 14 (0x70)
	virtual void* _0x78() = 0;                                                              // 15 (0x78)
public:
	char pad_0008[104];
	//char m_padding1[0x28];                         // 0x08
	//bool m_initialized;                            // 0x30
	//bool m_initialized2;                           // 0x31
	//char m_padding2[0x0E];                         // 0x32
	//netLoggingInterface* m_logger;           // 0x40
};

class GtaThread : public scrThread
{
public:
	rage::joaat_t m_script_hash;                // 0x128
	char m_padding3[0x14];                      // 0x12C
	std::int32_t m_instance_id;                 // 0x140
	char m_padding4[0x04];                      // 0x144
	std::uint8_t m_flag1;                       // 0x148
	bool m_safe_for_network_game;               // 0x149
	char m_padding5[0x02];                      // 0x14A
	bool m_is_minigame_script;                  // 0x14C
	char m_padding6[0x02];                      // 0x14D
	bool m_can_be_paused;                       // 0x14F
	bool m_can_remove_blips_from_other_scripts; // 0x150
	char m_padding7[0x0F];                      // 0x151
};
//class GtaThread : public scrThread
//{
//public:
//	rage::joaat_t m_script_hash;                // 0x128
//	int m_force_cleanup_ip;                     // 0x12C
//	int m_force_cleanup_fp;                     // 0x130
//	int m_force_cleanup_sp;                     // 0x134
//	int m_force_cleanup_filter;                 // 0x138
//	int m_force_cleanup_cause;                  // 0x13C
//	std::int32_t m_instance_id;                 // 0x140
//	char m_padding4[0x04];                      // 0x144
//	std::uint8_t m_flag1;                       // 0x148
//	bool m_safe_for_network_game;               // 0x149
//	char m_padding5[0x02];                      // 0x14A
//	bool m_is_minigame_script;                  // 0x14C
//	char m_padding6[0x02];                      // 0x14D
//	bool m_can_be_paused;                       // 0x14F
//	bool m_can_remove_blips_from_other_scripts; // 0x150
//	char m_padding7[0x2];                       // 0x151
//	std::uint8_t m_force_cleanup_state;         // 0x153
//	char m_padding8[0xC];                       // 0x154
//};
template<typename T> class pgCollection
{
private:
	T* m_pData;
	UINT16		m_pCount;
	UINT16		m_pSize;

public:
	T* begin()
	{
		return m_pData;
	}

	T* end()
	{
		return (m_pData + m_pCount);
	}

	T* at(UINT16 index)
	{
		return &m_pData[index];
	}
};

template<typename T> class pgPtrCollection
{
private:
	T** m_pData;
	UINT16		m_pCount;
	UINT16		m_pSize;

public:
	T** begin()
	{
		return m_pData;
	}

	T** end()
	{
		return (m_pData + m_pCount);
	}

	T* at(UINT16 index)
	{
		return m_pData[index];
	}

	UINT16 count()
	{
		return m_pCount;
	}

	void set(UINT16 index, T* ptr)
	{
		m_pData[index] = ptr;
	}
};

template <typename T>
class ObfVar
{
private:
	T m_unk1;
	T m_unk2;
	T m_unk3;
	T m_unk4;

public:
	T getData()
	{
		auto v105 = m_unk4;
		auto v28 = m_unk1 & v105;
		auto v94 = m_unk2 & ~v105;
		return v28 | v94;
	}

	operator T ()
	{
		return getData();
	}

#if _WIN32
	void setData(T val)
	{
		auto seed = time(nullptr);
		m_unk3 = seed;
		seed = time(nullptr);
		m_unk4 = seed;

		auto v48 = val & ~seed;
		m_unk1 = seed & val;
		m_unk2 = v48;
	}

	void operator =(T val)
	{
		setData(val);
	}
#endif
};

using Obf16 = ObfVar<unsigned short>;
using Obf32 = ObfVar<unsigned int>;

template<typename T>
union vector2
{
	T data[2];
	struct { T x, y; };
};

template<typename T>
union vector3
{
	T data[3];
	struct { T x, y, z; };
};

template<typename T>
union vector4
{
	T data[4];
	struct { T x, y, z, w; };
};

template<typename T>
union matrix34
{
	T data[3][4];
	struct { struct { T x, y, z, w; } rows[3]; };
};

template<typename T>
union matrix44
{
	T data[4][4];
	struct { struct { T x, y, z, w; } rows[4]; };
};

typedef vector2<float> fvector2;
typedef vector3<float> fvector3;
typedef vector4<float> fvector4;
typedef matrix34<float> fmatrix34;
typedef matrix44<float> fmatrix44;
class fwDrawData
{
public:
	std::uint64_t qword0;
	std::uint64_t qword8;
	char gap10[8];
	std::uint32_t dword18;
	std::uint32_t dword1C;
	std::uint64_t qword20;
	std::uint32_t dword28;
};
enum class eNetObjType
{
	NET_OBJ_TYPE_AUTOMOBILE,
	NET_OBJ_TYPE_BIKE,
	NET_OBJ_TYPE_BOAT,
	NET_OBJ_TYPE_DOOR,
	NET_OBJ_TYPE_HELI,
	NET_OBJ_TYPE_OBJECT,
	NET_OBJ_TYPE_PED,
	NET_OBJ_TYPE_PICKUP,
	NET_OBJ_TYPE_PICKUP_PLACEMENT,
	NET_OBJ_TYPE_PLANE,
	NET_OBJ_TYPE_SUBMARINE,
	NET_OBJ_TYPE_PLAYER,
	NET_OBJ_TYPE_TRAILER,
	NET_OBJ_TYPE_TRAIN
};
enum class eNetObjectFlags : std::uint16_t
{
	NET_OBJ_FLAGS_FROM_SCRIPT = 1 << 2,
	NET_OBJ_FLAGS_SCRIPTED = 1 << 6,
};

enum class eAckCode : std::uint32_t
{
	ACKCODE_SUCCESS,
	ACKCODE_FAIL,
	ACKCODE_WRONG_OWNER,
	ACKCODE_OUT_OF_SEQUENCE,
	ACKCODE_NO_OBJECT,
	ACKCODE_TOO_MANY_OBJECTS,
	ACKCODE_CANT_APPLY_DATA,
	ACKCODE_MATCH_NOT_STARTED,
	ACKCODE_NONE
};


class CPlayerGameStateDataNode2
{
public:
	char pad_0000[192]; //0x0000
	uint32_t m_player_state; //0x00C0
	bool m_controls_disabled_by_script; //0x00C4
	bool m_is_max_armor_and_health_default; //0x00C5
	bool unk_000C6; //0x00C6
	bool m_is_spectating; //0x00C7
	bool m_is_antagonistic_to_another_player; //0x00C8
	bool m_never_target; //0x00C9
	bool m_use_kinematic_physics; //0x00CA
	bool m_has_tutorial_data; //0x00CB
	bool m_pending_tutorial_change; //0x00CC
	bool unk_00CD; //0x00CD
	bool m_respawning; //0x00CE
	bool m_will_jack_any_player; //0x00CF
	bool m_will_jack_wanted_players; //0x00D0
	bool m_dont_drag_from_car; //0x00D1
	bool m_random_peds_flee; //0x00D2
	bool m_every_ped_back_away; //0x00D3
	bool m_has_microphone; //0x00D4
	bool m_is_invincible; //0x00D5
	bool unk_00D6; //0x00D6
	bool unk_00D7; //0x00D7
	bool m_seatbelt; //0x00D8
	bool unk_00D9; //0x00D9
	bool m_bullet_proof; //0x00DA
	bool m_fire_proof; //0x00DB
	bool m_explosion_proof; //0x00DC
	bool m_collision_proof; //0x00DD
	bool m_melee_proof; //0x00DE
	bool m_water_proof; //0x00DF
	bool m_steam_proof; //0x00E0
	bool unk_00E1; //0x00E1
	bool unk_00E2; //0x00E2
	bool unk_00E3; //0x00E3
	bool unk_00E4; //0x00E4
	bool unk_00E5; //0x00E5
	bool unk_00E6; //0x00E6
	bool unk_00E7; //0x00E7
	bool unk_00E8; //0x00E8
	bool unk_00E9; //0x00E9
	bool unk_00EA; //0x00EA
	bool unk_00EB; //0x00EB
	bool unk_00EC; //0x00EC
	bool unk_00ED; //0x00ED
	bool unk_00EE; //0x00EE
	bool unk_00EF; //0x00EF
	bool unk_00F0; //0x00F0
	bool unk_00F1; //0x00F1
	bool unk_00F2; //0x00F2
	bool unk_00F3; //0x00F3
	bool unk_00F4; //0x00F4
	bool unk_00F5; //0x00F5
	bool unk_00F6; //0x00F6
	bool unk_00F7; //0x00F7
	bool unk_00F8; //0x00F8
	bool unk_00F9; //0x00F9
	bool unk_00FA; //0x00FA
	bool unk_00FB; //0x00FB
	uint32_t unk_00FC; //0x00FC
	uint32_t m_mobile_ring_state; //0x0100
	int32_t m_player_team; //0x0104
	float m_air_drag_multiplier; //0x0108
	uint32_t m_max_health; //0x010C
	uint32_t m_max_armor; //0x0110
	uint32_t m_jack_speed; //0x0114
	uint16_t m_player_is_targetable_by_team; //0x0118
	uint32_t m_override_receive_chat; //0x011C
	uint32_t m_override_send_chat; //0x0120
	bool unk_0124; //0x0124
	bool unk_0125; //0x0125
	bool unk_0126; //0x0126
	bool unk_0127; //0x0127
	uint16_t m_spectating_net_id; //0x0128
	uint8_t m_antagonistic_to_player_id; //0x012C
	uint8_t m_tutorial_index; //0x012B
	uint8_t m_tutorial_instance_id; //0x012C
	char pad_012D[2]; //0x012D
	float m_microphone_volume; //0x0130
	uint32_t m_voice_channel; //0x0134
	bool m_is_overriding_voice_proximity; //0x0138
	char pad_0139[7]; //0x0139
	float m_voice_proximity_x; //0x0140
	float m_voice_proximity_y; //0x0144
	float m_voice_proximity_z; //0x0148
	float m_voice_proximity_radius_maybe; //0x014C
	uint32_t unk_0150; //0x0150
	uint32_t m_vehicle_weapon_index; //0x0154
	bool m_has_vehicle_weapon_index; //0x0158
	uint32_t m_decor_count; //0x015C
	uint32_t m_decor_type[3]; // 0x0160
	uint32_t m_decor_value[3]; // 0x016C
	uint32_t m_decor_name_hash[3]; // 0x0178
	bool m_friendly_fire_allowed; //0x0184
	bool unk_0185; //0x0185
	uint8_t m_current_garage_instance_index; //0x0186
	uint8_t m_current_property_id; //0x0187
	uint8_t unk_0188; //0x0188
	uint8_t unk_0189; //0x0189
	bool m_battle_aware; //0x018A
	bool m_vehicle_jump_down; //0x018B
	float m_weapon_defence_modifier; //0x018C
	float m_weapon_defence_modifier_2; //0x0190
	bool m_is_overriding_population_control_sphere; //0x0194
	char pad_0195[11]; //0x0195
	float m_population_control_sphere_x; //0x01A0
	float m_population_control_sphere_y; //0x01A4
	float m_population_control_sphere_z; //0x01A8
	uint16_t unk_01AC; //0x01AC
	uint16_t unk_01AE; //0x01AE
	uint16_t unk_01B0; //0x01B0
	bool pad_01B2; //0x01B2
	bool unk_01B3; //0x01B3
	bool m_no_collision; //0x01B4
	bool unk_01B5; //0x01B5
	bool unk_01B6; //0x01B6
	bool m_super_jump; //0x01B7
	bool unk_01B8; //0x01B8
	bool unk_01B9; //0x01B9
	uint16_t unk_01BA; //0x01BA
	uint32_t unk_01BC; //0x01BC
	float unk_01C0; //0x01C0
	float m_weapon_damage_modifier;  //0x01C4 Divisor: 0x3F800000
	float m_melee_weapon_damage_modifier;  //0x01C8 Divisor: 0x3F800000
	float unk_01CC; //0x01CC
	bool unk_01D0; //0x01D0
	char pad_01D1[15]; //0x01D1
	float unk_01E0; //0x01E0
	float unk_01E4; //0x01E4
	float unk_01E8; //0x01E8
	uint32_t unk_01EC; //0x01EC
	uint8_t unk_01F0; //0x01F0
	uint8_t unk_01F1; //0x01F1
	bool unk_01F2; //0x01F2
	uint8_t unk_01F3; //0x01F3
	bool unk_01F4; //0x01F4
	bool unk_01F5; //0x01F5
}; //Size: 0x01F8
class netEventMgr;

using give_pickup_rewards = void(*)(int players, uint32_t hash);


class byte_patch
{
public:
	virtual ~byte_patch();

	void apply() const;

	void restore() const;

	void remove() const;

	template <typename TAddr>
	static const std::unique_ptr<byte_patch>& make(TAddr address, std::remove_pointer_t<std::remove_reference_t<TAddr>> value)
	{
		return m_patches.emplace_back(
			std::unique_ptr<byte_patch>(new byte_patch(address, value)));
	}

	static void restore_all();

private:
	template <typename TAddr>
	byte_patch(TAddr address, std::remove_pointer_t<std::remove_reference_t<TAddr>> value)
		: m_address(address)
	{
		m_size = sizeof(std::remove_pointer_t<std::remove_reference_t<TAddr>>);
		m_original_bytes = std::make_unique<uint8_t[]>(m_size);
		m_value = std::make_unique<uint8_t[]>(m_size);

		memcpy(m_original_bytes.get(), m_address, m_size);
		memcpy(m_value.get(), &value, m_size);
	}

protected:
	static inline std::vector<std::unique_ptr<byte_patch>> m_patches;

private:
	void* m_address;
	std::unique_ptr<uint8_t[]> m_value;
	std::unique_ptr<uint8_t[]> m_original_bytes;
	std::size_t m_size;

	friend bool operator== (const std::unique_ptr<byte_patch>& a, const byte_patch* b);
};

class GameVariables
{
public:
	float m_RainRed = 255.f;
	float m_RainGreen = 255.f;
	float m_RainBlue = 255.f;
	float m_RainIntensity = 5.f;
	float m_RainMultiplier = 1.f;
	bool m_RainModification = 0;
	bool m_RainModification2 = 0;
	float m_RainGravity = -12.0f;
	float activatetraffic1 = 2.802596929E-44;
	float leftstreet = 0.004999999423;
	float rightstreet = 2.369427828E-38;
	float activatetraffic2 = 0.03999999911;
	float pedspeed = 0;
	float potatoe0 = 1.5f;
	float potatoe1 = 5.85451288E-39;
	float potatoe2 = 2.286919094E-41;
	float potatoe3 = 8.828180325E-44;
	float freezetraffic = 0;
	float m_Water = 0;
	int m_WaterLevel = 0;
	float m_WaterOpacity = 0;
	float m_iMinX;
	float m_iMinY;
	float m_iMaxX;
	float m_iMaxY;
	float disturb = 0;
	int red = 0;
	int green = 0;
	int blue = 0;
	int alpha = 0;
	float spec = 0;
	float zenith_red = 0;
	float zenith_green = 0;
	float zenith_blue = 0;
	float m_SkyAlpha = 0;
	float m_SkyBlue = 0;
	float m_SkyGreen = 0;
	float m_SkyRed = 0;
	float transition_red = 0;
	int modification = 7;
	float starintensity = 0;
	float moonred = 0;
	float moongreen = 0;
	float moonblue = 0;
	float moonalpha = 0;
	float sunred = 0.9849449992;
	float sungreen = 0.8096570969;
	float sunblue = 0.4731327295;
	float sunalpha = 0;
	float sunred2 = 0.9805356264;
	float sungreen2 = 0.6840549111;
	float sunblue2 = 0.2944725156;
	float sunalpha2 = 0;
	float sunfluidity = 0;
	float suncapacity = 0;
	float sunvalue = 0;
	int hoursTimes = 23;
	int minutesTimes = 59;
	int secondesTimes = 59;
	float sun_red = 0;
	float sun_green = 0;
	float sun_blue = 0;
	float sun_alpha = 0;
	float sun_red_a = 0;
	float sun_green_a = 0;
	float sun_blue_a = 0;
	float sun_alpha_a = 0;
	float star_red_p = 0;
	float star_green_p = 0;
	float star_blue_p = 0;
	float star_alpha_p = 0;
	float star_intensity_p = 0;
	float sky_red_p = 0;
	float sky_green_p = 0;
	float sky_blue_p = 0;
	float sky_alpha_p = 0;
	float sky_intensity_p = 0;
	float sky_red_p1 = 0;
	float sky_green_p1 = 0;
	float sky_blue_p1 = 0;
	float sky_alpha_p1 = 0;
	float sky_intensity_p1 = 0;
	float sky_red_p2 = 0;
	float sky_green_p2 = 0;
	float sky_blue_p2 = 0;
	float sky_alpha_p2 = 0;
	float sky_intensity_p2 = 0;
	float sky_red_p3 = 0;
	float sky_green_p3 = 0;
	float sky_blue_p3 = 0;
	float sky_alpha_p3 = 0;
	float sky_intensity_p3 = 0;
	float sky_red_pbw3 = 0;
	float sky_green_pbw3 = 0;
	float sky_blue_pbw3 = 0;
	float sky_alpha_pbw3 = 0;
	float sky_intensity_pbw3 = 0;
	float moon_red = 0;
	float moon_green = 0;
	float moon_blue = 0;
	float moon_alpha = 0;
	float star_intensity = 0;
	float sky_intensity_p4 = 0;
	float sky_intensity_p5 = 0;
	bool m_ChatSpammer;
	int m_ChatSpammerTimer = 30;
	char* m_ChatMessageInput = "https://Thunder-Menu.com";
	uint16_t m_tp_player_net_id;
	rage::fvector3 m_tp_position;
	const char* getplayerName;
	std::uint16_t m_tp_veh_net_id;
	bool m_JoinQueue;
	rage::rlSessionInfo m_SessionInfo;
	int m_SaveRIDJoinerTarget = 0;
	std::unordered_map<scrNativeHash, scrNativeHandler> m_HandlerCache;
	bool m_StarsModification = 0;
	float m_StarsIntensity = 0.0f;
	rage::fvector4 SunColor;
	bool ColorSun = 0;
	rage::fvector4 MoonColor;
	bool ColorMoon = 0;
	bool enable_custom_sky_color = 0;
	rage::fvector4 m_azimuth_east;
	rage::fvector4 m_azimuth_west;
	rage::fvector4 m_azimuth_transition;
	rage::fvector4 m_zenith;
	bool _intensity_mazimutheast = 0;
	float mazimutheast_intensity = 0;
	bool _intensitymazimuthwest = 0;
	float mazimuthwest_intensity = 0;
	bool _intensitymazimuthtransition = 0;
	float mazimuthtransition_intensity = 0;
	bool _positionmazimuthtransition = 0;
	float mazimuthtransition_position = 0;
	bool _intensitymzenith = 0;
	float mzenith_intensity = 0;
	bool _transitionmzenith = 0;
	rage::fvector4 mzenith_transition;
	bool _intensitymzenithtransition = 0;
	float mzenithtransition_intensity = 0;
	bool _positionmzenithtransition = 0;
	float mzenithtransition_position = 0;
	bool _blendmzenithtransitioneast = 0;
	float mzenithtransitioneast_blend = 0;
	bool _blendmzenithtransitionwest = 0;
	float mzenithtransitionwest_blend = 0;
	bool _startmzenithblend = 0;
	float mzenithblend_start = 0;
	bool _discmsun = 0;
	rage::fvector4 msun_disc;
	bool _sizemsundisc = 0;
	float msundisc_size = 0;
	bool _hdrmsun = 0;
	float msun_hdr = 0;
	bool _miephasemsun = 0;
	float msun_miephase = 0;
	bool _miescattermsun = 0;
	float msun_miescatter = 0;
	bool _intensitymultmsunmie = 0;
	float msunmie_intensitymult = 0;
	bool _strengthmcloudshadow = 0;
	float mcloudshadow_strength = 0;
	bool _multmclouddensity = 0;
	float mclouddensity_mult = 0;
	bool _biasmclouddensity = 0;
	float mclouddensity_bias = 0;
	bool _fadeoutmcloud = 0;
	float mcloud_fadeout = 0;
	bool _offsetmcloud = 0;
	float mcloud_offset = 0;
	bool _colormcloudoverall = 0;
	float mcloudoverall_color = 0;
	bool _hdrmcloud = 0;
	float mcloud_hdr = 0;
	bool _strengthmclouddither = 0;
	float mclouddither_strength = 0;
	bool _strengthmcloudedge = 0;
	float mcloudedge_strength = 0;
	bool _strengthmcloudoverall = 0;
	float mcloudoverall_strength = 0;
	bool _basemcloud = 0;
	rage::fvector4 mcloud_base;
	bool _mcloud = 0;
	rage::fvector4 mcloud_;
	bool _midmcloud = 0;
	rage::fvector4 mcloud_mid;
	bool _strengthmsmallclouddetail = 0;
	float msmallclouddetail_strength = 0;
	bool _multmsmallclouddensity = 0;
	float msmallclouddensity_mult = 0;
	bool _cloudmsmall = 0;
	rage::fvector4 msmall_cloud;
	bool _radiusmsuninfluence = 0;
	float msuninfluence_radius = 0;
	bool _intenmsunscatter = 0;
	float msunscatter_inten = 0;
	bool _radiusmmooninfluence = 0;
	float mmooninfluence_radius = 0;
	bool _intenmmoonscatter = 0;
	float mmoonscatter_inten = 0;
	bool _sizemmoondisc = 0;
	float mmoondisc_size = 0;
	bool _intensitymmoon = 0;
	float mmoon_intensity = 0;
};

inline GameVariables g_Settings;

namespace rage2
{
	template <typename T>
	class ObfVar
	{
	private:
		T m_unk1;
		T m_unk2;
		T m_unk3;
		T m_unk4;

	public:
		T getData()
		{
			auto v105 = m_unk4;
			auto v28 = m_unk1 & v105;
			auto v94 = m_unk2 & ~v105;
			return v28 | v94;
		}

		operator T ()
		{
			return getData();
		}

#if _WIN32
		void setData(T val)
		{
			auto seed = time(nullptr);
			m_unk3 = seed;
			seed = time(nullptr);
			m_unk4 = seed;

			auto v48 = val & ~seed;
			m_unk1 = seed & val;
			m_unk2 = v48;
		}

		void operator =(T val)
		{
			setData(val);
		}
#endif
	};

	using Obf16 = ObfVar<unsigned short>;
	using Obf32 = ObfVar<unsigned int>;
}


namespace rage2
{
	class rlMetric
	{
	public:
		virtual ~rlMetric() = default;

		virtual int _0x08() { return 0; }; // returns a constant integer

		virtual int _0x10() { return 0; }; // returns a constant integer

		virtual int _0x18() { return 0; };

		virtual const char* get_name() { return ""; };

		virtual bool serialize(void* serializer) { return false; };

		virtual int get_size() { return 0; };

		virtual joaat_t get_name_hash() { return 0; };
	};
};

class CNetRemoteComplaint2
{
public:
	uint64_t m_complainer_token; //0x0000
	uint64_t m_complainee_token; //0x0008
	uint32_t m_flags; //0x0010
	uint32_t m_time; //0x0014
}; //Size: 0x0018
//static_assert(sizeof(CNetRemoteComplaint) == 0x18);

class CNetComplaintMgr2
{
public:
	uint64_t m_host_token; //0x0000
	uint32_t m_host_peer_id; //0x0008
	char pad_000C[4]; //0x000C
	void* m_net_connection_mgr; //0x0010
	char pad_0018[64]; //0x0018
	uint64_t m_host_tokens_in_scope[64]; //0x0058
	uint32_t m_num_tokens_in_scope; //0x0258
	char pad_025C[4]; //0x025C
	class CNetRemoteComplaint2 m_remote_complaints[64]; //0x0260
	uint32_t m_num_remote_complaints; //0x0860
	char pad_0864[4]; //0x0864
	uint64_t m_host_tokens_complained[64]; //0x0868
	uint32_t m_num_tokens_complained; //0x0A68
	char pad_0A6C[520]; //0x0A6C
	uint32_t m_connection_identifier; //0x0C74
	uint32_t m_last_resend_time; //0x0C78
	char pad_0C7C[4]; //0x0C7C
	uint32_t m_time_to_resend; //0x0C80
	uint32_t m_flags; //0x0C84
	char pad_0C88[16]; //0x0C88

	inline bool has_local_complaint(uint64_t host_token)
	{
		for (std::uint32_t i = 0; i < m_num_tokens_complained; i++)
			if (m_host_tokens_complained[i] == host_token)
				return true;

		return false;
	}

	inline void raise_complaint(uint64_t host_token)
	{
		if (has_local_complaint(host_token))
			return;

		m_host_tokens_complained[m_num_tokens_complained++] = host_token;

		// big::g_pointers->m_raise_network_complaint(this, host_token);
	}

	inline void remove_complaint(uint64_t host_token)
	{
		if (!has_local_complaint(host_token))
			return;

		for (std::uint32_t i = 0; i < m_num_tokens_complained; i++)
			if (m_host_tokens_complained[i] == host_token)
				m_host_tokens_complained[i] = m_host_tokens_complained[m_num_tokens_complained - 1];

		m_num_tokens_complained--;
	}

}; //Size: 0x0C98
//static_assert(sizeof(CNetComplaintMgr) == 0xC98);


namespace rage2
{
	//#pragma pack(push, 8)
	template <typename T>
	class atArray
	{
	public:
		atArray() :
			m_data(nullptr),
			m_size(0),
			m_count(0)
		{

		}

		atArray(void* data_ptr, std::uint16_t size, std::uint16_t count) :
			m_data(data_ptr),
			m_size(size),
			m_count(count)
		{

		}

		T* begin() const
		{
			return &m_data[0];
		}

		T* end() const
		{
			return &m_data[m_size];
		}

		T* data() const
		{
			return m_data;
		}

		std::uint16_t size() const
		{
			return m_size;
		}

		std::uint16_t count() const
		{
			return m_count;
		}

		T& operator[](std::uint16_t index) const
		{
			return m_data[index];
		}

		friend std::ostream& operator<<(std::ostream& o, const atArray<T>& j)
		{
			o << "Array Size: " << j.size() << std::endl;
			for (int i = 0; i < j.size(); i++)
			{
				T item = j[i];
				if (std::is_pointer<T>())
					o << "\tArray Pointer: " << std::hex << std::uppercase << item << std::nouppercase << std::dec << " Item: [" << std::hex << std::uppercase << (*(T*)item) << std::nouppercase << std::dec << "]";
				else
					o << "\tArray Item: " << item;
				if (i != j.size() - 1)
					o << std::endl;
			}
			return o;
		}

	private:
		T* m_data;
		std::uint16_t m_size;
		std::uint16_t m_count;
	};
	//static_assert(sizeof(rage::atArray<std::uint32_t>) == 0x10, "rage::atArray is not properly sized");
//#pragma pack(pop)
}

namespace rage2
{
	template <typename T>
	/*class atArray;*/

	//class datBitBuffer;
	/*class sysMemAllocator;*/
		// Serializes the script id from the buffer.



	class scriptIdBase;
	//class scriptId;
	class scriptHandler;
	//class scriptHandlerNetComponent;
	class scriptHandlerObject;
	class scriptHandlerMgr;

	//class scrProgram;
	class scrProgramTable;

	/*class scrThreadContext;
	class scrThread;*/
	//class tlsContextz;

	class netLoggingInterface;
	class netLogStub;

	/*class netPlayer;
	class netPlayerMgr;*/

	//class netGameEvent;
	class netEventMgr;

	class netSyncTree;

	class netObject;
	class netObjectMgrBase;

	class scrNativeCallContext;
	//class scrNativeRegistration;
	//class scrNativeRegistrationTable;

	class fwRefAwareBase;
	class fwExtensibleBase;
	class fwArchetype;

	/*class fiDevice;
	class fiPackfile;*/

	class rlSessionInfo;
	//class rlSessionByGamerTaskResult;
}


#if _WIN32
#include <intrin.h>
#endif


namespace rage
{
	//class CPedFactory
	//{
	//public:
	//	virtual ~CPedFactory() = default;
	//	class CPed* m_local_ped; //0x0008
	//}; //Size: 0x0010

	//CUSTOM CLASS TO IMPROVE R* SHIT CLASS STRUCTURE
	class CEntityHandle {
	public:
		class fwEntity* m_entity_ptr; //0x0000
		int32_t m_handle; //0x0008
		char pad_000C[4]; //0x000C
	}; //Size: 0x0010
	//static_assert(sizeof(CEntityHandle) == 0x10, "CEntityHandle is not properly sized");

	class CObjectHandle
	{
	public:
		class CObject* m_object; //0x0000
		int32_t m_handle; //0x0008
		char pad_000C[4]; //0x000C
	}; //Size: 0x0010
	//static_assert(sizeof(CObjectHandle) == 0x10, "CObjectHandle is not properly sized");

	class CObjectList
	{
	public:
		class CEntityHandle m_objects[2300]; //0x0000
	}; //Size: 0x8FC0

	class CObjectInterface
	{
	public:
		char pad_0000[344]; //0x0000
		class CObjectList* m_object_list; //0x0158
		int32_t m_max_objects; //0x0160
		char pad_0164[4]; //0x0164
		int32_t m_cur_objects; //0x0168

		fwEntity* get_object(const int& index)
		{
			if (index < m_max_objects)
				return m_object_list->m_objects[index].m_entity_ptr;
			return nullptr;
		}
	}; //Size: 0x016C

	class CPedHandle
	{
	public:
		class CPed* m_ped; //0x0000
		int32_t m_handle; //0x0008
		char pad_000C[4]; //0x000C
	}; //Size: 0x0010
	//static_assert(sizeof(CPedHandle) == 0x10, "CPedHandle is not properly sized");

	class CPedList
	{
	public:
		//CHANGED FROM CPedHandle
		class CEntityHandle m_peds[256]; //0x0000 
	}; //Size: 0x1000

	class CPedInterface
	{
	public:
		char pad_0000[256]; //0x0000
		class CPedList* m_ped_list; //0x0100
		int32_t m_max_peds; //0x0108
		char pad_010C[4]; //0x010C
		int32_t m_cur_peds; //0x0110

		fwEntity* get_ped(const int& index)
		{
			if (index < m_max_peds)
				return m_ped_list->m_peds[index].m_entity_ptr;
			return nullptr;
		}
	}; //Size: 0x0114

	class CVehicleHandle
	{
	public:
		class CAutomobile* m_vehicle; //0x0000
		int32_t m_handle; //0x0008
		char pad_000C[4]; //0x000C
	}; //Size: 0x0010
	//static_assert(sizeof(CVehicleHandle) == 0x10, "CVehicleHandle is not properly sized");

	class CVehicleList
	{
	public:
		//CHANGED FROM CVehicleHandle
		class CEntityHandle m_vehicles[300]; //0x0000
	}; //Size: 0x12C0

	class CVehicleInterface
	{
	public:
		char pad_0000[384]; //0x0000
		class CVehicleList* m_vehicle_list; //0x0180
		int32_t m_max_vehicles; //0x0188
		char pad_018C[4]; //0x018C
		int32_t m_cur_vehicles; //0x0190

		fwEntity* get_vehicle(const int& index)
		{
			if (index < m_max_vehicles)
				return m_vehicle_list->m_vehicles[index].m_entity_ptr;
			return nullptr;
		}
	}; //Size: 0x0194


	class CReplayInterface
	{
	public:
		char pad_0000[16]; //0x0000
		class CVehicleInterface* m_vehicle_interface; //0x0010
		class CPedInterface* m_ped_interface; //0x0018
		char pad_0020[8]; //0x0020
		class CObjectInterface* m_object_interface; //0x0028
	}; //Size: 0x0030
}
//#pragma pack(pop)

class CNetworkBandwithManager {
public:
	char m_pad_0x0000[0x8]; //0x0000

}; //Size=0x0008
class CNetworkPlayerManager {
public:
	char m_pad_0x0000[0x10]; //0x0000
	CNetworkBandwithManager* m_bandwidthManager; //0x0010 
	char m_pad_0x0018[0xD0]; //0x0018
	CNetGamePlayer* m_localPlayer; //0x00E8 
	char m_pad_0x00F0[0x88]; //0x00F0
	uint8_t m_playersOnline; //0x0178 
	char m_pad_0x0179[0x7]; //0x0179
	CNetGamePlayer* m_players[0x20]; //0x0180 

}; //Size=0x0280
namespace BypassPatch
{
	extern void ModelSpawnBypass(bool toggle);
}

class GameVariables2
{
public:
	explicit GameVariables2();
	~GameVariables2() noexcept = default;
	GameVariables2(GameVariables2 const&) = delete;
	GameVariables2(GameVariables2&&) = delete;
	GameVariables2& operator=(GameVariables2 const&) = delete;
	GameVariables2& operator=(GameVariables2&&) = delete;
	float* m_FogModification;
	float* m_RainRed;
	float* m_RainGreen;
	float* m_RainBlue;
	/*float* m_RainIntensity;*/
	using RainIntensity = void(float intensity);
	RainIntensity* m_RainIntensity;
	float* m_RainMultiplier;
	float* m_RainGravity;
	char* m_zenith_patch;
	char* m_zenith_transition_patch;
	char* m_east_azimuth_patch;
	char* m_west_azimuth_patch;
	char* m_azimuth_transition_patch;
	char* m_cloud_base_patch;
	float* red_zenith;
	float* green_zenith;
	float* blue_zenith;
	float* red_transition;
	float* green_transition;
	float* blue_transition;
	float* red_cloud;
	float* green_cloud;
	float* blue_cloud;
	float* m_azimuth_west_red;
	float* m_azimuth_west_green;
	float* m_azimuth_west_blue;
	float* m_azimuth_est_red;
	float* m_azimuth_est_green;
	float* m_azimuth_est_blue;
	float* sun;
};
inline std::unique_ptr<GameVariables2> g_GameVariable2;

class netSyncDataUnit_Dynamic
{
public:
	virtual ~netSyncDataUnit_Dynamic() = default; // 0x00

	virtual void _0x08() = 0;

	virtual void _0x10() = 0;

	virtual void set_data_counter(int index, uint16_t counter) = 0; // 0x18

	virtual void reset_data_counter(int index) = 0; // 0x20

	// ...

	int m_players_need_ack;  // 0x08
	int m_players_need_sync; // 0x0C
};

class netSyncData_Dynamic
{
public:
	virtual ~netSyncData_Dynamic() = default; // 0x00

	virtual datBitBuffer* _0x08() = 0;

	virtual datBitBuffer* _0x10() = 0;

	virtual int get_num_receivers() = 0; // 0x18

	virtual int _0x20() = 0;

	virtual void _0x28() = 0; // same as get_sync_unit_for_element

	virtual netSyncDataUnit_Dynamic* get_sync_unit_for_element(uint32_t element) = 0; // 0x30

};

class netArrayHandlerBase
{
public:
	virtual ~netArrayHandlerBase() = default; // 0x00

	virtual void _0x08() = 0;

	virtual void _0x10() = 0;

	virtual void _0x18() = 0;

	virtual void _0x20() = 0;

	virtual void _0x28() = 0;

	virtual void _0x30() = 0;

	virtual void _0x38() = 0; //

	virtual void _0x40() = 0; //

	virtual int _0x48(CNetGamePlayer* player, int max_size, uint32_t* a3, uint32_t* a4) = 0; //

	virtual int get_size(CNetGamePlayer* player, int max_size, uint32_t element) = 0; // 0x50

	virtual int pack_array_data(CNetGamePlayer* player, rage::datBitBuffer* bit_buffer, uint16_t counter, uint32_t* elem_start, bool silent) = 0; // 0x58

	virtual void _0x60() = 0; //

	virtual bool _0x68(CNetGamePlayer* player) = 0; // is_player_out_of_scope or something like that

	virtual void _0x70() = 0; //

	virtual bool can_send_update(CNetGamePlayer* player) = 0; // 0x78

	virtual void _0x80() = 0; //

	virtual void _0x88(int) = 0; //

	virtual void* get_identifier() = 0; // 0x90

	virtual void* _0x98() = 0; // same as get_identifier

	virtual void _0xA0() = 0; //

	virtual bool can_verify_array_data() = 0; // 0xA8

	virtual void _0xB0() = 0; //

	virtual void _0xB8() = 0; //

	virtual void should_sync_element(uint32_t element) = 0; // 0xC0

	virtual void _0xC8() = 0; //

	virtual void _0xD0() = 0; //

	virtual bool are_all_elements_in_scope() = 0; // 0xD8

	virtual void _0xE0() = 0; //

	virtual void verify_array_data() = 0; // 0xE8

	virtual void verify_array_data_ack(CNetGamePlayer* player, int) = 0; //

	virtual char* get_name() = 0; // 0xF8

	virtual bool is_local_player_owner_of_array() = 0; // 0x100

	virtual CNetGamePlayer* get_owner_of_array() = 0; // 0x108

	virtual void _0x110() = 0;

	virtual uint32_t get_array_hash() = 0;

	virtual int _0x120() = 0; // gets array size for hashing

	virtual netSyncData_Dynamic* _0x128() = 0; // same as get_dynamic_sync_data

	virtual netSyncData_Dynamic* get_dynamic_sync_data() = 0; // 0x130

	virtual void _0x138() = 0;

	virtual bool is_element_in_scope(uint32_t element, CNetGamePlayer* player) = 0; // 0x140

	virtual int get_receiver_index_from_player(CNetGamePlayer*) = 0; // 0x148

	virtual void _0x150() = 0;

	virtual void _0x158() = 0;

	// pasted from fivem
	virtual bool is_element_empty(uint32_t element) = 0; // 0x160

	virtual void set_element_empty(uint32_t element) = 0; // 0x168

	virtual void write_element_index(rage::datBitBuffer& buffer, uint32_t) = 0; // 0x170

	virtual void read_element_index(rage::datBitBuffer& buffer, uint32_t&) = 0; // 0x178

	virtual bool is_valid_index(uint32_t) = 0; // 0x180

	virtual void recalculate_dirty_elements() = 0; // 0x188

	virtual void reset_element_sync_data(uint32_t element) = 0; // 0x190

	virtual void do_post_read_processing() = 0; // 0x198

	virtual void do_post_element_read_processing(uint32_t element) = 0; // 0x1A0

	virtual bool can_apply_element_data(uint32_t element, const rage::netPlayer& sender, bool force) = 0; // 0x1A8

	virtual void extract_data_for_serializing(uint32_t elem) = 0; // 0x1B0

	virtual void write_element(rage::datBitBuffer& buffer, uint32_t elem, void* logger) = 0; // 0x1B8

	virtual void read_element(rage::datBitBuffer& buffer, uint32_t elem, void* logger) = 0; // 0x1C0

	virtual void log_element(uint32_t elem, void* logger) = 0; // 0x1C8

	virtual uint32_t get_current_element_size_in_bits(uint32_t elem) = 0; // 0x1D0

	virtual void apply_element_data(uint32_t element, const rage::netPlayer& sender) = 0; // 0x1D8

	virtual void _0x1E0() = 0;

	virtual void _0x1E8(bool) = 0;

	void* m_something; // 0x10

	netArrayHandlerBase* m_next; // 0x18

	uint8_t m_pad[100 - 0x18]; // +8
	uint32_t m_hash;
	uint8_t m_pad2[244 - 104]; // +8
	uint16_t m_index;          // 244
	uint16_t m_count;          // 246
	uint8_t m_max_elements;    // 248
	uint8_t m_element_size;    // 249
	uint8_t m_element_size_2;  // 250
	uint8_t m_pad3[13];        // 251
	void* m_array;             // 264
	uint8_t m_pad4[341 - (264 + 8)];
	char m_flags; // 341
};

class GameVariables1
{
public:
	explicit GameVariables1();
	~GameVariables1() noexcept = default;
	GameVariables1(GameVariables1 const&) = delete;
	GameVariables1(GameVariables1&&) = delete;
	GameVariables1& operator=(GameVariables1 const&) = delete;
	GameVariables1& operator=(GameVariables1&&) = delete;
	void PostInit();

	std::uint32_t* m_GameState;
	std::uint32_t* m_FrameCount;
	HWND m_GameWindow;
	/*IDXGISwapChain* m_Swapchain;*/
	rage::scrNativeRegistration** m_NativeRegistrations;
	std::uint64_t** m_GlobalBase;
	CPedFactory** m_ped_factory/*{}*/;
	/*PVOID m_blame_explode;*/

	char* m_GameBuild;
	/*void RequestControlBypass(bool toggle);
	PUSHORT m_SpectatorCheck;*/
	//public:
	CNetworkPlayerMgr** m_NetworkPlayerMgr/*{}*/;
	//CNetworkPlayerMgr** m_NetworkPlayerMgr/*{}*/;
	/*GameVariables1::CNetGamePlayer* PlayerIndex;*/
	PVOID m_network_player_mgr_shutdown;
	/*GameVariables1::CNetGamePlayer* PlayerIndex;*/
	using convertHandleT = int32_t(*)(void* hndle);
	convertHandleT m_ConvertHandle;
	/*using GetNetPlayer = CNetGamePlayer*(std::int8_t PlayerIndex);
	GetNetPlayer* m_GetNetPlayer{};*/

	using Playerde = std::int32_t;
	//using GetNetPlayer = CNetGamePlayer*(Playerde player);
	//GetNetPlayer* m_GetNetPlayer/*{}*/;
	std::int64_t** m_script_globals/*{}*/;
	//__int64* m_ChatReceive/*{}*/;
	//using GetChatPlayerID = CNetGamePlayer*(__int64);
	//GetChatPlayerID* m_GetChatPlayerID{};
	//pgCollection<scrThread*>* script_threads;
	bool* is_session_started;
	/*using GetNetPlayer = CNetGamePlayer2*(std::int8_t PlayerIndex);*/
	using GetNetPlayer = CNetGamePlayer*(std::int8_t PlayerIndex);
	GetNetPlayer* m_GetNetPlayer;
	//using SendNetworkInfo = bool (*)(CNetGamePlayerDataMsg* player, int64_t a2, int64_t a3, DWORD* a4);//rage::netPlayerData	
	//using SendNetworkInfo = bool(*)(rage2::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4);//rage::netPlayerData
	using SendNetworkInfo = bool(*)(rage::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4);//rage::netPlayerData
	SendNetworkInfo* m_NetworkInfo;
	//bool* m_is_session_started{};
	give_pickup_rewards m_give_pickup_rewards/* = nullptr*/;
	PVOID m_ExplosionBypass;
	const char* m_game_version;
	const char* m_online_version;
	//functions2::get_net_object m_get_net_object{};
	//CNetworkPlayerMgr** m_NetworkPlayerMgr{};
	/*functions2::reset_network_complaints m_reset_network_complaints{};
	functions2::fidevice_get_device m_fidevice_get_device{};
	uintptr_t m_fidevices{};
	uint16_t* m_fidevices_len{};
	functions2::fipackfile_ctor m_fipackfile_ctor{};
	fiPackfile** m_fipackfile_instances{};
	functions2::fipackfile_open_archive m_fipackfile_open_archive{};
	functions2::fipackfile_mount m_fipackfile_mount{};
	functions2::fipackfile_unmount m_fipackfile_unmount{};*/
	byte_patch* m_blame_explode;
	Vector2* m_WaypointCoords;

	/*ScInfo* m_sc_info;*/
	uintptr_t ui_3d_draw_manager;
	uintptr_t add_element_to_scene;
	uintptr_t push_scene_preset_manager;
	uintptr_t set_scene_element_lighting;
	uintptr_t get_scene_preset;
	PVOID m_weather_data;
	float* activatetraffic1;
	float* leftstreet;
	float* rightstreet;
	float* activatetraffic2;
	float* pedspeed;
	float* potatoe0;
	float* potatoe1;
	float* potatoe2;
	float* potatoe3;
	float* freezetraffic;	
	PVOID shitter_crash;
	Network** m_Network;
	uint64_t m_networkPlayerManager;
	CNetworkPlayerManager* GetNetworkPlayerManager();
	FriendRegistry* m_friend_registry/*{}*/;
	//CNetworkPlayerMgr** m_network_player_mgr/*{}*/;
	//pgCollection<GtaThread*>* m_script_threads;
	pgCollection<GtaThread*>* m_scriptThreads;
	//rage2::atArray<GtaThread2*>* m_script_threads/*{}*/;
	/*rage2::scrProgramTable* m_script_program_table{};*/
	rage::scrProgramTable* m_ScriptProgramTable;

	//using run_script_threads = bool(std::uint32_t ops_to_execute);
	//run_script_threads* m_run_script_threads/*{}*/;
	/*using get_native_handler = rage::scrNativeHandler(*)(rage::scrNativeRegistrationTable* registration_table, rage::scrNativeHash hash);
	get_native_handler m_get_native_handler{};
	rage::scrNativeRegistrationTable* m_native_registration_table{};*/

	bool* m_IsSessionStarted;
	using DecodePeerInfo = bool(rage::rlGamerInfoBase* info, char* buffer, int* bytes_read);
	DecodePeerInfo* m_DecodePeerInfo;
	using ConnectToPeer = bool(rage::netConnectionManager* mgr, rage::rlGamerInfoBase* gamer_info, rage::snConnectToPeerTaskData* data, rage::snConnectToPeerTaskResult* result, rage::rlTaskStatus* status);
	ConnectToPeer* m_ConnectToPeer;
	using StartGetSessionByGamerHandle = bool(int profile_index, rage::rlGamerHandle* handles, int count, rage::rlSessionByGamerTaskResult* result, int unk, bool* success, rage::rlTaskStatus* state);
	StartGetSessionByGamerHandle* m_StartGetSessionByGamerHandle;
	using StartGetPresenceAttributes = bool(int profile_index, rage::rlScHandle* handle, rage::rlQueryPresenceAttributesContext* contexts, int count, rage::rlTaskStatus* state);
	StartGetPresenceAttributes* m_StartGetPresenceAttributes;
	ScInfo* m_sc_info;    // Social Club Info
	using RunScriptThreads = bool(std::uint32_t ops_to_execute);
	RunScriptThreads* m_RunScriptThreads{};
	rage::CReplayInterface** m_ReplayInterface{};
	using PtrToHandle = Entity(void*);
	PtrToHandle* m_PtrToHandle{};
	using HandleToPtr = rage::CDynamicEntity* (Entity);
	HandleToPtr* m_HandleToPtr{};
	using RequestControl = void(rage::netObject* net_object);
	RequestControl* m_RequestControl{};
	using MigrateObject = void(CNetGamePlayer* player, rage::netObject* object, int type);
	MigrateObject* m_MigrateObject/*{}*/;
	PVOID m_WriteVehicleProximityMigrationDataNode{};
	using ClearPedTaskNetwork = void(CPed* ped, bool immediately);
	ClearPedTaskNetwork* m_ClearPedTaskNetwork;
	rage::scrNativeRegistrationTable* m_NativeRegistrationsPtr;

	std::uint64_t m_WorldBase;

	using GetNativeHandler = scrNativeHandler(rage::scrNativeRegistrationTable* registration_table, scrNativeHash hash);
	GetNativeHandler* m_GetNativeHandler;

	PVOID m_ModelSpawnBypass;
	PVOID m_TimecycleOverride;//m_timecycle_keyframe_override
	//PVOID PVOID_RainMain;
	uintptr_t PVOID_RainMain;
	//int(*AddEntityToPool)(UINT64 address);
	UINT64(*GetEntityAddress)(Entity handle);
	uintptr_t* vm_address;
	uintptr_t* em_address;

	using get_host_array_handler_by_index = netArrayHandlerBase* (*)(CGameScriptHandlerNetComponent* component, int index);
	get_host_array_handler_by_index m_get_host_array_handler_by_index;
	PVOID m_serialize_join_request_message;
};
inline std::unique_ptr<GameVariables1> g_GameVariables;



namespace BATTLEYE
{
	static int _GET_BATTLEYE_INIT_STATE() { return invoke<int>(0x7F7E8401F81CB65B); }
}

//typedef int(__cdecl* BATTLEYE_INITSTATE)(int one, int two);
//typedef __int64(__fastcall BATTLEYE_INITSTATE(__int64 a1, __int64(__fastcall* a2)(void*, __int64, __int64)));
//typedef __int64(__cdecl BATTLEYE_INITSTATE(__int64 a1, __int64(__cdecl* a2)(void*, __int64, __int64)));
//class GameVariables3
//{
//public:
//	explicit GameVariables3();
//	~GameVariables3() noexcept = default;
//	GameVariables3(GameVariables3 const&) = delete;
//	GameVariables3(GameVariables3&&) = delete;
//	GameVariables3& operator=(GameVariables3 const&) = delete;
//	GameVariables3& operator=(GameVariables3&&) = delete;
//
//	//using BattleYeState = bool(std::uint64_t ops_to_execute);
//	//__int64(__int64 __fastcall sub_7FF6427F5680(__int64 a1, __int64(__fastcall* a2)(void*, __int64, __int64))
//	//using BattleYeState = __int64(__int64 __fastcall sub_7FF6427F5680(__int64 a1, __int64(__fastcall* a2)(void*, __int64, __int64)));
//	//using BattleYeState = __int64(__int64 a1, __int64(__fastcall* a2)(void*, __int64, __int64));
//	/*using BattleYeState = __int64(__int64 a1, __int64(__cdecl* a2)(void*, __int64, __int64));*/
//	//using BattleYeState = int(int, int);
//	////using BattleYeState = BATTLEYE_INITSTATE;
//	//BattleYeState* m_BattleYeState/*{}*/;
//};
//inline std::unique_ptr<GameVariables3> g_GameVariables3;

//GTA5.exe + 0x26E61C0//? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D//RED
//GTA5.exe + 0x26E61C4//? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D//GREEN
//GTA5.exe + 0x26E61C8//? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42//BLUE
//GTA5.exe+0x26E60FC//? ? ? C1 80 AA 5A CE F6 7F//RAIN GRAVITY (Default Value -12)
// 
//inline GameVariables1* g_pointers{};

//inline GameVariables1* g_pointers{};



inline Network* GetNetwork()
{
	return *g_GameVariables->m_Network;
}

class rate_limiter
{
	std::uint32_t m_attempts_allowed_in_time_period;
	std::chrono::milliseconds m_time_period;
	std::chrono::system_clock::time_point m_last_event_time{};
	std::uint32_t m_num_attempts_allowed = 0;
public:
	rate_limiter(std::chrono::milliseconds time_period, std::uint32_t num_allowed_attempts) :
		m_attempts_allowed_in_time_period(num_allowed_attempts),
		m_time_period(time_period)
	{
	}

	// Returns true if the rate limit has been exceeded
	bool process()
	{
		if (std::chrono::system_clock::now() - m_last_event_time < m_time_period)
		{
			if (++m_num_attempts_allowed > m_attempts_allowed_in_time_period)
				return true;
		}
		else
		{
			m_last_event_time = std::chrono::system_clock::now();
			m_num_attempts_allowed = 1;
		}
		return false;
	}

	// Check if the rate limit was exceeded by the last process() call. Use this to prevent the player from being flooded with notifications
	bool exceeded_last_process()
	{
		return (m_num_attempts_allowed - 1) == m_attempts_allowed_in_time_period;
	}
};

class AbstractCallback
{
public:
	virtual ~AbstractCallback() noexcept = default;
	AbstractCallback(AbstractCallback const&) = delete;
	AbstractCallback& operator=(AbstractCallback const&) = delete;
	AbstractCallback(AbstractCallback&&) = delete;
	AbstractCallback& operator=(AbstractCallback&&) = delete;

	/**
	 * \brief Is the callback completed?
	 * \return bool
	 */
	virtual bool IsDone() = 0;

	/**
	 * \brief Called when IsDone() returns true
	 */
	virtual void OnSuccess() = 0;

	/**
	 * \brief Called when IsDone() returns false
	 */
	virtual void OnFailure() = 0;
protected:
	AbstractCallback() = default;
};
class DelayCallback : public AbstractCallback
{
public:
	explicit DelayCallback(std::chrono::high_resolution_clock::duration delay, std::function<void()> action) :
		m_StartTime(std::chrono::high_resolution_clock::now()),
		m_Delay(delay),
		m_Action(std::move(action))
	{
	}

	bool IsDone() override
	{
		return (std::chrono::high_resolution_clock::now() - m_StartTime).count() >= m_Delay.count();
	}

	void OnSuccess() override
	{
		if (m_Action)
			std::invoke(m_Action);
	}

	void OnFailure() override
	{
	}

private:
	std::chrono::steady_clock::time_point m_StartTime;
	std::chrono::high_resolution_clock::duration m_Delay;
	std::function<void()> m_Action;
};
class ModelCallback : public AbstractCallback
{
public:
	explicit ModelCallback(std::uint32_t model, std::function<void()> action) :
		m_Model(model),
		m_Action(std::move(action))
	{
	}

	bool IsDone() override
	{
		return STREAMING::HAS_MODEL_LOADED(m_Model);
	}

	void OnSuccess() override
	{
		if (m_Action)
			std::invoke(m_Action);
	}

	void OnFailure() override
	{
		STREAMING::REQUEST_MODEL(m_Model);
	}
private:
	std::uint32_t m_Model;
	std::function<void()> m_Action;
};

namespace TPT
{
	extern void teleportWayp();
	extern bool IsDone();
	extern void OnSuccess();
	extern void OnFailure();
	extern float m_CoordX;
	extern float m_CoordY;
	extern float m_CoordZ;
	extern float m_GroundZ;
	/*extern std::int32_t m_Entity;*/
	extern int m_Entity;
}
class TeleportWaypoint : public AbstractCallback
{
public:
	explicit TeleportWaypoint(std::int32_t entity, float x, float y) :
		m_Entity(entity),
		m_CoordX(x),
		m_CoordY(y)
	{
	}
	bool IsDone() override
	{
		return (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(m_CoordX, m_CoordY, 1000.f, &m_Ground, false) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(m_Entity));
	}

	void OnSuccess() override
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(m_Entity, m_CoordX, m_CoordY, m_Ground + 2.f, FALSE, FALSE, FALSE);
	}

	void OnFailure() override
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(m_Entity);
		STREAMING::REQUEST_COLLISION_AT_COORD(m_CoordX, m_CoordY, m_CoordZ);
		if (m_CoordZ <= 0.f)
			m_CoordZ = 1000.f;
		m_CoordZ -= 100.f;
	}
private:
	float m_CoordX;
	float m_CoordY;
	float m_CoordZ = 1000.f;
	float m_Ground = 0.f;
	std::int32_t m_Entity;
	std::function<void()> m_Action;
};
//#pragma once


enum class ScriptType
{
	Game,
	D3D
};

enum class ScriptAction
{
	D3DResizeBuffersPre,
	D3DResizeBuffersPost,
	GetLabelText
};

class Script
{
public:
	virtual ~Script() noexcept = default;
	Script(Script const&) = delete;
	Script(Script&&) = delete;
	Script& operator=(Script const&) = delete;
	Script& operator=(Script&&) = delete;

	virtual bool IsInitialized() = 0;
	virtual ScriptType GetType() = 0;
	virtual void Initialize() = 0;
	virtual void Destroy() = 0;
	virtual void Tick() = 0;
protected:
	Script() = default;
};

class CallbackScript : public Script
{
public:
	explicit CallbackScript() = default;
	~CallbackScript() noexcept = default;

	bool IsInitialized() override;
	ScriptType GetType() override;
	void Initialize() override;
	void Destroy() override;
	void Tick() override;

	/**
	 * \brief Adds a callback to the list
	 * \param args... The arguments to be passed to CallbackType's constructor
	 */
	template <typename CallbackType, typename ...TArgs>
	void AddCallback(TArgs&&... args)
	{
		m_Callbacks.push_back(std::make_unique<CallbackType>(std::forward<TArgs>(args)...));
	}
private:
	bool m_Initialized{};
	std::vector<std::unique_ptr<AbstractCallback>> m_Callbacks;
};
inline std::shared_ptr<CallbackScript> g_CallbackScript;


//namespace rage2
//{
//	class pgBase
//	{
//	public:
//		virtual ~pgBase() = default;
//		virtual int return_zero() = 0;
//		virtual void error() = 0;
//
//		void* unk_0000; // 0x0000
//	}; //Size: 0x0008
//	//static_assert(sizeof(pgBase) == 0x10);
//}
//
//namespace rage2
//{
//	//class scrProgram : public rage2::pgBase
//	//{
//	//public:
//	//	std::uint8_t** m_code_blocks;  // 0x10
//	//	std::uint32_t m_hash;          // 0x18
//	//	std::uint32_t m_code_size;     // 0x1C
//	//	std::uint32_t m_arg_count;     // 0x20
//	//	std::uint32_t m_local_count;   // 0x24
//	//	std::uint32_t m_global_count;  // 0x28
//	//	std::uint32_t m_native_count;  // 0x2C
//	//	void* m_local_data;            // 0x30
//	//	std::int64_t** m_global_data;  // 0x38
//	//	void** m_native_entrypoints;   // 0x40
//	//	char m_padding6[0x10];         // 0x48
//	//	std::uint32_t m_name_hash;     // 0x58
//	//	char m_padding7[0x04];         // 0x5C
//	//	const char* m_name;            // 0x60
//	//	const char** m_strings_data;   // 0x68
//	//	std::uint32_t m_strings_count; // 0x70
//	//	char m_padding8[0x0C];         // 0x74
//
//	//	bool is_valid() const
//	//	{
//	//		return m_code_size != 0;
//	//	}
//
//	//	std::uint32_t get_num_code_pages() const
//	//	{
//	//		return (m_code_size + 0x3FFF) >> 14;
//	//	}
//
//	//	std::uint32_t get_code_page_size(std::uint32_t page) const
//	//	{
//	//		auto num = get_num_code_pages();
//	//		if (page < num)
//	//		{
//	//			if (page == num - 1)
//	//				return m_code_size & 0x3FFF;
//	//			return 0x4000;
//	//		}
//
//	//		return 0;
//	//	}
//
//	//	std::uint32_t get_full_code_size() const
//	//	{
//	//		auto numPages = get_num_code_pages();
//	//		if (!numPages)
//	//			return 0;
//	//		if (numPages == 1)
//	//			--numPages;
//
//	//		return (numPages * 0x4000) + (m_code_size & 0x3FFF);
//	//	}
//
//	//	std::uint8_t* get_code_page(std::uint32_t page) const
//	//	{
//	//		return m_code_blocks[page];
//	//	}
//
//	//	std::uint8_t* get_code_address(std::uint32_t index) const
//	//	{
//	//		if (index < m_code_size)
//	//			return &m_code_blocks[index >> 14][index & 0x3FFF];
//
//	//		return nullptr;
//	//	}
//
//	//	const char* get_string(std::uint32_t index) const
//	//	{
//	//		if (index < m_strings_count)
//	//			return &m_strings_data[index >> 14][index & 0x3FFF];
//
//	//		return nullptr;
//	//	}
//
//	//	void** get_address_of_native_entrypoint(void* entrypoint)
//	//	{
//	//		for (std::uint32_t i = 0; i < m_native_count; ++i)
//	//		{
//	//			if (m_native_entrypoints[i] == entrypoint)
//	//			{
//	//				return m_native_entrypoints + i;
//	//			}
//	//		}
//
//	//		return nullptr;
//	//	}
//	//};
//
//	class scrProgram : public rage2::pgBase
//	{
//	public:
//		std::uint8_t** m_code_blocks;  // 0x10
//		std::uint32_t m_hash;          // 0x18
//		std::uint32_t m_code_size;     // 0x1C
//		std::uint32_t m_arg_count;     // 0x20
//		std::uint32_t m_local_count;   // 0x24
//		std::uint32_t m_global_count;  // 0x28
//		std::uint32_t m_native_count;  // 0x2C
//		rage::scrValue* m_local_data;            // 0x30
//		rage::scrValue** m_global_data;  // 0x38
//		scrNativeHandler* m_native_entrypoints;   // 0x40
//		std::uint32_t m_proc_count;    // 0x48
//		char pad_004C[4];              // 0x4C
//		const char** m_proc_names;     // 0x50
//		std::uint32_t m_name_hash;     // 0x58
//		std::uint32_t m_ref_count;     // 0x5C
//		const char* m_name;            // 0x60
//		const char** m_strings_data;   // 0x68
//		std::uint32_t m_strings_count; // 0x70
//		char m_breakpoints[0x0C];      // 0x74 This is an atMap, which we don't have the class for ATM.
//
//		bool is_valid() const
//		{
//			return m_code_size != 0;
//		}
//
//		std::uint32_t get_num_code_pages() const
//		{
//			return (m_code_size + 0x3FFF) >> 14;
//		}
//
//		std::uint32_t get_code_page_size(std::uint32_t page) const
//		{
//			auto num = get_num_code_pages();
//			if (page < num)
//			{
//				if (page == num - 1)
//					return m_code_size & 0x3FFF;
//				return 0x4000;
//			}
//
//			return 0;
//		}
//
//		std::uint32_t get_full_code_size() const
//		{
//			auto numPages = get_num_code_pages();
//			if (!numPages)
//				return 0;
//			if (numPages == 1)
//				--numPages;
//
//			return (numPages * 0x4000) + (m_code_size & 0x3FFF);
//		}
//
//		std::uint8_t* get_code_page(std::uint32_t page) const
//		{
//			return m_code_blocks[page];
//		}
//
//		std::uint8_t* get_code_address(std::uint32_t index) const
//		{
//			if (index < m_code_size)
//				return &m_code_blocks[index >> 14][index & 0x3FFF];
//
//			return nullptr;
//		}
//
//		const char* get_string(std::uint32_t index) const
//		{
//			if (index < m_strings_count)
//				return &m_strings_data[index >> 14][index & 0x3FFF];
//
//			return nullptr;
//		}
//
//		scrNativeHandler* get_address_of_native_entrypoint(scrNativeHandler entrypoint)
//		{
//			for (std::uint32_t i = 0; i < m_native_count; ++i)
//			{
//				if (m_native_entrypoints[i] == entrypoint)
//				{
//					return m_native_entrypoints + i;
//				}
//			}
//
//			return nullptr;
//		}
//	};
//
//	class scrProgramTableEntry
//	{
//	public:
//		scrProgram* m_program;     // 0x00
//		char m_Pad1[0x04];         // 0x08
//		joaat_t m_hash;            // 0x0C
//	};
//
//	class scrProgramTable
//	{
//	public:
//		scrProgramTableEntry* m_data;    // 0x00
//		char m_padding[0x10];            // 0x08
//		std::uint32_t m_size;            // 0x18
//
//		std::list<joaat_t> all_script_hashes()
//		{
//			std::list<rage::joaat_t> hash;
//
//			for (uint32_t i = 0; i < m_size; ++i)
//			{
//				if (m_data[i].m_program != nullptr && m_data[i].m_program->m_name != nullptr)
//				{
//					hash.push_back(m_data[i].m_hash);
//				}
//			}
//			return hash;
//		}
//
//		std::list<std::string> all_script_names()
//		{
//			std::list<std::string> hash;
//
//			for (uint32_t i = 0; i < m_size; ++i)
//			{
//				if (m_data[i].m_program != nullptr && m_data[i].m_program->m_name != nullptr)
//				{
//					hash.push_back(m_data[i].m_program->m_name);
//				}
//			}
//			return hash;
//		}
//
//		scrProgram* find_script(joaat_t hash)
//		{
//			for (std::uint32_t i = 0; i < m_size; ++i)
//			{
//				if (m_data[i].m_hash == hash)
//				{
//					return m_data[i].m_program;
//				}
//			}
//
//			return nullptr;
//		}
//
//		scrProgramTableEntry* begin()
//		{
//			return m_data;
//		}
//
//		scrProgramTableEntry* end()
//		{
//			return m_data + m_size;
//		}
//	};
//
//	/*static_assert(sizeof(scrProgram) == 0x80);
//	static_assert(sizeof(scrProgramTableEntry) == 0x10);
//	static_assert(sizeof(scrProgramTable) == 0x1C);*/
//}
//#pragma pack(pop)

class CNetworkObjectMgr;

class GameFunctions1
{
public:
	explicit GameFunctions1();
	~GameFunctions1() noexcept = default;
	GameFunctions1(GameFunctions1 const&) = delete;
	GameFunctions1(GameFunctions1&&) = delete;
	GameFunctions1& operator=(GameFunctions1 const&) = delete;
	GameFunctions1& operator=(GameFunctions1&&) = delete;

	using IsDlcPresent = bool(std::uint32_t hash);
	IsDlcPresent* m_IsDlcPresent;

	using WndProc = LRESULT(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	WndProc* m_WndProc;

	using GetEventData = bool(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
	GetEventData* m_GetEventData;

	using GetLabelText = const char* (void* unk, const char* label);
	GetLabelText* m_GetLabelText;

	using DisableErrorScreen = void(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background);
	DisableErrorScreen* m_DisableErrorScreen;

	/*using RIDJoinHandle = std::int64_t* (int32_t friendIndex);
	RIDJoinHandle* m_RIDJoinHandle;*/
	/*RIDJoinHandle* o_RIDJoinHandle;*/

	using RIDJoinFriends = bool(int64_t* a1, int* hash);
	RIDJoinFriends* m_RIDJoinFriends;
	/*RIDJoinFriends* o_RIDJoinFriends;*/
	using ScriptVM = int(void* stack, signed __int64** globals, void* program, scrThreadContext* threadContext);
	ScriptVM* m_ScriptVM;
	using GetConnectionPeer = netConnectionPeer * (rage::netConnectionManager* manager, int peer_id);
	GetConnectionPeer* m_GetConnectionPeer;
	using SendRemoveGamerCmd = void(rage::netConnectionManager* net_connection_mgr, netConnectionPeer* player, int connection_id, rage::snMsgRemoveGamersFromSessionCmd* cmd, int flags);
	SendRemoveGamerCmd* m_SendRemoveGamerCmd;
	/*using GetConnectionPeer = uintptr_t(rage::netConnectionManager* manager, int peer_id);
	GetConnectionPeer* m_GetConnectionPeer;*/
	/*using SendRemoveGamerCmd = void(rage::netConnectionManager* net_connection_mgr, uintptr_t player, int connection_id, snMsgRemoveGamersFromSessionCmd* cmd, int flags);
	SendRemoveGamerCmd* m_SendRemoveGamerCmd;*/
	using HandleRemoveGamerCmd = void* (rage::snSession* session, rage::snPlayer* origin, rage::snMsgRemoveGamersFromSessionCmd* cmd);
	HandleRemoveGamerCmd* m_HandleRemoveGamerCmd;
	using ReadBitbufDWORD = bool(datBitBuffer* buffer, PVOID read, int bits);
	ReadBitbufDWORD* m_ReadBitbufDWORD;

	using ReadBitbufString = bool(datBitBuffer* buffer, char* read, int bits);
	ReadBitbufString* m_ReadBitbufString;

	using ReadBitbufBool = bool(datBitBuffer* buffer, bool* read, int bits);
	ReadBitbufBool* m_ReadBitbufBool;

	using ReadBitbufArray = bool(datBitBuffer* buffer, PVOID read, int bits, int unk);
	ReadBitbufArray* m_ReadBitbufArray;
	//WRITE
	using WriteBitbufQWORD = bool(datBitBuffer* buffer, uint64_t val, int bits);
	WriteBitbufQWORD* m_WriteBitbufQWORD;

	using WriteBitbufDWORD = bool(datBitBuffer* buffer, uint32_t val, int bits);
	WriteBitbufDWORD* m_WriteBitbufDWORD;

	using WriteBitbufInt64 = bool(datBitBuffer* buffer, int64_t val, int bits);
	WriteBitbufInt64* m_WriteBitbufInt64;

	using WriteBitbufInt32 = bool(datBitBuffer* buffer, int32_t val, int bits);
	WriteBitbufInt32* m_WriteBitbufInt32;

	using WriteBitbufBool = bool(datBitBuffer* buffer, bool val, int bits);
	WriteBitbufBool* m_WriteBitbufBool;

	using WriteBitbufArray = bool(datBitBuffer* buffer, void* val, int bits, int unk);
	WriteBitbufArray* m_WriteBitbufArray;

	int64_t** m_SendChatPointer{};
	using SendChatMessage = bool(int64_t* send_chat_ptr, rage::rlGamerInfo* gamer_info, char* message, bool is_team);
	SendChatMessage* m_SendChatMessage;

	using send_packet = bool(rage::netConnectionManager* mgr, netConnectionPeer* peer, int connection_id, void* data, int size, int flags);
	using queue_packet = bool(rage::netConnectionManager* mgr, int msg_id, void* data, int size, int flags, void* unk);
	send_packet* m_send_packet;
	queue_packet* m_queue_packet;

	typedef __int64(__cdecl* fpModelInfo)(unsigned int model, DWORD* out);
	fpModelInfo model_info;
	typedef uint64_t(__cdecl* fpGetEntityFromScriptGuId)(int ped);
	fpGetEntityFromScriptGuId			    get_entity_from_script_gu_id;
	/*using start_get_session_by_gamer_handle = bool(int profile_index, rage::rlGamerHandle* handles, int count, rlSessionByGamerTaskResult* result, int unk, bool* success, rage::rlTaskStatus* state);
	start_get_session_by_gamer_handle* m_start_get_session_by_gamer_handle;*/
	using script_vm = int(uint64_t* stack, int64_t** scr_globals, rage::scrProgram* program, scrThreadContext* ctx);
	/*using script_vm = int(uint64_t* stack, int64_t** scr_globals, rage2::scrProgram* program, scrThreadContext* ctx);*/
	script_vm* m_script_vm;
	/*using TriggerScriptEvent = void(bool unk0, uint64_t* args, int argCount, int bitFlags);
	TriggerScriptEvent* m_TriggerScriptEvent;*/

	//using trigger_script_event = void(int event_group, int64_t* args, int arg_count, int player_bits);
	using trigger_script_event = void(int event_group, int64_t* args, int arg_count, int player_bits, int event_id);
	trigger_script_event* m_trigger_script_event;
	using JoinSessionByInfo = bool(Network* network, rage::rlSessionInfo* info, int unk, int flags, rage::rlGamerHandle* handles, int handlecount);
	JoinSessionByInfo* m_JoinSessionByInfo;

	using EncodeSessionInfo = bool(rage::rlSessionInfo* info, char* buffer, int buffer_size, int* bytes_written);
	EncodeSessionInfo* m_EncodeSessionInfo;
	using DecodeSessionInfo = bool(rage::rlSessionInfo* out_info, char* buffer, int* bytes_read);
	DecodeSessionInfo* m_DecodeSessionInfo;
	using start_get_session_by_gamer_handle = bool(int profile_index, rage::rlGamerHandle* handles, int count, rage::rlSessionByGamerTaskResult* result, int unk, bool* success, rage::rlTaskStatus* state);
	start_get_session_by_gamer_handle* m_StartGetSessionByGamerHandle;

	using get_sync_type_info = const char* (*)(uint16_t sync_type, char a2);
	get_sync_type_info* m_get_sync_type_info;
	using get_sync_tree_for_type = rage::netSyncTree* (*)(CNetworkObjectMgr* mgr, uint16_t sync_type);
	get_sync_tree_for_type* m_get_sync_tree_for_type;

	using get_net_object = rage::netObject* (*)(CNetworkObjectMgr* mgr, int16_t id, bool can_delete_be_pending);
	get_net_object m_get_net_object;
	CNetworkObjectMgr** m_network_object_mgr;
	GameDataHash** m_game_data_hash;
	PVOID m_network_can_access_multiplayer;
	PVOID m_be_network_bail_patch;
	uint64_t* m_host_token;
	uint64_t* m_peer_id;
	rage::rlGamerInfo* m_profile_gamer_info;     // per profile gamer info
	rage::rlGamerInfo* m_player_info_gamer_info; // the gamer info that is applied to CPlayerInfo
	CCommunications** m_communications;
	using get_gameplay_cam_coords = Vector3(*)();
	get_gameplay_cam_coords m_get_gameplay_cam_coords;
};

inline std::unique_ptr<GameFunctions1> g_GameFunctions;


class datBitBuffer
{
public:
	datBitBuffer(void* data, uint32_t size) {
		m_data = data;
		m_bitOffset = 0;
		m_maxBit = size * 8;
		m_bitsRead = 0;
		m_curBit = 0;
		m_highestBitsRead = 0;
		m_flagBits = 0;
	}
	uint32_t GetPosition() {
		return m_bitsRead;
	}
	bool Seek(uint32_t bits) {
		if (bits >= 0) {
			uint32_t length = (m_flagBits & 1) ? m_maxBit : m_curBit;
			if (bits <= length)
				m_bitsRead = bits;
		}
		return false;
	}
	bool WriteBool(bool integer) {
		return g_GameFunctions->m_WriteBitbufBool(this, integer, 1);
	}
	bool ReadBool(bool* integer) {
		return g_GameFunctions->m_ReadBitbufBool(this, integer, 1);
	}
	bool ReadPeerId(uint64_t* integer) {
		return this->ReadQWord(integer, 0x40);
	}
	uint64_t ReadBits(size_t numBits) {
		auto const totalBits = (m_flagBits & 1) ? m_maxBit : m_curBit;
		if ((m_flagBits & 2) || m_bitsRead + numBits > totalBits)
			return 0;
		auto const bufPos = m_bitsRead + m_bitOffset;
		auto const initialBitOffset = bufPos & 0b111;
		auto const start = &((uint8_t*)m_data)[bufPos / 8];
		auto const next = &start[1];
		auto result = (start[0] << initialBitOffset) & 0xff;
		for (auto i = 0; i < ((numBits - 1) / 8); i++) {
			result <<= 8;
			result |= next[i] << initialBitOffset;
		}
		if (initialBitOffset)
			result |= next[0] >> (8 - initialBitOffset);
		m_bitsRead += static_cast<uint32_t>(numBits);
		if (m_bitsRead > m_highestBitsRead)
			m_highestBitsRead = m_bitsRead;
		return result >> ((8 - numBits) % 8);
	}
	int GetDataLength() {
		int leftoverBit = (m_curBit % 8) ? 1 : 0;
		return (m_curBit / 8) + leftoverBit;
	}
	bool ReadString(char* string, int bits) {
		return g_GameFunctions->m_ReadBitbufString(this, string, bits);
	}
	bool WriteByte(uint8_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadByte(uint8_t* integer, int bits) {
		uint32_t read;
		if (g_GameFunctions->m_ReadBitbufDWORD(this, &read, bits)) {
			*integer = read;
			return true;
		}
		return false;
	}
	bool WriteWord(uint16_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadWord(uint16_t* integer, int bits) {
		uint32_t read;
		if (g_GameFunctions->m_ReadBitbufDWORD(this, &read, bits)) {
			*integer = read;
			return true;
		}
		return false;
	}
	bool WriteDword(uint32_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadDword(uint32_t* integer, int bits) {
		return g_GameFunctions->m_ReadBitbufDWORD(this, integer, bits);
	}
	bool WriteInt32(int32_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufDWORD(this, integer, bits);
	}
	bool ReadInt32(int32_t* integer, int bits) {
		int32_t v8;
		int32_t v9;
		if (ReadDword((uint32_t*)&v8, 1u) && ReadDword((uint32_t*)&v9, bits - 1)) {
			*integer = v8 + (v9 ^ -v8);
			return true;
		}
		return false;
	}
	bool WriteQWord(uint64_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufQWORD(this, integer, bits);
	}
	bool ReadQWord(uint64_t* integer, int bits) {
		if (bits <= 32) {
			uint32_t v10;
			if (ReadDword(&v10, bits)) {
				*integer = v10;
				return true;
			}
		}
		else {
			uint32_t v10, v11;
			if (ReadDword(&v11, 32u) && ReadDword(&v10, bits - 32u)) {
				*integer = v11 | ((uint64_t)v10 << 32);
				return true;
			}
		}
		return false;
	}
	bool WriteInt64(int64_t integer, int bits) {
		return g_GameFunctions->m_WriteBitbufInt64(this, integer, bits);
	}
	bool ReadInt64(int64_t* integer, int bits) {
		uint32_t v8;
		uint64_t v9;
		if (ReadDword(&v8, 1u) && ReadQWord(&v9, bits - 1)) {
			*integer = v8 + (v9 ^ -(int64_t)v8);
			return true;
		}
		return false;
	}
	bool WriteArray(void* array, int size) {
		return g_GameFunctions->m_WriteBitbufArray(this, array, size, 0);
	}
	bool ReadArray(PVOID array, int size) {
		return g_GameFunctions->m_ReadBitbufArray(this, array, size, 0);
	}

	template<typename T>
	inline T Read(int length)
	{
		static_assert(sizeof(T) <= 4, "maximum of 32 bit read");

		uint32_t val = 0;
		ReadDword(&val, length);

		return T(val);
	}

	template<typename T>
	inline T ReadSigned(int length)
	{
		static_assert(sizeof(T) <= 4, "maximum of 32 bit read");

		int val = 0;
		ReadInt32(&val, length);

		return T(val);
	}

	template<typename T>
	inline void Write(T data, int length)
	{
		static_assert(sizeof(T) <= 8, "maximum of 64 bit write");

		WriteQWord((uint64_t)data, length);
	}

	template<typename T>
	inline void WriteSigned(int length, T data)
	{
		int sign = data < 0;
		int signEx = (data < 0) ? 0xFFFFFFFF : 0;
		int d = (data ^ signEx);

		Write<int>(1, sign);
		Write<int>(length - 1, d);
	}

	inline float ReadFloat(int length, float divisor)
	{
		auto integer = Read<int>(length);

		float max = (1 << length) - 1;
		return ((float)integer / max) * divisor;
	}

	inline void WriteFloat(int length, float divisor, float value)
	{
		float max = (1 << length) - 1;
		int integer = (int)((value / divisor) * max);

		Write<int>(length, integer);
	}

	inline float ReadSignedFloat(int length, float divisor)
	{
		auto integer = ReadSigned<int>(length);

		float max = (1 << (length - 1)) - 1;
		return ((float)integer / max) * divisor;
	}

	inline void WriteSignedFloat(int length, float divisor, float value)
	{
		float max = (1 << (length - 1)) - 1;
		int integer = (int)((value / divisor) * max);

		WriteSigned<int>(length, integer);
	}
public:
	void* m_data; //0x0000
	uint32_t m_bitOffset; //0x0008
	uint32_t m_maxBit; //0x000C
	uint32_t m_bitsRead; //0x0010
	uint32_t m_curBit; //0x0014
	uint32_t m_highestBitsRead; //0x0018
	uint8_t m_flagBits; //0x001C
};

namespace functions2
{
	using run_script_threads = bool(*)(std::uint32_t ops_to_execute);
	using fix_vectors = void(*)(scrNativeCallContext* call_ctx);

	using get_net_game_player = CNetGamePlayer * (*)(Player player);

	using trigger_script_event = void(*)(int event_group, int64_t* args, int arg_count, int player_bits);


	using increment_stat_event = bool(*)(uint64_t net_event_struct, int64_t sender, int64_t a3);

	using ptr_to_handle = Entity(*)(void*);
	using handle_to_ptr = rage::CDynamicEntity* (*)(Entity);

	using multiplayer_chat_filter = int(__int64 chat_type, const char* input, const char** output);
	using write_player_game_state_data_node = bool(*)(rage::netObject* plr, CPlayerGameStateDataNode2* node);

	using get_gameplay_cam_coords = Vector3(*)();

	using get_screen_coords_for_world_coords = bool(*)(float* world_coords, float* out_x, float* out_y);

	// Bitbuffer read/write START
	/*using read_bitbuf_dword = bool(datBitBuffer* buffer, PVOID read, int bits);
	using read_bitbuf_string = bool(datBitBuffer* buffer, char* read, int bits);
	using read_bitbuf_bool = bool(datBitBuffer* buffer, bool* read, int bits);
	using read_bitbuf_array = bool(datBitBuffer* buffer, PVOID read, int bits, int unk);
	using write_bitbuf_qword = bool(datBitBuffer* buffer, uint64_t val, int bits);
	using write_bitbuf_dword = bool(datBitBuffer* buffer, uint32_t val, int bits);
	using write_bitbuf_int64 = bool(datBitBuffer* buffer, int64_t val, int bits);
	using write_bitbuf_int32 = bool(datBitBuffer* buffer, int32_t val, int bits);
	using write_bitbuf_bool = bool(datBitBuffer* buffer, bool val, int bits);
	using write_bitbuf_array = bool(datBitBuffer* buffer, void* val, int bits, int unk);*/

	// Bitbuffer read/write END
	// Received Event Signatures START
	using send_event_ack = void(*)(netEventMgr* event_manager, CNetGamePlayer* source_player, CNetGamePlayer* target_player, int event_index, int event_handled_bitset);
	// Received Event Signatures END

	//Sync signatures START
	//using get_sync_type_info = const char* (*)(uint16_t sync_type, char a2);

	/*using get_sync_tree_for_type = rage::netSyncTree* (*)(rage::CNetworkObjectMgr* mgr, uint16_t sync_type);

	using get_net_object = rage::netObject* (*)(rage::CNetworkObjectMgr* mgr, int16_t id, bool can_delete_be_pending);

	using get_net_object_for_player = rage::netObject* (*)(rage::CNetworkObjectMgr*, int16_t, CNetGamePlayer*, bool);*/

	//using read_bitbuffer_into_sync_tree = void(*)(rage::netSyncTree* tree, uint64_t flag, uint32_t flag2, datBitBuffer* buffer, uint64_t netLogStub);
	//Sync signatures END

	//using reset_network_complaints = void(*)(CNetComplaintMgr* mgr);

	/*using fidevice_get_device = fiDevice* (*)(const char* path, bool allow_root);
	using fipackfile_ctor = fiPackfile* (*)(fiPackfile* this_);
	using fipackfile_open_archive = bool(*)(fiPackfile* this_, const char* archive, bool b_true, int type, intptr_t very_false);
	using fipackfile_mount = bool(*)(fiPackfile* this_, const char* mount_point);
	using fipackfile_unmount = bool(*)(const char* mount_point);*/

	/*using start_get_session_by_gamer_handle = bool(*)(int profile_index, rlGamerHandle* handles, int count, rlSessionByGamerTaskResult* result, int unk, bool* success, int* state);
	using start_matchmaking_find_sessions = bool(*)(int profile_index, int available_slots, NetworkGameFilterMatchmakingComponent* m_filter, unsigned int max_sessions, rlSessionInfo* result_sessions, int* result_session_count, int* state);
	using join_session_by_info = bool(*)(Network* network, rlSessionInfo* info, int unk, int flags, rlGamerHandle* handles, int handlecount);*/

	using generate_uuid = bool(*)(std::uint64_t* uuid);

	using get_vehicle_gadget_array_size = int(*)(eVehicleGadgetType type);

	//using write_join_response_data = bool(*)(CMsgJoinResponse* response, void* data, int size, uint32_t* size_used);

	//using queue_packet = bool(*)(netConnectionManager* mgr, int msg_id, void* data, int size, int flags, void* unk);

	using generate_uuid = bool(*)(std::uint64_t* uuid);

	using send_chat_message = bool(*)(int64_t* send_chat_ptr, rage::rlGamerInfo* game_info, char* message, bool is_team);

	using send_network_damage = void(*)(rage::CEntity* source, rage::CEntity* target, Vector3* position, int hit_component, bool override_default_damage, int weapon_type, float override_damage, int tire_index, int suspension_index, int flags,
		std::uint32_t action_result_hash, std::int16_t action_result_id, int action_unk, bool hit_weapon, bool hit_weapon_ammo_attachment, bool silenced, bool unk, Vector3* impact_direction);
	using request_ragdoll = void(*)(uint16_t object_id);

	using get_connection_peer = netConnectionPeer * (*)(rage::netConnectionManager* manager, int peer_id);
	using send_remove_gamer_cmd = void(*)(rage::netConnectionManager* net_connection_mgr, netConnectionPeer* player, int connection_id, rage::snMsgRemoveGamersFromSessionCmd* cmd, int flags);
	//using handle_remove_gamer_cmd = void* (*)(snSession* session, snPlayer* origin, snMsgRemoveGamersFromSessionCmd* cmd);

	//using script_vm = int (*) (uint64_t* stack, int64_t** scr_globals, rage::scrProgram* program, rage::scrThreadContext* ctx);
}
namespace rage
{
	class CPlayerSyncTree
	{
	public:
		char pad_0000[8]; //0x0000
		netObject* player_object; //0x0008
		char pad_0010[256]; //0x0010
	}; //Size: 0x0110

	class CNetworkSyncDataULBase
	{
	public:
		virtual ~CNetworkSyncDataULBase() = default;

		inline virtual void m_8() { }
		inline virtual void m_10() { }
		inline virtual void m_18() { }
		inline virtual void m_20() { }
		inline virtual void m_28() { }
		inline virtual void m_30() { }
		inline virtual void m_38() { }
		inline virtual void m_40() { }
		inline virtual void m_48() { }
		inline virtual void m_50() { }
		inline virtual void SetCloningFrequency(int player, int frequency) { }

	public:
		uint8_t pad_10h[49];
		uint8_t ownerId;
		uint8_t nextOwnerId;
		uint8_t isRemote;
		uint8_t wantsToDelete : 1; // netobj+76
		uint8_t unk1 : 1;
		uint8_t shouldNotBeDeleted : 1;
		uint8_t pad_4Dh[3];
		uint8_t pad_50h[32];
		uint32_t creationAckedPlayers; // netobj+112
		uint32_t m64;
		uint32_t m68;
		uint32_t m6C;

	public:
		inline bool IsCreationAckedByPlayer(int index)
		{
			return (creationAckedPlayers & (1 << index)) != 0;
		}
	};

	class netObjectMgrBase
	{
		public:
			class atDNetObjectNode : public atDNode<netObject*>
			{
			};

	public:
		virtual ~netObjectMgrBase() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update(bool) = 0;

		virtual void AddEntity(void*, void*) = 0;
		virtual void UnregisterNetworkObject_(void* unk, bool force) = 0;
		virtual void UnregisterNetworkObject(netObject* object, int reason, bool force1, bool force2) = 0;

		virtual void ChangeOwner(netObject* object, CNetGamePlayer* player, int migrationType) = 0;

		virtual void HandleJoiningPlayer(CNetGamePlayer* player) = 0;
		virtual void HandleLeavingPlayer(CNetGamePlayer* player) = 0;

		virtual void _0x50(CNetGamePlayer* player) = 0;
		virtual void _0x58() = 0;

		virtual void RegisterNetworkObject(netObject* object) = 0;

		virtual void PackCloneCreate(netObject* object, CNetGamePlayer* player, datBitBuffer* buffer) = 0;
		virtual bool PackCloneRemove(netObject* object, CNetGamePlayer* player, bool) = 0;
		virtual void PackCloneSync(netObject* object, CNetGamePlayer* player) = 0;

		//virtual void _0x78(netObject* object, void*) = 0;
		virtual void _0x80() = 0;
		virtual void _0x88() = 0;
		virtual const char* _0x90(int) = 0;

		virtual bool HandleCloneCreate(CNetGamePlayer* source, CNetGamePlayer* target, eNetObjType object_type, std::uint16_t object_id, eNetObjectFlags object_flags, void*, std::uint32_t timestamp) = 0;
		virtual void HandleCloneCreateAck(CNetGamePlayer* source, CNetGamePlayer* target, std::uint16_t object_flags, eAckCode ack_code) = 0;

		virtual int HandleCloneSync(CNetGamePlayer* source, CNetGamePlayer* target, eNetObjType object_type, std::uint16_t object_id, void*, std::uint16_t, std::uint32_t timestamp) = 0;
		virtual void HandleCloneSyncAck(CNetGamePlayer* source, CNetGamePlayer* target, void*, std::uint16_t objectId, eAckCode ack_code) = 0;

		virtual void HandleCloneRemove(CNetGamePlayer* source, CNetGamePlayer* target, std::uint16_t object_id, int) = 0;
		virtual void HandleCloneRemoveAck(CNetGamePlayer* source, CNetGamePlayer* target, std::uint16_t object_id, eAckCode ack_code) = 0;

		virtual void _0xC8() = 0;

	};

}



class CNetworkObjectMgr : public rage::netObjectMgrBase
{
public:
	rage::netObject* find_object_by_id(uint16_t object_id, bool can_delete_be_pending)
	{
		return g_GameFunctions->m_get_net_object(this, object_id, can_delete_be_pending);
	}
};


namespace rage2
{


	class netGameEvent
	{
	public:
		virtual ~netGameEvent() = default;

		virtual const char* get_name() { return 0; };
		virtual bool is_in_scope(rage::netPlayer* player) { return 0; };
		virtual bool time_to_resend(std::uint32_t time) { return 0; };
		virtual bool can_change_scope() { return 0; };

		virtual void prepare_data(datBitBuffer* buffer, rage::netPlayer* source_player, rage::netPlayer* target_player) {};
		virtual void handle_data(datBitBuffer* buffer, rage::netPlayer* source_player, rage::netPlayer* target_player) {};

		virtual bool decide(rage::netPlayer* source_player, rage::netPlayer* target_player) { return 0; };

		virtual void prepare_reply(datBitBuffer* buffer, rage::netPlayer* reply_player) {};
		virtual void handle_reply(datBitBuffer* buffer, rage::netPlayer* souce_player) {};

		virtual void prepare_extra_data(datBitBuffer* buffer, bool is_reply, rage::netPlayer* player, rage::netPlayer* player2) {};
		virtual void handle_extra_data(datBitBuffer* buffer, bool is_reply, rage::netPlayer* player, rage::netPlayer* player2) {};

	private:
		virtual void unk_0x60() {};
		virtual void unk_0x68() {};
		virtual void unk_0x70() {};
		virtual void unk_0x78() {};
	public:
		virtual bool operator==(netGameEvent const& other) { return 0; };
		virtual bool operator!=(netGameEvent const& other) { return 0; };

		virtual bool must_persist() { return 0; };
		virtual bool must_persist_when_out_of_scope() { return 0; };
		virtual bool has_timed_out() { return 0; };
	public:
		std::uint16_t m_id;          // 0x08
		bool m_requires_reply;       // 0x0A
	private:
		char m_padding1[0x05];       // 0x0B
	public:
		rage::netPlayer* m_source_player;  // 0x10
		rage::netPlayer* m_target_player;  // 0x18
		std::uint32_t m_resend_time; // 0x20
	private:
		std::uint16_t m_0x24;        // 0x24
		std::uint8_t m_0x26;         // 0x26
		std::uint8_t m_0x27;         // 0x27
		std::uint32_t m_0x28;        // 0x28
		char m_padding2[0x04];
	};
}
enum eHookState
{
	HookStateRunning, HookStateExiting,
	HookStateUnknown = -1
};	extern eHookState  g_HookState;

namespace SHVScriptManager
{
	void					WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void					MainFiber();
	void					UnloadHook();
	void					Notification(const std::string& str);
}

struct SHVscrThreadContext
{
	int ThreadId;
	uint32_t ScriptHash;
	eThreadState State;
	int IP;
	int FrameSP;
	int SP;
	float TimerA;
	float TimerB;
	float WaitTimer;
	int _mUnk1;
	int _mUnk2;
	int _f2C;
	int _f30;
	int _f34;
	int _f38;
	int _f3C;
	int _f40;
	int _f44;
	int _f48;
	int _f4C;
	int StackSize;
	int CatchIP;
	int CatchFrame;
	int CatchSP;
	int _set1;
	int FunctionDepth;
	int FunctionReturns[16];
};

struct SHVscrThread
{
	void* vTable;
	SHVscrThreadContext m_ctx;
	void* m_pStack;
	int pad0;
	int ParameterSize;
	int StaticsSize;
	int pad3;
	const char* m_pszExitMessage;
	char Name[64];
};

inline SHVscrThread* GetActiveThread2()
{
	char* moduleTls = *(char**)__readgsqword(88);
	return *reinterpret_cast<SHVscrThread**>(moduleTls + 2096);
}

inline void SetActiveThread(SHVscrThread* thread)
{
	char* moduleTls = *(char**)__readgsqword(88);

	*reinterpret_cast<SHVscrThread**>(moduleTls + 2096) = thread;
}
class SHVScript
{
public:

	inline SHVScript(void(*function)())
	{
		scriptFiber = nullptr;
		callbackFunction = function;
		wakeAt = timeGetTime();
	}

	inline ~SHVScript()
	{
		if (scriptFiber)
		{
			DeleteFiber(scriptFiber);
		}
	}

	void Tick();

	void Wait(uint32_t time);

	inline void(*GetCallbackFunction())()
	{
		return callbackFunction;
	}

private:

	HANDLE			scriptFiber;
	uint32_t		wakeAt;

	void			Run();
	void(*callbackFunction)();
};

typedef std::map<HMODULE, std::shared_ptr<SHVScript>> scriptMap;

typedef						void(*KeyboardHandler)(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow);
typedef						void(*TWndProcFn)(UINT uMsg, WPARAM wParam, LPARAM lParam);
static						std::set<KeyboardHandler> g_keyboardFunctions2;
static						std::set<TWndProcFn> g_WndProcCb;


static bool is_script_thread_good(scrThread* thread)
{
	if (!thread || !thread->m_handler)
	{
		return false;
	}
	return !*g_GameVariables->is_session_started || thread->m_handler->is_networked();
}

namespace SHVScriptManager
{
	extern bool isKeyPressedOnce(bool& bIsPressed, DWORD vk);
	extern void WndProc(HWND /*hwnd*/, UINT uMsg, WPARAM wParam, LPARAM lParam);
	extern void MainFiber2();
}

namespace Utility02
{
	/* String */
	std::wstring str_to_wstr(const std::string& string);
	std::string wstr_to_str(const std::wstring& wstring);

	/* Hash */
	constexpr unsigned char ToLowerLookupTable[256] =
	{
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
		0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
		0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
		0x40, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
		0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x5B, 0x2F, 0x5D, 0x5E, 0x5F,
		0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
		0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
		0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
		0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
		0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
		0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
		0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
		0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
		0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF,
	};

	constexpr std::uint32_t joaatc(const char* string, std::size_t length)
	{
		std::uint32_t hash = 0;

		for (std::size_t i = 0; i < length; ++i)
		{
			hash = static_cast<std::uint64_t>(hash) + ToLowerLookupTable[string[i]];
			hash = static_cast<std::uint64_t>(hash) + (hash << 10);
			hash = static_cast<std::uint64_t>(hash) ^ (hash >> 6);
		}

		hash = static_cast<std::uint64_t>(hash) + (hash << 3);
		hash = static_cast<std::uint64_t>(hash) ^ (hash >> 11);
		hash = static_cast<std::uint64_t>(hash) + (hash << 15);

		return hash;
	}

	std::uint32_t joaat(const char* string);
	std::uint32_t joaat(const std::string& string);

	/* File / Folder */
	bool				DoesFileExist(const char* name);
	const std::string	GetModuleFolder(HMODULE module, bool fullPath = false);
	const std::string	GetNamedModuleFolder(const std::string& name, bool fullPath = false);
	const std::string	GetRunningExecutableFolder();
	const std::string	GetOurModuleFolder();

	/* Module / Process Related */
	void				SetOurModuleHandle(const HMODULE module);
	const HMODULE		GetOurModuleHandle();

	const std::string	GetModuleName(const HMODULE module);
	const std::string	GetModuleNameWithoutExtension(const HMODULE module);

	bool				GetProcess(const std::string& filename, HANDLE& handle);
	DWORD				GetProcessID(const std::string& processName);
	HANDLE				StartProcessPaused(LPCTSTR lpApplicationName, PHANDLE ptr_thread);
	void				StartProcess(LPCTSTR lpApplicationName);
	void				killProcessByName(const char* filename);
	bool				CreateElevatedThread(LPTHREAD_START_ROUTINE thread);
	bool				SetPrivilege(const char* szPrivilege, bool bState = true);
	bool				Is64BitProcess(HANDLE hProc);

	/* General Misc */
	template <typename T>
	inline void SafeRelease(T*& p)
	{
		if (nullptr != p)
		{
			p->Release();
			p = nullptr;
		}
	}

	template <typename Container, typename Element>
	bool DoesVectorContain(const Container& container, const Element& element)
	{
		return std::find(std::begin(container), std::end(container), element) != std::end(container);
	}

	template<class T1, class T2>
	bool GetMapValue(const std::map<T1, T2>& input, T1 key, T2& out)
	{
		auto foundIter = input.find(key);
		if (foundIter != input.end())
		{
			out = foundIter->second;
			return true;
		}
		return false;
	}

	template<class T1, class T2>
	bool GetMapValue(const std::unordered_map<T1, T2>& input, T1 key, T2& out)
	{
		auto foundIter = input.find(key);
		if (foundIter != input.end())
		{
			out = foundIter->second;
			return true;
		}
		return false;
	}

	void playwindowsSound(const char* sound);
}

constexpr std::uint32_t operator""_joaat(const char* string, std::size_t length)
{
	return Utility02::joaatc(string, length);
}

namespace nM
{
	extern void NotifyMap(char* fmt, ...);
}

namespace m_function
{
	extern int VehicleMainWheel();
	extern int rainMain();
	extern inline void DrawChatScaleform(char* msg, const char* player_name);
	extern void SendChatMessage(char* a1);
	extern void SendTimedChatMessage(char* a1);
	extern int trafficspeed();
	extern int changeclouds();
	extern int rainaddress();
	extern int rainmenu();
	extern bool raincolor;
	extern int rain();
	extern int lastrdatachar;
	extern bool toggleoffsetrdata;
	extern int offsetrdatatoggle();
	extern int offsetrdata();
	extern int offsetdata();
	extern float FogValue;
	extern float m_FogModificationValue;
	extern void FogModification();
	extern bool turn9;
	extern bool changetheweatherbool;
	extern int changetheweather();
	extern void NoFog();
	extern void NoFogreset();
	extern void NoFog1();
	extern void NoFog2();
	extern void NoFog3();
	extern void NoFog4();
	extern void NoFog5();
	extern void NoFog6();
	extern void NoFog7();
	extern void NoFog8();
	extern void NoFog9();
	extern void NoFog10();
	extern void NoFog11();
	extern void NoFog12();
	extern void NoFog13();
	extern void NoFog14();
	extern void NoFog15();
	extern void NoFog16();
	extern void NoFog17();
	extern void NoFog18();
	extern void NoFog19();
	extern void NoFog20();
	extern void NoFog21();
	extern void NoFog22();
	extern void NoFog23();
	extern void NoFog24();
	extern void NoFog25();
	extern void NoFog26();
	extern void NoFog27();
	extern void NoFog28();
	extern void NoFog29();
	extern void NoFog30();
	extern void NoFog31();
	extern void NoFog32();
	extern void NoFog33();
	extern void NoFog34();
	extern void NoFog35();
	extern void NoFog36();
	extern void NoFog37();
	extern void NoFog38();
	extern void NoFog39();
	extern void NoFog40();
	extern void NoFog41();
	extern void NoFog42();
	extern void NoFog43();
	extern void NoFog44();
	extern void NoFog45();
	extern void NoFog46();
	extern void NoFog47();
	extern void NoFog48();
	extern void NoFog49();
	extern void NoFog50();
	extern void NoFog51();
	extern void NoFog52();
	extern void NoFog53();
	extern void NoFog54();
	extern void NoFog55();
	extern void NoFog56();
	extern void NoFog57();
	extern void NoFog58();
	extern int GetIntStats(Hash a1, int a2);
	extern void clear_fm_event_index(int index);
	extern void set_bit(int* address, int pos);
	extern void set_fm_event_index(int index);
	extern int weather;
	extern std::string GetPlayerRID(int player);
	//extern std::string GetPlayerIP(int player);
	extern bool IsRIDOnline(int rid);
	extern bool is_online;
}

class CViewPort
{
public:
	char _0x0000[0x24C];
	float fViewMatrix[0x10];
};

#include <xstring>

template<class... Args>
extern std::string format2(std::string_view fmt, const Args&... args);


template<class ...Args>
inline std::string format2(std::string_view fmt, const Args & ...args)
{
	return std::string();
}

//namespace hostsession
//{
//
//	//static void NetworkSessionHost(rage::scrNativeCallContext* src);
//	extern void NetworkSessionHost(rage::scrNativeCallContext* src);
//}
//typedef Vector4 ColorFloat;
typedef rage::fvector4 ColorFloat;
//typedef RGBA ColorInt;
struct Timecycle
{
	bool sky;
	ColorFloat sky_color;

	bool moon;
	ColorFloat moon_color;

	float stars_intensity;

};

struct Hooks
{
	//static void NetworkSessionHost(rage::scrNativeCallContext* src);
	//static bool send_net_info_to_lobby(rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4);
	//static bool send_net_info_to_lobby(rage2::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4);//rage::netPlayerData	
	static bool send_net_info_to_lobby(rage::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4);//rage::netPlayerData
	/*static void WriteVehicleProximityMigrationDataNode(rage::netObject* veh, CVehicleProximityMigrationDataNode* node);*/
	static void WriteVehicleProximityMigrationDataNode(rage::netObject* veh, CVehicleProximityMigrationDataNode* node);
};

namespace Menu_Settings2
{
	extern bool spoof_username;
	extern std::string username;

	extern bool spoof_ip;
	extern int ip_address[4];

	extern bool spoof_rockstar_id;
	extern uint64_t rockstar_id;

	extern int region_code;

	extern int pool_type;

	extern bool spoof_cheater;

	extern bool spoof_hide_god;

	extern bool spoof_rockstar_dev;
	extern bool spoof_rockstar_qa;

	extern bool spoof_crew_data;
	extern std::string crew_tag;
	extern bool rockstar_crew;
	extern bool square_crew_tag;
}
class file_manager;
inline file_manager* g_file_manager{};
class pickup_service final
{
public:
	pickup_service();
	~pickup_service();

	pickup_service(const pickup_service&) = delete;
	pickup_service(pickup_service&&) noexcept = delete;
	pickup_service& operator=(const pickup_service&) = delete;
	pickup_service& operator=(pickup_service&&) noexcept = delete;

	void give_player_ammo(const Player player) const;
	void give_player_armour(const Player player) const;
	void give_player_health(const Player player) const;
	void give_player_weapons(const Player player) const;

	void give_ammo(const int targets) const;
	void give_armour(const int targets) const;
	void give_health(const int targets) const;
	void give_weapons(const int targets) const;
};

namespace giveto
{
	extern int give_Player_ammo(int targets);
	extern int give_Player_armour(int targets);
	extern int give_Player_health(int targets);
	extern int give_Player_weapons(int targets);
}
inline pickup_service* g_pickup_service{};

enum class eGtaDataUpdateState
{
	IDLE,
	NEEDS_UPDATE,
	WAITING_FOR_ONLINE,
	UPDATING
};
class ped_item final
{
public:
	char m_name[32];
	char m_ped_type[16];
	std::uint32_t m_hash;
};
class vehicle_item final
{
public:
	char m_name[16];
	char m_display_name[32];
	char m_display_manufacturer[32];
	char m_vehicle_class[32];
	std::uint32_t m_hash;
};
class weapon_item final
{
public:
	char m_name[32];
	char m_display_name[32];
	char m_weapon_type[16];
	std::uint32_t m_hash;
	std::uint32_t m_reward_hash;
	std::uint32_t m_reward_ammo_hash;
	bool m_throwable;
};

using ped_map = std::map<std::string, ped_item>;
using vehicle_map = std::map<std::string, vehicle_item>;
using weapon_map = std::map<std::string, weapon_item>;
using string_vec = std::vector<std::string>;
class cache_header final
{
public:
	std::uint32_t m_cache_version;
	std::uint32_t m_game_version;
	float m_online_version;
	std::uint64_t m_data_size;
};
using cache_data = std::unique_ptr<std::uint8_t[]>;
class file
{
public:

	file(std::filesystem::path file_path);

	file copy(std::filesystem::path new_path);
	bool exists() const;
	const std::filesystem::path get_path() const;
	file move(std::filesystem::path new_path);

protected:
	file(file_manager* file_manager, std::filesystem::path file_path);

private:
	friend class file_manager;

	bool m_is_project_file;
	std::filesystem::path m_file_path;

};
class cache_file final
{
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name="cache_file">FileMgr file object</param>
	/// <param name="cache_version">Internal version, use this to invalidate the cache when changing the structure of the data</param>
	cache_file(file cache_file, std::uint32_t cache_version);

	/// <summary>
	/// Frees any memory used to hold the cached data.
	/// </summary>
	void free();

	/// <summary>
	/// Attempts to load the cache from disk
	/// </summary>
	/// <returns>True after successfully loading the data, false if the file didn't exist.</returns>
	bool load();

	/// <summary>
	/// Writes the cache to disk
	/// </summary>
	/// <returns></returns>
	bool write() const;

	std::uint8_t* data() const;
	std::uint64_t data_size() const;

	/// <summary>
	/// Check if the cache file is up to date with the expected versions
	/// </summary>
	/// <param name="game_version">Current Game version</param>
	/// <param name="online_version">Current Online version</param>
	/// <returns>True if cache is up to date, false otherwise.</returns>
	bool up_to_date(std::uint32_t game_version, float online_version) const;


	void set_data(cache_data&& data, std::uint64_t data_size);
	/// <summary>
	/// Sets the version information of the cache header.
	/// </summary>
	/// <param name="game_version">Game Build</param>
	/// <param name="online_version">Online Version</param>
	void set_header_version(std::uint32_t game_version, float online_version);

private:
	file m_cache_file;

	std::uint32_t m_cache_version;

	cache_header m_cache_header;
	cache_data m_data;
};

class folder
{

public:
	folder(std::filesystem::path folder_path);

	file get_file(std::filesystem::path file_path) const;
	const std::filesystem::path get_path() const;

protected:
	folder(file_manager* file_manager, std::filesystem::path file_path);

private:

	friend class file_manager;
	file_manager* m_file_manager;

	bool m_is_project_file;

	std::filesystem::path m_folder_path;

};

class file_manager final
{
public:

	file_manager(std::filesystem::path base_dir)
		: m_base_dir(base_dir)
	{
		file_manager::ensure_folder_exists(m_base_dir);

		g_file_manager = this;
	}
	~file_manager()
	{
		g_file_manager = nullptr;
	}

	std::filesystem::path get_base_dir()
	{
		return m_base_dir;
	}

	file get_project_file(std::filesystem::path file_path)
	{
		if (file_path.is_absolute())
			throw std::exception("Project files are relative to the BaseDir, don't use absolute paths!");

		return file(this, file_path);
	}
	folder get_project_folder(std::filesystem::path folder_path)
	{
		if (folder_path.is_absolute())
			throw std::exception("Project folders are relative to the BaseDir, don't use absolute paths!");

		return folder(this, folder_path);
	}

	static std::filesystem::path ensure_file_can_be_created(const std::filesystem::path file_path)
	{
		file_manager::ensure_folder_exists(file_path.parent_path());

		return file_path;
	}
	static std::filesystem::path ensure_folder_exists(const std::filesystem::path folder_path)
	{
		bool create_path = !std::filesystem::exists(folder_path);

		if (!create_path && !std::filesystem::is_directory(folder_path))
		{
			std::filesystem::remove(folder_path);
			create_path = true;
		}
		if (create_path)
			std::filesystem::create_directory(folder_path);

		return folder_path;
	}

private:
	std::filesystem::path m_base_dir;

};

class gta_data_service final
{
public:
	gta_data_service();
	~gta_data_service();

	bool cache_needs_update() const;
	eGtaDataUpdateState state() const;
	void update_in_online();
	void update_now();

	const ped_item& ped_by_hash(std::uint32_t hash);
	const vehicle_item& vehicle_by_hash(std::uint32_t hash);
	const weapon_item& weapon_by_hash(std::uint32_t hash);

	string_vec& ped_types();
	string_vec& vehicle_classes();
	string_vec& weapon_types();

	ped_map& peds()
	{
		return m_peds;
	}
	vehicle_map& vehicles()
	{
		return m_vehicles;
	}
	weapon_map& weapons()
	{
		return m_weapons;
	}

private:
	bool is_cache_up_to_date();

	void load_data();
	void load_peds();
	void load_vehicles();
	void load_weapons();

	void rebuild_cache();

private:
	cache_file m_peds_cache;
	cache_file m_vehicles_cache;
	cache_file m_weapons_cache;

	// std::map is free sorting algo
	ped_map m_peds;
	vehicle_map m_vehicles;
	weapon_map m_weapons;

	string_vec m_ped_types;
	string_vec m_vehicle_classes;
	string_vec m_weapon_types;

	eGtaDataUpdateState m_update_state;

private:
	static constexpr ped_item empty_ped{};
	static constexpr vehicle_item empty_vehicle{};
	static constexpr weapon_item empty_weapon{};

};

inline gta_data_service* g_gta_data_service{};
using file_contents_callback = std::function<void(const std::unique_ptr<std::uint8_t[]>& file_content, const int data_size)>;

namespace Bypass
{
	extern int bypassoff();
	extern int bypasson();
}

class handle
{
public:
	handle(void* ptr = nullptr);
	explicit handle(std::uintptr_t ptr);

	template <typename T>
	std::enable_if_t<std::is_pointer_v<T>, T> as();

	template <typename T>
	std::enable_if_t<std::is_lvalue_reference_v<T>, T> as();

	template <typename T>
	std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> as();

	template <typename T>
	handle add(T offset);

	template <typename T>
	handle sub(T offset);

	handle rip();

	explicit operator bool();

	friend bool operator==(handle a, handle b);
	friend bool operator!=(handle a, handle b);
private:
	void* ptr;
};

inline handle::handle(void* ptr) :
	ptr(ptr)
{}

inline handle::handle(std::uintptr_t ptr) :
	ptr(reinterpret_cast<void*>(ptr))
{}

template <typename T>
inline std::enable_if_t<std::is_pointer_v<T>, T> handle::as()
{
	return static_cast<T>(ptr);
}

template <typename T>
inline std::enable_if_t<std::is_lvalue_reference_v<T>, T> handle::as()
{
	return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(ptr);
}

template <typename T>
inline std::enable_if_t<std::is_same_v<T, std::uintptr_t>, T> handle::as()
{
	return reinterpret_cast<std::uintptr_t>(ptr);
}

template <typename T>
inline handle handle::add(T offset)
{
	return handle(as<std::uintptr_t>() + offset);
}

template <typename T>
inline handle handle::sub(T offset)
{
	return handle(as<std::uintptr_t>() - offset);
}

inline handle handle::rip()
{
	return add(as<std::int32_t&>()).add(4);
}

inline bool operator==(handle a, handle b)
{
	return a.ptr == b.ptr;
}

inline bool operator!=(handle a, handle b)
{
	return a.ptr != b.ptr;
}

inline handle::operator bool()
{
	return ptr != nullptr;
}

class handle;
class range;
class module;
class pattern2;
class pattern_batch;

class pattern2
{
	friend pattern_batch;
	friend range;
public:
	pattern2(std::string_view ida_sig);
	explicit pattern2(const void* bytes, std::string_view mask);

	inline pattern2(const char* ida_sig) :
		pattern2(std::string_view(ida_sig))
	{}
private:
	std::vector<std::optional<std::uint8_t>> m_bytes;
};

class range
{
public:
	range(handle base, std::size_t size);

	handle begin();
	handle end();
	std::size_t size();

	bool contains(handle h);

	handle scan(pattern2 const& sig);
	std::vector<handle> scan_all(pattern2 const& sig);
protected:
	handle m_base;
	std::size_t m_size;
};

class batch
{
public:
	explicit batch() = default;
	~batch() noexcept = default;

	void add(std::string name, pattern2 pattern2, std::function<void(handle)> callback);
	void run(range region);

	struct entry
	{
		std::string m_name;
		pattern2 m_pattern;
		std::function<void(handle)> m_callback;

		explicit entry(std::string name, pattern2 pattern2, std::function<void(handle)> callback) :
			m_name(std::move(name)),
			m_pattern(std::move(pattern2)),
			m_callback(std::move(callback))
		{}
	};

private:
	std::vector<entry> m_entries;
};
class module : public range
{
public:
	explicit module(const std::string_view name);

	/**
	 * @brief Get the export address of the current module given a symbol name
	 *
	 * @param symbol_name
	 * @return memory::handle
	 */
	handle get_export(std::string_view symbol_name);

	bool loaded() const;
	/**
	 * @brief Waits till the given module is loaded.
	 *
	 * @param time Time to wait before giving up.
	 * @return true
	 * @return false
	 */
	bool wait_for_module(std::optional<std::chrono::high_resolution_clock::duration> time = std::nullopt);

protected:
	bool try_get_module();

private:
	const std::string_view m_name;
	bool m_loaded;

};

namespace hkcrash
{
	extern uint64_t hk_nigger_crash(uint64_t data);
}

class CWaterDataItem
{
public:
	__int16 iMinX; //0x0000 X Coord 1
	__int16 iMinY; //0x0002  Y Coord 1
	__int16 iMaxX; //0x0004 X Coord 2
	__int16 iMaxY; //0x0006 Y Coord 2
	__int8 iAlphaSW; //0x0008  (South West, default 26)
	__int8 iAlphaSE; //0x0009  (South East, default 26)
	__int8 iAlphaNW; //0x000A  (North West, default 26)
	__int8 iAlphaNE; //0x000B  (North East, default 26)
	char _0x000C[8]; // (Unknown, appear to be two floats?)
	float fHeight; //0x0014 (Z-Height, default 0.0)
	BYTE bHasLimitedDepth; //0x0018  (Second bit [binary 10] = On, gives the water quad an effective range of 6 z-points)
	char _0x0019[3]; // (Unknown)
};//Size=0x001C

class CWaterTune
{
public:
	DWORD dwWaterColor; //0x0000  Default: 0x1A00191C
	float fRippleScale; //0x0004  Default: 0.040000f
	float fOceanFoamScale; //0x0008  Default: 0.050000f
	float fSpecularFalloff; //0x000C  Default: 1118.000000f
	float fFodPierceIntensity; //0x0010  Default: 1.100000f
	float fRefractionBlend; //0x0014  Default: 0.700000f
	float fRefractionExponent; //0x0018  Default: 0.250000f
	float fWaterCycleDepth; //0x001C  Default: 10.000000f
	float fWaterCycleFade; //0x0020  Default: 50.000000f
	float fWaterLightningDepth; //0x0024  Default: 0.000000f
	float fWaterLightningFade; //0x0028  Default: 10.000000f
	float fDeepWaterModDepth; //0x002C  Default: 90.000000f
	float fDeepWaterModFade; //0x0030  Default: 80.000000f
	float fGodRaysLerpStart; //0x0034  Default: 0.000000f
	float fGodRaysLerpEnd; //0x0038  Default: 200.000000f
	float fDisturbFoamScale; //0x003C  Default: 0.050000f
	Vector2 vec2FogMin; //0x0040  Default: x = -4000.000000 y = -4000.000000
	Vector2 vec2FogMax; //0x0048  Default: x = 4500.000000 y= 8000.000000
};//Size=0x0050

class CWaterData
{
public:
	char _0x0000[392];
	CWaterDataItem aWaterQuads[821]; //0x0188 (Should be consistantly 821 records)

};//Size=0x2258

namespace waterchange
{
	extern void ChangeWater();
	extern void GetWaterTune();
}

namespace engine
{
	inline void nop(uint64_t address, uint32_t size) {
		uint32_t old;
		VirtualProtect((void*)address, size, PAGE_EXECUTE_READWRITE, (DWORD*)&old);
		memset((void*)address, 0x90, size);
		VirtualProtect((void*)address, size, old, (DWORD*)&old);
	}

	inline uintptr_t scan_address(uintptr_t ptr, std::vector<unsigned int> offsets)
	{
		uintptr_t addr = ptr;
		for (unsigned int i = 0; i < offsets.size(); ++i)
		{
			addr = *(uintptr_t*)addr;
			addr += offsets[i];
		}
		return addr;
	}
}

namespace vars
{
	struct variables {
		float m_azimuth_east_red;
		float m_azimuth_east_green;
		float m_azimuth_east_blue;
		float m_azimuth_east_intensity = 1.0f;
		bool m_azimuth_east_rainbow = false;

		float m_azimuth_west_red;
		float m_azimuth_west_green;
		float m_azimuth_west_blue;
		float m_azimuth_west_intensity = 1.0f;
		bool m_azimuth_west_rainbow = false;

		float m_azimuth_transition_red;
		float m_azimuth_transition_green;
		float m_azimuth_transition_blue;
		float m_azimuth_transition_intensity = 1.0f;
		bool m_azimuth_transition_rainbow = false;

		float m_zenith_red;
		float m_zenith_green;
		float m_zenith_blue;
		float m_zenith_intensity = 1.0f;
		bool m_zenith_rainbow = false;

		float m_zenith_transition_red;
		float m_zenith_transition_green;
		float m_zenith_transition_blue;
		float m_zenith_transition_intensity = 1.0f;
		bool m_zenith_transition_rainbow = false;

		float m_cloud_mid_red;
		float m_cloud_mid_green;
		float m_cloud_mid_blue;
		float m_cloud_mid_intensity = 1.0f;
		bool m_cloud_mid_rainbow = false;

		float m_cloud_base_red;
		float m_cloud_base_green;
		float m_cloud_base_blue;
		float m_cloud_base_intensity = 1.0f;
		bool m_cloud_base_rainbow = false;
	};

	extern variables m_vars;
}
struct CWaterQuad
{
	short MinX;   // 0x0
	short MinY;   // 0x2
	short MaxX;   // 0x4
	short MaxY;   // 0x6
	uint Color;   // 0x8
	char unk1[4]; // 0xC
	char unk2[4]; // 0x10
	float Z;      // 0x14
	uint Flags;   // 0x18
};

namespace gta_util
{
	inline CPed* get_local_ped()
	{
		if (auto ped_factory = *g_GameVariables->m_ped_factory)
		{
			return ped_factory->m_local_ped;
		}

		return nullptr;
	}

	inline CVehicle* get_local_vehicle()
	{
		if (const auto ped = get_local_ped(); ped)
		{
			if (const auto veh = ped->m_vehicle; veh)
			{
				return veh;
			}
		}
		return nullptr;
	}

	inline CPlayerInfo* get_local_playerinfo()
	{
		if (auto ped_factory = *g_GameVariables->m_ped_factory)
		{
			if (auto ped = ped_factory->m_local_ped)
			{
				return ped->m_player_info;
			}
		}

		return nullptr;
	}

	inline CNetworkPlayerMgr* get_network_player_mgr()
	{
		//return *g_GameVariables->m_network_player_mgr;
		return *g_GameVariables->m_NetworkPlayerMgr;
	}

	inline Network* get_network()
	{
		return *g_GameVariables->m_Network;
	}

	template <typename F, typename ...Args>
	void execute_as_script(rage::joaat_t script_hash, F&& callback, Args &&...args)
	{
		/*auto tls_ctx = tlsContextz::get();*/
		auto tls_ctx = tlsContext::get();
		/*	for (auto thread : *g_GameVariables->script_threads)*/
		for (auto thread : *g_GameVariables->m_scriptThreads)//m_script_threads
		{
			if (!thread || !thread->m_context.m_thread_id || thread->m_context.m_script_hash != script_hash)
				continue;

			auto og_thread = tls_ctx->m_script_thread;

			tls_ctx->m_script_thread = thread;
			tls_ctx->m_is_script_thread_active = true;

			std::invoke(std::forward<F>(callback), std::forward<Args>(args)...);

			tls_ctx->m_script_thread = og_thread;
			tls_ctx->m_is_script_thread_active = og_thread != nullptr;

			return;
		}
	}



	inline GtaThread* find_script_thread(joaat_t hash)
	{
		for (auto thread : *g_GameVariables->m_scriptThreads)
		{
			if (thread
				&& thread->m_context.m_thread_id
				&& thread->m_handler
				&& thread->m_script_hash == hash)
			{
				return thread;
			}
		}

		return nullptr;
	}

	static rage::scrProgram* find_script_program(rage::joaat_t hash)
	{
		for (auto& script : *g_GameVariables->m_ScriptProgramTable/*m_script_program_table*/)
		{
			if (script.m_program && script.m_program->m_name_hash == hash)
				return script.m_program;
		}

		return nullptr;
	}
}
/*class player_service;*/
//namespace Thunder2
//{
	//class player;

enum class CommandAccessLevel
{
	NONE,
	FRIENDLY, // heal, semi godmode...
	AGGRESSIVE, // kick from vehicle, send to apartment...
	TOXIC, // kicks
	ADMIN // full access
};



/*class player;*/
class player final
{
public:
	player() {} // Constructeur par défaut
	using player_ptr = std::shared_ptr<player>;
	//player() = default;
	friend class player_service;

	/*CNetGamePlayer2* m_net_game_player = nullptr;*/
	CNetGamePlayer* m_net_game_player = nullptr;
	std::string m_identifier;
	bool m_is_friend;


	/*explicit player(CNetGamePlayer2* net_game_player);*/
	explicit player(CNetGamePlayer* net_game_player);
	~player() = default;

	player(const player&) = default;
	player(player&&) noexcept = default;
	player& operator=(const player&) = default;
	player& operator=(player&&) noexcept = default;

	float screen_position_x = -1.f;
	float screen_position_y = -1.f;

	[[nodiscard]] CVehicle* get_current_vehicle() const;
	[[nodiscard]] const char* get_name() const;
	[[nodiscard]] rage::rlGamerInfo* get_net_data() const;
	[[nodiscard]] int64_t get_rockstar_id() const;
	/*[[nodiscard]] CNetGamePlayer2* get_net_game_player() const;*/
	[[nodiscard]] CNetGamePlayer* get_net_game_player() const;
	[[nodiscard]] CPed* get_ped() const;
	[[nodiscard]] CPlayerInfo* get_player_info() const;
	[[nodiscard]] class rage::snPlayer* get_session_player();
	[[nodiscard]] class rage::snPeer* get_session_peer();
	/*[[nodiscard]] class snPlayer* get_session_player(int player);
	[[nodiscard]] class snPeer* get_session_peer(int player);*/

	[[nodiscard]] class netConnectionPeer* get_connection_peer();
	[[nodiscard]] std::optional<netAddress> get_ip_address();
	[[nodiscard]] uint16_t get_port();

	[[nodiscard]] uint8_t id() const;

	[[nodiscard]] bool is_friend() const;
	[[nodiscard]] bool is_host() const;
	[[nodiscard]] bool is_valid() const;

	std::optional<CommandAccessLevel> command_access_level = std::nullopt;

	bool off_radar = false;
	bool never_wanted = false;
	bool semi_godmode = false;

	bool kill_loop = false;
	bool explosion_loop = false;
	bool freeze_loop = false;
	bool ragdoll_loop = false;
	bool rotate_cam_loop = false;

	/*rate_limiter m_host_migration_rate_limit{ 1s, 20 };
	rate_limiter m_play_sound_rate_limit{ 1s, 10 };
	rate_limiter m_invites_rate_limit{ 10s, 2 };*/

	bool exposed_desync_protection = false;
	bool is_modder = false;
	bool block_join = false;
	int block_join_reason = 0;
	bool is_spammer = false;

	std::optional<std::uint32_t> player_time_value;
	std::optional<std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds>> player_time_value_received_time;
	std::optional<std::uint32_t> time_difference;
	std::uint32_t num_time_syncs_sent = 9999;

protected:
	/*bool equals(const CNetGamePlayer2* net_game_player) const;*/
	bool equals(const CNetGamePlayer* net_game_player) const;

	[[nodiscard]] std::string to_lowercase_identifier() const;

};
/*using player_ptr = std::shared_ptr<player>;
using player_entry = std::pair<std::string, player_ptr>;*/

//using player_ptr = std::shared_ptr<player2>;
//}
/*class player2 final*/



using player_entry = std::pair<std::string, player::player_ptr>;
using playersz = std::multimap<std::string, player::player_ptr>;
using PlayerPtr = player::player_ptr;
//using player_ptr = std::shared_ptr<player>;
//using player_entry = std::pair<std::string, player_ptr>;
//using playersz = std::multimap<std::string, player_ptr>;



class friends_service2 final
{
public:
	friends_service2();
	~friends_service2();

	friends_service2(const friends_service2&) = delete;
	friends_service2(friends_service2&&) noexcept = delete;
	friends_service2& operator=(const friends_service2&) = delete;
	friends_service2& operator=(friends_service2&&) noexcept = delete;

	/*[[nodiscard]] static bool is_friend(CNetGamePlayer2* net_player);*/
	[[nodiscard]] static bool is_friend(CNetGamePlayer* net_player);
};

inline friends_service2* g_friends_service{};


class player_service final
{
	//CNetGamePlayer2** m_self;
	CNetGamePlayer** m_self;
	player::player_ptr m_self_ptr;

	player::player_ptr m_dummy = std::make_shared<player>(nullptr);
	player::player_ptr m_selected_player;
	playersz m_players;
public:
	player_service();
	~player_service();

	player_service(const player_service&) = delete;
	player_service(player_service&&) noexcept = delete;
	player_service& operator=(const player_service&) = delete;
	player_service& operator=(player_service&&) noexcept = delete;

	void do_cleanup();

	[[nodiscard]] player::player_ptr get_self();

	[[nodiscard]] player::player_ptr get_by_msg_id(uint32_t msg_id) const;
	[[nodiscard]] player::player_ptr get_by_id(uint32_t id) const;
	[[nodiscard]] player::player_ptr get_by_host_token(uint64_t token) const;
	[[nodiscard]] player::player_ptr get_selected() const;

	/*[[nodiscard]] player_ptr get_by_name(const std::string_view name) const;
	[[nodiscard]] player_ptr get_by_name_closest(const std::string_view name) const;
	[[nodiscard]] player_ptr get_closest(bool exclude_friends = false) const;*/
	[[nodiscard]] player::player_ptr get_by_name(std::string_view name) const;
	[[nodiscard]] player::player_ptr get_by_name_closest(std::string_view name) const;
	[[nodiscard]] player::player_ptr get_closest(bool exclude_friends = false) const;

	/*void player_join(CNetGamePlayer2* net_game_player);
	void player_leave(CNetGamePlayer2* net_game_player)*/
	void player_join(CNetGamePlayer* net_game_player);
	void player_leave(CNetGamePlayer* net_game_player);
	playersz& players()
	{
		return m_players;
	}

	void iterate(const std::function< void(const player_entry& entry)> func)
	{
		for (const auto& iter : m_players) func(iter);
	}

	void set_selected(player::player_ptr plyr);

	std::optional<player::player_ptr> m_player_to_use_end_session_kick = std::nullopt;
	std::optional<player::player_ptr> m_player_to_use_complaint_kick = std::nullopt;
};
inline player_service* g_player_service{};

static rage::snPlayer* get_session_player(int player)
{
	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
		{
			return GetNetwork()->m_game_session_ptr->m_players[i];
		}

		if (GetNetwork()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_host_token)
			return &GetNetwork()->m_game_session_ptr->m_local_player;
	}

	return nullptr;
}

static rage::snPeer* get_session_peer(int player)
{
	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_peer_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle.m_rockstar_id == g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle.m_rockstar_id)
		{
			return GetNetwork()->m_game_session_ptr->m_peers[i];
		}
	}
	return nullptr;
}

static netAddress GetIPAddress(int player)
{
	if ((player == PLAYER::PLAYER_ID()) && (g_GameVariables->m_GetNetPlayer(PLAYER::PLAYER_ID()) != nullptr))
	{
		return g_GameVariables->m_GetNetPlayer(PLAYER::PLAYER_ID())->get_net_data()->m_external_ip;
	}
	if (auto session_player = get_session_player(player))
	{
		if (auto peer = g_GameFunctions->m_GetConnectionPeer(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, (int)get_session_player(player)->m_player_data.m_peer_id_2))
		{
			return netAddress{ ((netConnectionPeer*)peer)->m_external_ip };
		}
	}
	return { 0 };
}

static void BreakupKick(int target)
{
	rage::snMsgRemoveGamersFromSessionCmd cmd{};
	cmd.m_session_id = (*g_GameVariables->m_Network)->m_game_session_ptr->m_rline_session.m_session_id;
	cmd.m_num_peers = 1;
	///*cmd.m_peer_ids[0]*/cmd.m_handles[0] = g_GameVariables->m_GetNetPlayer(target)->get_net_data()->m_gamer_handle;/*get_session_peer(target)->m_peer_data.m_peer_id_2;*/
	cmd.m_handles[0] = g_GameVariables->m_GetNetPlayer(target)->get_net_data()->m_gamer_handle/*get_session_peer(target)->m_peer_data.m_peer_id_2*/;
	cmd.m_unk = 19;

	if (GetNetwork()->m_game_session.is_host())
	{
		g_GameFunctions->m_HandleRemoveGamerCmd((*g_GameVariables->m_Network)->m_game_session_ptr, get_session_player(target), &cmd);
	}
	else
	{
		for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
		{
			if (i != target)
				g_GameFunctions->m_SendRemoveGamerCmd(
					(*g_GameVariables->m_Network)->m_game_session_ptr->m_net_connection_mgr,
					//g_GameFunctions->m_GetConnectionPeer((*g_GameVariables->m_Network)->m_game_session_ptr->m_net_connection_mgr, (int)GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_peer_id_2),
					g_GameFunctions->m_GetConnectionPeer(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, (int)GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_peer_id_2),

					(*g_GameVariables->m_Network)->m_game_session_ptr->m_connection_identifier, &cmd, 0x1000000);
		}
		g_GameFunctions->m_HandleRemoveGamerCmd((*g_GameVariables->m_Network)->m_game_session_ptr, get_session_player(target), &cmd);
	}
}

class command_context
{
public:
	virtual player::player_ptr get_sender() const = 0;
	virtual CommandAccessLevel get_access_level() const = 0;
	virtual void report_output(const std::string& output) const = 0;
	virtual void report_error(const std::string& error) const = 0;
};
enum class eNetMessage : uint32_t
{
	MsgInvalid = 0xFFFFF,
	MsgSessionAcceptChat = 0x62,
	MsgStartMatchCmd = 0x2D,
	MsgSetInvitableCmd = 0x1F,
	MsgSessionMemberIds = 0x23,
	MsgRequestGamerInfo = 0x54,
	MsgRemoveGamersFromSessionCmd = 0x53,
	MsgNotMigrating = 0x35,
	MsgMigrateHostResponse = 0x12,
	MsgMigrateHostRequest = 0x66,
	MsgJoinResponse = 0x2A,
	MsgJoinRequest = 0x41,
	MsgHostLeftWhilstJoiningCmd = 0x58,
	MsgConfigResponse = 0x5F,
	MsgConfigRequest = 0x48,
	MsgChangeSessionAttributesCmd = 0x5A,
	MsgAddGamerToSessionCmd = 0x64, // this is where send net info to lobby is called, among other things
	MsgReassignResponse = 0x10,
	MsgReassignNegotiate = 0x01,
	MsgReassignConfirm = 0x26,
	MsgPlayerData = 0x18,
	MsgPackedReliables = 0x30,
	MsgPackedCloneSyncACKs = 0x3B,
	MsgNonPhysicalData = 0x16,
	MsgNetArrayMgrUpdateAck = 0x5D,
	MsgNetArrayMgrUpdate = 0x60,
	MsgNetArrayMgrSplitUpdateAck = 0x25,
	MsgScriptVerifyHostAck = 0x0B,
	MsgScriptVerifyHost = 0x3E,
	MsgScriptNewHost = 0x0E,
	MsgScriptMigrateHostFailAck = 0x1A,
	MsgScriptMigrateHost = 0x33,
	MsgScriptLeaveAck = 0x40,
	MsgScriptLeave = 0x17,
	MsgScriptJoinHostAck = 0x4D,
	MsgScriptJoinAck = 0x43,
	MsgScriptJoin = 0x5C,
	MsgScriptHostRequest = 0x67,
	MsgScriptHandshakeAck = 0x5B,
	MsgScriptHandshake = 0x57,
	MsgScriptBotLeave = 0x2B, // unused?
	MsgScriptBotJoinAck = 0x63, // unused?
	MsgScriptBotJoin = 0x1C, // unused?
	MsgScriptBotHandshakeAck = 0x31, // unused?
	MsgScriptBotHandshake = 0x4B, // unused?
	MsgPartyLeaveGame = 0x3D,
	MsgPartyEnterGame = 0x1E,
	MsgCloneSync = 0x4E, // aka clone_create, clone_sync etc.
	MsgActivateNetworkBot = 0x65, // unused?
	MsgRequestObjectIds = 0x29,
	MsgInformObjectIds = 0x09,
	MsgTextMessage = 0x24, // this one is for chat
	MsgPlayerIsTyping = 0x61,
	MsgPackedEvents = 0x4F, // aka received_event
	MsgPackedEventReliablesMsgs = 0x20,
	MsgRequestKickFromHost = 0x0D,
	MsgTransitionToGameStart = 0x50,
	MsgTransitionToGameNotify = 0x02,
	MsgTransitionToActivityStart = 0x06,
	MsgTransitionToActivityFinish = 0x36,
	MsgTransitionParameters = 0x3C,
	MsgTransitionParameterString = 0x37,
	MsgTransitionLaunchNotify = 0x1B,
	MsgTransitionLaunch = 0x19,
	MsgTransitionGamerInstruction = 0x14,
	MsgTextMessage2 = 0x0A, // this one is for phone message
	MsgSessionEstablishedRequest = 0x52,
	MsgSessionEstablished = 0x07,
	MsgRequestTransitionParameters = 0x42,
	MsgRadioStationSyncRequest = 0x47,
	MsgRadioStationSync = 0x46,
	MsgPlayerCardSync = 0x3A,
	MsgPlayerCardRequest = 0x6A,
	MsgLostConnectionToHost = 0x81,
	MsgKickPlayer = 0x34, // host kick
	MsgDebugStall = 0x7E, // unused?
	MsgCheckQueuedJoinRequestReply = 0x59,
	MsgCheckQueuedJoinRequest = 0x51,
	MsgBlacklist = 0x0C,
	MsgRoamingRequestBubbleRequiredResponse = 0x83,
	MsgRoamingRequestBubbleRequiredCheck = 0x82,
	MsgRoamingRequestBubble = 0x2E,
	MsgRoamingJoinBubble = 0x4C,
	MsgRoamingJoinBubbleAck = 0x3F,
	MsgRoamingInitialBubble = 0x32,
	MsgVoiceStatus = 0x03,
	MsgTextChatStatus = 0x00,
	MsgJoinResponse2 = 0x08,
	MsgJoinRequest2 = 0x68,
	MsgNetTimeSync = 0x38, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 37
	MsgNetComplaint = 0x55, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 54
	MsgNetLagPing = 0x27, // unused? ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 26
	MsgSearchResponse = 0x6B, // unused? ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 6A
	MsgSearchRequest = 0x05, // unused?
	MsgQosProbeResponse = 0x2C, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 2B
	MsgQosProbeRequest = 0x1D, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 1C
	MsgCxnRelayAddressChanged = 0x49, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 48
	MsgCxnRequestRemoteTimeout = 0x2F, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 2E
	MsgSessionDetailRequest = 0x22, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 21
	MsgSessionDetailResponse = 0x13, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 12
	MsgKeyExchangeOffer = 0x0F, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 0E (last result)
	MsgKeyExchangeAnswer = 0x44, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 43
	Msg_0x87 = 0x87,
	Msg_0x88 = 0x88,
	Msg_0x80 = 0x80,
	Msg_0x28 = 0x28,
	Msg_0x11 = 0x11,
	Msg_0x45 = 0x45,
	Msg_0x89 = 0x89,
	Msg_0x86 = 0x86,	
	MsgBattlEyeCmd = 0x8F,
};
//enum class eNetMessage : uint32_t
//{
//	MsgInvalid = 0xFFFFF,
//	MsgSessionAcceptChat = 0x62,
//	MsgStartMatchCmd = 0x2D,
//	MsgSetInvitableCmd = 0x1F,
//	MsgSessionMemberIds = 0x23,
//	MsgRequestGamerInfo = 0x54,
//	MsgRemoveGamersFromSessionCmd = 0x53,
//	MsgNotMigrating = 0x35,
//	MsgMigrateHostResponse = 0x12,
//	MsgMigrateHostRequest = 0x66,
//	MsgJoinResponse = 0x2A,
//	MsgJoinRequest = 0x41,
//	MsgHostLeftWhilstJoiningCmd = 0x58,
//	MsgConfigResponse = 0x5F,
//	MsgConfigRequest = 0x48,
//	MsgChangeSessionAttributesCmd = 0x5A,
//	MsgAddGamerToSessionCmd = 0x64, // this is where send net info to lobby is called, among other things
//	MsgReassignResponse = 0x10,
//	MsgReassignNegotiate = 0x01,
//	MsgReassignConfirm = 0x26,
//	MsgPlayerData = 0x18,
//	MsgPackedReliables = 0x30,
//	MsgPackedCloneSyncACKs = 0x3B,
//	MsgNonPhysicalData = 0x16,
//	MsgNetArrayMgrUpdateAck = 0x5D,
//	MsgNetArrayMgrUpdate = 0x60,
//	MsgNetArrayMgrSplitUpdateAck = 0x25,
//	MsgScriptVerifyHostAck = 0x0B,
//	MsgScriptVerifyHost = 0x3E,
//	MsgScriptNewHost = 0x0E,
//	MsgScriptMigrateHostFailAck = 0x1A,
//	MsgScriptMigrateHost = 0x33,
//	MsgScriptLeaveAck = 0x40,
//	MsgScriptLeave = 0x17,
//	MsgScriptJoinHostAck = 0x4D,
//	MsgScriptJoinAck = 0x43,
//	MsgScriptJoin = 0x5C,
//	MsgScriptHostRequest = 0x67,
//	MsgScriptHandshakeAck = 0x5B,
//	MsgScriptHandshake = 0x57,
//	MsgScriptBotLeave = 0x2B, // unused?
//	MsgScriptBotJoinAck = 0x63, // unused?
//	MsgScriptBotJoin = 0x1C, // unused?
//	MsgScriptBotHandshakeAck = 0x31, // unused?
//	MsgScriptBotHandshake = 0x4B, // unused?
//	MsgPartyLeaveGame = 0x3D,
//	MsgPartyEnterGame = 0x1E,
//	MsgCloneSync = 0x4E, // aka clone_create, clone_sync etc.
//	MsgActivateNetworkBot = 0x65, // unused?
//	MsgRequestObjectIds = 0x29,
//	MsgInformObjectIds = 0x09,
//	MsgTextMessage = 0x24, // this one is for chat
//	MsgPlayerIsTyping = 0x61,
//	MsgPackedEvents = 0x4F, // aka received_event
//	MsgPackedEventReliablesMsgs = 0x20,
//	MsgRequestKickFromHost = 0x0D,
//	MsgTransitionToGameStart = 0x50,
//	MsgTransitionToGameNotify = 0x02,
//	MsgTransitionToActivityStart = 0x06,
//	MsgTransitionToActivityFinish = 0x36,
//	MsgTransitionParameters = 0x3C,
//	MsgTransitionParameterString = 0x37,
//	MsgTransitionLaunchNotify = 0x1B,
//	MsgTransitionLaunch = 0x19,
//	MsgTransitionGamerInstruction = 0x14,
//	MsgTextMessage2 = 0x0A, // this one is for phone message
//	MsgSessionEstablishedRequest = 0x52,
//	MsgSessionEstablished = 0x07,
//	MsgRequestTransitionParameters = 0x42,
//	MsgRadioStationSyncRequest = 0x47,
//	MsgRadioStationSync = 0x46,
//	MsgPlayerCardSync = 0x3A,
//	MsgPlayerCardRequest = 0x6A,
//	MsgLostConnectionToHost = 0x81,
//	MsgKickPlayer = 0x34, // host kick
//	MsgDebugStall = 0x7E, // unused?
//	MsgCheckQueuedJoinRequestReply = 0x59,
//	MsgCheckQueuedJoinRequest = 0x51,
//	MsgBlacklist = 0x0C,
//	MsgRoamingRequestBubbleRequiredResponse = 0x83,
//	MsgRoamingRequestBubbleRequiredCheck = 0x82,
//	MsgRoamingRequestBubble = 0x2E,
//	MsgRoamingJoinBubble = 0x4C,
//	MsgRoamingJoinBubbleAck = 0x3F,
//	MsgRoamingInitialBubble = 0x32,
//	MsgVoiceStatus = 0x03,
//	MsgTextChatStatus = 0x00,
//	/*MsgJoinResponse2 = 0x08,
//	MsgJoinRequest2 = 0x68,*/
//	MsgSnJoinResponse = 0x08,
//	MsgSnJoinRequest = 0x68,
//	MsgNetTimeSync = 0x38, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 37
//	MsgNetComplaint = 0x55, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 54
//	MsgNetLagPing = 0x27, // unused? ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 26
//	MsgSearchResponse = 0x6B, // unused? ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 6A
//	MsgSearchRequest = 0x05, // unused?
//	MsgQosProbeResponse = 0x2C, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 2B
//	MsgQosProbeRequest = 0x1D, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 1C
//	MsgCxnRelayAddressChanged = 0x49, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 48
//	MsgCxnRequestRemoteTimeout = 0x2F, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 2E
//	MsgSessionDetailRequest = 0x22, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 21
//	MsgSessionDetailResponse = 0x13, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 12
//	MsgKeyExchangeOffer = 0x0F, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 0E (last result)
//	MsgKeyExchangeAnswer = 0x44, // ctor 40 53 48 83 EC 20 BA ? ? ? ? 4C 8D 0D ? ? ? ? 48 8B D9 44 8D 42 43
//	Msg_0x87 = 0x87,
//	Msg_0x88 = 0x88,
//	Msg_0x80 = 0x80,
//	Msg_0x28 = 0x28,
//	/*Msg_0x11 = 0x11,*/
//	MsgNatTunnelerResponse = 0x11,
//	MsgNatTunnelerRequest = 0x15,
//	MsgNatTunnelerUnk = 0x7F,
//	Msg_0x45 = 0x45,
//	Msg_0x89 = 0x89,
//	Msg_0x86 = 0x86,
//	MsgDtlsCxnCommand = 0x8A,
//	MsgSetKickVote = 0x8E,
//	MsgTransitionHandshake = 0x8D,
//	MsgDidInvitePlayerRequest = 0x8B,
//	MsgDidInvitePlayerResponse = 0x8C,
//};
inline const static constexpr std::pair<const char*, uint32_t> packet_types[] = {
	{"MsgInvalid", -1},
	{"MsgSessionAcceptChat", 0x62},
	{"MsgStartMatchCmd", 0x2D},
	{"MsgSetInvitableCmd", 0x1F},
	{"MsgSessionMemberIds", 0x23},
	{"MsgRequestGamerInfo", 0x54},
	{"MsgRemoveGamersFromSessionCmd", 0x53},
	{"MsgNotMigrating", 0x35},
	{"MsgMigrateHostResponse", 0x12},
	{"MsgMigrateHostRequest", 0x66},
	{"MsgJoinResponse", 0x2A},
	{"MsgJoinRequest", 0x41},
	{"MsgHostLeftWhilstJoiningCmd", 0x58},
	{"MsgConfigResponse", 0x5F},
	{"MsgConfigRequest", 0x48},
	{"MsgChangeSessionAttributesCmd", 0x5A},
	{"MsgAddGamerToSessionCmd", 0x64},
	{"MsgReassignResponse", 0x10},
	{"MsgReassignNegotiate", 0x01},
	{"MsgReassignConfirm", 0x26},
	{"MsgPlayerData", 0x18},
	{"MsgPackedReliables", 0x30},
	{"MsgPackedCloneSyncACKs", 0x3B},
	{"MsgNonPhysicalData", 0x16},
	{"MsgNetArrayMgrUpdateAck", 0x5D},
	{"MsgNetArrayMgrUpdate", 0x60},
	{"MsgNetArrayMgrSplitUpdateAck", 0x25},
	{"MsgScriptVerifyHostAck", 0x0B},
	{"MsgScriptVerifyHost", 0x3E},
	{"MsgScriptNewHost", 0x0E},
	{"MsgScriptMigrateHostFailAck", 0x1A},
	{"MsgScriptMigrateHost", 0x33},
	{"MsgScriptLeaveAck", 0x40},
	{"MsgScriptLeave", 0x17},
	{"MsgScriptJoinHostAck", 0x4D},
	{"MsgScriptJoinAck", 0x43},
	{"MsgScriptJoin", 0x5C},
	{"MsgScriptHostRequest", 0x67},
	{"MsgScriptHandshakeAck", 0x5B},
	{"MsgScriptHandshake", 0x57},
	{"MsgScriptBotLeave", 0x2B},
	{"MsgScriptBotJoinAck", 0x63},
	{"MsgScriptBotJoin", 0x1C},
	{"MsgScriptBotHandshakeAck", 0x31},
	{"MsgScriptBotHandshake", 0x4B},
	{"MsgPartyLeaveGame", 0x3D},
	{"MsgPartyEnterGame", 0x1E},
	{"MsgCloneSync", 0x4E},
	{"MsgActivateNetworkBot", 0x65},
	{"MsgRequestObjectIds", 0x29},
	{"MsgInformObjectIds", 0x09},
	{"MsgTextMessage", 0x24},
	{"MsgPlayerIsTyping", 0x61},
	{"MsgPackedEvents", 0x4F},
	{"MsgPackedEventReliablesMsgs", 0x20},
	{"MsgRequestKickFromHost", 0x0D},
	{"MsgTransitionToGameStart", 0x50},
	{"MsgTransitionToGameNotify", 0x02},
	{"MsgTransitionToActivityStart", 0x06},
	{"MsgTransitionToActivityFinish", 0x36},
	{"MsgTransitionParameters", 0x3C},
	{"MsgTransitionParameterString", 0x37},
	{"MsgTransitionLaunchNotify", 0x1B},
	{"MsgTransitionLaunch", 0x19},
	{"MsgTransitionGamerInstruction", 0x14},
	{"MsgTextMessage2", 0x0A},
	{"MsgSessionEstablishedRequest", 0x52},
	{"MsgSessionEstablished", 0x07},
	{"MsgRequestTransitionParameters", 0x42},
	{"MsgRadioStationSyncRequest", 0x47},
	{"MsgRadioStationSync", 0x46},
	{"MsgPlayerCardSync", 0x3A},
	{"MsgPlayerCardRequest", 0x6A},
	{"MsgLostConnectionToHost", 0x81},
	{"MsgKickPlayer", 0x34},
	{"MsgDebugStall", 0x7E},
	{"MsgCheckQueuedJoinRequestReply", 0x59},
	{"MsgCheckQueuedJoinRequest", 0x51},
	{"MsgBlacklist", 0x0C},
	{"MsgRoamingRequestBubbleRequiredResponse", 0x83},
	{"MsgRoamingRequestBubbleRequiredCheck", 0x82},
	{"MsgRoamingRequestBubble", 0x2E},
	{"MsgRoamingJoinBubble", 0x4C},
	{"MsgRoamingJoinBubbleAck", 0x3F},
	{"MsgRoamingInitialBubble", 0x32},
	{"MsgVoiceStatus", 0x03},
	{"MsgTextChatStatus", 0x00},
	{"MsgSnJoinResponse", 0x08},
	{"MsgSnJoinRequest", 0x68},
	{"MsgNetTimeSync", 0x38},
	{"MsgNetComplaint", 0x55},
	{"MsgNetLagPing", 0x27},
	{"MsgSearchResponse", 0x6B},
	{"MsgSearchRequest", 0x05},
	{"MsgQosProbeResponse", 0x2C},
	{"MsgQosProbeRequest", 0x1D},
	{"MsgCxnRelayAddressChanged", 0x49},
	{"MsgCxnRequestRemoteTimeout", 0x2F},
	{"MsgSessionDetailRequest", 0x22},
	{"MsgSessionDetailResponse", 0x13},
	{"MsgKeyExchangeOffer", 0x0F},
	{"MsgKeyExchangeAnswer", 0x44},
	{"Msg_0x87", 0x87},
	{"Msg_0x88", 0x88},
	{"Msg_0x80", 0x80},
	{"Msg_0x28", 0x28},
	{"MsgNatTunnelerResponse", 0x11},
	{"MsgNatTunnelerRequest", 0x15},
	{"MsgNatTunnelerUnk", 0x7F},
	{"Msg_0x45", 0x45},
	{"Msg_0x89", 0x89},
	{"Msg_0x86", 0x86},
	{"MsgDtlsCxnCommand", 0x8A},
	{"MsgSetKickVote", 0x8E},
	{"MsgTransitionHandshake", 0x8D},
	{"MsgDidInvitePlayerRequest", 0x8B},
	{"MsgDidInvitePlayerResponse", 0x8C},
};

namespace rage2
{
	class packet
	{
	public:
		char m_data[0x4000]{};
		datBitBuffer m_buffer;

		packet();
		void send(uint32_t msg_id);
		void send(int player, int connection_id);

		inline operator datBitBuffer& ()
		{
			return m_buffer;
		}

		template <typename T>
		inline void write(T data, int length)
		{
			m_buffer.Write<T>(data, length);
		}

		inline void write_message(eNetMessage message)
		{
			write<int>(0x3246, 14);
			if ((int)message > 0xFF)
			{
				write<bool>(true, 1);
				write<eNetMessage>(message, 16);
			}
			else
			{
				write<bool>(false, 1);
				write<eNetMessage>(message, 8);
			}
		}

		inline void write_peer_id(std::uint64_t peer_id)
		{
			char b[8];
			datBitBuffer buf(b, 8);
			buf.WriteQWord(peer_id, 64);
			m_buffer.WriteArray(b, 8 * buf.GetDataLength());
		}
	};
}
static void gamer_handle_serialize(rage::rlGamerHandle& hnd, datBitBuffer& buf)
{
	buf.Write<uint8_t>(*reinterpret_cast<uint8_t*>(&hnd.m_platform), 8);
	if (*reinterpret_cast<uint8_t*>(&hnd.m_platform) == 3)
	{
		buf.WriteInt64(*(int64_t*)&hnd.m_rockstar_id, 64);
		buf.Write<uint8_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<__int64>(&hnd) + 9), 8);
	}
}

//virtual void GamerInstruction(player_ptr player, const std::vector<std::uint64_t>& _args, const std::shared_ptr<command_context> ctx)
static void GamerInstruction(int player)
{
	rage2::packet msg;
	msg.write_message(eNetMessage::MsgTransitionGamerInstruction);
	//gamer_handle_serialize(g_player_service->get_selected()->get_net_data()->m_gamer_handle_2, msg.m_buffer); // src
	//gamer_handle_serialize(g_player_service->get_selected()->get_net_data()->m_gamer_handle_2, msg.m_buffer); // target
	gamer_handle_serialize(g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle_2, msg.m_buffer); // src
	gamer_handle_serialize(g_GameVariables->m_GetNetPlayer(player)->get_net_data()->m_gamer_handle_2, msg.m_buffer); // target
	msg.write<bool>(false, 1); // string extend
	msg.write<int>(0, 7); // string length
	msg.write<int>(8, 32); // instruction type
	msg.write<int>(0, 32);
	msg.write<int>(0, 32);
	/*msg.send(g_player_service->get_selected(), gta_util::get_network()->m_transition_session.m_connection_identifier);*/
	msg.send(get_session_player(player)->m_player_data.m_peer_id_2, GetNetwork()->m_transition_session.m_connection_identifier);/*, true*/
}

static void GamerHandleSerialize(rage::rlGamerHandle& hnd, datBitBuffer& buf)
{
	buf.Write<uint8_t>(*reinterpret_cast<uint8_t*>(&hnd.m_platform), 8);
	if (*reinterpret_cast<uint8_t*>(&hnd.m_platform) == 3)
	{
		buf.WriteInt64(*(int64_t*)&hnd.m_rockstar_id, 64);
		buf.Write<uint8_t>(*reinterpret_cast<uint8_t*>(reinterpret_cast<__int64>(&hnd) + 9), 8);
	}
}

static std::vector<Entity> target_entities;
static void get_entities()
{
	const auto replay_interface = *g_GameVariables->m_ReplayInterface;
	if (!replay_interface)
		return;

	const auto vehicle_interface = replay_interface->m_vehicle_interface;
	for (int i = 0; i < vehicle_interface->m_max_vehicles; i++)
	{
		const auto vehicle_ptr = vehicle_interface->get_vehicle(i);
		if (!vehicle_ptr)
			continue;

		const auto veh = g_GameVariables->m_PtrToHandle(vehicle_ptr);
		if (!veh)
			break;

		target_entities.push_back(veh);
	}
}

namespace CallerNative
{

class NativeInvoker
{
public:
	explicit NativeInvoker() = default;
	~NativeInvoker() noexcept = default;
	NativeInvoker(NativeInvoker const&) = delete;
	NativeInvoker(NativeInvoker&&) = delete;
	NativeInvoker& operator=(NativeInvoker const&) = delete;
	NativeInvoker& operator=(NativeInvoker&&) = delete;

	NativeInvoker& GetInstance()
	{
		static NativeInvoker i{};

		return i;
	}

	template<typename T>
	T& GetReturnValue()
	{
		return *GetInstance().m_CallContext.get_return_value<T>();
	}

	template<typename Args>
	void PushArg(Args&& arg)
	{
		GetInstance().m_CallContext.push_arg(std::forward<Args>(arg));
	}
	//g_context
	//m_CallContext
	/*template<typename T>
	T& GetReturnValue()
	{
		return *GetInstance().m_CallContext.GetResult<T>();
	}

	template<typename Args>
	void PushArg(Args&& arg)
	{
		GetInstance().m_CallContext.Push(std::forward<Args>(arg));
	}*/

	void CacheHandlersImpl()
	{
		auto handler = g_GameVariables->m_GetNativeHandler(g_GameVariables->m_NativeRegistrationsPtr, 0x255FDE258192D9FE);
		g_Settings.m_HandlerCache.emplace(0x6F3D4ED9BEE4E61D, handler);

		const auto& entry = *g_Settings.m_HandlerCache.begin();
		const scrNativeHash& first = entry.first;
		const scrNativeHandler& second = entry.second;
		Log::Msg("Handler cache entry - Hash: 0x%p | Handler: 0x%p", first, second);
		//g_Logger->Info(ConsoleColor::DARKRED, "Debug", "Handler cache entry - Hash: 0x%p | Handler: 0x%p", first, second);
	}

	void BeginCallImpl()
	{
		m_CallContext.Reset();
	}

	void EndCallImpl(scrNativeHash hash)
	{
		if (const auto& it = g_Settings.m_HandlerCache.find(hash); it != g_Settings.m_HandlerCache.end())
		{
			if (const auto& handler = it->second)
			{
				try
				{
					handler(&m_CallContext);
					//handler(reinterpret_cast<rage::scrNativeCallContext*>(&m_CallContext));
				}
				catch (const std::exception& ex)
				{
					Log::Msg("Exception while invoking native %p: %s", hash, ex.what());
					//g_Logger->Info(ConsoleColor::MAGENTA, "Error", "Exception while invoking native %p: %s", hash, ex.what());
				}
				catch (...)
				{
					Log::Msg("Unknown exception while invoking native %p", hash);
					//g_Logger->Info(ConsoleColor::MAGENTA, "Error", "Unknown exception while invoking native %p", hash);
				}
			}
			else
			{
				Log::Msg("Failed to find handler for native 0x%p", hash);
				//g_Logger->Info(ConsoleColor::MAGENTA, "Error", "Failed to find handler for native 0x%p", hash);
			}
		}
		else
		{
			Log::Msg("Failed to find current hash for native 0x%p", hash);
			//g_Logger->Info(ConsoleColor::MAGENTA, "Error", "Failed to find current hash for native 0x%p", hash);
		}
	}

private:
	NativeContext m_CallContext;
};

inline std::unique_ptr<NativeInvoker> g_NativeInvoker;



class VMTHook
{
public:
	/**
	 * \brief Initializes the hook class
	 * \param object The object to be hooked
	 * \param numFuncs The number of functions in the virtual table
	 */
	explicit VMTHook(void* object, std::size_t numFuncs) noexcept :
		m_Object(reinterpret_cast<std::uintptr_t**>(object)),
		m_NumFuncs(numFuncs),
		m_Original(*m_Object),
		m_New(std::make_unique<std::uintptr_t[]>(m_NumFuncs + 1))
	{
		std::copy_n(m_Original - 1, m_NumFuncs + 1, m_New.get());
	}

	~VMTHook() noexcept = default;

	/**
	 * \brief Enables the hook
	 */
	void Enable() noexcept
	{
		*m_Object = &m_New[1];
	}

	/**
	 * \brief Disables the hook
	 */
	void Disable() noexcept
	{
		*m_Object = m_Original;
	}

	/**
	 * \brief Hooks a function
	 * \param replacement The replacement function pointer
	 * \param index The index of the function in the virtual table
	 */
	void Hook(void* replacement, std::size_t index) noexcept
	{
		m_New[index + 1] = reinterpret_cast<std::uintptr_t>(replacement);
	}

	/**
	 * \brief Unhooks a function
	 * \param index The index of the function in the virtual table
	 */
	void Unhook(std::size_t index) noexcept
	{
		m_New[index + 1] = m_Original[index];
	}

	/**
	 * \brief Gets an original function
	 * \param index The index of the function in the virtual table
	 */
	template <typename T>
	T GetOriginal(std::size_t index) noexcept
	{
		return reinterpret_cast<T>(m_Original[index]);
	}

	VMTHook(VMTHook const&) noexcept = delete;
	VMTHook(VMTHook&&) noexcept = delete;
	VMTHook& operator=(VMTHook const&) noexcept = delete;
	VMTHook& operator=(VMTHook&&) noexcept = delete;
private:
	std::uintptr_t** m_Object;
	std::size_t m_NumFuncs;

	std::uintptr_t* m_Original;
	std::unique_ptr<std::uintptr_t[]> m_New;
};

class ScriptHook
{
public:
	explicit ScriptHook(rage::joaat_t script_hash, std::unordered_map<scrNativeHash, scrNativeHandler> replacements);
	explicit ScriptHook(rage::scrProgram* program, std::unordered_map<scrNativeHash, scrNativeHandler> replacements);
	~ScriptHook();

	void Ensure();
	static bool MapNative2(scrNativeHash* hash);
private:
	void HookInstance(rage::scrProgram* program);

	static void scrProgramDetour(rage::scrProgram* this_, bool free_memory);
	static std::unordered_map<rage::scrProgram*, ScriptHook*> s_Map;

	rage::joaat_t m_ScriptHash;
	rage::scrProgram* m_Program;
	std::unique_ptr<VMTHook> m_VMTHook;
	std::unordered_map<scrNativeHash, scrNativeHandler> m_NativeReplacementsPointer;
	std::unordered_map<scrNativeHash, scrNativeHandler*> m_NativeHandlerPointer;
};
inline std::shared_ptr<ScriptHook> g_ScriptHook;
class NativeHooks final
{
	using NativeDetour = std::pair<scrNativeHash, scrNativeHandler>;

	std::unordered_map<rage::joaat_t, std::vector<NativeDetour>> m_NativeRegistrations;
	std::unordered_map<rage::scrProgram*, std::unique_ptr<ScriptHook>> m_ScriptHooks;

public:
	NativeHooks();
	~NativeHooks();

	NativeHooks(const NativeHooks&) = delete;
	NativeHooks(NativeHooks&&) noexcept = delete;
	NativeHooks& operator=(const NativeHooks&) = delete;
	NativeHooks& operator=(NativeHooks&&) noexcept = delete;

	/**
	 * @brief Add a detour for all script threads
	 *
	 * @param hash Hash of the native to detour
	 * @param detour Detour Function
	 */
	void AddNativeDetour(const char* name, scrNativeHash hash, scrNativeHandler detour);
	/**
	 * @brief Add a detour for a specifik script
	 *
	 * @param script_hash Hash of the script to detour
	 * @param hash Hash of the native to detour
	 * @param detour Detour Function
	 */
	void AddNativeDetour(const char* name, rage::joaat_t script_hash, scrNativeHash hash, scrNativeHandler detour);

	void HookProgram(rage::scrProgram* program);

	void UnhookProgram(rage::scrProgram* program);

};


inline NativeHooks* g_NativeHooks{};
}
//inline std::unique_ptr<NativeHooks> g_NativeHooks2;

//inline std::unique_ptr<NativeHooks> g_NativeHooks;

//namespace ModMenu
//{
//	extern bool unload;
//	/*extern void jointype(std::int32_t SessionID); eSessionType*/
//	extern void jointype(eSessionType SessionID);
//}

namespace Hookss
{
	extern void NetworkSessionHost(scrNativeCallContext* src);
}

static uint64_t GetNetworkPlayerManagerPtr() { return g_GameVariables->m_networkPlayerManager; }

class TimecycleData //TimecycleKeyframeData
{
public:
	char pad_0000[32]; //0x0000
	rage::fvector4 m_azimuth_east; //0x0020
	float m_azimuth_east_intensity; //0x0030
	char pad_0034[28]; //0x0034
	rage::fvector4 m_azimuth_west; //0x0050
	float m_azimuth_west_intensity; //0x0060
	char pad_0064[28]; //0x0064
	rage::fvector4 m_azimuth_transition; //0x0080
	float m_azimuth_transition_intensity; //0x0090
	char pad_0094[4]; //0x0094
	float m_azimuth_transition_position; //0x0098
	char pad_009C[20]; //0x009C
	rage::fvector4 m_zenith; //0x00B0
	float m_zenith_intensity; //0x00C0
	char pad_00C4[28]; //0x00C4
	rage::fvector4 m_zenith_transition; //0x00E0
	float m_zenith_transition_intensity; //0x00F0
	float m_zenith_transition_position; //0x00F4
	float m_zenith_transition_east_blend; //0x00F8
	float m_zenith_transition_west_blend; //0x00FC
	float m_zenith_blend_start; //0x0100
	char pad_0104[60]; //0x0104
	rage::fvector3 m_plane; //0x0140
	float m_plane_intensity; //0x014C
	char pad_0150[52]; //0x0150
	float m_hdr; //0x0184
	float m_unk_188; //0x0188
	bool m_update_sky_attributes; //0x018C
	char pad_018D[3]; //0x018D
	uint32_t m_unk_190; //0x0190
	uint32_t m_unk_194; //0x0194
	char pad_0198[8]; //0x0198
	rage::fvector4 m_unk_1A0; //0x01A0
	char pad_01AC[16]; //0x01AC
	rage::fvector4 m_sun; //0x01C0
	char pad_01CC[32]; //0x01CC
	rage::fvector4 m_sun_disc; //0x01F0
	char pad_01FC[32]; //0x01FC
	float m_sun_disc_size; //0x0220
	float m_sun_hdr; //0x0224
	float m_sun_miephase; //0x0228
	float m_sun_miescatter; //0x022C
	float m_sun_mie_intensity_mult; //0x0230
	char pad_0234[28]; //0x0234
	rage::fvector4 m_unk_250; //0x0250
	char pad_025C[16]; //0x025C
	float m_cloud_shadow_strength; //0x0270
	float m_cloud_density_mult; //0x0274
	float m_cloud_density_bias; //0x0278
	float m_cloud_fadeout; //0x027C
	char pad_0280[32]; //0x0280
	float m_unk_2A0; //0x02A0
	float m_cloud_offset; //0x02A4
	float m_cloud_overall_color; //0x02A8
	float m_cloud_hdr; //0x02AC
	char pad_02B0[32]; //0x02B0
	float m_cloud_dither_strength; //0x02D0
	char pad_02D4[44]; //0x02D4
	float m_cloud_edge_strength; //0x0300
	char pad_0304[4]; //0x0304
	float m_cloud_overall_strength; //0x0308
	char pad_030C[16]; //0x030C
	rage::fvector4 m_unk_320; //0x031C
	rage::fvector4 m_cloud_base; //0x032C
	rage::fvector4 m_unk_340; //0x033C
	char pad_0348[16]; //0x0348
	rage::fvector4 m_cloud_1; //0x035C
	char pad_0368[20]; //0x0368
	rage::fvector4 m_cloud_mid; //0x0380
	char pad_038C[32]; //0x038C
	float m_unk_380; //0x03B0
	float m_small_cloud_detail_strength; //0x03B4
	float m_small_cloud_density_mult; //0x03B8
	float m_unk_3BC; //0x03BC
	char pad_03C0[32]; //0x03C0
	rage::fvector4 m_small_cloud; //0x03E0
	char pad_03EC[32]; //0x03EC
	float m_sun_influence_radius; //0x0410
	float m_sun_scatter_inten; //0x0414
	float m_moon_influence_radius; //0x0418
	float m_moon_scatter_inten; //0x041C
	char pad_0420[212]; //0x0420
	float m_stars_iten; //0x04F4
	char pad_04F8[60]; //0x04F8
	float m_moon_disc_size; //0x0534
	char pad_0538[24]; //0x0538
	rage::fvector4 m_moon; //0x0550
	float m_moon_intensity; //0x0560
	char pad_0564[140]; //0x0564
}; //Size: 0x05F0
//static_assert(sizeof(TimecycleKeyframeData) == 0x5F0);

namespace PrivateClass
{
typedef struct {
	float m_elements[16];
}Matrix;
class CModelInfo {
public:
	char pad_0x0000[0x808]; //0x0000

}; //Size=0x0808
class CPedDrawHandler {
public:
	char pad_0x0000[0x144]; //0x0000
	__int32 Face; //0x0144 
	__int32 FaceVariation; //0x0148 
	__int32 N00002CBF; //0x014C 
	char pad_0x0150[0x2B8]; //0x0150

}; //Size=0x0408
enum BoundType : uint8_t {
	BTSphere = 0,
	BTCapsule = 1,
	BTBox = 3,
	BTGeometry = 4,
	BTBoundingVolumeHierarchy = 8,
	BTComposite = 10,
	BTDisc = 12,
	BTCylinder = 13,
};
class phBoundComposite {
public:
	char pad_0x0000[0x10]; //0x0000
	BoundType Type; //0x0010 
	char pad_0x0011[0x3]; //0x0011
	float BoundingSphereRadius; //0x0014 
	char pad_0x0018[0x8]; //0x0018
	Vector3_t BoundingBoxMax; //0x0020 
	char pad_0x002C[0x4]; //0x002C
	Vector3_t BoundingBoxMin; //0x0030 
	char pad_0x003C[0x4]; //0x003C
	Vector3_t BoundingBoxCenter; //0x0040 
	char pad_0x004C[0x4]; //0x004C
	Vector3_t Center; //0x0050 
	char pad_0x005C[0x3AC]; //0x005C

}; //Size=0x0408
class NativeMatrix {
public:
	Matrix Matrix; //0x0000 
}; //Size=0x0040
class crSkeletonBoneData {
public:
	Vector4 Rotation; //0x0000 
	Vector3_t Position; //0x0010 
	char pad_0x001C[0x16]; //0x001C
	__int16 ParentIndex; //0x0032 
	char pad_0x0034[0x4]; //0x0034
	char* N0000160F; //0x0038 
	char pad_0x0040[0x2]; //0x0040
	__int16 index; //0x0042 
	char pad_0x0044[0xC]; //0x0044

}; //Size=0x0050
class crSkeletonBoneDataArray {
public:
	crSkeletonBoneData* array_boneDatas; //0x0000 

}; //Size=0x0050
class crSkeletonData {
public:
	char pad_0x0000[0x20]; //0x0000
	crSkeletonBoneDataArray* Bones; //0x0020 
	NativeMatrix* array_BonesTransformationsInverted; //0x0028 
	NativeMatrix* array_BonesTransformations; //0x0030 
	char pad_0x0038[0x40C]; //0x0038

}; //Size=0x0444
class CEntitySkeleton {
public:
	crSkeletonData* SkeletonData; //0x0000 
	NativeMatrix* EntityMatrix; //0x0008 
	NativeMatrix* desiredBonesMatricesArray; //0x0010 
	NativeMatrix* currentBonesMatricesArray; //0x0018 
	__int32 BonesCount; //0x0020 
	char pad_0x0024[0x3E4]; //0x0024

}; //Size=0x0408
class N000014A7 {
public:
	char pad_0x0000[0x60]; //0x0000
	float N000014C0; //0x0060 
	char pad_0x0064[0x3E4]; //0x0064

}; //Size=0x0448
class CArcheTypeDamp {
public:
	char pad_0x0000[0x20]; //0x0000
	phBoundComposite* Bounds; //0x0020 
	char pad_0x0028[0x130]; //0x0028
	CEntitySkeleton* EntitySkeleton; //0x0158 
	char pad_0x0160[0x2A8]; //0x0160

}; //Size=0x0408
class Groups {
public:
	char pad_0x0000[0x48]; //0x0000

}; //Size=0x0048

class CGroupNames {
public:
	char pad_0x0000[0x8]; //0x0000

}; //Size=0x0008
class CFragPhysicsLOD {
public:
	char pad_0x0000[0xC0]; //0x0000
	CGroupNames* GroupNames; //0x00C0 
	Groups* Groups; //0x00C8 
	char pad_0x00D0[0x3F8]; //0x00D0

}; //Size=0x04C8
class CFragPhysicsLODGroup {
public:
	char pad_0x0000[0x10]; //0x0000
	CFragPhysicsLOD* FragPhysicsLOD1; //0x0010 
	char pad_0x0018[0x3F0]; //0x0018

}; //Size=0x0408
class CFragType {
public:
	char pad_0x0000[0xF0]; //0x0000
	CFragPhysicsLODGroup* FragPhysicsLODGroup; //0x00F0 
	char pad_0x00F8[0x390]; //0x00F8

}; //Size=0x0488
class CFragInst {
public:
	char pad_0x0000[0x10]; //0x0000
	CArcheTypeDamp* ArcheTypeDamp; //0x0010 
	char pad_0x0018[0x60]; //0x0018
	CFragType* FragType; //0x0078 
	char pad_0x0080[0x388]; //0x0080

}; //Size=0x0408
class CVehicleStreamRender {
public:
	char _0x0000[8];
	uint8_t UNK1;
	uint8_t UNK2;
	unsigned char TireSize; //0x000B 
	char pad_0x000C[0x4]; //0x000C
	unsigned char CustomTires; //0x0010 
	//char pad_0x0011[0xF]; //0x0011
	char pad_0x0011[0xB8F]; //0x0011
	float m_tireWidth; //0x0BA0 
	char pad_0x0BA4[0x464]; //0x0BA4

}; //Size=0x0020
class CVehicleDrawHandlera {
public:
	char pad_0x0000[0x370]; //0x0000
	//CVehicleSteamRenderGFX* m_vehicleStreamRenderGfx; //0x0370 
	CVehicleStreamRender* m_vehicleStreamRender; //0x0370
	char pad_0x0378[0x8B0]; //0x0378

}; //Size=0x0C28
class CVehicleDeformation {
public:
	char pad_0x0000[0x20]; //0x0000
	float Rot1; //0x0020 
	float Width; //0x0024 
	float SideTilt; //0x0028 
	char pad_0x002C[0x4]; //0x002C
	float Rot2; //0x0030 
	float Length; //0x0034 
	float FrontUp; //0x0038 
	char pad_0x003C[0x4]; //0x003C
	float Sideways; //0x0040 
	float Forward; //0x0044 
	float Height; //0x0048 
	char pad_0x004C[0x4]; //0x004C
	Vector3_t Position; //0x0050 

}; //Size=0x005C
class CVehiclea {
public:
	char pad_0x0000[0x30]; //0x0000
	CFragInst* m_fragInst; //0x0030 
	char pad_0x0038[0x10]; //0x0038
	CVehicleDrawHandlera* m_vehicleDrawHandler; //0x0048 
	char pad_0x0050[0x230]; //0x0050
	float m_health; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float m_maxHealth; //0x02A0 
	char pad_0x02A4[0x77]; //0x02A4
	unsigned char m_rocketState; //0x031B 
	char pad_0x031C[0x1]; //0x031C
	unsigned char m_rocketEnergy; //0x031D 
	char pad_0x031E[0x5FA]; //0x031E
	CHandlingData* m_handlingData; //0x0918 
	char pad_0x0920[0x48]; //0x0920
	CVehicle* m_vehicle; //0x0968 
	char pad_0x0970[0x8]; //0x0970
	CVehicleDeformation* m_vehicleDeformation; //0x0978 
	char pad_0x0980[0x101C]; //0x0980
	float m_visualSuspension; //0x199C 
	char pad_0x19A0[0x240]; //0x19A0

}; //Size=0x1BE0
class CAimingInfo {
public:
	__int32 Hash; //0x0000 
	float HeadingLimit; //0x0004 
	float SweepPitchMin; //0x0008 
	float SweepPitchMax; //0x000C 

}; //Size=0x0010
class CAmmoInfo2 {
public:
	char pad_0x0000[0x20]; //0x0000
	unsigned char AmmoMax; //0x0020 
	char pad_0x0021[0x3]; //0x0021
	unsigned char AmmoMax50; //0x0024 
	char pad_0x0025[0x3]; //0x0025
	unsigned char AmmoMax100; //0x0028 
	char pad_0x0029[0x3]; //0x0029
	unsigned char AmmoMaxMP; //0x002C 
	char pad_0x002D[0x3]; //0x002D
	unsigned char AmmoMax50MP; //0x0030 
	char pad_0x0031[0x3]; //0x0031
	unsigned char AmmoMax100MP; //0x0034 
	char pad_0x0035[0xB]; //0x0035
	float Damage; //0x0040 
	float LifeTime; //0x0044 
	float FromVehicleLifeTime; //0x0048 
	float LifeTimeAfterImpact; //0x004C 
	float LifeTimeAfterExplosion; //0x0050 
	float ExplosionTime; //0x0054 
	float LaunchSpeed; //0x0058 
	float SeparationTime; //0x005C 
	float TimeToReachTarget; //0x0060 
	float Damping; //0x0064 
	float GravityFactor; //0x0068 
	float RicochetTolerance; //0x006C 
	float PedRicochetTolerance; //0x0070 
	float VehicleRicochetTolerance; //0x0074 
	float FrictionMultiplier; //0x0078 
	char pad_0x007C[0x64]; //0x007C
	Vector3_t LightColour; //0x00E0 
	char pad_0x00EC[0x4]; //0x00EC
	float LightIntensity; //0x00F0 
	float LightRange; //0x00F4 
	float LightFalloffExp; //0x00F8 
	float LightFrequency; //0x00FC 
	float LightPower; //0x0100 
	float CoronaSize; //0x0104 
	float CoronaIntensity; //0x0108 
	float CoronaZBias; //0x010C 
	char pad_0x0110[0x40]; //0x0110
	unsigned char AmmoMaxMPBonus; //0x0150 
	char pad_0x0151[0x7]; //0x0151

}; //Size=0x0158
class CWeapon {
public:
	char pad_0x0000[0x10]; //0x0000
	__int32 NameHash; //0x0010 
	__int32 ModelHash; //0x0014 
	char pad_0x0018[0x40]; //0x0018
	unsigned char WeaponWheelSlot; //0x0058 
	unsigned char N00002FF2; //0x0059 
	char pad_0x005A[0x6]; //0x005A
	CAmmoInfo2* AmmoInfo; //0x0060 
	CAimingInfo* AimingInfo; //0x0068 
	unsigned char ClipSize; //0x0070 
	char pad_0x0071[0x3]; //0x0071
	float AccuracySpread; //0x0074 
	float AccurateModeAccuracyModifier; //0x0078 
	float RunAndGunAccuracyModifier; //0x007C 
	float RunAndGunAccuracyMinOverride; //0x0080 
	float RecoilAccuracyMax; //0x0084 
	float RecoilErrorTime; //0x0088 
	float RecoilRecoveryRate; //0x008C 
	float RecoilAccuracyToAllowHeadShotAI; //0x0090 
	float MinHeadShotDistanceAI; //0x0094 
	float MaxHeadShotDistanceAI; //0x0098 
	float HeadShotDamageModifierAI; //0x009C 
	float RecoilAccuracyToAllowHeadShotPlayer; //0x00A0 
	float MinHeadShotDistancePlayer; //0x00A4 
	float MaxHeadShotDistancePlayer; //0x00A8 
	float HeadShotDamageModifierPlayer; //0x00AC 
	float Damage; //0x00B0 
	float DamageTime; //0x00B4 
	float DamageTimeInVehicle; //0x00B8 
	float DamageTimeInVehicleHeadShot; //0x00BC 
	float HitLimbsDamageModifier; //0x00C0 
	float NetworkHitLimbsDamageModifier; //0x00C4 
	float LightlyArmouredDamageModifier; //0x00C8 
	float VehicleDamageModifier; //0x00CC 
	float Force; //0x00D0 
	float ForceHitPed; //0x00D4 
	float ForceHitVehicle; //0x00D8 
	float ForceHitFlyingHeli; //0x00DC 
	char pad_0x00E0[0x10]; //0x00E0
	float ForceMaxStrengthMult; //0x00F0 
	float ForceFalloffRangeStart; //0x00F4 
	float ForceFalloffRangeEnd; //0x00F8 
	float ForceFalloffMin; //0x00FC 
	float ProjectileForce; //0x0100 
	float FragImpulse; //0x0104 
	float Penetration; //0x0108 
	float VerticalLaunchAdjustment; //0x010C 
	float DropForwardVelocity; //0x0110 
	float Speed; //0x0114 
	unsigned char BulletsInBatch; //0x0118 
	char pad_0x0119[0x3]; //0x0119
	float BatchSpread; //0x011C 
	float ReloadTimeMP; //0x0120 
	float ReloadTimeSP; //0x0124 
	float VehicleReloadTime; //0x0128 
	float AnimReloadRate; //0x012C 
	unsigned char BulletsPerAnimLoop; //0x0130 
	char pad_0x0131[0x3]; //0x0131
	float TimeBetweenShots; //0x0134 
	float TimeLeftBetweenShotsWhereShouldFireIsCached; //0x0138 
	float SpinUpTime; //0x013C 
	float SpinTime; //0x0140 
	float SpinDownTime; //0x0144 
	float AlternateWaitTime; //0x0148 
	float BulletBendingNearRadius; //0x014C 
	float BulletBendingFarRadius; //0x0150 
	float BulletBendingZoomedRadius; //0x0154 
	float FirstPersonBulletBendingNearRadius; //0x0158 
	float FirstPersonBulletBendingFarRadius; //0x015C 
	float FirstPersonBulletBendingZoomedRadius; //0x0160 
	char pad_0x0164[0xDC]; //0x0164
	__int32 InitialRumbleDuration; //0x0240 
	float InitialRumbleIntensity; //0x0244 
	float InitialRumbleIntensityTrigger; //0x0248 
	__int32 RumbleDuration; //0x024C 
	float RumbleIntensity; //0x0250 
	float RumbleIntensityTrigger; //0x0254 
	float RumbleDamageIntensity; //0x0258 
	__int32 InitialRumbleDurationFps; //0x025C 
	float InitialRumbleIntensityFps; //0x0260 
	__int32 RumbleDurationFps; //0x0264 
	float RumbleIntensityFps; //0x0268 
	float NetworkPlayerDamageModifier; //0x026C 
	float NetworkPedDamageModifier; //0x0270 
	float NetworkHeadShotPlayerDamageModifier; //0x0274 
	float LockOnRange; //0x0278 
	float WeaponRange; //0x027C 
	char pad_0x0280[0x8]; //0x0280
	float DamageFallOffRangeMin; //0x0288 
	float DamageFallOffRangeMax; //0x028C 
	char pad_0x0290[0x4]; //0x0290
	float DamageFallOffModifier; //0x0294 
	char pad_0x0298[0x50]; //0x0298
	float FirstPersonFOV; //0x02E8 
	char pad_0x02EC[0x678]; //0x02EC

}; //Size=0x0964
class CWeaponManager {
public:
	char pad_0x0000[0x20]; //0x0000
	CWeapon* WeaponInfo; //0x0020 
	char pad_0x0028[0x178]; //0x0028
	Vector3_t LastAimedPosition; //0x01A0 
	char pad_0x01AC[0x4]; //0x01AC
	Vector3_t ImpactPosition; //0x01B0 
	char pad_0x01BC[0x2E4]; //0x01BC

}; //Size=0x04A0
class CPedhand {
public:
	char pad_0x00002[0x20]; //0x0000
	CModelInfo* ModelInfo2; //0x0020 
	char pad_0x00282[0x20]; //0x0028
	CPedDrawHandler* PedDrawHandler2; //0x0048 
	char pad_0x00502[0x10]; //0x0050
	Matrix TransformationMatrix2; //0x0060 
	char pad_0x00A02[0x1E0]; //0x00A0
	float Health2; //0x0280 
	char pad_0x02842[0x1C]; //0x0284
	float MaxHealth2; //0x02A0 
	char pad_0x02A42[0xA6C]; //0xA6C//0xA84 //0x02A4
	CVehiclea* m_playerVehicle2; //0x0D28 
	char pad_0x0D302[0x378]; //0x388//0x0D30
	CPlayerInfo* PlayerInfo2; //0x10B8 //0x10A8
	char pad_0x10C02[0x8]; //0x8 //0x10C0
	CWeaponManager* m_weaponManager2; //0x10C8 
	char pad_0x10D02[0x13C0]; //0x10D0
}; //Size=0x2490
class CWorldd {
public:
	char pad_0x0000[0x8]; //0x0000
	CPedhand* LocalPed2; //0x0008 

}; //Size=0x0010
class BackEnd
{
public:
	static uint64_t GetWorldPtr() { return g_GameVariables->m_WorldBase; }
};
namespace ReClass {
	extern CWorldd* GetWorldd();
}

}
//class RainRGBColor
//{
//public:
//	char pad_0000[2];
//	Vector3 RBGRain;
//
//};

class RainRGBColor
{
public:
	//float m_precipitation;
	//char pad_0000[4];
	//fvector3 RGBRain;
	float m_red;
	float m_green;
	float m_blue;
	float m_rain_size;
};


class CMsgJoinRequest
{
public:
	std::uint32_t m_version_number;
	std::uint32_t m_flags;
	std::uint32_t m_unk_zero;
	std::uint32_t m_magic;
	GameDataHash m_game_data_hash;
	std::uint32_t m_dlc_hash;
	std::uint32_t m_timeout_time;
	std::uint32_t dword10C;
	bool m_no_handle;
	rage::rlGamerHandle m_gamer_handle;
	CNetGamePlayerDataMsg* m_player_data_msg;
};

struct bypassmysession
{
	bool spoof_game_data_hash = false;
	std::array<std::uint32_t, 16> game_data_hash{};
	bool game_data_hash_dirty = true;
	std::uint64_t custom_host_token = 0x000000200235F2EA;
	std::uint64_t original_host_token = 0;
	int spoof_host_token_type = 0;
	std::atomic_bool spoof_host_token_dirty = true;
	bool kick_host_when_forcing_host = false;
	bool exclude_modders_from_kick_host = false;
};




namespace BattleyeBypass
{
	extern bool boolTimer;
	extern bool booltoggleBE;
	extern int _Battleye();
	extern bool BypassBattleye;
	extern bool m_enabled;
	extern int hookbypass();
	extern int bpbattleye();
	extern int bpTimerBE();
	extern int TimerBEbp();
	extern void set_peer_id_upper(std::uint64_t upper);
	extern void set_host_token(std::uint64_t token);
	extern void on_enable();
	extern void on_tick();
	extern void on_disable();
	extern void bypass_battleye();
}
class hooks
{
public:
	static bool network_can_access_multiplayer(void* a1, int* error);

};

namespace math
	{
	inline unsigned long float_to_unsigned_long(float value) {
		// Explicitly cast the float to an unsigned long
		return static_cast<unsigned long>(value);
	}

		inline float deg_to_rad(float deg)
		{
			double radian = (3.14159265359 / 180) * deg;
			return (float)radian;
		}

		inline float distance_between_vectors(Vector3 a, Vector3 b)
		{
			return (float)sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2));
		}

		inline float distance_between_vectors(rage::fvector3 a, rage::fvector3 b)
		{
			return (float)sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2));
		}

		inline Vector3 rotation_to_direction(Vector3 rotation)
		{
			float x = deg_to_rad(rotation.x);
			float z = deg_to_rad(rotation.z);

			/*float num = abs(cos(x));

			return Vector3{ -sin(z) * num, cos(z) * num, sin(x) };*/
			float num = std::abs(cos(x));

			float cosZValue = cos(z);
			unsigned long reinterpretedCosZ;
			std::memcpy(&reinterpretedCosZ, &cosZValue, sizeof(unsigned long));

			float z_ = cos(z) * num;

			// Use the original float for calculations, not the reinterpreted version
			return Vector3{ -sin(z) * num, (unsigned long)z_, sin(x) };

		}

		inline float calculate_distance_from_game_cam(rage::fvector3 player_position)
		{
			const Vector3 plyr_coords = { player_position.x, player_position.y, player_position.z };
			const Vector3 cam_coords = g_GameFunctions->m_get_gameplay_cam_coords();

			return (float)distance_between_vectors(plyr_coords, cam_coords);
		}

		inline Vector3 raycast_coords(Vector3 coord, Vector3 rot, Entity ignore)
		{
			BOOL hit;
			Vector3 end_coords;
			Vector3 surface_normal;
			Entity hit_entity;
			Vector3 dir = math::rotation_to_direction(rot);
			Vector3 far_coords;

			far_coords.x = coord.x + dir.x * 1000;
			far_coords.y = coord.y + dir.y * 1000;
			far_coords.z = coord.z + dir.z * 1000;

			int ray = WORLDPROBE::_START_SHAPE_TEST_RAY(coord.x,
				coord.y,
				coord.z,
				far_coords.x,
				far_coords.y,
				far_coords.z,
				-1,
				ignore,
				7);
			WORLDPROBE::GET_SHAPE_TEST_RESULT(ray, &hit, &end_coords, &surface_normal, &hit_entity);
			return end_coords;
		}

		// [0, max_value)
		inline int rand(int max_value)
		{
			static std::random_device seed;
			static std::mt19937 gen{ seed() };
			std::uniform_int_distribution<int> dist{ 0, max_value - 1 };

			return dist(gen);
		}

		// [min_value, max_value]
		inline int rand(int min_value, int max_value)
		{
			static std::random_device seed;
			static std::mt19937 gen{ seed() };
			std::uniform_int_distribution<int> dist{ min_value, max_value };

			return dist(gen);
		}
	}


namespace
{
	static std::array<std::uint32_t, 16> orig_hash;

	void store_data(std::array<std::uint32_t, 16>& data)
	{
		for (int i = 0; i < 16; i++)
		{
			data[i] = (*g_GameFunctions->m_game_data_hash)->m_data[i];
		}
	}

	void load_data(const std::array<std::uint32_t, 16>& data)
	{
		for (int i = 0; i < 16; i++)
		{
			(*g_GameFunctions->m_game_data_hash)->m_data[i] = data[i];
		}
	}
}

namespace gamedata
{
	extern void execute();
	extern void on_disable();
	extern void on_tick();
	extern void on_enable();
}

class native_hook final
{
public:
	explicit native_hook(rage::scrProgram* program, const std::unordered_map<int, scrNativeHandler>& native_replacements);
	~native_hook();

private:
	void hook_instance(rage::scrProgram* program, const std::unordered_map<int, scrNativeHandler>& native_replacements);
	static void scrprogram_dtor(rage::scrProgram* this_, char free_memory);

	rage::scrProgram* m_program;
	std::unique_ptr<vmt_hook> m_vmt_hook;
	std::unique_ptr<vmt_hook> m_handler_hook;
};

class native_hooks final
{
	friend class native_hook;

	using native_detour = std::pair<int, scrNativeHandler>;

	static std::unordered_map<rage::joaat_t, std::vector<native_detour>> m_native_registrations;
	std::unordered_map<rage::scrProgram*, std::unique_ptr<native_hook>> m_native_hooks;

public:
	//native_hooks();
	~native_hooks();

	native_hooks(const native_hooks&) = delete;
	native_hooks(native_hooks&&) noexcept = delete;
	native_hooks& operator=(const native_hooks&) = delete;
	native_hooks& operator=(native_hooks&&) noexcept = delete;
	static void add_native_detour(int index, scrNativeHandler detour);

	static void add_native_detour(joaat_t script_hash, int index, scrNativeHandler detour);

	void hook_program(rage::scrProgram* program);
};

inline native_hooks* g_native_hooks{};


//namespace memory01
//{
//	template<typename T>
//	concept SpanCompatibleType = requires(T a) { std::span{ a }; };
//
//	class byte_patch
//	{
//	public:
//		virtual ~byte_patch();
//
//		void apply() const;
//		void restore() const;
//
//		void remove() const;
//
//		template<typename TAddr>
//		static const std::unique_ptr<byte_patch>& make(TAddr address, std::remove_pointer_t<std::remove_reference_t<TAddr>> value)
//		{
//			return m_patches.emplace_back(std::unique_ptr<byte_patch>(new byte_patch(address, value)));
//		}
//
//		template<typename TAddr, typename T>
//			requires SpanCompatibleType<T>
//		static const std::unique_ptr<byte_patch>& make(TAddr address, T span_compatible)
//		{
//			return m_patches.emplace_back(std::unique_ptr<byte_patch>(new byte_patch(address, std::span{ span_compatible })));
//		}
//
//		static void restore_all();
//
//	private:
//		template<typename TAddr>
//		byte_patch(TAddr address, std::remove_pointer_t<std::remove_reference_t<TAddr>> value) :
//			m_address(address)
//		{
//			m_size = sizeof(std::remove_pointer_t<std::remove_reference_t<TAddr>>);
//
//			m_original_bytes = std::make_unique<byte[]>(m_size);
//			memcpy(m_original_bytes.get(), m_address, m_size);
//
//			m_value = std::make_unique<byte[]>(m_size);
//			memcpy(m_value.get(), &value, m_size);
//		}
//
//		template<typename TAddr, typename T, std::size_t N>
//		byte_patch(TAddr address, std::span<T, N> span) :
//			m_address((void*)address)
//		{
//			m_size = span.size();
//
//			m_original_bytes = std::make_unique<byte[]>(m_size);
//			memcpy(m_original_bytes.get(), m_address, m_size);
//
//			m_value = std::make_unique<byte[]>(m_size);
//			for (int i = 0; i < m_size; i++)
//				m_value[i] = span[i];
//		}
//
//	protected:
//		static inline std::vector<std::unique_ptr<byte_patch>> m_patches;
//
//	private:
//		void* m_address;
//		std::unique_ptr<std::byte[]> m_value;
//		std::unique_ptr<std::byte[]> m_original_bytes;
//		std::size_t m_size;
//
//		friend bool operator==(const std::unique_ptr<byte_patch>& a, const byte_patch* b);
//	};
//}


#include <windows.h> // Or any other header that defines `max`
#undef max // Undefine the macro
#include <iostream>
#include <optional>
#include <string>
#include <algorithm> // For std::transform
#include <limits> // Now include <limits>
#include <cstdint> // For uint_least32_t

#include <WinSock2.h>
//#include "nlohmann/source_location"
#include "nlohmann/string_operations.hpp"
#include <cfloat> // For FLT_MIN and FLT_MAX
//#include "nlohmann/nlohmann/json.hpp"




//
//#include "nlohmann\lua\sol.hpp"
//#include "nlohmann\chrono"
//
//#include <xkeycheck.h>
//#include <concepts>
//#include <stdexcept>
//#include <type_traits>
//
//#include <iostream>
//#include <cstdint>
// 
// 
//class lua_module
//{
//	sol::state m_state;
//
//	sol::protected_function m_io_open;
//
//	std::filesystem::path m_module_path;
//
//	std::string m_module_name;
//	rage::joaat_t m_module_id;
//
//	std::chrono::time_point<std::chrono::file_clock> m_last_write_time;
//
//	bool m_disabled;
//	std::mutex m_registered_scripts_mutex;
//
//public:
//	std::vector<std::unique_ptr<script>> m_registered_scripts;
//	std::vector<std::unique_ptr<lua_patch>> m_registered_patches;
//	std::vector<std::unique_ptr<lua::scr_patch::scr_patch>> m_registered_script_patches;
//
//	std::vector<big::tabs> m_owned_tabs;
//
//	std::unordered_map<big::tabs, std::vector<big::tabs>> m_tab_to_sub_tabs;
//
//	std::vector<std::unique_ptr<lua::gui::gui_element>> m_independent_gui;
//	std::vector<std::unique_ptr<lua::gui::gui_element>> m_always_draw_gui;
//	std::unordered_map<rage::joaat_t, std::vector<std::unique_ptr<lua::gui::gui_element>>> m_gui;
//	std::unordered_map<menu_event, std::vector<sol::protected_function>> m_event_callbacks;
//	std::vector<void*> m_allocated_memory;
//
//	// lua modules own and share the runtime_func_t object, such as when no module reference it anymore the hook detour get cleaned up.
//	std::vector<std::shared_ptr<lua::memory::runtime_func_t>> m_dynamic_hooks;
//	std::unordered_map<uintptr_t, std::vector<sol::protected_function>> m_dynamic_hook_pre_callbacks;
//	std::unordered_map<uintptr_t, std::vector<sol::protected_function>> m_dynamic_hook_post_callbacks;
//
//	std::unordered_map<uintptr_t, std::unique_ptr<uint8_t[]>> m_dynamic_call_jit_functions;
//
//	lua_module(const std::filesystem::path& module_path, folder& scripts_folder, bool disabled = false);
//	~lua_module();
//
//	const std::filesystem::path& module_path() const;
//
//	rage::joaat_t module_id() const;
//	const std::string& module_name() const;
//	const std::chrono::time_point<std::chrono::file_clock> last_write_time() const;
//	const bool is_disabled() const;
//
//	// used for sandboxing and limiting to only our custom search path for the lua require function
//	void set_folder_for_lua_require(folder& scripts_folder);
//
//	void sandbox_lua_os_library();
//	void sandbox_lua_io_library();
//	void sandbox_lua_loads(folder& scripts_folder);
//
//	void init_lua_api(folder& scripts_folder);
//
//	void load_and_call_script();
//
//	inline void for_each_script(auto func)
//	{
//		std::lock_guard guard(m_registered_scripts_mutex);
//
//		for (auto& script : m_registered_scripts)
//		{
//			func(script.get());
//		}
//	}
//
//	void tick_scripts();
//	void cleanup_done_scripts();
//
//	sol::object to_lua(const lua::memory::runtime_func_t::parameters_t* params, const uint8_t i, const std::vector<lua::memory::type_info_t>& param_types);
//	sol::object to_lua(lua::memory::runtime_func_t::return_value_t* return_value, const lua::memory::type_info_t return_value_type);
//};
//class lua_manager final
//{
//private:
//	std::mutex m_module_lock;
//	std::vector<std::shared_ptr<lua_module>> m_modules;
//	std::mutex m_disabled_module_lock;
//	std::vector<std::shared_ptr<lua_module>> m_disabled_modules;
//
//	static constexpr std::chrono::seconds m_delay_between_changed_scripts_check = 3s;
//	std::chrono::high_resolution_clock::time_point m_wake_time_changed_scripts_check;
//
//	folder m_disabled_scripts_folder;
//	folder m_scripts_folder;
//	folder m_scripts_config_folder;
//
//public:
//	lua_manager(folder scripts_folder, folder scripts_config_folder);
//	~lua_manager();
//
//	void disable_all_modules();
//	void enable_all_modules();
//
//	void load_all_modules();
//	void unload_all_modules();
//
//	inline auto get_module_count() const
//	{
//		return m_modules.size();
//	}
//
//	inline const folder& get_scripts_folder() const
//	{
//		return m_scripts_folder;
//	}
//
//	inline const folder& get_scripts_config_folder() const
//	{
//		return m_scripts_config_folder;
//	}
//
//	// non owning map
//	std::unordered_map<uintptr_t, lua::memory::runtime_func_t*> m_target_func_ptr_to_dynamic_hook;
//
//	std::weak_ptr<lua_module> get_module(rage::joaat_t module_id);
//	std::weak_ptr<lua_module> get_disabled_module(rage::joaat_t module_id);
//
//	bool has_gui_to_draw(rage::joaat_t tab_hash);
//	void draw_independent_gui();
//	void draw_always_draw_gui();
//	void draw_gui(rage::joaat_t tab_hash);
//
//	bool dynamic_hook_pre_callbacks(const uintptr_t target_func_ptr, lua::memory::type_info_t return_type, lua::memory::runtime_func_t::return_value_t* return_value, std::vector<lua::memory::type_info_t> param_types, const lua::memory::runtime_func_t::parameters_t* params, const uint8_t param_count);
//	void dynamic_hook_post_callbacks(const uintptr_t target_func_ptr, lua::memory::type_info_t return_type, lua::memory::runtime_func_t::return_value_t* return_value, std::vector<lua::memory::type_info_t> param_types, const lua::memory::runtime_func_t::parameters_t* params, const uint8_t param_count);
//
//	std::weak_ptr<lua_module> enable_module(rage::joaat_t module_id);
//	std::weak_ptr<lua_module> disable_module(rage::joaat_t module_id);
//
//	void unload_module(rage::joaat_t module_id);
//	std::weak_ptr<lua_module> load_module(const std::filesystem::path& module_path);
//
//	void reload_changed_scripts();
//
//	void handle_error(const sol::error& error, const sol::state_view& state);
//
//	template<menu_event menu_event_, typename Return = void, typename... Args>
//	inline std::conditional_t<std::is_void_v<Return>, void, std::optional<Return>> trigger_event(Args&&... args)
//	{
//		std::lock_guard guard(m_module_lock);
//
//		for (auto& module : m_modules)
//		{
//			if (auto vec = module->m_event_callbacks.find(menu_event_); vec != module->m_event_callbacks.end())
//			{
//				for (auto& cb : vec->second)
//				{
//					auto result = cb(args...);
//
//					if (!result.valid())
//					{
//						handle_error(result, result.lua_state());
//						continue;
//					}
//
//					if constexpr (!std::is_void_v<Return>)
//					{
//						if (result.return_count() == 0)
//							continue;
//
//						if (!result[0].is<Return>())
//							continue;
//
//						return result[0].get<Return>();
//					}
//				}
//			}
//		}
//
//		if constexpr (!std::is_void_v<Return>)
//			return std::nullopt;
//	}
//
//	std::shared_ptr<lua::memory::runtime_func_t> get_existing_dynamic_hook(const uintptr_t target_func_ptr);
//
//	inline void for_each_module(auto func)
//	{
//		std::lock_guard guard(m_module_lock);
//
//		for (auto& module : m_modules)
//		{
//			func(module);
//		}
//	}
//
//	inline void for_each_disabled_module(auto func)
//	{
//		std::lock_guard guard(m_disabled_module_lock);
//
//		for (auto& module : m_disabled_modules)
//		{
//			func(module);
//		}
//	}
//};
//
//inline lua_manager* g_lua_manager;
//using script_list = std::vector<std::unique_ptr<script>>;

class script_mgr
{
public:
	explicit script_mgr() = default;
	~script_mgr() = default;

	//void add_script(std::unique_ptr<script> script);
	void remove_all_scripts();

	/*inline void for_each_script(auto func)
	{
		std::lock_guard lock(m_mutex);

		for (const auto& script : m_scripts)
		{
			func(script);
		}

		g_lua_manager->for_each_module([&func](const std::shared_ptr<lua_module>& module) {
			module->for_each_script([&func](script* script) {
				func(script);
				});
			});
	}*/

	void tick();

	[[nodiscard]] inline bool can_tick() const
	{
		return m_can_tick;
	}

private:
	void ensure_main_fiber();
	void tick_internal();

private:
	std::recursive_mutex m_mutex;
	//script_list m_scripts;

	bool m_can_tick = false;
};

inline script_mgr g_script_mgr;

class player_command;


// Define a concept to check if the size of T is <= sizeof(uint64_t)
//template<typename T>
//concept ArgumentLimit = sizeof(T) <= sizeof(uint64_t);




class command
{
protected:
	std::string m_name;
	std::string m_label;
	rage::joaat_t m_label_hash;
	std::string m_description;
	rage::joaat_t m_description_hash;
	std::optional<uint8_t> m_num_args;
	bool m_fiber_pool;

	/*virtual void execute(const command_arguments& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>()) = 0;
	virtual std::optional<command_arguments> parse_args(const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>())
	{
		return { 0 };
	};
	virtual CommandAccessLevel get_access_level()
	{
		return CommandAccessLevel::ADMIN;
	}*/

public:
	command(const std::string& name, const std::string& label, const std::string& description, std::optional<uint8_t> num_args, bool fiber_pool = true);
	inline const std::string& get_name()
	{
		return m_name;
	}
	/*inline const std::string get_label()
	{
		std::string key;
		if (key = g_translation_service.get_translation(m_label_hash); key.empty())
			key = m_label;

		return key;
	}
	inline const std::string get_description()
	{
		std::string key;
		if (key = g_translation_service.get_translation(m_description_hash); key.empty())
			key = m_description;

		return key;
	}*/
	inline const std::optional<uint8_t>& get_num_args()
	{
		return m_num_args;
	}

	virtual std::optional<std::vector<std::string>> get_argument_suggestions(int arg)
	{
		return std::nullopt;
	};

	inline std::optional<int> get_argument_proxy_value(const std::string proxy)
	{
		std::string local_player_name_lower = g_player_service->get_self()->get_name();
		std::string proxy_lower = proxy;
		operationstring::to_lower(local_player_name_lower);
		operationstring::to_lower(proxy_lower);

		switch (proxy_lower[0])
		{
		case '@': return g_player_service->get_selected()->id();
		case '!': return g_player_service->get_closest(true)->id();
		case '#':
			float distance = std::numeric_limits<float>::max();
			player::player_ptr closest = nullptr;
			for (auto p : g_player_service->players())
			{
				if (p.second->is_friend() && p.second->get_ped() && p.second->get_ped()->get_position())
				{
					auto distance_ = math::distance_between_vectors(*g_player_service->get_self()->get_ped()->get_position(),
						*p.second->get_ped()->get_position());
					if (distance_ < distance)
					{
						closest = p.second;
						distance = distance_;
					}
				}
			}

			if (closest)
				return closest->id();
			break;
		}

		if (proxy_lower == "me" || proxy_lower == "self" || local_player_name_lower.find(proxy_lower) != std::string::npos)
		{
			return g_player_service->get_self()->id();
		}

		return std::nullopt;
	}

	/*void call(command_arguments& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>());
	void call(const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>());*/
	static std::vector<command*> get_suggestions(std::string, int limit = 7);

	static command* get(rage::joaat_t command);

	/*static void call(rage::joaat_t command, command_arguments& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>());
	static void call(rage::joaat_t command, const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>());

	static bool process(const std::string& text, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>(), bool use_best_suggestion = false);*/
};

//class player_all_component : public command
//{
//	player_command* m_parent;
//
//protected:
//	/*virtual void execute(const command_arguments& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>()) override;
//	virtual std::optional<command_arguments> parse_args(const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>()) override;*/
//
//public:
//	//player_all_component(player_command* parent, const std::string& name, const std::string& label, const std::string& description, std::optional<uint8_t> num_args);
//};
//
//inline std::unordered_map<rage::joaat_t, player_command*> g_player_commands;



class player;
using player_ptr = std::shared_ptr<player>;



class command_arguments
{
private:
	const std::size_t m_argument_count;
	std::vector<uint64_t> m_argument_data;
	mutable std::size_t m_idx;

public:
	command_arguments(std::size_t argument_count = 0) :
		m_argument_count(argument_count),
		m_argument_data(),
		m_idx(0)
	{
		m_argument_data.reserve(argument_count);
	}

	command_arguments(std::size_t argument_count, const command_arguments& other) :
		command_arguments(argument_count)
	{
		std::copy_n(other.m_argument_data.begin(), min(argument_count, other.m_argument_data.size()), m_argument_data.begin());
	}

	command_arguments(const std::vector<uint64_t>& vec) :
		command_arguments(vec.size())
	{
		m_argument_data = vec;
	}

	/*template<typename T = uint64_t>
		requires ArgumentLimit<T>
	T get(std::size_t idx) const
	{
		return reinterpret_cast<const T&>(m_argument_data[idx]);
	}

	template<typename T = uint64_t>
		requires ArgumentLimit<T>
	std::enable_if_t<std::is_pointer_v<T>, T> get(std::size_t idx) const
	{
		return static_cast<T>(m_argument_data[idx]);
	}*/

	/*template<typename T = uint64_t>
		requires ArgumentLimit<T>
	T shift() const
	{
		if (m_idx >= m_argument_count)
		{
			throw std::runtime_error("Attempted to shift argument beyond allocated argument size.");
		}

		return reinterpret_cast<const T&>(m_argument_data[m_idx++]);
	}

	template<typename T = uint64_t>
		requires ArgumentLimit<T>
	std::enable_if_t<std::is_pointer_v<T>, T> shift() const
	{
		if (m_idx >= m_argument_count)
		{
			throw std::runtime_error("Attempted to shift argument beyond allocated argument size.");
		}

		return static_cast<const T>(m_argument_data[m_idx++]);
	}

	*/
	template<typename T = uint64_t>
		//requires ArgumentLimit<T>
	void push(T arg)
	{
		if (m_idx++ >= m_argument_count)
		{
			throw std::runtime_error("Attempted to push argument beyond allocated argument size.");
		}

		m_argument_data.push_back(reinterpret_cast<uint64_t&>(arg));
	}

	/*template<typename T = uint64_t>
		requires ArgumentLimit<T>
	void set(std::size_t idx, T arg)
	{
		if (idx >= m_argument_count)
		{
			throw std::runtime_error("Attempted to set argument beyond allocated argument size.");
		}

		m_argument_data[idx] = reinterpret_cast<uint64_t&>(arg);
	}*/

	command_arguments& reset_idx()
	{
		m_idx = 0;

		return *this;
	}

	std::size_t size() const
	{
		return m_argument_data.size();
	}

};

//class reaction
//{
//public:
//	bool announce_in_chat = false;
//	bool is_team_only = false;
//	bool notify = true;
//	bool log = true;
//	bool add_to_player_db = false;
//	bool block_joins = false;
//	int block_join_reason = 1;
//	bool kick = false;
//	bool timeout = false;
//
//	const char* m_event_name;
//	const char* m_notify_message;
//	const char* m_announce_message;
//
//	NLOHMANN_DEFINE_TYPE_INTRUSIVE(reaction, announce_in_chat, is_team_only, notify, log, add_to_player_db, block_joins, block_join_reason, kick, timeout)
//
//		reaction(const char* event_name, const char* notify_message, const char* announce_message);
//	virtual void process(player_ptr player);
//	virtual void only_notify(player_ptr player);
//	virtual void process_common(player_ptr player);
//}; 
//class command_context
//{
//public:
//	virtual player_ptr get_sender() const = 0;
//	virtual CommandAccessLevel get_access_level() const = 0;
//	virtual void report_output(const std::string& output) const = 0;
//	virtual void report_error(const std::string& error) const = 0;
//};
//class default_command_context : public command_context
//{
//public:
//	virtual player_ptr get_sender() const override;
//	virtual CommandAccessLevel get_access_level() const override;
//	virtual void report_output(const std::string& output) const override;
//	virtual void report_error(const std::string& error) const override;
//	default_command_context() {};
//};


inline std::unordered_map<rage::joaat_t, command*> g_commands;

class player_command : public command
{
	/*friend player_all_component;
	std::unique_ptr<player_all_component> m_all_component;

protected:*/
	//virtual void execute(const command_arguments& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>()) override;
	//virtual void execute(player_ptr player, const command_arguments& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>()) = 0;
	//virtual std::optional<command_arguments> parse_args(const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>()) override;
	//virtual std::optional<command_arguments> parse_args_p(const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>())
	//{
	//	return { 0 };
	//};

	//virtual std::optional<std::vector<std::string>> get_argument_suggestions(int arg) override
	//{
	//	if (arg == 1) // First argument of all player commands is the player name
	//	{
	//		std::vector<std::string> suggestions;
	//		for (auto& player : g_player_service->players() | std::ranges::views::values)
	//		{
	//			suggestions.push_back(player->get_name());
	//		}
	//		return suggestions;
	//	}

	//	return std::nullopt;
	//};

public:
	/*static player_command* get(rage::joaat_t command)
	{
		return g_player_commands[command];
	}*/

	/*void call(player_ptr player, const command_arguments& args, const std::shared_ptr<command_context> ctx = std::make_shared<default_command_context>());
	player_command(const std::string& name, const std::string& label, const std::string& description, std::optional<uint8_t> num_args, bool make_all_version = true);*/
};

//namespace big
//{
	// if this limit is hit you did something wrong coding wise.
	constexpr auto MAX_POOL_SIZE = 32u;

	struct thread_pool_job
	{
		std::function<void()> m_func;
		//std::source_location m_source_location;
	};

	class thread_pool
	{
		std::atomic<bool> m_accept_jobs;
		std::condition_variable m_data_condition;

		std::stack<thread_pool_job> m_job_stack;
		std::mutex m_lock;
		std::vector<std::thread> m_thread_pool;

		// the amount of threads active in the pool
		std::atomic<size_t> m_allocated_thread_count;
		// the amount of threads currently on a job
		std::atomic<size_t> m_busy_threads;

	public:
		// YimMenu only has 2 blocking threads, 4 should be sufficient but the pool should automatically allocate more if needed
		thread_pool(const std::size_t preallocated_thread_count = 4);
		~thread_pool();

		void destroy();
		//void push(std::function<void()> func, std::source_location location = std::source_location::current());

		std::pair<size_t, size_t> usage() const
		{
			return { m_busy_threads, m_allocated_thread_count };
		}

	private:
		void run();
		void rescale_thread_pool();
	};

	inline thread_pool* g_thread_pool{};
//}



class battleye_service
{
	using log_func_t = void (*)(const char* msg, int level);
	using kick_player_t = void (*)(std::uint64_t id, const char* reason);
	using send_message_t = void (*)(std::uint64_t id, const void* msg, int size);
	using add_player_t = void (*)(std::uint64_t id, u_long ip_addr, u_short port, const char* name, char unused);
	using set_player_state_t = void (*)(std::uint64_t id, int reason);
	using assign_guid_t = void (*)(std::uint64_t id, const void* guid, int size); // binary
	using receive_message_t = void (*)(std::uint64_t id, const void* packet, int size);

	using shutdown_t = void (*)();
	using run_t = bool (*)();
	using run_command_t = void (*)(const char* command);

	struct CUserData
	{
		const char* m_game_name;
		log_func_t m_log_func;
		kick_player_t m_kick_player;
		send_message_t m_send_message;
		void* m_unk;
	} m_battleye_user_data{};

	struct CApi
	{
		shutdown_t m_shutdown;
		run_t m_run;
		run_command_t m_run_command;
		add_player_t m_add_player;
		set_player_state_t m_set_player_state;
		assign_guid_t m_assign_guid;
		assign_guid_t m_assign_guid_verified;
		receive_message_t m_receive_message;
	} m_battleye_api{};

	using init_t = bool (*)(int api_level, CUserData* data, CApi* api);

	enum packet_id : std::uint8_t
	{
		INIT = 0x00,
		START = 0x02,
		REQUEST = 0x04,
		RESPONSE = 0x05,
		HEARTBEAT = 0x09,
	};

	std::mutex m_mutex{};

	bool is_running();

public:
	battleye_service();
	~battleye_service();

	void start();
	void stop();
	void add_player(std::uint64_t token, std::uint64_t rockstar_id, const char* name);
	void remove_player(std::uint64_t token);
	void receive_message(std::uint64_t token, void* message, int size);
	void on_receive_message_from_server(std::uint64_t token, void* message, int size);
	void send_message_to_client(std::uint64_t token, void* message, int size);
	void send_message_to_server(std::uint64_t token, void* message, int size);
	//void kick_player(std::uint64_t token, const char* reason);
	void script_func();
	void thread_func();
};

inline battleye_service g_battleye_service;

//namespace requestmessageserialize
//{

//}
//vmt_hook* hookvmt;

namespace dmr
{
	extern void detourmessagerequest();
}