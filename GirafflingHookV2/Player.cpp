#include "Player.h"
#include <DxLib.h>
#include <cassert>

Player::Player() :
	GameObject::GameObject{ "Player", "player" },
	hGiraffeMV1_{ -1 }
{
}

Player::~Player()
{
}

void Player::Init()
{
	hGiraffeMV1_ = MV1LoadModel("Assets/cube001.mv1");
	assert(hGiraffeMV1_ != -1);

	VECTOR cameraPosition{ VGet(0, 200, -600) };

	MV1SetRotationXYZ(hGiraffeMV1_, VGet(0.f, 0.f, 0.f));
	MV1SetPosition(hGiraffeMV1_, playerPosition);

	ChangeLightTypeDir(VGet(1.f, -1.f, 0.5f));

	SetCameraPositionAndTarget_UpVecY(cameraPosition, playerPosition);
}

void Player::Update()
{
}

void Player::Draw() const
{
	MV1DrawModel(hGiraffeMV1_);
	DrawBox(0, 500, 0, 500, 0xff00ff, TRUE);
}

void Player::End()
{
	MV1DeleteModel(hGiraffeMV1_);
}
