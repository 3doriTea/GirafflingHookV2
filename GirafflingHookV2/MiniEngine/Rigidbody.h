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
		Collider* colliderPtr,
		const bool& isDynamic = false);
	~Rigidbody();

	void Draw() const override;

public:
	// 1�b�Ԃ�����̈ړ����x
	Vector3 velocity;
	// 1�b�Ԃ�����̈ړ���R
	float resistance;

	// 1�b�Ԃ�����̉�]���x
	Vector3 velocityTorque;
	// 1�b�Ԃ�����̉�]��R
	float resistanceTorque;
	// 1�b�Ԃ�����̏d�͉����x
	float gravity;
	// x���̓������Œ肷�邩
	bool fixedX;
	// y���̓������Œ肷�邩
	bool fixedY;
	// z���̓������Œ肷�邩
	bool fixedZ;

	// ���̃R���C�_�[����̔����x�N�g��
	Vector3 reflection{};

private:
	Transform& transform_;
	Collider* colliderPtr_;
	Vector3& position_;
	Vector3& rotate_;
};
