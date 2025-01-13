#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "Frame.h"

PhysicsManager::PhysicsManager() :
	Manager::Manager{ CalledType::Frame },
	rigidBodies_{}
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
	for (auto&& rigidbody : rigidBodies_)
	{
		Vector3& position{ rigidbody->position_ };
		Vector3& velocity{ rigidbody->velocity };
		float& resistance{ rigidbody->resistance };
		
		position += velocity * deltaTime;
		velocity += velocity * -resistance * deltaTime;
		
		Vector3& rotate{ rigidbody->rotate_ };
		Vector3& velocityTorque{ rigidbody->velocityTorque };
		float& resistanceTorque{ rigidbody->resistanceTorque };

		rotate += velocityTorque * deltaTime;
		velocityTorque += velocityTorque * -resistanceTorque * deltaTime;
		rotate %= 360.f;  // 360“x“à‚ÉŽû‚ß‚é
	}
}

void PhysicsManager::End()
{
}

void PhysicsManager::Register(Rigidbody* rigidbody)
{
	instance->rigidBodies_.insert(rigidbody);
}

void PhysicsManager::Unregister(Rigidbody* rigidbody)
{
	instance->rigidBodies_.erase(rigidbody);
}

PhysicsManager* PhysicsManager::instance{ nullptr };
