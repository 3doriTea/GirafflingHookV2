#include "SceneManager.h"
#include "GameObject.h"
#include <cassert>

//SceneManager::SceneManager() :
//	Manager::Manager{ CalledType::Cycle },
//	readyScene_{ nullptr },
//	activeScene_{ nullptr }
//{
//}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	if (readyScene_ != nullptr)
	{
		if (activeScene_ != nullptr)
		{
			activeScene_->EndScene();
			delete activeScene_;
		}
		activeScene_ = readyScene_;
		readyScene_ = nullptr;
		activeScene_->InitScene();
	}

	activeScene_->UpdateScene();
	activeScene_->DrawScene();
}

void SceneManager::End()
{
	if (activeScene_ != nullptr)
	{
		activeScene_->EndScene();
		delete activeScene_;
	}
}

GameScene& SceneManager::RefActiveGameScene()
{
	assert(instance != nullptr);
	assert(instance->activeScene_ != nullptr);

	return *instance->activeScene_;
}

SceneManager* SceneManager::instance{ nullptr };
