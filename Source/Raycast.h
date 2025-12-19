#pragma once

#include "GTAmath.h"
#include "GTAentity.h"

enum class IntersectOptions : int
{
	Everything = -1,
	Map = 1,
	Mission_Entities = 2,
	Peds1 = 12,//4 and 8 both seem to be peds
	Objects = 16,
	Unk1 = 32,
	Unk2 = 64,
	Unk3 = 128,
	Vegetation = 256,
	Unk4 = 512
};

class RaycastResult
{
public:
	RaycastResult();
	RaycastResult(const RaycastResult& handle);
	RaycastResult(int handle);

	int Result();

	bool DidHitEntity();

	bool DidHitAnything();

	GTAentity HitEntity();

	Vector31 HitCoords();

	Vector31 SurfaceNormal();

	static RaycastResult Raycast(const Vector31& source, const Vector31& target, IntersectOptions options, GTAentity ignoreEntity = 0);
	static RaycastResult Raycast(const Vector31& source, const Vector31& direction, float maxDistance, IntersectOptions options, GTAentity ignoreEntity = 0);
	static RaycastResult RaycastCapsule(const Vector31& source, const Vector31& target, float radius, IntersectOptions options, GTAentity ignoreEntity = 0);
	static RaycastResult RaycastCapsule(const Vector31& source, const Vector31& direction, float maxDistance, float radius, IntersectOptions options, GTAentity ignoreEntity = 0);

private:
	int mResult;
	bool mDidHit;
	GTAentity mHitEntity;
	Vector31 mHitCoords;
	Vector31 mSurfaceNormal;
};


