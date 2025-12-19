#include "stdafx.h"
//
//#include <queue>
//#include <functional>
//#include <vector>
//
//namespace rage::api {
//	struct rockstar_account {
//		std::string m_name;
//		uint64_t m_rockstar_id;
//	};
//
//	struct result_info {
//		int m_total = 0;
//		int m_next_offset = 0;
//	};
//
//	struct queue_item {
//		std::string m_endpoint;
//		std::string m_data;
//		std::function<void(const char*, void*)> m_callback;
//		void* m_custom;
//		uint32_t m_data_hash;
//	};
//
//	class social_club {
//	public:
//		void update();
//		void send(std::string endpoint, std::string data, std::function<void(const char*, void*)> callback, void* custom_data);
//		void get_profiles_from_rid(uint64_t rockstar_id, std::function<void(bool, std::vector<rockstar_account>, void*)> callback, void* custom_data);
//		void get_profiles_from_name(std::string name, std::function<void(bool, std::vector<rockstar_account>, result_info*)> callback, void* custom_data, int page_offset = 0);
//
//		bool m_clear_queue = false;
//	private:
//		std::vector<queue_item> m_queue;
//	};
//
//	social_club* get_social_club();
//
//	inline void update() {
//		get_social_club()->update();
//	}
//
//	inline void send(std::string endpoint, std::string data, std::function<void(const char*, void*)> callback, void* custom_data) {
//		get_social_club()->send(endpoint, data, callback, custom_data);
//	}
//
//	inline void get_profiles_from_rid(uint64_t rockstar_id, std::function<void(bool, std::vector<rockstar_account>, void*)> callback, void* custom_data) {
//		get_social_club()->get_profiles_from_rid(rockstar_id, callback, custom_data);
//	}
//
//	inline void get_profiles_from_name(std::string name, std::function<void(bool, std::vector<rockstar_account>, result_info*)> callback, void* custom_data, int page_offset = 0) {
//		get_social_club()->get_profiles_from_name(name, callback, custom_data, page_offset);
//	}
//}
//
//
//namespace util::fiber::pool {
//	class fiber_pool {
//	public:
//		void load();
//		void update(std::function<void()>& function);
//		void add(std::function<void()> function);
//	private:
//		std::queue<std::function<void()>> m_jobs;
//	};
//
//	fiber_pool* get_fiber_pool();
//
//	inline void load() {
//		get_fiber_pool()->load();
//	}
//
//	inline void add(std::function<void()> function) {
//		get_fiber_pool()->add(function);
//	}
//}
//
//namespace util::fiber {
//	struct fiber_context {
//		fiber_context* m_next = nullptr;
//		void* m_handle = nullptr;
//		uint32_t m_wake_time = 0;
//		bool m_running = true;
//		std::string m_name = "";
//	};
//
//	class fiber_manager {
//	public:
//		void load();
//		void update();
//		void add(std::string name, std::function<void()> function);
//		void sleep(uint32_t time);
//		void go_to_main();
//		void cleanup();
//
//		std::vector<fiber_context>& get_fibers() { return m_fibers; }
//	private:
//		bool m_loaded;
//		void* m_main_fiber;
//		fiber_context* m_current;
//		std::vector<fiber_context> m_fibers;
//	};
//
//	fiber_manager* get_fiber_manager();
//	fiber_manager* get_fiber_manager_shv();
//
//	inline void load() {
//		get_fiber_manager()->load();
//	}
//
//	inline void update() {
//		get_fiber_manager()->update();
//	}
//
//	inline void add(std::string name, std::function<void()> function) {
//		get_fiber_manager()->add(name, function);
//	}
//
//	inline void sleep(uint32_t time) {
//		get_fiber_manager()->sleep(time);
//	}
//
//	inline void go_to_main() {
//		get_fiber_manager()->go_to_main();
//	}
//
//	inline void cleanup() {
//		get_fiber_manager()->cleanup();
//		get_fiber_manager_shv()->cleanup();
//	}
//
//	inline void load_shv() {
//		get_fiber_manager_shv()->load();
//	}
//
//	inline void update_shv() {
//		get_fiber_manager_shv()->update();
//	}
//
//	inline void add_shv(std::string name, std::function<void()> function) {
//		get_fiber_manager_shv()->add(name, function);
//	}
//
//	inline void sleep_shv(uint32_t time) {
//		get_fiber_manager_shv()->sleep(time);
//	}
//
//	inline void go_to_main_shv() {
//		get_fiber_manager_shv()->go_to_main();
//	}
//
//	inline std::vector<fiber_context>& get_fibers() {
//		return get_fiber_manager_shv()->get_fibers();
//	}
//}
//
//class localization {
//public:
//	localization();
//	localization(std::string original, bool translate = false, bool global_register = false);
//
//	void reset();
//	void set(std::string str);
//	void set_mapped(std::string str);
//	void set_translate(bool translate);
//	void register_translation();
//
//	std::string get_original();
//	std::string get();
//	bool has_translation();
//private:
//	bool m_translate = false;
//	std::string m_original;
//	std::string m_mapped;
//};
//
//#pragma pack(push)
//#pragma pack(1)
//struct protection_context {
//	int m_var = 0;
//	localization m_tooltip;
//
//	bool block() {
//		return m_var == 2 || m_var == 3 || m_var == 5 || m_var == 7;
//	}
//
//	bool notify() {
//		return m_var == 1 || m_var == 3 || m_var == 6 || m_var == 7;
//	}
//
//	bool redirect() {
//		return m_var >= 4;
//	}
//
//	bool enabled() {
//		return m_var > 0;
//	}
//};
//
//struct join_timeout_fix {
//	Player m_id;
//	uint32_t m_script_hash;
//	int m_retry_count;
//};
//
//struct gs_info_request {
//	bool m_finished = false;
//	int m_type; // 1 = join blocking, 2 = rid joiner, 69 = ozark
//	uint64_t m_rockstar_id;
//	uint32_t m_expiry;
//	std::function<void(std::string, uint64_t)> m_callback;
//};
//#pragma pack(push)
//#pragma pack(1)
//namespace rage::network {
//	struct player_info;
//	struct camera_manager_angles;
//	struct camera_angles;
//	struct player_angles;
//	struct net_object;
//
//	struct read_stats_by_gamer {
//		uint32_t m_bank_balance;
//		uint32_t m_wallet_balance;
//		uint32_t m_rank;
//		int m_kills;
//		int m_deaths;
//	};
//
//	struct stat_response_item {
//		int m_padding;
//		uint8_t m_type; // 0 = int, 3 = float
//
//		union {
//			int m_int;
//			uint32_t m_uint;
//			float m_float;
//		} value;
//	};
//
//	struct stat_response {
//		stat_response_item* m_stats;
//	};
//
//	struct attach_data_node {
//		char _0x0000[0xC0];
//		bool m_attached;
//		bool m_unk;
//		uint16_t m_network_id;
//	};
//
//	struct transaction {
//		int m_id;
//		int m_variation;
//		int m_price;
//		int m_multiplier;
//		int m_value;
//	};
//
//	struct net_shop_transaction_basket {
//		char _0x0000[0x8];
//		int m_transaction_id;
//		char _0x000C[0xC];
//		int m_category;
//		char _0x001C[0x8];
//		int m_action;
//		int m_target; // 4 = bank etc
//		char _0x002C[0xB4];
//		transaction m_transactions[71];
//		int m_transaction_count;
//	};
//
//	struct transaction_node {
//		char _0x0000[0x8];
//		net_shop_transaction_basket* m_transaction;
//		transaction_node* m_next;
//	};
//
//	struct metric {
//		virtual ~metric();
//		virtual int get_type();
//		virtual int get_sub_type();
//		virtual const char* get_name();
//		virtual bool create_json(uint64_t Json);
//		virtual int get_size();
//		virtual uint32_t get_hashed_name();
//	};
//
//	struct net_shop_queue {
//		char _0x0000[32];
//		void* m_first;
//		void* m_last;
//		char _0x0030[9];
//		bool m_is_busy1;
//		char _0x003A[14];
//		bool m_is_busy2;
//		char _0x0049[7];
//		bool m_is_busy3;
//	};
//
//	struct rockstar_identifier {
//		uint64_t m_rockstar_id;
//		uint32_t m_type;
//		uint32_t m_sub_type;
//	};
//
//	struct gs_session {
//		uint64_t m_peer_token;
//		uint64_t m_peer_token2;
//		uint64_t m_peer_token3;
//		rockstar_identifier m_rockstar_id;
//		char _0x0028[0x48];
//
//		uint32_t get_local_ip() {
//			return *(uint32_t*)((uint64_t)this + 0x64);
//		}
//	};
//
//	struct join_request {
//		uint32_t m_flags;
//		char _0x0004[0x4];
//		uint64_t m_net_game_player_data_msg;
//		uint32_t m_game_version; // 0x10
//		char _0x0014[0x4];
//		int m_ros_flags; // 0x18
//		char m_yeet[0x300];
//	};
//
//	struct player_gamer_data_node {
//		char _0x0000[0xC8];
//		int m_crew_id;
//		char _0x00cc[0x12];
//		char m_crew_name[0x19];
//		char m_crew_abbr[0x5];
//		char m_crew_motto[0x4C];
//		char m_crew_rank[0x18];
//	};
//
//	struct global_msg_context {
//		char m_message[0x100];
//		uint64_t m_sender_chat_token;
//		bool m_flag0_is_neg1;
//	};
//
//	struct player_peer {
//		uint8_t get_bitset() {
//			return *(uint8_t*)((uint64_t)this + 0x28);
//		}
//
//		uint8_t get_flag() {
//			return *(uint8_t*)((uint64_t)this + 0x18);
//		}
//
//		int get_player_key() {
//			return *(int*)((uint64_t)this);
//		}
//
//		int get_secondary_key() {
//			return *(int*)((uint64_t)this + 0x4);
//		}
//
//		uint32_t get_ip() {
//			return *(uint32_t*)((uint64_t)this + 0xC);
//		}
//	};
//
//	struct global_chat_raw {
//		char _0x0000[0x180];
//		int m_flag0;
//		char _0x0184[0x1D24];
//		player_peer* m_player_peers[0x20];
//		int m_player_count;
//		char _0x1fac[0xC];
//		uint64_t m_manager_ptr;
//		int m_flag1;
//		int m_flag2;
//		char _0x1fc8[0x30];
//		uint8_t m_bitset;
//	};
//
//	struct rs_info {
//		char m_scs_ticket[0x100];
//		char _0x0100[0x100];
//		char m_session_ticket[0x90];
//		uint64_t m_peer;
//		char _0x0298[0xA7];
//		char m_email[0x50];
//		char _0x038f[0x20];
//		char m_name[0x20];
//		char _0x03cf[0x29];
//		uint32_t m_rockstar_id;
//		char _0x03FC[0x1DC];
//		uint8_t m_session_key[0x10];
//	};
//
//	struct network_handle {
//		int m_handle;
//		char _0x0[48];
//	};
//
//	struct net_msg_identifier {
//		uint64_t m_rockstar_id;
//		uint8_t m_type;
//		char _0x0009[0xB];
//	};
//
//	struct net_msg_text_message {
//		char m_message[0x100];
//		net_msg_identifier m_sender;
//	};
//
//	struct network_gamer_cmd {
//		char _0x0000[0x10];
//		uint64_t m_rockstar_id; // 0x10
//		char _0x0018[0x3C];
//		uint32_t m_ip; // 0x54
//		char _0x0058[0x10];
//		uint64_t m_host_token; // 0x68
//		uint64_t m_chat_token; // 0x70
//		net_msg_identifier m_identifier; // 0x78
//		char m_name[0x14]; // 0x8C
//		char _0x00A0[0x8];
//		uint32_t m_msg_ip; // 0xA8
//
//		void set_ip(int index, uint8_t ip) {
//			uint8_t* val = (uint8_t*)&m_ip;
//			val[index] = ip;
//
//			val = (uint8_t*)&m_msg_ip;
//			val[index] = ip;
//		}
//	};
//
//	struct game_camera_angles {
//		camera_manager_angles* m_camera_manager_angles;
//		char _0x0008[56];
//	};
//
//	struct camera_manager_angles {
//		camera_angles* m_camera_angles;
//	};
//
//	struct camera_angles {
//		char _0x0000[0x3C0];
//		player_angles* m_fps_player_angles;
//		char _0x03C8[0x10];
//		uint64_t m_ped;
//	};
//
//	/*struct player_angles {
//		char _0x0000[0x40];
//		math::vector3_<float> m_view_angles;
//		char _0x0004C[0x14];
//		math::vector3_<float> m_crosshair_location;
//	};*/
//
//	struct player_info {
//		char _0x0000[0x20];
//		uint64_t m_host_token2;
//		uint64_t m_rockstar_id;
//		char _0x0030[0x3C];
//		uint32_t m_external_ip;
//		uint32_t m_external_port;
//		uint32_t m_internal_ip;
//		uint32_t m_internal_port;
//		char _0x007C[0x4];
//		uint64_t m_host_token;
//		uint64_t m_chat_token;
//		net_msg_identifier m_identifier;
//		char m_name[0x14]; // A4
//		char _0x00B8[0xB4];
//		float m_swim_speed; // 16C
//		float m_run_speed; // 170
//		char _0x0174[0xA4];
//		uint32_t m_frame_flags; // 218
//		char _0x021C[0xDD4];
//		char _new_padding[0x10];
//		uint32_t m_aim_flag; // FF0
//
//		bool is_free_aiming() {
//			return m_aim_flag >> 6 & 1;
//		}
//
//		void set_ip(int Index, uint8_t IP) {
//			uint8_t* Val = (uint8_t*)&m_external_ip;
//			Val[Index] = IP;
//		}
//
//		void set_run_speed(float Speed) {
//			*(float*)((uint64_t)this + 0xCF0) = Speed;
//		}
//	};
//
//	struct net_game_player {
//		char _0x0000[0x21];
//		int8_t m_id;
//		char _0x0022[0x7E];
//		player_info* m_player_info;
//		char _0x00b8[0xF1];
//		bool m_is_rockstar_developer; // 1A9
//		bool m_is_rockstar_qa; // 1AA
//		bool m_is_cheater; // 1AB
//		char _0x01AB[0x94];
//		uint8_t m_report_bits; // 240
//		char _0x0241[0x3];
//		int* m_report_reasons; // 244
//		char _0x024C[0x48];
//		int m_max_report_reasons; // 294
//
//		const char* get_crew_motto() {
//			return (const char*)((uint64_t)this + 0x104);
//		}
//
//		const char* get_crew_name() {
//			return (const char*)((uint64_t)this + 0xE6);
//		}
//
//		const char* get_crew_tag() {
//			return (const char*)((uint64_t)this + 0xFF);
//		}
//
//		const char* get_crew_rank() {
//			return (const char*)((uint64_t)this + 0x150);
//		}
//
//		int get_crew_id() {
//			return *(int*)((uint64_t)this + 0x148);
//		}
//	};
//	enum eNetObjectTypes : uint16_t {
//		NetObjectAutomobile,
//		NetObjectBike,
//		NetObjectBoat,
//		NetObjectDoor,
//		NetObjectHeli,
//		NetObjectObject,
//		NetObjectPed,
//		NetObjectPickup,
//		NetObjectPickupPlacement,
//		NetObjectPlane,
//		NetObjectSubmarine,
//		NetObjectPlayer,
//		NetObjectTrailer,
//		NetObjectTrain,
//		INVALID
//	};
//	struct net_object {
//		uint64_t m_vtable;
//		eNetObjectTypes m_type;
//		int16_t m_network_id;
//		char _0x000C[0x14];
//		int8_t m_player_sync_intervals[0x20];
//		char _0x0040[0x9];
//		uint8_t m_owner; // 0x49
//		char _0x004A[0x6];
//		uint64_t m_entity;
//		char _0x0058[0x4C0];
//		int16_t m_spectating_network_id;
//	};
//
//	struct data_node_common_operations {
//		virtual ~data_node_common_operations();
//
//		uint64_t m_data;
//	};
//
//	struct data_node {
//		virtual ~data_node() = 0;
//		virtual bool is_data_node() = 0;
//		virtual bool is_parent_node() = 0;
//
//		data_node* m_next; //0x0008
//		data_node* m_previous; //0x0010
//		uint64_t m_sync_tree; //0x0018
//		data_node* m_parent; //0x0020
//		uint32_t m_flag; //0x0028
//		uint32_t m_flag2; //0x002C
//		uint32_t m_flag3; //0x0030
//		char _0x0034[0x4]; //0x0034
//		data_node* m_first_child; //0x0038
//		data_node* m_last_child; //0x0040
//		uint64_t m_unk_data; //0x0048
//		uint32_t m_child_count; //0x0050
//		char _0x0054[0x54];
//		data_node_common_operations* m_data_node_common_operations; // 0xA8
//
//		bool is_writing() {
//			return *(bool*)((uint64_t)this + 0x40);
//		}
//	};
//
//	struct friends {
//		char _0x0000[128]; //0x0000
//		char m_name[32]; //0x0080
//		char _0x00A0[24]; //0x00A0
//		uint64_t m_rockstar_id; //0x00B8
//		char _0x00C0[4]; //0x00C0
//		int m_state; //0x00C4
//		char _0x00C8[312]; //0x00C8
//	};
//
//	struct event_added_gamer {
//		char _0x0000[0x6C];
//		uint32_t m_external_ip;		// 0x006C
//		char _0x0070[0x20];			// 0x0070
//		uint64_t m_rockstar_id;		// 0x0090
//		char _0x00098[0xC];			// 0x0098
//		char m_name[0x14];			// 0x00A4
//	};
//
//	struct blacklisted_player {
//		net_msg_identifier m_player;
//		uint32_t m_timestamp;
//		blacklisted_player* m_next;
//		blacklisted_player* m_last;
//	};
//
//	struct network_base_config {
//		char _0x0000[0x20];
//		uint64_t m_unk_ptr;
//		uint64_t m_unk_ptr2;
//		char _0x0030[0x198F8];
//		net_msg_identifier m_last_blacklisted; // 0x19928
//		uint32_t m_last_blacklisted_timestamp;
//		char _0x184b0[0x280];
//		blacklisted_player* m_first_blacklisted_player;
//		blacklisted_player* m_last_blacklisted_player;
//
//		void set_network_session_was_invited(bool invited);
//
//		gs_session* get_gs_session() {
//			return (gs_session*)((uint64_t)this + 0x178);
//		}
//
//		uint64_t get_net_msg_manager() {
//			return *(uint64_t*)((uint64_t)this + 0x48);
//		}
//	};
//
//	struct kick_peer {
//		uint64_t m_peer;
//		char _0x0008[5];
//		bool m_kicked;
//		char _0x000E[2];
//	};
//
//	struct list_kick_peers {
//		kick_peer m_peers[0x20];
//	};
//
//	struct sync_tree {
//		void* m_vtable;
//		net_object* m_object;
//		data_node* m_parent_node;
//		char _0x0018[0x8];
//		int m_data_node_count;
//		char _0x0024[0xC];
//		data_node** m_nodes;
//	};
//
//	struct game_invite {
//		char _0x0000[8]; //0x0000
//		gs_session gssession_start; //0x0008
//		uint64_t h; //0x0058
//		uint64_t h2; //0x0060
//		char s[125]; //0x0068
//		char n[17]; //0x00B5
//		char _0x00C6[2]; //0x00C6
//		uint32_t gm; //0x00C8
//		char c[23]; //0x00CC
//		char _0x00E3[5]; //0x00E3
//		uint64_t cc; //0x00E8
//		uint64_t cc2;
//		char mid[30]; //0x00F8
//		char _0x0116[2]; //0x0116
//		uint32_t if_; //0x0118
//		uint32_t it; //0x011C
//		uint32_t l; //0x0120
//		uint32_t p; //0x0124
//		uint32_t f; //0x0128
//		uint32_t cr; //0x012C
//		uint32_t u; //0x0130
//		uint32_t d; //0x0134
//		uint32_t jq; //0x0138
//	};
//
//	struct chat_config {
//		char _0x0000[0x10];
//		uint32_t m_override_gxt; // only works when it's a team message
//		char _0x0014[0x134];
//		uint32_t m_chat_color;
//		bool m_using_chat_color;
//	};
//}
//#pragma pack(pop)
//namespace global::vars {
//	extern uint64_t g_ros_init_crypto;
//	extern uint64_t g_ros_read_stats_by_gamer;
//	extern uint64_t g_ros_download_player_image;
//
//	extern bool g_arxan_called[10];
//	extern bool g_chinese;
//	extern bool g_unloading;
//	extern bool g_unloading_queue;
//	extern bool g_freemode_terminated;
//	extern bool g_reapply_weapons;
//	extern HMODULE g_module_handle;
//	extern std::pair<uint64_t, uint32_t> g_cheat_address;
//	extern std::pair<uint64_t, uint32_t> g_game_address;
//	extern HWND g_window;
//	//extern std::vector<localization*> g_localization_table;
//	extern bool g_steam;
//	extern bool g_reload_weapons;
//	extern std::pair<float, std::string> g_selected_metric_system;
//	extern std::unordered_map<uint64_t, std::pair<bool, int>> g_online_rockstar_ids;
//	extern std::vector<uint64_t> g_online_rockstar_ids_queue;
//	//extern std::vector<relay_usage> g_relay_usage;
//	extern std::queue<uint32_t> g_geo_queue;
//	/*extern std::unordered_map<uint32_t, geo_ip> g_geo;
//	extern rage::types::dictionary* g_custom_dictionary;
//	extern rage::types::dictionary* g_player_img_dictionary;
//	extern math::vector2<int> g_resolution;
//	extern math::vector2<int> g_desktop_resolution;*/
//	extern uint64_t g_texture_bypass;
//	extern uint64_t g_marker_bypass;
//	//extern std::unordered_map<std::string, alignment_test> g_alignment_tests;
//	//extern std::vector<patches> g_patches;
//	//extern std::unordered_map<std::string, patches> g_hack_patches;
//	extern std::vector<std::pair<uint64_t, int>> g_return_address_node_iterations;
//	extern std::unordered_map<uint64_t, uint64_t> g_desyncs_host;
//	//extern std::unordered_map<Player, desyncs> g_desyncs;
//	extern std::vector<join_timeout_fix> g_join_timeout_fix;
//	extern std::vector<std::pair<uint64_t, uint64_t>> g_host_desync_logs;
//	extern std::unordered_map<int, uint32_t> g_last_synced_player_models;
//	extern std::vector<gs_info_request> g_gs_info_requests;
//	extern std::unordered_map<uint64_t, uint32_t> g_spoofed_data_join_requests;
//	extern std::unordered_map<uint64_t, std::pair<uint32_t, uint32_t>> g_raw_buffer_translations;
//	extern std::unordered_map<uint64_t, uint32_t> g_sync_real_ip;
//	extern std::unordered_map<uint64_t, uint64_t> g_sync_peer_corruption;
//	extern uint8_t g_arxan_restore_bytes[2][2][25];
//	extern uint64_t g_arxan_restore_addresses[2];
//	extern std::unordered_map<uint64_t, rage::network::read_stats_by_gamer> g_read_stats_by_gamer_results;
//	extern std::vector<std::pair<uint32_t, uint8_t*>> g_player_image_queue;
//	//extern PlayerMenuType g_network_menu_type;
//	extern bool g_change_peer;
//
//	// game structures
//	//extern game_state* g_game_state;
//	//extern rage::invoker::native_registration** g_native_registration;
//	//extern rage::network::rs_info* g_rs_info;
//	//extern rage::types::ped_factory* g_ped_factory;
//	//extern rage::network::game_camera_angles* g_game_camera_angles;
//	//extern rage::types::waypoint_data* g_waypoint_data;
//	//extern rage::network::net_shop_queue* g_net_shop_queue;
//	//extern rage::types::ui_visual_settings* g_ui_visual_settings;
//	//extern rage::types::vfx_liquid* g_vfx_liquid;
//	//extern rage::network::friends* g_friends;
//	//extern rage::types::texture_store* g_texture_store;
//	//extern rage::types::store_manager* g_store_manager;
//	//extern rage::types::memory_heap_pt* g_memory_heap;
//	////extern rage::types::replay_interface* g_replay_interface;
//	//extern rage::types::explosion_data* g_explosion_data;
//	//extern rage::types::explosion_fx* g_explosion_fx;
//	//extern rage::network::network_base_config* g_network_base_config;
//	//extern rage::types::ocean_quads g_ocean_quads;
//	//extern rage::types::water_tune* g_water_tune;
//	//extern rage::types::ui_weather* g_ui_weather;
//	//extern rage::types::ui_puddle* g_ui_puddle;
//	//extern rage::types::blip_list* g_blip_list;
//
//	//// game pools
//	//extern guid_pool* g_object_pool;
//	//extern guid_pool* g_ped_pool;
//	//extern vehicle_pool* g_vehicle_pool;
//	//extern guid_pool* g_pickup_pool;
//
//	//// game lists
//	//extern hash_list g_weapon_components;
//	//extern hash_list g_weapon_info;
//	//extern hash_list g_script_handlers;
//	//extern std::pair<rage::types::vfx_wheel*, uint8_t> g_vfx_wheel;
//
//	// game addresses
//	extern uint64_t g_d3d11_device;
//	extern uint64_t g_process_transaction_id;
//	extern uint64_t g_sync_data_reader_vtable;
//	extern uint64_t g_nullsub;
//	extern uint64_t** g_global_cache;
//	extern uint64_t g_read_bool_from_bit_buffer;
//	extern uint64_t g_read_int_from_bit_buffer;
//	extern uint64_t g_read_uint_from_bit_buffer;
//	extern uint64_t g_read_byte_from_bit_buffer;
//	extern uint64_t g_read_ulonglong_from_bit_Buffer;
//	extern uint64_t g_read_short_from_bit_buffer;
//	extern uint64_t g_read_vector3_from_bit_buffer;
//	extern uint64_t g_read_array_from_bit_buffer;
//	extern uint64_t g_read_msg_header_from_bit_buffer;
//	extern uint64_t g_read_pickup_from_bit_buffer;
//	extern uint64_t g_write_uint_to_bit_buffer;
//	extern uint64_t g_sc_game_info_table;
//	extern uint64_t g_sc_get_game_info_table;
//	extern uint64_t g_game_streamed_scripts;
//	extern uint64_t g_get_streamed_script;
//	extern uint64_t g_get_third_person_camera;
//	extern uint64_t g_third_person_camera;
//	extern uint64_t g_get_entity_address;
//	extern uint64_t g_get_entity_handle_from_address;
//	extern uint64_t g_get_net_game_player_from_index;
//	extern uint64_t g_get_model_info;
//	extern uint64_t g_set_vehicle_gravity;
//	extern uint64_t g_get_vehicle_paint_array;
//	extern uint64_t g_draw_origin_index;
//	extern uint64_t g_add_to_clock_time;
//	extern uint64_t g_dispatch_service_table;
//	extern uint64_t g_sync_clock_time;
//	extern uint64_t g_send_weather_update;
//	extern uint64_t g_get_host_net_game_player;
//	extern uint64_t g_send_increment_stat_event;
//	extern uint64_t g_update_net_object_owner;
//	extern uint64_t g_network_object_manager;
//	extern uint64_t g_network_player_manager;
//	extern uint64_t g_handle_rotation_values_from_order;
//	extern uint64_t g_get_net_game_player_from_handle;
//	extern uint64_t g_get_sprite_texture;
//	extern uint64_t g_send_text_message_net_msg;
//	extern uint64_t g_set_traffic_lights;
//	extern uint64_t g_update_traffic_lights;
//	extern uint64_t g_set_traffic_light_colors;
//	extern uint64_t g_set_vehicle_lights;
//	extern uint64_t g_get_sync_tree_from_clone_type;
//	extern uint64_t g_get_network_object_from_network_id;
//	extern uint64_t g_get_network_config_from_peer;
//	extern uint64_t g_network_event_registration;
//	extern uint64_t g_update_ui_values;
//	extern uint64_t g_update_ui_values_2;
//	extern uint64_t g_set_vehicle_neon_ui;
//	extern uint64_t g_set_seethrough;
//	extern uint64_t g_add_basket_to_queue;
//	extern uint64_t g_add_item_to_basket;
//	extern uint64_t g_send_session_info_request;
//	extern uint64_t g_get_session_info_from_gs;
//	extern uint64_t g_send_network_event_reply;
//	extern uint64_t g_send_network_event_ack;
//	extern uint64_t g_setup_give_control_event;
//	extern uint64_t g_send_friend_request;
//	extern uint64_t g_get_client_player_key;
//	extern uint64_t g_render_water_on_map_intensity;
//	extern uint64_t g_map_fog_intensity;
//	extern uint64_t g_send_presence_event;
//	extern uint64_t g_migrate_script_host;
//	extern uint64_t g_is_reported_for_reason;
//	extern uint64_t g_chat_info;
//	extern uint64_t g_send_matchmaking_request;
//	extern uint64_t g_read_xml_string;
//	extern uint64_t g_read_xml_node_string;
//	extern uint64_t g_register_streaming_file;
//	extern uint64_t g_create_game_invite_presence;
//	extern uint64_t g_send_game_invite_presence;
//	extern uint64_t g_send_game_invite_presence_table;
//	extern uint64_t g_send_ragdoll_event;
//	extern uint64_t g_grc_texture_factory_dx11;
//	extern uint64_t g_thread_alloc;
//	extern uint64_t g_setup_dictionary;
//	extern uint64_t g_setup_store_item;
//	extern uint64_t g_is_valid_pool_slot;
//	extern uint64_t g_add_dictionary_to_pool;
//	extern uint64_t g_add_grc_texture_to_dictionary;
//	extern uint64_t g_get_weather_id;
//	extern uint64_t g_weather_table;
//	extern uint64_t g_get_font_id_table;
//	extern uint64_t g_get_store_module_extension;
//	extern uint64_t g_request_streaming_file;
//	extern uint64_t g_construct_gfx_font;
//	extern uint64_t g_destruct;
//	extern uint64_t g_create_id_for_font;
//	extern uint64_t g_add_font_lib;
//	extern uint64_t g_vertex_begin;
//	extern uint64_t g_vertex_end;
//	extern uint64_t g_vertex_add;
//	extern uint64_t g_render_script_texture;
//	extern uint64_t g_font_table;
//	extern uint64_t g_font_memory_helper;
//	extern uint64_t g_parse_nodes;
//	extern uint64_t g_read_new_script_host_message;
//	extern uint64_t g_write_gs_item;
//	extern uint64_t g_game_script_handler_manager;
//	extern uint64_t g_translate_native;
//	extern uint64_t g_global_chat_ptr;
//	extern uint64_t g_send_global_chat_message;
//	extern uint64_t g_add_chat_message;
//	extern uint64_t g_chat_config;
//	extern uint64_t g_ped_orientation_writer;
//	extern uint64_t g_entity_orientation_writer;
//	extern uint64_t g_social_club_game_info_table;
//	extern uint64_t g_social_club_get_game_info_table;
//	extern uint64_t g_reset_script_render_params[2];
//	extern uint64_t g_get_player_info_from_net_msg;
//	extern uint64_t g_drop_shaders;
//	extern uint64_t g_drop_shader_count;
//	extern uint64_t g_get_net_msg_net_player;
//	extern uint64_t g_ui_3d_draw_manager;
//	extern uint64_t g_push_scene_preset_to_manager;
//	extern uint64_t g_add_element_to_scene;
//	extern uint64_t g_set_scene_element_lighting;
//	extern uint64_t g_invalid_string_address;
//	extern uint64_t g_construct_read_session_join_request_msg;
//	extern uint64_t g_read_session_join_request_msg;
//	extern uint64_t g_read_token_from_bit_buffer;
//	extern uint64_t g_read_string_from_bit_buffer;
//	extern uint64_t g_invite_player;
//	extern uint64_t g_sync_data_writer_vtable;
//
//	extern uint32_t g_ozark_detections[100];
//}
//#pragma pack(pop)
//
//
//
//class base_option {
//public:
//	base_option();
//	base_option(std::string name, bool breaker = false, bool slider = false, bool input = false);
//
//	virtual void render(int position);
//	virtual void render_selected(int position, std::stack<std::string> submenu_name_stack);
//	virtual void invoke_save(std::stack<std::string> submenu_name_stack);
//	virtual void invoke_hotkey();
//	virtual void write_translation(nlohmann::json& object);
//	virtual void read_translation(nlohmann::json& object);
//	virtual void reset_translation();
//
//	bool is_visible() { return m_visible && m_requirement(); }
//	bool is_break() { return m_break_option; }
//	bool is_slider() { return m_slider; }
//	bool is_input() { return m_input; }
//	bool is_savable() { return m_savable; }
//	bool has_hotkey() { return m_has_hotkey; }
//	int get_hotkey() { return m_hotkey; }
//
//	localization& get_name() { return m_name; }
//	localization& get_tooltip() { return m_tooltip; }
//	std::stack<std::string>* get_submenu_name_stack() { return m_submenu_name_stack; }
//
//	void set_hotkey(int key) { m_hotkey = key; };
//	void set_name(std::string name) { m_name.set(name); };
//	void set_submenu_name_stack(std::stack<std::string>* stack) { m_submenu_name_stack = stack; }
//	void set_tooltip(std::string tooltip) { m_tooltip.set(tooltip); }
//protected:
//	localization m_name;
//	localization m_tooltip;
//
//	bool m_break_option = false;
//	bool m_visible = true;
//	bool m_savable = false;
//	bool m_slider = false;
//	bool m_input = false;
//	bool m_has_hotkey = false;
//	int m_hotkey = -1;
//
//	std::function<bool()> m_requirement = []() { return true; };
//	std::vector<std::tuple<std::string, int, bool>> m_instructionals = {};
//	std::stack<std::string>* m_submenu_name_stack = nullptr;
//};
//
//class button_option : public base_option {
//public:
//	button_option(std::string name)
//		: base_option(name) {}
//
//	button_option& ref() {
//		return *this;
//	}
//
//	button_option& add_click(std::function<void()> function) {
//		m_on_click = function;
//		return *this;
//	}
//
//	button_option& add_click_this(std::function<void(button_option*)> function) {
//		m_on_click_this = function;
//		return *this;
//	}
//
//	button_option& add_requirement(std::function<bool()> function) {
//		m_requirement = function;
//		return *this;
//	}
//
//	button_option& add_update(std::function<void(button_option*)> function) {
//		m_on_update = function;
//		return *this;
//	}
//
//	button_option& add_update_this(std::function<void(button_option*, int)> function) {
//		m_on_update_this = function;
//		return *this;
//	}
//
//	button_option& add_hover(std::function<void()> function) {
//		m_on_hover = function;
//		return *this;
//	}
//
//	button_option& add_tooltip(std::string tooltip) {
//		m_tooltip.set(tooltip.c_str());
//		return *this;
//	}
//
//	button_option& add_keyboard(std::string title, int max_chars, std::function<void(button_option*, const char*)> function) {
//		m_keyboard = { true, false, max_chars, function, title };
//		return *this;
//	}
//
//	button_option& add_translate() {
//		m_name.set_translate(true);
//		m_tooltip.set_translate(true);
//		return *this;
//	}
//
//	/*button_option& remove_sprite() {
//		m_sprite.m_enabled = false;
//		return *this;
//	}
//
//	button_option& add_sprite(std::pair<std::string, std::string> asset, std::function<bool()> requirement = [] { return true; }) {
//		m_sprite = { true, asset, requirement };
//		return *this;
//	}*/
//
//	/*button_option& add_sprite_scale(math::vector2<float> scale) {
//		m_sprite.m_scale = scale;
//		return *this;
//	}*/
//
//	/*button_option& add_sprite_rotation() {
//		m_sprite.m_rotate = true;
//		return *this;
//	}*/
//
//	/*button_option& add_instructional(std::string text, eScaleformButtons button_option) {
//		m_instructionals.push_back({ text, button_option, false });
//		return *this;
//	}*/
//
//	/*button_option& add_instructional(std::string text, eControls button_option) {
//		m_instructionals.push_back({ text, button_option, true });
//		return *this;
//	}*/
//
//	button_option& add_side_text(std::string text) {
//		m_side_text = { true, text };
//		return *this;
//	}
//
//	button_option& add_hotkey() {
//		m_has_hotkey = true;
//		return *this;
//	}
//
//	button_option& add_offset(float offset) {
//		m_offset = offset;
//		return *this;
//	}
//
//	button_option& add_keyboard_default(std::string de) {
//		m_keyboard.m_default_text = de;
//		return *this;
//	}
//
//	void render(int position);
//	void render_selected(int position, std::stack<std::string> submenu_name_stack);
//	void invoke_save(std::stack<std::string> submenu_name_stack) {}
//	void invoke_hotkey();
//	void write_translation(nlohmann::json& object) {}
//	void read_translation(nlohmann::json& object) {}
//	void reset_translation() {}
//private:
//	struct Keyboard {
//		bool m_enabled = false;
//		bool m_is_active = false;
//		int m_max_chars = 0;
//		std::function<void(button_option*, const char*)> m_callback = {};
//		std::string m_title = "";
//		std::string m_default_text = "";
//	};
//
//	/*struct Sprite {
//		bool m_enabled = false;
//		std::pair<std::string, std::string> m_asset = {};
//		std::function<bool()> m_requirement = {};
//		math::vector2<float> m_scale = { 0.f, 0.f };
//		bool m_rotate = false;
//		float m_rotation = 0.f;
//	};*/
//
//	struct SideText {
//		bool m_enabled = false;
//		std::string m_text = "";
//	};
//
//	Keyboard m_keyboard;
//	//Sprite m_sprite;
//	SideText m_side_text;
//	float m_offset = 0.f;
//
//	std::function<void()> m_on_click = []() {};
//	std::function<void(button_option*)> m_on_click_this = [](button_option*) {};
//	std::function<void()> m_on_hover = []() {};
//	std::function<void(button_option*)> m_on_update = [](button_option*) {};
//	std::function<void(button_option*, int)> m_on_update_this = [](button_option*, int) {};
//};
//namespace menu::submenu {
//	class submenu {
//	public:
//		void update_menu();
//		void clear_options(int offset);
//
//		virtual void load();
//		virtual void update_once();
//		virtual void update();
//		virtual void feature_update();
//
//		void set_parent(submenu* submenu) { m_parent = submenu; }
//		void set_can_be_searched(bool searchable) { m_can_be_searched = searchable; }
//		void set_default_instructionals(bool def) { m_default_instructionals = def; }
//		void set_old_current_option(int val) { m_old_current_option = val; }
//		void set_old_scroll_offset(int val) { m_old_scroll_offset = val; }
//		void set_name(std::string str, bool translation = true, bool searchable = true);
//
//		submenu* get_parent() { return m_parent; }
//		bool can_be_searched() { return m_can_be_searched; }
//		bool get_default_instructionals() { return m_default_instructionals; }
//		int get_old_current_option() { return m_old_current_option; }
//		int get_old_scroll_offset() { return m_old_scroll_offset; }
//		std::vector<std::shared_ptr<base_option>>& get_options() { return m_options; }
//		std::vector<localization>& get_strings() { return m_strings; }
//		std::stack<std::string>& get_submenu_name_stack() { return m_submenu_name_stack; }
//		std::string get_string(std::string str);
//
//		void add_string(std::string str) { m_strings.push_back(localization(str, true)); }
//		localization& get_name() { return m_name; }
//
//		template<typename T>
//		std::shared_ptr<T> add_option(T& option) {
//			std::shared_ptr<T> ptr = std::make_shared<T>(option);
//			m_options.push_back(ptr);
//
//			ptr.get()->set_submenu_name_stack(&m_submenu_name_stack);
//
//			if (ptr.get()->has_hotkey()) {
//				hotkey::read_hotkey(ptr.get());
//			}
//
//			return ptr;
//		}
//
//		template<typename T>
//		std::shared_ptr<T>& add_option(std::shared_ptr<T>& option) {
//			m_options.push_back(option);
//
//			option.get()->set_submenu_name_stack(&m_submenu_name_stack);
//
//			if (option.get()->has_hotkey()) {
//				hotkey::read_hotkey(option.get());
//			}
//
//			return option;
//		}
//
//		template<typename T>
//		void set_parent() {
//			m_parent = T::get();
//			m_submenu_name_stack = {};
//
//			m_submenu_name_stack.push(m_name.get_original());
//
//			submenu* submenu = m_parent;
//			while (submenu) {
//				m_submenu_name_stack.push(submenu->m_name.get_original());
//				submenu = submenu->get_parent();
//			}
//		}
//	private:
//		localization m_name;
//		submenu* m_parent = nullptr;
//
//		bool m_can_be_searched = true;
//		bool m_default_instructionals = true;
//		int m_old_current_option = 0;
//		int m_old_scroll_offset = 0;
//
//		std::vector<std::shared_ptr<base_option>> m_options = {};
//		std::vector<localization> m_strings = {};
//		std::stack<std::string> m_submenu_name_stack = {};
//	};
//}
//class network_player_search_menu : public menu::submenu::submenu {
//public:
//	static network_player_search_menu* get();
//
//	void load() override;
//	void update_once() override;
//	void update() override;
//	void feature_update() override;
//
//	network_player_search_menu()
//		: menu::submenu::submenu() {}
//};
//
//namespace network::player::search::vars {
//	struct variables {
//		std::vector<rage::api::rockstar_account> m_accounts;
//		int m_current_page = 0;
//		int m_current_offset = 0;
//		int m_total = 0;
//		int m_total_pages_requested = 0;
//		bool m_processing_next_page = false;
//
//		std::string m_name = "";
//		uint64_t m_rockstar_id = 0;
//
//		std::vector<uint64_t> m_queue;
//		std::vector<uint64_t> m_image_queue;
//	};
//
//	extern variables m_vars;
//}
//namespace util::threads {
//	struct thread_context {
//		const char* m_name = "";
//		HANDLE m_handle = 0;
//		bool m_running = true;
//		void* m_argument = nullptr;
//		std::function<void(void*)> m_callback = {};
//	};
//
//	class threads {
//	public:
//		void add_job(std::function<void(void*)> callback, void* argument = nullptr);
//		void add_thread(const char* name, std::function<void(void*)> callback, void* argument = nullptr);
//		void remove_thread(const char* name);
//		void cleanup();
//	private:
//		std::vector<thread_context*> m_threads;
//	};
//
//	threads* get_threads();
//
//	inline void add_job(std::function<void(void*)> callback, void* argument = nullptr) {
//		get_threads()->add_job(callback, argument);
//	}
//
//	inline void add_thread(const char* name, std::function<void(void*)> callback, void* argument = nullptr) {
//		get_threads()->add_thread(name, callback, argument);
//	}
//
//	inline void remove_thread(const char* name) {
//		get_threads()->remove_thread(name);
//	}
//
//	inline void cleanup() {
//		get_threads()->cleanup();
//	}
//}
//
//class submenu_option : public base_option {
//public:
//	submenu_option(std::string name)
//		: base_option(name) {}
//
//	template<typename T>
//	submenu_option& add_submenu() {
//		m_submenu = T::get();
//		return *this;
//	}
//
//	submenu_option& add_click(std::function<void()> function) {
//		m_on_click = function;
//		return *this;
//	}
//
//	submenu_option& add_click_this(std::function<void(submenu_option*)> function) {
//		m_on_click_this = function;
//		return *this;
//	}
//
//	submenu_option& add_requirement(std::function<bool()> function) {
//		m_requirement = function;
//		return *this;
//	}
//
//	submenu_option& add_update(std::function<void(submenu_option*, int)> function) {
//		m_on_update = function;
//		return *this;
//	}
//
//	submenu_option& add_hover(std::function<void(submenu_option*)> function) {
//		m_on_hover = function;
//		return *this;
//	}
//
//	submenu_option& add_tooltip(std::string tooltip) {
//		m_tooltip.set(tooltip.c_str());
//		return *this;
//	}
//
//	submenu_option& add_translate() {
//		m_name.set_translate(true);
//		m_tooltip.set_translate(true);
//		return *this;
//	}
//
//	submenu_option& add_hotkey() {
//		m_has_hotkey = true;
//		return *this;
//	}
//
//	submenu_option& add_side_text(std::string text) {
//		m_side_text = { true, text };
//		return *this;
//	}
//
//	submenu_option& add_offset(float offset) {
//		m_offset = offset;
//		return *this;
//	}
//
//	/*submenu_option& add_icon_override(std::pair<std::string, std::string> asset, math::vector2<float> offset, math::vector2<float> scale, color_rgba* color) {
//		m_override = { true, asset, offset, scale, color };
//		return *this;
//	}*/
//
//	submenu_option& add_custom_data(uint8_t* data) {
//		memcpy(m_custom_data, data, 0x10);
//		return *this;
//	}
//
//	submenu_option& disable_icon() {
//		m_disable_icon = true;
//		return *this;
//	}
//
//	uint8_t* get_custom_data() {
//		return m_custom_data;
//	}
//
//	void render(int position);
//	void render_selected(int position, std::stack<std::string> submenu_name_stack);
//	void invoke_save(std::stack<std::string> submenu_name_stack) {}
//	void invoke_hotkey();
//	void write_translation(nlohmann::json& object) {}
//	void read_translation(nlohmann::json& object) {}
//	void reset_translation() {}
//private:
//	struct side_text {
//		bool m_enabled = false;
//		std::string m_text = "";
//	};
//
//	/*struct icon_override {
//		bool m_enabled = false;
//		std::pair<std::string, std::string> m_asset = {};
//		math::vector2<float> m_offset;
//		math::vector2<float> m_scale;
//		color_rgba* m_color;
//	};*/
//
//	side_text m_side_text;
//	//icon_override m_override;
//	float m_offset = 0.f;
//	uint8_t m_custom_data[0x10];
//	bool m_disable_icon = false;
//
//	menu::submenu::submenu* m_submenu = nullptr;
//
//	std::function<void()> m_on_click = []() {};
//	std::function<void(submenu_option*)> m_on_click_this = [](submenu_option*) {};
//	std::function<void(submenu_option*)> m_on_hover = [](submenu_option*) {};
//	std::function<void(submenu_option*, int)> m_on_update = [](submenu_option*, int) {};
//};
//
//class network_player_search_selected_menu : public menu::submenu::submenu {
//public:
//	static network_player_search_selected_menu* get();
//
//	void load() override;
//	void update_once() override;
//	void update() override;
//	void feature_update() override;
//
//	network_player_search_selected_menu()
//		: menu::submenu::submenu() {}
//};
//namespace network::player::search::selected::vars {
//	struct variables {
//		rage::api::rockstar_account* m_selected;
//	};
//
//	void join_player(uint64_t rockstar_id);
//	extern variables m_vars;
//}
//namespace util::va {
//	const char* va(const char* fmt, ...);
//	const char* vap(char* buffer, const char* fmt, ...);
//	const wchar_t* vaw(const char* fmt, ...);
//	void cleanup();
//}
//
//
//
//namespace menu::panels {
//	class panel_manager;
//	struct panel_child;
//
//	struct panel_custom_recent_player {
//		char m_name[0x20];
//		char m_ip[16];
//		uint64_t m_rockstar_id;
//		int m_session_type;
//		char m_first_encountered[0x50];
//		char m_last_encountered[0x50];
//		bool m_in_session;
//		bool m_online;
//		bool m_has_stats;
//		rage::network::read_stats_by_gamer m_stats;
//	};
//
//	struct panel_custom_friend {
//		char m_name[32];
//		uint64_t m_rockstar_id;
//		bool m_has_stats;
//		rage::network::read_stats_by_gamer m_stats;
//		bool m_online;
//		bool m_in_session;
//		int m_session_type;
//	};
//
//	struct panel_custom_overseer {
//		char m_name[32];
//		uint64_t m_rockstar_id;
//		int m_flags;
//		bool m_has_stats;
//		rage::network::read_stats_by_gamer m_stats;
//		bool m_online;
//		bool m_in_session;
//		int m_session_type;
//	};
//
//	struct panel_custom_vehicle_preview {
//		uint32_t m_model;
//		char m_dict[50];
//		char m_name[50];
//		char m_manufacturer[12];
//		float m_max_speed;
//		float m_max_braking;
//		float m_max_traction;
//		int m_seats;
//	};
//
//	struct panel_custom_session_browser {
//		uint64_t m_rockstar_id;
//		uint64_t m_peer_token;
//		char m_name[0x20];
//		bool m_has_stats;
//		rage::network::read_stats_by_gamer m_stats;
//		uint32_t m_local_ip;
//	};
//
//	struct panel_custom_player_search {
//		uint64_t m_rockstar_id;
//		bool m_online;
//		char m_name[0x20];
//		bool m_has_stats;
//		rage::network::read_stats_by_gamer m_stats;
//	};
//
//	struct panel_custom_blacklisted_player {
//		char m_name[0x20];
//		uint64_t m_rockstar_id;
//		uint32_t m_blacklisted_time;
//	};
//
//	/*struct panel_custom_screen_ped_preview {
//		rage::types::ped* m_ped;
//		math::vector3_<float> m_screen_offset;
//		bool m_is_player;
//		Player m_player;
//	};*/
//
//	struct panel_parent {
//		bool m_render; // needed to render *any* children
//		std::string m_id; // identifier
//		std::string m_name;
//		//std::unordered_map<int, math::vector2<float>> m_column_offset; // index'd by column
//		std::vector<panel_child> m_children_panels;
//	};
//
//	struct panel_child {
//		panel_parent* m_parent;
//		bool m_render; // render this child
//		std::string m_id; // identifier
//		std::string m_name;
//
//		bool m_double_sided = true;
//		int m_index = 0; // render order
//		int m_column = 0; // 0 = next to menu, 1 = next to that, etc
//		int m_panel_tick_left = 0; // used for drawing
//		int m_panel_tick_right = 0; // used for drawing
//		int m_panel_option_count_left = 0; // used for drawing
//		int m_panel_option_count_right = 0; // used for drawing
//
//		uint8_t m_custom_ptr[0x150]; // struct addresses for passing data
//		//math::vector2<float>(*m_update)(panel_child&); // callback for rendering, returns total height of rendered element
//	};
//
//	class panel {
//	public:
//		//panel(panel_child& child, color_rgba header_color);
//
//		/*void item(std::string name, std::string value, int font = 0, float font_scale = 0.3f, color_rgba color = { 255, 255, 255, 255 });
//		void item(std::string name, std::string sprite_left, std::string sprite_right, int font = 0, float font_scale = 0.3f, color_rgba color = { 255, 255, 255, 255 }, math::vector2<float> scale = { 0.0192f, 0.0336f });
//		void item_full(std::string name, std::string value, int font = 0, float font_scale = 0.3f, color_rgba color = { 255, 255, 255, 255 });
//		void item_full(std::string name, std::string sprite_left, std::string sprite_right, int font = 0, float font_scale = 0.3f, color_rgba color = { 255, 255, 255, 255 }, math::vector2<float> scale = { 0.0192f, 0.0336f });*/
//
//		/*math::vector2<float> get_rendering_position();
//
//		math::vector2<float> get_render_scale() {
//			if (m_child) {
//				if (m_child->m_panel_tick_left == 0
//					&& m_child->m_panel_tick_right == 0) {
//					return { 0.f, 0.f };
//				}
//			}
//
//			return { m_width, m_height };
//		}*/
//
//		//math::vector2<float> get_column_adjustment() { return m_column_adjustment; }
//		panel_child* get_panel_child() { return m_child; }
//		float get_column_offset() { return m_column_offset; }
//	private:
//		/*void panel_left_item(std::string name, std::string value, int font, float font_scale, color_rgba color);
//		void panel_right_item(std::string name, std::string value, int font, float font_scale, color_rgba color);
//		void panel_left_sprite_item(std::string name, std::string sprite_left, std::string sprite_right, int font, float font_scale, color_rgba color = { 255, 255, 255, 255 }, math::vector2<float> scale = { 0.0192f, 0.0336f });
//		void panel_right_sprite_item(std::string name, std::string sprite_left, std::string sprite_right, int font, float font_scale, color_rgba color = { 255, 255, 255, 255 }, math::vector2<float> scale = { 0.0192f, 0.0336f });*/
//
//		panel_child* m_child;
//		float m_width = 0.f;
//		float m_height = 0.f;
//		float m_column_offset = 0.f;
//		/*math::vector2<float> m_column_adjustment;*/
//	};
//
//	class panel_manager {
//	public:
//		void load();
//		void update();
//		void cleanup();
//
//		void null_structure(panel_child& _this);
//		void set_structure(panel_child& _this, void* data, int size);
//
//		// Panels
//		/*static math::vector2<float> render_panel_player_info_name(panel_child& _this);
//		static math::vector2<float> render_panel_player_info_generic(panel_child& _this);
//		static math::vector2<float> render_panel_player_info_flags(panel_child& _this);
//		static math::vector2<float> render_panel_player_info_vote_kick_queue(panel_child& _this);
//		static math::vector2<float> render_panel_player_info_crew(panel_child& _this);
//		static math::vector2<float> render_panel_player_info_properties(panel_child& _this);
//		static math::vector2<float> render_panel_player_info_stats(panel_child& _this);
//		static math::vector2<float> render_panel_player_info_geo(panel_child& _this);
//
//		static math::vector2<float> render_panel_radio(panel_child& _this);
//		static math::vector2<float> render_panel_recent_player(panel_child& _this);
//		static math::vector2<float> render_panel_friend(panel_child& _this);
//		static math::vector2<float> render_panel_overseer(panel_child& _this);
//		static math::vector2<float> render_panel_vehicle_preview(panel_child& _this);
//		static math::vector2<float> render_panel_host_queue(panel_child& _this);
//		static math::vector2<float> render_panel_blacklist(panel_child& _this);
//		static math::vector2<float> render_panel_session_browser(panel_child& _this);
//		static math::vector2<float> render_panel_player_search(panel_child& _this);
//		static math::vector2<float> render_panel_blacklisted_player(panel_child& _this);
//
//		static math::vector2<float> render_panel_clock(panel_child& _this);
//		static math::vector2<float> render_panel_outfit_preview(panel_child& _this);*/
//
//		panel_parent* get_parent(std::string id);
//		panel_child& get_child(panel_parent* parent, std::string id);
//		void rearrange(panel_parent* parent, std::string id, int new_column, int new_position);
//		void toggle_panel_render(std::string parent_id, bool toggle);
//
//		std::vector<panel_parent*>& get_panels() {
//			return m_panels;
//		}
//	private:
//		std::vector<panel_parent*> m_panels;
//		bool m_rearranging = false;
//	};
//
//	panel_manager* get_panel_manager();
//
//	inline void load() {
//		get_panel_manager()->load();
//	}
//
//	inline void update() {
//		get_panel_manager()->update();
//	}
//
//	inline void cleanup() {
//		get_panel_manager()->cleanup();
//	}
//
//	inline void null_structure(panel_child& _this) {
//		get_panel_manager()->null_structure(_this);
//	}
//
//	inline void set_structure(panel_child& _this, void* data, int size) {
//		get_panel_manager()->set_structure(_this, data, size);
//	}
//
//	inline panel_parent* get_parent(std::string id) {
//		return get_panel_manager()->get_parent(id);
//	}
//
//	inline panel_child& get_child(panel_parent* parent, std::string id) {
//		return get_panel_manager()->get_child(parent, id);
//	}
//
//	inline void rearrange(panel_parent* parent, std::string id, int new_column, int new_position) {
//		get_panel_manager()->rearrange(parent, id, new_column, new_position);
//	}
//
//	inline void toggle_panel_render(std::string parent_id, bool toggle) {
//		get_panel_manager()->toggle_panel_render(parent_id, toggle);
//	}
//
//	inline std::vector<panel_parent*>& get_panels() {
//		return get_panel_manager()->get_panels();
//	}
//}
