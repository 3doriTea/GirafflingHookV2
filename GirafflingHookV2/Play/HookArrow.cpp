#include "HookArrow.h"
#include "Screen.h"
#include "Input.h"
#include "GiraffePoint.h"
#include "GiraffePointRoot.h"
#include "Draw2D.h"
#include "Player.h"

Play::HookArrow::HookArrow() :
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
	foundGiraffePoint_{ nullptr }
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

	Vector3 worldPosition{ transform_.GetWorldPosition() };

	// MEMO: 視線ベクトルとグラッフポイントへのベクトルのコサイン類似度を計算し
	//     : 最も類似しているポイントを探す

	float maxCosineSimilarity{ -1.f };
	for (auto&& point : giraffePoints_)
	{
		float result
		{
			VDot(diff.Normalize(), (giraffePointRoot_->ToWorldPosition(point->position) - worldPosition).Normalize())
		};
		if (result > maxCosineSimilarity && result >= 0.f)
		{
			maxCosineSimilarity = result;
			foundGiraffePoint_ = point;
		}
	}
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
			DrawCircle(screenPosition.x, screenPosition.y, 30, 0xffff00, FALSE, 10);
		}
	}

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
