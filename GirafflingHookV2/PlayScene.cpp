#include "PlayScene.h"
#include "MiniEngine.h"
#include "TitleScene.h"
#include <DxLib.h>
#include "Play/Player.h"
#include "Play/Camera.h"
#include "Play/Ground.h"
#include "Play/Goal.h"
#include "Play/GroundCollider.h"
#include "Play/GiraffePointRoot.h"
#include "Play/HookArrow.h"

using namespace Play;

PlayScene::PlayScene() :
	player_{ nullptr }
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Init()
{
	SetBackgroundColor(0x00, 0x00, 0x00);

	AddGameObject<Player>();
	AddGameObject<HookArrow>();
	AddGameObject<Camera>();
	AddGameObject<Ground>();
	AddGameObject<Goal>();
	AddGameObject<GiraffePointRoot>(2.f);

#pragma region 地面のコライダー
	AddGameObject<GroundCollider>(
		Vector3{ 0.f, -400.f, 0.f },
		Vector3{ 0.f, 0.f, 0.f },
		Vector3{ 200.f, 200.f, 200.f });
#pragma endregion

	player_ = FindGameObject<Player>();

	ChangeLightTypeDir(VGet(1.f, -1.f, 0.5f));
}

void PlayScene::Update()
{
	if (Input::IsKey(DIK_H))
	{
		printfDx("プレイシーン%f\n", Frame::GetDeltaTime());
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager::Move<TitleScene>();
	}
}

void PlayScene::Draw() const
{
	DrawFormatString(0, 10, 0xffffff, "x = %f\ny = %f\nz = %f", player_->position.x, player_->position.y, player_->position.z);
}

void PlayScene::End()
{
}
