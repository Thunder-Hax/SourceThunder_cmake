#include "stdafx.h"
#include "Crash.h"

bool do_slod_crash = false;

Player crash_victim = 0;
bool spoof_weapon_vtable = false;

bool do_clone_crash[32] = { false };
uint64_t clone_crash_entity[32] = { 0 };

bool do_spam_crash[32] = { false };
uint64_t spam_crash_entity[32] = { 0 };


uint64_t get_model_info_ptr(uint32_t hash) {
	DWORD index = 0xFF;
	return g_GameFunctions->model_info(hash, &index);
}

Vehicle spawn_vehicle(Hash hash, Entity on_entity) {
	if (STREAMING::IS_MODEL_VALID(hash)) {
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
		Vector3 l_coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(on_entity, 0.0f, 0.0f, 0.0f);
		auto vehicle = VEHICLE::CREATE_VEHICLE(hash, l_coords.x, l_coords.y, l_coords.z, ENTITY::GET_ENTITY_HEADING(on_entity), TRUE, FALSE);
		int NetworkID = NETWORK::VEH_TO_NET(vehicle);
		VEHICLE::SET_VEHICLE_ENGINE_ON(vehicle, true, true, true);
		PED::SET_PED_INTO_VEHICLE(on_entity, vehicle, -1);
		if (ENTITY::IS_ENTITY_VISIBLE_TO_SCRIPT(vehicle)) {
			DECORATOR::DECOR_SET_INT(vehicle, "MPBitset", 0);
			DECORATOR::DECOR_SET_INT(vehicle, "Player_Vehicle", NETWORK::_NETWORK_HASH_FROM_PLAYER_HANDLE(on_entity));
			ENTITY::_SET_ENTITY_REGISTER(vehicle, TRUE);
			if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(vehicle)) NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NetworkID, true);
			VEHICLE::SET_VEHICLE_IS_STOLEN(vehicle, FALSE);
			return vehicle;
		}
	}
	return NULL;
}

void spawn_crash_vehicle(Ped ped, char* vehicle, int id1, int id2) {
	Hash hash = HASH::GET_HASH_KEY(vehicle);
	uint64_t model_info = get_model_info_ptr(hash);
	if (model_info != NULL) {
		*(int*)(model_info + 0x340) = id1;
		Vehicle vehicle = spawn_vehicle(hash, ped);
		if (ENTITY::DOES_ENTITY_EXIST(vehicle)) {
			ENTITY::SET_ENTITY_VISIBLE(vehicle, FALSE, FALSE);
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(vehicle);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 100.0f);
			WAIT(1000);
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(vehicle, 0, 1);
			VEHICLE::DELETE_VEHICLE(&vehicle);
		}
		*(int*)(model_info + 0x340) = id2;
	}
}

void slod_crash(Player p, char* model) {
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(ped, 1);
	Hash model1 = $(model);
	STREAMING::REQUEST_MODEL(model1);
	while (!STREAMING::HAS_MODEL_LOADED(model1)) WAIT(0);
	Ped crash1 = PED::CREATE_PED(26, model1, pos.x, pos.y, pos.z + 0.5, 0, 1, 0);
	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model1);
	/*PED::DELETE_PED(&crash1);*/
}

Ped spawn_ped(Hash hash, Vector3 coords, float heading) {
	if (STREAMING::IS_MODEL_VALID(hash)) {
		STREAMING::REQUEST_MODEL(hash);
		while (!STREAMING::HAS_MODEL_LOADED(hash)) WAIT(0);
		int l_nNetworkId = NETWORK::PED_TO_NET(PED::CREATE_PED(4, hash, coords.x, coords.y, coords.z, heading, TRUE, FALSE));
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(l_nNetworkId, TRUE);
		if (ENTITY::IS_ENTITY_VISIBLE_TO_SCRIPT(NETWORK::NET_TO_PED(l_nNetworkId)))
			return NETWORK::NET_TO_PED(l_nNetworkId);
	}
	return NULL;
}

Object spawn_object(Hash model, Vector3 coords, BOOL dynamic) {
	if (STREAMING::IS_MODEL_VALID(model)) {
		STREAMING::REQUEST_MODEL(model);
		while (!STREAMING::HAS_MODEL_LOADED(model)) WAIT(0);
		int l_network_id = NETWORK::OBJ_TO_NET(OBJECT::CREATE_OBJECT(model, coords.x, coords.y, coords.z, TRUE, FALSE, dynamic));
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(l_network_id, TRUE);
		if (ENTITY::IS_ENTITY_VISIBLE_TO_SCRIPT(NETWORK::NET_TO_OBJ(l_network_id))) {
			ENTITY::SET_ENTITY_ROTATION(NETWORK::NET_TO_OBJ(l_network_id), 0.0f, 0.0f, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 2, 1);
			ENTITY::FREEZE_ENTITY_POSITION(NETWORK::NET_TO_OBJ(l_network_id), true);
			DECORATOR::DECOR_SET_INT(NETWORK::NET_TO_OBJ(l_network_id), "bombdec", HASH::GET_HASH_KEY(Hooking::get_player_name(PLAYER::PLAYER_ID())));
			return NETWORK::NET_TO_OBJ(l_network_id);
		}
	}
	return NULL;
}
void Crasher::vehicle_crash(Player p) {
	crash_victim = p;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	if (ENTITY::DOES_ENTITY_EXIST(ped)) {
		spawn_crash_vehicle(ped, "adder", 8, 0);
		spawn_crash_vehicle(ped, "blazer", 11, 3);
		spawn_crash_vehicle(ped, "dinghy", 1, 13);
		spawn_crash_vehicle(ped, "zentorno", 8, 0);
	}
}

void Crasher::weapon_crash(Player p) {
	crash_victim = p;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	spoof_weapon_vtable = true;
	if (ENTITY::DOES_ENTITY_EXIST(ped))
		WEAPON::REMOVE_WEAPON_FROM_PED(ped, INT_MAX);
}

void Crasher::human_crash(Player p) {
	do_slod_crash = true;
	crash_victim = p;
	slod_crash(p, "slod_human");
}

void Crasher::quadped_crash(Player p) {
	do_slod_crash = true;
	crash_victim = p;
	slod_crash(p, "slod_large_quadped");
	slod_crash(p, "slod_small_quadped");
}

void Crasher::clone_crash(Player p) {
	crash_victim = p;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	if (!ENTITY::DOES_ENTITY_EXIST(ped)) return;
	Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0.0f, 0.0f, 0.0f);
	Ped target_ped = spawn_ped(HASH::GET_HASH_KEY("s_m_m_movalien_01"), coords, 0.0f);
	if (ENTITY::DOES_ENTITY_EXIST(target_ped)) {
		uint64_t target_entity = g_GameFunctions->get_entity_from_script_gu_id(target_ped);
		if (target_entity) {
			clone_crash_entity[p] = target_entity;
			do_clone_crash[p] = true;
		}
	}
}

void Crasher::spam_crash(Player p) {
	simple_timer spam_crash_timer;
	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(p);
	Vector3 coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ped, 0.0f, 0.0f, 0.0f);
	spam_crash_timer.start(1500);
	if (ENTITY::DOES_ENTITY_EXIST(ped)) {
		Vehicle vehicle = spawn_vehicle(HASH::GET_HASH_KEY("jet"), ped);
		if (ENTITY::DOES_ENTITY_EXIST(vehicle)) {
			VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(vehicle);
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehicle, 100.0f);
			VEHICLE::SET_VEHICLE_CAN_BREAK(vehicle, TRUE);
			VEHICLE::SET_VEHICLE_ENGINE_HEALTH(vehicle, 0.5f);
			ENTITY::SET_ENTITY_HEALTH(vehicle, 0);
			spam_crash_entity[p] = vehicle;
			do_spam_crash[p] = true;
			while (!spam_crash_timer.is_ready()) WAIT(0);
			spam_crash_timer.reset();
		}
	}
	spam_crash_timer.start(1500);
	if (ENTITY::DOES_ENTITY_EXIST(ped)) {
		Ped ped = spawn_ped(HASH::GET_HASH_KEY("s_m_m_movalien_01"), coords, 0.0f);
		if (ENTITY::DOES_ENTITY_EXIST(ped)) {
			spam_crash_entity[p] = ped;
			do_spam_crash[p] = true;
			while (!spam_crash_timer.is_ready()) WAIT(0);
			spam_crash_timer.reset();
		}
	}
	spam_crash_timer.start(1500);
	if (ENTITY::DOES_ENTITY_EXIST(ped)) {
		Object object = spawn_object(HASH::GET_HASH_KEY("prop_juicestand"), coords, FALSE);
		if (ENTITY::DOES_ENTITY_EXIST(object)) {
			spam_crash_entity[p] = object;
			do_spam_crash[p] = true;
			while (!spam_crash_timer.is_ready()) WAIT(0);
			spam_crash_timer.reset();
		}
	}
}




void loadA(char* animation)
{
	if (!STREAMING::HAS_ANIM_DICT_LOADED(animation))
	{
		STREAMING::REQUEST_ANIM_DICT(animation);
	}
}
void loadM(char* model)
{
	if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(model)) && !STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(model)))
	{
		STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(model));
	}
}

void request_() {
	loadA("move_m@brave");
	loadM("w_pi_pistol");

}

int Rr = 153;
int Rg = 102;
int Rb = 255;
int entityHit, PBone, Entity_Punch, _Mouvement;
BOOL hit__ = 0; BOOL hit2 = 0, on_wall_hit = 0;
Vector3 endCoords, endCoords2, surfaceNormal, arriveCoords;
int ray_result_, ray_result_2, wall_detected;
bool walkwalking = 0, on_wall = 0;
Vector3 CamRotationWall;
Object arrive_helper, wall_helper;
bool walkonwall::wall_walkingbool = 0;

bool walkonthewall = 0;
void walkonwall::wall_walking()
{
	bool opencontroller = (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, ControlFrontendRs) & 1);
	bool openf3 = (GetAsyncKeyState(VK_F5) & 1);
	if (openf3 || opencontroller)
	{
		walkonthewall = !walkonthewall;
	}
	if (walkonthewall)
	{
		Vector3 starting_p = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 ending_p = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.50, 0.0);
		float heading;
		GRAPHICS::DRAW_LINE(starting_p.x, starting_p.y, starting_p.z, ending_p.x, ending_p.y, ending_p.z, Rr, Rg, Rb, 255);

		int wall_ray = WORLDPROBE::_START_SHAPE_TEST_RAY(starting_p.x, starting_p.y, starting_p.z, ending_p.x, ending_p.y, ending_p.z, 1, PLAYER::PLAYER_PED_ID(), 7);
		WORLDPROBE::GET_SHAPE_TEST_RESULT(wall_ray, &hit__, &endCoords, &surfaceNormal, &wall_detected);

		if (hit__)
		{
			if (!ENTITY::DOES_ENTITY_EXIST(wall_helper))
			{
				wall_helper = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("w_pi_pistol"), endCoords.x, endCoords.y, endCoords.z, 1, 0, 0);
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(wall_helper, endCoords.x, endCoords.y, endCoords.z, 0, 0, 0);
				ENTITY::SET_ENTITY_COLLISION_(wall_helper, 0);
				ENTITY::FREEZE_ENTITY_POSITION(wall_helper, 1);
				ENTITY::SET_ENTITY_VISIBLE1(wall_helper, 0);

				heading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
				ENTITY::SET_ENTITY_HEADING(wall_helper, heading);

				ENTITY::ATTACH_ENTITY_TO_ENTITY(PLAYER::PLAYER_PED_ID(), wall_helper, -1, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 1);
				//AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), "move_crouch_proto", "idle_intro", 8.0, 0.0, -1, 1, 0, 0, 0, 0);
				on_wall = 1;
			}
		}

		if (ENTITY::DOES_ENTITY_EXIST(wall_helper))
		{
			Vector3 rot_ = ENTITY::GET_ENTITY_ROTATION(wall_helper, 2);
			ENTITY::SET_ENTITY_ROTATION(wall_helper, 89.0, rot_.y, rot_.z, 2, 1);
		}

		if (on_wall) {

			CAM::_CLAMP_GAMEPLAY_CAM_PITCH(-90.0, 90.0);

			Vector3 ending_p = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.35, -2.20); //-1.10
			int on_wall_ray = WORLDPROBE::_START_SHAPE_TEST_RAY(starting_p.x, starting_p.y, starting_p.z, ending_p.x, ending_p.y, ending_p.z, 1, PLAYER::PLAYER_PED_ID(), 7);
			WORLDPROBE::GET_SHAPE_TEST_RESULT(on_wall_ray, &on_wall_hit, &endCoords, &surfaceNormal, &wall_detected);

			GRAPHICS::DRAW_LINE(starting_p.x, starting_p.y, starting_p.z, ending_p.x, ending_p.y, ending_p.z, 0, 0, 255, 255);
			//if (IsKeyPressed(VK_KEY_A) || IsKeyPressed(VK_KEY_D) || IsKeyPressed(VK_KEY_W) || IsKeyPressed(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendLeft) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendRight) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown))
			if (IsKeyPressed(VK_KEY_W) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp))

				//if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, 193))
			{
				if (on_wall_hit)
				{
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(wall_helper, endCoords.x, endCoords.y, endCoords.z, 0, 0, 0);
					if (!ENTITY::IS_ENTITY_PLAYING_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 1)) {
						AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 8.0, 0.0, -1, 1, 0, 0, 0, 0);
					}
				}
				else {
					if (!ENTITY::DOES_ENTITY_EXIST(arrive_helper))
					{
						arrive_helper = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("w_pi_pistol"), endCoords.x, endCoords.y, endCoords.z, 1, 0, 1);
						ENTITY::SET_ENTITY_COLLISION_(arrive_helper, 0);
						ENTITY::FREEZE_ENTITY_POSITION(arrive_helper, 1);
						ENTITY::SET_ENTITY_VISIBLE1(arrive_helper, 0);
					}
					else {

						Vector3 dim_min, dim_max;
						float ground;

						GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()), &dim_min, &dim_max);
						Vector3 Position_ = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), dim_min.x, dim_min.y + 4.5, dim_min.z + 2.5f);
						ENTITY::SET_ENTITY_COORDS(arrive_helper, ending_p.x, ending_p.y, ending_p.z, 0, 0, 0, 1);

						Vector3 arrive_helper_coords = ENTITY::GET_ENTITY_COORDS(arrive_helper, 1);

						ENTITY::DELETE_ENTITY(&wall_helper);
						if (ENTITY::DOES_ENTITY_EXIST(arrive_helper))
						{
							ENTITY::DELETE_ENTITY(&arrive_helper);
						}

						GAMEPLAY::_GET_GROUND_Z_FOR_3D_COORD(arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z, &ground);
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z, 0, 0, 0, 1);
						//ENTITY::SET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID(), heading);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
						on_wall_hit = 0;
						on_wall = 0;
					}
				}
			}
			else
			{
				AI::STOP_ANIM_TASK(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 2.0);
			}
			if (IsKeyPressed(VK_KEY_S) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown))

				//if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, 193))
			{
				if (on_wall_hit)
				{
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(wall_helper, endCoords.x, endCoords.y, endCoords.z - 0.5f, 0, 0, 0);
					if (!ENTITY::IS_ENTITY_PLAYING_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 1)) {
						AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 8.0, 0.0, -1, 1, 0, 0, 0, 0);
					}
				}
				else {
					if (!ENTITY::DOES_ENTITY_EXIST(arrive_helper))
					{
						arrive_helper = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("w_pi_pistol"), endCoords.x, endCoords.y, endCoords.z, 1, 0, 1);
						ENTITY::SET_ENTITY_COLLISION_(arrive_helper, 0);
						ENTITY::FREEZE_ENTITY_POSITION(arrive_helper, 1);
						ENTITY::SET_ENTITY_VISIBLE1(arrive_helper, 0);
					}
					else {

						Vector3 dim_min, dim_max;
						float ground;

						/*GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()), &dim_min, &dim_max);
						Vector3 Position_ = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), dim_min.x, dim_min.y - 4.5, dim_min.z - 2.5f);*/
						ENTITY::SET_ENTITY_COORDS(arrive_helper, ending_p.x, ending_p.y, ending_p.z, 0, 0, 0, 1);

						Vector3 arrive_helper_coords = ENTITY::GET_ENTITY_COORDS(arrive_helper, 1);

						ENTITY::DELETE_ENTITY(&wall_helper);
						if (ENTITY::DOES_ENTITY_EXIST(arrive_helper))
						{
							ENTITY::DELETE_ENTITY(&arrive_helper);
						}

						GAMEPLAY::_GET_GROUND_Z_FOR_3D_COORD(arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z, &ground);
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z - 2, 0, 0, 0, 1);
						//ENTITY::SET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID(), heading);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
						on_wall_hit = 0;
						on_wall = 0;
					}
				}
			}
			else
			{
				AI::STOP_ANIM_TASK(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 2.0);
			}
			if (IsKeyPressed(VK_KEY_A) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown))

				//if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, 193))
			{
				if (on_wall_hit)
				{
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(wall_helper, endCoords.x, endCoords.y + 0.5f, endCoords.z, 0, 0, 0);
					if (!ENTITY::IS_ENTITY_PLAYING_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 1)) {
						AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 8.0, 0.0, -1, 1, 0, 0, 0, 0);
					}
				}
				else {
					if (!ENTITY::DOES_ENTITY_EXIST(arrive_helper))
					{
						arrive_helper = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("w_pi_pistol"), endCoords.x, endCoords.y, endCoords.z, 1, 0, 1);
						ENTITY::SET_ENTITY_COLLISION_(arrive_helper, 0);
						ENTITY::FREEZE_ENTITY_POSITION(arrive_helper, 1);
						ENTITY::SET_ENTITY_VISIBLE1(arrive_helper, 0);
					}
					else {

						Vector3 dim_min, dim_max;
						float ground;

						/*GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()), &dim_min, &dim_max);
						Vector3 Position_ = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), dim_min.x, dim_min.y - 4.5, dim_min.z - 2.5f);*/
						ENTITY::SET_ENTITY_COORDS(arrive_helper, ending_p.x, ending_p.y - 1, ending_p.z, 0, 0, 0, 1);

						Vector3 arrive_helper_coords = ENTITY::GET_ENTITY_COORDS(arrive_helper, 1);

						ENTITY::DELETE_ENTITY(&wall_helper);
						if (ENTITY::DOES_ENTITY_EXIST(arrive_helper))
						{
							ENTITY::DELETE_ENTITY(&arrive_helper);
						}

						GAMEPLAY::_GET_GROUND_Z_FOR_3D_COORD(arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z, &ground);
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z, 0, 0, 0, 1);
						//ENTITY::SET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID(), heading);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
						on_wall_hit = 0;
						on_wall = 0;
					}
				}
			}
			else
			{
				AI::STOP_ANIM_TASK(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 2.0);
			}
			if (IsKeyPressed(VK_KEY_D) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown))

				//if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, 193))
			{
				if (on_wall_hit)
				{
					ENTITY::SET_ENTITY_COORDS_NO_OFFSET(wall_helper, endCoords.x, endCoords.y - 0.5f, endCoords.z, 0, 0, 0);
					if (!ENTITY::IS_ENTITY_PLAYING_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 1)) {
						AI::TASK_PLAY_ANIM(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 8.0, 0.0, -1, 1, 0, 0, 0, 0);
					}
				}
				else {
					if (!ENTITY::DOES_ENTITY_EXIST(arrive_helper))
					{
						arrive_helper = OBJECT::CREATE_OBJECT(GAMEPLAY::GET_HASH_KEY("w_pi_pistol"), endCoords.x, endCoords.y, endCoords.z, 1, 0, 1);
						ENTITY::SET_ENTITY_COLLISION_(arrive_helper, 0);
						ENTITY::FREEZE_ENTITY_POSITION(arrive_helper, 1);
						ENTITY::SET_ENTITY_VISIBLE1(arrive_helper, 0);
					}
					else {

						Vector3 dim_min, dim_max;
						float ground;

						/*GAMEPLAY::GET_MODEL_DIMENSIONS(ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()), &dim_min, &dim_max);
						Vector3 Position_ = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), dim_min.x, dim_min.y - 4.5, dim_min.z - 2.5f);*/
						ENTITY::SET_ENTITY_COORDS(arrive_helper, ending_p.x, ending_p.y - 1, ending_p.z, 0, 0, 0, 1);

						Vector3 arrive_helper_coords = ENTITY::GET_ENTITY_COORDS(arrive_helper, 1);

						ENTITY::DELETE_ENTITY(&wall_helper);
						if (ENTITY::DOES_ENTITY_EXIST(arrive_helper))
						{
							ENTITY::DELETE_ENTITY(&arrive_helper);
						}

						GAMEPLAY::_GET_GROUND_Z_FOR_3D_COORD(arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z, &ground);
						ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), arrive_helper_coords.x, arrive_helper_coords.y, arrive_helper_coords.z, 0, 0, 0, 1);
						//ENTITY::SET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID(), heading);
						AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
						on_wall_hit = 0;
						on_wall = 0;
					}
				}
			}
			else
			{
				AI::STOP_ANIM_TASK(PLAYER::PLAYER_PED_ID(), "move_m@brave", "run", 2.0);
			}
			/*ControlFrontendRleft = 193,
				ControlFrontendRright = 194,*/

			if (IsKeyPressed(VK_LSHIFT) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && on_wall)
				//if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, 192) && on_wall)
			{
				ENTITY::DELETE_ENTITY(&wall_helper);
				if (ENTITY::DOES_ENTITY_EXIST(arrive_helper))
				{
					ENTITY::DELETE_ENTITY(&arrive_helper);
				}
				AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
				on_wall = 0;
			}

		}
	}
}

bool crashmenu::dis_my_phone = 0;
void crashmenu::NoPhone()
{
	if (crashmenu::dis_my_phone)
	{
		UI::HIDE_HELP_TEXT_THIS_FRAME();
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 176);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 161);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 165);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 163);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 164);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
		CONTROLS::SET_INPUT_EXCLUSIVE(0, 195);
		CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
	}
}
void SetMoneyAmmont()
{
	//Create variables for easy access later on
	Ped onlinePed = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer);
	int MoneyAmmount = 50000;

	PED::S_P_M_A(onlinePed, MoneyAmmount);
}

CPed* CHack::m_pCPedPlayer = nullptr;

//bool Features::DriveThroughWalls = false;
//void Features::DriveWalls()
//{
//	if (Features::DriveThroughWalls)
//	{
//		Vehicle vehicle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), TRUE);
//		ENTITY::SET_ENTITY_COLLISION(vehicle, FALSE, FALSE);
//		TEST::SET_VEHICLE_ON_GROUND_PROPERLY(vehicle);
//	}
//	else
//	{
//		NULL;
//	}
//}

//void crashmenu::loopupdate()
//{
//
//}


bool crashmenu::BPResZone = false;
void crashmenu::BypassResZone()
{
	if (crashmenu::BPResZone)
	{
		GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("am_armybase");
		GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("restrictedareas");
		GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("re_armybase");
		GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("re_lossantosintl");
		GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("re_prison");
		GAMEPLAY::TERMINATE_ALL_SCRIPTS_WITH_THIS_NAME("re_prisonvanbreak");
	}
}

void crashmenu::menucrash()
{
	Menu::Title((char*)langage::Weapons.c_str());
	headers::thunderheaders();
	Menu::Toggle("BPResZone", crashmenu::BPResZone);
	Menu::Toggle("dis_my_phone", crashmenu::dis_my_phone);
			if (Menu::Option("Who want's money?"))
			{
				for (int i = 0; i < 32; i++)
				{
					char* mgs = "Who want's money?";
					int handle[76];
					NETWORK::NETWORK_HANDLE_FROM_PLAYER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), &handle[0], 13);
					NETWORK::NETWORK_SEND_TEXT_MESSAGE(mgs, &handle[0]);
				}
			}
			if (Menu::Option("Good bye everyone!"))
			{
				for (int i = 0; i < 32; i++)
				{
					char* mgs = "Good bye everyone!";
					int handle[76];
					NETWORK::NETWORK_HANDLE_FROM_PLAYER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), &handle[0], 13);
					NETWORK::NETWORK_SEND_TEXT_MESSAGE(mgs, &handle[0]);
				}
			}
			if (Menu::Option("Restart First Scenario Load Prologue"))
			{
				NETWORK::SHUTDOWN_AND_LAUNCH_SINGLE_PLAYER_GAME();
			}
			if (Menu::Option("Break All"))
			{
				for (int i = 0; i < 32; ++i)
				{
					if (i == Features::playerme)
					{
					}
					if (i != Features::playerme)
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
						int getTimer = seconds;
						if (getTimer % 3 == 0)
						{
							if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
							BreakupKick(i);
						}
					}
				}
			}
			//if (Menu::Option("test 3"))
			//{
			//	/*int uParam0;
			//	int Var0[4];
			//	if (NETWORK::NETWORK_IS_HOST_OF_THIS_SCRIPT())
			//	{

			//		if (!SCRIPT::GET_EVENT_DATA(1, uParam0, &Var0, 7))
			//		{

			//		}
			//	}*/

			//	int freemode = *ScriptGlobal::ScriptGlobal(2697019).As<int*>();
			//	if (PLAYER::PLAYER_ID() == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0))
			//	{

			//	}




			//	for (int i = 0; i < 32; ++i)
			//	{
			//		int globaltest1 = *ScriptGlobal::ScriptGlobal(1669394).Add(792).As<int*>() = 1;

			//		int globaltest2 = *ScriptGlobal::ScriptGlobal(1669394).Add(504).As<int*>() = 1;

			//		int globaltest = *ScriptGlobal::ScriptGlobal(1935690).As<int*>() = GAMEPLAY::ABSI(15000000);
			//		std::uint64_t args_1[7] = { 1279059857, i, 8, globaltest1, globaltest2, globaltest, 1 };
			//		Hooking::trigger_script_event(1, args_1, 7, 1 << i);

			//		/*int offsettedID = i * 2 + 2;
			//		if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
			//		{
			//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(Hooking::get_player_ped(i, false);
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;
			//		}*/
			//	}
			//}
			//if (Menu::Option("test 4"))
			//{
			//	/*int uParam0;
			//	int Var0[4];
			//	if (NETWORK::NETWORK_IS_HOST_OF_THIS_SCRIPT())
			//	{

			//		if (!SCRIPT::GET_EVENT_DATA(1, uParam0, &Var0, 7))
			//		{

			//		}
			//	}*/
			//	*ScriptGlobal::ScriptGlobal(2697019).As<int*>();

			//	if (PLAYER::PLAYER_ID() == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0))
			//	{

			//	}




			//	for (int i = 0; i < 32; ++i)
			//	{
			//		int globaltest1 = *ScriptGlobal::ScriptGlobal(1669394).Add(792).As<int*>() = 1;

			//		int globaltest2 = *ScriptGlobal::ScriptGlobal(1669394).Add(504).As<int*>() = 1;

			//		int globaltest = *ScriptGlobal::ScriptGlobal(1935690).As<int*>() = GAMEPLAY::ABSI(15000000);
			//		std::uint64_t args_1[7] = { 1279059857, i, 8, globaltest, globaltest1, globaltest2, 1 };
			//		Hooking::trigger_script_event(1, args_1, 7, 1 << i);

			//		/*int offsettedID = i * 2 + 2;
			//		if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
			//		{
			//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(Hooking::get_player_ped(i, false);
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;
			//		}*/
			//	}
			//}
			//if (Menu::Option("test 5"))
			//{
			//	/*int uParam0;
			//	int Var0[4];
			//	if (NETWORK::NETWORK_IS_HOST_OF_THIS_SCRIPT())
			//	{

			//		if (!SCRIPT::GET_EVENT_DATA(1, uParam0, &Var0, 7))
			//		{

			//		}
			//	}*/


			//	*ScriptGlobal::ScriptGlobal(2697019).As<int*>();

			//	if (PLAYER::PLAYER_ID() == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0))
			//	{


			//	}




			//	for (int i = 0; i < 32; ++i)
			//	{
			//		int globaltest1 = *ScriptGlobal::ScriptGlobal(1669394).Add(792).As<int*>() = 1;

			//		int globaltest2 = *ScriptGlobal::ScriptGlobal(1669394).Add(504).As<int*>() = 1;

			//		int globaltest = *ScriptGlobal::ScriptGlobal(1935690).As<int*>() = GAMEPLAY::ABSI(15000000);
			//		std::uint64_t args_1[7] = { 1279059857, i, 8, globaltest, globaltest2, globaltest1, 1 };
			//		Hooking::trigger_script_event(1, args_1, 7, 1 << i);

			//		/*int offsettedID = i * 2 + 2;
			//		if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
			//		{
			//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(Hooking::get_player_ped(i, false);
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;
			//		}*/
			//	}
			//}
			//if (Menu::Option("test 6"))
			//{
			//	/*int uParam0;
			//	int Var0[4];
			//	if (NETWORK::NETWORK_IS_HOST_OF_THIS_SCRIPT())
			//	{

			//		if (!SCRIPT::GET_EVENT_DATA(1, uParam0, &Var0, 7))
			//		{

			//		}
			//	}*/

			//	*ScriptGlobal::ScriptGlobal(2697019).As<int*>();

			//	if (PLAYER::PLAYER_ID() == NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0))
			//	{


			//	}




			//	for (int i = 0; i < 32; ++i)
			//	{
			//		int globaltest1 = *ScriptGlobal::ScriptGlobal(1669394).Add(792).As<int*>() = 1;

			//		int globaltest2 = *ScriptGlobal::ScriptGlobal(1669394).Add(504).As<int*>() = 1;

			//		int globaltest = *ScriptGlobal::ScriptGlobal(1935690).As<int*>() = GAMEPLAY::ABSI(15000000);
			//		std::uint64_t args_1[7] = { 1279059857, i, 8, globaltest2, globaltest1, globaltest, 1 };
			//		Hooking::trigger_script_event(1, args_1, 7, 1 << i);

			//		/*int offsettedID = i * 2 + 2;
			//		if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
			//		{
			//			Vector3 coords = ENTITY::GET_ENTITY_COORDS(Hooking::get_player_ped(i, false);
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 3).As<float*>() = coords.x;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 4).As<float*>() = coords.y;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 5).As<float*>() = coords.z;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal1 + 1).As<int*>() = 2000;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal2 + (1 + *ScriptGlobal::ScriptGlobal(moneydropglobal1).As<int*>() * 85) + 66 + 2).As<int*>() = 2;
			//			*ScriptGlobal::ScriptGlobal(moneydropglobal3).As<int*>() = 1 << 0;
			//		}*/
			//	}
			//}
}