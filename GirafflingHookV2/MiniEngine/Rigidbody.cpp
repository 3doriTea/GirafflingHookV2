#include "Rigidbody.h"
#include "PhysicsManager.h"

Rigidbody::Rigidbody(
	GameObject& attachingGameObject,
	Transform& transform,
	Collider* colliderPtr,
	const bool& isDynamic) :
	Attachment::Attachment{ attachingGameObject },
	transform_{ transform },
	colliderPtr_{ colliderPtr },
	position_{ transform.position },
	rotate_{ transform.rotate },
	velocity{ Vector3::Zero() },
	resistance{ 0.f }
{
	PhysicsManager::RegisterRigidbody(this, isDynamic);
}

Rigidbody::~Rigidbody()
{
	PhysicsManager::UnregisterRigidbody(this);
}

void Rigidbody::Draw() const
{
}
