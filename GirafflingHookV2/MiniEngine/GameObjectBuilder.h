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
	/// <summary>
	/// ��������̓A�N�e�B�u���ǂ���
	/// </summary>
	/// <param name="_isActive">�A�N�e�B�u true / false</param>
	/// <returns>�r���_�[�̎Q��</returns>
	GameObjectBuilder& IsActiveStart(const bool& _isActive);

	Vector3 position;
	Vector3 rotate;
	Vector3 scale;
	short layerOrder;  // NOTE: ���������C�A�E�g�I�ɃR�R
	bool isActiveStart;  // �A�N�e�B�u��ԂŊJ�n���邩
	std::string name;
	std::string tag;
};
