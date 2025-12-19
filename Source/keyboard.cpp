//keyboard.cpp
#include "stdafx.h"

const int KEYS_SIZE = 255;

//#define NOW_PERIOD 100
//#define MAX_DOWN 5000 // ms
//#define KEYS_SIZE 255

DWORD trainerResetTime = 0;

bool gameInputDisabledByUs = false;
bool gameInputBlockedByUs = false;

struct {
	DWORD time;
	BOOL isWithAlt;
	BOOL wasDownBefore;
	BOOL isUpNow;
} keyStates[KEYS_SIZE];

void OnKeyboardMessage(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt, BOOL wasDownBefore, BOOL isUpNow)
{
	if (key < KEYS_SIZE)
	{
		keyStates[key].time = GetTickCount();
		keyStates[key].isWithAlt = isWithAlt;
		keyStates[key].wasDownBefore = wasDownBefore;
		keyStates[key].isUpNow = isUpNow;
	}
}

const int NOW_PERIOD = 100, MAX_DOWN = 5000; // ms

bool KeyDown(DWORD key)
{
	return (key < KEYS_SIZE) ? ((GetTickCount() < keyStates[key].time + MAX_DOWN) && !keyStates[key].isUpNow) : false;
}

bool KeyJustUp(DWORD key, bool exclusive)
{
	bool b = (key < KEYS_SIZE) ? (GetTickCount() < keyStates[key].time + NOW_PERIOD && keyStates[key].isUpNow) : false;
	if (b && exclusive)
		ResetKeyState(key);
	return b;
}

void ResetKeyState(DWORD key)
{
	if (key < KEYS_SIZE)
		memset(&keyStates[key], 0, sizeof(keyStates[0]));
}
#define IsKeyPressed(key) GetAsyncKeyState(key) & 0x8000
bool KeyPressedOnce(bool& bIsPressed, DWORD vk)
{
	if (IsKeyPressed(vk))
	{
		if (bIsPressed == false)
		{
			bIsPressed = true;
			return true;
		}
	}
	else if (bIsPressed == true)
	{
		bIsPressed = false;
	}
	return false;
}

bool trainer_switch_pressed()
{
	bool result = KeyJustUp(VK_F4);
	return result;
}

void reset_trainer_switch()
{
	trainerResetTime = GetTickCount();
}

void get_button_state(bool *a, bool *b, bool *up, bool *down, bool *l, bool *r)
{
	if (a) *a = KeyDown(VK_NUMPAD5);
	if (b) *b = KeyJustUp(VK_NUMPAD0);
	if (up) *up = KeyDown(VK_NUMPAD8);
	if (down) *down = KeyDown(VK_NUMPAD2);
	if (r) *r = KeyDown(VK_NUMPAD6);
	if (l) *l = KeyDown(VK_NUMPAD4);
}

void menu_beep(int snd)
{
	switch (snd)
	{
		case NAV_SELECT: AUDIO::PLAY_SOUND_FRONTEND(-1, "SELECT", "HUD_FREEMODE_SOUNDSET", 1);
		case NAV_CANCEL: AUDIO::PLAY_SOUND_FRONTEND(-1, "CANCEL", "HUD_FREEMODE_SOUNDSET", 1);
		case NAV_UP_DOWN: AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FREEMODE_SOUNDSET", 1);
		case NAV_LEFT_RIGHT: AUDIO::PLAY_SOUND_FRONTEND(-1, "NAV_LEFT_RIGHT", "HUD_FREEMODE_SOUNDSET", 1);
		default: break;
	}
}

void setGameInputToEnabled(bool enabled, bool force)
{
	if (enabled && (gameInputDisabledByUs || force))
	{
		PLAYER::SET_PLAYER_CONTROL(0, 1, 0);
		//CONTROLS::ENABLE_ALL_CONTROL_ACTIONS(1);
		gameInputDisabledByUs = false;
	}
	else if (!enabled)
	{
		PLAYER::SET_PLAYER_CONTROL(0, 0, 256);
		//CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(1);
		gameInputDisabledByUs = true;
	}
}

bool IsKeyDown(DWORD key)
{
	return (key < KEYS_SIZE) ? ((GetTickCount() < keyStates[key].time + MAX_DOWN) && !keyStates[key].isUpNow) : false;
}

bool IsKeyJustUp(DWORD key, bool exclusive)
{
	bool b = (key < KEYS_SIZE) ? (GetTickCount() < keyStates[key].time + NOW_PERIOD && keyStates[key].isUpNow) : false;
	if (b && exclusive)
		ResetKeyState(key);
	return b;
}

std::string VkCodeToStr(UINT8 key)
{
	// I can just use GetKeyNameTextA ?
	switch (key)
	{
	default: return ""; break;
	case VirtualKey::A:  return ("A"); break;
	case VirtualKey::Add:  return ("+"); break;
	case VirtualKey::Subtract:  return ("-"); break;
	case VirtualKey::B: return ("B"); break;
	case VirtualKey::C:  return ("C"); break;
	case VirtualKey::D:  return ("D"); break;
	case VirtualKey::Decimal:  return ("."); break;
	case VirtualKey::Delete:  return ("Delete"); break;
	case VirtualKey::Divide:  return ("/"); break;
	case VirtualKey::Up:  return ("Up"); break;
	case VirtualKey::Down:  return ("Down"); break;
	case VirtualKey::Left:  return ("Left"); break;
	case VirtualKey::Right:  return ("Right"); break;
	case VirtualKey::E:  return ("E"); break;
	case VirtualKey::End:  return ("End"); break;
	case VirtualKey::Escape:  return ("ESC"); break;
	case VirtualKey::F:  return ("F"); break;
	case VirtualKey::F1:  return ("F1"); break;
	case VirtualKey::F2:  return ("F2"); break;
	case VirtualKey::F3:  return ("F3"); break;
	case VirtualKey::F4:  return ("F4"); break;
	case VirtualKey::F5:  return ("F5"); break;
	case VirtualKey::F6:  return ("F6"); break;
	case VirtualKey::F7:  return ("F7"); break;
	case VirtualKey::F8:  return ("F8"); break;
	case VirtualKey::F9:  return ("F9"); break;
	case VirtualKey::F10:  return ("F10"); break;
	case VirtualKey::F11:  return ("F11"); break;
	case VirtualKey::F12:  return ("F12"); break;
	case VirtualKey::G:  return ("G"); break;
	case VirtualKey::H:  return ("H"); break;
	case VirtualKey::I:  return ("I"); break;
	case VirtualKey::J:  return ("J"); break;
	case VirtualKey::K:  return ("K"); break;
	case VirtualKey::L:  return ("L"); break;
	case VirtualKey::M:  return ("M"); break;
	case VirtualKey::N:  return ("N"); break;
	case VirtualKey::O:  return ("O"); break;
	case VirtualKey::P:  return ("P"); break;
	case VirtualKey::Q:  return ("Q"); break;
	case VirtualKey::R:  return ("R"); break;
	case VirtualKey::S:  return ("S"); break;
	case VirtualKey::T:  return ("T"); break;
	case VirtualKey::U:  return ("U"); break;
	case VirtualKey::V:  return ("V"); break;
	case VirtualKey::W:  return ("W"); break;
	case VirtualKey::X:  return ("X"); break;
	case VirtualKey::Y:  return ("Y"); break;
	case VirtualKey::Z:  return ("Z"); break;
	case VirtualKey::Shift:  return ("Shift"); break;
	case VirtualKey::Space:  return ("Space"); break;
	}
}