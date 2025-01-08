#pragma once
#include "GameScene.h"

class TitleScene : public GameScene
{
public:
	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;
};
