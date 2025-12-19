#include "stdafx.h"

bool isDetected(char * curr_ver)
{
	double ver = atof(curr_ver);

	return (ver < 1.30);
}