#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Vector3.h"
#include "AABBCollider.h"
#include "Transform.h"

namespace Play
{
	/// <summary>
	/// Draw.io�Ő݌v�����X�e�[�W�̊ȈՕǃQ�[���I�u�W�F�N�g
	/// </summary>
	class StageBoard : public GameObject
	{
	public:
		/// <summary>
		/// Draw.io�̐݌v�����̂܂܂����
		/// </summary>
		/// <param name="topLeftDrawPosition">���̍���̍��W</param>
		/// <param name="widthHeight">���̂̕�</param>
		/// <param name="angle">���̂̊p�x</param>
		StageBoard(
			const Vector2& topLeftDrawPosition,
			const Vector2& widthHeight,
			const float& angle = 0.f);
		~StageBoard();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		AABBCollider collider_;
		Transform transform_;

		int hBoxModel_;
	};
}
