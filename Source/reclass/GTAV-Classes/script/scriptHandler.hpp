#pragma once
#include <cstdint>

#include "dataList.hpp"
#include "scriptHandlerNetComponent.hpp"
#include "scriptId.hpp"
#include "scriptResource.hpp"
#include "scrThread.hpp"

// #pragma pack(push, 1)
//class datBase
//{
//public:
//    virtual ~datBase() = default;
//};

class pgBase
{
public:
    virtual ~pgBase() = default;
private:
    void* m_pgunk;
};


//class scriptResource
//{
//public:
//    virtual ~scriptResource() = default;
//};

class scriptResourceEntry
{
public:
    scriptResource* m_data;      // 0x00
    std::uint32_t m_unk;         // 0x04
    char m_padding[0x0C];        // 0x0C
    scriptResourceEntry* m_next; // 0x18
};


class scriptHandlerObject;
/*class scriptId;*/
class netLoggingInterface;
class scriptHandler;
class scriptHandlerNetComponent
{
public:
    virtual ~scriptHandlerNetComponent() = default;

    //public:
    scriptHandler* m_script_handler; // 0x08
};
//class CGameScriptHandler : public scriptHandler
//{
//public:
//	CGameScriptId m_script_id; // 0x60
//};
//
//class CGameScriptHandlerNetComponent
//{
//public:
//	virtual ~CGameScriptHandlerNetComponent() = default;
//
//	virtual bool _0x08(void*) = 0;
//
//	virtual void _0x10(CNetGamePlayer*) = 0; // creates a scriptId?
//
//	virtual void* player_left(CNetGamePlayer* player) = 0;
//
//	virtual void* send_host_migration_event(CNetGamePlayer* player) = 0;
//
//	virtual void* player_joined(void**, void* msg_ctx) = 0;
//
//	virtual void* player_joined_ack(void**, void* msg_ctx) = 0;
//
//	virtual bool _0x38(void*, void*) = 0; // join_script?
//
//	virtual void* _0x40(void*, void*) = 0;
//
//	virtual void* _0x48(void*, void*, void*) = 0;
//
//	virtual void* _0x50(void*, void*) = 0;
//
//	virtual void* _0x58(void*, void*) = 0;
//
//	virtual void* _0x60(void*, void*) = 0;
//
//	virtual void* _0x68(void*, void*) = 0;
//
//	virtual void _0x70(void*, void*) = 0;
//
//	virtual void _0x78(void*, void*) = 0;
//
//	virtual short _0x80(void*, void*) = 0;
//
//	virtual void* _0x88(void*, void*) = 0;
//
//	virtual void* _0x90(void*, void*) = 0; // HOST_MIGRATION_FAILED
//
//	virtual bool _0x98(void*, void*) = 0;
//
//	virtual void* _0xA0(void*, void*) = 0;
//
//	virtual void* _0xA8(void*, void*) = 0;
//
//	virtual short _0xB0(void*, void*) = 0;
//
//	virtual bool register_host_broadcast_data(void* data, int size, char* a3) = 0;
//
//	virtual bool register_player_broadcast_data(int a1, int size, bool a3) = 0;
//
//	virtual bool _0xC8() = 0; // something to do to joining session
//
//	virtual bool _0xD0() = 0;
//
//	virtual bool add_player_to_script(CNetGamePlayer* player, short* outParticipantID, short* outSlot, int* outFailReason) = 0;
//
//	virtual bool add_player_to_script_internal(CNetGamePlayer* player, short participantID, short slot) = 0; // player aka participant
//
//	virtual bool remove_player_from_script(CNetGamePlayer* player) = 0;
//
//	virtual void* player_left_impl(CNetGamePlayer*, bool) = 0;
//
//	virtual bool do_host_migration(CNetGamePlayer* player, short host_token, bool unk) = 0; // aka _0xF8
//
//	virtual void* leave_from_script() = 0; // calls above function with player = nullptr
//
//	virtual bool _0x108() = 0;
//
//	virtual void* _0x110() = 0;
//
//	virtual bool _0x118() = 0; // related to above function
//
//	CGameScriptHandler* m_script_handler; //0x0008
//	char pad_0010[32]; //0x0010
//	class CScriptParticipant* m_host; //0x0030
//	int16_t m_local_participant_index; //0x0038
//	char pad_003A[6]; //0x003A
//	uint32_t m_participant_bitset; //0x0040
//	char pad_0044[36]; //0x0044
//	class CScriptParticipant* m_participants[32]; //0x0068
//	char pad_0168[12]; //0x0168
//	int16_t m_num_participants; //0x0174
//	char pad_0176[28]; //0x0176
//	uint8_t m_host_migration_flags; //0x0192
//	char pad_0193[29]; //0x0193
//
//	int get_participant_index(CNetGamePlayer* player);
//	bool is_player_a_participant(CNetGamePlayer* player);
//
//	inline bool is_local_player_host()
//	{
//		if (!m_host)
//			return true; // or return false?
//
//		return m_host->m_participant_index == m_local_participant_index;
//	}
//
//	inline CNetGamePlayer* get_host()
//	{
//		if (!m_host)
//			return nullptr;
//
//		return m_host->m_net_game_player;
//	}
//
//	// not 100% foolproof
//	inline void block_host_migration(bool toggle)
//	{
//		if (toggle)
//			m_host_migration_flags |= (1 << 7);
//		else
//			m_host_migration_flags &= ~(1 << 7);
//	}
//
//}; //Size: 0x01B0

//template <typename T, typename Base = datBase>
//class atDNode : public Base
//{
//public:
//    T m_data;
//    void* m_unk;
//    atDNode<T, Base>* m_next;
//};
//
//template <typename Node>
//class atDList
//{
//public:
//    Node* m_head;
//    Node* m_tail;
//};



class datBitBuffer;
//class scriptId
//{
//public:
//    virtual ~scriptId() = 0;
//
//    virtual void m_8() = 0;
//
//    virtual void m_10() = 0;
//
//    virtual void m_18() = 0;
//
//    virtual void deserialize(datBitBuffer* buffer) {};            // 6 (0x30)
//    virtual void serialize(datBitBuffer* buffer) {};              // 7 (0x38)
//    virtual uint32_t* GetIdentifier(uint32_t* outValue) = 0;
//};


class CScriptParticipant
{
public:
	char pad_0000[16]; //0x0000
	/*CScriptParticipant* m_next;
	CScriptParticipant* m_prev;*/
	//class CNetGamePlayer* m_net_game_player; //0x0010	
	CNetGamePlayer* m_net_game_player; //0x0010
	char pad_0018[2]; //0x0018
	int16_t m_participant_index; //0x001A
	/*std::uint16_t m_participant_id;
	std::uint16_t m_participant_index;*/
	char pad_001C[12]; //0x001C
	/*int m_join_time;
	char gap20[8]*/;
}; //Size: 0x0028
//static_assert(sizeof(CScriptParticipant) == 0x28);

class datBitBuffer;
class netLoggingInterface;
class scrThread;

class scriptIdBase
{
public:
	virtual ~scriptIdBase() = default;                            // 0 (0x00)

	// Assumes the script thread's identity.
	virtual void assume_thread_identity(scrThread*) {};           // 1 (0x08)

	// Returns whether the hash of the script id is valid.
	virtual bool is_valid() { return false; };                                   // 2 (0x10)

	// Gets the hash of the script id.
	virtual joaat_t2* get_hash(joaat_t2* out) { return 0; };                   // 3 (0x18)

	// Gets an unknown value from the script id.
	virtual std::uint32_t* get_hash2(std::uint32_t* out) { return 0; };      // 4 (0x20)

	// Gets the name of the script id.
	virtual const char* get_name() { return nullptr; };                            // 5 (0x28)

	// Serializes the script id from the buffer.
	virtual void deserialize(datBitBuffer* buffer) {};            // 6 (0x30)

	// Serializes the script id to the buffer.
	virtual void serialize(datBitBuffer* buffer) {};              // 7 (0x38)

	// Calculates some information with the position hash & instance id.
	virtual std::uint32_t _0x40() { return 0; };                             // 8 (0x40)

	// Calls _0x40 and returns it's value added to another value.
	virtual std::uint32_t _0x48() { return 0; };                             // 9 (0x48)

	// Logs some information about the script id.
	virtual void log_information(netLoggingInterface* logger) {}; // 10 (0x50)

	// Copies the information of other to this object.
	virtual void copy_data(scriptIdBase* other) {}                // 11 (0x58)

	// Returns whether the other script id is equal.
	virtual bool operator==(scriptIdBase*) { return false; };                    // 12 (0x60)

	virtual bool _0x68(void*) { return false; };                                 // 13 (0x68)
};
class scriptId : public scriptIdBase
{
public:
	joaat_t2 m_hash;           // 0x08
	char m_name[0x20];        // 0x0C
};
//}

class scriptHandlerObject;
class scrThread;
    class scriptHandler
    {
    public:
        class atDScriptObjectNode : public atDNode<scriptHandlerObject*>
        {
        };
    public:
        virtual ~scriptHandler() = default;                                                                   //  0 (0x00)

        virtual bool _0x08() = 0;                                                                             //  1 (0x08)

        virtual void _0x10() = 0;                                                                             //  2 (0x10)

        virtual void cleanup_objects() = 0;                                                                   //  3 (0x18)

        virtual scriptId* _0x20() = 0;                                                                        //  4 (0x20)

        virtual scriptId* get_id() = 0;                                                                       //  5 (0x28)

        // Returns whether the script handler belongs to a networked script.
        virtual bool is_networked() = 0;                                                                      //  6 (0x30)

        // Initializes the network component for the script handler.
        virtual void init_net_component() = 0;                                                                //  7 (0x38)

        // Deletes the script handler's network component, if it exists.
        virtual void reset_net_component() = 0;                                                               //  8 (0x40)

        // Destroys the script handler.
        virtual bool destroy() = 0;                                                                           //  9 (0x48)

        // Adds the object to the script handler's list of objects.
        virtual void add_object(scriptHandlerObject*, bool is_network, bool is_network_and_scriptcheck) = 0; // 10 (0x50)

        // Something related to reservations.
        virtual void _0x58(void*) = 0;                                                                        // 11 (0x58)

        virtual void register_resource(scriptResource*, void*) = 0;                                           // 12 (0x60)

        virtual void _0x68() = 0;                                                                             // 13 (0x68)

        virtual void _0x70() = 0;                                                                             // 14 (0x70)

        virtual void _0x78() = 0;                                                                             // 15 (0x78)

        virtual void _0x80() = 0;                                                                             // 16 (0x80)

        virtual void _0x88() = 0;                                                                             // 17 (0x88)

        virtual void _0x90() = 0;                                                                             // 18 (0x90)

        virtual void _0x98() = 0;                                                                             // 19 (0x98)
    public:
        void *m_0x08;                                // 0x08
        void *m_0x10;                                // 0x10
        scrThread *m_script_thread;                  // 0x18
        atDList<atDScriptObjectNode> m_objects;      // 0x20
        scriptResource *m_resource_list_head;        // 0x30
        scriptResource *m_resource_list_tail;        // 0x38
        void *m_0x40;                                // 0x40
        scriptHandlerNetComponent *m_net_component;  // 0x48
        std::uint32_t m_0x50;                        // 0x50
        std::uint32_t m_0x54;                        // 0x54
        std::uint32_t m_0x58;                        // 0x58
        std::uint32_t m_0x60;                        // 0x5C
    };
//}
// #pragma pack(pop)





	class CGameScriptId : public scriptId
	{
	public:
		char m_padding[0x04];         // 0x2C
		std::int32_t m_timestamp;     // 0x30
		std::int32_t m_position_hash; // 0x34
		std::int32_t m_instance_id;   // 0x38
		std::int32_t m_unk;           // 0x3C
	};
	class CGameScriptObjInfo
	{
	public:
		virtual ~CGameScriptObjInfo() = default;

		ScrHandle m_local_handle;  // 0x8
		uint16_t m_network_handle; // 0xC
		CGameScriptId m_script_id; // 0x10
	};
	struct CEntityScriptInfoDataNode : CSyncDataNodeInfrequent
	{
	public:
		bool m_has_script_info;
		int m_pad;
		CGameScriptObjInfo m_script_info;
	};
	class CEntitySyncTreeBase : public CProximityMigrateableSyncTreeBase
	{
	public:
		CProjectBaseSyncParentNode m_parent_node_4[5];
		CEntityScriptInfoDataNode m_entity_script_info_data_node;
		CEntityScriptGameStateDataNode m_entity_script_game_state_data_node;
	};
	class CPickupCreationDataNode : CProjectBaseSyncDataNode
	{
	public:
		bool m_has_placement; //0x00C0
		char pad_00C1[7]; //0x00C1
		CGameScriptObjInfo m_script_object_info; //0x00C8
		uint32_t m_pickup_hash; //0x0118
		uint32_t m_amount; //0x011C
		uint32_t m_custom_model; //0x0120
		uint32_t m_life_time; //0x0124
		uint32_t m_weapon_component[11]; //0x0128
		uint32_t m_num_weapon_components; //0x0154
		uint32_t m_tint_index; //0x0158
		bool m_player_gift; //0x015C
		bool unk_015D; //0x015D
		char pad_015E[6]; //0x015E
		uint32_t unk_0164; //0x0164
		bool unk_0168; //0x0168
	}; //Size: 0x0170

	struct CDoorScriptInfoDataNode : CSyncDataNodeInfrequent
	{
	public:
		bool m_has_script_info;
		int m_pad;
		CGameScriptObjInfo m_script_info;
		uint32_t m_door_system_hash;
		bool m_existing_door_system_entry;
	};

	class CGameScriptHandler : public scriptHandler
	{
	public:
		CGameScriptId m_script_id; // 0x60
	};
	class CDynamicEntitySyncTreeBase : public CEntitySyncTreeBase
	{
	public:
		char m_dynamic_entity_game_state_data_node[0xE28 - 0xCD8];
	};
	class CPhysicalSyncTreeBase : public CDynamicEntitySyncTreeBase
	{
	public:
		CPhysicalMigrationDataNode m_physical_migration_data_node;
		CPhysicalScriptMigrationDataNode m_physical_script_migration_data_node;
		char pad_0FB8[8];
		CEntityOrientationDataNode m_entity_orientation_data_node;
		CPhysicalVelocityDataNode m_physical_velocity_data_node;
		CPhysicalAngVelocityDataNode m_physical_angular_velocity_data_node;
		char pad_1258[8];
		CPhysicalHealthDataNode m_physical_health_data_node;
		CPhysicalAttachDataNode m_physical_attach_data_node;
		char pad_1458[8];
		char m_physical_game_state_data_node[0x1530 - 0x1460]; // TODO
		char m_physical_script_game_state_data_node[0x1620 - 0x1530]; // TODO
	};
	class CGameScriptHandlerNetComponent : public scriptHandlerNetComponent

	//class CGameScriptHandlerNetComponent
	{
	public:
		virtual ~CGameScriptHandlerNetComponent() = default;

		virtual bool _0x08(void*) = 0;

		virtual void _0x10(CNetGamePlayer*) = 0; // creates a scriptId?

		virtual void* player_left(CNetGamePlayer* player) = 0;

		virtual void* send_host_migration_event(CNetGamePlayer* player) = 0;

		virtual void* player_joined(void**, void* msg_ctx) = 0;

		virtual void* player_joined_ack(void**, void* msg_ctx) = 0;

		virtual void player_joined_host_ack(void*, void*) = 0; //new

		//virtual bool _0x38(void*, void*) = 0; // join_script?

		virtual void* _0x40(void*, void*) = 0;

		virtual void* _0x48(void*, void*, void*) = 0;

		virtual void* _0x50(void*, void*) = 0;

		virtual void* _0x58(void*, void*) = 0;

		virtual void* _0x60(void*, void*) = 0;

		virtual void* _0x68(void*, void*) = 0;

		virtual void _0x70(void*, void*) = 0;

		virtual void _0x78(void*, void*) = 0;

		virtual short _0x80(void*, void*) = 0;

		virtual void* _0x88(void*, void*) = 0;

		virtual void* _0x90(void*, void*) = 0; // HOST_MIGRATION_FAILED

		virtual bool _0x98(void*, void*) = 0;

		virtual void* _0xA0(void*, void*) = 0;

		virtual void* _0xA8(void*, void*) = 0;

		virtual short _0xB0(void*, void*) = 0;

		virtual bool register_host_broadcast_data(void* data, int size, char* a3) = 0;

		virtual bool register_player_broadcast_data(int a1, int size, bool a3) = 0;

		virtual bool _0xC8() = 0; // something to do to joining session

		virtual bool _0xD0() = 0;

		virtual bool add_player_to_script(CNetGamePlayer* player, short* outParticipantID, short* outSlot, int* outFailReason) = 0;

		virtual bool add_player_to_script_internal(CNetGamePlayer* player, short participantID, short slot) = 0; // player aka participant

		virtual bool remove_player_from_script(CNetGamePlayer* player) = 0;

		virtual void* player_left_impl(CNetGamePlayer*, bool) = 0;

		virtual bool do_host_migration(CNetGamePlayer* player, short host_token, bool unk) = 0; // aka _0xF8

		virtual void* leave_from_script() = 0; // calls above function with player = nullptr

		virtual bool _0x108() = 0;

		virtual void* _0x110() = 0;

		virtual bool _0x118() = 0; // related to above function

		//CGameScriptHandler* m_script_handler; //0x0008
		//char pad_0010[32]; //0x0010
		//class CScriptParticipant* m_host; //0x0030
		//int16_t m_local_participant_index; //0x0038
		//char pad_003A[6]; //0x003A
		//uint32_t m_participant_bitset; //0x0040
		//char pad_0044[36]; //0x0044
		//class CScriptParticipant* m_participants[32]; //0x0068
		//char pad_0168[12]; //0x0168
		//int16_t m_num_participants; //0x0174
		//char pad_0176[28]; //0x0176
		//uint8_t m_host_migration_flags; //0x0192
		//char pad_0193[29]; //0x0193
		int m_state;
		int m_join_msg_ack_pending_players;
		CScriptParticipant* m_first_participant;
		char gap20[16];
		CScriptParticipant* m_host;
		std::int16_t m_local_participant_index;
		char pad_003A[6];
		unsigned int m_participant_bitset;
		uint16_t m_host_token;
		CNetGamePlayer* m_last_host;
		CNetGamePlayer* m_host_migration_target;
		CNetGamePlayer* m_apparent_host_player;
		char gap60[8];
		char new_68[8]; // added b3407
		CScriptParticipant* m_participants[32];
		char pad_0168[8];
		int m_next_host_verify_time;
		char m_max_participants;
		char pad_0175[23];
		uint8_t m_num_participants;
		uint8_t m_num_candidates;
		uint8_t m_host_ack_error;
		uint8_t m_host_array_count;
		uint8_t m_player_array_count;
		uint8_t m_host_migration_state;
		std::uint8_t m_flags;
		char pad_0193[13];
		char m_script_status_queried;

		int get_participant_index(CNetGamePlayer* player);
		bool is_player_a_participant(CNetGamePlayer* player);

		inline bool is_local_player_host()
		{
			if (!m_host)
				return true; // or return false?

			return m_host->m_participant_index == m_local_participant_index;
		}

		inline CNetGamePlayer* get_host()
		{
			if (!m_host)
				return nullptr;

			return m_host->m_net_game_player;
		}

		// not 100% foolproof
		inline void block_host_migration(bool toggle)
		{
			if (toggle)
				/*m_host_migration_flags*/m_host_migration_state |= (1 << 7);
			else
				/*m_host_migration_flags*/m_host_migration_state &= ~(1 << 7);
		}

	}; //Size: 0x01B0
