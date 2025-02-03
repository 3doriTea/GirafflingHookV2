#pragma once
#include "Manager.h"

/// <summary>
/// ImGuiを使うためのマネージャ
/// </summary>
class ImGuiManager : public Manager
{
public:
	ImGuiManager();
	~ImGuiManager();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void End() override;
};

