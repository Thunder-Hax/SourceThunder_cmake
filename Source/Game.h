#pragma once

#include "types.h" //RGBA
#include "GTAmath.h" //Vector2
#include "GTAEntity.h"

#include <string>
#include <sstream>

typedef unsigned long DWORD, Hash;
typedef signed char INT8;
typedef unsigned char UINT8;

typedef char* PCHAR;

class GTAentity;
class GTAped;
class GTAplayer;

// Stringstream
std::ostream& operator<<(std::ostream& stream, std::wstring& text);
std::wostream& operator<<(std::wostream& stream, std::string& text);
#define oss_ std::ostringstream().flush() << ""
#define woss_ std::wostringstream().flush() << ""

//void add_text_component_long_string(const std::string& text);

namespace Game
{
	extern const std::pair<int, int> defaultScreenRes;

	// Request asset
	bool RequestControlOfId(int netid);
	bool RequestAnimDict(const std::string& anim_dict, DWORD timeOut = 1800);
	bool RequestAnimSet(const std::string& anim_set, DWORD timeOut = 1800);
	void RequestScript(PCHAR scriptName, int stackSize = 14000);

	// GXT
	inline bool DoesGXTEntryExist(const std::string& entry);
	/*std::string GetGXTEntry(const std::string& entry, const std::string& fallback = std::string());
	std::string GetGXTEntry1(Hash entry, const std::string& fallback = std::string());*/

	namespace Sound
	{
		class GameSound
		{
		private:
			std::string soundSet;
			std::string sound;
			int soundID;

		public:
			bool active;

			GameSound();
			GameSound(const std::string& nsoundSet, const std::string& nsound);

			static bool LoadBank(const std::string& audioBank);
			static void UnloadBank(const std::string& audioBank);

			void Play(GTAentity entity);

			void Stop();

			void Destroy();
		};

		void PlayFrontend(const std::string& sound_dict, const std::string& sound_name);
		void PlayFrontend_default(const std::string& sound_name);
	}

	namespace Print
	{
		// Game - Print/draw
		void setupdraw();
		void setupdraw(INT8 font, const Vector21& scale, bool centred, bool right_justified, bool outline, RGBA1 colour = { 255, 255, 255, 255 }, Vector21 wrap = { 0, 1 });
		void drawstring(const std::string& s, float X, float Y);
		void drawstring(std::ostream& os, float X, float Y);
		void drawstringGXT(const std::string& s, float X, float Y);
		void drawstringGXT(std::ostream& os, float X, float Y);
		void drawinteger(int text, float X, float Y);
		void drawfloat(float text, UINT8 decimal_places, float X, float Y);

		void PrintBottomCentre(const std::string& s, int time = 2500);
		void PrintBottomCentre(std::ostream& s, int time = 2500);
		void PrintBottomCentre(std::wostream& s, int time = 2500);

		class Notification
		{
		public:
			Notification(int newHandle) : mHandle(newHandle)
			{
			}
			int& Handle()
			{
				return mHandle;
			}

			void Hide();

		private:
			int mHandle;
		};
		Notification PrintBottomLeft(const std::string& s, bool gxt = false);
		Notification PrintBottomLeft(std::ostream& s, bool gxt = 0);
		Notification PrintBottomLeft(std::wostream& s, bool gxt = 0);
		Notification PrintBottomLeft(const std::string& s, const std::string& sender, const std::string& subject, const std::string& picName, int iconType, bool flash, bool gxt);
		Notification PrintBottomLeft(std::ostream& s, const std::string& sender, const std::string& subject, const std::string& picName, int iconType, bool flash, bool gxt);
		Notification PrintBottomLeft(std::wostream& s, const std::string& sender, const std::string& subject, const std::string& picName, int iconType, bool flash, bool gxt);

		// Messages - Errors
		void PrintError_InvalidInput();
		void PrintError_InvalidModel();

		// Text width
		float GetTextWidth(const std::string& s, bool gxt = false);
		float GetTextWidth(int inumber);
		float GetTextWidth(float fnumber, UINT8 decimal_places);
	}

	//On screen keyboard
	std::string InputBox(const std::string& escReturn = "", int maxChars = 64U, const std::string& titlegxt = "", std::string preText = "");

	//PLAYER_PED_ID()
	GTAplayer Player();
	GTAplayer Player(int index);
	GTAped PlayerPed();
	GTAped PlayerPed(int index);

}

