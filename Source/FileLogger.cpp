#include "stdafx.h"
#include "FileLogger.h"
#include "macros.h"
#include <fstream>
#include <time.h>

//namespace ige
//{
//	ige::FileLogger ThunderLogObject("ThunderLog.txt");
//	std::ofstream& myLog = ThunderLogObject.myFile;
//
//	FileLogger::FileLogger(const char* fname)
//	{
//		myFile.open(fname);
//
//		if (myFile.is_open())
//		{
//			time_t now = time(0);
//			tm t;
//			localtime_s(&t, &now);
//
//			myFile << "Thunder " << THUNDER_CURRENT_VER_ << std::endl;
//			myFile << "Log file created " << t.tm_mday << "/" << t.tm_mon + 1 << "/" << t.tm_year + 1900 << std::endl << std::endl << std::endl;
//		}
//
//	}
//
//	FileLogger::~FileLogger()
//	{
//		if (myFile.is_open())
//		{
//			myFile << std::endl << std::endl;
//
//			myFile.close();
//		}
//
//	}
//
//	std::ofstream& operator<<(std::ofstream& stream, const ige::LogType& logType)
//	{
//		time_t now = time(0);
//		tm t;
//		localtime_s(&t, &now);
//
//		stream << std::endl;
//
//		switch (logType)
//		{
//		case ige::LogType::LOG_ERROR: stream << "ERROR: "; break;
//		case ige::LogType::LOG_WARNING: stream << "WARNING: "; break;
//		case ige::LogType::LOG_INFO: stream << "INFO: "; break;
//		}
//
//		stream << "[" << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << "] ";
//
//		return stream;
//	}
//}

