#pragma once
#include "GameObject.h"
#include "Vector3.h"
#include "AABBCollider.h"
#include "Transform.h"

class GroundCollider : public GameObject
{
public:
	GroundCollider(
		const Vector3& _position,
		const Vector3& _rotate,
		const Vector3& _scale);
	~GroundCollider();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;

private:
	AABBCollider collider_;
	Transform transform_;
};

