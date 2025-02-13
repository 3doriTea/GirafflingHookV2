#include "GameScene.h"
#include "GameObject.h"

GameScene::GameScene() :
	gameObjects_{},
	uninitialisedGameObjects_{}
{
}

GameScene::~GameScene()
{
}

void GameScene::InitScene()
{
	Init();
}

void GameScene::UpdateScene()
{
	Update();

	for (auto&& gameObject : gameObjects_)
	{
		if (uninitialisedGameObjects_.count(gameObject))
		{
			gameObject->Init();
			uninitialisedGameObjects_.erase(gameObject);
		}
		if (gameObject->GetIsActive() == true)
		{
			gameObject->Update();
		}
	}
}

void GameScene::DrawScene()
{
	Draw();

	for (auto&& gameObject : gameObjects_)
	{
		if (gameObject->GetIsActive() == true)
		{
			gameObject->Draw();
		}
	}
}

void GameScene::EndScene()
{
	End();

	for (auto&& gameObject : gameObjects_)
	{
		gameObject->End();
	}
	for (auto&& gameObject : gameObjects_)
	{
		delete gameObject;
	}
	gameObjects_.clear();
}

void GameScene::RegisterGameObject(GameObject* gameObject)
{
	// 要求している順序
	int requestLayerOrder{ gameObject->GetLayerOrder() };

	for (auto&& itr = gameObjects_.begin(); itr != gameObjects_.end(); itr++)
	{
		if ((*itr)->GetLayerOrder() > requestLayerOrder)
		{
			gameObjects_.insert(itr, gameObject);  // 最適地が見つかれば挿入して回帰
			return;
		}
	}

	// 場所が見つからなければ末端に追加して回帰
	gameObjects_.push_back(gameObject);
}

void GameScene::RemoveGameObject(GameObject* gameObject)
{
	for (auto itr = gameObjects_.begin(); itr != gameObjects_.end(); itr++)
	{
		if ((*itr) == gameObject)
		{
			gameObjects_.erase(itr);
		}
	}
}

GameObject* GameScene::FindGameObject(const std::string& name)
{
	for (auto&& gameObject : gameObjects_)
	{
		if (gameObject->GetName() == name)
		{
			return gameObject;
		}
	}

	return nullptr;
}

std::vector<GameObject*> GameScene::FindGameObjects(const std::string& tag)
{
	std::vector<GameObject*> foundGameObjects{};
	for (auto&& gameObject : gameObjects_)
	{
		if (gameObject->GetTag() == tag)
		{
			foundGameObjects.push_back(gameObject);
		}
	}

	return foundGameObjects;
}
