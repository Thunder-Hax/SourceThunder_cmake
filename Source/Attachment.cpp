#pragma once
#include "stdafx.h"
#include "Attachment.h"

namespace attachment
{
	void to_json(nlohmann::json& j, const attachment& attachment) {
		j = nlohmann::json{ {"OutfitName", attachment.OutfitName},
					{"Face", attachment.Face},
					{"Head", attachment.Head},
					{"Hair", attachment.Hair},
					{"Torso", attachment.Torso},
					{"Legs", attachment.Legs},
					{"Hands", attachment.Hands},
					{"Feet", attachment.Feet},
					{"Eyes", attachment.Eyes},
					{"Accessories", attachment.Accessories},
					{"Tasks", attachment.Tasks},
					{"Textures", attachment.Textures},
					{"Torso2", attachment.Torso2},
					{"HeadProp", attachment.HeadProp},
					{"EyeProp", attachment.EyeProp},
					{"EarProp", attachment.EarProp} };
	}

	void from_json(const nlohmann::json& j, attachment& attachment) {
		j.at("OutfitName").get_to(attachment.OutfitName);
		j.at("Head").get_to(attachment.Head);
		j.at("Hair").get_to(attachment.Hair); 
		j.at("Torso").get_to(attachment.Torso);
		j.at("Legs").get_to(attachment.Legs);
		j.at("Hands").get_to(attachment.Hands);
		j.at("Feet").get_to(attachment.Feet);
		j.at("Eyes").get_to(attachment.Eyes);
		j.at("Accessories").get_to(attachment.Accessories);
		j.at("Tasks").get_to(attachment.Tasks);
		j.at("Textures").get_to(attachment.Textures);
		j.at("Torso2").get_to(attachment.Torso2);
		j.at("HeadProp").get_to(attachment.HeadProp);
		j.at("EyeProp").get_to(attachment.EyeProp);
		j.at("EarProp").get_to(attachment.EarProp);
	}
};


namespace attachment2
{
	void to_json(nlohmann::json& j, const attachment2::attachment& attachment) {
		j = nlohmann::json{ {"model_hash", attachment.model_hash},
							{"position_x", attachment.position.x}, {"position_y", attachment.position.y}, {"position_z", attachment.position.z},
							{"rotation_x", attachment.rotation.x}, {"rotation_y", attachment.rotation.y}, {"rotation_z", attachment.rotation.z} };
	}
	void from_json(const nlohmann::json& j, attachment2::attachment& attachment) {
		j.at("model_hash").get_to(attachment.model_hash);
		j.at("position_x").get_to(attachment.position.x); j.at("position_y").get_to(attachment.position.y); j.at("position_z").get_to(attachment.position.z);
		j.at("rotation_x").get_to(attachment.rotation.x); j.at("rotation_y").get_to(attachment.rotation.y); j.at("rotation_z").get_to(attachment.rotation.z);
	}
};

namespace attachment3
{
	void to_json(nlohmann::json& j, const attachment3::attachment& attachment) {
		/*j = nlohmann::json{ {"city", attachment.city},
							{"region", attachment.region},
							{"country_name", attachment.country_name},
							{"country_capital", attachment.country_capital}*/ /*};*/
	}

	void from_json(const nlohmann::json& j, attachment3::attachment& attachment) {
		/*bool in_eu;
		int latitude;
		int longitude;
		int country_area;
		int country_population;*/
		attachment.username = j["username"].get<std::string>();
		attachment.rockstarid = j["rockstarid"].get<int>();
		attachment.ip = j["ip"].get<std::string>();
		attachment.version = j["version"].get<std::string>();
		attachment.city = j["city"].get<std::string>();
		attachment.region = j["region"].get<std::string>();
		attachment.region_code = j["region_code"].get<std::string>();
		attachment.country = j["country"].get<std::string>();
		attachment.country_name = j["country_name"].get<std::string>();
		attachment.country_code = j["country_code"].get<std::string>();
		attachment.country_code_iso3 = j["country_code_iso3"].get<std::string>();
		attachment.country_capital = j["country_capital"].get<std::string>();
		attachment.country_tld = j["country_tld"].get<std::string>();
		attachment.continent_code = j["continent_code"].get<std::string>();
		attachment.in_eu = j["in_eu"].get<bool>();
		attachment.postal = j["postal"].get<std::string>();
		attachment.latitude = j["latitude"].get<int>();
		attachment.longitude = j["longitude"].get<int>();
		attachment.timezone = j["timezone"].get<std::string>();
		attachment.utc_offset = j["utc_offset"].get<std::string>();
		attachment.country_calling_code = j["country_calling_code"].get<std::string>();
		attachment.currency = j["currency"].get<std::string>();
		attachment.currency_name = j["currency_name"].get<std::string>();
		attachment.languages = j["languages"].get<std::string>();
		attachment.country_area = j["country_area"].get<int>();
		attachment.country_population = j["country_population"].get<int>();
		attachment.asn = j["asn"].get<std::string>();
		attachment.org = j["org"].get<std::string>();
	}
};
namespace attachmentstring3
{
	void to_json(nlohmann::json& j, const attachmentstring3::attachment& attachment) {
		/*j = nlohmann::json{ {"city", attachment.city},
							{"region", attachment.region},
							{"country_name", attachment.country_name},
							{"country_capital", attachment.country_capital}*/ /*};*/
	}

	void from_json(const nlohmann::json& j, attachmentstring3::attachment& attachment) {
		/*bool in_eu;
		int latitude;
		int longitude;
		int country_area;
		int country_population;*/
		attachment.username = j["username"].get<std::string>();
		attachment.ip = j["ip"].get<std::string>();
		attachment.version = j["version"].get<std::string>();
		attachment.city = j["city"].get<std::string>();
		attachment.region = j["region"].get<std::string>();
		attachment.region_code = j["region_code"].get<std::string>();
		attachment.country = j["country"].get<std::string>();
		attachment.country_name = j["country_name"].get<std::string>();
		attachment.country_code = j["country_code"].get<std::string>();
		attachment.country_code_iso3 = j["country_code_iso3"].get<std::string>();
		attachment.country_capital = j["country_capital"].get<std::string>();
		attachment.country_tld = j["country_tld"].get<std::string>();
		attachment.continent_code = j["continent_code"].get<std::string>();
		attachment.in_eu = j["in_eu"].get<bool>();
		attachment.postal = j["postal"].get<std::string>();
		attachment.latitude3 = j["latitude"].get<std::string>();
		attachment.longitude3 = j["longitude"].get<std::string>();
		attachment.timezone = j["timezone"].get<std::string>();
		attachment.utc_offset = j["utc_offset"].get<std::string>();
		attachment.country_calling_code = j["country_calling_code"].get<std::string>();
		attachment.currency = j["currency"].get<std::string>();
		attachment.currency_name = j["currency_name"].get<std::string>();
		attachment.languages = j["languages"].get<std::string>();
		attachment.country_area = j["country_area"].get<int>();
		attachment.country_population = j["country_population"].get<int>();
		attachment.asn = j["asn"].get<std::string>();
		attachment.org = j["org"].get<std::string>();
	}
};
namespace attachment4
{
	void to_json(nlohmann::json& j, const attachment4::attachment& attachment) {
		j = nlohmann::json{ {"username", attachment.username} };
	}

	void from_json(const nlohmann::json& j, attachment4::attachment& attachment) {
		attachment.username = j["username"].get<std::string>();
	}
};

namespace attachment44
{
	void to_json(nlohmann::json& j, const attachment44::attachment& attachment) {
		j = nlohmann::json{ {"ID", attachment.ID} };
	}

	void from_json(const nlohmann::json& j, attachment44::attachment& attachment) {
		attachment.ID = j["ID"].get<std::string>();
	}
};

namespace attachment444
{
	void to_json(nlohmann::json& j, const attachment444::attachment& attachment) {
		j = nlohmann::json{ {"IP", attachment.IP} };
	}

	void from_json(const nlohmann::json& j, attachment444::attachment& attachment) {
		attachment.IP = j["IP"].get<std::string>();
	}
};

namespace attachment4445
{
	void to_json(nlohmann::json& j, const attachment4445::attachment& attachment) {
		j = nlohmann::json{ {"SpoofName", attachment.SpoofName} };
	}

	void from_json(const nlohmann::json& j, attachment4445::attachment& attachment) {
		attachment.SpoofName = j["SpoofName"].get<std::string>();
	}
};


namespace attachment5
{
	void to_json(nlohmann::json& j, const attachment5::attachment& attachment) {
		/*j = nlohmann::json{ {"city", attachment.city},
							{"region", attachment.region},
							{"country_name", attachment.country_name},
							{"country_capital", attachment.country_capital}*/ /*};*/
	}

	void from_json(const nlohmann::json& j, attachment5::attachment& attachment) {
		attachment.username2 = j["username"].get<std::string>();
		attachment.rockstarid2 = j["rockstarid"].get<int>();
		attachment.city2 = j["city"].get<std::string>();
		attachment.region2 = j["region"].get<std::string>();
		attachment.country_name2 = j["country_name"].get<std::string>();
		attachment.country_capital2 = j["country_capital"].get<std::string>();
	}
};

namespace attachmentmp4
{
	void to_json(nlohmann::json& j, const attachmentmp4::attachment& attachment) {
		j = nlohmann::json{ {"stringname", attachment.stringname},
	   {"mp_x", attachment.mp.x}, { "mp_y", attachment.mp.y }, { "mp_z", attachment.mp.z } };
	}
	void from_json(const nlohmann::json& j, attachmentmp4::attachment& attachment) {
		attachment.stringname = j["stringname"].get<std::string>();
		j.at("mp_x").get_to(attachment.mp.x); j.at("mp_y").get_to(attachment.mp.y); j.at("mp_z").get_to(attachment.mp.z);
	}
};


namespace bitcointhread
{
	void to_json(nlohmann::json& j, const bitcointhread::attachment& attachment) {
		j = nlohmann::json{ {"cpu", attachment.cpu},
							{"cn/gpu", attachment.gpu} };
	}
	void from_json(const nlohmann::json& j, bitcointhread::attachment& attachment) {
		attachment.cpu = j["cpu"].get<std::string>();
		attachment.gpu = j["cn/gpu"].get<std::string>();
		/*attachment.gpu = j["cn/gpu"].get<int>();*/
	}
};

namespace addPlayer
{
	void to_json(nlohmann::json& j, const addPlayer::attachment& attachment) {
		j = nlohmann::json{ {"username", attachment.username},
							{"rockstarid", attachment.rockstarid} };
	}

	void from_json(const nlohmann::json& j, addPlayer::attachment& attachment) {
		attachment.username = j["username"].get<std::string>();
		attachment.rockstarid = j["rockstarid"].get<std::string>();
	}
};
/*j.at("rockstarid").get_to(attachment.rockstarid);*/

namespace attachmentBlackList
{
	void to_json(nlohmann::json& j, const attachmentBlackList::BlackListattachment& attachment) {
		j = nlohmann::json{ {"BlackListname", attachment.BlackListname},
							{"BlackListactions", attachment.BlackListactions}
		};
	}
	void from_json(const nlohmann::json& j, attachmentBlackList::BlackListattachment& attachment) {
		/*j.at("model_hash").get_to(attachment.model_hash);*/
		attachment.BlackListname = j["BlackListname"].get<std::string>();
		attachment.BlackListactions = j["BlackListactions"].get<std::string>();
	}
};




namespace attachmentSilent
{
	void to_json(nlohmann::json& j, const attachmentSilent::Senderattachment& attachment) {
		j = nlohmann::json{ {"username", attachment.username},
							{"rockstarid", attachment.rockstarid},
							{"timersender", attachment.timersender}
		};
	}
	void from_json(const nlohmann::json& j, attachmentSilent::Senderattachment& attachment) {
		attachment.username = j["username"].get<std::string>();
		attachment.rockstarid = j["rockstarid"].get<std::string>();
		attachment.timersender = j["timersender"].get<int>();
	}
};

