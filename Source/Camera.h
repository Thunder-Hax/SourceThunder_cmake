#pragma once

#include <vector>
#include <string>

class Vector31;
class Vector21;

class GTAentity;
class GTAped;

enum class CameraShake : int
{
	Hand = 0,
	SmallExplosion,
	MediumExplosion,
	LargeExplosion,
	Jolt,
	Vibrate,
	RoadVibration,
	Drunk,
	SkyDiving,
	FamilyDrugTrip,
	DeathFail
};

extern const std::vector<std::string> CameraShakeNames;

class Camera2
{
public:
	Camera2();
	Camera2(int handle);

	friend bool operator == (const Camera2& left, const Camera2& right);
	friend bool operator != (const Camera2& left, const Camera2& right);
	Camera2& operator = (const Camera2& right);

	int& Handle();
	int GetHandle() const;

	void DepthOfFieldStrength_set(float value);

	float FieldOfView_get() const;
	void FieldOfView_set(float value);

	float FarClip_get() const;
	void FarClip_set(float value);
	float FarDepthOfField_get() const;
	void FarDepthOfField_set(float value);

	float NearClip_get() const;
	void NearClip_set(float value);
	void NearDepthOfField_set(float value);

	bool IsActive() const;
	void SetActive(bool value);

	bool IsInterpolating() const;

	bool IsShaking() const;

	void SetShake(bool status);

	void MotionBlurStrength_set(float value);

	Vector31 Position_get() const;
	void Position_set(Vector31 coord);
	void Position_set(float X, float Y, float Z);

	Vector31 Rotation_get(__int8 unk = 2) const;
	void Rotation_set(const Vector31& rot, __int8 unk = 2);
	void Rotation_set(float X, float Y, float Z, __int8 unk = 2);


	Vector31 Direction_get(__int8 unk = 2) const;
	void Direction_set(Vector31 dir, __int8 unk = 2);
	void Direction_set(float X, float Y, float Z, __int8 unk = 2);

	float Heading_get() const;
	void Heading_set(float value);


	Vector31 GetOffsetInWorldCoords(const Vector31& offset) const;
	Vector31 GetOffsetInWorldCoords(float X, float Y, float Z) const;
	Vector31 GetOffsetGivenWorldCoords(const Vector31& worldCoords) const;
	Vector31 GetOffsetGivenWorldCoords(float X, float Y, float Z) const;

	float ShakeAmplitude_get() const;
	void ShakeAmplitude_set(float value);

	CameraShake ShakeType_get() const;
	void ShakeType_set(CameraShake value);

	void AttachTo(GTAentity entity, Vector31 offset);
	void AttachTo(GTAped ped, int boneIndex, Vector31 offset);
	void Detach();

	void InterpTo(Camera2 to, int duration, bool easePosition, bool easeRotation);

	void PointAt(Vector31 target);
	void PointAt(GTAentity target);
	void PointAt(GTAentity target, Vector31 offset);
	void PointAt(GTAped target, int boneIndex);
	void PointAt(GTAped target, int boneIndex, Vector31 offset);
	void StopPointing();

	bool Exists() const;

	void Destroy();
	static void DestroyAllCameras();
	static void RenderScriptCams(bool render);


	Vector31 ScreenToWorld(const Vector21& screenCoord) const;

	GTAentity RaycastForEntity(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance = 100.0f) const;

	Vector31 RaycastForCoord(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance = 100.0f, float failDistance = 100.0f) const;

	Vector31 DirectionFromScreenCentre_get() const;


private:
	int mHandle;
	float mShakeAmplitude;
	CameraShake mShakeType;

	static bool WorldToScreenRel(const Vector31& worldCoords, Vector21& screenCoords);
};


Vector31 get_coords_from_cam(int camid, float distance);

