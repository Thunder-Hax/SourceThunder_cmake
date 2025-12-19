#include "stdafx.h"
#include "SpoonerMode.h"

//#include "..\..\macros.h"

#include "natives.h"

//#include "..\..\Menu\Menu.h"
////#include "..\..\Menu\Routine.h"
//
#include "natives.h"
#include "keyboard.h"
#include "Camera.h"
#include "GTAentity.h"
#include "GTAprop.h"
#include "GTAvehicle.h"
#include "GTAped.h"
#include "GTAplayer.h"
#include "GTAmath.h"
#include "types.h" //RGBA
#include "World.h"
#include "model.h"
//#include "..\..\Scripting\ModelNames.h"
#include "StringManip.h"
#include "enums.h"
#include "Game.h"
//
//#include "SpoonerSettings.h"
#include "EntityManagement.h"
//#include "SpoonerEntity.h"
//#include "Databases.h"
//#include "SpoonerMarker.h"
//#include "MarkerManagement.h"
//#include "Submenus.h"

#include <utility>
#include <set>
#include <math.h>

namespace Spooner
{
	namespace SpoonerMode
	{
		BYTE bindsKeyboard = VirtualKey::F9;
		std::pair<UINT16, UINT16> bindsGamepad = { INPUT_FRONTEND_RB, INPUT_FRONTEND_RIGHT };

		bool bEnabled = false;
		bool bIsSomethingHeld = false;
		bool bHeldEntityHasCollision = true;
		Camera2 spoonerModeCamera;
		float spoonerModeCameraCamDistance = 5.0f;
		eSpoonerModeMode& spoonerModeMode = Settings::SpoonerModeMode;

		INT Menu2::currentsub_ar[100] = {};
		bool IsHotkeyPressed()
		{
			if (std::find(std::begin(Menu2::currentsub_ar), std::end(Menu2::currentsub_ar), /*SUB::SPOONER_MAIN*/SubMenus::noclipmenyoo) == std::end(Menu2::currentsub_ar))
			{
				UINT8 index1 = bindsGamepad.first < 50 ? 0 : 2;
				UINT8 index2 = bindsGamepad.second < 50 ? 0 : 2;
				return Menu3::bit_controller ? (CONTROLS::IS_DISABLED_CONTROL_PRESSED(index1, bindsGamepad.first) && CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(index2, bindsGamepad.second)) : IsKeyJustUp(bindsKeyboard);
			}
			return false;
		}

		ModelPreviewInfoStructure ModelPreviewInfo = { EntityType::ALL, 0, 0, 0,{} };
		void SpawnModelPreview()
		{
			bool bOnTheLine = NETWORK::NETWORK_IS_IN_SESSION() != 0;
			auto& info = ModelPreviewInfo;
			if (info.entityType == EntityType::ALL)
			{
				if (info.entity != 0)
				{
					if (bOnTheLine)
					{
						info.previousEntities.insert(info.entity);
					}
					else
					{
						info.entity.Delete(true);
						info.entity = 0;
					}
				}
				if (info.model.hash != 0)
				{
					if (info.model.IsLoaded())
						info.model.Unload();
					info.model = 0;
				}
				if (info.previousModel.hash != 0)
				{
					if (info.previousModel.IsLoaded())
						info.previousModel.Unload();
					info.previousModel = 0;
				}
			}
			else if (info.model != info.previousModel)
			{
				if (bOnTheLine)
				{
					info.previousEntities.insert(info.entity);
				}
				else
				{
					info.entity.Delete(true);
					info.entity = 0;
				}
				if (info.previousModel.IsLoaded())
					info.previousModel.Unload();
				info.previousModel = info.model;
				if (info.model.IsInCdImage())
					info.model.Load();
			}
			else
			{
				if (info.entity.Exists())
				{
					ModelDimensions& dimensions = info.model.Dimensions();

					Vector31 spawnRot(0, 0, spoonerModeCamera.Rotation_get().z1);

					Vector31& geSep = info.entity.Position_get();
					//auto& geGroundRay = RaycastResult::Raycast(geSep, Vector3::WorldDown(), max(max(dimensions.Dim1.x, dimensions.Dim2.x), max(max(dimensions.Dim1.y, dimensions.Dim2.y), max(dimensions.Dim1.z, dimensions.Dim2.z))) + 2.0f, IntersectOptions::Everything, info.entity);
					float geGroundZ = dimensions.Dim1.z1;
					//if (geGroundRay.DidHitAnything()){
					//float oldYaw = spawnRot.z;
					//geGroundZ = geGroundRay.HitCoords().DistanceTo(geSep);
					//Vector3 spawnRot;
					//spawnRot = Vector3::DirectionToRotation(geGroundRay.SurfaceNormal());
					//spawnRot.x += 90.0f;
					//spawnRot.z = oldYaw;
					//}
					if (abs(spawnRot.x1) > 150.0f || abs(spawnRot.y1) > 150.0f) geGroundZ = dimensions.Dim2.z1;
					else if (abs(spawnRot.x1) > 70.0f && abs(spawnRot.y1) > 70.0f) geGroundZ = (dimensions.Dim1.y1 + dimensions.Dim1.x1) / 2;
					else if (abs(spawnRot.x1) > 70.0f) geGroundZ = dimensions.Dim1.y1;
					else if (abs(spawnRot.y1) > 70.0f) geGroundZ = dimensions.Dim1.x1;
					Vector31 spawnPos(spoonerModeCamera.RaycastForCoord(Vector21(0.0f, 0.0f), info.entity, 120.0f, 23.0f + dimensions.Dim2.y1) + Vector31(0, 0, geGroundZ));

					if (bOnTheLine)
						info.entity.RequestControlOnce();
					info.entity.Rotation_set(spawnRot);
					info.entity.Position_set(spawnPos);
					EntityManagement::ShowBoxAroundEntity(info.entity, false, RGBA1::AllWhite());
				}
				else
				{
					if (info.model.IsLoaded())
					{
						switch (info.entityType)
						{
						case EntityType::PROP:
							info.entity = World::CreateProp(info.model, Vector31(), Vector31(), false, false);
							break;
						case EntityType::PED:
							info.entity = World::CreatePed(info.model, Vector31(), Vector31(), false);
							break;
						case EntityType::VEHICLE:
							info.entity = World::CreateVehicle(info.model, Vector31(), Vector31(), false);
							break;
						}
						info.entity.FreezePosition(true);
						info.entity.IsCollisionEnabled_set(false);
						info.entity.Alpha_set(120);
						//info.entity.Rotation_set()
						//info.entity.Position_set(spawnPos);
					}
				}
			}

			info.entityType = EntityType::ALL;

			for (auto& it = info.previousEntities.begin(); it != info.previousEntities.end();)
			{
				GTAentity e = *it;
				if (e.RequestControlOnce())
				{
					if (e == info.entity)
						info.entity = 0;
					e.Delete(true);
					it = info.previousEntities.erase(it);
				}
				else ++it;
			}
		}

		void ResetSelectedEntity()
		{
			SelectedEntity.Handle = 0;
		}
		bool GetEntityPtr(GTAentity& inEntity, SpoonerEntity*& outEntity)
		{
			outEntity = new SpoonerEntity;

			outEntity->Handle = inEntity;
			outEntity->Type = (EntityType)inEntity.Type();
			Model& outEntity_model = inEntity.Model();
			outEntity->HashName = outEntity->Type == EntityType::PROP ? get_prop_model_label(outEntity_model)
				: (outEntity->Type == EntityType::PED ? get_ped_model_label(outEntity_model, true)
					: get_vehicle_model_label(outEntity_model, true));
			if (outEntity->HashName.length() == 0) outEntity->HashName = int_to_hexstring(outEntity_model.hash, true);
			outEntity->Dynamic = !outEntity->Handle.IsPositionFrozen();//outEntity->Type == EntityType::PED || outEntity->Type == EntityType::VEHICLE;
			//outEntity->LastAnimation.dict.clear();
			//outEntity->LastAnimation.name.clear();
			outEntity->IsStill = false;

			auto idindb = EntityManagement::GetEntityIndexInDb(*outEntity);
			if (idindb >= 0)
			{
				delete outEntity;
				outEntity = &Databases::EntityDb[idindb];
				return true; // Is in db
			}
			else
			{
				return false; // Is not in db
			}
		}
		SpoonerEntity GetEntityPtrValue(GTAentity& entity)
		{
			SpoonerEntity* eifoc;
			bool isAlreadyInDb = SpoonerMode::GetEntityPtr(entity, eifoc);
			SpoonerEntity toReturn = *eifoc;
			if (!isAlreadyInDb)
				delete eifoc;
			return toReturn;
		}
		inline void SetAsSelectedEntity(GTAentity& entity)
		{
			SpoonerEntity* eifoc;
			bool isAlreadyInDb = SpoonerMode::GetEntityPtr(entity, eifoc);
			SelectedEntity = *eifoc;
			SelectedEntity.Handle.RequestControl();
			if (!isAlreadyInDb)
				delete eifoc;
		}
		namespace Game
		{
			GTAplayer Player()
			{
				return PLAYER::PLAYER_ID();
			}
			GTAplayer Player(int index)
			{
				return GTAplayer(index);
			}
			GTAped PlayerPed()
			{
				return PLAYER::PLAYER_PED_ID();
			}
			GTAped PlayerPed(int index)
			{
				return PLAYER::GET_PLAYER_PED(index);
			}
		}
		inline void CamTick()
		{
			if (UI::IS_PAUSE_MENU_ACTIVE())
				return;

			GTAplayer myPlayer = Game::Player();
			GTAped myPed = Game::PlayerPed();

			Camera2& freeCam = SpoonerMode::spoonerModeCamera;
			float& freeCamCamDistance = SpoonerMode::spoonerModeCameraCamDistance;

			if (SpoonerMode::bEnabled)
			{
				UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
//
//				//if (setting)
				{
					UINT totalNumProps = 0, totalNumPeds = 0, totalNumVehicles = 0;
					UINT totalNumEntities = (UINT)Databases::EntityDb.size();
					for (auto& eee : Databases::EntityDb)
					{
						switch (eee.Type)
						{
						case EntityType::PROP: totalNumProps++; break;
						case EntityType::PED: totalNumPeds++; break;
						case EntityType::VEHICLE: totalNumVehicles++; break;
						}
					}
					//bool bRightJus = get_xcoord_at_menu_leftEdge(0.0f, false) < 0.5f; // left edge of menu is on the left of the centre of the screen
					//float infoX = bRightJus ? 0.94f : 0.008f;
					//Game::Print::setupdraw(GTAfont::Arial, Vector2(0.37f, 0.37f), false, bRightJus, false);
					//Game::Print::drawstring("Total Entities Spawned: " + std::to_string(totalNumEntities), infoX, 0.064f);
					//Game::Print::setupdraw(GTAfont::Arial, Vector2(0.37f, 0.37f), false, bRightJus, false);
					//Game::Print::drawstring("Objects Spawned: " + std::to_string(totalNumProps), infoX, 0.094f);
					//Game::Print::setupdraw(GTAfont::Arial, Vector2(0.37f, 0.37f), false, bRightJus, false);
					//Game::Print::drawstring("Peds Spawned: " + std::to_string(totalNumPeds), infoX, 0.124f);
					//Game::Print::setupdraw(GTAfont::Arial, Vector2(0.37f, 0.37f), false, bRightJus, false);
					//Game::Print::drawstring("Vehicles Spawned: " + std::to_string(totalNumVehicles), infoX, 0.154f);
				}

				if (!freeCam.Exists())
				{
					Vector31& myPos = myPed.Position_get();
					freeCam = World::CreateCamera(myPos + Vector31(0, 0, 2.8f), Vector31(0, 0, myPed.Rotation_get().z1), 73.f);
					freeCam.SetActive(false);
				}
				if (!freeCam.IsActive())
				{
					freeCam.SetActive(true);
					Camera2::RenderScriptCams(true);
				}
				myPlayer.SetControl(false, 0);
				CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(0);
				CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(2);
				CONTROLS::ENABLE_CONTROL_ACTION(2, INPUT_FRONTEND_PAUSE, true);
				CONTROLS::ENABLE_CONTROL_ACTION(2, INPUT_FRONTEND_PAUSE_ALTERNATE, true);

				Vector31 nextOffset;
				Vector31 nextRot;

				Vector31& coordInFrontOfCam = freeCam.RaycastForCoord(Vector21(0.0f, 0.0f), 0, 160.0f, 3.0f);
				GTAentity& entityInFrontOfCam = freeCam.RaycastForEntity(Vector21(0.0f, 0.0f), 0, 160.0f);

				if (Menu3::bit_controller) // If controller
				{
					float movementSensitivity = Settings::CameraMovementSensitivityGamepad;
					//if (IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LS)) movementSensitivity += 1.36f * movementSensitivity;

					nextOffset.x1 = CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_MOVE_LR) * movementSensitivity;
					nextOffset.y1 = -CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_MOVE_UD) * movementSensitivity;

					float rotationSensitivity = Settings::CameraRotationSensitivityGamepad;
					nextRot.z1 = -CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_LOOK_LR) * rotationSensitivity;
					nextRot.x1 = -CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_LOOK_UD) * rotationSensitivity;
					nextRot.y1 = !CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RB) ? (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LB) ? -2.0f : 0.0f) : 2.0f;

					if (!bIsSomethingHeld || spoonerModeMode == eSpoonerModeMode::GroundEase)
					{
						if (!bIsSomethingHeld)
							nextRot.y1 = -freeCam.Rotation_get().y1; // Roll should be 0 when no entity is held
						if (nextOffset.x1 || nextOffset.y1)
							freeCam.Position_set(freeCam.GetOffsetInWorldCoords(nextOffset.x1, nextOffset.y1, 0));

						/*if (!bIsSomethingHeld && Settings::bShowModelPreviews)
							SpoonerMode::SpawnModelPreview();*/
					}
					if (!nextRot.IsZero())
					{
						Vector31& nextRotFinal = freeCam.Rotation_get() + nextRot;
						//float fcrXfinal = fmod(nextRotFinal.x, 360.0f); // What if -10/350/710?
						//if (fcrXfinal > -10.0f && fcrXfinal < 0.0f)
						//	nextRotFinal.x = -10.0f;
						//else if (fcrXfinal >= 0.0f && fcrXfinal < 10.0f)
						//	nextRotFinal.x = 10.0f;
						switch (spoonerModeMode)
						{
						case eSpoonerModeMode::GroundEase:
							nextRotFinal.y1 = 0.0f;
							break;
						case eSpoonerModeMode::Precision:
							break;
						}
						freeCam.Rotation_set(nextRotFinal);
					}

					/*if (Menu::currentsub == SUB::CLOSED)
					{
						Menu::add_IB(INPUT_VEH_EXIT, "Open main menu");
						if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_VEH_EXIT))
						{
							memset(Menu::currentsub_ar, 0, sizeof(Menu::currentsub_ar));
							memset(Menu::currentop_ar, 0, sizeof(Menu::currentop_ar));
							Menu::currentsub_ar[0] = SUB::MAINMENU;
							Menu::currentop_ar[0] = 1;
							Menu::currentsub_ar_index = 0;
							Menu::SetSub_new(SUB::SPOONER_MAIN);
							Menu::currentop = 2;
						}*/

						/*if (!bIsSomethingHeld)
						{
							Menu::add_IB(INPUT_FRONTEND_DOWN, "Place Marker");
							if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_DOWN))
							{
								auto newMarkerPtr = MarkerManagement::AddMarker(coordInFrontOfCam, Vector3(0, 0, freeCam.Rotation_get().z));
								if (newMarkerPtr != nullptr)
								{
									newMarkerPtr->m_position.z += (newMarkerPtr->m_scale / 2);
									SelectedMarker = newMarkerPtr;
									memset(Menu::currentsub_ar, 0, sizeof(Menu::currentsub_ar));
									memset(Menu::currentop_ar, 0, sizeof(Menu::currentop_ar));
									Menu::currentsub_ar[0] = SUB::MAINMENU;
									Menu::currentop_ar[0] = 1;
									Menu::currentsub_ar_index = 0;
									Menu::SetSub_new(SUB::SPOONER_MANAGEMARKERS_INMARKER);
								}
							}
						}*/


					if (entityInFrontOfCam.Exists() || bIsSomethingHeld)
					{
						GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.02f, 0.002f, 0, 255, 0, 255);
						GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.001f, 0.03f, 0, 255, 0, 255);

						GTAentity* currentEntPtr = bIsSomethingHeld ? &SelectedEntity.Handle : &entityInFrontOfCam;
						GTAentity& currentEnt = *currentEntPtr;

						/*auto indexInDb = EntityManagement::GetEntityIndexInDb(currentEnt);*/
						/*bool isInDb = indexInDb >= 0;*/

						if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LT))
						{
							if (!bIsSomethingHeld)
							{
								bIsSomethingHeld = true;
								/*SpoonerMode::SetAsSelectedEntity(currentEnt);*/

								switch (spoonerModeMode)
								{
								case eSpoonerModeMode::GroundEase:
									freeCam.PointAt(SelectedEntity.Handle);
									freeCam.StopPointing();
									bHeldEntityHasCollision = SelectedEntity.Handle.IsCollisionEnabled_get();
									ENTITY::SET_ENTITY_COLLISION(SelectedEntity.Handle.Handle(), false, false);
									break;
								case eSpoonerModeMode::Precision:
									bHeldEntityHasCollision = SelectedEntity.Handle.IsCollisionEnabled_get();
									freeCam.Rotation_set(SelectedEntity.Handle.Rotation_get());
									break;
								}
							}

							GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 255, 128, 0, 255);

							SelectedEntity.Handle.RequestControl();
							Vector31& r_sl = SelectedEntity.Handle.Rotation_get();
							Vector31& r_fc = freeCam.Rotation_get();
							switch (spoonerModeMode)
							{
							case eSpoonerModeMode::GroundEase:
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RS))
									r_sl.x1 -= 2.0f; // Decrease pitch RS
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LS))
									r_sl.x1 += 2.0f; // Increase pitch LS
								r_sl.y1 += nextRot.y1; // Increase/Decrease pitch using RB/LB
								r_sl.z1 += nextRot.z1; // Relative yaw kept constant
								SelectedEntity.Handle.Rotation_set(r_sl);
								break;
							case eSpoonerModeMode::Precision:
								SelectedEntity.Handle.Rotation_set(r_fc);
								break;
							}
							r_sl = SelectedEntity.Handle.Rotation_get(); // To get -180 to 180 values

							/*ModelDimensions& md_SelectedEntity = SelectedEntity.Handle.ModelDimensions();*/
							switch (spoonerModeMode)
							{
							//case eSpoonerModeMode::GroundEase:
							//{
							//	//Vector3& geSep = SelectedEntity.Handle.Position_get();
							//	//auto& geGroundRay = RaycastResult::Raycast(geSep, Vector3::WorldDown(), max(max(md_SelectedEntity.Dim1.x, md_SelectedEntity.Dim2.x), max(max(md_SelectedEntity.Dim1.y, md_SelectedEntity.Dim2.y), max(md_SelectedEntity.Dim1.z, md_SelectedEntity.Dim2.z))) + 2.0f, IntersectOptions::Everything, SelectedEntity.Handle);
							//	/*float geGroundZ = md_SelectedEntity.Dim1.z;*/
							//	//if (geGroundRay.DidHitAnything())
							//	//{
							//	//geGroundZ = geGroundRay.HitCoords().DistanceTo(geSep);
							//	//}
							//	if (abs(r_sl.x1) > 150.0f || abs(r_sl.y1) > 150.0f)
							//		geGroundZ = md_SelectedEntity.Dim2.z;
							//	else if (abs(r_sl.x1) > 70.0f && abs(r_sl.y1) > 70.0f)
							//		geGroundZ = (md_SelectedEntity.Dim1.y + md_SelectedEntity.Dim1.x) / 2;
							//	else if (abs(r_sl.x1) > 70.0f)
							//		geGroundZ = md_SelectedEntity.Dim1.y;
							//	else if (abs(r_sl.y1) > 70.0f)
							//		geGroundZ = md_SelectedEntity.Dim1.x;
							//	SelectedEntity.Handle.Position_set(spoonerModeCamera.RaycastForCoord(Vector21(0.0f, 0.0f), SelectedEntity.Handle, 90.0f, 15.0f + md_SelectedEntity.Dim2.y) + Vector31(0, 0, geGroundZ));
							//	break;
							//}
							case eSpoonerModeMode::Precision:
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RS))
									freeCamCamDistance -= 0.1f; // Zoom in RS
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LS))
									freeCamCamDistance += 0.1f; // Zoom out LS
								/*Vector31 attachmentOffset = { 0.0f, -md_SelectedEntity.Dim2.y - freeCamCamDistance, 0.0f };*/
								/*freeCam.AttachTo(SelectedEntity.Handle, attachmentOffset);
								SelectedEntity.Handle.Position_set(SelectedEntity.Handle.GetOffsetInWorldCoords(nextOffset));*/
								if (Settings::bFreezeEntityWhenMovingIt)
									SelectedEntity.Handle.FreezePosition(Settings::bFreezeEntityWhenMovingIt);
								break;
							}

							//if (Menu::currentsub == SUB::CLOSED)
							//{
							//	Menu::add_IB(INPUT_FRONTEND_RT, "Open property menu");
							//	switch (spoonerModeMode)
							//	{
							//	case eSpoonerModeMode::GroundEase:
							//		Menu::add_IB(INPUT_FRONTEND_RS, "");
							//		Menu::add_IB(INPUT_FRONTEND_LS, "Adjust pitch rotation");
							//		break;
							//	case eSpoonerModeMode::Precision:
							//		Menu::add_IB(INPUT_FRONTEND_RS, "");
							//		Menu::add_IB(INPUT_FRONTEND_LS, "Zoom camera in/out");
							//		break;
							//	}
							//	Menu::add_IB(INPUT_FRONTEND_RB, "");
							//	Menu::add_IB(INPUT_FRONTEND_LB, "Adjust roll rotation");
							//	Menu::add_IB(INPUT_FRONTEND_RIGHT, "Copy (and add to DB)");
							//	Menu::add_IB(INPUT_FRONTEND_LEFT, "Delete");
							//	if (!isInDb)
							//	{
							//		Menu::add_IB(INPUT_FRONTEND_UP, "Add to Database");
							//		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_UP))
							//		{
							//			EntityManagement::AddEntityToDb(SelectedEntity);
							//		}
							//	}

							//	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RIGHT))
							//	{
							//		SpoonerEntity& copiedEntity = EntityManagement::CopyEntity(SelectedEntity, isInDb, true, Submenus::_copyEntTexterValue);
							//		//EntityManagement::AddEntityToDb(copiedEntity);
							//		SelectedEntity = copiedEntity;
							//	}
							//	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LEFT))
							//	{
							//		SelectedEntity.Handle.RequestControl(600);
							//		EntityManagement::DeleteEntity(SelectedEntity);
							//		bIsSomethingHeld = false;
							//	}
							//}
						}
						else
						{
							if (bIsSomethingHeld)
							{
								switch (spoonerModeMode)
								{
								case eSpoonerModeMode::GroundEase:
									ENTITY::SET_ENTITY_COLLISION(SelectedEntity.Handle.Handle(), bHeldEntityHasCollision, true);
									freeCam.Detach(); // Just in case
									break;
								case eSpoonerModeMode::Precision:
									ENTITY::SET_ENTITY_COLLISION(SelectedEntity.Handle.Handle(), bHeldEntityHasCollision, true);
									freeCam.Detach();
									break;
								}
							}
							bIsSomethingHeld = false;

							//if (Menu::currentsub == SUB::CLOSED)
							//{
							//	Menu::add_IB(INPUT_FRONTEND_RT, "Open property menu");
							//	Menu::add_IB(INPUT_FRONTEND_LT, "Move entity around (hold)");
							//	Menu::add_IB(INPUT_FRONTEND_RIGHT, "Copy (and add to DB)");
							//	Menu::add_IB(INPUT_FRONTEND_LEFT, "Delete");
							//	if (!isInDb)
							//	{
							//		Menu::add_IB(INPUT_FRONTEND_UP, "Add to Database");
							//		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_UP))
							//		{
							//			EntityManagement::AddEntityToDb(GetEntityPtrValue(currentEnt));
							//		}
							//	}

							//	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RIGHT))
							//	{
							//		SpoonerEntity& copiedEntity = EntityManagement::CopyEntity(GetEntityPtrValue(currentEnt), isInDb, true, Submenus::_copyEntTexterValue);
							//		//EntityManagement::AddEntityToDb(copiedEntity);
							//		SelectedEntity = copiedEntity;
							//	}
							//	else if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LEFT))
							//	{
							//		auto& entPtrVal = GetEntityPtrValue(currentEnt);
							//		entPtrVal.Handle.RequestControl(600);
							//		EntityManagement::DeleteEntity(entPtrVal);
							//		bIsSomethingHeld = false;
							//	}
							}
						}
					//	if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RT))
					//	{
					//		/*if (!bIsSomethingHeld)
					//		{
					//			SpoonerMode::SetAsSelectedEntity(currentEnt);
					//		}*/
					//		/*memset(Menu::currentsub_ar, 0, sizeof(Menu::currentsub_ar));
					//		memset(Menu::currentop_ar, 0, sizeof(Menu::currentop_ar));
					//		Menu::currentsub_ar[0] = SUB::MAINMENU;
					//		Menu::currentop_ar[0] = 1;
					//		Menu::currentsub_ar_index = 0;
					//		Menu::SetSub_new(SUB::SPOONER_SELECTEDENTITYOPS);*/
					//	/*}*/
					//}
					/*else
					{
					GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.02f, 0.002f, 255, 255, 255, 255);
					GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.001f, 0.03f, 255, 255, 255, 255);
					}*/
				}
				else // If keyboard + mouse
				{
					float movementSensitivity = Settings::CameraMovementSensitivityKeyboard;
					if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_SPRINT))
						movementSensitivity = 4.0f * movementSensitivity;

					nextOffset.x1 = CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_MOVE_LR) * movementSensitivity;
					nextOffset.y1 = -CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_MOVE_UD) * movementSensitivity;
					nextOffset.z1 = IsKeyDown(VirtualKey::X) ? movementSensitivity / 2 : IsKeyDown(VirtualKey::Z) ? -movementSensitivity / 2 : 0.0f;

					float rotationSensitivity = Settings::CameraRotationSensitivityMouse;
					nextRot.z1 = -CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_LOOK_LR) * rotationSensitivity;
					nextRot.x1 = -CONTROLS::GET_DISABLED_CONTROL_NORMAL(0, INPUT_LOOK_UD) * rotationSensitivity;
					nextRot.y1 = !CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_PARACHUTE_BRAKE_RIGHT) ? (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_PARACHUTE_BRAKE_LEFT) ? -2.0f : 0.0f) : 2.0f;

					if (!bIsSomethingHeld || spoonerModeMode == eSpoonerModeMode::GroundEase)
					{
						if (!bIsSomethingHeld)
							nextRot.y1 = -freeCam.Rotation_get().y1; // Roll should be 0 when no entity is held
						if (!nextOffset.IsZero())
							freeCam.Position_set(freeCam.GetOffsetInWorldCoords(nextOffset));

						/*if (!bIsSomethingHeld && Settings::bShowModelPreviews)
							SpoonerMode::SpawnModelPreview();*/
					}
					if (!nextRot.IsZero())
					{
						Vector31& nextRotFinal = freeCam.Rotation_get() + nextRot;
						//float fcrXfinal = fmod(nextRotFinal.x, 360.0f); // What if -10/350/710?
						//if (fcrXfinal > -10.0f && fcrXfinal < 0.0f)
						//	nextRotFinal.x = -10.0f;
						//else if (fcrXfinal >= 0.0f && fcrXfinal < 10.0f)
						//	nextRotFinal.x = 10.0f;
						switch (spoonerModeMode)
						{
						case eSpoonerModeMode::GroundEase:
							nextRotFinal.y1 = 0.0f;
							break;
						case eSpoonerModeMode::Precision:
							break;
						}
						freeCam.Rotation_set(nextRotFinal);
					}

					/*if (Menu::currentsub == SUB::CLOSED)
					{
						Menu::add_IB(INPUT_VEH_EXIT, "Open main menu");
						if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_VEH_EXIT))
						{
							memset(Menu::currentsub_ar, 0, sizeof(Menu::currentsub_ar));
							memset(Menu::currentop_ar, 0, sizeof(Menu::currentop_ar));
							Menu::currentsub_ar[0] = SUB::MAINMENU;
							Menu::currentop_ar[0] = 1;
							Menu::currentsub_ar_index = 0;
							Menu::SetSub_new(SUB::SPOONER_MAIN);
							Menu::currentop = 2;
						}

						if (!bIsSomethingHeld)
						{
							Menu::add_IB(VirtualKey::M, "Place Marker");
							if (IsKeyJustUp(VirtualKey::M))
							{
								auto newMarkerPtr = MarkerManagement::AddMarker(coordInFrontOfCam, Vector3(0, 0, freeCam.Rotation_get().z));
								if (newMarkerPtr != nullptr)
								{
									newMarkerPtr->m_position.z += (newMarkerPtr->m_scale / 2);
									SelectedMarker = newMarkerPtr;
									memset(Menu::currentsub_ar, 0, sizeof(Menu::currentsub_ar));
									memset(Menu::currentop_ar, 0, sizeof(Menu::currentop_ar));
									Menu::currentsub_ar[0] = SUB::MAINMENU;
									Menu::currentop_ar[0] = 1;
									Menu::currentsub_ar_index = 0;
									Menu::SetSub_new(SUB::SPOONER_MANAGEMARKERS_INMARKER);
								}
							}
						}
					}*/

					if (entityInFrontOfCam.Exists() || bIsSomethingHeld)
					{
						GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.02f, 0.002f, 0, 255, 0, 255);
						GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.001f, 0.03f, 0, 255, 0, 255);

						GTAentity* currentEntPtr = bIsSomethingHeld ? &SelectedEntity.Handle : &entityInFrontOfCam;
						GTAentity& currentEnt = *currentEntPtr;

						/*auto indexInDb = EntityManagement::GetEntityIndexInDb(currentEnt);
						bool isInDb = indexInDb >= 0;*/

						if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_CURSOR_ACCEPT))
						{
							if (!bIsSomethingHeld)
							{
								bIsSomethingHeld = true;
								/*SpoonerMode::SetAsSelectedEntity(currentEnt);*/

								switch (spoonerModeMode)
								{
								case eSpoonerModeMode::GroundEase:
									freeCam.PointAt(SelectedEntity.Handle);
									freeCam.StopPointing();
									bHeldEntityHasCollision = SelectedEntity.Handle.IsCollisionEnabled_get();
									ENTITY::SET_ENTITY_COLLISION(SelectedEntity.Handle.Handle(), false, false);
									break;
								case eSpoonerModeMode::Precision:
									bHeldEntityHasCollision = SelectedEntity.Handle.IsCollisionEnabled_get();
									freeCam.Rotation_set(SelectedEntity.Handle.Rotation_get());
									break;
								}
							}

							GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 255, 128, 0, 255);

							SelectedEntity.Handle.RequestControl();
							Vector31& r_sl = SelectedEntity.Handle.Rotation_get();
							Vector31& r_fc = freeCam.Rotation_get();
							switch (spoonerModeMode)
							{
							case eSpoonerModeMode::GroundEase:
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_CURSOR_SCROLL_DOWN))
									r_sl.x1 -= 2.0f; // Decrease pitch ScrollDown
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_CURSOR_SCROLL_UP))
									r_sl.x1 += 2.0f; // Increase pitch ScrollUp
								r_sl.y1 += nextRot.y1; // Increase/Decrease pitch using RB/LB
								r_sl.z1 += nextRot.z1; // Relative yaw kept constant
								SelectedEntity.Handle.Rotation_set(r_sl);
								break;
							case eSpoonerModeMode::Precision:
								SelectedEntity.Handle.Rotation_set(r_fc);
								break;
							}
							r_sl = SelectedEntity.Handle.Rotation_get(); // To get -180 to 180 values

							/*ModelDimensions& md_SelectedEntity = SelectedEntity.Handle.ModelDimensions();*/
							switch (spoonerModeMode)
							{
							//case eSpoonerModeMode::GroundEase:
							//{
							//	//Vector3& geSep = SelectedEntity.Handle.Position_get();
							//	//auto& geGroundRay = RaycastResult::Raycast(geSep, Vector3::WorldDown(), max(max(md_SelectedEntity.Dim1.x, md_SelectedEntity.Dim2.x), max(max(md_SelectedEntity.Dim1.y, md_SelectedEntity.Dim2.y), max(md_SelectedEntity.Dim1.z, md_SelectedEntity.Dim2.z))) + 2.0f, IntersectOptions::Everything, SelectedEntity.Handle);
							//	
							//	/*float geGroundZ = md_SelectedEntity.Dim1.z;*/

							//	//if (geGroundRay.DidHitAnything())
							//	//{
							//	//geGroundZ = geGroundRay.HitCoords().DistanceTo(geSep);
							//	//}
							//	//if (abs(r_sl.x1) > 150.0f || abs(r_sl.y1) > 150.0f)
							//	//	/*geGroundZ = md_SelectedEntity.Dim2.z;*/
							//	//else if (abs(r_sl.x1) > 70.0f && abs(r_sl.y1) > 70.0f)
							//	//	geGroundZ = (md_SelectedEntity.Dim1.y + md_SelectedEntity.Dim1.x) / 2;
							//	//else if (abs(r_sl.x1) > 70.0f)
							//	//	geGroundZ = md_SelectedEntity.Dim1.y;
							//	//else if (abs(r_sl.y1) > 70.0f)
							//	//	geGroundZ = md_SelectedEntity.Dim1.x;
							//	SelectedEntity.Handle.Position_set(spoonerModeCamera.RaycastForCoord(Vector21(0.0f, 0.0f), SelectedEntity.Handle, 90.0f, 15.0f + md_SelectedEntity.Dim2.y) + Vector31(0, 0, geGroundZ));
							//	break;
							//}
							case eSpoonerModeMode::Precision:
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_CURSOR_SCROLL_UP))
									freeCamCamDistance -= 0.23f; // Zoom in RS
								if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_CURSOR_SCROLL_DOWN))
									freeCamCamDistance += 0.23f; // Zoom out LS
								/*Vector31 attachmentOffset = { 0.0f, -md_SelectedEntity.Dim2.y - freeCamCamDistance, 0.0f };*/
								/*freeCam.AttachTo(SelectedEntity.Handle, attachmentOffset);
								SelectedEntity.Handle.Position_set(SelectedEntity.Handle.GetOffsetInWorldCoords(nextOffset));*/
								if (Settings::bFreezeEntityWhenMovingIt)
									SelectedEntity.Handle.FreezePosition(Settings::bFreezeEntityWhenMovingIt);
								break;
							}

							//if (Menu::currentsub == SUB::CLOSED)
							//{
							//	Menu::add_IB(INPUT_CURSOR_CANCEL, "Open property menu");
							//	switch (spoonerModeMode)
							//	{
							//	case eSpoonerModeMode::GroundEase:
							//		Menu::add_IB(INPUT_CURSOR_SCROLL_DOWN, "");
							//		Menu::add_IB(INPUT_CURSOR_SCROLL_UP, "Adjust pitch rotation");
							//		break;
							//	case eSpoonerModeMode::Precision:
							//		Menu::add_IB(INPUT_CURSOR_SCROLL_DOWN, "");
							//		Menu::add_IB(INPUT_CURSOR_SCROLL_UP, "Zoom camera in/out");
							//		Menu::add_IB(VirtualKey::Z, "");
							//		Menu::add_IB(VirtualKey::X, "Ascend/Descend");
							//		break;
							//	}
							//	Menu::add_IB(INPUT_PARACHUTE_BRAKE_RIGHT, "");
							//	Menu::add_IB(INPUT_PARACHUTE_BRAKE_LEFT, "Adjust roll rotation");
							//	Menu::add_IB(INPUT_LOOK_BEHIND, "Copy (and add to DB)");
							//	Menu::add_IB(INPUT_CREATOR_DELETE, "Delete");
							//	if (!isInDb)
							//	{
							//		Menu::add_IB(INPUT_FRONTEND_UP, "Add to Database");
							//		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_UP))
							//		{
							//			EntityManagement::AddEntityToDb(SelectedEntity);
							//		}
							//	}

							//	if (IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_LOOK_BEHIND))
							//	{
							//		SpoonerEntity& copiedEntity = EntityManagement::CopyEntity(SelectedEntity, isInDb, true, Submenus::_copyEntTexterValue);
							//		//EntityManagement::AddEntityToDb(copiedEntity);
							//		SelectedEntity = copiedEntity;
							//	}
							//	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_CREATOR_DELETE))
							//	{
							//		SelectedEntity.Handle.RequestControl(600);
							//		EntityManagement::DeleteEntity(SelectedEntity);
							//		bIsSomethingHeld = false;
							//	}
							//}
						}
						else
						{
							if (bIsSomethingHeld)
							{
								switch (spoonerModeMode)
								{
								case eSpoonerModeMode::GroundEase:
									ENTITY::SET_ENTITY_COLLISION(SelectedEntity.Handle.Handle(), bHeldEntityHasCollision, true);
									freeCam.Detach(); // Just in case
									break;
								case eSpoonerModeMode::Precision:
									ENTITY::SET_ENTITY_COLLISION(SelectedEntity.Handle.Handle(), bHeldEntityHasCollision, true);
									freeCam.Detach();
									break;
								}
							}
							bIsSomethingHeld = false;

							//if (Menu::currentsub == SUB::CLOSED)
							//{
							//	Menu::add_IB(INPUT_CURSOR_CANCEL, "Open property menu");
							//	Menu::add_IB(INPUT_CURSOR_ACCEPT, "Move entity around (hold)");
							//	Menu::add_IB(INPUT_LOOK_BEHIND, "Copy (and add to DB)");
							//	Menu::add_IB(INPUT_CREATOR_DELETE, "Delete");
							//	if (!isInDb)
							//	{
							//		Menu::add_IB(INPUT_FRONTEND_UP, "Add to Database");
							//		if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_UP))
							//		{
							//			EntityManagement::AddEntityToDb(GetEntityPtrValue(currentEnt));
							//		}
							//	}

							//	if (IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_LOOK_BEHIND))
							//	{
							//		SpoonerEntity& copiedEntity = EntityManagement::CopyEntity(GetEntityPtrValue(currentEnt), isInDb, true, Submenus::_copyEntTexterValue);
							//		//EntityManagement::AddEntityToDb(copiedEntity);
							//		SelectedEntity = copiedEntity;
							//	}
							//	else if (IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_CREATOR_DELETE))
							//	{
							//		auto& entPtrVal = GetEntityPtrValue(currentEnt);
							//		entPtrVal.Handle.RequestControl(600);
							//		EntityManagement::DeleteEntity(entPtrVal);
							//		bIsSomethingHeld = false;
							//	}
							//}
						}
						if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_CURSOR_CANCEL))
						{
							/*if (!bIsSomethingHeld)
							{
								SpoonerMode::SetAsSelectedEntity(currentEnt);
							}*/
							/*memset(Menu::currentsub_ar, 0, sizeof(Menu::currentsub_ar));
							memset(Menu::currentop_ar, 0, sizeof(Menu::currentop_ar));
							Menu::currentsub_ar[0] = SUB::MAINMENU;
							Menu::currentop_ar[0] = 1;
							Menu::currentsub_ar_index = 0;
							Menu::SetSub_new(SUB::SPOONER_SELECTEDENTITYOPS);*/
						}
					}
					else
					{
						GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.02f, 0.002f, 255, 255, 255, 255);
						GRAPHICS::DRAW_RECT(0.5f, 0.5f, 0.001f, 0.03f, 255, 255, 255, 255);
					}
				}
			}
			else		
			{
				if (freeCam.Handle() != 0)
				{
					//myPed.Position_set(freeCam.Position_get() - Vector3(0, 0, 5.0f));
					//myPed.PlaceOnGround();

					myPlayer.SetControl(true, 0);

					bIsSomethingHeld = false;
					bHeldEntityHasCollision = true;

					freeCam.SetActive(false);
					freeCam.Destroy();
					World::RenderingCamera_set(0);
					freeCam = Camera2();
				}
			}
		}
		void Tick()
		{
			if (SpoonerMode::IsHotkeyPressed())
				SpoonerMode::Toggle(); // Hotkey (when mayo closed)
//
			CamTick();
//
			if (Settings::bShowBoxAroundSelectedEntity)
				EntityManagement::ShowBoxAroundEntity(SelectedEntity.Handle);
//
			for (auto& ent : Databases::EntityDb)
			{
				if (ent.Handle.Exists())
					ent.TaskSequence.Tick(reinterpret_cast<void*>(&ent)); //ent.TaskSequence.Tick((GTAped)ent.Handle);
			}

			/*if (!Databases::MarkerDb.empty())
				MarkerManagement::DrawAll();*/
		}

		void TurnOn()
		{
			if (!g_menuNotOpenedYet)
			{
				SpoonerMode::bEnabled = true;
				/*if (Menu::currentsub != SUB::CLOSED)
					Game::Print::PrintBottomLeft("~b~Note:~s~ Spooner Mode instructions only appear when Menyoo is closed.");*/
			}
			/*else
			{
				Game::Print::PrintBottomCentre("~r~Error:~s~ Menu not opened yet.");
			}*/
		}
		void TurnOff()
		{
			SpoonerMode::bEnabled = false;
			auto& info = ModelPreviewInfo;
			for (auto& it = info.previousEntities.begin(); it != info.previousEntities.end();)
			{
				GTAentity e = *it;
				e.RequestControl(600);
				if (e != info.entity)
					e.Delete(true);
				++it;
			}
			info.previousEntities.clear();
			if (info.entity != 0)
			{
				info.entityType = EntityType::ALL;
				SpoonerMode::SpawnModelPreview();
			}
		}
		void Toggle()
		{
			SpoonerMode::bEnabled ? SpoonerMode::TurnOff() : SpoonerMode::TurnOn();
		}
	}
}



