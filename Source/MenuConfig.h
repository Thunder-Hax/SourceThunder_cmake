#pragma once
#include "stdafx.h"
#include "SimpleIni.h"

namespace MenuConfig
{
	extern CSimpleIniA iniFile;
	extern bool bSaveAtIntervals;
	SI_Error ConfigInit();
	void ConfigRead();
	void ConfigSave();
}



