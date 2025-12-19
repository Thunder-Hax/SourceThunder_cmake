#include "stdafx.h"
#include "Raycast.h"
#include "macros.h"
#include "natives.h"
#include "GTAmath.h"
#include "GTAentity.h"
//#include "GTAped.h"
//#include "GTAvehicle.h"

RaycastResult::RaycastResult()
	: mResult(0), mDidHit(false)
{
}

RaycastResult::RaycastResult(const RaycastResult& handle)
	: mResult(handle.mResult), mDidHit(handle.mDidHit), mHitEntity(handle.mHitEntity), mHitCoords(handle.mHitCoords), mSurfaceNormal(handle.mSurfaceNormal)
{
}

RaycastResult::RaycastResult(int handle)
{
	int hitsomething = 0;
	int enthandle = 0;
	Vector31_t hitCoords, surfaceNormal;

	this->mResult = WORLDPROBE::GET_SHAPE_TEST_RESULT1(handle, &hitsomething, &hitCoords, &surfaceNormal, &enthandle);

	this->mDidHit = hitsomething != 0;
	this->mHitCoords = hitCoords;
	this->mSurfaceNormal = surfaceNormal;
	int* enthandle2 = &enthandle;
	/*int enthandleint = *enthandle2;*/
	if (ENTITY::DOES_ENTITY_EXIST(enthandle) && (ENTITY::IS_ENTITY_A_PED(enthandle) || ENTITY::IS_ENTITY_A_VEHICLE(enthandle) || ENTITY::IS_ENTITY_AN_OBJECT(enthandle2)))
	{
		this->mHitEntity = enthandle;
	}
	else
	{
		this->mHitEntity = GTAentity();

	}
}


int RaycastResult::Result()
{
	return this->mResult;
}
bool RaycastResult::DidHitEntity()
{
	return mHitEntity.Handle() != 0;
}
bool RaycastResult::DidHitAnything()
{
	return this->mDidHit;
}
GTAentity RaycastResult::HitEntity()
{
	return this->mHitEntity;
}
Vector31 RaycastResult::HitCoords()
{
	return this->mHitCoords;
}
Vector31 RaycastResult::SurfaceNormal()
{
	return this->mSurfaceNormal;
}


RaycastResult RaycastResult::Raycast(const Vector31& source, const Vector31& target, IntersectOptions options, GTAentity ignoreEntity)
{
	return RaycastResult(WORLDPROBE::_START_SHAPE_TEST_RAY(source.x1, source.y1, source.z1, target.x1, target.y1, target.z1, static_cast<int>(options), ignoreEntity.Handle(), 7));
}
RaycastResult RaycastResult::Raycast(const Vector31& source, const Vector31& direction, float maxDistance, IntersectOptions options, GTAentity ignoreEntity)
{
	Vector31& target = source + (direction * maxDistance);
	return RaycastResult(WORLDPROBE::_START_SHAPE_TEST_RAY(source.x1, source.y1, source.z1, target.x1, target.y1, target.z1, static_cast<int>(options), ignoreEntity.Handle(), 7));
}
RaycastResult RaycastResult::RaycastCapsule(const Vector31& source, const Vector31& target, float radius, IntersectOptions options, GTAentity ignoreEntity)
{
	return RaycastResult(WORLDPROBE::START_SHAPE_TEST_CAPSULE(source.x1, source.y1, source.z1, target.x1, target.y1, target.z1, radius, static_cast<int>(options), ignoreEntity.Handle(), 7));
}
RaycastResult RaycastResult::RaycastCapsule(const Vector31& source, const Vector31& direction, float maxDistance, float radius, IntersectOptions options, GTAentity ignoreEntity)
{
	Vector31& target = source + (direction * maxDistance);
	return RaycastResult(WORLDPROBE::START_SHAPE_TEST_CAPSULE(source.x1, source.y1, source.z1, target.x1, target.y1, target.z1, radius, static_cast<int>(options), ignoreEntity.Handle(), 7));
}


