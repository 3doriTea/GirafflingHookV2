#pragma once
#include "Attachment.h"
#include "Vector2.h"
#include <DirectXMath.h>
#include <set>

class GameObject;

class Transform : public Attachment
{
public:
	Transform(GameObject& gameObject);

	void Calculate();
	DirectX::XMFLOAT2 ToWorldPosition(const DirectX::XMFLOAT2& localPosition);

private:
	DirectX::XMMATRIX GetWorldMatrix();

public:
	float rotate;
	Vector2 scale;

	Transform* parent;
	std::set<Transform*> childs;

private:
	DirectX::XMMATRIX positionMatrix_;
	DirectX::XMMATRIX rotateMatrix_;
	DirectX::XMMATRIX scaleMatrix_;
};

