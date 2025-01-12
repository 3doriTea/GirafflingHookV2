#include "Ground.h"

Play::Ground::Ground() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("Ground")
			.Position({ 0.f, -400.f, 0.f })
			.Scale({ 1000.f, 10.f, 100.f })
	},
	transform_{ *this },
	collider_{ *this, transform_ }
{
}

Play::Ground::~Ground()
{
}

void Play::Ground::Init()
{
}

void Play::Ground::Draw() const
{
	collider_.Draw();
}
