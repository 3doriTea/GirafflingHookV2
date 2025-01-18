#include "GroundCollider.h"

GroundCollider::GroundCollider(
	const Vector3& _position,
	const Vector3& _rotate,
	const Vector3& _scale) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("GroundCollider")
			.Tag("ground-collider")
			.Position(_position)
			.Rotate(_rotate)
			.Scale(_scale)
	},
	transform_{ *this },
	collider_{ *this, transform_ }
{
}

GroundCollider::~GroundCollider()
{
}

void GroundCollider::Init()
{
}

void GroundCollider::Update()
{
}

void GroundCollider::Draw() const
{
	collider_.Draw();
}

void GroundCollider::End()
{
}
