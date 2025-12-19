#pragma once
#include "stdafx.h"
void Mains::dropModelsSelect() {
	Menu::Break("Models");
	if (Menu::Option("Plastic Bag (2.5k)")) { Features::bagHash = 0x9CA6F755; }
	if (Menu::Option("Money Bag")) { Features::bagHash = HASH::GET_HASH_KEY("prop_money_bag_01"); }
	if (Menu::Option("Alien Egg")) { Features::bagHash = HASH::GET_HASH_KEY("prop_alien_egg_01"); }
	if (Menu::Option("Dildo")) { Features::bagHash = HASH::GET_HASH_KEY("prop_cs_dildo_01"); }
	if (Menu::Option("Xmas Tree")) { Features::bagHash = HASH::GET_HASH_KEY("prop_xmas_tree_int"); }
	if (Menu::Option("Armor")) { Features::bagHash = HASH::GET_HASH_KEY("prop_armour_pickup"); }
	if (Menu::Option("Med Bag")) { Features::bagHash = HASH::GET_HASH_KEY("prop_med_bag_01"); }
	if (Menu::Option("Handbag")) { Features::bagHash = HASH::GET_HASH_KEY("prop_ld_handbag"); }
	if (Menu::Option("Gun Case")) { Features::bagHash = HASH::GET_HASH_KEY("prop_gun_case_01"); }
	if (Menu::Option("Golf Bag")) { Features::bagHash = HASH::GET_HASH_KEY("prop_golf_bag_01"); }
	if (Menu::Option("Whiskey Bottle")) { Features::bagHash = HASH::GET_HASH_KEY("prop_cs_whiskey_bottle"); }
	if (Menu::Option("Toaster")) { Features::bagHash = HASH::GET_HASH_KEY("prop_cs_toaster"); }
	if (Menu::Option("Plane")) { Features::bagHash = HASH::GET_HASH_KEY("prop_dummy_plane"); }
	if (Menu::Option("Bottle")) { Features::bagHash = HASH::GET_HASH_KEY("prop_cs_beer_bot_01"); }
	if (Menu::Option("Weight")) { Features::bagHash = HASH::GET_HASH_KEY("prop_barbell_10kg"); }
	if (Menu::Option("Guitar")) { Features::bagHash = HASH::GET_HASH_KEY("prop_acc_guitar_01"); }
	if (Menu::Option("Safe")) { Features::bagHash = HASH::GET_HASH_KEY("prop_ld_int_safe_01"); }
	if (Menu::Option("Medkit")) { Features::bagHash = HASH::GET_HASH_KEY("prop_ld_health_pack"); }
	if (Menu::Option("Purse")) { Features::bagHash = HASH::GET_HASH_KEY("prop_ld_purse_01"); }
	if (Menu::Option("Bin Bag")) { Features::bagHash = HASH::GET_HASH_KEY("prop_ld_rub_binbag_01"); }
	if (Menu::Option("Suitcase")) { Features::bagHash = HASH::GET_HASH_KEY("prop_ld_suitcase_01"); }
	if (Menu::Option("Shoe")) { Features::bagHash = HASH::GET_HASH_KEY("prop_ld_shoe_01"); }
	if (Menu::Option("Megaphone")) { Features::bagHash = HASH::GET_HASH_KEY("prop_megaphone_01"); }
	if (Menu::Option("Minigun")) { Features::bagHash = HASH::GET_HASH_KEY("prop_minigun_01"); }
}

