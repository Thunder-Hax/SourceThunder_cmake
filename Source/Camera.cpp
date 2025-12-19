#include "stdafx.h"
#include "Camera.h"

//#include "..\macros.h"

#include "GTAmath.h"
//#include "..\Natives\natives2.h"
#include "GTAentity.h"
#include "GTAped.h"
#include "Raycast.h"

#include <string>
#include <vector>
#include <math.h>

const std::vector<std::string> CameraShakeNames{ "HAND_SHAKE", "SMALL_EXPLOSION_SHAKE", "MEDIUM_EXPLOSION_SHAKE", "LARGE_EXPLOSION_SHAKE", "JOLT_SHAKE", "VIBRATE_SHAKE", "ROAD_VIBRATION_SHAKE", "DRUNK_SHAKE", "SKY_DIVING_SHAKE", "FAMILY5_DRUG_TRIP_SHAKE", "DEATH_FAIL_IN_EFFECT_SHAKE" };

Camera2::Camera2() : mHandle(0), mShakeType(CameraShake::Hand), mShakeAmplitude(0.0f)
{
}
Camera2::Camera2(int handle) : mHandle(handle), mShakeType(CameraShake::Hand), mShakeAmplitude(0.0f)
{
}

bool operator == (const Camera2& left, const Camera2& right)
{
	return (left.mHandle == right.mHandle);
}
bool operator != (const Camera2& left, const Camera2& right)
{
	return (left.mHandle != right.mHandle);
}
Camera2& Camera2::operator = (const Camera2& right)
{
	this->mHandle = right.mHandle;
	this->mShakeType = right.mShakeType;
	this->mShakeAmplitude = right.mShakeAmplitude;
	return *this;
}

int& Camera2::Handle()
{
	return this->mHandle;
}
int Camera2::GetHandle() const
{
	return this->mHandle;
}

void Camera2::DepthOfFieldStrength_set(float value)
{
	CAM::SET_CAM_DOF_STRENGTH(this->mHandle, value);
}

float Camera2::FieldOfView_get() const
{
	return CAM::GET_CAM_FOV(this->mHandle);
}
void Camera2::FieldOfView_set(float value)
{
	CAM::SET_CAM_FOV(this->mHandle, value);
}

float Camera2::FarClip_get() const
{
	return CAM::GET_CAM_FAR_CLIP(this->mHandle);
}
void Camera2::FarClip_set(float value)
{
	CAM::SET_CAM_FAR_CLIP(this->mHandle, value);
}
float Camera2::FarDepthOfField_get() const
{
	return CAM::GET_CAM_FAR_DOF(this->mHandle);
}
void Camera2::FarDepthOfField_set(float value)
{
	CAM::SET_CAM_FAR_DOF(this->mHandle, value);
}

float Camera2::NearClip_get() const
{
	return CAM::GET_CAM_NEAR_CLIP(this->mHandle);
}
void Camera2::NearClip_set(float value)
{
	CAM::SET_CAM_NEAR_CLIP(this->mHandle, value);
}
void Camera2::NearDepthOfField_set(float value)
{
	CAM::SET_CAM_NEAR_DOF(this->mHandle, value);
}

bool Camera2::IsActive() const
{
	return CAM::IS_CAM_ACTIVE(this->mHandle) != 0;
}
void Camera2::SetActive(bool value)
{
	CAM::SET_CAM_ACTIVE(this->mHandle, value);
}

bool Camera2::IsInterpolating() const
{
	return CAM::IS_CAM_INTERPOLATING(this->mHandle) != 0;
}

bool Camera2::IsShaking() const
{
	return CAM::IS_CAM_SHAKING(this->mHandle) != 0;
}

void Camera2::SetShake(bool status)
{
	if (status)
	{
		CAM::SHAKE_CAM(this->mHandle, const_cast<PCHAR>(CameraShakeNames[static_cast<int>(this->mShakeType)].c_str()), this->mShakeAmplitude);
	}
	else
	{
		CAM::STOP_CAM_SHAKING(this->mHandle, true);
	}
}

void Camera2::MotionBlurStrength_set(float value)
{
	CAM::SET_CAM_MOTION_BLUR_STRENGTH(this->mHandle, value);
}

Vector31 Camera2::Position_get() const
{
	return CAM::GET_CAM_COORD2(this->mHandle);
}
void Camera2::Position_set(Vector31 coord)
{
	CAM::SET_CAM_COORD(this->mHandle, coord.x1, coord.y1, coord.z1);
}
void Camera2::Position_set(float X, float Y, float Z)
{
	CAM::SET_CAM_COORD(this->mHandle, X, Y, Z);
}

Vector31 Camera2::Rotation_get(__int8 unk) const
{
	return CAM::GET_CAM_ROT2(this->mHandle, unk);
}
void Camera2::Rotation_set(const Vector31& rot, __int8 unk)
{
	CAM::SET_CAM_ROT(this->mHandle, rot.x1, rot.y1, rot.z1, unk);
}
void Camera2::Rotation_set(float X, float Y, float Z, __int8 unk)
{
	CAM::SET_CAM_ROT(this->mHandle, X, Y, Z, unk);
}


Vector31 Camera2::Direction_get(__int8 unk) const
{
	return Vector31::RotationToDirection(CAM::GET_CAM_ROT2(this->mHandle, unk));
}
void Camera2::Direction_set(Vector31 dir, __int8 unk)
{
	dir = Vector31::DirectionToRotation(dir);
	CAM::SET_CAM_ROT(this->mHandle, dir.x1, dir.y1, dir.z1, unk);
}
void Camera2::Direction_set(float X, float Y, float Z, __int8 unk)
{
	auto& dir = Vector31::DirectionToRotation(Vector31(X, Y, Z));
	CAM::SET_CAM_ROT(this->mHandle, dir.x1, dir.y1, dir.z1, unk);
}

float Camera2::Heading_get() const
{
	return CAM::GET_CAM_ROT(this->mHandle, 2).z;
}
void Camera2::Heading_set(float value)
{
	Vector31& oldRot = this->Rotation_get();
	CAM::SET_CAM_ROT(this->mHandle, oldRot.x1, oldRot.y1, value, 21);
}


Vector31 Camera2::GetOffsetInWorldCoords(const Vector31& offset) const
{
	//return this->Position_get() + (this->Direction_get() * offset);
	Vector31& rotation = this->Rotation_get();
	Vector31& forward = Vector31::RotationToDirection(rotation);
	const double D2R = 0.01745329251994329576923690768489;
	double num1 = cos(rotation.y1 * D2R);
	double x = num1 * cos(-rotation.z1 * D2R);
	double y = num1 * sin(rotation.z1 * D2R);
	double z = sin(-rotation.y1 * D2R);
	Vector31& right = Vector31(x, y, z);
	Vector31& Up = Vector31::Cross(right, forward);
	return this->Position_get() + (right * offset.x1) + (forward * offset.y1) + (Up * offset.z1);
}
Vector31 Camera2::GetOffsetInWorldCoords(float X, float Y, float Z) const
{
	return this->GetOffsetInWorldCoords(Vector31(X, Y, Z));
}
Vector31 Camera2::GetOffsetGivenWorldCoords(const Vector31& worldCoords) const
{
	//return this->Position_get() + (this->Direction_get() * Vector31(X, Y, Z));
	Vector31& rotation = this->Rotation_get();
	Vector31& forward = Vector31::RotationToDirection(rotation);
	const double D2R = 0.01745329251994329576923690768489;
	double num1 = cos(rotation.y1 * D2R);
	double x = num1 * cos(-rotation.z1 * D2R);
	double y = num1 * sin(rotation.z1 * D2R);
	double z = sin(-rotation.y1 * D2R);
	Vector31& right = Vector31(x, y, z);
	Vector31& up = Vector31::Cross(right, forward);
	Vector31& delta = worldCoords - this->Position_get();
	return Vector31(Vector31::Dot(right, delta), Vector31::Dot(forward, delta), Vector31::Dot(up, delta));
}
Vector31 Camera2::GetOffsetGivenWorldCoords(float X, float Y, float Z) const
{
	return this->GetOffsetGivenWorldCoords(Vector31(X, Y, Z));
}

float Camera2::ShakeAmplitude_get() const
{
	return this->mShakeAmplitude;
}
void Camera2::ShakeAmplitude_set(float value)
{
	this->mShakeAmplitude = value;
	CAM::SET_CAM_SHAKE_AMPLITUDE(this->mHandle, value);
}

CameraShake Camera2::ShakeType_get() const
{
	return this->mShakeType;
}
void Camera2::ShakeType_set(CameraShake value)
{
	this->mShakeType = value;

	if (this->IsShaking())
	{
		CAM::SHAKE_CAM(this->mHandle, const_cast<PCHAR>(CameraShakeNames[static_cast<int>(this->mShakeType)].c_str()), this->mShakeAmplitude);
	}
}

void Camera2::AttachTo(GTAentity entity, Vector31 offset)
{
	CAM::ATTACH_CAM_TO_ENTITY(this->mHandle, entity.Handle(), offset.x1, offset.y1, offset.z1, true);
}
void Camera2::AttachTo(GTAped ped, int boneIndex, Vector31 offset)
{
	CAM::ATTACH_CAM_TO_PED_BONE(this->mHandle, ped.Handle(), boneIndex, offset.x1, offset.y1, offset.z1, true);
}
void Camera2::Detach()
{
	CAM::DETACH_CAM(this->mHandle);
}

void Camera2::InterpTo(Camera2 to, int duration, bool easePosition, bool easeRotation)
{
	CAM::SET_CAM_ACTIVE_WITH_INTERP(to.Handle(), this->mHandle, duration, easePosition, easeRotation);
}

void Camera2::PointAt(Vector31 target)
{
	CAM::POINT_CAM_AT_COORD(this->mHandle, target.x1, target.y1, target.z1);
}
void Camera2::PointAt(GTAentity target)
{
	CAM::POINT_CAM_AT_ENTITY(this->mHandle, target.Handle(), 0.0f, 0.0f, 0.0f, true);
}
void Camera2::PointAt(GTAentity target, Vector31 offset)
{
	CAM::POINT_CAM_AT_ENTITY(this->mHandle, target.Handle(), offset.x1, offset.y1, offset.z1, true);
}
void Camera2::PointAt(GTAped target, int boneIndex)
{
	CAM::POINT_CAM_AT_PED_BONE(this->mHandle, target.Handle(), boneIndex, 0.0f, 0.0f, 0.0f, true);
}
void Camera2::PointAt(GTAped target, int boneIndex, Vector31 offset)
{
	CAM::POINT_CAM_AT_PED_BONE(this->mHandle, target.Handle(), boneIndex, offset.x1, offset.y1, offset.z1, true);
}
void Camera2::StopPointing()
{
	CAM::STOP_CAM_POINTING(this->mHandle);
}

bool Camera2::Exists() const
{
	return CAM::DOES_CAM_EXIST(this->mHandle) != 0;
}

void Camera2::Destroy()
{
	CAM::DESTROY_CAM(this->mHandle, false);
}
void Camera2::DestroyAllCameras()
{
	CAM::DESTROY_ALL_CAMS(0);
}
void Camera2::RenderScriptCams(bool render)
{
	CAM::RENDER_SCRIPT_CAMS(render, 0, 3000, 1, 0);
}

Vector31 Camera2::ScreenToWorld(const Vector21& screenCoord) const
{
	// Credit to Guadmaz
	Vector31& camRot = this->Rotation_get();
	Vector31& camPos = this->Position_get();

	Vector21 vector21;
	Vector21 vector211;
	Vector31& direction = Vector31::RotationToDirection(camRot);
	Vector31 vector31 = camRot + Vector31(10.f, 0.f, 0.f);
	Vector31 vector311 = camRot + Vector31(-10.f, 0.f, 0.f);
	Vector31 vector321 = camRot + Vector31(0.f, 0.f, -10.f);
	Vector31 direction1 = Vector31::RotationToDirection(camRot + Vector31(0.f, 0.f, 10.f)) - Vector31::RotationToDirection(vector321);
	Vector31 direction2 = Vector31::RotationToDirection(vector31) - Vector31::RotationToDirection(vector311);
	float rad = -DegreeToRadian(camRot.y1);
	Vector31 vector331 = (direction1 * cos(rad)) - (direction2 * sin(rad));
	Vector31 vector341 = (direction1 * sin(rad)) + (direction2 * cos(rad));
	if (!WorldToScreenRel(((camPos + (direction * 10.f)) + vector331) + vector341, vector21))
	{
		return camPos + (direction * 10.f);
	}
	if (!WorldToScreenRel(camPos + (direction * 10.f), vector211))
	{
		return camPos + (direction * 10.f);
	}
	if (abs(vector21.x1 - vector211.x1) < 0.001f || abs(vector21.y1 - vector211.y1) < 0.001f)
	{
		return camPos + (direction * 10.f);
	}
	float x = (screenCoord.x1 - vector211.x1) / (vector21.x1 - vector211.x1);
	float y = (screenCoord.y1 - vector211.y1) / (vector21.y1 - vector211.y1);
	return ((camPos + (direction * 10.f)) + (vector331 * x)) + (vector341 * y);
}

GTAentity Camera2::RaycastForEntity(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance) const
{
	// Credit to Guadmaz
	Vector31& world = this->ScreenToWorld(screenCoord);
	Vector31& Vector3 = this->Position_get();
	Vector31& vector31 = world - Vector3;
	vector31.Normalize();
	RaycastResult raycastResult = RaycastResult::Raycast(Vector3 + (vector31 * 1.f), Vector3 + (vector31 * maxDistance), IntersectOptions(287), ignoreEntity);
	return raycastResult.DidHitEntity() ? raycastResult.HitEntity() : 0;
}

Vector31 Camera2::RaycastForCoord(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance, float failDistance) const
{
	// Credit to Guadmaz
	Vector31& position = this->Position_get();
	Vector31& world = this->ScreenToWorld(screenCoord);
	Vector31 Vector3 = position;
	Vector31 vector31 = world - Vector3;
	vector31.Normalize();
	RaycastResult raycastResult = RaycastResult::Raycast(Vector3 + (vector31 * 1.f), Vector3 + (vector31 * maxDistance), IntersectOptions(287), ignoreEntity);
	return raycastResult.DidHitAnything() ? raycastResult.HitCoords() : position + (vector31 * failDistance);
}

Vector31 Camera2::DirectionFromScreenCentre_get() const
{
	Vector31& position = this->Position_get();
	Vector31& world = this->ScreenToWorld(Vector21(0.0f, 0.0f));
	return Vector31::Normalize(world - position);
}

bool Camera2::WorldToScreenRel(const Vector31& worldCoords, Vector21& screenCoords)
{
	if (!GRAPHICS::_WORLD3D_TO_SCREEN2D(worldCoords.x1, worldCoords.y1, worldCoords.z1, &screenCoords.x1, &screenCoords.y1))
		return false;

	screenCoords.x1 = (screenCoords.x1 - 0.5f) * 2.0f;
	screenCoords.y1 = (screenCoords.y1 - 0.5f) * 2.0f;
	return true;
}


Vector31 get_coords_from_cam(int camid, float distance)
{
	Vector31 Rot = DegreeToRadian(CAM::GET_CAM_ROT2(camid, 2));
	Vector31 Coord = CAM::GET_CAM_COORD2(camid);

	Rot.y1 = distance * cos(Rot.x1);
	Coord.x1 = Coord.x1 + Rot.y1 * sin(Rot.z1 * -1.0f);
	Coord.y1 = Coord.y1 + Rot.y1 * cos(Rot.z1 * -1.0f);
	Coord.z1 = Coord.z1 + distance * sin(Rot.x1);

	return Coord;
}

