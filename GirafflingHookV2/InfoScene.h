#pragma once
#include "GameScene.h"

namespace Info
{

}

class InfoScene : public GameScene
{
public:
	InfoScene();
	~InfoScene();

	void GoHome();

private:
	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;
};
