#include "Player.h"
#include <DxLib.h>
#include <cassert>
#include <cmath>
#include "Draw3D.h"
#include "GiraffePoint.h"
#include "HookArrow.h"
#include "Frame.h"
#include "EasingFunctions.h"
#include "../PlayScene.h"

namespace
{
	const float PI{ std::acosf(-1.f) };
}

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
	rigidbody_{ *this, transform_, &collider_, true },
	animationTime_{ 0.f },
	animationTimeMax_{ 0.f },
	hGiraffeMV1_{ -1 },
	hTextureImage_{ -1 },
	hookTarget_{ nullptr },
	hookArrow_{ nullptr },
	hookDistance_{ 0.f },
	state_{ State::Defualt },
	move_{ Vector3::Zero() },
	moveSign_{ +1 },
	isGoalling_{ false },
	goallingTimeLeft_{ 0.f },
	GOALLING_TIME_MAX{ 3.f }
{
}

Play::Player::~Player()
{
}

void Play::Player::Init()
{
	hookArrow_ = FindGameObject<HookArrow>();
	assert(hookArrow_ != nullptr);  // HookArrowは見つかる

	hGiraffeMV1_ = MV1LoadModel("Assets/Play/giraffeee.mv1");
	hTextureImage_ = LoadGraph("Assets/Play/cube001.png");
	MV1SetTextureGraphHandle(hGiraffeMV1_, 0, hTextureImage_, FALSE);
	assert(hGiraffeMV1_ != -1);

	rigidbody_.resistance = 0.1f;
	rigidbody_.resistanceTorque = 1.f;
	rigidbody_.gravity = 9.8f;
	rigidbody_.fixedZ = true;
}

void Play::Player::Update()
{
	if (isGoalling_)
	{
		// ゴールしているなら
		MoveGoalling();
	}
	else
	{
		// ゴールしていない

		/*rotate.y += Frame::GetDeltaTime() * 1000.f;
		rotate.y = std::fmodf(rotate.y, 360.f);*/

		// キー入力から移動方向を更新
		UpdateMove();

		// Eキーが押された瞬間グラッフリング開始
		if (Input::IsKeyDown(KeyCode::LeftShift))
		{
			StartHooking();
		}

		// Eキーが離された瞬間グラッフリング辞める
		if (Input::IsKeyUp(KeyCode::LeftShift))
		{
			FinishHooking();
		}

		// 各状態の処理
		switch (state_)
		{
		case State::Defualt:
			MoveDefault();  // 通常の移動
			break;
		case State::Shooting:
			Shooting();     // グラッフ発射中
			break;
		case State::Hooking:
			MoveHooking();  // グラッフリング中
			break;
		default:
			throw "範囲外の列挙子";
		}
	}

	DxLib::MV1SetRotationXYZ(hGiraffeMV1_, transform_.GetRotateRadian());
	DxLib::MV1SetPosition(hGiraffeMV1_, position);
	DxLib::MV1SetScale(hGiraffeMV1_, scale * 0.002f);
}

void Play::Player::StartGoalAnimation(const Vector3& goalPosition)
{
	smootingBeginPosition_ = position;
	smootingDiff_ = goalPosition - smootingBeginPosition_;
	isGoalling_ = true;
}

void Play::Player::UpdateMove()
{
	move_ = Vector3::Zero();
	if (CheckHitKey(KEY_INPUT_W))
		move_.y += MOVE_FORCE;
	if (CheckHitKey(KEY_INPUT_S))
		move_.y -= MOVE_FORCE;
	if (CheckHitKey(KEY_INPUT_A))
		move_.x -= MOVE_FORCE;
	if (CheckHitKey(KEY_INPUT_D))
		move_.x += MOVE_FORCE;
}

void Play::Player::StartHooking()
{
	hookTarget_ = hookArrow_->GetFoundGiraffePoint();  //FindGameObject<GiraffePoint>();
	assert(hookTarget_ != nullptr); // ギラッフポイントは見つかる
	Vector3 hookPosition{ hookTarget_->GetHookPosition() };

	hookDistance_ = position.Distance(hookPosition);

	if (hookDistance_ >= NECK_LENGTH_MAX)
	{
		hookTarget_ = nullptr;
		printfDx("長すぎて届かない\n");
	}
	else
	{
		MV1AttachAnim(hGiraffeMV1_, 0);
		animationTime_ = 0.f;
		rigidbody_.velocityTorque = Vector3::Zero();
		if (position.y < hookPosition.y)
		{
			moveSign_ = 1.f;
		}
		else
		{
			moveSign_ = -1.f;
		}

		state_ = State::Shooting;
	}
}

void Play::Player::FinishHooking()
{
	MV1DetachAnim(hGiraffeMV1_, 0);
	transform_.rotate = { 0.f, 0.f, 0.f };
	hookTarget_ = nullptr;
	hookDistance_ = 0.f;
	if (move_.x < 0.f)
	{
		rigidbody_.velocityTorque.z += 3600.f;
	}
	else
	{
		rigidbody_.velocityTorque.z -= 3600.f;
	}

	state_ = State::Defualt;
}

float Play::Player::LengthToAnimationTime(float length)
{
	return (HOOKING_ANIMATION_TIME_MAX
		- HOOKING_ANIMATION_OFFSET_IDOL_TIME
		- HOOKING_ANIMATION_OFFSET_TIME)
		* (length / NECK_LENGTH_MAX)
		+ HOOKING_ANIMATION_OFFSET_IDOL_TIME
		+ HOOKING_ANIMATION_OFFSET_TIME;
}

void Play::Player::MoveDefault()
{
	rigidbody_.velocity += move_ * MOVE_SPEED;
}

void Play::Player::Shooting()
{
	Vector3 hookPosition{ hookTarget_->GetHookPosition() };

#pragma region 発射中も絶えずターゲットに向けて調整
	transform_.LookAt({ 0.f, 1.f, 0.f }, hookPosition);
	
	hookDistance_ = position.Distance(hookPosition);
	
	animationTimeMax_ = LengthToAnimationTime(hookDistance_);
#pragma endregion

	if (animationTime_ <= animationTimeMax_)
	{
		animationTime_ += Frame::GetDeltaTime() * HOOKING_ANIMATION_SPEED;
		// アニメーション終了したらグラッフリングできる状態に
		if (animationTime_ > animationTimeMax_)
		{
			animationTime_ = animationTimeMax_;
			state_ = State::Hooking;
		}
		MV1SetAttachAnimTime(hGiraffeMV1_, 0, animationTime_);
	}
}

void Play::Player::MoveHooking()
{
	assert(hookTarget_ != nullptr);  // ターゲットはある
	Vector3 hookPosition{ hookTarget_->GetHookPosition() };

	Vector3 angles{ transform_.GetRotateRadian() };

	float currentDistance{ position.Distance(hookPosition) };

#pragma region 向心力の適用
	// 2次元上の円の接線から中心への垂線
	Vector3 perpendicular
	{
		-std::sinf(angles.z),
		std::cosf(angles.z),
		0.f
	};

	// グラッフリングのズレ
	float diffDistance
	{
		currentDistance - hookDistance_
	};

	rigidbody_.velocity += perpendicular * diffDistance;
#pragma endregion

#pragma region 接線方向の速度適用
	// 2次元上の円の接線
	Vector3 direction
	{
		-std::sinf(angles.z - PI / 2.f),
		std::cosf(angles.z - PI / 2.f),
		0.f
	};
	rigidbody_.velocity += direction * move_.x * moveSign_;
#pragma endregion

	animationTime_ = LengthToAnimationTime(currentDistance);

	MV1SetAttachAnimTime(hGiraffeMV1_, 0, animationTime_);

	transform_.LookAt({ 0.f, 1.f, 0.f }, hookPosition);
}

void Play::Player::MoveGoalling()
{
	if (goallingTimeLeft_ == GOALLING_TIME_MAX)
	{
		return;
	}

	goallingTimeLeft_ += Frame::GetDeltaTime();

	if (goallingTimeLeft_ >= GOALLING_TIME_MAX)
	{
		goallingTimeLeft_ = GOALLING_TIME_MAX;
		GetGameScene<PlayScene>().FinishedGoalAnimation();
	}

	float rate{ goallingTimeLeft_ / GOALLING_TIME_MAX };
	position = smootingBeginPosition_ + smootingDiff_ * Ease::InOutExpo(rate);
}

void Play::Player::Draw() const
{
	MV1DrawModel(hGiraffeMV1_);
	collider_.Draw();
}

void Play::Player::End()
{
	MV1DeleteModel(hGiraffeMV1_);
	DeleteGraph(hTextureImage_);
}

bool Play::Player::TryGetHookTargetPosition(Vector3& outPosition)
{
	if (hookTarget_ != nullptr)
	{
		outPosition = hookTarget_->GetHookPosition();
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

const float Play::Player::MOVE_SPEED{ 1.f };

const float Play::Player::MOVE_FORCE{ 50.f };
