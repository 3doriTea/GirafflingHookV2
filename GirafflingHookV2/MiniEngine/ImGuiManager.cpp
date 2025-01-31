#include "ImGuiManager.h"
#include <imgui_impl_dxlib.hpp>

// MEMO: CoGエンジンを参照した

ImGuiManager::ImGuiManager() :
	Manager::Manager{ CalledType::Frame, 20 }
{
}

ImGuiManager::~ImGuiManager()
{
}

void ImGuiManager::Init()
{
	SetHookWinProc([](HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT /*CALLBACK*/
	{
		// DxLibとImGuiのウィンドウプロシージャを両立させる
		SetUseHookWinProcReturnValue(FALSE);
		return ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
	});

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.Fonts->AddFontFromFileTTF(
		u8"c:\\Windows\\Fonts\\meiryo.ttc",
		18.0f,
		nullptr,
		io.Fonts->GetGlyphRangesJapanese());
	ImGui_ImplDXlib_Init();
}

void ImGuiManager::Update()
{
	ImGui_ImplDXlib_NewFrame();
	ImGui::NewFrame();
}

void ImGuiManager::LateUpdate()
{
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDXlib_RenderDrawData();

	if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
	}
}

void ImGuiManager::End()
{
	ImGui_ImplDXlib_Shutdown();
	ImGui::DestroyContext();
}
