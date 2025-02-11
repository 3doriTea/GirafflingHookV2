#pragma once
#include "Vector3.h"
#include <string>

/// <summary>
/// �Q�[���I�u�W�F�N�g�����r���_�[
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

	Vector3 position;
	Vector3 rotate;
	Vector3 scale;
	short layerOrder;  // NOTE: ���������C�A�E�g�I�ɃR�R
	std::string name;
	std::string tag;
};
