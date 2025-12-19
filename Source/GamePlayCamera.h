#pragma once

class Vector31;
class Vector21;
class GTAentity;

enum class CameraShake : int;

class GameplayCamera final
{
public:
	static float FieldOfView_get();
	static void FieldOfView_set(float value);

	static bool IsAimCamActive();
	static bool IsFirstPersonAimCamActive();
	static bool IsLookingBehind();
	static bool IsRendering();
	static bool IsShaking();
	static Vector31 Position_get();
	static Vector31 GetOffsetInWorldCoords(const Vector31& offset);
	static Vector31 GetOffsetInWorldCoords(float X, float Y, float Z);
	static Vector31 GetOffsetGivenWorldCoords(const Vector31& worldCoords);
	static Vector31 GetOffsetGivenWorldCoords(float X, float Y, float Z);
	static float RelativeHeading_get();
	static void RelativeHeading_set(float value);
	static float RelativePitch_get();
	static void RelativePitch_set(float value);
	static Vector31 Rotation_get();
	static Vector31 Direction_get();
	static float Zoom_get();
	static void ShakeAmplitude_set(float value);

	static void Shake(CameraShake shakeType, float amplitude);

	static void StopShaking(bool value);

	static void ClampYaw(float min, float max);

	static void ClampPitch(float min, float max);

	static Vector31 ScreenToWorld(const Vector21& screenCoord);

	static GTAentity RaycastForEntity(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance = 100.0f);

	static Vector31 RaycastForCoord(const Vector21& screenCoord, GTAentity ignoreEntity, float maxDistance = 100.0f, float failDistance = 100.0f);

	static Vector31 DirectionFromScreenCentre_get();

private:

	static bool WorldToScreenRel(const Vector31& worldCoords, Vector21& screenCoords);
};


Vector31 get_coords_from_cam(float distance);