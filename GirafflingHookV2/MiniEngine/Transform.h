#pragma once
#include "Attachment.h"
#include "Vector2.h"
#include <DirectXMath.h>
#include <set>
#include "Vector3.h"

class GameObject;

class Transform : public Attachment
{
public:
	/// <summary>
	/// ���W�ϊ�������A�^�b�`�����g
	/// </summary>
	/// <param name="attachingGameObject">�A�^�b�`����Ώۂ̃Q�[���I�u�W�F�N�g</param>
	Transform(GameObject& attachingGameObject);

	void Draw() const override;

	/// <summary>
	/// ���W�A��]�A�傫���̃p�����[�^�����W�ϊ������s����v�Z���čX�V
	/// </summary>
	void UpdateCalculate();
	/// <summary>
	/// ���[�J�����W�����[���h���W�ɕϊ�
	/// </summary>
	/// <param name="localPosition">�A�^�b�`���ꂽ�Q�[���I�u�W�F�N�g��̃��[�J�����W</param>
	/// <returns>���[���h���W</returns>
	Vector3 ToWorldPosition(const Vector3& localPosition);
	/// <summary>
	/// �e�̍��W�ϊ��n��ݒ�
	/// </summary>
	/// <param name="parent">�e�̍��W�ϊ��n / �e���� nullptr</param>
	void SetParent(Transform* parent);
	/// <summary>
	/// �e�̍��W�ϊ��n���擾
	/// </summary>
	/// <returns>�e�̍��W�ϊ��n / �e���� nullptr</returns>
	inline Transform* GetParent() { return parent_; }

private:
	DirectX::XMMATRIX GetWorldMatrix();

public:
	Vector3& position;
	Vector3& rotate;
	Vector3& scale;

private:
	DirectX::XMMATRIX positionMatrix_;
	DirectX::XMMATRIX rotateMatrix_;
	DirectX::XMMATRIX scaleMatrix_;

	Transform* parent_;
	std::set<Transform*> childs_;
};

