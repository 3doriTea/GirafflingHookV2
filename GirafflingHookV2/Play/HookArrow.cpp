#include "HookArrow.h"
#include "Screen.h"
#include "Input.h"
#include "GiraffePoint.h"
#include "GiraffePointRoot.h"
#include "Draw2D.h"
#include "Player.h"
#include <cassert>

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
	arrowImageCenter_{},
	arrowAngle_{ 0.0f }
{
}

Play::HookArrow::~HookArrow()
{
}

void Play::HookArrow::Init()
{
	transform_.SetParent(
		FindGameObject<Player>()->GetTransform());

	giraffePointRoot_ =
		FindGameObject<GiraffePointRoot>()
		->GetGroundTransform();

	hArrowImage_ = LoadGraph("Assets/Play/arrow.png");
	assert(hArrowImage_ > 0);

	GetGraphSizeF(hArrowImage_, &arrowImageCenter_.x, &arrowImageCenter_.y);
	arrowImageCenter_ /= 2.0f;
}

void Play::HookArrow::Update()
{
	int mouseX{}, mouseY{};
	GetMousePoint(&mouseX, &mouseY);

	mouseY = Screen::HEIGHT - mouseY;

	Vector2 mousePosition
	{
		static_cast<float>(mouseX),
		static_cast<float>(mouseY)
	};

	Vector3 diff
	{
		Vector3::From(mousePosition - SCREEN_CENTER)
	};

	Draw2D::Vector(diff, 0xff00ff);

	arrowAngle_ = std::atan2f(diff.x, diff.y);

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
			VDot(diff.Normalize(), (pointWorldPoint - worldPosition).Normalize())
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
	DrawRotaGraph2(
		Screen::WIDTH / 2, Screen::HEIGHT / 2,
		cx * 2.0f, cy,
		1.0f, PI / 2.0f + arrowAngle_,
		hArrowImage_, TRUE);
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
