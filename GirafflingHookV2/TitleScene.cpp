#include "TitleScene.h"
#include "MiniEngine.h"
#include "PlayScene.h"
#include <DxLib.h>
#include "MiniEngine/Screen.h"

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
	if (Input::IsKey(KeyCode::Space))
	{
		printfDx("�^�C�g���V�[��%f\n", Frame::GetDeltaTime());
	}

	if (Input::IsKeyDown(KeyCode::J))
	{
		printfDx("�e�X�e�XDown%f\n", Frame::GetDeltaTime());
	}
	if (Input::IsKeyUp(KeyCode::J))
	{
		printfDx("�e�X�e�XUp%f\n", Frame::GetDeltaTime());
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

void TitleScene::Draw() const // ���̊֐��̒��ł̓����o�ϐ�����؏��������邱�Ƃ͂Ȃ�
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
}

void TitleScene::End()
{
}
