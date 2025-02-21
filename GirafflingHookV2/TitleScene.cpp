#include "TitleScene.h"
#include "MiniEngine.h"
#include "PlayScene.h"
#include "InfoScene.h"
#include <DxLib.h>
#include <cassert>
#include "Screen.h"
#include "Title/TitleString.h"
#include "Title/TitleCamera.h"
#include "Title/SelectButton.h"
#include <imgui.h>
#include "ClearScene.h"
#include "TestScene.h"
#include "GirafflingHook.h"
#include "Sound.h"

using namespace Title;

static int y{ 0 };

TitleScene::TitleScene() :
	hPointLight_{ -1 },
	hDirectional_{ -1 },
	selectButtons{},
	selectionButton{ 0 },
	hGiraffeImageBody_{ -1 },
	hGiraffeImageHead_{ -1 }
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	Sound::Load(AudioInfo{}
		.File("Assets/BGM/Blackmoor Colossus.mp3")
		.Name("title-bgm"));
	
	Sound::PlayBGM("title-bgm");
	Sound::SetVolumeBGM(100);

	hGiraffeImageBody_ = LoadGraph("Assets/Title/giraffeBody.png");
	assert(hGiraffeImageBody_ > 0);  // 画像は読み込まれる！
	hGiraffeImageHead_ = LoadGraph("Assets/Title/giraffeHead.png");
	assert(hGiraffeImageHead_ > 0);  // 画像は読み込まれる！

	SetBackgroundColor(0xf0, 0xf0, 0xf0);

	TitleString& titleString{ AddGameObject<TitleString>() };
	TitleCamera& titleCamera{ AddGameObject<TitleCamera>() };

	Vector3 direction{ titleCamera.position - titleString.position };

	CreateDirLightHandle(direction);
	CreateDirLightHandle(direction);
	CreateDirLightHandle(direction);

	selectButtons.push_back(
		&AddGameObject<SelectButton>(
			"playbutton", Vector3{ -400.f, 0.f, 0.f }));

	selectButtons.push_back(
		&AddGameObject<SelectButton>(
			"infobutton", Vector3{ -400.f, -100.f, 0.f }));

	selectButtons.push_back(
		&AddGameObject<SelectButton>(
			"quitbutton", Vector3{ -400.f, -200.f, 0.f }));
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(KeyCode::Up))
	{
		selectionButton++;
		selectionButton %= BUTTON_MAX;
	}
	if (Input::IsKeyDown(KeyCode::Down))
	{
		if (selectionButton < 1)
		{
			selectionButton = BUTTON_MAX;
		}
		selectionButton--;
	}

	if (Input::IsKeyDown(KeyCode::T))
	{
		SceneManager::Move<TestScene>();
	}

	if (Input::IsKeyDown(KeyCode::I))
	{
		SceneManager::Move<InfoScene>();
	}


	// Pキーが押されたならプレイシーンに
	if (Input::IsKeyDown(KeyCode::P))
	{
		GirafflingHook::SetPlayStyle(PlayStyle::KeyBoardAndMouse);
		SceneManager::Move<PlayScene>();
	}

	// Aボタンが押されたならプレイシーンに
	if (Input::IsPadButtonDown(GamePad::A))
	{
		GirafflingHook::SetPlayStyle(PlayStyle::GamePad);
		SceneManager::Move<PlayScene>();
	}

	if (Input::IsKeyDown(KeyCode::U))
	{
		SceneManager::Move<ClearScene>();
	}
}

void TitleScene::Draw() const // この関数の中ではメンバ変数を一切書き換えることはない
{
	MV1DrawModel(hPlayButtonModel_);
	MV1DrawModel(hInfoButtonModel_);
	MV1DrawModel(hQuitButtonModel_);

	DrawExtendGraph(371, Screen::HEIGHT - y, 371 + 280, Screen::HEIGHT, hGiraffeImageBody_, TRUE);
	DrawGraph(371, Screen::HEIGHT - y, hGiraffeImageHead_, TRUE);
}

void TitleScene::End()
{
	DeleteLightHandleAll();

	MV1DeleteModel(hPlayButtonModel_);
	MV1DeleteModel(hInfoButtonModel_);
	MV1DeleteModel(hQuitButtonModel_);
}
