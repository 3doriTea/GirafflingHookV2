#include "Occluder.h"
#include "OccludableObject.h"
#include "Player.h"

Play::Occluder::Occluder() :
	player_{ nullptr },
	occludableObjects_{},
	OCCLUDE_PLAYER_DISTANCE{ 300.f }
{
}

Play::Occluder::~Occluder()
{
}

void Play::Occluder::Init()
{
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // ƒvƒŒƒCƒ„[‚ÍŒ©‚Â‚©‚é
}

void Play::Occluder::Update()
{
	for (auto&& object : occludableObjects_)
	{
		if (Vector3::Distance(player_->position, object->position) < object->occludeDistance)
		{
			object->SetIsActive(true);
		}
		else
		{
			object->SetIsActive(false);
		}
	}
}

void Play::Occluder::End()
{
}

void Play::Occluder::Register(OccludableObject* object)
{
	occludableObjects_.insert(object);
}

void Play::Occluder::Unregister(OccludableObject* object)
{
	occludableObjects_.erase(object);
}
