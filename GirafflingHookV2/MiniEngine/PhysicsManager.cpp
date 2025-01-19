#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "Frame.h"
#include "AABBCollider.h"
#include "Collider.h"
#include "GameObject.h"

PhysicsManager::PhysicsManager() :
	Manager::Manager{ CalledType::Frame },
	rigidBodies_{},
	dynamicRigidBodies_{},
	colliders_{}
{
	instance = this;
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::Init()
{
}

void PhysicsManager::Update()
{
	float deltaTime = Frame::GetDeltaTime();

	for (auto&& self : dynamicRigidBodies_)
	{
		for (auto&& targetCollider : colliders_)
		{
			// Ž©•ªŽ©g‚ÌƒRƒ‰ƒCƒ_[‚È‚ç‰ñ‹A
			if (self->colliderPtr_ == targetCollider)
			{
				continue;
			}

			if (static_cast<AABBCollider*>(self->colliderPtr_)
				->IsHitAABB(*static_cast<AABBCollider*>(targetCollider)))
			{
				printfDx(
					"OnHit %s : %s\n",
					self->gameObject.GetName().c_str(),
					targetCollider->gameObject.GetName().c_str());
				Vector3 reflection
				{
					static_cast<AABBCollider*>(self->colliderPtr_)
						->ReflectionAABB(*static_cast<AABBCollider*>(targetCollider))
				};

				self->velocity += reflection * 100.f;
			}
			else
			{
				//printfDx("“–‚½‚Á‚Ä‚È‚¢I");
			}
		}
	}

	for (auto&& rigidbody : dynamicRigidBodies_)
	{
		// À•W
		Vector3& position{ rigidbody->position_ };
		// ˆÚ“®‘¬“x
		Vector3& velocity{ rigidbody->velocity };
		// ˆÚ“®’ïR
		float& resistance{ rigidbody->resistance };
		// d—Í
		float& gravity{ rigidbody->gravity };
		// ŒÅ’èŽ²
		bool&
			fixedX{ rigidbody->fixedX },
			fixedY{ rigidbody->fixedY },
			fixedZ{ rigidbody->fixedZ };

		if (fixedX)
		{
			velocity.x *= 0.f;
		}
		if (fixedY)
		{
			velocity.y *= 0.f;
		}
		if (fixedZ)
		{
			velocity.z *= 0.f;
		}

		// ‘¬“x‚Ì“K—p
		position += velocity * deltaTime;
		// ˆÚ“®’ïR‚Ì“K—p
		velocity += velocity * -resistance * deltaTime;

		// Šp“x
		Vector3& rotate{ rigidbody->rotate_ };
		// ‰ñ“]‘¬“x
		Vector3& velocityTorque{ rigidbody->velocityTorque };
		// ‰ñ“]’ïR
		float& resistanceTorque{ rigidbody->resistanceTorque };

		// ‰ñ“]‚Ì“K—p
		rotate += velocityTorque * deltaTime;
		// ‰ñ“]’ïR‚Ì“K—p
		velocityTorque += velocityTorque * -resistanceTorque * deltaTime;
		// 360“x“à‚ÉŽû‚ß‚é
		rotate %= 360.f;
	}
}

void PhysicsManager::End()
{
}

void PhysicsManager::RegisterRigidbody(Rigidbody* rigidbody, const bool& isDynamic)
{
	instance->rigidBodies_.insert(rigidbody);
	if (isDynamic)
	{
		instance->dynamicRigidBodies_.insert(rigidbody);
	}
}

void PhysicsManager::UnregisterRigidbody(Rigidbody* rigidbody)
{
	instance->rigidBodies_.erase(rigidbody);

	// “®“I„‘Ì‚Æ‚µ‚Ä“o˜^Ï‚Ý‚È‚çÁ‚·
	if (instance->dynamicRigidBodies_.count(rigidbody))
	{
		instance->dynamicRigidBodies_.erase(rigidbody);
	}
}

void PhysicsManager::RegisterCollider(Collider* collider)
{
	instance->colliders_.insert(collider);
}

void PhysicsManager::UnregisterCollider(Collider* collider)
{
	instance->colliders_.erase(collider);
}

PhysicsManager* PhysicsManager::instance{ nullptr };
