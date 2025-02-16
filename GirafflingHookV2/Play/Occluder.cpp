#include "Occluder.h"
#include "OccludableObject.h"
#include "Camera.h"

Play::Occluder::Occluder() :
	camera_{ nullptr },
	occludableObjects_{},
	OCCLUDE_PLAYER_DISTANCE{ 5000.f }
{
}

Play::Occluder::~Occluder()
{
}

void Play::Occluder::Init()
{
	camera_ = FindGameObject<Camera>();
	assert(camera_ != nullptr);  // ƒvƒŒƒCƒ„[‚ÍŒ©‚Â‚©‚é
}

void Play::Occluder::Update()
{
	for (auto&& object : occludableObjects_)
	{
		if (Vector3::Distance(camera_->position, object->GetWorldPosition()) < object->occludeDistance)
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
