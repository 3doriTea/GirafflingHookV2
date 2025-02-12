#include "Debug.h"
#include <DxLib.h>
#include "Player.h"

Play::Debug::Debug() :
	GameObject
{
	GameObjectBuilder{}
		.LayerOrder(LayerOrderType::UI+1)
}
{
}

Play::Debug::~Debug()
{
}

void Play::Debug::Init()
{
	player_ = FindGameObject<Player>();
}

void Play::Debug::Update()
{
}

void Play::Debug::Draw() const
{
	DrawFormatString(0, 10, 0xffffff, "x = %f\ny = %f\nz = %f", player_->position.x, player_->position.y, player_->position.z);
}
