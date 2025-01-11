#pragma once
#include "GameObject.h"
#include "MiniEngine.h"
#include "Transform.h"
#include "AABBCollider.h"

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
	Transform transform_;
	AABBCollider collider_;
	int hGiraffeMV1_;
};

