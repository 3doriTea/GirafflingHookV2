#include "StageBoard.h"
#include "Screen.h"
#include "GiraffePointRoot.h"

namespace
{
	// モデルのサイズ調整率
	static float MODEL_SIZE_RATE{ 0.005f };
}

Play::StageBoard::StageBoard(
	const Vector2& topLeftDrawPosition,
	const Vector2& widthHeight,
	const float& angle) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("StageBoard")
			.Tag("stage-board")
			.Position(
				Vector3::From(
					Vector2{ topLeftDrawPosition.x, Screen::HEIGHT - topLeftDrawPosition.y }
					+ widthHeight / 2.f))
			.Rotate(Vector3::Forward() * angle)
			.Scale(Vector3::From(widthHeight, 1.f))
	},
	transform_{ *this },
	collider_{ *this, transform_ },
	hBoxModel_{ -1 }
{
	transform_.SetParent(GiraffePointRoot::GetGroundTransform());
}

Play::StageBoard::~StageBoard()
{
}

void Play::StageBoard::Init()
{
	hBoxModel_ = MV1DuplicateModel(GiraffePointRoot::GetBoxModelSourceHandle());

	MV1SetPosition(
		hBoxModel_,
		transform_.ToWorldPosition({ 0.f, 0.f, 0.f }));
	MV1SetRotationXYZ(hBoxModel_, transform_.GetRotateRadian());
	/*Vector3 scale{ transform_.GetWorldScale() * MODEL_SIZE_RATE };
	scale.z = 1.f;*/
	MV1SetScale(hBoxModel_, transform_.GetWorldScale() * MODEL_SIZE_RATE);
}

void Play::StageBoard::Update()
{
}

void Play::StageBoard::Draw() const
{
	MV1DrawModel(hBoxModel_);
	collider_.Draw();
}

void Play::StageBoard::End()
{
	MV1DeleteModel(hBoxModel_);
}
