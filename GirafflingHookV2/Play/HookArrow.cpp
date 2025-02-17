#include "HookArrow.h"
#include "Screen.h"
#include "Input.h"
#include "GiraffePoint.h"
#include "GiraffePointRoot.h"
#include "Draw2D.h"
#include "Player.h"
#include <cassert>
#include "../GirafflingHook.h"

namespace
{
	const float PI{ std::acosf(-1.f) };
}

Play::HookArrow::HookArrow() :
	GameObject
	{
		GameObjectBuilder{}
			.LayerOrder(LayerOrderType::UI)
	},
	transform_{ *this },
	SCREEN_CENTER
	{
		Vector2
		{
			static_cast<float>(Screen::WIDTH),
			static_cast<float>(Screen::HEIGHT)
		} / 2.f
	},
	giraffePoints_{},
	giraffePointRoot_{ nullptr },
	foundGiraffePoint_{ nullptr },
	animationTimer_{ 0.f },
	hArrowImage_{ -1 },
	hExtendImage_{ -1 },
	hShrinkImage_{ -1 },
	arrowImageCenter_{},
	arrowAngle_{ 0.0f },
	arrowForce_{ 0.0f },
	player_{ nullptr },
	diff_{}
{
}

Play::HookArrow::~HookArrow()
{
}

void Play::HookArrow::Init()
{
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // プレイヤーは見つかる

	transform_.SetParent(
		FindGameObject<Player>()->GetTransform());

	giraffePointRoot_ =
		FindGameObject<GiraffePointRoot>()
		->GetGroundTransform();

	hArrowImage_ = LoadGraph("Assets/Play/arrow.png");
	assert(hArrowImage_ > 0);  // 矢印の画像を読み込む
	hExtendImage_ = LoadGraph("Assets/Play/extend.png");
	assert(hExtendImage_ > 0);  // 伸びの画像を読み込む
	hShrinkImage_ = LoadGraph("Assets/Play/shrink.png");
	assert(hShrinkImage_ > 0);  // 縮みの画像を読み込む

	GetGraphSizeF(hArrowImage_, &arrowImageCenter_.x, &arrowImageCenter_.y);
	arrowImageCenter_ /= 2.0f;
}

void Play::HookArrow::Update()
{
	if (GirafflingHook::GetPlayStyle() == PlayStyle::KeyBoardAndMouse)
	{
		int mouseX{}, mouseY{};
		GetMousePoint(&mouseX, &mouseY);

		mouseY = Screen::HEIGHT - mouseY;

		Vector2 mousePosition
		{
			static_cast<float>(mouseX),
			static_cast<float>(mouseY)
		};

		diff_ = Vector3::From(mousePosition - SCREEN_CENTER);

		Draw2D::Vector(diff_, 0xff00ff);

	}
	else if (GirafflingHook::GetPlayStyle() == PlayStyle::GamePad)
	{
		Vector3 stickR{ Vector3::From(Input::GetPadStickR()) };
		
		if (player_->GetState() == Player::State::Defualt)
		{
			float stickMagnitude{ stickR.Length() };
			if (stickMagnitude > 0.3f)
			{
				arrowForce_ = stickMagnitude;
				diff_ = stickR;
			}
			else
			{
				arrowForce_ = 0.3f;
			}
			extendShrinkForce_ = 0.0f;
		}
		else
		{
			extendShrinkForce_ = stickR.y;
			arrowForce_ = 0.0f;
		}
	}

	arrowAngle_ = std::atan2f(diff_.x, diff_.y);

	Vector3 worldPosition{ transform_.GetWorldPosition() };

	// MEMO: 視線ベクトルとグラッフポイントへのベクトルのコサイン類似度を計算し
	//     : 最も類似しているポイントを探す

	float maxCosineSimilarity{ -1.f };
	for (auto&& point : giraffePoints_)
	{
		Vector3 pointWorldPoint{ giraffePointRoot_->ToWorldPosition(point->position) };
		if (Vector3::Distance(pointWorldPoint, worldPosition) >= 2000.f)
		{
			continue;
		}

		float result
		{
			VDot(Vector3::Normalize(diff_), (pointWorldPoint - worldPosition).Normalize())
		};
		if (result > maxCosineSimilarity && result >= 0.f)
		{
			maxCosineSimilarity = result;
			foundGiraffePoint_ = point;
		}
	}

	animationTimer_ += Frame::GetDeltaTime() * 10.f;
	animationTimer_ = std::fmodf(animationTimer_, PI * 2.f);
}

void Play::HookArrow::Draw() const
{
	if (foundGiraffePoint_ != nullptr)
	{
		Vector3 screenPosition
		{
			Vector3::From(ConvWorldPosToScreenPos(foundGiraffePoint_->GetHookPosition()))
		};
		if (0.f <= screenPosition.z && screenPosition.z <= 1.f)
		{
			DrawCircle(
				screenPosition.x,
				screenPosition.y,
				// TODO: 円のアニメーションを付ける
				static_cast<int>(40.f + std::sinf(animationTimer_) * 10.f),
				0xffff00,
				FALSE,
				10);
		}
	}

	int cx{ static_cast<int>(arrowImageCenter_.x) };
	int cy{ static_cast<int>(arrowImageCenter_.y) };
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0f * arrowForce_));
	DrawRotaGraph2(
		Screen::WIDTH / 2, Screen::HEIGHT / 2,
		cx * 2.0f, cy,
		1.0f, PI / 2.0f + arrowAngle_,
		hArrowImage_, TRUE);

	int image{ -1 };
	if (extendShrinkForce_ < 0.0f)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0f * -extendShrinkForce_));
		image = hShrinkImage_;
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(255.0f * extendShrinkForce_));
		image = hExtendImage_;
	}
	DrawRotaGraph2(
		Screen::WIDTH / 2, Screen::HEIGHT / 2,
		cx, cy,
		1.0f, PI / 2.0f + (PI * 2.0f - player_->GetTransform()->GetRotateRadian().z),
		image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Play::HookArrow::End()
{
}

void Play::HookArrow::RegisterGiraffePoint(GiraffePoint* ptr)
{
	giraffePoints_.insert(ptr);
}

void Play::HookArrow::UnregisterGiraffePoint(GiraffePoint* ptr)
{
	giraffePoints_.erase(ptr);
}
