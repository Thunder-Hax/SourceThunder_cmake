#pragma once
#include "stdafx.h"

//struct playerinfo {
//	std::string name;
//	Ped ped;
//	Blip blip;
//	int head;
//	bool wasDead;
//};
//
//#define MAX_PLAYERS 32
//playerinfo playerdb[MAX_PLAYERS];
//DWORD statusTextDrawTicksMax;
//std::string statusText;
//bool statusTextGxtEntry;
//bool featurePlayerHeadDisplay = true;
//bool featurePlayerBlipCone = false;
//bool featurePlayerBlips = false;
//bool featurePlayerNotifications = true;
//bool featureShowVoiceChatSpeaker = true;
//bool playerWasDisconnected = false;
//Player playerId;
//void update_status_cue()
//{
//	if (GetTickCount64() < statusTextDrawTicksMax)
//	{
//		if (statusTextGxtEntry)
//		{
//			UI::_SET_NOTIFICATION_TEXT_ENTRY((char*)statusText.c_str());
//		}
//		else
//		{
//			UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
//			UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)statusText.c_str());
//		}
//		/*UI::END_TEXT_COMMAND_THEFEED_POST_TICKER(FALSE, FALSE);*/
//		CHooking::draw_notification(false, false);
//	}
//}
//void DRAW_CLAN(char* Streamedtexture, char* textureName, char* WhatSubMenu)
//{
//	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture))
//	{
//		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
//	}
//	else
//	{
//		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2(Streamedtexture, textureName, 1, rand() % 8, "Thunder-Menu", WhatSubMenu, 1, "Fair-Use", rand() % 8, 1);
//	}
//}
//void CustomNotify(std::string whattosay, char* WhatSubMenu) {
//	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
//	std::string curName = PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID());
//	std::string ss = curName + ",  ~c~" + whattosay;
//	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)ss.c_str());
//	DRAW_CLAN("char_polaris", "icon", WhatSubMenu);
//	CHooking::draw_notification(false, false);
//}
//void set_status_text(std::string str)
//{
//	statusText = str;
//}
//
//bool whotalk::whotalks = false;
//void whotalk::updatePolaris()
//{
//	if (playerWasDisconnected) {
//		NETWORK::NETWORK_SET_FRIENDLY_FIRE_OPTION(1);
//		playerId = PLAYER::PLAYER_ID();
//		PED::SET_CAN_ATTACK_FRIENDLY(playerId, 1, 1);
//	}
//
//	std::string voice_status_msg = "Currently Talking:";
//	bool isVoiceChatRunning = FALSE;
//
//	for (int i = 0; i < MAX_PLAYERS; i++)
//	{
//		if (featureShowVoiceChatSpeaker && isVoiceChatRunning)
//			update_status_cue();
//
//		if (NETWORK::NETWORK_IS_PLAYER_CONNECTED(i))
//		{
//			std::string name = (char*)PLAYER::GET_PLAYER_NAME(i);
//
//			if (featureShowVoiceChatSpeaker && NETWORK::NETWORK_IS_PLAYER_TALKING(i))
//			{
//				if (!isVoiceChatRunning)
//					isVoiceChatRunning = TRUE;
//				voice_status_msg += "~n~" + name;
//			}
//
//			if (i != playerId)
//			{
//				Ped pedId = PLAYER::GET_PLAYER_PED(i);
//				unsigned int headDisplayId = UI::_CREATE_MP_GAMER_TAG(pedId, (char*)"", 0, 0, (char*)"", 0); // CREATE_PED_HEAD_DISPLAY
//
//				if (UI::IS_MP_GAMER_TAG_ACTIVE(headDisplayId))
//				{
//					playerdb[i].head = headDisplayId;
//					if (featurePlayerHeadDisplay)
//						UI::SET_MP_GAMER_TAG_NAME(headDisplayId, (char*)name.c_str()); // SET_HEAD_DISPLAY_STRING
//					UI::SET_MP_GAMER_TAG_VISIBILITY(headDisplayId, 0, 1); // SET_HEAD_DISPLAY_FLAG
//				}
//
//				if (playerWasDisconnected || !UI::DOES_BLIP_EXIST(playerdb[i].blip))
//				{
//					if (featurePlayerBlips)
//					{
//						playerdb[i].blip = UI::ADD_BLIP_FOR_ENTITY(pedId);
//						UI::SET_BLIP_COLOUR(playerdb[i].blip, 0);
//						UI::SET_BLIP_SCALE(playerdb[i].blip, 0.8f);
//						if (featurePlayerBlipCone)
//							UI::SET_BLIP_SHOW_CONE(playerdb[i].blip, 1);
//						UI::SET_BLIP_NAME_TO_PLAYER_NAME(playerdb[i].blip, i);
//						UI::SET_BLIP_CATEGORY(playerdb[i].blip, 7);
//					}
//
//					if (playerWasDisconnected || playerdb[i].name != name) // Making sure the player wasn't already here and only changed his ped (ex. skin change)
//					{
//						if (featurePlayerNotifications)
//						{
//							//char Join[50];
//							//snprintf(Join, sizeof(Join), "Nice! \n <C>%s</C> is joining.", name);
//							//Notify(Predo, 6);
//							std::string msg = "<C>" + name + "</C> is joining.";
//							CustomNotify((char*)msg.c_str(), "Joining Player");
//							PED::SET_CAN_ATTACK_FRIENDLY(i, 1, 1);
//							playerdb[i].name = name;
//							playerdb[i].ped = pedId;
//						}
//					}
//				}
//				else if (playerdb[i].name != "")
//				{
//					if (featurePlayerNotifications)
//					{
//						//std::string msg = "Goodbye, <C>" + playerdb[i].name + "</C>.";
//						//leave_notification((char*)msg.c_str());
//					}
//
//					if (UI::IS_MP_GAMER_TAG_ACTIVE(playerdb[i].head))
//						UI::SET_MP_GAMER_TAG_NAME(playerdb[i].head, (char*)"");
//					if (UI::DOES_BLIP_EXIST(playerdb[i].blip))
//						UI::REMOVE_BLIP(playerdb[i].blip);
//					playerdb[i].name = "";
//				}
//			}
//			playerWasDisconnected = FALSE;
//
//			if (isVoiceChatRunning)
//				set_status_text(voice_status_msg);
//		}
//		else
//		{
//			playerWasDisconnected = TRUE;
//		}
//	}
//}