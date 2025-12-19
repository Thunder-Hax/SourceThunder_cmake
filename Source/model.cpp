#include "stdafx.h"
#include "model.h"

//#include "..\macros.h"

#include "GTAmath.h"
#include "natives.h"
#include "enums.h"
#include "GTAmemory.h"
#include "StringManip.h"

#include <string>
#include <Windows.h> //GetTickCount

Hash MODEL::GET_HASH_KEY(const std::string& value)
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

namespace GTAmodel
{
	ModelDimensions::ModelDimensions()
	{
	}
	ModelDimensions::ModelDimensions(const Vector31& d1, const Vector31& d2) : Dim1(d1), Dim2(d2)
	{
	}


	Model::Model() : hash(0)
	{
	}
	Model::Model(const std::string& name) : hash(MODEL::GET_HASH_KEY(name))
	{
	}
	Model::Model(Hash newHash) : hash(newHash)
	{
	}
	Model::Model(VehicleHash newHash) : hash(newHash)
	{
	}

	bool operator == (const Model& left, const Model& right)
	{
		return (left.hash == right.hash);
	}
	bool operator != (const Model& left, const Model& right)
	{
		return (left.hash != right.hash);
	}
	bool Model::Equals(const Model& right) const
	{
		return (this->hash == right.hash);
	}
	Model& Model::operator = (const Model& right)
	{
		this->hash = right.hash;
		return *this;
	}

	// Zorg93
	UINT64 Model::MemoryAddress() const
	{
		static UINT64 _gtaModelMemoryAddressAddr = MemryScan::PatternScanner::FindPattern("\x80\xF9\x05\x75\x08\x48\x05\x00\x00\x00\x00", "xxxxxxx????");
		if (_gtaModelMemoryAddressAddr)
		{
			static UINT64(*_gtaModelGetInfo)(int, __int64) = (UINT64(*)(int, __int64))(*(int*)(_gtaModelMemoryAddressAddr - 0x12) + _gtaModelMemoryAddressAddr - 0x12 + 0x4);

			int data = 0xFFFF;
			return _gtaModelGetInfo(this->hash, (__int64)&data);
		}
		return NULL;
	}

	std::string Model::VehicleDisplayName(bool properName) const
	{
		static UINT64 _gtaModelMemoryAddressAddr = MemryScan::PatternScanner::FindPattern("\x80\xF9\x05\x75\x08\x48\x05\x00\x00\x00\x00", "xxxxxxx????");
		if (_gtaModelMemoryAddressAddr)
		{
			static UINT64(*_gtaModelGetInfo)(int, __int64) = (UINT64(*)(int, __int64))(*(int*)(_gtaModelMemoryAddressAddr - 0x12) + _gtaModelMemoryAddressAddr - 0x12 + 0x4);
			static int _gtaModelDisplayNameOffset = *(int*)(_gtaModelMemoryAddressAddr + 0x7);

			int data = 0xFFFF;
			__int64 addr = _gtaModelGetInfo(this->hash, (__int64)&data);
			if (addr && (*(unsigned char*)(addr + 157) & 0x1F) == 5)//make sure model is valid and is a car
			{
				return properName ?
					(UI::DOES_TEXT_LABEL_EXIST((char*)(addr + _gtaModelDisplayNameOffset)) ? UI::_GET_LABEL_TEXT((char*)(addr + _gtaModelDisplayNameOffset)) : (char*)(addr + _gtaModelDisplayNameOffset))
					: (char*)(addr + _gtaModelDisplayNameOffset);
			}
		}
		else
		{
			char* name = VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL(this->hash);
			return properName ?
				(UI::DOES_TEXT_LABEL_EXIST(name) ? UI::_GET_LABEL_TEXT(name) : name)
				: name;
		}
		return "CARNOTFOUND";
	}

	ModelDimensions Model::Dimensions() const
	{
		ModelDimensions dims;
		this->Dimensions(dims.Dim1, dims.Dim2);
		return dims;
	}
	void Model::Dimensions(Vector31& dim1C, Vector31& dim2C) const
	{
		/*Vector3_t dim1, dim2;
		GET_MODEL_DIMENSIONS(this->hash, &dim1, &dim2);
		dim1.x = abs(dim1.x); dim2.x = abs(dim2.x);
		dim1.y = abs(dim1.y); dim2.y = abs(dim2.y);
		dim1.z = abs(dim1.z); dim2.z = abs(dim2.z);
		dim1C = dim1;
		dim2C = dim2;*/
		Vector31_t dim1, dim2;
		UINT64 modelInfo = this->MemoryAddress();
		if (modelInfo)
		{
			auto darr = reinterpret_cast<float*>(modelInfo + 48);
			dim1.x1 = abs(darr[0]); dim2.x1 = abs(darr[4]);
			dim1.y1 = abs(darr[1]); dim2.y1 = abs(darr[5]);
			dim1.z1 = abs(darr[2]); dim2.z1 = abs(darr[6]);
		}
		else
		{
			GAMEPLAY::GET_MODEL_DIMENSIONS2(this->hash, &dim1, &dim2);
			dim1.x1 = abs(dim1.x1); dim2.x1 = abs(dim2.x1);
			dim1.y1 = abs(dim1.y1); dim2.y1 = abs(dim2.y1);
			dim1.z1 = abs(dim1.z1); dim2.z1 = abs(dim2.z1);
		}
		dim1C = dim1;
		dim2C = dim2;
	}
	void Model::Dimensions(Vector31_t& dim1, Vector31_t& dim2) const
	{
		/*GET_MODEL_DIMENSIONS(this->hash, &dim1, &dim2);
		dim1.x = abs(dim1.x); dim2.x = abs(dim2.x);
		dim1.y = abs(dim1.y); dim2.y = abs(dim2.y);
		dim1.z = abs(dim1.z); dim2.z = abs(dim2.z);*/
		UINT64 modelInfo = this->MemoryAddress();
		if (modelInfo)
		{
			auto darr = reinterpret_cast<float*>(modelInfo + 48);
			dim1.x1 = abs(darr[0]); dim2.x1 = abs(darr[4]);
			dim1.y1 = abs(darr[1]); dim2.y1 = abs(darr[5]);
			dim1.z1 = abs(darr[2]); dim2.z1 = abs(darr[6]);
		}
		else
		{
			GAMEPLAY::GET_MODEL_DIMENSIONS2(this->hash, &dim1, &dim2);
			dim1.x1 = abs(dim1.x1); dim2.x1 = abs(dim2.x1);
			dim1.y1 = abs(dim1.y1); dim2.y1 = abs(dim2.y1);
			dim1.z1 = abs(dim1.z1); dim2.z1 = abs(dim2.z1);
		}
	}
	Vector31 Model::Dim1() const
	{
		Vector31_t dim1, dim2;
		this->Dimensions(dim1, dim2);
		return dim1;
	}
	Vector31 Model::Dim2() const
	{
		Vector31_t dim1, dim2;
		this->Dimensions(dim1, dim2);
		return dim2;
	}

	//bool Model::IsBicycle() const
	//{
	//	return IS_THIS_MODEL_A_BICYCLE(this->hash) != 0;
	//}
	//bool Model::IsBike() const
	//{
	//	return IS_THIS_MODEL_A_BIKE(this->hash) || this->hash == VEHICLE_CHIMERA;
	//}
	//bool Model::IsQuadbike() const
	//{
	//	return IS_THIS_MODEL_A_QUADBIKE(this->hash) != 0;
	//}
	//bool Model::IsBoat() const
	//{
	//	return IS_THIS_MODEL_A_BOAT(this->hash) != 0;
	//}
	//bool Model::IsCar() const
	//{
	//	return IS_THIS_MODEL_A_CAR(this->hash) != 0;
	//}
	//bool Model::IsHeli() const
	//{
	//	return IS_THIS_MODEL_A_HELI(this->hash) != 0;
	//}
	//bool Model::IsPlane() const
	//{
	//	return IS_THIS_MODEL_A_PLANE(this->hash) != 0;
	//}
	//bool Model::IsTrain() const
	//{
	//	return IS_THIS_MODEL_A_TRAIN(this->hash) != 0;
	//}
	//bool Model::IsFastBoat() const
	//{
	//	return _IS_THIS_MODEL_AN_EMERGENCY_BOAT(this->hash) != 0;
	//}
	//bool Model::IsCargobob() const
	//{
	//	switch (this->hash)
	//	{
	//	case VEHICLE_CARGOBOB:
	//	case VEHICLE_CARGOBOB2:
	//	case VEHICLE_CARGOBOB3:
	//	case VEHICLE_CARGOBOB4:
	//		return true;
	//	}
	//	return false;
	//}
	//bool Model::IsBus() const
	//{
	//	//if (boost::to_upper_copy(this->VehicleDisplayName(false)).find("BUS") != std::string::npos) return true; return false;

	//	switch (this->hash)
	//	{
	//	case VEHICLE_BUS:
	//	case VEHICLE_RENTALBUS:
	//	case VEHICLE_AIRBUS:
	//	case VEHICLE_PBUS:
	//	case VEHICLE_TOURBUS:
	//		return true;
	//	}
	//	return false;
	//}
	//bool Model::IsPoliceVehicle() const
	//{
	//	switch (this->hash)
	//	{
	//	case VEHICLE_POLICEOLD2:
	//	case VEHICLE_FBI:
	//	case VEHICLE_RIOT:
	//	case VEHICLE_FBI2:
	//	case VEHICLE_PRANGER:
	//	case VEHICLE_POLICEOLD1:
	//	case VEHICLE_POLICET:
	//	case VEHICLE_SHERIFF2:
	//	case VEHICLE_PBUS:
	//	case VEHICLE_POLICE2:
	//	case VEHICLE_POLICE:
	//	case VEHICLE_POLICE3:
	//	case VEHICLE_SHERIFF:
	//	case VEHICLE_POLICE4:
	//	case VEHICLE_POLICEB:
	//		return true;
	//	}
	//	return false;
	//}
	//bool Model::HasSiren() const
	//{
	//	if (this->IsPoliceVehicle()) return true;

	//	switch (this->hash)
	//	{
	//	case VEHICLE_FIRETRUK:
	//	case VEHICLE_AMBULANCE:
	//		return true;
	//	}
	//	return false;
	//}
	//bool Model::IsWheelChangingSupportedVehicle() const
	//{
	//	//if (boost::to_upper_copy(this->VehicleDisplayName(false)).find("BUS") != std::string::npos) return true; return false;

	//	if (this->IsBus() || this->IsBicycle()) return false;

	//	switch (this->hash)
	//	{
	//	case VEHICLE_DUMP:
	//	case VEHICLE_FLATBED:
	//	case VEHICLE_FIRETRUK:
	//	case VEHICLE_RIPLEY:
	//	case VEHICLE_PHANTOM:
	//	case VEHICLE_AMBULANCE:
	//	case VEHICLE_TYRUS:
	//	case VEHICLE_CARGOPLANE:
	//	case VEHICLE_RIOT:
	//	case VEHICLE_BUS:
	//	case VEHICLE_AIRBUS:
	//	case VEHICLE_TAMPA:
	//	case VEHICLE_TROHPYTRUCK:
	//	case VEHICLE_CADDY3:
	//		return false;
	//	}
	//	return true;
	//}
	//bool Model::IsBennySupportedVehicle()
	//{
	//	switch (this->hash)
	//	{
	//	case VEHICLE_BUCCANEER2:
	//	case VEHICLE_CHINO2:
	//	case VEHICLE_FACTION:
	//	case VEHICLE_FACTION2:
	//	case VEHICLE_MOONBEAM:
	//	case VEHICLE_MOONBEAM2:
	//	case VEHICLE_PRIMO2:
	//	case VEHICLE_VOODOO:
	//	case VEHICLE_BTYPE2:
	//	case VEHICLE_LURCHER:
	//		// And many others
	//		return true;
	//	}
	//	return false;
	//}

	bool Model::IsVehicle() const
	{
		return STREAMING::IS_MODEL_A_VEHICLE(this->hash) != 0;
	}
	bool Model::IsPed() const
	{
		return GTAmemory::IsModelAPed(this->hash);
	}

	void Model::Load() const
	{
		STREAMING::REQUEST_MODEL(this->hash);
	}
	bool Model::Load(DWORD timeOut) const
	{
		if (STREAMING::HAS_MODEL_LOADED(this->hash)) return true;
		else
		{
			STREAMING::REQUEST_MODEL(this->hash);

			for (timeOut += GetTickCount(); GetTickCount() < timeOut;)
			{
				if (STREAMING::HAS_MODEL_LOADED(this->hash))
					return true;
				WAIT(0);
			}
			return false;
		}
	}
	void Model::LoadAndWait() const
	{
		this->Load(7500);
	}
	bool Model::IsLoaded() const
	{
		return STREAMING::HAS_MODEL_LOADED(this->hash) != 0;
	}
	void Model::Unload() const
	{
		if (STREAMING::HAS_MODEL_LOADED(this->hash))
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(this->hash);
	}

	void Model::LoadCollision() const
	{
		STREAMING::REQUEST_COLLISION_FOR_MODEL(this->hash);
	}
	bool Model::LoadCollision(DWORD timeOut) const
	{
		STREAMING::REQUEST_COLLISION_FOR_MODEL(this->hash);

		for (timeOut += GetTickCount(); GetTickCount() < timeOut;)
		{
			if (STREAMING::HAS_COLLISION_FOR_MODEL_LOADED(this->hash)) return true;
			WAIT(0);
		}
		return false;
	}
	bool Model::IsCollisionLoaded() const
	{
		return STREAMING::HAS_COLLISION_FOR_MODEL_LOADED(this->hash) != 0;
	}
	void Model::LoadCollisionAndWait() const
	{
		this->LoadCollision(4000);
	}


	bool Model::IsValid() const
	{
		return STREAMING::IS_MODEL_VALID(this->hash) != 0;
	}
	bool Model::IsInCdImage() const
	{
		return STREAMING::IS_MODEL_IN_CDIMAGE(this->hash) != 0;
	}
	bool Model::Exists() const
	{
		return STREAMING::IS_MODEL_VALID(this->hash) && STREAMING::IS_MODEL_IN_CDIMAGE(this->hash);
	}

}



