#include "Collider.h"
#include "Vector3.h"
#include <cfloat>
#include <DirectXMath.h>
#include <cmath>
#include <DxLib.h>
#include "AABBCollider.h"
#include "GameObject.h"
#include "PhysicsManager.h"

Collider::Collider(const GameObject& _gameObject) :
	gameObject{ _gameObject }
{
	PhysicsManager::RegisterCollider(this);
}

Collider::~Collider()
{
	PhysicsManager::UnregisterCollider(this);
}

bool Collider::IsHit_AABB2AABB(const AABBCollider& a, const AABBCollider& b) const
{
	Vector3 abDistance
	{
		(a.transform_.ToWorldPosition(Vector3::Zero())
		- b.transform_.ToWorldPosition(Vector3::Zero()))
		.Abs()
	};

	Vector3 abLength{ a.HalfSize() + b.HalfSize() };

	for (int i = 0; i < 3; i++)
	{
		// x y z �����ɃC���f�b�N�X�ŃA�N�Z�X
		if ((abLength[i] <= abDistance[i]))
		{
			return false;
		}
	}

	return true;
}

Vector3 Collider::Reflection_AABB2AABB(
	const AABBCollider& self,
	const AABBCollider& target) const
{
	// �����Ƒ���Ƃ̈ʒu�֌W�x�N�g��
	Vector3 diff
	{
		self.transform_.ToWorldPosition(Vector3::Zero())
		- target.transform_.ToWorldPosition(Vector3::Zero())
	};

	// �����Ƒ���A�����𑫂����T�C�Y�x�N�g��
	Vector3 bothSize
	{
		self.HalfSize() + target.HalfSize()
	};

	Vector3 volume
	{
		diff.Abs() + bothSize
	};

	Vector3 reflection{ Vector3::One() };

	float volumeMax{ std::fmaxf(std::fmaxf(volume.x, volume.y), volume.z) };
	for (int i = 0; i < 3; i++)
	{
		if (volume[i] < volumeMax)
		{
			reflection[i] = 0.f;
		}
	}


	return reflection;
}
