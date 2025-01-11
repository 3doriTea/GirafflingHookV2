#include "AABBCollider.h"
#include "GameObject.h"

AABBCollider::AABBCollider(GameObject& gameObject, Transform& transform) :
	Attachment::Attachment{ gameObject },
	transform{ transform }
{
	max = gameObject.scale / 2.f;
	min = gameObject.scale / -2.f;
}

void AABBCollider::Draw() const
{
	DrawLine3D(min, max, 0x00ff00);
}
