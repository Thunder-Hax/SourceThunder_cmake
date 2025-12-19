#include "stdafx.h"
#include "GETHASHKEY.h"
#include <iostream> 
H HASH::GET_HASH_KEY(char* value)
{
	size_t len = strlen(value);
	DWORD hash, i;
	for (hash = i = 0; i < len; ++i)
	{
		hash += tolower(value[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash; // joaat
}
H HASH::GET_HASH_KEY(const std::wstring& value)
{
	size_t len = value.length();
	DWORD hash, i;
	for (hash = i = 0; i < len; ++i)
	{
		hash += tolower(value[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}
H HASH::GET_HASH_KEY(const std::string& value)
{
	size_t len = value.length();
	DWORD hash, i;
	for (hash = i = 0; i < len; ++i)
	{
		hash += tolower(value[i]);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}
DWORD HASH::value3;
H HASH::GETHASHKEYSTRING(std::string hexstring)
{
	std::stringstream shex;
	shex << std::hex << hexstring;
	shex >> HASH::value3;
	return 0;
}

std::string HASH::hex = "";
H HASH::GETHASHKEYDWORD(DWORD value2)
{
	std::stringstream hhex;
	hhex << std::hex << value2;
	HASH::hex = hhex.str();
	return 0;
}

// Function to convert hexadecimal to decimal 
int hexadecimalToDecimal(char hexVal[])
{
	int len = strlen(hexVal);

	// Initializing base value to 1, i.e 16^0 
	int base = 1;

	int dec_val = 0;

	// Extracting characters as digits from last character 
	for (int i = len - 1; i >= 0; i--)
	{
		// if character lies in '0'-'9', converting  
		// it to integral 0-9 by subtracting 48 from 
		// ASCII value. 
		if (hexVal[i] >= '0' && hexVal[i] <= '9')
		{
			dec_val += (hexVal[i] - 48) * base;

			// incrementing base by power 
			base = base * 16;
		}

		// if character lies in 'A'-'F' , converting  
		// it to integral 10 - 15 by subtracting 55  
		// from ASCII value 
		else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
		{
			dec_val += (hexVal[i] - 55) * base;

			// incrementing base by power 
			base = base * 16;
		}
	}

	return dec_val;
}

//link-https://www.geeksforgeeks.org/program-for-hexadecimal-to-decimal/
//link-https://www.geeksforgeeks.org/program-decimal-hexadecimal-conversion/

// function to convert decimal to hexadecimal 
void decToHexa(int n)
{
	// char array to store hexadecimal number 
	char hexaDeciNum[100];

	// counter for hexadecimal number array 
	int i = 0;
	while (n != 0)
	{
		// temporary variable to store remainder 
		int temp = 0;

		// storing remainder in temp variable. 
		temp = n % 16;

		// check if temp < 10 
		if (temp < 10)
		{
			hexaDeciNum[i] = temp + 48;
			i++;
		}
		else
		{
			hexaDeciNum[i] = temp + 55;
			i++;
		}

		n = n / 16;
	}

	// printing hexadecimal number array in reverse order 
	for (int j = i - 1; j >= 0; j--)
		std::cout << hexaDeciNum[j];
}

