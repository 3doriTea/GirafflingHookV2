#include "PlayScene.h"
#include "MiniEngine.h"
#include "TitleScene.h"
#include <DxLib.h>
#include "Play/Player.h"
#include "Play/Camera.h"
#include "Play/Ground.h"
#include "Play/Goal.h"
#include "Play/GroundCollider.h"
#include "Play/GiraffePointRoot.h"
#include "Play/HookArrow.h"

using namespace Play;

PlayScene::PlayScene() :
	player_{ nullptr },
	isPlayerGoaled_{ false }
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Init()
{
	SetBackgroundColor(0x00, 0x00, 0x00);

	player_ = &AddGameObject<Player>();
	AddGameObject<HookArrow>();
	AddGameObject<Camera>();
	AddGameObject<Ground>();
	goal_ = &AddGameObject<Goal>();
	AddGameObject<GiraffePointRoot>(2.f);

#pragma region �n�ʂ̃R���C�_�[
	AddGameObject<GroundCollider>(
		Vector3{ 0.f, -400.f, 0.f },
		Vector3{ 0.f, 0.f, 0.f },
		Vector3{ 200.f, 200.f, 200.f });
#pragma endregion
	ChangeLightTypeDir(VGet(1.f, -1.f, 0.5f));
}

void PlayScene::Update()
{
	/*if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager::Move<TitleScene>();
	}*/

	playTimer_ += Frame::GetDeltaTime();
}

void PlayScene::Draw() const
{
	DrawFormatString(0, 10, 0xffffff, "x = %f\ny = %f\nz = %f", player_->position.x, player_->position.y, player_->position.z);
	
	SetFontSize(30);
	int sizeX{}, sizeY{}, lineCount{};
	GetDrawFormatStringSize(&sizeX, &sizeY, &lineCount, "�^�C���F%f", playTimer_);
	DrawFormatString((Screen::WIDTH - sizeX) / 2, 0, 0xffffff, "�^�C���F%f", playTimer_);
	SetFontSize(DEFAULT_FONT_SIZE);
}

void PlayScene::End()
{
}

void PlayScene::FinishedGoalAnimation()
{
	// TODO: �X�R�A�V�[���ɑJ��
	SceneManager::Move<TitleScene>();
}

void PlayScene::GoalPlayer()
{
	isPlayerGoaled_ = true;
	player_->StartGoalAnimation(goal_->position);
}
