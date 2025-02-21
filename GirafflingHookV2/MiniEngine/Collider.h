#pragma once
#include "GameObject.h"

//class OBBCollider;
class AABBCollider;
class PhysicsManager;

class Collider
{
	//friend OBBCollider;
	friend AABBCollider;
public:
	Collider(const GameObject& _gameObject);
	~Collider();

	/*bool IsHit_OBB2OBB(
		OBBCollider& a,
		OBBCollider& b);*/

	bool IsHit_AABB2AABB(
		const AABBCollider& a,
		const AABBCollider& b) const;

	Vector3 Reflection_AABB2AABB(
		const AABBCollider& self,
		const AABBCollider& target) const;

	const GameObject& gameObject;
};
