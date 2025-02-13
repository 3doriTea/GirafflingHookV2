#pragma once
#include "GameObject.h"
#include "MiniEngine.h"
#include "Transform.h"
#include "AABBCollider.h"

namespace Play
{
	class GiraffePoint;
	class HookArrow;

	class Player : public GameObject
	{
		enum struct State : int
		{
			Defualt,  // ���ʂ̈ړ�
			Shooting,  // �O���b�t���[����
			Hooking,  // �O���b�t�����O��
		};

	public:
		Player();
		~Player();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

		inline bool IsHooking() const { return hookTarget_ != nullptr; }
		/// <summary>
		/// �t�b�L���O����^�[�Q�b�g�̍��W�������Ɏ擾
		/// </summary>
		/// <param name="outPosition">�^�[�Q�b�g���W�̎Q��(/ �Ȃ���Ζ��ύX)</param>
		/// <returns>�擾�ɐ��� true / false</returns>
		bool TryGetHookTargetPosition(Vector3& outPosition);

		inline Transform* GetTransform() { return &transform_; }
		inline Vector3 GetWorldPosition() { return transform_.GetWorldPosition(); }

		/// <summary>
		/// �S�[������
		/// </summary>
		/// <param name="goalPosition">�S�[���̃��[���h���W</param>
		void StartGoalAnimation(const Vector3& goalPosition);

	private:
		/// <summary>
		/// �ړ��̍X�V �L�[���͂��ړ������ɍX�V
		/// </summary>
		void UpdateMove();

		/// <summary>
		/// ���ʂ̈ړ�
		/// </summary>
		void MoveDefault();
		/// <summary>
		/// ����
		/// </summary>
		void Shooting();
		/// <summary>
		/// �O���b�t�����O�ړ�
		/// </summary>
		void MoveHooking();
		/// <summary>
		/// �S�[�����̈ړ�
		/// </summary>
		void MoveGoalling();

		/// <summary>
		/// �O���b�t�����O�J�n
		/// </summary>
		void StartHooking();
		/// <summary>
		/// �O���b�t�����O�I��
		/// </summary>
		void FinishHooking();

		/// <summary>
		/// ��̒������A�j���[�V�������Ԃɕϊ�����
		/// </summary>
		/// <param name="length">��̒���</param>
		/// <returns>�A�j���[�V��������</returns>
		float LengthToAnimationTime(float length);

	private:
		Transform transform_;
		AABBCollider collider_;
		Rigidbody rigidbody_;

		float animationTime_;     // �O���b�t�����O���̃A�j���[�V��������
		// MEMO: �����ɂ���ăA�j���[�V�������X�g�b�v�����鎞�Ԃ�ύX���Ă���
		float animationTimeMax_;  // �O���b�t�����O���̃A�j���[�V�������ԍő�
		int hGiraffeMV1_;
		float hookDistance_;
		int hTextureImage_;

		Vector3 smootingBeginPosition_;  // �S�[�����̂Ɉړ�����J�n���W
		Vector3 smootingDiff_;  // �S�[�����Ɉړ����鍷���x�N�g��
		bool isGoalling_;
		float goallingTimeLeft_;  // �S�[�����̃A�j���[�V��������
		const float GOALLING_TIME_MAX;  // �S�[�����̃A�j���[�V�����ő厞��

		GiraffePoint* hookTarget_;  // �O���b�t�����O����^�[�Q�b�g
		HookArrow* hookArrow_;

		State state_;  // �v���C���[�̏��
		Vector3 move_;
		int moveSign_;

	private:
		// MEMO: �L�����̎��5000�L�т�
		static const float NECK_LENGTH_MAX;
		static const float HOOKING_ANIMATION_TIME_MAX;
		// 1�b�Ԃ����艽�A�j���[�V�������Ԑi�߂邩
		static const float HOOKING_ANIMATION_SPEED;
		// �������삵�Ȃ��󔒂̎���
		static const float HOOKING_ANIMATION_OFFSET_IDOL_TIME;
		// �Y�����������邽�߂̎��ƃI�t�Z�b�g
		static const float HOOKING_ANIMATION_OFFSET_TIME;

		// �ړ����x (�����x)
		static const float MOVE_SPEED;

		// �ړ������
		static const float MOVE_FORCE;
	};
}
