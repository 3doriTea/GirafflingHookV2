#pragma once
#include "Attachment.h"
#include "Vector2.h"
#include <DirectXMath.h>
#include <set>
#include <cmath>
#include "Vector3.h"

class OBBCollider;
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
	Vector3 ToWorldPosition(const Vector3& localPosition) const;
	/// <summary>
	/// ���[�J�������������[���h�������ɕϊ�
	/// </summary>
	/// <param name="localDirection">������</param>
	/// <returns>���[���h������</returns>
	Vector3 ToWorldDirection(const Vector3& localDirection) const;
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
	/// <summary>
	/// ���[�J���E�������̃��[���h������(�P�ʃx�N�g��)���擾
	/// </summary>
	/// <returns>���[���h������(�P�ʃx�N�g��)</returns>
	inline Vector3 RightUnit() const
	{
		return ToWorldDirection({ 1.f, 0.f, 0.f });
	};
	/// <summary>
	/// ���[�J����������̃��[���h������(�P�ʃx�N�g��)���擾
	/// </summary>
	/// <returns>���[���h������(�P�ʃx�N�g��)</returns>
	inline Vector3 UpUnit() const
	{
		return ToWorldDirection({ 0.f, 1.f, 0.f });
	};
	/// <summary>
	/// ���[�J���O�������̃��[���h������(�P�ʃx�N�g��)���擾
	/// </summary>
	/// <returns>���[���h������(�P�ʃx�N�g��)</returns>
	inline Vector3 ForwardUnit() const
	{
		return ToWorldDirection({ 0.f, 0.f, 1.f });
	};
	/// <summary>
	/// ���[�J���E�������̃��[���h���������擾
	/// </summary>
	/// <returns>���[���h������</returns>
	inline Vector3 Right() const
	{
		return ToWorldDirection({ scale.x / 2.f, 0.f, 0.f });
	};
	/// <summary>
	/// ���[�J����������̃��[���h���������擾
	/// </summary>
	/// <returns>���[���h������</returns>
	inline Vector3 Up() const
	{
		return ToWorldDirection({ 0.f, scale.y / 2.f, 0.f });
	};
	/// <summary>
	/// ���[�J���O�������̃��[���h���������擾
	/// </summary>
	/// <returns>���[���h������</returns>
	inline Vector3 Forward() const
	{
		return ToWorldDirection({ 0.f, 0.f, scale.z / 2.f });
	};

private:
	DirectX::XMMATRIX GetWorldTranslateMatrix() const;
	DirectX::XMMATRIX GetWorldDirectionMatrix() const;

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

