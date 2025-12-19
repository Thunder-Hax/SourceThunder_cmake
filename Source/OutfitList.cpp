#include "stdafx.h"
#include "OutfitList.h"
#include "natives.h"

using namespace std;

#include "xkeycheck.h"

//#include <stdlib.h>
//#include <iterator>
//#include <algorithm>
//#include <iomanip>

#include <cstdlib>
#include <fstream>
#include "pugixml.h"
#include "dirent.h"
//
#include <direct.h>
#define GetCurrentDir _getcwd
#include <wchar.h>
#include <errno.h>

#include <sstream>
    /*char loadsave::outfitbuffer[255];*/
    std::string Directory::get_current_dir() {
        char buff[FILENAME_MAX];
        GetCurrentDir(buff, FILENAME_MAX);
        string current_working_dir(buff);
        stringstream stringcustoms1;
        string stringcustom1;
        stringcustoms1 << current_working_dir;
        stringcustoms1 >> stringcustom1;
        std::string quote = "/";
        std::string doublequote = "\\";
        std::string::size_type ir1 = stringcustom1.find(quote);
        if (ir1 != std::string::npos)
            stringcustom1.replace(ir1, quote.length(), doublequote);
        return stringcustom1;
    }

char outfitchar[255];
void Outfit::checkoutfitfolder()
{
    ifstream outfitifstream;
    outfitifstream.open(Directory::get_current_dir() + "\\ThunderMenu\\Outfit\\");
    if (outfitifstream) {
        outfitifstream >> outfitchar;
    }
    if (!outfitifstream) {
        makeoutfitfolder();
    }
    outfitifstream.close();
}

char teleportchar[255];
void Teleport::teleportfolder()
{
    ifstream teleportstream;
    teleportstream.open(Directory::get_current_dir() + "\\ThunderMenu\\Teleport\\");
    if (teleportstream) {
        teleportstream >> teleportchar;
    }
    if (!teleportstream) {
        maketeleportfolder();
    }
    teleportstream.close();
}
char youtubefoldchar[255];
void YoutubeFolder::FolderYoutube()
{
    ifstream youtubefold;
    youtubefold.open(Directory::get_current_dir() + "\\ThunderMenu\\Youtube\\");
    if (youtubefold) {
        youtubefold >> youtubefoldchar;
    }
    if (!youtubefold) {
        makeyoutubefolder();
    }
    youtubefold.close();
}

char Overseechar[255];

void OverSeeing::Overseefolder()
{
    ifstream Oversee;
    Oversee.open(Directory::get_current_dir() + "\\ThunderMenu\\Oversee\\");
    if (Oversee) {
        Oversee >> Overseechar;
    }
    if (!Oversee) {
        makeoverseefolder();
    }
    Oversee.close();
}

char addPlayerchar[255];

void OverSeeing::addPlayerfolder()
{
    ifstream Oversee;
    Oversee.open(Directory::get_current_dir() + "\\ThunderMenu\\Oversee\\");
    if (Oversee) {
        Oversee >> addPlayerchar;
    }
    if (!Oversee) {
        makeaddPlayerfolder();
    }
    Oversee.close();
}

char* SaveOutfits(char* windowName = "", int maxInput = 21, char* defaultText = "") {
    WAIT(50);
    GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
    while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
    if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return ""; //1
    return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}
std::string Outfit::outfitnamesaved = "";
void Outfit::savedoutfits()
{
    /*if (Menu::Option((char*)langage::SaveOutfit.c_str())) {*/
        string outfitsaved = SaveOutfits();
        if (outfitsaved != "")
        {
            Outfit::outfitnamesaved = outfitsaved;
            /*Features::SaveOutfit(outfitsaved);*/
        }
        else
        {
        }
    /*}*/
}


char* CharKeyboardsaveteleport(char* windowName = "", int maxInput = 21, char* defaultText = "") {
    WAIT(50);
    GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "", "", defaultText, "", "", "", maxInput);
    while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0) WAIT(0);
    if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()) return ""; //Thunder
    return GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT();
}

std::string Teleport::Teleportnamesaved = "";
void Teleport::savedTeleport()
{
    /*if (Menu::Option((char*)langage::SaveOutfit.c_str())) {*/
   string saveteleport = CharKeyboardsaveteleport();
    if (saveteleport != "")
    {
        Teleport::Teleportnamesaved = saveteleport;
        /*Features::SaveOutfit(outfitsaved);*/
    }
    else
    {
    }
    /*}*/
}

//string saveteleport;
//string thunder;


std::string Teleport::teleportName = "";

std::string Outfit::OutfitName = "";
int Outfit::Face = 0;
int Outfit::Head = 0;
int Outfit::Hair = 0;
int Outfit::Torso = 0;
int Outfit::Legs = 0;
int Outfit::Hands = 0;
int Outfit::Feet = 0;
int Outfit::Eyes = 0;
int Outfit::Accessories = 0;
int Outfit::Tasks = 0;
int Outfit::Textures = 0;
int Outfit::Torso2 = 0;
int Outfit::HeadProp = 0;
int Outfit::EyeProp = 0;
int Outfit::EarProp = 0;
