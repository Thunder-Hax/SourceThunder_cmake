#include "stdafx.h"
#include "Functions.h"
#include "reclass/GTAV-Classes/network/netPlayer.hpp"

#include <format>

#include "Log.h"

#include "NativeForce.h"
#include <unordered_map>

//#include <map>

#pragma warning(disable:4996)
#pragma warning(disable : 4244 4305) // double <-> float conversions
#define PROP_MONEY_BAG_01 0x113FD533

//#define PICKUP_MONEY_CASE 0xCE6FDD6B
//#define PICKUP_MONEY_VARIABLE 0xFE18F3AF

//#define PICKUP_MONEY_CASE 0x0
//#define MAIN_PERSISTENT 0x0

//#define PICKUP_MONEY_PURSE 0x1E9A99F8 //1
//#define PICKUP_MONEY_VARIABLE 0xEA888D49 //1

#define PROP_MONEY_BAG_02 -1666779307
#define PROP_WEED_01 452618762
#define PROP_WEED_02 -305885281

//bool ModMenu::unload = 1;

PlayerData players[32];
std::set<Ped> lastSeenPeds;

rage::fmatrix44 m_transformation_matrix2;
void model_to_world2(const rage::fvector3& model_coords, rage::fvector3& world_coords)
{
	world_coords.x = model_coords.x * m_transformation_matrix2.data[0][0] + model_coords.y * m_transformation_matrix2.data[1][0] + model_coords.z * m_transformation_matrix2.data[2][0] + m_transformation_matrix2.data[3][0];
	world_coords.y = model_coords.x * m_transformation_matrix2.data[0][1] + model_coords.y * m_transformation_matrix2.data[1][1] + model_coords.z * m_transformation_matrix2.data[2][1] + m_transformation_matrix2.data[3][1];
	world_coords.z = model_coords.x * m_transformation_matrix2.data[0][2] + model_coords.y * m_transformation_matrix2.data[1][2] + model_coords.z * m_transformation_matrix2.data[2][2] + m_transformation_matrix2.data[3][2];
}

/*m_Swapchain(Signature("48 8B 0D ? ? ? ? 48 8D 55 A0 48 8B 01").Scan().Add(3).Rip().As<decltype(m_Swapchain)&>()),*/
inline std::atomic_bool g_Running = true;
extern std::uint32_t g_HookFrameCount{};
eHookState		g_HookState;
bool Elite = false;

scrThread* ActiveThread()
{
	return *(scrThread**)(*(std::uintptr_t*)(__readgsqword(0x58)) + 0x830);
}
void SHVScriptManager::WndProc(HWND /*hwnd*/, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	for (auto& function : g_WndProcCb) function(uMsg, wParam, lParam);

	if (uMsg == WM_KEYDOWN || uMsg == WM_KEYUP || uMsg == WM_SYSKEYDOWN || uMsg == WM_SYSKEYUP)
	{
		for (auto& function : g_keyboardFunctions2) function((DWORD)wParam, lParam & 0xFFFF, (lParam >> 16) & 0xFF, (lParam >> 24) & 1, (uMsg == WM_SYSKEYDOWN || uMsg == WM_SYSKEYUP), (lParam >> 30) & 1, (uMsg == WM_SYSKEYUP || uMsg == WM_KEYUP));
	}
}
bool SHVScriptManager::isKeyPressedOnce(bool& bIsPressed, DWORD vk)
{
	if (IsKeyPressed(vk))
	{
		if (bIsPressed == false)
		{
			bIsPressed = true;
			return true;
		}
	}
	else if (bIsPressed == true)
	{
		bIsPressed = false;
	}
	return false;
}

//inline bool load_ground_at_3dcoord(Vector3& location)
//{
//	float groundZ;
//	const uint8_t attempts = 10;
//
//	for (uint8_t i = 0; i < attempts; i++)
//	{
//		// Only request a collision after the first try failed because the location might already be loaded on first attempt.
//		for (uint16_t z = 0; i && z < 1000; z += 100)
//		{
//			STREAMING::REQUEST_COLLISION_AT_COORD(location.x, location.y, (float)z);
//
//			/*script::get_current()->yield();*/
//		}
//
//		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(location.x, location.y, 1000.f, &groundZ, false))
//		{
//			location.z = groundZ + 1.f;
//
//			return true;
//		}
//
//
//
//	}
//
//	location.z = 1000.f;
//
//	return false;
//}

//HANDLE          g_MainFiber;
//SHVScriptThread	g_ScriptThread;
//SHVScriptThread	g_AdditionalThread;
//
//SHVScript* g_CurrentScript;
//std::uint32_t g_ThreadHash = "main_persistent"_joaat;
//
//void SHVScriptManager::MainFiber2()
//{
//	g_MainFiber = IsThreadAFiber() ? GetCurrentFiber() : ConvertThreadToFiber(nullptr);
//
//	if (g_MainFiber)
//	{
//		static SHVscrThread* target_thread = nullptr;
//
//		SHVscrThread* current_thread = GetActiveThread2();
//
//		// do this while script::wait
//		g_AdditionalThread.DoRun();
//		g_ScriptThread.DoRun();
//		//	SetActiveThread(target_thread);
//		//	SetActiveThread(current_thread);
//
//
//		static bool RemoveAllScriptsBool = false; const uint32_t RemoveAllScriptsKey = VK_NEXT; //Page Down
//		static bool LoadAllScriptsBool = false; const uint32_t LoadAllScriptsKey = VK_PRIOR;//Page Up
//		static bool RemoveScriptHookBool = false; const uint32_t RemoveScriptHookKey = VK_END;
//
//		if (IsKeyPressed(RemoveAllScriptsKey))
//		{
//			g_AdditionalThread.RemoveAllScripts();
//			g_ScriptThread.RemoveAllScripts();
//		}
//	}
//}

//int Hooks::ScriptVM(void* stack, signed __int64** globals, void* program, scrThreadContext* threadContext)
//{
//	for (auto thread : *g_GameVariables->script_threads)
//	{
//		if (!thread)
//		{
//			continue;
//		}
//		if (thread->m_context.m_state != eThreadState::running)
//		{
//			continue;
//		}
//		if (thread->m_context.m_script_hash == RAGE_JOAAT("freemode") || RAGE_JOAAT("main_persistent"))
//		{
//			if (g_Running && g_HookFrameCount != *g_GameVariables->m_FrameCount && is_script_thread_good(ActiveThread()) && !PLAYER::IS_PLAYER_DEAD(PLAYER::PLAYER_ID()))//
//			{
//				g_HookFrameCount = *g_GameVariables->m_FrameCount;
//				g_ScriptManager->OnGameTick();
//				if (Elite)
//				{
//					switch (g_HookState)
//					{
//					case HookStateRunning:
//					{
//						SHVScriptManager::MainFiber2();
//					} break;
//
//					case HookStateExiting:
//					{
//					} break;
//
//					default:
//						break;
//					}
//				}
//			}//
//		}
//	}
//	return static_cast<decltype(&ScriptVM)>(g_Hooking2->m_OriginalScriptVM)(stack, globals, program, threadContext);
//
//};


vmt_hook::vmt_hook(void* obj, std::size_t num_funcs) :
	m_object(static_cast<void***>(obj)),
	m_num_funcs(num_funcs),
	m_original_table(*m_object),
	m_new_table(std::make_unique<void*[]>(m_num_funcs))
{
	std::copy_n(m_original_table, m_num_funcs, m_new_table.get());
}

vmt_hook::~vmt_hook()
{
	disable();
}

void vmt_hook::hook(std::size_t index, void* func)
{
	m_new_table[index] = func;
}

void vmt_hook::unhook(std::size_t index)
{
	m_new_table[index] = m_original_table[index];
}

void vmt_hook::enable()
{
	*m_object = m_new_table.get();
}

void vmt_hook::disable()
{
	*m_object = m_original_table;
}

//Hookings::Hookings()/* :
//	m_swapchain_hook(*g_hookinh->m_swapchain, hooks::swapchain_num_funcs)*/
//
//{
//	/*m_swapchain_hook.hook(hooks::swapchain_present_index, &hooks::swapchain_present);
//	m_swapchain_hook.hook(hooks::swapchain_resizebuffers_index, &hooks::swapchain_resizebuffers);*/
//
//	for (auto& detour_hook_helper : m_detour_hook_helpers)
//	{
//		detour_hook_helper->m_detour_hook->set_target_and_create_hook(detour_hook_helper->m_on_hooking_available());
//	}
//
//	detour_hook_helper::add<hooks::send_net_info_to_lobby>("SNITL", g_GameVariables->m_NetworkInfo);
//
//	//g_hooking2 = this;
//}




//bool Hooks::SendNetworkInfo(netPlayerData* player, int64_t a2, int64_t a3, DWORD* a4)
//{
//	Hooking::RealHostToken = player->m_host_token;
//
//	/*if (g_Settings.m_SpoofName)
//		memcpy(player->m_name, "Spectral.SE", sizeof(player->m_name));*/
//
//	if (std::stoull(m_function::GetPlayerRID(PlayerID)) == player->m_rockstar_id && g_Settings.m_SpoofIP || g_Settings.m_SpoofRockstarID || g_Settings.m_SpoofName || g_Settings.m_SpoofHostToken)
//	{
//		if (g_Settings.m_SpoofName)
//			memcpy(player->m_name, g_Settings.m_Name.c_str(), sizeof(player->m_name));
//
//		if (g_Settings.m_SpoofHostToken)
//			player->m_host_token = g_Settings.m_HostToken;
//
//		if (g_Settings.m_SpoofRockstarID)
//		{
//			player->m_rockstar_id = g_Settings.m_RockstarID;
//			player->m_rockstar_id2 = g_Settings.m_RockstarID;
//		}
//
//		if (g_Settings.m_SpoofIP)
//		{
//			player->m_external_port = g_Settings.m_IPAddressPort;
//			player->m_external_ip.m_field1 = g_Settings.m_IPAddress[0];
//			player->m_external_ip.m_field2 = g_Settings.m_IPAddress[1];
//			player->m_external_ip.m_field3 = g_Settings.m_IPAddress[2];
//			player->m_external_ip.m_field4 = g_Settings.m_IPAddress[3];
//		}
//
//		if (g_Settings.m_SpoofIP || g_Settings.m_SpoofRockstarID || g_Settings.m_SpoofName)
//		{
//			g_Logger->Info(ConsoleColor::CYAN, Obfuscate("Spoofing"), Obfuscate("Sending spoofed values to the session."));
//			char buffer[99];
//			sprintf(buffer, "%d.%d.%d.%d:%u", player->m_external_ip.m_field1, player->m_external_ip.m_field2, player->m_external_ip.m_field3, player->m_external_ip.m_field4, player->m_external_port);
//			std::string ip_address(buffer);
//			g_Logger->Info(ConsoleColor::CYAN, Obfuscate("Spoofing"), "Name: %s RockstarID: %s IP Address: %s", player->m_name, std::to_string(player->m_rockstar_id).c_str(), ip_address.c_str());
//		}
//		//g_Logger->Info(ConsoleColor::CYAN, Obfuscate("Hook"), "Host Token: %s", std::to_string(player->m_host_token).c_str());
//		//g_Logger->Info(ConsoleColor::CYAN, Obfuscate("Hook"), "Peer ID: %s", std::to_string(player->m_peer_id).c_str());
//	}
//	return static_cast<decltype(&SendNetworkInfo)>(g_Hooking->m_OriginalNetworkInfo)(player, a2, a3, a4);
//}
std::string Hookings::m_Name = "";
std::string Hookings::IDSpoof = "";
std::string Hookings::IPSpoof = "";
std::string Hookings::IPSpoofarray[] = { "" };
bool Menu_Settings2::spoof_username = false;
std::string Menu_Settings2::username = "";

bool Menu_Settings2::spoof_ip = false;
int Menu_Settings2::ip_address[4] = { 42, 42, 42, 42 };

bool Menu_Settings2::spoof_rockstar_id = false;
uint64_t Menu_Settings2::rockstar_id = 123456789;

int Menu_Settings2::region_code = 0;

int Menu_Settings2::pool_type = 0;

bool Menu_Settings2::spoof_cheater = false;

bool Menu_Settings2::spoof_hide_god = false;

bool Menu_Settings2::spoof_rockstar_dev = false;
bool Menu_Settings2::spoof_rockstar_qa = false;

bool Menu_Settings2::spoof_crew_data = false;
std::string Menu_Settings2::crew_tag = "";
bool Menu_Settings2::rockstar_crew = false;
bool Menu_Settings2::square_crew_tag = false;

std::string on_off_name = "";
bool onoffnamebool = 0;
//int onoffname()
//{
//	onoffnamebool = !onoffnamebool;
//	return 0;
//}
//int check_On_Off_name()
//{
//	if (onoffnamebool)
//	{
//		on_off_name = "Name Spoof on";
//	}
//	if (!onoffnamebool)
//	{
//		on_off_name = "Name Spoof off";
//	}
//	return 0;
//}
//int m_features::onoffname()
//{
//	check_On_Off_name();
//	/*if (Menu::Option((char*)on_off_name.c_str())) {*/
//	Menu_Settings2::spoof_username = !Menu_Settings2::spoof_username;
//	/*}*/
//	return 0;
//}
// 


std::vector<std::string> split5(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

std::string GetPlayerRID(int player)
{
	int networkhandle[13];
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, networkhandle, 13);
	char* rockstar_id = NETWORK::NETWORK_MEMBER_ID_FROM_GAMER_HANDLE(&networkhandle[0]);
	return rockstar_id;
}
bool userspoof = 0;
//bool hooks::send_net_info_to_lobby(rage2::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4)
bool Hooks::send_net_info_to_lobby(rage::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4)
{
	/*if (ENTITY::DOES_ENTITY_EXIST(Hooking::get_player_ped(Features::playerme)))
	{
	}
	else
	{*/
	if (PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::playerme) == PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0) == Features::playerme) {
		userspoof = 1;
	}
	else
	{
		userspoof = 0;
	}
	//const bool is_local_player = g_local_player->m_player_info->m_net_player_data.m_gamer_handle_2.m_rockstar_id == player->m_gamer_handle_2.m_rockstar_id;

	//// check so we're 100% sure we modify data only for ourselves
	//if (is_local_player)
	//{
	if (userspoof)
	{
		if (Hookings::m_Name == "")
		{
			Hookings::m_Name = "Thunder-Menu";
		}
		if (Menu_Settings2::spoof_username)
			memcpy(player->m_name, Hookings::m_Name.c_str(), sizeof(player->m_name));
	}
	//memcpy(player->m_name, g_local_player->m_player_info->m_net_player_data.m_name, sizeof(player->m_name));
	//memcpy(player->m_name, "Thunder-Menu", sizeof(player->m_name));/*ggg->spoofing.username.c_str()*/

/*if (ggg->spoofing.spoof_rockstar_id)
{
	player->m_rockstar_id = ggg->spoofing.rockstar_id;
	player->m_rockstar_id = ggg->spoofing.rockstar_id;
}*/
//if (Menu_Settings2::spoof_rockstar_id)
//{
//	if (Hookings::IDSpoof != "")
//	{
//		Menu_Settings2::rockstar_id = atoi(Hookings::IDSpoof.c_str());
//	}
//	if (std::stoull(GetPlayerRID(PLAYER::PLAYER_ID())) == player->m_rockstar_id)
//	{
//		player->m_rockstar_id = Menu_Settings2::rockstar_id;
//		player->m_rockstar_id2 = Menu_Settings2::rockstar_id;
//	}
//	/*if (std::stoull(GetPlayerRID(PLAYER::PLAYER_ID())) == player->m_peer_id)
//	{
//		player->m_peer_id = Menu_Settings2::rockstar_id;
//		player->m_gamer_handle_2 = Menu_Settings2::rockstar_id;
//	}*/
//	
//}
	if (Menu_Settings2::spoof_ip)
	{
		if (Hookings::IPSpoof != "")
		{
			/*const char point = '.';
			const char virgulespace = ', ';
			std::replace(Hookings::IPSpoof.begin(), Hookings::IPSpoof.end(), point, virgulespace);
			Hookings::IPSpoofarray[0] = Hookings::IPSpoof;

			Menu_Settings2::ip_address[0] = atoi(Hookings::IPSpoofarray[0].c_str());
			Menu_Settings2::ip_address[1] = atoi(Hookings::IPSpoofarray[1].c_str());
			Menu_Settings2::ip_address[2] = atoi(Hookings::IPSpoofarray[2].c_str());
			Menu_Settings2::ip_address[3] = atoi(Hookings::IPSpoofarray[3].c_str());*/
			std::string point = ".";
			std::string space = " ";
			size_t pos = Hookings::IPSpoof.find(point);
			while (pos != std::string::npos)
			{
				Hookings::IPSpoof.replace(pos, point.size(), space);
				pos = Hookings::IPSpoof.find(point, pos + space.size());
			}
			std::vector<std::string> words = split5(Hookings::IPSpoof, ' ');
			Menu_Settings2::ip_address[0] = atoi(words[0].c_str());
			Menu_Settings2::ip_address[1] = atoi(words[1].c_str());
			Menu_Settings2::ip_address[2] = atoi(words[2].c_str());
			Menu_Settings2::ip_address[3] = atoi(words[3].c_str());
		}
		player->m_external_ip.m_field1 = Menu_Settings2::ip_address[0];
		player->m_external_ip.m_field2 = Menu_Settings2::ip_address[1];
		player->m_external_ip.m_field3 = Menu_Settings2::ip_address[2];
		player->m_external_ip.m_field4 = Menu_Settings2::ip_address[3];

		player->m_internal_ip.m_field1 = Menu_Settings2::ip_address[0];
		player->m_internal_ip.m_field2 = Menu_Settings2::ip_address[1];
		player->m_internal_ip.m_field3 = Menu_Settings2::ip_address[2];
		player->m_internal_ip.m_field4 = Menu_Settings2::ip_address[3];

	}
	if (userspoof)
	{
		if (Hookings::m_Name == "")
		{
			Hookings::m_Name = "Thunder-Menu";
		}
		if (Menu_Settings2::spoof_username)
			memcpy(player->m_name, Hookings::m_Name.c_str(), sizeof(player->m_name));
	}
	//if (ggg->notifications.send_net_info_to_lobby.log)
	//{ }
	//	//LOG(INFO) << "Sending spoofed values to session host";
	//if (ggg->notifications.send_net_info_to_lobby.notify)
	//{
	//}
	//	//g_notification_service->push("Player Info Spoofing", "Sent spoofed values to lobby host.");
/*}*/

//const auto result = g_hooking2->/*get_original*/m_OriginalNetworkInfo<hooks::send_net_info_to_lobby>()(player, a2, a3, a4);

// restore player name to prevent detection of spoofed name
/*if (is_local_player && ggg->spoofing.spoof_username)
	memcpy(player->m_name, g_local_player->m_player_info->m_net_player_data.m_name, sizeof(player->m_name));*/
	return static_cast<decltype(&send_net_info_to_lobby)>(OriginalPTR::m_OriginalNetworkInfo)(player, a2, a3, a4);
	/*return result;*/
}


detour_hook::detour_hook()
{
}

detour_hook::detour_hook(const std::string& name, void* detour)
{
	set_instance(name, detour);
}

detour_hook::detour_hook(const std::string& name, void* target, void* detour)
{
	set_instance(name, target, detour);
}

void detour_hook::set_instance(const std::string& name, void* detour)
{
	m_name = name;
	m_detour = detour;
}

void detour_hook::set_instance(const std::string& name, void* target, void* detour)
{
	m_name = name;
	m_target = target;
	m_detour = detour;

	create_hook();
}

//detour_hook::set_instance(const std::string& name, void* detour)
//{
//	m_name = name;
//	m_detour = detour;
//}
//
//detour_hook::detour_hook(std::string name, void* detour) :
//	m_name(std::move(name)),
//	m_detour(detour)
//{
//
//}
//
//detour_hook::detour_hook(std::string name, void* target, void* detour) :
//	m_name(std::move(name)),
//	m_target(target),
//	m_detour(detour)
//{
//	create_hook();
//}

void detour_hook::set_target_and_create_hook(void* target)
{
	m_target = target;
	create_hook();
}

void detour_hook::create_hook()
{
	fix_hook_address();
	if (auto status = MH_CreateHook(m_target, m_detour, &m_original); status != MH_OK)
		/*{ }*/
		throw std::runtime_error(("Failed to create hook '{}' at 0x{:X} (error: {})", m_name, uintptr_t(m_target), MH_StatusToString(status)));//std::format
}

detour_hook::~detour_hook() noexcept
{
	if (auto status = MH_RemoveHook(m_target); status != MH_OK)
	{
	}
	//LOG(FATAL) << "Failed to remove hook '" << m_name << "' at 0x" << HEX_TO_UPPER(uintptr_t(m_target)) << "(error: " << m_name << ")";
}

void detour_hook::enable()
{
	if (auto status = MH_QueueEnableHook(m_target); status != MH_OK)
		/*{ }*/
		throw std::runtime_error(format2("Failed to enable hook 0x{:X} ({})", uintptr_t(m_target), MH_StatusToString(status)));//std::format
}

void detour_hook::disable()
{
	if (auto status = MH_QueueDisableHook(m_target); status != MH_OK)
	{
	}
	//LOG(WARNING) << "Failed to disable hook '" << m_name << "'.";
}

DWORD exp_handler(PEXCEPTION_POINTERS exp, std::string const& name)
{
	return exp->ExceptionRecord->ExceptionCode == STATUS_ACCESS_VIOLATION
		? EXCEPTION_EXECUTE_HANDLER
		: EXCEPTION_CONTINUE_SEARCH;
}


void detour_hook::fix_hook_address()
{
	__try {
		auto ptr = memory2::handle(m_target);
		while (ptr.as<std::uint8_t&>() == 0xE9)
			ptr = ptr.add(1).rip();
		m_target = ptr.as<void*>();
	}
	__except (exp_handler(GetExceptionInformation(), m_name)) {
		[this]() {
			throw std::runtime_error(format2("Failed to fix hook address for '{}'", m_name));//std::format
			}();
	}
}

vmt_hook::detour_hook_helper::~detour_hook_helper()
{
	delete m_detour_hook;
}

void vmt_hook::detour_hook_helper::enable_hook_if_hooking_is_already_running()
{
	if (g_hooking2 && g_hooking2->m_enabled)
	{
		if (m_on_hooking_available)
		{
			m_detour_hook->set_target_and_create_hook(m_on_hooking_available());
		}

		m_detour_hook->enable();
		MH_ApplyQueued();
	}
}

byte_patch::~byte_patch()
{
	restore();
}

void byte_patch::apply() const
{
	memcpy(m_address, m_value.get(), m_size);
}

void byte_patch::restore() const
{
	memcpy(m_address, m_original_bytes.get(), m_size);
}

void byte_patch::remove() const
{
	if (const auto it = std::find(m_patches.begin(), m_patches.end(), this); it != m_patches.end())
	{
		m_patches.erase(it);
	}
}

void byte_patch::restore_all()
{
	m_patches.clear();
}

bool operator==(const std::unique_ptr<byte_patch>& a, const byte_patch* b)
{
	return a->m_address == b->m_address;
}

module::module(const std::string_view name) :
	range(nullptr, 0),
	m_name(name),
	m_loaded(false)
{
	try_get_module();
}

handle module::get_export(std::string_view symbol_name)
{
	if (!m_loaded)
		return nullptr;

	const auto dosHeader = m_base.as<IMAGE_DOS_HEADER*>();
	const auto ntHeader = m_base.add(dosHeader->e_lfanew).as<IMAGE_NT_HEADERS*>();
	const auto imageDataDirectory = ntHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
	const auto exportDirectory = m_base.add(imageDataDirectory.VirtualAddress).as<IMAGE_EXPORT_DIRECTORY*>();

	const auto nameOffsetArray = m_base.add(exportDirectory->AddressOfNames).as<DWORD*>();
	const auto ordinalArray = m_base.add(exportDirectory->AddressOfNameOrdinals).as<DWORD*>();
	const auto functionOffsetArray = m_base.add(exportDirectory->AddressOfFunctions).as<DWORD*>();

	for (std::size_t i = 0; i < exportDirectory->NumberOfFunctions; i++)
	{
		const auto functionName = m_base.add(nameOffsetArray[i]).as<const char*>();
		if (strcmp(functionName, symbol_name.data()))
			continue;

		return functionOffsetArray + ordinalArray[i];
	}
	return nullptr;
}

bool module::loaded() const
{
	return m_loaded;
}

bool module::wait_for_module(std::optional<std::chrono::high_resolution_clock::duration> time)
{
	const auto giveup_time = time.has_value()
		? std::make_optional(std::chrono::high_resolution_clock::now() + time.value())
		: std::nullopt;
	/*LOG(G3LOG_DEBUG) << "Waiting for " << m_name << "...";*/
	while (!try_get_module())
	{
		if (giveup_time.has_value() && giveup_time <= std::chrono::high_resolution_clock::now())
			break;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	return m_loaded;
}

bool module::try_get_module()
{
	if (m_loaded)
		return m_loaded;

	const auto mod = GetModuleHandleA(m_name.data());
	if (!mod)
		return false;
	m_loaded = true;

	m_base = mod;
	const auto dosHeader = m_base.as<IMAGE_DOS_HEADER*>();
	const auto ntHeader = m_base.add(dosHeader->e_lfanew).as<IMAGE_NT_HEADERS*>();

	m_size = ntHeader->OptionalHeader.SizeOfImage;

	return m_loaded;
}

inline CNetworkPlayerMgr* GetNetworkPlayerMgr()
//inline CNetworkPlayerMgr* GetNetworkPlayerMgr()
{
	return *g_GameVariables->m_NetworkPlayerMgr;
}
auto socialclub_region = Module("socialclub.dll");

//std::uint64_t g_HookFrameCount{};
//std::uint32_t* m_FrameCount;



CNetworkPlayerManager* GameVariables1::GetNetworkPlayerManager() { return *(CNetworkPlayerManager**)GetNetworkPlayerManagerPtr(); }


template<typename T>
inline uint64_t GetAddressFromInstruction(T address, int offset = 0, int opSize = 3, int opLength = 7) {
	T _address = (address + offset);
	return (uint64_t)(*reinterpret_cast<int*>(_address + opSize) + _address + opLength);
}
GameVariables2::GameVariables2() :
	m_FogModification(Signature("? ? ? ? 6F 12 83 3A 0A D7 23 3C 35 FA 8E 3C 08 21 04 3D 89 88 08 3D", "m_FogModification").Scan().As<float*>()),
	/*m_RainMultiplier(Signature("? ? ? ? 0A D7 23 BC 0A D7 23 BC 06 00 00 00 00 00 00 00 00 00 00 00").Scan().As<float*>()),*/
	/*PVOID_RainMain(Signature("CD CC CC 3E CD CC CC 3E CD CC CC 3E CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D").Scan().As<uintptr_t>()),*///		9A 99 19 3F CD CC CC 3E CD CC CC 3E CD CC
	/*m_RainRed(Signature("? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A").Scan().As<float*>()),
	m_RainGreen(Signature("? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A").Scan().As<float*>()),
	m_RainBlue(Signature("? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A").Scan().As<float*>()),*/
	//m_RainRed(Signature("? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? ? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D
	//m_RainGreen(Signature("? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? ? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D
	//m_RainBlue(Signature("? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42 ? ? ? ? ? ? A0 C0 ? ? 80 3F ? ? C8 42 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F ? ? 80 3F ? ? 80 3F F7 7F ? ? ? ? 20 41 ? ? 48 42 ? ? ? 3F F7 7F ? ? 66 66 66 3F ? ? ? ? ? ? ? ? CD CC CC 3D ? ? 80 3F ? ? 60 40 ? ? FA 43 02 ? ? ? ? ? 80 3F CD CC 4C 3F ? ? ? ? ? ? ? ? 19 81 69 F4 01 ? ? ? 9A 99 99 3E ? ? 40").Scan().As<float*>()),//? ? ? ? CD CC 4C 3E CD CC 4C 3D CD CC 4C 3D CD CC CC 3D ? ? C8 42
	//m_RainGravity(Signature("? ? ? ? 80 AA E5 48 F7 7F ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 50 41 ? ? C0 40 ? 7F ? ? ? ? 34 42").Scan().As<float*>()),//? ? ? C1 80 AA ? ? ? 7F
	m_zenith_patch(Signature("0F 29 A2 B0 00 00 00 8B 81 58 03 00 00", "m_zenith_patch").Scan().As<decltype(m_zenith_patch)>()),//GTA5.exe+E3FF77
	m_zenith_transition_patch(Signature("0F 29 A2 E0 00 00 00", "m_zenith_transition_patch").Scan().As<decltype(m_zenith_transition_patch)>()),//GTA5.exe+E3FFB1
	m_east_azimuth_patch(Signature("0F 29 62 20", "m_east_azimuth_patch").Scan().As<decltype(m_east_azimuth_patch)>()),//GTA5.exe+E3FEC9
	m_west_azimuth_patch(Signature("0F 29 62 50 8B 81 9C 03 00 00", "m_west_azimuth_patch").Scan().As<decltype(m_west_azimuth_patch)>()),//GTA5.exe+E3FEFD
	m_azimuth_transition_patch(Signature("0F 29 A2 80 00 00 00", "m_azimuth_transition_patch").Scan().As<decltype(m_azimuth_transition_patch)>()),//GTA5.exe+E3FF31
	m_cloud_base_patch(Signature("0F 29 A2 80 03 00 00", "m_cloud_base_patch").Scan().As<decltype(m_cloud_base_patch)>()),//GTA5.exe+E402F1
	red_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25", "red_zenith").Scan().As<float*>()),//GTA5.exe+26BB960
	green_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25", "green_zenith").Scan().As<float*>()),//GTA5.exe+26BB964
	blue_zenith(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25", "blue_zenith").Scan().As<float*>()),//GTA5.exe+26BB968
	red_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25", "red_transition").Scan().As<float*>()),//GTA5.exe+26BB990 //GTA5.exe+26CEB80 - 00 60 60              - add [rax+60],ah
	green_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25", "green_transition").Scan().As<float*>()),//GTA5.exe+26BB994
	blue_transition(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 27 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 26 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 44 ? ? 80 42 ? ? ? 43 ? ? ? ? 25", "blue_transition").Scan().As<float*>()),//GTA5.exe+26BB998
	red_cloud(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 15", "red_cloud").Scan().As<float*>()),//GTA5.exe+0x26EB4E0 //26BBC30
	green_cloud(Signature("? ? ? ? ? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 15", "green_cloud").Scan().As<float*>()),//GTA5.exe+0x26EB4E4 //26BBC34
	blue_cloud(Signature("? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 15", "blue_cloud").Scan().As<float*>()),//GTA5.exe+0x26EB4E0 //26BBC38
	//red_cloud(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 15").Scan().As<float*>()),//GTA5.exe+0x26EB4E0 //26BBC30
	//green_cloud(Signature("? ? ? ? ? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 15").Scan().As<float*>()),//GTA5.exe+0x26EB4E4 //26BBC34
	//blue_cloud(Signature("? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 15").Scan().As<float*>()),//GTA5.exe+0x26EB4E0 //26BBC38
	//red_cloud(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? B8 ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? 3F ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3C 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ?").Scan().As<float*>()),//GTA5.exe+26BBC30
	//green_cloud(Signature("? ? ? ? ? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? B8 ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? 3F ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3C 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ?").Scan().As<float*>()),//GTA5.exe+26BBC34
	//blue_cloud(Signature("? ? ? ? ? ? ? ? 1B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? B8 ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? 3F ? ? ? ? 17 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 40 ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3C 16 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ?").Scan().As<float*>()),//GTA5.exe+26BBC38
	m_azimuth_west_red(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28", "m_azimuth_west_red").Scan().As<float*>()),//GTA5.exe+0x26EB1B0 //tu scan 48 83 EC 68  0F 29 74 24 50 0F 28 35 tu appuis dessus xmmword_7FF6EFFDB300 et tu compte 6 db h au dessus
	m_azimuth_west_green(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28", "m_azimuth_west_green").Scan().As<float*>()),//GTA5.exe+26BB904
	m_azimuth_west_blue(Signature("? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28", "m_azimuth_west_blue").Scan().As<float*>()),//GTA5.exe+26BB908
	//m_azimuth_west_red(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+0x26EB1B0 //tu scan 48 83 EC 68  0F 29 74 24 50 0F 28 35 tu appuis dessus xmmword_7FF6EFFDB300 et tu compte 6 db h au dessus
	//m_azimuth_west_green(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB904
	//m_azimuth_west_blue(Signature("? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB908
	//m_azimuth_west_red(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3E ? ? ? ? ? ? 80 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E0 B0 3C ? ? ? 3D ? ? ? 3D ? E0 B0 3C ? ? 80 3F ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB900
	//m_azimuth_west_green(Signature("? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3E ? ? ? ? ? ? 80 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E0 B0 3C ? ? ? 3D ? ? ? 3D ? E0 B0 3C ? ? 80 3F ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB904
	//m_azimuth_west_blue(Signature("? ? ? ? ? ? ? 3D ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3E ? ? ? ? ? ? 80 3F 2A ? ? ? ? ? ? 3F ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E0 B0 3C ? ? ? 3D ? ? ? 3D ? E0 B0 3C ? ? 80 3F ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB908
	//m_azimuth_est_red(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+0x26EB180
	//m_azimuth_est_green(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+0x26EB184
	//m_azimuth_est_blue(Signature("? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+0x26EB188
	m_azimuth_est_red(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28", "m_azimuth_est_red").Scan().As<float*>()),//GTA5.exe+0x26EB180
	m_azimuth_est_green(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28", "m_azimuth_est_green").Scan().As<float*>()),//GTA5.exe+0x26EB184
	m_azimuth_est_blue(Signature("? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 28", "m_azimuth_est_blue").Scan().As<float*>())//GTA5.exe+0x26EB188
	//m_azimuth_est_red(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? 80 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E0 B0 3C ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB8D0
	//m_azimuth_est_green(Signature("? ? ? ? ? ? ? ? ? ? ? 3D ? ? 80 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E0 B0 3C ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB8D4
	//m_azimuth_est_blue(Signature("? ? ? ? ? ? ? 3D ? ? 80 3F ? ? ? ? ? ? ? ? ? ? ? ? 2C ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 3D ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 2B ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? 29 ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? E0 B0 3C ? ? ? 3F ? ? ? ? ? ? ? ? ? ? ? ? 28").Scan().As<float*>()),//GTA5.exe+26BB8D8
{

}


GameVariables1::GameVariables1() :

	//m_FrameCount(Signature("8B 15 ? ? ? ? 41 FF CF").Scan().Add(2).Rip().As<decltype(m_FrameCount)>()),
	//if (g_HookFrameCount != *g_GameVariables->m_FrameCount)
	//{
	//	g_HookFrameCount = *g_GameVariables->m_FrameCount;
	//	g_ScriptManager->OnGameTick();
	//}
	//m_GameState(Signature("83 3D ? ? ? ? ? 75 17 8B 43 20 25").Scan().Add(2).Rip().Add(1).As<decltype(m_GameState)>()),
		//m_GameState(Signature("48 85 C9 74 4B 83 3D").Scan().Add(7).Rip().As<decltype(m_GameState)>()),
		/*m_FrameCount(Signature("8B 15 ? ? ? ? 41 FF CF").Scan().Add(2).Rip().As<decltype(m_FrameCount)>()),*///new
		/*m_FrameCount(Signature("F3 0F 10 0D ? ? ? ? 44 89 6B 08").Scan().Add(4).Rip().Sub(8).As<decltype(m_GameState)>()),*///olds
	//m_GameWindow(FindWindowA("grcWindow", "Grand Theft Auto V")),
	//m_FrameCount(Signature("8B 15 ? ? ? ? 41 FF CF").Scan().Add(2).Rip().As<decltype(m_FrameCount)>()),
	/*m_FrameCount(Signature(xorstr_("8B 15 ? ? ? ? 41 FF CF"), xorstr_("FrameCount")).Scan().Add(2).Rip().As<decltype(m_FrameCount)>()),
	m_Swapchain(Signature(xorstr_("48 8B 0D ? ? ? ? 48 8B 01 44 8D 43 01 33 D2 FF 50 40 8B C8"), xorstr_("Swapchain")).Scan().Add(3).Rip().As<decltype(m_Swapchain)&>()),*/
	//m_GetNativeHandler(Signature("48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A").Scan().Add(12).Rip().As<decltype(m_GetNativeHandler)>()),
	//m_NativeRegistrations(Signature("48 83 EC 20 48 8D 0D ? ? ? ? E8 ? ? ? ? 0F B7 15 ? ? ? ? 33 FF").Scan().Add(7).Rip().As<decltype(m_NativeRegistrations)>()),
	m_serialize_join_request_message(Signature("E8 ? ? ? ? 84 C0 0F 84 9B 00 00 00 49 8D 8F 50 11 00 00", "m_serialize_join_request_message").Scan().Add(1).Rip().As<decltype(m_serialize_join_request_message)>()),
	m_get_host_array_handler_by_index(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 8A 81 97", "m_get_host_array_handler_by_index").Scan().As<decltype(m_get_host_array_handler_by_index)>()),
	m_GlobalBase(Signature("4C 8D 4D 08 48 8D 15 ? ? ? ? 4C 8B C0", "m_GlobalBase").Scan().Add(7).Rip().As<decltype(m_GlobalBase)>()),
	m_ped_factory(Signature("48 8B 05 ? ? ? ? 48 8B 48 08 48 85 C9 74 52 8B 81", "m_ped_factory").Scan().Add(3).Rip().As<CPedFactory**>()),// decltype(m_ped_factory)
	/*m_SetVectorResult(Signature("83 79 18 00 48 8B D1 74 4A FF 4A 18", "SetVectorResult").Scan().As<decltype(m_SetVectorResult)>()),*/
	m_GetNetPlayer(Signature("48 83 EC 28 33 C0 38 05 ? ? ? ? 74 0A", "m_GetNetPlayer").Scan().As<decltype(m_GetNetPlayer)>()),
	/*m_NetworkPlayerMgr(Signature("48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF").Scan().Add(3).Rip().As<decltype(m_NetworkPlayerMgr)>()),*/
	m_NetworkPlayerMgr(Signature("48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF", "m_NetworkPlayerMgr").Scan().Add(3).Rip().As<decltype(m_NetworkPlayerMgr)>()),//CNetworkPlayerMgr**
	/*m_GetPlayerHandle(Signature("83 F9 FF 74 31 4C 8B 0D ? ? ? ?").Scan().As<decltype(m_GetPlayerHandle)>()),*/
	/*m_blame_explode(Signature("0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8").Scan().As<decltype(m_blame_explode)>()),*/
	/*m_Swapchain(Signature("48 8B 0D ? ? ? ? 48 8D 55 A0 48 8B 01").Scan().Add(3).Rip().As<decltype(m_Swapchain)&>()),*/
	/*script_threads(Signature("48 8B 01 FF 50 20 0F B7 15 ? ? ? ? FF C3 0F B7 C2 3B D8 7C C9 48 8B 5C 24").Scan().Sub(30).Rip().As<decltype(script_threads)>()),*/
	/*m_is_session_started(Signature("40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE").Scan().Add(3).Rip().As<decltype(m_is_session_started)>())*/
	//m_NetworkInfo(Signature("03 D4 E8 ? ? ? ? 84 C0 74 69").Scan().Sub(0x81).As<decltype(m_NetworkInfo)>()),
	m_NetworkInfo(Signature("48 8B EC 48 83 EC 50 49 8B F9 45 8B F8 4C 8B E2", "m_NetworkInfo").Scan().Sub(24).As<decltype(m_NetworkInfo)>()),
	//m_NetworkInfo(Signature("44 8B 6C 24 ? 45 8B C6 48 8D 4E 70 41 8B D5 45 2B C5 4C 8D 4C 24 ? 03 D5 44 2B C5 49 03 D4 E8 ? ? ? ? 84 C0 74 69").Scan().Sub(0x64).As<decltype(m_NetworkInfo)>()),
	//m_is_session_started(Signature("40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE").Scan().Add(3).Rip().As<bool*>()), //44 38 1D ? ? ? ? 0F 84 ? ? ? ? 48 8B 01 FF 90 ? ? ? ? 48 8B 85
	m_give_pickup_rewards(Signature("48 8B C8 33 C0 48 85 C9 74 0A 44 8B C3 8B D7 E8", "m_give_pickup_rewards").Scan().Sub(0x28).As<decltype(m_give_pickup_rewards)>()),
	m_WaypointCoords(Signature("74 1F F3 0F 10 05 ? ? ? ? F3 0F 11 03", "m_WaypointCoords").Scan().Add(6).Rip().As<decltype(m_WaypointCoords)>()),
	ui_3d_draw_manager(Signature("4C 8B 15 ? ? ? ? F3 0F 11 45 ? F3 0F 10 05 ? ? ? ? BF ? ? ? ? BB ? ? ? ? 41 BE ? ? ? ? F3 0F 11", "ui_3d_draw_manager").Scan().As<decltype(ui_3d_draw_manager)>()),
	push_scene_preset_manager(Signature("40 53 48 83 EC 20 8B 02 48 8D 54 24 38 48 8B D9 89 44 24 38 E8 ? ? ? ? 48 8B C8", "push_scene_preset_manager").Scan().As<decltype(push_scene_preset_manager)>()),
	add_element_to_scene(Signature("4C 8B DC 48 83 EC 58 8B", "add_element_to_scene").Scan().As<decltype(add_element_to_scene)>()),
	set_scene_element_lighting(Signature("48 8B C4 48 89 58 10 48 89 70 18 57 48 83 EC 30 48 83 B9", "get_scene_preset").Scan().As<decltype(set_scene_element_lighting)>()),
	get_scene_preset(Signature("0F B7 81 10 08 00 00", "get_scene_preset").Scan().As<decltype(get_scene_preset)>()),
	m_weather_data(Signature("40 53 48 83 EC 30 0F 29 74 24 ? 48 8B D9 E8 ? ? ? ? F3 0F 10 83 ? ? ? ? F3 0F 10 35", "m_weather_data").Scan().As<PVOID>()),
	//activatetraffic1(Signature("? ? ? ? 01 01 01 01 78 32 ? ? ? ? ? ? 7C 85 C9 B3 ? ? ?").Scan().As<float*>()),//1E33270
	//leftstreet(Signature("? ? ? ? 09 D7 23 3C CC CC 4C 3E 0F ? ? ? ? ? ? ? 01 01 01 01 78 32 ? ? ? 7F ? ? 7C 85 C9 B3 ? ? ?").Scan().As<float*>()),//1E33260
	rightstreet(Signature("? ? ? ? 01 01 01 01 01 01 01 01 42 60 E5 3B 8F C2 F5 3C 01 ? ? ? FF FF ? ? 02 ? ? ? ? ? ? ? 09 D7 23 3C CC CC 4C 3E", "rightstreet").Scan().As<float*>()),//1E33240
	activatetraffic2(Signature("? ? ? ? 0A D7 23 3C CD CC CC 3D CD CC CC 3D ? ? ? ? 01 01 01 01 01 01 01 01 42 60 E5 3B 8F C2 F5 3C 01 ? ? ? FF", "activatetraffic2").Scan().As<float*>()),//1E33230
	pedspeed(Signature("? ? ? ? ? ? ? ? CD CC 1C C1 ? ? ? ? 6F 12 83 3A 6F 12 83 3A 6F 12 83 3A ? ? ? ? CD CC CC 3D ? ? ? ?", "pedspeed").Scan().As<float*>()),//1E33310		
	//potatoe0(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? E0 3F 39 8E E3 3F ? ? 80 40 ? ? A0 40 ? ? 20 41 ? ? 98 41 ? ?").Scan().As<float*>()),//19B1DB0
	//potatoe1(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? E0 3F 39 8E E3 3F ? ? 80 40 ? ? A0 40 ? ? 20 41 ? ? 98 41 ? ?").Scan().As<float*>()),//19B1DB1
	//potatoe2(Signature("? ? ? ? ? ? ? ? ? ? ? ? E0 3F 39 8E E3 3F ? ? 80 40 ? ? A0 40 ? ? 20 41 ? ? 98 41 ? ?").Scan().As<float*>()),//19B1DB2
	//potatoe3(Signature("? ? ? ? ? ? ? ? ? ? ? E0 3F 39 8E E3 3F ? ? 80 40 ? ? A0 40 ? ? 20 41 ? ? 98 41 ? ?").Scan().As<float*>()),//19B1DB3
	//freezetraffic(Signature("? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? FF FF FF FF ? ? ? ? ? ? ? ? ? ? ? ? FF FF FF FF FF FF FF FF 1C 45 ? ? ? 7F ? ? C8 8A ? ? ? ? ? ? B8").Scan().As<float*>()),//19B7188 	
	shitter_crash(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 20 48 8D 81 D4 ? ? ?", "shitter_crash").Scan().As<PVOID>()),//15E5690	
	m_networkPlayerManager(Signature("48 8B 0D ? ? ? ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 0D ? ? ? ? E8", "m_networkPlayerManager").Scan().Add(3).Rip().As<decltype(m_networkPlayerManager)>()),
	//AddEntityToPool(Signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 8B 15 ? ? ? ? 48 8B F9 48 83 C1 10 33 DB").Scan().Rip().As<decltype(AddEntityToPool)>()),
	GetEntityAddress(Signature("83 F9 FF 74 31 4C 8B 0D ? ? ? ? 44 8B C1 49 8B 41 08", "GetEntityAddress").Scan().Rip().As<decltype(GetEntityAddress)>()),
	vm_address(Signature("48 8B 05 ? ? ? ? F3 0F 59 F6 48 8B 08", "vm_address").Scan().Add(3).As<uintptr_t*>()),
	em_address(Signature("4C 8B 0D ? ? ? ? 44 8B C1 49 8B 41 08", "em_address").Scan().Add(3).As<uintptr_t*>()),
	m_Network(Signature("48 8B 0D ? ? ? ? 48 8B D7 E8 ? ? ? ? 84 C0 75 17 48 8B 0D ? ? ? ? 48 8B D7", "m_Network").Scan().Add(3).Rip().As<Network**>()),
	m_friend_registry(Signature("3B 0D ? ? ? ? 73 17", "m_friend_registry").Scan().Add(2).Rip().As<FriendRegistry*>()),
	//m_network_player_mgr(Signature("48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF").Scan().Add(3).Rip().As<CNetworkPlayerMgr**>()),
	/*m_script_threads(Signature("45 33 F6 8B E9 85 C9 B8").Scan().Sub(4).Rip().Sub(8).As<decltype(m_script_threads)>()),
	m_run_script_threads(Signature("45 33 F6 8B E9 85 C9 B8").Scan().Sub(0x1F).As<run_script_threads*>()),*/
	/*m_script_program_table(Signature("48 8B 1D ? ? ? ? 41 83 F8 FF").Scan().Add(3).Rip().As<decltype(m_script_program_table)>()),*/
	m_ScriptProgramTable(Signature("48 8B 1D ? ? ? ? 41 83 F8 FF", "m_ScriptProgramTable").Scan().Add(3).Rip().As<decltype(m_ScriptProgramTable)>()),
	m_IsSessionStarted(Signature("44 38 1D ? ? ? ? 0F 84 ? ? ? ? 48 8B 01 FF 90 ? ? ? ? 48 8B 85", "m_IsSessionStarted").Scan().Add(3).Rip().As<bool*>()),
	//m_IsSessionStarted(Signature("40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE").Scan().Add(3).Rip().As<bool*>()), //before
	/*m_StartGetPresenceAttributes(Signature("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 54 41 56 41 57 48 83 EC 40 33 DB 41").Scan(socialclub_region).As<StartGetPresenceAttributes*>()),*/
	m_StartGetPresenceAttributes(Signature("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 54 41 56 41 57 48 83 EC 40 33 DB 41", "m_StartGetPresenceAttributes").Scan(socialclub_region).As<decltype(m_StartGetPresenceAttributes)>()),
	/*m_StartGetSessionByGamerHandle(Signature("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24").Scan().Add(1).Rip().As<StartGetSessionByGamerHandle*>()),*/
	m_StartGetSessionByGamerHandle(Signature("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24", "m_StartGetSessionByGamerHandle").Scan().Add(1).Rip().As<decltype(m_StartGetSessionByGamerHandle)>()),
	//m_DecodePeerInfo(Signature("48 8B C4 48 89 58 08 48 89 70 10 57 48 81 EC A0 00 00 00 48 8B DA").Scan().As<decltype(m_DecodePeerInfo)>()),
	/*m_DecodePeerInfo(Signature("48 89 5C 24 08 48 89 74 24 10 57 48 81 EC C0 00 00 00 48 8B F1 49").Scan().As<DecodePeerInfo*>()),*/
	m_DecodePeerInfo(Signature("48 89 5C 24 08 48 89 74 24 10 57 48 81 EC C0 00 00 00 48 8B F1 49", "m_DecodePeerInfo").Scan().As<DecodePeerInfo*>()),
	m_ConnectToPeer(Signature("48 89 5C 24 08 4C 89 4C 24 20 48 89 54 24 10 55 56 57 41 54 41 55 41 56 41 57 48 83 EC 60 4D", "m_ConnectToPeer").Scan().As<decltype(m_ConnectToPeer)>()),
	//m_ConnectToPeer(Signature("48 89 5C 24 08 4C 89 44 24 18 55 56 57 41 54 41 55 41 56 41 57 48 81 EC 80").Scan().As<decltype(m_ConnectToPeer)>()),
	/*m_ConnectToPeer(Signature("48 89 5C 24 08 4C 89 4C 24 20 48 89 54 24 10 55 56 57 41 54 41 55 41 56 41 57 48 83 EC 60 4D").Scan().As<ConnectToPeer*>()),*/
	/*m_sc_info(Signature("48 8B D3 48 8D 4C 24 ? 48 69 D2").Scan().Sub(4).As<decltype(m_sc_info)>()),*/
	m_sc_info(Signature("48 8B D3 48 8D 4C 24 ? 48 69 D2", "m_sc_info").Scan().Sub(4).As<ScInfo*>()),
	m_script_globals(Signature("48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D", "m_script_globals").Scan().Add(3).Rip().As<decltype(m_script_globals)>()),
	m_ReplayInterface(Signature("0F B7 44 24 ? 66 89 44 4E", "m_ReplayInterface").Scan().Add(0x1F).Rip().As<rage::CReplayInterface**>()),
	m_PtrToHandle(Signature("48 8B F9 48 83 C1 10 33 DB", "m_PtrToHandle").Scan().Sub(0x15).As<decltype(m_PtrToHandle)>()),
	m_HandleToPtr(Signature("83 F9 FF 74 31 4C 8B 0D", "m_HandleToPtr").Scan().As<decltype(m_HandleToPtr)>()),
	//m_RequestControl(Signature("E8 ? ? ? ? EB 3E 48 8B D3").Scan().Add(1).Rip().As<decltype(m_RequestControl)>()),
	m_RequestControl(Signature("E8 ? ? ? ? EB 50 48 8B D3", "m_RequestControl").Scan().Add(1).Rip().As<decltype(m_RequestControl)>()),
	m_MigrateObject(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 20 41 8B F8 48", "m_MigrateObject").Scan().As<decltype(m_MigrateObject)>()),//MigrateObject*
	m_WriteVehicleProximityMigrationDataNode(Signature("48 89 4C 24 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 68 4C 8B A9", "m_WriteVehicleProximityMigrationDataNode").Scan().As<PVOID>()),
	m_ClearPedTaskNetwork(Signature("E8 ? ? ? ? EB 28 48 8B 8F A0 10 00 00", "m_ClearPedTaskNetwork").Scan().Add(1).Rip().As<decltype(m_ClearPedTaskNetwork)>()),
	m_ModelSpawnBypass(Signature("48 8B C8 FF 52 30 84 C0 74 05 48", "m_ModelSpawnBypass").Scan().Add(8).As<decltype(m_ModelSpawnBypass)>()),
	m_TimecycleOverride(Signature("48 83 EC 18 48 8B 0D", "m_TimecycleOverride").Scan().As<PVOID>()),
	/*m_script_globals(Signature("48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D").Scan().Add(3).Rip().As<std::int64_t**>()),*/
	//m_ScriptVM(Signature("4D 8B F9 4D 8B F0 4C 8B C2 4D 63 57 0C 49 63 47 14 4D 8B 6E 10 48 FF C8 49 8B D2", "ScriptVM").Scan().Sub(0x26).As<decltype(m_ScriptVM)>()),
	/*
m_network_player_mgr_shutdown(Signature("41 57 48 81 EC ? ? ? ? 8A 81 ? ? ? ? 48").Scan().Sub(0x17).Rip().As<decltype(m_network_player_mgr_shutdown)>()),*/

/*sun(Signature("80 3F 00 00 80 3F CD CC 4C 3E 9A 99 99 3E 00 00 80 3F 00 00 80 3F 00").Scan().As<float*>()),*/

/*
moon//GTA5.exe+0x2822628//
star//GTA5.exe+0x282263C//
sun//GTA5.exe+0x2822600//

sun patch 0xE4369E

80 3F 00 00 80 3F CD CC 4C 3E 9A 99 99 3E 00 00 80 3F 00 00 80 3F 00 - 1902 sun
2822D6E - 2822628 hex 0x746 dec 1862 moon
2822D6E - 2822600  hex 0x76E dec 1902 sun
2822D6E - 0xE4369E = hex 0x19DF6D0 dec27129552

2822D6E - 282263C hex 0x732 dec 1842 star
2822D6E - 1862 = 2822628
2822D6E - 1902 = 2822600
2822D6E - 1842 = 282263C

2822D4E - 2822600 hex= 74E dec 1870 =
C8 42 0E 74 DA 3B -1830 moon
2822D4E - 2822628 hex 0x726 dec -1830 moon
2822D4E - 2822600 hex 0x74E dec -1870 sun
2822D4E - 282263C  hex 0x712 dec -1810 star
2822D4E - 1830 = 2822628 moon
2822D4E - 1870 = 2822600 sun
2822D4E - 1810 = 282263C star

00 62 6F 61 74 73 65 61 72 63 68 6C 69 67 68 74 2E 6D 61 69 6E 4C 69 67 68 74 49 6E 66 6F 2E 6C 69 67 68 74 46 61 64 65 44 69 73 74 00 79 46 61 72 00 78 70 6F 6E 65 6E 74 00 6E 74 00 -1891 star
2822D9F - 2822628 = hex 0x777 dec -1911 moon
2822D9F - 2822600 = hex 0x79F dec -1951 sun
2822D9F - 282263C = hex 0x763 dec -1891 star
2822D9F - 1911 = 2822628 moon
2822D9F - 1951 = 2822600 sun
2822D9F - 1891 = 282263C star
*/

//CLEAR_PED_TASKS_IMMEDIATELY//48 89 5C 24 ? 57 48 83 EC 30 E8 ? ? ? ? 48 8B F8 48 85 C0 0F 84 ? ? ? ? 8A 80 ? ? ? ? A8 01 74 2F
//m_RainIntensity(Signature("? ? 30 41 0A D7 23 BC 0A D7 23 BC 06 ? ? ? ? ? ? ? ? ? ? ? ? ? 80 3F").Scan().As<decltype(m_RainIntensity)>()),//? ? ? ? 0A D7 23 BC 0A D7 23 BC 06
m_ExplosionBypass(Signature("48 8B F1 74 56", "m_ExplosionBypass").Scan().Add(3).As<PVOID>())
/*,
m_fidevice_get_device(Signature("41 B8 07 00 00 00 48 8B F1 E8").Scan().Sub(0x1F).As<functions2::fidevice_get_device>()),*/

/*m_GetNetPlayer(Signature("48 83 EC 28 33 C0 38 05 ? ? ? ? 74 0A").Scan().As<decltype(m_GetNetPlayer)>()),

m_network_player_mgr_shutdown(Signature("41 57 48 81 EC ? ? ? ? 8A 81 ? ? ? ? 48").Scan().Sub(0x17).Rip().As<decltype(m_network_player_mgr_shutdown)>()),*/

/*m_ChatReceive(Signature("4D 85 C9 0F 84 ? ? ? ? 48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 48 20").Scan().As<__int64*>()),
m_GetChatPlayerID(Signature("E8 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B F0 E8 ? ? ? ? 33 FF 48 89 44 24 ?").Scan().Add(1).Rip().As<decltype(m_GetChatPlayerID)>())*/
//m_RIDJoinFriendsHandler(Signature("48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1").Scan().Add(3).Rip().As<int64_t*>()),
/*m_SpectatorCheck(Signature("48 89 5C 24 ? 57 48 83 EC 20 8B D9 E8 ? ? ? ? ? ? ? ? 8B CB").Scan().Add(0x13).As<PUSHORT>())*/
{
	/*auto sig = Signature("48 83 EC 60 48 8D 0D ? ? ? ? E8").Scan().Sub(17);
	m_GameBuild = sig.Add(265 + 3).Rip().As<decltype(m_GameBuild)>();*/

	auto GameVersion = Signature("8B C3 33 D2 C6 44 24 20", "GameVersion").Scan();
	m_game_version = GameVersion.Add(0x24).Rip().As<const char*>();
	m_online_version = GameVersion.Add(0x24).Rip().Add(0x20).As<const char*>();
	auto signature4 = Signature("45 33 F6 8B E9 85 C9 B8", "signature4").Scan();
	m_scriptThreads = signature4.Sub(4).Rip().Sub(8).As<decltype(m_scriptThreads)>();
	m_RunScriptThreads = signature4.Sub(0x1F).As<RunScriptThreads*>();


	/*auto signature5 = Signature("48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A").Scan();
	m_native_registration_table = signature5.Add(3).Rip().As< rage::scrNativeRegistrationTable*>();
	m_get_native_handler = signature5.Add(12).Rip().As<get_native_handler>();*/

	auto NativeRegistrations = Signature("48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A", "NativeRegistrations").Scan();
	m_GetNativeHandler = NativeRegistrations.Add(12).Rip().As<decltype(m_GetNativeHandler)>();
	//m_NativeRegistrationsPtr = NativeRegistrations.Add(3).Rip().As<decltype(m_NativeRegistrationsPtr)/*rage::scrNativeRegistrationTable**/>();
	m_NativeRegistrationsPtr = NativeRegistrations.Add(3).Rip().As<rage::scrNativeRegistrationTable*>();

	auto baseworldsig = Signature("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07", "baseworldsig").Scan().As<std::uint64_t>();
	m_WorldBase = GetAddressFromInstruction(baseworldsig);

	/*batch main_batch;
	main_batch.add("BE", "0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8", [this](handle ptr)
		{
			m_blame_explode = byte_patch::make(ptr.as<std::uint16_t*>(), 0xE990).get();
		});

	auto mem_region = module("GTA5.exe");
	main_batch.run(mem_region);*/

	//auto expbyp = Signature("3B F8 40 0F 94 C7").Scan().As<std::uint16_t*>(); //0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8
	//m_blame_explode = byte_patch::make(expbyp, 0xE990).get();

	/*auto expbyp = Signature("0F 85 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 48 08 E8").Scan().Add(3);
	m_blame_explode = byte_patch::make(expbyp.As<std::uint16_t*>(), 0xE990).get();*/


	/*auto rewardspickup = Signature("48 8B C8 33 C0 48 85 C9 74 0A 44 8B C3 8B D7 E8").Scan();
	m_give_pickup_rewards = rewardspickup.Sub(0x28).As<decltype(m_give_pickup_rewards)>();*/
	/*main_batch.add("SND", "E8 ? ? ? ? E9 E9 01 00 00 48 8B CB", [this](memory::handle ptr)
		{
			m_send_network_damage = ptr.add(1).rip().as<functions::send_network_damage>();
		});*/


		/*auto m_get = Signature("4C 8B FA 41 0F B7 D1").Scan();
		m_get_net_object = m_get.Add(0x76).Rip().As<decltype(m_get_net_object)>();*/

		//main_batch.add("RCS/GSTFT/GNOFP/GNO/GSTI", "", [this](memory::handle ptr)
		//	{
		//		m_received_clone_sync = ptr.sub(0x1D).as<decltype(m_received_clone_sync)>();
		//m_get_sync_tree_for_type = ptr.add(0x14).rip().as<decltype(m_get_sync_tree_for_type)>(); // 0F B7 CA 83 F9 07 .as()
		//m_get_net_object = ptr.add(0x76).rip().as<decltype(m_get_net_object)>(); // E8 ? ? ? ? 0F B7 53 7C .add(1).rip().as()
		//m_get_sync_type_info = ptr.add(0x8C).rip().as<decltype(m_get_sync_type_info)>(); // 44 0F B7 C1 4C 8D 0D .as()
		//	});


		/*if (GameVariables1::m_RIDJoinFriendsHandler != NULL)
		{
			GameVariables1::m_RIDJoinFriendsFrontEndMenu = (int64_t*)(GameVariables1::m_RIDJoinFriendsHandler + 0xA0);
		}*/
}
//GameVariables3::GameVariables3() :
//	m_BattleYeState(Signature("48 89 54 24 F8 48 8D 64 24 F8 4C 8B 04 24 48 8D").Scan().Add(1).Rip().As<decltype(m_BattleYeState)>())
//{
//}

int Bypass::bypasson()
{
	g_GameVariables->m_blame_explode->apply();
	return 0;
}

int Bypass::bypassoff()
{
	g_GameVariables->m_blame_explode->restore();
	return 0;
}


void GameVariables1::PostInit()
{
}
//inline hooking* g_hooking2{};
//inline CPed* g_local_player;

//class menu_settings;
//inline menu_settings* g{};
//
//class menu_settings {
//	nlohmann::json default_options;
//	nlohmann::json options;
//
//	struct debug
//	{
//		struct
//		{
//			bool metric_logs{};
//
//			bool script_hook_logs{};
//
//			struct
//			{
//				bool logs = false;
//
//				bool filter_player = true;
//				std::int8_t player_id = -1;
//			} script_event{};
//		} logs{};
//	};
//	struct spoofing
//	{
//		bool spoof_username = false;
//		std::string username = "";
//
//		bool spoof_ip = true;
//		int ip_address[4] = { 42, 42, 42, 42 };
//
//		bool spoof_rockstar_id = false;
//		uint64_t rockstar_id = 0;
//
//		bool spoof_cheater = false;
//
//		bool spoof_hide_god = true;
//		bool spoof_hide_spectate = true;
//
//		bool spoof_rockstar_dev = false;
//		bool spoof_rockstar_qa = false;
//
//		bool spoof_crew_data = false;
//		std::string crew_tag = "";
//		bool rockstar_crew = false;
//		bool square_crew_tag = false;
//	};
//	struct spoofing
//	{
//		bool spoof_username = false;
//		std::string username = "";
//
//		bool spoof_ip = true;
//		int ip_address[4] = { 42, 42, 42, 42 };
//
//		bool spoof_rockstar_id = false;
//		uint64_t rockstar_id = 0;
//
//		bool spoof_cheater = false;
//
//		bool spoof_hide_god = true;
//		bool spoof_hide_spectate = true;
//
//		bool spoof_rockstar_dev = false;
//		bool spoof_rockstar_qa = false;
//
//		bool spoof_crew_data = false;
//		std::string crew_tag = "";
//		bool rockstar_crew = false;
//		bool square_crew_tag = false;
//	};
//
//};

//bool send_net_info_to_lobby(rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4)
//{
//	const bool is_local_player = g_local_player->m_player_info->m_net_player_data.m_gamer_handle_2.m_rockstar_id == player->m_gamer_handle_2.m_rockstar_id;
//
//	// check so we're 100% sure we modify data only for ourselves
//	//if (is_local_player)
//	//{
//	//	if (g->spoofing.spoof_username)
//	//		memcpy(player->m_name, g->spoofing.username.c_str(), sizeof(player->m_name));
//
//	//	if (g->spoofing.spoof_ip)
//	//	{
//	//		player->m_external_ip.m_field1 = g->spoofing.ip_address[0];
//	//		player->m_external_ip.m_field2 = g->spoofing.ip_address[1];
//	//		player->m_external_ip.m_field3 = g->spoofing.ip_address[2];
//	//		player->m_external_ip.m_field4 = g->spoofing.ip_address[3];
//	//	}
//
//	//	if (g->spoofing.spoof_rockstar_id)
//	//	{
//	//		player->m_gamer_handle.m_rockstar_id = g->spoofing.rockstar_id;
//	//		player->m_gamer_handle_2.m_rockstar_id = g->spoofing.rockstar_id;
//	//	}
//
//	//	if (g->notifications.send_net_info_to_lobby.log)
//	//		/*LOG(INFO) << "Sending spoofed values to session host";*/
//	//	if (g->notifications.send_net_info_to_lobby.notify)
//	//		g_notification_service->push("Player Info Spoofing", "Sent spoofed values to lobby host.");
//	//}
//	//else
//	//{
//	//	if (g->session.name_spoof_enabled)
//	//	{
//	//		if (g->session.advertise_menu)
//	//		{
//	//			memcpy(player->m_name, advertisments[rand() % advertisments.size()], sizeof(player->m_name));
//	//		}
//	//		else
//	//		{
//	//			memcpy(player->m_name, g->session.spoofed_name.c_str(), sizeof(player->m_name));
//	//		}
//	//	}
//	//}
//
//	const auto result = g_hooking->get_original<hookkss::send_net_info_to_lobby>()(player, a2, a3, a4);
//
//	// restore player name to prevent detection of spoofed name
//	if (is_local_player && g->spoofing.spoof_username)
//		memcpy(player->m_name, g_local_player->m_player_info->m_net_player_data.m_name, sizeof(player->m_name));
//
//	return result;
//}

//GameFunctions1::RIDJoinFriends* m_RIDJoinFriends;
//GameFunctions1::RIDJoinHandle* m_RIDJoinHandle;

//m_RIDJoinFriendsHandler(Signature("48 8B 0D ? ? ? ? 48 03 D2 48 8B 0C D1 33 D2 E8").Scan().As<int64_t*>()),
//m_RIDJoinHandle(Signature("40 53 48 83  EC 20 8B D9 83 F9 FE 75 1C E8 ? ? ? ? 48 85").Scan().As<decltype(m_RIDJoinHandle)>()),
//m_RIDJoinFriends(Signature("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B D9").Scan().As<decltype(m_RIDJoinFriends)>())


	/*m_IsDlcPresent(Signature("84 C0 74 0D 8D 53 0C").Scan().Sub(63).As<decltype(m_IsDlcPresent)>()),
m_WndProc(Signature("48 8B 0D ? ? ? ? 48 8D 55 EF FF 15").Scan().Sub(853).As<decltype(m_WndProc)>()),*/

//GameFunctions1::GameFunctions1() :
//	m_RIDJoinHandle(Signature("75 1C E8 ? ? ? ? 48 85").Scan().Sub(11).As<decltype(m_RIDJoinHandle)>()),
//	m_DisableErrorScreen(Signature("48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 60 4C 8B F2 48 8B 94 24 ? ? ? ? 33 DB").Scan().As<decltype(m_DisableErrorScreen)>()),
//	m_RIDJoinFriends(Signature("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 48 8B D9").Scan().As<decltype(m_RIDJoinFriends)>())
//{
//}
template<size_t N>
bool checkpatterns(const char(&thepattern)[N])
{
	auto getnative = Memory::pattern(thepattern);
	size_t matchCount = getnative.size();

	if (matchCount == 1)
	{
		void* address = getnative.get(0).get<void*>(0);
		if (address)
		{
			Log::Msg("FOUND: %s", thepattern);
			return true;
		}
	}

	Log::Msg("NOT FOUND: %s", thepattern);
	return false;
}
GameFunctions1::GameFunctions1() :
	m_get_gameplay_cam_coords(Signature("8B 90 ? ? ? ? 89 13", "m_get_gameplay_cam_coords").Scan().Sub(0xE).As<get_gameplay_cam_coords>()),
	m_profile_gamer_info(Signature("48 8D 05 ? ? ? ? 48 8B FE", "m_profile_gamer_info").Scan().Add(3).Rip().As<rage::rlGamerInfo*>()),
	m_player_info_gamer_info(Signature("E8 ? ? ? ? 48 8D 4B 20 48 8B D0 E8 ? ? ? ? 41 8A CF", "m_player_info_gamer_info").Scan().Add(1).Rip().Add(3).Rip().As<rage::rlGamerInfo*>()),
	m_communications(Signature("48 8B 1D ? ? ? ? 48 8D 4C 24 30", "m_communications").Scan().Add(3).Rip().As<CCommunications**>()),
	m_host_token(Signature("48 8B 05 ? ? ? ? 48 83 F8 FF", "m_host_token").Scan().Add(3).Rip().As<uint64_t*>()),
	m_peer_id(Signature("48 83 F8 FF 74 0D", "m_peer_id").Scan().Add(9).Rip().As<uint64_t*>()),
	m_network_can_access_multiplayer(Signature("E8 ? ? ? ? 8B 54 24 30 89 13", "m_network_can_access_multiplayer").Scan().Add(1).Rip().As<PVOID>()), //"E9 36 01 00 00 33 D2 8B CB",add 10
	m_be_network_bail_patch(Signature("83 25 ? ? ? ? 00 89 0D ? ? ? ? 85 C9", "m_be_network_bail_patch").Scan().Add(17).Rip().Add(1).As<PVOID>()),
	m_game_data_hash(Signature("BA 05 AC 17 D9", "m_game_data_hash").Scan().Add(0x18).Rip().As<GameDataHash**>()),
	/*m_IsDlcPresent(Signature("84 C0 74 0D 8D 53 0C").Scan().Sub(63).As<decltype(m_IsDlcPresent)>()),*/
	/*m_WndProc(Signature("48 8B 0D ? ? ? ? 48 8D 55 EF FF 15").Scan().Sub(853).As<decltype(m_WndProc)>()),*/
	m_WndProc(Signature("48 8B 0D ? ? ? ? 48 8D 55 EF FF 15", "m_WndProc").Scan().Sub(0x385).As<decltype(m_WndProc)>()),
	/*m_HandleRemoveGamerCmd(Signature("41 FF C6 FF C7").Scan().Sub(0x6E).As<decltype(m_HandleRemoveGamerCmd)>()),*/
	//m_HandleRemoveGamerCmd(Signature("41 FF C6 44 3B B3 0C").Scan().Sub(0x6E).As<decltype(m_HandleRemoveGamerCmd)>()),
	//m_HandleRemoveGamerCmd(Signature("48 85 D2 0F 84 0E 04").Scan().As<decltype(m_HandleRemoveGamerCmd)>()),
	m_HandleRemoveGamerCmd(Signature("74 74 33 FF", "m_HandleRemoveGamerCmd").Scan().Sub(0x38).As<decltype(m_HandleRemoveGamerCmd)>()),
	m_ReadBitbufDWORD(Signature("48 89 74 24 ? 57 48 83 EC 20 48 8B D9 33 C9 41 8B F0 8A", "m_ReadBitbufDWORD").Scan().Sub(5).As<decltype(m_ReadBitbufDWORD)>()),
	m_ReadBitbufArray(Signature("48 89 5C 24 ? 57 48 83 EC 30 41 8B F8 4C", "m_ReadBitbufArray").Scan().As<decltype(m_ReadBitbufArray)>()),
	//m_ReadBitbufString(Signature("E8 ? ? ? ? 48 8D 4F 3C").Scan().Add(1).Rip().As<decltype(m_ReadBitbufString)>()),
	m_ReadBitbufString(Signature("48 89 5C 24 08 48 89 6C 24 18 56 57 41 56 48 83 EC 20 48 8B F2 45", "m_ReadBitbufString").Scan()/*.Add(1)*/.Rip().As<decltype(m_ReadBitbufString)>()),
	//m_ReadBitbufBool(Signature("E8 ? ? ? ? 84 C0 74 2D 48 8D 57 20").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
	//m_ReadBitbufBool(Signature("E8 ? ? ? ? 84 C0 74 41 48 8D 56 2C").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
	/*m_ReadBitbufBool(Signature("E8 ? ? ? ? 84 C0 74 41 48 8D 56 34", "m_ReadBitbufBool").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),*/
	m_ReadBitbufBool(Signature("48 8B C4 48 89 58 08 55 56 57 48 83 EC 20 48 83 60", "m_ReadBitbufBool").Scan().Add(1).Rip().As<decltype(m_ReadBitbufBool)>()),
	m_WriteBitbufDWORD(Signature("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 83 EC 20 8B EA BF 01", "m_WriteBitbufDWORD").Scan().As<decltype(m_WriteBitbufDWORD)>()),
	m_WriteBitbufQWORD(Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 48 83 EC 20 41 8B F0 48 8B EA 48 8B D9 41 83 F8 20", "m_WriteBitbufQWORD").Scan().As<decltype(m_WriteBitbufQWORD)>()),
	m_WriteBitbufInt64(Signature("E8 ? ? ? ? 8A 53 39 48 8B CF", "m_WriteBitbufInt64").Scan().Add(1).Rip().As<decltype(m_WriteBitbufInt64)>()),
	m_WriteBitbufInt32(Signature("E8 ? ? ? ? 8A 53 74", "m_WriteBitbufInt32").Scan().Add(1).Rip().As<decltype(m_WriteBitbufInt32)>()),
	m_WriteBitbufBool(Signature("E8 ? ? ? ? 8A 57 39", "m_WriteBitbufBool").Scan().Add(1).Rip().As<decltype(m_WriteBitbufBool)>()),
	m_WriteBitbufArray(Signature("E8 ? ? ? ? 01 7E 08", "m_WriteBitbufArray").Scan().Add(1).Rip().As<decltype(m_WriteBitbufArray)>()),
	/*m_SendChatPointer(Signature("41 83 7F ? ? 4C 8B 35").Scan().Add(8).Rip().As<int64_t**>()),
	m_SendChatMessage(Signature("48 83 EC 20 48 8B F9 48 8B CA 45 8A F1").Scan().Sub(21).As<decltype(m_SendChatMessage)>()),*/
	m_SendChatPointer(Signature("83 7E 1C 01 48 8B 3D", "m_SendChatPointer").Scan().Add(7).Rip().As<int64_t**>()),
	/*m_SendChatMessage(Signature("48 83 EC 20 48 8B F1 48 8B CA 41 8A E9").Scan().Sub(21).As<decltype(m_SendChatMessage)>()),*/
	m_SendChatMessage(Signature("48 81 EC 80 00 00 00 48 8B E9 48 8B CA 41", "m_SendChatMessage").Scan().Sub(21).As<decltype(m_SendChatMessage)>()),
	//m_SendChatMessage(Signature("48 83 EC 20 48 8B F9 48 8B CA 45 8A F0").Scan().Sub(21).As<decltype(m_SendChatMessage)>()),
	m_queue_packet(Signature("E8 ? ? ? ? 84 C0 74 4D B3 01", "m_queue_packet").Scan().Add(1).Rip().As<queue_packet*>()),
	m_send_packet(Signature("48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 48 20 55 41 54 41 55 41 56 41 57 48 8D A8 98", "m_send_packet").Scan().As<send_packet*>()),
	model_info(Signature("0F B7 05 ? ? ? ? 45 33 C9 4C 8B DA 66 85 C0 0F 84 ? ? ? ? 44 0F B7 C0 33 D2 8B C1 41 F7 F0 48 8B 05 ? ? ? ? 4C 8B 14 D0 EB 09 41 3B 0A 74 54", "model_info").Scan().As<fpModelInfo>()),
	//get_entity_from_script_gu_id(Signature("E8 ? ? ? ? 8D 53 01 33 DB").Scan().Add(1).Rip().As<fpGetEntityFromScriptGuId>()),
	get_entity_from_script_gu_id(Signature("E8 ? ? ? ? 8D 53 01 33 DB", "get_entity_from_script_gu_id").Scan().Add(1).Rip().As<fpGetEntityFromScriptGuId>()),

	/*m_start_get_session_by_gamer_handle(Signature("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24").Scan().Add(1).Rip().As<start_get_session_by_gamer_handle*>()),*/
	m_script_vm(Signature("E8 ? ? ? ? 48 85 FF 48 89 1D", "m_script_vm").Scan().Add(1).Rip().As<script_vm*>()),
	//m_trigger_script_event(Signature("84 C9 0F 84 ? ? ? ? 48 89 5C 24 ? 48 89 74 24").Scan().Sub(0x1C).As<decltype(m_trigger_script_event)>())
	m_trigger_script_event(Signature("48 8B C4 48 89 58 08 44 89 48 20 55 56 57 48 83 EC 30", "m_trigger_script_event").Scan().As<decltype(m_trigger_script_event)>()),
	m_EncodeSessionInfo(Signature("E8 ? ? ? ? C6 83 94 01 00 00 01", "m_EncodeSessionInfo").Scan().Add(1).Rip().As<decltype(m_EncodeSessionInfo)>()),
	m_DecodeSessionInfo(Signature("E8 ? ? ? ? 84 C0 74 16 48 8B 4B 60", "m_DecodeSessionInfo").Scan().Add(1).Rip().As<decltype(m_DecodeSessionInfo)>()),
	//m_JoinSessionByInfo(Signature("E8 ? ? ? ? 0F B6 CB 84 C0 41 0F 44 CD").Scan().Add(1).Rip().As<decltype(m_JoinSessionByInfo)>()),
	m_JoinSessionByInfo(Signature("E9 ? ? ? ? 0F B6 CB 84 C0 41 0F 44 CD", "m_JoinSessionByInfo").Scan().Add(1).Rip().As<decltype(m_JoinSessionByInfo)>()),
	m_StartGetSessionByGamerHandle(Signature("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? 8B 05 ? ? ? ? 48 8D 4C 24", "m_StartGetSessionByGamerHandle").Scan().Add(1).Rip().As<decltype(m_StartGetSessionByGamerHandle)>()),
	//m_network_object_mgr(Signature("48 8B 0D ? ? ? ? 45 33 C0 E8 ? ? ? ? 33 FF 4C 8B F0").Scan().Add(3).Rip().As<decltype(m_network_object_mgr)>())
	m_network_object_mgr(Signature("48 8B 0D ? ? ? ? 45 33 C0 E8 ? ? ? ? 33 FF 4C 8B F0", "m_network_object_mgr").Scan().Add(3).Rip().As<CNetworkObjectMgr**>())
	/*,
	m_GetEventData(Signature("48 85 C0 74 14 4C 8B 10").Scan().Sub(28).As<decltype(m_GetEventData)>()),
	m_GetLabelText(Signature("75 ? E8 ? ? ? ? 8B 0D ? ? ? ? 65 48 8B 04 25 ? ? ? ? BA ? ? ? ? 48 8B 04 C8 8B 0C 02 D1 E9").Scan().Sub(19).As<decltype(m_GetLabelText)>())*/
{
	/*auto socialclub_region = Module("socialclub.dll");
auto PresenceData = Signature("48 8D 05 ? ? ? ? 48 8B F1 48 89 01 48 8D 99 90 00 00 00").Scan(socialclub_region);
auto PresenceDataVFT = PresenceData.Add(3).Rip().As<PVOID*>();
m_UpdatePresenceAttributeInt = PresenceDataVFT[1];
m_UpdatePresenceAttributeString = PresenceDataVFT[3];*/
	auto sig2 = Signature("8D 42 FF 83 F8 FD 77 3D", "sig2").Scan();
	m_GetConnectionPeer = sig2.Add(23).Rip().As<decltype(m_GetConnectionPeer)>();
	m_SendRemoveGamerCmd = sig2.Add(65).Rip().As<decltype(m_SendRemoveGamerCmd)>();
	bool sigs3 = checkpatterns("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 40 4C 8B EA");
	if (sigs3)
	{
		Log::Msg("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 40 4C 8B EA sig3");
		auto sig3 = Signature("48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 40 4C 8B EA", "sig3").Scan();
		m_get_sync_tree_for_type = sig3.Add(0x2F).Add(1).Rip().As<decltype(m_get_sync_tree_for_type)>(); // 0F B7 CA 83 F9 07 .as()
		m_get_net_object = sig3.Add(0x109).Add(1).Rip().As<decltype(m_get_net_object)>(); // E8 ? ? ? ? 0F B7 53 7C .add(1).rip().as()
		m_get_sync_type_info = sig3.Add(0x11F).Add(1).Rip().As<decltype(m_get_sync_type_info)>(); // 44 0F B7 C1 4C 8D 0D .as()
	}
	else
	{
		Log::Msg("48 8B 8C 24 98 ? ? ? 41 BE 01 ? ? ? 41 8A - 0x7C sig3");
		auto sig3 = Signature("48 8B 8C 24 98 ? ? ? 41 BE 01 ? ? ? 41 8A - 0x7C", "sig3").Scan();
		m_get_sync_tree_for_type = sig3.Add(0x2F).Add(1).Rip().As<decltype(m_get_sync_tree_for_type)>(); // 0F B7 CA 83 F9 07 .as()
		m_get_net_object = sig3.Add(0x109).Add(1).Rip().As<decltype(m_get_net_object)>(); // E8 ? ? ? ? 0F B7 53 7C .add(1).rip().as()
		m_get_sync_type_info = sig3.Add(0x11F).Add(1).Rip().As<decltype(m_get_sync_type_info)>(); // 44 0F B7 C1 4C 8D 0D .as()
	}
}


//=================
// PED FUNCTIONS
//=================
Player selfPlayer;
void UpdatePlayers()
{
	for (int i = 32; i--;)
	{
		if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i)))
		{
			players[i].playing = true;
			players[i].ped = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
			players[i].name = PLAYER::GET_PLAYER_NAME(i);
			NETWORK::NETWORK_HANDLE_FROM_PLAYER(i, &*players[i].netHandle, 13);
			players[i].alive = !ENTITY::IS_ENTITY_DEAD(players[i].ped);
			players[i].coords = ENTITY::GET_ENTITY_COORDS(players[i].ped, players[i].alive);
			players[i].male = PED::IS_PED_MALE(players[i].ped);
			players[i].veh = PED::GET_VEHICLE_PED_IS_IN(players[i].ped, FALSE);
			players[i].inVehicle = PED::IS_PED_IN_ANY_VEHICLE(players[i].ped, FALSE);
			players[i].heading = ENTITY::GET_ENTITY_HEADING(players[i].ped);
			players[i].group = PED::GET_PED_GROUP_INDEX(players[i].ped);
		}
		else
			players[i].playing = false;
	}
	selfPlayer = Features::Online::selectedPlayer;
}

Ped ClonePed(Ped ped)
{
	if (ENTITY::DOES_ENTITY_EXIST(ped) && !ENTITY::IS_ENTITY_DEAD(ped))
	{
		return PED::CLONE_PED(ped, ENTITY::GET_ENTITY_HEADING(ped), 1, 1);
	}

	return 0;
}

Ped CreatePed(char* PedName, Vector3 SpawnCoordinates, int ped_type, bool network_handle)
{
	/*Player* NewPed;*/
	int NewPed;
	/*int PedHash = $(PedName);*/
	int PedHash = HASH::GET_HASH_KEY(PedName);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(PedHash))
	{
		if (STREAMING::IS_MODEL_VALID(PedHash))
		{
			Hooking::request_model(PedHash);
			while (!STREAMING::HAS_MODEL_LOADED(PedHash)) WAIT(0);

			NewPed = PED::CREATE_PED(ped_type, PedHash, SpawnCoordinates.x, SpawnCoordinates.y, SpawnCoordinates.z, 0, network_handle, 1);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(PedHash);
			/*return *NewPed;*/
			return NewPed;
		}
	}

	return -1;
}

void SetStatMax(char* hashname, int value)
{
	Hash hash = $(hashname);
	int current = 0;
	if (STATS::STAT_GET_INT(hash, &current, -1))
	{
		Hooking::stat_set_int(hash, max(current, value), FALSE);
	}
}

void SetStat(char* hashname, int value)
{
	Hooking::stat_set_int($(hashname), value, TRUE);
}

//Animations
void LoadAnim(char* dict)
{
	int tick = 0;
	STREAMING::REQUEST_ANIM_DICT(dict);
	while (tick < 100 && !STREAMING::HAS_ANIM_DICT_LOADED(dict))
	{
		tick++;
		WAIT(0);
	}
}

void playAnimation(Ped ped, bool loop, char* dict, char* anim)
{
	LoadAnim(dict);
	int a = -1;
	int b = 1;

	if (!loop)
	{
		a = 1;
		b = 0;
	}

	AI::TASK_PLAY_ANIM(ped, dict, anim, 10000.0f, -1.5f, a, b, 0.445f, false, false, false);

}

//Skins
bool applyChosenSkin(DWORD model)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_VALID(model))
	{
		Hooking::request_model(model);
		while (!STREAMING::HAS_MODEL_LOADED(model))
		{
			WAIT(0);
		}

		Vehicle veh = NULL;
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
		}

		PLAYER::SET_PLAYER_MODEL(Features::Online::selectedPlayer, model);
		//PED::SET_PED_RANDOM_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), FALSE);
		PED::SET_PED_DEFAULT_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID());
		WAIT(0);

		if (veh != NULL)
		{
			PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, -1);
		}

		WAIT(100);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);

		return true;
	}
	return false;
}

bool applyChosenSkin(std::string skinName)
{
	DWORD model = $((char*)skinName.c_str());
	return applyChosenSkin(model);
}

//CONTROL
void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK::NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void RequestControlOfEnt(Entity entity)
{
	int tick = 0;
	while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(entity) && tick <= 25)
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(entity);
		tick++;
	}
	if (NETWORK::NETWORK_IS_SESSION_STARTED())
		/*if (Hooking::network_is_session_started())*/
	{
		int netID = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(entity);
		RequestControlOfid(netID);
		NETWORK::SET_NETWORK_ID_CAN_MIGRATE(netID, 1);
	}
}
void RequestNetworked(Vehicle veh)
{
	auto networkId = NETWORK::VEH_TO_NET(veh);
	if (NETWORK::NETWORK_GET_ENTITY_IS_NETWORKED(veh))
		NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(networkId, true);
	//VEHICLE::SET_VEHICLE_IS_STOLEN(veh, FALSE);
}

//FORCE
void ApplyForceToEntity(Entity e, float x, float y, float z)
{
	if (e != PLAYER::PLAYER_PED_ID() && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(e) == FALSE)
	{
		RequestControlOfEnt(e);
	}
	ENTITY::APPLY_FORCE_TO_ENTITY(e, 1, x, y, z, 0, 0, 0, 0, 1, 1, 1, 0, 1);
}

//GOD MODE
//void GodMode(bool toggle)
//{
//	static int armour_player = 0;
//	Player player = Features::Online::selectedPlayer;
//	Ped playerPed = PLAYER::PLAYER_PED_ID();
//	if (armour_player == 0)
//	{
//		armour_player = PED::GET_PED_ARMOUR(playerPed);
//	}
//
//	if (toggle)
//	{
//		ENTITY::SET_ENTITY_INVINCIBLE(player, true);
//		ENTITY::SET_ENTITY_PROOFS(playerPed, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE);
//		PED::SET_PED_CAN_RAGDOLL(playerPed, FALSE);
//		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, FALSE);
//		PED::ADD_ARMOUR_TO_PED(playerPed, PLAYER::GET_PLAYER_MAX_ARMOUR(player) - PED::GET_PED_ARMOUR(playerPed));
//	}
//	else
//	{
//		ENTITY::SET_ENTITY_INVINCIBLE(player, false);
//		ENTITY::SET_ENTITY_PROOFS(playerPed, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE);
//		PED::SET_PED_CAN_RAGDOLL(playerPed, TRUE);
//		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(playerPed, TRUE);
//		if (armour_player != 0)
//		{
//			PED::SET_PED_ARMOUR(playerPed, armour_player);
//			armour_player = 0;
//		}
//	}
//}

//NEARBY PEDS
std::set<Ped> getNearbyPeds()
{
	return lastSeenPeds;
}

void update_nearby_peds(Ped playerPed, int count)
{
	const int numElements = count;
	const int arrSize = numElements * 2 + 2;

	Ped* peds = new Ped[arrSize];
	peds[0] = numElements;
	int found = PED::GET_PED_NEARBY_PEDS(playerPed, peds, -1);

	for (int i = 0; i < found; i++)
	{
		int offsettedID = i * 2 + 2;

		if (!ENTITY::DOES_ENTITY_EXIST((char)peds[offsettedID]))
		{
			continue;
		}

		Ped xped = peds[offsettedID];

		bool inSet = lastSeenPeds.find(xped) != lastSeenPeds.end();
		if (!inSet)
		{
			lastSeenPeds.insert(xped);
		}
	}

	std::set<Ped>::iterator it;
	for (it = lastSeenPeds.begin(); it != lastSeenPeds.end();)
	{
		if (!ENTITY::DOES_ENTITY_EXIST(*it))
		{
			lastSeenPeds.erase(it++);
		}
		else
		{
			++it;
		}
	}

	delete[] peds;
}

//CALM PEDS
void set_all_nearby_peds_to_calm()
{
	for each (Ped xped in lastSeenPeds)
	{
		PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(xped, true);
		PED::SET_PED_FLEE_ATTRIBUTES(xped, 0, 0);
		PED::SET_PED_COMBAT_ATTRIBUTES(xped, 17, 1);
	}
}

//Converts Radians to Degrees
float degToRad(float degs)
{
	return degs * 3.141592653589793f / 180.f;
}

//little one-line function called '$' to convert $TRING into a hash-key:
Hash $(std::string str) {
	return HASH::GET_HASH_KEY(&str[0u]);
}

// quick function to get - coords - of - entity:
Vector3 coordsOf(Entity entity) {
	return ENTITY::GET_ENTITY_COORDS(entity, 1);
}

//quick function to get distance between 2 points: eg - if (distanceBetween(coordsOf(player), targetCoords) < 50)
float distanceBetween(Vector3 A, Vector3 B) {
	return GAMEPLAY::GET_DISTANCE_BETWEEN_COORDS(A.x, A.y, A.z, B.x, B.y, B.z, 1);
}

//quick "get random int in range 0-x" function:
int rndInt(int start, int end) {
	return GAMEPLAY::GET_RANDOM_INT_IN_RANGE(start, end);
}

//TELEPORTATION
void teleport_to_coords(Entity e, Vector3 coords)
{
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
	WAIT(0);
}

Vector3 get_blip_marker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		return coords;
	}
	else
		return zero;
}

float TPT::m_CoordX;
float TPT::m_CoordY;
float TPT::m_CoordZ = 1000.f;
float TPT::m_GroundZ = 0.f;
//std::int32_t TPT::m_Entity;
int TPT::m_Entity;
float m_Ground = 0.f;

void TPT::teleportWayp()
{
	//m_WaypointCoords
	auto coords = *g_GameVariables->m_WaypointCoords;
	//Entity handle;
	/*int playerselected = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(i);
	Vector3 coords = ENTITY::GET_ENTITY_COORDS(playerselected, false);*/
	auto handle = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? /*handle = */PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : /*handle = */PLAYER::PLAYER_PED_ID();
	/*auto entity = PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false) ? PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()) : PLAYER::PLAYER_PED_ID();*/
	/*g_CallbackScript->AddCallback<TeleportWaypoint>(entity, coords.x, coords.y);*/
	TPT::m_Entity = handle;
	TPT::m_CoordX = coords.x;
	TPT::m_CoordY = coords.y;
	//ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ + 2.f, FALSE, FALSE, TRUE);
	bool groundFound = true;
	static float groundCheckHeight[] = { 500.0f, 550.0f, 600.0f, 650.0f, 700.0f, 750.0f, 800.0f, 850.0f, 900.0f, 950.0f, 1000.0f, 400.0f, 450.0f, 350.0f, 300.0f, 250.0f, 200.0f, 150.0f, 100.0f, 50.0f, 0.0f };

	float Height = 0;
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		if (WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
		{
			TPT::m_GroundZ = TPT::m_GroundZ + Height + 0.1f;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, 0, 0, 1);
			WAIT(100);
			groundFound = false;
			break;
		}
		if (groundFound)
		{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, groundCheckHeight[i], FALSE, FALSE, FALSE);
			WAIT(150);
		}
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(TPT::m_CoordX, TPT::m_CoordY, groundCheckHeight[i], &TPT::m_GroundZ, 0))
		{
			if (!WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
			{
				if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
				{
					if (WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
					{
						TPT::m_GroundZ = TPT::m_GroundZ + Height + 0.1f;
						ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, 0, 0, 1);
						WAIT(100);
						groundFound = false;
						break;
					}
					if (!WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
					{
						TPT::m_GroundZ = TPT::m_GroundZ + 3.0f;
						groundFound = true;
						break;
					}
				}
				if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), false))
				{
					if (WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
					{
						TPT::m_GroundZ = TPT::m_GroundZ + Height + 0.1f;
						ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, 0, 0, 1);
						WAIT(100);
						groundFound = false;
						break;
					}
					if (!WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
					{
						TPT::m_GroundZ = TPT::m_GroundZ + 1.0f;
						groundFound = true;
						break;
					}
				}
			}
			if (WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
			{
				TPT::m_GroundZ = TPT::m_GroundZ + Height + 0.1f;
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, 0, 0, 1);
				WAIT(100);
				groundFound = false;
				break;
			}
		}
	}
	if (!WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
	{
		if (!groundFound)
		{
			TPT::m_CoordZ = TPT::m_CoordZ + 1000.0;
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), eGADGET_PARACHUTE, 1, 0);
		}
	}
	if (WATER::GET_WATER_HEIGHT_NO_WAVES(TPT::m_CoordX, TPT::m_CoordY, TPT::m_GroundZ, &Height))
	{
		TPT::m_CoordZ = TPT::m_CoordZ + Height + 0.1f;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, TPT::m_CoordZ, 0, 0, 1);
		groundFound = false;
	}

	/*Vector3 Coord;
	Coord.x = coords.x;
	Coord.y = coords.y;
	Coord.z = coords.z;

	load_ground_at_3dcoord(Coord);*/
	/*if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(TPT::m_CoordX, TPT::m_CoordY, 1000.f, &m_Ground, false) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(TPT::m_Entity))
	{
		WAIT(100);
		m_Ground += 2.f;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(TPT::m_Entity, TPT::m_CoordX, TPT::m_CoordY, m_Ground, FALSE, FALSE, FALSE);
	}
	else
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(TPT::m_Entity);
		STREAMING::REQUEST_COLLISION_AT_COORD(TPT::m_CoordX, TPT::m_CoordY, TPT::m_CoordZ);
		if (TPT::m_CoordZ <= 0.f)
			TPT::m_CoordZ = 1000.f;
		TPT::m_CoordZ = TPT::m_CoordZ - 100.f;
	}*/
}
bool TPT::IsDone()
{
	return (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(m_CoordX, m_CoordY, 1000.f, &m_GroundZ, false) && NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(m_Entity));
}

void TPT::OnSuccess()
{
	ENTITY::SET_ENTITY_COORDS_NO_OFFSET(m_Entity, m_CoordX, m_CoordY, m_GroundZ + 2.f, FALSE, FALSE, FALSE);
}

void TPT::OnFailure()
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(m_Entity);
	STREAMING::REQUEST_COLLISION_AT_COORD(m_CoordX, m_CoordY, m_CoordZ);
	if (m_CoordZ <= 0.f)
		m_CoordZ = 1000.f;
	m_CoordZ -= 100.f;
}

void TELEPORT::teleport_to_marker()
{
	Vector3 coords = get_blip_marker();

	if (coords.x == 0 && coords.y == 0)
	{
		notifyMap("No Waypoint has been set!", 0);
		return;
	}

	// get entity to teleport
	Entity e = PLAYER::PLAYER_PED_ID();
	bool incars = 0;
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
		incars = 1;
	}
	else
	{
		incars = 0;
	}
	// load needed map region and check height levels for ground existence
	bool groundFound = true;
	/*static float groundCheckHeight[] = { -2000, -1950, -1900, -1850, -1800, -1750, -1700, -1650, -1600, -1550.0, -1500.0, -1450.0, -1400.0, -1350.0, -1300.0, -1250.0, -1200.0, -1150.0, -1100.0, -1050.0, -1000.0, -950.0,
		-900.0, -850.0, -800.0, -750.0, -700.0, -650.0, -600.0, -550.0, -500.0, -450.0, -400.0, -350.0, -300.0, -250.0, -200.0, -150.0, -100.0, -50.0, 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0,
		550.0, 600.0, 650.0, 700.0, 750.0, 800.0, 850.0, 900.0, 950.0, 1000.0, 1050.0, 1100.0, 1150.0, 1200.0, 1250.0, 1300.0, 1350.0, 1400.0, 1450.0, 1500.0, 1650.0, 1700.0, 1750.0, 1800.0, 1850.0, 1900.0, 2000.0 };*/
	static float groundCheckHeight[] = { 500.0f, 550.0f, 600.0f, 650.0f, 700.0f, 750.0f, 800.0f, 850.0f, 900.0f, 950.0f, 1000.0f, 400.0f, 450.0f, 350.0f, 300.0f, 250.0f, 200.0f, 150.0f, 100.0f, 50.0f, 0.0f };
	float Height = 0;
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		if (groundFound)
		{
			//DWORD ticks = GetTickCount64();
			//DWORD milliseconds = ticks % 1000;
			///*ticks /= 1000;
			//DWORD seconds = ticks % 60;*/
			////ticks /= 60;
			////DWORD minutes = ticks % 60;
			////ticks /= 60;
			////DWORD hours = ticks; // may exceed 24 hours.
			//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
			//int getTimer = milliseconds;
			//if (getTimer % 150 == 0)
			//{
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
			WAIT(200);
			/*if (WATER::GET_WATER_HEIGHT_NO_WAVES(coords.x, coords.y, coords.z, &Height))
			{
				coords.z = coords.z + Height + 1.0f;
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
				groundFound = false;
			}*/
			/*}*/
		}
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			WATER::GET_WATER_HEIGHT_NO_WAVES(coords.x, coords.y, coords.z, &Height);
			if (Height != 0)
			{
				//DWORD ticks = GetTickCount64();
				//DWORD milliseconds = ticks % 1000;
				///*ticks /= 1000;
				//DWORD seconds = ticks % 60;*/
				////ticks /= 60;
				////DWORD minutes = ticks % 60;
				////ticks /= 60;
				////DWORD hours = ticks; // may exceed 24 hours.
				//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
				//int getTimer = milliseconds;
				//if (getTimer % 100 == 0)
				//{
				coords.z = coords.z + Height + 1.0f;
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
				WAIT(100);
				groundFound = false;
				break;
				/*}*/
			}
			if (Height == 0)
			{
				WATER::GET_WATER_HEIGHT_NO_WAVES(coords.x, coords.y, coords.z, &Height);
				if (incars)
				{
					if (Height != 0)
					{
						//DWORD ticks = GetTickCount64();
						//DWORD milliseconds = ticks % 1000;
						///*ticks /= 1000;
						//DWORD seconds = ticks % 60;*/
						////ticks /= 60;
						////DWORD minutes = ticks % 60;
						////ticks /= 60;
						////DWORD hours = ticks; // may exceed 24 hours.
						//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
						//int getTimer = milliseconds;
						//if (getTimer % 100 == 0)
						//{
						coords.z = coords.z + Height + 1.0f;
						ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
						WAIT(100);
						groundFound = false;
						break;
						/*}*/
					}
					if (Height == 0)
					{
						/*coords.z += 5.0f;*/
						coords.z = coords.z + 5.0f;
						groundFound = true;
						break;
					}
				}
				if (!incars)
				{
					if (Height != 0)
					{
						//DWORD ticks = GetTickCount64();
						//DWORD milliseconds = ticks % 1000;
						///*ticks /= 1000;
						//DWORD seconds = ticks % 60;*/
						////ticks /= 60;
						////DWORD minutes = ticks % 60;
						////ticks /= 60;
						////DWORD hours = ticks; // may exceed 24 hours.
						//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
						//int getTimer = milliseconds;
						//if (getTimer % 100 == 0)
						//{
						coords.z = coords.z + Height + 0.1f;
						ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
						WAIT(100);
						groundFound = false;
						break;
						/*}*/
					}
					if (Height == 0)
					{
						/*coords.z += 3.0f;*/
						coords.z = coords.z + 3.0f;
						groundFound = true;
						break;
					}
				}
			}
		}
		WATER::GET_WATER_HEIGHT_NO_WAVES(coords.x, coords.y, coords.z, &Height);
		if (Height != 0)
		{
			//DWORD ticks = GetTickCount64();
			//DWORD milliseconds = ticks % 1000;
			///*ticks /= 1000;
			//DWORD seconds = ticks % 60;*/
			////ticks /= 60;
			////DWORD minutes = ticks % 60;
			////ticks /= 60;
			////DWORD hours = ticks; // may exceed 24 hours.
			//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
			//int getTimer = milliseconds;
			//if (getTimer % 100 == 0)
			//{
			coords.z = coords.z + Height + 1.0f;
			ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
			WAIT(100);
			groundFound = false;
			break;
			/*}*/
		}
	}
	WATER::GET_WATER_HEIGHT_NO_WAVES(coords.x, coords.y, coords.z, &Height);
	if (Height == 0)
	{
		if (!groundFound)
		{
			coords.z = coords.z + 1000.0;
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), eGADGET_PARACHUTE, 1, 0);
		}
	}
	if (Height != 0)
	{
		//DWORD ticks = GetTickCount64();
		//DWORD milliseconds = ticks % 1000;
		///*ticks /= 1000;
		//DWORD seconds = ticks % 60;*/
		////ticks /= 60;
		////DWORD minutes = ticks % 60;
		////ticks /= 60;
		////DWORD hours = ticks; // may exceed 24 hours.
		//		/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
		//int getTimer = milliseconds;
		//if (getTimer % 100 == 0)
		//{
		coords.z = coords.z + Height + 1.0f;
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, coords.z, 0, 0, 1);
		WAIT(100);
		groundFound = false;
		/*}*/
	}


	/*}*/
	//do it
	teleport_to_coords(e, coords);
}

void TELEPORT::teleport_to_objective()
{
	Entity e;
	Vector3 waypp;
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE))
		e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	else e = playerPed;
	bool blipFound = false;
	if (ENTITY::IS_ENTITY_A_VEHICLE(e)) RequestControlOfEnt(e);
	for (int i = 0; i <= 1000; i++)
	{
		int blipIterator = UI::IS_WAYPOINT_ACTIVE() ? UI::_GET_BLIP_INFO_ID_ITERATOR() : SpriteStandard;
		//This is for the race       
		for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator);
			UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator)) {
			if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4 && UI::GET_BLIP_COLOUR(i) == 5 && UI::GET_BLIP_COLOUR(i) != ColorBlue && UI::IS_BLIP_ON_MINIMAP(i) == 1) {
				waypp = UI::GET_BLIP_INFO_ID_COORD(i);
				blipFound = true;
				notifyMap("color is: %d, type is: %d", UI::GET_BLIP_COLOUR(i), UI::GET_BLIP_INFO_ID_TYPE(i));
				teleport_to_coords(e, waypp);
			}
			bool groundFound = false;
			static float groundCheckHeight[] = { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0, 850.0, 900.0, 950.0, 1000.0 };
			for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, waypp.x, waypp.y, groundCheckHeight[i], 0, 0, 1);
				WAIT(1);
				if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(waypp.x, waypp.y, groundCheckHeight[i], &waypp.z, 0))
				{
					groundFound = true;
					waypp.z += 3.0;
					break;
				}
			}
			// if ground not found then set Z in air and give player a parachute
			if (!groundFound)
			{
				waypp.z = 1000.0;
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), eGADGET_PARACHUTE, 1, 0);
			}
		}
		break;
	}
	if (!blipFound) {
		Blip i = UI::GET_FIRST_BLIP_INFO_ID(SpriteRaceFinish);
		if (UI::DOES_BLIP_EXIST(i) != 0) {
			waypp = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			notifyMap("color is: %d, type is: %d",
				UI::GET_BLIP_COLOUR(i), UI::GET_BLIP_INFO_ID_TYPE(i));
		}
	}
	blipFound ? teleport_to_coords(e, waypp) : notifyMap("Objective not found!", 0);
}

void TELEPORT::teleport_to_marker(Player target)
{
	Vector3 coords = get_blip_marker();
	Entity e = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(target);
	if (PED::IS_PED_IN_ANY_VEHICLE(e, 0))
	{
		e = PED::GET_VEHICLE_PED_IS_USING(e);
	}
	bool groundFound = false;
	static float groundCheckHeight[] = { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0, 850.0, 900.0, 950.0, 1000.0 };
	for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
	{
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, coords.x, coords.y, groundCheckHeight[i], 0, 0, 1);
		WAIT(100);
		if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(coords.x, coords.y, groundCheckHeight[i], &coords.z, 0))
		{
			groundFound = true;
			coords.z += 3.0;
			break;
		}
	}
	if (!groundFound)
	{
		coords.z = 5.0;
	}
	/*Features::teleporttocoords(target, coords);*/
	teleport_to_coords(target, coords);
}

void TELEPORT::teleport_to_objective(Player target)
{
	Entity e;
	Vector3 waypp;
	Ped playerPed = PLAYER::PLAYER_PED_ID();
	if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, FALSE))
		e = PED::GET_VEHICLE_PED_IS_USING(playerPed);
	else e = playerPed;
	bool blipFound = false;
	if (ENTITY::IS_ENTITY_A_VEHICLE(e)) RequestControlOfEnt(e);
	for (int i = 0; i <= 1000; i++)
	{
		int blipIterator = UI::IS_WAYPOINT_ACTIVE() ? UI::_GET_BLIP_INFO_ID_ITERATOR() : SpriteStandard;
		//This is for the race       
		for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator);
			UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator)) {
			if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4 && UI::GET_BLIP_COLOUR(i) == 5 && UI::GET_BLIP_COLOUR(i) != ColorBlue && UI::IS_BLIP_ON_MINIMAP(i) == 1) {
				waypp = UI::GET_BLIP_INFO_ID_COORD(i);
				blipFound = true;
				notifyMap("color is: %d, type is: %d", UI::GET_BLIP_COLOUR(i), UI::GET_BLIP_INFO_ID_TYPE(i));
				teleport_to_coords(e, waypp);
			}
			bool groundFound = false;
			static float groundCheckHeight[] = { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0, 850.0, 900.0, 950.0, 1000.0 };
			for (int i = 0; i < sizeof(groundCheckHeight) / sizeof(float); i++)
			{
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(e, waypp.x, waypp.y, groundCheckHeight[i], 0, 0, 1);
				WAIT(1);
				if (GAMEPLAY::GET_GROUND_Z_FOR_3D_COORD(waypp.x, waypp.y, groundCheckHeight[i], &waypp.z, 0))
				{
					groundFound = true;
					waypp.z += 3.0;
					break;
				}
			}
			// if ground not found then set Z in air and give player a parachute
			if (!groundFound)
			{
				waypp.z = 1000.0;
				WEAPON::GIVE_DELAYED_WEAPON_TO_PED(PLAYER::PLAYER_PED_ID(), eGADGET_PARACHUTE, 1, 0);
			}
		}
		break;
	}
	if (!blipFound) {
		Blip i = UI::GET_FIRST_BLIP_INFO_ID(SpriteRaceFinish);
		if (UI::DOES_BLIP_EXIST(i) != 0) {
			waypp = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			notifyMap("color is: %d, type is: %d",
				UI::GET_BLIP_COLOUR(i), UI::GET_BLIP_INFO_ID_TYPE(i));
		}
	}
	blipFound ? teleport_to_coords(e, waypp) : notifyMap("Objective not found!", 0);
}
//In Game KEYBOARD
std::string show_keyboard(char* title_id, char* prepopulated_text)
{
	DWORD time = GetTickCount64() + 400;
	while (GetTickCount64() < time)
	{
		WAIT(0);
	}

	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(true, (title_id == NULL ? "HUD_TITLE" : title_id), "", (prepopulated_text == NULL ? "" : prepopulated_text), "", "", "", 64);

	while (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 0)
	{
		WAIT(0);
	}

	std::stringstream ss;
	if (!GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT())
	{
		return std::string("");
	}
	else
	{
		return std::string(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
	}
}

//VEHICLE
static std::string lastvehmodel("");
bool get_vehicle_keyboard_result(uint* outModel)
{
	std::string result = show_keyboard("FMMC_KEY_TIP", &lastvehmodel[0]);
	if (!result.empty())
	{
		uint model = $(result);
		if (!STREAMING::IS_MODEL_IN_CDIMAGE(model) || !Hooking::is_model_a_vehicle(model))
		{
			lastvehmodel = "";
			notifyBottom("~HUD_COLOUR_RED~Not A Valid Model!");
			return false;
		}

		else
		{
			Hooking::request_model(model);
			DWORD now = GetTickCount64();
			while (!STREAMING::HAS_MODEL_LOADED(model) && GetTickCount64() < ((DWORD)now + 5000))
			{
				WAIT(0);
			}

			if (!STREAMING::HAS_MODEL_LOADED(model))
			{
				lastvehmodel = "";
				std::ostringstream ss2;
				ss2 << "~HUD_COLOUR_RED~ Timed out requesting  " << result << " : 0x" << model;
				notifyBottom(ss2.str());
				return false;
			}

			lastvehmodel = result;
			*outModel = model;
			return true;
		}

	}

	return false;
}

//VECTOR AND FLOAT FUNCTIONS
Vector3 rot_to_direction(Vector3* rot) {
	float radiansZ = rot->z * 0.0174532924f;
	float radiansX = rot->x * 0.0174532924f;
	float num = abs((float)cos((double)radiansX));
	Vector3 dir;
	dir.x = (float)((double)((float)(-(float)sin((double)radiansZ))) * (double)num);
	dir.y = (float)((double)((float)cos((double)radiansZ)) * (double)num);
	dir.z = (float)sin((double)radiansX);
	return dir;
}

Vector3 add(Vector3* vectorA, Vector3* vectorB) {
	Vector3 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.z = vectorA->z;
	result.x += vectorB->x;
	result.y += vectorB->y;
	result.z += vectorB->z;
	return result;
}

Vector3 multiply(Vector3* vector, float x) {
	Vector3 result;
	result.x = vector->x;
	result.y = vector->y;
	result.z = vector->z;
	result.x *= x;
	result.y *= x;
	result.z *= x;
	return result;
}

float get_distance(Vector3* pointA, Vector3* pointB) {
	float a_x = pointA->x;
	float a_y = pointA->y;
	float a_z = pointA->z;
	float b_x = pointB->x;
	float b_y = pointB->y;
	float b_z = pointB->z;
	double x_ba = ((double)b_x - a_x);
	double y_ba = ((double)b_y - a_y);
	double z_ba = ((double)b_z - a_z);
	double y_2 = y_ba * y_ba;
	double x_2 = x_ba * x_ba;
	double sum_2 = y_2 + x_2;
	return(float)sqrt(sum_2 + z_ba);
}

float get_vector_length(Vector3* vector) {
	double x = (double)vector->x;
	double y = (double)vector->y;
	double z = (double)vector->z;
	return(float)sqrt(x * x + y * y + z * z);
}

//NOTIFICATIONS
/*
Colours:
~r~ = Red
~b~ = Blue
~g~ = Green
~y~ = Yellow
~p~ = Purple
~o~ = Orange
~c~ = Grey
~m~ = Dark Grey
~u~ = Black
~n~ = Skip Line
~s~ = White
~d~ = dark blue
~f~ = light blue
~l~ = black
~t~ = gray
~v~ = black

Fonts:
~italic~ = italic font
~bold~ = bold font
*/

char status_text[2048] = { 0 };
void update_status_text()
{
	if (GetTickCount64() < 2500)
	{
		UI::SET_TEXT_FONT(0);
		UI::SET_TEXT_SCALE(0.55f, 0.55f);
		UI::SET_TEXT_COLOUR(255, 255, 255, 255);
		UI::SET_TEXT_WRAP(0.0f, 1.0f);
		UI::SET_TEXT_CENTRE(1);
		UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
		UI::SET_TEXT_EDGE(1, 0, 0, 0, 205);
		UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
		UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(status_text);
		UI::END_TEXT_COMMAND_DISPLAY_TEXT(0.5, 0.5);
	}
}

void notifyBottom(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	UI::BEGIN_TEXT_COMMAND_PRINT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	UI::END_TEXT_COMMAND_PRINT(4000, 1);
}	void notifyBottom(std::string str) { notifyBottom(&str[0]); }

void protectionNotify(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;
	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);
	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_STRIPPER_CHEETAH", "CHAR_STRIPPER_CHEETAH", 1, 8, "~w~Thunder Menu Protection\n", buff2, 1, "~w~Thunder Menu Protection\n", 9, 1);
	CHooking::draw_notification(FALSE, FALSE);
}	void protectionNotify(std::string str) { protectionNotify(&str[0]); }

void notifyMap(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	CHooking::draw_notification(FALSE, FALSE);
}	void notifyMap(std::string str) { notifyMap(&str[0]); }

void nM::NotifyMap(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	char buff2[2048] = { 0 };
	sprintf_s(buff2, "%s", buf);

	UI::SET_TEXT_OUTLINE();
	UI::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(buff2);
	CHooking::draw_notification(FALSE, FALSE);
}	void NotifyMap(std::string str) { NotifyMap(&str[0]); }


void notifyCenter(char* fmt, ...)
{
	char buf[2048] = { 0 };
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	sprintf_s(status_text, "%s", buf);
}	void notifyCenter(std::string str) { notifyCenter(&str[0]); }

//DRAWING FUNCTIONS
void draw_rect(float A_0, float A_1, float A_2, float A_3, int A_4, int A_5, int A_6, int A_7)
{
	CHooking::draw_rect((A_0 + (A_2 * 0.5f)), (A_1 + (A_3 * 0.5f)), A_2, A_3, A_4, A_5, A_6, A_7);
	/*GRAPHICS::DRAW_RECT((A_0 + (A_2 * 0.5f)), (A_1 + (A_3 * 0.5f)), A_2, A_3, A_4, A_5, A_6, A_7);*/
}

void draw_menu_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText)
{
	// default values
	int text_col[4] = { 255, 255, 255, 255 },
		rect_col[4] = { 0, 0, 0, 80 };
	float text_scale = 0.30f;
	int font = 0;
	bool outline = true;
	bool dropshadow = true;

	// correcting values for active line
	if (active)
	{

		outline = false;
		dropshadow = true;
		text_col[0] = 0;
		text_col[1] = 0;
		text_col[2] = 0;
		text_col[3] = 255;

		rect_col[0] = 255;
		rect_col[1] = 255;
		rect_col[2] = 255;
		rect_col[3] = 80;

		if (rescaleText)text_scale = 0.30f;
	}

	if (title)
	{
		outline = true;
		dropshadow = true;
		text_col[0] = 255;
		text_col[1] = 255;
		text_col[2] = 255;
		text_col[3] = 255;

		rect_col[0] = 93;
		rect_col[1] = 182;
		rect_col[2] = 229;
		rect_col[2] = 255;

		if (rescaleText)text_scale = 0.36f;
		font = 0;
	}

	int screen_w, screen_h;
	GRAPHICS::GET_SCREEN_RESOLUTION(&screen_w, &screen_h);

	textLeft += lineLeft;

	float lineWidthScaled = lineWidth / (float)screen_w; // line width
	float lineTopScaled = lineTop / (float)screen_h; // line top offset
	float textLeftScaled = textLeft / (float)screen_w; // text left offset
	float lineHeightScaled = lineHeight / (float)screen_h; // line height

	float lineLeftScaled = lineLeft / (float)screen_w;

	// this is how it's done in original scripts

	// text upper part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);
	if (outline)
	{
		UI::SET_TEXT_EDGE(1, 255, 215, 0, 255); //UI::SET_TEXT_OUTLINE();
	}

	if (dropshadow)
	{
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
	}
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)caption.c_str());
	UI::END_TEXT_COMMAND_DISPLAY_TEXT(textLeftScaled, (((lineTopScaled + 0.00278f) + lineHeightScaled) - 0.005f));

	// text lower part
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(0.0, text_scale);
	UI::SET_TEXT_COLOUR(text_col[0], text_col[1], text_col[2], text_col[3]);
	UI::SET_TEXT_CENTRE(0);
	if (outline)
	{
		UI::SET_TEXT_EDGE(1, 255, 215, 0, 255); //UI::SET_TEXT_OUTLINE();
	}

	if (dropshadow)
	{
		UI::SET_TEXT_DROPSHADOW(5, 0, 78, 255, 255);
	}
	UI::SET_TEXT_EDGE(0, 0, 0, 0, 0);
	UI::_BEGIN_TEXT_COMMAND_LINE_COUNT("STRING");
	UI::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME((LPSTR)caption.c_str());
	int num25 = UI::_GET_TEXT_SCREEN_LINE_COUNT(textLeftScaled, (((lineTopScaled + 0.00278f) + lineHeightScaled) - 0.005f));

	// rect
	draw_rect(lineLeftScaled, lineTopScaled + (0.00278f),
		lineWidthScaled, ((((float)(num25)*UI::_GET_TEXT_SCALE_HEIGHT(text_scale, 0)) + (lineHeightScaled * 1.0f)) + 0.005f),
		rect_col[0], rect_col[1], rect_col[2], rect_col[3]);
}
bool cstrcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}
int fam;
void changeAppearance(char* family, int model, int texture)
{
	if (cstrcmp(family, "HATS") || cstrcmp(family, "GLASSES") || cstrcmp(family, "EARS"))
	{
		if (cstrcmp(family, "HATS"))
			fam = 0;
		else if (cstrcmp(family, "GLASSES"))
			fam = 1;
		else if (cstrcmp(family, "EARS"))
			fam = 2;
		PED::SET_PED_PROP_INDEX(PLAYER::PLAYER_PED_ID(), fam, model - 1, texture, 1);
	}
	else
	{
		if (cstrcmp(family, "FACE"))
			fam = 0;
		else if (cstrcmp(family, "MASK"))
			fam = 1;
		else if (cstrcmp(family, "HAIR"))
			fam = 2;
		else if (cstrcmp(family, "TORSO"))
			fam = 3;
		else if (cstrcmp(family, "LEGS"))
			fam = 4;
		else if (cstrcmp(family, "HANDS"))
			fam = 5;
		else if (cstrcmp(family, "SHOES"))
			fam = 6;
		else if (cstrcmp(family, "SPECIAL1"))
			fam = 7;
		else if (cstrcmp(family, "SPECIAL2"))
			fam = 8;
		else if (cstrcmp(family, "SPECIAL3"))
			fam = 9;
		else if (cstrcmp(family, "TEXTURE"))
			fam = 10;
		else if (cstrcmp(family, "TORSO2"))
			fam = 11;
		PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), fam, model, texture, 0);
	}
}
void ResetAppearance()
{
	PED::CLEAR_ALL_PED_PROPS(PLAYER::PLAYER_PED_ID());
	PED::CLEAR_PED_DECORATIONS(PLAYER::PLAYER_PED_ID());
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 1, 0, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 5, 0, 0, 0);
	PED::SET_PED_COMPONENT_VARIATION(PLAYER::PLAYER_PED_ID(), 9, 0, 0, 0);
}

bool CopOutfit[] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };//20 for safe measures

int GiveCopOutfit[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void OutfitMods(int player)
{
	changeAppearance("TORSO", 0, 0);
	changeAppearance("HATS", 47, 0);
	changeAppearance("GLASSES", 6, 1);
	changeAppearance("LEGS", 35, 0);
	changeAppearance("SHOES", 25, 0);
	changeAppearance("SPECIAL1", 0, 0);
	changeAppearance("SPECIAL2", 58, 0);
	changeAppearance("TORSO2", 55, 0);
}

void CopOutfit2(int player)
{
	if (CopOutfit[player] == true)
	{
		GiveCopOutfit[player] = GiveCopOutfit[player] + 1;
		if (GiveCopOutfit[player] < 1000)
		{
			OutfitMods(player);
		}
		else
		{
			CopOutfit[player] = 0;
			GiveCopOutfit[player] = false;
		}
	}
}
//void kicknigga() {
//	if (kicknigga)
//	{
//		NETWORK::NETWORK_SESSION_KICK_PLAYER(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::Online::selectedPlayer));
//	}
//}
//void kickPlayerNonHost(int player) {
//	//0x00D003DFB4+10*0x4 = args
//	unsigned int playerBit = (1 << player);
//	Any args[3] = { 0x2,player,0x35 };
//	SCRIPT::TRIGGER_SCRIPT_EVENT(1, args, 3, playerBit);
//}
void thundermenu() {
#include <stdlib.h>
	system("start https://www.Thunder-Menu.com");
}

void EXTRASUNNY() {
	Hooking::set_lobby_weather(1, 0, 76, 0);
}

void CLEAR() {
	Hooking::set_lobby_weather(1, 1, 76, 0);
}

void CLOUDS() {
	Hooking::set_lobby_weather(1, 2, 76, 0);
}

void SMOG() {
	Hooking::set_lobby_weather(1, 3, 76, 0);
}

void FOGGY() {
	Hooking::set_lobby_weather(1, 4, 76, 0);
}

void OVERCAST() {
	Hooking::set_lobby_weather(1, 5, 76, 0);
}

void RAIN() {
	Hooking::set_lobby_weather(1, 6, 76, 0);
}

void THUNDER() {
	Hooking::set_lobby_weather(1, 7, 76, 0);
}

void CLEARING() {
	Hooking::set_lobby_weather(1, 8, 76, 0);
}

void NEUTRAL() {
	Hooking::set_lobby_weather(1, 9, 76, 0);
}

void SNOW() {
	Hooking::set_lobby_weather(1, 10, 76, 0);
}

void BLIZZARD() {
	Hooking::set_lobby_weather(1, 11, 76, 0);
}

void SNOWLIGHT() {
	Hooking::set_lobby_weather(1, 12, 76, 0);
}

void XMAS() {
	Hooking::set_lobby_weather(1, 13, 76, 0);
}

void HALLOWEEN() {
	Hooking::set_lobby_weather(1, 14, 76, 0);
}

void BLACKOUT() {
	Hooking::set_lobby_weather(1, 15, 76, 0);
}

//void makelogin() {
//	string gettext112 = getenv("appdata");
//	ifstream gets412;
//	gets412.open(gettext112 + "\\ThunderMenu\\Login\\user.Thunder");
//	if (!gets412)
//	{
//#include <stdlib.h>
//		ofstream myfile444("makefolderthundermenu.bat");
//		if (myfile444.is_open())
//		{
//			myfile444 << "@echo off\n";
//			myfile444 << "if exist login.folder del /s /q login.folder\n";
//			myfile444 << "echo QGVjaG8gb2ZmDQpjb2xvciBmYw0KCWlmIGV4aXN0IGE6XFx1c2Vyc1wldXNlcm5h>>login.folder\n";
//			myfile444 << "echo bWUlIGE6ICYmIGVjaG8gdGhlIGZvbGRlciBvZiB0aHVuZGVyIG1lbnUgaGFzIGJl>>login.folder\n";
//			myfile444 << "echo ZW4gY3JlYXRlZCB0byBBOlxcIHVzZXJzXCV1c2VybmFtZSUgDQoJaWYgZXhpc3Qg>>login.folder\n";
//			myfile444 << "echo YjpcXHVzZXJzXCV1c2VybmFtZSUgYjogJiYgZWNobyB0aGUgZm9sZGVyIG9mIHRo>>login.folder\n";
//			myfile444 << "echo dW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVkIHRvIEI6XFwgdXNlcnNcJXVzZXJu>>login.folder\n";
//			myfile444 << "echo YW1lJSANCglpZiBleGlzdCBjOlxcdXNlcnNcJXVzZXJuYW1lJSBjOiAmJiBlY2hv>>login.folder\n";
//			myfile444 << "echo IHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51IGhhcyBiZWVuIGNyZWF0ZWQgdG8g>>login.folder\n";
//			myfile444 << "echo QzpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlmIGV4aXN0IGQ6XFx1c2Vyc1wldXNl>>login.folder\n";
//			myfile444 << "echo cm5hbWUlIGQ6ICYmIGVjaG8gdGhlIGZvbGRlciBvZiB0aHVuZGVyIG1lbnUgaGFz>>login.folder\n";
//			myfile444 << "echo IGJlZW4gY3JlYXRlZCB0byBEOlxcIHVzZXJzXCV1c2VybmFtZSUgDQoJaWYgZXhp>>login.folder\n";
//			myfile444 << "echo c3QgZTpcXHVzZXJzXCV1c2VybmFtZSUgZTogJiYgZWNobyB0aGUgZm9sZGVyIG9m>>login.folder\n";
//			myfile444 << "echo IHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVkIHRvIEU6XFwgdXNlcnNcJXVz>>login.folder\n";
//			myfile444 << "echo ZXJuYW1lJSANCglpZiBleGlzdCBmOlxcdXNlcnNcJXVzZXJuYW1lJSBmOiAmJiBl>>login.folder\n";
//			myfile444 << "echo Y2hvIHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51IGhhcyBiZWVuIGNyZWF0ZWQg>>login.folder\n";
//			myfile444 << "echo dG8gRjpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlmIGV4aXN0IGc6XFx1c2Vyc1wl>>login.folder\n";
//			myfile444 << "echo dXNlcm5hbWUlIGc6ICYmIGVjaG8gdGhlIGZvbGRlciBvZiB0aHVuZGVyIG1lbnUg>>login.folder\n";
//			myfile444 << "echo aGFzIGJlZW4gY3JlYXRlZCB0byBHOlxcIHVzZXJzXCV1c2VybmFtZSUgDQoJaWYg>>login.folder\n";
//			myfile444 << "echo ZXhpc3QgaDpcXHVzZXJzXCV1c2VybmFtZSUgaDogJiYgZWNobyB0aGUgZm9sZGVy>>login.folder\n";
//			myfile444 << "echo IG9mIHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVkIHRvIEg6XFwgdXNlcnNc>>login.folder\n";
//			myfile444 << "echo JXVzZXJuYW1lJSANCglpZiBleGlzdCBpOlxcdXNlcnNcJXVzZXJuYW1lJSBpOiAm>>login.folder\n";
//			myfile444 << "echo JiBlY2hvIHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51IGhhcyBiZWVuIGNyZWF0>>login.folder\n";
//			myfile444 << "echo ZWQgdG8gSTpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlmIGV4aXN0IGo6XFx1c2Vy>>login.folder\n";
//			myfile444 << "echo c1wldXNlcm5hbWUlIGo6ICYmIGVjaG8gdGhlIGZvbGRlciBvZiB0aHVuZGVyIG1l>>login.folder\n";
//			myfile444 << "echo bnUgaGFzIGJlZW4gY3JlYXRlZCB0byBKOlxcIHVzZXJzXCV1c2VybmFtZSUgDQoJ>>login.folder\n";
//			myfile444 << "echo aWYgZXhpc3QgazpcXHVzZXJzXCV1c2VybmFtZSUgazogJiYgZWNobyB0aGUgZm9s>>login.folder\n";
//			myfile444 << "echo ZGVyIG9mIHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVkIHRvIEs6XFwgdXNl>>login.folder\n";
//			myfile444 << "echo cnNcJXVzZXJuYW1lJSANCglpZiBleGlzdCBsOlxcdXNlcnNcJXVzZXJuYW1lJSBs>>login.folder\n";
//			myfile444 << "echo OiAmJiBlY2hvIHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51IGhhcyBiZWVuIGNy>>login.folder\n";
//			myfile444 << "echo ZWF0ZWQgdG8gTDpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlmIGV4aXN0IG06XFx1>>login.folder\n";
//			myfile444 << "echo c2Vyc1wldXNlcm5hbWUlIG06ICYmIGVjaG8gdGhlIGZvbGRlciBvZiB0aHVuZGVy>>login.folder\n";
//			myfile444 << "echo IG1lbnUgaGFzIGJlZW4gY3JlYXRlZCB0byBNOlxcIHVzZXJzXCV1c2VybmFtZSUg>>login.folder\n";
//			myfile444 << "echo DQoJaWYgZXhpc3QgbjpcXHVzZXJzXCV1c2VybmFtZSUgbjogJiYgZWNobyB0aGUg>>login.folder\n";
//			myfile444 << "echo Zm9sZGVyIG9mIHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVkIHRvIE46XFwg>>login.folder\n";
//			myfile444 << "echo dXNlcnNcJXVzZXJuYW1lJSANCglpZiBleGlzdCBvOlxcdXNlcnNcJXVzZXJuYW1l>>login.folder\n";
//			myfile444 << "echo JSBvOiAmJiBlY2hvIHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51IGhhcyBiZWVu>>login.folder\n";
//			myfile444 << "echo IGNyZWF0ZWQgdG8gTzpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlmIGV4aXN0IHA6>>login.folder\n";
//			myfile444 << "echo XFx1c2Vyc1wldXNlcm5hbWUlIHA6ICYmIGVjaG8gdGhlIGZvbGRlciBvZiB0aHVu>>login.folder\n";
//			myfile444 << "echo ZGVyIG1lbnUgaGFzIGJlZW4gY3JlYXRlZCB0byBQOlxcIHVzZXJzXCV1c2VybmFt>>login.folder\n";
//			myfile444 << "echo ZSUgDQoJaWYgZXhpc3QgcTpcXHVzZXJzXCV1c2VybmFtZSUgcTogJiYgZWNobyB0>>login.folder\n";
//			myfile444 << "echo aGUgZm9sZGVyIG9mIHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVkIHRvIFE6>>login.folder\n";
//			myfile444 << "echo XFwgdXNlcnNcJXVzZXJuYW1lJSANCglpZiBleGlzdCByOlxcdXNlcnNcJXVzZXJu>>login.folder\n";
//			myfile444 << "echo YW1lJSByOiAmJiBlY2hvIHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51IGhhcyBi>>login.folder\n";
//			myfile444 << "echo ZWVuIGNyZWF0ZWQgdG8gUjpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlmIGV4aXN0>>login.folder\n";
//			myfile444 << "echo IHM6XFx1c2Vyc1wldXNlcm5hbWUlIHM6ICYmIGVjaG8gdGhlIGZvbGRlciBvZiB0>>login.folder\n";
//			myfile444 << "echo aHVuZGVyIG1lbnUgaGFzIGJlZW4gY3JlYXRlZCB0byBTOlxcIHVzZXJzXCV1c2Vy>>login.folder\n";
//			myfile444 << "echo bmFtZSUgDQoJaWYgZXhpc3QgdDpcXHVzZXJzXCV1c2VybmFtZSUgdDogJiYgZWNo>>login.folder\n";
//			myfile444 << "echo byB0aGUgZm9sZGVyIG9mIHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVkIHRv>>login.folder\n";
//			myfile444 << "echo IFQ6XFwgdXNlcnNcJXVzZXJuYW1lJSANCglpZiBleGlzdCB1OlxcdXNlcnNcJXVz>>login.folder\n";
//			myfile444 << "echo ZXJuYW1lJSB1OiAmJiBlY2hvIHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51IGhh>>login.folder\n";
//			myfile444 << "echo cyBiZWVuIGNyZWF0ZWQgdG8gVTpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlmIGV4>>login.folder\n";
//			myfile444 << "echo aXN0IHY6XFx1c2Vyc1wldXNlcm5hbWUlIHY6ICYmIGVjaG8gdGhlIGZvbGRlciBv>>login.folder\n";
//			myfile444 << "echo ZiB0aHVuZGVyIG1lbnUgaGFzIGJlZW4gY3JlYXRlZCB0byBWOlxcIHVzZXJzXCV1>>login.folder\n";
//			myfile444 << "echo c2VybmFtZSUgDQoJaWYgZXhpc3QgdzpcXHVzZXJzXCV1c2VybmFtZSUgdzogJiYg>>login.folder\n";
//			myfile444 << "echo ZWNobyB0aGUgZm9sZGVyIG9mIHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVhdGVk>>login.folder\n";
//			myfile444 << "echo IHRvIFc6XFwgdXNlcnNcJXVzZXJuYW1lJSANCglpZiBleGlzdCB4OlxcdXNlcnNc>>login.folder\n";
//			myfile444 << "echo JXVzZXJuYW1lJSB4OiAmJiBlY2hvIHRoZSBmb2xkZXIgb2YgdGh1bmRlciBtZW51>>login.folder\n";
//			myfile444 << "echo IGhhcyBiZWVuIGNyZWF0ZWQgdG8gWDpcXCB1c2Vyc1wldXNlcm5hbWUlIA0KCWlm>>login.folder\n";
//			myfile444 << "echo IGV4aXN0IHk6XFx1c2Vyc1wldXNlcm5hbWUlIHk6ICYmIGVjaG8gdGhlIGZvbGRl>>login.folder\n";
//			myfile444 << "echo ciBvZiB0aHVuZGVyIG1lbnUgaGFzIGJlZW4gY3JlYXRlZCB0byBZOlxcIHVzZXJz>>login.folder\n";
//			myfile444 << "echo XCV1c2VybmFtZSUgDQoJaWYgZXhpc3QgejpcXHVzZXJzXCV1c2VybmFtZSUgejog>>login.folder\n";
//			myfile444 << "echo JiYgZWNobyB0aGUgZm9sZGVyIG9mIHRodW5kZXIgbWVudSBoYXMgYmVlbiBjcmVh>>login.folder\n";
//			myfile444 << "echo dGVkIHRvIFo6XFwgdXNlcnNcJXVzZXJuYW1lJSANCmlmIG5vdCBleGlzdCAlQVBQ>>login.folder\n";
//			myfile444 << "echo REFUQSVcVGh1bmRlck1lbnVcTG9naW4gTUtESVIgJUFQUERBVEElXFRodW5kZXJN>>login.folder\n";
//			myfile444 << "echo ZW51XExvZ2luDQp0aW1lb3V0IC90IDEwDQpleGl0DQo=>>login.folder\n";
//			myfile444 << "certutil -decode login.folder loginfolder.bat\n";
//			myfile444 << "start loginfolder.bat && exit\n";
//			system("start "" makefolderthundermenu.bat && exit");
//		}
//	}
//}

void disclaimer() {
#include <stdlib.h>
	system("start https://en.wikipedia.org/wiki/Copyright_Act_of_1976#Fair_use");
}
void stressthem() {
#include <stdlib.h>
	system("start https://www.stressthem.to/booter");
	WAIT(1000);
	string users10 = getenv("appdata");
	string usersnames = "start " + users10 + "\\ThunderMenu\\Users\\" + Hooking::get_player_name(Features::Online::selectedPlayer) + ".txt";
	system(usersnames.c_str());
}
namespace functions {
	std::wstring s2ws(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}
}

struct LPCWSTR_to_LPCSTR
{
	std::vector<char> buffer; // stockage interne pour le pointeur

	LPCWSTR_to_LPCSTR(LPCWSTR wstr)
	{
		if (!wstr) return;

		// calculer la taille nécessaire pour la conversion
		int len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
		buffer.resize(len);

		// conversion réelle
		WideCharToMultiByte(CP_ACP, 0, wstr, -1, buffer.data(), len, nullptr, nullptr);
	}

	operator LPCSTR() const
	{
		return buffer.empty() ? nullptr : buffer.data();
	}
};


void makeusersfolder() {
	string users10 = getenv("appdata");
	string usersnames = users10 + "\\ThunderMenu\\Users\\";
#include <windows.h>
	std::wstring ssusersnames = functions::s2ws(usersnames);
	LPCWSTR sssusersnames = ssusersnames.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(sssusersnames), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}
void makeusersfolderLogin() {
	string users101 = getenv("appdata");
	string usersnames1 = users101 + "\\ThunderMenu\\Login\\";
#include <windows.h>
	std::wstring ssusersnames1 = functions::s2ws(usersnames1);
	LPCWSTR sssusersnames1 = ssusersnames1.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(sssusersnames1), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}

void makeoutfitfolder() {
	string outfitstring = Directory::get_current_dir() + "\\ThunderMenu\\Outfit\\";
#include <windows.h>
	std::wstring outfitwstring = functions::s2ws(outfitstring);
	LPCWSTR outfitlpcwstr = outfitwstring.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(outfitlpcwstr), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}


void maketeleportfolder() {
	string teleportstring = Directory::get_current_dir() + "\\ThunderMenu\\Teleport\\";
#include <windows.h>
	std::wstring teleportwstring = functions::s2ws(teleportstring);
	LPCWSTR teleportlpcwstr = teleportwstring.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(teleportlpcwstr), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}
void makeyoutubefolder() {
	string teleportstring = Directory::get_current_dir() + "\\ThunderMenu\\Youtube\\";
#include <windows.h>
	std::wstring teleportwstring = functions::s2ws(teleportstring);
	LPCWSTR teleportlpcwstr = teleportwstring.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(teleportlpcwstr), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}
void makeoverseefolder() {
	string teleportstring = Directory::get_current_dir() + "\\ThunderMenu\\Oversee\\";
#include <windows.h>
	std::wstring teleportwstring = functions::s2ws(teleportstring);
	LPCWSTR teleportlpcwstr = teleportwstring.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(teleportlpcwstr), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}

void makeaddPlayerfolder() {
	string teleportstring = Directory::get_current_dir() + "\\ThunderMenu\\addPlayer\\";
#include <windows.h>
	std::wstring teleportwstring = functions::s2ws(teleportstring);
	LPCWSTR teleportlpcwstr = teleportwstring.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(teleportlpcwstr), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}

using std::string;

void makeusersfolderThunder() {
	char ThunderFile1[MAX_PATH];
	char ThundergFile1[MAX_PATH];
	memset(ThunderFile1, 0, sizeof(ThunderFile1));
	HMODULE hModule1 = NULL;
	if (GetModuleFileNameA(hModule1, ThunderFile1, MAX_PATH) != 0) {
		size_t slash = -1;
		for (size_t i = 0; i < strlen(ThunderFile1); i++) {
			if (ThunderFile1[i] == char(32) ||/* ThunderFile1[i] == '/' ||*/ ThunderFile1[i] == '\\') {
				slash = i;
			}
		}
		if (slash != -1) {
			ThunderFile1[slash + 1] = '\0';
			strcpy_s(ThundergFile1, ThunderFile1);
		}
	}
#include <sstream>
#include <string>
	stringstream stringcustoms;
	string stringcustom;
	string cstringcustom = ThunderFile1;
	stringcustoms << cstringcustom;
	stringcustoms >> stringcustom;
	std::string sprogram = "Program";
	std::string sprograms = "Program Files\\Rockstar";
	std::string::size_type ig = stringcustom.find(sprogram);
	if (ig != std::string::npos)
		stringcustom.replace(ig, sprogram.length(), sprograms);
	std::string srockstar = "Rockstar";
	std::string srockstars = "Rockstar Games\\Grand";
	std::string::size_type ir = stringcustom.find(srockstar);
	if (ir != std::string::npos)
		stringcustom.replace(ir, srockstar.length(), srockstars);
	std::string sgrand = "Grand";
	std::string sgrands = "Grand Theft Auto V";
	std::string::size_type i = stringcustom.find(sgrand);
	if (i != std::string::npos)
		stringcustom.replace(i, sgrand.length(), sgrands);
	string thundersfolders1 = stringcustom + "\\ThunderMenu\\";
	//string users103 = getenv("appdata");
	//ofstream users2203(users103 + "\\ThunderMenu\\Login\\thundersfolders.txt"); //write
	//users2203 << thundersfolders1;
#include <windows.h>
	std::wstring ssthunderfolder = functions::s2ws(thundersfolders1);
	LPCWSTR sssthunderfolder = ssthunderfolder.c_str();
	if (CreateDirectory(LPCWSTR_to_LPCSTR(sssthunderfolder), NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}
//void backgroundcustom() {
//	if (backgroundcustom) {
//#include <stdlib.h>
//		system("start explorer http://www.mediafire.com/file/ufdl2nkkpqa524l/Thunder.ytd");
//	}
//}
void discord() {
#include <stdlib.h>
	system("start https://discord.gg/8v9VevWs7S");
}

void newInjector() {
#include <stdlib.h>
	system("start http://www.mediafire.com/file/j931d3o5ha8b10y/Thunder-Menu.zip");
}

void CopyOutfit(Player player)
{
	for (int i = 0; i < 12; i++)
	{
		PED::SET_PED_COMPONENT_VARIATION(players[selfPlayer].ped, i, PED::GET_PED_DRAWABLE_VARIATION(players[player].ped, i), PED::GET_PED_TEXTURE_VARIATION(players[player].ped, i), PED::GET_PED_PALETTE_VARIATION(players[player].ped, i));
		for (int i = 0; i < 2; i++) {
			WAIT(0);
		}
	}
}
void JoinCrew2(Player player)
{
	int clanId;
	int desc;
	NETWORK::NETWORK_CLAN_PLAYER_GET_DESC(&desc, 35, &clanId);
	if (NETWORK::NETWORK_CLAN_JOIN(clanId)) {
		NETWORK::NETWORK_CLAN_JOIN(clanId);
	}
}

bool Features::pedhornboostbool;
void Features::pedhornboost()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle* vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(vehs[OffsetID]);
		if (AUDIO::IS_HORN_ACTIVE(vehs[OffsetID]) && vehs[OffsetID] != PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false))
		{
			VEHICLE::SET_VEHICLE_FORWARD_SPEED(vehs[OffsetID], 100.f);
		}
	}
	delete[] vehs;
}

bool Features::hornhavocbool;
void Features::hornhavoc()
{
	const int ElementAmount = 10;
	const int ArrSize = ElementAmount * 2 + 2;

	Vehicle* vehs = new Vehicle[ArrSize];
	vehs[0] = ElementAmount;
	int VehFound = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), vehs);

	for (int i = 0; i < VehFound; i++)
	{
		int OffsetID = i * 2 + 2;
		RequestControlOfEnt(vehs[OffsetID]);
		AUDIO::_SOUND_VEHICLE_HORN_THIS_FRAME(vehs[OffsetID]);
	}
	delete[] vehs;
}
void Vehiclee::Walldrive() //void coding
{
	int ped = PLAYER::PLAYER_PED_ID();
	int veh = PED::GET_VEHICLE_PED_IS_IN(ped, true);
	if (PED::IS_PED_IN_VEHICLE(ped, veh, true))
	{
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0, 0, -0.4, 0, 0, 0, 1, true, true, true, true, true);
	}
}

void RestrictedArea(Player Ped) {
	/*Any args[5] = { 526, 0, Features::Online::selectedPlayer, 0, Features::Online::selectedPlayer };*/
	int args[5] = { 526, 0, Features::Online::selectedPlayer, 0, Features::Online::selectedPlayer };
	int playerId;
	GAMEPLAY::SET_BIT(&playerId, Features::Online::selectedPlayer);
	Hooking::trigger_script_event(0x0, args, 5, playerId, 526);
	GAMEPLAY::CLEAR_BIT(&playerId, Features::Online::selectedPlayer);
}

void Vehiclee::NativeHandler()
{
}
void Vehiclee::ScriptEngine()
{
}

Object SpawnObject(char* name, Vector3 coords) {
	Vector3 pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	//	Object obj = CREATE_OBJECT_NO_OFFSET(GET_HASH_KEY(name), coords.x, coords.y, coords.z, 1, 0, 0);
	/*float obj = OBJECT::CREATE_OBJECT(HASH::GET_HASH_KEY(name), pos.x, pos.y, pos.z, true, 1, 0);*/
	float obj = OBJECT::CREATE_OBJECT_NO_OFFSET(HASH::GET_HASH_KEY(name), pos.x, pos.y, pos.z, true, 1, 0);
	return obj;
}
void AttachThingToThing(Any p0, Any p1, float x = 0, float y = 0, float z = 0, float rx = 0, float ry = 0, float rz = 0) {
	//ATTACH_ENTITY_TO_ENTITY(p0, p1, 0, -0.5f, -0.2f, -0.1f, 0.0f, 0.0f, 180.0f, 1, 0, 0, 2, 1, 1);
	ENTITY::ATTACH_ENTITY_TO_ENTITY(p0, p1, 0, x, y, z, rx, ry, rz, 1, 0, 0, 2, 1, 1);
}
int Levels[8000] = { 0, 800, 2100, 3800, 6100, 9500, 12500, 16000, 19800, 24000, 28500, 33400, 38700, 44200, 50200, 56400, 63000, 69900, 77100, 84700, 92500, 100700, 109200, 118000, 127100, 136500, 146200,
156200, 166500, 177100, 188000, 199200, 210700, 222400, 234500, 246800, 259400, 272300, 285500, 299000, 312700, 326800, 341000, 355600, 370500, 385600, 401000, 416600, 432600, 448800, 465200, 482000, 499000,
516300, 533800, 551600, 569600, 588000, 606500, 625400, 644500, 663800, 683400, 703300, 723400, 743800, 764500, 785400, 806500, 827900, 849600, 871500, 893600, 916000, 938700, 961600, 984700, 1008100, 1031800,
1055700, 1079800, 1104200, 1128800, 1153700, 1178800, 1204200, 1229800, 1255600, 1281700, 1308100, 1334600, 1361400, 1388500, 1415800, 1443300, 1471100, 1499100, 1527300, 1555800, 1584350, 1612950, 1641600,
1670300, 1699050, 1727850, 1756700, 1785600, 1814550, 1843550, 1872600, 1901700, 1930850, 1960050, 1989300, 2018600, 2047950, 2077350, 2106800, 2136300, 2165850, 2195450, 2225100, 2254800, 2284550, 2314350,
2344200, 2374100, 2404050, 2434050, 2464100, 2494200, 2524350, 2554550, 2584800, 2615100, 2645450, 2675850, 2706300, 2736800, 2767350, 2797950, 2828600, 2859300, 2890050, 2920850, 2951700, 2982600, 3013550,
3044550, 3075600, 3106700, 3137850, 3169050, 3200300, 3231600, 3262950, 3294350, 3325800, 3357300, 3388850, 3420450, 3452100, 3483800, 3515550, 3547350, 3579200, 3611100, 3643050, 3675050, 3707100, 3739200,
3771350, 3803550, 3835800, 3868100, 3900450, 3932850, 3965300, 3997800, 4030350, 4062950, 4095600, 4128300, 4161050, 4193850, 4226700, 4259600, 4292550, 4325550, 4358600, 4391700, 4424850, 4458050, 4491300,
4524600, 4557950, 4591350, 4624800, 4658300, 4691850, 4725450, 4759100, 4792800, 4826550, 4860350, 4894200, 4928100, 4962050, 4996050, 5030100, 5064200, 5098350, 5132550, 5166800, 5201100, 5235450, 5269850,
5304300, 5338800, 5373350, 5407950, 5442600, 5477300, 5512050, 5546850, 5581700, 5616600, 5651550, 5686550, 5721600, 5756700, 5791850, 5827050, 5862300, 5897600, 5932950, 5968350, 6003800, 6039300, 6074850,
6110450, 6146100, 6181800, 6217550, 6253350, 6289200, 6325100, 6361050, 6397050, 6433100, 6469200, 6505350, 6541550, 6577800, 6614100, 6650450, 6686850, 6723300, 6759800, 6796350, 6832950, 6869600, 6906300,
6943050, 6979850, 7016700, 7053600, 7090550, 7127550, 7164600, 7201700, 7238850, 7276050, 7313300, 7350600, 7387950, 7425350, 7462800, 7500300, 7537850, 7575450, 7613100, 7650800, 7688550, 7726350, 7764200,
7802100, 7840050, 7878050, 7916100, 7954200, 7992350, 8030550, 8068800, 8107100, 8145450, 8183850, 8222300, 8260800, 8299350, 8337950, 8376600, 8415300, 8454050, 8492850, 8531700, 8570600, 8609550, 8648550,
8687600, 8726700, 8765850, 8805050, 8844300, 8883600, 8922950, 8962350, 9001800, 9041300, 9080850, 9120450, 9160100, 9199800, 9239550, 9279350, 9319200, 9359100, 9399050, 9439050, 9479100, 9519200, 9559350,
9599550, 9639800, 9680100, 9720450, 9760850, 9801300, 9841800, 9882350, 9922950, 9963600, 10004300, 10045050, 10085850, 10126700, 10167600, 10208550, 10249550, 10290600, 10331700, 10372850, 10414050, 10455300,
10496600, 10537950, 10579350, 10620800, 10662300, 10703850, 10745450, 10787100, 10828800, 10870550, 10912350, 10954200, 10996100, 11038050, 11080050, 11122100, 11164200, 11206350, 11248550, 11290800, 11333100,
11375450, 11417850, 11460300, 11502800, 11545350, 11587950, 11630600, 11673300, 11716050, 11758850, 11801700, 11844600, 11887550, 11930550, 11973600, 12016700, 12059850, 12103050, 12146300, 12189600, 12232950,
12276350, 12319800, 12363300, 12406850, 12450450, 12494100, 12537800, 12581550, 12625350, 12669200, 12713100, 12757050, 12801050, 12845100, 12889200, 12933350, 12977550, 13021800, 13066100, 13110450, 13154850,
13199300, 13243800, 13288350, 13332950, 13377600, 13422300, 13467050, 13511850, 13556700, 13601600, 13646550, 13691550, 13736600, 13781700, 13826850, 13872050, 13917300, 13962600, 14007950, 14053350, 14098800,
14144300, 14189850, 14235450, 14281100, 14326800, 14372550, 14418350, 14464200, 14510100, 14556050, 14602050, 14648100, 14694200, 14740350, 14786550, 14832800, 14879100, 14925450, 14971850, 15018300, 15064800,
15111350, 15157950, 15204600, 15251300, 15298050, 15344850, 15391700, 15438600, 15485550, 15532550, 15579600, 15626700, 15673850, 15721050, 15768300, 15815600, 15862950, 15910350, 15957800, 16005300, 16052850,
16100450, 16148100, 16195800, 16243550, 16291350, 16339200, 16387100, 16435050, 16483050, 16531100, 16579200, 16627350, 16675550, 16723800, 16772100, 16820450, 16868850, 16917300, 16965800, 17014350, 17062950,
17111600, 17160300, 17209050, 17257850, 17306700, 17355600, 17404550, 17453550, 17502600, 17551700, 17600850, 17650050, 17699300, 17748600, 17797950, 17847350, 17896800, 17946300, 17995850, 18045450, 18095100,
18144800, 18194550, 18244350, 18294200, 18344100, 18394050, 18444050, 18494100, 18544200, 18594350, 18644550, 18694800, 18745100, 18795450, 18845850, 18896300, 18946800, 18997350, 19047950, 19098600, 19149300,
19200050, 19250850, 19301700, 19352600, 19403550, 19454550, 19505600, 19556700, 19607850, 19659050, 19710300, 19761600, 19812950, 19864350, 19915800, 19967300, 20018850, 20070450, 20122100, 20173800, 20225550,
20277350, 20329200, 20381100, 20433050, 20485050, 20537100, 20589200, 20641350, 20693550, 20745800, 20798100, 20850450, 20902850, 20955300, 21007800, 21060350, 21112950, 21165600, 21218300, 21271050, 21323850,
21376700, 21429600, 21482550, 21535550, 21588600, 21641700, 21694850, 21748050, 21801300, 21854600, 21907950, 21961350, 22014800, 22068300, 22121850, 22175450, 22229100, 22282800, 22336550, 22390350, 22444200,
22498100, 22552050, 22606050, 22660100, 22714200, 22768350, 22822550, 22876800, 22931100, 22985450, 23039850, 23094300, 23148800, 23203350, 23257950, 23312600, 23367300, 23422050, 23476850, 23531700, 23586600,
23641550, 23696550, 23751600, 23806700, 23861850, 23917050, 23972300, 24027600, 24082950, 24138350, 24193800, 24249300, 24304850, 24360450, 24416100, 24471800, 24527550, 24583350, 24639200, 24695100, 24751050,
24807050, 24863100, 24919200, 24975350, 25031550, 25087800, 25144100, 25200450, 25256850, 25313300, 25369800, 25426350, 25482950, 25539600, 25596300, 25653050, 25709850, 25766700, 25823600, 25880550, 25937550,
25994600, 26051700, 26108850, 26166050, 26223300, 26280600, 26337950, 26395350, 26452800, 26510300, 26567850, 26625450, 26683100, 26740800, 26798550, 26856350, 26914200, 26972100, 27030050, 27088050, 27146100,
27204200, 27262350, 27320550, 27378800, 27437100, 27495450, 27553850, 27612300, 27670800, 27729350, 27787950, 27846600, 27905300, 27964050, 28022850, 28081700, 28140600, 28199550, 28258550, 28317600, 28376700,
28435850, 28495050, 28554300, 28613600, 28672950, 28732350, 28791800, 28851300, 28910850, 28970450, 29030100, 29089800, 29149550, 29209350, 29269200, 29329100, 29389050, 29449050, 29509100, 29569200, 29629350,
29689550, 29749800, 29810100, 29870450, 29930850, 29991300, 30051800, 30112350, 30172950, 30233600, 30294300, 30355050, 30415850, 30476700, 30537600, 30598550, 30659550, 30720600, 30781700, 30842850, 30904050,
30965300, 31026600, 31087950, 31149350, 31210800, 31272300, 31333850, 31395450, 31457100, 31518800, 31580550, 31642350, 31704200, 31766100, 31828050, 31890050, 31952100, 32014200, 32076350, 32138550, 32200800,
32263100, 32325450, 32387850, 32450300, 32512800, 32575350, 32637950, 32700600, 32763300, 32826050, 32888850, 32951700, 33014600, 33077550, 33140550, 33203600, 33266700, 33329850, 33393050, 33456300, 33519600,
33582950, 33646350, 33709800, 33773300, 33836850, 33900450, 33964100, 34027800, 34091550, 34155350, 34219200, 34283100, 34347050, 34411050, 34475100, 34539200, 34603350, 34667550, 34731800, 34796100, 34860450,
34924850, 34989300, 35053800, 35118350, 35182950, 35247600, 35312300, 35377050, 35441850, 35506700, 35571600, 35636550, 35701550, 35766600, 35831700, 35896850, 35962050, 36027300, 36092600, 36157950, 36223350,
36288800, 36354300, 36419850, 36485450, 36551100, 36616800, 36682550, 36748350, 36814200, 36880100, 36946050, 37012050, 37078100, 37144200, 37210350, 37276550, 37342800, 37409100, 37475450, 37541850, 37608300,
37674800, 37741350, 37807950, 37874600, 37941300, 38008050, 38074850, 38141700, 38208600, 38275550, 38342550, 38409600, 38476700, 38543850, 38611050, 38678300, 38745600, 38812950, 38880350, 38947800, 39015300,
39082850, 39150450, 39218100, 39285800, 39353550, 39421350, 39489200, 39557100, 39625050, 39693050, 39761100, 39829200, 39897350, 39965550, 40033800, 40102100, 40170450, 40238850, 40307300, 40375800, 40444350,
40512950, 40581600, 40650300, 40719050, 40787850, 40856700, 40925600, 40994550, 41063550, 41132600, 41201700, 41270850, 41340050, 41409300, 41478600, 41547950, 41617350, 41686800, 41756300, 41825850, 41895450,
41965100, 42034800, 42104550, 42174350, 42244200, 42314100, 42384050, 42454050, 42524100, 42594200, 42664350, 42734550, 42804800, 42875100, 42945450, 43015850, 43086300, 43156800, 43227350, 43297950, 43368600,
43439300, 43510050, 43580850, 43651700, 43722600, 43793550, 43864550, 43935600, 44006700, 44077850, 44149050, 44220300, 44291600, 44362950, 44434350, 44505800, 44577300, 44648850, 44720450, 44792100, 44863800,
44935550, 45007350, 45079200, 45151100, 45223050, 45295050, 45367100, 45439200, 45511350, 45583550, 45655800, 45728100, 45800450, 45872850, 45945300, 46017800, 46090350, 46162950, 46235600, 46308300, 46381050,
46453850, 46526700, 46599600, 46672550, 46745550, 46818600, 46891700, 46964850, 47038050, 47111300, 47184600, 47257950, 47331350, 47404800, 47478300, 47551850, 47625450, 47699100, 47772800, 47846550, 47920350,
47994200, 48068100, 48142050, 48216050, 48290100, 48364200, 48438350, 48512550, 48586800, 48661100, 48735450, 48809850, 48884300, 48958800, 49033350, 49107950, 49182600, 49257300, 49332050, 49406850, 49481700,
49556600, 49631550, 49706550, 49781600, 49856700, 49931850, 50007050, 50082300, 50157600, 50232950, 50308350, 50383800, 50459300, 50534850, 50610450, 50686100, 50761800, 50837550, 50913350, 50989200, 51065100,
51141050, 51217050, 51293100, 51369200, 51445350, 51521550, 51597800, 51674100, 51750450, 51826850, 51903300, 51979800, 52056350, 52132950, 52209600, 52286300, 52363050, 52439850, 52516700, 52593600, 52670550,
52747550, 52824600, 52901700, 52978850, 53056050, 53133300, 53210600, 53287950, 53365350, 53442800, 53520300, 53597850, 53675450, 53753100, 53830800, 53908550, 53986350, 54064200, 54142100, 54220050, 54298050,
54376100, 54454200, 54532350, 54610550, 54688800, 54767100, 54845450, 54923850, 55002300, 55080800, 55159350, 55237950, 55316600, 55395300, 55474050, 55552850, 55631700, 55710600, 55789550, 55868550, 55947600,
56026700, 56105850, 56185050, 56264300, 56343600, 56422950, 56502350, 56581800, 56661300, 56740850, 56820450, 56900100, 56979800, 57059550, 57139350, 57219200, 57299100, 57379050, 57459050, 57539100, 57619200,
57699350, 57779550, 57859800, 57940100, 58020450, 58100850, 58181300, 58261800, 58342350, 58422950, 58503600, 58584300, 58665050, 58745850, 58826700, 58907600, 58988550, 59069550, 59150600, 59231700, 59312850,
59394050, 59475300, 59556600, 59637950, 59719350, 59800800, 59882300, 59963850, 60045450, 60127100, 60208800, 60290550, 60372350, 60454200, 60536100, 60618050, 60700050, 60782100, 60864200, 60946350, 61028550,
61110800, 61193100, 61275450, 61357850, 61440300, 61522800, 61605350, 61687950, 61770600, 61853300, 61936050, 62018850, 62101700, 62184600, 62267550, 62350550, 62433600, 62516700, 62599850, 62683050, 62766300,
62849600, 62932950, 63016350, 63099800, 63183300, 63266850, 63350450, 63434100, 63517800, 63601550, 63685350, 63769200, 63853100, 63937050, 64021050, 64105100, 64189200, 64273350, 64357550, 64441800, 64526100,
64610450, 64694850, 64779300, 64863800, 64948350, 65032950, 65117600, 65202300, 65287050, 65371850, 65456700, 65541600, 65626550, 65711550, 65796600, 65881700, 65966850, 66052050, 66137300, 66222600, 66307950,
66393350, 66478800, 66564300, 66649850, 66735450, 66821100, 66906800, 66992550, 67078350, 67164200, 67250100, 67336050, 67422050, 67508100, 67594200, 67680350, 67766550, 67852800, 67939100, 68025450, 68111850,
68198300, 68284800, 68371350, 68457950, 68544600, 68631300, 68718050, 68804850, 68891700, 68978600, 69065550, 69152550, 69239600, 69326700, 69413850, 69501050, 69588300, 69675600, 69762950, 69850350, 69937800,
70025300, 70112850, 70200450, 70288100, 70375800, 70463550, 70551350, 70639200, 70727100, 70815050, 70903050, 70991100, 71079200, 71167350, 71255550, 71343800, 71432100, 71520450, 71608850, 71697300, 71785800,
71874350, 71962950, 72051600, 72140300, 72229050, 72317850, 72406700, 72495600, 72584550, 72673550, 72762600, 72851700, 72940850, 73030050, 73119300, 73208600, 73297950, 73387350, 73476800, 73566300, 73655850,
73745450, 73835100, 73924800, 74014550, 74104350, 74194200, 74284100, 74374050, 74464050, 74554100, 74644200, 74734350, 74824550, 74914800, 75005100, 75095450, 75185850, 75276300, 75366800, 75457350, 75547950,
75638600, 75729300, 75820050, 75910850, 76001700, 76092600, 76183550, 76274550, 76365600, 76456700, 76547850, 76639050, 76730300, 76821600, 76912950, 77004350, 77095800, 77187300, 77278850, 77370450, 77462100,
77553800, 77645550, 77737350, 77829200, 77921100, 78013050, 78105050, 78197100, 78289200, 78381350, 78473550, 78565800, 78658100, 78750450, 78842850, 78935300, 79027800, 79120350, 79212950, 79305600, 79398300,
79491050, 79583850, 79676700, 79769600, 79862550, 79955550, 80048600, 80141700, 80234850, 80328050, 80421300, 80514600, 80607950, 80701350, 80794800, 80888300, 80981850, 81075450, 81169100, 81262800, 81356550,
81450350, 81544200, 81638100, 81732050, 81826050, 81920100, 82014200, 82108350, 82202550, 82296800, 82391100, 82485450, 82579850, 82674300, 82768800, 82863350, 82957950, 83052600, 83147300, 83242050, 83336850,
83431700, 83526600, 83621550, 83716550, 83811600, 83906700, 84001850, 84097050, 84192300, 84287600, 84382950, 84478350, 84573800, 84669300, 84764850, 84860450, 84956100, 85051800, 85147550, 85243350, 85339200,
85435100, 85531050, 85627050, 85723100, 85819200, 85915350, 86011550, 86107800, 86204100, 86300450, 86396850, 86493300, 86589800, 86686350, 86782950, 86879600, 86976300, 87073050, 87169850, 87266700, 87363600,
87460550, 87557550, 87654600, 87751700, 87848850, 87946050, 88043300, 88140600, 88237950, 88335350, 88432800, 88530300, 88627850, 88725450, 88823100, 88920800, 89018550, 89116350, 89214200, 89312100, 89410050,
89508050, 89606100, 89704200, 89802350, 89900550, 89998800, 90097100, 90195450, 90293850, 90392300, 90490800, 90589350, 90687950, 90786600, 90885300, 90984050, 91082850, 91181700, 91280600, 91379550, 91478550,
91577600, 91676700, 91775850, 91875050, 91974300, 92073600, 92172950, 92272350, 92371800, 92471300, 92570850, 92670450, 92770100, 92869800, 92969550, 93069350, 93169200, 93269100, 93369050, 93469050, 93569100,
93669200, 93769350, 93869550, 93969800, 94070100, 94170450, 94270850, 94371300, 94471800, 94572350, 94672950, 94773600, 94874300, 94975050, 95075850, 95176700, 95277600, 95378550, 95479550, 95580600, 95681700,
95782850, 95884050, 95985300, 96086600, 96187950, 96289350, 96390800, 96492300, 96593850, 96695450, 96797100, 96898800, 97000550, 97102350, 97204200, 97306100, 97408050, 97510050, 97612100, 97714200, 97816350,
97918550, 98020800, 98123100, 98225450, 98327850, 98430300, 98532800, 98635350, 98737950, 98840600, 98943300, 99046050, 99148850, 99251700, 99354600, 99457550, 99560550, 99663600, 99766700, 99869850, 99973050,
100076300, 100179600, 100282950, 100386350, 100489800, 100593300, 100696850, 100800450, 100904100, 101007800, 101111550, 101215350, 101319200, 101423100, 101527050, 101631050, 101735100, 101839200, 101943350,
102047550, 102151800, 102256100, 102360450, 102464850, 102569300, 102673800, 102778350, 102882950, 102987600, 103092300, 103197050, 103301850, 103406700, 103511600, 103616550, 103721550, 103826600, 103931700,
104036850, 104142050, 104247300, 104352600, 104457950, 104563350, 104668800, 104774300, 104879850, 104985450, 105091100, 105196800, 105302550, 105408350, 105514200, 105620100, 105726050, 105832050, 105938100,
106044200, 106150350, 106256550, 106362800, 106469100, 106575450, 106681850, 106788300, 106894800, 107001350, 107107950, 107214600, 107321300, 107428050, 107534850, 107641700, 107748600, 107855550, 107962550,
108069600, 108176700, 108283850, 108391050, 108498300, 108605600, 108712950, 108820350, 108927800, 109035300, 109142850, 109250450, 109358100, 109465800, 109573550, 109681350, 109789200, 109897100, 110005050,
110113050, 110221100, 110329200, 110437350, 110545550, 110653800, 110762100, 110870450, 110978850, 111087300, 111195800, 111304350, 111412950, 111521600, 111630300, 111739050, 111847850, 111956700, 112065600,
112174550, 112283550, 112392600, 112501700, 112610850, 112720050, 112829300, 112938600, 113047950, 113157350, 113266800, 113376300, 113485850, 113595450, 113705100, 113814800, 113924550, 114034350, 114144200,
114254100, 114364050, 114474050, 114584100, 114694200, 114804350, 114914550, 115024800, 115135100, 115245450, 115355850, 115466300, 115576800, 115687350, 115797950, 115908600, 116019300, 116130050, 116240850,
116351700, 116462600, 116573550, 116684550, 116795600, 116906700, 117017850, 117129050, 117240300, 117351600, 117462950, 117574350, 117685800, 117797300, 117908850, 118020450, 118132100, 118243800, 118355550,
118467350, 118579200, 118691100, 118803050, 118915050, 119027100, 119139200, 119251350, 119363550, 119475800, 119588100, 119700450, 119812850, 119925300, 120037800, 120150350, 120262950, 120375600, 120488300,
120601050, 120713850, 120826700, 120939600, 121052550, 121165550, 121278600, 121391700, 121504850, 121618050, 121731300, 121844600, 121957950, 122071350, 122184800, 122298300, 122411850, 122525450, 122639100,
122752800, 122866550, 122980350, 123094200, 123208100, 123322050, 123436050, 123550100, 123664200, 123778350, 123892550, 124006800, 124121100, 124235450, 124349850, 124464300, 124578800, 124693350, 124807950,
124922600, 125037300, 125152050, 125266850, 125381700, 125496600, 125611550, 125726550, 125841600, 125956700, 126071850, 126187050, 126302300, 126417600, 126532950, 126648350, 126763800, 126879300, 126994850,
127110450, 127226100, 127341800, 127457550, 127573350, 127689200, 127805100, 127921050, 128037050, 128153100, 128269200, 128385350, 128501550, 128617800, 128734100, 128850450, 128966850, 129083300, 129199800,
129316350, 129432950, 129549600, 129666300, 129783050, 129899850, 130016700, 130133600, 130250550, 130367550, 130484600, 130601700, 130718850, 130836050, 130953300, 131070600, 131187950, 131305350, 131422800,
131540300, 131657850, 131775450, 131893100, 132010800, 132128550, 132246350, 132364200, 132482100, 132600050, 132718050, 132836100, 132954200, 133072350, 133190550, 133308800, 133427100, 133545450, 133663850,
133782300, 133900800, 134019350, 134137950, 134256600, 134375300, 134494050, 134612850, 134731700, 134850600, 134969550, 135088550, 135207600, 135326700, 135445850, 135565050, 135684300, 135803600, 135922950,
136042350, 136161800, 136281300, 136400850, 136520450, 136640100, 136759800, 136879550, 136999350, 137119200, 137239100, 137359050, 137479050, 137599100, 137719200, 137839350, 137959550, 138079800, 138200100,
138320450, 138440850, 138561300, 138681800, 138802350, 138922950, 139043600, 139164300, 139285050, 139405850, 139526700, 139647600, 139768550, 139889550, 140010600, 140131700, 140252850, 140374050, 140495300,
140616600, 140737950, 140859350, 140980800, 141102300, 141223850, 141345450, 141467100, 141588800, 141710550, 141832350, 141954200, 142076100, 142198050, 142320050, 142442100, 142564200, 142686350, 142808550,
142930800, 143053100, 143175450, 143297850, 143420300, 143542800, 143665350, 143787950, 143910600, 144033300, 144156050, 144278850, 144401700, 144524600, 144647550, 144770550, 144893600, 145016700, 145139850,
145263050, 145386300, 145509600, 145632950, 145756350, 145879800, 146003300, 146126850, 146250450, 146374100, 146497800, 146621550, 146745350, 146869200, 146993100, 147117050, 147241050, 147365100, 147489200,
147613350, 147737550, 147861800, 147986100, 148110450, 148234850, 148359300, 148483800, 148608350, 148732950, 148857600, 148982300, 149107050, 149231850, 149356700, 149481600, 149606550, 149731550, 149856600,
149981700, 150106850, 150232050, 150357300, 150482600, 150607950, 150733350, 150858800, 150984300, 151109850, 151235450, 151361100, 151486800, 151612550, 151738350, 151864200, 151990100, 152116050, 152242050,
152368100, 152494200, 152620350, 152746550, 152872800, 152999100, 153125450, 153251850, 153378300, 153504800, 153631350, 153757950, 153884600, 154011300, 154138050, 154264850, 154391700, 154518600, 154645550,
154772550, 154899600, 155026700, 155153850, 155281050, 155408300, 155535600, 155662950, 155790350, 155917800, 156045300, 156172850, 156300450, 156428100, 156555800, 156683550, 156811350, 156939200, 157067100,
157195050, 157323050, 157451100, 157579200, 157707350, 157835550, 157963800, 158092100, 158220450, 158348850, 158477300, 158605800, 158734350, 158862950, 158991600, 159120300, 159249050, 159377850, 159506700,
159635600, 159764550, 159893550, 160022600, 160151700, 160280850, 160410050, 160539300, 160668600, 160797950, 160927350, 161056800, 161186300, 161315850, 161445450, 161575100, 161704800, 161834550, 161964350,
162094200, 162224100, 162354050, 162484050, 162614100, 162744200, 162874350, 163004550, 163134800, 163265100, 163395450, 163525850, 163656300, 163786800, 163917350, 164047950, 164178600, 164309300, 164440050,
164570850, 164701700, 164832600, 164963550, 165094550, 165225600, 165356700, 165487850, 165619050, 165750300, 165881600, 166012950, 166144350, 166275800, 166407300, 166538850, 166670450, 166802100, 166933800,
167065550, 167197350, 167329200, 167461100, 167593050, 167725050, 167857100, 167989200, 168121350, 168253550, 168385800, 168518100, 168650450, 168782850, 168915300, 169047800, 169180350, 169312950, 169445600,
169578300, 169711050, 169843850, 169976700, 170109600, 170242550, 170375550, 170508600, 170641700, 170774850, 170908050, 171041300, 171174600, 171307950, 171441350, 171574800, 171708300, 171841850, 171975450,
172109100, 172242800, 172376550, 172510350, 172644200, 172778100, 172912050, 173046050, 173180100, 173314200, 173448350, 173582550, 173716800, 173851100, 173985450, 174119850, 174254300, 174388800, 174523350,
174657950, 174792600, 174927300, 175062050, 175196850, 175331700, 175466600, 175601550, 175736550, 175871600, 176006700, 176141850, 176277050, 176412300, 176547600, 176682950, 176818350, 176953800, 177089300,
177224850, 177360450, 177496100, 177631800, 177767550, 177903350, 178039200, 178175100, 178311050, 178447050, 178583100, 178719200, 178855350, 178991550, 179127800, 179264100, 179400450, 179536850, 179673300,
179809800, 179946350, 180082950, 180219600, 180356300, 180493050, 180629850, 180766700, 180903600, 181040550, 181177550, 181314600, 181451700, 181588850, 181726050, 181863300, 182000600, 182137950, 182275350,
182412800, 182550300, 182687850, 182825450, 182963100, 183100800, 183238550, 183376350, 183514200, 183652100, 183790050, 183928050, 184066100, 184204200, 184342350, 184480550, 184618800, 184757100, 184895450,
185033850, 185172300, 185310800, 185449350, 185587950, 185726600, 185865300, 186004050, 186142850, 186281700, 186420600, 186559550, 186698550, 186837600, 186976700, 187115850, 187255050, 187394300, 187533600,
187672950, 187812350, 187951800, 188091300, 188230850, 188370450, 188510100, 188649800, 188789550, 188929350, 189069200, 189209100, 189349050, 189489050, 189629100, 189769200, 189909350, 190049550, 190189800,
190330100, 190470450, 190610850, 190751300, 190891800, 191032350, 191172950, 191313600, 191454300, 191595050, 191735850, 191876700, 192017600, 192158550, 192299550, 192440600, 192581700, 192722850, 192864050,
193005300, 193146600, 193287950, 193429350, 193570800, 193712300, 193853850, 193995450, 194137100, 194278800, 194420550, 194562350, 194704200, 194846100, 194988050, 195130050, 195272100, 195414200, 195556350,
195698550, 195840800, 195983100, 196125450, 196267850, 196410300, 196552800, 196695350, 196837950, 196980600, 197123300, 197266050, 197408850, 197551700, 197694600, 197837550, 197980550, 198123600, 198266700,
198409850, 198553050, 198696300, 198839600, 198982950, 199126350, 199269800, 199413300, 199556850, 199700450, 199844100, 199987800, 200131550, 200275350, 200419200, 200563100, 200707050, 200851050, 200995100,
201139200, 201283350, 201427550, 201571800, 201716100, 201860450, 202004850, 202149300, 202293800, 202438350, 202582950, 202727600, 202872300, 203017050, 203161850, 203306700, 203451600, 203596550, 203741550,
203886600, 204031700, 204176850, 204322050, 204467300, 204612600, 204757950, 204903350, 205048800, 205194300, 205339850, 205485450, 205631100, 205776800, 205922550, 206068350, 206214200, 206360100, 206506050,
206652050, 206798100, 206944200, 207090350, 207236550, 207382800, 207529100, 207675450, 207821850, 207968300, 208114800, 208261350, 208407950, 208554600, 208701300, 208848050, 208994850, 209141700, 209288600,
209435550, 209582550, 209729600, 209876700, 210023850, 210171050, 210318300, 210465600, 210612950, 210760350, 210907800, 211055300, 211202850, 211350450, 211498100, 211645800, 211793550, 211941350, 212089200,
212237100, 212385050, 212533050, 212681100, 212829200, 212977350, 213125550, 213273800, 213422100, 213570450, 213718850, 213867300, 214015800, 214164350, 214312950, 214461600, 214610300, 214759050, 214907850,
215056700, 215205600, 215354550, 215503550, 215652600, 215801700, 215950850, 216100050, 216249300, 216398600, 216547950, 216697350, 216846800, 216996300, 217145850, 217295450, 217445100, 217594800, 217744550,
217894350, 218044200, 218194100, 218344050, 218494050, 218644100, 218794200, 218944350, 219094550, 219244800, 219395100, 219545450, 219695850, 219846300, 219996800, 220147350, 220297950, 220448600, 220599300,
220750050, 220900850, 221051700, 221202600, 221353550, 221504550, 221655600, 221806700, 221957850, 222109050, 222260300, 222411600, 222562950, 222714350, 222865800, 223017300, 223168850, 223320450, 223472100,
223623800, 223775550, 223927350, 224079200, 224231100, 224383050, 224535050, 224687100, 224839200, 224991350, 225143550, 225295800, 225448100, 225600450, 225752850, 225905300, 226057800, 226210350, 226362950,
226515600, 226668300, 226821050, 226973850, 227126700, 227279600, 227432550, 227585550, 227738600, 227891700, 228044850, 228198050, 228351300, 228504600, 228657950, 228811350, 228964800, 229118300, 229271850,
229425450, 229579100, 229732800, 229886550, 230040350, 230194200, 230348100, 230502050, 230656050, 230810100, 230964200, 231118350, 231272550, 231426800, 231581100, 231735450, 231889850, 232044300, 232198800,
232353350, 232507950, 232662600, 232817300, 232972050, 233126850, 233281700, 233436600, 233591550, 233746550, 233901600, 234056700, 234211850, 234367050, 234522300, 234677600, 234832950, 234988350, 235143800,
235299300, 235454850, 235610450, 235766100, 235921800, 236077550, 236233350, 236389200, 236545100, 236701050, 236857050, 237013100, 237169200, 237325350, 237481550, 237637800, 237794100, 237950450, 238106850,
238263300, 238419800, 238576350, 238732950, 238889600, 239046300, 239203050, 239359850, 239516700, 239673600, 239830550, 239987550, 240144600, 240301700, 240458850, 240616050, 240773300, 240930600, 241087950,
241245350, 241402800, 241560300, 241717850, 241875450, 242033100, 242190800, 242348550, 242506350, 242664200, 242822100, 242980050, 243138050, 243296100, 243454200, 243612350, 243770550, 243928800, 244087100,
244245450, 244403850, 244562300, 244720800, 244879350, 245037950, 245196600, 245355300, 245514050, 245672850, 245831700, 245990600, 246149550, 246308550, 246467600, 246626700, 246785850, 246945050, 247104300,
247263600, 247422950, 247582350, 247741800, 247901300, 248060850, 248220450, 248380100, 248539800, 248699550, 248859350, 249019200, 249179100, 249339050, 249499050, 249659100, 249819200, 249979350, 250139550,
250299800, 250460100, 250620450, 250780850, 250941300, 251101800, 251262350, 251422950, 251583600, 251744300, 251905050, 252065850, 252226700, 252387600, 252548550, 252709550, 252870600, 253031700, 253192850,
253354050, 253515300, 253676600, 253837950, 253999350, 254160800, 254322300, 254483850, 254645450, 254807100, 254968800, 255130550, 255292350, 255454200, 255616100, 255778050, 255940050, 256102100, 256264200,
256426350, 256588550, 256750800, 256913100, 257075450, 257237850, 257400300, 257562800, 257725350, 257887950, 258050600, 258213300, 258376050, 258538850, 258701700, 258864600, 259027550, 259190550, 259353600,
259516700, 259679850, 259843050, 260006300, 260169600, 260332950, 260496350, 260659800, 260823300, 260986850, 261150450, 261314100, 261477800, 261641550, 261805350, 261969200, 262133100, 262297050, 262461050,
262625100, 262789200, 262953350, 263117550, 263281800, 263446100, 263610450, 263774850, 263939300, 264103800, 264268350, 264432950, 264597600, 264762300, 264927050, 265091850, 265256700, 265421600, 265586550,
265751550, 265916600, 266081700, 266246850, 266412050, 266577300, 266742600, 266907950, 267073350, 267238800, 267404300, 267569850, 267735450, 267901100, 268066800, 268232550, 268398350, 268564200, 268730100,
268896050, 269062050, 269228100, 269394200, 269560350, 269726550, 269892800, 270059100, 270225450, 270391850, 270558300, 270724800, 270891350, 271057950, 271224600, 271391300, 271558050, 271724850, 271891700,
272058600, 272225550, 272392550, 272559600, 272726700, 272893850, 273061050, 273228300, 273395600, 273562950, 273730350, 273897800, 274065300, 274232850, 274400450, 274568100, 274735800, 274903550, 275071350,
275239200, 275407100, 275575050, 275743050, 275911100, 276079200, 276247350, 276415550, 276583800, 276752100, 276920450, 277088850, 277257300, 277425800, 277594350, 277762950, 277931600, 278100300, 278269050,
278437850, 278606700, 278775600, 278944550, 279113550, 279282600, 279451700, 279620850, 279790050, 279959300, 280128600, 280297950, 280467350, 280636800, 280806300, 280975850, 281145450, 281315100, 281484800,
281654550, 281824350, 281994200, 282164100, 282334050, 282504050, 282674100, 282844200, 283014350, 283184550, 283354800, 283525100, 283695450, 283865850, 284036300, 284206800, 284377350, 284547950, 284718600,
284889300, 285060050, 285230850, 285401700, 285572600, 285743550, 285914550, 286085600, 286256700, 286427850, 286599050, 286770300, 286941600, 287112950, 287284350, 287455800, 287627300, 287798850, 287970450,
288142100, 288313800, 288485550, 288657350, 288829200, 289001100, 289173050, 289345050, 289517100, 289689200, 289861350, 290033550, 290205800, 290378100, 290550450, 290722850, 290895300, 291067800, 291240350,
291412950, 291585600, 291758300, 291931050, 292103850, 292276700, 292449600, 292622550, 292795550, 292968600, 293141700, 293314850, 293488050, 293661300, 293834600, 294007950, 294181350, 294354800, 294528300,
294701850, 294875450, 295049100, 295222800, 295396550, 295570350, 295744200, 295918100, 296092050, 296266050, 296440100, 296614200, 296788350, 296962550, 297136800, 297311100, 297485450, 297659850, 297834300,
298008800, 298183350, 298357950, 298532600, 298707300, 298882050, 299056850, 299231700, 299406600, 299581550, 299756550, 299931600, 300106700, 300281850, 300457050, 300632300, 300807600, 300982950, 301158350,
301333800, 301509300, 301684850, 301860450, 302036100, 302211800, 302387550, 302563350, 302739200, 302915100, 303091050, 303267050, 303443100, 303619200, 303795350, 303971550, 304147800, 304324100, 304500450,
304676850, 304853300, 305029800, 305206350, 305382950, 305559600, 305736300, 305913050, 306089850, 306266700, 306443600, 306620550, 306797550, 306974600, 307151700, 307328850, 307506050, 307683300, 307860600,
308037950, 308215350, 308392800, 308570300, 308747850, 308925450, 309103100, 309280800, 309458550, 309636350, 309814200, 309992100, 310170050, 310348050, 310526100, 310704200, 310882350, 311060550, 311238800,
311417100, 311595450, 311773850, 311952300, 312130800, 312309350, 312487950, 312666600, 312845300, 313024050, 313202850, 313381700, 313560600, 313739550, 313918550, 314097600, 314276700, 314455850, 314635050,
314814300, 314993600, 315172950, 315352350, 315531800, 315711300, 315890850, 316070450, 316250100, 316429800, 316609550, 316789350, 316969200, 317149100, 317329050, 317509050, 317689100, 317869200, 318049350,
318229550, 318409800, 318590100, 318770450, 318950850, 319131300, 319311800, 319492350, 319672950, 319853600, 320034300, 320215050, 320395850, 320576700, 320757600, 320938550, 321119550, 321300600, 321481700,
321662850, 321844050, 322025300, 322206600, 322387950, 322569350, 322750800, 322932300, 323113850, 323295450, 323477100, 323658800, 323840550, 324022350, 324204200, 324386100, 324568050, 324750050, 324932100,
325114200, 325296350, 325478550, 325660800, 325843100, 326025450, 326207850, 326390300, 326572800, 326755350, 326937950, 327120600, 327303300, 327486050, 327668850, 327851700, 328034600, 328217550, 328400550,
328583600, 328766700, 328949850, 329133050, 329316300, 329499600, 329682950, 329866350, 330049800, 330233300, 330416850, 330600450, 330784100, 330967800, 331151550, 331335350, 331519200, 331703100, 331887050,
332071050, 332255100, 332439200, 332623350, 332807550, 332991800, 333176100, 333360450, 333544850, 333729300, 333913800, 334098350, 334282950, 334467600, 334652300, 334837050, 335021850, 335206700, 335391600,
335576550, 335761550, 335946600, 336131700, 336316850, 336502050, 336687300, 336872600, 337057950, 337243350, 337428800, 337614300, 337799850, 337985450, 338171100, 338356800, 338542550, 338728350, 338914200,
339100100, 339286050, 339472050, 339658100, 339844200, 340030350, 340216550, 340402800, 340589100, 340775450, 340961850, 341148300, 341334800, 341521350, 341707950, 341894600, 342081300, 342268050, 342454850,
342641700, 342828600, 343015550, 343202550, 343389600, 343576700, 343763850, 343951050, 344138300, 344325600, 344512950, 344700350, 344887800, 345075300, 345262850, 345450450, 345638100, 345825800, 346013550,
346201350, 346389200, 346577100, 346765050, 346953050, 347141100, 347329200, 347517350, 347705550, 347893800, 348082100, 348270450, 348458850, 348647300, 348835800, 349024350, 349212950, 349401600, 349590300,
349779050, 349967850, 350156700, 350345600, 350534550, 350723550, 350912600, 351101700, 351290850, 351480050, 351669300, 351858600, 352047950, 352237350, 352426800, 352616300, 352805850, 352995450, 353185100,
353374800, 353564550, 353754350, 353944200, 354134100, 354324050, 354514050, 354704100, 354894200, 355084350, 355274550, 355464800, 355655100, 355845450, 356035850, 356226300, 356416800, 356607350, 356797950,
356988600, 357179300, 357370050, 357560850, 357751700, 357942600, 358133550, 358324550, 358515600, 358706700, 358897850, 359089050, 359280300, 359471600, 359662950, 359854350, 360045800, 360237300, 360428850,
360620450, 360812100, 361003800, 361195550, 361387350, 361579200, 361771100, 361963050, 362155050, 362347100, 362539200, 362731350, 362923550, 363115800, 363308100, 363500450, 363692850, 363885300, 364077800,
364270350, 364462950, 364655600, 364848300, 365041050, 365233850, 365426700, 365619600, 365812550, 366005550, 366198600, 366391700, 366584850, 366778050, 366971300, 367164600, 367357950, 367551350, 367744800,
367938300, 368131850, 368325450, 368519100, 368712800, 368906550, 369100350, 369294200, 369488100, 369682050, 369876050, 370070100, 370264200, 370458350, 370652550, 370846800, 371041100, 371235450, 371429850,
371624300, 371818800, 372013350, 372207950, 372402600, 372597300, 372792050, 372986850, 373181700, 373376600, 373571550, 373766550, 373961600, 374156700, 374351850, 374547050, 374742300, 374937600, 375132950,
375328350, 375523800, 375719300, 375914850, 376110450, 376306100, 376501800, 376697550, 376893350, 377089200, 377285100, 377481050, 377677050, 377873100, 378069200, 378265350, 378461550, 378657800, 378854100,
379050450, 379246850, 379443300, 379639800, 379836350, 380032950, 380229600, 380426300, 380623050, 380819850, 381016700, 381213600, 381410550, 381607550, 381804600, 382001700, 382198850, 382396050, 382593300,
382790600, 382987950, 383185350, 383382800, 383580300, 383777850, 383975450, 384173100, 384370800, 384568550, 384766350, 384964200, 385162100, 385360050, 385558050, 385756100, 385954200, 386152350, 386350550,
386548800, 386747100, 386945450, 387143850, 387342300, 387540800, 387739350, 387937950, 388136600, 388335300, 388534050, 388732850, 388931700, 389130600, 389329550, 389528550, 389727600, 389926700, 390125850,
390325050, 390524300, 390723600, 390922950, 391122350, 391321800, 391521300, 391720850, 391920450, 392120100, 392319800, 392519550, 392719350, 392919200, 393119100, 393319050, 393519050, 393719100, 393919200,
394119350, 394319550, 394519800, 394720100, 394920450, 395120850, 395321300, 395521800, 395722350, 395922950, 396123600, 396324300, 396525050, 396725850, 396926700, 397127600, 397328550, 397529550, 397730600,
397931700, 398132850, 398334050, 398535300, 398736600, 398937950, 399139350, 399340800, 399542300, 399743850, 399945450, 400147100, 400348800, 400550550, 400752350, 400954200, 401156100, 401358050, 401560050,
401762100, 401964200, 402166350, 402368550, 402570800, 402773100, 402975450, 403177850, 403380300, 403582800, 403785350, 403987950, 404190600, 404393300, 404596050, 404798850, 405001700, 405204600, 405407550,
405610550, 405813600, 406016700, 406219850, 406423050, 406626300, 406829600, 407032950, 407236350, 407439800, 407643300, 407846850, 408050450, 408254100, 408457800, 408661550, 408865350, 409069200, 409273100,
409477050, 409681050, 409885100, 410089200, 410293350, 410497550, 410701800, 410906100, 411110450, 411314850, 411519300, 411723800, 411928350, 412132950, 412337600, 412542300, 412747050, 412951850, 413156700,
413361600, 413566550, 413771550, 413976600, 414181700, 414386850, 414592050, 414797300, 415002600, 415207950, 415413350, 415618800, 415824300, 416029850, 416235450, 416441100, 416646800, 416852550, 417058350,
417264200, 417470100, 417676050, 417882050, 418088100, 418294200, 418500350, 418706550, 418912800, 419119100, 419325450, 419531850, 419738300, 419944800, 420151350, 420357950, 420564600, 420771300, 420978050,
421184850, 421391700, 421598600, 421805550, 422012550, 422219600, 422426700, 422633850, 422841050, 423048300, 423255600, 423462950, 423670350, 423877800, 424085300, 424292850, 424500450, 424708100, 424915800,
425123550, 425331350, 425539200, 425747100, 425955050, 426163050, 426371100, 426579200, 426787350, 426995550, 427203800, 427412100, 427620450, 427828850, 428037300, 428245800, 428454350, 428662950, 428871600,
429080300, 429289050, 429497850, 429706700, 429915600, 430124550, 430333550, 430542600, 430751700, 430960850, 431170050, 431379300, 431588600, 431797950, 432007350, 432216800, 432426300, 432635850, 432845450,
433055100, 433264800, 433474550, 433684350, 433894200, 434104100, 434314050, 434524050, 434734100, 434944200, 435154350, 435364550, 435574800, 435785100, 435995450, 436205850, 436416300, 436626800, 436837350,
437047950, 437258600, 437469300, 437680050, 437890850, 438101700, 438312600, 438523550, 438734550, 438945600, 439156700, 439367850, 439579050, 439790300, 440001600, 440212950, 440424350, 440635800, 440847300,
441058850, 441270450, 441482100, 441693800, 441905550, 442117350, 442329200, 442541100, 442753050, 442965050, 443177100, 443389200, 443601350, 443813550, 444025800, 444238100, 444450450, 444662850, 444875300,
445087800, 445300350, 445512950, 445725600, 445938300, 446151050, 446363850, 446576700, 446789600, 447002550, 447215550, 447428600, 447641700, 447854850, 448068050, 448281300, 448494600, 448707950, 448921350,
449134800, 449348300, 449561850, 449775450, 449989100, 450202800, 450416550, 450630350, 450844200, 451058100, 451272050, 451486050, 451700100, 451914200, 452128350, 452342550, 452556800, 452771100, 452985450,
453199850, 453414300, 453628800, 453843350, 454057950, 454272600, 454487300, 454702050, 454916850, 455131700, 455346600, 455561550, 455776550, 455991600, 456206700, 456421850, 456637050, 456852300, 457067600,
457282950, 457498350, 457713800, 457929300, 458144850, 458360450, 458576100, 458791800, 459007550, 459223350, 459439200, 459655100, 459871050, 460087050, 460303100, 460519200, 460735350, 460951550, 461167800,
461384100, 461600450, 461816850, 462033300, 462249800, 462466350, 462682950, 462899600, 463116300, 463333050, 463549850, 463766700, 463983600, 464200550, 464417550, 464634600, 464851700, 465068850, 465286050,
465503300, 465720600, 465937950, 466155350, 466372800, 466590300, 466807850, 467025450, 467243100, 467460800, 467678550, 467896350, 468114200, 468332100, 468550050, 468768050, 468986100, 469204200, 469422350,
469640550, 469858800, 470077100, 470295450, 470513850, 470732300, 470950800, 471169350, 471387950, 471606600, 471825300, 472044050, 472262850, 472481700, 472700600, 472919550, 473138550, 473357600, 473576700,
473795850, 474015050, 474234300, 474453600, 474672950, 474892350, 475111800, 475331300, 475550850, 475770450, 475990100, 476209800, 476429550, 476649350, 476869200, 477089100, 477309050, 477529050, 477749100,
477969200, 478189350, 478409550, 478629800, 478850100, 479070450, 479290850, 479511300, 479731800, 479952350, 480172950, 480393600, 480614300, 480835050, 481055850, 481276700, 481497600, 481718550, 481939550,
482160600, 482381700, 482602850, 482824050, 483045300, 483266600, 483487950, 483709350, 483930800, 484152300, 484373850, 484595450, 484817100, 485038800, 485260550, 485482350, 485704200, 485926100, 486148050,
486370050, 486592100, 486814200, 487036350, 487258550, 487480800, 487703100, 487925450, 488147850, 488370300, 488592800, 488815350, 489037950, 489260600, 489483300, 489706050, 489928850, 490151700, 490374600,
490597550, 490820550, 491043600, 491266700, 491489850, 491713050, 491936300, 492159600, 492382950, 492606350, 492829800, 493053300, 493276850, 493500450, 493724100, 493947800, 494171550, 494395350, 494619200,
494843100, 495067050, 495291050, 495515100, 495739200, 495963350, 496187550, 496411800, 496636100, 496860450, 497084850, 497309300, 497533800, 497758350, 497982950, 498207600, 498432300, 498657050, 498881850,
499106700, 499331600, 499556550, 499781550, 500006600, 500231700, 500456850, 500682050, 500907300, 501132600, 501357950, 501583350, 501808800, 502034300, 502259850, 502485450, 502711100, 502936800, 503162550,
503388350, 503614200, 503840100, 504066050, 504292050, 504518100, 504744200, 504970350, 505196550, 505422800, 505649100, 505875450, 506101850, 506328300, 506554800, 506781350, 507007950, 507234600, 507461300,
507688050, 507914850, 508141700, 508368600, 508595550, 508822550, 509049600, 509276700, 509503850, 509731050, 509958300, 510185600, 510412950, 510640350, 510867800, 511095300, 511322850, 511550450, 511778100,
512005800, 512233550, 512461350, 512689200, 512917100, 513145050, 513373050, 513601100, 513829200, 514057350, 514285550, 514513800, 514742100, 514970450, 515198850, 515427300, 515655800, 515884350, 516112950,
516341600, 516570300, 516799050, 517027850, 517256700, 517485600, 517714550, 517943550, 518172600, 518401700, 518630850, 518860050, 519089300, 519318600, 519547950, 519777350, 520006800, 520236300, 520465850,
520695450, 520925100, 521154800, 521384550, 521614350, 521844200, 522074100, 522304050, 522534050, 522764100, 522994200, 523224350, 523454550, 523684800, 523915100, 524145450, 524375850, 524606300, 524836800,
525067350, 525297950, 525528600, 525759300, 525990050, 526220850, 526451700, 526682600, 526913550, 527144550, 527375600, 527606700, 527837850, 528069050, 528300300, 528531600, 528762950, 528994350, 529225800,
529457300, 529688850, 529920450, 530152100, 530383800, 530615550, 530847350, 531079200, 531311100, 531543050, 531775050, 532007100, 532239200, 532471350, 532703550, 532935800, 533168100, 533400450, 533632850,
533865300, 534097800, 534330350, 534562950, 534795600, 535028300, 535261050, 535493850, 535726700, 535959600, 536192550, 536425550, 536658600, 536891700, 537124850, 537358050, 537591300, 537824600, 538057950,
538291350, 538524800, 538758300, 538991850, 539225450, 539459100, 539692800, 539926550, 540160350, 540394200, 540628100, 540862050, 541096050, 541330100, 541564200, 541798350, 542032550, 542266800, 542501100,
542735450, 542969850, 543204300, 543438800, 543673350, 543907950, 544142600, 544377300, 544612050, 544846850, 545081700, 545316600, 545551550, 545786550, 546021600, 546256700, 546491850, 546727050, 546962300,
547197600, 547432950, 547668350, 547903800, 548139300, 548374850, 548610450, 548846100, 549081800, 549317550, 549553350, 549789200, 550025100, 550261050, 550497050, 550733100, 550969200, 551205350, 551441550,
551677800, 551914100, 552150450, 552386850, 552623300, 552859800, 553096350, 553332950, 553569600, 553806300, 554043050, 554279850, 554516700, 554753600, 554990550, 555227550, 555464600, 555701700, 555938850,
556176050, 556413300, 556650600, 556887950, 557125350, 557362800, 557600300, 557837850, 558075450, 558313100, 558550800, 558788550, 559026350, 559264200, 559502100, 559740050, 559978050, 560216100, 560454200,
560692350, 560930550, 561168800, 561407100, 561645450, 561883850, 562122300, 562360800, 562599350, 562837950, 563076600, 563315300, 563554050, 563792850, 564031700, 564270600, 564509550, 564748550, 564987600,
565226700, 565465850, 565705050, 565944300, 566183600, 566422950, 566662350, 566901800, 567141300, 567380850, 567620450, 567860100, 568099800, 568339550, 568579350, 568819200, 569059100, 569299050, 569539050,
569779100, 570019200, 570259350, 570499550, 570739800, 570980100, 571220450, 571460850, 571701300, 571941800, 572182350, 572422950, 572663600, 572904300, 573145050, 573385850, 573626700, 573867600, 574108550,
574349550, 574590600, 574831700, 575072850, 575314050, 575555300, 575796600, 576037950, 576279350, 576520800, 576762300, 577003850, 577245450, 577487100, 577728800, 577970550, 578212350, 578454200, 578696100,
578938050, 579180050, 579422100, 579664200, 579906350, 580148550, 580390800, 580633100, 580875450, 581117850, 581360300, 581602800, 581845350, 582087950, 582330600, 582573300, 582816050, 583058850, 583301700,
583544600, 583787550, 584030550, 584273600, 584516700, 584759850, 585003050, 585246300, 585489600, 585732950, 585976350, 586219800, 586463300, 586706850, 586950450, 587194100, 587437800, 587681550, 587925350,
588169200, 588413100, 588657050, 588901050, 589145100, 589389200, 589633350, 589877550, 590121800, 590366100, 590610450, 590854850, 591099300, 591343800, 591588350, 591832950, 592077600, 592322300, 592567050,
592811850, 593056700, 593301600, 593546550, 593791550, 594036600, 594281700, 594526850, 594772050, 595017300, 595262600, 595507950, 595753350, 595998800, 596244300, 596489850, 596735450, 596981100, 597226800,
597472550, 597718350, 597964200, 598210100, 598456050, 598702050, 598948100, 599194200, 599440350, 599686550, 599932800, 600179100, 600425450, 600671850, 600918300, 601164800, 601411350, 601657950, 601904600,
602151300, 602398050, 602644850, 602891700, 603138600, 603385550, 603632550, 603879600, 604126700, 604373850, 604621050, 604868300, 605115600, 605362950, 605610350, 605857800, 606105300, 606352850, 606600450,
606848100, 607095800, 607343550, 607591350, 607839200, 608087100, 608335050, 608583050, 608831100, 609079200, 609327350, 609575550, 609823800, 610072100, 610320450, 610568850, 610817300, 611065800, 611314350,
611562950, 611811600, 612060300, 612309050, 612557850, 612806700, 613055600, 613304550, 613553550, 613802600, 614051700, 614300850, 614550050, 614799300, 615048600, 615297950, 615547350, 615796800, 616046300,
616295850, 616545450, 616795100, 617044800, 617294550, 617544350, 617794200, 618044100, 618294050, 618544050, 618794100, 619044200, 619294350, 619544550, 619794800, 620045100, 620295450, 620545850, 620796300,
621046800, 621297350, 621547950, 621798600, 622049300, 622300050, 622550850, 622801700, 623052600, 623303550, 623554550, 623805600, 624056700, 624307850, 624559050, 624810300, 625061600, 625312950, 625564350,
625815800, 626067300, 626318850, 626570450, 626822100, 627073800, 627325550, 627577350, 627829200, 628081100, 628333050, 628585050, 628837100, 629089200, 629341350, 629593550, 629845800, 630098100, 630350450,
630602850, 630855300, 631107800, 631360350, 631612950, 631865600, 632118300, 632371050, 632623850, 632876700, 633129600, 633382550, 633635550, 633888600, 634141700, 634394850, 634648050, 634901300, 635154600,
635407950, 635661350, 635914800, 636168300, 636421850, 636675450, 636929100, 637182800, 637436550, 637690350, 637944200, 638198100, 638452050, 638706050, 638960100, 639214200, 639468350, 639722550, 639976800,
640231100, 640485450, 640739850, 640994300, 641248800, 641503350, 641757950, 642012600, 642267300, 642522050, 642776850, 643031700, 643286600, 643541550, 643796550, 644051600, 644306700, 644561850, 644817050,
645072300, 645327600, 645582950, 645838350, 646093800, 646349300, 646604850, 646860450, 647116100, 647371800, 647627550, 647883350, 648139200, 648395100, 648651050, 648907050, 649163100, 649419200, 649675350,
649931550, 650187800, 650444100, 650700450, 650956850, 651213300, 651469800, 651726350, 651982950, 652239600, 652496300, 652753050, 653009850, 653266700, 653523600, 653780550, 654037550, 654294600, 654551700,
654808850, 655066050, 655323300, 655580600, 655837950, 656095350, 656352800, 656610300, 656867850, 657125450, 657383100, 657640800, 657898550, 658156350, 658414200, 658672100, 658930050, 659188050, 659446100,
659704200, 659962350, 660220550, 660478800, 660737100, 660995450, 661253850, 661512300, 661770800, 662029350, 662287950, 662546600, 662805300, 663064050, 663322850, 663581700, 663840600, 664099550, 664358550,
664617600, 664876700, 665135850, 665395050, 665654300, 665913600, 666172950, 666432350, 666691800, 666951300, 667210850, 667470450, 667730100, 667989800, 668249550, 668509350, 668769200, 669029100, 669289050,
669549050, 669809100, 670069200, 670329350, 670589550, 670849800, 671110100, 671370450, 671630850, 671891300, 672151800, 672412350, 672672950, 672933600, 673194300, 673455050, 673715850, 673976700, 674237600,
674498550, 674759550, 675020600, 675281700, 675542850, 675804050, 676065300, 676326600, 676587950, 676849350, 677110800, 677372300, 677633850, 677895450, 678157100, 678418800, 678680550, 678942350, 679204200,
679466100, 679728050, 679990050, 680252100, 680514200, 680776350, 681038550, 681300800, 681563100, 681825450, 682087850, 682350300, 682612800, 682875350, 683137950, 683400600, 683663300, 683926050, 684188850,
684451700, 684714600, 684977550, 685240550, 685503600, 685766700, 686029850, 686293050, 686556300, 686819600, 687082950, 687346350, 687609800, 687873300, 688136850, 688400450, 688664100, 688927800, 689191550,
689455350, 689719200, 689983100, 690247050, 690511050, 690775100, 691039200, 691303350, 691567550, 691831800, 692096100, 692360450, 692624850, 692889300, 693153800, 693418350, 693682950, 693947600, 694212300,
694477050, 694741850, 695006700, 695271600, 695536550, 695801550, 696066600, 696331700, 696596850, 696862050, 697127300, 697392600, 697657950, 697923350, 698188800, 698454300, 698719850, 698985450, 699251100,
699516800, 699782550, 700048350, 700314200, 700580100, 700846050, 701112050, 701378100, 701644200, 701910350, 702176550, 702442800, 702709100, 702975450, 703241850, 703508300, 703774800, 704041350, 704307950,
704574600, 704841300, 705108050, 705374850, 705641700, 705908600, 706175550, 706442550, 706709600, 706976700, 707243850, 707511050, 707778300, 708045600, 708312950, 708580350, 708847800, 709115300, 709382850,
709650450, 709918100, 710185800, 710453550, 710721350, 710989200, 711257100, 711525050, 711793050, 712061100, 712329200, 712597350, 712865550, 713133800, 713402100, 713670450, 713938850, 714207300, 714475800,
714744350, 715012950, 715281600, 715550300, 715819050, 716087850, 716356700, 716625600, 716894550, 717163550, 717432600, 717701700, 717970850, 718240050, 718509300, 718778600, 719047950, 719317350, 719586800,
719856300, 720125850, 720395450, 720665100, 720934800, 721204550, 721474350, 721744200, 722014100, 722284050, 722554050, 722824100, 723094200, 723364350, 723634550, 723904800, 724175100, 724445450, 724715850,
724986300, 725256800, 725527350, 725797950, 726068600, 726339300, 726610050, 726880850, 727151700, 727422600, 727693550, 727964550, 728235600, 728506700, 728777850, 729049050, 729320300, 729591600, 729862950,
730134350, 730405800, 730677300, 730948850, 731220450, 731492100, 731763800, 732035550, 732307350, 732579200, 732851100, 733123050, 733395050, 733667100, 733939200, 734211350, 734483550, 734755800, 735028100,
735300450, 735572850, 735845300, 736117800, 736390350, 736662950, 736935600, 737208300, 737481050, 737753850, 738026700, 738299600, 738572550, 738845550, 739118600, 739391700, 739664850, 739938050, 740211300,
740484600, 740757950, 741031350, 741304800, 741578300, 741851850, 742125450, 742399100, 742672800, 742946550, 743220350, 743494200, 743768100, 744042050, 744316050, 744590100, 744864200, 745138350, 745412550,
745686800, 745961100, 746235450, 746509850, 746784300, 747058800, 747333350, 747607950, 747882600, 748157300, 748432050, 748706850, 748981700, 749256600, 749531550, 749806550, 750081600, 750356700, 750631850,
750907050, 751182300, 751457600, 751732950, 752008350, 752283800, 752559300, 752834850, 753110450, 753386100, 753661800, 753937550, 754213350, 754489200, 754765100, 755041050, 755317050, 755593100, 755869200,
756145350, 756421550, 756697800, 756974100, 757250450, 757526850, 757803300, 758079800, 758356350, 758632950, 758909600, 759186300, 759463050, 759739850, 760016700, 760293600, 760570550, 760847550, 761124600,
761401700, 761678850, 761956050, 762233300, 762510600, 762787950, 763065350, 763342800, 763620300, 763897850, 764175450, 764453100, 764730800, 765008550, 765286350, 765564200, 765842100, 766120050, 766398050,
766676100, 766954200, 767232350, 767510550, 767788800, 768067100, 768345450, 768623850, 768902300, 769180800, 769459350, 769737950, 770016600, 770295300, 770574050, 770852850, 771131700, 771410600, 771689550,
771968550, 772247600, 772526700, 772805850, 773085050, 773364300, 773643600, 773922950, 774202350, 774481800, 774761300, 775040850, 775320450, 775600100, 775879800, 776159550, 776439350, 776719200, 776999100,
777279050, 777559050, 777839100, 778119200, 778399350, 778679550, 778959800, 779240100, 779520450, 779800850, 780081300, 780361800, 780642350, 780922950, 781203600, 781484300, 781765050, 782045850, 782326700,
782607600, 782888550, 783169550, 783450600, 783731700, 784012850, 784294050, 784575300, 784856600, 785137950, 785419350, 785700800, 785982300, 786263850, 786545450, 786827100, 787108800, 787390550, 787672350,
787954200, 788236100, 788518050, 788800050, 789082100, 789364200, 789646350, 789928550, 790210800, 790493100, 790775450, 791057850, 791340300, 791622800, 791905350, 792187950, 792470600, 792753300, 793036050,
793318850, 793601700, 793884600, 794167550, 794450550, 794733600, 795016700, 795299850, 795583050, 795866300, 796149600, 796432950, 796716350, 796999800, 797283300, 797566850, 797850450, 798134100, 798417800,
798701550, 798985350, 799269200, 799553100, 799837050, 800121050, 800405100, 800689200, 800973350, 801257550, 801541800, 801826100, 802110450, 802394850, 802679300, 802963800, 803248350, 803532950, 803817600,
804102300, 804387050, 804671850, 804956700, 805241600, 805526550, 805811550, 806096600, 806381700, 806666850, 806952050, 807237300, 807522600, 807807950, 808093350, 808378800, 808664300, 808949850, 809235450,
809521100, 809806800, 810092550, 810378350, 810664200, 810950100, 811236050, 811522050, 811808100, 812094200, 812380350, 812666550, 812952800, 813239100, 813525450, 813811850, 814098300, 814384800, 814671350,
814957950, 815244600, 815531300, 815818050, 816104850, 816391700, 816678600, 816965550, 817252550, 817539600, 817826700, 818113850, 818401050, 818688300, 818975600, 819262950, 819550350, 819837800, 820125300,
820412850, 820700450, 820988100, 821275800, 821563550, 821851350, 822139200, 822427100, 822715050, 823003050, 823291100, 823579200, 823867350, 824155550, 824443800, 824732100, 825020450, 825308850, 825597300,
825885800, 826174350, 826462950, 826751600, 827040300, 827329050, 827617850, 827906700, 828195600, 828484550, 828773550, 829062600, 829351700, 829640850, 829930050, 830219300, 830508600, 830797950, 831087350,
831376800, 831666300, 831955850, 832245450, 832535100, 832824800, 833114550, 833404350, 833694200, 833984100, 834274050, 834564050, 834854100, 835144200, 835434350, 835724550, 836014800, 836305100, 836595450,
836885850, 837176300, 837466800, 837757350, 838047950, 838338600, 838629300, 838920050, 839210850, 839501700, 839792600, 840083550, 840374550, 840665600, 840956700, 841247850, 841539050, 841830300, 842121600,
842412950, 842704350, 842995800, 843287300, 843578850, 843870450, 844162100, 844453800, 844745550, 845037350, 845329200, 845621100, 845913050, 846205050, 846497100, 846789200, 847081350, 847373550, 847665800,
847958100, 848250450, 848542850, 848835300, 849127800, 849420350, 849712950, 850005600, 850298300, 850591050, 850883850, 851176700, 851469600, 851762550, 852055550, 852348600, 852641700, 852934850, 853228050,
853521300, 853814600, 854107950, 854401350, 854694800, 854988300, 855281850, 855575450, 855869100, 856162800, 856456550, 856750350, 857044200, 857338100, 857632050, 857926050, 858220100, 858514200, 858808350,
859102550, 859396800, 859691100, 859985450, 860279850, 860574300, 860868800, 861163350, 861457950, 861752600, 862047300, 862342050, 862636850, 862931700, 863226600, 863521550, 863816550, 864111600, 864406700,
864701850, 864997050, 865292300, 865587600, 865882950, 866178350, 866473800, 866769300, 867064850, 867360450, 867656100, 867951800, 868247550, 868543350, 868839200, 869135100, 869431050, 869727050, 870023100,
870319200, 870615350, 870911550, 871207800, 871504100, 871800450, 872096850, 872393300, 872689800, 872986350, 873282950, 873579600, 873876300, 874173050, 874469850, 874766700, 875063600, 875360550, 875657550,
875954600, 876251700, 876548850, 876846050, 877143300, 877440600, 877737950, 878035350, 878332800, 878630300, 878927850, 879225450, 879523100, 879820800, 880118550, 880416350, 880714200, 881012100, 881310050,
881608050, 881906100, 882204200, 882502350, 882800550, 883098800, 883397100, 883695450, 883993850, 884292300, 884590800, 884889350, 885187950, 885486600, 885785300, 886084050, 886382850, 886681700, 886980600,
887279550, 887578550, 887877600, 888176700, 888475850, 888775050, 889074300, 889373600, 889672950, 889972350, 890271800, 890571300, 890870850, 891170450, 891470100, 891769800, 892069550, 892369350, 892669200,
892969100, 893269050, 893569050, 893869100, 894169200, 894469350, 894769550, 895069800, 895370100, 895670450, 895970850, 896271300, 896571800, 896872350, 897172950, 897473600, 897774300, 898075050, 898375850,
898676700, 898977600, 899278550, 899579550, 899880600, 900181700, 900482850, 900784050, 901085300, 901386600, 901687950, 901989350, 902290800, 902592300, 902893850, 903195450, 903497100, 903798800, 904100550,
904402350, 904704200, 905006100, 905308050, 905610050, 905912100, 906214200, 906516350, 906818550, 907120800, 907423100, 907725450, 908027850, 908330300, 908632800, 908935350, 909237950, 909540600, 909843300,
910146050, 910448850, 910751700, 911054600, 911357550, 911660550, 911963600, 912266700, 912569850, 912873050, 913176300, 913479600, 913782950, 914086350, 914389800, 914693300, 914996850, 915300450, 915604100,
915907800, 916211550, 916515350, 916819200, 917123100, 917427050, 917731050, 918035100, 918339200, 918643350, 918947550, 919251800, 919556100, 919860450, 920164850, 920469300, 920773800, 921078350, 921382950,
921687600, 921992300, 922297050, 922601850, 922906700, 923211600, 923516550, 923821550, 924126600, 924431700, 924736850, 925042050, 925347300, 925652600, 925957950, 926263350, 926568800, 926874300, 927179850,
927485450, 927791100, 928096800, 928402550, 928708350, 929014200, 929320100, 929626050, 929932050, 930238100, 930544200, 930850350, 931156550, 931462800, 931769100, 932075450, 932381850, 932688300, 932994800,
933301350, 933607950, 933914600, 934221300, 934528050, 934834850, 935141700, 935448600, 935755550, 936062550, 936369600, 936676700, 936983850, 937291050, 937598300, 937905600, 938212950, 938520350, 938827800,
939135300, 939442850, 939750450, 940058100, 940365800, 940673550, 940981350, 941289200, 941597100, 941905050, 942213050, 942521100, 942829200, 943137350, 943445550, 943753800, 944062100, 944370450, 944678850,
944987300, 945295800, 945604350, 945912950, 946221600, 946530300, 946839050, 947147850, 947456700, 947765600, 948074550, 948383550, 948692600, 949001700, 949310850, 949620050, 949929300, 950238600, 950547950,
950857350, 951166800, 951476300, 951785850, 952095450, 952405100, 952714800, 953024550, 953334350, 953644200, 953954100, 954264050, 954574050, 954884100, 955194200, 955504350, 955814550, 956124800, 956435100,
956745450, 957055850, 957366300, 957676800, 957987350, 958297950, 958608600, 958919300, 959230050, 959540850, 959851700, 960162600, 960473550, 960784550, 961095600, 961406700, 961717850, 962029050, 962340300,
962651600, 962962950, 963274350, 963585800, 963897300, 964208850, 964520450, 964832100, 965143800, 965455550, 965767350, 966079200, 966391100, 966703050, 967015050, 967327100, 967639200, 967951350, 968263550,
968575800, 968888100, 969200450, 969512850, 969825300, 970137800, 970450350, 970762950, 971075600, 971388300, 971701050, 972013850, 972326700, 972639600, 972952550, 973265550, 973578600, 973891700, 974204850,
974518050, 974831300, 975144600, 975457950, 975771350, 976084800, 976398300, 976711850, 977025450, 977339100, 977652800, 977966550, 978280350, 978594200, 978908100, 979222050, 979536050, 979850100, 980164200,
980478350, 980792550, 981106800, 981421100, 981735450, 982049850, 982364300, 982678800, 982993350, 983307950, 983622600, 983937300, 984252050, 984566850, 984881700, 985196600, 985511550, 985826550, 986141600,
986456700, 986771850, 987087050, 987402300, 987717600, 988032950, 988348350, 988663800, 988979300, 989294850, 989610450, 989926100, 990241800, 990557550, 990873350, 991189200, 991505100, 991821050, 992137050,
992453100, 992769200, 993085350, 993401550, 993717800, 994034100, 994350450, 994666850, 994983300, 995299800, 995616350, 995932950, 996249600, 996566300, 996883050, 997199850, 997516700, 997833600, 998150550,
998467550, 998784600, 999101700, 999418850, 999736050, 1000053300, 1000370600, 1000687950, 1001005350, 1001322800, 1001640300, 1001957850, 1002275450, 1002593100, 1002910800, 1003228550, 1003546350, 1003864200,
1004182100, 1004500050, 1004818050, 1005136100, 1005454200, 1005772350, 1006090550, 1006408800, 1006727100, 1007045450, 1007363850, 1007682300, 1008000800, 1008319350, 1008637950, 1008956600, 1009275300, 1009594050,
1009912850, 1010231700, 1010550600, 1010869550, 1011188550, 1011507600, 1011826700, 1012145850, 1012465050, 1012784300, 1013103600, 1013422950, 1013742350, 1014061800, 1014381300, 1014700850, 1015020450, 1015340100,
1015659800, 1015979550, 1016299350, 1016619200, 1016939100, 1017259050, 1017579050, 1017899100, 1018219200, 1018539350, 1018859550, 1019179800, 1019500100, 1019820450, 1020140850, 1020461300, 1020781800, 1021102350,
1021422950, 1021743600, 1022064300, 1022385050, 1022705850, 1023026700, 1023347600, 1023668550, 1023989550, 1024310600, 1024631700, 1024952850, 1025274050, 1025595300, 1025916600, 1026237950, 1026559350, 1026880800,
1027202300, 1027523850, 1027845450, 1028167100, 1028488800, 1028810550, 1029132350, 1029454200, 1029776100, 1030098050, 1030420050, 1030742100, 1031064200, 1031386350, 1031708550, 1032030800, 1032353100, 1032675450,
1032997850, 1033320300, 1033642800, 1033965350, 1034287950, 1034610600, 1034933300, 1035256050, 1035578850, 1035901700, 1036224600, 1036547550, 1036870550, 1037193600, 1037516700, 1037839850, 1038163050, 1038486300,
1038809600, 1039132950, 1039456350, 1039779800, 1040103300, 1040426850, 1040750450, 1041074100, 1041397800, 1041721550, 1042045350, 1042369200, 1042693100, 1043017050, 1043341050, 1043665100, 1043989200, 1044313350,
1044637550, 1044961800, 1045286100, 1045610450, 1045934850, 1046259300, 1046583800, 1046908350, 1047232950, 1047557600, 1047882300, 1048207050, 1048531850, 1048856700, 1049181600, 1049506550, 1049831550, 1050156600,
1050481700, 1050806850, 1051132050, 1051457300, 1051782600, 1052107950, 1052433350, 1052758800, 1053084300, 1053409850, 1053735450, 1054061100, 1054386800, 1054712550, 1055038350, 1055364200, 1055690100, 1056016050,
1056342050, 1056668100, 1056994200, 1057320350, 1057646550, 1057972800, 1058299100, 1058625450, 1058951850, 1059278300, 1059604800, 1059931350, 1060257950, 1060584600, 1060911300, 1061238050, 1061564850, 1061891700,
1062218600, 1062545550, 1062872550, 1063199600, 1063526700, 1063853850, 1064181050, 1064508300, 1064835600, 1065162950, 1065490350, 1065817800, 1066145300, 1066472850, 1066800450, 1067128100, 1067455800, 1067783550,
1068111350, 1068439200, 1068767100, 1069095050, 1069423050, 1069751100, 1070079200, 1070407350, 1070735550, 1071063800, 1071392100, 1071720450, 1072048850, 1072377300, 1072705800, 1073034350, 1073362950, 1073691600,
1074020300, 1074349050, 1074677850, 1075006700, 1075335600, 1075664550, 1075993550, 1076322600, 1076651700, 1076980850, 1077310050, 1077639300, 1077968600, 1078297950, 1078627350, 1078956800, 1079286300, 1079615850,
1079945450, 1080275100, 1080604800, 1080934550, 1081264350, 1081594200, 1081924100, 1082254050, 1082584050, 1082914100, 1083244200, 1083574350, 1083904550, 1084234800, 1084565100, 1084895450, 1085225850, 1085556300,
1085886800, 1086217350, 1086547950, 1086878600, 1087209300, 1087540050, 1087870850, 1088201700, 1088532600, 1088863550, 1089194550, 1089525600, 1089856700, 1090187850, 1090519050, 1090850300, 1091181600, 1091512950,
1091844350, 1092175800, 1092507300, 1092838850, 1093170450, 1093502100, 1093833800, 1094165550, 1094497350, 1094829200, 1095161100, 1095493050, 1095825050, 1096157100, 1096489200, 1096821350, 1097153550, 1097485800,
1097818100, 1098150450, 1098482850, 1098815300, 1099147800, 1099480350, 1099812950, 1100145600, 1100478300, 1100811050, 1101143850, 1101476700, 1101809600, 1102142550, 1102475550, 1102808600, 1103141700, 1103474850,
1103808050, 1104141300, 1104474600, 1104807950, 1105141350, 1105474800, 1105808300, 1106141850, 1106475450, 1106809100, 1107142800, 1107476550, 1107810350, 1108144200, 1108478100, 1108812050, 1109146050, 1109480100,
1109814200, 1110148350, 1110482550, 1110816800, 1111151100, 1111485450, 1111819850, 1112154300, 1112488800, 1112823350, 1113157950, 1113492600, 1113827300, 1114162050, 1114496850, 1114831700, 1115166600, 1115501550,
1115836550, 1116171600, 1116506700, 1116841850, 1117177050, 1117512300, 1117847600, 1118182950, 1118518350, 1118853800, 1119189300, 1119524850, 1119860450, 1120196100, 1120531800, 1120867550, 1121203350, 1121539200,
1121875100, 1122211050, 1122547050, 1122883100, 1123219200, 1123555350, 1123891550, 1124227800, 1124564100, 1124900450, 1125236850, 1125573300, 1125909800, 1126246350, 1126582950, 1126919600, 1127256300, 1127593050,
1127929850, 1128266700, 1128603600, 1128940550, 1129277550, 1129614600, 1129951700, 1130288850, 1130626050, 1130963300, 1131300600, 1131637950, 1131975350, 1132312800, 1132650300, 1132987850, 1133325450, 1133663100,
1134000800, 1134338550, 1134676350, 1135014200, 1135352100, 1135690050, 1136028050, 1136366100, 1136704200, 1137042350, 1137380550, 1137718800, 1138057100, 1138395450, 1138733850, 1139072300, 1139410800, 1139749350,
1140087950, 1140426600, 1140765300, 1141104050, 1141442850, 1141781700, 1142120600, 1142459550, 1142798550, 1143137600, 1143476700, 1143815850, 1144155050, 1144494300, 1144833600, 1145172950, 1145512350, 1145851800,
1146191300, 1146530850, 1146870450, 1147210100, 1147549800, 1147889550, 1148229350, 1148569200, 1148909100, 1149249050, 1149589050, 1149929100, 1150269200, 1150609350, 1150949550, 1151289800, 1151630100, 1151970450,
1152310850, 1152651300, 1152991800, 1153332350, 1153672950, 1154013600, 1154354300, 1154695050, 1155035850, 1155376700, 1155717600, 1156058550, 1156399550, 1156740600, 1157081700, 1157422850, 1157764050, 1158105300,
1158446600, 1158787950, 1159129350, 1159470800, 1159812300, 1160153850, 1160495450, 1160837100, 1161178800, 1161520550, 1161862350, 1162204200, 1162546100, 1162888050, 1163230050, 1163572100, 1163914200, 1164256350,
1164598550, 1164940800, 1165283100, 1165625450, 1165967850, 1166310300, 1166652800, 1166995350, 1167337950, 1167680600, 1168023300, 1168366050, 1168708850, 1169051700, 1169394600, 1169737550, 1170080550, 1170423600,
1170766700, 1171109850, 1171453050, 1171796300, 1172139600, 1172482950, 1172826350, 1173169800, 1173513300, 1173856850, 1174200450, 1174544100, 1174887800, 1175231550, 1175575350, 1175919200, 1176263100, 1176607050,
1176951050, 1177295100, 1177639200, 1177983350, 1178327550, 1178671800, 1179016100, 1179360450, 1179704850, 1180049300, 1180393800, 1180738350, 1181082950, 1181427600, 1181772300, 1182117050, 1182461850, 1182806700,
1183151600, 1183496550, 1183841550, 1184186600, 1184531700, 1184876850, 1185222050, 1185567300, 1185912600, 1186257950, 1186603350, 1186948800, 1187294300, 1187639850, 1187985450, 1188331100, 1188676800, 1189022550,
1189368350, 1189714200, 1190060100, 1190406050, 1190752050, 1191098100, 1191444200, 1191790350, 1192136550, 1192482800, 1192829100, 1193175450, 1193521850, 1193868300, 1194214800, 1194561350, 1194907950, 1195254600,
1195601300, 1195948050, 1196294850, 1196641700, 1196988600, 1197335550, 1197682550, 1198029600, 1198376700, 1198723850, 1199071050, 1199418300, 1199765600, 1200112950, 1200460350, 1200807800, 1201155300, 1201502850,
1201850450, 1202198100, 1202545800, 1202893550, 1203241350, 1203589200, 1203937100, 1204285050, 1204633050, 1204981100, 1205329200, 1205677350, 1206025550, 1206373800, 1206722100, 1207070450, 1207418850, 1207767300,
1208115800, 1208464350, 1208812950, 1209161600, 1209510300, 1209859050, 1210207850, 1210556700, 1210905600, 1211254550, 1211603550, 1211952600, 1212301700, 1212650850, 1213000050, 1213349300, 1213698600, 1214047950,
1214397350, 1214746800, 1215096300, 1215445850, 1215795450, 1216145100, 1216494800, 1216844550, 1217194350, 1217544200, 1217894100, 1218244050, 1218594050, 1218944100, 1219294200, 1219644350, 1219994550, 1220344800,
1220695100, 1221045450, 1221395850, 1221746300, 1222096800, 1222447350, 1222797950, 1223148600, 1223499300, 1223850050, 1224200850, 1224551700, 1224902600, 1225253550, 1225604550, 1225955600, 1226306700, 1226657850,
1227009050, 1227360300, 1227711600, 1228062950, 1228414350, 1228765800, 1229117300, 1229468850, 1229820450, 1230172100, 1230523800, 1230875550, 1231227350, 1231579200, 1231931100, 1232283050, 1232635050, 1232987100,
1233339200, 1233691350, 1234043550, 1234395800, 1234748100, 1235100450, 1235452850, 1235805300, 1236157800, 1236510350, 1236862950, 1237215600, 1237568300, 1237921050, 1238273850, 1238626700, 1238979600, 1239332550,
1239685550, 1240038600, 1240391700, 1240744850, 1241098050, 1241451300, 1241804600, 1242157950, 1242511350, 1242864800, 1243218300, 1243571850, 1243925450, 1244279100, 1244632800, 1244986550, 1245340350, 1245694200,
1246048100, 1246402050, 1246756050, 1247110100, 1247464200, 1247818350, 1248172550, 1248526800, 1248881100, 1249235450, 1249589850, 1249944300, 1250298800, 1250653350, 1251007950, 1251362600, 1251717300, 1252072050,
1252426850, 1252781700, 1253136600, 1253491550, 1253846550, 1254201600, 1254556700, 1254911850, 1255267050, 1255622300, 1255977600, 1256332950, 1256688350, 1257043800, 1257399300, 1257754850, 1258110450, 1258466100,
1258821800, 1259177550, 1259533350, 1259889200, 1260245100, 1260601050, 1260957050, 1261313100, 1261669200, 1262025350, 1262381550, 1262737800, 1263094100, 1263450450, 1263806850, 1264163300, 1264519800, 1264876350,
1265232950, 1265589600, 1265946300, 1266303050, 1266659850, 1267016700, 1267373600, 1267730550, 1268087550, 1268444600, 1268801700, 1269158850, 1269516050, 1269873300, 1270230600, 1270587950, 1270945350, 1271302800,
1271660300, 1272017850, 1272375450, 1272733100, 1273090800, 1273448550, 1273806350, 1274164200, 1274522100, 1274880050, 1275238050, 1275596100, 1275954200, 1276312350, 1276670550, 1277028800, 1277387100, 1277745450,
1278103850, 1278462300, 1278820800, 1279179350, 1279537950, 1279896600, 1280255300, 1280614050, 1280972850, 1281331700, 1281690600, 1282049550, 1282408550, 1282767600, 1283126700, 1283485850, 1283845050, 1284204300,
1284563600, 1284922950, 1285282350, 1285641800, 1286001300, 1286360850, 1286720450, 1287080100, 1287439800, 1287799550, 1288159350, 1288519200, 1288879100, 1289239050, 1289599050, 1289959100, 1290319200, 1290679350,
1291039550, 1291399800, 1291760100, 1292120450, 1292480850, 1292841300, 1293201800, 1293562350, 1293922950, 1294283600, 1294644300, 1295005050, 1295365850, 1295726700, 1296087600, 1296448550, 1296809550, 1297170600,
1297531700, 1297892850, 1298254050, 1298615300, 1298976600, 1299337950, 1299699350, 1300060800, 1300422300, 1300783850, 1301145450, 1301507100, 1301868800, 1302230550, 1302592350, 1302954200, 1303316100, 1303678050,
1304040050, 1304402100, 1304764200, 1305126350, 1305488550, 1305850800, 1306213100, 1306575450, 1306937850, 1307300300, 1307662800, 1308025350, 1308387950, 1308750600, 1309113300, 1309476050, 1309838850, 1310201700,
1310564600, 1310927550, 1311290550, 1311653600, 1312016700, 1312379850, 1312743050, 1313106300, 1313469600, 1313832950, 1314196350, 1314559800, 1314923300, 1315286850, 1315650450, 1316014100, 1316377800, 1316741550,
1317105350, 1317469200, 1317833100, 1318197050, 1318561050, 1318925100, 1319289200, 1319653350, 1320017550, 1320381800, 1320746100, 1321110450, 1321474850, 1321839300, 1322203800, 1322568350, 1322932950, 1323297600,
1323662300, 1324027050, 1324391850, 1324756700, 1325121600, 1325486550, 1325851550, 1326216600, 1326581700, 1326946850, 1327312050, 1327677300, 1328042600, 1328407950, 1328773350, 1329138800, 1329504300, 1329869850,
1330235450, 1330601100, 1330966800, 1331332550, 1331698350, 1332064200, 1332430100, 1332796050, 1333162050, 1333528100, 1333894200, 1334260350, 1334626550, 1334992800, 1335359100, 1335725450, 1336091850, 1336458300,
1336824800, 1337191350, 1337557950, 1337924600, 1338291300, 1338658050, 1339024850, 1339391700, 1339758600, 1340125550, 1340492550, 1340859600, 1341226700, 1341593850, 1341961050, 1342328300, 1342695600, 1343062950,
1343430350, 1343797800, 1344165300, 1344532850, 1344900450, 1345268100, 1345635800, 1346003550, 1346371350, 1346739200, 1347107100, 1347475050, 1347843050, 1348211100, 1348579200, 1348947350, 1349315550, 1349683800,
1350052100, 1350420450, 1350788850, 1351157300, 1351525800, 1351894350, 1352262950, 1352631600, 1353000300, 1353369050, 1353737850, 1354106700, 1354475600, 1354844550, 1355213550, 1355582600, 1355951700, 1356320850,
1356690050, 1357059300, 1357428600, 1357797950, 1358167350, 1358536800, 1358906300, 1359275850, 1359645450, 1360015100, 1360384800, 1360754550, 1361124350, 1361494200, 1361864100, 1362234050, 1362604050, 1362974100,
1363344200, 1363714350, 1364084550, 1364454800, 1364825100, 1365195450, 1365565850, 1365936300, 1366306800, 1366677350, 1367047950, 1367418600, 1367789300, 1368160050, 1368530850, 1368901700, 1369272600, 1369643550,
1370014550, 1370385600, 1370756700, 1371127850, 1371499050, 1371870300, 1372241600, 1372612950, 1372984350, 1373355800, 1373727300, 1374098850, 1374470450, 1374842100, 1375213800, 1375585550, 1375957350, 1376329200,
1376701100, 1377073050, 1377445050, 1377817100, 1378189200, 1378561350, 1378933550, 1379305800, 1379678100, 1380050450, 1380422850, 1380795300, 1381167800, 1381540350, 1381912950, 1382285600, 1382658300, 1383031050,
1383403850, 1383776700, 1384149600, 1384522550, 1384895550, 1385268600, 1385641700, 1386014850, 1386388050, 1386761300, 1387134600, 1387507950, 1387881350, 1388254800, 1388628300, 1389001850, 1389375450, 1389749100,
1390122800, 1390496550, 1390870350, 1391244200, 1391618100, 1391992050, 1392366050, 1392740100, 1393114200, 1393488350, 1393862550, 1394236800, 1394611100, 1394985450, 1395359850, 1395734300, 1396108800, 1396483350,
1396857950, 1397232600, 1397607300, 1397982050, 1398356850, 1398731700, 1399106600, 1399481550, 1399856550, 1400231600, 1400606700, 1400981850, 1401357050, 1401732300, 1402107600, 1402482950, 1402858350, 1403233800,
1403609300, 1403984850, 1404360450, 1404736100, 1405111800, 1405487550, 1405863350, 1406239200, 1406615100, 1406991050, 1407367050, 1407743100, 1408119200, 1408495350, 1408871550, 1409247800, 1409624100, 1410000450,
1410376850, 1410753300, 1411129800, 1411506350, 1411882950, 1412259600, 1412636300, 1413013050, 1413389850, 1413766700, 1414143600, 1414520550, 1414897550, 1415274600, 1415651700, 1416028850, 1416406050, 1416783300,
1417160600, 1417537950, 1417915350, 1418292800, 1418670300, 1419047850, 1419425450, 1419803100, 1420180800, 1420558550, 1420936350, 1421314200, 1421692100, 1422070050, 1422448050, 1422826100, 1423204200, 1423582350,
1423960550, 1424338800, 1424717100, 1425095450, 1425473850, 1425852300, 1426230800, 1426609350, 1426987950, 1427366600, 1427745300, 1428124050, 1428502850, 1428881700, 1429260600, 1429639550, 1430018550, 1430397600,
1430776700, 1431155850, 1431535050, 1431914300, 1432293600, 1432672950, 1433052350, 1433431800, 1433811300, 1434190850, 1434570450, 1434950100, 1435329800, 1435709550, 1436089350, 1436469200, 1436849100, 1437229050,
1437609050, 1437989100, 1438369200, 1438749350, 1439129550, 1439509800, 1439890100, 1440270450, 1440650850, 1441031300, 1441411800, 1441792350, 1442172950, 1442553600, 1442934300, 1443315050, 1443695850, 1444076700,
1444457600, 1444838550, 1445219550, 1445600600, 1445981700, 1446362850, 1446744050, 1447125300, 1447506600, 1447887950, 1448269350, 1448650800, 1449032300, 1449413850, 1449795450, 1450177100, 1450558800, 1450940550,
1451322350, 1451704200, 1452086100, 1452468050, 1452850050, 1453232100, 1453614200, 1453996350, 1454378550, 1454760800, 1455143100, 1455525450, 1455907850, 1456290300, 1456672800, 1457055350, 1457437950, 1457820600,
1458203300, 1458586050, 1458968850, 1459351700, 1459734600, 1460117550, 1460500550, 1460883600, 1461266700, 1461649850, 1462033050, 1462416300, 1462799600, 1463182950, 1463566350, 1463949800, 1464333300, 1464716850,
1465100450, 1465484100, 1465867800, 1466251550, 1466635350, 1467019200, 1467403100, 1467787050, 1468171050, 1468555100, 1468939200, 1469323350, 1469707550, 1470091800, 1470476100, 1470860450, 1471244850, 1471629300,
1472013800, 1472398350, 1472782950, 1473167600, 1473552300, 1473937050, 1474321850, 1474706700, 1475091600, 1475476550, 1475861550, 1476246600, 1476631700, 1477016850, 1477402050, 1477787300, 1478172600, 1478557950,
1478943350, 1479328800, 1479714300, 1480099850, 1480485450, 1480871100, 1481256800, 1481642550, 1482028350, 1482414200, 1482800100, 1483186050, 1483572050, 1483958100, 1484344200, 1484730350, 1485116550, 1485502800,
1485889100, 1486275450, 1486661850, 1487048300, 1487434800, 1487821350, 1488207950, 1488594600, 1488981300, 1489368050, 1489754850, 1490141700, 1490528600, 1490915550, 1491302550, 1491689600, 1492076700, 1492463850,
1492851050, 1493238300, 1493625600, 1494012950, 1494400350, 1494787800, 1495175300, 1495562850, 1495950450, 1496338100, 1496725800, 1497113550, 1497501350, 1497889200, 1498277100, 1498665050, 1499053050, 1499441100,
1499829200, 1500217350, 1500605550, 1500993800, 1501382100, 1501770450, 1502158850, 1502547300, 1502935800, 1503324350, 1503712950, 1504101600, 1504490300, 1504879050, 1505267850, 1505656700, 1506045600, 1506434550,
1506823550, 1507212600, 1507601700, 1507990850, 1508380050, 1508769300, 1509158600, 1509547950, 1509937350, 1510326800, 1510716300, 1511105850, 1511495450, 1511885100, 1512274800, 1512664550, 1513054350, 1513444200,
1513834100, 1514224050, 1514614050, 1515004100, 1515394200, 1515784350, 1516174550, 1516564800, 1516955100, 1517345450, 1517735850, 1518126300, 1518516800, 1518907350, 1519297950, 1519688600, 1520079300, 1520470050,
1520860850, 1521251700, 1521642600, 1522033550, 1522424550, 1522815600, 1523206700, 1523597850, 1523989050, 1524380300, 1524771600, 1525162950, 1525554350, 1525945800, 1526337300, 1526728850, 1527120450, 1527512100,
1527903800, 1528295550, 1528687350, 1529079200, 1529471100, 1529863050, 1530255050, 1530647100, 1531039200, 1531431350, 1531823550, 1532215800, 1532608100, 1533000450, 1533392850, 1533785300, 1534177800, 1534570350,
1534962950, 1535355600, 1535748300, 1536141050, 1536533850, 1536926700, 1537319600, 1537712550, 1538105550, 1538498600, 1538891700, 1539284850, 1539678050, 1540071300, 1540464600, 1540857950, 1541251350, 1541644800,
1542038300, 1542431850, 1542825450, 1543219100, 1543612800, 1544006550, 1544400350, 1544794200, 1545188100, 1545582050, 1545976050, 1546370100, 1546764200, 1547158350, 1547552550, 1547946800, 1548341100, 1548735450,
1549129850, 1549524300, 1549918800, 1550313350, 1550707950, 1551102600, 1551497300, 1551892050, 1552286850, 1552681700, 1553076600, 1553471550, 1553866550, 1554261600, 1554656700, 1555051850, 1555447050, 1555842300,
1556237600, 1556632950, 1557028350, 1557423800, 1557819300, 1558214850, 1558610450, 1559006100, 1559401800, 1559797550, 1560193350, 1560589200, 1560985100, 1561381050, 1561777050, 1562173100, 1562569200, 1562965350,
1563361550, 1563757800, 1564154100, 1564550450, 1564946850, 1565343300, 1565739800, 1566136350, 1566532950, 1566929600, 1567326300, 1567723050, 1568119850, 1568516700, 1568913600, 1569310550, 1569707550, 1570104600,
1570501700, 1570898850, 1571296050, 1571693300, 1572090600, 1572487950, 1572885350, 1573282800, 1573680300, 1574077850, 1574475450, 1574873100, 1575270800, 1575668550, 1576066350, 1576464200, 1576862100, 1577260050,
1577658050, 1578056100, 1578454200, 1578852350, 1579250550, 1579648800, 1580047100, 1580445450, 1580843850, 1581242300, 1581640800, 1582039350, 1582437950, 1582836600, 1583235300, 1583634050, 1584032850, 1584431700,
1584830600, 1585229550, 1585628550, 1586027600, 1586426700, 1586825850, 1587225050, 1587624300, 1588023600, 1588422950, 1588822350, 1589221800, 1589621300, 1590020850, 1590420450, 1590820100, 1591219800, 1591619550,
1592019350, 1592419200, 1592819100, 1593219050, 1593619050, 1594019100, 1594419200, 1594819350, 1595219550, 1595619800, 1596020100, 1596420450, 1596820850, 1597221300, 1597621800, 1598022350, 1598422950, 1598823600,
1599224300, 1599625050, 1600025850, 1600426700, 1600827600, 1601228550, 1601629550, 1602030600, 1602431700, 1602832850, 1603234050, 1603635300, 1604036600, 1604437950, 1604839350, 1605240800, 1605642300, 1606043850,
1606445450, 1606847100, 1607248800, 1607650550, 1608052350, 1608454200, 1608856100, 1609258050, 1609660050, 1610062100, 1610464200, 1610866350, 1611268550, 1611670800, 1612073100, 1612475450, 1612877850, 1613280300,
1613682800, 1614085350, 1614487950, 1614890600, 1615293300, 1615696050, 1616098850, 1616501700, 1616904600, 1617307550, 1617710550, 1618113600, 1618516700, 1618919850, 1619323050, 1619726300, 1620129600, 1620532950,
1620936350, 1621339800, 1621743300, 1622146850, 1622550450, 1622954100, 1623357800, 1623761550, 1624165350, 1624569200, 1624973100, 1625377050, 1625781050, 1626185100, 1626589200, 1626993350, 1627397550, 1627801800,
1628206100, 1628610450, 1629014850, 1629419300, 1629823800, 1630228350, 1630632950, 1631037600, 1631442300, 1631847050, 1632251850, 1632656700, 1633061600, 1633466550, 1633871550, 1634276600, 1634681700, 1635086850,
1635492050, 1635897300, 1636302600, 1636707950, 1637113350, 1637518800, 1637924300, 1638329850, 1638735450, 1639141100, 1639546800, 1639952550, 1640358350, 1640764200, 1641170100, 1641576050, 1641982050, 1642388100,
1642794200, 1643200350, 1643606550, 1644012800, 1644419100, 1644825450, 1645231850, 1645638300, 1646044800, 1646451350, 1646857950, 1647264600, 1647671300, 1648078050, 1648484850, 1648891700, 1649298600, 1649705550,
1650112550, 1650519600, 1650926700, 1651333850, 1651741050, 1652148300, 1652555600, 1652962950, 1653370350, 1653777800, 1654185300, 1654592850, 1655000450, 1655408100, 1655815800, 1656223550, 1656631350, 1657039200,
1657447100, 1657855050, 1658263050, 1658671100, 1659079200, 1659487350, 1659895550, 1660303800, 1660712100, 1661120450, 1661528850, 1661937300, 1662345800, 1662754350, 1663162950, 1663571600, 1663980300, 1664389050,
1664797850, 1665206700, 1665615600, 1666024550, 1666433550, 1666842600, 1667251700, 1667660850, 1668070050, 1668479300, 1668888600, 1669297950, 1669707350, 1670116800, 1670526300, 1670935850, 1671345450, 1671755100,
1672164800, 1672574550, 1672984350, 1673394200, 1673804100, 1674214050, 1674624050, 1675034100, 1675444200, 1675854350, 1676264550, 1676674800, 1677085100, 1677495450, 1677905850, 1678316300, 1678726800, 1679137350,
1679547950, 1679958600, 1680369300, 1680780050, 1681190850, 1681601700, 1682012600, 1682423550, 1682834550, 1683245600, 1683656700, 1684067850, 1684479050, 1684890300, 1685301600, 1685712950, 1686124350, 1686535800,
1686947300, 1687358850, 1687770450, 1688182100, 1688593800, 1689005550, 1689417350, 1689829200, 1690241100, 1690653050, 1691065050, 1691477100, 1691889200, 1692301350, 1692713550, 1693125800, 1693538100, 1693950450,
1694362850, 1694775300, 1695187800, 1695600350, 1696012950, 1696425600, 1696838300, 1697251050, 1697663850, 1698076700, 1698489600, 1698902550, 1699315550, 1699728600, 1700141700, 1700554850, 1700968050, 1701381300,
1701794600, 1702207950, 1702621350, 1703034800, 1703448300, 1703861850, 1704275450, 1704689100, 1705102800, 1705516550, 1705930350, 1706344200, 1706758100, 1707172050, 1707586050, 1708000100, 1708414200, 1708828350,
1709242550, 1709656800, 1710071100, 1710485450, 1710899850, 1711314300, 1711728800, 1712143350, 1712557950, 1712972600, 1713387300, 1713802050, 1714216850, 1714631700, 1715046600, 1715461550, 1715876550, 1716291600,
1716706700, 1717121850, 1717537050, 1717952300, 1718367600, 1718782950, 1719198350, 1719613800, 1720029300, 1720444850, 1720860450, 1721276100, 1721691800, 1722107550, 1722523350, 1722939200, 1723355100, 1723771050,
1724187050, 1724603100, 1725019200, 1725435350, 1725851550, 1726267800, 1726684100, 1727100450, 1727516850, 1727933300, 1728349800, 1728766350, 1729182950, 1729599600, 1730016300, 1730433050, 1730849850, 1731266700,
1731683600, 1732100550, 1732517550, 1732934600, 1733351700, 1733768850, 1734186050, 1734603300, 1735020600, 1735437950, 1735855350, 1736272800, 1736690300, 1737107850, 1737525450, 1737943100, 1738360800, 1738778550,
1739196350, 1739614200, 1740032100, 1740450050, 1740868050, 1741286100, 1741704200, 1742122350, 1742540550, 1742958800, 1743377100, 1743795450, 1744213850, 1744632300, 1745050800, 1745469350, 1745887950, 1746306600,
1746725300, 1747144050, 1747562850, 1747981700, 1748400600, 1748819550, 1749238550, 1749657600, 1750076700, 1750495850, 1750915050, 1751334300, 1751753600, 1752172950, 1752592350, 1753011800, 1753431300, 1753850850,
1754270450, 1754690100, 1755109800, 1755529550, 1755949350, 1756369200, 1756789100, 1757209050, 1757629050, 1758049100, 1758469200, 1758889350, 1759309550, 1759729800, 1760150100, 1760570450, 1760990850, 1761411300,
1761831800, 1762252350, 1762672950, 1763093600, 1763514300, 1763935050, 1764355850, 1764776700, 1765197600, 1765618550, 1766039550, 1766460600, 1766881700, 1767302850, 1767724050, 1768145300, 1768566600, 1768987950,
1769409350, 1769830800, 1770252300, 1770673850, 1771095450, 1771517100, 1771938800, 1772360550, 1772782350, 1773204200, 1773626100, 1774048050, 1774470050, 1774892100, 1775314200, 1775736350, 1776158550, 1776580800,
1777003100, 1777425450, 1777847850, 1778270300, 1778692800, 1779115350, 1779537950, 1779960600, 1780383300, 1780806050, 1781228850, 1781651700, 1782074600, 1782497550, 1782920550, 1783343600, 1783766700, 1784189850,
1784613050, 1785036300, 1785459600, 1785882950, 1786306350, 1786729800, 1787153300, 1787576850 };



void Github::ThunderMenufolder() {
	std::string outfitstring = Directory::get_current_dir() + "\\ThunderMenu\\";
#include <windows.h>
	std::wstring outfitwstring = functions::s2ws(outfitstring);
	LPCWSTR outfitlpcwstr = outfitwstring.c_str();
	if (CreateDirectoryW(outfitlpcwstr, NULL))
	{
		// Directory created
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		// Directory already exists
	}
	else
	{
		// Failed for some other reason
	}
}

int Github::Thunderytd()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thunder.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thunder.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thunder.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}

int Github::darkside1()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside1-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside1-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside1-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside2()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside2-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside2-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside2-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside3()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside3-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside3-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside3-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside4()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside4-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside4-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside4-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside5()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside5-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside5-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside5-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside6()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside6-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside6-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside6-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside7()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside7-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside7-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside7-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside8()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside8-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside8-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside8-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside9()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside9-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside9-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside9-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside10()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside10-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside10-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside10-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside11()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside11-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside11-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside11-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside12()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside12-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside12-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside12-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside13()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside13-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside13-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside13-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside14()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside14-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside14-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside14-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside15()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside15-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside15-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside15-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside16()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside16-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside16-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside16-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside17()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside17-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside17-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside17-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}int Github::darkside18()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside18-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside18-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside18-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside19()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside19-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside19-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside19-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside20()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside20-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside20-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside20-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside21()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside21-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside21-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside21-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::darkside22()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside22-GTA5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Darkside22-GTA5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Darkside22-GTA5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}

int Github::Thor()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Thor1()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor1.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor1.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor1.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Thor2()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor2.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor2.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor2.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Thor21()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor21.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor21.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor21.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Thor22()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor22.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor22.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor22.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Thor3()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor3.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor3.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor3.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}

int Github::Thor4()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor4.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor4.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor4.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}

int Github::Thor20()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor20.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor20.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor20.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}

int Github::Thor23()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor23.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor23.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor23.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}

int Github::Thor24()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor24.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Thor24.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Thor24.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole1()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole1.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole1.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole1.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole2()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole2.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole2.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole2.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole3()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole3.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole3.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole3.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole4()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole4.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole4.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole4.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole5()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole5.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole5.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole5.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole6()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole6.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole6.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole6.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole7()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole7.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole7.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole7.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole8()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole8.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole8.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole8.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole9()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole9.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole9.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole9.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole10()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole10.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole10.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole10.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole11()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole11.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole11.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole11.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole12()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole12.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole12.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole12.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole13()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole13.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole13.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole13.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole14()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole14.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole14.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole14.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole15()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole15.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole15.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole15.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole16()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole16.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole16.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole16.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole17()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole17.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole17.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole17.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole18()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole18.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole18.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole18.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole19()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole19.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole19.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole19.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole20()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole20.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole20.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole20.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole21()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole21.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole21.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole21.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole22()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole22.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole22.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole22.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole23()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole23.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole23.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole23.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole24()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole24.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole24.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole24.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole25()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole25.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole25.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole25.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole26()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole26.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole26.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole26.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole27()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole27.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole27.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole27.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole272()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole272.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole272.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole272.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole28()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole28.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole28.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole28.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole29()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole29.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole29.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole29.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole30()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole30.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole30.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole30.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole31()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole31.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole31.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole31.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole32()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole32.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole32.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole32.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole33()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole33.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole33.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole33.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole333()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole333.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole333.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole333.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole34()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole34.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole34.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole34.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole35()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole35.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole35.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole35.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole36()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole36.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole36.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole36.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole37()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole37.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole37.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole37.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole38()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole38.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole38.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole38.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole39()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole39.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole39.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole39.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole40()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole40.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole40.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole40.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole41()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole41.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole41.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole41.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole42()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole42.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole42.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole42.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole43()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole43.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole43.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole43.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole44()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole44.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole44.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole44.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole45()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole45.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole45.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole45.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole46()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole46.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole46.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole46.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole47()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole47.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole47.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole47.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole48()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole48.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole48.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole48.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole49()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole49.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole49.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole49.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole50()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole50.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole50.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole50.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole51()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole51.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole51.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole51.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole52()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole52.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole52.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole52.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole53()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole53.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole53.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole53.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole54()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole54.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole54.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole54.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole55()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole55.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole55.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole55.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole56()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole56.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole56.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole56.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole57()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole57.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole57.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole57.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole58()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole58.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole58.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole58.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole59()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole59.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole59.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole59.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole60()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole60.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole60.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole60.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole61()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole61.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole61.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole61.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole62()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole62.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole62.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole62.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole63()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole63.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole63.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole63.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole64()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole64.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole64.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole64.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole65()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole65.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole65.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole65.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole66()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole66.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole66.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole66.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole67()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole67.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole67.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole67.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole68()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole68.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole68.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole68.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole69()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole69.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole69.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole69.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole70()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole70.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole70.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole70.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole71()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole71.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole71.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole71.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole72()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole72.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole72.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole72.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole73()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole73.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole73.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole73.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole74()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole74.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole74.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole74.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole75()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole75.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole75.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole75.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}
int Github::Blackhole76()
{
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")
	std::string dwnld_URL = "https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole76.ytd";
	Log::Msg("https://github.com/3xploitch3ats/Thunder-Menu/raw/Menyoo/Blackhole76.ytd");
	std::string savepath = Directory::get_current_dir() + "\\ThunderMenu\\Blackhole76.ytd";
	std::wstring downloadfile = functions::s2ws(dwnld_URL);
	LPCWSTR downloadingfile = downloadfile.c_str();
	std::wstring savefile = functions::s2ws(savepath);
	LPCWSTR savingfile = savefile.c_str();
	/*URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);*/
	URLDownloadToFile(NULL, LPCWSTR_to_LPCSTR(downloadingfile), LPCWSTR_to_LPCSTR(savingfile), 0, NULL);
	return 0;
}

void m_function::set_bit(int* address, int pos)
{
	*address |= 1 << pos;
}
//namespace size
//{
//	constexpr int globalplayer_bd = 453;
//	constexpr int gpbd_fm_3 = 599;
//	constexpr int gpbd_fm_1 = 888;
//}
//
//
//static inline script_global gpbd_fm_3(1892703);
//static inline script_global gsbd_fm_events(1920255);

#define PlayerID PLAYER::PLAYER_ID()

int m_function::weather = 0;
void m_function::set_fm_event_index(int index)
{
	/*int idx = index / 32;
	int bit = index % 32;*/
	/*m_function::set_bit(gsbd_fm_events.at(11).at(341).at(idx, 1).as<int*>(), bit);
	m_function::set_bit(gsbd_fm_events.at(11).at(348).at(idx, 1).as<int*>(), bit);
	m_function::set_bit(gpbd_fm_3.at(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::playerme), size::gpbd_fm_3).at(10).at(205).at(idx, 1).as<int*>(), bit);*/
	/*m_function::set_bit(gsbd_fm_events.at(11).at(341).at(idx, 1).as<int*>(), bit);
	m_function::set_bit(gsbd_fm_events.at(11).at(348).at(idx, 1).as<int*>(), bit);
	m_function::set_bit(gpbd_fm_3.at(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(Features::playerme), size::gpbd_fm_3).at(10).at(205).at(idx, 1).as<int*>(), bit);*/
	//last
	/*m_function::set_bit(ScriptGlobal::ScriptGlobal(1920255).Add(11).Add(354).Add(idx, 1).As<int*>(), bit);
	m_function::set_bit(ScriptGlobal::ScriptGlobal(1920255).Add(11).Add(347).Add(idx, 1).As<int*>(), bit);
	m_function::set_bit(ScriptGlobal::ScriptGlobal(1892703).Add(Features::playerme, 599).Add(10).Add(205).Add(idx, 1).As<int*>(), bit);*/
	//int idx = index / 32;
	//int bit = index % 32;
	///*m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(354).Add(idx, 1).As<int*>(), bit);
	//m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(347).Add(idx, 1).As<int*>(), bit);*/
	//m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(361).Add(idx, 1).As<int*>(), bit);
	//m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(353).Add(idx, 1).As<int*>(), bit);
	//m_function::set_bit(scr_globals::gpbd_fm_3.Add(Features::playerme, scr_globals::size::gpbd_fm_3).Add(10).Add(205).Add(idx, 1).As<int*>(), bit);
	int idx = index / 32;
	int bit = index % 32;
	/*m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(361).Add(idx, 1).As<int*>(), bit);
	m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(353).Add(idx, 1).As<int*>(), bit);*/
	m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(379).Add(idx, 1).As<int*>(), bit);
	m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(370).Add(idx, 1).As<int*>(), bit);
	m_function::set_bit((int*)&scr_globals::gpbd_fm_3.As<GPBD_FM_3*>()->Entries[PlayerID].BossGoon.ActiveFreemodeEvents[idx], bit);
}
void m_function::clear_fm_event_index(int index)
{
	//int idx = index / 32;
	//int bit = index % 32;
	///*m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(354).Add(idx, 1).As<int*>(), bit);
	//m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(347).Add(idx, 1).As<int*>(), bit);*/
	//m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(361).Add(idx, 1).As<int*>(), bit);
	//m_function::set_bit(scr_globals::gsbd_fm_events.Add(11).Add(353).Add(idx, 1).As<int*>(), bit);
	//m_function::set_bit(scr_globals::gpbd_fm_3.Add(Features::playerme, scr_globals::size::gpbd_fm_3).Add(10).Add(205).Add(idx, 1).As<int*>(), bit);
	int idx = index / 32;
	int bit = index % 32;
	misc::clear_bit(scr_globals::gsbd_fm_events.Add(11).Add(361).Add(idx, 1).As<int*>(), bit);
	misc::clear_bit(scr_globals::gsbd_fm_events.Add(11).Add(353).Add(idx, 1).As<int*>(), bit);
	misc::clear_bit((int*)&scr_globals::gpbd_fm_3.As<GPBD_FM_3*>()->Entries[PlayerID].BossGoon.ActiveFreemodeEvents[idx], bit);
}

//set_fm_event_index(9);
//set_fm_event_index(10);
//set_fm_event_index(11);

//folder::folder(file_manager* file_manager, std::filesystem::path file_path)
//	: folder(file_manager->get_base_dir() / file_path)
//{
//	m_file_manager = file_manager;
//	m_is_project_file = true;
//}
//
//folder::folder(std::filesystem::path folder_path)
//	: m_folder_path(file_manager::ensure_folder_exists(folder_path))
//{
//
//}
//
//file folder::get_file(std::filesystem::path file_path) const
//{
//	if (file_path.is_absolute())
//		throw std::exception("folder#get_file requires a relative path.");
//
//	return file(
//		m_folder_path / file_path
//	);
//}
//
//const std::filesystem::path folder::get_path() const
//{
//	return m_folder_path;
//}
//
//file::file(file_manager* file_manager, std::filesystem::path file_path)
//	: file(file_manager->get_base_dir() / file_path)
//{
//	m_is_project_file = true;
//}
//
//file::file(std::filesystem::path file_path)
//	: m_file_path(file_manager::ensure_file_can_be_created(file_path)), m_is_project_file(false)
//{
//
//}
//
//bool file::exists() const
//{
//	return std::filesystem::exists(m_file_path);
//}
//
//const std::filesystem::path file::get_path() const
//{
//	return m_file_path;
//}
//
//file file::move(std::filesystem::path new_path)
//{
//	if (new_path.is_relative())
//		new_path = m_file_path.parent_path() / new_path;
//
//	file_manager::ensure_file_can_be_created(new_path);
//
//	if (std::filesystem::exists(m_file_path))
//		std::filesystem::rename(m_file_path, new_path);
//
//	return { new_path };
//}
//yim_fipackfile::yim_fipackfile(rage::fiPackfile* rpf, const std::string& mount_name)
//{
//	this->rpf = rpf;
//	this->mount_name = mount_name;
//}
//
//static std::vector<std::string> get_non_dlc_mounted_devices_names()
//{
//	std::vector<std::string> non_dlc_mounted_devices_names;
//
//	uint16_t mounted_devices_len = *g_GameVariables->m_fidevices_len;
//	if (mounted_devices_len)
//	{
//		auto devices_arr = *(uint64_t*)g_GameVariables->m_fidevices;
//		uint8_t** current_device_mount_name_ptr = *(unsigned __int8***)g_GameVariables->m_fidevices;
//		auto device_i = 0;
//
//		while (true)
//		{
//			non_dlc_mounted_devices_names.push_back(*(const char**)current_device_mount_name_ptr);
//
//			++device_i;
//			current_device_mount_name_ptr += 4;
//			if (device_i >= mounted_devices_len)
//				break;
//		}
//	}
//
//	return non_dlc_mounted_devices_names;
//}
//
//static int ends_with(const char* str, const char* suffix)
//{
//	if (!str || !suffix)
//		return 0;
//	size_t lenstr = strlen(str);
//	size_t lensuffix = strlen(suffix);
//	if (lensuffix > lenstr)
//		return 0;
//	return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
//}

//void yim_fipackfile::for_each_fipackfile(std::function<size_t(yim_fipackfile& rpf_wrapper)> cb)
//{
//	// the idea is to reuse existing mount points as much as possible because
//	// even when mounting / unmounting properly you'll get file errors
//	// and crashes if the rpf file was already mounted
//
//	// iterate the fidevice array which contains devices that are currently mounted
//	// the dlc devices are in another array
//	const auto non_dlc_mounted_devices_names = get_non_dlc_mounted_devices_names();
//
//	// for not hanging the game too much
//	constexpr auto yield_increment = 80;
//
//	auto i = 1;
//	while (g_GameVariables->m_fipackfile_instances[i])
//	{
//		auto* rpf = g_GameVariables->m_fipackfile_instances[i];
//
//		// its hard coded in the binary?
//		if (++i >= 3672)
//		{
//			break;
//		}
//
//		yim_fipackfile rpf_wrapper = yim_fipackfile(rpf, default_mount_name);
//
//		auto already_mounted = false;
//		for (const auto& non_dlc_mounted_device_name : non_dlc_mounted_devices_names)
//		{
//			auto* non_dlc_mounted_device = rage::fiDevice::GetDevice(non_dlc_mounted_device_name.c_str(), true);
//
//			if (rpf == non_dlc_mounted_device)
//			{
//				rpf_wrapper.mount_name = non_dlc_mounted_device_name;
//				already_mounted = true;
//			}
//		}
//
//		if (!already_mounted)
//		{
//			size_t acc = 0;
//
//			rpf_wrapper.mount_name = "memory:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "memory:";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "dlc";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "dlc:";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "dlc:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "dlcpacks:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "common:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "commoncrc:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "update:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "update2:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "platform:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "platformcrc:/";
//			acc += cb(rpf_wrapper);
//
//			rpf_wrapper.mount_name = "gamecache:/";
//			acc += cb(rpf_wrapper);
//
//			// if we got nothing with those mount points for this rpf, mount it
//			if (!acc)
//			{
//				rpf_wrapper.mount_name = default_mount_name;
//				rpf->Mount(default_mount_name);
//
//				cb(rpf_wrapper);
//
//				g_GameVariables->m_fipackfile_unmount(default_mount_name);
//			}
//		}
//		else
//		{
//			cb(rpf_wrapper);
//		}
//
//		if (i % yield_increment == 0)
//		{
//			DWORD ticks = GetTickCount64();
//			DWORD milliseconds = ticks % 1000;
//			//ticks /= 1000;
//			//DWORD seconds = ticks % 60;
//			//ticks /= 60;
//			//DWORD minutes = ticks % 60;
//			//ticks /= 60;
//			//DWORD hours = ticks; // may exceed 24 hours.
//					/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
//			int getTimer = milliseconds;
//			if (getTimer % 20 == 0)
//			{
//			}
//		}
//			/*script::get_current()->yield();*/
//	}
//}

//std::vector<std::filesystem::path> yim_fipackfile::get_file_paths(std::string parent)
//{
//	std::vector<std::filesystem::path> file_paths;
//	if (parent.empty())
//		parent = mount_name;
//
//	std::vector<std::string> directories;
//
//	rage::fiFindData findData = { 0 };
//	auto handlef = rpf->FindFirst(parent.c_str(), &findData);
//	if (handlef != -1)
//	{
//		do
//		{
//			std::string fn = std::string(parent.c_str()) + std::string("/") + std::string(findData.fileName);
//
//			if (findData.fileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//			{
//				directories.push_back(fn);
//			}
//			else
//			{
//				file_paths.push_back(fn);
//			}
//		} while (rpf->FindNext(handlef, &findData));
//
//		rpf->FindClose(handlef);
//	}
//
//	for (auto& directory : directories)
//	{
//		auto files = get_file_paths(directory);
//
//		file_paths.insert(file_paths.end(), files.begin(), files.end());
//	}
//
//	return file_paths;
//}

//void yim_fipackfile::read_file(const std::filesystem::path& path, file_contents_callback&& cb)
//{
//	if (const auto handle = rpf->Open(path.string().c_str(), true); handle != -1)
//	{
//		const auto data_length = rpf->GetFileLength(handle);
//		const auto file_content = std::make_unique<std::uint8_t[]>(data_length);
//
//		rpf->ReadFull(handle, file_content.get(), data_length);
//
//		cb(file_content, data_length);
//
//		rpf->Close(handle);
//	}
//}
//
//void yim_fipackfile::read_xml_file(const std::filesystem::path& path, std::function<void(pugi::xml_document& doc)> cb)
//{
//	read_file(path, [&cb](const std::unique_ptr<std::uint8_t[]>& file_content, const int data_size)
//		{
//			if (pugi::xml_document doc; doc.load_buffer(file_content.get(), data_size).status == pugi::xml_parse_status::status_ok)
//			{
//				cb(doc);
//			}
//		});
//}

//void gta_data_service::rebuild_cache()
//{
//	m_update_state = eGtaDataUpdateState::UPDATING;
//
//	using hash_array = std::vector<std::uint32_t>;
//	hash_array mapped_peds;
//	hash_array mapped_vehicles;
//	hash_array mapped_weapons;
//
//	std::vector<ped_item> peds;
//	std::vector<vehicle_item> vehicles;
//	std::vector<weapon_item> weapons;
//
//	constexpr auto exists = [](const hash_array& arr, std::uint32_t val) -> bool
//	{
//		return std::find(arr.begin(), arr.end(), val) != arr.end();
//	};
//
//	//LOG(INFO) << "Rebuilding cache started...";
//	yim_fipackfile::for_each_fipackfile([&](yim_fipackfile& rpf_wrapper)
//		{
//			const auto files = rpf_wrapper.get_file_paths();
//	for (const auto& file : files)
//	{
//		if (file.filename() == "setup2.xml")
//		{
//			std::string dlc_name;
//			rpf_wrapper.read_xml_file(file, [&dlc_name](pugi::xml_document& doc)
//				{
//					const auto item = doc.select_node("/SSetupData/nameHash");
//			dlc_name = item.node().text().as_string();
//				});
//
//			if (dlc_name == "mpG9EC")
//			{
//				//LOG(G3LOG_DEBUG) << "Bad DLC, skipping...";
//
//				return std::size_t(0);
//			}
//		}
//		else if (file.filename() == "vehicles.meta")
//		{
//			rpf_wrapper.read_xml_file(file, [&exists, &vehicles, &mapped_vehicles](pugi::xml_document& doc)
//				{
//					const auto& items = doc.select_nodes("/CVehicleModelInfo__InitDataList/InitDatas/Item");
//			for (const auto& item_node : items)
//			{
//				const auto item = item_node.node();
//
//				const auto name = item.child("modelName").text().as_string();
//				const auto hash = rage::joaat(name);
//
//				if (exists(mapped_vehicles, hash))
//					continue;
//				mapped_vehicles.emplace_back(hash);
//
//				auto veh = vehicle_item{};
//				std::strncpy(veh.m_name, name, sizeof(veh.m_name));
//
//				const auto manufacturer_display = item.child("vehicleMakeName").text().as_string();
//				std::strncpy(
//					veh.m_display_manufacturer,
//					HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION(manufacturer_display),
//					sizeof(veh.m_display_manufacturer));
//
//				const auto game_name = item.child("gameName").text().as_string();
//				std::strncpy(
//					veh.m_display_name,
//					HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION(game_name),
//					sizeof(veh.m_display_name));
//
//				const auto vehicle_class = item.child("vehicleClass").text().as_string();
//				constexpr auto enum_prefix_len = 3;
//				if (std::strlen(vehicle_class) > enum_prefix_len)
//					std::strncpy(veh.m_vehicle_class, vehicle_class + enum_prefix_len, sizeof(veh.m_vehicle_class));
//
//				veh.m_hash = hash;
//
//				vehicles.emplace_back(std::move(veh));
//			}
//				});
//		}
//		else if (const auto file_str = file.string(); file_str.find("weapon") != std::string::npos && file.extension() == ".meta")
//		{
//			rpf_wrapper.read_xml_file(file, [&exists, &weapons, &mapped_weapons](pugi::xml_document& doc)
//				{
//					const auto& items = doc.select_nodes("/CWeaponInfoBlob/Infos/Item/Infos/Item[@type='CWeaponInfo']");
//			for (const auto& item_node : items)
//			{
//				const auto item = item_node.node();
//				const auto name = item.child("Name").text().as_string();
//				const auto hash = rage::joaat(name);
//
//				if (exists(mapped_weapons, hash))
//					continue;
//				mapped_weapons.emplace_back(hash);
//
//				const auto human_name_hash = item.child("HumanNameHash").text().as_string();
//				if (std::strcmp(human_name_hash, "WT_INVALID") == 0)
//					continue;
//
//				auto weapon = weapon_item{};
//
//				std::strncpy(weapon.m_name, name, sizeof(weapon.m_name));
//
//				const auto display_name = HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION(human_name_hash);
//				std::strncpy(weapon.m_display_name, display_name, sizeof(weapon.m_name));
//
//				auto weapon_flags = std::string(
//					item.child("WeaponFlags").text().as_string()
//				);
//
//				bool is_gun = false;
//				bool is_rechargable = false;
//
//				std::size_t pos;
//				while ((pos = weapon_flags.find(' ')) != std::string::npos) {
//					const auto flag = weapon_flags.substr(0, pos);
//					if (flag == "Thrown")
//					{
//						weapon.m_throwable = true;
//					}
//					else if (flag == "Gun")
//					{
//						is_gun = true;
//					}
//					else if (flag == "DisplayRechargeTimeHUD")
//					{
//						is_rechargable = true;
//					}
//
//					weapon_flags.erase(0, pos + 1);
//				}
//
//				const auto category = item.child("Group").text().as_string();
//				if (std::strlen(category) > 6)
//				{
//					std::strncpy(weapon.m_weapon_type, category + 6, sizeof(weapon.m_weapon_type));
//				}
//
//				if (is_gun || !std::strcmp(weapon.m_weapon_type, "MELEE") || !std::strcmp(weapon.m_weapon_type, "UNARMED"))
//				{
//					const std::string reward_prefix = "REWARD_";
//					weapon.m_reward_hash = rage::joaat(reward_prefix + name);
//
//					if (is_gun && !is_rechargable)
//					{
//						std::string weapon_id = name + 7;
//						weapon.m_reward_ammo_hash = rage::joaat(reward_prefix + "AMMO_" + weapon_id);
//					}
//				}
//
//				weapon.m_hash = hash;
//
//				weapons.emplace_back(std::move(weapon));
//			}
//				});
//		}
//		else if (file.filename() == "peds.meta" || file.filename() == "peds.ymt")
//		{
//			rpf_wrapper.read_xml_file(file, [&exists, &peds, &mapped_peds](pugi::xml_document& doc)
//				{
//					const auto& items = doc.select_nodes("/CPedModelInfo__InitDataList/InitDatas/Item");
//			for (const auto& item_node : items)
//			{
//				const auto& item = item_node.node();
//				const auto name = item.child("Name").text().as_string();
//				const auto hash = rage::joaat(name);
//
//				if (exists(mapped_peds, hash))
//					continue;
//				mapped_peds.emplace_back(hash);
//
//				auto ped = ped_item{};
//
//				std::strncpy(ped.m_name, name, sizeof(ped.m_name));
//
//				const auto ped_type = item.child("Pedtype").text().as_string();
//				std::strncpy(ped.m_ped_type, ped_type, sizeof(ped.m_ped_type));
//
//				ped.m_hash = hash;
//
//				peds.emplace_back(std::move(ped));
//			}
//				});
//		}
//	}
//
//	return files.size();
//		});
//
//	m_update_state = eGtaDataUpdateState::IDLE;
//	//LOG(INFO) << "Cache has been rebuilt.\n\tPeds: " << peds.size() << "\n\tVehicles: " << vehicles.size() << "\n\tWeapons: " << weapons.size();
//
//	/*LOG(G3LOG_DEBUG) << "Starting cache saving procedure...";
//	g_thread_pool->push([this, peds = std::move(peds), vehicles = std::move(vehicles), weapons = std::move(weapons)]
//		{*/
//			const auto game_version = std::strtoul(g_GameVariables->m_game_version, nullptr, 10);
//	const auto online_version = std::strtof(g_GameVariables->m_online_version, nullptr);
//
//	{
//		const auto data_size = sizeof(ped_item) * peds.size();
//		m_peds_cache.set_data(std::make_unique<std::uint8_t[]>(data_size), data_size);
//		std::memcpy(m_peds_cache.data(), peds.data(), data_size);
//
//		m_peds_cache.set_header_version(game_version, online_version);
//		m_peds_cache.write();
//	}
//
//	{
//		const auto data_size = sizeof(vehicle_item) * vehicles.size();
//		m_vehicles_cache.set_data(std::make_unique<std::uint8_t[]>(data_size), data_size);
//		std::memcpy(m_vehicles_cache.data(), vehicles.data(), data_size);
//
//		m_vehicles_cache.set_header_version(game_version, online_version);
//		m_vehicles_cache.write();
//	}
//
//	{
//		const auto data_size = sizeof(weapon_item) * weapons.size();
//		m_weapons_cache.set_data(std::make_unique<std::uint8_t[]>(data_size), data_size);
//		std::memcpy(m_weapons_cache.data(), weapons.data(), data_size);
//
//		m_weapons_cache.set_header_version(game_version, online_version);
//		m_weapons_cache.write();
//	}
//
//	//LOG(INFO) << "Finished writing cache to disk.";
//
//	load_data();
//		/*});*/
//}

cache_file::cache_file(file cache_file, std::uint32_t cache_version) :
	m_cache_file(cache_file),
	m_data(nullptr),
	m_cache_version(cache_version),
	m_cache_header()
{

}

void cache_file::free()
{
	m_data.reset();
}

bool cache_file::load()
{
	if (!m_cache_file.exists())
		return false;
	if (m_data)
		return true;

	auto file = std::ifstream(m_cache_file.get_path(), std::ios::binary);

	file.read(reinterpret_cast<char*>(&m_cache_header), sizeof(m_cache_header));

	m_data = std::make_unique<std::uint8_t[]>(m_cache_header.m_data_size);
	file.read(reinterpret_cast<char*>(m_data.get()), m_cache_header.m_data_size);

	file.close();
	return true;
}

bool cache_file::write() const
{
	if (!m_data)
		return false;

	auto file = std::ofstream(m_cache_file.get_path(), std::ios::binary);

	file.write(reinterpret_cast<const char*>(&m_cache_header), sizeof(m_cache_header));
	file.write(reinterpret_cast<const char*>(m_data.get()), m_cache_header.m_data_size);
	file.close();

	return true;
}

std::uint8_t* cache_file::data() const
{
	return m_data.get();
}

std::uint64_t cache_file::data_size() const
{
	return m_cache_header.m_data_size;
}

bool cache_file::up_to_date(std::uint32_t game_version, float online_version) const
{
	if (!m_data)
		return false;

	return
		m_cache_version == m_cache_header.m_cache_version &&
		game_version == m_cache_header.m_game_version &&
		online_version == m_cache_header.m_online_version;
}

void cache_file::set_data(cache_data&& data, std::uint64_t data_size)
{
	m_data.swap(data);
	m_cache_header.m_data_size = data_size;
}

void cache_file::set_header_version(std::uint32_t game_version, float online_version)
{
	m_cache_header.m_cache_version = m_cache_version;
	m_cache_header.m_game_version = game_version;
	m_cache_header.m_online_version = online_version;
}

folder::folder(file_manager* file_manager, std::filesystem::path file_path)
	: folder(file_manager->get_base_dir() / file_path)
{
	m_file_manager = file_manager;
	m_is_project_file = true;
}

folder::folder(std::filesystem::path folder_path)
	: m_folder_path(file_manager::ensure_folder_exists(folder_path))
{

}

file folder::get_file(std::filesystem::path file_path) const
{
	if (file_path.is_absolute())
		throw std::exception("folder#get_file requires a relative path.");

	return file(
		m_folder_path / file_path
	);
}

const std::filesystem::path folder::get_path() const
{
	return m_folder_path;
}


file::file(file_manager* file_manager, std::filesystem::path file_path)
	: file(file_manager->get_base_dir() / file_path)
{
	m_is_project_file = true;
}

file::file(std::filesystem::path file_path)
	: m_file_path(file_manager::ensure_file_can_be_created(file_path)), m_is_project_file(false)
{

}

bool file::exists() const
{
	return std::filesystem::exists(m_file_path);
}

const std::filesystem::path file::get_path() const
{
	return m_file_path;
}

file file::move(std::filesystem::path new_path)
{
	if (new_path.is_relative())
		new_path = m_file_path.parent_path() / new_path;

	file_manager::ensure_file_can_be_created(new_path);

	if (std::filesystem::exists(m_file_path))
		std::filesystem::rename(m_file_path, new_path);

	return { new_path };
}
void gta_data_service::update_in_online()
{
	m_update_state = eGtaDataUpdateState::WAITING_FOR_ONLINE;

	/*g_fiber_pool->queue_job([this]
		{*/
		//session::join_type(eSessionType::SOLO);

/*while (!*g_pointers->m_is_session_started)
{
	script::get_current()->yield(100ms);
}*/

/*rebuild_cache();*/
	/*});*/
}

void gta_data_service::update_now()
{
	/*g_fiber_pool->queue_job([this]
		{*/
		/*rebuild_cache();*/
	/*});*/
}

//pickup_service* servicepickup;
pickup_service::pickup_service()
{
	g_pickup_service = this;
}

pickup_service::~pickup_service()
{
	g_pickup_service = nullptr;
}

void pickup_service::give_ammo(const int targets) const
{
	for (const auto& [_, weapon] : g_gta_data_service->weapons())
	{
		if (weapon.m_reward_ammo_hash != 0 || weapon.m_throwable)
		{
			DWORD ticks = GetTickCount64();
			DWORD milliseconds = ticks % 1000;
			//ticks /= 1000;
			//DWORD seconds = ticks % 60;
			//ticks /= 60;
			//DWORD minutes = ticks % 60;
			//ticks /= 60;
			//DWORD hours = ticks; // may exceed 24 hours.
					/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
			int getTimer = milliseconds;
			if (getTimer % 20 == 0)
			{
				g_GameVariables->m_give_pickup_rewards(targets, weapon.m_reward_ammo_hash);
			}
			//script::get_current()->yield(20ms);
		}
	}
}

void pickup_service::give_armour(const int targets) const
{
	DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;
	ticks /= 1000;
	DWORD seconds = ticks % 60;
	//ticks /= 60;
	//DWORD minutes = ticks % 60;
	//ticks /= 60;
	//DWORD hours = ticks; // may exceed 24 hours.
			/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
	int getTimer = seconds;
	if (getTimer % 1 == 0)
	{
		g_GameVariables->m_give_pickup_rewards(1 << targets, RAGE_JOAAT("REWARD_ARMOUR"));
	}
	//script::get_current()->yield(20ms);
}

void pickup_service::give_health(const int targets) const
{
	DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;
	ticks /= 1000;
	DWORD seconds = ticks % 60;
	//ticks /= 60;
	//DWORD minutes = ticks % 60;
	//ticks /= 60;
	//DWORD hours = ticks; // may exceed 24 hours.
			/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
	int getTimer = seconds;
	if (getTimer % 1 == 0)
	{
		g_GameVariables->m_give_pickup_rewards(1 << targets, RAGE_JOAAT("REWARD_HEALTH"));
	}
}

void pickup_service::give_weapons(const int targets) const
{
	for (const auto& [_, weapon] : g_gta_data_service->weapons())
	{
		if (weapon.m_reward_hash != 0)
		{
			DWORD ticks = GetTickCount64();
			DWORD milliseconds = ticks % 1000;
			ticks /= 1000;
			DWORD seconds = ticks % 60;
			//ticks /= 60;
			//DWORD minutes = ticks % 60;
			//ticks /= 60;
			//DWORD hours = ticks; // may exceed 24 hours.
					/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
			int getTimer = seconds;
			if (getTimer % 2 == 0)
			{
				g_GameVariables->m_give_pickup_rewards(targets, weapon.m_reward_hash);
			}
			//script::get_current()->yield(20ms);
		}
		else
			g_GameVariables->m_give_pickup_rewards(targets, RAGE_JOAAT("REWARD_PARACHUTE"));
	}
	/*DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;*/
	//ticks /= 1000;
	//DWORD seconds = ticks % 60;
	//ticks /= 60;
	//DWORD minutes = ticks % 60;
	//ticks /= 60;
	//DWORD hours = ticks; // may exceed 24 hours.
			/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
	/*int getTimer = milliseconds;
	if (getTimer % 2 == 0)
	{
		g_GameVariables->m_give_pickup_rewards(targets, RAGE_JOAAT("REWARD_PARACHUTE"));
	}*/
	//script::get_current()->yield(20ms);
}

//void pickup_service::give_player_ammo(Player player)
//{
//	give_ammo(1 << player);
//}
//
//void pickup_service::give_player_armour(Player player)
//{
//	give_armour(1 << player);
//}
//
//void pickup_service::give_player_health(Player player)
//{
//	give_health(1 << player);
//}
//
//void pickup_service::give_player_weapons(Player player)
//{
//	give_weapons(1 << player);
//}


gta_data_service::gta_data_service() :
	m_peds_cache(g_file_manager->get_project_file("./cache/peds.bin"), 1),
	m_vehicles_cache(g_file_manager->get_project_file("./cache/vehicles.bin"), 1),
	m_weapons_cache(g_file_manager->get_project_file("./cache/weapons.bin"), 1),
	m_update_state(eGtaDataUpdateState::IDLE)
{
	if (!is_cache_up_to_date())
		m_update_state = eGtaDataUpdateState::NEEDS_UPDATE;
	else
		load_data();

	g_gta_data_service = this;
}

gta_data_service::~gta_data_service()
{
	g_gta_data_service = nullptr;
}

bool gta_data_service::cache_needs_update() const
{
	return m_update_state == eGtaDataUpdateState::NEEDS_UPDATE;
}

eGtaDataUpdateState gta_data_service::state() const
{
	return m_update_state;
}

// innefficient getters, don't care to fix right now
const ped_item& gta_data_service::ped_by_hash(std::uint32_t hash)
{
	for (const auto& [name, ped] : m_peds)
		if (rage::joaat(name) == hash)
			return ped;
	return gta_data_service::empty_ped;
}

const vehicle_item& gta_data_service::vehicle_by_hash(std::uint32_t hash)
{
	for (const auto& [name, veh] : m_vehicles)
		if (rage::joaat(name) == hash)
			return veh;
	return gta_data_service::empty_vehicle;
}

const weapon_item& gta_data_service::weapon_by_hash(std::uint32_t hash)
{
	for (const auto& [name, weapon] : m_weapons)
		if (rage::joaat(name) == hash)
			return weapon;
	return gta_data_service::empty_weapon;
}

string_vec& gta_data_service::ped_types()
{
	return m_ped_types;
}

string_vec& gta_data_service::vehicle_classes()
{
	return m_vehicle_classes;
}

string_vec& gta_data_service::weapon_types()
{
	return m_weapon_types;
}

bool gta_data_service::is_cache_up_to_date()
{
	m_peds_cache.load();
	m_vehicles_cache.load();
	m_weapons_cache.load();

	const auto game_version = std::strtoul(g_GameVariables->m_game_version, nullptr, 10);
	const auto online_version = std::strtof(g_GameVariables->m_online_version, nullptr);

	return
		m_peds_cache.up_to_date(game_version, online_version) &&
		m_vehicles_cache.up_to_date(game_version, online_version) &&
		m_weapons_cache.up_to_date(game_version, online_version);
}

void gta_data_service::load_data()
{
	//LOG(G3LOG_DEBUG) << "Loading data from cache.";

	load_peds();
	load_vehicles();
	load_weapons();

	//LOG(G3LOG_DEBUG) << "Loaded all data from cache.";
}
bool add_if_not_exists(string_vec& vec, std::string str)
{
	if (std::find(vec.begin(), vec.end(), str) != vec.end())
		return true;

	vec.emplace_back(std::move(str));
	return false;
}
void gta_data_service::load_peds()
{
	const auto ped_count = m_peds_cache.data_size() / sizeof(ped_item);
	//LOG(INFO) << "Loading " << ped_count << " peds from cache.";

	auto cached_peds = reinterpret_cast<const ped_item*>(m_peds_cache.data());
	for (size_t i = 0; i < ped_count; i++)
	{
		const auto ped = cached_peds[i];

		add_if_not_exists(m_ped_types, ped.m_ped_type);
		m_peds.insert({ ped.m_name, ped });
	}

	std::sort(m_ped_types.begin(), m_ped_types.end());
	m_peds_cache.free();
}

void gta_data_service::load_vehicles()
{
	const auto vehicle_count = m_vehicles_cache.data_size() / sizeof(vehicle_item);
	//LOG(INFO) << "Loading " << vehicle_count << " vehicles from cache.";

	auto cached_vehicles = reinterpret_cast<const vehicle_item*>(m_vehicles_cache.data());
	for (size_t i = 0; i < vehicle_count; i++)
	{
		const auto vehicle = cached_vehicles[i];

		add_if_not_exists(m_vehicle_classes, vehicle.m_vehicle_class);
		m_vehicles.insert({ vehicle.m_name, vehicle });
	}

	std::sort(m_vehicle_classes.begin(), m_vehicle_classes.end());
	m_vehicles_cache.free();
}

void gta_data_service::load_weapons()
{
	const auto weapon_count = m_weapons_cache.data_size() / sizeof(weapon_item);
	//LOG(INFO) << "Loading " << weapon_count << " weapons from cache.";

	auto cached_weapons = reinterpret_cast<const weapon_item*>(m_weapons_cache.data());
	for (size_t i = 0; i < weapon_count; i++)
	{
		const auto weapon = cached_weapons[i];

		add_if_not_exists(m_weapon_types, weapon.m_weapon_type);
		m_weapons.insert({ weapon.m_name, weapon });
	}

	std::sort(m_weapon_types.begin(), m_weapon_types.end());
	m_weapons_cache.free();
}

//int giveto::give_Player_ammo(int targets)
//{
//	servicepickup->give_player_ammo(targets);
//	return 0;
//}
//int giveto::give_Player_armour(int targets)
//{
//	servicepickup->give_player_armour(targets);
//	return 0;
//}
//int giveto::give_Player_health(int targets)
//{
//	servicepickup->give_player_health(targets);
//	return 0;
//}
//int giveto::give_Player_weapons(int targets)
//{
//	servicepickup->give_player_weapons(targets);
//	return 0;
//}
//int giveto::give_Player_ammo(int targets)
//{
//	g_pickup_service->give_ammo(targets);
//	return 0;
//}
//int giveto::give_Player_armour(int targets)
//{
//	g_pickup_service->give_armour(targets);
//	return 0;
//}
//int giveto::give_Player_health(int targets)
//{
//	g_pickup_service->give_health(targets);
//	return 0;
//}
//int giveto::give_Player_weapons(int targets)
//{
//	g_pickup_service->give_weapons(targets);
//	return 0;
//}

std::optional<std::uint8_t> to_hex(char const c)
{
	switch (c)
	{
	case '0':
		return static_cast<std::uint8_t>(0x0);
	case '1':
		return static_cast<std::uint8_t>(0x1);
	case '2':
		return static_cast<std::uint8_t>(0x2);
	case '3':
		return static_cast<std::uint8_t>(0x3);
	case '4':
		return static_cast<std::uint8_t>(0x4);
	case '5':
		return static_cast<std::uint8_t>(0x5);
	case '6':
		return static_cast<std::uint8_t>(0x6);
	case '7':
		return static_cast<std::uint8_t>(0x7);
	case '8':
		return static_cast<std::uint8_t>(0x8);
	case '9':
		return static_cast<std::uint8_t>(0x9);
	case 'a':
		return static_cast<std::uint8_t>(0xa);
	case 'b':
		return static_cast<std::uint8_t>(0xb);
	case 'c':
		return static_cast<std::uint8_t>(0xc);
	case 'd':
		return static_cast<std::uint8_t>(0xd);
	case 'e':
		return static_cast<std::uint8_t>(0xe);
	case 'f':
		return static_cast<std::uint8_t>(0xf);
	case 'A':
		return static_cast<std::uint8_t>(0xA);
	case 'B':
		return static_cast<std::uint8_t>(0xB);
	case 'C':
		return static_cast<std::uint8_t>(0xC);
	case 'D':
		return static_cast<std::uint8_t>(0xD);
	case 'E':
		return static_cast<std::uint8_t>(0xE);
	case 'F':
		return static_cast<std::uint8_t>(0xF);
	default:
		return std::nullopt;
	}
}

pattern2::pattern2(std::string_view ida_sig)
{
	const auto size = ida_sig.size();
	for (std::size_t i{}; i != size; ++i)
	{
		if (ida_sig[i] == ' ')
			continue;
		bool last = (i == ida_sig.size() - 1);
		if (ida_sig[i] != '?')
		{
			if (!last)
			{
				auto c1 = to_hex(ida_sig[i]);
				auto c2 = to_hex(ida_sig[i + 1]);
				if (c1 && c2)
				{
					m_bytes.emplace_back(static_cast<std::uint8_t>((*c1 * 0x10) + *c2));
				}
			}
		}
		else
		{
			m_bytes.push_back({});
		}
	}
}

pattern2::pattern2(const void* bytes, std::string_view mask)
{
	const auto size = mask.size();
	for (std::size_t i{}; i != size; ++i)
	{
		if (mask[i] != '?')
			m_bytes.emplace_back(static_cast<const std::uint8_t*>(bytes)[i]);
		else
			m_bytes.push_back(std::nullopt);
	}
}

range::range(handle base, std::size_t size) :
	m_base(base), m_size(size)
{
}

handle range::begin()
{
	return m_base;
}

handle range::end()
{
	return m_base.add(m_size);
}

std::size_t range::size()
{
	return m_size;
}

bool range::contains(handle h)
{
	return h.as<std::uintptr_t>() >= begin().as<std::uintptr_t>() && h.as<std::uintptr_t>() <= end().as<std::uintptr_t>();
}

// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore%E2%80%93Horspool_algorithm
// https://www.youtube.com/watch?v=AuZUeshhy-s
handle scan_pattern(const std::optional<std::uint8_t>* sig, std::size_t length, handle begin, std::size_t module_size)
{
	std::size_t maxShift = length;
	std::size_t max_idx = length - 1;

	//Get wildcard index, and store max shiftable byte count
	std::size_t wild_card_idx{ static_cast<size_t>(-1) };
	for (int i{ static_cast<int>(max_idx - 1) }; i >= 0; --i)
	{
		if (!sig[i])
		{
			maxShift = max_idx - i;
			wild_card_idx = i;
			break;
		}
	}

	//Store max shiftable bytes for non wildcards.
	std::size_t shift_table[UINT8_MAX + 1]{};
	for (std::size_t i{}; i <= UINT8_MAX; ++i)
	{
		shift_table[i] = maxShift;
	}

	//Fill shift table with sig bytes
	for (std::size_t i{ wild_card_idx + 1 }; i != max_idx; ++i)
	{
		shift_table[*sig[i]] = max_idx - i;
	}

	//Loop data
	const auto scan_end = module_size - length;
	for (std::size_t current_idx{}; current_idx != scan_end;)
	{
		for (std::size_t sig_idx{ max_idx }; sig_idx >= 0; --sig_idx)
		{
			if (sig[sig_idx] && *begin.add(current_idx + sig_idx).as<uint8_t*>() != *sig[sig_idx])
			{
				current_idx += shift_table[*begin.add(current_idx + max_idx).as<uint8_t*>()];
				break;
			}
			else if (sig_idx == NULL)
			{
				return begin.add(current_idx);
			}
		}
	}
	return nullptr;
}

handle range::scan(pattern2 const& sig)
{
	auto data = sig.m_bytes.data();
	auto length = sig.m_bytes.size();

	if (auto result = scan_pattern(data, length, m_base, m_size); result)
	{
		return result;
	}

	return nullptr;
}

bool pattern_matches(std::uint8_t* target, const std::optional<std::uint8_t>* sig, std::size_t length)
{
	for (std::size_t i{}; i != length; ++i)
	{
		if (sig[i] && *sig[i] != target[i])
		{
			return false;
		}
	}

	return true;
}

std::vector<handle> range::scan_all(pattern2 const& sig)
{
	std::vector<handle> result{};
	auto data = sig.m_bytes.data();
	auto length = sig.m_bytes.size();

	const auto scan_end = m_size - length;
	for (std::uintptr_t i{}; i != scan_end; ++i)
	{
		if (pattern_matches(m_base.add(i).as<std::uint8_t*>(), data, length))
		{
			result.push_back(m_base.add(i));
		}
	}

	return std::move(result);
}

void batch::add(std::string name, pattern2 pattern, std::function<void(handle)> callback)
{
	m_entries.emplace_back(std::move(name), std::move(pattern), std::move(callback));
}
#define HEX_TO_UPPER(value) "0x" << std::hex << std::uppercase << (DWORD64)value << std::dec << std::nouppercase
void batch::run(range region)
{
	bool all_found = true;
	for (auto& entry : m_entries)
	{
		if (auto result = region.scan(entry.m_pattern))
		{
			if (entry.m_callback)
			{
				std::invoke(std::move(entry.m_callback), result);
				//std::stringstream file_out{}; //I hate this, but not logging it except on fail really helps on speed.
				//file_out << "Found '" << entry.m_name << "' GTA5.exe+" << HEX_TO_UPPER(result.as<DWORD64>() - region.begin().as<DWORD64>());
				///*big::g_log->file_out(file_out);*/
				//file_out.clear();
			}
			else
			{
				all_found = false;
				/*LOG(WARNING) << "Failed to find '" << entry.m_name << "'.";*/
			}
		}
		else
		{
			all_found = false;
			/*LOG(WARNING) << "Failed to find '" << entry.m_name << "'.";*/
		}
	}

	m_entries.clear();
	if (!all_found)
	{
		throw std::runtime_error("Failed to find some patterns.");
	}
}

//model_preview_service::model_preview_service()
//{
//	g_model_preview_service = this;
//}
//
//model_preview_service::~model_preview_service()
//{
//	g_model_preview_service = nullptr;
//}
//
//void model_preview_service::show_ped(Hash hash)
//{
//	m_ped_clone = 0;
//	m_veh_model_hash = 0;
//	m_veh_owned_mods.clear();
//
//	if (m_ped_model_hash != hash)
//	{
//		m_ped_model_hash = hash;
//
//		if (m_ped_model_hash != 0)
//		{
//			m_new_model = true;
//
//			preview_loop();
//		}
//	}
//}
//
//void model_preview_service::show_ped(Hash hash, Ped clone)
//{
//	m_veh_model_hash = 0;
//	m_veh_owned_mods.clear();
//
//	if (m_ped_model_hash != hash || m_ped_clone != clone)
//	{
//		m_ped_model_hash = hash;
//		m_ped_clone = clone;
//
//		if (m_ped_model_hash != 0)
//		{
//			m_new_model = true;
//
//			preview_loop();
//		}
//	}
//}
//
//void model_preview_service::show_vehicle(Hash hash, bool spawn_max)
//{
//	m_ped_model_hash = 0;
//	m_ped_clone = 0;
//	m_veh_owned_mods.clear();
//
//	if (m_veh_model_hash != hash || m_veh_spawn_max != spawn_max)
//	{
//		m_veh_model_hash = hash;
//
//		if (m_veh_model_hash != 0)
//		{
//			m_veh_spawn_max = spawn_max;
//			m_new_model = true;
//
//			preview_loop();
//		}
//	}
//}
//
//void model_preview_service::show_vehicle(const std::map<int, int32_t>& owned_mods, bool spawn_max)
//{
//	m_ped_model_hash = 0;
//	m_ped_clone = 0;
//
//	if (
//		m_veh_spawn_max != spawn_max ||
//		m_veh_owned_mods.size() != owned_mods.size() ||
//		!std::equal(m_veh_owned_mods.begin(), m_veh_owned_mods.end(), owned_mods.begin())
//		) {
//		m_veh_owned_mods.clear();
//
//		auto hash_item = owned_mods.find(CustomVehicleModType::MOD_MODEL_HASH);
//
//		m_veh_model_hash = hash_item->second;
//
//		if (m_veh_model_hash != 0)
//		{
//			m_veh_owned_mods.insert(owned_mods.begin(), owned_mods.end());
//			m_veh_spawn_max = spawn_max;
//			m_new_model = true;
//
//			preview_loop();
//		}
//	}
//}

//void model_preview_service::preview_loop()
//{
//	if (m_running || m_loop_running)
//	{
//		return;
//	}
//
//	m_running = true;
//
//	g_fiber_pool->queue_job([this] {
//		m_loop_running = true;
//
//	while (
//		g_running && m_running && g_gui->is_open() &&
//		(m_ped_model_hash || m_veh_model_hash)
//		) {
//		Vector3 location;
//
//		if (m_ped_model_hash)
//		{
//			location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, 0.f, 5.f, -.5f);
//		}
//		else if (m_veh_model_hash)
//		{
//			location = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(self::ped, 0.f, 10.f, .5f);
//		}
//
//		if (m_current_ent == 0)
//		{
//			m_new_model = false;
//			location.z = -10.f;
//
//			if (m_ped_model_hash)
//			{
//				m_current_ent = ped::spawn(ePedType::PED_TYPE_ARMY, m_ped_model_hash, m_ped_clone, location, 0.f, false);
//
//				ENTITY::SET_ENTITY_HEALTH(m_current_ent, 0, 0);
//				//script::get_current()->yield(20ms);
//				PED::RESURRECT_PED(m_current_ent);
//				AI::CLEAR_PED_TASKS(m_current_ent);
//			}
//			else if (m_veh_model_hash)
//			{
//				if (m_veh_owned_mods.empty())
//				{
//					m_current_ent = vehicle::spawn(m_veh_model_hash, location, 0.f, false);
//				}
//				else
//				{
//					m_current_ent = vehicle::clone_from_owned_mods(m_veh_owned_mods, location, 0.f, false);
//				}
//			}
//
//			if (m_current_ent)
//			{
//				if (m_veh_model_hash && m_veh_spawn_max)
//				{
//					vehicle::max_vehicle(m_current_ent);
//				}
//
//				ENTITY::FREEZE_ENTITY_POSITION(m_current_ent, true);
//				ENTITY::SET_ENTITY_ALPHA(m_current_ent, 0, false);
//				ENTITY::SET_ENTITY_COLLISION(m_current_ent, false, false);
//				ENTITY::SET_CAN_CLIMB_ON_ENTITY(m_current_ent, false);
//				OBJECT::SET_OBJECT_ALLOW_LOW_LOD_BUOYANCY(m_current_ent, false);
//			}
//		}
//		else if (m_new_model)
//		{
//			ENTITY::DETACH_ENTITY(m_current_ent, 1, 1);
//			ENTITY::DELETE_ENTITY(&m_current_ent);
//		}
//		else
//		{
//			if (const int alpha = ENTITY::GET_ENTITY_ALPHA(m_current_ent); alpha < 255)
//			{
//				ENTITY::SET_ENTITY_ALPHA(m_current_ent, std::min<int>(255, alpha + 20), false);
//			}
//
//			ENTITY::SET_ENTITY_HEADING(m_current_ent, m_heading);
//			ENTITY::SET_ENTITY_COORDS(m_current_ent, location.x, location.y, location.z, 0, 0, 0, 0);
//		}
//
//		if (m_heading += 0.5f; m_heading > 359)
//		{
//			m_heading = 0;
//		}
//
//		script::get_current()->yield(15ms);
//	}
//
//	ENTITY::DETACH_ENTITY(m_current_ent, 1, 1);
//	ENTITY::DELETE_ENTITY(&m_current_ent);
//
//	m_current_ent = 0;
//	m_ped_model_hash = 0;
//	m_veh_model_hash = 0;
//	m_veh_owned_mods.clear();
//	m_running = false;
//	m_loop_running = false;
//		});
//}

//void model_preview_service::stop_preview()
//{
//	m_veh_owned_mods.clear();
//	m_running = false;
//}


void* OriginalPTR::CrashPTR = nullptr;

inline uintptr_t g_base_address = (uintptr_t)GetModuleHandle(NULL);
uint64_t hkcrash::hk_nigger_crash(uint64_t data)
{
	uint64_t v3; // rbx

	if (!data) {
		return false;
	}

	v3 = engine::scan_address(g_base_address + 0x15E4D2E, {});

	if (!v3) {
		return false;
	}
	/*return g_hooking->og_nigger_crash.get_original<decltype(&hk_nigger_crash)>()(data);*/
	return static_cast<decltype(&hk_nigger_crash)>(OriginalPTR::CrashPTR)(data);
}
//template<typename T> T ReadMemory(DWORD64 address) { T r; ReadProcessMemory(pHandle, (void*)address, &r, sizeof(T), 0); return r; };
//#define IsValidPtr(x) (x && !IsBadReadPtr(&x, sizeof(void*) && x != nullptr && x > nullptr))
CWaterTune* WaterTune = nullptr;
int getfirstpointer = 1;
int getwaterpointer()
{
	Log::Msg("Water Pointer");
	auto WaterPtr2 = Memory::pattern("48 8B D9 48 6B DB 1C 48 2B F9 48 8B 05 ? ? ? ?");
	DWORD64* d_location = nullptr;
	d_location = (DWORD64*)WaterPtr2.count(1).get(0).get<DWORD64*>(0);
	std::string datar = std::string(std::to_string(reinterpret_cast<DWORD64>(d_location)));
	DWORD64 base_address = DWORD64(GetModuleHandleA(nullptr));
	Log::Msg((char*)datar.c_str());
	Log::Msg((char*)std::string(std::to_string(base_address)).c_str());
	std::stringstream myStrm(datar);
	DWORD64 x;
	myStrm >> x;
	std::string address2;
	stringstream addrs2;
	addrs2 << hex << "0x" << x;
	address2 = addrs2.str();
	Log::Msg((char*)address2.c_str());

	std::string address;
	stringstream addrs;
	addrs << hex << "0x" << base_address;
	address = addrs.str();
	Log::Msg((char*)address.c_str());
	std::stringstream myStrm1;
	myStrm1 << base_address;
	DWORD64 x1;
	myStrm1 >> x1;
	std::stringstream myStrm2(datar);
	DWORD64 x2;
	myStrm2 >> x2;
	DWORD64 in2 = ((DWORD64)x2 - (DWORD64)x1);
	Log::Msg((char*)std::string(std::to_string(in2)).c_str());
	std::string address3;
	stringstream addrs3;
	addrs3 << hex << "0x" << in2;
	address3 = addrs3.str();
	Log::Msg((char*)address3.c_str());
	Addresss::AddressPTR1 = in2;
	/*Addresss::AddressPTR2 = new char[address3.size() + 1];
	strcpy(Addresss::AddressPTR2, address3.c_str());*/
	return 0;
}
int getwatertune()
{
	Log::Msg("Water Tune");
	auto WaterPtr2 = Memory::pattern("0F B6 05 ? ? ? ? 0F 28 4C 24 ?");
	DWORD64* d_location = nullptr;
	d_location = (DWORD64*)WaterPtr2.count(1).get(0).get<DWORD64*>(0);
	std::string datar = std::string(std::to_string(reinterpret_cast<DWORD64>(d_location)));
	DWORD64 base_address = DWORD64(GetModuleHandleA(nullptr));
	Log::Msg((char*)datar.c_str());
	Log::Msg((char*)std::string(std::to_string(base_address)).c_str());
	std::stringstream myStrm(datar);
	DWORD64 x;
	myStrm >> x;
	std::string address2;
	stringstream addrs2;
	addrs2 << hex << "0x" << x;
	address2 = addrs2.str();
	Log::Msg((char*)address2.c_str());

	std::string address;
	stringstream addrs;
	addrs << hex << "0x" << base_address;
	address = addrs.str();
	Log::Msg((char*)address.c_str());
	std::stringstream myStrm1;
	myStrm1 << base_address;
	DWORD64 x1;
	myStrm1 >> x1;
	std::stringstream myStrm2(datar);
	DWORD64 x2;
	myStrm2 >> x2;
	DWORD64 in2 = ((DWORD64)x2 - (DWORD64)x1);
	Log::Msg((char*)std::string(std::to_string(in2)).c_str());
	std::string address3;
	stringstream addrs3;
	addrs3 << hex << "0x" << in2;
	address3 = addrs3.str();
	Log::Msg((char*)address3.c_str());
	Addresss::AddressPTR01 = in2;
	/*Addresss::AddressPTR02 = new char[address3.size() + 1];
	strcpy(Addresss::AddressPTR02, address3.c_str());*/
	return 0;
}
void waterchange::GetWaterTune() {

	static DWORD64 CWateTune_Pattern, CWaterTune_Ptr = 0;
	/*if (CWateTune_Pattern == 0)CWateTune_Pattern = (addy.BASE + Tools->FindPattern("\x0F\xB6\x05\x00\x00\x00\x00\x0F\x28\x4C\x24\x00", "xxx????xxxx?"));*/
	uintptr_t base_address = uintptr_t(GetModuleHandleA(nullptr));

	if (CWateTune_Pattern == 0)
		CWateTune_Pattern = engine::scan_address(base_address + 0x585C28, {});

	/*if (CWateTune_Pattern == 0)CWateTune_Pattern = (base_address + 0x585c28);*/
	if (CWaterTune_Ptr == 0 && CWaterTune_Ptr != 0)CWaterTune_Ptr = ((CWateTune_Pattern + *(DWORD*)(CWateTune_Pattern + 0x3)) + 0x4);

	CWaterTune* WaterTune = reinterpret_cast<CWaterTune*>(CWaterTune_Ptr);
	WaterTune->fSpecularFalloff = 0.0f;
}

void waterchange::ChangeWater() {
	if (GetKeyState(VK_F5) & 0x800 || GetKeyState(VK_F6) & 0x800 || GetKeyState(VK_F7) & 0x800 || GetKeyState(VK_F8) & 0x800) //Only access on change! otherwise you will lose a lot performance.
		for (int i = 0; i < 821; i++) { //821 = max water items.
			static DWORD64 Water_Pattern, WaterPtr, WaterPtrX = 0;

			getwatertune();
			getwaterpointer();
			waterchange::GetWaterTune();

			uintptr_t base_address = uintptr_t(GetModuleHandleA(nullptr));
			if (Water_Pattern == 0)
				Water_Pattern = engine::scan_address(base_address + 0x58a695, {}) + 0xA;



			/*if (Water_Pattern == 0)Water_Pattern = (addy.BASE + Tools->FindPattern("\x48\x8B\xD9\x48\x6B\xDB\x1C\x48\x2B\xF9\x48\x8B\x05\x00\x00\x00\x00 ", "xxxxxxxxxxxxx????")) + 0xA;*/




			if (WaterPtr == 0 && Water_Pattern != 0)WaterPtr = ((Water_Pattern + *(DWORD*)(Water_Pattern + 0x3)) + 0x7);
			WaterPtrX = *(DWORD64*)WaterPtr;


			if (&WaterPtrX != nullptr) {
				CWaterDataItem* Water = (CWaterDataItem*)(WaterPtrX + (i * 0x1C));

				if (GetKeyState(VK_F5) & 0x800)Water->fHeight = -1000.0f; //Remove Water
				if (GetKeyState(VK_F6) & 0x800)Water->fHeight = 0.0f; //Restore Water

				if (GetKeyState(VK_F7) & 0x800) { //Glass Water
					Water->iAlphaNE = 0;
					Water->iAlphaNW = 0;
					Water->iAlphaSE = 0;
					Water->iAlphaSW = 0;
					if ((WaterTune != nullptr))WaterTune->fDisturbFoamScale = 0.0f;
				}
				if (GetKeyState(VK_F8) & 0x800) { //Normal Water
					Water->iAlphaNE = 26;
					Water->iAlphaNW = 26;
					Water->iAlphaSE = 26;
					Water->iAlphaSW = 26;
					if ((WaterTune != nullptr))WaterTune->fDisturbFoamScale = 0.05f;
				}
			}
		}
}

//static CWaterQuad* WaterQuads;
//static std::vector<float> WaterHeights;
//
//static CWaterQuad* GetWaterQuads()
//{
//	static Handle handle = Memory::Pattern("? 6B C9 1C ? 03 0D ? ? ? ? 66 ? 03 C5 66 89 05 ? ? ? ?");
//	if (handle.IsValid())
//	{
//		return *handle.At(6).Into().Get<CWaterQuad*>();
//	}
//	return nullptr;
//}
//
//static void OnStart()
//{
//	WaterQuads = GetWaterQuads();
//	if (WaterQuads)
//	{
//		for (int i = 0; i < 821; i++) // 821 = Max Water Items
//		{
//			WaterHeights.push_back(WaterQuads[i].Z); // Save Water Heights
//			WaterQuads[i].Z = -1000.0f;              // Remove Water
//		}
//	}
//}
//
//static void OnStop()
//{
//	if (WaterQuads)
//	{
//		for (int i = 0; i < 821; i++) // 821 = Max Water Items
//		{
//			WaterQuads[i].Z = WaterHeights.at(i); // Restore Water
//		}
//		WaterHeights.clear(); // Clear Storage Vector
//	}
//}

inline std::unordered_map<CommandAccessLevel, const char*> COMMAND_ACCESS_LEVELS =
{
	{ CommandAccessLevel::NONE, "None" },
	{ CommandAccessLevel::FRIENDLY, "Friendly" },
	{ CommandAccessLevel::AGGRESSIVE, "Aggressive" },
	{ CommandAccessLevel::TOXIC, "Toxic" },
	{ CommandAccessLevel::ADMIN, "Admin (!)" }
};

friends_service2::friends_service2()
{
	g_friends_service = this;
}

friends_service2::~friends_service2()
{
	g_friends_service = nullptr;
}

//bool friends_service2::is_friend(CNetGamePlayer2* net_player)
bool friends_service2::is_friend(CNetGamePlayer* net_player)
{
	if (net_player == nullptr)
		return false;

	const auto rockstar_id = net_player->get_net_data()->m_gamer_handle_2.m_rockstar_id;
	for (std::uint32_t i = 0; i < g_GameVariables->m_friend_registry->m_friend_count; i++)
		if (rockstar_id == g_GameVariables->m_friend_registry->get(i)->m_rockstar_id)
			return true;
	return false;
}

//player::player(CNetGamePlayer2* net_game_player)
player::player(CNetGamePlayer* net_game_player)
	: m_net_game_player(net_game_player)
{
	m_is_friend = friends_service2::is_friend(net_game_player);
}

CVehicle* player::get_current_vehicle() const
{
	if (const auto ped = this->get_ped(); ped != nullptr)
		if (const auto vehicle = ped->m_vehicle; vehicle != nullptr)
			return vehicle;
	return nullptr;
}

int64_t player::get_rockstar_id() const
{
	if (auto net_data = get_net_data())
		return net_data->m_gamer_handle.m_rockstar_id;
	return 0;
}

const char* player::get_name() const
{
	return m_net_game_player == nullptr ? "" : m_net_game_player->get_name();
}

rage::rlGamerInfo* player::get_net_data() const
{
	return m_net_game_player == nullptr ? nullptr : m_net_game_player->get_net_data();
}

CNetGamePlayer* player::get_net_game_player() const
//CNetGamePlayer2* player::get_net_game_player() const
{
	return m_net_game_player;
}

CPed* player::get_ped() const
{
	if (const auto player_info = this->get_player_info(); player_info != nullptr)
		if (const auto ped = player_info->m_ped; ped != nullptr)
			return ped;
	return nullptr;
}

CPlayerInfo* player::get_player_info() const
{
	if (m_net_game_player != nullptr && m_net_game_player->m_player_info != nullptr)
		return m_net_game_player->m_player_info;
	return nullptr;
}

//snPlayer* player::get_session_player()
//{
//	for (std::uint32_t i = 0; i < gta_util::get_network()->m_game_session_ptr->m_player_count; i++)
//	{
//		if (gta_util::get_network()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == get_net_data()->m_host_token)
//		{
//			return gta_util::get_network()->m_game_session_ptr->m_players[i];
//		}
//	}
//
//	if (gta_util::get_network()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == get_net_data()->m_host_token)
//		return &gta_util::get_network()->m_game_session_ptr->m_local_player;
//
//	return nullptr;
//}
//
//snPeer* player::get_session_peer()
//{
//	for (std::uint32_t i = 0; i < gta_util::get_network()->m_game_session_ptr->m_peer_count; i++)
//	{
//		//if (gta_util::get_network()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle_2.m_rockstar_id == get_net_data()->m_gamer_handle_2.m_rockstar_id)
//		if (gta_util::get_network()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle_2.m_rockstar_id == get_net_data()->m_gamer_handle_2.m_rockstar_id)
//		{
//			return gta_util::get_network()->m_game_session_ptr->m_peers[i];
//		}
//	}
//
//	return nullptr;
//}

rage::snPlayer* player::get_session_player()
{
	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_player_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(Features::Online::selectedPlayer)->get_net_data()->m_host_token)
		{
			return GetNetwork()->m_game_session_ptr->m_players[i];
		}

		if (GetNetwork()->m_game_session_ptr->m_local_player.m_player_data.m_host_token == g_GameVariables->m_GetNetPlayer(Features::Online::selectedPlayer)->get_net_data()->m_host_token)
			return &GetNetwork()->m_game_session_ptr->m_local_player;
	}

	return nullptr;
}

rage::snPeer* player::get_session_peer()
{
	for (std::uint32_t i = 0; i < GetNetwork()->m_game_session_ptr->m_peer_count; i++)
	{
		if (GetNetwork()->m_game_session_ptr->m_peers[i]->m_peer_data.m_gamer_handle_2.m_rockstar_id == g_GameVariables->m_GetNetPlayer(Features::Online::selectedPlayer)->get_net_data()->m_gamer_handle_2.m_rockstar_id)
		{
			return GetNetwork()->m_game_session_ptr->m_peers[i];
		}
	}
	return nullptr;
}



uint8_t player::id() const
{
	return m_net_game_player == nullptr ? -1 : m_net_game_player->m_player_id;
}

bool player::is_host() const
{
	return m_net_game_player == nullptr ? false : m_net_game_player->is_host();
}

bool player::is_friend() const
{
	return m_is_friend;
}


bool player::is_valid() const
{
	return m_net_game_player == nullptr ? false : m_net_game_player->is_valid();
}

//bool player::equals(const CNetGamePlayer2* net_game_player) const
bool player::equals(const CNetGamePlayer* net_game_player) const
{
	return net_game_player == m_net_game_player;
}

std::string player::to_lowercase_identifier() const
{
	std::string lower = this->get_name();
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

	return lower;
}

inline void m_function::DrawChatScaleform(char* msg, const char* player_name)
{
	int scaleform = GRAPHICS::REQUEST_SCALEFORM_MOVIE("MULTIPLAYER_CHAT");
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(scaleform, "ADD_MESSAGE");
	//GRAPHICS::_0xE83A3E3557A56640(const_cast<PCHAR>(arg.c_str()));
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING((char*)player_name); // player name
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_LITERAL_STRING(msg); // content
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_TEXTURE_NAME_STRING(UI::_GET_LABEL_TEXT("MP_CHAT_ALL")); // scope //HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION(is_team ? "MP_CHAT_TEAM" : "MP_CHAT_ALL")
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_BOOL(false); // teamOnly
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(1); // eHudColour //(int)HudColor::HUD_COLOUR_PURE_WHITE
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	GRAPHICS::BEGIN_SCALEFORM_MOVIE_METHOD(scaleform, "SET_FOCUS");
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(1); // VISIBLE_STATE_DEFAULT
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(0); // scopeType (unused)
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(0); // scope (unused)
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_PLAYER_NAME_STRING((char*)player_name); // player
	GRAPHICS::SCALEFORM_MOVIE_METHOD_ADD_PARAM_INT(1); // eHudColour //(int)HudColor::HUD_COLOUR_PURE_WHITE
	GRAPHICS::END_SCALEFORM_MOVIE_METHOD();
	GRAPHICS::DRAW_SCALEFORM_MOVIE_FULLSCREEN(scaleform, 255, 255, 255, 255, 0);
}

void m_function::SendChatMessage(char* a1)
{
	if (*g_GameVariables->m_IsSessionStarted)
	{
		if (const auto net_game_player = GetNetworkPlayerMgr()->m_local_net_player; net_game_player)
		{
			if (g_GameFunctions->m_SendChatMessage(*g_GameFunctions->m_SendChatPointer, net_game_player->get_net_data(), a1, false))
				m_function::DrawChatScaleform(a1, net_game_player->get_name());
		}
	}
}

void m_function::SendTimedChatMessage(char* a1)
{
	if (g_Settings.m_ChatSpammer && *g_GameVariables->m_IsSessionStarted)
	{
		if (g_Settings.m_ChatSpammer == 0)
		{
		}
		else
		{
			static int timer;
			/*if ((GetTickCount64() - timer) > g_Settings.m_ChatSpammerTimer)
			{*/
			DWORD ticks = GetTickCount64();
			DWORD milliseconds = ticks % 1000;
			ticks /= 1000;
			DWORD seconds = ticks % 60;
			//ticks /= 60;
			//DWORD minutes = ticks % 60;
			//ticks /= 60;
			//DWORD hours = ticks; // may exceed 24 hours.
					/*int getTimer = TIME::GET_MILLISECONDS_PER_GAME_MINUTE();*/
			int getTimer = seconds;
			if (getTimer % g_Settings.m_ChatSpammerTimer == 0)
			{
				if (const auto net_game_player = GetNetworkPlayerMgr()->m_local_net_player; net_game_player)
				{
					if (g_GameFunctions->m_SendChatMessage(*g_GameFunctions->m_SendChatPointer, net_game_player->get_net_data(), a1, false))
						m_function::DrawChatScaleform(a1, net_game_player->get_name());
				}
			}
			/*timer = GetTickCount64();*/
		}
	}
}


rage2::packet::packet() :
	m_buffer(m_data, 0x4000)
{
}
//void rage2::packet::send(player_ptr player, int connection_id)
void rage2::packet::send(uint32_t msg_id)
{
	/*g_GameFunctions->m_queue_packet(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, msg_id, m_data, (m_buffer.m_curBit + 7) >> 3, 1, nullptr);*/
	g_GameFunctions->m_queue_packet(GetNetwork()->m_game_session_ptr->m_net_connection_mgr, msg_id, m_data, (m_buffer.m_curBit + 7) >> 3, 1, nullptr);
}

void rage2::packet::send(int player, int connection_id)/*, bool is_peer*/
{
	/*if (is_peer)
	{*/
	auto mgr = GetNetwork()->m_game_session_ptr->m_net_connection_mgr;
	auto peer = g_GameFunctions->m_GetConnectionPeer(mgr, player);
	g_GameFunctions->m_send_packet(mgr, (netConnectionPeer*)peer, connection_id, m_data, (m_buffer.m_curBit + 7) >> 3, 0x1000000);
	/*g_GameFunctions->m_send_packet(mgr, (netConnectionPeer*)peer, connection_id, m_data, (m_buffer.m_curBit + 7) >> 3, 0x1000000);*/
/*}
else*/
//send(get_session_player(player)->m_player_data.m_peer_id_2, connection_id, false);
}


/*player_service::player_service()
: m_self(), m_selected_player(m_dummy)
{
	g_player_service = this;

	const auto network_player_mgr = gta_util::get_network_player_mgr();
	if (!network_player_mgr)
		return;

	m_self = &network_player_mgr->m_local_net_player;

	for (uint16_t i = 0; i < network_player_mgr->m_player_limit; ++i)
		player_join(network_player_mgr->m_player_list[i]);
}*/

player_service::~player_service()
{
	g_player_service = nullptr;
}

void player_service::do_cleanup()
{
	m_player_to_use_end_session_kick.reset();
	m_player_to_use_complaint_kick.reset();
	m_selected_player = m_dummy;
	m_players.clear();
}

//player_ptr player_service::get_by_msg_id(uint32_t msg_id) const
//{
//	for (const auto& [_, player] : m_players)
//		if (player->get_net_game_player()->m_msg_id == msg_id)
//			return player;
//	return nullptr;
//}
//
//player_ptr player_service::get_by_id(uint32_t id) const
//{
//	for (const auto& [_, player] : m_players)
//		if (player->id() == id)
//			return player;
//	return nullptr;
//}
//
//player_ptr player_service::get_by_host_token(uint64_t token) const
//{
//	for (const auto& [_, player] : m_players)
//		if (player->get_net_data()->m_host_token == token)
//			return play::player;
//	return nullptr;
//}

player::player_ptr player_service::get_by_host_token(uint64_t token) const
{
	for (const auto& [_, player] : m_players)
		if (player->get_net_data()->m_host_token == token)
			return player;
	return nullptr;
}

//CNetGamePlayer2* get_by_host_token(uint64_t token)
CNetGamePlayer* get_by_host_token(uint64_t token)
{
	for (int i = 0; i < 32; i++)
	{
		if (g_GameVariables->m_GetNetPlayer(i)->get_net_data()->m_host_token == token)
			return g_GameVariables->m_GetNetPlayer(i);
		return nullptr;
	}
}

#include <ranges>
#include <limits>

//player_ptr player_service::get_closest(bool exclude_friends) const
//{
//	float closest_distance = std::numeric_limits<float>::max();
//	player_ptr closest_player = nullptr;
//	for (auto player : m_players | std::ranges::views::values)
//	{
//		if (exclude_friends && player->is_friend())
//			continue;
//
//		if (player && player->get_ped() && player->get_ped()->get_position())
//		{
//			if (math::distance_between_vectors(*player->get_ped()->get_position(),
//				*g_player_service->get_self()->get_ped()->get_position())
//				< closest_distance)
//			{
//				closest_distance = math::distance_between_vectors(*player->get_ped()->get_position(),
//					*g_player_service->get_self()->get_ped()->get_position());
//				closest_player = player;
//			}
//		}
//	}
//
//	return closest_player;
//}



player::player_ptr player_service::get_selected() const
{
	return m_selected_player;
}

player::player_ptr player_service::get_self()
{
	if (!m_self_ptr || !m_self_ptr->equals(*m_self))
	{
		m_self_ptr = std::make_shared<player>(*m_self);
		m_self_ptr->command_access_level = CommandAccessLevel::ADMIN;
	}

	return m_self_ptr;
}
//
//void player_service::player_join(CNetGamePlayer* net_game_player)
//{
//	if (net_game_player == nullptr || net_game_player == *m_self) return;
//
//	auto plyr = std::make_shared<player>(net_game_player);
//	m_players.insert({
//		plyr->get_name(),
//		std::move(plyr)
//		});
//}
//
//void player_service::player_leave(CNetGamePlayer* net_game_player)
//{
//	if (net_game_player == nullptr)
//		return;
//
//	if (m_selected_player && m_selected_player->equals(net_game_player))
//		m_selected_player = m_dummy;
//
//	if (auto it = std::find_if(m_players.begin(), m_players.end(), [net_game_player](const auto& p) { return p.second->id() == net_game_player->m_player_id; }); it != m_players.end())
//	{
//		if (m_player_to_use_end_session_kick == it->second)
//			m_player_to_use_end_session_kick = std::nullopt;
//
//		if (m_player_to_use_complaint_kick == it->second)
//			m_player_to_use_complaint_kick = std::nullopt;
//
//		m_players.erase(it);
//	}
//}


void player_service::set_selected(player::player_ptr plyr)
{
	m_selected_player = plyr;
}





//player_all_component::player_all_component(player_command* parent, const std::string& name, const std::string& label, const std::string& description, std::optional<std::uint8_t> num_args) :
//	command(name + "all", label, description, num_args),
//	m_parent(parent)
//{
//}
//
//void player_all_component::execute(const std::vector<std::uint64_t>& args, const std::shared_ptr<command_context> ctx)
//{
//	g_fiber_pool->queue_job([this, args, &ctx]
//		{
//			g_player_service->iterate([this, args, &ctx](const player_entry& player)
//				{
//					m_parent->execute(player.second, args, ctx);
//				});
//		});
//}
//
//std::optional<std::vector<std::uint64_t>> player_all_component::parse_args(const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx)
//{
//	return m_parent->parse_args_p(args, ctx);
//}
//
//player_command::player_command(const std::string& name, const std::string& label, const std::string& description, std::optional<std::uint8_t> num_args, bool make_all_version) :
//	command(name, label, description, num_args.has_value() ? std::optional{ num_args.value() + 1 } : std::nullopt)
//{
//	if (make_all_version)
//		m_all_component = std::make_unique<player_all_component>(this, name, label, description, num_args);
//}
//
//void player_command::execute(const std::vector<std::uint64_t>& args, const std::shared_ptr<command_context> ctx)
//{
//	g_fiber_pool->queue_job([this, args, ctx]
//		{
//			std::vector<std::uint64_t> new_args;
//
//	// TODO: This looks ugly and inefficient
//	for (int i = 1; i < m_num_args; i++)
//		new_args.push_back(args[i]);
//
//	if (g_player_service->get_self()->id() == args[0])
//	{
//		execute(g_player_service->get_self(), new_args, ctx);
//		return;
//	}
//
//	for (auto& plyr : g_player_service->players())
//	{
//		if (plyr.second->id() == args[0])
//		{
//			execute(plyr.second, new_args, ctx);
//			return;
//		}
//	}
//
//	ctx->report_error(std::format("Tried to execute command {}, but a player with index {} was not found", m_name, args[0]));
//		});
//}
//
//std::optional<std::vector<std::uint64_t>> player_command::parse_args(const std::vector<std::string>& args, const std::shared_ptr<command_context> ctx)
//{
//	std::vector<std::string> new_args;
//	std::vector<std::uint64_t> result;
//
//	if (args[0] == "me" || args[0] == "self")
//	{
//		result.push_back(ctx->get_sender()->id());
//	}
//	else
//	{
//		int plyr_id = -1;
//
//		for (auto& plyr : g_player_service->players())
//		{
//			if (stricmp(plyr.second->get_name(), args[0].c_str()) == 0)
//			{
//				plyr_id = plyr.second->id();
//				break;
//			}
//		}
//
//		if (stricmp(g_player_service->get_self()->get_name(), args[0].c_str()) == 0 || (g.spoofing.spoof_username && stricmp(g.spoofing.username.c_str(), args[0].c_str()) == 0))
//		{
//			plyr_id = g_player_service->get_self()->id();
//		}
//
//		if (ctx->get_access_level() != CommandAccessLevel::ADMIN && (get_access_level() == CommandAccessLevel::TOXIC || get_access_level() == CommandAccessLevel::AGGRESSIVE) && plyr_id == self::id)
//		{
//			ctx->report_error("Permission denied, cannot call toxic commands on me");
//			return std::nullopt;
//		}
//
//		if (plyr_id == -1)
//		{
//			ctx->report_error(std::format("Cannot find player with name {} in command {}", args[0], m_name));
//			return std::nullopt;
//		}
//
//		result.push_back(plyr_id);
//	}
//
//	for (int i = 1; i < args.size(); i++)
//		new_args.push_back(args[i]);
//
//	auto res = parse_args_p(new_args, ctx);
//	if (!res.has_value())
//		return std::nullopt;
//
//	for (auto& p : res.value())
//		result.push_back(p);
//
//	return result;
//}
//
//void player_command::call(player_ptr player, const std::vector<std::uint64_t>& args, const std::shared_ptr<command_context> ctx)
//{
//	// TODO: Code duplication
//	if (m_num_args.has_value() && args.size() != (m_num_args.value() - 1))
//	{
//		ctx->report_error(std::format("Command {} called with the wrong number of arguments. Expected {}, got {}", m_name, m_num_args.value(), args.size()));
//		return;
//	}
//
//	g_fiber_pool->queue_job([this, player, args, ctx] {
//		if (player->is_valid())
//		execute(player, args, ctx);
//		});
//}


int playerhost()
{
	for (int i = 0; i < 32; i++)
	{
		auto player2 = g_player_service->get_by_host_token(GetNetwork()->m_game_session_ptr->m_players[i]->m_player_data.m_host_token);
	}
	return 0;
}

//void waiting(DWORD time)
//{
//	WAIT(time);
//}

//bool force_host(rage::joaat_t hash)
//{
//	if (auto launcher = gta_util::find_script_thread(hash); launcher && launcher->m_net_component)
//	{
//		for (int i = 0; !launcher->m_net_component->is_local_player_host(); i++)
//		{
//			if (i > 200)
//				return false;
//
//			//Log::Msg("Get ForceHost");
//			/*((CGameScriptHandlerNetComponent*)launcher->m_net_component)->send_host_migration_event(g_player_service->get_self()->get_net_game_player());*/
//			((CGameScriptHandlerNetComponent*)launcher->m_net_component)->send_host_migration_event(g_GameVariables->m_GetNetPlayer(Features::playerme));
//			//Log::Msg("ForceHost Completed");
//			/*script::get_current()->yield(10ms);*/
//			WAIT(100);
//			/*DWORD ticks = GetTickCount64();
//		DWORD milliseconds = ticks % 1000;
//		ticks /= 1000;
//		DWORD seconds = ticks % 60;
//		ticks /= 60;
//		int getTimer = seconds;
//		if (getTimer % 1 == 0)
//		{
//		}*/
//			if (!launcher->m_stack || !launcher->m_net_component)
//				return false;
//		}
//	}
//
//	return true;
//}
//void bail_kick(int playerid)
//{
//	//player_ptr player;
//
//	/*eGlobal::NetworkBail, PlayerID,
//		* ScriptGlobal(NeverWanted1).Add(1).Add(a1 * NeverWanted2).Add(NeverWanted3).As<int*>()
//};
//g_GameFunctions->m_TriggerScriptEvent(1, args, sizeof(args), 1 << a1); */
//
//
//	const size_t arg_count = 3;
//	int64_t args[arg_count] =
//	{
//		(int64_t)eRemoteEvent::NetworkBail,
//		(int64_t)PLAYER::PLAYER_ID(),
//		//scr_globals::gpbd_fm_3.as<GPBD_FM_3*>()->Entries[player->id()].ScriptEventReplayProtectionCounter
//		ScriptGlobal::ScriptGlobal(1894573).As<GPBD_FM_3*>()->Entries[g_GameVariables->m_GetNetPlayer(playerid)->m_player_id].ScriptEventReplayProtectionCounter///*player->id()*/
//	};
//	g_GameFunctions->m_trigger_script_event(1, args, arg_count, 1 << playerid);//player->id()
//}





//void sendmillion::moneymillion(int player)
//{
//	if (ForceHost(RAGE_JOAAT("freemode")))
//	{
//		if (auto freemode_thread = findscriptthread::findscriptthread2(RAGE_JOAAT("freemode")); freemode_thread && freemode_thread->m_net_component)//
//		{
//			freemode_thread->m_net_component->block_host_migration(true);
//
//			rage2::packet msg{};
//			msg.write_message(eNetMessage::MsgScriptMigrateHost);
//			freemode_thread->m_handler->get_id()->serialize(&msg.m_buffer);
//			msg.write<int>(0, 16);
//			msg.write<int>(0, 32);
//			/*auto msg_id = player->get_net_game_player()->m_msg_id;*/
//			auto msg_id = g_GameVariables->m_GetNetPlayer(player)->m_msg_id;
//			msg.send(msg_id);
//
//			//LOG(INFO) << "Gave you 15m bozo.";
//
//			freemode_thread->m_context.m_stack_size *= 2;
//
//			int64_t args[4] = { milliondrop, PLAYER::PLAYER_ID(), 288806, 0 };
//			g_GameFunctions->m_trigger_script_event(1, args, 4, 1 << Features::Online::selectedPlayer);
//
//			int64_t args1[4] = { milliondrop, PLAYER::PLAYER_ID(), 288807, 15000000 };
//			g_GameFunctions->m_trigger_script_event(1, args1, 4, 1 << Features::Online::selectedPlayer);
//
//			int64_t args2[4] = { milliondrop, PLAYER::PLAYER_ID(), 288808, 393059668 };
//			g_GameFunctions->m_trigger_script_event(1, args2, 4, 1 << Features::Online::selectedPlayer);
//
//			int64_t args3[4] = { milliondrop, PLAYER::PLAYER_ID(), 288809, 0 };
//			g_GameFunctions->m_trigger_script_event(1, args3, 4, 1 << Features::Online::selectedPlayer);
//
//			int64_t args4[4] = { milliondrop, PLAYER::PLAYER_ID(), 288810, 0 };
//			g_GameFunctions->m_trigger_script_event(1, args4, 4, 1 << Features::Online::selectedPlayer);
//
//			int64_t args5[4] = { milliondrop, PLAYER::PLAYER_ID(), 288811, 1 };
//			g_GameFunctions->m_trigger_script_event(1, args5, 4, 1 << Features::Online::selectedPlayer);
//
//			int64_t args6[4] = { milliondrop, PLAYER::PLAYER_ID(), 288812, 2147483647 };
//			g_GameFunctions->m_trigger_script_event(1, args6, 4, 1 << Features::Online::selectedPlayer);
//
//			int64_t args7[4] = { milliondrop, PLAYER::PLAYER_ID(), 26003, 1 };
//			g_GameFunctions->m_trigger_script_event(1, args7, 4, 1 << Features::Online::selectedPlayer);
//
//		}
//	}
//}

//static inline const script_global session(1574589);
//static inline const script_global session2(1575032);
//static inline const script_global session3(32829);
//static inline const script_global session4(1574941);
//static inline const script_global session5(1575007);
//static inline const script_global session6(2695909);
//
//static inline const script_global gooch(1882037);

//#define JoinSession1 1575032 //Global_1575020
//#define JoinSession2 1574589 //Global_1574589

#define JoinSession1 1574589 //Global_1574589
#define JoinSession2 1575032 //Global_1575020
//
//inline bool jointype(int SessionID)
////inline bool jointype(eSessionType SessionID)
////void ModMenu::jointype(std::int32_t SessionID)//SessionTypes
////void ModMenu::jointype(eSessionType SessionID)//SessionTypes
//{
//	if (SessionID == eSessionType::LEAVE_ONLINE)
//	{
//		Log::Msg("LEAVE_ONLINE JoinType");
//		//*globalHandle(JoinSession2).At(2).As<int*>() = -1;
//		//*globalHandle(JoinSession2).As<int*>() = 1;
//		//*globalHandle(JoinSession2).As<int*>() = 0;
//		*ScriptGlobal::ScriptGlobal(JoinSession2).Add(2).As<int*>() = -1;
//		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 1;
//		WAIT(200);
//		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 0;
//	}
//	else
//	{
//		Log::Msg("SessionID JoinType");
//		*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = /*(int)*/SessionID;//rage::rlSessionInfo*
//		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 1;
//		/*script::get_current()->yield(200ms);*/
//		WAIT(200);
//		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 0;
//		//*globalHandle(JoinSession1).As<int*>() = (int)session.id;
//		//*globalHandle(JoinSession2).As<int*>() = 1;
//		///*script::get_current()->yield(200ms);*/
//		//WAIT(200);
//		//*globalHandle(JoinSession2).As<int*>() = 0;
//	}
//	return true;
//}
void SessionStart(std::int32_t SessionID)
{
	//g_UiManager->m_Opened = false;
	if (SessionID == SessionTypes::LeaveOnline)
	{
		*ScriptGlobal::ScriptGlobal(JoinSession2).Add(2).As<int*>() = -1;
		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 1;
		//g_FiberScript->Wait(200);
		WAIT(500);
		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 0;
	}
	else
	{
		int myInt = static_cast<int>(SessionID);
		*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = myInt;
		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 1;
		//g_FiberScript->Wait(200);
		WAIT(500);
		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 0;
	}
}

//#include <string_view>
//#include <cstdint>
//
//// Typedef for the hash type (assuming joaat_t is a 32-bit unsigned integer)
//using joaat_t = uint32_t;
//
//constexpr char constexpr_to_lower(char c) {
//	return c >= 'A' && c <= 'Z' ? c | (1 << 5) : c;
//}
//
//// User-defined literal for computing JOAAT hash at compile-time
//constexpr rage::joaat_t operator""_J(const char* s, std::size_t n) {
//	rage::joaat_t result = 0;
//
//	for (std::size_t i = 0; i < n; i++) {
//		result += constexpr_to_lower(s[i]);
//		result += (result << 10);
//		result ^= (result >> 6);
//	}
//
//	result += (result << 3);
//	result ^= (result >> 11);
//	result += (result << 15);
//
//	return result;
//}
///*inline */bool join_type(SessionTypes session)
/*inline */void jointype(SessionTypes session)
{
	//SCRIPT::REQUEST_SCRIPT_WITH_NAME_HASH(RAGE_JOAAT("pausemenu_multiplayer")/*_J*/);

	//while (!SCRIPT::HAS_SCRIPT_WITH_NAME_HASH_LOADED(RAGE_JOAAT("pausemenu_multiplayer")/*_J*/))
	//	/*script::get_current()->yield();*/
	//	WAIT(0);
	//*scr_globals::sctv_spectator.as<int*>() = (session == eSessionType::SC_TV ? 1 : 0); // If SCTV then enable spectator mode

	if (session == SessionTypes::LeaveOnline)
	{
		*ScriptGlobal::ScriptGlobal(JoinSession1).Add(2).As<int*>() = -1;
		*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = 1;
		WAIT(200);
		*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = 0;

	}
		//*scr_globals::session.at(2).as<int*>() = -1;
	else
	{
		//*scr_globals::session.at(2).as<int*>() = 0;
		//*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = 0;
		/**ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = (int)session;*/
		*ScriptGlobal::ScriptGlobal(JoinSession2).As<int*>() = 1;
		*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = 1;
		//*scr_globals::session2.as<int*>() = (int)session;
		WAIT(200);
		*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = 0;
		//*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = 0;
	}

	/**scr_globals::session.as<int*>() = 1;

	if (*g_pointers->m_gta.m_is_session_started && session != eSessionType::LEAVE_ONLINE)
	{
		*scr_globals::transition_state.as<eTransitionState*>() = eTransitionState::TRANSITION_STATE_LOOK_TO_JOIN_ANOTHER_SESSION_FM;
	}
	else if (session == eSessionType::LEAVE_ONLINE)
	{
		*scr_globals::transition_state.as<eTransitionState*>() = eTransitionState::TRANSITION_STATE_RETURN_TO_SINGLEPLAYER;
	}*/

	/*scr_functions::reset_session_data({ true, true });
	*scr_globals::session3.as<int*>() = 0;
	*scr_globals::session4.as<int*>() = 1;
	*scr_globals::session5.as<int*>() = 32;

	*/
	if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(RAGE_JOAAT("maintransition")/*_J*/) == 0)
	{
		/**scr_globals::session6.as<int*>() = 1;
		script::get_current()->yield(200ms);
		*scr_globals::session.as<int*>() = 0;*/
		*ScriptGlobal::ScriptGlobal(JoinSession1).As<int*>() = 0;
	}
	//SCRIPT::SET_SCRIPT_WITH_NAME_HASH_AS_NO_LONGER_NEEDED(RAGE_JOAAT("pausemenu_multiplayer")/*_J*/);
	//return true;
}

/*inline */void joinsession(const rage::rlSessionInfo& info)
{
	//if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(RAGE_JOAAT("maintransition")/*_J*/) != 0 || STREAMING::IS_PLAYER_SWITCH_IN_PROGRESS())
	//{
	//	//g_notification_service.push_error("RID_JOINER"_T.data(), "RID_JOINER_SWITCH_IN_PROGRESS"_T.data());
	//	return;
	//}

	/*g.session.join_queued = true;
	g.session.info = info;*/

	g_Settings.m_JoinQueue = true;
	g_Settings.m_SessionInfo = info;

	jointype(SessionTypes::NewPublic);
	if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(RAGE_JOAAT("maintransition")/*_J*/) == 0)
	{
		/*g.session.join_queued = false;*/
		g_Settings.m_JoinQueue = false;
		//g_notification_service.push_error("RID_JOINER"_T.data(), "RID_JOINER_UNABLE_MAINTRANSITION"_T.data());
	}
	return;
}
void m_features::JoinByRockstarID(uint64_t rid, bool spectate)
{

	/*FiberHandle myFiberTask = [=]()
		{*/
	if (SCRIPT::_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(/*CONSTEXPR_JOAAT*/RAGE_JOAAT("maintransition")) != 0 || STREAMING::IS_PLAYER_SWITCH_IN_PROGRESS())//GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH
	{
		//ImGui::InsertNotification({ ImGuiToastType_Error, ImGuiToastMedium, "Player switch in progress, wait a bit.", "" });
		return;
	}

	rage::rlGamerHandle player_handle(rid);
	rage::rlSessionByGamerTaskResult result;
	bool success = false;
	rage::rlTaskStatus state{};

	if (g_GameFunctions->m_StartGetSessionByGamerHandle(0, &player_handle, 1, &result, 1, &success, &state))
	{
		while (state.status == 1)
			///*g_FiberScript->*/Wait(0);
			WAIT(0);

		if (state.status == 3 && success)
		{
			g_Settings.m_JoinQueue = true;
			g_Settings.m_SessionInfo = result.m_session_info;
			g_Settings.m_SaveRIDJoinerTarget = result.m_gamer_handle.m_rockstar_id;

			joinsession(result.m_session_info);
			//SessionStart(static_cast<int32_t>(SessionTypes::NewPublic));
			Log::Msg("After JoinType");
		}
		/*else
		{
			ImGui::InsertNotification({ ImGuiToastType_Error, ImGuiToastMedium, "Player is offline (%i).", rid });
			return;
		}*/
	}

};
bool m_function::is_online = false;
bool m_function::IsRIDOnline(int rid)
{
	bool success = false;

	rage::rlTaskStatus state{};
	rage::rlSessionByGamerTaskResult result;
	rage::rlGamerHandle player_handle(rid);
	if (g_GameFunctions->m_StartGetSessionByGamerHandle(0, &player_handle, 1, &result, 1, &success, &state))
	{
		while (state.status == 1) WAIT(0);
		if (state.status == 3 && success)
		{
			is_online = true;
		}
		else
		{
			is_online = false;
		}
	}
	return is_online;
}


void RETURNFALSE(scrNativeCallContext* src)
{
	src->set_return_value<BOOL>(FALSE); // Set the return value in the context
}

#include <cstddef>
#include <cstdint>
#include <string_view>
#include <type_traits>
#include <xkeycheck.h>


inline constexpr char joaat_to_lower(char c)
{
	return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

constexpr rage::joaat_t operator""_J(const char* s, std::size_t n)
{
	rage::joaat_t result = 0;

	for (std::size_t i = 0; i < n; i++)
	{
		result += joaat_to_lower(s[i]);
		result += (result << 10);
		result ^= (result >> 6);
	}

	result += (result << 3);
	result ^= (result >> 11);
	result += (result << 15);

	return result;
}

// Now this will be computed at compile-time without errors
constexpr auto ALL_SCRIPT_HASH = "ALL_SCRIPTS"_J;

native_hooks::~native_hooks()
{
	m_native_hooks.clear();
	g_native_hooks = nullptr;
}

void native_hooks::add_native_detour(int index, scrNativeHandler detour)
//void native_hooks::add_native_detour(scrNativeHandler detour)
{
	
	//index = reinterpret_cast<int>(g_GameVariables3->m_BattleYeState);
	//index = BATTLEYE::_GET_BATTLEYE_INIT_STATE();
	add_native_detour(ALL_SCRIPT_HASH, BATTLEYE::_GET_BATTLEYE_INIT_STATE(), detour);
}
//using native_detour = std::pair<int, scrNativeHandler>;
std::unordered_map<unsigned int, std::vector<std::pair<int, void(*)(scrNativeCallContext*)>>> native_hooks::m_native_registrations;


#include <string>
#include <sstream>
#include <iomanip>

// Assume scrNativeHandler is defined as a function pointer
using scrNativeHandler = void(*)(scrNativeCallContext*);

std::string handlerToString(scrNativeHandler handler) {
	std::ostringstream oss;
	oss << std::hex << reinterpret_cast<std::uintptr_t>(handler); // Convert to hexadecimal string
	return oss.str();
}
//std::string handlerToString(scrNativeHandler handler) {
//	auto it = handlerNames.find(handler);
//	if (it != handlerNames.end()) {
//		return it->second; // Return the mapped string
//	}
//	return "Unknown Handler"; // Fallback if not found
//}

void native_hooks::add_native_detour(joaat_t script_hash, int index, scrNativeHandler detour)
{
	//index = BATTLEYE::_GET_BATTLEYE_INIT_STATE();
	//index = reinterpret_cast<int>(g_GameVariables3->m_BattleYeState);
	if (const auto& it = m_native_registrations.find(script_hash); it != m_native_registrations.end())
	{
		it->second.emplace_back(index, detour);

		/*Log::Msg("index");
		Log::Msg((char*)std::to_string(index).c_str());
		Log::Msg("Detour");
		Log::Msg((char*)handlerToString(detour).c_str());*/
		return;
	}

	m_native_registrations.emplace(script_hash, std::vector<native_detour>({ {index, detour} }));

	/*Log::Msg("index");
	Log::Msg((char*)std::to_string(index).c_str());
	Log::Msg("Detour");
	Log::Msg((char*)handlerToString(detour).c_str());*/

}

//void native_hooks::hook_program(rage::scrProgram* program)
//{
//	std::unordered_map<ForceNative::NativeIndex, scrNativeHandler> native_replacements;
//	const auto script_hash = program->m_name_hash;
//
//	// Functions that need to be detoured for all scripts
//	if (const auto& pair = m_native_registrations.find(ALL_SCRIPT_HASH); pair != m_native_registrations.end())
//	{
//		for (const auto& native_hook_reg : pair->second)
//		{
//			ForceNative::NativeIndex key = static_cast<ForceNative::NativeIndex>(native_hook_reg.first);  // Conversion explicite
//			native_replacements.emplace(key, native_hook_reg.second);  // Insertion dans la map
//		}
//	}
//
//	// Functions that only need to be detoured for a specific script
//	if (const auto& pair = m_native_registrations.find(script_hash); pair != m_native_registrations.end())
//	{
//		for (const auto& native_hook_reg : pair->second)
//		{
//			ForceNative::NativeIndex key = static_cast<ForceNative::NativeIndex>(native_hook_reg.first);  // Conversion explicite
//			native_replacements.emplace(key, native_hook_reg.second);  // Insertion dans la map
//		}
//	}
//
//	if (!native_replacements.empty())
//	{
//		m_native_hooks.emplace(program, std::make_unique<native_hook>(program, native_replacements));
//	}
//}


//void native_hooks::hook_program(rage::scrProgram* program)
//{
//	std::unordered_map<ForceNative::NativeIndex, scrNativeHandler> native_replacements;
//	const auto script_hash = program->m_name_hash;
//
//	// Functions that need to be detoured for all scripts
//	if (const auto& pair = m_native_registrations.find(ALL_SCRIPT_HASH); pair != m_native_registrations.end())
//	{
//		for (const auto& native_hook_reg : pair->second)
//		{
//			native_replacements.emplace(native_hook_reg); //insert
//		}
//	}
//
//	// Functions that only need to be detoured for a specific script
//	if (const auto& pair = m_native_registrations.find(script_hash); pair != m_native_registrations.end())
//	{
//		for (const auto& native_hook_reg : pair->second)
//		{
//			native_replacements.emplace(native_hook_reg); //insert
//		}
//	}
//
//	if (!native_replacements.empty())
//	{
//		m_native_hooks.emplace(program, std::make_unique<native_hook>(program, native_replacements));
//	}
//}

native_hook::~native_hook()
{

	if (m_handler_hook)
	{
		m_handler_hook->disable();
		m_handler_hook.reset();
	}

	if (m_vmt_hook)
	{
		m_vmt_hook->disable();
		m_vmt_hook.reset();
	}
}

void BattleyeBypass::set_peer_id_upper(std::uint64_t upper)
{
	*g_GameFunctions->m_peer_id &= 0xFFFFFFFF;
	*g_GameFunctions->m_peer_id |= (upper << 32);

	if (gta_util::get_network()->m_game_session_ptr)
		gta_util::get_network()->m_game_session_ptr->m_local_player.m_player_data.m_peer_id = *g_GameFunctions->m_peer_id;
	if (gta_util::get_network()->m_transition_session_ptr)
		gta_util::get_network()->m_transition_session_ptr->m_local_player.m_player_data.m_peer_id = *g_GameFunctions->m_peer_id;

	g_GameFunctions->m_profile_gamer_info->m_peer_id = *g_GameFunctions->m_peer_id;
	g_GameFunctions->m_player_info_gamer_info->m_peer_id = *g_GameFunctions->m_peer_id;
	if (g_GameFunctions->m_communications != nullptr)
		(*g_GameFunctions->m_communications)->m_voice.m_connections[0]->m_gamer_info.m_peer_id = *g_GameFunctions->m_peer_id;

	if (g_local_player && g_local_player->m_player_info)
		g_local_player->m_player_info->m_net_player_data.m_peer_id = *g_GameFunctions->m_peer_id;
}

void BattleyeBypass::set_host_token(std::uint64_t token)
{
	*g_GameFunctions->m_host_token = token;

	if (gta_util::get_network()->m_game_session_ptr)
		gta_util::get_network()->m_game_session_ptr->m_local_player.m_player_data.m_host_token = token;
	if (gta_util::get_network()->m_transition_session_ptr)
		gta_util::get_network()->m_transition_session_ptr->m_local_player.m_player_data.m_host_token = token;

	g_GameFunctions->m_profile_gamer_info->m_host_token = token;
	g_GameFunctions->m_player_info_gamer_info->m_host_token = token;
	if (g_GameFunctions->m_communications != nullptr)
		(*g_GameFunctions->m_communications)->m_voice.m_connections[0]->m_gamer_info.m_host_token = token;

	if (g_local_player && g_local_player->m_player_info)
		g_local_player->m_player_info->m_net_player_data.m_host_token = token;


	set_peer_id_upper(token >> 32);
}
bypassmysession bypass_my;

void BattleyeBypass::on_enable()
{
	bypass_my.original_host_token = *g_GameFunctions->m_host_token;
}

#include <cstdint>   // Pour uint64_t
#include <random>    // Pour la génération de nombres aléatoires

// Fonction pour générer un token hôte aléatoire
std::uint64_t generate_host_token() {
	// Générateur de nombres aléatoires
	std::random_device rd;  // Graine
	std::mt19937_64 gen(rd());  // Moteur Mersenne Twister 64 bits
	std::uniform_int_distribution<std::uint64_t> dis(0, 0xFFFFFFFF);  // Distribution uniforme (0 à 0xFFFFFFFF)

	// Générer la valeur uint64_t aléatoire
	return dis(gen);
}

void BattleyeBypass::on_tick()
{
	if (bypass_my.spoof_host_token_dirty && gta_util::get_network()->m_game_session_state == 0)
	{
		switch (bypass_my.spoof_host_token_type)
		{
		case 0: // Disabled
		{
			BattleyeBypass::m_enabled = 0;
			//gamedata::on_disable();
			set_host_token(bypass_my.original_host_token);
			break;
		}
		case 1: // Legit
		{
			BattleyeBypass::m_enabled = 1;
			//gamedata::on_enable();
			std::uint64_t rand_upper = math::rand(20, 230);
			set_host_token(((bypass_my.original_host_token) & 0xFFFFFFFF) | (rand_upper << 32));
			break;
		}
		case 2: // Aggressive
		{
			BattleyeBypass::m_enabled = 1;
			//gamedata::on_enable();
			set_host_token(math::rand(10, 1000));
			break;
		}
		case 3: // Very aggressive
		{
			BattleyeBypass::m_enabled = 1;
			set_host_token(0);
			//gamedata::on_enable();
			break;
		}
		case 4: // Custom
		{
			BattleyeBypass::m_enabled = 1;
			//gamedata::on_enable();
			/*std::uint64_t custom_host_token = generate_host_token();
			custom_host_token = (custom_host_token & 0xFFFFFFFF) | 0x0000000000000000;
			set_host_token(custom_host_token);*/
			set_host_token(bypass_my.custom_host_token);

			break;
		}
		}
		bypass_my.spoof_host_token_dirty = false;
	}
}

void BattleyeBypass::on_disable()
{

	if (bypass_my.original_host_token)
		set_host_token(bypass_my.original_host_token);
}

void BattleyeBypass::bypass_battleye()
{
	auto old = bypass_my.spoof_host_token_type;
	bypass_my.spoof_host_token_type = max(old, 1);
	if (old != bypass_my.spoof_host_token_type)
		bypass_my.spoof_host_token_dirty = true;
	bypass_my.kick_host_when_forcing_host = true;
	bypass_my.exclude_modders_from_kick_host = true; // useful

	constexpr std::array<std::uint32_t, 16> valid_hashes = { 1410389794, 967, 1523678325, 472, 0, 0, 1323039495, 0, 0, 1731098795, 2256610353, 17956, 414639110, 307143837, 3443181821, 0 };

	if (auto hashes = *g_GameFunctions->m_game_data_hash)
	{
		for (int i = 0; i < valid_hashes.size(); i++)
			hashes->m_data[i] = valid_hashes[i];
	}
}

bool hooks::network_can_access_multiplayer(void* a1, int* error)
{
	if (error)
		*error = 0;

	return true;
}
detourhookhelper::~detourhookhelper()
{
}
bool BattleyeBypass::m_enabled = 0;
void detourhookhelper::enablehookifhookingisalreadyrunning()
{
	if (BattleyeBypass::m_enabled)
	{
		if (m_on_hooking_available)
		{
			m_detour_hook->set_target_and_create_hook(m_on_hooking_available());
		}

		m_detour_hook->enable();
		MH_ApplyQueued();
	}
}


int BattleyeBypass::hookbypass()
{
	detourhookhelper::add<hooks::network_can_access_multiplayer>("NCAM", g_GameFunctions->m_network_can_access_multiplayer);

	//native_hooks* nh;
	//int battleye = BATTLEYE::_GET_BATTLEYE_INIT_STATE();
	//int battleye = reinterpret_cast<int>(g_GameVariables3->m_BattleYeState);
	//native_hooks::add_native_detour(battleye, RETURNFALSE);//(scrNativeHandler)
	native_hooks::add_native_detour(BATTLEYE::_GET_BATTLEYE_INIT_STATE(), RETURNFALSE);//(scrNativeHandler)
	return 0;
}

uint32_t m_curBit;          //0x0014

int GetDataLength()
{
	int leftoverBit = (m_curBit % 8) ? 1 : 0;
	return (m_curBit / 8) + leftoverBit;
}

void send_message_to_client(std::uint64_t token, void* message, int size)
{
	rage2::packet pkt;
	/*char header_buf[32];
	rage::datBitBuffer header(header_buf, sizeof(header_buf));*/

	pkt.write<int>(size, 11);
	pkt.write<bool>(false, 1); // we are not the client

	pkt.write_message(eNetMessage::MsgBattlEyeCmd);
	pkt.m_buffer.WriteArray(&pkt, GetDataLength() * 8);
	//pkt.m_buffer.WriteArray(&header_buf, header.GetDataLength() * 8);
	pkt.m_buffer.WriteArray(message, size * 8);

	// send to player
	if (auto plyr = g_player_service->get_by_host_token(token); plyr && plyr->get_session_player())
	{
		pkt.send(plyr->get_session_player()->m_msg_id, true);
	}
}

//struct gta_pointers
//{
//	PVOID m_be_network_bail_patch;
//};
//bool tampered_with_be = false;
//
////memory::byte_patch::make(g_pointers->m_gta.m_be_network_bail_patch, std::to_array({ 0xC3 }))->apply();
//void Bypass_Patch()
//{
//	unsigned char data[] = { 0x00, 0x50, 0x31, 0x4A, 0xC0, 0x1A, 0x13, 0xFF, 0xFF, 0xFF };
//	player->tampered_with_be = true;
//	for (int i = 0; i < 20; i++)
//	{
//		data[0] = i;
//		send_message_to_client(player->get_net_game_player()->get_host_token(), &data, sizeof(data));
//	}
//}

//int BattleyeBypass::bpbattleye()
//{
//	/*DWORD ticks = GetTickCount64();
//	DWORD milliseconds = ticks % 1000;
//	ticks /= 1000;
//	DWORD seconds = ticks % 60;
//	int getTimer = seconds;
//	if (getTimer % 9 == 0)
//	{*/
//
//	//}
//	return 0;
//};
bool BattleyeBypass::boolTimer = 0;


int BattleyeBypass::TimerBEbp()
{

	if (BattleyeBypass::boolTimer)
	{
		DWORD ticks = GetTickCount64();
		DWORD milliseconds = ticks % 1000;
		ticks /= 1000;
		DWORD seconds = ticks % 60;
		int getTimer = seconds;
		if (getTimer % 5 == 0)
		{
			BattleyeBypass::booltoggleBE = 1;
			BattleyeBypass::boolTimer = 0;
		}
	}
	return 0;
}
bool BattleyeBypass::booltoggleBE = 0;
bool bypasshook = 1;


int BattleyeBypass::bpTimerBE()
{
	if (BattleyeBypass::booltoggleBE)
	{
	DWORD ticks = GetTickCount64();
	DWORD milliseconds = ticks % 1000;
	ticks /= 1000;
	DWORD seconds = ticks % 60;
	int getTimer = seconds;
	if (getTimer % 5 == 0)
	{
		if (bypasshook)
		{
			BattleyeBypass::hookbypass();
			bypasshook = 0;
		}

		BattleyeBypass::bypass_battleye();
		//BattleyeBypass::bpbattleye();

		BattleyeBypass::booltoggleBE = 0;
		BattleyeBypass::boolTimer = 1;
	}
	}
	return 0;
};

bool BattleyeBypass::BypassBattleye = 1;
int BattleyeBypass::_Battleye()
{
	BattleyeBypass::on_tick();



	if (BattleyeBypass::BypassBattleye)
	{
			BattleyeBypass::booltoggleBE = 1;
			BattleyeBypass::boolTimer = 0;
			//gamedata::on_tick();
	}
	else
	{
		BattleyeBypass::booltoggleBE = 0;
		BattleyeBypass::boolTimer = 0;
	}
	return 0;
}

#include <ranges>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


static bool is_next_in_queue()
{
	std::vector<std::string> playerNames;

	uint64_t my_host_token = g_player_service->get_self()->get_net_data()->m_host_token;
	for (const auto& pair : g_player_service->players()/* | std::ranges::views::values*/)
	{
		const auto& plyr = pair.second;

		if (plyr->is_host())
			continue;
		if (plyr->get_net_data()->m_host_token < my_host_token)
		{
			return false;
		}
	}
	return true;
}
void gamedata::on_enable()
{
	store_data(orig_hash);
}

void gamedata::on_tick()
{
	//is_next_in_queue();
	if (bypass_my.game_data_hash_dirty)
	{
		load_data(bypass_my.game_data_hash);
		bypass_my.game_data_hash_dirty = false;
	}
}

void gamedata::on_disable()
{
	load_data(orig_hash);
}


void gamedata::execute()
{
	if (bypass_my.spoof_game_data_hash)
		bypass_my.game_data_hash = orig_hash;
	else
		store_data(bypass_my.game_data_hash);

	bypass_my.game_data_hash_dirty = true;
}

void native_hook::scrprogram_dtor(rage::scrProgram* this_, char free_memory)
{
	if (auto it = g_native_hooks->m_native_hooks.find(this_); it != g_native_hooks->m_native_hooks.end())
	{
		auto og_func = it->second->m_vmt_hook->get_original<decltype(&native_hook::scrprogram_dtor)>(6);
		it->second->m_vmt_hook->disable();
		it->second->m_vmt_hook.reset();
		it->second->m_handler_hook->disable();
		it->second->m_handler_hook.reset();
		g_native_hooks->m_native_hooks.erase(it);
		og_func(this_, free_memory);
	}
	else
	{
		//LOG(FATAL) << "Cannot find hook for program";
	}
}


	/*class battleye_kick : player_command
	{
		using player_command::player_command;
		virtual CommandAccessLevel get_access_level() override
		{
			return CommandAccessLevel::TOXIC;
		}*/

enum class KickReason : uint8_t
{
	VOTED_OUT,
	PEER_COMPLAINTS,
	CONNECTION_ERROR,
	NAT_TYPE,
	SCADMIN,
	SCADMIN_BLACKLIST,
	UNK,
	BATTLEYE_KICK,
	BATTLEYE_BAN,
	NUM_REASONS
};

void battleye_kick()
		//virtual void execute(player_ptr player, const command_arguments& _args, const std::shared_ptr<command_context> ctx) override
		{
	rage2::packet msg{};
			msg.write_message(eNetMessage::MsgKickPlayer);
			msg.write<KickReason>(KickReason::BATTLEYE_KICK, 5);
			msg.write<int>(0, 32);
			msg.write<bool>(false, 1);
			//auto msg_id = player->get_session_player()->m_msg_id;
			auto session_player = get_session_player(Features::Online::selectedPlayer)->m_msg_id;
			msg.send(session_player);
		}
	//};
	//class battleye_ban : player_command
	//{
	//	using player_command::player_command;
	//	virtual CommandAccessLevel get_access_level() override
	//	{
	//		return CommandAccessLevel::TOXIC;
	//	}
void battleye_ban()
		//virtual void execute(player_ptr player, const command_arguments& _args, const std::shared_ptr<command_context> ctx) override
		{
	rage2::packet msg{};
			msg.write_message(eNetMessage::MsgKickPlayer);
			msg.write<KickReason>(KickReason::BATTLEYE_BAN, 5);
			msg.write<int>(0, 32);
			msg.write<bool>(false, 1);
			/*auto msg_id = player->get_session_player()->m_msg_id;
			msg.send(msg_id);*/
			auto session_player = get_session_player(Features::Online::selectedPlayer)->m_msg_id;
			msg.send(session_player);
		}
	//};
	//battleye_kick g_battleye_kick("battlekick", "BATTLEYE_KICK", "BATTLEYE_KICK_DESC", 0);
	//battleye_ban g_battleye_ban("battleban", "BATTLEYE_FAKE_BAN", "BATTLEYE_FAKE_BAN_DESC", 0);

namespace
{
	static std::string base64_encode(const std::string& data)
	{
		static constexpr char sEncodingTable[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };

		size_t in_len = data.size();
		size_t out_len = 4 * ((in_len + 2) / 3);
		std::string ret(out_len, '\0');
		size_t i;
		char* p = ret.data();

		for (i = 0; i < in_len - 2; i += 3)
		{
			*p++ = sEncodingTable[(data[i] >> 2) & 0x3F];
			*p++ = sEncodingTable[((data[i] & 0x3) << 4) | ((int)(data[i + 1] & 0xF0) >> 4)];
			*p++ = sEncodingTable[((data[i + 1] & 0xF) << 2) | ((int)(data[i + 2] & 0xC0) >> 6)];
			*p++ = sEncodingTable[data[i + 2] & 0x3F];
		}
		if (i < in_len)
		{
			*p++ = sEncodingTable[(data[i] >> 2) & 0x3F];
			if (i == (in_len - 1))
			{
				*p++ = sEncodingTable[((data[i] & 0x3) << 4)];
				*p++ = '=';
			}
			else
			{
				*p++ = sEncodingTable[((data[i] & 0x3) << 4) | ((int)(data[i + 1] & 0xF0) >> 4)];
				*p++ = sEncodingTable[((data[i + 1] & 0xF) << 2)];
			}
			*p++ = '=';
		}

		return ret;
	}

}

//namespace big
//{
	/*class battleye_server : looped_command
	{
		using looped_command::looped_command;

		virtual void on_enable() override
		{
			g_battleye_service.start();
		}

		virtual void on_tick() override
		{
		}

		virtual void on_disable() override
		{
			g_battleye_service.stop();
		}
	};*/

	//#if 0
	//battleye_server g_battleye_server("battleyeserver", "BATTLEYE_SERVER", "BATTLEYE_SERVER_DESC", g.debug.battleye_server);
	//#endif

	bool battleye_service::is_running()
	{
		return m_battleye_api.m_shutdown != nullptr;
	}

	void battleye_service::send_message_to_client(std::uint64_t token, void* message, int size)
	{
		rage2::packet pkt;

		char header_buf[32];
		datBitBuffer header(header_buf, sizeof(header_buf));

		header.Write<int>(size, 11);
		header.Write<bool>(false, 1); // we are not the client

		pkt.write_message(eNetMessage::MsgBattlEyeCmd);
		pkt.m_buffer.WriteArray(&header_buf, header.GetDataLength() * 8);
		pkt.m_buffer.WriteArray(message, size * 8);

		// send to player
		if (auto plyr = g_player_service->get_by_host_token(token); plyr && plyr->get_session_player())
		{
			pkt.send(plyr->get_session_player()->m_msg_id, true);
		}
	}

	void battleye_service::send_message_to_server(std::uint64_t token, void* message, int size)
	{
		rage2::packet pkt;

		char header_buf[32];
		datBitBuffer header(header_buf, sizeof(header_buf));

		header.Write<int>(size, 11);
		header.Write<bool>(true, 1); // we are the client

		pkt.write_message(eNetMessage::MsgBattlEyeCmd);
		pkt.m_buffer.WriteArray(&header_buf, header.GetDataLength() * 8);
		pkt.m_buffer.WriteArray(message, size * 8);

		// send to player
		if (auto plyr = g_player_service->get_by_host_token(token); plyr && plyr->get_session_player())
		{
			pkt.send(plyr->get_session_player()->m_msg_id, true);
		}
	}

	//void battleye_service::kick_player(std::uint64_t token, const char* reason)
	//{
	//	if (auto plyr = g_player_service->get_by_host_token(token))
	//	{
	//		//LOGF(WARNING, "BattlEye wants us to kick {} for {}", plyr->get_name(), reason);
	//		if (!plyr->tampered_with_be)
	//		{
	//			session::add_infraction(plyr, Infraction::TRIGGERED_ANTICHEAT);
	//		}
	//	}
	//}

	void battleye_service::script_func()
	{
		bool was_host = false;
		while (is_running())
		{
			if (g_player_service->get_self()->is_valid())
			{
				bool is_host = g_player_service->get_self()->is_host();

				if (is_host != was_host)
				{
					if (is_host)
					{
						for (auto& [_, player] : g_player_service->players())
						{
							add_player(player->get_net_game_player()->get_host_token(),
								player->get_rockstar_id(),
								player->get_name());
						}
					}
					was_host = is_host;
				}
			}

			script::get_current()->yield();
		}
	}

	void battleye_service::thread_func()
	{
		while (is_running()/* && g_running*/)
		{
			// we need to run this every frame (lockstep with game or otherwise)
			{
				std::lock_guard lock(m_mutex);
				if (is_running() && !m_battleye_api.m_run())
				{
					//LOG(WARNING) << "BE::Run failed";
				}
			}

			std::this_thread::yield();
		}
	}

	battleye_service::battleye_service()
	{
	}

	battleye_service::~battleye_service()
	{
		stop();
	}

	void battleye_service::start()
	//void battleye_service_start()
	{
		std::lock_guard lock(m_mutex);

		if (is_running())
		{
			return;
		}

		auto handle = LoadLibraryA("BattlEye\\BEServer_x64.dll");

		if (!handle)
		{
			//LOG(WARNING) << "Failed to load BattlEye";
			return;
		}

		m_battleye_user_data.m_game_name = "paradise";
		m_battleye_user_data.m_log_func = [](const char* message, int level) {
			//LOG(INFO) << "BattlEye: " << message;
			};
		/*m_battleye_user_data.m_kick_player = [](std::uint64_t player, const char* reason) {
			g_battleye_service.kick_player(player, reason);
			};*/
		m_battleye_user_data.m_send_message = [](std::uint64_t player, const void* pkt_data, int size) {
			g_battleye_service.send_message_to_client(player, const_cast<void*>(pkt_data), size);
			};
		if (reinterpret_cast<init_t>(GetProcAddress(handle, "Init"))(1, &m_battleye_user_data, &m_battleye_api))
		{
			//// background thread (not game thread)
			//g_thread_pool->push([this] {
			//	this->thread_func();
			//	});

			//// background script (game thread)
			//g_script_mgr.add_script(std::make_unique<script>(
			//	[this] {
			//		this->script_func();
			//	},
			//	"BE Background Script",
			//	false));
		}
		else
		{
			//LOG(WARNING) << "Failed to initialize BattlEye";
		}
	}

	void battleye_service::stop()
	{
		std::lock_guard lock(m_mutex);

		if (!is_running())
		{
			return;
		}

		m_battleye_api.m_shutdown();
		memset(&m_battleye_api, 0, sizeof(CApi));
	}

	void battleye_service::add_player(std::uint64_t token, std::uint64_t rockstar_id, const char* name)
	{
		std::lock_guard lock(m_mutex);

		if (!is_running() || !g_player_service->get_self()->is_host())
		{
			return;
		}

		char string[32]{};

		snprintf(string, sizeof(string), "%I64d", rockstar_id);
		auto guid = base64_encode(string);

		m_battleye_api.m_add_player(token, -1, 0, name, false);
		m_battleye_api.m_assign_guid(token, guid.data(), guid.length());
		m_battleye_api.m_assign_guid_verified(token, guid.data(), guid.length());
		m_battleye_api.m_set_player_state(token, 1);
	}

	void battleye_service::remove_player(std::uint64_t token)
	{
		std::lock_guard lock(m_mutex);

		if (!is_running())
		{
			return;
		}

		m_battleye_api.m_set_player_state(token, -1);
	}

	void battleye_service::receive_message(std::uint64_t token, void* message, int size)
	{
		std::lock_guard lock(m_mutex);

		if (!is_running())
		{
			return;
		}

		m_battleye_api.m_receive_message(token, const_cast<const void*>(message), size);
	}

	void battleye_service::on_receive_message_from_server(std::uint64_t token, void* message, int size)
	{
		if (size == 0)
		{
			return;
		}

		auto msg = reinterpret_cast<unsigned char*>(message);
		auto op = msg[0];

		switch (op)
		{
		case INIT:
		{
			std::uint8_t payload[] = { 0x0, 0x5 };
			send_message_to_server(token, payload, sizeof(payload));
			break;
		}
		case START:
		{
			//LOG(INFO) << "BattlEye: Our GUID: " << (char*)&msg[3];
			send_message_to_server(token, message, 2);
			break;
		}
		case HEARTBEAT:
		{
			send_message_to_server(token, message, size);

			//if (g.session.kick_host_to_stay_in_session && msg[1] == 5)
			//{
			//	if (auto player = g_player_service->get_by_host_token(token))
			//	{
			//		//player_command::get("nfkick"_J)->call(player, {});
			//	}
			//}
			break;
		}
		case REQUEST:
		{
			if (size == 1028)
			{
				break;
			}
			send_message_to_server(token, message, 2);
			break;
		}
		}
	}
//}

	void session_force_script_host()
	{
		/*if (!g.session.force_script_host)
			return;*/

		static bool loaded_into_session = false;

		/*if (!*g_pointers->m_gta.m_is_session_started)
		{
			loaded_into_session = false;
			return;
		}*/

		if (!loaded_into_session)
		{
			/*if (SCRIPT::GET_NUMBER_OF_THREADS_RUNNING_THE_SCRIPT_WITH_THIS_HASH("maintransition"_J) == 0) [[unlikely]]
			{*/
				if (auto freemode = gta_util::find_script_thread("freemode"_J); freemode && freemode->m_net_component)
				{
					auto net_component = reinterpret_cast<CGameScriptHandlerNetComponent*>(freemode->m_net_component);
					int num_synced_arrays = 0;

					for (int i = 0; i < net_component->m_host_array_count; i++)
					{
						if ((g_GameVariables->m_get_host_array_handler_by_index(net_component, i)->m_flags & 1) != 0)
							num_synced_arrays++;
					}

					if (num_synced_arrays == net_component->m_host_array_count)
					{
						net_component->do_host_migration(g_player_service->get_self()->get_net_game_player(), 0xFFFF, true);

						rage2::packet pack;
						pack.write_message(eNetMessage::MsgScriptVerifyHostAck);
						net_component->m_script_handler->get_id()->serialize(&pack.m_buffer);
						pack.write<bool>(true, 1);
						pack.write<bool>(true, 1);
						pack.write<std::uint16_t>(0xFFFF, 16);

						for (auto& player : g_player_service->players())
						{
							if (player.second->get_net_game_player())
								pack.send(player.second->get_net_game_player()->m_msg_id);
						}

						loaded_into_session = true;
					}
				}
			/*}*/
		}
	}



	bool sjrm::serialize_join_request_message(RemoteGamerInfoMsg* info, void* data, int size, int* bits_serialized)
	{
		//if (info->unk_0xC0 == 0)
		//	info->unk_0xC0 = 1; // TODO: do we need this anymore?

		//if (g.protections.desync_kick)
		//	info->m_gamer_info.m_nat_type = 0;

		//info->m_num_handles = 0;

		return g_hookz->get_original<sjrm::serialize_join_request_message>()(info, data, size, bits_serialized);
		//return g_hooking->get_original<hooks::serialize_join_request_message>()(info, data, size, bits_serialized);
	}

	void dmr::detourmessagerequest()
	{
		vmt_hook::detour_hook_helper::add<sjrm::serialize_join_request_message>("SJRM", g_GameVariables->m_serialize_join_request_message);
	}

