#include "ScoreObject.h"
#include <DxLib.h>
#include "Player.h"
#include <cassert>
#include "../PlayScene.h"
#include "GiraffePointRoot.h"

namespace
{
	static const float GET_DISTANCE{ 300.f };  // 半径3m
}

Play::ScoreObject::ScoreObject(
	const std::string& name,
	const Vector3& position) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name(name)
			.Position(position)
			.Scale({ 100.f, 100.f, 100.f })
	},
	hAppleModel_{ -1 },
	player_{ nullptr },
	transform_{ *this }
{
	transform_.SetParent(GiraffePointRoot::GetGroundTransform());
}

Play::ScoreObject::~ScoreObject()
{
}

void Play::ScoreObject::Init()
{
	hAppleModel_ = MV1DuplicateModel(GiraffePointRoot::GethAppleModelSourceHandle());
	assert(hAppleModel_ != -1);  // モデルのデュプリケートはできる
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // プレイヤーは見つかる
}

void Play::ScoreObject::Update()
{
	if (Vector3::Distance(position, player_->position) < GET_DISTANCE)
	{
		GetGameScene<PlayScene>().AddScore(10);
		Destroy();
	}
}

void Play::ScoreObject::Draw() const
{
}

void Play::ScoreObject::End()
{
	DeleteGraph(hAppleModel_);
}
