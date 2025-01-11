#pragma once
#include "GameScene.h"

class PlayScene : public GameScene
{
public:
	PlayScene();
	~PlayScene();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;
};
