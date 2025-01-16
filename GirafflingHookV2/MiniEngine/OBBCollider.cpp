#include "OBBCollider.h"
#include "GameObject.h"
#include "Draw3D.h"

OBBCollider::OBBCollider(GameObject& gameObject, Transform& transform) :
	Attachment::Attachment{ gameObject },
	transform_{ transform }
{
	max = gameObject.scale / 2.f;
	min = gameObject.scale / -2.f;
}

void OBBCollider::Draw() const
{
	Draw3D::Box(*this, 0x00ff00);
}

Vector3 OBBCollider::ToProjectionSize()
{
	// REF: http://marupeke296.com/COL_3D_No13_OBBvsOBB.html
	// REF: http://distancevector.web.fc2.com/collision.html



	Vector3 right{ transform_.Right() };
	Vector3 up{ transform_.Up() };
	Vector3 forward{ transform_.Forward() };

	float rA{ right.x + up.x };

	return ;
}
