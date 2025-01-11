#pragma once
#include "Vector3.h"
#include <string>

/// <summary>
/// ゲームオブジェクト生成ビルダー
/// </summary>
struct GameObjectBuilder
{
	GameObjectBuilder();

	GameObjectBuilder& Position(const Vector3& _position);
	GameObjectBuilder& Rotate(const Vector3& _rotate);
	GameObjectBuilder& Scale(const Vector3& _scale);
	GameObjectBuilder& Name(const std::string& _name);
	GameObjectBuilder& Tag(const std::string& _tag);

	Vector3 position;
	Vector3 rotate;
	Vector3 scale;
	std::string name;
	std::string tag;
};
