#include "InfoScene.h"
#include "Input.h"
#include "TitleScene.h"
#include "SceneManager.h"
#include "Info/AboutText.h"
#include "Info/Projector.h"

using namespace Info;

InfoScene::InfoScene()
{
}

InfoScene::~InfoScene()
{
}

void InfoScene::GoHome()
{
	SceneManager::Move<TitleScene>();
}

void InfoScene::Init()
{
	AddGameObject<AboutText>();
	AddGameObject<Projector>();
}

void InfoScene::Update()
{
	if (Input::IsKeyDown(KeyCode::Space)
		|| Input::IsPadButtonDown(GamePad::A))
	{
		GoHome();
	}
}

void InfoScene::Draw() const
{
}

void InfoScene::End()
{
}
