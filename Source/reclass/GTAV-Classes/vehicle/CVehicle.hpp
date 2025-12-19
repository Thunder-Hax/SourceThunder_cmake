#pragma once

#include "../entities/CPhysical.hpp"
#include "CHandlingData.hpp"

#include <cstdint>
#include <cmath>
class CDeformation
{
public:
	char pad_0000[732]; //0x0000
}; //Size: 0x02DC
//static_assert(sizeof(CDeformation) == 0x2DC);
class CVehicleDamage
{
public:
	char pad_0000[16]; //0x0000
	class CDeformation m_deformation; //0x0010
	char pad_02EC[284]; //0x02EC
	class CVehicle* m_vehicle; //0x0408
	float m_body_health; //0x0410
	float m_petrol_tank_health; //0x0414
}; //Size: 0x0418
//static_assert(sizeof(CVehicleDamage) == 0x418);
class CVehicle : public rage::CPhysical
{
public:
	char pad_02EC[12]; //0x02EC
	bool m_boosting; //0x02F8
	char pad_02F9[2]; //0x02F9
	bool m_boost_allow_recharge; //0x02FB
	char pad_02FC[4]; //0x02FC
	float m_boost; //0x0300
	float m_rocket_recharge_speed; //0x0304
	char pad_0308[152]; //0x0308
	float m_jump_boost_charge; //0x03A0
	bool m_can_boost_jump; //0x03A4
	char pad_03A5[123]; //0x03A5
	class CVehicleDamage m_vehicle_damage; //0x0420
	char pad_0838[72]; //0x0838
	int16_t m_next_gear; //0x0880
	int16_t m_current_gear; //0x0882
	char pad_0884[2]; //0x0884
	int8_t m_top_gear; //0x0886
	char pad_0887[137]; //0x0887
	float m_engine_health; //0x0910
	char pad_0914[24]; //0x0914
	float m_kers_boost_max; //0x092C
	float m_kers_boost; //0x0930
	char pad_0934[44]; //0x0934
	class CHandlingData* m_handling_data; //0x0960
	char pad_0968[2]; //0x0968
	uint8_t m_drivable_bitset; //0x096A
	uint8_t m_tyre_burst_bitset; //0x096B
	uint8_t m_deform_god; //0x096C
	char pad_096D[179]; //0x096D
	float m_dirt_level; //0x0A20
	char pad_0A24[202]; //0x0A24
	bool m_is_targetable; //0x0AEE
	char pad_0AEF[297]; //0x0AEF
	uint32_t m_gravity_state; //0x0C18
	char pad_0C1C[112]; //0x0C1C
	float m_gravity; //0x0C8C
	uint8_t m_max_passengers; //0x0C90
	char pad_0C91[1]; //0x0C91
	uint8_t m_num_of_passengers; //0x0C92
	char pad_0C93[5]; //0x0C93
	class CPed* m_driver; //0x0C98
	class CPed* m_passengers[15]; //0x0CA0
	class CPed* m_last_driver; //0x0D18
	char pad_0D20[1696]; //0x0D20
	uint32_t m_door_lock_status; //0x13C0
	char pad_13C4[2356]; //0x13C4
}; //Size: 0x1CF8
// #pragma pack(push, 1)
//class CVehicle : public rage::CPhysical
//{
//public:
//    char pad_02EC[0xC]; //0x02EC
//    uint8_t m_boost_state; //0x02F8
//    char pad_02F9[0x2]; //0x02F9
//    uint8_t m_boost_allow_recharge; //0x02FB
//    char pad_02FC[0x4]; //0x02FC
//    float m_boost; //0x0300
//    float m_rocket_recharge_speed; //0x304
//    char pad_0308[0x88]; //0x0308
//    float m_jump_boost_charge; //0x0390
//    char pad_0394[0x43C]; //0x0394
//    rage::fvector3 m_velocity; //0x07D0
//    char pad_07DC[0x44]; //0x07DC
//    float m_body_health; //0x0820
//    float m_petrol_tank_health; //0x0824
//    char pad_0x828[0xC0]; //0x0828
//    float m_engine_health; //0x08E8
//    char pad_08EC[0x2C]; //0x08EC
//    CHandlingData* m_handling_data; //0x0918
//    char pad_0920[0x2]; //0x0920
//    uint8_t m_is_drivable; //0x0922
//    uint8_t m_tyres_can_burst; //0x0923
//    uint8_t m_deform_god; //0x0924
//    char pad_0925[0xB3]; //0x0925
//    float m_dirt_level; //0x09D8
//    char pad_09DC[0xC2]; //0x09DC
//    uint8_t m_is_targetable; //0x0A9E
//    char pad_0A9F[0x19D]; //0x0A9F
//    float m_gravity; //0x0C3C - might be start of some sub-class
//    uint8_t m_max_passengers; //0x0C40
//    char pad_0C41; //0x0C41
//    uint8_t m_num_of_passengers; //0x0C42
//    char pad_0C43[5]; //0x0C43
//    class CPed* m_driver; //0x0C48
//    class CPed* m_passengers[15]; //0x0C50
//    class CPed* m_last_driver; //0x0CC8
//    char pad_0CD0[0x6A0]; //0x0CD0
//    uint32_t m_door_lock_status; //0x1370
//    char pad_1374[0xDC]; //0x1374
//
//    float get_speed() { return sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y + m_velocity.z * m_velocity.z); }
//};
// static_assert(sizeof(CVehicle) == 0x1450);
// #pragma pack(pop)

