#include "stdafx.h"
#include "Scaleform.h"

//#include "..\macros.h"
//
//#include "..\Util\GTAmath.h"
//#include "..\Natives\types.h"
//#include "..\Natives\natives2.h"

#include <string>

Scaleform::Scaleform()
{
}
Scaleform::Scaleform(const Scaleform& obj)
	: mHandle(obj.mHandle)
{
}
Scaleform::Scaleform(int handle)
	: mHandle(handle)
{
}

int& Scaleform::Handle()
{
	return this->mHandle;
}

int Scaleform::GetHandle() const
{
	return this->mHandle;
}

bool Scaleform::HasLoaded() const
{
	return GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->mHandle) != 0;
}

bool Scaleform::Load(const std::string& scaleformID)
{
	//this->mScaleformID = scaleformID;

	if (!GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->mHandle))
	{
		this->mHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE(const_cast<PCHAR>(scaleformID.c_str()));
		if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(this->mHandle))
			return true;
		return false;
	}

	return true;
}

void Scaleform::Unload()
{
	auto& handle = this->mHandle;
	if (GRAPHICS::HAS_SCALEFORM_MOVIE_LOADED(handle))
		GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&handle);
}

void Scaleform::PushFunction(const std::string& function)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION(this->mHandle, const_cast<PCHAR>(function.c_str()));
}
void Scaleform::PushInteger(int arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg);
}
void Scaleform::PushBoolean(bool arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_BOOL(arg);
}
void Scaleform::PushFloat(float arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(arg);
}
void Scaleform::PushString(const std::string& arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_STRING(const_cast<PCHAR>(arg.c_str()));
}
void Scaleform::PushString2(const std::string& arg)
{
	GRAPHICS::_0xE83A3E3557A56640(const_cast<PCHAR>(arg.c_str()));
}
void Scaleform::PushTextComponent(const std::string& arg)
{
	PCHAR text = const_cast<PCHAR>(arg.c_str());
	if (UI::DOES_TEXT_LABEL_EXIST(text))
	{
		GRAPHICS::_BEGIN_TEXT_COMPONENT(text);
	}
	else
	{
		GRAPHICS::_BEGIN_TEXT_COMPONENT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	}
	//ADD_TEXT_COMPONENT_INTEGER(-1);
	GRAPHICS::_END_TEXT_COMPONENT();
}
void Scaleform::PushRGBA(const RGBA1& arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg.R);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg.G);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg.B);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg.A);
}
void Scaleform::PushRGB(const RgbS& arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg.R);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg.G);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_INT(arg.B);
}
void Scaleform::PushVector2(const Vector21& arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(arg.x1);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(arg.y1);
}
void Scaleform::PushVector3(const Vector31& arg)
{
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(arg.x1);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(arg.y1);
	GRAPHICS::_PUSH_SCALEFORM_MOVIE_FUNCTION_PARAMETER_FLOAT(arg.z1);
}

void Scaleform::PopFunction()
{
	GRAPHICS::_POP_SCALEFORM_MOVIE_FUNCTION_VOID();
}


void Scaleform::Render2D(RGBA1 colour)
{
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(this->mHandle, colour.R, colour.G, colour.B, colour.A, 0);
}
void Scaleform::Render2DScreenSpace(const Vector21& location, const Vector21& size, RGBA1 colour)
{
	GRAPHICS::DRAW_SCALEFORM_MOVIE(this->mHandle, location.x1, location.y1, size.x1, size.y1, colour.R, colour.G, colour.B, colour.A, 0);
}
void Scaleform::Render3D(const Vector31& position, const Vector31& rotation, const Vector31& unk, const Vector31& scale)
{
	GRAPHICS::_DRAW_SCALEFORM_MOVIE_3D_NON_ADDITIVE(this->mHandle, position.x1, position.y1, position.z1, rotation.x1, rotation.y1, rotation.z1, unk.x1, unk.y1, unk.z1, scale.x1, scale.y1, scale.z1, 2);
}
void Scaleform::Render3DAdditive(const Vector31& position, const Vector31& rotation, const Vector31& unk, const Vector31& scale)
{
	GRAPHICS::DRAW_SCALEFORM_MOVIE_3D(this->mHandle, position.x1, position.y1, position.z1, rotation.x1, rotation.y1, rotation.z1, unk.x1, unk.y1, unk.z1, scale.x1, scale.y1, scale.z1, 2);
}



