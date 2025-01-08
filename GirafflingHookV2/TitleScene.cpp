#include "TitleScene.h"
#include "CarGameEngine.h"
#include "PlayScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	if (Input::IsKey(DIK_H))
	{
		printfDx("タイトルシーン%f\n", Frame::GetDeltaTime());
	}
	
	if (CheckHitKey(KEY_INPUT_P))
	{
		SceneManager::Move<PlayScene>();
	}

	/*if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager::Move<PlayScene>();
	}*/
}

void TitleScene::Draw() const
{
}

void TitleScene::End()
{
}
