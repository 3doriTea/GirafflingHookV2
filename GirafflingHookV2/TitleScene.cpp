#include "TitleScene.h"
#include "MiniEngine.h"
#include "PlayScene.h"
#include <DxLib.h>
#include <cassert>
#include "Screen.h"
#include "Title/TitleString.h"
#include "Title/TitleCamera.h"
#include "Title/SelectButton.h"
#include <imgui.h>

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
	hGiraffeImageBody_ = LoadGraph("Assets/Title/giraffeBody.png");
	assert(hGiraffeImageBody_ > 0);  // 画像は読み込まれる！
	hGiraffeImageHead_ = LoadGraph("Assets/Title/giraffeHead.png");
	assert(hGiraffeImageHead_ > 0);  // 画像は読み込まれる！

	SetBackgroundColor(0xf0, 0xf0, 0xf0);

	TitleString& titleString{ AddGameObject<TitleString>() };
	TitleCamera& titleCamera{ AddGameObject<TitleCamera>() };

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
		if (selectionButton < 1)
		{
			selectionButton = BUTTON_MAX;
		}
		selectionButton--;
	}

	if (CheckHitKey(KEY_INPUT_P))
	{
		SceneManager::Move<PlayScene>();
	}

	ImGui::Begin("giraffe position");
	ImGui::DragInt("selectionButton", &selectionButton);
	ImGui::SliderInt("y", &y, 0, Screen::HEIGHT);
	ImGui::End();
}

void TitleScene::Draw() const // この関数の中ではメンバ変数を一切書き換えることはない
{
	//ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
	//int defaultFontSize = GetFontSize();
	//SetFontSize(100);
	//int titleStrHead = (Screen::WIDTH - GetDrawStringWidth(titleElement[TITLE_TEXT], -1)) / 2;
	//DrawString(titleStrHead, 100, titleElement[TITLE_TEXT], 0xffffff, 0x00ffff);
	//SetFontSize(70);
	//DrawString(titleStrHead, 345, titleElement[PLAY_BUTTON], 0xffffff);
	//DrawString(titleStrHead, 445, titleElement[INFO_BUTTON], 0xffffff);
	//DrawString(titleStrHead, 545, titleElement[QUIT_BUTTON], 0xffffff);
	//SetFontSize(defaultFontSize);
	//ChangeFontType(DX_FONTTYPE_NORMAL);

	MV1DrawModel(hPlayButtonModel_);
	MV1DrawModel(hInfoButtonModel_);
	MV1DrawModel(hQuitButtonModel_);

	/*DrawGraph(posX, posY, hGiraffeImageBody_, TRUE);
	DrawGraph(posX, posY, hGiraffeImageHead_, TRUE);*/

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
