#pragma once
#include "Manager.h"

class DxLibManager : public Manager
{
public:
	DxLibManager();
	~DxLibManager();

	void Init() override;
	void Update() override;
	void End() override;
};

