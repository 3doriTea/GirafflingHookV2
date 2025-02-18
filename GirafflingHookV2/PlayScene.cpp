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
#include "Play/BackgroundCloud.h"
#include "Play/Occluder.h"
#include "Play/UITimer.h"
#include "Play/SkySphere.h"
#include "ClearScene.h"

using namespace Play;

namespace
{
	
}

PlayScene::PlayScene() :
	player_{ nullptr },
	isPlayerGoaled_{ false }
{
	playTimer_ = 0.f;
	score = 0;
}

PlayScene::~PlayScene()
{
}

void PlayScene::Init()
{
	Sound::Load(AudioInfo{}
		.File("Assets/Sounds/getApple.mp3")
		.Name("get-apple"));
	Sound::Load(AudioInfo{}
		.File("Assets/BGM/Dance_With_Powder.mp3")
		.Name("play-bgm"));

	Sound::PlayBGM("play-bgm");

	SetBackgroundColor(0x08, 0xC2, 0xFF);

	player_ = &AddGameObject<Player>();
	AddGameObject<Debug>();
	AddGameObject<HookArrow>();
	AddGameObject<Camera>();
	AddGameObject<Ground>();
	goal_ = &AddGameObject<Goal>();
	AddGameObject<GiraffePointRoot>(2.f);
	AddGameObject<BackgroundCloud>();
	AddGameObject<Occluder>();
	AddGameObject<UITimer>();

	AddGameObject<SkySphere>();

	ChangeLightTypeDir(VGet(1.f, -1.f, 0.5f));

	playTimer_ = 0.0f;  // タイマーリセット
}

void PlayScene::Update()
{
	if (Input::IsKeyDown(KEY_INPUT_C))
	{
		SceneManager::Move<ClearScene>();
	}

	playTimer_ += Frame::GetDeltaTime();
}

void PlayScene::Draw() const
{
}

void PlayScene::End()
{
	//SetupCamera_Perspective(60 * (DX_PI_F / 180.f));
	Sound::Stop("play-bgm");
}

void PlayScene::FinishedGoalAnimation()
{
	// TODO: スコアシーンに遷移
	SceneManager::Move<ClearScene>();
}

void PlayScene::GoalPlayer()
{
	isPlayerGoaled_ = true;
	player_->StartGoalAnimation(goal_->position);
}

void PlayScene::AddScore(const int& scorePoint)
{
	score += scorePoint;
	Sound::Play("get-apple");
}

float PlayScene::playTimer_{ 0.0f };
int PlayScene::score{ 0 };
