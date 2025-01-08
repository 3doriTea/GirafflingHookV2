#pragma once
#include "Manager.h"

class ImageManager : public Manager
{
public:
	ImageManager();
	~ImageManager();

	void Init() override;
	void Update() override;
	void End() override;
};

