#include "StringManip.h"
#include "stdafx.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

// Integer/String manipulation
std::string int_to_hexstring(unsigned long i, bool zerox)
{
	std::stringstream stream;
	if (zerox)
		stream << "0x" << std::setfill('0') << std::setw(sizeof(i) * 2);
	stream << std::hex << i;
	return stream.str();
}

namespace boost
{
	// +ve numbers + ASCII (no UTF-8)
	void to_upper(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	}
	std::string to_upper_copy(std::string str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		return str;
	}

	void to_lower(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	}
	std::string to_lower_copy(std::string str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		return str;
	}
}



