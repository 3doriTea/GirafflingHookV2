#include "Camera.h"
#include "Player.h"
#include <cassert>

Camera::Camera() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("MainCamera")
			.Position({ 0.f, 200.f, -600.f })
	},
	player_{ nullptr },
	transform_{ *this }
{
}

Camera::~Camera()
{
}

void Camera::Init()
{
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // NOTE: ƒvƒŒƒCƒ„[‚ÍŒ©‚Â‚©‚é
}

void Camera::Update()
{
	Vector3 move{ Vector3::Zero() };
	if (CheckHitKey(KEY_INPUT_Q))
		move.y -= 10.f;
	if (CheckHitKey(KEY_INPUT_E))
		move.y += 10.f;
	if (CheckHitKey(KEY_INPUT_W))
		move.z += 10.f;
	if (CheckHitKey(KEY_INPUT_A))
		move.x -= 10.f;
	if (CheckHitKey(KEY_INPUT_S))
		move.z -= 10.f;
	if (CheckHitKey(KEY_INPUT_D))
		move.x += 10.f;

	position = transform_.ToWorldPosition(move);

	//transform_.LookAt({ 0.f, 0.f, 1.f }, player_->position);

	Vector3 rotation{ Vector3::Zero() };
	if (CheckHitKey(KEY_INPUT_LEFT))
		rotation.y -= Frame::GetDeltaTime() * 100.f;
	if (CheckHitKey(KEY_INPUT_RIGHT))
		rotation.y += Frame::GetDeltaTime() * 100.f;
	if (CheckHitKey(KEY_INPUT_UP))
		rotation.x -= Frame::GetDeltaTime() * 100.f;
	if (CheckHitKey(KEY_INPUT_DOWN))
		rotation.x += Frame::GetDeltaTime() * 100.f;

	rotate += rotation;

	Vector3 angles{ transform_.GetRotateRadian() };
	SetCameraPositionAndAngle(position, angles.x, angles.y, angles.z);

	//SetCameraPositionAndTarget_UpVecY(position, player_->position);

}
