#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;

private:
	int hGiraffeMV1_;
	VECTOR playerPosition_{ VGet(0, 0, 0) };
};

