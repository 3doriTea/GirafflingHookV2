#include "Camera.h"
#include "Player.h"
#include <cassert>

Camera::Camera() :
	player_{ nullptr }
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // NOTE: ƒvƒŒƒCƒ„[‚ÍŒ©‚Â‚©‚é

	position = { 0, 200, -600 };
}

void Camera::Update()
{
	if (CheckHitKey(KEY_INPUT_Q))
		position.y -= 10.f;
	if (CheckHitKey(KEY_INPUT_E))
		position.y += 10.f;
	if (CheckHitKey(KEY_INPUT_W))
		position.z += 10.f;
	if (CheckHitKey(KEY_INPUT_A))
		position.x -= 10.f;
	if (CheckHitKey(KEY_INPUT_S))
		position.z -= 10.f;
	if (CheckHitKey(KEY_INPUT_D))
		position.x += 10.f;

	SetCameraPositionAndTarget_UpVecY(position, player_->position);
}
