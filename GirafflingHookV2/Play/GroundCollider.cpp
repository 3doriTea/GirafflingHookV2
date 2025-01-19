#include "GroundCollider.h"

Play::GroundCollider::GroundCollider(
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

Play::GroundCollider::~GroundCollider()
{
}

void Play::GroundCollider::Init()
{
}

void Play::GroundCollider::Update()
{
}

void Play::GroundCollider::Draw() const
{
	collider_.Draw();
}

void Play::GroundCollider::End()
{
}
