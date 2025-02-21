#pragma once
#include "Attachment.h"
#include "Collider.h"
#include "Box3.h"
#include "Transform.h"
#include <DirectXMath.h>

class Draw3D;

class AABBCollider : public Attachment, public Collider
{
	friend Collider;
	friend Draw3D;
public:
	AABBCollider(GameObject& attachingGameObject, Transform& transform);
	virtual ~AABBCollider() {};

	void Draw() const override;

	/// <summary>
	/// 各軸-投影線分の長さの半分に変換
	/// </summary>
	/// <returns></returns>
	Vector3 ToProjectionSize();


public:
	bool IsHitAABB(const AABBCollider& target) const;
	Vector3 ReflectionAABB(const AABBCollider& target) const;

	Vector3 Min() const;
	Vector3 Max() const;

	Vector3 HalfSize() const;

private:
	Transform& transform_;
	DirectX::XMMATRIX& rotateMatrix_;
};
