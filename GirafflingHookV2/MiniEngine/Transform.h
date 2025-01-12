#pragma once
#include "Attachment.h"
#include "Vector2.h"
#include <DirectXMath.h>
#include <set>
#include <cmath>
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
	~Transform();

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
	/// �C�ӂ̎����w����W�̕����Ɍ�����
	/// </summary>
	/// <param name="forwardDirection">���������C�ӂ̎�</param>
	/// <param name="targetPosition">�����������W</param>
	void LookAt(Vector3 forwardDirection, const Vector3& targetPosition);
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
	/// <summary>
	/// ���W���擾����
	/// </summary>
	/// <returns>���W(�R�s�[�l)</returns>
	inline Vector3 GetPosition() const { return position; }
	/// <summary>
	/// ��]���擾����
	/// </summary>
	/// <returns>��](�R�s�[�l)</returns>
	inline Vector3 GetRotate() const { return rotate; }
	/// <summary>
	/// ��]�����W�A���Ŏ擾����
	/// </summary>
	/// <returns>���W�A���̉�](�R�s�[�l)</returns>
	inline Vector3 GetRotateRadian() const { return rotate * (std::acosf(-1.f) / 180.f); }
	/// <summary>
	/// �傫�����擾����
	/// </summary>
	/// <returns>�傫��(�R�s�[�l)</returns>
	inline Vector3 GetScale() const { return scale; }

private:
	DirectX::XMMATRIX GetWorldTranslateMatrix();

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

