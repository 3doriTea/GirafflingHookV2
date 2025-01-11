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
	SetCameraPositionAndTarget_UpVecY(position, player_->position);
}
