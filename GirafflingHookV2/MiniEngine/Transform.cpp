#include "Transform.h"
#include "GameObject.h"

using namespace DirectX;

Transform::Transform(GameObject& gameObject) :
	Attachment::Attachment{ gameObject },
	position{ gameObject.position },
	rotate{ gameObject.rotate },
	scale{ gameObject.scale },
	positionMatrix_{},
	rotateMatrix_{},
	scaleMatrix_{},
	parent_{ nullptr },
	childs_{}
{
	UpdateCalculate();
}

void Transform::Draw() const
{
}

void Transform::UpdateCalculate()
{
	positionMatrix_ = XMMatrixTranslation(
		position.x,
		position.y,
		position.z);

	XMMATRIX
		rotateX{ XMMatrixRotationX(XMConvertToRadians(rotate.x)) },
		rotateY{ XMMatrixRotationY(XMConvertToRadians(rotate.y)) },
		rotateZ{ XMMatrixRotationZ(XMConvertToRadians(rotate.z)) };
	
	rotateMatrix_ = rotateZ * rotateX * rotateY;

	scaleMatrix_ = XMMatrixScaling(
		scale.x,
		scale.y,
		scale.z);
}

Vector3 Transform::ToWorldPosition(const Vector3& localPosition)
{
	DirectX::XMVECTOR localPositionVector
	{
		DirectX::XMLoadFloat3(&localPosition)
	};

	DirectX::XMVECTOR worldPositionVector
	{
		DirectX::XMVector3Transform(localPositionVector, GetWorldMatrix())
	};

	DirectX::XMFLOAT3 worldPosition{};
	DirectX::XMStoreFloat3(&worldPosition, worldPositionVector);

	return Vector3::From(worldPosition);
}

void Transform::SetParent(Transform* parent)
{
	if (parent_ != nullptr)
	{
		parent_->childs_.erase(this);
	}
	parent_ = parent;
}

DirectX::XMMATRIX Transform::GetWorldMatrix()
{
	if (parent_ != nullptr)
	{
		return scaleMatrix_ * rotateMatrix_ * positionMatrix_ * parent_->GetWorldMatrix();
	}
	
	return scaleMatrix_ * rotateMatrix_ * positionMatrix_;
}
