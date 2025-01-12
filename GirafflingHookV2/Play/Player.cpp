#include "Player.h"
#include <DxLib.h>
#include <cassert>
#include <cmath>
#include "Draw3D.h"
#include "GiraffePoint.h"

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
	animationTime_{ 0.f },
	hGiraffeMV1_{ -1 },
	isHooking_{ false }
{
}

Play::Player::~Player()
{
}

void Play::Player::Init()
{
	hGiraffeMV1_ = MV1LoadModel("Assets/Play/giraffeee.mv1");
	assert(hGiraffeMV1_ != -1);
}

void Play::Player::Update()
{
	/*rotate.y += Frame::GetDeltaTime() * 1000.f;
	rotate.y = std::fmodf(rotate.y, 360.f);*/

	Vector3 move{ Vector3::Zero() };
	if (CheckHitKey(KEY_INPUT_W))
		move.y += 10.f;
	if (CheckHitKey(KEY_INPUT_S))
		move.y -= 10.f;
	if (CheckHitKey(KEY_INPUT_A))
		move.x -= 10.f;
	if (CheckHitKey(KEY_INPUT_D))
		move.x += 10.f;

	if (Input::IsKeyDown(KeyCode::E))
	{
		isHooking_ = true;
		MV1AttachAnim(hGiraffeMV1_, 0);
		animationTime_ = 0.f;

		GiraffePoint* point{ FindGameObject<GiraffePoint>() };
		assert(point != nullptr);  // ギラッフポイントは見つかる

		transform_.LookAt({ 0.f, 1.f, 0.f }, point->position);
	}

	if (Input::IsKeyUp(KeyCode::E))
	{
		isHooking_ = false;
		MV1DetachAnim(hGiraffeMV1_, 0);
		transform_.rotate = { 0.f, 0.f, 0.f };
	}

	if (isHooking_)
	{
		animationTime_ += Frame::GetDeltaTime() * 100.f;
		MV1SetAttachAnimTime(hGiraffeMV1_, 0, animationTime_);
	}

	position += move;

	MV1SetRotationXYZ(hGiraffeMV1_, transform_.GetRotateRadian());
	MV1SetPosition(hGiraffeMV1_, position);
	MV1SetScale(hGiraffeMV1_, scale * 0.002f);
}

void Play::Player::Draw() const
{
	MV1DrawModel(hGiraffeMV1_);
	collider_.Draw();
	//Draw3D::Box(collider_, 0x00ff00);
}

void Play::Player::End()
{
	MV1DeleteModel(hGiraffeMV1_);
}
