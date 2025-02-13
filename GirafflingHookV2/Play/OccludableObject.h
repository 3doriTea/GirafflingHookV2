#pragma once
#include "GameObject.h"
#include "Transform.h"
#include "Occluder.h"

namespace Play
{
	class Player;

	/// <summary>
	/// �J�����̎��E�ɂ��Ȃ���Δ�A�N�e�B�u�ɂȂ�Q�[���I�u�W�F�N�g
	/// </summary>
	class OccludableObject :
		// MEMO: ���z���N���X�ɂ��Ĕh���N���X������N���X�̃R���X�g���N�^���Ăяo���\�ɂ���
		virtual public GameObject
	{
		friend Occluder;

	public:
		OccludableObject();
		virtual ~OccludableObject();

		virtual void Init() override;
		virtual void End() override;

		inline Vector3 GetWorldPosition() { return transform_.GetWorldPosition(); }

	protected:
		Transform transform_;
	private:
		float occludeDistance;
	};
}
