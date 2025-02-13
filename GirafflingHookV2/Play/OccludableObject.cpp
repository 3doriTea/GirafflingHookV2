#include "OccludableObject.h"
#include "Player.h"

Play::OccludableObject::OccludableObject() :
	occludeDistance{ 0.0f }
{
}

Play::OccludableObject::~OccludableObject()
{
}

void Play::OccludableObject::Init(const Transform& _transform)
{
	Vector3 worldScale{ _transform.GetWorldScale() };
	float maxWidth
	{
		std::fmaxf(worldScale.x, std::fmaxf(worldScale.y, worldScale.z))
	};
	Occluder* occluder{ FindGameObject<Occluder>() };
	assert(occluder != nullptr);  // オクルーダーは見つかる

	occludeDistance = maxWidth + occluder->OCCLUDE_PLAYER_DISTANCE;

	occluder->Register(this);
}

void Play::OccludableObject::End()
{
	Occluder* occluder{ FindGameObject<Occluder>() };
	assert(occluder != nullptr);  // オクルーダーは見つかる

	occluder->Unregister(this);
}
