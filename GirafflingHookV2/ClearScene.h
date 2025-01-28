#pragma once
#include "GameScene.h"

class ClearScene : public GameScene
{
public:
private:
	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;
};
