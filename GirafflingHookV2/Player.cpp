#include "Player.h"
#include <DxLib.h>

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
}

void Player::Update()
{
	VECTOR cameraPosition{ VGet(0, 0, -600) };
	VECTOR playerPosition{ VGet(0, 0, 10.f) };
	
	MV1SetRotationXYZ(hGiraffeMV1_, VGet(0.f, 0.f, 0.f));
	MV1SetPosition(hGiraffeMV1_, playerPosition);

	ChangeLightTypeDir(VGet(1.f, -1.f, .5f));


	SetCameraPositionAndTarget_UpVecY(cameraPosition, playerPosition);
}

void Player::Draw() const
{
	MV1DrawModel(hGiraffeMV1_);
}

void Player::End()
{
}
