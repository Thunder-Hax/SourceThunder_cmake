#include "stdafx.h"
#include "NewMenu.h"
//#include <functional>
//#include <vector>
//
//void rage::api::social_club::send(std::string endpoint, std::string data, std::function<void(const char*, void*)> callback, void* custom_data) {
//	/*LOG("Adding request to api pool...");*/
//	Log::Msg("Adding request to api pool...");
//	m_queue.push_back({ endpoint, data, callback, custom_data, 0 });
//}
//void rage::api::social_club::get_profiles_from_name(std::string name, std::function<void(bool, std::vector<rockstar_account>, result_info*)> callback, void* custom_data, int page_offset) {
//	send("https://scui.rockstargames.com/api/friend/accountsearch",
//		nlohmann::json({
//			{ "env", "prod" },
//			{ "title", "gta5" },
//			{ "version", 11 },
//			{ "searchNickname", name },
//			{ "pageIndex", page_offset }
//			}).dump(), [=](const char* jresponse, void* data) {
//				if (!nlohmann::json::accept(jresponse)) {
//					util::fiber::pool::add([=] {
//						callback(false, {}, nullptr);
//						});
//
//					return;
//				}
//
//	try {
//		nlohmann::json json = nlohmann::json::parse(jresponse);
//		if ((json["Status"].is_null() || !json["Status"].get<bool>()) || (json["Accounts"].is_null() || json["Accounts"].get<nlohmann::json::array_t>().size() == 0)) {
//			util::fiber::pool::add([=] {
//				callback(false, {}, nullptr);
//				});
//
//			return;
//		}
//
//		std::vector<rockstar_account> accounts;
//
//		for (nlohmann::json& account : json["Accounts"]) {
//			accounts.push_back({ account["Nickname"], account["RockstarId"] });
//		}
//
//		result_info* out_info = new result_info();
//		out_info->m_next_offset = json["NextOffset"];
//		out_info->m_total = json["Total"];
//
//		util::fiber::pool::add([=] {
//			callback(true, accounts, out_info);
//			});
//	}
//	catch (std::exception& e) {
//		/*LOG_WARN("[Json] %s", e.what());*/
//		Log::Msg("[Json] %s", e.what());
//
//		util::fiber::pool::add([=] {
//			callback(false, {}, nullptr);
//			});
//	}
//		}, custom_data);
//}
//
//
////namespace util::fiber::pool {
////	void fiber_pool::load() {
////		static std::function<void()> job1;
////		static std::function<void()> job2;
////		static std::function<void()> job3;
////		static std::function<void()> job4;
////		static std::function<void()> job5;
////		static std::function<void()> job6;
////		static std::function<void()> job7;
////		static std::function<void()> job8;
////
////		util::fiber::add("F_JOB1", [] { get_fiber_pool()->update(job1); });
////		util::fiber::add("F_JOB2", [] { get_fiber_pool()->update(job2); });
////		util::fiber::add("F_JOB3", [] { get_fiber_pool()->update(job3); });
////		util::fiber::add("F_JOB4", [] { get_fiber_pool()->update(job4); });
////		util::fiber::add("F_JOB5", [] { get_fiber_pool()->update(job5); });
////		util::fiber::add("F_JOB6", [] { get_fiber_pool()->update(job6); });
////		util::fiber::add("F_JOB7", [] { get_fiber_pool()->update(job7); });
////		util::fiber::add("F_JOB8", [] { get_fiber_pool()->update(job8); });
////	}
////
////	void fiber_pool::update(std::function<void()>& function) {
////		if (m_jobs.empty()) return;
////		function = m_jobs.front();
////		m_jobs.pop();
////		function();
////	}
////
////	void fiber_pool::add(std::function<void()> function) {
////		if (m_jobs.size() >= 200)
////			return;
////
////		m_jobs.emplace(function);
////	}
////
////	fiber_pool* get_fiber_pool() {
////		static fiber_pool instance;
////		return &instance;
////	}
////}
//namespace global::vars {
//	uint64_t g_ros_init_crypto;
//	uint64_t g_ros_read_stats_by_gamer;
//	uint64_t g_ros_download_player_image;
//
//	bool g_arxan_called[10];
//	bool g_chinese;
//	bool g_unloading = false;
//	bool g_unloading_queue = false;
//	bool g_freemode_terminated = false;
//	bool g_reapply_weapons = false;
//	HMODULE g_module_handle;
//	std::pair<uint64_t, uint32_t> g_cheat_address;
//	std::pair<uint64_t, uint32_t> g_game_address;
//	HWND g_window;
//	std::vector<localization*> g_localization_table;
//	bool g_steam = false;
//	bool g_reload_weapons;
//	std::pair<float, std::string> g_selected_metric_system = { 2.236936f, "MPH" };
//	std::unordered_map<uint64_t, std::pair<bool, int>> g_online_rockstar_ids;
//	std::vector<uint64_t> g_online_rockstar_ids_queue;
//	//std::vector<relay_usage> g_relay_usage;
//	std::queue<uint32_t> g_geo_queue;
//	/*std::unordered_map<uint32_t, geo_ip> g_geo;
//	rage::types::dictionary* g_custom_dictionary;
//	rage::types::dictionary* g_player_img_dictionary;
//	math::vector2<int> g_resolution;
//	math::vector2<int> g_desktop_resolution;*/
//	uint64_t g_texture_bypass;
//	uint64_t g_marker_bypass;
//	//std::unordered_map<std::string, alignment_test> g_alignment_tests;
//	//std::vector<patches> g_patches;
//	//std::unordered_map < std::string, patches> g_hack_patches;
//	std::vector<std::pair<uint64_t, int>> g_return_address_node_iterations;
//	std::unordered_map<uint64_t, uint64_t> g_desyncs_host;
//	//std::unordered_map<Player, desyncs> g_desyncs;
//	std::vector<join_timeout_fix> g_join_timeout_fix;
//	std::vector<std::pair<uint64_t, uint64_t>> g_host_desync_logs;
//	std::unordered_map<int, uint32_t> g_last_synced_player_models;
//	std::vector<gs_info_request> g_gs_info_requests;
//	std::unordered_map<uint64_t, uint32_t> g_spoofed_data_join_requests;
//	std::unordered_map<uint64_t, std::pair<uint32_t, uint32_t>> g_raw_buffer_translations;
//	std::unordered_map<uint64_t, uint32_t> g_sync_real_ip;
//	std::unordered_map<uint64_t, uint64_t> g_sync_peer_corruption;
//	uint8_t g_arxan_restore_bytes[2][2][25];
//	uint64_t g_arxan_restore_addresses[2];
//	std::unordered_map<uint64_t, rage::network::read_stats_by_gamer> g_read_stats_by_gamer_results;
//	std::vector<std::pair<uint32_t, uint8_t*>> g_player_image_queue;
//	//PlayerMenuType g_network_menu_type;
//	bool g_change_peer;
//
//	// game structures
//	//game_state* g_game_state;
//	//rage::invoker::native_registration** g_native_registration;
//	//rage::network::rs_info* g_rs_info;
//	//rage::types::ped_factory* g_ped_factory;
//	//rage::network::game_camera_angles* g_game_camera_angles;
//	//rage::types::waypoint_data* g_waypoint_data;
//	//rage::network::net_shop_queue* g_net_shop_queue;
//	//rage::types::ui_visual_settings* g_ui_visual_settings;
//	//rage::types::vfx_liquid* g_vfx_liquid;
//	//rage::network::friends* g_friends;
//	//rage::types::texture_store* g_texture_store;
//	//rage::types::store_manager* g_store_manager;
//	//rage::types::memory_heap_pt* g_memory_heap;
//	////rage::types::replay_interface* g_replay_interface;
//	//rage::types::explosion_data* g_explosion_data;
//	//rage::types::explosion_fx* g_explosion_fx;
//	//rage::network::network_base_config* g_network_base_config;
//	//rage::types::ocean_quads g_ocean_quads;
//	//rage::types::water_tune* g_water_tune;
//	//rage::types::ui_weather* g_ui_weather;
//	//rage::types::ui_puddle* g_ui_puddle;
//	//rage::types::blip_list* g_blip_list;
//
//	//// game pools
//	//guid_pool* g_object_pool;
//	//guid_pool* g_ped_pool;
//	//vehicle_pool* g_vehicle_pool;
//	//guid_pool* g_pickup_pool;
//
//	//// game lists
//	//hash_list g_weapon_components;
//	//hash_list g_weapon_info;
//	//hash_list g_script_handlers;
//	//std::pair<rage::types::vfx_wheel*, uint8_t> g_vfx_wheel;
//
//	// game addresses
//	uint64_t g_d3d11_device;
//	uint64_t g_process_transaction_id;
//	uint64_t g_sync_data_reader_vtable;
//	uint64_t** g_global_cache;
//	uint64_t g_nullsub;
//	uint64_t g_read_bool_from_bit_buffer;
//	uint64_t g_read_int_from_bit_buffer;
//	uint64_t g_read_uint_from_bit_buffer;
//	uint64_t g_read_byte_from_bit_buffer;
//	uint64_t g_read_ulonglong_from_bit_Buffer;
//	uint64_t g_read_short_from_bit_buffer;
//	uint64_t g_read_vector3_from_bit_buffer;
//	uint64_t g_read_array_from_bit_buffer;
//	uint64_t g_read_msg_header_from_bit_buffer;
//	uint64_t g_read_pickup_from_bit_buffer;
//	uint64_t g_write_uint_to_bit_buffer;
//	uint64_t g_sc_game_info_table;
//	uint64_t g_sc_get_game_info_table;
//	uint64_t g_game_streamed_scripts;
//	uint64_t g_get_streamed_script;
//	uint64_t g_get_third_person_camera;
//	uint64_t g_third_person_camera;
//	uint64_t g_get_entity_address;
//	uint64_t g_get_entity_handle_from_address;
//	uint64_t g_get_net_game_player_from_index;
//	uint64_t g_get_model_info;
//	uint64_t g_set_vehicle_gravity;
//	uint64_t g_get_vehicle_paint_array;
//	uint64_t g_draw_origin_index;
//	uint64_t g_add_to_clock_time;
//	uint64_t g_dispatch_service_table;
//	uint64_t g_sync_clock_time;
//	uint64_t g_send_weather_update;
//	uint64_t g_get_host_net_game_player;
//	uint64_t g_send_increment_stat_event;
//	uint64_t g_update_net_object_owner;
//	uint64_t g_network_object_manager;
//	uint64_t g_network_player_manager;
//	uint64_t g_handle_rotation_values_from_order;
//	uint64_t g_get_net_game_player_from_handle;
//	uint64_t g_get_sprite_texture;
//	uint64_t g_send_text_message_net_msg;
//	uint64_t g_set_traffic_lights;
//	uint64_t g_update_traffic_lights;
//	uint64_t g_set_traffic_light_colors;
//	uint64_t g_set_vehicle_lights;
//	uint64_t g_get_sync_tree_from_clone_type;
//	uint64_t g_get_network_object_from_network_id;
//	uint64_t g_get_network_config_from_peer;
//	uint64_t g_network_event_registration;
//	uint64_t g_update_ui_values;
//	uint64_t g_update_ui_values_2;
//	uint64_t g_set_vehicle_neon_ui;
//	uint64_t g_set_seethrough;
//	uint64_t g_add_basket_to_queue;
//	uint64_t g_add_item_to_basket;
//	uint64_t g_send_session_info_request;
//	uint64_t g_get_session_info_from_gs;
//	uint64_t g_send_network_event_reply;
//	uint64_t g_send_network_event_ack;
//	uint64_t g_setup_give_control_event;
//	uint64_t g_send_friend_request;
//	uint64_t g_get_client_player_key;
//	uint64_t g_render_water_on_map_intensity;
//	uint64_t g_map_fog_intensity;
//	uint64_t g_send_presence_event;
//	uint64_t g_migrate_script_host;
//	uint64_t g_is_reported_for_reason;
//	uint64_t g_chat_info;
//	uint64_t g_send_matchmaking_request;
//	uint64_t g_read_xml_string;
//	uint64_t g_read_xml_node_string;
//	uint64_t g_register_streaming_file;
//	uint64_t g_create_game_invite_presence;
//	uint64_t g_send_game_invite_presence;
//	uint64_t g_send_game_invite_presence_table;
//	uint64_t g_send_ragdoll_event;
//	uint64_t g_grc_texture_factory_dx11;
//	uint64_t g_thread_alloc;
//	uint64_t g_setup_dictionary;
//	uint64_t g_setup_store_item;
//	uint64_t g_is_valid_pool_slot;
//	uint64_t g_add_dictionary_to_pool;
//	uint64_t g_add_grc_texture_to_dictionary;
//	uint64_t g_get_weather_id;
//	uint64_t g_weather_table;
//	uint64_t g_get_font_id_table;
//	uint64_t g_get_store_module_extension;
//	uint64_t g_request_streaming_file;
//	uint64_t g_construct_gfx_font;
//	uint64_t g_destruct;
//	uint64_t g_create_id_for_font;
//	uint64_t g_add_font_lib;
//	uint64_t g_vertex_begin;
//	uint64_t g_vertex_end;
//	uint64_t g_vertex_add;
//	uint64_t g_render_script_texture;
//	uint64_t g_font_table;
//	uint64_t g_font_memory_helper;
//	uint64_t g_parse_nodes;
//	uint64_t g_read_new_script_host_message;
//	uint64_t g_write_gs_item;
//	uint64_t g_game_script_handler_manager;
//	uint64_t g_translate_native;
//	uint64_t g_global_chat_ptr;
//	uint64_t g_send_global_chat_message;
//	uint64_t g_add_chat_message;
//	uint64_t g_chat_config;
//	uint64_t g_ped_orientation_writer;
//	uint64_t g_entity_orientation_writer;
//	uint64_t g_social_club_game_info_table;
//	uint64_t g_social_club_get_game_info_table;
//	uint64_t g_reset_script_render_params[2];
//	uint64_t g_get_player_info_from_net_msg;
//	uint64_t g_drop_shaders;
//	uint64_t g_drop_shader_count;
//	uint64_t g_get_net_msg_net_player;
//	uint64_t g_ui_3d_draw_manager;
//	uint64_t g_push_scene_preset_to_manager;
//	uint64_t g_add_element_to_scene;
//	uint64_t g_set_scene_element_lighting;
//	uint64_t g_invalid_string_address;
//	uint64_t g_construct_read_session_join_request_msg;
//	uint64_t g_read_session_join_request_msg;
//	uint64_t g_read_token_from_bit_buffer;
//	uint64_t g_read_string_from_bit_buffer;
//	uint64_t g_invite_player;
//	uint64_t g_sync_data_writer_vtable;
//
//	uint32_t g_ozark_detections[] = {
//		0x22ae9ef7,
//		0xd5c31f7a,
//		0xf807b7e0,
//		0x3895afe2,
//		0x4ee4092c,
//		0x8c16a626,
//		0x3039cd1b,
//		0xfe2d7811,
//		0xff1816e5,
//		0xf7badafb,
//		0xb9d09512,
//		0xfb2a0138,
//		0x1c1fe653,
//		0xcc50aa5a,
//		0x4c0a1f3c,
//		0x01397d8e,
//		0x1cca797b,
//		0xa3c78808,
//		0xe0e0d4ae,
//		0x80f00989,
//		0xcc450cbb,
//		0xc7dc381,
//		0x3640ac4d,
//		0xae6d9427,
//		0x6613ba47,
//		0xbd9b0ece,
//		0x7989c8ef,
//		0x6c0df033,
//		0x2c826d8c,
//		0x4d4a2dbf,
//		0xcc1a895a,
//		0x1097331,
//		0xdf577ec3,
//		0x62c5565,
//		0xfe7b45da,
//		0xd268409b,
//		0x200bfa48,
//		0xc3851eef,
//		0x7d973e49,
//		0x9e20d29,
//		0x203ac304,
//		0x35d0430d,
//		0x0d1c850a,
//		0x095436c0,
//		0x68a29afa,
//		0x753ec6fd,
//		0x7cd15134,
//		0xcb41f199,
//		0xebbe7348,
//		0xceba5a71,
//		0xb4ad9f12,
//		0x00b8b574,
//		0xb5f0b06d,
//		0xa4daa011,
//		0x74be9134,
//		0xc61f6ed7,
//		0x92e195f9,
//		0xe0732c89,
//		0xcee496c4,
//		0x048cd47d,
//		0xd23d2d64,
//		0xd2229f24,
//		0xf0a8b10a,
//		0x69a48342,
//		0x6c548c90,
//		0x94b993ab,
//		0x2876763d,
//		0xc300d11c,
//		0x3aeb8203,
//		0xcf4ac36e,
//		0xfd0fc06b,
//		0x551b54a5,
//		0x4cc1c54b,
//		0x03774cdb,
//		0x379ce628,
//		0xe8490ddd,
//		0xd9352f6b,
//		0xf47c081e,
//		0xc765d720,
//		0xfcca2774,
//		0x114dee50,
//		0xcb29360b,
//		0x983162a9,
//		0xbb98b280,
//		0xb1fac843,
//		0xae08ab79,
//		0x646f1d41,
//		0x8fc23a82,
//		0x3543f2bd,
//		0x8701d0e0,
//		0x677a359f,
//		0xa4ea31f,
//		0x97c34e43,
//		0x5b396fbb,
//		0xf7080942,
//		0x278946b1,
//		0x6518b45a,
//		0x6325d30f,
//		0xa19b464,
//		0x63794f98
//	};
//}
//namespace util::fiber {
//	void fiber_manager::load() {
//		if (m_loaded) return;
//		m_loaded = true;
//
//		ConvertThreadToFiber(nullptr);
//		m_main_fiber = GetCurrentFiber();
//	}
//
//	void fiber_manager::update() {
//		if (!m_loaded || !m_current) return;
//
//		for (fiber_context& fiber : m_fibers) {
//			if (fiber.m_running) {
//				if (timeGetTime() >= fiber.m_wake_time) {
//					SwitchToFiber(fiber.m_handle);
//				}
//			}
//		}
//
//		m_current = m_current->m_next;
//	}
//
//	void fiber_manager::add(std::string name, std::function<void()> function) {
//		struct Arguments {
//			std::function<void()> m_function;
//			void* m_main;
//		};
//
//		Arguments* arguments = new Arguments();
//		arguments->m_function = function;
//		arguments->m_main = m_main_fiber;
//
//		void* fiber_handle = CreateFiber(0, [](void* param) {
//			Arguments* arguments = (Arguments*)param;
//		while (!global::vars::g_unloading) {
//			arguments->m_function();
//			SwitchToFiber(arguments->m_main);
//		}
//
//		delete[] arguments;
//			}, arguments);
//
//		m_fibers.push_back({ nullptr, fiber_handle, timeGetTime(), true, name });
//
//		for (auto fiber = m_fibers.begin(); fiber != m_fibers.end(); ++fiber) {
//			auto next = fiber + 1;
//			if (next != m_fibers.end()) fiber->m_next = &*next;
//			else fiber->m_next = &m_fibers.front();
//		}
//
//		m_current = &m_fibers.front();
//	}
//
//	void fiber_manager::sleep(uint32_t time) {
//		auto vit = std::find_if(begin(m_fibers), end(m_fibers), [](fiber_context& fiber) { return fiber.m_handle == GetCurrentFiber(); });
//		if (vit != end(m_fibers)) {
//			vit->m_wake_time = timeGetTime() + time;
//			SwitchToFiber(m_main_fiber);
//		}
//	}
//
//	void fiber_manager::go_to_main() {
//		SwitchToFiber(m_main_fiber);
//	}
//
//	void fiber_manager::cleanup() {
//		for (fiber_context& fiber : m_fibers) {
//			fiber.m_running = false;
//			DeleteFiber(fiber.m_handle);
//		}
//	}
//
//	/*fiber_manager* get_fiber_manager() {
//		static fiber_manager instance;
//		return &instance;
//	}
//
//	fiber_manager* get_fiber_manager_shv() {
//		static fiber_manager instance;
//		return &instance;
//	}*/
//}
//
//localization::localization() {}
//
//localization::localization(std::string original, bool translate, bool global_register) {
//	if (global_register) {
//		register_translation();
//	}
//
//	m_translate = translate;
//	set(original);
//}
//
//void localization::reset() {
//	set_mapped(m_original);
//}
//
//void localization::set(std::string str) {
//	m_original = str;
//	set_mapped(m_original);
//}
//
//void localization::set_mapped(std::string str) {
//	m_mapped = str;
//}
//
//void localization::set_translate(bool translate) {
//	m_translate = translate;
//}
//
//void localization::register_translation() {
//	global::vars::g_localization_table.push_back(this);
//}
//
//std::string localization::get_original() {
//	return m_original;
//}
//
//std::string localization::get() {
//	return m_translate ? m_mapped : m_original;
//}
//
//bool localization::has_translation() {
//	return m_translate;
//}
//network::player::search::vars::variables m_vars;
//
////void menu::submenu::submenu::clear_options(int offset) {
////	if (offset > m_options.size()) return;
////
////	for (std::shared_ptr<base_option>& option : m_options) {
////		/*if (option->has_hotkey()) {
////			hotkey::unregister_hotkey(&*option);
////		}*/
////	}
////
////	m_options.resize(offset);
////}
//
//namespace menu::submenu {
//	//void submenu::update_menu() {
//	//	update();
//
//	//	/*renderer::render_title(m_name.get());
//
//	//	handler::set_total_options(0);
//	//	handler::set_current_options_without_breaks(0);
//	//	handler::set_total_options_without_breaks(0);*/
//
//	//	/*bool slider = false;
//	//	bool input = false;
//	//	bool hotkey = false;
//
//	//	if (m_options.size() > 0) {
//	//		std::vector<std::shared_ptr<base_option>> options;
//	//		options.reserve(m_options.size());
//
//	//		int relative_position = 0;
//	//		int visibility_offset = 0;
//
//	//		for (std::shared_ptr<base_option> option : m_options) {
//	//			if (option->is_visible()) {
//	//				visibility_offset++;
//	//				options.push_back(option);
//
//	//				handler::set_total_options(handler::get_total_options() + 1);
//	//				if (!option->is_break()) {
//	//					if (visibility_offset <= base::get_current_option()) {
//	//						handler::set_current_options_without_breaks(handler::get_current_options_without_breaks() + 1);
//	//					}
//
//	//					handler::set_total_options_without_breaks(handler::get_total_options_without_breaks() + 1);
//	//				}
//	//			}
//	//		}
//
//	//		for (int i = base::get_scroll_offset(); i < base::get_scroll_offset() + base::get_max_options(); i++) {
//	//			if (i >= 0 && i < options.size()) {
//	//				if (relative_position >= base::get_max_options()) break;
//
//	//				options.at(i).get()->render(relative_position);
//
//	//				if (relative_position == base::get_current_option() - base::get_scroll_offset()) {
//	//					if (base::is_open()) {
//	//						renderer::render_tooltip(options.at(i).get()->get_tooltip().get());
//	//						options.at(i).get()->render_selected(relative_position, m_submenu_name_stack);
//
//	//						slider = options.at(i).get()->is_slider();
//	//						input = options.at(i).get()->is_input();
//	//						hotkey = options.at(i).get()->has_hotkey();
//	//					}
//	//				}
//
//	//				relative_position++;
//	//			}
//	//		}
//	//	}
//
//	//	if (m_default_instructionals) {
//	//		instructionals::standard(slider, input, hotkey);
//	//	}*/
//	//}
//
//	void submenu::clear_options(int offset) {
//		if (offset > m_options.size()) return;
//
//		for (std::shared_ptr<base_option>& option : m_options) {
//			if (option->has_hotkey()) {
//				//hotkey::unregister_hotkey(&*option);
//			}
//		}
//
//		m_options.resize(offset);
//	}
//
//	std::string submenu::get_string(std::string str) {
//		for (localization local : m_strings) {
//			if (!local.get_original().compare(str)) {
//				return local.get();
//			}
//		}
//
//		return str;
//	}
//
//	void submenu::set_name(std::string str, bool translation, bool searchable) {
//		if (!str.empty() && str.length() > 0) {
//			m_name.set(str);
//			m_name.set_translate(true);
//			m_can_be_searched = searchable;
//		}
//	}
//
//	void submenu::load() {}
//	void submenu::update_once() {}
//	void submenu::update() {}
//	void submenu::feature_update() {}
//}
//namespace util::va {
//	std::unordered_map<uint32_t, char*> g_va_storage;
//	std::unordered_map<uint32_t, std::pair<wchar_t*, char*>> g_vaw_storage;
//
//	const char* va(const char* fmt, ...) {
//		if (g_va_storage.find(GetCurrentThreadId()) == end(g_va_storage)) {
//			g_va_storage[GetCurrentThreadId()] = new char[0x300];
//		}
//
//		char* buffer = g_va_storage[GetCurrentThreadId()];
//		memset(buffer, 0, 0x300);
//
//		va_list va_l;
//		va_start(va_l, fmt);
//		vsnprintf(buffer, 0x300, fmt, va_l);
//		va_end(va_l);
//
//		return buffer;
//	}
//
//	const char* vap(char* buffer, const char* fmt, ...) {
//		va_list va_l;
//		va_start(va_l, fmt);
//		vsprintf(buffer, fmt, va_l);
//		va_end(va_l);
//		return buffer;
//	}
//
//	const wchar_t* vaw(const char* fmt, ...) {
//		if (g_vaw_storage.find(GetCurrentThreadId()) == end(g_vaw_storage)) {
//			g_vaw_storage[GetCurrentThreadId()] = { new wchar_t[0x300], new char[0x300] };
//		}
//
//		wchar_t* message = g_vaw_storage[GetCurrentThreadId()].first;
//		memset(message, 0, 0x300);
//
//		char* buffer = g_vaw_storage[GetCurrentThreadId()].second;
//		memset(buffer, 0, 0x300);
//
//		va_list va_l;
//		va_start(va_l, fmt);
//		vsnprintf(buffer, 0x300, fmt, va_l);
//		va_end(va_l);
//
//		mbstowcs(message, buffer, strlen(buffer) + 1);
//		return message;
//	}
//
//	void cleanup() {
//		for (std::pair<uint32_t, char*> ptr : g_va_storage) {
//			delete[] ptr.second;
//		}
//
//		for (std::pair<uint32_t, std::pair<wchar_t*, char*>> ptr : g_vaw_storage) {
//			delete[] ptr.second.first;
//			delete[] ptr.second.second;
//		}
//	}
//}
//#include "nlohmann/json.hpp"
////#include <xhash>
////#include <xtree>
////#include <algorithm>
////#include <xstring>
//
//void add_player(network_player_search_menu* _this, rage::api::rockstar_account* account) {
//	uint8_t custom[0x10];
//	*(uint64_t*)&custom[0] = account->m_rockstar_id;
//	*(uint64_t*)&custom[8] = (uint64_t)&account->m_name;
//
//	_this->add_option(submenu_option(account->m_name)
//		.add_custom_data(custom)
//		.add_submenu<network_player_search_selected_menu>()
//		.add_click([=] { network::player::search::selected::vars::m_vars.m_selected = account; })
//		.add_update([](submenu_option* option, int pos) {
//			uint8_t* data = option->get_custom_data();
//	uint64_t rid = *(uint64_t*)&data[0];
//	std::string* name = (std::string*)*(uint64_t*)&data[8];
//
//	option->set_name(((global::vars::g_online_rockstar_ids[rid].first) ? "" : "~m~") + *name);
//	option->set_tooltip(util::va::va("Page %i of %i", m_vars.m_current_page + 1, (m_vars.m_total / 10) + 1));
//
//	//menu::textures::texture_context context;
//	//if (menu::textures::get_texture(std::string("playerimg_" + std::to_string(rid)), &context)) {
//	//	option->add_offset(0.016f);
//
//	//	//menu::renderer::draw_rect_unaligned({ global::ui::g_position.x + 0.004f + 0.007f, global::ui::g_position.y + (pos * global::ui::g_option_scale) + 0.005f + 0.011f }, { 0.0136f, 0.0216f }, { 200, 200, 200, 255 });
//	//	//menu::renderer::draw_sprite({ "ozarkplayerimg", context.m_name }, { global::ui::g_position.x + 0.004f + 0.007f, global::ui::g_position.y + (pos * global::ui::g_option_scale) + 0.005f + 0.011f }, { 0.0136f, 0.0216f }, 0.f, { 255, 255, 255, 255 });
//	//}
//			})
//		.add_hover([](submenu_option* option) {
//				uint8_t* data = option->get_custom_data();
//			uint64_t rid = *(uint64_t*)&data[0];
//			std::string* name = (std::string*)*(uint64_t*)&data[8];
//
//			menu::panels::panel_custom_player_search search;
//			search.m_rockstar_id = rid;
//			search.m_online = global::vars::g_online_rockstar_ids[rid].first;
//			strcpy_s(search.m_name, name->c_str());
//			int contains = rid;
//
//			if (/*global::vars::g_read_stats_by_gamer_results.contains(rid)*/contains) {
//				search.m_has_stats = true;
//				memcpy(&search.m_stats, &/*global::vars::g_read_stats_by_gamer_results[rid]*/contains, sizeof(search.m_stats));
//			}
//			else {
//				search.m_has_stats = false;
//			}
//
//			menu::panels::panel_parent* parent = menu::panels::get_parent("PANEL_PLAYER_SEARCH");
//			if (parent) {
//				menu::panels::set_structure(menu::panels::get_child(parent, "PANEL_PLAYER_SEARCH_INFO"), (void*)&search, sizeof(search));
//				parent->m_render = true;
//			}
//			}));
//
//
//	m_vars.m_queue.push_back(account->m_rockstar_id);
//}
//uint64_t g_ros_download_player_image;
//uint64_t g_ros_send_stat_requests;
//void add_request(std::vector<uint64_t> players) {
//	if (players.empty()) return;
//
//	uint32_t* rids = new uint32_t[players.size()];
//
//	for (std::size_t i = 0; i < players.size(); i++) {
//		rids[i] = (uint32_t)players[i];
//	}
//
//	uint64_t* info = new uint64_t[2];
//	*(uint64_t*)((uint64_t)info) = (uint64_t)players.size();
//	*(uint64_t*)((uint64_t)info + 8) = (uint64_t)rids;
//
//	util::threads::add_job([](void* lp) {
//		uint64_t count = *(uint64_t*)((uint64_t)lp);
//	uint32_t* ridss = (uint32_t*)*(uint64_t*)((uint64_t)lp + 8);
//
//	///*rage::ros::send_stat_requests*/g_ros_send_stat_requests(ridss, (int)count);
//
//	for (uint64_t i = 0; i < count; i++) {
//		if (global::vars::g_unloading) return;
//
//		/*if (menu::submenu::handler::get_current() != network_player_search_menu::get()) {
//			if (std::find_if(begin(m_vars.m_image_queue), end(m_vars.m_image_queue), [=](uint64_t rid) { return (uint32_t)rid == ridss[i]; }) == end(m_vars.m_image_queue)) m_vars.m_image_queue.push_back(ridss[i]);
//			return;
//		}*/
//
//		//rage::ros::download_player_image(ridss[i]);
//	}
//
//	delete[] ridss;
//	delete[] lp;
//		}, info);
//}
//void network_player_search_menu::update_once() {
//	clear_options(5);
//
//	if (!m_vars.m_image_queue.empty()) {
//		uint32_t* rids = new uint32_t[m_vars.m_image_queue.size()];
//
//		for (std::size_t i = 0; i < m_vars.m_image_queue.size(); i++) {
//			rids[i] = (uint32_t)m_vars.m_image_queue[i];
//		}
//
//		uint64_t* info = new uint64_t[2];
//		*(uint64_t*)((uint64_t)info) = (uint64_t)m_vars.m_image_queue.size();
//		*(uint64_t*)((uint64_t)info + 8) = (uint64_t)rids;
//
//		m_vars.m_image_queue.clear();
//
//		util::threads::add_job([](void* lp) {
//			uint64_t count = *(uint64_t*)((uint64_t)lp);
//		uint32_t* ridss = (uint32_t*)*(uint64_t*)((uint64_t)lp + 8);
//
//		for (uint64_t i = 0; i < count; i++) {
//			if (global::vars::g_unloading) return;
//			///*rage::ros::download_player_image*/g_ros_download_player_image(ridss[i]);
//		}
//
//		delete[] ridss;
//		delete[] lp;
//			}, info);
//	}
//
//	std::vector<uint64_t> players;
//
//	if (m_vars.m_current_page == 0) {
//		if (m_vars.m_accounts.size() <= 10) {
//			for (rage::api::rockstar_account& account : m_vars.m_accounts) {
//				add_player(this, &account);
//				players.push_back(account.m_rockstar_id);
//			}
//
//			add_request(players);
//
//			if (m_vars.m_accounts.empty()) {
//				add_option(button_option(get_string("~m~None")).ref());
//			}
//		}
//		else {
//			for (std::size_t i = 0; i < 10; i++) {
//				add_player(this, &m_vars.m_accounts[i]);
//				players.push_back(m_vars.m_accounts[i].m_rockstar_id);
//			}
//
//			add_request(players);
//		}
//	}
//	else {
//		std::size_t max_size = m_vars.m_accounts.size() > (m_vars.m_current_page * 10) + 10 ? 10 : m_vars.m_accounts.size() - (m_vars.m_current_page * 10);
//		for (std::size_t i = 0; i < max_size; i++) {
//			add_player(this, &m_vars.m_accounts[i + (m_vars.m_current_page * 10)]);
//			players.push_back(m_vars.m_accounts[i + (m_vars.m_current_page * 10)].m_rockstar_id);
//		}
//
//		add_request(players);
//
//		if (max_size == 0) {
//			add_option(button_option(get_string("~m~None")).ref());
//		}
//	}
//}
//
//void network_player_search_menu::feature_update() {}
//
//network_player_search_menu* g_instance;
//network_player_search_menu* network_player_search_menu::get() {
//	if (g_instance == nullptr) {
//		g_instance = new network_player_search_menu();
//		g_instance->load();
//		//menu::submenu::handler::add_submenu(g_instance);
//	}
//
//	return g_instance;
//}
//
//
//
//
//
//void input_player_name_callback(button_option* option, const char* result) {
//	m_vars.m_name = result;
//	m_vars.m_rockstar_id = 0;
//	m_vars.m_current_offset = 0;
//	m_vars.m_current_page = 0;
//	m_vars.m_total_pages_requested = 0;
//	m_vars.m_accounts.clear();
//	network_player_search_menu::get()->clear_options(5);
//
//	rage::api::get_profiles_from_name(result, [=](bool success, std::vector<rage::api::rockstar_account> accounts, rage::api::result_info* out_info) {
//		if (success && !accounts.empty()) {
//			for (rage::api::rockstar_account& account : accounts) {
//				if (std::find_if(begin(m_vars.m_accounts), end(m_vars.m_accounts), [=](rage::api::rockstar_account& elem) { return elem.m_rockstar_id == account.m_rockstar_id; }) == end(m_vars.m_accounts)) {
//					m_vars.m_accounts.push_back(account);
//				}
//			}
//
//			m_vars.m_total_pages_requested = 1;
//			m_vars.m_current_offset += (int)accounts.size() + 1;
//			m_vars.m_total = out_info->m_total;
//			network_player_search_menu::get()->update_once();
//		}
//	/*else {
//		menu::notify::stacked(network_player_search_menu::get()->get_name().get(), network_player_search_menu::get()->get_string("Failed resolving profiles"), global::ui::g_error);
//	}*/
//
//	if (out_info) {
//		delete out_info;
//	}
//		}, nullptr);
//}
//
//namespace util::threads {
//	void threads::add_job(std::function<void(void*)> callback, void* argument) {
//		struct thread_job {
//			void* m_argument;
//			std::function<void(void*)> m_callback;
//		};
//
//		thread_job* job = new thread_job();
//		job->m_callback = callback;
//		job->m_argument = argument;
//
//		CreateThread(0, 0, [](void* argument) -> DWORD {
//			thread_job* job = (thread_job*)argument;
//		job->m_callback(job->m_argument);
//		delete job;
//		return 0;
//			}, job, 0, 0);
//	}
//
//	void threads::add_thread(const char* name, std::function<void(void*)> callback, void* argument) {
//		thread_context* thread = new thread_context();
//		thread->m_name = name;
//		thread->m_callback = callback;
//		thread->m_argument = argument;
//		thread->m_running = true;
//
//		thread->m_handle = CreateThread(0, 0, [](void* argument) -> DWORD {
//			thread_context* thread = (thread_context*)argument;
//
//		while (thread && !global::vars::g_unloading) {
//			if (!thread->m_running) {
//				break;
//			}
//
//			if (thread->m_callback) {
//				thread->m_callback(thread->m_argument);
//			}
//		}
//
//		if (thread) delete thread;
//		return 0;
//			}, thread, 0, 0);
//
//		m_threads.push_back(thread);
//	}
//
//	void threads::remove_thread(const char* name) {
//		for (thread_context* thread : m_threads) {
//			if (!strcmp(thread->m_name, name)) {
//				thread->m_running = false;
//			}
//		}
//	}
//
//	void threads::cleanup() {
//		for (thread_context* thread : m_threads) {
//			thread->m_running = false;
//			TerminateThread(thread->m_handle, 0);
//		}
//	}
//
//	threads* get_threads() {
//		static threads instance;
//		return &instance;
//	}
//}
