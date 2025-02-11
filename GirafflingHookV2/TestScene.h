#pragma once
#include "GameScene.h"

class TestScene : public GameScene
{
public:
	TestScene();
	~TestScene();

private:
	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;
};
