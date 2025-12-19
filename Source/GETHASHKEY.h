#pragma once
typedef unsigned long DWORD;
typedef DWORD H;
namespace HASH
{
	H GET_HASH_KEY(char* value);
	H GET_HASH_KEY(const std::wstring& value);
	H GET_HASH_KEY(const std::string& value);
	extern DWORD value3;
	H GETHASHKEYSTRING(std::string hexstring);
	extern std::string hex;
	H GETHASHKEYDWORD(DWORD value2);
}