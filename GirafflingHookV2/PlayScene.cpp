#include "PlayScene.h"
#include "MiniEngine.h"
#include "TitleScene.h"
#include <DxLib.h>
#include "Play/Player.h"
#include "Play/Camera.h"
#include "Play/Ground.h"

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
