#pragma once

// #pragma pack(push, 1)
//namespace rage
//{
#include "scriptHandler.hpp"
#include "scriptId.hpp"

//class scriptHandler;
//class CScriptParticipant
//{
//public:
//	char pad_0000[16]; //0x0000
//	class CNetGamePlayer* m_net_game_player; //0x0010
//	char pad_0018[2]; //0x0018
//	int16_t m_participant_index; //0x001A
//	char pad_001C[12]; //0x001C
//}; //Size: 0x0028
//static_assert(sizeof(CScriptParticipant) == 0x28);

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


    //class scriptHandlerNetComponent
    //{
    //public:
    //    virtual ~scriptHandlerNetComponent() = default;

    //public:
    //    scriptHandler *m_script_handler; // 0x08
    //};
//}
// #pragma pack(pop)
