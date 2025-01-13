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
	// 1ïbä‘Ç†ÇΩÇËÇÃë¨ìx
	Vector3 velocity;
	// 1ïbä‘Ç†ÇΩÇËÇÃíÔçR
	float resistance;

private:
	Transform& transform_;
	Collider* colliderPtr_;
	Vector3& position_;
};
