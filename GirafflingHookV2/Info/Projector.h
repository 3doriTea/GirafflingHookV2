#pragma once
#include "GameObject.h"

class Projector : public GameObject
{
public:
	Projector();
	~Projector();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;
private:
	int hImage_;

	static const int POSITION_X;
	static const int POSITION_Y;
	static const float SIZE;
	static const int RAY_ORIGIN_X;
	static const int RAY_ORIGIN_Y;
	static const int RAY_TARGET_X;
	static const int RAY_TARGET_Y;
	static const float RAY_RADIUS;
	static float offsetRadian;
};
