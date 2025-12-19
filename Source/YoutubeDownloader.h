#pragma once
namespace yd
{
	extern void BgMusic(bool enable);
	extern int youtubeDownloader(std::string link, std::string name);
	extern std::string youtubelink;
	extern std::string outputname;
	extern bool youtubebool;
	extern int start();
	extern int stop();
	extern void startmusicdownloadsmp3(const std::string title);
	extern std::string szAlias;
	extern int looptimer();
	extern bool loopbool;
	extern int convertint;
	extern int convertto96k(std::string ffmpegname);
	extern bool timerffmpegbool;
	extern int timerffmpegconvert(std::string ffmpegname);
	extern int pause();
	extern int resumeplay();
	extern std::wstring s2ws2(const std::string& s);
	extern bool converted;
	extern int renameffmpeg1();
	extern int renameffmpeg2();
}
namespace youdown
{
	struct downyou
	{
		std::string ytl;
		std::string ytn;
	};

	void to_json(nlohmann::json& j, const downyou& youdown);
	void from_json(const nlohmann::json& j, downyou& youdown);
};
class youtube_persist
{
public:
	static void do_presentation_layer2();
private:
	static void save_location2(std::string link, std::string name);
	static void load_location2(std::string name);
	static void delete_location2(std::string name);
	static std::vector<std::string> list_locations2();
	static void save2(youdown::downyou downyou, std::string name);
	static void save_json2(nlohmann::json json);
	static nlohmann::json get_locations_json2();
	static std::string get_locations_config2();
};
namespace dlyoutube
{
	extern int downloading();
	extern int downloading2();
	extern std::string youtubedl;
}

namespace ffmpeg
{
	extern std::string gplzip3;
}
