#include "TitleScene.h"
#include "MiniEngine.h"
#include "PlayScene.h"
#include <DxLib.h>
#include "Screen.h"
#include "Title/TitleString.h"
#include "Title/TitleCamera.h"
#include "Title/SelectButton.h"

using namespace Title;

TitleScene::TitleScene() :
	hPointLight_{ -1 },
	hDirectional_{ -1 }
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	SetBackgroundColor(0xf0, 0xf0, 0xf0);

	TitleString& titleString{ AddGameObject<TitleString>() };
	TitleCamera& titleCamera{ AddGameObject<TitleCamera>() };
	
	//ChangeLightTypeDir(VGet(1.f, -1.f, 0.5f));

	/*hPointLight_ = CreatePointLightHandle(
		{ 100.f, 140.f, -500.f },
		2000.f,
		0.f, 0.0001f, 0.f);*/

	Vector3 direction{ titleCamera.position - titleString.position };

	hDirectional_ = CreateDirLightHandle(direction);
	hDirectional_ = CreateDirLightHandle(direction);
	hDirectional_ = CreateDirLightHandle(direction);

	AddGameObject<SelectButton>(
		"playbutton", Vector3{ -400.f, 0.f, 0.f });

	AddGameObject<SelectButton>(
		"infobutton", Vector3{ -400.f, -100.f, 0.f });

	AddGameObject<SelectButton>(
		"quitbutton", Vector3{ -400.f, -200.f, 0.f });
}

void TitleScene::Update()
{
	if (Input::IsKey(KeyCode::Space))
	{
		printfDx("タイトルシーン%f\n", Frame::GetDeltaTime());
	}

	if (Input::IsKeyDown(KeyCode::J))
	{
		printfDx("テステスDown%f\n", Frame::GetDeltaTime());
	}
	if (Input::IsKeyUp(KeyCode::J))
	{
		printfDx("テステスUp%f\n", Frame::GetDeltaTime());
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

void TitleScene::Draw() const // この関数の中ではメンバ変数を一切書き換えることはない
{
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
	int defaultFontSize = GetFontSize();
	SetFontSize(100);
	int titleStrHead = (Screen::WIDTH - GetDrawStringWidth(titleElement[TITLE_TEXT], -1)) / 2;
	DrawString(titleStrHead, 100, titleElement[TITLE_TEXT], 0xffffff, 0x00ffff);
	SetFontSize(70);
	DrawString(titleStrHead, 345, titleElement[PLAY_BUTTON], 0xffffff);
	DrawString(titleStrHead, 445, titleElement[INFO_BUTTON], 0xffffff);
	DrawString(titleStrHead, 545, titleElement[QUIT_BUTTON], 0xffffff);
	SetFontSize(defaultFontSize);
	ChangeFontType(DX_FONTTYPE_NORMAL);

	MV1DrawModel(hPlayButtonModel_);
	MV1DrawModel(hInfoButtonModel_);
	MV1DrawModel(hQuitButtonModel_);
}

void TitleScene::End()
{
	DeleteLightHandleAll();
	/*DeleteLightHandle(hPointLight_);
	DeleteLightHandle(hDirectional_);*/

	MV1DeleteModel(hPlayButtonModel_);
	MV1DeleteModel(hInfoButtonModel_);
	MV1DeleteModel(hQuitButtonModel_);
}
