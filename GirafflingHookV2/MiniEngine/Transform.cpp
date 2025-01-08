#include "Transform.h"

Transform::Transform(GameObject& gameObject) :
	Attachment::Attachment{ gameObject },
	rotate{},
	scale{},
	positionMatrix_{},
	rotateMatrix_{},
	scaleMatrix_{}
{
	Calculate();
}

void Transform::Calculate()
{
	positionMatrix_ = DirectX::XMMatrixTranslation(position.x, position.y, 0.f);

	rotateMatrix_ = DirectX::XMMatrixRotationZ(rotate);

	scaleMatrix_ = DirectX::XMMatrixScaling(scale.x, scale.y, 1.f);
}

DirectX::XMFLOAT2 Transform::ToWorldPosition(const DirectX::XMFLOAT2& localPosition)
{
	DirectX::XMVECTOR localPositionVector{ DirectX::XMLoadFloat2(&localPosition) };

	DirectX::XMVECTOR worldPositionVector
	{
		DirectX::XMVector2Transform(localPositionVector, GetWorldMatrix())
	};

	DirectX::XMFLOAT2 worldPosition{};
	DirectX::XMStoreFloat2(&worldPosition, worldPositionVector);

	return worldPosition;
}

DirectX::XMMATRIX Transform::GetWorldMatrix()
{
	if (parent == nullptr)
	{
		return scaleMatrix_ * rotateMatrix_ * positionMatrix_ * parent->GetWorldMatrix();
	}
	
	return scaleMatrix_ * rotateMatrix_ * positionMatrix_;
}
