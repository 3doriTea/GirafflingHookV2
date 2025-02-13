#pragma once
#include "Vector3.h"
#include <string>

enum LayerOrderType : short
{
	Background = -0b0'100'0000'0000'0000,
	Default    =  0b0'000'0000'0000'0000,
	UI         =  0b0'100'0000'0000'0000,
};

/// <summary>
/// ゲームオブジェクト生成ビルダー
/// </summary>
struct GameObjectBuilder
{
	GameObjectBuilder();

	GameObjectBuilder& Position(const Vector3& _position);
	GameObjectBuilder& Rotate(const Vector3& _rotate);
	GameObjectBuilder& Scale(const Vector3& _scale);
	GameObjectBuilder& LayerOrder(const short& _layerOrder);
	GameObjectBuilder& Name(const std::string& _name);
	GameObjectBuilder& Tag(const std::string& _tag);
	/// <summary>
	/// 生成直後はアクティブかどうか
	/// </summary>
	/// <param name="_isActive">アクティブ true / false</param>
	/// <returns>ビルダーの参照</returns>
	GameObjectBuilder& IsActiveStart(const bool& _isActive);

	Vector3 position;
	Vector3 rotate;
	Vector3 scale;
	short layerOrder;  // NOTE: メモリレイアウト的にココ
	bool isActiveStart;  // アクティブ状態で開始するか
	std::string name;
	std::string tag;
};
