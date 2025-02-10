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
	// 1秒間あたりの移動速度
	Vector3 velocity;
	// 1秒間あたりの移動抵抗
	float resistance;

	// 1秒間あたりの回転速度
	Vector3 velocityTorque;
	// 1秒間あたりの回転抵抗
	float resistanceTorque;
	// 1秒間あたりの重力加速度
	float gravity;
	// x軸の動きを固定するか
	bool fixedX;
	// y軸の動きを固定するか
	bool fixedY;
	// z軸の動きを固定するか
	bool fixedZ;

	// 地面に立っているかどうか
	inline bool IsGrounded() const { return reflection.y > 0.f; }

	// 他のコライダーからの反発ベクトル
	Vector3 reflection{};

private:
	Transform& transform_;
	Collider* colliderPtr_;
	Vector3& position_;
	Vector3& rotate_;
};
