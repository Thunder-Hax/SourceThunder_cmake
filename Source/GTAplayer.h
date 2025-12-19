#pragma once
class GTAplayer
{
private:
	INT8 index;
public:
	GTAplayer();
	GTAplayer(const GTAplayer& obj);
	GTAplayer(INT8 handle);
	bool IsFreeAiming() const; /// return whether free aiming
	bool IsTargetingAnything() const; /// return whether targetting anything
	void SetControl(bool toggle, int flag); /// set control flags
	GTAentity AimedEntity() const; /// returns entity handle for the entity 
};