#include "PlayScene.h"
#include "MiniEngine.h"
#include "TitleScene.h"
#include "Sound.h"
#include <DxLib.h>
#include "Play/Player.h"
#include "Play/Camera.h"
#include "Play/Ground.h"
#include "Play/Goal.h"
#include "Play/GroundCollider.h"
#include "Play/GiraffePointRoot.h"
#include "Play/HookArrow.h"
#include "Play/Debug.h"
#include "Play/ScoreObject.h"

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
	Sound::Load(AudioInfo{}
		.File("Assets/Sounds/getApple.mp3")
		.Name("get-apple"));

	//SetupCamera_Ortho(10000.f);
	SetBackgroundColor(0x00, 0x00, 0x00);

	player_ = &AddGameObject<Player>();
	AddGameObject<Debug>();
	AddGameObject<HookArrow>();
	AddGameObject<Camera>();
	AddGameObject<Ground>();
	goal_ = &AddGameObject<Goal>();
	AddGameObject<GiraffePointRoot>(2.f);

#pragma region 地面のコライダー
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
	SetFontSize(30);
	int sizeX{}, sizeY{}, lineCount{};
	GetDrawFormatStringSize(&sizeX, &sizeY, &lineCount, "タイム：%f", playTimer_);
	DrawFormatString((Screen::WIDTH - sizeX) / 2, 0, 0xffffff, "タイム：%f", playTimer_);
	SetFontSize(DEFAULT_FONT_SIZE);
}

void PlayScene::End()
{
	//SetupCamera_Perspective(60 * (DX_PI_F / 180.f));
}

void PlayScene::FinishedGoalAnimation()
{
	// TODO: スコアシーンに遷移
	SceneManager::Move<TitleScene>();
}

void PlayScene::GoalPlayer()
{
	isPlayerGoaled_ = true;
	player_->StartGoalAnimation(goal_->position);
}

void PlayScene::AddScore(const int& scorePoint)
{
	score_ += scorePoint;
	Sound::Play("get-apple");
}
