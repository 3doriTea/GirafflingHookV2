#include "Transform.h"
#include "GameObject.h"
#include "TransformManager.h"
#include <cmath>
//#include "OBBCollider.h"
#include "AABBCollider.h"

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
	TransformManager::Register(this);

	UpdateCalculate();
}

Transform::~Transform()
{
	/*if (parent_ != nullptr)
	{
		parent_->childs_.erase(this);
	}*/
	for (auto&& child : childs_)
	{
		child->parent_ = nullptr;
	}
	TransformManager::Unregister(this);
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

Vector3 Transform::ToWorldPosition(const Vector3& localPosition) const
{
	DirectX::XMVECTOR localPositionVector
	{
		DirectX::XMLoadFloat3(&localPosition)
	};

	DirectX::XMVECTOR worldPositionVector
	{
		DirectX::XMVector3Transform(localPositionVector, GetWorldTranslateMatrix())
	};

	DirectX::XMFLOAT3 worldPosition{};
	DirectX::XMStoreFloat3(&worldPosition, worldPositionVector);

	return Vector3::From(worldPosition);
}

Vector3 Transform::ToWorldDirection(const Vector3& localDirection) const
{
	DirectX::XMVECTOR localDirectionVector
	{
		DirectX::XMLoadFloat3(&localDirection)
	};

	DirectX::XMVECTOR worldDirectionVector
	{
		DirectX::XMVector3Transform(localDirectionVector, GetWorldDirectionMatrix())
	};

	DirectX::XMFLOAT3 worldPosition{};
	DirectX::XMStoreFloat3(&worldPosition, worldDirectionVector);

	return Vector3::From(worldPosition);
}

void Transform::LookAt(Vector3 forwardDirection, const Vector3& targetPosition)
{
	// SRC: http://www.yz-learning.com:8080/knowledge/open.knowledge/view/36?offset=0
	
	// 向けたい軸
	Vector3 forward{ forwardDirection.Normalize() };

	// 対象への方向ベクトル
	Vector3 direction{ (targetPosition - this->position).Normalize() };

	// 2軸に垂直なベクトル = 法線ベクトル
	Vector3 normal{ Vector3::From(VCross(forward, direction)) };

	if (normal.Length() <= FLT_EPSILON)
	{
		return;
	}

	float rotationAngle
	{
		XMVectorGetX(
			XMVector3AngleBetweenVectors(
				forward, direction))
	};
	rotateMatrix_ = XMMatrixRotationAxis(normal, rotationAngle);

	XMFLOAT4X4 m{};
	XMStoreFloat4x4(&m, rotateMatrix_);

	if (std::abs(m._32) < 0.99999f)
	{
		rotate.x = std::asin(-m._32);
		rotate.y = std::atan2(m._31, m._33);
		rotate.z = std::atan2(m._12, m._22);
	}
	else  // ジンバルロック回避
	{
		rotate.x = std::copysign(XM_PIDIV2, -m._32);
		rotate.y = std::atan2(-m._13, m._11);
		rotate.z = 0.0f;
	}

	// MEMO: ラジアンから度数に変換
	rotate.x = XMConvertToDegrees(rotate.x);
	rotate.y = XMConvertToDegrees(rotate.y);
	rotate.z = XMConvertToDegrees(rotate.z);
}

void Transform::SetParent(Transform* parent)
{
	if (parent_ != nullptr)
	{
		parent_->childs_.erase(this);
	}
	parent_ = parent;
}

void Transform::SetParent(Transform& parent)
{
	SetParent(&parent);
}

DirectX::XMMATRIX Transform::GetWorldTranslateMatrix() const
{
	if (this->parent_ != nullptr)
	{
		return scaleMatrix_ * rotateMatrix_ * positionMatrix_ * parent_->GetWorldTranslateMatrix();
	}
	
	return scaleMatrix_ * rotateMatrix_ * positionMatrix_;
}

DirectX::XMMATRIX Transform::GetWorldDirectionMatrix() const
{
	if (parent_ != nullptr)
	{
		return rotateMatrix_ * parent_->GetWorldDirectionMatrix();
	}

	return rotateMatrix_;
}
