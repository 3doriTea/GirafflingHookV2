#include "Goal.h"
#include "MiniEngine.h"

Play::Goal::Goal() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("GoalRocket")
			.Position({ 2000.f, 0.f, 0.f })
			//.Scale({})
	},
	hRocketModel_{ -1 }
{
}

Play::Goal::~Goal()
{
}

void Play::Goal::Init()
{
	hRocketModel_ = MV1LoadModel("Assets/Play/RetroToyRocket.mv1");

	MV1SetPosition(hRocketModel_, position);
}

void Play::Goal::Update()
{
}

void Play::Goal::Draw() const
{
	MV1DrawModel(hRocketModel_);
}

void Play::Goal::End()
{
	MV1DeleteModel(hRocketModel_);
}
