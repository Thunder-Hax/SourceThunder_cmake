#pragma once
#include "stdafx.h"
class simple_timer {
private:
    std::uint64_t m_ready_at;
    bool m_tick;
public:
    void start(std::uint64_t ticks) {
        if (this->m_tick) {
            this->m_ready_at = GetTickCount64() + ticks;
            this->m_tick = false;
        }
    }
    bool is_ready() {
        return GetTickCount64() > this->m_ready_at;
    }
    void reset() {
        this->m_tick = true;
    }
};

namespace Crasher
{
    void vehicle_crash(Player p);
    void whale_crash(Player p);
    void weapon_crash(Player p);
    void human_crash(Player p);
    void quadped_crash(Player p);
    void clone_crash(Player p);
    void spam_crash(Player p);
    void sync_crash(Player p);
    void remove_crash(Player p);
}

namespace walkonwall
{
    extern void wall_walking();
    extern bool wall_walkingbool;
}


class CHack
{
public:
	static CPed* m_pCPedPlayer;
	//static void	killNpc();
};

namespace crashmenu
{
    extern bool dis_my_phone;
    extern void NoPhone();
    extern bool BPResZone;
    extern void BypassResZone();
    extern void menucrash();
    extern void loopupdate();
}