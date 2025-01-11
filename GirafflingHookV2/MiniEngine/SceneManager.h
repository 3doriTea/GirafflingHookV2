#pragma once
#include "Manager.h"
#include "GameScene.h"
#include <cassert>

class GameObject;

class SceneManager : public Manager
{
	friend GameObject;

public:
	SceneManager();
	~SceneManager();

	void Init() override;
	void Update() override;
	void End() override;

	template<typename GameSceneT>
	static void Move()
	{
		assert(instance->readyScene_ == nullptr);
		instance->readyScene_ = new GameSceneT{};
		assert(instance->readyScene_ != nullptr);
	}
	static GameScene& RefActiveGameScene();

private:
	GameScene* readyScene_;
	GameScene* activeScene_;

	static SceneManager* instance;
};

