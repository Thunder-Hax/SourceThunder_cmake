#pragma once
#include "GTAEntity.h"
#include "Scaleform.h"
/*enum SubMenus { //Add Sub Menus in here
	NOMENU,
	mainmenu,
	lsc,
	senas,
	PTFX,
	PTFXO,
	playermenu,
	recover,
	moneyoptions,
	weapon,
	objectoptions,
	onlinemenu_playerlist,
	onlinemenu_selected,
	miscoptions,
	settings,
	credit,
	exitgta,
	settingstheme,
	themeloader,
	settingstitlerect,
	settingsscroller,
	settingsoptiontext,
	font,
	allplayers,
	anim,
	teleports,
	ipl,
	teleportso,
	teleportsoa,
	plateoptions,
	protection,
	modelchanger,
	tpother,
	weatheroptions,
	vehicle,
	vehspawner,
	attachoptions,
	forcean,
	forceanall,
	Doomsday,
	Super,
	Sports,
	SportClassic,
	Offroad,
	Sedans,
	Coupes,
	Muscle,
	Boats,
	Commercial,
	Compacts,
	Cycles,
	Emergency,
	Helicopters,
	Industrial,
	Military,
	Motorcycles,
	Planes,
	Service,
	SUV,
	Trailer,
	Trains,
	Utility,
	Vans,

};*/

enum SubMenus;

struct VECTOR2 {
	float x, y;
};
struct VECTOR22_22 {
	float w2, h2;
};
struct VECTOR2_2 {
	float w, h;
};
struct RGBAF {
	int r, g, b, a, f;
};
struct RGBA {
	int r, g, b, a;
};
struct RGB {
	int r, g, b;
};
extern float fx;
extern float fxx;
extern float fxxx;
extern float fxxxx;
namespace Menu {
	namespace Loading
	{
		extern int registerblackhole();
		extern int registerswitch(char charload);
		extern bool registerbool;
		extern int loadregister();
	}
	namespace Drawing {
		void Text(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		//void Title(const char* text, RGBAF rgbaf, VECTOR2 position, VECTOR2_2 size, bool center);
		void Rect(RGBA rgba, VECTOR2 position, VECTOR2_2 size);
		void Spriter(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
		void Spriter2(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
		void Header(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
		void Vehicle(std::string Streamedtexture, std::string textureName, float x2, float y2, float width2, float height2, float rotation2, int r2, int g2, int b2, int a2);
		/*void NATIVE_DRAW_SPRITE(char* textureDict, char* textureName, float screenX, float screenY, float width, float height, float heading, int red, int green, int blue, int alpha);*/
		void NATIVE_DRAW_SPRITE2(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
		void NATIVE_DRAW_SPRITE1(std::string Streamedtexture, std::string textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a);
	}
	namespace Settings {

		extern unsigned long long keyHoldStartTick;
		extern bool isMenuKeyPressed;
		extern bool isMenuKeyHeld;
		//extern int keyPressDelay; // Délai lorsque vous appuyez brièvement sur un bouton
		extern int keyHoldDelay; // Délai lorsque vous maintenez un bouton enfoncé
		extern int keyPressCooldown; // Temps de refroidissement entre les pressions successives

		extern bool enablerid;
		extern bool selectPressed;
		extern bool leftPressed;
		extern bool rightPressed;
		extern bool center;
		extern bool controllerinput;

		extern int maxVisOptions;
		extern int currentOption;
		extern int optionCount;

		extern SubMenus currentMenu;
		extern int menuLevel;
		extern int optionsArray[1000];
		extern SubMenus menusArray[1000];
		extern RGBAF selectedTextClrs;
		extern float menuY;
		extern float menuX;
		extern float menuXscale;
		extern RGBAF count;
		extern RGBAF titleText;
		extern RGBA titleRect;
		extern RGBAF breakText;
		extern RGBAF optionText;
		extern RGBA selectedText;
		extern RGBAF arrow;
		extern RGBAF integre;
		extern RGBA optionRect;
		extern RGBA scroller;
		extern RGBA line;
		extern RGBA primary;
		extern RGBA secondary;
		extern RGBAF selectedTextClrs;
		extern int keyPressDelay;
		extern int keyPressPreviousTick;
		extern int keyPressDelay2;
		extern int keyPressPreviousTick2;
		extern int keyPressDelay3;
		extern int keyPressPreviousTick3;
		extern int openKey;
		extern int backKey;
		extern int upKey;
		extern int downKey;
		extern int leftKey;
		extern int rightKey;
		extern int selectKey;
		extern int arrowupKey;
		extern int arrowdownKey;
		extern int arrowleftKey;
		extern int arrowrightKey;
		extern int enterKey;
		extern int deleteKey;
		extern int openpress;
		extern int downpress;
		extern int uppress;
		extern int backpress;
		extern int click;
		extern int leftpress;
		extern int rightpress;

		extern bool DrawTextOutline;
		extern bool menuclosed;
	}
	namespace MenuLevelHandler {
		void* MoveMenuBlame(SubMenus menu);
		void MoveMenu(SubMenus menu);
		void BackMenu();
	}
	namespace Checks {
		void Controlls();
	}
	namespace Tools {
		char* StringToChar(std::string string);
	}
	namespace Files {
		void WriteStringToIni(std::string string, std::string file, std::string app, std::string key);
		std::string ReadStringFromIni(std::string file, std::string app, std::string key);
		void WriteIntToIni(int intValue, std::string file, std::string app, std::string key);
		int ReadIntFromIni(std::string file, std::string app, std::string key);
		void WriteFloatToIni(float floatValue, std::string file, std::string app, std::string key);
		float ReadFloatFromIni(std::string file, std::string app, std::string key);
		void WriteBoolToIni(bool b00l, std::string file, std::string app, std::string key);
		bool ReadBoolFromIni(std::string file, std::string app, std::string key);
	}
	void DrawGlare(float pX, float pY, float scaleX, float scaleY, int red, int green, int blue, int alpha);
	void render_globe(const float x, const float y, const float sx, const float sy, const int r, const int g, const int b);
	void Title(const char* title);
	void info(const char * title);
	void Vehicle(std::string texture1, std::string texture2);
	void Speedometer(char* text);
	void fps(char* text);
	void AddSmallTitle(char* text);
	void AddSmallTitle02(char* text);
	void AddSmallTitle5(const char * option, int pid);
	void AddSmallInfo(char* text, short line);
	void AddSmallInfo02(char* text, short line);
	void AddSmallInfoHeal1(char* text, short line);
	void AddSmallInfoHeal2(char* text, short line);
	void AddSmallInfoHeal3(char* text, short line);
	/*void AddSmallInfoHeal4(char* text, short line);*/
	void AddSmallInfoGeo(char* text, short line);
	void AddSmallInfo222(char* text, short line);
	void AddSmallInfo2224(char* text, short line);
	void AddSmallInfo2222(char* text, short line);
	void AddSmallTitle2(char* text);
	void AddSmallInfo2(char* text, short line);
	void AddSmallInfo22(char* text, short line);
	void AddSmallTitle3(char* text);
	void AddSmallInfo3(char* text, short line);
	bool Break(const char* option);
	bool Option(const char* option);
	bool OptionCars(const char* option);
	bool Option(const char* Option, std::function<void()> function);
	bool Optiontni(const char* option);
	bool Optiontni(const char* option, std::function<void()> function);
	bool carsOptionSpawn(const char* Option, std::function<void()> function);
	bool MenuOption(const char* option, SubMenus newSub);
	bool MenuOptions2(const char* option, SubMenus newSub, int pid);
	bool MenuOptionint(const char* option, SubMenus newSub);
	bool MenuOption(const char* option, SubMenus newSub, std::function<void()> function);
	bool Toggle(const char* option, bool& b00l);
	bool Toggle(const char* option, bool& b00l, std::function<void()> function);
	bool Bool(const char* option, bool& b00l);
	bool Bool(const char* option, bool& b00l, std::function<void()> function);
	bool StringOption(const char* option, int& position, const std::vector<std::string>& options, std::function<void()> function);
	//bool StringOption(const char* option, int* position, const std::vector<std::string>& options);
	bool Int(const char* option, int& _int, int min, int max);
	bool Int(const char* option, int& _int, int min, int max, int step);
	bool Int(const char* option, int& _int, int min, int max, std::function<void()> function);
	bool Int(const char* option, int& _int, int min, int max, int step, std::function<void()> function);
	//bool Float(const char* option, float& _float, int min, int max);
	bool Float(const char * option, float & _float, float min, float max);
	bool Float3(const char* option, float& _float, float min, float max);
	bool Float2(const char* option, float& _float, float min, float max);
	bool Float1(const char* option, float& _float, float min, float max);
	bool Float(const char * option, float & _float, float min, float max, float step);
	//bool Float(const char* option, float& _float, int min, int max, int step);
	bool Float(const char* option, float& _float, int min, int max, std::function<void()> function);
	bool Float(const char* option, float& _float, int min, int max, int step, std::function<void()> function);
	bool IntVector(const char* option, std::vector<int> Vector, int& position);
	bool IntVector(const char* option, std::vector<int> Vector, int& position, std::function<void()> function);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position);
	bool FloatVector(const char* option, std::vector<float> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position);
	bool StringVector(const char* option, std::vector<std::string> Vector, int& position, std::function<void()> function);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position);
	bool StringVector(const char* option, std::vector<char*> Vector, int& position, std::function<void()> function);
	bool Teleport(const char* option, Vector3 coords);
	bool Teleport(const char* option, Vector3 coords, std::function<void()> function);
	void End();
	const std::string GetModulePath11(HMODULE module);
	bool FileExists(const std::string& fileName);
	/*int RegisterFile(const std::string& fullPath, const std::string& fileName);*/
	/*void Vehicle(std::string texture1, std::string texture2);*/
}

namespace Menu2
{
extern bool Darkside;
extern int PlayerListPos;
extern int HudColorPos1;
extern int HudColorPos2;
using namespace std;
bool ListVector(const char* option, /*std::*/Menu2::vector<char*> Vector, int& position);
extern std::string RadioStation;
extern std::string RadioSong;
extern int RadioSongInt;
extern int RADIOPos1;
extern int RADIO_18_90S_ROCKPos1;
extern int RADIO_17_FUNKPos1;
extern int RADIO_16_SILVERLAKEPos1;
extern int RADIO_15_MOTOWNPos1;
extern int RADIO_14_DANCE_02Pos1;
extern int RADIO_13_JAZZPos1;
extern int RADIO_12_REGGAEPos1;
extern int RADIO_09_HIPHOP_OLDPos1;
extern int RADIO_08_MEXICANPos1;
extern int RADIO_07_DANCE_01Pos1;
extern int RADIO_06_COUNTRYPos1;
extern int RADIO_04_PUNKPos1;
extern int RADIO_03_HIPHOP_NEWPos1;
extern int RADIO_02_POPPos1;
extern int RADIO_01_CLASS_ROCKPos1;

extern bool skipradiobool;
extern void skipradio();
extern void skiptheradio();

extern int OpenKeysPos1;
extern int sendtomission;
extern int sendtoPos1;
extern int OpenKeysPos2;
extern int OpenKeysPos3;
extern int OpenKeysPos4;
extern int OpenKeysPos5;
extern int OpenKeysPos6;
extern int OpenKeysPos7;
extern int OpenMenu;
extern int OpenMenu8;
extern int OpenMenu6;
extern int OpenMenu5;
extern int OpenMenu4;
extern int OpenMenu2;
extern int OpenMenu0;
extern int ControllerKeysPos1;
extern int ControllerKeysfopenPos;
extern int ControllerKeysfupPos;
extern int ControllerKeysfdownPos;
extern int ThunderGroundPos1;
extern int resultpos2;
extern int DriftKey;
extern int BoostBackKey;
}
namespace flyingcars
{ 
extern int open;
extern int up;
extern int down;
}
namespace noclips
{
	extern int open;
	extern bool nobool;
}
namespace RadioStations
{
	extern int stationradio(std::string radiochoice);
}

//namespace converter
//{
////	int powInt(int x, int y);
////	int parseInt(char* chars);
////	int charToint(char* a);
//}


extern bool titletext_ALPHA_DIS_TEMP;
extern bool bit_frontend_addnumber_selected;
extern bool g_menuNotOpenedYet;

extern Vector21 g_deltaCursorNormal;
extern float OptionY;

extern INT8 font_title;
extern INT8 font_options;
extern INT8 font_selection;
extern INT8 font_breaks;
extern INT8 font_xyzh;
extern INT8 font_speedo;

//extern RGBA1 titlebox;
extern RGBA1 BG;
//extern RGBA1 titletext;
extern RGBA1 optiontext;
extern RGBA1 selectedtext;
extern RGBA1 optionbreaks;
extern RGBA1 optioncount;
extern RGBA1 selectionhi;
extern RGBA1 _globalPedTrackers_Col;

extern std::pair<UINT16, UINT16> menubindsGamepad;
extern UINT16 menubinds;

extern bool null;
extern int inull;
void nullFunc();

//class MenuInput final
//{
//public:
//
//	static bool IsUsingController();
//	static void UpdateDeltaCursorNormal();
//
//};

float get_xcoord_at_menu_rightEdge(float widthOfElement, float extraWidth, bool centered);
float get_xcoord_at_menu_leftEdge(float width, bool centered);

namespace MenuPressTimer
{
	enum class Button
	{
		None, Up, Down, Left, Right, Back, Accept
	};
	extern MenuPressTimer::Button currentButton;
	extern DWORD offsettedTime;

	void Update();
	bool IsButtonHeld(const MenuPressTimer::Button& button);
	bool IsButtonTapped(const MenuPressTimer::Button& button);
	bool IsButtonHeldOrTapped(const MenuPressTimer::Button& button);
}

class MenuInput final
{
public:

	static bool IsUsingController();
	static void UpdateDeltaCursorNormal();

};

class MouseSupport final
{
public:
	static bool pressedSelectAfterSelect;
	static INT currentopM;
	struct ItemNumber { INT real; INT onScreen; };
	static std::vector<ItemNumber> vItems;

	static INT ItemNumberToItemNumberOnScreen(INT itemNumber);

	static Vector21 ItemNumberToItemCoords(INT itemNumber);

	static void Tick();

	static void DisableControls();

	static void DoMouseTick();

	static void DrawOptionHighlight();

	static Vector21 GetSafezoneBounds();

	static Vector21 MousePosition();
	static bool IsMouseInBounds(Vector21 const& boxCentre, Vector21 const& boxSize);

	static std::pair<int, int> GetScreenResolutionMantainRatio();

	static void DoScrollChecks();

};

class Menu3 final
{
public:
	static UINT16 currentsub, LOOCsub;
	static INT currentop;
	static INT* currentopATM;
	static INT currentop_w_breaks;
	//static INT totalop;
	//static INT printingop;
	static UINT16 breakcount;
	static UINT16 totalbreaks;
	static UINT8 breakscroll;
	static INT16 currentsub_ar_index;
	static INT currentsub_ar[100];
	static INT currentop_ar[100];
	static INT SetSub_delayed;
	static int delayedTimer;
	static bool bit_controller, bit_mouse, bit_centre_title, bit_centre_options, bit_centre_breaks, gradients, thin_line_over_screct, bit_glare_test;
	static Scaleform scaleform_menuGlare, instructional_buttons;
	static std::vector<Scaleform_IbT> vIB;

	static void Up(bool playSound = true);
	static void Down(bool playSound = true);

	/*static void set_opened_IB();*/
	static void add_IB(ControllerInputs button_id, std::string string_val);
	static void add_IB(VirtualKey::VirtualKey button_id, std::string string_val);
	static void add_IB(ScaleformButton button_id, std::string string_val);
	static std::string get_key_IB(const Scaleform_IbT& ib);
	static void draw_IB();

	static void SetInputMethods();
};

//void AddOption(std::string text, bool& option_code_bool = null, void(&callback)() = nullFunc, int submenu_index = -1, bool show_arrow = 0, bool gxt = 0);
//inline void AddOption(std::ostream& os, bool& option_code_bool = null, void(&callback)() = nullFunc, int submenu_index = -1, bool show_arrow = 0, bool gxt = 0);
//void OptionStatus(BOOL status);
//void AddToggle(const std::string& text, bool& loop_variable, bool& extra_option_code_ON = null, bool& extra_option_code_OFF = null, bool gxt = 0);
//void AddToggle(const std::string& text, bool& loop_variable, void(&callback_ON)(), void(&callback_OFF)(), bool gxt = 0);

class Thunder
{
public:
	void ThunderVoid();
};

namespace geofloat
{
	extern float zeropointdeuxcentquatrevingtquinze;
	extern float zeropointzerotrentecinq;
	extern float twopointzero;
	extern float zeropointcentcinquanteneuf;
	extern float zeropointcenttrentecinq;
	extern float zeropointcentvingtcinq;
	extern float zeropointcentquatrevingttreize;
	extern float zeropointcentvingt;
	extern float zeropointzerovingt;
	extern float zeropointcentvingttrois;
	extern float zeropointtroiscentsoixantequinze;
	extern float zeropointtroiscentcinquantehuit;
}

namespace info
{
	extern float zeropointcentsoixantequinze;
	extern float zeropointzerotrentecinq;
	extern float deuxpointzero;
	extern float zeropointcentcinquanteneuf;
	extern float zeropointcenttrentecinq;
	extern float zeropointcentquinze;
	extern float zeropointcentquatrevingttreize;
	extern float zeropointcentvingt;
	extern float zeropointzerovingt;
	extern float zeropointcentvingttrois;
	extern float zeropointtroiscentsoixantequinze;
	extern float zeropointdeuxcentvingthuit;
	extern float zeropointcentsoixantequinze2;
	extern float zeropointzerotrentecinq2;
	extern float deuxpointzero2;
	extern float zeropointcentcinquanteneuf2;
	extern float zeropointcenttrentecinq2;
	extern float zeropointcentquinze2;
	extern float zeropointcentquatrevingttreize2;
	extern float zeropointcentvingt2;
	extern float zeropointzerovingt2;
	extern float zeropointcentvingttrois2;
	extern float zeropointtroiscentsoixantequinze2;
	extern float zeropointdeuxcentvingthuit2;
	extern int dixhuit;
}
namespace title
{
	extern float zeropointcentsoixantequinze;
	extern float zeropointzeroquatrevingtdix;
	extern float zeropointquatrecentvingtcinq;
	extern float zeropointzerodixneuf;
	extern float zeropointcentquinze;
	extern float zeropointzeroquarantecinq;
	extern float zeropointzerotrentecinq;
	extern float zeropointmillecentsoixantequinze;
	extern int centquatrevingt;
	extern int deuxcentcinquantecinqr;
	extern int deuxcentcinquantecinqg;
	extern int deuxcentcinquantecinqb;
	extern int deuxcentcinquantecinqa;
}

//struct c_settings
//{
//public:
//	struct {
//
//	} menu;
//};