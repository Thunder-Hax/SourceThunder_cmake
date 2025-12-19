#include "stdafx.h"
#include "PersistOutfit.h"
#include "OutfitList.h"
#include "Gui.h"
#include "Geo.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


#include <thread>
#include <chrono>

#include <cstdlib> 
#include <cstring>
#include <conio.h>

#include <iomanip>

#include <direct.h>
#define GetCurrentDir _getcwd
#include <wchar.h>
#include <errno.h>

#include <sstream>

#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

#include "nlohmann/json.hpp"
using namespace nlohmann;

#include <limits>

#include "Hooking.h"

int imin = INT_MIN; // minimum value
int imax = INT_MAX;

nlohmann::json j;

json toJson(const char* jsonString) {
	json jsonObj;
	std::stringstream(jsonString) >> jsonObj;

	return jsonObj;

}

char* CharKeyboardsavea(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	WAIT(50);
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return ""; //1
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

char* CharKeyboardsaveab(char* windowName = "", int maxInput = 21, char* defaultText = "") {
	WAIT(50);
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return ""; //1
	return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

std::string GeoLocation::GeoLoc = "";
std::string GeoLocation::GeoLoc2 = "";
#pragma execution_character_set("utf-8")

	void persist_outfit::save_outfit(std::string OutfitName1, int Face1, int Head1, int Hair1, int Torso1, int Legs1, int Hands1, int Feet1, int Eyes1, int Accessories1, int Tasks1, int Textures1, int Torso21, int HeadProp1, int EyeProp1, int EarProp1)
	{
		attachment::attachment attachment;
		attachment.OutfitName = OutfitName1;
		attachment.Face = Face1;
		attachment.Head = Head1;
		attachment.Hair = Hair1;
		attachment.Torso = Torso1;
		attachment.Legs = Legs1;
		attachment.Hands = Hands1;
		attachment.Feet = Feet1;
		attachment.Eyes = Eyes1;
		attachment.Accessories = Accessories1;
		attachment.Tasks = Tasks1;
		attachment.Textures = Textures1;
		attachment.Torso2 = Torso21;
		attachment.HeadProp = HeadProp1;
		attachment.EyeProp = EyeProp1;
		attachment.EarProp = EarProp1;
		save(attachment, OutfitName1);
	}

	int loadoutfit()
	{
		Features::face = Outfit::Face;
		Features::head = Outfit::Head;
		Features::hair = Outfit::Hair;
		Features::torso = Outfit::Torso;
		Features::legs = Outfit::Legs;
		Features::hands = Outfit::Hands;
		Features::feet = Outfit::Feet;
		Features::eyes = Outfit::Eyes;
		Features::accesories = Outfit::Accessories;
		Features::accesoriessec = Outfit::Tasks;
		Features::textures = Outfit::Textures;
		Features::torsosec = Outfit::Torso2;
		Features::HeadPropint = Outfit::HeadProp;
		Features::EyePropint = Outfit::EyeProp;
		Features::EarPropint = Outfit::EarProp;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 0, Outfit::Face, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 1, Outfit::Head, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 2, Outfit::Hair, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 3, Outfit::Torso, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 4, Outfit::Legs, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, Outfit::Hands, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 6, Outfit::Feet, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 7, Outfit::Eyes, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 8, Outfit::Accessories, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, Outfit::Tasks, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 10, Outfit::Textures, 0, 0);
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 11, Outfit::Torso2, 0, 0);
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 1, Outfit::HeadProp, 0, 0);
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 2, Outfit::EyeProp, 0, 0);
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), 3, Outfit::EarProp, 0, 0);
		return 0;
	}
	void persist_outfit::load_outfit(std::string OutfitName1, int Face1, int Head1, int Hair1, int Torso1, int Legs1, int Hands1, int Feet1, int Eyes1, int Accessories1, int Tasks1, int Textures1, int Torso21, int HeadProp1, int EyeProp1, int EarProp1)
	{
		auto locations = get_locations_json();
		if (locations[OutfitName1].is_null())
			return;
		auto model_attachment = locations[OutfitName1].get<attachment::attachment>();
		Outfit::OutfitName = model_attachment.OutfitName;
		Outfit::Face = model_attachment.Face;
		Outfit::Head = model_attachment.Head;
		Outfit::Hair = model_attachment.Hair;
		Outfit::Torso = model_attachment.Torso;
		Outfit::Legs = model_attachment.Legs;
		Outfit::Hands = model_attachment.Hands;
		Outfit::Feet = model_attachment.Feet;
		Outfit::Eyes = model_attachment.Eyes;
		Outfit::Accessories = model_attachment.Accessories;
		Outfit::Tasks = model_attachment.Tasks;
		Outfit::Textures = model_attachment.Textures;
		Outfit::Torso2 = model_attachment.Torso2;
		Outfit::HeadProp = model_attachment.HeadProp;
		Outfit::EyeProp = model_attachment.EyeProp;
		Outfit::EarProp = model_attachment.EarProp;
		loadoutfit();
	}

	void persist_outfit::delete_outfit(std::string name)
	{
		auto locations = get_locations_json();
		if (locations[name].is_null())
			return;
		locations.erase(name);
		save_json(locations);
	}

	std::vector<std::string> persist_outfit::list_locations()
	{
		std::vector<std::string> return_value;
		auto json = get_locations_json();
		for (auto& item : json.items())
			return_value.push_back(item.key());
		return return_value;
	}

	int resultpos = 0;
	int resultpos2 = 0;
	void persist_outfit::do_presentation_layer()
	{
		auto outfits = list_locations();
		static std::string selected_outfit;
		int vecint = 0;
			std::vector<char*> charVec(outfits.size(), nullptr);
			for (int i = 0; i < outfits.size(); i++) {
				charVec[i] = &outfits[i][0];
				vecint = i;
			}
			if (vecint != 0)
			{
				if (Menu2::ListVector("List", charVec, resultpos)) {
					char* result = charVec[resultpos];
					selected_outfit = result;
				}
			}

	if (Menu::Option("save"))
	{
		Outfit::savedoutfits();
		Outfit::OutfitName = Outfit::outfitnamesaved;
		if (Outfit::OutfitName != "")
		{
			Outfit::Face = Features::face;
			Outfit::Head = Features::head;
			Outfit::Hair = Features::hair;
			Outfit::Torso = Features::torso;
			Outfit::Legs = Features::legs;
			Outfit::Hands = Features::hands;
			Outfit::Feet = Features::feet;
			Outfit::Eyes = Features::eyes;
			Outfit::Accessories = Features::accesories;
			Outfit::Tasks = Features::accesoriessec;
			Outfit::Textures = Features::textures;
			Outfit::Torso2 = Features::torsosec;
			Outfit::HeadProp = Features::HeadPropint;
			Outfit::EyeProp = Features::EyePropint;
			Outfit::EarProp = Features::EarPropint;
			save_outfit(Outfit::OutfitName, Outfit::Face, Outfit::Head, Outfit::Hair, Outfit::Torso, Outfit::Legs, Outfit::Hands, Outfit::Feet, Outfit::Eyes, Outfit::Accessories, Outfit::Tasks, Outfit::Textures, Outfit::Torso2, Outfit::HeadProp, Outfit::EyeProp, Outfit::EarProp);
		}
	}
	if (vecint != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_outfit.empty())
			{
				Outfit::OutfitName = selected_outfit;
				load_outfit(Outfit::OutfitName, Outfit::Face, Outfit::Head, Outfit::Hair, Outfit::Torso, Outfit::Legs, Outfit::Hands, Outfit::Feet, Outfit::Eyes, Outfit::Accessories, Outfit::Tasks, Outfit::Textures, Outfit::Torso2, Outfit::HeadProp, Outfit::EyeProp, Outfit::EarProp);
				selected_outfit.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_outfit.empty())
			{
				delete_outfit(selected_outfit);
				selected_outfit.clear();
			}
		}
	}
	}

	void persist_outfit::save(attachment::attachment attachment, std::string name)
	{
		auto json = get_locations_json();
		json[name] = attachment;
		save_json(json);
	}

	void persist_outfit::save_json(nlohmann::json json)
	{
		auto file_path = get_locations_config();
		std::ofstream file(file_path, std::ios::out | std::ios::trunc);
		file << json.dump(4);
		file.close();
	}

	nlohmann::json persist_outfit::get_locations_json()
	{
		auto file_path = get_locations_config();
		nlohmann::json locations;
		std::ifstream file(file_path);

		if (!file.fail())
			file >> locations;

		return locations;
	}


	/*std::filesystem::path persist_outfit::get_locations_config()*/
	std::string persist_outfit::get_locations_config()
	{
		Outfit::checkoutfitfolder();
		/*std::string result;
        for (auto const& s : Directory::get_current_dir()) { result += s; }*/
		auto file_path = Directory::get_current_dir();
		file_path += "\\ThunderMenu\\Outfit\\";
		/*auto file_path = std::filesystem::path(std::getenv("appdata"));
		file_path /= "Miscellaneous";

		if (!std::filesystem::exists(file_path))
		{
			std::filesystem::create_directory(file_path);
		}
		else if (!std::filesystem::is_directory(file_path))
		{
			std::filesystem::remove(file_path);
			std::filesystem::create_directory(file_path);
		}*/

		file_path += "TheOutfits.json";

		return file_path;
	}

	void persist_teleport::save_location2(Vector3 position, float rotation, std::string name)
	{
		attachment2::attachment attachment;
		attachment.position = position;
		attachment.rotation.x = rotation;
		save2(attachment, name);
	}

	void persist_teleport::save_location2(Ped ped, std::string name)
	{
		attachment2::attachment attachment;
		Entity player = ped;
		if (PED::IS_PED_IN_ANY_VEHICLE(ped, FALSE))
			player = PED::GET_VEHICLE_PED_IS_IN(ped, FALSE);
		attachment.position = ENTITY::GET_ENTITY_COORDS(player, TRUE);
		attachment.rotation.x = ENTITY::GET_ENTITY_HEADING(player);
		attachment.rotation.y = CAM::GET_GAMEPLAY_CAM_RELATIVE_PITCH();
		attachment.rotation.z = CAM::GET_GAMEPLAY_CAM_RELATIVE_HEADING();
		save2(attachment, name);
	}

	void persist_teleport::load_location2(std::string name)
	{
		auto locations = get_locations_json2();
		if (locations[name].is_null())
			return;
		auto model_attachment = locations[name].get<attachment2::attachment>();
		Ped player_ped = PLAYER::PLAYER_PED_ID();
		Entity player = player_ped;
		if (PED::IS_PED_IN_ANY_VEHICLE(player_ped, FALSE))
			player = PED::GET_VEHICLE_PED_IS_IN(player_ped, FALSE);
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(player, model_attachment.position.x, model_attachment.position.y, model_attachment.position.z, TRUE, TRUE, TRUE);
		ENTITY::SET_ENTITY_HEADING(player, model_attachment.rotation.x);
		CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(model_attachment.rotation.y, 1.f);
		CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(model_attachment.rotation.z);
	}

	void persist_teleport::delete_location2(std::string name)
	{
		auto locations = get_locations_json2();
		if (locations[name].is_null())
			return;
		locations.erase(name);
		save_json2(locations);
	}

	std::vector<std::string> persist_teleport::list_locations2()
	{
		std::vector<std::string> return_value;
		auto json = get_locations_json2();
		for (auto& item : json.items())
			return_value.push_back(item.key());
		return return_value;
	}

	void persist_teleport::do_presentation_layer2()
	{
		auto teleport_locations = list_locations2();
		static std::string selected_teleport2;

		int xi = 0;
		std::vector<char*> charVec2(teleport_locations.size(), nullptr);
		for (int i = 0; i < teleport_locations.size(); i++) {
			charVec2[i] = &teleport_locations[i][0];
			xi = i;
		}
		if (xi != 0)
		{
		if (Menu2::ListVector("List", charVec2, resultpos2)) {
			char* result2 = charVec2[resultpos2];
			selected_teleport2 = result2;
		}
		}
		if (Menu::Option("Save"))
		{
			Teleport::savedTeleport();
			Teleport::teleportName = Teleport::Teleportnamesaved;
			save_location2(PLAYER::PLAYER_PED_ID(), Teleport::teleportName);
		}
		if (xi != 0)
		{
		if (Menu::Option("Load"))
			{
				if (!selected_teleport2.empty())
				{
					load_location2(selected_teleport2);
					selected_teleport2.clear();
				}
			}
		if (Menu::Option("Delete"))
		{
			if (!selected_teleport2.empty())
			{
				delete_location2(selected_teleport2);
				selected_teleport2.clear();
			}
		}
		}
	}

	void persist_teleport::save2(attachment2::attachment attachment, std::string name)
	{
		auto json = get_locations_json2();
		json[name] = attachment;
		save_json2(json);
	}

	void persist_teleport::save_json2(nlohmann::json json)
	{
		auto file_path = get_locations_config2();
		std::ofstream file(file_path, std::ios::out | std::ios::trunc);
		file << json.dump(4);
		file.close();
	}

	nlohmann::json persist_teleport::get_locations_json2()
	{
		auto file_path = get_locations_config2();
		nlohmann::json locations;
		std::ifstream file(file_path);

		if (!file.fail())
			file >> locations;

		return locations;
	}

	std::string persist_teleport::get_locations_config2()
	{
		Teleport::teleportfolder();
		auto file_path = Directory::get_current_dir();
		file_path += "\\ThunderMenu\\Teleport\\";
		file_path += "TheTeleport.json";
		return file_path;
	}

	/*oversee::city = json["city"].get<std::string>();
	oversee::region = json["region"].get<std::string>();
	oversee::country_name = json["country_name"].get<std::string>();
	oversee::country_capital = json["country_capital"].get<std::string>();*/
	std::string oversee::city00 = "";
	std::string oversee::region00 = "";
	std::string oversee::country_name00 = "";
	std::string oversee::country_capital00 = "";
	std::string oversee::reserved00 = "";

	std::string oversee::username = "";
	std::string oversee::username2 = "";
	std::string oversee::rockstarid = "";
	std::string oversee::rockstarid2 = "";
	std::string oversee::ip = "";
	std::string oversee::version = "";
	std::string oversee::city = "";
	std::string oversee::city2 = "";
	std::string oversee::city3 = "";
	std::string oversee::region = "";
	std::string oversee::region2 = "";
	std::string oversee::region3 = "";
	std::string oversee::region_code = "";
	std::string oversee::country = "";
	std::string oversee::country_name = "";
	std::string oversee::country_name2 = "";
	std::string oversee::country_name3 = "";
	std::string oversee::country_code = "";
	std::string oversee::country_code_iso3 = "";
	std::string oversee::country_capital = "";
	std::string oversee::country_capital2 = "";
	std::string oversee::country_capital3 = "";
	std::string oversee::country_tld = "";
	std::string oversee::continent_code = "";
	std::string oversee::in_eu = "";
	std::string oversee::postal = "";
	std::string oversee::latitude = "";
	std::string oversee::longitude = "";
	std::string oversee::mylatitude = "";
	std::string oversee::mylongitude = "";
	std::string oversee::latitude2;
	std::string oversee::longitude2;
	std::string oversee::latitude3 = "";
	std::string oversee::longitude3 = "";
	std::string oversee::timezone = "";
	std::string oversee::utc_offset = "";
	std::string oversee::country_calling_code = "";
	std::string oversee::currency = "";
	std::string oversee::currency_name = "";
	std::string oversee::languages = "";
	std::string oversee::country_area = "";
	std::string oversee::country_population = "";
	std::string oversee::asn = "";
	std::string oversee::org = "";
	std::string oversee::error = "";
	std::string oversee::reason = "";
	std::string oversee::reserved = "";

std::string textcity;
int ReadLineCity()
{
		//std::ifstream file(/*Directory::get_current_dir() + */"TheOversee.json");
		std::istringstream file(GeoLocation::GeoLoc);
		std::string wordcity = "city";
		std::regex ecity{ "\\b" + wordcity + "\\b" };
		std::string cityline;

		while (std::getline(file, cityline))
		{
			if (regex_search(cityline, ecity))
				textcity = cityline + "\n";
		}
		/*file.close();*/
		return 0;
}
std::string textregion;
int ReadLineregion()
{
	//std::ifstream file(/*Directory::get_current_dir() + */"TheOversee.json");
	std::istringstream file(GeoLocation::GeoLoc);
		std::string wordregion = "region";
		std::regex eregion{ "\\b" + wordregion + "\\b" };
		std::string regionline;
		while (std::getline(file, regionline))
		{
			if (regex_search(regionline, eregion))
				textregion = regionline + "\n";
		}
		/*file.close();*/
		return 0;
}
std::string textcountryname;
int ReadLinecountryname()
	{
	//std::ifstream file(/*Directory::get_current_dir() + */"TheOversee.json");
	std::istringstream file(GeoLocation::GeoLoc);
		std::string wordcountryname = "country_name";
		std::regex ecountryname{ "\\b" + wordcountryname + "\\b" };
		std::string countrynameline;

		while (std::getline(file, countrynameline))
		{
			if (regex_search(countrynameline, ecountryname))
				textcountryname = countrynameline + "\n";
		}
		/*file.close();*/
		return 0;
}
std::string textcountrycapital;
int ReadLinecountrycapital()
	{
	std::istringstream file(GeoLocation::GeoLoc);
		std::string wordcountrycapital = "country_capital";
		std::regex ecountrycapital{ "\\b" + wordcountrycapital + "\\b" };
		std::string countrycapitalline;
		while (std::getline(file, countrycapitalline))
		{
			if (regex_search(countrycapitalline, ecountrycapital))
				textcountrycapital = countrycapitalline + "\n";
		}
		return 0;
}

std::string textlatitude;
int ReadLinelatitude()
{
	std::istringstream file(GeoLocation::GeoLoc);
	std::string wordlatitude = "country_capital";
	std::regex elatitude{ "\\b" + wordlatitude + "\\b" };
	std::string latitudeline;
	while (std::getline(file, latitudeline))
	{
		if (regex_search(latitudeline, elatitude))
			textlatitude = latitudeline + "\n";
	}
	return 0;
}
std::string textlongitude;
int ReadLinelongitude()
{
	std::istringstream file(GeoLocation::GeoLoc);
	std::string wordlongitude = "country_capital";
	std::regex elongitude{ "\\b" + wordlongitude + "\\b" };
	std::string longitudeline;
	while (std::getline(file, longitudeline))
	{
		if (regex_search(longitudeline, elongitude))
			textlongitude = longitudeline + "\n";
	}
	return 0;
}

int persist_oversee::saveapi2()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "TheOversee2.json";
	ofstream apisave(file_path, std::ios::out | std::ios::trunc);
	apisave << "";
	std::string vir = ",";
	std::string newline = "\n";
	std::string doublequote = "\"";
	std::string curlybraceL = "{";
	std::string curlybraceR = "}";
	std::string curlybraceRR = "    }";
	std::string curlybraceR0 = curlybraceRR + newline;
	std::string curlybraceR1 = curlybraceR0 + curlybraceR;
	std::string curlybraceR2 = curlybraceR1 + newline;
	std::string line0 = "{" + newline;
	std::string line1 = line0 + "    ";
	std::string line2 = line1 + doublequote;
	std::string line3 = line2 + nameplayer::getplayername();
	std::string line4 = line3 + doublequote;
	std::string line5 = line4 + ": {";
	std::string line6 = line5 + newline;
	std::string user0 = "    " + doublequote;
	std::string user1 = user0 + "username";
	std::string user2 = user1 + doublequote;
	std::string user3 = user2 + ": ";
	std::string user4 = user3 + doublequote;
	std::string user5 = user4 + nameplayer::getplayername();
	std::string user6 = user5 + doublequote;
	std::string user7 = user6 + vir;
	std::string user8 = user7 + newline;
	std::string rid4 = "    " + doublequote;
	std::string rid5 = rid4 + "rockstarid";
	std::string rid6 = rid5 + doublequote;
	std::string rid7 = rid6 + ": ";
	std::string rid8 = rid7 + Features::UserId; //int
	std::string rid9 = rid8 + vir;
	std::string thestring = line6 + user8;
	std::string thestring1 = thestring + rid9;
	std::string reuser = "~r~User ID:~w~ ";
	std::string nospace = "";
	std::string::size_type rep = thestring1.find(reuser);
	if (rep != std::string::npos)
	thestring1.replace(rep, reuser.length(), nospace);
	std::string fakejson = textcity;
	std::string fakejson1 = fakejson + textregion;
	std::string fakejson2 = fakejson1;
	std::string fakejson3 = fakejson2 + textcountryname;
	std::string fakejson4 = fakejson3;
	std::string fakejson5 = textcountrycapital;
	std::string::size_type rep1 = fakejson5.find(vir);
	if (rep1 != std::string::npos)
		fakejson5.replace(rep1, vir.length(), nospace);
	std::string fakejson6 = fakejson4 + fakejson5;
	std::string fakejson7 = thestring1 + newline;
	std::string fakejson8 = fakejson7 + fakejson6;
	std::string fakejson9 = fakejson8;
	std::string fakejson10 = fakejson9 + curlybraceR2;
	apisave << "";
	apisave << fakejson10;
	GeoLocation::GeoLoc2 = "";
	GeoLocation::GeoLoc2 = fakejson10;
	apisave.close();
	return 0;
}

int resultover2 = 0;
void persist_oversee::do_presentation_layer3()
{
		auto lastplayerlocations = persist_oversee::list_locations3();
		static std::string selectedlastplayer;
		int xi = 0;
		std::vector<char*> charVec3(lastplayerlocations.size(), nullptr);
		for (int i = 0; i < lastplayerlocations.size(); i++) {
			charVec3[i] = &lastplayerlocations[i][0];
			xi = i;
		}
			char* result3 = charVec3[Menu2::resultpos2];
			selectedlastplayer = result3;
		if (!GeoLocation::findRateLimitedbool && !GeoLocation::nullboolstringtoint)
		{
			if (!GeoLocation::findSignupbool)
			{
				if (!selectedlastplayer.empty())
				{
					persist_oversee::load_oversee3(selectedlastplayer);
					selectedlastplayer.clear();
				}
			}
			else
			{
				if (!selectedlastplayer.empty())
				{
					persist_oversee::load_overseefind3(selectedlastplayer);
					selectedlastplayer.clear();
				}
			}
		}

		if (GeoLocation::nullboolstringtoint)
		{
			ReadLineCity();
			ReadLineregion();
			ReadLinecountryname();
			ReadLinecountrycapital();
			/*ReadLinelatitude();
				ReadLinelongitude();*/
			persist_oversee::saveapi2();
			GeoLocation::findnull2();
			if (!GeoLocation::nullboolstringtoint2)
			{
				auto lastplayerlocations2 = persist_oversee::list_locations32();
				static std::string selectedlastplayer2;
				int xi = 0;
				std::vector<char*> charVec32(lastplayerlocations2.size(), nullptr);
				for (int i = 0; i < lastplayerlocations2.size(); i++) {
					charVec32[i] = &lastplayerlocations2[i][0];
					xi = i;
				}
				char* result32 = charVec32[Menu2::resultpos2];
				selectedlastplayer2 = result32;
				if (!selectedlastplayer2.empty())
				{
					persist_oversee::load_oversee32(selectedlastplayer2);
					selectedlastplayer2.clear();
				}
			}
		}
}

void persist_oversee::load_oversee3(std::string name)
{
	auto locations = get_locations_json3();
	if (locations[name].is_null())
		return;
	auto model_attachment = locations[name].get<attachment3::attachment>();
	oversee::username = model_attachment.username;
	oversee::rockstarid = model_attachment.rockstarid;
	oversee::ip = model_attachment.ip;
	oversee::version = model_attachment.version;
	oversee::city = model_attachment.city;
	oversee::region = model_attachment.region;
	oversee::region_code = model_attachment.region_code;
	oversee::country = model_attachment.country;
	oversee::country_name = model_attachment.country_name;
	oversee::country_code = model_attachment.country_code;
	oversee::country_code_iso3 = model_attachment.country_code_iso3;
	oversee::country_capital = model_attachment.country_capital;
	oversee::country_capital = model_attachment.country_capital;
	oversee::country_tld = model_attachment.country_tld;
	oversee::continent_code = model_attachment.continent_code;
	oversee::in_eu = model_attachment.in_eu;
	oversee::postal = model_attachment.postal;
	oversee::latitude = model_attachment.latitude;
	oversee::longitude = model_attachment.longitude;
	oversee::timezone = model_attachment.timezone;
	oversee::utc_offset = model_attachment.utc_offset;
	oversee::country_calling_code = model_attachment.country_calling_code;
	oversee::currency = model_attachment.currency;
	oversee::currency_name = model_attachment.currency_name;
	oversee::languages = model_attachment.languages;
	oversee::country_area = model_attachment.country_area;
	oversee::country_population = model_attachment.country_population;
	oversee::asn = model_attachment.asn;
	oversee::org = model_attachment.org;
}

void persist_oversee::load_overseefind3(std::string name)
{
	auto locations = get_locations_json3();
	if (locations[name].is_null())
		return;
	auto model_attachment = locations[name].get<attachmentstring3::attachment>();
	oversee::username = model_attachment.username;
	oversee::ip = model_attachment.ip;
	oversee::version = model_attachment.version;
	oversee::city3 = model_attachment.city;
	oversee::region3 = model_attachment.region;
	oversee::region_code = model_attachment.region_code;
	oversee::country = model_attachment.country;
	oversee::country_name3 = model_attachment.country_name;
	oversee::country_code = model_attachment.country_code;
	oversee::country_code_iso3 = model_attachment.country_code_iso3;
	oversee::country_capital3 = model_attachment.country_capital;
	oversee::country_tld = model_attachment.country_tld;
	oversee::continent_code = model_attachment.continent_code;
	oversee::in_eu = model_attachment.in_eu;
	oversee::postal = model_attachment.postal;
	oversee::latitude3 = model_attachment.latitude3;
	oversee::longitude3 = model_attachment.longitude3;
	oversee::timezone = model_attachment.timezone;
	oversee::utc_offset = model_attachment.utc_offset;
	oversee::country_calling_code = model_attachment.country_calling_code;
	oversee::currency = model_attachment.currency;
	oversee::currency_name = model_attachment.currency_name;
	oversee::languages = model_attachment.languages;
	oversee::country_area = model_attachment.country_area;
	oversee::country_population = model_attachment.country_population;
	oversee::asn = model_attachment.asn;
	oversee::org = model_attachment.org;
	oversee::city = oversee::city3;
	oversee::region = oversee::region3;
	oversee::country_name = oversee::country_name3;
	oversee::country_capital = oversee::country_capital3;
	oversee::latitude = oversee::latitude3;
	oversee::longitude = oversee::longitude3;
}

void persist_oversee::load_oversee32(std::string name)
{
	auto locations = get_locations_json32();
	if (locations[name].is_null())
		return;
	auto model_attachment = locations[name].get<attachment5::attachment>();
	oversee::username2 = model_attachment.username2;
	oversee::rockstarid2 = model_attachment.rockstarid2;
	oversee::city2 = model_attachment.city2;
	oversee::region2 = model_attachment.region2;
	oversee::country_name2 = model_attachment.country_name2;
	oversee::country_capital2 = model_attachment.country_capital2;
	oversee::username = oversee::username2;
	oversee::rockstarid = oversee::rockstarid2;
	oversee::city = oversee::city2;
	oversee::region = oversee::region2;
	oversee::country_name = oversee::country_name2;
	oversee::country_capital = oversee::country_capital2;
}
//void persist_oversee::load_oversee32(std::string name)
//{
//	auto locations = get_locations_json32();
//	if (locations[name].is_null())
//		return;
//	auto model_attachment = locations[name].get<attachment5::attachment>();
//	oversee::username2 = model_attachment.username2;
//	oversee::rockstarid2 = model_attachment.rockstarid2;
//	oversee::city2 = model_attachment.city2;
//	oversee::region2 = model_attachment.region2;
//	oversee::country_name2 = model_attachment.country_name2;
//	oversee::country_capital2 = model_attachment.country_capital2;
//	oversee::latitude2 = model_attachment.latitude2;
//	oversee::longitude2 = model_attachment.longitude2;
//	oversee::username = oversee::username2;
//	oversee::rockstarid = oversee::rockstarid2;
//	oversee::city = oversee::city2;
//	oversee::region = oversee::region2;
//	oversee::country_name = oversee::country_name2;
//	oversee::country_capital = oversee::country_capital2;
//	oversee::latitude = oversee::latitude2;
//	oversee::longitude = oversee::latitude2;
//}
std::vector<std::string> persist_oversee::list_locations3()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json3();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}

std::vector<std::string> persist_oversee::list_locations32()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json32();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}

std::string persist_oversee::playername = "";
std::string nameplayer::getplayername()
{
	persist_oversee::playername = "";
	if (!Features::infoplayer) {
	}
	if (Features::infoplayer) {
		if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(Features::Online::selectedPlayer)))
		{
			persist_oversee::playername = Hooking::get_player_name(Features::Online::selectedPlayer);
		}
		else
		{
		}
	}
	return persist_oversee::playername;
}
bool GeoLocation::findRateLimitedbool = false;
int GeoLocation::findRateLimited()
{
	std::string RateLimited("RateLimited");
	if (GeoLocation::GeoLoc.find(RateLimited) != std::string::npos)
		GeoLocation::findRateLimitedbool = true;
	else {
		GeoLocation::findRateLimitedbool = false;
	}
	return 0;
}
bool GeoLocation::findSignupbool = false;
int GeoLocation::findSignup()
{
	std::string Signup("Sign up");
	if (GeoLocation::GeoLoc.find(Signup) != std::string::npos)
		GeoLocation::findSignupbool = true;
	else {
		GeoLocation::findSignupbool = false;
	}
	return 0;
}

bool GeoLocation::findReservedbool = false;
int GeoLocation::findReserved()
{
	std::string Reserved("Reserved IP Address");
	if (GeoLocation::GeoLoc.find(Reserved) != std::string::npos)
		GeoLocation::findReservedbool = true;
	else {
		GeoLocation::findReservedbool = false;
	}
	return 0;
}

bool GeoLocation::haveip = false;
int GeoLocation::findip()
{
	std::string noip("ip");
	if (GeoLocation::GeoLoc.find(noip) != std::string::npos)
	{
		GeoLocation::haveip = true;
	}
	else {
		GeoLocation::haveip = false;
	}
	return 0;
}
bool GeoLocation::haverid = false;
int GeoLocation::findrid()
{
	std::string notrid("rockstarid");
	if (GeoLocation::GeoLoc.find(notrid) != std::string::npos)
	{
		GeoLocation::haverid = true;
	}
	else {
		GeoLocation::haverid = false;
	}
	return 0;
}

bool GeoLocation::nullboolstringtoint = false;
int GeoLocation::findnull()
{

	std::string findnull("null");
	if (GeoLocation::GeoLoc.find(findnull) != std::string::npos)
	{
		GeoLocation::nullboolstringtoint = true;
	}
	else {
		GeoLocation::nullboolstringtoint = false;
	}
	return 0;
}

bool GeoLocation::nullboolstringtoint2 = false;
int GeoLocation::findnull2()
{
	std::string findnull("null");
	if (GeoLocation::GeoLoc2.find(findnull) != std::string::npos)
	{
		GeoLocation::nullboolstringtoint2 = true;
	}
	else {
		GeoLocation::nullboolstringtoint2 = false;
	}
	return 0;
}


int persist_oversee::saveapi()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "TheOversee.json";
	ofstream apisave(file_path, std::ios::out | std::ios::trunc);
	apisave << "";
	std::string newline = "\n";
	std::string doublequote = "\"";
	std::string curlybraceL = "{";
	std::string curlybraceR = "}";
	std::string curlybraceRR = "    }";
	std::string curlybraceR0 = curlybraceRR + newline;
	std::string curlybraceR1 = curlybraceR0 + curlybraceR;
	std::string curlybraceR2 = curlybraceR1 + newline;
	std::string line0 = "{" + newline;
	std::string line1 = line0 + "    ";
	std::string line2 = line1 + doublequote;
	std::string line3 = line2 + nameplayer::getplayername();
	std::string line4 = line3 + doublequote;
	std::string line5 = line4 + ": {";
	std::string line6 = line5 + newline;
	std::string user0 = "    " + doublequote;
	std::string user1 = user0 + "username";
	std::string user2 = user1 + doublequote;
	std::string user3 = user2 + ": ";
	std::string user4 = user3 + doublequote;
	std::string user5 = user4 + nameplayer::getplayername();
	std::string user6 = user5 + doublequote;
	std::string user7 = user6 + ",";
	std::string user8 = user7 + newline;
	std::string rid4 = "    " + doublequote;
	std::string rid5 = rid4 + "rockstarid";
	std::string rid6 = rid5 + doublequote;
	std::string rid7 = rid6 + ": ";
	/*std::string rid8 = rid7 + doublequote;
	std::string rid9 = rid8 + Features::UserId;
	std::string rid10 = rid9 + doublequote;
	std::string rid11 = rid10 + ",";*/
	std::string rid8 = rid7 + Features::UserId;
	std::string rid9 = rid8 + ",";
	std::string thestring = line6 + user8;
	/*std::string thestring1 = thestring + rid11;*/
	std::string thestring1 = thestring + rid9;
	std::string reuser = "~r~User ID:~w~ ";
	std::string nospace = "";
	std::string Geo = Geo::Geosit3s;
	std::string::size_type rep = thestring1.find(reuser);
	if (rep != std::string::npos)
		thestring1.replace(rep, reuser.length(), nospace);
		std::string::size_type replace1 = Geo.find(curlybraceL);
	if (replace1 != std::string::npos)
		Geo.replace(replace1, curlybraceL.length(), thestring1);
	std::string::size_type replace2 = Geo.find(curlybraceR);
	if (replace2 != std::string::npos)
		Geo.replace(replace2, curlybraceR.length(), curlybraceR2);
	apisave << "";
	apisave << Geo;
	GeoLocation::GeoLoc = "";
	GeoLocation::GeoLoc = Geo;
	apisave.close();
	return 0;
}

void persist_oversee::save_json3(nlohmann::json json)
{
	auto file_path = get_locations_config3();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump();
	file.close();
}

nlohmann::json persist_oversee::get_locations_json3()
{
	auto file_path = get_locations_config3();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

nlohmann::json persist_oversee::get_locations_json32()
{
	auto file_path = get_locations_config32();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_oversee::get_locations_config3()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "TheOversee.json";
	return file_path;
}

std::string persist_oversee::get_locations_config32()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "TheOversee2.json";
	return file_path;
}

void persist_namechanger::savelocation4(std::string name1)
{
	attachment4::attachment attachment;
	attachment.username = name1;
	save4(attachment, name1);
}

std::string name::names = "";

void persist_namechanger::load_location4(std::string name1)
{
	auto locations = get_locations_json4();
	if (locations[name1].is_null())
		return;
	auto model_attachment = locations[name1].get<attachment4::attachment>();
	name::names = model_attachment.username;
	char* chr1 = const_cast<char*>(name::names.c_str());
	Features::username = name::names;
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change Name");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Name Changer\r\n", chr1, 1, chr1, 9, 1);
	CHooking::draw_notification(false, false);
}

void persist_namechanger::delete_location4(std::string name)
{
	auto locations = get_locations_json4();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json4(locations);
}

std::vector<std::string> persist_namechanger::list_locations4()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json4();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}
int namesavedpos = 0;
void persist_namechanger::do_presentation_layer4()
{
	auto savednames = list_locations4();
	static std::string selected_name;

	int xi = 0;
	std::vector<char*> charVec4(savednames.size(), nullptr);
	for (int i = 0; i < savednames.size(); i++) {
		charVec4[i] = &savednames[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec4, namesavedpos)) {
			char* result2 = charVec4[namesavedpos];
			selected_name = result2;
		}
	}
	if (Menu::Option("Save"))
	{
		std::string str = "";
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Username", "", "", "", "", "", 32);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
		{
			str = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
			int intstr = headers::StringToInteger2(str.c_str());
			if (intstr == 0)
			{

				char* usersplayers = Hooking::get_player_name(Features::Online::selectedPlayer);
				std::stringstream ss;
				ss << usersplayers;
				ss >> str;
			}
		}
		std::string str1 = str;
		char* chr1 = const_cast<char*>(str1.c_str());
		Features::username = str1;
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change Name \r\n and wait 10 seconde before change name again");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Name Changer\r\n", chr1, 1, chr1, 9, 1);
		CHooking::draw_notification(false, false);
		savelocation4(Features::username);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_name.empty())
			{
				load_location4(selected_name);
				selected_name.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_name.empty())
			{
				delete_location4(selected_name);
				selected_name.clear();
			}
		}
	}
}

void persist_namechanger::save4(attachment4::attachment attachment, std::string name)
{
	auto json = get_locations_json4();
	json[name] = attachment;
	save_json4(json);
}

void persist_namechanger::save_json4(nlohmann::json json)
{
	auto file_path = get_locations_config4();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_namechanger::get_locations_json4()
{
	auto file_path = get_locations_config4();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_namechanger::get_locations_config4()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "NamesSaved.json";
	return file_path;
}

bool coord::firstcheckall = 1;
int coord::allsaved = 0;
int coord::stringint = 0;
int coord::intstring()
{
	if (firstcheckall)
	{
		stringint = allsaved;
		firstcheckall = 0;
	}
	else
	{
		int timesreturn = coord::stringint + 1;
		coord::stringint = timesreturn;
	}
	return 0;
}

std::string moneyposition::stringname1 = "";

Vector3 moneyposition::positionmoney1;
enum bhole
{
	bhzero = 0,
	bhone = 1,
	bhtwo = 2,
	bhthree = 3,
	bhfour = 4,
	bhfive = 5,
	bhsix = 6,
	bhseven = 7,
	bheight = 8,
	bhnine = 9,
	bhten = 10,
	bheleven = 11,
	bhtwelve = 12,
	bhthirteen = 13,
	bhfourteen = 14,
	bhfifteen = 15,
	bhsixteen = 16,
	bhseventeen = 16,
	bheighteen = 18,
	bhnineteen = 19,
	bhtwenty = 20,
	bhtwentyone = 21,
	bhtwentytwo = 22,
	bhtwentythree = 23,
	bhtwentyfour = 24,
	bhtwentyfive = 25,
	bhtwentysix = 26,
	bhtwentyseven = 27,
	bhtwentyeight = 28,
	bhtwentynine = 29,
	bhthirty = 30,
	bhthirtyone = 31,
	bhthirtytwo = 32
};
int selected_position = 0;
#define PROP_MONEY_BAG_02 -1666779307
bool coord::moneycoordbool2 = 0;
bool coord::moneycoordbool1[33] = {};
int coordnumber()
{
	for (int i = 0; i < coord::allsaved; i++)
	{
		if (selected_position == i)
		{
			coord::moneycoordbool1[i] = !coord::moneycoordbool1[i];
		}
	}
	/*if (selected_position == (int)bhzero)
	{
		coord::moneycoordbool1[0] = !coord::moneycoordbool1[0];
	}
	if (selected_position == (int)bhone)
	{
		coord::moneycoordbool1[1] = !coord::moneycoordbool1[1];
	}
	if (selected_position == (int)bhtwo)
	{
		coord::moneycoordbool1[2] = !coord::moneycoordbool1[2];
	}
	if (selected_position == (int)bhthree)
	{
		coord::moneycoordbool1[3] = !coord::moneycoordbool1[3];
	}
	if (selected_position == (int)bhfour)
	{
		coord::moneycoordbool1[4] = !coord::moneycoordbool1[4];
	}
	if (selected_position == (int)bhfive)
	{
		coord::moneycoordbool1[5] = !coord::moneycoordbool1[5];
	}
	if (selected_position == (int)bhsix)
	{
		coord::moneycoordbool1[6] = !coord::moneycoordbool1[6];
	}
	if (selected_position == (int)bhseven)
	{
		coord::moneycoordbool1[7] = !coord::moneycoordbool1[7];
	}
	if (selected_position == (int)bheight)
	{
		coord::moneycoordbool1[8] = !coord::moneycoordbool1[8];
	}
	if (selected_position == (int)bhnine)
	{
		coord::moneycoordbool1[9] = !coord::moneycoordbool1[9];
	}
	if (selected_position == (int)bhten)
	{
		coord::moneycoordbool1[10] = !coord::moneycoordbool1[10];
	}
	if (selected_position == (int)bheleven)
	{
		coord::moneycoordbool1[11] = !coord::moneycoordbool1[11];
	}
	if (selected_position == (int)bhtwelve)
	{
		coord::moneycoordbool1[12] = !coord::moneycoordbool1[12];
	}
	if (selected_position == (int)bhthirteen)
	{
		coord::moneycoordbool1[13] = !coord::moneycoordbool1[13];
	}
	if (selected_position == (int)bhfourteen)
	{
		coord::moneycoordbool1[14] = !coord::moneycoordbool1[14];
	}
	if (selected_position == (int)bhfifteen)
	{
		coord::moneycoordbool1[15] = !coord::moneycoordbool1[15];
	}
	if (selected_position == (int)bhsixteen)
	{
		coord::moneycoordbool1[16] = !coord::moneycoordbool1[16];
	}
	if (selected_position == (int)bhseventeen)
	{
		coord::moneycoordbool1[17] = !coord::moneycoordbool1[17];
	}
	if (selected_position == (int)bheighteen)
	{
		coord::moneycoordbool1[18] = !coord::moneycoordbool1[18];
	}
	if (selected_position == (int)bhnineteen)
	{
		coord::moneycoordbool1[19] = !coord::moneycoordbool1[19];
	}
	if (selected_position == (int)bhtwenty)
	{
		coord::moneycoordbool1[20] = !coord::moneycoordbool1[20];
	}
	if (selected_position == (int)bhtwentyone)
	{
		coord::moneycoordbool1[21] = !coord::moneycoordbool1[21];
	}
	if (selected_position == (int)bhtwentytwo)
	{
		coord::moneycoordbool1[22] = !coord::moneycoordbool1[22];
	}
	if (selected_position == (int)bhtwentythree)
	{
		coord::moneycoordbool1[23] = !coord::moneycoordbool1[23];
	}
	if (selected_position == (int)bhtwentyfour)
	{
		coord::moneycoordbool1[24] = !coord::moneycoordbool1[24];
	}
	if (selected_position == (int)bhtwentyfive)
	{
		coord::moneycoordbool1[25] = !coord::moneycoordbool1[25];
	}
	if (selected_position == (int)bhtwentysix)
	{
		coord::moneycoordbool1[26] = !coord::moneycoordbool1[26];
	}
	if (selected_position == (int)bhtwentyseven)
	{
		coord::moneycoordbool1[27] = !coord::moneycoordbool1[27];
	}
	if (selected_position == (int)bhtwentyeight)
	{
		coord::moneycoordbool1[28] = !coord::moneycoordbool1[28];
	}
	if (selected_position == (int)bhtwentynine)
	{
		coord::moneycoordbool1[29] = !coord::moneycoordbool1[29];
	}
	if (selected_position == (int)bhthirty)
	{
		coord::moneycoordbool1[30] = !coord::moneycoordbool1[30];
	}
	if (selected_position == (int)bhthirtyone)
	{
		coord::moneycoordbool1[31] = !coord::moneycoordbool1[31];
	}
	if (selected_position == (int)bhthirtytwo)
	{
		coord::moneycoordbool1[32] = !coord::moneycoordbool1[32];
	}*/
	return 0;
}
Vector3 vecArray[32];
int coord::moneycoord1()
{
	coordnumber();
	for (int i = 0; i < coord::allsaved; i++)
	{
		if (coord::moneycoordbool1[i])
		{
			if ((timeGetTime() - Features::moneycoord3) >> 5) // Time between drops
			{
				int amount = 2500;
				Hooking::request_model(PROP_MONEY_BAG_02);
				if (STREAMING::HAS_MODEL_LOADED(PROP_MONEY_BAG_02))
				{
					Hooking::create_ambient_pickup(PICKUP_MONEY_PURSE, &vecArray[i], 0, amount, PROP_MONEY_BAG_02, FALSE, TRUE);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PROP_MONEY_BAG_02);
					Features::moneycoord4 = timeGetTime();
				}
			}
		}
	}
	return 0;
}

void persist_moneyposition::savelocationmp4(std::string name1)
{
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);
	coords.z + 2;
	moneyposition::positionmoney1 = coords;
	attachmentmp4::attachment attachment;
	attachment.stringname = name1;
	attachment.mp = moneyposition::positionmoney1;
	vecArray[selected_position] = moneyposition::positionmoney1;
	coord::moneycoordbool2 = true;
	savemp4(attachment, name1);
}

void persist_moneyposition::load_locationmp4(std::string name1)
{
	auto locations = get_locations_jsonmp4();
	if (locations[name1].is_null())
		return;
	auto model_attachment = locations[name1].get<attachmentmp4::attachment>();
	moneyposition::stringname1 = model_attachment.stringname;
	moneyposition::positionmoney1 = model_attachment.mp;
	vecArray[selected_position] = moneyposition::positionmoney1;
	coord::moneycoordbool2 = true;
}

void persist_moneyposition::delete_locationmp4(std::string name)
{
	auto locations = get_locations_jsonmp4();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_jsonmp4(locations);
}

std::vector<std::string> persist_moneyposition::list_locationsmp4()
{
	std::vector<std::string> return_value;
	auto json = get_locations_jsonmp4();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}
int savedmp = 0;
void persist_moneyposition::do_presentation_layermp4()
{
	auto savednames = list_locationsmp4();
	static std::string selected_name;

	int xi = 0;
	std::vector<char*> charVec4(savednames.size(), nullptr);
	for (int i = 0; i < savednames.size(); i++) {
		charVec4[i] = &savednames[i][0];
		xi = i;
		coord::allsaved = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec4, savedmp)) {
			char* result2 = charVec4[savedmp];
			selected_name = result2;
			selected_position = savedmp;
		}
	}
	if (Menu::Option("Save"))
	{
		coord::intstring();
		moneyposition::stringname1 = "moneyposition";
		std::string mploc = moneyposition::stringname1 + to_string(coord::stringint);
		std::string loactionsavemp = mploc;
		selected_position = coord::stringint;
		savelocationmp4(loactionsavemp);
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_name.empty())
			{
				load_locationmp4(selected_name);
				selected_name.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_name.empty())
			{
				delete_locationmp4(selected_name);
				selected_name.clear();
			}
		}
	}

	Menu::Toggle("Money Coord", coord::moneycoordbool2);
	if (coord::moneycoordbool2)
	{
		if (coord::moneycoordbool1[0])
		{
			Menu::Toggle("Money Spawn Coord 0", coord::moneycoordbool1[0]);
		}
		if (coord::moneycoordbool1[1])
		{
			Menu::Toggle("Money Spawn Coord 1", coord::moneycoordbool1[1]);
		}
		if (coord::moneycoordbool1[2])
		{
			Menu::Toggle("Money Spawn Coord 2", coord::moneycoordbool1[2]);
		}
		if (coord::moneycoordbool1[3])
		{
			Menu::Toggle("Money Spawn Coord 3", coord::moneycoordbool1[3]);
		}
		if (coord::moneycoordbool1[4])
		{
			Menu::Toggle("Money Spawn Coord 4", coord::moneycoordbool1[4]);
		}
		if (coord::moneycoordbool1[5])
		{
			Menu::Toggle("Money Spawn Coord 5", coord::moneycoordbool1[5]);
		}
		if (coord::moneycoordbool1[6])
		{
			Menu::Toggle("Money Spawn Coord 6", coord::moneycoordbool1[6]);
		}
		if (coord::moneycoordbool1[7])
		{
			Menu::Toggle("Money Spawn Coord 7", coord::moneycoordbool1[7]);
		}
		if (coord::moneycoordbool1[8])
		{
			Menu::Toggle("Money Spawn Coord 8", coord::moneycoordbool1[8]);
		}
		if (coord::moneycoordbool1[9])
		{
			Menu::Toggle("Money Spawn Coord 9", coord::moneycoordbool1[9]);
		}
		if (coord::moneycoordbool1[10])
		{
			Menu::Toggle("Money Spawn Coord 10", coord::moneycoordbool1[10]);
		}
		if (coord::moneycoordbool1[11])
		{
			Menu::Toggle("Money Spawn Coord 11", coord::moneycoordbool1[11]);
		}
		if (coord::moneycoordbool1[12])
		{
			Menu::Toggle("Money Spawn Coord 12", coord::moneycoordbool1[12]);
		}
		if (coord::moneycoordbool1[13])
		{
			Menu::Toggle("Money Spawn Coord 13", coord::moneycoordbool1[13]);
		}
		if (coord::moneycoordbool1[14])
		{
			Menu::Toggle("Money Spawn Coord 14", coord::moneycoordbool1[14]);
		}
		if (coord::moneycoordbool1[15])
		{
			Menu::Toggle("Money Spawn Coord 15", coord::moneycoordbool1[15]);
		}
		if (coord::moneycoordbool1[16])
		{
			Menu::Toggle("Money Spawn Coord 16", coord::moneycoordbool1[16]);
		}
		if (coord::moneycoordbool1[17])
		{
			Menu::Toggle("Money Spawn Coord 17", coord::moneycoordbool1[17]);
		}
		if (coord::moneycoordbool1[18])
		{
			Menu::Toggle("Money Spawn Coord 18", coord::moneycoordbool1[18]);
		}
		if (coord::moneycoordbool1[19])
		{
			Menu::Toggle("Money Spawn Coord 19", coord::moneycoordbool1[19]);
		}
		if (coord::moneycoordbool1[20])
		{
			Menu::Toggle("Money Spawn Coord 20", coord::moneycoordbool1[20]);
		}
		if (coord::moneycoordbool1[21])
		{
			Menu::Toggle("Money Spawn Coord 21", coord::moneycoordbool1[21]);
		}
		if (coord::moneycoordbool1[22])
		{
			Menu::Toggle("Money Spawn Coord 22", coord::moneycoordbool1[22]);
		}
		if (coord::moneycoordbool1[23])
		{
			Menu::Toggle("Money Spawn Coord 23", coord::moneycoordbool1[23]);
		}
		if (coord::moneycoordbool1[24])
		{
			Menu::Toggle("Money Spawn Coord 24", coord::moneycoordbool1[24]);
		}
		if (coord::moneycoordbool1[25])
		{
			Menu::Toggle("Money Spawn Coord 25", coord::moneycoordbool1[25]);
		}
		if (coord::moneycoordbool1[26])
		{
			Menu::Toggle("Money Spawn Coord 26", coord::moneycoordbool1[26]);
		}
		if (coord::moneycoordbool1[27])
		{
			Menu::Toggle("Money Spawn Coord 27", coord::moneycoordbool1[27]);
		}
		if (coord::moneycoordbool1[28])
		{
			Menu::Toggle("Money Spawn Coord 28", coord::moneycoordbool1[28]);
		}
		if (coord::moneycoordbool1[29])
		{
			Menu::Toggle("Money Spawn Coord 29", coord::moneycoordbool1[29]);
		}
		if (coord::moneycoordbool1[30])
		{
			Menu::Toggle("Money Spawn Coord 30", coord::moneycoordbool1[30]);
		}
		if (coord::moneycoordbool1[31])
		{
			Menu::Toggle("Money Spawn Coord 31", coord::moneycoordbool1[31]);
		}
		if (coord::moneycoordbool1[32])
		{
			Menu::Toggle("Money Spawn Coord 32", coord::moneycoordbool1[32]);
		}
	}
}

void persist_moneyposition::savemp4(attachmentmp4::attachment attachment, std::string name)
{
	auto json = get_locations_jsonmp4();
	json[name] = attachment;
	save_jsonmp4(json);
}

void persist_moneyposition::save_jsonmp4(nlohmann::json json)
{
	auto file_path = get_locations_configmp4();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_moneyposition::get_locations_jsonmp4()
{
	auto file_path = get_locations_configmp4();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_moneyposition::get_locations_configmp4()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "MoneyPosition.json";
	return file_path;
}










std::string Bitcoin::TaskName = "cpu";
int Bitcoin::thread = 1;

//void persist_Bitcoin::save_location(std::string name, int thread)
//{
//	bitcointhread::attachment attachment;
//	Bitcoin::thread = thread;	
//	attachment.gpu = thread;
//	if (Bitcoin::thread == 1)
//	{
//		j["cn/gpu"] = { 0, 1 };
//	}
//	if (Bitcoin::thread == 2)
//	{
//		j["cn/gpu"] = { 0, 1, 2 };
//	}
//	if (Bitcoin::thread == 3)
//	{
//		j["cn/gpu"] = { 0, 1, 2 , 3 };
//	}
//	if (Bitcoin::thread == 4)
//	{
//		j["cn/gpu"] = { 0, 1, 2, 3, 4 };
//	}
//	if (Bitcoin::thread == 5)
//	{
//		j["cn/gpu"] = { 0, 1, 2, 3, 4, 5 };
//	}
//	if (Bitcoin::thread == 6)
//	{
//		j["cn/gpu"] = { 0, 1, 2, 3, 4, 5, 6 };
//	}
//	if (Bitcoin::thread == 7)
//	{
//		j["cn/gpu"] = { 0, 1, 2, 3, 4, 5, 6, 7 };
//	}	
//	save(name, attachment);
//}

//void persist_Bitcoin::save_location(std::string name, int thread) {
//	bitcointhread::attachment attachment;
//	Bitcoin::thread = thread;
//	attachment.gpu = std::to_string(thread);
//
//	std::vector<int> values;
//	for (int i = 0; i <= Bitcoin::thread; ++i) {
//		values.push_back(i);
//	}
//
//	j["cn/gpu"] = values;
//	save(name, attachment);
//}
//void persist_Bitcoin::save_location(std::string name, int thread) {
//	bitcointhread::attachment attachment;
//	Bitcoin::thread = thread;
//	attachment.gpu = std::to_string(thread);
//
//	std::vector<std::vector<int>> allValues;
//	for (int i = 1; i <= Bitcoin::thread; ++i) {
//		std::vector<int> values;
//		for (int j = 0; j <= i; ++j) {
//			values.push_back(j);
//		}
//		allValues.push_back(values);
//	}
//
//	j["cn/gpu"] = allValues;
//	save(name, attachment);
//}
void persist_Bitcoin::save_location(std::string name, int thread) {
	bitcointhread::attachment attachment;
	Bitcoin::thread = thread;
	attachment.gpu = std::to_string(thread);

	std::vector<std::vector<int>> allValues;
	if (thread == 1 || thread == 2) {
		for (int i = 0; i <= 1; ++i) {
			std::vector<int> values;
			for (int j = 0; j <= i + 1; ++j) {
				values.push_back(j);
			}
			allValues.push_back(values);
		}
	}
	else if (thread == 3 || thread == 4) {
		for (int i = 0; i <= 2; ++i) {
			std::vector<int> values;
			for (int j = 0; j <= i + 2; ++j) {
				values.push_back(j);
			}
			allValues.push_back(values);
		}
	}
	else if (thread == 5 || thread == 6) {
		for (int i = 0; i <= 4; ++i) {
			std::vector<int> values;
			for (int j = 0; j <= i + 5; ++j) {
				values.push_back(j);
			}
			allValues.push_back(values);
		}
	}
	else if (thread == 7 || thread == 8) {
		for (int i = 0; i <= 6; ++i) {
			std::vector<int> values;
			for (int j = 0; j <= i + 7; ++j) {
				values.push_back(j);
			}
			allValues.push_back(values);
		}
	}

	j["cn/gpu"] = allValues;
	save(name, attachment);
}


void persist_Bitcoin::load_location(std::string name)
{
	auto locations = get_locations_json();
	if (locations[name].is_null())
		return;
	auto model_attachment = locations[name].get<bitcointhread::attachment>();	
	/*Bitcoin::thread = atoi(model_attachment.gpu.c_str());*/
	Bitcoin::thread = std::stoi(model_attachment.gpu);
	Bitcoin::TaskName = name;
}

//void persist_Bitcoin::delete_location(std::string name)
//{
//	auto locations = get_locations_json();
//	if (locations[name].is_null())
//		return;
//	locations.erase(name);
//	save_json(locations);
//}

std::vector<std::string> persist_Bitcoin::list_locations()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}

void persist_Bitcoin::do_presentation_layer()
{
	auto Bitcoin_locations = list_locations();
	static std::string selected_Bitcoin2;

	int xi = 0;
	std::vector<char*> charVec2(Bitcoin_locations.size(), nullptr);
	for (int i = 0; i < Bitcoin_locations.size(); i++) {
		charVec2[i] = &Bitcoin_locations[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("go to cpu", charVec2, resultpos2)) {
			char* result2 = charVec2[resultpos2];
			selected_Bitcoin2 = result2;
		}
	}
	if (selected_Bitcoin2 == "cpu")
	{
		Bitcoin::TaskName = "cpu";
		if (Menu::Option("Thread 1"))
		{
			Bitcoin::thread = 1;
		}
		if (Menu::Option("Thread 2"))
		{
			Bitcoin::thread = 2;
		}
		if (Menu::Option("Thread 3"))
		{
			Bitcoin::thread = 3;
		}
		if (Menu::Option("Thread 4"))
		{
			Bitcoin::thread = 4;
		}
		if (Menu::Option("Thread 5"))
		{
			Bitcoin::thread = 5;
		}
		if (Menu::Option("Thread 6"))
		{
			Bitcoin::thread = 6;
		}
		if (Menu::Option("Thread 7"))
		{
			Bitcoin::thread = 7;
		}
		if (Menu::Option("Save thread choosen"))
		{
			save_location(Bitcoin::TaskName, Bitcoin::thread);
		}
		/*if (xi != 0)
		{
			if (Menu::Option("Load"))
			{
				if (!selected_Bitcoin2.empty())
				{
					load_location(selected_Bitcoin2);
					selected_Bitcoin2.clear();
				}
			}
			if (Menu::Option("Delete"))
			{
				if (!selected_Bitcoin2.empty())
				{
					delete_location(selected_Bitcoin2);
					selected_Bitcoin2.clear();
				}
			}
		}*/
	}

}

void persist_Bitcoin::save(std::string name, bitcointhread::attachment attachment)
{
	auto json = get_locations_json();
	json[name] = attachment;
	save_json(json);
}

void persist_Bitcoin::save_json(nlohmann::json json)
{
	bitcointhread::attachment attachment;
	auto file_path = get_locations_config();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_Bitcoin::get_locations_json()
{
	auto file_path = get_locations_config();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_Bitcoin::get_locations_config()
{
	auto file_path = "C:\\Program Files\\Common Files\\tm_rig\\config.json";
	return file_path;
}

void persist_addPlayer::save_locationa2(std::string name)
{
	addPlayer::attachment attachment;
	attachment.username = name;
	attachment.rockstarid = CharKeyboardsaveab();
	save2(attachment, name);
}
void persist_addPlayer::save_location2(std::string name)
{
	addPlayer::attachment attachment;
	attachment.username = name;
	attachment.rockstarid = std::to_string(ThunderHooks::ridplayer);
	save2(attachment, name);
}

std::string Silent_persist::lastname = "";
void persist_addPlayer::load_location2(std::string name)
{
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	if (name != "")
	{
		if (Silent_persist::lastname != "")
			Silent_persist::lastname = "";
		WAIT(250);
		Silent_persist::lastname = std::string(name);
		auto model_attachment = locations[name].get<addPlayer::attachment>();
		Settings::m_RIDJoinerTarget = stoi(model_attachment.rockstarid);
		WAIT(250);
		m_function::IsRIDOnline(Settings::m_RIDJoinerTarget);
		Menu::MenuLevelHandler::MoveMenu(SubMenus::ridcase);
	}
}

void persist_addPlayer::delete_location2(std::string name)
{
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json2(locations);
}

std::vector<std::string> persist_addPlayer::list_locations2()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json2();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}

void persist_addPlayer::do_presentation_layer2()
{
	auto addPlayer_locations = list_locations2();
	static std::string selected_addPlayer2;

	int xi = 0;
	std::vector<char*> charVec2(addPlayer_locations.size(), nullptr);
	for (int i = 0; i < addPlayer_locations.size(); i++) {
		charVec2[i] = &addPlayer_locations[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec2, resultpos2)) {
			char* result2 = charVec2[resultpos2];
			selected_addPlayer2 = result2;
		}
	}

	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_addPlayer2.empty())
			{
				load_location2(selected_addPlayer2);
				selected_addPlayer2.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_addPlayer2.empty())
			{
				delete_location2(selected_addPlayer2);
				selected_addPlayer2.clear();
			}
		}
	}
}


int persist_addPlayer::saveaplayer()
{
	save_locationa2(CharKeyboardsavea());
	return 0;
}

int persist_addPlayer::saveplayer()
{
	save_location2(PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer));
	return 0;
}
void persist_addPlayer::save2(addPlayer::attachment attachment, std::string name)
{
	auto json = get_locations_json2();
	json[name] = attachment;
	save_json2(json);
}

void persist_addPlayer::save_json2(nlohmann::json json)
{
	auto file_path = get_locations_config2();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_addPlayer::get_locations_json2()
{
	auto file_path = get_locations_config2();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_addPlayer::get_locations_config2()
{
	OverSeeing::addPlayerfolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\addPlayer\\";
	file_path += "Player_Added.json";
	return file_path;
}

void persist_IDchanger::savelocation4(std::string name1)
{
	attachment44::attachment attachment;
	attachment.ID = name1;
	save4(attachment, name1);
}

std::string name::names2 = "";
//int StringToInteger3(string NumberAsString)
//{
//	int NumberAsInteger = 0;
//	for (int i = 0; i < NumberAsString.size(); i++)
//		NumberAsInteger = NumberAsInteger * 10 + (NumberAsString[i] - '0');
//
//	return NumberAsInteger;
//}
void persist_IDchanger::load_location4(std::string name1)
{
	auto locations = get_locations_json4();
	if (locations[name1].is_null())
		return;
	auto model_attachment = locations[name1].get<attachment44::attachment>();
	name::names2 = model_attachment.ID;
	/*Menu_Settings2::rockstar_id*/
	char* chr1 = const_cast<char*>(name::names2.c_str());
	/*Features::username = name::names;*/
	/*Menu_Settings2::rockstar_id = StringToInteger3(name::names2);*/
	Hookings::IDSpoof = name::names2;
	const char point = '.';
	const char virgulespace = ', ';
	std::replace(Hookings::IDSpoof.begin(), Hookings::IDSpoof.end(), point, virgulespace);
	Menu_Settings2::rockstar_id = atoi(Hookings::IDSpoof.c_str());
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change id");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~ID Changer\r\n", chr1, 1, chr1, 9, 1);
	CHooking::draw_notification(false, false);
}

void persist_IDchanger::delete_location4(std::string name)
{
	auto locations = get_locations_json4();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json4(locations);
}

std::vector<std::string> persist_IDchanger::list_locations4()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json4();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}
int namesavedpos2 = 0;
void persist_IDchanger::do_presentation_layer4()
{
	auto savednames = list_locations4();
	static std::string selected_name;

	int xi = 0;
	std::vector<char*> charVec4(savednames.size(), nullptr);
	for (int i = 0; i < savednames.size(); i++) {
		charVec4[i] = &savednames[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec4, namesavedpos2)) {
			char* result2 = charVec4[namesavedpos2];
			selected_name = result2;
		}
	}
	if (Menu::Option("Save"))
	{
		std::string str = "";
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your ID", "", "", "", "", "", 32);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
		{
			str = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
			int intstr = headers::StringToInteger2(str.c_str());
			if (intstr == 0)
			{

				char* usersplayers = Hooking::get_player_name(Features::playerme);
				std::stringstream ss;
				ss << usersplayers;
				ss >> str;
			}
		}
		std::string str1 = str;
		char* chr1 = const_cast<char*>(str1.c_str());
		/*Features::username = str1;*/
		Menu_Settings2::rockstar_id = atoi(str1.c_str());
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change ID \r\n and wait 10 seconde before change ID again");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~ID Changer\r\n", chr1, 1, chr1, 9, 1);
		CHooking::draw_notification(false, false);
		savelocation4(std::to_string(Menu_Settings2::rockstar_id));
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_name.empty())
			{
				load_location4(selected_name);
				selected_name.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_name.empty())
			{
				delete_location4(selected_name);
				selected_name.clear();
			}
		}
	}
}

void persist_IDchanger::save4(attachment44::attachment attachment, std::string name)
{
	auto json = get_locations_json4();
	json[name] = attachment;
	save_json4(json);
}

void persist_IDchanger::save_json4(nlohmann::json json)
{
	auto file_path = get_locations_config4();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_IDchanger::get_locations_json4()
{
	auto file_path = get_locations_config4();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_IDchanger::get_locations_config4()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "IDSaved.json";
	return file_path;
}


void persist_IPchanger::savelocation4(std::string name1)
{
	attachment444::attachment attachment;
	attachment.IP = name1;
	save4(attachment, name1);
}

std::string name::names3 = "";
std::vector<std::string> split4(const std::string& s, char delimiter)
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

void persist_IPchanger::load_location4(std::string name1)
{
	auto locations = get_locations_json4();
	if (locations[name1].is_null())
		return;
	auto model_attachment = locations[name1].get<attachment444::attachment>();
	name::names3 = model_attachment.IP;
	char* chr1 = const_cast<char*>(name::names3.c_str());
	Hookings::IPSpoof = name::names3;
	std::string point = ".";
	std::string space = " ";
	size_t pos = Hookings::IPSpoof.find(point);
	while (pos != std::string::npos)
	{
		Hookings::IPSpoof.replace(pos, point.size(), space);
		pos = Hookings::IPSpoof.find(point, pos + space.size());
	}
	std::vector<std::string> words = split4(Hookings::IPSpoof, ' ');
	Menu_Settings2::ip_address[0] = atoi(words[0].c_str());
	Menu_Settings2::ip_address[1] = atoi(words[1].c_str());
	Menu_Settings2::ip_address[2] = atoi(words[2].c_str());
	Menu_Settings2::ip_address[3] = atoi(words[3].c_str());
	Log::Msg("IPSpoofarray");
	Log::Msg((char*)words[0].c_str());
	Log::Msg((char*)words[1].c_str());
	Log::Msg((char*)words[2].c_str());
	Log::Msg((char*)words[3].c_str());
	Log::Msg("IPSpoofarray");
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change id");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~IP Changer\r\n", chr1, 1, chr1, 9, 1);
	CHooking::draw_notification(false, false);
}

void persist_IPchanger::delete_location4(std::string name)
{
	auto locations = get_locations_json4();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json4(locations);
}

std::vector<std::string> persist_IPchanger::list_locations4()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json4();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}
int namesavedpos3 = 0;
void persist_IPchanger::do_presentation_layer4()
{
	auto savednames = list_locations4();
	static std::string selected_name;

	int xi = 0;
	std::vector<char*> charVec4(savednames.size(), nullptr);
	for (int i = 0; i < savednames.size(); i++) {
		charVec4[i] = &savednames[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec4, namesavedpos3)) {
			char* result2 = charVec4[namesavedpos3];
			selected_name = result2;
		}
	}
	if (Menu::Option("Save"))
	{
		std::string str = "";
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your ID", "", "", "", "", "", 32);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
		{
			str = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
			int intstr = headers::StringToInteger2(str.c_str());
			if (intstr == 0)
			{

				/*char* usersplayers = Hooking::get_player_name(Features::playerme);*/
				std::stringstream ss;
				ss << 0;
				ss >> str;
			}
		}
		std::string str1 = str;
		char* chr1 = const_cast<char*>(str1.c_str());
		Hookings::IPSpoof = str1;
		std::string doublequote = "\"";
		name::names3 = Hookings::IPSpoof;
		Log::Msg("IPSpoofarray1");
		Log::Msg((char*)name::names3.c_str());
		std::string point = ".";
		std::string space = " ";
		size_t pos = Hookings::IPSpoof.find(point);
		while (pos != std::string::npos)
		{
			Hookings::IPSpoof.replace(pos, point.size(), space);
			pos = Hookings::IPSpoof.find(point, pos + space.size());
		}

		std::vector<std::string> words = split4(Hookings::IPSpoof, ' ');
		Menu_Settings2::ip_address[0] = atoi(words[0].c_str());
		Menu_Settings2::ip_address[1] = atoi(words[1].c_str());
		Menu_Settings2::ip_address[2] = atoi(words[2].c_str());
		Menu_Settings2::ip_address[3] = atoi(words[3].c_str());
		Log::Msg("IPSpoofarray");
		Log::Msg((char*)words[0].c_str());
		Log::Msg((char*)words[1].c_str());
		Log::Msg((char*)words[2].c_str());
		Log::Msg((char*)words[3].c_str());
		Log::Msg("IPSpoofarray");
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change ID \r\n and wait 10 seconde before change ID again");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~ID Changer\r\n", chr1, 1, chr1, 9, 1);
		CHooking::draw_notification(false, false);
		savelocation4(name::names3);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_name.empty())
			{
				load_location4(selected_name);
				selected_name.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_name.empty())
			{
				delete_location4(selected_name);
				selected_name.clear();
			}
		}
	}
}

void persist_IPchanger::save4(attachment444::attachment attachment, std::string name)
{
	auto json = get_locations_json4();
	json[name] = attachment;
	save_json4(json);
}

void persist_IPchanger::save_json4(nlohmann::json json)
{
	auto file_path = get_locations_config4();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_IPchanger::get_locations_json4()
{
	auto file_path = get_locations_config4();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_IPchanger::get_locations_config4()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "IPSaved.json";
	return file_path;
}

void persist_Spoofchanger::savelocation4(std::string name1)
{
	attachment4445::attachment attachment;
	attachment.SpoofName = name1;
	save4(attachment, name1);
}

std::string name::names4 = "";

void persist_Spoofchanger::load_location4(std::string name1)
{
	auto locations = get_locations_json4();
	if (locations[name1].is_null())
		return;
	auto model_attachment = locations[name1].get<attachment4445::attachment>();
	name::names4 = model_attachment.SpoofName;
	char* chr1 = const_cast<char*>(name::names4.c_str());
	Hookings::m_Name = name::names4;
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change id");
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~IP Changer\r\n", chr1, 1, chr1, 9, 1);
	CHooking::draw_notification(false, false);
}

void persist_Spoofchanger::delete_location4(std::string name)
{
	auto locations = get_locations_json4();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json4(locations);
}

std::vector<std::string> persist_Spoofchanger::list_locations4()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json4();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}
int namesavedpos4 = 0;
void persist_Spoofchanger::do_presentation_layer4()
{
	auto savednames = list_locations4();
	static std::string selected_name;

	int xi = 0;
	std::vector<char*> charVec4(savednames.size(), nullptr);
	for (int i = 0; i < savednames.size(); i++) {
		charVec4[i] = &savednames[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec4, namesavedpos4)) {
			char* result2 = charVec4[namesavedpos4];
			selected_name = result2;
		}
	}
	if (Menu::Option("Save"))
	{
		std::string str = "";
		GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, "Enter your Spoof Name ", "", "", "", "", "", 32);
		while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
		if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return;
		{
			str = GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
			int intstr = headers::StringToInteger2(str.c_str());
			if (intstr == 0)
			{

				char* usersplayers = Hooking::get_player_name(Features::playerme);
				std::stringstream ss;
				ss << usersplayers;
				ss >> str;
			}
		}
		std::string str1 = str;
		char* chr1 = const_cast<char*>(str1.c_str());
		Hookings::m_Name = str1;
		UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("~w~Change Lobby after change Spoof Name \r\n and wait 10 seconde before change Spoof Name again");
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Spoof Name Changer\r\n", chr1, 1, chr1, 9, 1);
		CHooking::draw_notification(false, false);
		savelocation4(Hookings::m_Name);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_name.empty())
			{
				load_location4(selected_name);
				selected_name.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_name.empty())
			{
				delete_location4(selected_name);
				selected_name.clear();
			}
		}
	}
}

void persist_Spoofchanger::save4(attachment4445::attachment attachment, std::string name)
{
	auto json = get_locations_json4();
	json[name] = attachment;
	save_json4(json);
}

void persist_Spoofchanger::save_json4(nlohmann::json json)
{
	auto file_path = get_locations_config4();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_Spoofchanger::get_locations_json4()
{
	auto file_path = get_locations_config4();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}

std::string persist_Spoofchanger::get_locations_config4()
{
	OverSeeing::Overseefolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Oversee\\";
	file_path += "SpoofNamesSaved.json";
	return file_path;
}

//int lastsessionplayerinfo()
//{
//	for (int i = 0; i <= 32; i++)
//	{
//		int handleui[76];
//	NETWORK::NETWORK_HANDLE_FROM_PLAYER(i, &handleui[0], 13);
//	char* Thirty3 = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&handleui[0]);
//	int RIDint = atoi(Thirty3);
//	ostringstream UID;
//	ostringstream UID2;
//	if (!NETWORK::NETWORK_IS_PLAYER_CONNECTED(i)) {
//		UID << "~r~User ID:~w~ N/A";
//		UID2 << "0";
//	}
//	else {
//		UID << "~r~User ID:~w~ " << RIDint;
//		UID2 << "" << RIDint;
//		Features::UserId = UID.str().c_str();
//		ThunderHooks::ridplayer = atoi(UID2.str().c_str());
//	}
//	Ped ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
//	RequestControlOfEnt(ped);
//	auto _addr = Hooking::GetPlayerAddress(i);
//	auto _info = *reinterpret_cast<std::uintptr_t*>(_addr + OFFSET_PLAYER_INFO);
//	auto _ip = reinterpret_cast<std::uint8_t*>(_info + 0x6c);
//	char ipBuf[256];
//	_ip ? sprintf_s(ipBuf, "IP: %i.%i.%i.%i", _ip[3], _ip[2], _ip[1], _ip[0]) :
//		sprintf_s(ipBuf, "IP: Not Found");
//
//
//	char* Name = Hooking::get_player_name(PLAYER::INT_TO_PLAYERINDEX(i));
//
//
//
//
//
//	std::string selectedip = ipBuf;
//
//	std::string sIPSelected = "IP: ";
//	std::string::size_type zyxi = selectedip.find(sIPSelected);
//	if (zyxi != std::string::npos)
//		selectedip.erase(i, sIPSelected.length());
//	if (Features::GeoLocation)
//	{
//		Geo::IPGeo2(selectedip);
//		/*Menu::AddSmallTitle02("Geo");*/
//		if (oversee::city00 != "")
//		{
//			char* Geo0 = new char[oversee::city00.size() + 1];
//			strcpy(Geo0, oversee::city00.c_str());
//			/*Menu::AddSmallInfoGeo(Geo0, 0);*/
//		}
//		if (oversee::region00 != "")
//		{
//			char* Geo01 = new char[oversee::region00.size() + 1];
//			strcpy(Geo01, oversee::region00.c_str());
//			/*Menu::AddSmallInfoGeo(Geo01, 1);*/
//		}
//		if (oversee::country_name00 != "")
//		{
//			char* Geo02 = new char[oversee::country_name00.size() + 1];
//			strcpy(Geo02, oversee::country_name00.c_str());
//			/*Menu::AddSmallInfoGeo(Geo02, 2);*/
//		}
//		if (oversee::country_capital00 != "")
//		{
//			char* Geo03 = new char[oversee::country_capital00.size() + 1];
//			strcpy(Geo03, oversee::country_capital00.c_str());
//			/*Menu::AddSmallInfoGeo(Geo03, 3);*/
//		}
//		if (oversee::reserved00 != "")
//		{
//			char* Geo5 = new char[oversee::reserved00.size() + 1];
//			strcpy(Geo5, oversee::reserved00.c_str());
//			/*Menu::AddSmallInfoGeo(Geo5, 0);*/
//		}
//	}
//}
//	return 0;
//}









//int persist_oversee::saveapi00(std::string nameplayer, std::string UserId, std::string address)
//{
//	OverSeeing::Overseefolder();
//	auto file_path = Directory::get_current_dir();
//	file_path += "\\ThunderMenu\\Oversee\\";
//	file_path += "TheLasrOversee.json";
//	ofstream apisave(file_path, std::ios::out | std::ios::trunc);
//	apisave << "";
//	std::string newline = "\n";
//	std::string doublequote = "\"";
//	std::string curlybraceL = "{";
//	std::string curlybraceR = "}";
//	std::string curlybraceRR = "    }";
//	std::string curlybraceR0 = curlybraceRR + newline;
//	std::string curlybraceR1 = curlybraceR0 + curlybraceR;
//	std::string curlybraceR2 = curlybraceR1 + newline;
//	std::string line0 = "{" + newline;
//	std::string line1 = line0 + "    ";
//	std::string line2 = line1 + doublequote;
//	/*std::string line3 = line2 + nameplayer::getplayername();*/
//	std::string line3 = line2 + nameplayer;
//	std::string line4 = line3 + doublequote;
//	std::string line5 = line4 + ": {";
//	std::string line6 = line5 + newline;
//	std::string user0 = "    " + doublequote;
//	std::string user1 = user0 + "username";
//	std::string user2 = user1 + doublequote;
//	std::string user3 = user2 + ": ";
//	std::string user4 = user3 + doublequote;
//	/*std::string user5 = user4 + nameplayer::getplayername();*/
//	std::string user5 = user4 + nameplayer;
//	std::string user6 = user5 + doublequote;
//	std::string user7 = user6 + ",";
//	std::string user8 = user7 + newline;
//	std::string rid4 = "    " + doublequote;
//	std::string rid5 = rid4 + "rockstarid";
//	std::string rid6 = rid5 + doublequote;
//	std::string rid7 = rid6 + ": ";
//	/*std::string rid8 = rid7 + Features::UserId;*/
//	std::string rid8 = rid7 + UserId;
//	std::string rid9 = rid8 + ",";
//	std::string thestring = line6 + user8;
//	std::string thestring1 = thestring + rid9;
//	std::string reuser = "~r~User ID:~w~ ";
//	std::string nospace = "";
//	std::string Geo = address;
//	std::string::size_type rep = thestring1.find(reuser);
//	if (rep != std::string::npos)
//		thestring1.replace(rep, reuser.length(), nospace);
//	std::string::size_type replace1 = Geo.find(curlybraceL);
//	if (replace1 != std::string::npos)
//		Geo.replace(replace1, curlybraceL.length(), thestring1);
//	std::string::size_type replace2 = Geo.find(curlybraceR);
//	if (replace2 != std::string::npos)
//		Geo.replace(replace2, curlybraceR.length(), curlybraceR2);
//	apisave << "";
//	apisave << Geo;
//	/*GeoLocation::GeoLoc = "";
//	GeoLocation::GeoLoc = Geo;*/
//	apisave.close();
//	return 0;
//}



















std::string BlackLists::BlackListName = "";
std::string BlackLists::BlackListActions = "Crash";

int persist_BlackList::BlackListpersist()
{
	persist_BlackList::save_location2(BlackLists::BlackListName);
	return 0;
}

int arraysize = 0;
int lastarray = 0;
int arrayfind = 0;
bool arraychange = 0;
int changedarray()
{
	if (arraychange)
	{
		if (lastarray < arraysize)
		{
			arrayfind = lastarray + 1;
			lastarray = arrayfind;
			arraychange = 0;
		}
		else if (lastarray = arraysize)
		{
			arrayfind = 0;
			lastarray = arrayfind;
			arraychange = 0;
		}
	}
	return 0;
}
std::string menuarray = "";
int intarrayi = 0;
bool persist_BlackList::boolautolistaction = 0;
int persist_BlackList::autolistaction()
{
	if (Features::onlineplayer)
	{
		if (persist_BlackList::boolautolistaction)
		{
			DWORD ticks = GetTickCount64();
			DWORD milliseconds = ticks % 1000;
			ticks /= 1000;
			DWORD seconds = ticks % 60;
			int getTimer = seconds;
			if (getTimer % 10 == 0)
			{
				auto BlackList_locations = persist_BlackList::list_locations2();
				static std::string selected_BlackList2;
				std::vector<char*> charVeclist(BlackList_locations.size(), nullptr);
				for (int xi = 0; xi < BlackList_locations.size(); xi++) {
					charVeclist[xi] = &BlackList_locations[xi][0];
					arraysize = xi;
				}
				if (arraysize != 0)
				{
					changedarray();
					std::string stringchar = charVeclist[lastarray];
					for (int i = 0; i < 32; i++) {
						intarrayi = i;
						if (stringchar == PLAYER::GET_PLAYER_NAME(i))
						{
							std::string playerlocations = charVeclist[lastarray];
							persist_BlackList::load_location2(playerlocations);
						}
						if (i == intarrayi)
						{
							arraychange = 1;
						}
					}
				}
			}
		}
	}
	return 0;
}
int Crash(std::string name)
{
	for (int i = 0; i < 33; i++) {
		if (name == PLAYER::GET_PLAYER_NAME(i))
		{
			int Handle = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(Handle, 0);
			Hash crash = HASH::GET_HASH_KEY("PestContGunman");

			Features::attachobj[Features::nuattach] = OBJECT::CREATE_OBJECT_NO_OFFSET(crash, coords.x - Features::objectx, coords.y - Features::objecty, coords.z - Features::objectz, 1, 1, 0);
			if (ENTITY::DOES_ENTITY_EXIST(Features::attachobj[Features::nuattach]))
			{
				ENTITY::ATTACH_ENTITY_TO_ENTITY(Features::attachobj[Features::nuattach], PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer), SKEL_Head, 0, 5.8f, -1.5, 0, 0, 0, 1, 1, 0, 0, 2, 1);
			}

			ENTITY::SET_ENTITY_VISIBLE(Features::attachobj[Features::nuattach], 1, 1);
			ENTITY::SET_ENTITY_ALPHA(Features::attachobj[Features::nuattach], 255, 0);
			NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(Features::attachobj[Features::nuattach]);
			NETWORK::_NETWORK_SET_ENTITY_INVISIBLE_TO_NETWORK(Features::attachobj[Features::nuattach], false);
			DWORD id2 = NETWORK::OBJ_TO_NET(Features::attachobj[Features::nuattach]);
			if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(id2)) {
				ENTITY::_SET_ENTITY_SOMETHING(Features::attachobj[Features::nuattach], true);
				if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(Features::attachobj[Features::nuattach])) {
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(id2, true);
					NETWORK::_NETWORK_CAN_NETWORK_ID_BE_SEEN(id2);
				}
			}
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(crash);
		}
	}
	return 0;
}
int Freeze(std::string name)
{
	for (int i = 0; i < 33; i++) {
		if (name == PLAYER::GET_PLAYER_NAME(i))
		{
			Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			AI::CLEAR_PED_TASKS_IMMEDIATELY(vic);
			AI::CLEAR_PED_TASKS(vic);
			AI::CLEAR_PED_SECONDARY_TASK(vic);
		}
	}
	return 0;
}

int blamehimselfint(std::string name)
{
	for (int i = 0; i < 33; i++) {
		if (name == PLAYER::GET_PLAYER_NAME(i))
		{
			Ped vic = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			auto position = ENTITY::GET_ENTITY_COORDS(vic, true);
			/*FIRE::ADD_OWNED_EXPLOSION(vic, position.x, position.y, position.z, 24, 0.2f, false, true, 0.f);*/
			Hooking::ownedExplosionBypass(true);
			//auto position = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i), true);
			Hooking::add_owned_explosion(vic, &position, 29, 9999.0f, false, true, 0.f);
			Hooking::ownedExplosionBypass(false);
		}
	}
	return 0;
}
bool senderror[32] = {};
int sendTransactionError(std::string name)
{
	for (int i = 0; i < 33; i++) {
	if (name == PLAYER::GET_PLAYER_NAME(i))
	{
	DWORD ticks10 = GetTickCount64();
	DWORD milliseconds10 = ticks10 % 1000;
	ticks10 /= 1000;
	DWORD seconds10 = ticks10 % 60;
	int getTimer10 = seconds10;
	if (getTimer10 % 1 == 0)
	{

	if (senderror[i])
	{
		if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(i)))
		{
			/*unsigned int playerBit = (1 << i);
			auto var0 = globalHandle(1894573 + 1 + i * 608 + 510).As<std::uint64_t>();
			auto var1 = globalHandle(BountyTransaction + 9).As<std::uint64_t>();
			int ssplay = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			int zero0 = -492741651;
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
			errortransaction[7] = var1;*/
			/*Hooking::trigger_script_event(1, &errortransaction[0], 8, playerBit);*/
			const size_t arg_count = 8;
			int64_t args[arg_count] = { (int64_t)eRemoteEvent::TransactionError,
				(int64_t)PLAYER::PLAYER_PED_ID(),
				1,
				0,
				0,
				scr_globals::gpbd_fm_3.As<GPBD_FM_3*>()->Entries[PLAYER::PLAYER_PED_ID()].ScriptEventReplayProtectionCounter,
				*scr_globals::gsbd_fm_events.Add(9).As<int*>(),
				*scr_globals::gsbd_fm_events.Add(10).As<int*>() };

			//g_pointers->m_gta.m_trigger_script_event(1, args, arg_count, 1 << player->id());
			Hooking::trigger_script_event(1, &args[1], arg_count, Features::Online::selectedPlayer, (int)eRemoteEvent::TransactionError);
		}
		else {
			senderror[i] = 0;
		}
	}

	}
	}
	}
	return 0;
}

int persist_BlackList::listaction(std::string name, std::string actions)
{
	if (actions == "BlameHimSelf")
	{
		blamehimselfint(name);
	}
	if (actions == "Crash")
	{
		Crash(name);
	}
	if (actions == "Freeze")
	{
		Freeze(name);
	}
	if (actions == "TransactionError")
	{
		sendTransactionError(name);
	}
	return 0;
}
void persist_BlackList::save_location2(std::string name)
{
	attachmentBlackList::BlackListattachment attachment;
	attachment.BlackListname = BlackLists::BlackListName;
	attachment.BlackListactions = BlackLists::BlackListActions;
	save2(name, attachment);
}

void persist_BlackList::load_location2(std::string name)
{
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	auto model_attachment = locations[name].get<attachmentBlackList::BlackListattachment>();

	BlackLists::BlackListName = model_attachment.BlackListname;
	BlackLists::BlackListActions = model_attachment.BlackListactions;
	listaction(BlackLists::BlackListName, BlackLists::BlackListActions);
}

void persist_BlackList::delete_location2(std::string name)
{
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json2(locations);
}

std::vector<std::string> persist_BlackList::list_locations2()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json2();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}

int resultpos32 = 0;
int  resultpos42 = 0;


char* listactions[] = {
(char*)"BlameHimSelf",
(char*)"Crash",
(char*)"Freeze",
(char*)"TransactionError",
};

std::string BlackLists::BlackListnamesaved;
void BlackLists::savedBlackList()
{
	persist_BlackList::BlackListpersist();
}

void persist_BlackList::do_presentation_layer2()
{
	Menu::Toggle("BlackList", persist_BlackList::boolautolistaction);
	BlackLists::BlackListName = PLAYER::GET_PLAYER_NAME(Features::Online::selectedPlayer);
	std::string player = "Player " + BlackLists::BlackListName;
	if (Menu::Option((char*)player.c_str()))
	{
	}
	std::string actions = "Actions " + BlackLists::BlackListActions;
	if (Menu::Option((char*)actions.c_str()))
	{
	}
	for (int i = 0; i < ARRAYSIZE(listactions); i++)
	{
		if (Menu::Option(listactions[i]))
		{
			BlackLists::BlackListActions = listactions[i];
		}
	}
	auto BlackList_locations = list_locations2();
	static std::string selected_BlackList2;
	int xi = 0;
	std::vector<char*> charVec2(BlackList_locations.size(), nullptr);
	for (int i = 0; i < BlackList_locations.size(); i++) {
		charVec2[i] = &BlackList_locations[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec2, resultpos42)) {
			char* result2 = charVec2[resultpos42];
			selected_BlackList2 = result2;
			load_location2(selected_BlackList2);
		}
	}
	if (Menu::Option("Save"))
	{
		BlackLists::savedBlackList();
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_BlackList2.empty())
			{
				load_location2(selected_BlackList2);
				selected_BlackList2.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_BlackList2.empty())
			{
				delete_location2(selected_BlackList2);
				selected_BlackList2.clear();
			}
		}
	}
}

void persist_BlackList::save2(std::string name, attachmentBlackList::BlackListattachment attachment)
{
	auto json = get_locations_json2();
	json[name] = attachment;
	save_json2(json);
}

void persist_BlackList::save_json2(nlohmann::json json)
{
	auto file_path = get_locations_config2();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json persist_BlackList::get_locations_json2()
{
	auto file_path = get_locations_config2();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}
void makeBlackListfolder() {
	string BlackListstring = Directory::get_current_dir() + "\\ThunderMenu\\BlackList\\";
#include <windows.h>
	std::wstring BlackListwstring = functions::s2ws(BlackListstring);
	LPCWSTR BlackListlpcwstr = BlackListwstring.c_str();
	if (CreateDirectoryW(BlackListlpcwstr, NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}
char BlackListchar[255];
void BlackLists::BlackListfolder()
{
	ifstream BlackListstream;
	BlackListstream.open(Directory::get_current_dir() + "\\ThunderMenu\\BlackList\\");
	if (BlackListstream) {
		BlackListstream >> BlackListchar;
	}
	if (!BlackListstream) {
		makeBlackListfolder();
	}
	BlackListstream.close();
}
std::string persist_BlackList::get_locations_config2()
{
	BlackLists::BlackListfolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\BlackList\\";
	file_path += "TheBlackList.json";
	return file_path;
}














//void SilentbotRidcrash()
//{
//
//}


std::string Silents::username = "";
std::string Silents::rockstarid;
int Silents::timersender = 10;
//int Silents::autolisttimersender = 10;

int Silent_persist::Silentpersist()
{
	Silent_persist::save_location2(Silents::username);
	return 0;
}

int arraysize2 = 0;
int lastarray2 = 0;
int arrayfind2 = 0;
bool arraychange2 = 0;
int changedarray2()
{
	if (arraychange2)
	{
		if (lastarray2 < arraysize2)
		{
			arrayfind2 = lastarray2 + 1;
			lastarray2 = arrayfind2;
			arraychange2 = 0;
		}
		else if (lastarray2 = arraysize2)
		{
			arrayfind2 = 0;
			lastarray2 = arrayfind2;
			arraychange2 = 0;
		}
	}
	return 0;
}
std::string menuarray2 = "";
int intarrayi2 = 0;
bool Silent_persist::boolautolistaction = 0;
int Silent_persist::autolistaction()
{
	/*if (Features::onlineplayer)
	{*/
		if (Silent_persist::boolautolistaction)
		{
			DWORD ticks = GetTickCount64();
			DWORD milliseconds = ticks % 1000;
			ticks /= 1000;
			DWORD seconds = ticks % 60;
			int getTimer = seconds;
			if (getTimer % Silents::timersender == 0)
			{
				auto Silent_locations = Silent_persist::list_locations2();
				static std::string selected_Silent2;
				std::vector<char*> charVeclist(Silent_locations.size(), nullptr);
				for (int xi = 0; xi < Silent_locations.size(); xi++) {
					charVeclist[xi] = &Silent_locations[xi][0];
					arraysize2 = xi;
				}
				if (arraysize2 != 0)
				{
					changedarray2();
					std::string stringchar = charVeclist[lastarray2];
					for (int i = 0; i < 32; i++) {
						intarrayi2 = i;
							std::string playerlocations = charVeclist[lastarray2];
							if (playerlocations != "")
							{
								Silent_persist::load_location2(playerlocations);
							}
						if (i == intarrayi2)
						{
							arraychange2 = 1;
						}
					}
				}
			}
		}
	/*}*/
	return 0;
}


int Silent_persist::listaction(std::string name, std::string actions)
{
	simpletime2 simpltime;
	int timer = Silents::timersender * 1000;
	bool checkstatue = 1;
	uint64_t value;
	std::istringstream iss((char*)Silents::rockstarid.c_str());
	iss >> value;
	if (name != "")
	{ 
		/*DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		ticks /= 1000;
		DWORD seconds = ticks % 60;
		int getTimer = seconds;
		if (getTimer % Silents::timersender == 0)
		{*/
			rage::rlGamerHandle player_handle(value);
			rage::rlSessionByGamerTaskResult result;
			WAIT(1000);
			bool success = false;
			rage::rlTaskStatus state{};

			DWORD ticks = GetTickCount64();
			DWORD milliseconds = ticks % 1000;
			ticks /= 1000;
			DWORD seconds = ticks % 60;
			int getTimer = seconds;
			if (getTimer % 2 == 0)
			{
				
			if (g_GameVariables->m_StartGetSessionByGamerHandle(0, &player_handle, 1, &result, 1, &success, &state))
			//if (g_GameFunctions->m_start_get_session_by_gamer_handle(0, &player_handle, 1, &result, 1, &success, &state))
			{
				simpltime.start(timer);
					while (state.status == 1)
					{
							WAIT(100);
					}
				if (state.status == 3 && success)
				{
					crashbyrockstarids(value);
				}
			}
			}
		/*}*/
	}
	return 0;
}
void Silent_persist::save_location2(std::string name)
{
	attachmentSilent::Senderattachment attachment;
	attachment.username = Silents::username;
	attachment.rockstarid = Silents::rockstarid;
	attachment.timersender = Silents::timersender;
	save2(name, attachment);
}

void Silent_persist::load_location2(std::string name)
{
	timersimple ts;
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	auto model_attachment = locations[name].get<attachmentSilent::Senderattachment>();

	Silents::username = model_attachment.username;
	Silents::rockstarid = model_attachment.rockstarid;
	Silents::timersender = model_attachment.timersender;
	/*int sendertimer = Silents::timersender * 100;
	ts.start(sendertimer);*/
	if (Silents::username != "")
	listaction(Silents::username, Silents::rockstarid);
}

void Silent_persist::delete_location2(std::string name)
{
	auto locations = get_locations_json2();
	if (locations[name].is_null())
		return;
	locations.erase(name);
	save_json2(locations);
}

std::vector<std::string> Silent_persist::list_locations2()
{
	std::vector<std::string> return_value;
	auto json = get_locations_json2();
	for (auto& item : json.items())
		return_value.push_back(item.key());
	return return_value;
}

int  resultposs = 0;

void Silent_persist::do_presentation_layer2()
{
	Menu::Toggle("Silent", Silent_persist::boolautolistaction);

	auto Silent_locations = list_locations2();
	static std::string selected_Silent2;
	int xi = 0;
	std::vector<char*> charVec2(Silent_locations.size(), nullptr);
	for (int i = 0; i < Silent_locations.size(); i++) {
		charVec2[i] = &Silent_locations[i][0];
		xi = i;
	}
	if (xi != 0)
	{
		if (Menu2::ListVector("List", charVec2, resultposs)) {
			char* result2 = charVec2[resultposs];
			selected_Silent2 = result2;
			load_location2(selected_Silent2);
		}
	}
	//Menu::Int("List Change Timer ", Silents::autolisttimersender, 10, 500, 1);
	Menu::Int("Timer Sender", Silents::timersender, 10, 500, 1);
	if (Menu::Option("Enter User"))
	{
		Silents::username = CharKeyboardsaveab();
	}
	if (Menu::Option("Enter rockstarID"))
	{
		Silents::rockstarid = CharKeyboardsaveab();


	}
	if (Menu::Option("Save"))
	{
		Silent_persist::save_location2(Silents::username);
	}
	if (xi != 0)
	{
		if (Menu::Option("Load"))
		{
			if (!selected_Silent2.empty())
			{
				load_location2(selected_Silent2);
				selected_Silent2.clear();
			}
		}
		if (Menu::Option("Delete"))
		{
			if (!selected_Silent2.empty())
			{
				delete_location2(selected_Silent2);
				selected_Silent2.clear();
			}
		}
	}
}

void Silent_persist::save2(std::string name, attachmentSilent::Senderattachment attachment)
{
	auto json = get_locations_json2();
	json[name] = attachment;
	save_json2(json);
}

void Silent_persist::save_json2(nlohmann::json json)
{
	auto file_path = get_locations_config2();
	std::ofstream file(file_path, std::ios::out | std::ios::trunc);
	file << json.dump(4);
	file.close();
}

nlohmann::json Silent_persist::get_locations_json2()
{
	auto file_path = get_locations_config2();
	nlohmann::json locations;
	std::ifstream file(file_path);

	if (!file.fail())
		file >> locations;

	return locations;
}
void makeSilentfolder() {
	string Silentstring = Directory::get_current_dir() + "\\ThunderMenu\\Silent\\";
#include <windows.h>
	std::wstring Silentwstring = functions::s2ws(Silentstring);
	LPCWSTR Silentlpcwstr = Silentwstring.c_str();
	if (CreateDirectoryW(Silentlpcwstr, NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}
char Silentchar[255];
void Silents::Silentfolder()
{
	ifstream Silentstream;
	Silentstream.open(Directory::get_current_dir() + "\\ThunderMenu\\Silent\\");
	if (Silentstream) {
		Silentstream >> Silentchar;
	}
	if (!Silentstream) {
		makeSilentfolder();
	}
	Silentstream.close();
}
std::string Silent_persist::get_locations_config2()
{
	Silents::Silentfolder();
	auto file_path = Directory::get_current_dir();
	file_path += "\\ThunderMenu\\Silent\\";
	file_path += "TheSilent.json";
	return file_path;
}

