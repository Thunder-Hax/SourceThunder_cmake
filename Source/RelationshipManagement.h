#pragma once

typedef unsigned long DWORD, Hash;

#include <string>
#include <vector>

class GTAped;

namespace Spooner
{
	namespace RelationshipManagement
	{
		//struct RelationshipGroup_t{ std::string name; Hash handle; };
		extern bool RG_Created;
		extern std::string RG_SpoonerFriends;
		extern std::string RG_SpoonerEnemies;
		extern std::string RG_SpoonerNeutral;
		extern std::string RG_Me;

		extern std::vector<std::string> vRGs;

		//bool GetPedRelationshipGroup(const GTAped& ped, std::string& outGrp)
		bool GetPedRelationshipGroup(const GTAped& ped, Hash& outHash);
		void SetPedRelationshipGroup(GTAped ped, Hash group);
	}

}



namespace gethashkey
{ 
	Hash GET_HASH_KEY(const std::string& value);
}