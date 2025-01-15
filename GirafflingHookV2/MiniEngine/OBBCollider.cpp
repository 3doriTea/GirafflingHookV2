#include "OBBCollider.h"
#include "GameObject.h"
#include "Draw3D.h"

OBBCollider::OBBCollider(GameObject& gameObject, Transform& transform) :
	Attachment::Attachment{ gameObject },
	transform{ transform }
{
	max = gameObject.scale / 2.f;
	min = gameObject.scale / -2.f;
}

void OBBCollider::Draw() const
{
	Draw3D::Box(*this, 0x00ff00);
}
