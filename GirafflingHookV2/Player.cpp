#include "Player.h"
#include <DxLib.h>
#include <cassert>

Player::Player() :
	GameObject::GameObject
	{ 
		GameObjectBuilder{}
			.Name("Player")
			.Tag("player")
			.Scale({ 30.f, 30.f, 30.f })
	},
	transform_{ *this },
	collider_{ *this, transform_ },
	hGiraffeMV1_{ -1 }
{
}

Player::~Player()
{
}

void Player::Init()
{
	hGiraffeMV1_ = MV1LoadModel("Assets/cube001.mv1");
	assert(hGiraffeMV1_ != -1);

	MV1SetRotationXYZ(hGiraffeMV1_, VGet(0.f, 0.f, 0.f));
	MV1SetPosition(hGiraffeMV1_, position);
}

void Player::Update()
{
}

void Player::Draw() const
{
	MV1DrawModel(hGiraffeMV1_);
	collider_.Draw();
}

void Player::End()
{
	MV1DeleteModel(hGiraffeMV1_);
}
