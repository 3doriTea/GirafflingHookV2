#pragma once
#include "Manager.h"

/// <summary>
/// ImGui���g�����߂̃}�l�[�W��
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

