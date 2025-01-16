#pragma once
#include "Attachment.h"
#include "Collider.h"
#include "Box3.h"
#include "Transform.h"
#include <DirectXMath.h>

class Draw3D;

class OBBCollider : public Attachment, public Collider, public Box3
{
	friend Collider;
	friend Draw3D;
public:
	OBBCollider(GameObject& attachingGameObject, Transform& transform);

	void Draw() const override;

	/// <summary>
	/// �e��-���e�����̒����̔����ɕϊ�
	/// </summary>
	/// <returns></returns>
	Vector3 ToProjectionSize();

public:
	using Box3::max;
	using Box3::min;

private:
	Transform& transform_;
	DirectX::XMMATRIX& rotateMatrix_;
};
