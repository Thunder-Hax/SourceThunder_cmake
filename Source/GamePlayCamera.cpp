#include "stdafx.h"
#include "GameplayCamera.h"
//#include "..\macros.h"

#include "GTAmath.h"
//#include "..\Natives\natives2.h"

#include "natives.h"

#include "GTAentity.h"
#include "Raycast.h"
#include "Camera.h"

#include <math.h>

float GameplayCamera::FieldOfView_get()
{
	return CAM::GET_GAMEPLAY_CAM_FOV();
}
void GameplayCamera::FieldOfView_set(float value)
{
	CAM::CUSTOM_MENU_COORDINATES(value); // I have no clue what this does //0x487A82C650EB7799
}

bool GameplayCamera::IsAimCamActive()
{
	return CAM::IS_AIM_CAM_ACTIVE() != 0;
}
bool GameplayCamera::IsFirstPersonAimCamActive()
{
	return CAM::IS_FIRST_PERSON_AIM_CAM_ACTIVE() != 0;
}
bool GameplayCamera::IsLookingBehind()
{
	return CAM::IS_GAMEPLAY_CAM_LOOKING_BEHIND() != 0;
}
bool GameplayCamera::IsRendering()
{
	return CAM::IS_GAMEPLAY_CAM_RENDERING() != 0;
}
bool GameplayCamera::IsShaking()
{
	return CAM::IS_GAMEPLAY_CAM_SHAKING() != 0;
}
Vector31 GameplayCamera::Position_get()
{
	return CAM::GET_GAMEPLAY_CAM_COORD2();
}
Vector31 GameplayCamera::GetOffsetInWorldCoords(const Vector31& offset)
{
	//return GameplayCamera::Position_get() + (GameplayCamera::Direction_get() * offset);
	Vector31& rotation = GameplayCamera::Rotation_get();
	Vector31& forward = Vector31::RotationToDirection(rotation);
	const double D2R = 0.01745329251994329576923690768489;
	double num1 = cos(rotation.y1 * D2R);
	double x = num1 * cos(-rotation.z1 * D2R);
	double y = num1 * sin(rotation.z1 * D2R);
	double z = sin(-rotation.y1 * D2R);
	Vector31& right = Vector31(x, y, z);
	Vector31& Up = Vector31::Cross(right, forward);
	return GameplayCamera::Position_get() + (right * offset.x1) + (forward * offset.y1) + (Up * offset.z1);
}
Vector31 GameplayCamera::GetOffsetInWorldCoords(float X, float Y, float Z)
{
	return GameplayCamera::GetOffsetInWorldCoords(Vector31(X, Y, Z));
}
Vector31 GameplayCamera::GetOffsetGivenWorldCoords(const Vector31& worldCoords)
{
	//return GameplayCamera::Position_get() + (GameplayCamera::Direction_get() * Vector3(X, Y, Z));
	Vector31& rotation = GameplayCamera::Rotation_get();
	Vector31& forward = Vector31::RotationToDirection(rotation);
	const double D2R = 0.01745329251994329576923690768489;
	double num1 = cos(rotation.y1 * D2R);
	double x = num1 * cos(-rotation.z1 * D2R);
	double y = num1 * sin(rotation.z1 * D2R);
	double z = sin(-rotation.y1 * D2R);
	Vector31& right = Vector31(x, y, z);
	Vector31& up = Vector31::Cross(right, forward);
	Vector31& delta = worldCoords - GameplayCamera::Position_get();
	return Vector31(Vector31::Dot(right, delta), Vector31::Dot(forward, delta), Vector31::Dot(up, delta));
}
Vector31 GameplayCamera::GetOffsetGivenWorldCoords(float X, float Y, float Z)
{
	return GameplayCamera::GetOffsetGivenWorldCoords(Vector31(X, Y, Z));
}
float GameplayCamera::RelativeHeading_get()
{
	return CAM::GET_GAMEPLAY_CAM_RELATIVE_HEADING();
}
void GameplayCamera::RelativeHeading_set(float value)
{
	CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(value);
}
float GameplayCamera::RelativePitch_get()
{
	return CAM::GET_GAMEPLAY_CAM_RELATIVE_PITCH();
}
void GameplayCamera::RelativePitch_set(float value)
{
	CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(value, 0.0f);
}
Vector31 GameplayCamera::Rotation_get()
{
	return CAM::GET_GAMEPLAY_CAM_ROT2(2);
}
Vector31 GameplayCamera::Direction_get()
{
	return Vector31::RotationToDirection(CAM::GET_GAMEPLAY_CAM_ROT2(2));
}
float GameplayCamera::Zoom_get()
{
	return CAM::_GET_GAMEPLAY_CAM_ZOOM();
}
void GameplayCamera::ShakeAmplitude_set(float value)
{
	CAM::SET_GAMEPLAY_CAM_SHAKE_AMPLITUDE(value);
}

void GameplayCamera::Shake(CameraShake shakeType, float amplitude)
{
	CAM::SHAKE_GAMEPLAY_CAM(const_cast<PCHAR>(CameraShakeNames[static_cast<int>(shakeType)].c_str()), amplitude);
}

void GameplayCamera::StopShaking(bool value)
{
	CAM::STOP_GAMEPLAY_CAM_SHAKING(value);
}

void GameplayCamera::ClampYaw(float min, float max)
{
	CAM::_CLAMP_GAMEPLAY_CAM_YAW(min, max);
}

void GameplayCamera::ClampPitch(float min, float max)
{
	CAM::_CLAMP_GAMEPLAY_CAM_PITCH(min, max);
}

Vector31 GameplayCamera::ScreenToWorld(const Vector21& screenCoord)
{
	// Credit to Guadmaz
	Vector31& camRot = GameplayCamera::Rotation_get();
	Vector31& camPos = GameplayCamera::Position_get();

	Vector21 vector20;
	Vector21 vector210;
	Vector31& direction = Vector31::RotationToDirection(camRot);
	Vector31 vector3 = camRot + Vector31(10.f, 0.f, 0.f);
	Vector31 vector31 = camRot + Vector31(-10.f, 0.f, 0.f);
	Vector31 vector32 = camRot + Vector31(0.f, 0.f, -10.f);
	Vector31 direction1 = Vector31::RotationToDirection(camRot + Vector31(0.f, 0.f, 10.f)) - Vector31::RotationToDirection(vector32);
	Vector31 direction2 = Vector31::RotationToDirection(vector3) - Vector31::RotationToDirection(vector31);
	float rad = -DegreeToRadian(camRot.y1);
	Vector31 vector33 = (direction1 * cos(rad)) - (direction2 * sin(rad));
	Vector31 vector34 = (direction1 * sin(rad)) + (direction2 * cos(rad));
	if (!WorldToScreenRel(((camPos + (direction * 10.f)) + vector33) + vector34, vector20))
	{
		return camPos + (direction * 10.f);
	}
	if (!WorldToScreenRel(camPos + (direction * 10.f), vector210))
	{
		return camPos + (direction * 10.f);
	}
	if (abs(vector20.x1 - vector210.x1) < 0.001f || abs(vector20.y1 - vector210.y1) < 0.001f)
	{
		return camPos + (direction * 10.f);
	}
	float x = (screenCoord.x1 - vector210.x1) / (vector20.x1 - vector210.x1);
	float y = (screenCoord.y1 - vector210.y1) / (vector20.y1 - vector210.y1);
	return ((camPos + (direction * 10.f)) + (vector33 * x)) + (vector34 * y);
}

GTAentity GameplayCamera::RaycastForEntity(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance)
{
	// Credit to Guadmaz
	Vector31& world = ScreenToWorld(screenCoord);
	Vector31& vector3 = GameplayCamera::Position_get();
	Vector31& vector310 = world - vector3;
	vector310.Normalize();
	RaycastResult raycastResult = RaycastResult::Raycast(vector3 + (vector310 * 1.f), vector3 + (vector310 * maxDistance), IntersectOptions(287), ignoreEntity);
	return raycastResult.DidHitEntity() ? raycastResult.HitEntity() : 0;
}

Vector31 GameplayCamera::RaycastForCoord(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance, float failDistance)
{
	// Credit to Guadmaz
	Vector31& position = GameplayCamera::Position_get();
	Vector31& world = ScreenToWorld(screenCoord);
	Vector31 vector30 = position;
	Vector31 vector31 = world - vector30;
	vector31.Normalize();
	RaycastResult& raycastResult = RaycastResult::Raycast(vector30 + (vector31 * 1.f), vector30 + (vector31 * maxDistance), IntersectOptions(287), ignoreEntity);
	return raycastResult.DidHitAnything() ? raycastResult.HitCoords() : position + (vector31 * failDistance);
}

Vector31 GameplayCamera::DirectionFromScreenCentre_get()
{
	Vector31& position = GameplayCamera::Position_get();
	Vector31& world = GameplayCamera::ScreenToWorld(Vector21(0.0f, 0.0f));
	return Vector31::Normalize(world - position);
}

bool GameplayCamera::WorldToScreenRel(const Vector31& worldCoords, Vector21& screenCoords)
{
	if (!GRAPHICS::_WORLD3D_TO_SCREEN2D(worldCoords.x1, worldCoords.y1, worldCoords.z1, &screenCoords.x1, &screenCoords.y1))
		return false;

	screenCoords.x1 = (screenCoords.x1 - 0.5f) * 2.0f;
	screenCoords.y1 = (screenCoords.y1 - 0.5f) * 2.0f;
	return true;
}


Vector31 get_coords_from_cam(float distance)
{
	Vector31& Rot = DegreeToRadian(CAM::GET_GAMEPLAY_CAM_ROT2(2));
	Vector31 Coord = CAM::GET_GAMEPLAY_CAM_COORD2();

	Rot.y1 = distance * cos(Rot.x1);
	Coord.x1 = Coord.x1 + Rot.y1 * sin(Rot.z1 * -1.0f);
	Coord.y1 = Coord.y1 + Rot.y1 * cos(Rot.z1 * -1.0f);
	Coord.z1 = Coord.z1 + distance * sin(Rot.x1);

	return Coord;
}


