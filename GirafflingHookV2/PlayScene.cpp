#include "PlayScene.h"
#include "CarGameEngine.h"
#include "TitleScene.h"
#include <DxLib.h>
#include "Player.h"

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
