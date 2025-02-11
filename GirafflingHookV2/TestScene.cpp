#include "TestScene.h"
#include "Input.h"
#include "SceneManager.h"
#include "TitleScene.h"
#include "Test/TestGameObjA.h"
#include "Test/TestGameObjB.h"
#include "Test/TestGameObjC.h"

using namespace Test;

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Init()
{
	AddGameObject<TestGameObjC>();
	AddGameObject<TestGameObjB>();
	AddGameObject<TestGameObjA>();
}

void TestScene::Update()
{
	if (Input::IsKeyDown(KeyCode::T))
	{
		SceneManager::Move<TitleScene>();
	}
}

void TestScene::Draw() const
{
}

void TestScene::End()
{
}
