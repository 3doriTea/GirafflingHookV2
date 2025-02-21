#include "ClearScene.h"
#include "MiniEngine.h"
#include <DxLib.h>
#include "TitleScene.h"
#include "PlayScene.h"
#include <cassert>
#include "Screen.h"
#include "../Clear/ClearString.h"
#include "../Clear/ClearCamera.h"

using namespace Clear;

ClearScene::ClearScene() :
	    totalScore_{0},
	     clearTime_{0},
	girafferingNum_{0}
{

}

ClearScene::~ClearScene()
{

}

void ClearScene::Init()
{
	ClearString& clearString{ AddGameObject<ClearString>() };
	ClearCamera& clearCamera{ AddGameObject<ClearCamera>() };
	Vector3 direction{ clearCamera.position - clearString.position };

	CreateDirLightHandle(direction);
	CreateDirLightHandle(direction);
	CreateDirLightHandle(direction);

	SetGlobalAmbientLight(GetColorF(255, 255, 255, 255));
}

void ClearScene::Update()
{
	if (Input::IsKeyDown(KeyCode::Space))
	{
		SceneManager::Move<TitleScene>();
	}
}

void ClearScene::Draw() const
{
	/*
	* スコア
	* プレイヤー
	* 文字列
	*/
	/*
#pragma region Temp Code
	DrawString(100, 50, "All Things Become GIRAFFA", 0x000000);
	DrawString(100, 100, "SCORE : 0xf09c1a", 0x000000);
	DrawString(100, 150, "ClearTime : ", 0x000000);
	DrawString(100, 300, "GirafferingNum : ", 0x000000);
	DrawString(100, 500, "Next", 0x000000);
#pragma endregion 仮レイアウト確認
	*/
}

void ClearScene::End()
{
	totalScore_ = 0;
	clearTime_ = 0;
	girafferingNum_ = 0;
}

void ClearScene::SetTotalScore_(int)
{
}

void ClearScene::SetClearTime_(int)
{
}

void ClearScene::SetGirafferingNum_(int)
{
}
