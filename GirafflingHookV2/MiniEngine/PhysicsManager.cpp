#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "Frame.h"
#include "AABBCollider.h"
#include "Collider.h"

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
	for (auto&& rigidbody : dynamicRigidBodies_)
	{
		Vector3& position{ rigidbody->position_ };
		Vector3& velocity{ rigidbody->velocity };
		float& resistance{ rigidbody->resistance };
		float& gravity{ rigidbody->gravity };

		
		position += velocity * deltaTime;
		velocity += velocity * -resistance * deltaTime;
		
		// 重力の適用
		velocity += Vector3::Down() * gravity * deltaTime;
		
		Vector3& rotate{ rigidbody->rotate_ };
		Vector3& velocityTorque{ rigidbody->velocityTorque };
		float& resistanceTorque{ rigidbody->resistanceTorque };

		rotate += velocityTorque * deltaTime;
		velocityTorque += velocityTorque * -resistanceTorque * deltaTime;
		rotate %= 360.f;  // 360度内に収める
	}

	for (auto&& self : dynamicRigidBodies_)
	{
		for (auto&& targetCollider : colliders_)
		{
			if (self->colliderPtr_ == targetCollider)
			{
				continue;
			}

			if (static_cast<AABBCollider*>(self->colliderPtr_)
				->IsHitAABB(*static_cast<AABBCollider*>(targetCollider)))
			{
				printfDx("当たってる！");
			}
			else
			{
				printfDx("当たってない！");
			}
		}
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

	// 動的剛体として登録済みなら消す
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
