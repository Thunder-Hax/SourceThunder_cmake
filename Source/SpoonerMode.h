/*
* Menyoo PC - Grand Theft Auto V single-player trainer mod
* Copyright (C) 2019  MAFINS
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*/
#pragma once

#include "GTAentity.h"
#include "model.h"

#include <utility>
#include <set>

typedef unsigned char UINT8, BYTE;
typedef unsigned short UINT16;

//class Camera;

namespace Spooner
{
	class SpoonerEntity;

	namespace SpoonerMode
	{
		extern BYTE bindsKeyboard;
		extern std::pair<UINT16, UINT16> bindsGamepad;

		extern bool bEnabled;
		extern bool bIsSomethingHeld;
		extern bool bHeldEntityHasCollision;
		extern Camera2 spoonerModeCamera;
		extern float spoonerModeCameraCamDistance;

		bool IsHotkeyPressed();

		class Menu2 final
		{
		public:
			static INT currentsub_ar[100];
			/*static bool bit_controller;*/
		};
		struct ModelPreviewInfoStructure
		{
			EntityType entityType;
			Model previousModel,
				model;
			GTAentity entity;
			std::set<GTAentity> previousEntities;
		};
		extern ModelPreviewInfoStructure ModelPreviewInfo;
		void SpawnModelPreview();

		void ResetSelectedEntity();
		bool GetEntityPtr(GTAentity& inEntity, SpoonerEntity*& outEntity);
		SpoonerEntity GetEntityPtrValue(GTAentity& entity);
		inline void SetAsSelectedEntity(GTAentity& entity);

		inline void CamTick();
		void Tick();

		void TurnOn();
		void TurnOff();
		void Toggle();
	}

}



