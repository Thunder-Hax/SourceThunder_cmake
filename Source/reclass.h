#include "stdafx.h"
#pragma once

//enum EFrameFlags : unsigned int
//{
//	FRAME_FLAG_EXPLOSIVE_AMMO = (1 << 11),
//	FRAME_FLAG_FIRE_AMMO = (1 << 12),
//	FRAME_FLAG_EXPLOSIVE_MELEE = (1 << 13),
//	FRAME_FLAG_SUPER_JUMP = (1 << 14),
//	FRAME_FLAG_UNK0 = (1 << 15),
//	FRAME_FLAG_UNK1 = (1 << 28),
//	FRAME_FLAG_UNK2 = (1 << 29)
//};
//
//enum EPlayerActivity : int
//{
//	PLAYER_ACTIVITY_NONE = 0,
//	PLAYER_ACTIVITY_DEAD_SCREEN,
//	PLAYER_ACTIVITY_UNK2,
//	PLAYER_ACTIVITY_UNK3,
//	PLAYER_ACTIVITY_UNK4,
//	PLAYER_ACTIVITY_LEAVING_CUTSCENE,
//	PLAYER_ACTIVITY_IN_CUTSCENE
//};
//
//enum EHandlingDataModelFlags
//{
//	HANDLING_DATA_MODEL_FLAG_BULLETPROOF = (1 << 25)
//};
//
//class CNavigation
//{
//public:
//	char BYTE_PAD1[0x20]; // 0x00
//	//ViewMatrix_t matWorldView; // 0x20
//};
////static_assert(sizeof(CNavigation) == 0x60);
//
//class CBaseModelInfo
//{
//public:
//	char BYTE_PAD2[0x18]; // 0x0000
//	//JOAAT_t uModelHash; // 0x0018
//}; // Size: 0x001C (~expected: 0x0168)
////static_assert(sizeof(CBaseModelInfo) == 0x001C);
//
//class CEntityBase
//{
//public:
//	char BYTE_PAD3[0x20]; // 0x0000
//	CBaseModelInfo* pModelInfo; // 0x0020
//	std::uint8_t nEntityType; // 0x0028
//	char BYTE_PAD4[0x5]; // 0x0029
//	std::uint8_t nFreezeMomentum; //0x002E
//	char BYTE_PAD5[0x1]; // 0x002F
//	CNavigation* pNavigation; // 0x0030
//	char BYTE_PAD6[0x28]; // 0x0038
//	//ViewMatrix_t matWorldView; // 0x60 (why CNavigation have same vars??)
//	char BYTE_PAD7[0x30]; // 0x00A0
//	//rage::CNetObject* pNetObject; // 0x00D0
//	char BYTE_PAD8[0xB0]; // 0x00D8
//	std::uint32_t uDamageFlags; // 0x0188
//};
////static_assert(sizeof(CEntityBase) == 0x018C);
//
//class CHandlingData
//{
//public:
//	char BYTE_PAD9[0x8]; // 0x0000
//	//JOAAT_t uModelHash; // 0x0008
//	float flMass; // 0x000C
//	float flInitialDragCoefficient; // 0x0010
//	float flDownforceMultiplier; // 0x0014
//	float flPopupLightRotation; // 0x0018
//	char BYTE_PAD10[0x4]; // 0x001C
//	//Vector3D_t vecCentreOfMass; // 0x0020
//	char BYTE_PAD11[0x4]; // 0x002C
//	//Vector3D_t vecInertiaMultiplier; // 0x0030
//	char BYTE_PAD12[0x4]; // 0x003C
//	float flBuoyancy; // 0x0040
//	float flDriveBiasNear; // 0x0044
//	float flDriveBiasFront; // 0x0048
//	float flAcceleration; // 0x004C
//	std::uint8_t uInitialDriveGears; // 0x0050
//	char BYTE_PAD13[0x3]; // 0x0051
//	float flDriveInertia; // 0x0054
//	float flUpShift; // 0x0058
//	float flDownShift; // 0x005C
//	float flInitialDriveForce; // 0x0060
//	float flDriveMaxFlatVelocity; // 0x0064
//	float flInitialDriveMaxFlatVelocity; // 0x0068
//	float flBrakeForce; // 0x006C
//	char BYTE_PAD14[0x4]; // 0x0070
//	float flBrakeBiasFront; // 0x0074
//	float flBrakeBiasRear; // 0x0078
//	float flHandBrakeForce; // 0x007C
//	float flSteeringLock; // 0x0080
//	float flSteeringLockRatio; // 0x0084
//	float flTractionCurveMax; // 0x0088
//	float flTractionCurveLateral; // 0x008C
//	float flTractionCurveMin; // 0x0090
//	float flTractionCurveRatio; // 0x0094
//	float flCurveLateral; // 0x0098
//	float flCurveLateralRatio; // 0x009C
//	float flTractionSpringDeltaMax; // 0x00A0
//	float flTractionSpringDeltaMaxRatio; // 0x00A4
//	float flLowSpeedTractionLossMultiplier; // 0x00A8
//	float flCamberStiffness; // 0x00AC
//	float flTractionBiasFront; // 0x00B0
//	float flTractionBiasRear; // 0x00B4
//	float flTractionLossMultiplier; // 0x00B8
//	float flSuspensionForce; // 0x00BC
//	float flSuspensionCompDamp; // 0x00C0
//	float flSuspensionReboundDamp; // 0x00C4
//	float flSuspensionUpperLimit; // 0x00C8
//	float flSuspensionLowerLimit; // 0x00CC
//	float flSuspensionRaise; // 0x00D0
//	float flSuspensionBiasFront; // 0x00D4
//	float flSuspensionBiasRear; // 0x00D8
//	float flAntiRollbarForce; // 0x00DC
//	float flAntiRollbarBiasFront; // 0x00E0
//	float flAntiRollbarBiasRear; // 0x00E4
//	float flRollCentreHeightFront; // 0x00E8
//	float flRollCentreHeightRear; // 0x00EC
//	float flCollisionDamageMultiplier; // 0x00F0
//	float flWeaponDamamgeMultiplier; // 0x00F4
//	float flDeformationMultiplier; // 0x00F8
//	float flEngineDamageMultiplier; // 0x00FC
//	float flPetrolTankVolume; // 0x0100
//	float flOilVolume; // 0x0104
//	char BYTE_PAD15[0x4]; // 0x0108
//	//Vector3D_t vecSeatOffsetDistance; // 0x010C
//	std::uint32_t uMonetaryValue; // 0x0118
//	char BYTE_PAD16[0x4]; // 0x011C
//	float flBoostSpeedMultiplier; // 0x0120
//	std::uint32_t uModelFlags; // 0x0124
//	std::uint32_t uHandlingFlags; // 0x0128
//	std::uint32_t uDamageFlags; // 0x012C
//	char BYTE_PAD17[0xC]; // 0x0130
//	//JOAAT_t uHandlingAIHash; // 0x013C
//};
////static_assert(sizeof(CHandlingData) == 0x0140);
//
//class CPed;
//class CVehicle : public CEntityBase
//{
//public:
//	std::uint8_t uHostility; // 0x018C
//	char BYTE_PAD18[0xF3]; // 0x018D
//	float flHealth; // 0x0280
//	char BYTE_PAD19[0x1C]; // 0x0284
//	float flHealthMax; // 0x02A0
//	char BYTE_PAD20[0x74]; // 0x02A4
//	std::uint8_t nRocketBoostState; // 0x0318 // 0x1 - on, 0x0 - off // should be bool
//	char BYTE_PAD21[0x2]; // 0x0319
//	std::uint8_t nRocketBoostAllowRecharge; // 0x031B // 0x1 - recharging, 0x0 - can't
//	char BYTE_PAD22[0x4]; // 0x031C
//	float flRocketBoostCharge; // 0x0320 // 2.250 (scamjet), 1.250 (voltic), 1.0 (oppressor mk2) - full, 0.0 - empty
//	float flRocketBoostChargeSpeedMultiplier; // 0x0324
//	char BYTE_PAD23[0x88]; // 0x0328
//	// bool bNitro_0; // 0x0330
//	// float flNitro_1; // 0x0334
//	// float flNitro_2; // 0x0338
//	// int/float iNitro_3; // 0x033C
//	// bool bNitro_5; // 0x0340
//	// float flMaxSpeed; // 0x0370
//	float flJumpBoostCharge; // 0x03B0 // 5.0 - full, 0.0 - empty
//	char BYTE_PAD24[0x48C]; // 0x03B4
//	float flBodyHealth; // 0x0840
//	float flPetrolTankHealth; // 0x0844
//	char BYTE_PAD25[0xC0]; // 0x0848
//	// std::uint32_t uFireFlags; // 0x086C IsVehicleEngineOnFire: (uFireFlags & 1) && (uFireFlags & 2)
//	float flEngineHealth; // 0x0908
//	char BYTE_PAD26[0x2C]; // 0x090C
//	CHandlingData* pHandlingData; // 0x0938
//	char BYTE_PAD27[0x2]; // 0x0940
//	std::uint8_t nIsDriveable; // 0x0942 // result = (nIsDriveable >> 1) & 1;
//	std::uint8_t nTyresCanBurst; // 0x0943 // result |= 0x20 - bulletproof; result &= 0xDF - off; // result = (~(nTyresCanBurst >> 5) & 1);
//	std::uint8_t uDeformationState; // 0x0944 // 0x8C = on 0x9C = off
//	//std::uint8_t nIsBreakableLights; // 0x0947 // 0xFE = unbreakable
//	//and byte ptr[rax + 947h], 0FEh
//	//and bl, 1
//	//or [rax + 947h], bl
//	//std::uint8_t nIsStolen; // 0x0948 // nIsStolen & 1 - true : false
//	char BYTE_PAD28[0xB3]; // 0x0945
//	// std::uint8_t nHasBeenDriven; 0x094E // nHasBeenDriven &= 0xF7u; nHasBeenDriven |= 8 * ((bool to set) & 1);
//	// float flSteerBias; // 0x09B0
//	float flDirtLevel; // 0x09F8
//	// 0x0980 std::uint8_t nMissilesUsed = 0 - 255; 0x0981 std::uint8_t nMissilesClipsUsed = count of times 255 missiles used;
//	char BYTE_PAD29[0xC2]; // 0x09FC
//	// float flLightMultiplier; // 0x0A14
//	// CPed* pLockOnTarget; // 0x0A38
//	// float flFrictionOverride; // 0x0A6C
//	std::uint8_t nIsTargetable; // 0x0ABE
//	char BYTE_PAD30[0x19D]; // 0x0ABF
//	// 0x0AC2 - DriftTyresEnabled
//	float flGravity; // 0x0C5C
//	char BYTE_PAD31[0x8]; // 0x0C60 // last ped in vehicle seat or std::int8_t door count? 0x0C61 also smth related to doors
//	CPed* pDriver; // 0x0C68
//	CPed* arrPassengers[15]; // 0x0C70
//	CPed* pLastDriver; // 0x0CE8
//	// float flCheatPowerIncrease; 0x1360
//	// flHeliRotorSpeed; // 0x1AE4
//	// flHeliMainRotorHealth; // 0x1AF0
//	// flHeliTailRotorHealth; // 0x1AF4
//	// flHeliTailBoomHealth; // 0x1AF8
//	// iPlanePropellerIntact1; // 0x1CD8
//	// flPlanePropellerIntact2; // 0x1CDC
//	// flPlanePropellerSpeed; // 0x1F54
//};
////static_assert(sizeof(CVehicle) == 0xCF0);
//
//class CPlayerInfo;
//class CWeaponManager;
//class CPed : public CEntityBase
//{
//public:
//	std::uint8_t uHostility; // 0x018C
//	char BYTE_PAD32[0xF3]; // 0x018D
//	float flHealth; // 0x0280
//	char BYTE_PAD33[0x1C]; // 0x0284
//	float flHealthMax; // 0x02A0
//	char BYTE_PAD34[0x4]; // 0x02A4
//	void* pAttackers; // 0x02A8
//	char BYTE_PAD35[0x70]; // 0x02B0
//	//Vector3D_t vecVelocity; // 0x0320
//	char BYTE_PAD36[0xA04]; // 0x032C
//	CVehicle* pLastVehicle; // 0x0D30
//	char BYTE_PAD37[0x380]; // 0x0D38
//	std::uint8_t nType; // 0x10B8
//	// mov edx, [rax+10B8h] ; ped type
//	// shl edx, 0Bh
//	// sar edx, 19h
//	char BYTE_PAD38[0xF]; // 0x10B9
//	CPlayerInfo* pPlayerInfo; // 0x10C8
//	char BYTE_PAD39[0x8]; // 0x10D0 // pointer to smth weapon related, maybe weapon draw manager
//	CWeaponManager* pWeaponManager; // 0x10D8
//	char BYTE_PAD40[0x32C]; // 0x10E0
//	std::int8_t nBikeSeatBelt; // 0x140C
//	char BYTE_PAD41[0xB]; // 0x140D
//	std::int8_t nVehicleSeatBelt; // 0x1418
//	char BYTE_PAD42[0x5E]; // 0x1419
//	std::uint8_t nNotInVehicle; // 0x1477
//	char BYTE_PAD43[0x68]; // 0x1478
//	float flArmor; // 0x14E0
//	// int/float iDeathTime; 0x15FC
//	// int iMoney; 0x1604
//};
////static_assert(sizeof(CPed) == 0x14E4);
//
//class CPlayerInfo
//{
//public:
//	char BYTE_PAD44[0x20]; // 0x0000
//	//NetAddress_t netInternalIP; // 0x0020
//	std::uint16_t uInternalPort; // 0x0024
//	char BYTE_PAD45[0x2]; // 0x0026
//	//NetAddress_t netRelayIP; // 0x0028
//	std::uint16_t uRelayPort; // 0x002C
//	char BYTE_PAD46[0x46]; // 0x002E
//	//NetAddress_t netExternalIP; // 0x0074
//	std::uint16_t uExternalPort; // 0x0078
//	char BYTE_PAD47[0x16]; // 0x007A
//	std::uint64_t nRockstarID; // 0x0090
//	char BYTE_PAD48[0xC]; // 0x0098
//	char szName[20]; // 0x00A4
//	char BYTE_PAD49[0xB8]; // 0x00B8
//	float flSwimSpeed; // 0x0170
//	char BYTE_PAD50[0x64]; // 0x0174
//	EPlayerActivity nCurrentActivity; // 0x1D8
//	char BYTE_PAD51[0xC]; // 0x01DC
//	CPed* pPed; // 0x01E8
//	char BYTE_PAD52[0x28]; // 0x01F0
//	EFrameFlags nFrameFlags; // 0x0218
//	char BYTE_PAD53[0x66C]; // 0x021D
//	int iWantedLevelDisplay; // 0x0888
//	int iWantedLevel; // 0x088C
//	char BYTE_PAD54[0x460]; // 0x0890
//	float flRunSpeed; // 0x0CF0
//	float flStamina; // 0x0CF4
//	float flStaminaRegeneration; // 0x0CF8
//	char BYTE_PAD55[0x10]; // 0x0CFC
//	float flWeaponDamageMultiplier; // 0x0D0C
//	float flWeaponDefenceMultiplier; // 0x0D10
//	char BYTE_PAD56[0x4]; // 0x0D14
//	float flMeleeWeapon_damageMultiplier; // 0x0D18
//	float flMeleeDamageMultiplier; // 0x0D1C
//	float flMeleeDefenceMultiplier; // 0x0D20
//	char BYTE_PAD57[0x8]; // 0x0D24
//	float flMeleeWeaponDefenceMultiplier; // 0x0D2C
//};
////static_assert(sizeof(CPlayerInfo) == 0x0D30);
//
//class CAmmoInfo
//{
//public:
//	char BYTE_PAD58[0xC]; // 0x0000
//	int nProjectileType; // 0x000C
//	//JOAAT_t uAmmoNameHash; // 0x0010
//	//JOAAT_t uAmmoModelHash; // 0x0014
//	int iCurrentAmmo; // 0x0018         @test: packed?
//	char BYTE_PAD59[0xC]; // 0x001C
//	int iMaxAmmo; // 0x0028
//	char BYTE_PAD60[0x2C]; // 0x002C
//	float flMissileSpeed; // 0x0058
//	char BYTE_PAD61[0x11C]; // 0x005C
//	float flLockOnTime; // 0x0178         @test:
//};
////static_assert(sizeof(CAmmoInfo) == 0x017C);
//
//class CWeaponInfo
//{
//public:
//	char BYTE_PAD62[0x10]; // 0x0000
//	//JOAAT_t uNameHash; // 0x0010
//	//JOAAT_t uModelHash; // 0x0014
//	char BYTE_PAD63[0x48]; // 0x0018
//	CAmmoInfo* pAmmoInfo; // 0x0060
//	char BYTE_PAD64[0x14]; // 0x0068
//	float flAccuracySpread; // 0x007С
//	char BYTE_PAD65[0x3C]; // 0x0080
//	float flBulletDamage; // 0x00BC
//	char BYTE_PAD66[0x1C]; // 0x00C0
//	float flForceOnPed; // 0x00DC
//	float flForceOnVehicle; // 0x00E0
//	float flForceOnHeli; // 0x00E4
//	char BYTE_PAD67[0x28]; // 0x00E8
//	float flPenetration; // 0x0110
//	char BYTE_PAD68[0x8]; // 0x0114
//	float flMuzzleVelocity; // 0x011C
//	char BYTE_PAD69[0x10]; // 0x0120
//	float flVehicleReloadSpeedMultiplier; // 0x0130
//	float flReloadSpeedMultiplier; // 0x0134
//	char BYTE_PAD70[0x150]; // 0x0138
//	float flLockOnRange; // 0x288
//	float flMaxRange; // 0x028C
//	char BYTE_PAD71[0x64]; // 0x0290
//	float flAccuracyRecoil; // 0x02F4
//};
////static_assert(sizeof(CWeaponInfo) == 0x02F8);
//
//class CWeaponManager
//{
//public:
//	char BYTE_PAD72[0x10]; // 0x00
//	CPed* pOwnerPed; // 0x10
//	//JOAAT_t uSeletedWeaponHash; // 0x18
//	char BYTE_PAD73[0x4]; // 0x1C // val: 0
//	CWeaponInfo* pWeaponInfo; // 0x20
//	char BYTE_PAD74[0x48]; // 0x28
//	CWeaponInfo* pVehicleWeaponInfo; // 0x70
//};
////static_assert(sizeof(CWeaponManager) == 0x78);
//
//class CObject : public CEntityBase
//{
//public:
//}; // Size: 0x018C
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//struct ScInAddr
//{
//	uint64_t unkKey1;
//	uint64_t unkKey2;
//	uint32_t secKeyTime; // added in 393
//	uint32_t ipLan;
//	uint16_t portLan;
//	uint32_t ipUnk;
//	uint16_t portUnk;
//	uint32_t ipOnline;
//	uint16_t portOnline;
//	uint16_t pad3;
//	uint32_t newVal; // added in 372
//	uint64_t rockstarAccountId; // 463/505 addition - really R*? given this field one could easily replace everything with a Steam-like implementation only passing around user IDs...
//};
//struct ScPlayerData
//{
//	ScInAddr addr;
//};
//class CNetworkPlayer
//{
//public:
//	virtual ~CNetworkPlayer() = 0;
//
//	virtual void Reset() = 0;
//
//	virtual void m_10() = 0;
//
//	virtual const char* GetName() = 0;
//
//	virtual void m_20() = 0;
//
//	virtual void m_28() = 0;
//
//	// contains ScInAddr as well
//	virtual ScPlayerData* GetPlatformPlayerData() = 0;
//};
//
////class CPlayerInfo
////{
////public:
////	char pad_0000[32]; //0x0000
////	uint32_t m_internal_ip; //0x0020
////	uint16_t m_internal_port; //0x0024
////	char pad_0026[2]; //0x0026
////	uint32_t m_relay_ip; //0x0028
////	uint16_t m_relay_port; //0x002C
////	char pad_002E[66]; //0x002E
////	uint32_t N00000124; //0x0070
////	uint32_t m_external_ip; //0x0074
////	uint16_t m_external_port; //0x0078
////	char pad_007A[22]; //0x007A
////	uint64_t m_rockstar_id; //0x0090
////	char pad_0098[12]; //0x0098
////	char m_name[20]; //0x00A4
////	char pad_00B8[184]; //0x00B8
////	float m_swim_speed; //0x0170
////	char pad_0174[165]; //0x0174
////	uint32_t m_frame_flags; //0x0218
////	char pad_021D[1644]; //0x021D
////	int32_t m_wanted_level; //0x0888
////	int32_t m_wanted_level_2; //0x088C
////	char pad_0890[1120]; //0x0890
////	float m_run_speed; //0x0CF0
////	float m_stamina; //0x0CF4
////	float m_stamina_regen; //0x0CF8
////}; //Size: 0x0CFC
//class CNetGamePlayers : public CNetworkPlayer
//{
//public:
//	char m_pad_0x000[0x2D];
//	uint8_t m_player_id;
//	char m_pad_0x002R[0x7A];
//	CPlayerInfo* PlayerInfo;
//	char m_pad_0x00B0[0x1B8];
//};
//
//static unsigned int joaat(std::string input)
//{
//	unsigned int num1 = 0U;
//	for (char c : input)
//	{
//		unsigned int num2 = num1 + (unsigned int)tolower(c);
//		unsigned int num3 = num2 + (num2 << 10);
//		num1 = num3 ^ num3 >> 6;
//	}
//	unsigned int num4 = num1 + (num1 << 3);
//	unsigned int num5 = num4 ^ num4 >> 11;
//	return num5 + (num5 << 15);
//}
//struct VehicleModValues {
//	int Spoiler;
//	int Frontbumper;
//	int Rearbumper;
//	int SideSkirts;
//	int Exhaust;
//	int Chassis;
//	int Grille;
//	int Hood;
//	int Fender;
//	int Rightfender;
//	int Roof;
//	int Engine;
//	int Brakes;
//	int Transmission;
//	int Horns;
//	int Suspension;
//	int Armor;
//	int Frontwheels;
//	int Backwheels;
//	int Plateholder;
//	int VanityPlates;
//	int TrimDesign;
//	int Ornaments;
//	int Dashboard;
//	int Dial;
//	int DoorSpeaker;
//	int Seats;
//	int Steeringwheel;
//	int ShifterLeavers;
//	int Plaques;
//	int Speakers;
//	int Trunk;
//	int Hydrulics;
//	int EngineBlock;
//	int AirFilter;
//	int Struts;
//	int ArchCover;
//	int Aerials;
//	int Trim;
//	int Tank;
//	int Windows;
//	int Doors;
//	int Livery;
//};
//struct VehiclePreview {
//	std::wstring VName;
//	char* VCode;
//	VehicleModValues VMod;
//};
//
//
//class CPed2
//{
//public:
//	char m_padding[0x10B8];
//	CPlayerInfo* m_playerinfo;
//};
//
//class CPedFactory
//{
//public:
//	virtual ~CPedFactory() = default;
//	CPed2 *m_local_ped;
//	CPedFactory* m_ped_factory{};
//};
//class netPlayerData
//{
//public:
//	char pad_0000[8]; //0x0000
//	uint64_t m_rockstar_id; //0x0008
//	char pad_0010[52]; //0x0010
//	//class netAddress m_relay_ip; //0x0044
//	uint16_t m_relay_ip; //0x0044
//	uint16_t m_relay_port; //0x0048
//	char pad_004A[2]; //0x004A
//	//class netAddress m_external_ip; //0x004C
//	uint16_t m_external_ip; //0x004C
//	uint16_t m_external_port; //0x0050
//	char pad_0052[2]; //0x0052
//	//class netAddress m_internal_ip; //0x0054
//	uint16_t m_internal_ip; //0x0054
//	uint16_t m_internal_port; //0x0058
//	char pad_005A[6]; //0x005A
//	uint64_t m_host_token; //0x0060
//	uint64_t m_peer_id; //0x0068
//	uint64_t m_rockstar_id2; //0x0070
//	char pad_0078[12]; //0x0078
//	char m_name[20]; //0x0084
//}; //Size: 0x0098
//static_assert(sizeof(netPlayerData) == 0x98);


//class CNonPhysicalPlayerData {
//public:
//    int32_t m_bubble_id; //0x0008
//    int32_t m_player_id; //0x000C
//    //class rage::vector3 m_position; //0x0010
//}; //Size: 0x001C


//class netAddress {
//public:
//    netAddress() = default;
//    netAddress(std::uint8_t field1, std::uint8_t field2, std::uint8_t field3, std::uint8_t field4) {
//        m_field1 = field1;
//        m_field2 = field2;
//        m_field3 = field3;
//        m_field4 = field4;
//    }
//public:
//    std::uint8_t m_field1;
//    std::uint8_t m_field2;
//    std::uint8_t m_field3;
//    std::uint8_t m_field4;
//};
//class netPlayerData {
//public:
//    char pad_0000[8]; //0x0000
//    uint64_t m_rockstar_id; //0x0008
//    char pad_0010[52]; //0x0010
//    class netAddress m_relay_ip; //0x0044
//    uint16_t m_relay_port; //0x0048
//    char pad_004A[2]; //0x004A
//    class netAddress m_external_ip; //0x004C
//    uint16_t m_external_port; //0x0050
//    char pad_0052[2]; //0x0052
//    class netAddress m_internal_ip; //0x0054
//    uint16_t m_internal_port; //0x0058
//    char pad_005A[6]; //0x005A
//    uint64_t m_host_token; //0x0060
//    uint64_t m_peer_id; //0x0068
//    uint64_t m_rockstar_id2; //0x0070
//    char pad_0078[12]; //0x0078
//    char m_name[20]; //0x0084
//}; //Size: 0x0098
//class netPlayer {
//public:
//    virtual ~netPlayer() = default;
//    virtual void reset() = 0;
//    virtual bool is_valid() = 0;
//    virtual const char* get_name() = 0;
//    virtual void _0x20() = 0;
//    virtual bool is_host() = 0;
//    virtual netPlayerData* get_net_data() = 0;
//    virtual void _0x38() = 0;
//}; //Size: 0x0008
//class CNetGamePlayer : public netPlayer {
//public:
//    char pad_0008[8]; //0x0008
//    class CNonPhysicalPlayerData* m_non_physical_player; //0x0010
//    uint32_t m_msg_id; //0x0018
//    char pad_001C[4]; //0x001C
//    uint8_t m_active_id; //0x0020
//    uint8_t m_player_id; //0x0021
//    char pad_0022[126]; //0x0022
//    class CPlayerInfo* m_player_info; //0x00A0
//}; //Size: 0x00A8

//static CNetGamePlayer* SelectedPlayers;
//
//class netPlayerMgrBase {
//public:
//    virtual ~netPlayerMgrBase() = default;
//    virtual void Initialize() = 0;
//    virtual void Shutdown() = 0;
//    virtual void unk_0x18() = 0;
//    virtual CNetGamePlayer* AddPlayer_raw(void* a1, void* a2, void* a3, netPlayerData* net_player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
//    virtual void RemovePlayer(CNetGamePlayer* net_game_player) = 0;
//    virtual void UpdatePlayerListsForPlayer(CNetGamePlayer* net_game_player) = 0;
//    virtual CNetGamePlayer* AddPlayer(void* a1, void* a2, void* a3, netPlayerData* net_player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
//}; //Size: 0x0008
//
//class CNetworkPlayerMgr : public netPlayerMgrBase {
//public:
//    char pad_0008[224]; //0x0008
//    class CNetGamePlayer* m_local_net_player; //0x00E8
//    char pad_00F0[144]; //0x00F0
//    class CNetGamePlayer* m_player_list[32]; //0x0180
//    uint16_t m_player_limit; //0x0280
//    char pad_0282[10]; //0x0282
//    uint16_t m_player_count; //0x028C
//}; //Size: 0x028E
//static CNetworkPlayerMgr** m_NetworkPlayerMgr;
//





//using start_get_session_by_gamer_handle = bool(*)(int metric_manager, rlGamerHandle* handles, int count, rlSessionByGamerTaskResult* result, int unk, bool* success, int* state);
//using send_invite_accepted_presence_event = void(*)(void* presenceStruct, rlPresenceEventInviteAccepted* invite, int flags);

//class CPlayerInfo {
//public:
//    char pad_0000[32]; //0x0000
//    class netPlayerData m_net_player_data; //0x0020
//    char pad_00B8[184]; //0x00B8
//    float m_swim_speed; //0x0170
//    char pad_0174[20]; //0x0174
//    uint32_t m_water_proof; //0x0188
//    char pad_018C[92]; //0x018C
//    class CPed* m_ped; //0x01E8
//    char pad_01F0[40]; //0x01F0
//    uint32_t m_frame_flags; //0x0218
//    char pad_021C[52]; //0x021C
//    uint32_t m_player_controls; //0x0250
//    char pad_0254[1256]; //0x0254
//    float m_wanted_can_change; //0x073C
//    char pad_0740[304]; //0x0740
//    uint32_t m_npc_ignore; //0x0870
//    char pad_0874[12]; //0x0874
//    bool m_is_wanted; //0x0880
//    char pad_0881[7]; //0x0881
//    uint32_t m_wanted_level; //0x0888
//    uint32_t m_wanted_level_display; //0x088C
//    char pad_0890[1120]; //0x0890
//    float m_run_speed; //0x0CF0
//    float m_stamina; //0x0CF4
//    float m_stamina_regen; //0x0CF8
//    char pad_0CFC[16]; //0x0CFC
//    float m_weapon_damage_mult; //0x0D0C
//    float m_weapon_defence_mult; //0x0D10
//    char pad_0D14[4]; //0x0D14
//    float m_melee_weapon_damage_mult; //0x0D18
//    float m_melee_damage_mult; //0x0D1C
//    float m_melee_defence_mult; //0x0D20
//    char pad_0D24[8]; //0x0D24
//    float m_melee_weapon_defence_mult; //0x0D2C
//}; //Size: 0x0D30
