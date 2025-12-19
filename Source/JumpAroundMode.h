#pragma once

namespace _JumpAroundMode_
{
	extern int jumpstart1;
	extern int jumpend1;
	extern float jumpstart2;
	extern float jumpend2;
	extern float lightrange;
	extern float lightrange1;
	extern float lightrange2;
	extern float lightintensity;
	extern float lightposition;
	extern float discolightangle;

	extern bool bEnabled;
	extern bool jumpAround_on;
	extern bool jumpAround_off;
	inline void DrawDiscoLights();

	void Tick();
	void startmusicdownloadsmp3(const std::string title);
	void startmusicdownloads2(const std::string title);
	void BgMusic(bool enable);
	void BgMusic2(bool enable);
	void StartJumping(bool enable);
	int stop();
	int start();
}

namespace massacremode
{
	extern bool bmassEnabled;
	extern void set_massacre_mode_tick();
}