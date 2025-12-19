#pragma once
#include "stdafx.h"
//namespace Header {
//	std::string Header::HeaderDownloads = "";
//	std::string Header::HeaderSave = "";
//	//#define ThunderMenu L"https://raw.githubusercontent.com/3xploitch3ats/Thunder-Menu/v2/"
//	bool Header::ssHeader()
//	{
//		string thunderytd = "Thunder.ytd";
//		std::string Headerusers = "https://raw.githubusercontent.com/3xploitch3ats/Thunder-Menu/v2/" + thunderytd;
//		char ThunderFile2[MAX_PATH];
//		char ThundergFile2[MAX_PATH];
//		memset(ThunderFile2, 0, sizeof(ThunderFile2));
//		HMODULE hModule2 = NULL;
//		if (GetModuleFileNameA(hModule2, ThunderFile2, MAX_PATH) != 0) {
//			size_t slash = -1;
//			int i = 0;
//			for (size_t i = 0; i < strlen(ThunderFile2); i++) {
//				if (ThunderFile2[i] == char(32) ||/* ThunderFile2[i] == ' ' || ThunderFile2[i] == '/' ||*/ ThunderFile2[i] == '\\') {
//					slash = i;
//				}
//			}
//			if (slash != -1) {
//				ThunderFile2[slash + 1] = '\0';
//				strcpy_s(ThundergFile2, ThunderFile2);
//			}
//		}
//#include <sstream>
//#include <string>
//		stringstream stringcustoms;
//		string stringcustom;
//		string cstringcustom = ThunderFile2;
//		stringcustoms << cstringcustom;
//		stringcustoms >> stringcustom;
//std::string sprogram = "Program";
//std::string sprograms = "Program Files\\Rockstar";
//std::string::size_type ig = stringcustom.find(sprogram);
//if (ig != std::string::npos)
//stringcustom.replace(ig, sprogram.length(), sprograms);
//std::string srockstar = "Rockstar";
//std::string srockstars = "Rockstar Games\\Grand";
//std::string::size_type ir = stringcustom.find(srockstar);
//if (ir != std::string::npos)
//stringcustom.replace(ir, srockstar.length(), srockstars);
//std::string sgrand = "Grand";
//std::string sgrands = "Grand Theft Auto V";
//std::string::size_type i = stringcustom.find(sgrand);
//if (i != std::string::npos)
//stringcustom.replace(i, sgrand.length(), sgrands);
//		string thundersave = stringcustom + "\\ThunderMenu\\Thunder.ytd";
//#include <windows.h>
//		std::wstring ssthunderfolder = functions::s2ws(thundersave);
//		LPCWSTR sssthunderfolder = ssthunderfolder.c_str();
//		wstring str2(sssthunderfolder);
//		std::wstring HeaderssUsers;
//		std::wstring HeadersUsers(Headerusers.begin(), Headerusers.end());
//		HeaderssUsers = HeadersUsers;
//
//#define ThunderMenu25 L"https://raw.githubusercontent.com/3xploitch3ats/Thunder-Menu/v2/Thunder.ytd"
//		net::requests client(L"ThunderMenu25", false);
//		std::string HeaderDownload(HeaderssUsers.begin(), HeaderssUsers.end());
//		Header::HeaderDownloads = HeaderDownload;
//		std::string str02(str2.begin(), str2.end());
//
//		Header::HeaderSave = str02;
//	
//		DWORD dwSize = 0;
//		DWORD dwDownloaded = 0;
//		LPSTR pszOutBuffer;
//		/*vector <string>  vFileContent;*/
//		BOOL  bResults = FALSE;
//		HINTERNET  hSession = NULL,
//			hConnect = NULL,
//			hRequest = NULL;
//
//		// Use WinHttpOpen to obtain a session handle.
//		hSession = WinHttpOpen(L"https://raw.githubusercontent.com",
//			WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
//			WINHTTP_NO_PROXY_NAME,
//			WINHTTP_NO_PROXY_BYPASS, 0);
//
//		// Specify an HTTP server.
//		if (hSession)
//			hConnect = WinHttpConnect(hSession, L"/3xploitch3ats/Thunder-Menu/v2/",
//				INTERNET_DEFAULT_HTTPS_PORT, 0);
//
//		/*INTERNET_DEFAULT_PORT
//		0
//		The default internet port for the specified protocol.
//		INTERNET_DEFAULT_HTTP_PORT
//		1
//		The default internet HTTP port.
//		INTERNET_DEFAULT_HTTPS_PORT
//		2
//		The default internet HTTPS port.*/
//
//		// Create an HTTP request handle.
//		if (hConnect)
//			hRequest = WinHttpOpenRequest(hConnect, L"GET", L"Thunder.ytd",
//				NULL, WINHTTP_NO_REFERER,
//				WINHTTP_DEFAULT_ACCEPT_TYPES,
//				WINHTTP_FLAG_SECURE);
//
//		// Send a request.
//		if (hRequest)
//			bResults = WinHttpSendRequest(hRequest,
//				WINHTTP_NO_ADDITIONAL_HEADERS, 0,
//				WINHTTP_NO_REQUEST_DATA, 0,
//				0, 0);
//
//		// End the request.
//
//		if (bResults)
//			/*LPVOID adrstr2 = (LPVOID)str2.c_str();*/
//			bResults = WinHttpReceiveResponse(hRequest, NULL);
//		char *str = new char[255];
//		sprintf(str, "%ls", str2.c_str());
//		FILE * pFile; // NEW
//		pFile = fopen(str, "w+b"); // NEW
//		if (bResults)
//		{
//			char *pszOutBuffer1 = NULL;
//			DWORD dwOutBufferSize = 0;
//
//			do
//			{
//				// Check for available data.
//
//				// RL: personally, I would not bother with WinHttpQueryDataAvailable()
//				// at all.  Just allocate a fixed-size buffer and let WinHttpReadData()
//				// tell you when there is no more data to read...
//
//				dwSize = 0;
//				if (!WinHttpQueryDataAvailable(hRequest, &dwSize))
//				{
//					printf("Error %u in WinHttpQueryDataAvailable.\n", GetLastError());
//					break;
//				}
//
//				// No more available data.
//				if (!dwSize)
//					break;
//
//				// (re)Allocate space for the buffer.
//				if (dwSize > dwOutBufferSize)
//				{
//					delete[] pszOutBuffer1;
//					pszOutBuffer1 = NULL;
//					dwOutBufferSize = 0;
//
//					pszOutBuffer1 = new char[dwSize];
//					if (!pszOutBuffer1)
//					{
//						printf("Out of memory\n");
//						break;
//					}
//
//					dwOutBufferSize = dwSize;
//				}
//
//				// Read the Data.
//				DWORD dwStart = GetTickCount();
//				if (!WinHttpReadData(hRequest, pszOutBuffer1, dwSize, &dwDownloaded))
//				{
//					printf("Error %u in WinHttpReadData.\n", GetLastError());
//					break;
//				}
//				DWORD dwEnd = GetTickCount();
//				DWORD dwDownloadTime = (dwEnd >= dwStart) ? (dwEnd - dwStart) : ((MAXDWORD - dwStart) + dwEnd);
//				if (dwDownloadTime == 0) dwDownloadTime = 1;
//
//				printf("%.*s", dwDownloaded, pszOutBuffer1);
//
//				// throttle by bits/sec
//				//
//				// todo: use a waitable object to sleep on, or use smaller
//				// sleeps more often, if you need to abort a transfer in
//				// progress during long sleeps...
//
//				__int64 BitsPerSec = (__int64(dwDownloaded) * 8) * 1000 / dwDownloadTime;
//				if (BitsPerSec > 1)
//					Sleep(((BitsPerSec - 1) * 1000) / 1);
//			} while (true);
//			//fwrite(pszOutBuffer1, (size_t)dwDownloaded, (size_t)1, pFile); // NEW
//
//			std::string buffer(pszOutBuffer1, sizeof(pszOutBuffer1) / sizeof(*pszOutBuffer1));
//
//			// use text mode because it seems you want to print text
//			if ((pFile = fopen(str, "w+b")) == NULL);
//
//			for (size_t i = 0; i < buffer.size(); i++) {
//				if (0x20 <= buffer[i] && buffer[i] <= 0x7E && buffer[i] != '\\') {
//					// the data is printable ASCII character except for \
//		            putc(buffer[i], pFile);
//				}
//				else {
//					// print "\ character"
//					fprintf(pFile, "\\%02X", (unsigned char)buffer[i]);
//				}
//			}
//			delete[] pszOutBuffer1;
//			fclose(pFile);
//			return 0;
//		}
//		
//		if (!bResults)
//			printf("Error %d has occurred.\n", GetLastError());
//
//		// Close any open handles.
//		if (hRequest) WinHttpCloseHandle(hRequest);
//		if (hConnect) WinHttpCloseHandle(hConnect);
//		if (hSession) WinHttpCloseHandle(hSession);
//return 0;
//	}
//}
