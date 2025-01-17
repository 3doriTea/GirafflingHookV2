#pragma once
#include "GameScene.h"

namespace Play
{
	class Player;
}


class PlayScene : public GameScene
{
public:
	PlayScene();
	~PlayScene();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;

private:
	Play::Player* player_;
};
