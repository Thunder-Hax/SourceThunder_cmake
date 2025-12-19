#include "stdafx.h"
#include "RelationshipManagement.h"

//#include "..\..\macros.h"

//#include "..\..\Menu\Menu.h"
//#include "..\..\Menu\Routine.h"

//#include "..\..\Natives\natives2.h"
#include "GTAped.h"
#include "World.h"
#include "enums.h"

#include "Databases.h"

#include <string>
#include <vector>
#include <utility>

Hash gethashkey::GET_HASH_KEY(const std::string& value)
{
	size_t len = value.length();
	DWORD hash, i;
	for (hash = i = 0; i < len; ++i)
	{
		hash += tolower(value[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

namespace Spooner
{
	namespace RelationshipManagement
	{
		//struct RelationshipGroup_t{ std::string name; Hash handle; };
		bool RG_Created = false;
		std::string RG_SpoonerFriends = { "SPOONER_FRIENDS" };
		std::string RG_SpoonerEnemies = { "SPOONER_ENEMIES" };
		std::string RG_SpoonerNeutral = { "SPOONER_NEUTRAL" };
		std::string RG_Me = { "PLAYER", };

		std::vector<std::string> vRGs{ RG_SpoonerFriends, RG_SpoonerEnemies, RG_SpoonerNeutral };

		/*bool GetPedRelationshipGroup(const GTAped& ped, std::string& outGrp)
		{
			for (auto& r : Databases::RelationshipDb)
			{
				if (ped.Equals(r.first))
				{
					outGrp = r.second;
					return true;
				}
			}
			return false;
		}*/
		bool GetPedRelationshipGroup(const GTAped& ped, Hash& outHash)
		{
			outHash = ped.RelationshipGroup_get();
			return (outHash == gethashkey::GET_HASH_KEY(RG_SpoonerFriends) || outHash == gethashkey::GET_HASH_KEY(RG_SpoonerEnemies) || outHash == gethashkey::GET_HASH_KEY(RG_SpoonerNeutral));
		}
		void SetPedRelationshipGroup(GTAped ped, Hash group)
		{
			//using namespace sub::Spooner::RelationshipManagement;

			if (NETWORK::NETWORK_HAS_PLAYER_STARTED_TRANSITION(Features::Online::selectedPlayer/*PLAYER_ID()*/))
				RG_Created = false;

			if (!RG_Created)
			{
				World::AddRelationshipGroup(RG_SpoonerFriends);
				World::AddRelationshipGroup(RG_SpoonerEnemies);
				World::AddRelationshipGroup(RG_SpoonerNeutral);
				//World::AddRelationshipGroup(RG_Me);

				World::SetRelationshipBetweenGroups(PedRelationship::Neutral, RG_SpoonerFriends, RG_SpoonerNeutral);
				World::SetRelationshipBetweenGroups(PedRelationship::Neutral, RG_SpoonerEnemies, RG_SpoonerNeutral);
				World::SetRelationshipBetweenGroups(PedRelationship::Hate, RG_SpoonerFriends, RG_SpoonerEnemies);
				World::SetRelationshipBetweenGroups(PedRelationship::Companion, RG_SpoonerFriends, RG_Me);
				RG_Created = true;
			}

			ped.RelationshipGroup_set(group);

			for (auto& r : Databases::RelationshipDb)
			{
				if (ped.Equals(r.first))
				{
					r.second = group;
					return;
				}
			}
			Databases::RelationshipDb.push_back(std::make_pair(ped, group));
		}
	}

}



