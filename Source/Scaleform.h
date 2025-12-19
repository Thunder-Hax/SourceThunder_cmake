#include "stdafx.h"
#include "GTAEntity.h"
#pragma once

//#include "..\Natives\types.h" // RGBA, RgbS

#include <string>

class Vector31;
class Vector21;

struct Scaleform_IbT { int button; std::string text; bool isKey; };
class Scaleform final
{
public:

	Scaleform();
	Scaleform(const Scaleform& obj);
	Scaleform(int handle);

	int& Handle();

	int GetHandle() const;

	bool HasLoaded() const;

	bool Load(const std::string& scaleformID);

	void Unload();

	void PushFunction(const std::string& function);
	void PushInteger(int arg);
	void PushBoolean(bool arg);
	void PushFloat(float arg);
	void PushString(const std::string& arg);
	void PushString2(const std::string& arg);
	void PushTextComponent(const std::string& arg);
	void PushRGBA(const RGBA1& arg);
	void PushRGB(const RgbS& arg);
	void PushVector2(const Vector21& arg);
	void PushVector3(const Vector31& arg);

	void PopFunction();


	void Render2D(RGBA1 colour = { 255, 255, 255, 255 });
	void Render2DScreenSpace(const Vector21& location, const Vector21& size, RGBA1 colour = { 255, 255, 255, 255 });
	void Render3D(const Vector31& position, const Vector31& rotation, const Vector31& unk, const Vector31& scale);
	void Render3DAdditive(const Vector31& position, const Vector31& rotation, const Vector31& unk, const Vector31& scale);

private:
	int mHandle;
};

