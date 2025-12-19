// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

//std::byte //transact.h

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

// Windows Library Files:
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Winmm.lib")

// Windows Header Files:
#include <windows.h>
#include <Mmsystem.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <Psapi.h>
#include <MinHook.h>
#include <timeapi.h>
#include <time.h>
#include <cassert>
#include <iterator>

// Additional Header Files:
#include "Log.h"
#include "Memory.h"
#include "types.h"
#include "enums.h"
#include "InputHook.h"
#include "keyboard.h"
#include "CrossMapping.h"
#include "NativeInvoker.h"
#include "nativeCaller.h"
#include "natives.h"
#include "Hooking.h"
#include "Structs.h"
#include "Functions.h"
#include "menu.h"

// Menu Files:
#include "GUI.h"
#include "subs.h"
#include "Features.h"

#include <locale>
#include <codecvt>
#include <stdio.h>
#include <tchar.h>

#include "targetver.h"


// Menu Files:
#include "GUI.h"
#include "menu.h"
#include "types.h"
#include "Functions.h"
#include <locale>
#include <codecvt>
#include <stdio.h>
#include "Auth/Networking/sha512.hh"
#include "Auth/Networking/Web2.0.h"

#include "initialization.h"
#include "Authentification.h"
#include "Geo.h"

#include "Mains.h"
#include "backgrounds.h"
#include "Header.h"

#include "particlefx.h"
#include "ObjectsSpawner.h"
//#include "WhoTalking.h"
#include "JumpAroundMode.h"
#include "Raycast.h"
#include "GTAmath.h"
#include "GTAentity.h"
#include "World.h"
#include "ExePath.h"

#include "macros.h"
#include "FileLogger.h"
#include "GTAmemory.h"
#include "GTAped.h"
#include "Tasks.h"

#include "Camera.h"
#include "Scaleform.h"
#include "GTAplayer.h"

#include "base64.h"
#include "base64caller.h"

#include "SimpleIni.h"
#include "pugixml.h"
#include "dirent.h"

#include "MenuConfig.h"

#include "SpoonerSettings.h"
#include "SpoonerMode.h"
#include "SpoonerEntity.h"

#include "GamePlayCamera.h"
#include "Game.h"
#include "GTAblip.h"
#include "model.h"
#include "StringManip.h"
#include "EntityManagement.h"
#include "GTAVehicle.h"
#include "GTAprop.h"
#include "SpoonerTaskSequence.h"
#include "STSTask.h"
#include "STSTasks.h"
#include "Submenus_TaskSequence.h"
#include "ModelNames.h"
#include "Databases.h"

#include "OutfitList.h"
//#include "SpoonerMode.h"

#include "PedComponentChanger.h"
#include "FileManagement.h"
#include "RelationshipManagement.h"
#include "PedModelChanger.h"
#include "WeaponIndivs.h"

#include "Discord.h" 
#include "discord_rpc.h"
#include "discord_register.h"
#include "connection.h"
#include "rpc_connection.h"
#include "serialization.h"

#include "MyTimer.h"
#include "GETHASHKEY.h"

#include "Language.h"

#include "nlohmann/json.hpp"
#include "Attachment.h"
#include "PersistOutfit.h"

#include "reclass.h"
#include "YoutubeDownloader.h"

#include "Ptolemy.h"
#include "NativeForce.h"
//#include "reclass/CAmmoInfo.hpp"
//#include "reclass/CAutomobile.hpp"
//#include "reclass/CBaseModelInfo.hpp"
//#include "reclass/CHandlingData.hpp"
//#include "reclass/CItemInfo.hpp"
//#include "reclass/CNavigation.hpp"
//#include "reclass/CNetGamePlayer.hpp"
//#include "reclass/CNetworkPlayerMgr.hpp"
//#include "reclass/CNonPhysicalPlayerData.hpp"
//#include "reclass/CPed.hpp"
//#include "reclass/CPedFactory.hpp"
//#include "reclass/CPedModelInfo.hpp"
//#include "reclass/CPedWeaponManager.hpp"
//#include "reclass/CPlayerInfo.hpp"
//#include "reclass/CVehicleDrawHandler.hpp"
//#include "reclass/CVehicleModelInfo.hpp"
//#include "reclass/CWeaponInfo.hpp"
//#include "reclass/FriendInfo.hpp"
//#include "reclass/FriendRegistry.hpp"
//#include "reclass/fwDrawData.hpp"
//#include "reclass/fwEntity.hpp"
//#include "reclass/netObject.hpp"
//#include "reclass/netPlayer.hpp"
//#include "reclass/netPlayerData.hpp"
//#include "reclass/ScInfo.hpp"
//#include "reclass/vector.hpp"

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


#include "NewMenu.h"

#include "BusinessManager.h"
#include "ScreenPed.h"

#include "Crash.h"
#include "reclass/GTAV-Classes/script/scriptHandler.hpp"
//#include "scriptHandler.hpp"
//#include "cpr/cpr/cpr.h"
//#include "cpr/cpr/curl.h"

#include "Traduction.h"

class globalHandle
{
private:
	void* _handle;

public:
	globalHandle(int index)
		: _handle(&Hooking::getGlobalPtr()[index >> 18 & 0x3F][index & 0x3FFFF])
	{ }

	globalHandle(void* p)
		: _handle(p)
	{ }

	globalHandle(const globalHandle& copy)
		: _handle(copy._handle)
	{ }

	globalHandle At(int index)
	{
		return globalHandle(reinterpret_cast<void**>(this->_handle) + (index));
	}

	globalHandle At(int index, int size)
	{
		// Position 0 = Array Size
		return this->At(1 + (index * size));
	}

	globalHandle Add(int offset)
	{
		return globalHandle(reinterpret_cast<void**>(this->_handle) + (offset));
	}


	template <typename T>
	T* Get()
	{
		return reinterpret_cast<T*>(this->_handle);
	}

	template <typename T>
	T& As()
	{
		return *this->Get<T>();
	}
};

