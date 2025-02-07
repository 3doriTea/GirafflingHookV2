#pragma once
#include "Manager.h"

class SoundManager : public Manager
{
public:
	SoundManager() :
		Manager(CalledType::Frame)
	{}

	void Init() override;
	void Update() override;
	void End() override;

private:
};

