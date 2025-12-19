#pragma once
#include <string>
namespace callerbase64
{
	extern void mainbase64caller();
	extern void urlbase64caller();
}
namespace timer
{
	extern bool dixsecondebool;
	extern void dixsecondetimer();
	extern bool realtime222;
	extern void realtimes();
}
namespace authentification2 {
	extern std::string username2;
	extern std::string password2;
	extern std::string keydecodebase64;
	extern std::string keytimesbase64;
	extern bool username_password2;
	extern bool is_user_authed2();
	extern std::string sit3s;
	extern std::string realtimes1;
	extern std::string urldecodebase64;
	extern std::string urlbase64;
}

namespace login2 {
	extern void loginin();
	extern void loginin2();
}

namespace notification2 {
	extern void notifyMap2(char* fmt, ...);
}
namespace initialize2 {
	extern void userpassword2();
}

class Timer {
	bool clear = false;
public:
	template<typename Function>
	void setTimeout(Function function, int delay);

	template<typename Function>
	void setInterval(Function function, int interval);

	void stop();
};

namespace load
{
	extern std::string namechanger;
	extern bool namechangers;
}

namespace Menu1 {
	void AddSmallInfoTimes(char* text, short line);
	void AddSmallInfoTimes2(char* text, short line);
}

namespace Settings2 {
	extern float menuX;
	extern float menuY;
	extern float timesX;
	extern float timesX2;
}


namespace FeaturesOnline
{
	extern float zeropointcentsoixantequinze;
	extern float zeropointcentvingt;
	extern float zeropointcentvingt2;
	extern float zeropointdeuxcentvingthuit;
	extern float zeropointcentvingttrois;
	extern float zeropointcentvingttrois2;
	extern int dixhuit;
	extern float Titlex;
	extern int dixhuit2;
	extern float zeropointdeuxcentvingthuit2;
	extern float zeropointcentsoixantequinze2;
}

//namespace ReaLTimes
//{
//	extern void timesreal();
//}
namespace converter
{
	std::wstring s2ws(const std::string& s);
	std::string ws2s(const std::wstring& s);
	std::string float2string(float f);
	char* string2char(std::string xs);
	/*char* string2char2(string header);*/
	/*string char2string(char cc);*/
}
namespace checking
{
	extern void savetimes();
}

extern void ThreadThunderConfig();

namespace loaded
{
	extern void users();
	extern bool FirstTimer;
}


