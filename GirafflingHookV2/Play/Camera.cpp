#include "Camera.h"
#include "Player.h"
#include <cassert>
#include <cmath>

namespace
{
	const float PI{ std::acosf(-1.f) };
}

Play::Camera::Camera() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("MainCamera")
			.Position({ 0.f, 200.f, -2000.f })
	},
	cameraMoveRate{ 1.01f },
	cameraDistance{ 2000.f },  // MEMO: 距離が広がるほど上から目線になる
	cameraDistanceZ{ -2000.f },
	hSoptLight_{ -1 },
	player_{ nullptr },
	transform_{ *this }
{
	// NOTE: cameraDistanceは cameraDistanceZより大きい必要がある
	//assert(cameraDistance > std::fabsf(cameraDistanceZ));
}

Play::Camera::~Camera()
{
}

void Play::Camera::Init()
{
	//hSoptLight_ = CreateSpotLightHandle(
	//	position,
	//	transform_.GetRotateRadian(),
	//	PI / 1.f,
	//	0.f,//PI / 5.f,
	//	5000.f,
	//	0.f, 0.0001f, 0.f);


	VECTOR dirLightDir =
	{
		100 * PI / 180,
		75 * PI / 180,
		0
	};
	hDirLight_ = CreateDirLightHandle(dirLightDir);

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

	Vector3 targetPosition{};
	//Vector3 
	float cameraFOV{ 60.0f * PI / 180.0f };

	switch (player_->GetState())
	{
	case Player::State::Hooking:
		player_->TryGetHookTargetPosition(targetPosition);
		targetPosition = (targetPosition - player_->position) / 2.0f + player_->position;
		cameraFOV = float
		{
			std::atan2f(Vector3::Distance(targetPosition, player_->position) * 4.0f, cameraDistance)
		};
		break;
	case Player::State::Defualt:
	default:
		targetPosition = player_->position;
		break;
	}

	SetupCamera_Perspective(cameraFOV);

	float diffX = targetPosition.x - position.x;
	diffX /= cameraMoveRate;

	/*transform_.position = Vector3
	{
		diffX * Frame::GetDeltaTime() + position.x,
		std::sqrtf(cameraDistance * cameraDistance - cameraDistanceZ * cameraDistanceZ) + player_->position.y,
		cameraDistanceZ
	};*/

	transform_.position = Vector3
	{
		targetPosition.x,
		targetPosition.y,
		targetPosition.z + cameraDistanceZ
	};

	transform_.LookAt({ 0.f, 0.f, 1.f }, targetPosition);

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

	SetLightPositionHandle(hSoptLight_, position);
	SetLightDirectionHandle(hSoptLight_, angles);

	//SetCameraPositionAndTarget_UpVecY(position, player_->position);

}

void Play::Camera::End()
{
	DeleteLightHandle(hSoptLight_);
	DeleteLightHandle(hDirLight_);
}
