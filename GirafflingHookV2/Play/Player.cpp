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
	animationTimeMax_{ 0.f },
	hGiraffeMV1_{ -1 },
	isHooking_{ false },
	hookTarget_{ nullptr }
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

	// 首伸ばし中じゃないなら移動可能
	if (isHooking_ == false)
	{
		Vector3 move{ Vector3::Zero() };
		if (CheckHitKey(KEY_INPUT_W))
			move.y += 10.f;
		if (CheckHitKey(KEY_INPUT_S))
			move.y -= 10.f;
		if (CheckHitKey(KEY_INPUT_A))
			move.x -= 10.f;
		if (CheckHitKey(KEY_INPUT_D))
			move.x += 10.f;

		position += move;
	}

	// Eキーが押された瞬間グラッフリング開始
	if (Input::IsKeyDown(KeyCode::E))
	{
		hookTarget_ = FindGameObject<GiraffePoint>();
		assert(hookTarget_ != nullptr);  // ギラッフポイントは見つかる

		float distance{ position.Distance(hookTarget_->position) };

		if (distance >= NECK_LENGTH_MAX)
		{
			hookTarget_ = nullptr;
			printfDx("長すぎて届かない\n");
		}
		else
		{
			animationTimeMax_ =
				(HOOKING_ANIMATION_TIME_MAX
					- HOOKING_ANIMATION_OFFSET_IDOL_TIME
					- HOOKING_ANIMATION_OFFSET_TIME)
				* (distance / NECK_LENGTH_MAX)
				+ HOOKING_ANIMATION_OFFSET_IDOL_TIME
				+ HOOKING_ANIMATION_OFFSET_TIME;

			isHooking_ = true;
			MV1AttachAnim(hGiraffeMV1_, 0);
			animationTime_ = 0.f;

			transform_.LookAt({ 0.f, 1.f, 0.f }, hookTarget_->position);
		}
	}

	// Eキーが離された瞬間グラッフリング辞める
	if (Input::IsKeyUp(KeyCode::E))
	{
		isHooking_ = false;
		MV1DetachAnim(hGiraffeMV1_, 0);
		transform_.rotate = { 0.f, 0.f, 0.f };
		hookTarget_ = nullptr;
	}

	// グラッフリング中の処理
	if (isHooking_)
	{
		if (animationTime_ <= animationTimeMax_)
		{
			animationTime_ += Frame::GetDeltaTime() * HOOKING_ANIMATION_SPEED;
			if (animationTime_ > animationTimeMax_)
			{
				animationTime_ = animationTimeMax_;
			}
			MV1SetAttachAnimTime(hGiraffeMV1_, 0, animationTime_);
		}
	}


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

bool Play::Player::TryGetHookTargetPosition(Vector3& outPosition)
{
	if (hookTarget_ != nullptr)
	{
		outPosition = hookTarget_->position;
		return true;
	}
	else
	{
		return false;
	}
}

const float Play::Player::NECK_LENGTH_MAX{ 5000.f };
const float Play::Player::HOOKING_ANIMATION_TIME_MAX{ 249.f };
const float Play::Player::HOOKING_ANIMATION_SPEED{ 500.f };
const float Play::Player::HOOKING_ANIMATION_OFFSET_IDOL_TIME{ 8.f };
const float Play::Player::HOOKING_ANIMATION_OFFSET_TIME{ 8.f };
