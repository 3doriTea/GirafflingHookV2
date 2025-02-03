#include "Goal.h"
#include "MiniEngine.h"
#include "Player.h"
#include "../PlayScene.h"

Play::Goal::Goal() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("GoalRocket")
			.Position({ 32800.f, 13500.f, 0.f })
			//.Scale({})
	},
	hRocketModel_{ -1 },
	player_{ nullptr }
{
}

Play::Goal::~Goal()
{
}

void Play::Goal::Init()
{
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // �v���C���[�͌�����

	hRocketModel_ = MV1LoadModel("Assets/Play/RetroToyRocket.mv1");

	MV1SetPosition(hRocketModel_, position);
}

void Play::Goal::Update()
{
	if (GetGameScene<PlayScene>().IsPlayerGoaled())
	{
		return;  // �S�[�����Ă���Ȃ珈���X�L�b�v
	}

	if (position.Distance(player_->position) <= 600.f)
	{
		// �S�[���I�I
		GetGameScene<PlayScene>().GoalPlayer();
	}
}

void Play::Goal::Draw() const
{
	MV1DrawModel(hRocketModel_);
}

void Play::Goal::End()
{
	MV1DeleteModel(hRocketModel_);
}
