#pragma once
#include "Game.h"

class GirafflingHook : public Game
{
private:
	void Update() override;
	void Init() override;
	void End() override;
};
