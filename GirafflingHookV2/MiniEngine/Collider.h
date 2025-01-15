#pragma once

class OBBCollider;

class Collider
{
	friend OBBCollider;
public:
	Collider() {};
	~Collider() {};

	bool IsHit_OBB2OBB(
		const OBBCollider& a,
		const OBBCollider& b);
};
