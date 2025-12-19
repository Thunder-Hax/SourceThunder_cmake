#include "stdafx.h"
#include "GTAplayer.h"
GTAplayer::GTAplayer()
	: index(0Ui8)
{
}

GTAplayer::GTAplayer(const GTAplayer& obj)
	: index(obj.index)
{
}

GTAplayer::GTAplayer(INT8 newIndex)
	: index(newIndex)
{
}

bool GTAplayer::IsFreeAiming() const
{
	return PLAYER::IS_PLAYER_FREE_AIMING(index) != 0;
}

bool GTAplayer::IsTargetingAnything() const
{
	return PLAYER::IS_PLAYER_TARGETTING_ANYTHING(index) != 0;
}

void GTAplayer::SetControl(bool toggle, int flag)
{
	PLAYER::SET_PLAYER_CONTROL(index, toggle, flag);
}

GTAentity GTAplayer::AimedEntity() const
{
	Entity target;
	if (PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(index, &target))
	{
		if (ENTITY::IS_ENTITY_A_PED(target))
		{
			if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(target))
				return PED::GET_VEHICLE_PED_IS_IN(target, 0);
		}
		return target;
	}
	return 0;
}
