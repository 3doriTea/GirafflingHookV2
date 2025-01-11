#pragma once
#include "GameObject.h"

class Player;

class Camera : public GameObject
{
public:
	Camera();
	~Camera();

	void Init() override;
	void Update() override;

private:
	Player* player_;
};

