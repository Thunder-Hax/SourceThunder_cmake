#pragma once

#include "types.h" //RGBA/RgbS

#include "SpoonerSettings.h"

#include <string>
#include <unordered_set>

typedef unsigned __int8 UINT8;
typedef unsigned int UINT;
enum class EntityType : UINT8;
class Vector31;
class GTAentity;
namespace GTAmodel {
	class Model;
}

namespace Spooner
{
	class SpoonerEntity;

	namespace EntityManagement
	{
		//UINT GetNumberOfEntitiesSpawned(const EntityType& type);

		int GetEntityIndexInDb(const GTAentity& entity);
		int GetEntityIndexInDb(const SpoonerEntity& ent);
		//void AddEntityToDb(SpoonerEntity& ent, bool missionEnt = Settings::bAddToDbAsMissionEntities);
		void RemoveEntityFromDb(const SpoonerEntity& ent);

		//void ClearDb();
		void DeleteEntity(SpoonerEntity& ent);
		//void DeleteAllEntitiesInDb();
		//void DeleteAllEntitiesOfTypeInDb(const EntityType& targetType);
		//inline void DeleteAllPropsInDb();
		//inline void DeleteAllPedsInDb();
		//inline void DeleteAllVehiclesInDb();
		//void DeleteInvalidEntitiesInDb();

		//void DeleteAllEntitiesInWorld();
		//void DeleteAllPropsInWorld();
		//void DeleteAllPedsInWorld();
		//void DeleteAllVehiclesInWorld();

		//SpoonerEntity AddProp(const GTAmodel::Model& model, const std::string& name, bool unloadModel = true);
		//SpoonerEntity AddPed(const GTAmodel::Model& model, const std::string& name, bool unloadModel = true);
		//SpoonerEntity AddVehicle(const GTAmodel::Model& model, const std::string& name, bool unloadModel = true);
		//SpoonerEntity AddEntityOfType(const EntityType& type, const GTAmodel::Model& model, const std::string& name);

		//SpoonerEntity CopyEntity(SpoonerEntity& orig, bool isInDb, bool addToDb = true, UINT8 copyAttachments = 0, bool unloadModel = true, UINT8 currAtir = 0);

		void DetachEntity(SpoonerEntity& ent);
		bool GetEntityThisEntityIsAttachedTo(GTAentity& from, GTAentity& to);
		extern std::unordered_set<Vehicle> g_vehWheelsInvisForRussian;
		extern std::map<Vehicle, float> g_multList_rpm;
		extern std::map<Vehicle, float> g_multList_torque;
		extern std::map<Vehicle, float> g_multList_maxSpeed;
		extern std::map<Vehicle, float> g_multList_headlights;
		void set_vehicle_wheels_invisible(GTAvehicle vehicle, bool enable);
		bool are_vehicle_wheels_invisible(const GTAvehicle& vehicle);
		void AttachEntity(SpoonerEntity& ent, GTAentity to, int boneIndex, const Vector31& offset, const Vector31& rotation);
		//void AttachEntityInit(SpoonerEntity& ent, GTAentity to, bool bAttachWithRelativePosRot = false);

		//// Keyboard input
		//SpoonerEntity InputEntityIntoDb(const EntityType& type);

		void ShowBoxAroundEntity(const GTAentity& ent, bool showPoly = true, RgbS colour = { 0, 255, 255 });
		/*void ShowArrowAboveEntity(const GTAentity& ent, RGBA1 colour = { 0, 255, 255, 200 });
		void DrawRadiusDisplayingMarker(const Vector31& pos, float radius, RGBA1 colour = { 0, 255, 0, 130 });*/
	}

}



