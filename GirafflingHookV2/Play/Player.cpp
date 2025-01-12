#include "Player.h"
#include <DxLib.h>
#include <cassert>
#include <cmath>
#include "Draw3D.h"

Play::Player::Player() :
	GameObject::GameObject
	{ 
		GameObjectBuilder{}
			.Name("Player")
			.Tag("player")
			.Scale({ 300.f, 300.f, 300.f })
	},
	transform_{ *this },
	collider_{ *this, transform_ },
	hGiraffeMV1_{ -1 },
	isHooking_{ false }
{
}

Play::Player::~Player()
{
}

void Play::Player::Init()
{
	hGiraffeMV1_ = MV1LoadModel("Assets/cube001.mv1");
	assert(hGiraffeMV1_ != -1);
}

void Play::Player::Update()
{
	/*rotate.y += Frame::GetDeltaTime() * 1000.f;
	rotate.y = std::fmodf(rotate.y, 360.f);*/

	Vector3 move{ Vector3::Zero() };
	if (CheckHitKey(KEY_INPUT_Q))
		move.y -= 10.f;
	if (CheckHitKey(KEY_INPUT_E))
		move.y += 10.f;
	if (CheckHitKey(KEY_INPUT_W))
		move.z += 10.f;
	if (CheckHitKey(KEY_INPUT_A))
		move.x -= 10.f;
	if (CheckHitKey(KEY_INPUT_S))
		move.z -= 10.f;
	if (CheckHitKey(KEY_INPUT_D))
		move.x += 10.f;

	position += move;

	MV1SetRotationXYZ(hGiraffeMV1_, transform_.GetRotateRadian());
	MV1SetPosition(hGiraffeMV1_, position);
}

void Play::Player::Draw() const
{
	MV1DrawModel(hGiraffeMV1_);
	//collider_.Draw();
	Draw3D::Box(collider_, 0x00ff00);
}

void Play::Player::End()
{
	MV1DeleteModel(hGiraffeMV1_);
}
