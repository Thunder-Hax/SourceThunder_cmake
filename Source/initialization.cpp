#pragma once
#include "stdafx.h"
#pragma warning(disable:4996)
//#include <Windows.h>
//#include <vector>
//#include <unordered_set>
//#include <map>
#include "..\Source\ExePath.h"

#include <iostream> 
#include <string> 
#include <sstream>
#include <fstream> 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <functional>

#include "..\Source\GUI.h"

#include "Language.h"

string initialize::Sounds1 = "Hack_Failed";
string initialize::Sounds2 = "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS";

int initialize::soundsauth(string authsounds) {
	if (authsounds == "10s") {
		initialize::Sounds1 = "10s";
		initialize::Sounds2 = "MP_MISSION_COUNTDOWN_SOUNDSET";
	}
	if (authsounds == "1st_Person_Transition") {
		initialize::Sounds1 = "1st_Person_Transition";
		initialize::Sounds2 = "PLAYER_SWITCH_CUSTOM_SOUNDSET";
	}
	if (authsounds == "3_2_1") {
		initialize::Sounds1 = "3_2_1";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "3_2_1_NON_RACE") {
		initialize::Sounds1 = "3_2_1_NON_RACE";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "5_SEC_WARNING") {
		initialize::Sounds1 = "5_SEC_WARNING";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "5_Second_Timer") {
		initialize::Sounds1 = "5_Second_Timer";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "5s") {
		initialize::Sounds1 = "5s";
		initialize::Sounds2 = "MP_MISSION_COUNTDOWN_SOUNDSET";
	}
	if (authsounds == "5s_To_Event_Start_Countdown") {
		initialize::Sounds1 = "5s_To_Event_Start_Countdown";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Apt_Style_Purchase") {
		initialize::Sounds1 = "Apt_Style_Purchase";
		initialize::Sounds2 = "DLC_APT_Apartment_SoundSet";
	}
	if (authsounds == "ARM_3_CAR_GLASS_CRASH") {
		initialize::Sounds1 = "ARM_3_CAR_GLASS_CRASH";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "ARM_3_PISTOL_COCK") {
		initialize::Sounds1 = "ARM_3_PISTOL_COCK";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "ARM_WRESTLING_WHOOSH_MASTER") {
		initialize::Sounds1 = "ARM_WRESTLING_WHOOSH_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "Arming_Countdown") {
		initialize::Sounds1 = "Arming_Countdown";
		initialize::Sounds2 = "GTAO_Speed_Convoy_Soundset";
	}
	if (authsounds == "ASSASSINATIONS_HOTEL_TIMER_COUNTDOWN") {
		initialize::Sounds1 = "ASSASSINATIONS_HOTEL_TIMER_COUNTDOWN";
		initialize::Sounds2 = "ASSASSINATION_MULTI";
	}
	if (authsounds == "ATM_WINDOW") {
		initialize::Sounds1 = "ATM_WINDOW";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Arming_Countdown") {
		initialize::Sounds1 = "Arming_Countdown";
		initialize::Sounds2 = "GTAO_Speed_Convoy_Soundset";
	}
	if (authsounds == "BACK1") {
		initialize::Sounds1 = "BACK";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "BACK2") {
		initialize::Sounds1 = "BACK";
		initialize::Sounds2 = "HUD_FREEMODE_SOUNDSET";
	}
	if (authsounds == "BACK3") {
		initialize::Sounds1 = "BACK";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "BACK4") {
		initialize::Sounds1 = "BACK";
		initialize::Sounds2 = "HUD_FRONTEND_MP_SOUNDSET";
	}
	if (authsounds == "BACK5") {
		initialize::Sounds1 = "BACK";
		initialize::Sounds2 = "HUD_FRONTEND_TATTOO_SHOP_SOUNDSET";
	}
	if (authsounds == "BACK6") {
		initialize::Sounds1 = "BACK";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Banshee2_Upgrade") {
		initialize::Sounds1 = "Banshee2_Upgrade";
		initialize::Sounds2 = "JA16_Super_Mod_Garage_Sounds";
	}
	if (authsounds == "BASE_JUMP_PASSED") {
		initialize::Sounds1 = "BASE_JUMP_PASSED";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "Beast_Checkpoint") {
		initialize::Sounds1 = "Beast_Checkpoint";
		initialize::Sounds2 = "APT_BvS_Soundset";
	}
	if (authsounds == "Beast_Checkpoint_NPC") {
		initialize::Sounds1 = "Beast_Checkpoint_NPC ";
		initialize::Sounds2 = "APT_BvS_Soundset";
	}
	if (authsounds == "Bed") {
		initialize::Sounds1 = "Bed";
		initialize::Sounds2 = "WastedSounds";
	}
	if (authsounds == "Beep_Green") {
		initialize::Sounds1 = "Beep_Green";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "Beep_Red") {
		initialize::Sounds1 = "Beep_Red";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "Blade_Appear") {
		initialize::Sounds1 = "Blade_Appear";
		initialize::Sounds2 = "APT_BvS_Soundset";
	}
	if (authsounds == "BOATS_PLANES_HELIS_BOOM") {
		initialize::Sounds1 = "BOATS_PLANES_HELIS_BOOM";
		initialize::Sounds2 = "MP_LOBBY_SOUNDS";
	}
	if (authsounds == "Bomb_Disarmed") {
		initialize::Sounds1 = "Bomb_Disarmed";
		initialize::Sounds2 = "GTAO_Speed_Convoy_Soundset ";
	}
	if (authsounds == "Boss_Blipped") {
		initialize::Sounds1 = "Boss_Blipped";
		initialize::Sounds2 = "GTAO_Magnate_Hunt_Boss_SoundSet";
	}
	if (authsounds == "Boss_Message_Orange") {
		initialize::Sounds1 = "Boss_Message_Orange";
		initialize::Sounds2 = "GTAO_Boss_Goons_FM_Soundset";
	}
	if (authsounds == "Breaker_01") {
		initialize::Sounds1 = "Breaker_01";
		initialize::Sounds2 = "DLC_HALLOWEEN_FVJ_Sounds";
	}
	if (authsounds == "Breaker_02") {
		initialize::Sounds1 = "Breaker_02";
		initialize::Sounds2 = "DLC_HALLOWEEN_FVJ_Sounds";
	}
	if (authsounds == "BULL_SHARK_TESTOSTERONE_END_MASTER") {
		initialize::Sounds1 = "BULL_SHARK_TESTOSTERONE_END_MASTER";
		initialize::Sounds2 = "";
	}
	if (authsounds == "BULL_SHARK_TESTOSTERONE_START_MASTER") {
		initialize::Sounds1 = "BULL_SHARK_TESTOSTERONE_START_MASTER";
		initialize::Sounds2 = "";
	}
	if (authsounds == "Bus_Schedule_Pickup") {
		initialize::Sounds1 = "Bus_Schedule_Pickup";
		initialize::Sounds2 = "DLC_PRISON_BREAK_HEIST_SOUNDS";
	}
	if (authsounds == "CABLE_SNAPS") {
		initialize::Sounds1 = "CABLE_SNAPS";
		initialize::Sounds2 = "CONSTRUCTION_ACCIDENT_1_SOUNDS";
	}
	if (authsounds == "CAM_PAN_DARTS") {
		initialize::Sounds1 = "CAM_PAN_DARTS";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Camera_Shoot") {
		initialize::Sounds1 = "Camera_Shoot";
		initialize::Sounds2 = "Phone_Soundset_Franklin";
	}
	if (authsounds == "CANCEL1") {
		initialize::Sounds1 = "CANCEL";
		initialize::Sounds2 = "HUD_FREEMODE_SOUNDSET";
	}
	if (authsounds == "CANCEL2") {
		initialize::Sounds1 = "CANCEL";
		initialize::Sounds2 = "HUD_FRONTEND_CLOTHESSHOP_SOUNDSET";
	}
	if (authsounds == "CANCEL3") {
		initialize::Sounds1 = "CANCEL";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "CANCEL4") {
		initialize::Sounds1 = "CANCEL";
		initialize::Sounds2 = "HUD_LIQUOR_STORE_SOUNDSET";
	}
	if (authsounds == "CANCEL5") {
		initialize::Sounds1 = "CANCEL";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "CAR_BIKE_WHOOSH") {
		initialize::Sounds1 = "CAR_BIKE_WHOOSH";
		initialize::Sounds2 = "MP_LOBBY_SOUNDS";
	}
	if (authsounds == "CHALLENGE_UNLOCKED") {
		initialize::Sounds1 = "CHALLENGE_UNLOCKED";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "CHARACTER_SELECT") {
		initialize::Sounds1 = "CHARACTER_SELECT";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "CHECKPOINT_AHEAD") {
		initialize::Sounds1 = "CHECKPOINT_AHEAD";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Checkpoint_Beast_Hit") {
		initialize::Sounds1 = "Checkpoint_Beast_Hit";
		initialize::Sounds2 = "FM_Events_Sasquatch_Sounds";
	}
	if (authsounds == "CHECKPOINT_BEHIND") {
		initialize::Sounds1 = "CHECKPOINT_BEHIND";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Checkpoint_Cash_Hit") {
		initialize::Sounds1 = "Checkpoint_Cash_Hit";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Checkpoint_Hit") {
		initialize::Sounds1 = "Checkpoint_Hit";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "CHECKPOINT_MISSED") {
		initialize::Sounds1 = "CHECKPOINT_MISSED";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "CHECKPOINT_NORMAL") {
		initialize::Sounds1 = "CHECKPOINT_NORMAL";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "CHECKPOINT_PERFECT") {
		initialize::Sounds1 = "CHECKPOINT_PERFECT";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Checkpoint_Teammate") {
		initialize::Sounds1 = "Checkpoint_Teammate";
		initialize::Sounds2 = "GTAO_Shepherd_Sounds";
	}
	if (authsounds == "CHECKPOINT_UNDER_THE_BRIDGE") {
		initialize::Sounds1 = "CHECKPOINT_UNDER_THE_BRIDGE";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Cheers") {
		initialize::Sounds1 = "Cheers";
		initialize::Sounds2 = "DLC_TG_Running_Back_Sounds";
	}
	if (authsounds == "Click") {
		initialize::Sounds1 = "Click";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "CLICK_BACK") {
		initialize::Sounds1 = "CLICK_BACK";
		initialize::Sounds2 = "WEB_NAVIGATION_SOUNDS_PHONE";
	}
	if (authsounds == "Click_Fail") {
		initialize::Sounds1 = "Click_Fail";
		initialize::Sounds2 = "WEB_NAVIGATION_SOUNDS_PHONE";
	}
	if (authsounds == "Click_Special") {
		initialize::Sounds1 = "Click_Special";
		initialize::Sounds2 = "WEB_NAVIGATION_SOUNDS_PHONE";
	}
	if (authsounds == "CLOSE_WINDOW") {
		initialize::Sounds1 = "CLOSE_WINDOW";
		initialize::Sounds2 = "LESTER1A_SOUNDS";
	}
	if (authsounds == "CLOSED1") {
		initialize::Sounds1 = "CLOSED";
		initialize::Sounds2 = "DLC_APT_YACHT_DOOR_SOUNDS";
	}
	if (authsounds == "CLOSED2") {
		initialize::Sounds1 = "CLOSED";
		initialize::Sounds2 = "MP_PROPERTIES_ELEVATOR_DOORS";
	}
	if (authsounds == "COMPUTERS_MOUSE_CLICK") {
		initialize::Sounds1 = "COMPUTERS_MOUSE_CLICK";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "CONFIRM_BEEP") {
		initialize::Sounds1 = "CONFIRM_BEEP";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "CONTINUE") {
		initialize::Sounds1 = "CONTINUE";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Continue_Accepted") {
		initialize::Sounds1 = "Continue_Accepted";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Continue_Appears") {
		initialize::Sounds1 = "Continue_Appears";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Crash") {
		initialize::Sounds1 = "Crash";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "Criminal_Damage_High_Value") {
		initialize::Sounds1 = "Criminal_Damage_High_Value";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Criminal_Damage_Kill_Player") {
		initialize::Sounds1 = "Criminal_Damage_Kill_Player";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Criminal_Damage_Low_Value") {
		initialize::Sounds1 = "Criminal_Damage_Low_Value";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "CUTSCENE_DIALOGUE_OVERRIDE_SOUND_01") {
		initialize::Sounds1 = "CUTSCENE_DIALOGUE_OVERRIDE_SOUND_01";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "CUTSCENE_DIALOGUE_OVERRIDE_SOUND_02") {
		initialize::Sounds1 = "CUTSCENE_DIALOGUE_OVERRIDE_SOUND_02";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "Cycle_Item") {
		initialize::Sounds1 = "Cycle_Item";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "DELETE") {
		initialize::Sounds1 = "DELETE";
		initialize::Sounds2 = "HUD_DEATHMATCH_SOUNDSET";
	}
	if (authsounds == "Delete_Placed_Prop") {
		initialize::Sounds1 = "Delete_Placed_Prop";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "Deliver_Pick_Up") {
		initialize::Sounds1 = "Deliver_Pick_Up";
		initialize::Sounds2 = "HUD_FRONTEND_MP_COLLECTABLE_SOUNDS";
	}
	if (authsounds == "DiggerRevOneShot") {
		initialize::Sounds1 = "DiggerRevOneShot";
		initialize::Sounds2 = "BulldozerDefault";
	}
	if (authsounds == "Door_Open") {
		initialize::Sounds1 = "Door_Open";
		initialize::Sounds2 = "DOCKS_HEIST_FINALE_2B_SOUNDS";
	}
	if (authsounds == "Drill_Pin_Break") {
		initialize::Sounds1 = "Drill_Pin_Break";
		initialize::Sounds2 = "DLC_HEIST_FLEECA_SOUNDSET";
	}
	if (authsounds == "Dropped") {
		initialize::Sounds1 = "Dropped";
		initialize::Sounds2 = "HUD_FRONTEND_MP_COLLECTABLE_SOUNDS";
	}
	if (authsounds == "DRUG_TRAFFIC_AIR_BOMB_DROP_ERROR_MASTER") {
		initialize::Sounds1 = "DRUG_TRAFFIC_AIR_BOMB_DROP_ERROR_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "DRUG_TRAFFIC_AIR_SCREAMS") {
		initialize::Sounds1 = "DRUG_TRAFFIC_AIR_SCREAMS";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "EDIT") {
		initialize::Sounds1 = "EDIT";
		initialize::Sounds2 = "HUD_DEATHMATCH_SOUNDSET";
	}
	if (authsounds == "End_Squelch") {
		initialize::Sounds1 = "End_Squelch";
		initialize::Sounds2 = "CB_RADIO_SFX";
	}
	if (authsounds == "Enemy_Capture_Start") {
		initialize::Sounds1 = "Enemy_Capture_Start";
		initialize::Sounds2 = "GTAO_Magnate_Yacht_Attack_Soundset";
	}
	if (authsounds == "Enemy_Deliver") {
		initialize::Sounds1 = "Enemy_Deliver";
		initialize::Sounds2 = "HUD_FRONTEND_MP_COLLECTABLE_SOUNDS";
	}
	if (authsounds == "Enemy_Pick_Up") {
		initialize::Sounds1 = "Enemy_Pick_Up";
		initialize::Sounds2 = "HUD_FRONTEND_MP_COLLECTABLE_SOUNDS";
	}
	if (authsounds == "Enter_1st1") {
		initialize::Sounds1 = "Enter_1st";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Enter_1st2") {
		initialize::Sounds1 = "Enter_1st";
		initialize::Sounds2 = "GTAO_Magnate_Boss_Modes_Soundset";
	}
	if (authsounds == "Enter_Area") {
		initialize::Sounds1 = "Enter_Area";
		initialize::Sounds2 = "DLC_Lowrider_Relay_Race_Sounds";
	}
	if (authsounds == "Enter_Capture_Zone") {
		initialize::Sounds1 = "Enter_Capture_Zone";
		initialize::Sounds2 = "DLC_Apartments_Drop_Zone_Sounds";
	}
	if (authsounds == "ERROR1") {
		initialize::Sounds1 = "ERROR";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "ERROR2") {
		initialize::Sounds1 = "ERROR";
		initialize::Sounds2 = "HUD_FRONTEND_CLOTHESSHOP_SOUNDSET";
	}
	if (authsounds == "ERROR3") {
		initialize::Sounds1 = "ERROR";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "ERROR4") {
		initialize::Sounds1 = "ERROR";
		initialize::Sounds2 = "HUD_FRONTEND_TATTOO_SHOP_SOUNDSET";
	}
	if (authsounds == "ERROR5") {
		initialize::Sounds1 = "ERROR";
		initialize::Sounds2 = "HUD_LIQUOR_STORE_SOUNDSET";
	}
	if (authsounds == "Event_Message_Purple") {
		initialize::Sounds1 = "Event_Message_Purple";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Event_Start_Text") {
		initialize::Sounds1 = "Event_Start_Text";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "EXILE_3_TRAIN_BRAKE_PULL_MASTER") {
		initialize::Sounds1 = "EXILE_3_TRAIN_BRAKE_PULL_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "EXILE_3_TRAIN_BRAKE_RELEASE_MASTER") {
		initialize::Sounds1 = "EXILE_3_TRAIN_BRAKE_RELEASE_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "EXIT") {
		initialize::Sounds1 = "EXIT";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Exit_Capture_Zone") {
		initialize::Sounds1 = "Exit_Capture_Zone";
		initialize::Sounds2 = "DLC_Apartments_Drop_Zone_Sounds";
	}
	if (authsounds == "Failure") {
		initialize::Sounds1 = "Failure";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "Falling_Crates") {
		initialize::Sounds1 = "Falling_Crates";
		initialize::Sounds2 = "EXILE_1";
	}
	if (authsounds == "FAMILY_1_CAR_BREAKDOWN") {
		initialize::Sounds1 = "FAMILY_1_CAR_BREAKDOWN";
		initialize::Sounds2 = "FAMILY1_BOAT";
	}
	if (authsounds == "FAMILY_1_CAR_BREAKDOWN_ADDITIONAL") {
		initialize::Sounds1 = "FAMILY_1_CAR_BREAKDOWN_ADDITIONAL";
		initialize::Sounds2 = "FAMILY1_BOAT";
	}
	if (authsounds == "Faster_Bar_Full") {
		initialize::Sounds1 = "Faster_Bar_Full";
		initialize::Sounds2 = "RESPAWN_ONLINE_SOUNDSET";
	}
	if (authsounds == "Faster_Click") {
		initialize::Sounds1 = "Faster_Click";
		initialize::Sounds2 = "RESPAWN_ONLINE_SOUNDSET";
	}
	if (authsounds == "FestiveGift") {
		initialize::Sounds1 = "FestiveGift";
		initialize::Sounds2 = "Feed_Message_Sounds";
	}
	if (authsounds == "FIRST_PLACE") {
		initialize::Sounds1 = "FIRST_PLACE";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "FLIGHT_SCHOOL_LESSON_PASSED") {
		initialize::Sounds1 = "FLIGHT_SCHOOL_LESSON_PASSED";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "FLYING_STREAM_END_INSTANT") {
		initialize::Sounds1 = "FLYING_STREAM_END_INSTANT";
		initialize::Sounds2 = "FAMILY_5_SOUNDS";
	}
	if (authsounds == "FocusIn") {
		initialize::Sounds1 = "FocusIn";
		initialize::Sounds2 = "HintCamSounds";
	}
	if (authsounds == "FocusOut") {
		initialize::Sounds1 = "FocusOut";
		initialize::Sounds2 = "HintCamSounds";
	}
	if (authsounds == "Friend_Deliver") {
		initialize::Sounds1 = "Friend_Deliver";
		initialize::Sounds2 = "HUD_FRONTEND_MP_COLLECTABLE_SOUNDS";
	}
	if (authsounds == "Friend_Pick_Up") {
		initialize::Sounds1 = "Friend_Pick_Up";
		initialize::Sounds2 = "HUD_FRONTEND_MP_COLLECTABLE_SOUNDS";
	}
	if (authsounds == "Frontend_Beast_Fade_Screen") {
		initialize::Sounds1 = "Frontend_Beast_Fade_Screen";
		initialize::Sounds2 = "FM_Events_Sasquatch_Sounds";
	}
	if (authsounds == "Frontend_Beast_Freeze_Screen") {
		initialize::Sounds1 = "Frontend_Beast_Freeze_Scree";
		initialize::Sounds2 = "FM_Events_Sasquatch_Sounds";
	}
	if (authsounds == "Frontend_Beast_Text_Hit") {
		initialize::Sounds1 = "Frontend_Beast_Text_Hit";
		initialize::Sounds2 = "FM_Events_Sasquatch_Sounds";
	}
	if (authsounds == "Frontend_Beast_Transform_Back") {
		initialize::Sounds1 = "Frontend_Beast_Transform_Back";
		initialize::Sounds2 = "FM_Events_Sasquatch_Sounds";
	}
	if (authsounds == "GO") {
		initialize::Sounds1 = "GO";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "GO_NON_RACE") {
		initialize::Sounds1 = "GO_NON_RACE";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Goal") {
		initialize::Sounds1 = "Goal";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "GOLF_BIRDIE") {
		initialize::Sounds1 = "GOLF_BIRDIE";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "GOLF_EAGLE") {
		initialize::Sounds1 = "GOLF_EAGLE";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "GOLF_HUD_HOLE_IN_ONE_MASTER") {
		initialize::Sounds1 = "GOLF_HUD_HOLE_IN_ONE_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "GOLF_NEW_RECORD") {
		initialize::Sounds1 = "GOLF_NEW_RECORD";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "Goon_Paid_Small") {
		initialize::Sounds1 = "Goon_Paid_Small";
		initialize::Sounds2 = "GTAO_Boss_Goons_FM_Soundset";
	}
	if (authsounds == "Grab_Parachute") {
		initialize::Sounds1 = "Grab_Parachute";
		initialize::Sounds2 = "BASEJUMPS_SOUNDS";
	}
	if (authsounds == "Hack_Failed") {
		initialize::Sounds1 = "Hack_Failed";
		initialize::Sounds2 = "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS";
	}
	if (authsounds == "Hack_Success") {
		initialize::Sounds1 = "Hack_Success";
		initialize::Sounds2 = "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS";
	}
	if (authsounds == "HACKING_CLICK") {
		initialize::Sounds1 = "HACKING_CLICK";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "HACKING_CLICK_BAD") {
		initialize::Sounds1 = "HACKING_CLICK_BAD";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "HACKING_CLICK_GOOD") {
		initialize::Sounds1 = "HACKING_CLICK_GOOD";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "HACKING_FAILURE") {
		initialize::Sounds1 = "HACKING_FAILURE";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "HACKING_MOVE_CURSOR") {
		initialize::Sounds1 = "HACKING_MOVE_CURSOR";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "HACKING_SUCCESS") {
		initialize::Sounds1 = "HACKING_SUCCESS";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "Hang_Up") {
		initialize::Sounds1 = "Hang_Up";
		initialize::Sounds2 = "Phone_SoundSet_Michael";
	}
	if (authsounds == "HIGHLIGHT") {
		initialize::Sounds1 = "HIGHLIGHT";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Highlight_Accept") {
		initialize::Sounds1 = "Highlight_Accept";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Highlight_Cancel") {
		initialize::Sounds1 = "Highlight_Cancel";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Highlight_Error") {
		initialize::Sounds1 = "Highlight_Error";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Highlight_Move") {
		initialize::Sounds1 = "Highlight_Move";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "HIGHLIGHT_NAV_UP_DOWN") {
		initialize::Sounds1 = "HIGHLIGHT_NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Hit1") {
		initialize::Sounds1 = "Hit";
		initialize::Sounds2 = "RESPAWN_ONLINE_SOUNDSET";
	}
	if (authsounds == "Hit2") {
		initialize::Sounds1 = "Hit";
		initialize::Sounds2 = "RESPAWN_SOUNDSET";
	}
	if (authsounds == "Hit_1") {
		initialize::Sounds1 = "Hit_1";
		initialize::Sounds2 = "LONG_PLAYER_SWITCH_SOUNDS";
	}
	if (authsounds == "Hit_In") {
		initialize::Sounds1 = "Hit_In";
		initialize::Sounds2 = "PLAYER_SWITCH_CUSTOM_SOUNDSET";
	}
	if (authsounds == "Hit_Out") {
		initialize::Sounds1 = "Hit_Out";
		initialize::Sounds2 = "PLAYER_SWITCH_CUSTOM_SOUNDSET";
	}
	if (authsounds == "HOORAY") {
		initialize::Sounds1 = "HOORAY";
		initialize::Sounds2 = "BARRY_02_SOUNDSET";
	}
	if (authsounds == "HORDE_COOL_DOWN_TIMER") {
		initialize::Sounds1 = "HORDE_COOL_DOWN_TIMER";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "HUD_FREEMODE_CANCEL_MASTER") {
		initialize::Sounds1 = "HUD_FREEMODE_CANCEL_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "Kill_List_Counter") {
		initialize::Sounds1 = "Kill_List_Counter";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "LAMAR1_PARTYGIRLS_master") {
		initialize::Sounds1 = "LAMAR1_PARTYGIRLS_master";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "LEADER_BOARD") {
		initialize::Sounds1 = "LEADER_BOARD";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "LEADER_BOARD") {
		initialize::Sounds1 = "LEADER_BOARD";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Lester_Laugh_Phone") {
		initialize::Sounds1 = "Lester_Laugh_Phone";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "Lights_On") {
		initialize::Sounds1 = "Lights_On";
		initialize::Sounds2 = "GTAO_MUGSHOT_ROOM_SOUNDS";
	}
	if (authsounds == "LIMIT1") {
		initialize::Sounds1 = "LIMIT";
		initialize::Sounds2 = "DLC_APT_YACHT_DOOR_SOUNDS";
	}
	if (authsounds == "LIMIT2") {
		initialize::Sounds1 = "LIMIT";
		initialize::Sounds2 = "GTAO_APT_DOOR_DOWNSTAIRS_GLASS_SOUNDS";
	}
	if (authsounds == "LIMIT3") {
		initialize::Sounds1 = "LIMIT";
		initialize::Sounds2 = "GTAO_APT_DOOR_DOWNSTAIRS_WOOD_SOUNDS";
	}
	if (authsounds == "Load_Scene") {
		initialize::Sounds1 = "Load_Scene";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "LOCAL_PLYR_CASH_COUNTER_COMPLETE") {
		initialize::Sounds1 = "LOCAL_PLYR_CASH_COUNTER_COMPLETE";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "LOOSE_MATCH") {
		initialize::Sounds1 = "LOOSE_MATCH";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Lose_1st1") {
		initialize::Sounds1 = "Lose_1st";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Lose_1st2") {
		initialize::Sounds1 = "Lose_1st";
		initialize::Sounds2 = "GTAO_Magnate_Boss_Modes_Soundset";
	}
	if (authsounds == "LOSER") {
		initialize::Sounds1 = "LOSER";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "Lowrider_Upgrade") {
		initialize::Sounds1 = "Lowrider_Upgrade";
		initialize::Sounds2 = "Lowrider_Super_Mod_Garage_Sounds";
	}
	if (authsounds == "Map_Roll_Down") {
		initialize::Sounds1 = "Map_Roll_Down";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Map_Roll_Up") {
		initialize::Sounds1 = "Map_Roll_Up";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "MARKER_ERASE") {
		initialize::Sounds1 = "MARKER_ERASE";
		initialize::Sounds2 = "HEIST_BULLETIN_BOARD_SOUNDSET";
	}
	if (authsounds == "MARTIN1_DISTANT_TRAIN_HORNS_MASTER") {
		initialize::Sounds1 = "MARTIN1_DISTANT_TRAIN_HORNS_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "MEDAL_BRONZE") {
		initialize::Sounds1 = "MEDAL_BRONZE";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "MEDAL_GOLD") {
		initialize::Sounds1 = "MEDAL_GOLD";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "MEDAL_SILVER") {
		initialize::Sounds1 = "MEDAL_SILVER";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "MEDAL_UP") {
		initialize::Sounds1 = "MEDAL_UP";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Menu_Accept") {
		initialize::Sounds1 = "Menu_Accept";
		initialize::Sounds2 = "Phone_SoundSet_Default";
	}
	if (authsounds == "MICHAEL_LONG_SCREAM") {
		initialize::Sounds1 = "MICHAEL_LONG_SCREAM";
		initialize::Sounds2 = "FAMILY_5_SOUNDS";
	}
	if (authsounds == "MICHAEL_SOFA_REMOTE_CLICK_VOLUME_MASTER") {
		initialize::Sounds1 = "MICHAEL_SOFA_REMOTE_CLICK_VOLUME_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "MICHAEL_SOFA_TV_CHANGE_CHANNEL_MASTER") {
		initialize::Sounds1 = "MICHAEL_SOFA_TV_CHANGE_CHANNEL_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "MICHAEL_SOFA_TV_ON_MASTER") {
		initialize::Sounds1 = "MICHAEL_SOFA_TV_ON_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "Mission_Pass_Notify") {
		initialize::Sounds1 = "Mission_Pass_Notify";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "MP_5_SECOND_TIMER") {
		initialize::Sounds1 = "MP_5_SECOND_TIMER";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "MP_AWARD") {
		initialize::Sounds1 = "MP_AWARD";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "MP_Flash") {
		initialize::Sounds1 = "MP_Flash";
		initialize::Sounds2 = "WastedSounds";
	}
	if (authsounds == "MP_IDLE_KICK") {
		initialize::Sounds1 = "MP_IDLE_KICK";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "MP_IDLE_TIMER") {
		initialize::Sounds1 = "MP_IDLE_TIMER";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "MP_Impact") {
		initialize::Sounds1 = "MP_Impact";
		initialize::Sounds2 = "WastedSounds";
	}
	if (authsounds == "MP_RANK_UP") {
		initialize::Sounds1 = "MP_RANK_UP";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "MP_WAVE_COMPLETE") {
		initialize::Sounds1 = "MP_WAVE_COMPLETE";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "NAV") {
		initialize::Sounds1 = "NAV";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "Nav_Arrow_Ahead") {
		initialize::Sounds1 = "Nav_Arrow_Ahead";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "Nav_Arrow_Behind") {
		initialize::Sounds1 = "Nav_Arrow_Behind";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "Nav_Arrow_Left") {
		initialize::Sounds1 = "Nav_Arrow_Left";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "Nav_Arrow_Right") {
		initialize::Sounds1 = "Nav_Arrow_Right";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "NAV_LEFT_RIGHT") {
		initialize::Sounds1 = "NAV_LEFT_RIGHT";
		initialize::Sounds2 = "HUD_FREEMODE_SOUNDSET";
	}
	if (authsounds == "NAV_LEFT_RIGHT") {
		initialize::Sounds1 = "NAV_LEFT_RIGHT";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "NAV_UP_DOWN1") {
		initialize::Sounds1 = "NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_FREEMODE_SOUNDSET";
	}
	if (authsounds == "NAV_UP_DOWN2") {
		initialize::Sounds1 = "NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_FRONTEND_CLOTHESSHOP_SOUNDSET";
	}
	if (authsounds == "NAV_UP_DOWN3") {
		initialize::Sounds1 = "NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "NAV_UP_DOWN4") {
		initialize::Sounds1 = "NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "NAV_UP_DOWN5") {
		initialize::Sounds1 = "NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_FRONTEND_TATTOO_SHOP_SOUNDSET";
	}
	if (authsounds == "NAV_UP_DOWN6") {
		initialize::Sounds1 = "NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_LIQUOR_STORE_SOUNDSET";
	}
	if (authsounds == "NAV_UP_DOWN7") {
		initialize::Sounds1 = "NAV_UP_DOWN";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Near_Miss_Counter_Reset") {
		initialize::Sounds1 = "Near_Miss_Counter_Reset";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "NET_RACE_START_EVENT_MASTER") {
		initialize::Sounds1 = "NET_RACE_START_EVENT_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "NO") {
		initialize::Sounds1 = "NO";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Object_Collect_Player") {
		initialize::Sounds1 = "Object_Collect_Player";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Object_Collect_Remote") {
		initialize::Sounds1 = "Object_Collect_Remote";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Object_Dropped_Remote") {
		initialize::Sounds1 = "Object_Dropped_Remote";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Off_High") {
		initialize::Sounds1 = "Off_High";
		initialize::Sounds2 = "MP_RADIO_SFX";
	}
	if (authsounds == "OK") {
		initialize::Sounds1 = "OK";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "ON") {
		initialize::Sounds1 = "ON";
		initialize::Sounds2 = "NOIR_FILTER_SOUNDS";
	}
	if (authsounds == "On_Call_Player_Join") {
		initialize::Sounds1 = "On_Call_Player_Join";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "Oneshot_Final") {
		initialize::Sounds1 = "Oneshot_Final";
		initialize::Sounds2 = "MP_MISSION_COUNTDOWN_SOUNDSET";
	}
	if (authsounds == "OOB_Cancel") {
		initialize::Sounds1 = "OOB_Cancel";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "OOB_Start") {
		initialize::Sounds1 = "OOB_Start";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "OPEN_WINDOW") {
		initialize::Sounds1 = "OPEN_WINDOW";
		initialize::Sounds2 = "LESTER1A_SOUNDS";
	}
	if (authsounds == "OPENED") {
		initialize::Sounds1 = "OPENED";
		initialize::Sounds2 = "MP_PROPERTIES_ELEVATOR_DOORS";
	}
	if (authsounds == "OTHER_TEXT") {
		initialize::Sounds1 = "OTHER_TEXT";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "Out_Of_Area") {
		initialize::Sounds1 = "Out_Of_Area";
		initialize::Sounds2 = "DLC_Lowrider_Relay_Race_Sounds";
	}
	if (authsounds == "Out_Of_Bounds_Timer") {
		initialize::Sounds1 = "Out_Of_Bounds_Timer";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "Paper_Shuffle") {
		initialize::Sounds1 = "Paper_Shuffle";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Parcel_Vehicle_Lost") {
		initialize::Sounds1 = "Parcel_Vehicle_Lost";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "Payment_Non_Player") {
		initialize::Sounds1 = "Payment_Non_Player";
		initialize::Sounds2 = "DLC_HEISTS_GENERIC_SOUNDS";
	}
	if (authsounds == "Payment_Player") {
		initialize::Sounds1 = "Payment_Player";
		initialize::Sounds2 = "DLC_HEISTS_GENERIC_SOUNDS";
	}
	if (authsounds == "Pen_Tick") {
		initialize::Sounds1 = "Pen_Tick";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "PERSON_SCROLL") {
		initialize::Sounds1 = "PERSON_SCROLL";
		initialize::Sounds2 = "HEIST_BULLETIN_BOARD_SOUNDSET";
	}
	if (authsounds == "PERSON_SELECT") {
		initialize::Sounds1 = "PERSON_SELECT";
		initialize::Sounds2 = "HEIST_BULLETIN_BOARD_SOUNDSET";
	}
	if (authsounds == "Phone_Generic_Key_02") {
		initialize::Sounds1 = "Phone_Generic_Key_02";
		initialize::Sounds2 = "HUD_MINIGAME_SOUNDSET";
	}
	if (authsounds == "Phone_Generic_Key_03") {
		initialize::Sounds1 = "Phone_Generic_Key_03";
		initialize::Sounds2 = "HUD_MINIGAME_SOUNDSET";
	}
	if (authsounds == "PICK_UP") {
		initialize::Sounds1 = "PICK_UP";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "PICK_UP_WEAPON") {
		initialize::Sounds1 = "PICK_UP_WEAPON";
		initialize::Sounds2 = "HUD_FRONTEND_CUSTOM_SOUNDSET";
	}
	if (authsounds == "PICK_UP_SOUND") {
		initialize::Sounds1 = "PICK_UP_SOUND";
		initialize::Sounds2 = "HUD_FRONTEND_CUSTOM_SOUNDSET";
	}
	if (authsounds == "PICKUP_WEAPON_SMOKEGRENADE") {
		initialize::Sounds1 = "PICKUP_WEAPON_SMOKEGRENADE";
		initialize::Sounds2 = "HUD_FRONTEND_WEAPONS_PICKUPS_SOUNDSET";
	}
	if (authsounds == "Pin_Bad") {
		initialize::Sounds1 = "Pin_Bad";
		initialize::Sounds2 = "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS";
	}
	if (authsounds == "PIN_BUTTON") {
		initialize::Sounds1 = "PIN_BUTTON";
		initialize::Sounds2 = "ATM_SOUNDS";
	}
	if (authsounds == "Pin_Centred") {
		initialize::Sounds1 = "Pin_Centred";
		initialize::Sounds2 = "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS";
	}
	if (authsounds == "Pin_Good") {
		initialize::Sounds1 = "Pin_Good";
		initialize::Sounds2 = "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS";
	}
	if (authsounds == "PIPES_LAND") {
		initialize::Sounds1 = "PIPES_LAND";
		initialize::Sounds2 = "CONSTRUCTION_ACCIDENT_1_SOUNDS";
	}
	if (authsounds == "Place_Prop_Fail") {
		initialize::Sounds1 = "Place_Prop_Fail";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "Place_Prop_Success") {
		initialize::Sounds1 = "Place_Prop_Success";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "Player_Collect") {
		initialize::Sounds1 = "Player_Collect";
		initialize::Sounds2 = "DLC_PILOT_MP_HUD_SOUNDS";
	}
	if (authsounds == "Player_Enter_Line") {
		initialize::Sounds1 = "Player_Enter_Line";
		initialize::Sounds2 = "GTAO_FM_Cross_The_Line_Soundset";
	}
	if (authsounds == "Player_Exit_Line") {
		initialize::Sounds1 = "Player_Exit_Line";
		initialize::Sounds2 = "GTAO_FM_Cross_The_Line_Soundset";
	}
	if (authsounds == "Power_Down") {
		initialize::Sounds1 = "Power_Down";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "Pre_Screen_Stinger1") {
		initialize::Sounds1 = "Pre_Screen_Stinger";
		initialize::Sounds2 = "DLC_HEISTS_FAILED_SCREEN_SOUNDS";
	}
	if (authsounds == "Pre_Screen_Stinger2") {
		initialize::Sounds1 = "Pre_Screen_Stinger";
		initialize::Sounds2 = "DLC_HEISTS_FINALE_SCREEN_SOUNDS";
	}
	if (authsounds == "Pre_Screen_Stinger3") {
		initialize::Sounds1 = "Pre_Screen_Stinger";
		initialize::Sounds2 = "DLC_HEISTS_PREP_SCREEN_SOUNDS";
	}
	if (authsounds == "PROPERTY_PURCHASE") {
		initialize::Sounds1 = "PROPERTY_PURCHASE";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "PROPERTY_PURCHASE_MEDIUM") {
		initialize::Sounds1 = "PROPERTY_PURCHASE_MEDIUM";
		initialize::Sounds2 = "HUD_PROPERTY_SOUNDSET";
	}
	if (authsounds == "PS2A_DISTANT_TRAIN_HORNS_MASTER") {
		initialize::Sounds1 = "PS2A_DISTANT_TRAIN_HORNS_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "PS2A_MONEY_LOST") {
		initialize::Sounds1 = "PS2A_MONEY_LOST";
		initialize::Sounds2 = "PALETO_SCORE_2A_BANK_SS";
	}
	if (authsounds == "PURCHASE1") {
		initialize::Sounds1 = "PURCHASE";
		initialize::Sounds2 = "HUD_FRONTEND_TATTOO_SHOP_SOUNDSET";
	}
	if (authsounds == "PURCHASE2") {
		initialize::Sounds1 = "PURCHASE";
		initialize::Sounds2 = "HUD_LIQUOR_STORE_SOUNDSET";
	}
	if (authsounds == "PUSH1") {
		initialize::Sounds1 = "PUSH";
		initialize::Sounds2 = "DLC_APT_YACHT_DOOR_SOUNDS";
	}
	if (authsounds == "PUSH2") {
		initialize::Sounds1 = "PUSH";
		initialize::Sounds2 = "GTAO_APT_DOOR_DOWNSTAIRS_GLASS_SOUNDS";
	}
	if (authsounds == "PUSH3") {
		initialize::Sounds1 = "PUSH";
		initialize::Sounds2 = "GTAO_APT_DOOR_DOWNSTAIRS_WOOD_SOUNDS";
	}
	if (authsounds == "Put_Away") {
		initialize::Sounds1 = "Put_Away";
		initialize::Sounds2 = "Phone_SoundSet_Michael";
	}
	if (authsounds == "QUIT") {
		initialize::Sounds1 = "QUIT";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "QUIT_WHOOSH") {
		initialize::Sounds1 = "QUIT_WHOOSH";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "RACE_PLACED") {
		initialize::Sounds1 = "RACE_PLACED";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "Radar_Beast_Blip") {
		initialize::Sounds1 = "Radar_Beast_Blip";
		initialize::Sounds2 = "FM_Events_Sasquatch_Sounds";
	}
	if (authsounds == "RAMP_DOWN") {
		initialize::Sounds1 = "RAMP_DOWN";
		initialize::Sounds2 = "TRUCK_RAMP_DOWN";
	}
	if (authsounds == "RAMP_UP") {
		initialize::Sounds1 = "RAMP_UP";
		initialize::Sounds2 = "TRUCK_RAMP_DOWN";
	}
	if (authsounds == "RAMPAGE_KILLED_COUNTER_MASTER") {
		initialize::Sounds1 = "RAMPAGE_KILLED_COUNTER_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "RAMPAGE_KILLED_HEAD_SHOT_MASTER") {
		initialize::Sounds1 = "RAMPAGE_KILLED_HEAD_SHOT_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "RAMPAGE_PASSED_MASTER") {
		initialize::Sounds1 = "RAMPAGE_PASSED_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "RAMPAGE_ROAR_MASTER") {
		initialize::Sounds1 = "RAMPAGE_ROAR_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "RANK_UP") {
		initialize::Sounds1 = "RANK_UP";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "REMOTE_PLYR_CASH_COUNTER_COMPLETE") {
		initialize::Sounds1 = "REMOTE_PLYR_CASH_COUNTER_COMPLETE";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "REMOTE_PLYR_CASH_COUNTER_INCREASE") {
		initialize::Sounds1 = "REMOTE_PLYR_CASH_COUNTER_INCREASE";
		initialize::Sounds2 = "DLC_HEISTS_GENERAL_FRONTEND_SOUNDS";
	}
	if (authsounds == "Remote_Sniper_Rifle_Fire") {
		initialize::Sounds1 = "Remote_Sniper_Rifle_Fire";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "Reset_Prop_Position ") {
		initialize::Sounds1 = "Reset_Prop_Position";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "RESTART") {
		initialize::Sounds1 = "RESTART";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "RETRY") {
		initialize::Sounds1 = "RETRY";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Retune_High") {
		initialize::Sounds1 = "Retune_High";
		initialize::Sounds2 = "MP_RADIO_SFX";
	}
	if (authsounds == "ROBBERY_MONEY_TOTAL") {
		initialize::Sounds1 = "ROBBERY_MONEY_TOTAL";
		initialize::Sounds2 = "HUD_FRONTEND_CUSTOM_SOUNDSET";
	}
	if (authsounds == "ROPE_CUT") {
		initialize::Sounds1 = "ROPE_CUT";
		initialize::Sounds2 = "ROPE_CUT_SOUNDSET";
	}
	if (authsounds == "ROUND_ENDING_STINGER_CUSTOM") {
		initialize::Sounds1 = "ROUND_ENDING_STINGER_CUSTOM";
		initialize::Sounds2 = "CELEBRATION_SOUNDSET";
	}
	if (authsounds == "Save_Scene") {
		initialize::Sounds1 = "Save_Scene";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "SCOPE_UI_MASTER") {
		initialize::Sounds1 = "SCOPE_UI_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "SCREEN_FLASH") {
		initialize::Sounds1 = "SCREEN_FLASH";
		initialize::Sounds2 = "CELEBRATION_SOUNDSET";
	}
	if (authsounds == "ScreenFlash1") {
		initialize::Sounds1 = "ScreenFlash";
		initialize::Sounds2 = "MissionFailedSounds";
	}
	if (authsounds == "ScreenFlash2") {
		initialize::Sounds1 = "ScreenFlash";
		initialize::Sounds2 = "WastedSounds";
	}
	if (authsounds == "SCREEN_SWIPE") {
		initialize::Sounds1 = "SCREEN_SWIPE";
		initialize::Sounds2 = "CELEBRATION_SWIPE";
	}
	if (authsounds == "SELECT1") {
		initialize::Sounds1 = "SELECT";
		initialize::Sounds2 = "HUD_FREEMODE_SOUNDSET";
	}
	if (authsounds == "SELECT2") {
		initialize::Sounds1 = "SELECT";
		initialize::Sounds2 = "HUD_FRONTEND_CLOTHESSHOP_SOUNDSET";
	}
	if (authsounds == "SELECT3") {
		initialize::Sounds1 = "SELECT";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "SELECT4") {
		initialize::Sounds1 = "SELECT";
		initialize::Sounds2 = "HUD_FRONTEND_MP_SOUNDSET";
	}
	if (authsounds == "SELECT5") {
		initialize::Sounds1 = "SELECT";
		initialize::Sounds2 = "HUD_FRONTEND_TATTOO_SHOP_SOUNDSET";
	}
	if (authsounds == "SELECT6") {
		initialize::Sounds1 = "SELECT";
		initialize::Sounds2 = "HUD_LIQUOR_STORE_SOUNDSET";
	}
	if (authsounds == "SELECT7") {
		initialize::Sounds1 = "SELECT";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "Select_Placed_Prop") {
		initialize::Sounds1 = "Select_Placed_Prop";
		initialize::Sounds2 = "DLC_Dmod_Prop_Editor_Sounds";
	}
	if (authsounds == "Shard_Disappear1") {
		initialize::Sounds1 = "Shard_Disappear";
		initialize::Sounds2 = "GTAO_Boss_Goons_FM_Shard_Sounds";
	}
	if (authsounds == "Shard_Disappear2") {
		initialize::Sounds1 = "Shard_Disappear";
		initialize::Sounds2 = "GTAO_FM_Events_Soundset";
	}
	if (authsounds == "SHOOTING_RANGE_ROUND_OVER") {
		initialize::Sounds1 = "SHOOTING_RANGE_ROUND_OVER";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "Short_Transition_In") {
		initialize::Sounds1 = "Short_Transition_In";
		initialize::Sounds2 = "PLAYER_SWITCH_CUSTOM_SOUNDSET";
	}
	if (authsounds == "Short_Transition_Out") {
		initialize::Sounds1 = "Short_Transition_Out";
		initialize::Sounds2 = "PLAYER_SWITCH_CUSTOM_SOUNDSET";
	}
	if (authsounds == "SKIP") {
		initialize::Sounds1 = "SKIP";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Start") {
		initialize::Sounds1 = "Start";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "Start_Squelch") {
		initialize::Sounds1 = "Start_Squelch";
		initialize::Sounds2 = "CB_RADIO_SFX";
	}
	if (authsounds == "STUN_COLLECT") {
		initialize::Sounds1 = "STUN_COLLECT";
		initialize::Sounds2 = "MINUTE_MAN_01_SOUNDSET";
	}
	if (authsounds == "Success") {
		initialize::Sounds1 = "Success";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "SultanRS_Upgrade") {
		initialize::Sounds1 = "SultanRS_Upgrade";
		initialize::Sounds2 = "JA16_Super_Mod_Garage_Sounds";
	}
	if (authsounds == "Swap_Sides") {
		initialize::Sounds1 = "Swap_Sides";
		initialize::Sounds2 = "DLC_HALLOWEEN_FVJ_Sounds";
	}
	if (authsounds == "SWING_SHUT1") {
		initialize::Sounds1 = "SWING_SHUT";
		initialize::Sounds2 = "GTAO_APT_DOOR_DOWNSTAIRS_GLASS_SOUNDS";
	}
	if (authsounds == "SWING_SHUT2") {
		initialize::Sounds1 = "SWING_SHUT";
		initialize::Sounds2 = "GTAO_APT_DOOR_DOWNSTAIRS_WOOD_SOUNDS";
	}
	if (authsounds == "Tattooing_Oneshot") {
		initialize::Sounds1 = "Tattooing_Oneshot";
		initialize::Sounds2 = "TATTOOIST_SOUNDS";
	}
	if (authsounds == "Tattooing_Oneshot_Remove") {
		initialize::Sounds1 = "Tattooing_Oneshot_Remove";
		initialize::Sounds2 = "TATTOOIST_SOUNDS";
	}
	if (authsounds == "Team_Capture_Start") {
		initialize::Sounds1 = "Team_Capture_Start";
		initialize::Sounds2 = "GTAO_Magnate_Yacht_Attack_Soundset";
	}
	if (authsounds == "TENNIS_MATCH_POINT") {
		initialize::Sounds1 = "TENNIS_MATCH_POINT";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "TENNIS_POINT_WON") {
		initialize::Sounds1 = "TENNIS_POINT_WON";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "TextHit") {
		initialize::Sounds1 = "TextHit";
		initialize::Sounds2 = "WastedSounds";
	}
	if (authsounds == "Thermal_Off") {
		initialize::Sounds1 = "Thermal_Off";
		initialize::Sounds2 = "CAR_STEAL_2_SOUNDSET";
	}
	if (authsounds == "Thermal_On") {
		initialize::Sounds1 = "Thermal_On";
		initialize::Sounds2 = "CAR_STEAL_2_SOUNDSET";
	}
	if (authsounds == "THERMAL_VISION_GOGGLES_OFF_MASTER") {
		initialize::Sounds1 = "THERMAL_VISION_GOGGLES_OFF_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "THERMAL_VISION_GOGGLES_ON_MASTER") {
		initialize::Sounds1 = "THERMAL_VISION_GOGGLES_ON_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "TIME_LAPSE_MASTER") {
		initialize::Sounds1 = "TIME_LAPSE_MASTER";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "TIMER") {
		initialize::Sounds1 = "TIMER";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Timer_10s") {
		initialize::Sounds1 = "Timer_10s";
		initialize::Sounds2 = "DLC_HALLOWEEN_FVJ_Sounds";
	}
	if (authsounds == "TIMER_STOP") {
		initialize::Sounds1 = "TIMER_STOP";
		initialize::Sounds2 = "HUD_MINI_GAME_SOUNDSET";
	}
	if (authsounds == "TOGGLE_ON") {
		initialize::Sounds1 = "TOGGLE_ON";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Traffic_Control_Fail") {
		initialize::Sounds1 = "Traffic_Control_Fail";
		initialize::Sounds2 = "BIG_SCORE_3A_SOUNDS";
	}
	if (authsounds == "Traffic_Control_Fail_Blank") {
		initialize::Sounds1 = "Traffic_Control_Fail_Blank";
		initialize::Sounds2 = "BIG_SCORE_3A_SOUNDS";
	}
	if (authsounds == "Traffic_Control_Light_Switch_Back") {
		initialize::Sounds1 = "Traffic_Control_Light_Switch_Back";
		initialize::Sounds2 = "BIG_SCORE_3A_SOUNDS";
	}
	if (authsounds == "TRAFFIC_CONTROL_MOVE_CROSSHAIR") {
		initialize::Sounds1 = "TRAFFIC_CONTROL_MOVE_CROSSHAIR";
		initialize::Sounds2 = "BIG_SCORE_3A_SOUNDS";
	}
	if (authsounds == "Turn") {
		initialize::Sounds1 = "Turn";
		initialize::Sounds2 = "DLC_HEIST_HACKING_SNAKE_SOUNDS";
	}
	if (authsounds == "UNDER_THE_BRIDGE") {
		initialize::Sounds1 = "UNDER_THE_BRIDGE";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "UNDER_WATER_COME_UP") {
		initialize::Sounds1 = "UNDER_WATER_COME_UP";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "UNDO") {
		initialize::Sounds1 = "UNDO";
		initialize::Sounds2 = "HEIST_BULLETIN_BOARD_SOUNDSET";
	}
	if (authsounds == "WAYPOINT_SET") {
		initialize::Sounds1 = "WAYPOINT_SET";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "WEAKEN") {
		initialize::Sounds1 = "WEAKEN";
		initialize::Sounds2 = "CONSTRUCTION_ACCIDENT_1_SOUNDS";
	}
	if (authsounds == "WEAPON_AMMO_PURCHASE") {
		initialize::Sounds1 = "WEAPON_AMMO_PURCHASE";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_ATTACHMENT_EQUIP") {
		initialize::Sounds1 = "WEAPON_ATTACHMENT_EQUIP";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_ATTACHMENT_UNEQUIP") {
		initialize::Sounds1 = "WEAPON_ATTACHMENT_UNEQUIP";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_PURCHASE") {
		initialize::Sounds1 = "WEAPON_PURCHASE";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_ARMOR") {
		initialize::Sounds1 = "WEAPON_SELECT_ARMOR";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_BATON") {
		initialize::Sounds1 = "WEAPON_SELECT_BATON";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_FUEL_CAN") {
		initialize::Sounds1 = "WEAPON_SELECT_FUEL_CAN";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_GRENADE_LAUNCHER") {
		initialize::Sounds1 = "WEAPON_SELECT_GRENADE_LAUNCHER";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_HANDGUN") {
		initialize::Sounds1 = "WEAPON_SELECT_HANDGUN";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_KNIFE") {
		initialize::Sounds1 = "WEAPON_SELECT_KNIFE";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_OTHER") {
		initialize::Sounds1 = "WEAPON_SELECT_OTHER";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_PARACHUTE") {
		initialize::Sounds1 = "WEAPON_SELECT_PARACHUTE";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_RIFLE") {
		initialize::Sounds1 = "WEAPON_SELECT_RIFLE";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_RPG_LAUNCHER") {
		initialize::Sounds1 = "WEAPON_SELECT_RPG_LAUNCHER";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "WEAPON_SELECT_SHOTGUN") {
		initialize::Sounds1 = "WEAPON_SELECT_SHOTGUN";
		initialize::Sounds2 = "HUD_AMMO_SHOP_SOUNDSET";
	}
	if (authsounds == "Whistle") {
		initialize::Sounds1 = "Whistle";
		initialize::Sounds2 = "DLC_TG_Running_Back_Sounds";
	}
	if (authsounds == "Whoosh_1s_L_to_R") {
		initialize::Sounds1 = "Whoosh_1s_L_to_R";
		initialize::Sounds2 = "MP_LOBBY_SOUNDS";
	}
	if (authsounds == "Whoosh_1s_R_to_L") {
		initialize::Sounds1 = "Whoosh_1s_R_to_L";
		initialize::Sounds2 = "MP_LOBBY_SOUNDS";
	}
	if (authsounds == "WIN") {
		initialize::Sounds1 = "WIN";
		initialize::Sounds2 = "HUD_AWARDS";
	}
	if (authsounds == "WOODEN_DOOR_CLOSED_AT") {
		initialize::Sounds1 = "WOODEN_DOOR_CLOSED_AT";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "WOODEN_DOOR_OPEN_HANDLE_AT") {
		initialize::Sounds1 = "WOODEN_DOOR_OPEN_HANDLE_AT";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "WOODEN_DOOR_OPEN_NO_HANDLE_AT") {
		initialize::Sounds1 = "WOODEN_DOOR_OPEN_NO_HANDLE_AT";
		initialize::Sounds2 = "0";
	}
	if (authsounds == "YES") {
		initialize::Sounds1 = "YES";
		initialize::Sounds2 = "HUD_FRONTEND_DEFAULT_SOUNDSET";
	}
	if (authsounds == "Zone_Enemy_Capture") {
		initialize::Sounds1 = "Zone_Enemy_Capture";
		initialize::Sounds2 = "DLC_Apartments_Drop_Zone_Sounds";
	}
	if (authsounds == "Zone_Neutral") {
		initialize::Sounds1 = "Zone_Neutral";
		initialize::Sounds2 = "DLC_Apartments_Drop_Zone_Sounds";
	}
	if (authsounds == "Zone_Team_Capture") {
		initialize::Sounds1 = "Zone_Team_Capture";
		initialize::Sounds2 = "DLC_Apartments_Drop_Zone_Sounds";
	}
	if (authsounds == "Zoom_In") {
		initialize::Sounds1 = "Zoom_In";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Zoom_Left") {
		initialize::Sounds1 = "Zoom_Left";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Zoom_Out") {
		initialize::Sounds1 = "Zoom_Out";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	if (authsounds == "Zoom_Right") {
		initialize::Sounds1 = "Zoom_Right";
		initialize::Sounds2 = "DLC_HEIST_PLANNING_BOARD_SOUNDS";
	}
	return 0;
}

string initialize::carmodel1 = "www_arenawar_tv";
string initialize::carmodel2 = "splash_centre";

int initialize::pictureofcars(string carmodel) {
	if (carmodel == "benson2") {
		initialize::carmodel1 = "candc_2023_2";
		initialize::carmodel2 = "benson2";
	}
	if (carmodel == "boxville6") {
		initialize::carmodel1 = "candc_2023_2";
		initialize::carmodel2 = "boxville6";
	}
	if (carmodel == "polgauntlet") {
		initialize::carmodel1 = "candc_2023_2";
		initialize::carmodel2 = "polgauntlet";
	}
	if (carmodel == "police5") {
		initialize::carmodel1 = "candc_2023_2";
		initialize::carmodel2 = "police5";
	}
	if (carmodel == "aleutian") {
		initialize::carmodel1 = "lgm_dlc_2023_2";
		initialize::carmodel2 = "aleutian";
	}
	if (carmodel == "baller8") {
		initialize::carmodel1 = "lgm_dlc_2023_2";
		initialize::carmodel2 = "baller8";
	}
	if (carmodel == "turismo3") {
		initialize::carmodel1 = "lgm_dlc_2023_2";
		initialize::carmodel2 = "turismo3";
	}
	if (carmodel == "asterope2") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "asterope2";
	}
	if (carmodel == "cavalcade3") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "cavalcade3";
	}
	if (carmodel == "dominator9") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "dominator9";
	}
	if (carmodel == "dorado") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "dorado";
	}
	if (carmodel == "fr36") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "fr36";
	}
	if (carmodel == "impaler5") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "impaler5";
	}
	if (carmodel == "impaler6") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "impaler6";
	}
	if (carmodel == "terminus") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "terminus";
	}
	if (carmodel == "vigero3") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "vigero3";
	}
	if (carmodel == "vivanite") {
		initialize::carmodel1 = "sssa_dlc_2023_2";
		initialize::carmodel2 = "vivanite";
	}

	if (carmodel == "buffalo5") {
		initialize::carmodel1 = "lgm_dlc_2023_01";
		initialize::carmodel2 = "buffalo5";
	}
	if (carmodel == "coureur") {
		initialize::carmodel1 = "lgm_dlc_2023_01";
		initialize::carmodel2 = "coureur";
	}
	if (carmodel == "stingertt") {
		initialize::carmodel1 = "lgm_dlc_2023_01";
		initialize::carmodel2 = "stingertt";
	}
	if (carmodel == "conada2") {
		initialize::carmodel1 = "candc_2023_01";
		initialize::carmodel2 = "conada2";
	}
	if (carmodel == "raiju") {
		initialize::carmodel1 = "candc_2023_01";
		initialize::carmodel2 = "raiju";
	}
	if (carmodel == "streamer216") {
		initialize::carmodel1 = "candc_2023_01";
		initialize::carmodel2 = "streamer216";
	}
	if (carmodel == "inductor") {
		initialize::carmodel1 = "pandm_dlc_2023_01";
		initialize::carmodel2 = "inductor";
	}
	if (carmodel == "inductor2") {
		initialize::carmodel1 = "pandm_dlc_2023_01";
		initialize::carmodel2 = "inductor2";
	}
	if (carmodel == "brigham") {
		initialize::carmodel1 = "sssa_dlc_2023_01";
		initialize::carmodel2 = "brigham";
	}
	if (carmodel == "clique2") {
		initialize::carmodel1 = "sssa_dlc_2023_01";
		initialize::carmodel2 = "clique2";
	}
	if (carmodel == "gauntlet6") {
		initialize::carmodel1 = "sssa_dlc_2023_01";
		initialize::carmodel2 = "gauntlet6";
	}
	if (carmodel == "l35") {
		initialize::carmodel1 = "sssa_dlc_2023_01";
		initialize::carmodel2 = "l35";
	}
	if (carmodel == "monstrociti") {
		initialize::carmodel1 = "sssa_dlc_2023_01";
		initialize::carmodel2 = "monstrociti";
	}
	if (carmodel == "ratel") {
		initialize::carmodel1 = "sssa_dlc_2023_01";
		initialize::carmodel2 = "ratel";
	}
	if (carmodel == "boor") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "boor";
	}
	if (carmodel == "brickade2") {
		initialize::carmodel1 = "candc_xmas2022";
		initialize::carmodel2 = "brickade2";
	}
	if (carmodel == "broadway") {
		initialize::carmodel1 = "lgm_dlc_xmas2022";
		initialize::carmodel2 = "broadway";
	}
	if (carmodel == "cargoplane2") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "cargoplane2";
	}
	if (carmodel == "entity3") {
		initialize::carmodel1 = "lgm_dlc_xmas2022";
		initialize::carmodel2 = "entity3";
	}
	if (carmodel == "eudora") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "eudora";
	}
	if (carmodel == "everon2") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "everon2";
	}
	if (carmodel == "issi8") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "issi8";
	}
	if (carmodel == "journey2") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "journey2";
	}
	if (carmodel == "manchez3") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "manchez3";
	}
	if (carmodel == "panthere") {
		initialize::carmodel1 = "lgm_dlc_xmas2022";
		initialize::carmodel2 = "panthere";
	}
	if (carmodel == "powersurge") {
		initialize::carmodel1 = "lgm_dlc_xmas2022";
		initialize::carmodel2 = "powersurge";
	}
	if (carmodel == "r300") {
		initialize::carmodel1 = "lgm_dlc_xmas2022";
		initialize::carmodel2 = "r300";
	}
	if (carmodel == "surfer3") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "surfer3";
	}
	if (carmodel == "tahoma") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "tahoma";
	}
	if (carmodel == "tulip2") {
		initialize::carmodel1 = "sssa_dlc_xmas2022";
		initialize::carmodel2 = "tulip2";
	}
	if (carmodel == "virtue") {
		initialize::carmodel1 = "lgm_dlc_xmas2022";
		initialize::carmodel2 = "virtue";
	}
	if (carmodel == "greenwood") {
		initialize::carmodel1 = "sssa_dlc_sum2";
		initialize::carmodel2 = "greenwood";
	}
	if (carmodel == "draugur") {
		initialize::carmodel1 = "sssa_dlc_sum2";
		initialize::carmodel2 = "draugur";
	}
	if (carmodel == "kanjosj") {
		initialize::carmodel1 = "sssa_dlc_sum2";
		initialize::carmodel2 = "kanjosj";
	}
	if (carmodel == "postlude") {
		initialize::carmodel1 = "sssa_dlc_sum2";
		initialize::carmodel2 = "postlude";
	}
	if (carmodel == "rhinehart") {
		initialize::carmodel1 = "sssa_dlc_sum2";
		initialize::carmodel2 = "rhinehart";
	}
	if (carmodel == "ruiner4") {
		initialize::carmodel1 = "sssa_dlc_sum2";
		initialize::carmodel2 = "ruiner4";
	}
	if (carmodel == "vigero2") {
		initialize::carmodel1 = "sssa_dlc_sum2";
		initialize::carmodel2 = "vigero2";
	}
	if (carmodel == "conada") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "conada";
	}
	if (carmodel == "corsita") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "corsita";
	}
	if (carmodel == "lm87") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "lm87";
	}
	if (carmodel == "omnisegt") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "omnisegt";
	}
	if (carmodel == "sm722") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "sm722";
	}
	if (carmodel == "tenf") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "tenf";
	}
	if (carmodel == "tenf2") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "tenf2";
	}
	if (carmodel == "torero2") {
		initialize::carmodel1 = "lgm_dlc_sum2";
		initialize::carmodel2 = "torero2";
	}
	if (carmodel == "comet6") {
		initialize::carmodel1 = "lgm_dlc_tuner";
		initialize::carmodel2 = "comet6";
	}
	if (carmodel == "cypher") {
		initialize::carmodel1 = "lgm_dlc_tuner";
		initialize::carmodel2 = "cypher";
	}
	if (carmodel == "growler") {
		initialize::carmodel1 = "lgm_dlc_tuner";
		initialize::carmodel2 = "growler";
	}
	if (carmodel == "jester4") {
		initialize::carmodel1 = "lgm_dlc_tuner";
		initialize::carmodel2 = "jester4";
	}
	if (carmodel == "tailgater2") {
		initialize::carmodel1 = "lgm_dlc_tuner";
		initialize::carmodel2 = "tailgater2";
	}
	if (carmodel == "vectre") {
		initialize::carmodel1 = "lgm_dlc_tuner";
		initialize::carmodel2 = "vectre";
	}
	if (carmodel == "zr350") {
		initialize::carmodel1 = "lgm_dlc_tuner";
		initialize::carmodel2 = "zr350";
	}

	if (carmodel == "calico") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "calico";
	}
	if (carmodel == "dominator7") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "dominator7";
	}
	if (carmodel == "dominator8") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "dominator8";
	}
	if (carmodel == "futo2") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "futo2";
	}
	if (carmodel == "previon") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "previon";
	}
	if (carmodel == "remus") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "remus";
	}
	if (carmodel == "rt3000") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "rt3000";
	}
	if (carmodel == "sultan3") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "sultan3";
	}
	if (carmodel == "warrener2") {
		initialize::carmodel1 = "sssa_dlc_tuner";
		initialize::carmodel2 = "warrener2";
	}

	if (carmodel == "club") {
		initialize::carmodel1 = "sssa_dlc_summer2020";
		initialize::carmodel2 = "club";
	}
	if (carmodel == "dukes3") {
		initialize::carmodel1 = "sssa_dlc_summer2020";
		initialize::carmodel2 = "dukes3";
	}
	if (carmodel == "landstalker2") {
		initialize::carmodel1 = "sssa_dlc_summer2020";
		initialize::carmodel2 = "landstlkr2";
	}
	if (carmodel == "penumbra2") {
		initialize::carmodel1 = "sssa_dlc_summer2020";
		initialize::carmodel2 = "penumbra2";
	}
	if (carmodel == "seminole2") {
		initialize::carmodel1 = "sssa_dlc_summer2020";
		initialize::carmodel2 = "seminole2";
	}
	if (carmodel == "coquette4") {
		initialize::carmodel1 = "lgm_dlc_summer2020";
		initialize::carmodel2 = "coquette4";
	}
	if (carmodel == "openwheel1") {
		initialize::carmodel1 = "lgm_dlc_summer2020";
		initialize::carmodel2 = "openwheel1";
	}
	if (carmodel == "openwheel2") {
		initialize::carmodel1 = "lgm_dlc_summer2020";
		initialize::carmodel2 = "openwheel2";
	}
	if (carmodel == "tigon") {
		initialize::carmodel1 = "lgm_dlc_summer2020";
		initialize::carmodel2 = "tigon";
	}
	if (carmodel == "yosemite3") {
		initialize::carmodel1 = "lsc_dlc_summer2020";
		initialize::carmodel2 = "yosemite";
	}
	if (carmodel == "gauntlet5") {
		initialize::carmodel1 = "lsc_dlc_summer2020";
		initialize::carmodel2 = "gauntlet3";
	}
	if (carmodel == "youga3") {
		initialize::carmodel1 = "lsc_dlc_summer2020";
		initialize::carmodel2 = "youga2";
	}
	if (carmodel == "glendale2") {
		initialize::carmodel1 = "lsc_dlc_summer2020";
		initialize::carmodel2 = "glendale";
	}
	if (carmodel == "peyote3") {
		initialize::carmodel1 = "lsc_dlc_summer2020";
		initialize::carmodel2 = "peyote";
	}
	if (carmodel == "manana") {
		initialize::carmodel1 = "lsc_dlc_summer2020";
		initialize::carmodel2 = "manana2";
	}
	if (carmodel == "limo2") {
		initialize::carmodel1 = "candc_apartments";
		initialize::carmodel2 = "limo2";		
	}
	if (carmodel == "caracara") {
		initialize::carmodel1 = "candc_assault";
		initialize::carmodel2 = "caracara";
	}
	if (carmodel == "menacer") {
		initialize::carmodel1 = "candc_battle";
		initialize::carmodel2 = "menacer";
	}
	if (carmodel == "mule4") {
		initialize::carmodel1 = "candc_battle";
		initialize::carmodel2 = "mule4";
	}
	if (carmodel == "opressor2") {
		initialize::carmodel1 = "candc_battle";
		initialize::carmodel2 = "opressor2";
	}
	if (carmodel == "pounder2") {
		initialize::carmodel1 = "candc_battle";
		initialize::carmodel2 = "pounder2";
	}
	if (carmodel == "scramjet") {
		initialize::carmodel1 = "candc_battle";
		initialize::carmodel2 = "scramjet";
	}
	if (carmodel == "strikeforce") {
		initialize::carmodel1 = "candc_battle";
		initialize::carmodel2 = "strikeforce";
	}	
	if (carmodel == "blazer2") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "blazer2";
	}
	if (carmodel == "boxville") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "boxville";
	}
	if (carmodel == "burrito2") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "burrito2";
	}
	if (carmodel == "firetruk") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "firetruk";
	}
	if (carmodel == "jb7002") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "jb7002";
	}
	if (carmodel == "lguard") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "lguard";
	}
	if (carmodel == "minitank") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "minitank";
	}
	if (carmodel == "stockade") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "stockade";
	}
	if (carmodel == "zhaba") {
		initialize::carmodel1 = "candc_casinoheist";
		initialize::carmodel2 = "zhaba";
	}
	if (carmodel == "banner_0") {
		initialize::carmodel1 = "candc_chopper";
		initialize::carmodel2 = "banner_0";
	}
	if (carmodel == "airbus") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "airbus";
	}
	if (carmodel == "barracks") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "barracks";
	}
	if (carmodel == "boxville4") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "boxville4";
	}
	if (carmodel == "bus") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "bus";
	}
	if (carmodel == "buzzard") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "buzzard";
	}
	if (carmodel == "cargobob") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "cargobob";
	}
	if (carmodel == "coach") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "coach";
	}
	if (carmodel == "crusader") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "crusader";
	}
	if (carmodel == "dubsta3") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "dubsta3";
	}
	if (carmodel == "dukes") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "dukes";
	}
	if (carmodel == "dump") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "dump";
	}
	if (carmodel == "hydra") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "hydra";
	}
	if (carmodel == "insurgent") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "insurgent";
	}
	if (carmodel == "insurgent2") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "insurgent2";
	}
	if (carmodel == "journey") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "journey";
	}
	if (carmodel == "marshall") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "marshall";
	}
	if (carmodel == "mesa") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "mesa";
	}
	if (carmodel == "mesa3") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "mesa3";
	}
	if (carmodel == "monster") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "monster";
	}
	if (carmodel == "mule") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "mule";
	}
	if (carmodel == "mule3") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "mule3";
	}
	if (carmodel == "pbus") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "pbus";
	}
	if (carmodel == "rentbus") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "rentbus";
	}
	if (carmodel == "rhino") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "rhino";
	}
	if (carmodel == "savage") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "savage";
	}
	if (carmodel == "technical") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "technical";
	}
	if (carmodel == "valkyrie") {
		initialize::carmodel1 = "candc_default";
		initialize::carmodel2 = "valkyrie";
	}
	if (carmodel == "brickade") {
		initialize::carmodel1 = "candc_executive1";
		initialize::carmodel2 = "brickade";
	}
	if (carmodel == "cargobob2") {
		initialize::carmodel1 = "candc_executive1";
		initialize::carmodel2 = "cargobob2";
	}
	if (carmodel == "apc") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "apc";
	}
	if (carmodel == "ardent") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "ardent";
	}
	if (carmodel == "ballistic_equip") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "ballistic_equip";
	}
	if (carmodel == "dune3") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "dune3";
	}
	if (carmodel == "halftrack") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "halftrack";
	}
	if (carmodel == "nightshark") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "nightshark";
	}
	if (carmodel == "oppressor") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "oppressor";
	}
	if (carmodel == "tampa3") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "tampa3";
	}
	if (carmodel == "trsmall2") {
		initialize::carmodel1 = "candc_gunrunning";
		initialize::carmodel2 = "trsmall2";
	}
	if (carmodel == "banner0") {
		initialize::carmodel1 = "candc_hacker";
		initialize::carmodel2 = "banner0";
	}		
	if (carmodel == "blazer5") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "blazer5";
	}
	if (carmodel == "boxville5") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "boxville5";
	}
	if (carmodel == "dune5") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "dune5";
	}
	if (carmodel == "phantom2") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "phantom2";
	}
	if (carmodel == "ruiner2") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "ruiner2";
	}
	if (carmodel == "technical2") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "technical2";
	}
	if (carmodel == "voltic2") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "voltic2";
	}
	if (carmodel == "wastlndr") {
		initialize::carmodel1 = "candc_importexport";
		initialize::carmodel2 = "wastlndr";
	}
	if (carmodel == "bombushka") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "bombushka";
	}
	if (carmodel == "hunter") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "hunter";
	}
	if (carmodel == "lazer") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "lazer";
	}
	if (carmodel == "mogul") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "mogul";
	}
	if (carmodel == "molotok") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "molotok";
	}
	if (carmodel == "nokota") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "nokota";
	}
	if (carmodel == "pyro") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "pyro";
	}
	if (carmodel == "rogue") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "rogue";
	}
	if (carmodel == "starling") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "starling";
	}
	if (carmodel == "tula") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "tula";
	}
	if (carmodel == "vigilante") {
		initialize::carmodel1 = "candc_smuggler";
		initialize::carmodel2 = "vigilante";
	}
	if (carmodel == "banner_0") {
		initialize::carmodel1 = "candc_truck";
		initialize::carmodel2 = "banner_0";
	}
	if (carmodel == "cab_0") {
		initialize::carmodel1 = "candc_truck";
		initialize::carmodel2 = "cab_0";
	}
	if (carmodel == "cab_1") {
		initialize::carmodel1 = "candc_truck";
		initialize::carmodel2 = "cab_1";
	}
	if (carmodel == "akula") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "akula";
	}
	if (carmodel == "barrage") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "barrage";
	}
	if (carmodel == "chernobog") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "chernobog";
	}
	if (carmodel == "deluxo") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "deluxo";
	}
	if (carmodel == "khanjali") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "khanjali";
	}
	if (carmodel == "riot2") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "riot2";
	}
	if (carmodel == "stromberg") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "stromberg";
	}
	if (carmodel == "thruster") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "thruster";
	}
	if (carmodel == "volatol") {
		initialize::carmodel1 = "candc_xmas2017";
		initialize::carmodel2 = "volatol";
	}
	if (carmodel == "dinghy3") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "dinghy3";
	}
	if (carmodel == "jetmax") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "jetmax";
	}
	if (carmodel == "marquis") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "marquis";
	}
	if (carmodel == "seashark") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "seashark";
	}
	if (carmodel == "speeder") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "speeder";
	}
	if (carmodel == "squalo") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "squalo";
	}
	if (carmodel == "sub2") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "sub2";
	}
	if (carmodel == "suntrap") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "suntrap";
	}
	if (carmodel == "toro") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "toro";
	}
	if (carmodel == "tropic") {
		initialize::carmodel1 = "dock_default";
		initialize::carmodel2 = "tropic";
	}
	if (carmodel == "yatcht_banner_0") {
		initialize::carmodel1 = "dock_dlc_banner";
		initialize::carmodel2 = "yatcht_banner_0";
	}
	if (carmodel == "tug") {
		initialize::carmodel1 = "dock_dlc_executive1";
		initialize::carmodel2 = "tug";
	}
	if (carmodel == "svolito") {
		initialize::carmodel1 = "elt_dlc_apartments";
		initialize::carmodel2 = "svolito";
	}
	if (carmodel == "svolito2") {
		initialize::carmodel1 = "elt_dlc_apartments";
		initialize::carmodel2 = "svolito2";
	}
	if (carmodel == "sparrow") {
		initialize::carmodel1 = "elt_dlc_assault";
		initialize::carmodel2 = "sparrow";
	}
	if (carmodel == "blimp3") {
		initialize::carmodel1 = "elt_dlc_battle";
		initialize::carmodel2 = "blimp3";
	}
	if (carmodel == "vestra") {
		initialize::carmodel1 = "elt_dlc_business";
		initialize::carmodel2 = "vestra";
	}
	if (carmodel == "nimbus") {
		initialize::carmodel1 = "elt_dlc_executive1";
		initialize::carmodel2 = "nimbus";
	}
	if (carmodel == "volatus") {
		initialize::carmodel1 = "elt_dlc_executive1";
		initialize::carmodel2 = "volatus";
	}	
	if (carmodel == "luxor2") {
		initialize::carmodel1 = "elt_dlc_luxe";
		initialize::carmodel2 = "luxor2";
	}
	if (carmodel == "swift2") {
		initialize::carmodel1 = "elt_dlc_luxe";
		initialize::carmodel2 = "swift2";
	}
	if (carmodel == "besra") {
		initialize::carmodel1 = "elt_dlc_pilot";
		initialize::carmodel2 = "besra";
	}
	if (carmodel == "miljet") {
		initialize::carmodel1 = "elt_dlc_pilot";
		initialize::carmodel2 = "miljet";
	}
	if (carmodel == "swift") {
		initialize::carmodel1 = "elt_dlc_pilot";
		initialize::carmodel2 = "swift";
	}
	if (carmodel == "alphaz1") {
		initialize::carmodel1 = "elt_dlc_smuggler";
		initialize::carmodel2 = "alphaz1";
	}
	if (carmodel == "havok") {
		initialize::carmodel1 = "elt_dlc_smuggler";
		initialize::carmodel2 = "havok";
	}
	if (carmodel == "howard") {
		initialize::carmodel1 = "elt_dlc_smuggler";
		initialize::carmodel2 = "howard";
	}
	if (carmodel == "microlight") {
		initialize::carmodel1 = "elt_dlc_smuggler";
		initialize::carmodel2 = "microlight";
	}
	if (carmodel == "seabreeze") {
		initialize::carmodel1 = "elt_dlc_smuggler";
		initialize::carmodel2 = "seabreeze";
	}
	if (carmodel == "transportation_1") {
		initialize::carmodel1 = "foreclosures_bunker";
		initialize::carmodel2 = "transportation_1";
	}
	if (carmodel == "transportation_2") {
		initialize::carmodel1 = "foreclosures_bunker";
		initialize::carmodel2 = "transportation_2";
	}
	if (carmodel == "adder") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "adder";
	}
	if (carmodel == "banshee") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "banshee";
	}
	if (carmodel == "bullet") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "bullet";
	}
	if (carmodel == "carbon") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "carbon";
	}
	if (carmodel == "carboniz") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "carboniz";
	}
	if (carmodel == "cheetah") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "cheetah";
	}
	if (carmodel == "cogcabri") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "cogcabri";
	}
	if (carmodel == "comet2") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "comet2";
	}
	if (carmodel == "coquette") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "coquette";
	}
	if (carmodel == "elegy2") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "elegy2";
	}
	if (carmodel == "entityxf") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "entityxf";
	}
	if (carmodel == "exemplar") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "exemplar";
	}
	if (carmodel == "feltzer") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "feltzer";
	}
	if (carmodel == "hotknife") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "hotknife";
	}
	if (carmodel == "infernus") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "infernus";
	}
	if (carmodel == "jb700") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "jb700";
	}
	if (carmodel == "khamel") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "khamel";
	}
	if (carmodel == "monroe") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "monroe";
	}
	if (carmodel == "ninef") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "ninef";
	}
	if (carmodel == "ninef2") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "ninef2";
	}
	if (carmodel == "rapidgt") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "rapidgt";
	}
	if (carmodel == "stinger") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "stinger";
	}
	if (carmodel == "stingerg") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "stingerg";
	}
	if (carmodel == "superd") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "superd";
	}
	if (carmodel == "surano_convertable") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "surano_convertable";
	}
	if (carmodel == "vacca") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "vacca";
	}
	if (carmodel == "voltic_tless") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "voltic_tless";
	}
	if (carmodel == "ztype") {
		initialize::carmodel1 = "lgm_default";
		initialize::carmodel2 = "ztype";
	}
	if (carmodel == "baller3") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "baller3";
	}
	if (carmodel == "baller4") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "baller4";
	}
	if (carmodel == "cog55") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "cog55";
	}
	if (carmodel == "cognosc") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "cognosc";
	}
	if (carmodel == "mamba") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "mamba";
	}
	if (carmodel == "niteshad") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "niteshad";
	}
	if (carmodel == "schafter3") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "schafter3";
	}
	if (carmodel == "schafter4") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "schafter4";
	}
	if (carmodel == "verlier") {
		initialize::carmodel1 = "lgm_dlc_apartments";
		initialize::carmodel2 = "verlier";
	}
	if (carmodel == "clique") {
		initialize::carmodel1 = "lgm_dlc_arena";
		initialize::carmodel2 = "clique";
	}
	if (carmodel == "cliquexmas") {
		initialize::carmodel1 = "lgm_dlc_arena";
		initialize::carmodel2 = "cliquexmas";
	}
	if (carmodel == "deveste") {
		initialize::carmodel1 = "lgm_dlc_arena";
		initialize::carmodel2 = "deveste";
	}
	if (carmodel == "deviant") {
		initialize::carmodel1 = "lgm_dlc_arena";
		initialize::carmodel2 = "deviant";
	}
	if (carmodel == "italigto") {
		initialize::carmodel1 = "lgm_dlc_arena";
		initialize::carmodel2 = "italigto";
	}
	if (carmodel == "schlagen") {
		initialize::carmodel1 = "lgm_dlc_arena";
		initialize::carmodel2 = "schlagen";
	}
	if (carmodel == "toros") {
		initialize::carmodel1 = "lgm_dlc_arena";
		initialize::carmodel2 = "toros";
	}
	if (carmodel == "entity2") {
		initialize::carmodel1 = "lgm_dlc_assault";
		initialize::carmodel2 = "entity2";
	}
	if (carmodel == "flashgt") {
		initialize::carmodel1 = "lgm_dlc_assault";
		initialize::carmodel2 = "flashgt";
	}
	if (carmodel == "gb200") {
		initialize::carmodel1 = "lgm_dlc_assault";
		initialize::carmodel2 = "gb200";
	}
	if (carmodel == "jester3") {
		initialize::carmodel1 = "lgm_dlc_assault";
		initialize::carmodel2 = "jester3";
	}
	if (carmodel == "taipan") {
		initialize::carmodel1 = "lgm_dlc_assault";
		initialize::carmodel2 = "taipan";
	}
	if (carmodel == "tezeract") {
		initialize::carmodel1 = "lgm_dlc_assault";
		initialize::carmodel2 = "tezeract";
	}
	if (carmodel == "tyrant") {
		initialize::carmodel1 = "lgm_dlc_assault";
		initialize::carmodel2 = "tyrant";
	}
	if (carmodel == "freecrawler") {
		initialize::carmodel1 = "lgm_dlc_battle";
		initialize::carmodel2 = "freecrawler";
	}
	if (carmodel == "stafford") {
		initialize::carmodel1 = "lgm_dlc_battle";
		initialize::carmodel2 = "stafford";
	}
	if (carmodel == "swinger") {
		initialize::carmodel1 = "lgm_dlc_battle";
		initialize::carmodel2 = "swinger";
	}
	if (carmodel == "hakuchou2") {
		initialize::carmodel1 = "lgm_dlc_biker";
		initialize::carmodel2 = "hakuchou2";
	}
	if (carmodel == "raptor") {
		initialize::carmodel1 = "lgm_dlc_biker";
		initialize::carmodel2 = "raptor";
	}
	if (carmodel == "shotaro") {
		initialize::carmodel1 = "lgm_dlc_biker";
		initialize::carmodel2 = "shotaro";
	}
	if (carmodel == "alpha") {
		initialize::carmodel1 = "lgm_dlc_business";
		initialize::carmodel2 = "alpha";
	}
	if (carmodel == "jester") {
		initialize::carmodel1 = "lgm_dlc_business";
		initialize::carmodel2 = "jester";
	}
	if (carmodel == "turismor") {
		initialize::carmodel1 = "lgm_dlc_business";
		initialize::carmodel2 = "turismor";
	}
	if (carmodel == "banshee_tless") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "banshee_tless";
	}
	if (carmodel == "coquette_tless") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "coquette_tless";
	}
	if (carmodel == "huntley") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "huntley";
	}
	if (carmodel == "massacro") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "massacro";
	}
	if (carmodel == "stinger_tless") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "stinger_tless";
	}
	if (carmodel == "thrust") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "thrust";
	}
	if (carmodel == "voltic_htop") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "voltic_htop";
	}
	if (carmodel == "zentorno") {
		initialize::carmodel1 = "lgm_dlc_business2";
		initialize::carmodel2 = "zentorno";
	}		
	if (carmodel == "formula") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "formula";
	}
	if (carmodel == "formula2") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "formula2";
	}
	if (carmodel == "furia") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "furia";
	}
	if (carmodel == "imorgon") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "imorgon";
	}		
	if (carmodel == "komoda") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "komoda";
	}
	if (carmodel == "rebla") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "rebla";
	}
	if (carmodel == "stryder") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "stryder";
	}
	if (carmodel == "vstr") {
		initialize::carmodel1 = "lgm_dlc_casinoheist";
		initialize::carmodel2 = "vstr";
	}
	if (carmodel == "bestiagts") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "bestiagts";
	}
	if (carmodel == "fmj") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "fmj";
	}
	if (carmodel == "pfister811") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "pfister811";
	}
	if (carmodel == "prototipo") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "prototipo";
	}
	if (carmodel == "reaper") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "reaper";
	}
	if (carmodel == "seven70") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "seven70";
	}
	if (carmodel == "windsor2") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "windsor2";
	}
	if (carmodel == "xls") {
		initialize::carmodel1 = "lgm_dlc_executive1";
		initialize::carmodel2 = "xls";
	}
	if (carmodel == "cheetah2") {
		initialize::carmodel1 = "lgm_dlc_gunrunning";
		initialize::carmodel2 = "cheetah2";
	}
	if (carmodel == "terero") {
		initialize::carmodel1 = "lgm_dlc_gunrunning";
		initialize::carmodel2 = "terero";
	}
	if (carmodel == "vagner") {
		initialize::carmodel1 = "lgm_dlc_gunrunning";
		initialize::carmodel2 = "vagner";
	}
	if (carmodel == "xa21") {
		initialize::carmodel1 = "lgm_dlc_gunrunning";
		initialize::carmodel2 = "xa21";
	}
	if (carmodel == "casco") {
		initialize::carmodel1 = "lgm_dlc_heist";
		initialize::carmodel2 = "casco";
	}
	if (carmodel == "lectro") {
		initialize::carmodel1 = "lgm_dlc_heist";
		initialize::carmodel2 = "lectro";
	}
	if (carmodel == "penetrator") {
		initialize::carmodel1 = "lgm_dlc_importexport";
		initialize::carmodel2 = "penetrator";
	}
	if (carmodel == "tempesta") {
		initialize::carmodel1 = "lgm_dlc_importexport";
		initialize::carmodel2 = "tempesta";
	}
	if (carmodel == "furore") {
		initialize::carmodel1 = "lgm_dlc_lts_creator";
		initialize::carmodel2 = "furore";
	}
	if (carmodel == "brawler") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "brawler";
	}
	if (carmodel == "chino") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "chino";
	}
	if (carmodel == "coquette3") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "coquette3";
	}
	if (carmodel == "feltzer3") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "feltzer3";
	}
	if (carmodel == "osiris") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "osiris";
	}
	if (carmodel == "t20") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "t20";
	}
	if (carmodel == "vindicator") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "vindicator";
	}
	if (carmodel == "virgo") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "virgo";
	}
	if (carmodel == "windsor") {
		initialize::carmodel1 = "lgm_dlc_luxe";
		initialize::carmodel2 = "windsor";
	}
	if (carmodel == "coquette2") {
		initialize::carmodel1 = "lgm_dlc_pilot";
		initialize::carmodel2 = "coquette2";
	}
	if (carmodel == "coquette2_tless") {
		initialize::carmodel1 = "lgm_dlc_pilot";
		initialize::carmodel2 = "coquette2_tless";
	}
	if (carmodel == "cyclone") {
		initialize::carmodel1 = "lgm_dlc_smuggler";
		initialize::carmodel2 = "cyclone";
	}
	if (carmodel == "rapidgt3") {
		initialize::carmodel1 = "lgm_dlc_smuggler";
		initialize::carmodel2 = "rapidgt3";
	}
	if (carmodel == "visione") {
		initialize::carmodel1 = "lgm_dlc_smuggler";
		initialize::carmodel2 = "visione";
	}		
	if (carmodel == "gp1") {
		initialize::carmodel1 = "lgm_dlc_specialraces";
		initialize::carmodel2 = "gp1";
	}
	if (carmodel == "infernus2") {
		initialize::carmodel1 = "lgm_dlc_specialraces";
		initialize::carmodel2 = "infernus2";
	}		
	if (carmodel == "ruston") {
		initialize::carmodel1 = "lgm_dlc_specialraces";
		initialize::carmodel2 = "ruston";
	}
	if (carmodel == "turismo2") {
		initialize::carmodel1 = "lgm_dlc_specialraces";
		initialize::carmodel2 = "turismo2";
	}
	if (carmodel == "le7b") {
		initialize::carmodel1 = "lgm_dlc_stunt";
		initialize::carmodel2 = "le7b";
	}
	if (carmodel == "lynx") {
		initialize::carmodel1 = "lgm_dlc_stunt";
		initialize::carmodel2 = "lynx";
	}
	if (carmodel == "sheava") {
		initialize::carmodel1 = "lgm_dlc_stunt";
		initialize::carmodel2 = "sheava";
	}
	if (carmodel == "tyrus") {
		initialize::carmodel1 = "lgm_dlc_stunt";
		initialize::carmodel2 = "tyrus";
	}
	if (carmodel == "roosevelt") {
		initialize::carmodel1 = "lgm_dlc_valentines";
		initialize::carmodel2 = "roosevelt";
	}
	if (carmodel == "roosevelt2") {
		initialize::carmodel1 = "lgm_dlc_valentines2";
		initialize::carmodel2 = "roosevelt2";
	}
	if (carmodel == "drafter") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "drafter";
	}
	if (carmodel == "emerus") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "emerus";
	}
	if (carmodel == "jugular") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "jugular";
	}
	if (carmodel == "krieger") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "krieger";
	}
	if (carmodel == "locust") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "locust";
	}
	if (carmodel == "neo") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "neo";
	}
	if (carmodel == "novak") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "novak";
	}
	if (carmodel == "paragon") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "paragon";
	}
	if (carmodel == "rrocket") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "rrocket";
	}
	if (carmodel == "s80") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "s80";
	}
	if (carmodel == "thrax") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "thrax";
	}
	if (carmodel == "zorrusso") {
		initialize::carmodel1 = "lgm_dlc_vinewood";
		initialize::carmodel2 = "zorrusso";
	}
	if (carmodel == "autarch") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "autarch";
	}
	if (carmodel == "comet4") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "comet4";
	}
	if (carmodel == "comet5") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "comet5";
	}
	if (carmodel == "gt500") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "gt500";
	}
	if (carmodel == "hustler") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "hustler";
	}
	if (carmodel == "neon") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "neon";
	}
	if (carmodel == "pariah") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "pariah";
	}
	if (carmodel == "raiden") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "raiden";
	}
	if (carmodel == "revolter") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "revolter";
	}
	if (carmodel == "savestra") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "savestra";
	}
	if (carmodel == "sc1") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "sc1";
	}
	if (carmodel == "streiter") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "streiter";
	}
	if (carmodel == "viseris") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "viseris";
	}
	if (carmodel == "z190") {
		initialize::carmodel1 = "lgm_dlc_xmas2017";
		initialize::carmodel2 = "z190";
	}
	if (carmodel == "buzzaneer2") {
		initialize::carmodel1 = "lsc_default";
		initialize::carmodel2 = "buzzaneer2";
	}
	if (carmodel == "chino2") {
		initialize::carmodel1 = "lsc_default";
		initialize::carmodel2 = "chino2";
	}
	if (carmodel == "faction2") {
		initialize::carmodel1 = "lsc_default";
		initialize::carmodel2 = "faction2";
	}
	if (carmodel == "primo2") {
		initialize::carmodel1 = "lsc_default";
		initialize::carmodel2 = "primo2";
	}
	if (carmodel == "voodoo") {
		initialize::carmodel1 = "lsc_default";
		initialize::carmodel2 = "voodoo";
	}
	if (carmodel == "comet3") {
		initialize::carmodel1 = "lsc_dlc_import_export";
		initialize::carmodel2 = "comet3";
	}
	if (carmodel == "diablous2") {
		initialize::carmodel1 = "lsc_dlc_import_export";
		initialize::carmodel2 = "diablous2";
	}
	if (carmodel == "elegy") {
		initialize::carmodel1 = "lsc_dlc_import_export";
		initialize::carmodel2 = "elegy";
	}
	if (carmodel == "fcr2") {
		initialize::carmodel1 = "lsc_dlc_import_export";
		initialize::carmodel2 = "fcr2";
	}
	if (carmodel == "italigtb2") {
		initialize::carmodel1 = "lsc_dlc_import_export";
		initialize::carmodel2 = "italigtb2";
	}
	if (carmodel == "nero2") {
		initialize::carmodel1 = "lsc_dlc_import_export";
		initialize::carmodel2 = "nero2";
	}
	if (carmodel == "specter2") {
		initialize::carmodel1 = "lsc_dlc_import_export";
		initialize::carmodel2 = "specter2";
	}
	if (carmodel == "banshee2") {
		initialize::carmodel1 = "lsc_jan2016";
		initialize::carmodel2 = "banshee2";
	}
	if (carmodel == "sultan2") {
		initialize::carmodel1 = "lsc_jan2016";
		initialize::carmodel2 = "sultan2";
	}
	if (carmodel == "faction3") {
		initialize::carmodel1 = "lsc_lowrider2";
		initialize::carmodel2 = "faction3";
	}
	if (carmodel == "minivan2") {
		initialize::carmodel1 = "lsc_lowrider2";
		initialize::carmodel2 = "minivan2";
	}
	if (carmodel == "sabregt2") {
		initialize::carmodel1 = "lsc_lowrider2";
		initialize::carmodel2 = "sabregt2";
	}
	if (carmodel == "slamvan3") {
		initialize::carmodel1 = "lsc_lowrider2";
		initialize::carmodel2 = "slamvan3";
	}
	if (carmodel == "tornado5") {
		initialize::carmodel1 = "lsc_lowrider2";
		initialize::carmodel2 = "tornado5";
	}
	if (carmodel == "virgo2") {
		initialize::carmodel1 = "lsc_lowrider2";
		initialize::carmodel2 = "virgo2";
	}
	if (carmodel == "bmx") {
		initialize::carmodel1 = "pandm_default";
		initialize::carmodel2 = "bmx";
	}
	if (carmodel == "cruiser") {
		initialize::carmodel1 = "pandm_default";
		initialize::carmodel2 = "cruiser";
	}
	if (carmodel == "scorcher") {
		initialize::carmodel1 = "pandm_default";
		initialize::carmodel2 = "scorcher";
	}
	if (carmodel == "tribike") {
		initialize::carmodel1 = "pandm_default";
		initialize::carmodel2 = "tribike";
	}
	if (carmodel == "tribike2") {
		initialize::carmodel1 = "pandm_default";
		initialize::carmodel2 = "tribike2";
	}
	if (carmodel == "tribike3") {
		initialize::carmodel1 = "pandm_default";
		initialize::carmodel2 = "tribike3";
	}
	if (carmodel == "akuma") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "akuma";
	}	
	if (carmodel == "baller2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "baller2";
	}
	if (carmodel == "banshee") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "banshee";
	}
	if (carmodel == "bati") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "bati";
	}
	if (carmodel == "bati2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "bati2";
	}
	if (carmodel == "bfinject") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "bfinject";
	}
	if (carmodel == "bifta") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "bifta";
	}
	if (carmodel == "bison") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "bison";
	}
	if (carmodel == "blazer") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "blazer";
	}
	if (carmodel == "bodhi2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "bodhi2";
	}
	if (carmodel == "cavcade") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "cavcade";
	}
	if (carmodel == "comet2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "comet2";
	}
	if (carmodel == "delettan") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "delettan";
	}
	if (carmodel == "double") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "double";
	}
	if (carmodel == "dune") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "dune";
	}
	if (carmodel == "examplar") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "examplar";
	}
	if (carmodel == "faggio") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "faggio";
	}
	if (carmodel == "felon") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "felon";
	}
	if (carmodel == "felon2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "felon2";
	}
	if (carmodel == "feltzer") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "feltzer";
	}
	if (carmodel == "fugitive") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "fugitive";
	}	
	if (carmodel == "gauntlet") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "gauntlet";
	}
	if (carmodel == "hexer") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "hexer";
	}
	if (carmodel == "infernus") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "infernus";
	}
	if (carmodel == "issi2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "issi2";
	}
	if (carmodel == "kalahari") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "kalahari";
	}
	if (carmodel == "ninef") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "ninef";
	}
	if (carmodel == "oracle") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "oracle";
	}
	if (carmodel == "paradise") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "paradise";
	}
	if (carmodel == "pcj") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "pcj";
	}
	if (carmodel == "rebel") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "rebel";
	}
	if (carmodel == "rocoto") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "rocoto";
	}
	if (carmodel == "ruffian") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "ruffian";
	}
	if (carmodel == "sadler") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "sadler";
	}
	if (carmodel == "sanchez") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "sanchez";
	}
	if (carmodel == "sanchez2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "sanchez2";
	}
	if (carmodel == "sandkin2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "sandkin2";
	}
	if (carmodel == "sandking") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "sandking";
	}		
	if (carmodel == "schwarze") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "schwarze";
	}		
	if (carmodel == "stretch") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "stretch";
	}
	if (carmodel == "superd") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "superd";
	}		
	if (carmodel == "surano") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "surano";
	}
	if (carmodel == "vacca") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "vacca";
	}
	if (carmodel == "vader") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "vader";
	}
	if (carmodel == "vigero") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "vigero";
	}
	if (carmodel == "zion") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "zion";
	}
	if (carmodel == "zion2") {
		initialize::carmodel1 = "sssa_default";
		initialize::carmodel2 = "zion2";
	}	
	if (carmodel == "blista3") {
		initialize::carmodel1 = "sssa_dlc_arena";
		initialize::carmodel2 = "blista3";
	}
	if (carmodel == "rcbandito") {
		initialize::carmodel1 = "sssa_dlc_arena";
		initialize::carmodel2 = "rcbandito";
	}
	if (carmodel == "tulip") {
		initialize::carmodel1 = "sssa_dlc_arena";
		initialize::carmodel2 = "tulip";
	}
	if (carmodel == "vamos") {
		initialize::carmodel1 = "sssa_dlc_arena";
		initialize::carmodel2 = "vamos";
	}
	if (carmodel == "cheburek") {
		initialize::carmodel1 = "sssa_dlc_assault";
		initialize::carmodel2 = "cheburek";
	}
	if (carmodel == "dominator3") {
		initialize::carmodel1 = "sssa_dlc_assault";
		initialize::carmodel2 = "dominator3";
	}
	if (carmodel == "ellie") {
		initialize::carmodel1 = "sssa_dlc_assault";
		initialize::carmodel2 = "ellie";
	}
	if (carmodel == "fagaloa") {
		initialize::carmodel1 = "sssa_dlc_assault";
		initialize::carmodel2 = "fagaloa";
	}
	if (carmodel == "hotring") {
		initialize::carmodel1 = "sssa_dlc_assault";
		initialize::carmodel2 = "hotring";
	}
	if (carmodel == "issi3") {
		initialize::carmodel1 = "sssa_dlc_assault";
		initialize::carmodel2 = "issi3";
	}
	if (carmodel == "michelli") {
		initialize::carmodel1 = "sssa_dlc_assault";
		initialize::carmodel2 = "michelli";
	}
	if (carmodel == "bjxl") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "bjxl";
	}
	if (carmodel == "fq2") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "fq2";
	}
	if (carmodel == "futo") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "futo";
	}
	if (carmodel == "habanero") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "habanero";
	}
	if (carmodel == "patriot") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "patriot";
	}
	if (carmodel == "patriot2") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "patriot2";
	}
	if (carmodel == "pbus2") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "pbus2";
	}
	if (carmodel == "prairie") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "prairie";
	}
	if (carmodel == "romero") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "romero";
	}
	if (carmodel == "ruiner") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "ruiner";
	}
	if (carmodel == "serrano") {
		initialize::carmodel1 = "sssa_dlc_battle";
		initialize::carmodel2 = "serrano";
	}
	if (carmodel == "avarus") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "avarus";
	}
	if (carmodel == "bagger") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "bagger";
	}
	if (carmodel == "blazer4") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "blazer4";
	}
	if (carmodel == "chimera") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "chimera";
	}
	if (carmodel == "daemon2") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "daemon2";
	}
	if (carmodel == "defiler") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "defiler";
	}
	if (carmodel == "esskey") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "esskey";
	}
	if (carmodel == "faggio3") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "faggio3";
	}
	if (carmodel == "faggion") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "faggion";
	}
	if (carmodel == "manchez") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "manchez";
	}
	if (carmodel == "nightblade") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "nightblade";
	}
	if (carmodel == "ratbike") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "ratbike";
	}
	if (carmodel == "sanctus") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "sanctus";
	}
	if (carmodel == "tornado6") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "tornado6";
	}
	if (carmodel == "vortex") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "vortex";
	}
	if (carmodel == "wolfsbane") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "wolfsbane";
	}
	if (carmodel == "youga2") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "youga2";
	}
	if (carmodel == "zombiea") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "zombiea";
	}
	if (carmodel == "zombieb") {
		initialize::carmodel1 = "sssa_dlc_biker";
		initialize::carmodel2 = "zombieb";
	}
	if (carmodel == "asea") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "asea";
	}
	if (carmodel == "astrope") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "astrope";
	}
	if (carmodel == "bobcatxl") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "bobcatxl";
	}
	if (carmodel == "cavcade2") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "cavcade2";
	}
	if (carmodel == "granger") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "granger";
	}
	if (carmodel == "ingot") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "ingot";
	}
	if (carmodel == "intruder") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "intruder";
	}
	if (carmodel == "minivan") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "minivan";
	}
	if (carmodel == "premier") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "premier";
	}
	if (carmodel == "radi") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "radi";
	}
	if (carmodel == "rancherx") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "rancherx";
	}
	if (carmodel == "stanier") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "stanier";
	}
	if (carmodel == "stratum") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "stratum";
	}
	if (carmodel == "washingt") {
		initialize::carmodel1 = "sssa_dlc_business";
		initialize::carmodel2 = "washingt";
	}
	if (carmodel == "dominato") {
		initialize::carmodel1 = "sssa_dlc_business2";
		initialize::carmodel2 = "dominato";
	}
	if (carmodel == "f620") {
		initialize::carmodel1 = "sssa_dlc_business2";
		initialize::carmodel2 = "f620";
	}
	if (carmodel == "fusilade") {
		initialize::carmodel1 = "sssa_dlc_business2";
		initialize::carmodel2 = "fusilade";
	}
	if (carmodel == "penumbra") {
		initialize::carmodel1 = "sssa_dlc_business2";
		initialize::carmodel2 = "penumbra";
	}
	if (carmodel == "sentinel") {
		initialize::carmodel1 = "sssa_dlc_business2";
		initialize::carmodel2 = "sentinel";
	}
	if (carmodel == "sentinel_convertable") {
		initialize::carmodel1 = "sssa_dlc_business2";
		initialize::carmodel2 = "sentinel_convertable";
	}
	if (carmodel == "asbo") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "asbo";
	}
	if (carmodel == "everon") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "everon";
	}
	if (carmodel == "kanjo") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "kanjo";
	}
	if (carmodel == "outlaw") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "outlaw";
	}
	if (carmodel == "retinue2") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "retinue2";
	}
	if (carmodel == "sugoi") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "sugoi";
	}
	if (carmodel == "sultan2") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "sultan2";
	}
	if (carmodel == "vagrant") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "vagrant";
	}		
	if (carmodel == "yosemite2") {
		initialize::carmodel1 = "sssa_dlc_casinoheist";
		initialize::carmodel2 = "yosemite2";
	}
	if (carmodel == "jester2") {
		initialize::carmodel1 = "sssa_dlc_christmas_2";
		initialize::carmodel2 = "jester2";
	}
	if (carmodel == "massacro2") {
		initialize::carmodel1 = "sssa_dlc_christmas_2";
		initialize::carmodel2 = "massacro2";
	}
	if (carmodel == "rloader2") {
		initialize::carmodel1 = "sssa_dlc_christmas_2";
		initialize::carmodel2 = "rloader2";
	}
	if (carmodel == "slamvan") {
		initialize::carmodel1 = "sssa_dlc_christmas_2";
		initialize::carmodel2 = "slamvan";
	}
	if (carmodel == "tampa") {
		initialize::carmodel1 = "sssa_dlc_christmas_3";
		initialize::carmodel2 = "tampa";
	}
	if (carmodel == "rumpo3") {
		initialize::carmodel1 = "sssa_dlc_executive_1";
		initialize::carmodel2 = "rumpo3";
	}
	if (carmodel == "btype2") {
		initialize::carmodel1 = "sssa_dlc_halloween";
		initialize::carmodel2 = "btype2";
	}
	if (carmodel == "lurcher") {
		initialize::carmodel1 = "sssa_dlc_halloween";
		initialize::carmodel2 = "lurcher";
	}
	if (carmodel == "blade") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "blade";
	}
	if (carmodel == "enduro") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "enduro";
	}
	if (carmodel == "gburrito2") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "gburrito2";
	}
	if (carmodel == "gresley") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "gresley";
	}
	if (carmodel == "guardian") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "guardian";
	}
	if (carmodel == "innovation") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "innovation";
	}
	if (carmodel == "jackal") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "jackal";
	}
	if (carmodel == "kuruma") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "kuruma";
	}
	if (carmodel == "kuruma2") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "kuruma2";
	}
	if (carmodel == "landstalker") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "landstalker";
	}
	if (carmodel == "nemesis") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "nemesis";
	}	
	if (carmodel == "oracle1") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "oracle1";
	}
	if (carmodel == "rumpo") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "rumpo";
	}
	if (carmodel == "schafter2") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "schafter2";
	}
	if (carmodel == "seminole") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "seminole";
	}
	if (carmodel == "surge") {
		initialize::carmodel1 = "sssa_dlc_heist";
		initialize::carmodel2 = "surge";
	}		
	if (carmodel == "blade") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "blade";
	}
	if (carmodel == "blazer3") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "blazer3";
	}
	if (carmodel == "buffalo") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "buffalo";
	}
	if (carmodel == "buffalo2") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "buffalo2";
	}
	if (carmodel == "glendale") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "glendale";
	}
	if (carmodel == "panto") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "panto";
	}
	if (carmodel == "picador") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "picador";
	}
	if (carmodel == "pigalle") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "pigalle";
	}
	if (carmodel == "primo") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "primo";
	}
	if (carmodel == "rebel2") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "rebel2";
	}
	if (carmodel == "regina") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "regina";
	}
	if (carmodel == "rhapsody") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "rhapsody";
	}
	if (carmodel == "surfer") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "surfer";
	}
	if (carmodel == "tailgater") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "tailgater";
	}
	if (carmodel == "warrener") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "warrener";
	}
	if (carmodel == "youga") {
		initialize::carmodel1 = "sssa_dlc_hipster";
		initialize::carmodel2 = "youga";
	}
	if (carmodel == "sovereign") {
		initialize::carmodel1 = "sssa_dlc_independence";
		initialize::carmodel2 = "sovereign";
	}
	if (carmodel == "hakuchou") {
		initialize::carmodel1 = "sssa_dlc_lts_creator";
		initialize::carmodel2 = "hakuchou";
	}
	if (carmodel == "innovation") {
		initialize::carmodel1 = "sssa_dlc_lts_creator";
		initialize::carmodel2 = "innovation";
	}
	if (carmodel == "kalahari_topless") {
		initialize::carmodel1 = "sssa_dlc_lts_creator";
		initialize::carmodel2 = "kalahari_topless";
	}
	if (carmodel == "blista2") {
		initialize::carmodel1 = "sssa_dlc_mp_to_sp";
		initialize::carmodel2 = "blista2";
	}
	if (carmodel == "buffalo3") {
		initialize::carmodel1 = "sssa_dlc_mp_to_sp";
		initialize::carmodel2 = "buffalo3";
	}
	if (carmodel == "dominator2") {
		initialize::carmodel1 = "sssa_dlc_mp_to_sp";
		initialize::carmodel2 = "dominator2";
	}
	if (carmodel == "dukes") {
		initialize::carmodel1 = "sssa_dlc_mp_to_sp";
		initialize::carmodel2 = "dukes";
	}
	if (carmodel == "gauntlet2") {
		initialize::carmodel1 = "sssa_dlc_mp_to_sp";
		initialize::carmodel2 = "gauntlet2";
	}
	if (carmodel == "stalion2") {
		initialize::carmodel1 = "sssa_dlc_mp_to_sp";
		initialize::carmodel2 = "stalion2";
	}
	if (carmodel == "stallion") {
		initialize::carmodel1 = "sssa_dlc_mp_to_sp";
		initialize::carmodel2 = "stallion";
	}
	if (carmodel == "retinue") {
		initialize::carmodel1 = "sssa_dlc_smuggler";
		initialize::carmodel2 = "retinue";
	}
	if (carmodel == "retinue") {
		initialize::carmodel1 = "sssa_dlc_smuggler";
		initialize::carmodel2 = "retinue";
	}	
	if (carmodel == "bf400") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "bf400";
	}
	if (carmodel == "brioso") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "brioso";
	}
	if (carmodel == "cliffhanger") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "cliffhanger";
	}
	if (carmodel == "contender") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "contender";
	}
	if (carmodel == "gargoyle") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "gargoyle";
	}
	if (carmodel == "omnis") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "omnis";
	}
	if (carmodel == "rallytruck") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "rallytruck";
	}
	if (carmodel == "tampa2") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "tampa2";
	}
	if (carmodel == "trophy") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "trophy";
	}
	if (carmodel == "trophy2") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "trophy2";
	}
	if (carmodel == "tropos") {
		initialize::carmodel1 = "sssa_dlc_stunt";
		initialize::carmodel2 = "tropos";
	}
	if (carmodel == "rloader") {
		initialize::carmodel1 = "sssa_dlc_valentines";
		initialize::carmodel2 = "rloader";
	}
	if (carmodel == "caracara2") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "caracara2";
	}
	if (carmodel == "dynasty") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "dynasty";
	}
	if (carmodel == "gauntlet3") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "gauntlet3";
	}	
	if (carmodel == "gauntlet4") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "gauntlet4";
	}
	if (carmodel == "hellion") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "hellion";
	}
	if (carmodel == "impaler") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "impaler";
	}
	if (carmodel == "issi7") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "issi7";
	}
	if (carmodel == "nebula") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "nebula";
	}
	if (carmodel == "peyote2") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "peyote2";
	}
	if (carmodel == "zion3") {
		initialize::carmodel1 = "sssa_dlc_vinewood";
		initialize::carmodel2 = "zion3";
	}
	if (carmodel == "hermes") {
		initialize::carmodel1 = "sssa_dlc_xmas2017";
		initialize::carmodel2 = "hermes";
	}
	if (carmodel == "kamacho") {
		initialize::carmodel1 = "sssa_dlc_xmas2017";
		initialize::carmodel2 = "kamacho";
	}
	if (carmodel == "riata") {
		initialize::carmodel1 = "sssa_dlc_xmas2017";
		initialize::carmodel2 = "riata";
	}
	if (carmodel == "sentinel3") {
		initialize::carmodel1 = "sssa_dlc_xmas2017";
		initialize::carmodel2 = "sentinel3";
	}
	if (carmodel == "streiter") {
		initialize::carmodel1 = "sssa_dlc_xmas2017";
		initialize::carmodel2 = "streiter";
	}
	if (carmodel == "yosemite") {
		initialize::carmodel1 = "sssa_dlc_xmas2017";
		initialize::carmodel2 = "yosemite";
	}	
	if (carmodel == "brutus1") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "brutus1";
	}
	if (carmodel == "brutus2") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "brutus2";
	}
	if (carmodel == "brutus3") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "brutus3";
	}
	if (carmodel == "cerberus1") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "cerberus1";
	}
	if (carmodel == "cerberus2") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "cerberus2";
	}
	if (carmodel == "cerberus3") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "cerberus3";
	}
	if (carmodel == "dominato") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "dominato";
	}
	if (carmodel == "gargoyle") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "gargoyle";
	}
	if (carmodel == "glendale") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "glendale";
	}
	if (carmodel == "impaler") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "impaler";
	}
	if (carmodel == "imperator1") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "imperator1";
	}
	if (carmodel == "imperator2") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "imperator2";
	}
	if (carmodel == "imperator3") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "imperator3";
	}
	if (carmodel == "issi3") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "issi3";
	}
	if (carmodel == "rloader") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "rloader";
	}
	if (carmodel == "scarab1") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "scarab1";
	}
	if (carmodel == "scarab2") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "scarab2";
	}
	if (carmodel == "scarab3") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "scarab3";
	}
	if (carmodel == "slamvan") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "slamvan";
	}
	if (carmodel == "zr3801") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "zr3801";
	}
	if (carmodel == "zr3802") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "zr3802";
	}
	if (carmodel == "zr3803") {
		initialize::carmodel1 = "mba_vehicles";
		initialize::carmodel2 = "zr3803";
	}
	if (carmodel == "splash_centre") {
		initialize::carmodel1 = "www_arenawar_tv";
		initialize::carmodel2 = "splash_centre";
	}
	if (carmodel == "suemurry_background_left") {
		initialize::carmodel1 = "www_suemurry_com";
		initialize::carmodel2 = "suemurry_background_left";
	}
	if (carmodel == "mural_0_0") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_0";
	}
	if (carmodel == "mural_0_1") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_1";
	}
	if (carmodel == "mural_0_2") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_2";
	}
	if (carmodel == "mural_0_3") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_3";
	}
	if (carmodel == "mural_0_4") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_4";
	}
	if (carmodel == "mural_0_5") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_5";
	}
	if (carmodel == "mural_0_6") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_6";
	}
	if (carmodel == "mural_0_7") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_7";
	}
	if (carmodel == "mural_0_8") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_8";
	}
	if (carmodel == "mural_1_0") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_0";
	}
	if (carmodel == "mural_1_1") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_1";
	}
	if (carmodel == "mural_1_2") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_2";
	}
	if (carmodel == "mural_1_3") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_3";
	}
	if (carmodel == "mural_1_4") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_4";
	}
	if (carmodel == "mural_1_5") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_5";
	}
	if (carmodel == "mural_1_6") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_6";
	}
	if (carmodel == "mural_1_7") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_7";
	}
	if (carmodel == "mural_1_8") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_1_8";
	}	
	if (carmodel == "emblem_0") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_0";
	}
	if (carmodel == "emblem_1") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_1";
	}
	if (carmodel == "emblem_2") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_2";
	}
	if (carmodel == "emblem_3") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_3";
	}
	if (carmodel == "emblem_4") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_4";
	}
	if (carmodel == "emblem_5") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_5";
	}
	if (carmodel == "emblem_6") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_6";
	}
	if (carmodel == "emblem_7") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_7";
	}
	if (carmodel == "emblem_8") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_8";
	}	
	if (carmodel == "alkonost") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "alkonost";
	}
	if (carmodel == "annihilator2") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "annihlator2";
	}
	if (carmodel == "avisa") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "avisa";
	}
	if (carmodel == "brioso2") {
		initialize::carmodel1 = "sssa_dlc_heist4";
		initialize::carmodel2 = "brioso2";
	}
	if (carmodel == "dinghy5") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "dinghy5";
	}
	if (carmodel == "italirsx") {
		initialize::carmodel1 = "lgm_dlc_heist4";
		initialize::carmodel2 = "italirsx";
	}
	if (carmodel == "kosatka") {
		initialize::carmodel1 = "candc_sub";
		initialize::carmodel2 = "thumbnail";
	}
	if (carmodel == "longfin") {
		initialize::carmodel1 = "dock_dlc_heist4";
		initialize::carmodel2 = "longfin";
	}
	if (carmodel == "manchez2") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "manchez2";
	}
	if (carmodel == "patrolboat") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "patrolboat";
	}
	if (carmodel == "seasparrow2") {
		initialize::carmodel1 = "foreclosures_signage";
		initialize::carmodel2 = "emblem_0";
	}
	if (carmodel == "seasparrow3") {
		initialize::carmodel1 = "foreclosures_mural";
		initialize::carmodel2 = "mural_0_1";
	}
	if (carmodel == "slamtruck") {
		initialize::carmodel1 = "sssa_dlc_heist4";
		initialize::carmodel2 = "slamtruck";
	}
	if (carmodel == "squaddie") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "squaddie";
	}
	if (carmodel == "toreador") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "toreador";
	}
	if (carmodel == "verus") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "verus";
	}
	if (carmodel == "vetir") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "vetir";
	}
	if (carmodel == "veto") {
		initialize::carmodel1 = "sssa_dlc_heist4";
		initialize::carmodel2 = "veto";
	}
	if (carmodel == "veto2") {
		initialize::carmodel1 = "sssa_dlc_heist4";
		initialize::carmodel2 = "veto2";
	}
	if (carmodel == "weevil") {
		initialize::carmodel1 = "sssa_dlc_heist4";
		initialize::carmodel2 = "weevil";
	}
	if (carmodel == "winky") {
		initialize::carmodel1 = "candc_heist4";
		initialize::carmodel2 = "winky";
	}
	return 0;
} //scaleform_web

void initialize::showpicturesofcars() {
char* carmodel11 = new char[initialize::carmodel1.length() + 1];
strcpy(carmodel11, initialize::carmodel1.c_str());
char* carmodel22 = new char[initialize::carmodel2.length() + 1];
strcpy(carmodel22, initialize::carmodel2.c_str());
Menu::Drawing::Spriter(carmodel11, carmodel22, Features::screenX, Features::screenY, Features::width, Features::height, Features::heading, Features::red, Features::green, Features::blue, Features::alpha);
}

int firstloading()
{
	DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;
	ticks /= 1000;
	DWORD seconds = ticks % 60;
	int getTimer = seconds;
	if (getTimer % 3 == 0)
	{

		/*if (firstread2)
		{*/
		string addplayer = Directory::get_current_dir() + "\\ThunderMenu\\addPlayer\\";
		std::ifstream addplayers;
		addplayers.open(addplayer);
		if (!addplayers)
		{
			makeaddPlayerfolder();
		}
		std::string ConfigPath = Directory::get_current_dir() + "\\ThunderMenu\\ThunderConfig.ini";
		std::ifstream ConfigCheck;
		ConfigCheck.open(ConfigPath);
		if (ConfigCheck)
		{
			MenuConfig::ConfigInit();
			MenuConfig::ConfigRead();
			/*if (loaded::FirstTimer) {
				Features::Lupbool = 1;
			}
			if (!loaded::FirstTimer) {
				Features::Lupbool = 0;
			}*/
				login2::loginin2();
			//Log::Msg("log2");
	//std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
		if (!ConfigCheck)
		{
			MenuConfig::ConfigInit();
			MenuConfig::ConfigSave();

			//initializing::makefirstconfig();
			login2::loginin();
		}

		/*firstread2 = 0;
	}*/
	}
	return 0;
}
#include <iostream>
#include <windows.h>

bool doesFolderExist(const std::string& folderPath) {
	DWORD fileAttributes = GetFileAttributesA(folderPath.c_str());
	return (fileAttributes != INVALID_FILE_ATTRIBUTES && (fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}

bool createFolder(const std::string& folderPath) {
	return CreateDirectoryA(folderPath.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
}
bool initialize::thunderytd = 0;

int initialize::mainytd() {
	char buffer[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, buffer);
	std::string GitDownloadPath = std::string(buffer) + "\\ThunderMenu\\";

	if (!doesFolderExist(GitDownloadPath)) {
		if (createFolder(GitDownloadPath)) {
			initialize::thunderytd = 1;
			//std::cout << "Le dossier a été créé : " << GitDownloadPath << std::endl;
		}
		else {
			initialize::thunderytd = 0;
			//std::cout << "Échec de la création du dossier : " << GitDownloadPath << std::endl;
		}
	}
	else {
		initialize::thunderytd = 1;
		//std::cout << "Le dossier existe déjà : " << GitDownloadPath << std::endl;
	}

	return 0;
}

bool bloadregister = 1;
void initialize::loadingmenu()
{
	firstloading();
	timer::dixsecondebool = true;
	notifyMap("Options Loading");
	std::string GitDownloadPath = Directory::get_current_dir() + "\\ThunderMenu\\Thunder.ytd";
	std::ifstream GitDownload;
	GitDownload.open(GitDownloadPath);
	if (!GitDownload)
	{
			makeoutfitfolder();
			Github::downloading();
			notifyMap("new Thunder.ytd file downloaded");
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	GitDownload.close();
	DiscordApp::discordmain();
	initialize::mainytd();

	if (initialize::thunderytd)
	{
		notifyMap("~r~Thunder Ultimate function loaded");
		char ThunderMenu[255];
		strcpy_s(ThunderMenu, "ThunderMenu/");
		strcat_s(ThunderMenu, "Thunder.ytd");
		int textureID = -1;
		Hooking::pRegisterFile(&textureID, ThunderMenu, true, "Thunder.ytd", false);
		if (textureID != -1)
		{
			Log::Msg("ThunderMenu register OK");
		}
		else
			Log::Msg("Failed to register ThunderMenu %s", ThunderMenu);
	}
	if (load::namechangers)
	{
		Features::namechanged();
	}
}

//void initializing::makefirstconfig()
//{
//	/*Hooking::protect = false;
//	Features::titleRect = false;
//	Features::optionRect = false;
//	Features::RGBSCROLLER = false;
//	Features::RGBTITLE = false;
//	Features::RGBTEXTE = false;
//	MenuConfig::bSaveAtIntervals = true;
//	timer::realtime222 = true;
//	load::namechangers = true;
//	Features::MobileRadio = false;
//	Features::spawnincar = true;
//	Features::spawnmaxed = true;
//	Features::Neverwanted = true;
//	Features::antiafk = true;
//	Features::SonicRun = false;
//	Features::fastswim = false;
//	Features::osk = false;
//	Features::playerGodMode = true;
//	Features::playersuperjump = true;
//	Features::boostboolb = true;
//	Features::AutoClear = false;
//	Features::Seat = false;
//	Features::infammo = true;
//	Features::Speedometerbool = true;
//	Features::cargodmodebool = true;
//	Features::vehiclegun = false;
//	Features::brakebool = false;
//	Features::enginealwaysonbool = false;
//	Features::GeoLocation = true;
//	Features::sp_vehicle_bypass = true;
//	Features::mainprotection = false;
//	Features::infoplayer = true;
//	Features::header02 = false;
//	Features::header012 = false;
//	Features::optionText1bool = false;
//	Features::scroller0bool = false;
//	Features::titlestextbool = false;
//	Features::menucolors = false;
//	Hooking::geteventdata = false;
//	Hooking::dump = false;
//	Hooking::protect = false;
//	Features::ThunderLog = false;
//	droptimer::picbackbool2 = false;
//	droptimer::picbackbool = false;
//	Menu2::OpenMenu = 80;
//	Menu2::OpenMenu = 73;
//	Menu2::OpenMenu = 106;
//	Menu2::OpenMenu8 = 104;
//	Menu2::OpenMenu6 = 102;
//	Menu2::OpenMenu5 = 101;
//	Menu2::OpenMenu4 = 100;
//	Menu2::OpenMenu2 = 98;
//	Menu2::OpenMenu0 = 96;
//	Features::waveban = false;
//	Features::CustomCar = true;
//	Features::ptfx2car = true;
//	Features::ptfx2car01 = false;
//	Features::ptfx2car02 = false;
//	Features::ptfx2car03 = false;
//	Features::ptfx2car04 = false;
//	Features::ptfx2car05 = false;
//	Features::ptfx2car06 = false;
//	Features::ptfx2car07 = false;
//	Features::ptfx2car08 = false;
//	Features::ptfx2car09 = false;
//	Features::ptfx2car12 = false;
//	Features::ptfx2car13 = false;
//	Features::ptfx2car14 = false;
//	Features::ptfx2car15 = false;
//	Features::ptfx2car16 = false;
//	Features::ptfx2car17 = false;
//	Features::ptfx2car18 = false;
//	Features::rapidfirer = false;
//	Features::orbool2 = false;
//	Features::showall = false;
//	Features::ZoneStreetbool = true;
//	Features::Drift = true;
//	Features::burnout = false;
//	Features::Rneon = false;
//	Features::showback = false;
//	Features::menucolors = false;
//	Features::dropbool = true;
//	Features::selecArrow = false;
//	Features::DisplayFPS = true;
//	Features::NameESP = true;
//	Features::esper = true;
//	Features::dowbool = false;
//	Features::vehjump = false;
//	Features::rr = 255;
//	Features::gg = 0;
//	Features::bb = 0;
//	Features::rr5 = 255;
//	Features::gg5 = 0;
//	Features::bb5 = 0;
//	Features::rw2 = 255;
//	Features::gw2 = 0;
//	Features::bw2 = 0;
//	Features::optionText6 = 255;
//	Features::optionText7 = 6;
//	Features::rw = 255;
//	Features::gw = 0;
//	Features::bw = 0;
//	Features::Scroller4 = 150;
//	Features::rw1 = 255;
//	Features::gw1 = 0;
//	Features::bw1 = 0;
//	Features::title4 = 200;
//	Features::title5 = 7;
//	Features::redint = 0;
//	Features::greenint = 0;
//	Features::blueint = 255;
//	Features::alphaint = 255;
//	Features::bennystypeok = 11;
//	Features::bennysok = 137;
//	Features::paintcolor01 = 0;
//	Features::paintcolor02 = 0;
//	Features::paintcolor03 = 255;
//	Features::chrome = 120;
//	Features::hornsound = 43;
//	droptimer::timertimes = 500;
//	droptimer::timertimes2 = 50;
//	timesback::lastpicid = 15;
//	timesback::lastpicid2 = 5;
//	FeaturesOnline::zeropointcentvingt = -0.106300;
//	FeaturesOnline::zeropointcentvingttrois = 0.003000;
//	Features::zeropointquarantecinq = 0.450000;
//	Features::zeropointtrentedeux = 0.320000;
//	Features::centvingt = -0.050000;
//	Features::zeroundeuxtrois = 0.665000;
//	Features::zerotroiscentsoixantequinze = 0.575000;
//	Features::xzerovingt = 0.500000;
//	Features::yzerodix = 0.010000;
//	Menu::Settings::menuX = 0.849000;
//	Menu::Settings::menuY = 0.000000;
//	Features::menuXPositionX = 1.199000;
//	Features::zeropointcentvingtf = 0.000000;
//	Features::zeropointundeuxtroisf = 0.643000;
//	Features::zeropointtroiscentsoixantequinzef = 0.545000;
//	Features::zeropointhuitcent = 0.849999;
//	Features::zeropointmillecentsoixantequinze = 0.117500;
//	Features::zeropointvingtetun = 0.210000;
//	Features::zeropointhuitcenttt = 0.860000;
//	Features::zeropointmillecentsoixantequinzettt = 0.427500;
//	Features::zeropointvingtetunttt = 0.190000;
//	Features::zeropointzeroquatrevingtcinq = 0.535000;
//	Features::deuxzerosepthuit = -0.242000;
//	Features::zerounquatredeux = 0.062000;
//	Features::deuxzeroquinze = 0.027000;
//	Features::deuxzerodeuxsept = 0.035000;
//	Features::screenX = 0.690000;
//	Features::screenY = 0.167500;
//	Features::width = 0.105000;
//	Features::height = 0.180000;
//	Features::heading = 0.000000;
//	Features::nameespsize = 0.200000;
//	Features::HeaderMenu = "";
//	Features::HeaderMenu2 = "";
//	headers::Background = "";
//	headers::Background2 = "";
//	timesback::backgroundfile = "";
//	Features::hudcolor1 = "HUD_COLOUR_NORTH_BLUE";
//	Features::hudcolor2 = "HUD_COLOUR_NORTH_BLUE_OFFICIAL";
//	Features::username = "Thunder-Menu";
//	Features::Sounds1 = "";
//	Features::Notify = "CHAR_STRIPPER_CHEETAH";
//	authentification2::username2 = "";
//	authentification2::password2 = "";*/
//	MenuConfig::ConfigSave();
//}

//float ScaleformMovie::posx = 0.0f;
//float ScaleformMovie::posy = 0.0f;
//float ScaleformMovie::posz = 0.0f;
//float ScaleformMovie::posx1 = 0.0f;
//float ScaleformMovie::posy1 = 0.0f;

float ScaleformMovie::posx = 0.40f;
float ScaleformMovie::posy = 0.0f;
float ScaleformMovie::posz = 0.0f;
float ScaleformMovie::posx1 = 0.40f;
float ScaleformMovie::posy1 = 0.0f;

float ScaleformMovie::posz1 = 0.0f;
float ScaleformMovie::poszheight = 0.50f;
float ScaleformMovie::poszwidth = 1.0f;
int ScaleformMovie::red = 255;
int ScaleformMovie::green = 255;
int ScaleformMovie::blue = 255;
int ScaleformMovie::alpha = 255;

//char* IntToString(int data) {
//	std::string strData = std::to_string(data);
//
//	char* temp = new char[strData.length() + 1];
//	strcpy(temp, strData.c_str());
//
//	return temp;
//}
//char* IntToChar(int data)
//{
//stringstream strs;
//strs << data;
//string temp_str = strs.str();
//char* char_type = (char*)temp_str.c_str();
//return char_type;
////std::string s = std::to_string(number);
////char const* pchar = s.c_str();  //use char const* as target type
//}
Vector3 addVector2(Vector3 vector, Vector3 vector2) {
	vector.x += vector2.x;
	vector.y += vector2.y;
	vector.z += vector2.z;
	vector._paddingx += vector2._paddingx;
	vector._paddingy += vector2._paddingy;
	vector._paddingz += vector2._paddingz;
	return vector;
}
double DegreeToRadian2(double n) {
	return n * 0.017453292519943295;
}
Vector3 RotationToDirection2(Vector3 rot) {
	double num = DegreeToRadian2(rot.z);
	double num2 = DegreeToRadian2(rot.x);
	double val = cos(num2);
	double num3 = abs(val);
	rot.x = (float)(-(float)sin(num) * num3);
	rot.y = (float)(cos(num) * num3);
	rot.z = (float)sin(num2);
	return rot;
}

Vector3 multiplyVector2(Vector3 vector, float inc) {
	vector.x *= inc;
	vector.y *= inc;
	vector.z *= inc;
	vector._paddingx *= inc;
	vector._paddingy *= inc;
	vector._paddingz *= inc;
	return vector;
}

int inthash(std::string str) {
	std::hash<std::string> hasher;
	auto hashed = hasher(str);
	std::cout << hashed << '\n';
	return hashed;
}
#define FLOAT_TO_INT(x) (static_cast<int>(x) + ((x - static_cast<int>(x)) >= 0.5 ? 1 : 0))

//#define FLOAT_TO_INT(x) /*((x)>=0?*/(int)((x)+0.5)/*:(int)((x)-0.5))*/
//bool ScaleformMovie::VehicleInfoBool = 0;
//void ScaleformMovie::VehicleInfoVoid()
//{
//	PLAYER::_EXPAND_WORLD_LIMITS(FLT_MAX, FLT_MAX, FLT_MAX);
//	const int ElementAmount = 10;
//	const int ArrSize = ElementAmount * 2 + 2;
//	Vehicle* vehs = new Vehicle[ArrSize];
//	vehs[0] = ElementAmount;
//	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);
//	for (int i = 0; i < VehFound; i++)
//	{
//		int OffsetID = i * 2 + 2;
//		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
//		{
//			RequestControlOfEnt(vehs[OffsetID]);
//			const int scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE("mp_car_stats_01");
//			if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(scaleform))
//			{
//				/*Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID());*/
//				Hash vehHash = ENTITY::GET_ENTITY_MODEL(/*PED::GET_VEHICLE_PED_IS_IN(*/vehs[OffsetID]/*, 0)*/);
//				/*stringstream vehoffset;
//				vehoffset << VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash);
//				std::string strData = vehoffset.str();*/
//				std::string strData = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash);
//				/*std::string strData = std::to_string(vehs[OffsetID]);*/
//				char* temp = new char[strData.length() + 1];
//				strcpy(temp, strData.c_str());
//
//				//const int MAX_SPEED = 400;
//				//const int MAX_ACCELERATION = 100;
//				//const int MAX_HAND_BRAKE = 100;
//
//				//int vehiclemaxspeed = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_MAX_SPEED(HASH::GET_HASH_KEY(temp))));
//				//int vehicleacceleration = static_cast<int>(FLOAT_TO_INT(VEHICLE::GET_VEHICLE_MODEL_ACCELERATION(HASH::GET_HASH_KEY(temp)) * 100));
//				//int vehiclehandbrake = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_HAND_BRAKE(HASH::GET_HASH_KEY(temp)) * 100));
//				//int vehiclemaxtraction = static_cast<int>(FLOAT_TO_INT(VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION(HASH::GET_HASH_KEY(temp)) * 10));
//
//				//int vehiclemaxbraking = static_cast<int>(FLOAT_TO_INT(VEHICLE::GET_VEHICLE_MODEL_MAX_BRAKING(HASH::GET_HASH_KEY(temp)) * 100));
//				//int vehicledownforce = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_DOWN_FORCE(HASH::GET_HASH_KEY(temp)) * 100));
//				//int vehiclemaxknots = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_MAX_KNOTS(HASH::GET_HASH_KEY(temp)) * 100));
//				//int vehiclemoveresistance = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_MOVE_RESISTANCE(HASH::GET_HASH_KEY(temp)) * 100));
//
//				const int MAX_SPEED = 400;
//				const int MAX_ACCELERATION = 100;
//				const int MAX_HAND_BRAKE = 100;
//				const int MAX_TRACTION = 100;  // Adjust this based on your game's maximum possible value
//				const int MAX_BRAKING = 100;  // Similarly, adjust this
//				const int MAX_DOWNFORCE = 100; // Adjust this
//				const int MAX_KNOTS = 100; // Adjust this
//				const int MAX_RESISTANCE = 100; // Adjust this
//
//				int vehiclemaxspeed = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_MAX_SPEED(HASH::GET_HASH_KEY(temp))));
//				int vehicleacceleration = static_cast<int>(FLOAT_TO_INT(VEHICLE::GET_VEHICLE_MODEL_ACCELERATION(HASH::GET_HASH_KEY(temp)) * 100));
//				int vehiclehandbrake = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_HAND_BRAKE(HASH::GET_HASH_KEY(temp)) * 100));
//				int vehiclemaxtraction = static_cast<int>(FLOAT_TO_INT(VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION(HASH::GET_HASH_KEY(temp)) * 10));
//				int vehiclemaxbraking = static_cast<int>(FLOAT_TO_INT(VEHICLE::GET_VEHICLE_MODEL_MAX_BRAKING(HASH::GET_HASH_KEY(temp)) * 100));
//				int vehicledownforce = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_DOWN_FORCE(HASH::GET_HASH_KEY(temp)) * 100));
//				int vehiclemaxknots = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_MAX_KNOTS(HASH::GET_HASH_KEY(temp)) * 100));
//				int vehiclemoveresistance = static_cast<int>(FLOAT_TO_INT(VEHICLE::_GET_VEHICLE_MODEL_MOVE_RESISTANCE(HASH::GET_HASH_KEY(temp)) * 100));
//
//				// Now, compute percentages
//				int vehiclemaxspeedPercent = (vehiclemaxspeed * 100) / MAX_SPEED;
//				int vehicleaccelerationPercent = (vehicleacceleration * 100) / MAX_ACCELERATION;
//				int vehiclehandbrakePercent = (vehiclehandbrake * 100) / MAX_HAND_BRAKE;
//				int vehiclemaxtractionPercent = (vehiclemaxtraction * 100) / MAX_TRACTION;
//				int vehiclemaxbrakingPercent = (vehiclemaxbraking * 100) / MAX_BRAKING;
//				int vehicledownforcePercent = (vehicledownforce * 100) / MAX_DOWNFORCE;
//				int vehiclemaxknotsPercent = (vehiclemaxknots * 100) / MAX_KNOTS;
//				int vehiclemoveresistancePercent = (vehiclemoveresistance * 100) / MAX_RESISTANCE;
//
//
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(temp);
//				GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(scaleform, "SET_VEHICLE_INFOR_AND_STATS");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(temp);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("Vehicle Stat Menu");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("MPCarHUD");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(temp);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("MAX SPEED");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("ACCELERATION");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("HAND BRAKE");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("TRACTION");
//				//GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(temp);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("MAX BRAKING");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("DOWN FORCE");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("MAX KNOTS");
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("MOVE RESISTANCE");
//
//				/*Vector3 pCoords = ENTITY::GET_ENTITY_COORDS(ENTITY::GET_ENTITY_MODEL(vehs[OffsetID]), 1);*/
//				/*GRAPHICS::END_TEXT_COMMAND_SCALEFORM_STRING();*/
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclemaxspeedPercent);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehicleaccelerationPercent);;
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclehandbrakePercent);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclemaxtractionPercent);
//
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclemaxbrakingPercent);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehicledownforcePercent);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclemaxknotsPercent);
//				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(vehiclemoveresistancePercent);
//
//				//Vector3 vehCoords = ENTITY::GET_ENTITY_COORDS(vehs[OffsetID], 1);
//
//				//// Draw the scaleform movie at vehicle's position
//				// 				Vector3 vehCoords = ENTITY::GET_ENTITY_COORDS(vehs[OffsetID], 1);
//				//float aboveVehZ = vehCoords.z + 2.0f;  // ajuster le 2.0f en fonction de la hauteur souhaitée
//
//				//GRAPHICS::DRAW_SCALEFORM_MOVIE(scaleform, vehCoords.x, vehCoords.y, aboveVehZ, ScaleformMovie::poszheight, ScaleformMovie::red, ScaleformMovie::green, ScaleformMovie::blue, ScaleformMovie::alpha, 0);
//
//				//GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
//
//
//
//				GRAPHICS::DRAW_SCALEFORM_MOVIE(scaleform, ScaleformMovie::posx, ScaleformMovie::posy, ScaleformMovie::poszwidth, ScaleformMovie::poszheight, ScaleformMovie::red, ScaleformMovie::green, ScaleformMovie::blue, ScaleformMovie::alpha, 0);
//				GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
//			}
//		}
//	}
//		delete[] vehs;
//}

bool ScaleformMovie::VehicleInfoBool = 0;

void ScaleformMovie::VehicleInfoVoid()
{
	PLAYER::_EXPAND_WORLD_LIMITS(FLT_MAX, FLT_MAX, FLT_MAX);
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;
	Vehicle* vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		if (vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
		{
			RequestControlOfEnt(vehs[OffsetID]);
			const int scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE("mp_car_stats_01");

			if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(scaleform))
			{
				Hash vehHash = ENTITY::GET_ENTITY_MODEL(vehs[OffsetID]);
				std::string strData = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(vehHash);
				char* temp = new char[strData.length() + 1];
				strcpy(temp, strData.c_str());

				const int MAX_RECTANGLE_PERCENTAGE = 20;  // Chaque rectangle peut représenter jusqu'à 20%.
				const int NUM_RECTANGLES = 5;

				const int MAX_VALUES[] = { 400, 100, 100, 100, 100, 100, 100, 100 };
				int stats[] = {
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::_GET_VEHICLE_MODEL_MAX_SPEED(HASH::GET_HASH_KEY(temp)))/*)*/,
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::GET_VEHICLE_MODEL_ACCELERATION(HASH::GET_HASH_KEY(temp))/* * 100*/)/*)*/,
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::_GET_VEHICLE_MODEL_HAND_BRAKE(HASH::GET_HASH_KEY(temp))/* * 100*/)/*)*/,
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::GET_VEHICLE_MODEL_MAX_TRACTION(HASH::GET_HASH_KEY(temp))/* * 10*/)/*)*/,
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::GET_VEHICLE_MODEL_MAX_BRAKING(HASH::GET_HASH_KEY(temp))/* * 100*/)/*)*/,
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::_GET_VEHICLE_MODEL_DOWN_FORCE(HASH::GET_HASH_KEY(temp))/* * 100*/)/*)*/,
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::_GET_VEHICLE_MODEL_MAX_KNOTS(HASH::GET_HASH_KEY(temp))/* * 100*/)/*)*/,
					static_cast<int>(/*FLOAT_TO_INT(*/VEHICLE::_GET_VEHICLE_MODEL_MOVE_RESISTANCE(HASH::GET_HASH_KEY(temp))/* * 100*/)/*)*/
				};

				/*int percentages[8];
				for (int j = 0; j < 8; j++)
					percentages[j] = (stats[j] * 100) / MAX_VALUES[j];*/
				int percentages[NUM_RECTANGLES];

				// Calculez les pourcentages initiaux
				for (int i = 0; i < NUM_RECTANGLES; i++) {
					percentages[i] = (stats[i] * 100) / MAX_VALUES[i];
					if (percentages[i] > MAX_RECTANGLE_PERCENTAGE) {
						percentages[i] = MAX_RECTANGLE_PERCENTAGE;
					}
				}

				// Distribuez les pourcentages excédentaires
				int excess = 0;
				for (int i = 0; i < NUM_RECTANGLES; i++) {
					if (percentages[i] > MAX_RECTANGLE_PERCENTAGE) {
						excess += percentages[i] - MAX_RECTANGLE_PERCENTAGE;
						percentages[i] = MAX_RECTANGLE_PERCENTAGE;
					}
				}

				for (int i = 0; i < NUM_RECTANGLES && excess > 0; i++) {
					if (percentages[i] < MAX_RECTANGLE_PERCENTAGE) {
						int availableSpace = MAX_RECTANGLE_PERCENTAGE - percentages[i];
						int toAdd = min(availableSpace, excess);
						percentages[i] += toAdd;
						excess -= toAdd;
					}
				}

				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(temp);
				GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(scaleform, "SET_VEHICLE_INFOR_AND_STATS");
				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(temp);
				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("Vehicle Stat Menu");
				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING("MPCarHUD");
				GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(temp);
				const char* statNames[] = { "MAX SPEED", "ACCELERATION", "HAND BRAKE", "TRACTION", "MAX BRAKING", "DOWN FORCE", "MAX KNOTS", "MOVE RESISTANCE" };
				/*for (const char* name : statNames)
					GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(name);*/
				for (const char* name : statNames)
					GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_STRING(const_cast<char*>(name));

				for (int value : percentages)
					GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_INT(value * 50);

				GRAPHICS::DRAW_SCALEFORM_MOVIE(scaleform, ScaleformMovie::posx, ScaleformMovie::posy, ScaleformMovie::poszwidth, ScaleformMovie::poszheight, ScaleformMovie::red, ScaleformMovie::green, ScaleformMovie::blue, ScaleformMovie::alpha, 0);
				GRAPHICS::END_SCALEFORM_MOVIE_METHOD();

				delete[] temp;
			}
		}
	}

	delete[] vehs;
}
