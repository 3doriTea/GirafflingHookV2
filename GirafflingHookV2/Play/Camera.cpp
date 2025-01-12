#include "Camera.h"
#include "Player.h"
#include <cassert>
#include <cmath>

Play::Camera::Camera() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("MainCamera")
			.Position({ 0.f, 200.f, -600.f })
	},
	cameraMoveRate{ 1.01f },
	cameraDistance{ 501.f },  // MEMO: 距離が広がるほど上から目線になる
	cameraDistanceZ{ -500.f },
	player_{ nullptr },
	transform_{ *this }
{
	// NOTE: cameraDistanceはcameraDistanceZより大きい必要がある
	assert(cameraDistance > std::fabsf(cameraDistanceZ));
}

Play::Camera::~Camera()
{
}

void Play::Camera::Init()
{
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // NOTE: プレイヤーは見つかる
}

void Play::Camera::Update()
{
	/*Vector3 move{ Vector3::Zero() };
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

	position = transform_.ToWorldPosition(move);*/

	// MEMO: 円の公式 x^2 + y^2 = r^2 により
	//     : y = +-root(r^2 - x^2) になるため、
	//     : z=100のときのy座標を求められる！！

	float diffX = player_->position.x - position.x;
	diffX /= cameraMoveRate;

	transform_.position = Vector3
	{
		diffX * Frame::GetDeltaTime() + position.x,
		std::sqrtf(cameraDistance * cameraDistance - cameraDistanceZ * cameraDistanceZ) + player_->position.y,
		cameraDistanceZ
	};

	transform_.LookAt({ 0.f, 0.f, 1.f }, player_->position);

	/*Vector3 rotation{ Vector3::Zero() };
	if (CheckHitKey(KEY_INPUT_LEFT))
		rotation.y -= Frame::GetDeltaTime() * 100.f;
	if (CheckHitKey(KEY_INPUT_RIGHT))
		rotation.y += Frame::GetDeltaTime() * 100.f;
	if (CheckHitKey(KEY_INPUT_UP))
		rotation.x -= Frame::GetDeltaTime() * 100.f;
	if (CheckHitKey(KEY_INPUT_DOWN))
		rotation.x += Frame::GetDeltaTime() * 100.f;

	rotate += rotation;*/

	Vector3 angles{ transform_.GetRotateRadian() };
	SetCameraPositionAndAngle(position, angles.x, angles.y, angles.z);

	//SetCameraPositionAndTarget_UpVecY(position, player_->position);

}
