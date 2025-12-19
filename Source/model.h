#pragma once

#include "GTAmath.h"

#include <string>

typedef unsigned long DWORD, Hash;
typedef unsigned __int64 UINT64;
enum VehicleHash : DWORD;

namespace GTAmodel
{
	class ModelDimensions
	{
	public:
		Vector31 Dim1;
		Vector31 Dim2;

		ModelDimensions();
		ModelDimensions(const Vector31& d1, const Vector31& d2);
	};

	class Model // Inconsistent with other class names - fix?
	{
	public:
		Hash hash;

		Model();
		Model(const std::string& name);
		Model(Hash newHash);
		Model(VehicleHash newHash);

		friend bool operator == (const Model& left, const Model& right);
		friend bool operator != (const Model& left, const Model& right);
		bool Equals(const Model& right) const;
		Model& operator = (const Model& right);

		UINT64 MemoryAddress() const;

		std::string VehicleDisplayName(bool properName) const;

		ModelDimensions Dimensions() const;
		void Dimensions(Vector31& dim1C, Vector31& dim2C) const;
		void Dimensions(Vector31_t& dim1, Vector31_t& dim2) const;
		Vector31 Dim1() const;
		Vector31 Dim2() const;

		/*bool IsBicycle() const;
		bool IsBike() const;
		bool IsQuadbike() const;
		bool IsBoat() const;
		bool IsCar() const;
		bool IsHeli() const;
		bool IsPlane() const;
		bool IsTrain() const;
		bool IsFastBoat() const;
		bool IsCargobob() const;
		bool IsBus() const;
		bool IsPoliceVehicle() const;
		bool HasSiren() const;
		bool IsWheelChangingSupportedVehicle() const;
		bool IsBennySupportedVehicle();*/

		bool IsVehicle() const;
		bool IsPed() const;

		void Load() const;
		bool Load(DWORD timeOut) const;
		void LoadAndWait() const;
		bool IsLoaded() const;
		void Unload() const;

		void LoadCollision() const;
		bool LoadCollision(DWORD timeOut) const;
		bool IsCollisionLoaded() const;
		void LoadCollisionAndWait() const;


		bool IsValid() const;
		bool IsInCdImage() const;
		bool Exists() const;

	};
}

using namespace GTAmodel;

namespace MODEL
{
	extern Hash GET_HASH_KEY(const std::string& value);
}