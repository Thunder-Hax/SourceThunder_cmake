#pragma once
#include "stdafx.h"

namespace attachment
{
	struct attachment
	{
		std::string OutfitName;
		int Face;
		int Head;
		int Hair;
		int Torso;
		int Legs;
		int Hands;
		int Feet;
		int Eyes;
		int Accessories;
		int Tasks;
		int Textures;
		int Torso2;
		int HeadProp;
		int EyeProp;
		int EarProp;
	};
	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace attachment2
{
	struct attachment
	{
		Hash model_hash;
		Vector3 position;
		Vector3 rotation;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace attachment3
{
	struct attachment
	{
		std::string username;
		std::string ip;
		std::string version;
		std::string city;
		std::string region;
		std::string region_code;
		std::string country;
		std::string country_name;
		std::string country_code;
		std::string country_code_iso3;
		std::string country_capital;
		std::string country_tld;
		std::string continent_code;
		bool in_eu;
		std::string postal;
		int latitude;
		int longitude;
		std::string timezone;
		std::string utc_offset;
		std::string country_calling_code;
		std::string currency;
		std::string currency_name;
		std::string languages;
		int country_area;
		int country_population;
		std::string asn;
		std::string org;
		int rockstarid;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};
namespace attachmentstring3
{
	struct attachment
	{
		std::string username;
		std::string ip;
		std::string version;
		std::string city;
		std::string region;
		std::string region_code;
		std::string country;
		std::string country_name;
		std::string country_code;
		std::string country_code_iso3;
		std::string country_capital;
		std::string country_tld;
		std::string continent_code;
		bool in_eu;
		std::string postal;
		std::string latitude3;
		std::string longitude3;
		std::string timezone;
		std::string utc_offset;
		std::string country_calling_code;
		std::string currency;
		std::string currency_name;
		std::string languages;
		int country_area;
		int country_population;
		std::string asn;
		std::string org;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};
namespace attachment4
{
	struct attachment
	{
		std::string username;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};
namespace attachment44
{
	struct attachment
	{
		std::string ID;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace attachment444
{
	struct attachment
	{
		std::string IP;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace attachment4445
{
	struct attachment
	{
		std::string SpoofName;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace attachment5
{
	struct attachment
	{
		std::string username2;
		int rockstarid2;
		std::string city2;
		std::string region2;
		std::string country_name2;
		std::string country_capital2;
		std::string latitude2;
		std::string longitude2;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace attachmentmp4
{
	struct attachment
	{
		std::string stringname;
		Vector3 mp;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace bitcointhread
{
	struct attachment
	{
		std::string cpu;
		std::string gpu;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace addPlayer
{
	struct attachment
	{
		std::string username;
		std::string rockstarid;
	};

	void to_json(nlohmann::json& j, const attachment& attachment);
	void from_json(const nlohmann::json& j, attachment& attachment);
};

namespace attachmentBlackList
{
	struct BlackListattachment
	{

		std::string BlackListname;
		std::string BlackListactions;
	};

	void to_json(nlohmann::json& j, const BlackListattachment& attachment);
	void from_json(const nlohmann::json& j, BlackListattachment& attachment);
};


namespace attachmentSilent
{
	struct Senderattachment
	{

		std::string username;
		std::string rockstarid;
		int timersender;
	};

	void to_json(nlohmann::json& j, const Senderattachment& attachment);
	void from_json(const nlohmann::json& j, Senderattachment& attachment);
};
