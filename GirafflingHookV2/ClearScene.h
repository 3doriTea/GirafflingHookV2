#pragma once
#include "GameScene.h"

class ClearScene : public GameScene
{
public:
protected:
	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;
};

