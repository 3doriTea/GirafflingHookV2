#pragma once
#include "Vector2Int.h"

/// <summary>
/// 画面関係
/// </summary>
class Screen final
{
	/*
	* ビューポート座標：左下が原点の座標系
	* スクリーン座標：左上が原点の座標系
	*/
public:
	/// <summary>
	/// スクリーン座標をビューポート座標に変換する
	/// </summary>
	/// <param name="screenX">スクリーン座標のx</param>
	/// <param name="screenY">スクリーン座標のy</param>
	/// <returns>ビューポート座標</returns>
	static Vector2Int ToViewportPosition(const int& screenX, const int& screenY);
	/// <summary>
	/// スクリーン座標をビューポート座標に変換する
	/// </summary>
	/// <param name="screen">スクリーン座標</param>
	/// <returns>ビューポート座標</returns>
	static Vector2Int ToViewportPosition(const Vector2Int& screen);

public:
	static const int WIDTH;  // 横幅
	static const int HEIGHT;  // 立幅
	static const int COLOR_DEPTH;  // 使うカラービット数
};
