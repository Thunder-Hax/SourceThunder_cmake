#include "stdafx.h"
#include "Scaleform.h"
#pragma warning(disable:4996)
#pragma execution_character_set("utf-8")

#include <vector>
#include <iostream> 
#include <string> 
#include <sstream>
#include <fstream> 
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>

#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

#include <cstdint> 


UINT8 Menu3::breakscroll = 0;
INT Menu3::SetSub_delayed = 0;
bool Menu3::bit_centre_title = 1, Menu3::bit_centre_options = 0, /*Menu::bit_centre_breaks = 1,*/
Menu3::gradients = 1/*, Menu::thin_line_over_screct = 1, Menu::bit_glare_test = 1*/;

void Menu::Drawing::Text(const char * text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center)
{
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_COLOUR(rgbaf.r, rgbaf.g, rgbaf.b, rgbaf.a);
	UI::SET_TEXT_FONT(rgbaf.f);
	UI::SET_TEXT_SCALE(size.w, size.h);
	UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
	UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((char*)text);
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(position.x, position.y);
}
bool Menu::FileExists(const std::string& fileName)
{
	struct stat buffer;
	Log::Msg("Debug File Exists Success");
	return (stat(fileName.c_str(), &buffer) == 0);
}

const std::string Menu::GetModulePath11(HMODULE module)
{
	std::string path;
	char buffer[MAX_PATH];
	GetModuleFileNameA(module, buffer, MAX_PATH);
	PathRemoveFileSpecA(buffer);
	path = buffer;
	Log::Msg("Debug Module Path Success");
	return path;
}

//int Menu::RegisterFile(const std::string& fullPath, const std::string& fileName)
//{
//	Log::Msg("Debug Register File");
//	int textureID = -1;
//	static uint32_t*(*pRegisterFile)(int*, const char*, bool, const char*, bool) = reinterpret_cast<decltype(pRegisterFile)>(Memory::pattern("48 89 5C 24 ? 48 89 6C 24 ? 48 89 7C 24 ? 41 54 41 56 41 57 48 83 EC 50 48 8B EA 4C 8B FA 48 8B D9 4D 85 C9").count(1).get(0).get<void>(0));
//	if (pRegisterFile(&textureID, fullPath.c_str(), true, fileName.c_str(), false))
//	{
//		Log::Msg("Debug Register File Success");
//		Log::Msg("Registered File %s with ID:%i", fullPath.c_str(), textureID);
//		return textureID;
//	}
//	Log::Msg("Debug Register File Error");
//	Log::Error("Failed to register %s", fullPath.c_str());
//	return 0;
//}

void Menu::Drawing::Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::Spriter2(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::Header(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

//void Menu::Drawing::NATIVE_DRAW_SPRITE(char* textureDict, char* textureName, float screenX, float screenY, float width, float height, float heading, int red, int green, int blue, int alpha)
//{
//	if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(textureDict))
//	{
//		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(textureDict, false);
//		std::this_thread::sleep_for(std::chrono::milliseconds(10));
//	}
//	else if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(textureDict))
//	{
//		GRAPHICS::DRAW_SPRITE(textureDict, textureName, screenX, screenY, width, height, heading, red, green, blue, alpha);
//	}
//}

void Menu::Drawing::NATIVE_DRAW_SPRITE1(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::NATIVE_DRAW_SPRITE2(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x, y, width, height, rotation, r, g, b, a);
	}
}

void Menu::Drawing::Vehicle(std::string Streamedtexture, std::string textureName, float x2, float y2, float width2, float height2, float rotation2, int r2, int g2, int b2, int a2)
{
		GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT((char*)Streamedtexture.c_str(), false);
	if (GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED((char*)Streamedtexture.c_str()))
	{
		GRAPHICS::DRAW_SPRITE((char*)Streamedtexture.c_str(), (char*)textureName.c_str(), x2, y2, width2, height2, rotation2, r2, g2, b2, a2);
	}
}

void Menu::Drawing::Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size)
{
	CHooking::draw_rect(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);
	/*GRAPHICS::DRAW_RECT(position.x, position.y, size.w, size.h, rgba.r, rgba.g, rgba.b, rgba.a);*/
}

float gGlareDir;
float conv360(float base, float min, float max)
{
	float fVar0;
	if (min == max) return min;
	fVar0 = max - min;
	base -= SYSTEM::ROUND(base - min / fVar0) * fVar0;
	if (base < min) base += fVar0;
	return base;
}
float DrawGlareX = 1.120f;
float DrawGlareY = 0.507f;
float DrawGlareScaleX = 0.949f;
float DrawGlareScaleY = 0.958f;

void Menu::DrawGlare(float pX, float pY, float scaleX, float scaleY, int red, int green, int blue, int alpha)
{
	if (!Features::stoppedglare)
	{ 
	int gGlareHandle = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");
	Vector3 rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	float dir = conv360(rot.z, 0, 360);
	if ((gGlareDir == 0 || gGlareDir - dir > 0.5) || gGlareDir - dir < -0.5)
	{
		gGlareDir = dir;
		GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(gGlareHandle, "SET_DATA_SLOT");
		GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_FLOAT(gGlareDir);
		GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	}
	GRAPHICS::DRAW_SCALEFORM_MOVIE(gGlareHandle, pX, pY, scaleX, scaleY, red, green, blue, alpha, 0);
	}
}

float Menu::Settings::menuY = 0.00f;
float Menu::Settings::menuX = 0.17f;
bool Menu::Settings::selectPressed = false;
bool Menu::Settings::leftPressed = false;
bool Menu::Settings::rightPressed = false;
bool firstopen = true;
int Menu::Settings::maxVisOptions = 16;
int Menu::Settings::currentOption = 0;
int Menu::Settings::optionCount = 0;
SubMenus Menu::Settings::currentMenu;
int Menu::Settings::menuLevel = 0;
int Menu::Settings::optionsArray[1000];
SubMenus Menu::Settings::menusArray[1000];

RGBAF Menu::Settings::count{ 255, 255, 255, 255, 6 };
RGBAF Menu::Settings::titleText{ 52, 46, 226, 200, 7 };
RGBA Menu::Settings::titleRect{ 37, 35, 35, 255 };
RGBAF Menu::Settings::optionText{ 0, 191, 255, 255, 6 };
RGBAF Menu::Settings::breakText{ 226, 46, 52, 200, 1 };
RGBAF Menu::Settings::arrow{ 255, 255, 255, 255, 3 };
RGBA Menu::Settings::optionRect{ 37, 35, 35, 175 };
RGBA Menu::Settings::scroller{ 52, 46, 226, 150 };
RGBAF Menu::Settings::integre{ 255, 255, 255, 255, 2 };
RGBA Menu::Settings::line{ 255, 255, 255, 255 };
//RGBA Menu::Settings::primary{ 255, 0, 0 };
//RGBA Menu::Settings::secondary{ 0, 255, 0 };
RGBA Menu::Settings::primary{ 0, 0, 0 };
RGBA Menu::Settings::secondary{ 255, 255, 255 };
RGBAF Menu::Settings::selectedTextClrs{ 255, 255, 255, 255, 6 };

void Menu::render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g, const int b)
{
	if (!Features::stoppedglare)
	{
		float g_glare_dir = 0;
		auto g_glare_handle = GRAPHICS::REQUEST_SCALEFORM_MOVIE(static_cast<char*>("MP_MENU_GLARE"));
		const auto rot = CAM::_GET_GAMEPLAY_CAM_ROT(2);
		const auto dir = conv360(rot.z, 0, 360);
		if ((g_glare_dir == 0 || g_glare_dir - dir > 0.5) || g_glare_dir - dir < -0.5)
		{
			g_glare_dir = dir;
			GRAPHICS::CALL_SCALEFORM_MOVIE_METHOD(g_glare_handle, static_cast<char*>("SET_DATA_SLOT"));
			GRAPHICS::_ADD_SCALEFORM_MOVIE_METHOD_PARAMETER_FLOAT(g_glare_dir);
			GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
		}
		GRAPHICS::DRAW_SCALEFORM_MOVIE(g_glare_handle, Features::menuXPositionX, y, sx, sy, r, g, b, 20, 0);
		/*GRAPHICS::_SCREEN_DRAW_POSITION_END();*/
		/*GRAPHICS::_SCREEN_DRAW_POSITION_RATIO;*/
		//GRAPHICS::SET_SCALEFORM_MOVIE_AS_NO_LONGER_NEEDED(&g_glare_handle);
	}
}
float fx = 0.516999f;
float fxx = 0.481000f;
float fxxx = 1.088999f;
float fxxxx = 0.902000f;
void Menu::Title(const char * title)
{
	Drawing::Text(title, Settings::titleText, { Settings::menuX, Settings::menuY + 0.095f }, { 0.85f, 0.85f }, true);
	Drawing::Rect(Settings::titleRect, { Settings::menuX, Settings::menuY + 0.1175f }, { 0.21f, 0.085f });
	if (!Features::stoppedglare)
	{
		render_globe(fx, fxx, fxxx, fxxxx, 255, 255, 255); //globe
	}
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	/*UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);*/
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_NEXT_CAMERA, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_CHARACTER_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_LIGHT, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_HEAVY, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MULTIPLAYER_INFO, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MELEE_ATTACK_ALTERNATE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_CIN_CAM, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_MAP_POI, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_PHONE, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_RADIO_WHEEL, true);
	CONTROLS::DISABLE_CONTROL_ACTION(2, INPUT_VEH_HEADLIGHT, true);
}

/*bool Menu::Option(const char * option)
{
Settings::optionCount++;
bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
{
Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
}
else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
{
Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
}
if (Settings::currentOption == Settings::optionCount)
{
if (Settings::selectPressed)
{
return true;
}
}
return false;
}
bool Menu::Option(const char * option, std::function<void()> function)
{
return false;
}
bool Menu::Break(const char * option)
{
Settings::optionCount++;
bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
{
Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, true);
Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
}
else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
{
Drawing::Text(option, Settings::breakText, { Settings::menuX, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, true);		//This was the broken draw btw
//This was the broken draw btw 																																			//This was the broken draw btw
Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });				//This was the broken draw btw
}
return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub)
{
Option(option);

if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
Drawing::Text("", Settings::titleText, { Settings::menuX + 0.099f, Settings::optionCount * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
Drawing::Text("", Settings::titleText, { Settings::menuX + 0.099f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.35f, 0.35f }, true);

if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
MenuLevelHandler::MoveMenu(newSub);
return true;
}
return false;
}

bool Menu::MenuOption(const char * option, SubMenus newSub, std::function<void()> function)
{
return false;
}*/

//bool Menu::Option(const char * option)
//{
//	Settings::optionCount++;
//	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
//	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
//	{
//		!onThis ? Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
//		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
//		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
//	{
//		!onThis ? Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
//		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
//		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
//		Drawing::Rect(Settings::optionRect, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
//		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
//	}
//	if (Settings::currentOption == Settings::optionCount)
//	{
//		if (Settings::selectPressed)
//		{
//			return true;
//		}
//	}
//	return false;
//}

bool Menu::Option(const char * option)
{
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.101f, Settings::menuY + (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.101f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
	}
	if (Settings::currentOption == Settings::optionCount)
	{
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}

bool Menu::OptionCars(const char* option)
{
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.101f, Settings::menuY + (Settings::optionCount) * 0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount) * 0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX, Settings::menuY + (Settings::optionCount) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
		
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { Settings::menuX - 0.101f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false) : NULL;
		Drawing::Text(option, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, false);
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
		onThis ? Drawing::Rect(Settings::scroller, { Settings::menuX,  Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.1415f }, { 0.21f, 0.035f }) : NULL;
	}
	if (Settings::currentOption == Settings::optionCount)
	{
		std::string carstring;
		std::stringstream sstt;
		sstt << option;
		sstt >> carstring;
		initialize::pictureofcars(carstring);
		onThis ? initialize::showpicturesofcars() : NULL;
		if (Settings::selectPressed)
		{
			return true;
		}
	}
	return false;
}

bool Menu::Option(const char * option, std::function<void()> function)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::carsOptionSpawn(const char* option, std::function<void()> function)
{
	OptionCars(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Break(const char * option)
{
	Settings::optionCount++;
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, Settings::menuY + (Settings::optionCount)*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		Drawing::Text(option, Settings::breakText, { Settings::menuX, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.125f }, { Features::zeropointquarantecinq, Features::zeropointquarantecinq }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX,  Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1415f }, { 0.21f, 0.035f });
	}
	return false;
}
bool Menu::MenuOption(const char * option, SubMenus newSub)
{
	Option(option);
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text("~ws~", Settings::titleText, { Settings::menuX + 0.099f, Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text("~ws~", Settings::titleText, { Settings::menuX + 0.099f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

bool Menu::MenuOption(const char * option, SubMenus newSub, std::function<void()> function)
{
	MenuOption(option, newSub);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

//if (Global_1666668[iParam0 /*5*/].f_2 != 0)
//CHAR_DEFAULT


bool Menu::MenuOptions2(const char * option, SubMenus newSub, int pid)
{
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1379953 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1383710 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1385294 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1389078 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1389221 + 2
	//StringCopy(&cVar0, "CHAR_DEFAULT", 64);
	//if (Global_1391551[iParam0 /*5*/].f_2 != 0)
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1391551 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1656652 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1656661 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1660783 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1666668 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1666485 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1680805 + 2		
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1681225 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1686330 + 2
#define SCORE_BOARD_HEADSHOT_GLOBAL 1686471 + 2 //1686523
	
	char* GPic = "CHAR_MULTIPLAYER";
		/*int index = 1379955;*/
	const int index = SCORE_BOARD_HEADSHOT_GLOBAL;
		for (int i = 0; i <= 150; i += 5)
		{
			__int64* base = globalHandle(index + i).Get<__int64>();
			int playerId = (int)*base;
			/*int playerId = *base;*/
			if (playerId == pid)
			{
				__int64* logo = globalHandle(index + i + 1).Get<__int64>();
				int logos = (int)*logo;
				GPic = PED::GET_PEDHEADSHOT_TXD_STRING(/**logo*/logos);
				break;
			}
			if (playerId == -1)
				break;
		}
	Option(option);
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Spriter(GPic, GPic, (Settings::menuX + 0.078f), (Settings::optionCount * 0.035f + 0.142f), 0.015f, 0.027f, 0, 255, 255, 255, 255);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
	Drawing::Spriter(GPic, GPic, (Settings::menuX + 0.078f), ((Settings::optionCount - (Settings::currentOption - 16))* 0.035f + 0.142f), 0.015f, 0.027f, 0, 255, 255, 255, 255);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		MenuLevelHandler::MoveMenu(newSub);
		return true;
	}
	return false;
}

bool Menu::Toggle(const char * option, bool & b00l)
{
	//Option(option);
	//if (b00l)
	//{
	//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	//		Drawing::Text(b00l ? "~italic~~p~Activated" : "~italic~~r~OFF", Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true);
	//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
	//		Drawing::Text(b00l ? "~italic~~p~Activated" : "~italic~~r~OFF", Settings::optionText, { Settings::menuX + 0.069f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true);
	//}
	//else
	//{
	//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	//		Drawing::Text(b00l ? "~italic~~p~Activated" : "~italic~~r~OFF", Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true);
	//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
	//		Drawing::Text(b00l ? "~italic~~p~Activated" : "~italic~~r~OFF", Settings::optionText, { Settings::menuX + 0.068f, Settings::optionCount * 0.035f + 0.128f }, { 0.40f, 0.40f }, true);
	//}
	//Option(option);
	//if (b00l)
	//{
	//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	//		Drawing::Spriter("commonmenu", b00l ? "mp_specitem_weed" : "mp_specitem_weed", (Settings::menuX + 0.078f), (Settings::optionCount * 0.035f + 0.142f), 0.015f, 0.027f, 0, b00l ? 0 : 255, b00l ? 255 : 0, 0, 255);
	//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
	//		Drawing::Spriter("commonmenu", b00l ? "mp_specitem_weed" : "mp_specitem_weed", (Settings::menuX + 0.078f), ((Settings::optionCount - (Settings::currentOption - 16))* 0.035f + 0.142f), 0.015f, 0.027f, 0, b00l ? 0 : 255, b00l ? 255 : 0, 0, 255);
	//}
	//else
	//{
	//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	//		Drawing::Spriter("commonmenu", b00l ? "mp_specitem_weed" : "mp_specitem_weed", (Settings::menuX + 0.078f), (Settings::optionCount * 0.035f + 0.142f), 0.015f, 0.027f, 0, b00l ? 0 : 255, b00l ? 255 : 0, 0, 255);
	//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
	//		Drawing::Spriter("commonmenu", b00l ? "mp_specitem_weed" : "mp_specitem_weed", (Settings::menuX + 0.078f), ((Settings::optionCount - (Settings::currentOption - 16))* 0.035f + 0.142f), 0.015f, 0.027f, 0, b00l ? 0 : 255, b00l ? 255 : 0, 0, 255);
	//}
	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
	Option(option);
	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Spriter("commonmenu", b00l ? "mp_specitem_weed" : "mp_specitem_weed", (Settings::menuX + 0.078f), Settings::menuY + (Settings::optionCount * 0.035f + 0.142f), 0.015f, 0.027f, 0, b00l ? 0 : 255, b00l ? 255 : 0, 0, 255);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Spriter("commonmenu", b00l ? "mp_specitem_weed" : "mp_specitem_weed", (Settings::menuX + 0.078f), Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16))* 0.035f + 0.142f), 0.015f, 0.027f, 0, b00l ? 0 : 255, b00l ? 255 : 0, 0, 255);
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		b00l ^= 1;
		return true;
	}
	return false;
}

/*bool Menu::Toggle(const char * option, bool & b00l, std::function<void()> function)
{
return false;
}*/
bool Menu::Toggle(const char * option, bool & b00l, std::function<void()> function)
{
	Toggle(option, b00l);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Settings::DrawTextOutline = false;
bool Menu2::ListVector(const char* option, /*std::*/Menu2::vector<char*> Vector, int& position)
{
	constexpr static const VECTOR22_22 textSize = { 0.45f, 0.45f };
	bool onThis = Menu::Settings::currentOption == Menu::Settings::optionCount + 1 ? true : false;
	Menu::Option("");

	if (Menu::Settings::optionCount == Menu::Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Menu::Settings::rightPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Menu::Settings::leftPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Menu::Settings::currentOption <= Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::maxVisOptions) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));
		if (SelectedChar == "NULL") SelectedChar = Vector[position];

		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_FONT(6);
		UI::SET_TEXT_SCALE(textSize.w2, textSize.h2);
		UI::SET_TEXT_CENTRE(false);
		if (Menu::Settings::DrawTextOutline) {
			UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
			UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
			UI::SET_TEXT_OUTLINE();
		}
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		std::string s = option;
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Menu::Tools::StringToChar(s + " <" + SelectedChar + ">"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Menu::Settings::menuX - 0.09f, Menu::Settings::optionCount * 0.035f + 0.125f);
	}
	else if (Menu::Settings::optionCount > Menu::Settings::currentOption - Menu::Settings::maxVisOptions && Menu::Settings::optionCount <= Menu::Settings::currentOption) {
		std::string SelectedChar
			= UI::_GET_LABEL_TEXT(VEHICLE::GET_DISPLAY_NAME_FROM_VEHICLE_MODEL($(Vector[position])));
		if (SelectedChar == "NULL") SelectedChar = Vector[position];

		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_FONT(6);
		UI::SET_TEXT_SCALE(textSize.w2, textSize.h2);
		UI::SET_TEXT_CENTRE(false);
		UI::SET_TEXT_DROPSHADOW(1, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 0);
		UI::SET_TEXT_OUTLINE();
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		std::string s = option;
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(Menu::Tools::StringToChar(s + " <" + SelectedChar + ">"));
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(Menu::Settings::menuX - 0.09f, (Menu::Settings::optionCount - (Menu::Settings::currentOption - Menu::Settings::maxVisOptions)) * 0.035f + 0.125f);
	}

	if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::selectPressed) return true;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::leftPressed) return false;
	else if (Menu::Settings::optionCount == Menu::Settings::currentOption && Menu::Settings::rightPressed) return false;
	return false;
}
////bool Menu::StringOption(const char* option, int* position, const std::vector<std::string>& options)
bool Menu::StringOption(const char* option, int& position, const std::vector<std::string>& options, std::function<void()> function)
{
	//Option(option);

	//if (Settings::optionCount == Settings::currentOption) {
	//	if (Settings::leftPressed) {
	//		position = (position + 1 < options.size()) ? position + 1 : 0;
	//		return true;
	//	}
	//	if (Settings::rightPressed) {
	//		position = (position > 0) ? position - 1 : options.size() - 1;
	//		return true;
	//	}
	//}
	static int lastOptionCount = 0;
	static int lastCurrentOption = 0;

	Option(option);

	if (lastOptionCount != Settings::optionCount || lastCurrentOption != Settings::currentOption) {
		lastOptionCount = Settings::optionCount;
		lastCurrentOption = Settings::currentOption;
	}

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			position = (position + 1) % options.size();
			/**position = (*position + 1) % options.size();*/
		}
		if (Settings::rightPressed) {
			position = (position - 1 + options.size()) % options.size();
			//*position = (*position - 1 + options.size()) % options.size();
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + options[position] + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + options[position] + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && (Settings::selectPressed || Settings::leftPressed || Settings::rightPressed)) {
		if (Settings::selectPressed)
		{
			if (function) {
				function();
			}
		}
		return Settings::optionCount == Settings::currentOption && (Settings::selectPressed || Settings::leftPressed || Settings::rightPressed);
	}
	else {
		return false;
	}
}

bool Menu::Int(const char * option, int & _int, int min, int max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int++ : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int-- : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_int < max ? _int += step : _int = min;
		}
		if (Settings::rightPressed) {
			_int >= min ? _int -= step : _int = max;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar("< " + std::to_string(_int) + " >"), Settings::integre, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
/*bool Menu::Int(const char * option, int & _int, int min, int max, std::function<void()> function)
{
return false;
}*/
bool Menu::Int(const char * option, int & _int, int min, int max, std::function<void()> function)
{
	Int(option, _int, min, max);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Int(const char * option, int & _int, int min, int max, int step, std::function<void()> function)
{
	Int(option, _int, min, max, step);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}

bool Menu::Float2(const char* option, float& _float, float min, float max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.1f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.1f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Float3(const char* option, float& _float, float min, float max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 1.0f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 1.0f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Float1(const char* option, float& _float, float min, float max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.01f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.01f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}

#pragma warning(disable: 4244)
bool Menu::Float(const char * option, float & _float, float min, float max)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= 0.01f;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += 0.01f;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::Float(const char * option, float & _float, float min, float max, float step)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		if (Settings::leftPressed) {
			_float <= min ? _float = max : _float -= step;
		}
		if (Settings::rightPressed) {
			_float >= max ? _float = min : _float += step;
		}
		_float < min ? _float = max : _float > max ? _float = min : NULL;
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.128f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(_float)), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { Features::zeropointtrentedeux, Features::zeropointtrentedeux }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4244)
bool Menu::Float(const char * option, float & _float, int min, int max, std::function<void()> function)
{
	Float(option, _float, (float)min, (float)max);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Float(const char * option, float & _float, int min, int max, int step, std::function<void()> function)
{
	Float(option, _float, (float)min, (float)max, (float)step);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
#pragma warning(disable: 4267)
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		int max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::IntVector(const char * option, std::vector<int> Vector, int & position, std::function<void()> function)
{
	IntVector(option, Vector, position);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar(std::to_string(Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::FloatVector(const char * option, std::vector<float> Vector, int & position, std::function<void()> function)
{
	FloatVector(option, Vector, position);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(Tools::StringToChar((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
bool Menu::StringVector(const char * option, std::vector<std::string> Vector, int & position, std::function<void()> function)
{
	StringVector(option, Vector, position);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption) {
		size_t max = Vector.size() - 1;
		int min = 0;
		if (Settings::leftPressed) {
			position >= 1 ? position-- : position = max;
		}
		if (Settings::rightPressed) {
			position < max ? position++ : position = min;
		}
	}

	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + Settings::optionCount * 0.035f + 0.125f }, { 0.5f, 0.5f }, true);
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
		Drawing::Text(((Vector[position])), Settings::optionText, { Settings::menuX + 0.068f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.12f }, { 0.5f, 0.5f }, true);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) return true;
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) return true;
	return false;
}
#pragma warning(default: 4267)
bool Menu::StringVector(const char * option, std::vector<char*> Vector, int & position, std::function<void()> function)
{
	StringVector(option, Vector, position);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::leftPressed) {
		function();
		return true;
	}
	else if (Settings::optionCount == Settings::currentOption && Settings::rightPressed) {
		function();
		return true;
	}
	return false;
}
bool Menu::Teleport(const char * option, Vector3 coords)
{
	Option(option);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		Entity handle = PLAYER::PLAYER_PED_ID();
		PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? handle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : PLAYER::PLAYER_PED_ID();
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(handle, coords.x, coords.y, coords.z, false, false, false);
		return true;
	}
	return false;
}
bool Menu::Teleport(const char * option, Vector3 coords, std::function<void()> function)
{
	Teleport(option, coords);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}
void Menu::info(const char * info)
{
	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + 17 * 0.035f + 0.1600f }, { 0.25f, 0.25f }, false); }
	}
	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
	{
		if (bool onThis = true) { Drawing::Text(info, Settings::optionText, { Settings::menuX - 0.100f, Settings::menuY + (Settings::optionCount - (Settings::currentOption - 16))*0.035f + 0.1300f }, { 0.25f, 0.25f }, false); }
	}
}
void Menu::End()
{
	int opcount = Settings::optionCount;
	int currop = Settings::currentOption;
	if (opcount >= 16) {
		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, Settings::menuY + 17 * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, Settings::menuY + 17 * 0.035f + 0.1415f }, { 0.21f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX, Settings::menuY + 17 * 0.035f + 0.1235f }, { 0.21f, 0.002f });
		Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, Settings::menuY + ((16 + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
	}
	else if (opcount > 0) {
		Drawing::Text(Tools::StringToChar(std::to_string(currop) + " / " + std::to_string(opcount)), Settings::count, { Settings::menuX + 0.078f, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.125f }, { 0.35f, 0.35f }, true);
		Drawing::Rect(Settings::optionRect, { Settings::menuX, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1415f }, { 0.21f, 0.035f });
		Drawing::Rect(Settings::line, { Settings::menuX, Settings::menuY + (Settings::optionCount + 1) * 0.035f + 0.1235f }, { 0.21f, 0.002f });
		Drawing::Spriter("commonmenu", "shop_arrows_upanddown", Settings::menuX, Settings::menuY + ((Settings::optionCount + 1) * 0.035f + 0.140f), 0.020f, 0.035f, 180, Settings::line.r, Settings::line.g, Settings::line.b, Settings::line.a);
	}
}

int IconNotification(char *text, char *text2, char *Subject)
{
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG("CHAR_GANGAPP", "CHAR_GANGAPP", false, 7, text2, Subject, 1.0, "___Menu");
	return CHooking::draw_notification(1, 1);
}
void PlaySoundFrontend_default(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "HUD_FRONTEND_DEFAULT_SOUNDSET", 0);
}
void PlaySoundFrontend_default2(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_BIOLAB_PREP_HACKING_SOUNDS", 0);
}

void PlaySoundFrontend_default3(char* sound_name)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound_name, "DLC_HEIST_HACKING_SNAKE_SOUNDS", 0);
}
//int Menu::Settings::keyPressDelay = 200;
//int Menu::Settings::keyPressDelay = 400;
int Menu::Settings::keyPressPreviousTick = GetTickCount();
//int Menu::Settings::keyPressDelay2 = 100;
int Menu::Settings::keyPressDelay2 = 200;
int Menu::Settings::keyPressPreviousTick2 = GetTickCount();
//int Menu::Settings::keyPressDelay3 = 140;
int Menu::Settings::keyPressDelay3 = 280;
int Menu::Settings::keyPressPreviousTick3 = GetTickCount();

int Menu::Settings::openKey = VK_MULTIPLY;
int Menu::Settings::backKey = VK_NUMPAD0;
int Menu::Settings::upKey = VK_NUMPAD8;
int Menu::Settings::downKey = VK_NUMPAD2;
int Menu::Settings::leftKey = VK_NUMPAD4;
int Menu::Settings::rightKey = VK_NUMPAD6;
int Menu::Settings::selectKey = VK_NUMPAD5;
int Menu::Settings::arrowupKey = VK_UP;
int Menu::Settings::arrowdownKey = VK_DOWN;
int Menu::Settings::arrowleftKey = VK_LEFT;
int Menu::Settings::arrowrightKey = VK_RIGHT;
int Menu::Settings::enterKey = VK_RETURN;
int Menu::Settings::deleteKey = VK_BACK;

#pragma endregion
bool Menu::Settings::menuclosed = false;

Thunder* light_N;

void Thunder::ThunderVoid()
{
	if (Menu::Settings::menuLevel == 0)/*Menu::Settings::currentOption == 0*/
	{
		Menu::Settings::menuclosed = false;
	}
	else
	{
		Menu::Settings::menuclosed = true;
	}
}

//#include <sysinfoapi.h>
//
//unsigned long long keyHoldStartTick = 0;
//bool isMenuKeyPressed = false; // Variable pour suivre l'état de la touche du menu
//bool isMenuKeyHeld = false; // Variable pour suivre l'état de maintien de la touche du menu
//int keyHoldDelay = 1000;
//bool Menu::Settings::controllerinput = true;
//void Menu::Checks::Controlls()
//{
//	Settings::selectPressed = false;
//	Settings::leftPressed = false;
//	Settings::rightPressed = false;
//
//		/*if ((!isMenuKeyPressed || (isMenuKeyHeld && (GetTickCount64() - Settings::keyPressPreviousTick > keyHoldDelay && GetTickCount64() - keyHoldStartTick > 2)))) {*/
//		if (GetTickCount64() - Settings::keyPressPreviousTick > Settings::keyPressDelay) {
//			if (GetTickCount64() - Settings::keyPressPreviousTick2 > Settings::keyPressDelay2) {
//				if (GetTickCount64() - Settings::keyPressPreviousTick3 > Settings::keyPressDelay3) {
//					if (IsKeyPressed(Menu2::OpenMenu)/* || IsKeyPressed(Features::vkmultiply)*/ || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
//						Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
//						Settings::keyPressPreviousTick = /*(unsigned int)*/(GetTickCount64());
//						isMenuKeyPressed = true; // Mettez à jour l'état de la touche pour indiquer qu'elle a été enfoncée
//						isMenuKeyHeld = false;
//					}
//					else if (IsKeyPressed(Menu2::OpenMenu0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput) {
//						Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
//						if (Settings::menuLevel > 0)
//							PlaySoundFrontend_default("BACK");
//						Settings::keyPressPreviousTick = (unsigned int)(GetTickCount64());
//						isMenuKeyPressed = true; // Mettez à jour l'état de la touche pour indiquer qu'elle a été enfoncée
//						isMenuKeyHeld = false;
//					}
//					else if (IsKeyPressed(Menu2::OpenMenu8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput) {
//						Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
//						if (Settings::menuLevel > 0)
//							PlaySoundFrontend_default("NAV_UP_DOWN");
//
//						Settings::keyPressPreviousTick2 = (unsigned int)(GetTickCount64());
//						isMenuKeyPressed = true; // Mettez à jour l'état de la touche pour indiquer qu'elle a été enfoncée
//						isMenuKeyHeld = false;
//					}
//					else if (IsKeyPressed(Menu2::OpenMenu2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput) {
//						Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
//						if (Settings::menuLevel > 0)
//							PlaySoundFrontend_default("NAV_UP_DOWN");
//
//						Settings::keyPressPreviousTick2 = (unsigned int)(GetTickCount64());
//						isMenuKeyPressed = true; // Mettez à jour l'état de la touche pour indiquer qu'elle a été enfoncée
//						isMenuKeyHeld = false;
//					}
//					else if (IsKeyPressed(Menu2::OpenMenu6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput) {
//						Settings::leftPressed = true;
//						if (Settings::menuLevel > 0)
//							PlaySoundFrontend_default("NAV_UP_DOWN");
//
//						Settings::keyPressPreviousTick3 = (unsigned int)(GetTickCount64());
//						isMenuKeyPressed = true; // Mettez à jour l'état de la touche pour indiquer qu'elle a été enfoncée
//						isMenuKeyHeld = false;
//					}
//					else if (IsKeyPressed(Menu2::OpenMenu4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput) {
//						Settings::rightPressed = true;
//						if (Settings::menuLevel > 0)
//							PlaySoundFrontend_default("NAV_UP_DOWN");
//
//						Settings::keyPressPreviousTick3 = (unsigned int)(GetTickCount64());
//						isMenuKeyPressed = true; // Mettez à jour l'état de la touche pour indiquer qu'elle a été enfoncée
//						isMenuKeyHeld = false;
//					}
//					else if (IsKeyPressed(Menu2::OpenMenu5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput) {
//						Settings::selectPressed = true;
//						if (Settings::menuLevel > 0)
//							PlaySoundFrontend_default("SELECT");
//
//						Settings::keyPressPreviousTick = (unsigned int)(GetTickCount64());
//						isMenuKeyPressed = true; // Mettez à jour l'état de la touche pour indiquer qu'elle a été enfoncée
//						isMenuKeyHeld = false;
//					}
//				}
//			}
//		}
//	//}
//	//else {
//	//	// Si la touche est enfoncée et le délai de maintien est atteint, marquez-la comme maintenue
//	//	if (!isMenuKeyHeld && GetTickCount64() - Settings::keyPressPreviousTick2 > keyHoldDelay) {
//	//		Settings::keyPressPreviousTick = (unsigned int)(GetTickCount64());
//	//		isMenuKeyHeld = true;
//	//		// Effectuez les actions appropriées pour la touche maintenue ici
//	//		keyHoldStartTick = GetTickCount64(); // Enregistrez l'instant de départ du maintien de la touche
//	//	}
//	//}
//	//	// Si la touche a été enfoncée précédemment, mais n'est plus enfoncée maintenant, réinitialisez son état
//	//	if (!(IsKeyPressed(Menu2::OpenMenu) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput)
//	//		&& !(IsKeyPressed(Menu2::OpenMenu0) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput)
//	//		&& !(IsKeyPressed(Menu2::OpenMenu8) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput)
//	//		&& !(IsKeyPressed(Menu2::OpenMenu2) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput)
//	//		&& !(IsKeyPressed(Menu2::OpenMenu6) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput)
//	//		&& !(IsKeyPressed(Menu2::OpenMenu4) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput)
//	//		&& !(IsKeyPressed(Menu2::OpenMenu5) || CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput)) {
//	//		isMenuKeyPressed = false; // Réinitialisez l'état de la touche pour indiquer qu'elle n'est plus enfoncée
//	//		isMenuKeyHeld = false; // Réinitialisez l'état de maintien de la touche
//	//	}
//
//
//	Settings::optionCount = 0;
//}

#include <sysinfoapi.h>

unsigned long long Menu::Settings::keyHoldStartTick = 0;
bool Menu::Settings::isMenuKeyPressed = false;
bool Menu::Settings::isMenuKeyHeld = false;
int Menu::Settings::keyPressDelay = 400; // Délai lorsque vous appuyez brièvement sur un bouton
int Menu::Settings::keyHoldDelay = 100; // Délai lorsque vous maintenez un bouton enfoncé
int Menu::Settings::keyPressCooldown = 1000; // Temps de refroidissement entre les pressions successives
bool Menu::Settings::controllerinput = true;

void Menu::Checks::Controlls()
{
	Settings::selectPressed = false;
	Settings::leftPressed = false;
	Settings::rightPressed = false;

	// Vérification de l'appui sur les boutons
	if (!Menu::Settings::isMenuKeyPressed || (Menu::Settings::isMenuKeyHeld && GetTickCount64() - Menu::Settings::keyHoldStartTick > Menu::Settings::keyHoldDelay))
	{
		if (IsKeyPressed(Menu2::OpenMenu) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)) && Settings::controllerinput)
		{
			Settings::menuLevel == 0 ? MenuLevelHandler::MoveMenu(SubMenus::mainmenu) : Settings::menuLevel == 1 ? MenuLevelHandler::BackMenu() : NULL;
			Settings::keyPressPreviousTick = GetTickCount64();
			Menu::Settings::isMenuKeyPressed = true;
			Menu::Settings::isMenuKeyHeld = false;
		}
		else if (IsKeyPressed(Menu2::OpenMenu0) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput))
		{
			if (!Menu::Settings::isMenuKeyPressed || (GetTickCount64() - Settings::keyPressPreviousTick > Menu::Settings::keyPressCooldown))
			{
				Settings::menuLevel > 0 ? MenuLevelHandler::BackMenu() : NULL;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("BACK");
				Settings::keyPressPreviousTick = GetTickCount64();
				Menu::Settings::isMenuKeyPressed = true;
				Menu::Settings::isMenuKeyHeld = false;
			}
		}
		else if (IsKeyPressed(Menu2::OpenMenu8) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput))
		{
			Settings::currentOption > 1 ? Settings::currentOption-- : Settings::currentOption = Settings::optionCount;
			if (Settings::menuLevel > 0)
				PlaySoundFrontend_default("NAV_UP_DOWN");

			Settings::keyPressPreviousTick = GetTickCount64();
			Menu::Settings::isMenuKeyPressed = true;
			Menu::Settings::isMenuKeyHeld = false;
		}
		else if (IsKeyPressed(Menu2::OpenMenu2) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput))
		{
			Settings::currentOption < Settings::optionCount ? Settings::currentOption++ : Settings::currentOption = 1;
			if (Settings::menuLevel > 0)
				PlaySoundFrontend_default("NAV_UP_DOWN");

			Settings::keyPressPreviousTick = GetTickCount64();
			Menu::Settings::isMenuKeyPressed = true;
			Menu::Settings::isMenuKeyHeld = false;
		}
		else if (IsKeyPressed(Menu2::OpenMenu6) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput))
		{
			Settings::leftPressed = true;
			if (Settings::menuLevel > 0)
				PlaySoundFrontend_default("NAV_UP_DOWN");

			Settings::keyPressPreviousTick = GetTickCount64();
			Menu::Settings::isMenuKeyPressed = true;
			Menu::Settings::isMenuKeyHeld = false;
		}
		else if (IsKeyPressed(Menu2::OpenMenu4) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput))
		{
			Settings::rightPressed = true;
			if (Settings::menuLevel > 0)
				PlaySoundFrontend_default("NAV_UP_DOWN");

			Settings::keyPressPreviousTick = GetTickCount64();
			Menu::Settings::isMenuKeyPressed = true;
			Menu::Settings::isMenuKeyHeld = false;
		}
		else if (IsKeyPressed(Menu2::OpenMenu5) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput))
		{
			if (!Settings::selectPressed || (GetTickCount64() - Menu::Settings::keyHoldStartTick > Menu::Settings::keyHoldDelay))
			{
				Settings::selectPressed = true;
				if (Settings::menuLevel > 0)
					PlaySoundFrontend_default("SELECT");

				Settings::keyPressPreviousTick = GetTickCount64();
				Menu::Settings::isMenuKeyPressed = true;
				Menu::Settings::isMenuKeyHeld = false;
			}
		}
	}
	else
	{
		// Si la touche est enfoncée et le délai de maintien est atteint, marquez-la comme maintenue
		if (!Menu::Settings::isMenuKeyHeld && GetTickCount64() - Settings::keyPressPreviousTick > Menu::Settings::keyHoldDelay)
		{
			Menu::Settings::isMenuKeyHeld = true;
			Menu::Settings::keyHoldStartTick = GetTickCount64(); // Enregistrez l'instant de départ du maintien de la touche
		}
	}

	// Si la touche a été enfoncée précédemment, mais n'est plus enfoncée maintenant, réinitialisez son état
	if (!(IsKeyPressed(Menu2::OpenMenu) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlScriptRB) && CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight)) && Settings::controllerinput)
		&& !(IsKeyPressed(Menu2::OpenMenu0) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendCancel) && Settings::controllerinput))
		&& !(IsKeyPressed(Menu2::OpenMenu8) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendUp) && Settings::controllerinput))
		&& !(IsKeyPressed(Menu2::OpenMenu2) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendDown) && Settings::controllerinput))
		&& !(IsKeyPressed(Menu2::OpenMenu6) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneRight) && Settings::controllerinput))
		&& !(IsKeyPressed(Menu2::OpenMenu4) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlPhoneLeft) && Settings::controllerinput))
		&& !(IsKeyPressed(Menu2::OpenMenu5) || (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, ControlFrontendAccept) && Settings::controllerinput)))
	{
		Menu::Settings::isMenuKeyPressed = false; // Réinitialisez l'état de la touche pour indiquer qu'elle n'est plus enfoncée
		Menu::Settings::isMenuKeyHeld = false; // Réinitialisez l'état de maintien de la touche
	}

	Settings::optionCount = 0;
}

#pragma warning(default : 4018)
void Menu::MenuLevelHandler::MoveMenu(SubMenus menu)
{
	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
	Settings::menuLevel++;
	Settings::currentMenu = menu;
	Settings::currentOption = 1;
	light_N->ThunderVoid();
}

void Menu::MenuLevelHandler::BackMenu()
{
	Settings::menuLevel--;
	Settings::currentMenu = Settings::menusArray[Settings::menuLevel];
	Settings::currentOption = Settings::optionsArray[Settings::menuLevel];
	light_N->ThunderVoid();
}

char * Menu::Tools::StringToChar(std::string string)
{
	return _strdup(string.c_str());
}

void Menu::Files::WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}

std::string Menu::Files::ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), "NULL", buf, 100, file.c_str());
	return (std::string)buf;
}

void Menu::Files::WriteIntToIni(int intValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni(std::to_string(intValue), file, app, key);
}

int Menu::Files::ReadIntFromIni(std::string file, std::string app, std::string key)
{
	return std::stoi(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key)
{
	WriteStringToIni((std::to_string(floatValue)), file, app, key);
}

float Menu::Files::ReadFloatFromIni(std::string file, std::string app, std::string key)
{
	return std::stof(ReadStringFromIni(file, app, key));
}

void Menu::Files::WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key)
{
	WriteStringToIni(b00l ? "true" : "false", file, app, key);
}

bool Menu::Files::ReadBoolFromIni(std::string file, std::string app, std::string key)
{
	return ReadStringFromIni(file, app, key) == "true" ? true : false;
}

void Menu::Vehicle(std::string texture1, std::string texture2)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.24f, Settings::menuY + 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); }
	}
	else { if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.24f, Settings::menuY + 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); } }
}
void Menu::Speedometer(char* text)
{
	Drawing::Text(text, Settings::titleText, { 0.84f, 0.8800f }, { 0.70f, 0.70f }, false);
}
void Menu::fps(char* text)
{
	Drawing::Text(text, Settings::optionText, { 0.84f, 0.050f }, { 0.70f, 0.70f }, false);
}
void Menu::AddSmallTitle(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallTitle02(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{	
		/*Drawing::Text(text, Settings::titleText, { Settings::menuX + Features::zeropointcentsoixantequinze, Features::zeropointzeroquatrevinghtdix }, { Features::zeropointquatrecentvingtcinq, Features::zeropointquatrecentvingtcinq }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + Features::zeropointcentsoixantequinze, Features::zeropointmillecentsoixantequinzee - Features::zeropointzerodixneuf, Features::zeropointcentquinze, Features::zeropointzeroquarantecinq, Features::centquatrevingt, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);*/
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.295f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.295f, Settings::menuY + 0.1175f - 0.019f, 0.125f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		/*Drawing::Text(text, Settings::titleText, { Settings::menuX - Features::zeropointcentsoixantequinze, Features::zeropointzeroquatrevinghtdix }, { Features::zeropointquatrecentvingtcinq, Features::zeropointquatrecentvingtcinq }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - Features::zeropointcentsoixantequinze, Features::zeropointmillecentsoixantequinzee - Features::zeropointzerodixneuf, Features::zeropointcentquinze, Features::zeropointzeroquarantecinq, Features::centquatrevingt, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);*/
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.295f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.295f, Settings::menuY + 0.1175f - 0.019f, 0.125f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

float title::zeropointcentsoixantequinze = 0.175f;
float title::zeropointzeroquatrevingtdix = 0.090f;
float title::zeropointquatrecentvingtcinq = 0.425f;
float title::zeropointzerodixneuf = 0.019f;
float title::zeropointcentquinze = 0.115f;
float title::zeropointzeroquarantecinq = 0.045f;
float title::zeropointzerotrentecinq = 0.035f;
float title::zeropointmillecentsoixantequinze = 0.1175f;
int title::centquatrevingt = 180;
int title::deuxcentcinquantecinqr = 255;
int title::deuxcentcinquantecinqg = 255;
int title::deuxcentcinquantecinqb = 255;
int title::deuxcentcinquantecinqa = 255;


void Menu::AddSmallTitle5(const char * option, int pid)
{
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1379953 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1383710 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1385294 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1389078 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1389221 + 2	
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1391551 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1656652 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1656661 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1660783 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1666668 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1666485 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1680805 + 2		
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1681225 + 2
//#define SCORE_BOARD_HEADSHOT_GLOBAL 1686330 + 2
#define SCORE_BOARD_HEADSHOT_GLOBAL 1686471 + 2 //1686523

	char* GPic = "CHAR_MULTIPLAYER";
	const int index = SCORE_BOARD_HEADSHOT_GLOBAL;
	/*int index = 1379955;*/
	for (int i = 0; i <= 150; i += 5)
	{
		__int64* base = globalHandle(index + i).Get<__int64>();
		int playerId = (int)*base;
		/*int playerId = *base;*/
		if (playerId == pid)
		{
			__int64* logo = globalHandle(index + i + 1).Get<__int64>();
			int logos = (int)*logo;
			GPic = PED::GET_PEDHEADSHOT_TXD_STRING(/**logo*/logos);
			break;
		}
		if (playerId == -1)
			break;
	}
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(option, Settings::titleText, { Settings::menuX + title::zeropointcentsoixantequinze, Settings::menuY + title::zeropointzeroquatrevingtdix }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + title::zeropointcentsoixantequinze, Settings::menuY + -title::zeropointzerodixneuf, title::zeropointcentquinze, title::zeropointzeroquarantecinq, title::centquatrevingt, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
		Menu::Drawing::Spriter(GPic, GPic, (Menu::Settings::menuX + Features::deuxzerosepthuit), Settings::menuY + (Settings::optionCount * title::zeropointzerotrentecinq + Features::zerounquatredeux), Features::deuxzeroquinze, Features::deuxzerodeuxsept, 0, title::deuxcentcinquantecinqr, title::deuxcentcinquantecinqg, title::deuxcentcinquantecinqb, title::deuxcentcinquantecinqa);
	}
	else
	{
		Drawing::Text(option, Settings::titleText, { Settings::menuX - title::zeropointcentsoixantequinze, Settings::menuY + title::zeropointzeroquatrevingtdix }, { title::zeropointquatrecentvingtcinq, title::zeropointquatrecentvingtcinq }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - title::zeropointcentsoixantequinze, Settings::menuY + title::zeropointmillecentsoixantequinze - title::zeropointzerodixneuf, title::zeropointcentquinze, title::zeropointzeroquarantecinq, title::centquatrevingt, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
		Menu::Drawing::Spriter(GPic, GPic, (Menu::Settings::menuX + Features::deuxzerosepthuit), Settings::menuY + (Settings::optionCount * title::zeropointzerotrentecinq + Features::zerounquatredeux), Features::deuxzeroquinze, Features::deuxzerodeuxsept, 0, title::deuxcentcinquantecinqr, title::deuxcentcinquantecinqg, title::deuxcentcinquantecinqb, title::deuxcentcinquantecinqa);
	}
	/*if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)*/
}

float info::zeropointcentsoixantequinze = 0.175f;
float info::zeropointzerotrentecinq = 0.035f;
float info::deuxpointzero = 2.0f;
float info::zeropointcentcinquanteneuf = 0.159f;
float info::zeropointcenttrentecinq = 0.135f;
float info::zeropointcentquinze = 0.115f;
float info::zeropointcentquatrevingttreize = 0.193f;
float info::zeropointcentvingt = 0.120f;
float info::zeropointzerovingt = 0.020f;
float info::zeropointcentvingttrois = 0.123f;
float info::zeropointtroiscentsoixantequinze = 0.375f;
float info::zeropointdeuxcentvingthuit = 0.228f;

float info::zeropointcentsoixantequinze2 = 0.175f;
float info::zeropointzerotrentecinq2 = 0.035f;
float info::deuxpointzero2 = 2.0f;
float info::zeropointcentcinquanteneuf2 = 0.159f;
float info::zeropointcenttrentecinq2 = 0.135f;
float info::zeropointcentquinze2 = 0.115f;
float info::zeropointcentquatrevingttreize2 = 0.193f;
float info::zeropointcentvingt2 = 0.120f;
float info::zeropointzerovingt2 = 0.020f;
float info::zeropointcentvingttrois2 = 0.123f;
float info::zeropointtroiscentsoixantequinze2 = 0.375f;
float info::zeropointdeuxcentvingthuit2 = 0.228f;
int info::dixhuit = 25;

void Menu::AddSmallInfo(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + info::zeropointcentsoixantequinze, Settings::menuY + ((18 * info::zeropointzerotrentecinq) / info::deuxpointzero) + info::zeropointcentcinquanteneuf - info::zeropointcenttrentecinq }, { info::zeropointcentquinze, 18 * info::zeropointzerotrentecinq + -info::zeropointcentquatrevingttreize });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + info::zeropointcentvingt, Settings::menuY + (line * info::zeropointzerovingt) + info::zeropointcentvingttrois }, { info::zeropointtroiscentsoixantequinze, info::zeropointtroiscentsoixantequinze }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - info::zeropointcentsoixantequinze, Settings::menuY + ((18 * info::zeropointzerotrentecinq) / info::deuxpointzero) + info::zeropointcentcinquanteneuf - info::zeropointcenttrentecinq }, { info::zeropointcentquinze, 18 * info::zeropointzerotrentecinq + -info::zeropointcentquatrevingttreize });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - info::zeropointdeuxcentvingthuit, Settings::menuY + (line * info::zeropointzerovingt) + info::zeropointcentvingttrois }, { info::zeropointtroiscentsoixantequinze, info::zeropointtroiscentsoixantequinze }, false);
	}
}

void Menu::AddSmallInfo02(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + info::zeropointcentsoixantequinze2, Settings::menuY + ((info::dixhuit * info::zeropointzerotrentecinq2) / info::deuxpointzero2) + info::zeropointcentcinquanteneuf2 - info::zeropointcenttrentecinq2 }, { info::zeropointcentquinze2, info::dixhuit * info::zeropointzerotrentecinq2 + -info::zeropointcentquatrevingttreize2 });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + info::zeropointcentvingt2, Settings::menuY + (line * info::zeropointzerovingt2) + info::zeropointcentvingttrois2 }, { info::zeropointtroiscentsoixantequinze2, info::zeropointtroiscentsoixantequinze2 }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - info::zeropointcentsoixantequinze2, Settings::menuY + ((info::dixhuit * info::zeropointzerotrentecinq2) / info::deuxpointzero2) + info::zeropointcentcinquanteneuf2 - info::zeropointcenttrentecinq2 }, { info::zeropointcentquinze2, info::dixhuit * info::zeropointzerotrentecinq2 + -info::zeropointcentquatrevingttreize2 });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - info::zeropointdeuxcentvingthuit2, Settings::menuY + (line * info::zeropointzerovingt2) + info::zeropointcentvingttrois2 }, { info::zeropointtroiscentsoixantequinze2, info::zeropointtroiscentsoixantequinze2 }, false);
	}
}

void Menu::AddSmallInfoHeal1(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}

void Menu::AddSmallInfoHeal2(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
void Menu::AddSmallInfoHeal3(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}
//void Menu::AddSmallInfoHeal4(char* text, short line)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//	else
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, ((16 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 16 * 0.035f + -0.193f });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
//	}
//}
//void Menu::AddSmallInfoGeo(char* text, short line)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX + Features::zeropointdeuxcentquatrevingtquinze, ((Features::seize * Features::zeropointzerotrentecinq) / Features::deuxpointzeroo) + Features::zeropointcentcinquanteneuf - Features::zeropointcenttrentecinq }, { Features::zeropointcentvingtcinq, Features::seize * Features::zeropointzerotrentecinq + -Features::zeropointcentquatrevingttreize });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX + Features::zeropointcentvingt, (line * Features::zerozerovingt) + Features::centvingttrois }, { Features::zeropointtroiscentsoixtantequinze, Features::zeropointtroiscentsoixtantequinze }, false);
//	}
//	else
//	{
//		if (line == 1) {
//			Drawing::Rect(Settings::optionRect, { Settings::menuX - Features::zeropointdeuxcentquatrevingtquinze, ((Features::seize * Features::zeropointzerotrentecinq) / Features::deuxpointzeroo) + Features::zeropointcentcinquanteneuf - Features::zeropointcenttrentecinq }, { Features::zeropointcentvingtcinq, Features::seize * Features::zeropointzerotrentecinq + -Features::zeropointcentquatrevingttreize });
//		}
//		Drawing::Text(text, Settings::count, { Settings::menuX - Features::zeropointdeuxcentvingthuit, (line * Features::zerozerovingt) + Features::centvingttrois }, { Features::zeropointtroiscentsoixtantequinze, Features::zeropointtroiscentsoixtantequinze }, false);
//	}
//}

float geofloat::zeropointdeuxcentquatrevingtquinze = 0.295f;
float geofloat::zeropointzerotrentecinq = 0.045f;
//float geofloat::zeropointzerotrentecinq = 0.035f;
float geofloat::twopointzero = 2.0f;
//float geofloat::zeropointcentcinquanteneuf = 0.159f;
float geofloat::zeropointcentcinquanteneuf = 0.139f;
//float geofloat::zeropointcenttrentecinq = 0.135f;
float geofloat::zeropointcenttrentecinq = 0.115f;
//float geofloat::zeropointcenttrentecinq = 0.105f;
float geofloat::zeropointcentvingtcinq = 0.125f;
float geofloat::zeropointcentquatrevingttreize = 0.193f;
float geofloat::zeropointcentvingt = 0.120f;
float geofloat::zeropointzerovingt = 0.020f;
float geofloat::zeropointcentvingttrois = 0.123f;
float geofloat::zeropointtroiscentsoixantequinze = 0.375f;
float geofloat::zeropointtroiscentcinquantehuit = 0.358f;

void Menu::AddSmallInfoGeo(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + geofloat::zeropointdeuxcentquatrevingtquinze, Settings::menuY + ((8 * geofloat::zeropointzerotrentecinq) / geofloat::twopointzero) + geofloat::zeropointcentcinquanteneuf - geofloat::zeropointcenttrentecinq }, { geofloat::zeropointcentvingtcinq, 8 * geofloat::zeropointzerotrentecinq + -geofloat::zeropointcentquatrevingttreize });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + geofloat::zeropointcentvingt, Settings::menuY + (line * geofloat::zeropointzerovingt) + geofloat::zeropointcentvingttrois }, { geofloat::zeropointtroiscentsoixantequinze, geofloat::zeropointtroiscentsoixantequinze }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - geofloat::zeropointdeuxcentquatrevingtquinze, Settings::menuY + ((8 * geofloat::zeropointzerotrentecinq) / geofloat::twopointzero) + geofloat::zeropointcentcinquanteneuf - geofloat::zeropointcenttrentecinq }, { geofloat::zeropointcentvingtcinq, 8 * geofloat::zeropointzerotrentecinq + -geofloat::zeropointcentquatrevingttreize });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - geofloat::zeropointtroiscentcinquantehuit, Settings::menuY + (line * geofloat::zeropointzerovingt) + geofloat::zeropointcentvingttrois }, { geofloat::zeropointtroiscentsoixantequinze, geofloat::zeropointtroiscentsoixantequinze }, false);
	}
}
void Menu::AddSmallInfo222(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + Features::zeropointcentvingtf, Settings::menuY + (line * 0.020f) + Features::zeropointundeuxtroisf }, { Features::zeropointtroiscentsoixantequinzef, Features::zeropointtroiscentsoixantequinzef }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - Features::zeropointcentvingtf, Settings::menuY + (line * 0.020f) + Features::zeropointundeuxtroisf }, { Features::zeropointtroiscentsoixantequinzef, Features::zeropointtroiscentsoixantequinzef }, false);
	}
}
void Menu::AddSmallInfo2224(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + Features::zeropointcentvingtf, Settings::menuY + (line * 0.020f) + Features::zeropointundeuxtroisf }, { Features::zeropointtroiscentsoixantequinzef, Features::zeropointtroiscentsoixantequinzef }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - Features::zeropointcentvingtf, Settings::menuY + (line * 0.020f) + Features::zeropointundeuxtroisf }, { Features::zeropointtroiscentsoixantequinzef, Features::zeropointtroiscentsoixantequinzef }, false);
	}
}
void Menu::AddSmallInfo2222(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + Features::zeropointcentvingtf, Settings::menuY + (line * 0.020f) + Features::zeropointundeuxtroisf }, { Features::zeropointtroiscentsoixantequinzef, Features::zeropointtroiscentsoixantequinzef }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - Features::zeropointcentvingtf, Settings::menuY + (line * 0.020f) + Features::zeropointundeuxtroisf }, { Features::zeropointtroiscentsoixantequinzef, Features::zeropointtroiscentsoixantequinzef }, false);
	}
}
void Menu::AddSmallTitle2(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallInfo2(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}

void Menu::AddSmallInfo22(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + Features::centvingt, Settings::menuY + (line * 0.020f) + Features::zeroundeuxtrois }, { Features::zerotroiscentsoixantequinze, Features::zerotroiscentsoixantequinze }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((13 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 13 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - Features::centvingt, Settings::menuY + (line * 0.020f) + Features::zeroundeuxtrois }, { Features::zerotroiscentsoixantequinze, Features::zerotroiscentsoixantequinze }, false);
	}//Settings::menuX - 0.228f
}

void Menu::AddSmallTitle3(char* text)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX + 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX + 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
	else
	{
		Drawing::Text(text, Settings::titleText, { Settings::menuX - 0.175f, Settings::menuY + 0.090f }, { 0.425f, 0.425f }, true);
		Drawing::Spriter("CommonMenu", "", Settings::menuX - 0.175f, Settings::menuY + 0.1175f - 0.019f, 0.115f, 0.045f, 180, Settings::titleRect.r, Settings::titleRect.g, Settings::titleRect.b, Settings::titleRect.a);
	}
}

void Menu::AddSmallInfo3(char* text, short line)
{
	if (Menu::Settings::menuX < 0.78f)
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX + 0.175f, Settings::menuY + ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX + 0.120f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
	else
	{
		if (line == 1) {
			Drawing::Rect(Settings::optionRect, { Settings::menuX - 0.175f, Settings::menuY + ((11 * 0.035f) / 2.0f) + 0.159f - 0.135f }, { 0.115f, 11 * 0.035f + -0.193f });
		}
		Drawing::Text(text, Settings::count, { Settings::menuX - 0.228f, Settings::menuY + (line * 0.020f) + 0.123f }, { 0.375f, 0.375f }, false);
	}
}

bool Menu::Bool(const char * option, bool & b00l)
{
	Option(option);
	if (b00l)
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			Drawing::Spriter("commonmenu", "shop_NEW_Star", Settings::menuX + 0.095f, Settings::menuY + (Settings::optionCount * 0.035f + 0.141f), 0.02f, 0.03f, 0, 0, 255, 0, 255);
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			Drawing::Spriter("commonmenu", "shop_NEW_Star", Settings::menuX + 0.095f, Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.02f, 0.03f, 0, 0, 255, 0, 255);
	}
	else
	{
		if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
			Drawing::Spriter("commonmenu", "shop_NEW_Star", Settings::menuX + 0.095f, Settings::menuY + (Settings::optionCount * 0.035f + 0.141f), 0.02f, 0.03f, 0, 255, 0, 70, 255);
		else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
			Drawing::Spriter("commonmenu", "shop_NEW_Star", Settings::menuX + 0.095f, Settings::menuY + ((Settings::optionCount - (Settings::currentOption - 16)) * 0.035f + 0.141f), 0.02f, 0.03f, 0, 255, 0, 70, 255);
	}
	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		b00l ^= 1;
		return true;
	}
	return false;
}
bool Menu::Bool(const char * option, bool & b00l, std::function<void()> function)
{
	Bool(option, b00l);

	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
		function();
		return true;
	}
	return false;
}

//void Menu::Vehicle(std::string texture1, std::string texture2)
//{
//	if (Menu::Settings::menuX < 0.78f)
//	{
//		if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX + 0.24f, 0.2f, 0.11f, 0.11f, 0, 255, 255, 255, 255); }
//	}
//	else {
//		if (Menu::Settings::optionCount == Menu::Settings::currentOption) { Menu::Drawing::Spriter(texture1, texture2, Menu::Settings::menuX - 0.18f, 0.2f, 0.15f, 0.15f, 0, 255, 255, 255, 255); }
//	}
//}
std::string Menu2::RadioStation = "RADIO_01_CLASS_ROCK";
std::string Menu2::RadioSong = "all_the_things_she_said";
int Menu2::RadioSongInt = 1;

bool Menu2::skipradiobool = false;
void Menu2::skipradio()
{
	/*AUDIO::SKIP_RADIO_FORWARD();*/
}

void Menu2::skiptheradio()
{

	int radio3 = AUDIO::GET_AUDIBLE_MUSIC_TRACK_TEXT_ID(); //GET_PLAYER_RADIO_STATION_INDEX
	string gettheradio2;
	gettheradio2 = getenv("appdata");
	ofstream gettheradio3(gettheradio2 + "\\ThunderMenu\\GetRadioTrackId.Thunder");
	gettheradio3 << "";
	gettheradio3 << radio3;
}
int Menu2::sendtomission = 1;

int Menu2::OpenMenu = VK_MULTIPLY;
int Menu2::OpenMenu8 = VK_NUMPAD8;
int Menu2::OpenMenu6 = VK_NUMPAD6;
int Menu2::OpenMenu5 = VK_NUMPAD5;
int Menu2::OpenMenu4 = VK_NUMPAD4;
int Menu2::OpenMenu2 = VK_NUMPAD2;
int Menu2::OpenMenu0 = VK_NUMPAD0;

int Menu2::DriftKey = A_73;
int Menu2::BoostBackKey = B_80;
int flyingcars::open = R3_79;

int flyingcars::up = DPUP_42;
int flyingcars::down = DPDN_48;

int noclips::open = L3_28;
bool noclips::nobool = 0;
//int converter::parseInt(char* chars)
//{
//	int sum = 0;
//	int len = strlen(chars);
//	for (int x = 0; x < len; x++)
//	{
//		int n = chars[len - (x + 1)] - '0';
//		sum = sum + converter::powInt(n, x);
//	}
//	return sum;
//}
//
//int converter::powInt(int x, int y)
//{
//	for (int i = 0; i < y; i++)
//	{
//		x *= 10;
//	}
//	return x;
//}

//int converter::charToint(char* a) {
//	/*char* p = &a;*/
//	int k = atoi(/*p*/a);
//	return k;
//}

bool titletext_ALPHA_DIS_TEMP;
bool bit_frontend_addnumber_selected = false;
bool g_menuNotOpenedYet = true;

Vector21 g_deltaCursorNormal;
float OptionY;

INT8 font_title = 7;
INT8 font_options = 4;
INT8 font_selection = 4;
INT8 font_breaks = 1;
INT8 font_xyzh = 0;
INT8 font_speedo = 0;

//RGBA1 titlebox(0, 255, 255, 247);
RGBA1 BG(10, 10, 10, 200);
//RGBA1 titletext(255, 255, 255, 255);
RGBA1 optiontext(255, 255, 255, 255);
RGBA1 selectedtext(0, 0, 0, 255);
RGBA1 optionbreaks(255, 255, 255, 240);
RGBA1 optioncount(255, 255, 255, 255);
RGBA1 selectionhi(255, 255, 255, 211);
RGBA1 _globalPedTrackers_Col(0, 255, 255, 205);

std::pair<UINT16, UINT16> menubindsGamepad = { INPUT_FRONTEND_RB, INPUT_FRONTEND_LEFT };
UINT16 menubinds = VirtualKey::F8;

bool null;
int inull;
void nullFunc() { return; }
UINT16 Menu3::currentsub = 0/*, Menu3::LOOCsub = SUB::MAINMENU*/; //SubMenus::noclip
INT Menu3::currentop = 0, * Menu3::currentopATM = &currentop;
INT Menu3::currentop_w_breaks = 0;
//INT Menu3::totalop = 0;
//INT Menu3::printingop = 0;
Scaleform Menu3::scaleform_menuGlare;
Scaleform Menu3::instructional_buttons;
std::vector<Scaleform_IbT> Menu3::vIB;

//void Menu3::set_opened_IB()
//{
//	if (!bit_frontend_addnumber_selected)
//		add_IB(INPUT_CELLPHONE_SELECT, "ITEM_SELECT");
//	if (currentsub != SUB::MAINMENU)
//		add_IB(INPUT_FRONTEND_RRIGHT, "ITEM_BACK");
//	else
//		add_IB(INPUT_FRONTEND_RRIGHT, "ITEM_EXIT");
//	/*if (bit_frontend_addnumber_selected)
//	{
//	Menu::add_IB(INPUT_FRONTEND_RIGHT, "Right");
//	Menu::add_IB(INPUT_FRONTEND_LEFT, "Left");
//	}
//	if (Menu::totalop > 1)
//	{
//	add_IB(INPUT_FRONTEND_DOWN, "Down");
//	add_IB(INPUT_FRONTEND_UP, "Up");
//	}*/
//
//	bit_frontend_addnumber_selected = false;
//}
void Menu3::add_IB(ControllerInputs button_id, std::string string_val)
{
	vIB.push_back({ button_id, (string_val), false });
}
void Menu3::add_IB(VirtualKey::VirtualKey button_id, std::string string_val)
{
	vIB.push_back({ button_id, (string_val), true });
}
void Menu3::add_IB(ScaleformButton button_id, std::string string_val)
{
	vIB.push_back({ int(button_id) + 1000, (string_val), false });
}
std::string Menu3::get_key_IB(const Scaleform_IbT& ib)
{
	if (ib.button == -3)
		return "";

	if (!ib.isKey)
		return CONTROLS::_GET_CONTROL_ACTION_NAME(2, ib.button, 1); // _0x0499D7B09FC9B407

	std::string bs = "t_" + VkCodeToStr(ib.button);

	return bs;
}
bool loop_hide_hud = 0;
void Menu3::draw_IB()
{
	if (vIB.empty() || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0 || loop_hide_hud)//IS_HUD_HIDDEN())
	{
		//instructional_buttons.Unload();
		return;
	}

	if (!instructional_buttons.Load("instructional_buttons"))
		return;

	instructional_buttons.PushFunction("CLEAR_ALL");
	instructional_buttons.PopFunction();

	instructional_buttons.PushFunction("SET_MAX_WIDTH");
	instructional_buttons.PushFloat(100.0f);
	instructional_buttons.PopFunction();

	instructional_buttons.PushFunction("TOGGLE_MOUSE_BUTTONS");
	instructional_buttons.PushBoolean(true);
	instructional_buttons.PopFunction();

	for (UINT8 i = 0; i < vIB.size(); i++)
	{
		instructional_buttons.PushFunction("SET_DATA_SLOT");
		instructional_buttons.PushInteger(i);

		if (vIB[i].button >= 1000) // Direct scaleform button index
		{
			instructional_buttons.PushInteger(vIB[i].button - 1000);
			instructional_buttons.PushTextComponent(vIB[i].text);
		}
		else
		{
			instructional_buttons.PushString2(get_key_IB(vIB[i]));
			instructional_buttons.PushTextComponent(vIB[i].text);
			instructional_buttons.PushBoolean(true);
			instructional_buttons.PushInteger(vIB[i].button);
		}
		instructional_buttons.PopFunction();
	}

	instructional_buttons.PushFunction("SET_BACKGROUND_COLOUR");
	instructional_buttons.PushRGBA(RGBA1(0, 0, 0, 80));
	instructional_buttons.PopFunction();

	instructional_buttons.PushFunction("DRAW_INSTRUCTIONAL_BUTTONS");
	instructional_buttons.PushInteger(0);
	instructional_buttons.PopFunction();

	GRAPHICS::_SET_SCREEN_DRAW_POSITION(76, 66); // Safezone
	GRAPHICS::_0xF5A2C681787E579D(0.0f, 0.0f, 0.0f, 0.0f); // Offset
	GRAPHICS::_SCREEN_DRAW_POSITION_END(); // Safezone end

	instructional_buttons.Render2D();

	vIB.clear();
}

float get_xcoord_at_menu_rightEdge(float widthOfElement, float extraWidth, bool centered)
{
	if (centered)
	{
		return (0.16f + /*Features::menuPos.x1*/Menu::Settings::menuX + 0.1f) - 0.002f - extraWidth - (widthOfElement / 2);
	}

	return (0.16f + /*Features::menuPos.x1*/Menu::Settings::menuX + 0.1f) - 0.002f - extraWidth - (widthOfElement);
}
float get_xcoord_at_menu_leftEdge(float width, bool centered)
{
	if (centered)
	{
		return (0.16f + /*Features::menuPos.x1*/Menu::Settings::menuX - 0.1f) + 0.002f + (width / 2);
	}

	return (0.16f + /*Features::menuPos.x1*/Menu::Settings::menuX - 0.1f) + 0.002f;
}

namespace MenuPressTimer
{
	MenuPressTimer::Button currentButton = { MenuPressTimer::Button::None };
	DWORD offsettedTime = 0;

	void Update()
	{
		//GeneralGlobalHax::DisableAnnoyingRecordingUI(true);

		if (currentButton == Button::None)
		{
			offsettedTime = GetTickCount() + 630;
		}

		if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RIGHT) || IsKeyDown(VirtualKey::Numpad6))
		{
			currentButton = Button::Right;
		}
		else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_LEFT) || IsKeyDown(VirtualKey::Numpad4))
		{
			currentButton = Button::Left;
		}
		else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_DOWN) || IsKeyDown(VirtualKey::Numpad2))
		{
			currentButton = Button::Down;
		}
		else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_UP) || IsKeyDown(VirtualKey::Numpad8))
		{
			currentButton = Button::Up;
		}
		else
		{
			currentButton = Button::None;
			offsettedTime = 0;
		}
	}
	bool IsButtonHeld(const MenuPressTimer::Button& button)
	{
		DWORD tickCount = GetTickCount();
		return (currentButton == button && offsettedTime < tickCount);
	}
	bool IsButtonTapped(const MenuPressTimer::Button& button)
	{
		bool isTapped = true;
		switch (button)
		{
		case Button::Right: isTapped = CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RIGHT) || IsKeyJustUp(VirtualKey::Numpad6); break;
		case Button::Left: isTapped = CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_LEFT) || IsKeyJustUp(VirtualKey::Numpad4); break;
		case Button::Down: isTapped = CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_DOWN) || IsKeyJustUp(VirtualKey::Numpad2); break;
		case Button::Up: isTapped = CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_UP) || IsKeyJustUp(VirtualKey::Numpad8); break;
		case Button::Back: isTapped = CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_RRIGHT) || IsKeyJustUp(VirtualKey::Numpad0); break;
		case Button::Accept: isTapped = CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(2, INPUT_FRONTEND_ACCEPT) || IsKeyJustUp(VirtualKey::Numpad5); break;
		}
		return isTapped;
	}
	bool IsButtonHeldOrTapped(const MenuPressTimer::Button& button)
	{
		return IsButtonHeld(button) || IsButtonTapped(button);
	}
}

bool IsOptionPressed()
{
	if (MenuPressTimer::IsButtonTapped(MenuPressTimer::Button::Accept) || MouseSupport::pressedSelectAfterSelect)
	{
		Game::Sound::PlayFrontend_default("SELECT");
		return true;
	}
	return false;
}

void Menu3::Up(bool playSound)
{
	currentop--;
	currentop_w_breaks--;
	if (playSound)
		Game::Sound::PlayFrontend_default("NAV_UP_DOWN");
	breakscroll = 1;
}
void Menu3::Down(bool playSound)
{
	currentop++;
	currentop_w_breaks++;
	if (playSound)
		Game::Sound::PlayFrontend_default("NAV_UP_DOWN");
	breakscroll = 2;
}

bool MenuInput::IsUsingController()
{
	return !CONTROLS::_IS_INPUT_DISABLED(2);
}
void MenuInput::UpdateDeltaCursorNormal()
{
	Vector21 l_deltaCursorNormal;
	l_deltaCursorNormal.x1 = CONTROLS::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_X);
	l_deltaCursorNormal.y1 = CONTROLS::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_Y);
	//if (l_deltaCursorNormal.x > 0.999f && l_deltaCursorNormal.x > g_deltaCursorNormal.x) l_deltaCursorNormal.x -= 0.01f;
	//if (l_deltaCursorNormal.y > 0.999f && l_deltaCursorNormal.y > g_deltaCursorNormal.y) l_deltaCursorNormal.y -= 0.01f;
	//if (l_deltaCursorNormal.x < -0.999f && l_deltaCursorNormal.x < g_deltaCursorNormal.x) l_deltaCursorNormal.x -= -0.01f;
	//if (l_deltaCursorNormal.y < -0.999f && l_deltaCursorNormal.y < g_deltaCursorNormal.y) l_deltaCursorNormal.y -= -0.01f;
	g_deltaCursorNormal = l_deltaCursorNormal - g_deltaCursorNormal;
}

bool MouseSupport::pressedSelectAfterSelect = 0;
INT MouseSupport::currentopM = -1;
std::vector<MouseSupport::ItemNumber> MouseSupport::vItems;
INT MouseSupport::ItemNumberToItemNumberOnScreen(INT itemNumber)
{
	/*if (itemNumber >= vItems.size() + Menu::breakcount)
	{
	return -1;
	}*/
	for (auto& it : vItems)
	{
		if (itemNumber == it.real)
			return it.onScreen;
	}
	return -1;
}

Vector21 MouseSupport::ItemNumberToItemCoords(INT itemNumber)
{
	INT itemNumberOnScreen = ItemNumberToItemNumberOnScreen(itemNumber);

	if (itemNumberOnScreen < 0)
		return Vector21(-1, -1);

	return Vector21(0.16f + /*Features::menuPos.x1*/Menu::Settings::menuX, (itemNumberOnScreen * 0.035f) + 0.1415f + /*Features::menuPos.y1*/Menu::Settings::menuY);

}

void MouseSupport::Tick()
{
	Menu3::currentopATM = Menu3::bit_mouse ? &MouseSupport::currentopM : &Menu3::currentop;

	pressedSelectAfterSelect = false;

	if (Menu3::bit_mouse)
	{
		DisableControls();
		DoMouseTick();
	}
}

void MouseSupport::DisableControls()
{
	std::vector<ControllerInputs> list
	{
		INPUT_ATTACK,
		INPUT_FRONTEND_ACCEPT,
		INPUT_FRONTEND_AXIS_X,
		INPUT_FRONTEND_AXIS_Y,
		INPUT_FRONTEND_CANCEL,
		INPUT_FRONTEND_SELECT,
		INPUT_CURSOR_SCROLL_UP,
		INPUT_CURSOR_SCROLL_DOWN,
		INPUT_CURSOR_SCROLL_UP,
		INPUT_CURSOR_X,
		INPUT_CURSOR_Y,
		INPUT_VEH_FLY_YAW_LEFT,
		INPUT_VEH_FLY_YAW_RIGHT,
		INPUT_VEH_FLY_ROLL_LR,
		INPUT_VEH_FLY_PITCH_UD,
		INPUT_VEH_HANDBRAKE

	};

	for (auto& control : list)
	{
		CONTROLS::DISABLE_CONTROL_ACTION(0, control, true);
	}

}

void MouseSupport::DoMouseTick()
{

	Vector21& safezoneOffset = GetSafezoneBounds();

	UI::_SHOW_CURSOR_THIS_FRAME();

	if (IsMouseInBounds(Vector21(0.0078f, 0.5f), Vector21(0.0156f, 1.0f)))
	{
		GameplayCamera::RelativeHeading_set(GameplayCamera::RelativeHeading_get() + 5.0f);
		UI::_SET_CURSOR_SPRITE(6);
	}
	else if (IsMouseInBounds(Vector21(1.0 - 0.0078f, 0.5f), Vector21(0.0156f, 1.0f)))
	{
		GameplayCamera::RelativeHeading_set(GameplayCamera::RelativeHeading_get() - 5.0f);
		UI::_SET_CURSOR_SPRITE(7);
	}
	else
	{
		UI::_SET_CURSOR_SPRITE(1);
	}

	DoScrollChecks();


	Vector21 pos;
	for (auto& item : vItems)
	{
		pos = ItemNumberToItemCoords(item.real);

		if (IsMouseInBounds(pos, Vector21(0.20f, 0.035f)))
		{
			// hover highlight
			GRAPHICS::DRAW_RECT(pos.x1, pos.y1, 0.20f, 0.035f, selectionhi.R, selectionhi.G, selectionhi.B, selectionhi.A / 3);

			if (CONTROLS::IS_DISABLED_CONTROL_JUST_PRESSED(0, INPUT_ATTACK))
			{
				//pressedSelectAfterSelect = false;
				if (currentopM != item.real)
					currentopM = item.real;
				else
				{
					pressedSelectAfterSelect = true; // used for proper highlight, execute press
				}
			}
		}


	}

}

void MouseSupport::DrawOptionHighlight()
{
	if (/*Menu3::totalop*/Menu::Settings::maxVisOptions < 1)
		return;

	Vector21& pos = ItemNumberToItemCoords(MouseSupport::currentopM);
	Vector21 size = { 0.20f, 0.035f };

	if (Menu3::gradients)
		GRAPHICS::DRAW_SPRITE("CommonMenu", "Gradient_Nav", pos.x1, pos.y1, size.x1, size.y1, 0.0f, selectionhi.R, selectionhi.G, selectionhi.B, selectionhi.A);
	else
		GRAPHICS::DRAW_RECT(pos.x1, pos.y1, size.x1, size.y1, selectionhi.R, selectionhi.G, selectionhi.B, selectionhi.A);

}

Vector21 MouseSupport::GetSafezoneBounds()
{
	float g = GRAPHICS::GET_SAFE_ZONE_SIZE(); // Safezone size.
	g = (g * 100) - 90;
	g = 10 - g;

	const float hmp = 5.4f;
	int screenw, screenh;
	GRAPHICS::_GET_ACTIVE_SCREEN_RESOLUTION(&screenw, &screenh); //0x873C9F3104101DD3
	float ratio = (float)screenw / screenh;
	float wmp = ratio * hmp;

	return Vector21(round(g * wmp) / 1920, round(g * hmp) / 1080);
}

Vector21 MouseSupport::MousePosition()
{
	//auto& res = MouseSupport::GetScreenResolutionMantainRatio();
	Vector21 pos;

	pos.x1 = CONTROLS::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_X); //idk
	pos.y1 = CONTROLS::GET_DISABLED_CONTROL_NORMAL(2, INPUT_CURSOR_Y);

	return pos;
}
bool MouseSupport::IsMouseInBounds(Vector21 const& boxCentre, Vector21 const& boxSize)
{
	Vector21& pos = MousePosition();

	return (pos.x1 >= boxCentre.x1 - boxSize.x1 / 2 && pos.x1 <= boxCentre.x1 + boxSize.x1 / 2)
		&& (pos.y1 > boxCentre.y1 - boxSize.y1 / 2 && pos.y1 < boxCentre.y1 + boxSize.y1 / 2);
}

std::pair<int, int> MouseSupport::GetScreenResolutionMantainRatio()
{
	int screenw, screenh;
	GRAPHICS::_GET_ACTIVE_SCREEN_RESOLUTION(&screenw, &screenh); //0x873C9F3104101DD3
	const float height = 1080.0f;
	float ratio = (float)screenw / screenh;
	float width = height * ratio;

	return std::make_pair((int)width, (int)height);
}

void MouseSupport::DoScrollChecks()
{
	if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_SCROLL_UP))
	{
		if (/*Menu3::currentop*/Menu::Settings::currentOption > 1)
			Menu3::Up();
	}
	else if (CONTROLS::IS_DISABLED_CONTROL_PRESSED(0, INPUT_CURSOR_SCROLL_DOWN))
	{
		if (/*Menu3::currentop*/Menu::Settings::currentOption < /*Menu3::totalop*/Menu::Settings::maxVisOptions)
			Menu3::Down();
	}

}

//#define GTA_SCROLLOP 8
//#define GTA_BETOP 6
//#define GTA_MAXOP 14
//
//void AddOption(std::string text, bool& option_code_bool, void(&callback)(), int submenu_index, bool show_arrow, bool gxt)
//{
//	char* tempChar;
//
//	/*Menu3::printingop++;*/
//	Menu::Settings::optionCount++;
//
//	OptionY = 0;
//	if ((/*Menu3::currentop*/Menu::Settings::currentOption < GTA_SCROLLOP && /*Menu3::printingop*/Menu::Settings::optionCount <= GTA_MAXOP) || /*Menu3::totalop*/Menu::Settings::maxVisOptions <= GTA_MAXOP)
//	{
//		OptionY = (float)/*Menu3::printingop*/Menu::Settings::optionCount;
//	}
//	else
//	{
//		if (/*Menu3::currentop*/Menu::Settings::currentOption >= GTA_SCROLLOP)
//		{
//
//			if (/*Menu3::currentop*/Menu::Settings::currentOption > (/*Menu3::totalop*/Menu::Settings::maxVisOptions - GTA_BETOP))
//			{
//				OptionY = (float)GTA_SCROLLOP + (GTA_BETOP - (/*Menu3::totalop*/Menu::Settings::maxVisOptions - /*Menu3::printingop*/Menu::Settings::optionCount));
//			}
//			else
//			{
//				OptionY = (float)GTA_SCROLLOP + (/*Menu3::printingop*/Menu::Settings::optionCount - /*Menu3::currentop*/Menu::Settings::currentOption);
//			}
//		}
//	}
//	if (OptionY > GTA_MAXOP || OptionY <= 0) return;
//
//	// store on screen item number in array
//	if (/*Menu3::printingop*/Menu::Settings::optionCount == 1) MouseSupport::vItems.clear();
//	MouseSupport::vItems.push_back({ /*Menu3::printingop*/Menu::Settings::optionCount, (int)OptionY });
//
//	OptionY = OptionY * 0.035f + 0.125f;
//
//	Game::Print::setupdraw();
//	if (font_options == 0) UI::SET_TEXT_SCALE(0, 0.33f);
//	UI::SET_TEXT_FONT(font_options);
//	UI::SET_TEXT_COLOUR(optiontext.R, optiontext.G, optiontext.B, optiontext.A);
//	if (Menu3::bit_mouse ? /*Menu3::printingop*/Menu::Settings::optionCount == MouseSupport::currentopM : /*Menu3::printingop*/Menu::Settings::optionCount == /*Menu3::currentop*/Menu::Settings::currentOption)
//	{
//		if (font_selection == 2 || font_selection == 7) tempChar = "  ~b~=="; // Font unsafe
//		else tempChar = "  ~b~>"; // Font safe
//
//		UI::SET_TEXT_FONT(font_selection);
//		UI::SET_TEXT_COLOUR(selectedtext.R, selectedtext.G, selectedtext.B, selectedtext.A);
//		if (IsOptionPressed())
//		{
//			/*if (&option_code_bool != &null)*/ option_code_bool = true;
//			callback();
//			if (submenu_index != -1) Menu3::SetSub_delayed = submenu_index;
//		}
//	}
//	else
//	{
//		if (font_options == 2 || font_options == 7) tempChar = "  ~b~=="; // Font unsafe
//		else tempChar = "  ~b~>"; // Font safe
//	}
//
//	if (show_arrow || submenu_index != -1)
//	{
//		//Menu::possibleNameOfCurrentSubmenu = text;
//		if (!gxt)
//			text += tempChar;
//	}
//	/*Features::menuPos.x1 = Menu::Settings::menuX;
//	Features::menuPos.x1 = Menu::Settings::menuY;
//	Menu3::bit_centre_options = Menu::Settings::currentOption;*/
//	if (gxt)
//	{
//		//if (Menu3::bit_centre_options)
//		//{
//		//	UI::SET_TEXT_CENTRE(1);
//		//	Game::Print::drawstringGXT(text, 0.16f + /*Features::menuPos.x1*/Menu::Settings::menuX, OptionY + /*Features::menuPos.y1*/Menu::Settings::menuY);
//		//}
//		//else 
//		Game::Print::drawstringGXT(text, 0.066f + /*Features::menuPos.x1*/Menu::Settings::menuX, OptionY + /*Features::menuPos.y1*/Menu::Settings::menuY);
//	}
//	else
//	{
//		//if (Menu3::bit_centre_options)
//		//{
//		//	UI::SET_TEXT_CENTRE(1);
//		//	Game::Print::drawstring(text, 0.16f + /*Features::menuPos.x1*/Menu::Settings::menuX, OptionY + /*Features::menuPos.y1*/Menu::Settings::menuY);
//		//}
//		//else 
//		Game::Print::drawstring(text, 0.066f + /*Features::menuPos.x1*/Menu::Settings::menuX, OptionY + /*Features::menuPos.y1*/Menu::Settings::menuY);
//	}
//}
//inline void AddOption(std::ostream& os, bool& option_code_bool, void(&callback)(), int submenu_index, bool show_arrow, bool gxt)
//{
//	AddOption(dynamic_cast<std::ostringstream&>(os).str(), option_code_bool, callback, submenu_index, show_arrow, gxt);
//}
//void OptionStatus(BOOL status)
//{
//	if (OptionY < 0.6325f && OptionY > 0.1425f)
//	{
//		//char* tempChar;
//		//SET_TEXT_FONT(4);
//		//SET_TEXT_SCALE(0.34f, 0.34f);
//		//SET_TEXT_CENTRE(1); SET_TEXT_OUTLINE();
//
//		//if (status == 0){
//		//	SET_TEXT_COLOUR(255, 102, 102, 250); //RED
//		//	tempChar = "OFF";
//		//}
//		//else if (status == 1){
//		//	SET_TEXT_COLOUR(102, 255, 102, 250); //GREEN
//		//	tempChar = "ON";
//		//}
//		//else{
//		//	SET_TEXT_COLOUR(255, 255, 102, 250); //YELLOW
//		//	tempChar = "??";
//		//}
//		//Game::Print::drawstring(tempChar, 0.233f + menuPos.x, OptionY + menuPos.y);
//
//		//char* tempChar = "000";
//		//SET_TEXT_FONT(0);
//		//SET_TEXT_SCALE(0.28f, 0.28f);
//		//SET_TEXT_CENTRE(1);
//
//		if (!GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED("mprankbadge")) GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT("mprankbadge", 0);
//
//		Vector21 res = { 0.022f, 0.03f };
//
//		if (status == 0)
//		{
//			GRAPHICS::DRAW_SPRITE("mprankbadge", "rankglobe_21x21_colour", get_xcoord_at_menu_rightEdge(res.x1, 0.0f, true), OptionY + 0.0166f + /*Features::menuPos.y1*/Menu::Settings::menuY, res.x1, res.y1, 0.0f, 255, 102, 102, 250);
//			// medaldot_32
//			//DRAW_SPRITE("mpsafecracking", "dial_bg", get_xcoord_at_menu_rightEdge(res.x, 0.0f, true), OptionY + 0.0166f, res.x, res.y, 0.0f, 255, 102, 102, 250);
//			//DRAW_RECT(0.233 + menuPos.x, OptionY + 0.0147f + menuPos.y, 0.05, 0.0315, 255, 102, 102, 250);
//			//DRAW_SPRITE("CommonMenu", "shop_box_blank", 0.233f + menuPos.x, OptionY + 0.0147f + menuPos.y, 0.06f, 0.037f, 0.0f, 255, 102, 102, 250);
//			//SET_TEXT_COLOUR(255, 102, 102, 250); //RED
//			//tempChar = "OFF";
//		}
//		else
//		{
//			GRAPHICS::DRAW_SPRITE("mprankbadge", "rankglobe_21x21_colour", get_xcoord_at_menu_rightEdge(res.x1, 0.0f, true), OptionY + 0.0166f + /*Features::menuPos.y1*/Menu::Settings::menuY, res.x1, res.y1, 0.0f, 102, 255, 102, 250);
//			// medaldot_32 + emptydot_32
//			//DRAW_SPRITE("mpsafecracking", "dial_bg", get_xcoord_at_menu_rightEdge(res.x, 0.0f, true), OptionY + 0.0166f, res.x, res.y, 0.0f, 102, 255, 102, 250);
//			//DRAW_SPRITE("mpsafecracking", "dial_bg", 0.233f + menuPos.x, OptionY + 0.0146f + menuPos.y, 0.03f, 0.03f, 0.0f, 255, 102, 102, 250);
//			//DRAW_RECT(0.233 + menuPos.x, OptionY + 0.0147f + menuPos.y, 0.05, 0.0315, 102, 255, 102, 250);
//			//DRAW_SPRITE("CommonMenu", "shop_box_blank", 0.233f + menuPos.x, OptionY + 0.0147f + menuPos.y, 0.06f, 0.037f, 0.0f, 102, 255, 102, 250);
//			//SET_TEXT_COLOUR(102, 255, 102, 250); //GREEN
//			//tempChar = "ON";
//		}
//
//		//Game::Print::drawstring(tempChar, 0.233f + menuPos.x, OptionY + menuPos.y);
//
//	}
//}
//void AddToggle(const std::string& text, bool& loop_variable, bool& extra_option_code_ON, bool& extra_option_code_OFF, bool gxt)
//{
//	null = 0;
//	AddOption(text, null, nullFunc, -1, false, gxt);
//
//	if (null) {
//		loop_variable = !loop_variable;
//		if (loop_variable != 0) extra_option_code_ON = true;
//		else extra_option_code_OFF = true;
//	}
//
//	OptionStatus(loop_variable); // Display ON/OFF
//}
//void AddToggle(const std::string& text, bool& loop_variable, void(&callback_ON)(), void(&callback_OFF)(), bool gxt)
//{
//	null = 0;
//	AddOption(text, null, nullFunc, -1, false, gxt);
//
//	if (null) {
//		loop_variable = !loop_variable;
//		if (loop_variable != 0) callback_ON();
//		else callback_OFF();
//	}
//
//	OptionStatus(loop_variable); // Display ON/OFF
//}
bool Menu3::bit_controller = 0, Menu3::bit_mouse = 0;
void Menu3::SetInputMethods()
{
	Menu3::bit_controller = MenuInput::IsUsingController();
}
//c_settings settings2;
//void* Menu::MenuLevelHandler::MoveMenuBlame(SubMenus menu)
//{
//	Settings::menusArray[Settings::menuLevel] = Settings::currentMenu;
//	Settings::optionsArray[Settings::menuLevel] = Settings::currentOption;
//	Blaming::blameplayer(Features::Online::blamePlayer);
//	/*Settings::menuLevel++;
//	Settings::currentMenu = menu;
//	Settings::currentOption = 1;*/
//	light_N->ThunderVoid();
//	return 0;
//}
//float menux = 0.79f;
//float menu099 = 0.98f;
//float menu035 = 0.04f;
//float menu0125 = 0.125f;
//float menu012 = 0.12f;
//float zeropointtrentedeux = 0.32f;
//float zeropointquarantecinq = 0.45f;
//float menu01415 = 0.1415f;
//float menu021 = 0.20f;
//
//bool Menu::Optiontni(const char* option)
//{
//	Settings::optionCount++;
//	bool onThis = Settings::currentOption == Settings::optionCount ? true : false;
//	if (Settings::currentOption <= 16 && Settings::optionCount <= 16)
//	{
//		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { menux - 0.101f, (Settings::optionCount)*menu035 + menu0125 }, { zeropointquarantecinq, zeropointquarantecinq }, false), 0 : NULL;
//		Drawing::Text(option, Settings::optionText, { menux - 0.100f, (Settings::optionCount)*menu035 + menu0125 }, { zeropointquarantecinq, zeropointquarantecinq }, false);
//		Drawing::Rect(Settings::optionRect, { menux, (Settings::optionCount)*menu035 + menu01415 }, { menu021, menu035 });
//		onThis ? Drawing::Rect(Settings::scroller, { menux, (Settings::optionCount)*menu035 + menu01415 }, { menu021, menu035 }), 0 : NULL;
//	}
//	else if (Settings::optionCount > (Settings::currentOption - 16) && Settings::optionCount <= Settings::currentOption)
//	{
//		onThis ? Drawing::Text(option, Settings::selectedTextClrs, { menux - 0.101f, (Settings::optionCount - (Settings::currentOption - 16)) * menu035 + menu0125 }, { zeropointquarantecinq, zeropointquarantecinq }, false), 0 : NULL;
//		Drawing::Text(option, Settings::optionText, { menux - 0.100f, (Settings::optionCount - (Settings::currentOption - 16)) * menu035 + menu0125 }, { zeropointquarantecinq, zeropointquarantecinq }, false);
//		Drawing::Rect(Settings::optionRect, { menux,  (Settings::optionCount - (Settings::currentOption - 16)) * menu035 + menu01415 }, { menu021, menu035 });
//		onThis ? Drawing::Rect(Settings::scroller, { menux,  (Settings::optionCount - (Settings::currentOption - 16)) * menu035 + menu01415 }, { menu021, menu035 }), 0 : NULL;
//	}
//	if (Settings::currentOption == Settings::optionCount)
//	{
//		if (Settings::selectPressed)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//bool Menu::Optiontni(const char* option, std::function<void()> function)
//{
//	Optiontni(option);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
//		function();
//		return true;
//	}
//	return false;
//}
//
//bool Menu::MenuOptionint(const char* option, SubMenus newSub)
//{
//	Optiontni(option);
//	if (Settings::currentOption <= Settings::maxVisOptions && Settings::optionCount <= Settings::maxVisOptions)
//		Drawing::Text("~ws~", Settings::titleText, { menux + menu099, Settings::optionCount * menu035 + menu0125 }, { zeropointtrentedeux, zeropointtrentedeux }, true);
//	else if (Settings::optionCount > Settings::currentOption - Settings::maxVisOptions && Settings::optionCount <= Settings::currentOption)
//		Drawing::Text("~ws~", Settings::titleText, { menux + menu099, (Settings::optionCount - (Settings::currentOption - 16)) * menu035 + menu012 }, { zeropointtrentedeux, zeropointtrentedeux }, true);
//
//	if (Settings::optionCount == Settings::currentOption && Settings::selectPressed) {
//		MenuLevelHandler::MoveMenuBlame(newSub);
//		return true;
//	}
//	return false;
//}