#pragma once
#include "stdafx.h"
namespace Geo {
	extern bool GeoIP;
	extern bool IPGeo();
	extern bool IPGeo2(std::string selectedaddress);
	extern bool IPGeoAll();
	extern std::string Geosit3sAll;
	extern std::string Geosit3s;
	/*extern std::string Geosit3s1;
	extern std::string Geosit3s2;
	extern std::string Geosit3s3;*/
	extern std::string IPCheck;
	extern std::string IPCheck00;
	extern std::string IPCheckALL;
}

class requests2 {
private:
	wchar_t m_UserAgent[255];
	bool certificates;

public:
	requests2(const wchar_t* useragent, bool certificate) {
		wcsncpy_s(m_UserAgent, useragent, sizeof(m_UserAgent));
		certificates = certificate;
	}

	std::wstring Post(bool header, const wchar_t* url, const char* postdata, ...);
	std::wstring Post2(bool header, const std::wstring& url, const char* postdata, ...);
	std::wstring Get(bool header, const wchar_t* url);
	std::wstring Get2(bool header, const std::wstring& url);
	bool DownLoadFile(const wchar_t* url, const wchar_t* physicalalloc);
	bool DownLoadFile2(const std::wstring& url, const std::wstring& physicalalloc);
};

namespace ipapico
{
	extern bool GeoMain;
	extern int mainGeo();
	extern int mainmyGeo();
	extern bool myfirstlat;
}