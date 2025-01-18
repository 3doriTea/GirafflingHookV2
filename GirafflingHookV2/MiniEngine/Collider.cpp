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
		if ((abLength[i] <= abDistance[i]))
		{
			return false;
		}
	}

	return true;
}
