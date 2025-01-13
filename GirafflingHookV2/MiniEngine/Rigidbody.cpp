#include "Rigidbody.h"
#include "PhysicsManager.h"

Rigidbody::Rigidbody(
	GameObject& attachingGameObject,
	Transform& transform,
	Collider* colliderPtr) :
	Attachment::Attachment{ attachingGameObject },
	transform_{ transform },
	colliderPtr_{ colliderPtr },
	position_{ transform.position },
	velocity{ Vector3::Zero() },
	resistance{ 0.f }
{
	PhysicsManager::Register(this);
}

Rigidbody::~Rigidbody()
{
}

void Rigidbody::Draw() const
{
}
