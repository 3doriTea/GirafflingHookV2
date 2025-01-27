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
			// �������g�̃R���C�_�[�Ȃ��A
			if (self->colliderPtr_ == targetCollider)
			{
				continue;
			}

			if (static_cast<AABBCollider*>(self->colliderPtr_)
				->IsHitAABB(*static_cast<AABBCollider*>(targetCollider)))
			{
				// TODO: �q�b�g�����Ƃ��̃C�x���g�֐����Ăяo������
				/*printfDx(
					"OnHit %s : %s\n",
					self->gameObject.GetName().c_str(),
					targetCollider->gameObject.GetName().c_str());*/
				Vector3 reflection
				{
					static_cast<AABBCollider*>(self->colliderPtr_)
						->ReflectionAABB(*static_cast<AABBCollider*>(targetCollider))
				};

				//self->velocity += reflection * 1.f;
				self->reflection += reflection;
			}
			else
			{
				//printfDx("�������ĂȂ��I");
			}
		}
	}

	for (auto&& rigidbody : dynamicRigidBodies_)
	{
		// ���W
		Vector3& position{ rigidbody->position_ };
		// �ړ����x
		Vector3& velocity{ rigidbody->velocity };
		// �R���C�_�[�̔����x�N�g��
		Vector3& reflection{ rigidbody->reflection };
		// �ړ���R
		float& resistance{ rigidbody->resistance };
		// �d��
		float& gravity{ rigidbody->gravity };
		// �Œ莲
		bool&
			fixedX{ rigidbody->fixedX },
			fixedY{ rigidbody->fixedY },
			fixedZ{ rigidbody->fixedZ };

		if (fixedX)
		{
			velocity.x *= 0.f;
			reflection.x *= 0.f;
		}
		if (fixedY)
		{
			velocity.y *= 0.f;
			reflection.y *= 0.f;
		}
		if (fixedZ)
		{
			velocity.z *= 0.f;
			reflection.z *= 0.f;
		}

		// �R���C�_�[�̔����x�N�g����K�p
		position += reflection;

#pragma region ���˃x�N�g�������߂�
		// REF: http://marupeke296.com/COL_Basic_No5_WallVector.html
		
		Vector3 n{ reflection };
		Vector3 nNorm{ (n.Length() < FLT_EPSILON ? Vector3::Zero() : n.Normalize())};
		float a{ -VDot(velocity, nNorm) };

		// �ǂ���x�N�g��
		Vector3 w
		{
			velocity - (nNorm * VDot(velocity, nNorm))
		};

		// ���˃x�N�g��
		Vector3 r
		{
			velocity + nNorm * (2.f * a)
		};

		// ���˃x�N�g���̓K�p
		velocity = r;
#pragma endregion

		// ���x�̓K�p
		position += velocity * deltaTime;
		// �ړ���R�̓K�p
		velocity += velocity * -resistance * deltaTime;

		// �p�x
		Vector3& rotate{ rigidbody->rotate_ };
		// ��]���x
		Vector3& velocityTorque{ rigidbody->velocityTorque };
		// ��]��R
		float& resistanceTorque{ rigidbody->resistanceTorque };

		// ��]�̓K�p
		rotate += velocityTorque * deltaTime;
		// ��]��R�̓K�p
		velocityTorque += velocityTorque * -resistanceTorque * deltaTime;
		// 360�x���Ɏ��߂�
		rotate %= 360.f;
		// ���̃t���[���ł͈��������g��Ȃ����߃N���A
		reflection = Vector3::Zero();
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

	// ���I���̂Ƃ��ēo�^�ς݂Ȃ����
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
