#include "AABBCollider.h"
#include "GameObject.h"
#include "Draw3D.h"

AABBCollider::AABBCollider(GameObject& gameObject, Transform& transform) :
	Attachment::Attachment{ gameObject },
	Collider::Collider{ gameObject },
	transform_{ transform },
	rotateMatrix_{ transform.rotateMatrix_ }
{
	/*max = gameObject.scale / 2.f;
	min = gameObject.scale / -2.f;*/
}

void AABBCollider::Draw() const
{
	Draw3D::Box(*this, 0x00ff00);
}

Vector3 AABBCollider::ToProjectionSize()
{
	// REF: http://marupeke296.com/COL_3D_No13_OBBvsOBB.html
	// REF: http://distancevector.web.fc2.com/collision.html



	Vector3 right{ transform_.Right() };
	Vector3 up{ transform_.Up() };
	Vector3 forward{ transform_.Forward() };

	float rA{ right.x + up.x };

	return {};
}

bool AABBCollider::IsHitAABB(const AABBCollider& target) const
{
	return IsHit_AABB2AABB(*this, target);
}

Vector3 AABBCollider::ReflectionAABB(const AABBCollider& target) const
{
	return Reflection_AABB2AABB(*this, target);
}

Vector3 AABBCollider::Min() const
{
	return -HalfSize() + transform_.ToWorldPosition(Vector3::Zero());
}

Vector3 AABBCollider::Max() const
{
	return HalfSize() + transform_.ToWorldPosition(Vector3::Zero());
}
Vector3 AABBCollider::HalfSize() const
{
	float halfX
	{
		std::fabsf(VDot(Vector3::Right(), transform_.Right()))
		+ std::fabsf(VDot(Vector3::Right(), transform_.Up()))
	};
	float halfY
	{
		std::fabsf(VDot(Vector3::Up(), transform_.Right()))
		+ std::fabsf(VDot(Vector3::Up(), transform_.Up()))
	};
	float halfZ
	{
		std::fabsf(VDot(Vector3::Forward(), transform_.Forward()))
		+ std::fabsf(VDot(Vector3::Forward(), transform_.Up()))
	};

	return { halfX, halfY, halfZ };
}
//
//bool AABBCollider::IsHit2OBB(AABBCollider& target)
//{
//	return false;
//}
