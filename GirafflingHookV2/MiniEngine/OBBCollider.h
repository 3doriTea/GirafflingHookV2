#pragma once
#include "Attachment.h"
#include "Collider.h"
#include "Box3.h"
#include "Transform.h"

class Draw3D;

class OBBCollider : public Attachment, public Collider, public Box3
{
	friend Collider;
	friend Draw3D;
public:
	OBBCollider(GameObject& attachingGameObject, Transform& transform);

	void Draw() const override;

public:
	using Box3::max;
	using Box3::min;

private:
	Transform& transform;
};
