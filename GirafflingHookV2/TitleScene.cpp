#include "TitleScene.h"
#include "MiniEngine.h"
#include "PlayScene.h"
#include <DxLib.h>
#include <cassert>
#include "Screen.h"
#include "Title/TitleString.h"
#include "Title/TitleCamera.h"
#include "Title/SelectButton.h"
//#include <imgui.h>
#include "../ImGui/imgui.h"

using namespace Title;

static int posX{ 0 };
static int posY{ 0 };

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
	hGiraffeImageBody_ = LoadGraph("Assets/Title/giraffeBody.png");
	assert(hGiraffeImageBody_ > 0);  // 画像は読み込まれる！
	hGiraffeImageHead_ = LoadGraph("Assets/Title/giraffeHead.png");
	assert(hGiraffeImageHead_ > 0);  // 画像は読み込まれる！

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
	
	if (Input::IsKeyDown(KeyCode::Up))
	{
		selectionButton++;
		selectionButton %= BUTTON_MAX;
	}
	if (Input::IsKeyDown(KeyCode::Down))
	{
		selectionButton--;
		selectionButton %= BUTTON_MAX;
	}

	if (CheckHitKey(KEY_INPUT_P))
	{
		SceneManager::Move<PlayScene>();
	}

	/*if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager::Move<PlayScene>();
	}*/

	ImGui::Begin("giraffe position");
	ImGui::SliderInt("x", &posX, 0, Screen::WIDTH);
	ImGui::SliderInt("x", &posY, 0, Screen::HEIGHT);
	ImGui::End();
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

	DrawGraph(posX, posY, hGiraffeImageBody_, TRUE);
	DrawGraph(posX, posY, hGiraffeImageHead_, TRUE);

	//DrawExtendGraph()
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
