#pragma once

//class OBBCollider;
class AABBCollider;
class PhysicsManager;

class Collider
{
	//friend OBBCollider;
	friend AABBCollider;
public:
	Collider();
	~Collider();

	/*bool IsHit_OBB2OBB(
		OBBCollider& a,
		OBBCollider& b);*/

	bool IsHit_AABB2AABB(
		const AABBCollider& a,
		const AABBCollider& b) const;
};
