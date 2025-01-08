#pragma once
#include "Manager.h"
#include <functional>
#include <Windows.h>


/// <summary>
/// フレームを管理するクラス
/// </summary>
class FrameManager : public Manager
{
public:
	FrameManager();
	~FrameManager();

	void Init() override;
	void Update() override;
	void End() override;
	/// <summary>
	/// 1フレームが更新されたタイミングで呼ばれるコールバック
	/// </summary>
	/// <param name="">コールバック</param>
	/// <returns>フレームマネージャの参照</returns>
	FrameManager& OnFrame(std::function<void()>);
	/// <summary>
	/// FPS制限を設定する
	/// </summary>
	/// <param name="fpsLimit">最大FPS</param>
	/// <returns>フレームマネージャの参照</returns>
	FrameManager& SetFPSLimit(const int& fpsLimit);

private:
	LARGE_INTEGER currentTime;  // 今回のサイクル時
	LARGE_INTEGER previousTime;  // 前回のサイクル時
	LONGLONG differenceTime;  // サイクル間の時間差
	LONGLONG frameDifferenceTime;  // フレーム間の時間差
	int fpsCounter;
	int fpsLimit;  // FPS制限 (理想のFPS)
	LONGLONG fpsUpdateTimeLeft;
	std::function<void()> onFrame;

	static FrameManager* instance;
};
