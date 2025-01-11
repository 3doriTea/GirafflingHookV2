#include "PlayScene.h"
#include "MiniEngine.h"
#include "TitleScene.h"
#include <DxLib.h>
#include "Player.h"
#include "Camera.h"

namespace
{
}

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Init()
{
	AddGameObject<Player>();
	AddGameObject<Camera>();

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

}

void PlayScene::End()
{
}
