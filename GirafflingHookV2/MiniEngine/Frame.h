#pragma once

class FrameManager;

class Frame final
{
	friend FrameManager;
private:
	static float deltaTime;
	static int fps;
	static float timeScale;

public:
	/// <summary>
	/// デルタタイム(フレーム間時間)を取得
	/// </summary>
	/// <returns>デルタタイム(秒)</returns>
	static float GetDeltaTime();
	/// <summary>
	/// タイムスケールを取得
	/// </summary>
	/// <returns>タイムスケール</returns>
	static float GetTimeScale();
	/// <summary>
	/// タイムスケールを設定
	/// </summary>
	static void SetTimeScale(const float& scale);
	/// <summary>
	/// フレームレート(秒間あたりの更新数)を取得
	/// </summary>
	/// <returns>FPS</returns>
	static int GetFPS();
};
