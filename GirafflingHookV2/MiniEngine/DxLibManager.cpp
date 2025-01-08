#include "DxLibManager.h"
#include "Game.h"
#include "Screen.h"
#include <DxLib.h>
#include <cassert>

DxLibManager::DxLibManager() :
	Manager::Manager(CalledType::Frame)
{
	SetOrder(10);
}

DxLibManager::~DxLibManager()
{
}

void DxLibManager::Init()
{
	SetWindowText("Giraffling Hook ver1.0.0");

	// MEMO: Window�̍ő�T�C�Y�����߂�
	SetGraphMode(Screen::WIDTH, Screen::HEIGHT, Screen::COLOR_DEPTH);

	// MEMO: Window���[�h�ŋN��
	ChangeWindowMode(TRUE);

	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetWindowSize(Screen::WIDTH, Screen::HEIGHT);

	assert(DxLib_Init() != -1);

	SetBackgroundColor(0, 0, 0);
	SetDrawScreen(DX_SCREEN_BACK);
}

void DxLibManager::Update()
{
	ClearDrawScreen();
	ScreenFlip();
	if (ProcessMessage() || CheckHitKey(KEY_INPUT_ESCAPE))
	{
		Game::Exit();
	}
}

void DxLibManager::End()
{
	DxLib_End();
}
