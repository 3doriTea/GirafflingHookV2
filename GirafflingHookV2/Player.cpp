#include "Player.h"
#include <DxLib.h>
#include <cassert>
#include "Draw3D.h"

Player::Player() :
	GameObject::GameObject
	{ 
		GameObjectBuilder{}
			.Name("Player")
			.Tag("player")
			.Scale({ 300.f, 300.f, 300.f })
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
	//collider_.Draw();
	Draw3D::Box(collider_, 0x00ff00);
}

void Player::End()
{
	MV1DeleteModel(hGiraffeMV1_);
}
