#pragma once
#include "stdafx.h"

	class persist_outfit
	{
	public:
		static void do_presentation_layer();
	private:
		static void save_outfit(std::string OutfitName1, int Face1, int Head1, int Hair1, int Torso1, int Legs1, int Hands1, int Feet1, int Eyes1, int Accessories1, int Tasks1, int Textures1, int Torso21, int HeadProp1, int EyeProp1, int EarProp1);
		/*static void save_location(Ped ped, std::string name);*/
		static void load_outfit(std::string OutfitName1, int Face1, int Head1, int Hair1, int Torso1, int Legs1, int Hands1, int Feet1, int Eyes1, int Accessories1, int Tasks1, int Textures1, int Torso21, int HeadProp1, int EyeProp1, int EarProp1);
		static void delete_outfit(std::string name);
		static std::vector<std::string> list_locations();
		static void save(attachment::attachment attachment, std::string name);
		static void save_json(nlohmann::json json);
		static nlohmann::json get_locations_json();
		/*static std::filesystem::path get_locations_config();*/
		static std::string get_locations_config();
	};

	class persist_teleport
	{
	public:
		static void do_presentation_layer2();
	private:
		static void save_location2(Vector3 position, float rotation, std::string name);
		static void save_location2(Ped ped, std::string name);
		static void load_location2(std::string name);
		static void delete_location2(std::string name);
		static std::vector<std::string> list_locations2();
		static void save2(attachment2::attachment attachment, std::string name);
		static void save_json2(nlohmann::json json);
		static nlohmann::json get_locations_json2();
		static std::string get_locations_config2();
		/*static std::filesystem::path get_locations_config();*/
	};

	class persist_oversee
	{
	public:
		static void do_presentation_layer3();
		static int saveapi();
		static int saveapi00(std::string nameplayer, std::string UserId, std::string address);
		static int saveapi2();
		static std::string playername;
	private:
		static void load_oversee3(std::string name);
		static void load_overseefind3(std::string name);
		static void load_oversee32(std::string name);
		static void save_json3(nlohmann::json json);
		static std::vector<std::string> list_locations3();
		static std::vector<std::string> list_locations32();
		static nlohmann::json get_locations_json3();
		static nlohmann::json get_locations_json32();
		/*static std::filesystem::path get_locations_config();*/
		static std::string get_locations_config3();
		static std::string get_locations_config32();
	};
	namespace oversee
	{
		extern std::string city00;
		extern std::string region00;
		extern std::string country_name00;
		extern std::string country_capital00;		
		extern std::string reserved00;
		extern std::string username;
		extern std::string username2;
		extern std::string rockstarid;
		extern std::string rockstarid2;
		extern std::string ip;
		extern std::string version;
		extern std::string city;
		extern std::string city2;
		extern std::string city3;
		extern std::string region;
		extern std::string region2;
		extern std::string region3;
		extern std::string country;
		extern std::string country_name;
		extern std::string country_name2;
		extern std::string country_name3;
		extern std::string region_code;
		extern std::string country_code;
		extern std::string country_code_iso3;
		extern std::string country_capital;
		extern std::string country_capital2;
		extern std::string country_capital3;
		extern std::string country_tld;
		extern std::string continent_code;
		extern std::string in_eu;
		extern std::string postal;
		extern std::string latitude;
		extern std::string longitude;
		extern std::string mylatitude;
		extern std::string mylongitude;
		extern std::string latitude2;
		extern std::string longitude2;
		extern std::string latitude3;
		extern std::string longitude3;
		extern std::string timezone;
		extern std::string utc_offset;
		extern std::string country_calling_code;
		extern std::string currency;
		extern std::string currency_name;
		extern std::string languages;
		extern std::string country_area;
		extern std::string country_population;
		extern std::string asn;
		extern std::string org;
		extern std::string error;
		extern std::string reason;
		extern std::string reserved;
	}

	/*namespace overcheck
	{
		extern int waitTimer;
		extern bool overcheckbool;
		extern void wait();
		extern bool overcheckbool2;
		extern void wait2();
	}*/
	class persist_namechanger
	{
	public:
		static void do_presentation_layer4();
	private:
		static void savelocation4(std::string name1);
		static void load_location4(std::string name1);
		static void delete_location4(std::string name1);
		static std::vector<std::string> list_locations4();
		static void save4(attachment4::attachment attachment, std::string name);
		static void save_json4(nlohmann::json json);
		static nlohmann::json get_locations_json4();
		static std::string get_locations_config4();
		/*static std::filesystem::path get_locations_config();*/
	};
	
	class persist_IDchanger
	{
	public:
		static void do_presentation_layer4();
	private:
		static void savelocation4(std::string name1);
		static void load_location4(std::string name1);
		static void delete_location4(std::string name1);
		static std::vector<std::string> list_locations4();
		static void save4(attachment44::attachment attachment, std::string name);
		static void save_json4(nlohmann::json json);
		static nlohmann::json get_locations_json4();
		static std::string get_locations_config4();
		/*static std::filesystem::path get_locations_config();*/
	};

	class persist_IPchanger
	{
	public:
		static void do_presentation_layer4();
	private:
		static void savelocation4(std::string name1);
		static void load_location4(std::string name1);
		static void delete_location4(std::string name1);
		static std::vector<std::string> list_locations4();
		static void save4(attachment444::attachment attachment, std::string name);
		static void save_json4(nlohmann::json json);
		static nlohmann::json get_locations_json4();
		static std::string get_locations_config4();
		/*static std::filesystem::path get_locations_config();*/
	};
	class persist_Spoofchanger
	{
	public:
		static void do_presentation_layer4();
	private:
		static void savelocation4(std::string name1);
		static void load_location4(std::string name1);
		static void delete_location4(std::string name1);
		static std::vector<std::string> list_locations4();
		static void save4(attachment4445::attachment attachment, std::string name);
		static void save_json4(nlohmann::json json);
		static nlohmann::json get_locations_json4();
		static std::string get_locations_config4();
		/*static std::filesystem::path get_locations_config();*/
	};
	namespace name
	{
		extern std::string names;
		extern std::string names2;
		extern std::string names3;
		extern std::string names4;
	}

	namespace GeoLocation
	{
		extern std::string GeoLoc;
		extern std::string GeoLoc2;
		extern bool findRateLimitedbool;
		extern int findRateLimited();
		extern bool findSignupbool;
		extern int findSignup();
		extern bool findReservedbool;
		extern int findReserved();
		extern bool nullboolstringtoint;
		extern int findnull();
		extern bool haveip;
		extern int findip();
		extern bool haverid;
		extern int findrid();
		extern bool nullboolstringtoint2;
		extern int findnull2();
	}

	namespace nameplayer
	{
		extern std::string getplayername();
	}
	namespace coord
	{
		extern bool firstcheckall;
		extern int allsaved;
		extern int stringint;
		extern int intstring();
		extern bool moneycoordbool1[33];
		extern bool moneycoordbool2;
		extern int moneycoord1();
	}
	namespace moneyposition
	{
		extern std::string stringname1;
		extern Vector3 positionmoney1;
	}
	class persist_moneyposition
	{
	public:
		static void do_presentation_layermp4();
	private:
		static void savelocationmp4(std::string name1);
		static void load_locationmp4(std::string name1);
		static void delete_locationmp4(std::string name1);
		static std::vector<std::string> list_locationsmp4();
		static void savemp4(attachmentmp4::attachment attachment, std::string name);
		static void save_jsonmp4(nlohmann::json json);
		static nlohmann::json get_locations_jsonmp4();
		static std::string get_locations_configmp4();
		/*static std::filesystem::path get_locations_config();*/
	};

	class persist_Bitcoin
	{
	public:
		static void do_presentation_layer();
	private:
		/*static void save_location(Vector3 position, float rotation, std::string name);*/
		static void save_location(std::string name, int thread);
		static void load_location(std::string name);
		/*static void delete_location(std::string name);*/
		static std::vector<std::string> list_locations();
		static void save(std::string name, bitcointhread::attachment attachment);
		static void save_json(nlohmann::json json);
		static nlohmann::json get_locations_json();
		static std::string get_locations_config();
	};

	namespace Bitcoin
	{
		extern std::string TaskName;
		extern int thread;
	}


	class persist_addPlayer
	{
	public:
		static void do_presentation_layer2();
		static int saveplayer();
		static int saveaplayer();
	private:
		/*static void save_location2(Vector3 position, float rotation, std::string name);*/
		static void save_location2(std::string name);
		static void save_locationa2(std::string name);
		static void load_location2(std::string name);
		static void delete_location2(std::string name);
		static std::vector<std::string> list_locations2();
		static void save2(addPlayer::attachment attachment, std::string name);
		static void save_json2(nlohmann::json json);
		static nlohmann::json get_locations_json2();
		static std::string get_locations_config2();
		/*static std::filesystem::path get_locations_config();*/
	};

	namespace BlackLists
	{
		extern std::string BlackListName;
		extern void BlackListfolder();
		extern std::string BlackListnamesaved;
		extern void savedBlackList();
		extern std::string BlackListActions;
	}

	class persist_BlackList
	{
	public:
		static bool boolautolistaction;
		static int autolistaction();
		static int listaction(std::string name, std::string actions);
		static void do_presentation_layer2();
		static int BlackListpersist();
	private:
		static void save_location2(std::string name, std::string action);
		static void save_location2(std::string name);
		static void load_location2(std::string name);
		static void delete_location2(std::string name);
		static std::vector<std::string> list_locations2();
		static void save2(std::string name, attachmentBlackList::BlackListattachment attachment);
		static void save_json2(nlohmann::json json);
		static nlohmann::json get_locations_json2();
		static std::string get_locations_config2();
		/*static std::filesystem::path get_locations_config();*/
	};
	extern void makeBlackListfolder();

	class Silent_persist
	{
	public:
		static bool boolautolistaction;
		static int autolistaction();
		static int listaction(std::string name, std::string actions);
		static void do_presentation_layer2();
		static int Silentpersist();
		static std::string lastname;
	private:
		static void save_location2(std::string name, std::string rockstarid, int timersender);
		static void save_location2(std::string name);
		static void load_location2(std::string name);
		static void delete_location2(std::string name);
		static std::vector<std::string> list_locations2();
		static void save2(std::string name, attachmentSilent::Senderattachment attachment);
		static void save_json2(nlohmann::json json);
		static nlohmann::json get_locations_json2();
		static std::string get_locations_config2();
	};
	extern void makeSilentfolder();

	class timersimple {
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

	namespace Silents
	{
		extern void Silentfolder();
		extern std::string username;
		extern std::string rockstarid;
		extern int autolisttimersender;
		extern int timersender;
	}
	extern void SilentbotRidcrash();
