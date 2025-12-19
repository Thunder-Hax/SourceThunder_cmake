#include "stdafx.h"
#pragma execution_character_set("utf-8")
#include "Traduction.h"
#include "Language.h"

#include <Windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <wininet.h>
#include <string>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "wininet.lib")

// Variables
#include <tchar.h>
#include <iostream>
#include <wininet.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "wininet.lib")
#include <locale>
#include <codecvt>
#include <vector>
#include <sstream>
#include <fstream>
#include <regex>
#include <cstring>
#include <functional>
#include <type_traits>
#include <typeinfo>
#include <algorithm>
#include <ranges>
#include <iterator>

#include <string>
#include <cstring>
#include <string>
#include <vector>
#include <codecvt>
#include <iostream>
#include <chrono>
#include <thread>

char* lang[]
{
"VF",
"CHINESES",
"RUSSE",
"SPANISH",
"UKRAINIEN",
"VO",
"Other"
};

int MainWindow::menulangage()
{
    for (int i = 0; i < ARRAYSIZE(lang); i++)
    {
        if (Menu::Option(lang[i]))
        {
            langage::rawchar = lang[i];


            ofstream file(Directory::get_current_dir() + "\\ThunderMenu\\lang.langage", ios::binary); // ouverture du fichier en mode binaire

            if (file.is_open()) {
                file << langage::rawchar << std::endl;
            }
            file.close();
            langage::rawrequest();
            langage::loadfunction2();                 
        }
    }
    /*if (Menu::Option("Lang"))
    {
        langage::Translation();
        langage::loadfunction2();
    }*/
    if (Menu::Option("All Lang"))
    {
        power::main();
    }
    if (Menu::Option("Press Other for Auto-Load langage.langage"))
    {
        power::loadallLangage();
    }

    return 0;
}


