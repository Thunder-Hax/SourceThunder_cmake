#include "stdafx.h"
#include "Tasks.h"

#include "macros.h"

#include "enums.h"
#include "natives.h"

//#include <stdarg.h>

Tasks::Tasks(GTAentity ped)
	: _ped(ped)
{
}
Tasks::Tasks(int pedHandle)
	: _ped(pedHandle)
{
}
Tasks::Tasks(const Tasks& obj)
	: _ped(obj._ped)
{
}

Tasks& Tasks::operator = (const Tasks& right)
{
	this->_ped = right._ped;
	return *this;
}

//void Tasks::AimAt(GTAentity target, int duration)
//{
//	TASK_AIM_GUN_AT_ENTITY(_ped.Handle(), target.Handle(), duration, false);
//}
//void Tasks::AimAt(const Vector3& target, int duration)
//{
//	TASK_AIM_GUN_AT_COORD(_ped.Handle(), target.x, target.y, target.z, duration, false, false);
//}
//void Tasks::Arrest(GTAentity ped)
//{
//	TASK_ARREST_PED(_ped.Handle(), ped.Handle());
//}
//void Tasks::ChatTo(GTAentity ped)
//{
//	TASK_CHAT_TO_PED(_ped.Handle(), ped.Handle(), 16, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
//}
//void Tasks::Climb()
//{
//	TASK_CLIMB(_ped.Handle(), true);
//}
//void Tasks::Cower(int duration)
//{
//	TASK_COWER(_ped.Handle(), duration);
//}
//void Tasks::CruiseWithVehicle(GTAentity vehicle, float speed)
//{
//	this->CruiseWithVehicle(vehicle, speed, 0);
//}
//void Tasks::CruiseWithVehicle(GTAentity vehicle, float speed, int drivingstyle)
//{
//	TASK_VEHICLE_DRIVE_WANDER(_ped.Handle(), vehicle.Handle(), speed, drivingstyle);
//}
//void Tasks::DriveTo(GTAentity vehicle, Vector3 position, float radius, float speed)
//{
//	this->DriveTo(vehicle, position, radius, speed, 0);
//}
//void Tasks::DriveTo(GTAentity vehicle, Vector3 position, float radius, float speed, int drivingstyle)
//{
//	TASK_VEHICLE_DRIVE_TO_COORD_LONGRANGE(_ped.Handle(), vehicle.Handle(), position.x, position.y, position.z, speed, drivingstyle, radius);
//}
//void Tasks::EnterVehicle(GTAentity vehicle, VehicleSeat seat, int timeout, float speed, int flag)
//{
//	TASK_ENTER_VEHICLE(_ped.Handle(), vehicle.Handle(), timeout, (seat), speed, flag, 0);
//}
//void Tasks::EveryoneLeaveVehicle(GTAentity vehicle)
//{
//	TASK_EVERYONE_LEAVE_VEHICLE(vehicle.Handle());
//}
//void Tasks::FightAgainst(GTAentity target)
//{
//	TASK_COMBAT_PED(_ped.Handle(), target.Handle(), 0, 16);
//}
//void Tasks::FightAgainst(GTAentity target, int duration)
//{
//	TASK_COMBAT_PED_TIMED(_ped.Handle(), target.Handle(), duration, 0);
//}
//void Tasks::FightAgainstHatedTargets(float radius)
//{
//	TASK_COMBAT_HATED_TARGETS_AROUND_PED(_ped.Handle(), radius, 0);
//}
//void Tasks::FightAgainstHatedTargets(float radius, int duration)
//{
//	TASK_COMBAT_HATED_TARGETS_AROUND_PED_TIMED(_ped.Handle(), radius, duration, 0);
//}
//void Tasks::ThrowProjectile(const Vector3& targetPos)
//{
//	TASK_THROW_PROJECTILE(_ped.Handle(), targetPos.x, targetPos.y, targetPos.z);
//}
//void Tasks::FleeFrom(GTAentity ped)
//{
//	this->FleeFrom(ped, -1);
//}
//void Tasks::FleeFrom(GTAentity ped, int duration)
//{
//	TASK_SMART_FLEE_PED(_ped.Handle(), ped.Handle(), 100.0f, duration, false, false);
//}
//void Tasks::FleeFrom(const Vector3& position)
//{
//	this->FleeFrom(position, -1);
//}
//void Tasks::FleeFrom(const Vector3& position, int duration)
//{
//	TASK_SMART_FLEE_COORD(_ped.Handle(), position.x, position.y, position.z, 1000.0f, duration, false, false);
//}
//template<typename... Args> void Tasks::FollowPointRoute(float speed, Args... p)
//{
//	struct Pass
//	{
//		template<typename ...T> Pass(T...) {}
//	};
//
//	TASK_FLUSH_ROUTE();
//
//	std::deque<Vector3> points;
//	Pass
//	{
//		(
//			[&]()
//	{
//		points.push_front(static_cast<Vector3>(p));
//	}
//			(), 1
//		)...
//	};
//
//	for (auto& point : points)
//	{
//		TASK_EXTEND_ROUTE(point.x, point.y, point.z);
//	}
//
//	TASK_FOLLOW_POINT_ROUTE(_ped.Handle(), speed, 0);
//}
//void Tasks::FollowPointRoute(std::vector<Vector3>& points, float speed)
//{
//	TASK_FLUSH_ROUTE();
//
//	for (auto& point : points)
//	{
//		TASK_EXTEND_ROUTE(point.x, point.y, point.z);
//	}
//
//	TASK_FOLLOW_POINT_ROUTE(_ped.Handle(), speed, 0);
//}
//void Tasks::FollowPointRoute(std::initializer_list<Vector3>& points, float speed)
//{
//	TASK_FLUSH_ROUTE();
//
//	for (auto& point : points)
//	{
//		TASK_EXTEND_ROUTE(point.x, point.y, point.z);
//	}
//
//	TASK_FOLLOW_POINT_ROUTE(_ped.Handle(), speed, 0);
//}
//void Tasks::GoTo(GTAentity target)
//{
//	this->GoTo(target, Vector3(), -1);
//}
//void Tasks::GoTo(GTAentity target, const Vector3& offset)
//{
//	this->GoTo(target, offset, -1);
//}
//void Tasks::GoTo(GTAentity target, const Vector3& offset, int timeout)
//{
//	TASK_GOTO_ENTITY_OFFSET_XY(_ped.Handle(), target.Handle(), timeout, offset.x, offset.y, offset.z, 1.0f, true);
//}
//void Tasks::GoTo(const Vector3& position, bool ignorePaths, int timeout)
//{
//	if (ignorePaths)
//	{
//		TASK_GO_STRAIGHT_TO_COORD(_ped.Handle(), position.x, position.y, position.z, 1.0f, timeout, 0.0f /* heading */, 0.0f);
//	}
//	else
//	{
//		TASK_FOLLOW_NAV_MESH_TO_COORD(_ped.Handle(), position.x, position.y, position.z, 1.0f, timeout, 0.0f, 0, 0.0f);
//	}
//}
//void Tasks::GuardCurrentPosition()
//{
//	TASK_GUARD_CURRENT_POSITION(_ped.Handle(), 15.0f, 10.0f, true);
//}
//void Tasks::HandsUp(int duration)
//{
//	TASK_HANDS_UP(_ped.Handle(), duration, 0, -1, false);
//}
//void Tasks::Jump()
//{
//	TASK_JUMP(_ped.Handle(), true);
//}
//void Tasks::LeaveVehicle()
//{
//	TASK_LEAVE_ANY_VEHICLE(_ped.Handle(), 0, 0 /* flags */);
//}
//void Tasks::LeaveVehicle(GTAentity vehicle, bool closeDoor)
//{
//	TASK_LEAVE_VEHICLE(_ped.Handle(), vehicle.Handle(), closeDoor ? 0 : 1 << 8);
//}
//void Tasks::LookAt(GTAentity target, int duration)
//{
//	TASK_LOOK_AT_ENTITY(_ped.Handle(), target.Handle(), duration, 0 /* flags */, 2);
//}
//void Tasks::LookAt(const Vector3& position, int duration)
//{
//	TASK_LOOK_AT_COORD(_ped.Handle(), position.x, position.y, position.z, duration, 0 /* flags */, 2);
//}
//void Tasks::ParachuteTo(const Vector3& position)
//{
//	TASK_PARACHUTE_TO_TARGET(_ped.Handle(), position.x, position.y, position.z);
//}
//void Tasks::ParkVehicle(GTAentity vehicle, const Vector3& position, float heading)
//{
//	TASK_VEHICLE_PARK(_ped.Handle(), vehicle.Handle(), position.x, position.y, position.z, heading, 1, 0.0f, false);
//}
//void Tasks::PerformSequence(TaskSequence& sequence)
//{
//	if (!sequence.IsClosed())
//	{
//		sequence.Close();
//	}
//
//	//ClearAll();
//
//	//SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(_ped.Handle(), true);
//
//	TASK_PERFORM_SEQUENCE(_ped.Handle(), sequence.Handle());
//}
//bool Tasks::IsPlayingAnimation(const std::string& animDict, const std::string& animName)
//{
//	return IS_ENTITY_PLAYING_ANIM(_ped.Handle(), const_cast<PCHAR>(animDict.c_str()), const_cast<PCHAR>(animName.c_str()), 3) != 0;
//}
void Tasks::PlayAnimation(const std::string& animDict, const std::string& animName)
{
	this->PlayAnimation(animDict, animName, 4.0f, -4.0f, -1, AnimFlag::Loop, 0, false);
}
void Tasks::PlayAnimation(const std::string& animDict, const std::string& animName, float speed, float speedMultiplier, int duration, int flag, float playbackRate, bool lockPos)
{
	PCHAR animDict1 = const_cast<PCHAR>(animDict.c_str());
	PCHAR animName1 = const_cast<PCHAR>(animName.c_str());

	STREAMING::REQUEST_ANIM_DICT(animDict1);
	for (DWORD timeOut = GetTickCount() + 1650; GetTickCount() < timeOut;)
	{
		if (STREAMING::HAS_ANIM_DICT_LOADED(animDict1)) break;
		WAIT(0);
	}

	AI::TASK_PLAY_ANIM(_ped.Handle(), animDict1, animName1, speed, speedMultiplier, duration, flag, playbackRate, lockPos, lockPos, lockPos);
}
//void Tasks::PutAwayMobilePhone()
//{
//	TASK_USE_MOBILE_PHONE(_ped.Handle(), 0);
//}
//void Tasks::PutAwayParachute()
//{
//	TASK_PARACHUTE(_ped.Handle(), false);
//}
//void Tasks::ReactAndFlee(GTAentity pedToFleeFrom)
//{
//	TASK_REACT_AND_FLEE_PED(_ped.Handle(), pedToFleeFrom.Handle());
//}
//void Tasks::ReloadWeapon()
//{
//	TASK_RELOAD_WEAPON(_ped.Handle(), true);
//}
//void Tasks::RunTo(const Vector3& position, bool ignorePaths, int timeout)
//{
//	if (ignorePaths)
//	{
//		TASK_GO_STRAIGHT_TO_COORD(_ped.Handle(), position.x, position.y, position.z, 4.0f, timeout, 0.0f /* heading */, 0.0f);
//	}
//	else
//	{
//		TASK_FOLLOW_NAV_MESH_TO_COORD(_ped.Handle(), position.x, position.y, position.z, 4.0f, timeout, 0.0f, 0, 0.0f);
//	}
//}
//void Tasks::ShootAt(GTAentity target, int duration, int pattern)
//{
//	TASK_SHOOT_AT_ENTITY(_ped.Handle(), target.Handle(), duration, (pattern));
//}
//void Tasks::ShootAt(const Vector3& position, int duration, int pattern)
//{
//	TASK_SHOOT_AT_COORD(_ped.Handle(), position.x, position.y, position.z, duration, (pattern));
//}
//void Tasks::ShuffleToNextVehicleSeat(GTAentity vehicle)
//{
//	TASK_SHUFFLE_TO_NEXT_VEHICLE_SEAT(_ped.Handle(), vehicle.Handle());
//}
//void Tasks::Skydive()
//{
//	TASK_SKY_DIVE(_ped.Handle());
//}
//void Tasks::SlideTo(const Vector3& position, float heading)
//{
//	TASK_PED_SLIDE_TO_COORD(_ped.Handle(), position.x, position.y, position.z, heading, 0.7f);
//}
//void Tasks::StandStill(int duration)
//{
//	TASK_STAND_STILL(_ped.Handle(), duration);
//}
//bool Tasks::IsUsingScenario(const std::string& name)
//{
//	return IS_PED_USING_SCENARIO(_ped.Handle(), const_cast<PCHAR>(name.c_str())) != 0;
//}
void Tasks::StartScenario(const std::string& name, const Vector31& position, float heading)
{
	AI::TASK_START_SCENARIO_AT_POSITION2(_ped.Handle(), const_cast<PCHAR>(name.c_str()), position.x1, position.y1, position.z1, heading, 0, 0, 1);
	if (name.find("MUSICIAN") != std::string::npos)
	{
		//CLEAR_PED_TASKS_IMMEDIATELY(_ped.Handle());
		AI::TASK_START_SCENARIO_AT_POSITION(_ped.Handle(), "WORLD_HUMAN_MUSICIAN", position.x1, position.y1, position.z1, heading, 0, 0, 1);
	}
}
void Tasks::StartScenario(const std::string& name, int unkDelay, bool playEnterAnim)
{
	AI::TASK_START_SCENARIO_IN_PLACE(_ped.Handle(), const_cast<PCHAR>(name.c_str()), unkDelay, playEnterAnim);
	if (name.find("MUSICIAN") != std::string::npos)
	{
		//CLEAR_PED_TASKS_IMMEDIATELY(_ped.Handle());
		AI::TASK_START_SCENARIO_IN_PLACE(_ped.Handle(), "WORLD_HUMAN_MUSICIAN", unkDelay, playEnterAnim);
	}
}
//void Tasks::UseNearestScenario(bool warp)
//{
//	this->UseNearestScenario(_ped.Position_get(), 15.0f, warp);
//}
//void Tasks::UseNearestScenario(float radius, bool warp)
//{
//	this->UseNearestScenario(_ped.Position_get(), radius, warp);
//}
//void Tasks::UseNearestScenario(const Vector3& pos, float radius, bool warp)
//{
//	if (warp)
//		TASK_USE_NEAREST_SCENARIO_TO_COORD_WARP(_ped.Handle(), pos.x, pos.y, pos.z, radius, 0);
//	else
//		TASK_USE_NEAREST_SCENARIO_TO_COORD(_ped.Handle(), pos.x, pos.y, pos.z, radius, 0);
//}
//void Tasks::SwapWeapon()
//{
//	TASK_SWAP_WEAPON(_ped.Handle(), false);
//}
//void Tasks::TurnTo(GTAentity target, int duration)
//{
//	TASK_TURN_PED_TO_FACE_ENTITY(_ped.Handle(), target.Handle(), duration);
//}
//void Tasks::TurnTo(const Vector3& position, int duration)
//{
//	TASK_TURN_PED_TO_FACE_COORD(_ped.Handle(), position.x, position.y, position.z, duration);
//}
//void Tasks::UseMobilePhone()
//{
//	TASK_USE_MOBILE_PHONE(_ped.Handle(), true);
//}
//void Tasks::UseMobilePhone(int duration)
//{
//	TASK_USE_MOBILE_PHONE_TIMED(_ped.Handle(), duration);
//}
//void Tasks::UseParachute()
//{
//	TASK_PARACHUTE(_ped.Handle(), true);
//}
//void Tasks::VehicleChase(GTAentity target)
//{
//	TASK_VEHICLE_CHASE(_ped.Handle(), target.Handle());
//}
//void Tasks::VehicleShootAtPed(GTAentity target)
//{
//	TASK_VEHICLE_SHOOT_AT_PED(_ped.Handle(), target.Handle(), 20.0f);
//}
//void Tasks::Wait(int duration)
//{
//	TASK_PAUSE(_ped.Handle(), duration);
//}
void Tasks::WanderAround()
{
	AI::TASK_WANDER_STANDARD(_ped.Handle(), 0.0f, 0);
}
void Tasks::WanderAround(const Vector3& position, float radius)
{
	AI::TASK_WANDER_IN_AREA(_ped.Handle(), position.x, position.y, position.z, radius, 0.0f, 0.0f);
}
//void Tasks::WarpIntoVehicle(GTAentity vehicle, VehicleSeat seat)
//{
//	TASK_WARP_PED_INTO_VEHICLE(_ped.Handle(), vehicle.Handle(), (seat));
//}
//void Tasks::WarpOutOfVehicle(GTAentity vehicle)
//{
//	TASK_LEAVE_VEHICLE(_ped.Handle(), vehicle.Handle(), 16);
//}
//
//void Tasks::ClearAll()
//{
//	CLEAR_PED_TASKS(_ped.Handle());
//}
void Tasks::ClearAllImmediately()
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(_ped.Handle());
}
void Tasks::ClearLookAt()
{
	AI::TASK_CLEAR_LOOK_AT(_ped.Handle());
}
//void Tasks::ClearSecondary()
//{
//	CLEAR_PED_SECONDARY_TASK(_ped.Handle());
//}
//void Tasks::ClearAnimation(const std::string& animDict, const std::string& animName)
//{
//	STOP_ANIM_TASK(_ped.Handle(), const_cast<PCHAR>(animDict.c_str()), const_cast<PCHAR>(animName.c_str()), -4.0f);
//}
//
//
//
TaskSequence2::TaskSequence2()
	: _count(0), _isClosed(false)
{
	int handle = 0;
	AI::OPEN_SEQUENCE_TASK(&handle);

	this->_handle = handle;
}
TaskSequence2::TaskSequence2(int handle)
	: _handle(handle), _count(0), _isClosed(false)
{
}
//TaskSequence2::~TaskSequence2()
//{
//this->Clear();
//}

int& TaskSequence2::Handle()
{
	return this->_handle;
}

int TaskSequence2::Count()
{
	return this->_count;
}

Tasks TaskSequence2::AddTask()
{
	if (this->_isClosed)
	{
		throw ("You can't add tasks to a closed sequence!");
	}

	this->_count++;

	return Tasks(0);
}

bool TaskSequence2::IsClosed()
{
	return this->_isClosed;
}
void TaskSequence2::Close(bool repeat)
{
	if (!this->_isClosed)
	{
		AI::SET_SEQUENCE_TO_REPEAT(this->_handle, repeat);
		AI::CLOSE_SEQUENCE_TASK(this->_handle);

		_isClosed = true;
	}
}
void TaskSequence2::Clear()
{
	int handle = this->_handle;
	AI::CLEAR_SEQUENCE_TASK(&handle);
	this->_handle = handle;
}

void TaskSequence2::MakePedPerform(GTAentity ped)
{
	if (!this->IsClosed())
	{
		this->Close();
	}

	//ClearAll();

	//SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(_ped.Handle(), true);

	AI::TASK_PERFORM_SEQUENCE(ped.Handle(), this->Handle());
}


