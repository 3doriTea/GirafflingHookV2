#pragma once
#include "Attachment.h"
#include "Transform.h"
#include "Collider.h"
#include "Vector3.h"

class PhysicsManager;

class Rigidbody : public Attachment
{
	friend PhysicsManager;

public:
	Rigidbody( 
		GameObject& attachingGameObject,
		Transform& transform,
		Collider* colliderPtr
		);
	~Rigidbody();

	void Draw() const override;

public:
	// 1•bŠÔ‚ ‚½‚è‚ÌˆÚ“®‘¬“x
	Vector3 velocity;
	// 1•bŠÔ‚ ‚½‚è‚ÌˆÚ“®’ïR
	float resistance;

	// 1•bŠÔ‚ ‚½‚è‚Ì‰ñ“]‘¬“x
	Vector3 velocityTorque;
	// 1•bŠÔ‚ ‚½‚è‚Ì‰ñ“]’ïR
	float resistanceTorque;

private:
	Transform& transform_;
	Collider* colliderPtr_;
	Vector3& position_;
	Vector3& rotate_;
};
