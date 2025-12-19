#pragma once
#include "stdafx.h"
#include "Geo.h"

#include <chrono>
#include <thread>

#include "PersistOutfit.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include <string>
#include <vector>
#include <fstream>


#include <string>
#include <windows.h>

#include <cstdarg>
#include <vector>


std::wstring requests2::Post(bool header, const wchar_t* url, const char* postdata, ...) {
	static char buffer[32768];

	va_list ap;
	va_start(ap, postdata);
	int length = vsnprintf(buffer, 32768, postdata, ap);
	va_end(ap);

	WinHttpClient client(url);

	client.SetRequireValidSslCertificates(this->certificates);
	client.SetUserAgent(this->m_UserAgent);

	std::string data(buffer);
	client.SetAdditionalDataToSend(reinterpret_cast<BYTE*>(data.data()), data.size());

	wchar_t szSize[50] = L"";
	swprintf_s(szSize, L"%zd", data.size());
	std::wstring headers = L"Content-Length: ";
	headers += szSize;
	headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
	client.SetAdditionalRequestHeaders(headers);

	client.SendHttpRequest(L"POST");

	return header ? client.GetResponseHeader() : client.GetResponseContent();
}

std::wstring requests2::Post2(bool header, const std::wstring& url, const char* postdata, ...) {
	static char buffer[32768];

	va_list ap;
	va_start(ap, postdata);
	int length = vsnprintf(buffer, 32768, postdata, ap);
	va_end(ap);

	WinHttpClient client(url);

	client.SetRequireValidSslCertificates(this->certificates);
	client.SetUserAgent(this->m_UserAgent);

	std::string data(buffer);
	client.SetAdditionalDataToSend(reinterpret_cast<BYTE*>(data.data()), data.size());

	wchar_t szSize[50] = L"";
	swprintf_s(szSize, L"%zd", data.size());
	std::wstring headers = L"Content-Length: ";
	headers += szSize;
	headers += L"\r\nContent-Type: application/x-www-form-urlencoded\r\n";
	client.SetAdditionalRequestHeaders(headers);

	client.SendHttpRequest(L"POST");

	return header ? client.GetResponseHeader() : client.GetResponseContent();
}

std::wstring requests2::Get(bool header, const wchar_t* url) {
	WinHttpClient client(url);

	client.SetRequireValidSslCertificates(this->certificates);
	client.SetUserAgent(this->m_UserAgent);

	client.SendHttpRequest();

	return header ? client.GetResponseHeader() : client.GetResponseContent();
}

std::wstring requests2::Get2(bool header, const std::wstring& url) {
	WinHttpClient client(url);

	client.SetRequireValidSslCertificates(this->certificates);
	client.SetUserAgent(this->m_UserAgent);

	client.SendHttpRequest();

	return header ? client.GetResponseHeader() : client.GetResponseContent();
}

bool requests2::DownLoadFile(const wchar_t* url, const wchar_t* physicalalloc) {
	WinHttpClient downloadClient(url);

	downloadClient.SetUserAgent(this->m_UserAgent);

	return downloadClient.SaveResponseToFile(physicalalloc);
}

bool requests2::DownLoadFile2(const std::wstring& url, const std::wstring& physicalalloc) {
	WinHttpClient downloadClient(url);

	downloadClient.SetUserAgent(this->m_UserAgent);

	return downloadClient.SaveResponseToFile(physicalalloc);
}


// Convert a string to a wide string
std::wstring s2ws(const std::string& s) {
    int slength = static_cast<int>(s.length());
    int len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, nullptr, 0);
    std::wstring r(len, L'\0');
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
    return r;
}

// Convert a wide string to a string
std::string ws2s(const std::wstring& s) {
    int slength = static_cast<int>(s.length());
    int len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, nullptr, 0, nullptr, nullptr);
    std::string r(len, '\0');
    WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, &r[0], len, nullptr, nullptr);
    return r;
}

//namespace oversee {
//    std::vector<std::string> city(32, "don't know");
//    std::vector<std::string> region(32, "don't know");
//    std::vector<std::string> country_name(32, "don't know");
//    std::vector<std::string> country_capital(32, "don't know");
//    std::vector<std::string> latitude(32, "don't know");
//    std::vector<std::string> longitude(32, "don't know");
//}

void saveToJson(const std::string& filename, const std::string& city, const std::string& region, const std::string& country_name, const std::string& country_capital, const std::string& latitude, const std::string& longitude) {
	nlohmann::json jsonData;
	jsonData["city"] = city;
	jsonData["region"] = region;
	jsonData["country_name"] = country_name;
	jsonData["country_capital"] = country_capital;
	jsonData["latitude"] = latitude;
	jsonData["longitude"] = longitude;

	std::ofstream file(filename);
	if (file.is_open()) {
		file << jsonData.dump(4); // Pretty print with 4 spaces
		file.close();
	}
}

#include <string>
#include <sstream> // Pour std::ostringstream

std::string doubleToString(double value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}
#include <string>
#include <sstream>
#include <iostream>

double stringToDouble(const std::string& str) {
	std::istringstream iss(str);
	double value;
	iss >> value;
	return value;
}


bool haveip2 = false;
int findip2()
{
	std::string noip(".");
	if (Features::IPSelected.find(noip) != std::string::npos)
	{
		haveip2 = true;
	}
	else {
		haveip2 = false;
	}
	return 0;
}
int findmyip2()
{
	std::string noip(".");
	if (Features::myIPSelected.find(noip) != std::string::npos)
	{
		haveip2 = true;
	}
	else {
		haveip2 = false;
	}
	return 0;
}
bool ipapico::myfirstlat = 1;

bool ipapico::GeoMain = 0;

std::string myipcheck = "";
int ipapico::mainmyGeo() {


	if (Features::myIPSelected == myipcheck) {
		return 0; // Les IP sont identiques, aucune action supplémentaire nécessaire
	}
	else {
		/*std::string Geousers = "https://ipapi.co/" + Features::IPSelected + "/json";
		std::wstring geosUsers = s2ws(Geousers);
		requests2 m_request(L"Mozilla/5.0", false);
		Log::Msg("ipapi log2");
		std::wstring answer = m_request.Get2(false, geosUsers);
		std::string sites = ws2s(answer);*/
		std::string Geousers = "";
		Geousers = "https://ipapi.co/" + Features::myIPSelected + "/json";
		std::wstring geossUsers;

		/*std::wstring geosUsers(Geousers.begin(), Geousers.end());*/
		std::wstring geosUsers(s2ws(Geousers));
		geossUsers = geosUsers;
#define ThunderMenu21 L"geossUsers"
		net::requests m_request(ThunderMenu21, false);
		std::wstring answer = m_request.Get2(false, geossUsers);

		std::string sites(ws2s(answer));
		Geo::Geosit3s = sites;
		GeoLocation::GeoLoc = Geo::Geosit3s;
		oversee::reserved = "";
		findmyip2();;
		GeoLocation::findRateLimited();
		GeoLocation::findSignup();
		GeoLocation::findReserved();
		GeoLocation::findnull();
		GeoLocation::GeoLoc = "";

		if (haveip2)
		{
			if (!GeoLocation::findReservedbool)
			{
				if (!GeoLocation::findRateLimitedbool && !GeoLocation::nullboolstringtoint)
				{
					if (!GeoLocation::findSignupbool)
					{
						auto json = nlohmann::json::parse(answer.begin(), answer.end());
						if (json.contains("latitude") && json.contains("longitude")) {
							double latitude = json["latitude"].get<double>();
							double longitude = json["longitude"].get<double>();
							oversee::mylatitude = doubleToString(latitude);
							oversee::mylongitude = doubleToString(longitude);
							GeoMain = false;
						}
						else {

							GeoMain = false;
						}
					}
				}
			}
			else
			{
				oversee::reserved = "Reserved IP Address";
			}
		}
		myipcheck = Features::myIPSelected;


	}
	return 0;
}


int ipapico::mainGeo() {
	if (Features::IPSelected == Geo::IPCheck) {
		return 0; // Les IP sont identiques, aucune action supplémentaire nécessaire
	}
	else {
		/*std::string Geousers = "https://ipapi.co/" + Features::IPSelected + "/json";
		std::wstring geosUsers = s2ws(Geousers);
		requests2 m_request(L"Mozilla/5.0", false);
		Log::Msg("ipapi log9");
		std::wstring answer = m_request.Get2(false, geosUsers);
		std::string sites = ws2s(answer);*/
		std::string Geousers = "";
		Geousers = "https://ipapi.co/" + Features::IPSelected + "/json";
		std::wstring geossUsers;
		std::wstring geosUsers(s2ws(Geousers));
		geossUsers = geosUsers;
#define ThunderMenu21 L"geossUsers"
		net::requests m_request(ThunderMenu21, false);
		std::wstring answer = m_request.Get2(false, geossUsers);
		std::string sites(ws2s(answer));
		Geo::Geosit3s = sites;
		GeoLocation::GeoLoc = Geo::Geosit3s;
		oversee::reserved = "";
		findip2();

		GeoLocation::findRateLimited();
		GeoLocation::findSignup();
		GeoLocation::findReserved();
		GeoLocation::findnull();
		GeoLocation::GeoLoc = "";
		if (haveip2)
		{
			if (!GeoLocation::findReservedbool)
			{
				if (!GeoLocation::findRateLimitedbool && !GeoLocation::nullboolstringtoint)
				{
					if (!GeoLocation::findSignupbool)
					{
						//try {
						auto json = nlohmann::json::parse(answer.begin(), answer.end());
						if (json.contains("city") && json.contains("region") && json.contains("country_name") && json.contains("country_capital") && json.contains("latitude") && json.contains("longitude")) {
							std::string city = json["city"].get<std::string>();
							std::string region = json["region"].get<std::string>();
							std::string country_name = json["country_name"].get<std::string>();
							std::string country_capital = json["country_capital"].get<std::string>();
							double latitude = json["latitude"].get<double>();
							double longitude = json["longitude"].get<double>();
							oversee::city = city;
							oversee::region = region;
							oversee::country_name = country_name;
							oversee::country_capital = country_capital;
							oversee::latitude = doubleToString(latitude);
							oversee::longitude = doubleToString(longitude);

							GeoMain = true;
						}
						else {
							oversee::city = "don't know";
							oversee::region = "don't know";
							oversee::country_name = "don't know";
							oversee::country_capital = "don't know";
							oversee::latitude = "don't know";
							oversee::longitude = "don't know";

							GeoMain = false;
						}
						/*}
						catch (const nlohmann::json::parse_error& e) {
							oversee::city = "don't know";
							oversee::region = "don't know";
							oversee::country_name = "don't know";
							oversee::country_capital = "don't know";
							oversee::latitude = "don't know";
							oversee::longitude = "don't know";

							GeoMain = false;
						}*/
					}
				}
			}
			else
			{
				oversee::reserved = "Reserved IP Address";
			}
		}
		Geo::IPCheck = Features::IPSelected;
	}
	return 0;
}

namespace Geo {
	std::string Geo::Geosit3sAll = "";
	std::string Geo::Geosit3s = "";
	std::string Geo::IPCheck = "";
	std::string Geo::IPCheck00 = "";
	std::string Geo::IPCheckALL = "";
	bool Geo::GeoIP = false;
	bool Geo::IPGeoAll()
	{
		int intoneall = atoi(Features::IPSelected.c_str());
		int inttwoall = atoi(Geo::IPCheckALL.c_str());
		if (intoneall==inttwoall)
		{
			return 0;
		}
		else {
			std::string Geousersall = "";
				Geousersall = "https://ipapi.co/" + Features::IPSelected + "/json";
			std::wstring geossUsersall;
			std::wstring geosUsersall(Geousersall.begin(), Geousersall.end());
			geossUsersall = geosUsersall;
#define ThunderMenu20 L"geossUsersall"
			net::requests m_requestall(ThunderMenu20, false);
			std::wstring answerall = m_requestall.Get2(false, geossUsersall);
			std::string sitesall(answerall.begin(), answerall.end());
			Geo::Geosit3sAll = sitesall;
			Geo::IPCheckALL = Features::IPSelected;
		}
		return 0;
	}

	std::wstring s2ws(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		std::wstring r(len, L'\0');
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, &r[0], len);
		return r;
	}

	std::string ws2s(const std::wstring& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
		std::string r(len, '\0');
		WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, &r[0], len, 0, 0);
		return r;
	}

bool Geo::IPGeo()
	{

		int intone = atoi(Features::IPSelected.c_str());
		int inttwo = atoi(Geo::IPCheck.c_str());
		if (intone==inttwo)
		{ 
			return 0;
		}
			else {
			std::string Geousers = "";
		Geousers = "https://ipapi.co/" + Features::IPSelected + "/json";
		std::wstring geossUsers;

		/*std::wstring geosUsers(Geousers.begin(), Geousers.end());*/
		std::wstring geosUsers(s2ws(Geousers));
		geossUsers = geosUsers;
#define ThunderMenu21 L"geossUsers"
		net::requests m_request(ThunderMenu21, false);
		std::wstring answer = m_request.Get2(false, geossUsers);
		std::string sites(ws2s(answer));

		/*std::string sites(answer.begin(), answer.end());*/
		Geo::Geosit3s = sites;
		persist_oversee::saveapi();
		/*oversee::city = "";
		oversee::region = "";
		oversee::country_name = "";
		oversee::country_capital = "";*/
		/*oversee::error = "";
		oversee::reason = "";*/
		oversee::reserved = "";
		GeoLocation::findip();
		GeoLocation::findrid();
		GeoLocation::findRateLimited();
		GeoLocation::findSignup();
		GeoLocation::findReserved();
		GeoLocation::findnull();
		if (GeoLocation::haveip && GeoLocation::haverid)
		{
			if (!GeoLocation::findReservedbool)
			{
				/*auto json{ nlohmann::json::parse(answer.begin(), answer.end()) };
				if (json.contains("city") && json.contains("region") && json.contains("country_name") && json.contains("country_capital"))
				{
					oversee::city = json["city"].get<std::string>();
					oversee::region = json["region"].get<std::string>();
					oversee::country_name = json["country_name"].get<std::string>();
					oversee::country_capital = json["country_capital"].get<std::string>();
				}
				else
				{
					oversee::city = "dont know";
					oversee::region = "dont know";
					oversee::country_name = "dont know";
					oversee::country_capital = "dont know";
				}*/

				persist_oversee::do_presentation_layer3();
			}
			else
			{
				oversee::reserved = "Reserved IP Address";
			}
		}
		Geo::IPCheck = Features::IPSelected;
		}
		return 0;
	}

bool Geo::IPGeo2(std::string selectedaddress)
{

	int intone = atoi(selectedaddress.c_str());
	int inttwo = atoi(Geo::IPCheck00.c_str());
	if (intone == inttwo)
	{
		return 0;
	}
	else {
		std::string Geousers = "";
		Geousers = "https://ipapi.co/" + selectedaddress + "/json";
		std::wstring geossUsers;
		std::wstring geosUsers(s2ws(Geousers));
		geossUsers = geosUsers;
#define ThunderMenu21 L"geossUsers"
		net::requests m_request(ThunderMenu21, false);
		std::wstring answer = m_request.Get2(false, geossUsers);
		auto json{ nlohmann::json::parse(answer.begin(), answer.end()) };
		if (json.contains("city") && json.contains("region") && json.contains("country_name") && json.contains("country_capital"))
		{
			oversee::city00 = json["city"].get<std::string>();
			oversee::region00 = json["region"].get<std::string>();
			oversee::country_name00 = json["country_name"].get<std::string>();
			oversee::country_capital00 = json["country_capital"].get<std::string>();
		}
		else
		{
			oversee::city00 = "";
			oversee::region00 = "";
			oversee::country_name00 = "";
			oversee::country_capital00 = "";
		}
		Geo::IPCheck00 = selectedaddress;
	}
	return 0;
}
}