#include "PlayScene.h"
#include "MiniEngine.h"
#include "TitleScene.h"
#include <DxLib.h>
#include "Play/Player.h"
#include "Play/Camera.h"
#include "Play/Ground.h"
#include "Play/GiraffePoint.h"
#include "Play/Goal.h"

using namespace Play;

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Init()
{
	SetBackgroundColor(0x00, 0x00, 0x00);

	AddGameObject<Player>();
	AddGameObject<Camera>();
	AddGameObject<Ground>();
	AddGameObject<GiraffePoint>(Vector3{ 0.f, 0.f, 0.f });
	AddGameObject<Goal>();

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
