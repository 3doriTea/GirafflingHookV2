#pragma once
#include "GameObject.h"
#include "Transform.h"
#include <set>

namespace Play
{
	class GiraffePoint;
	class Player;

	/// <summary>
	/// �t�b�N�|�C���g��I�Ԃ��߂̖��I�u�W�F�N�g
	/// </summary>
	class HookArrow : public GameObject
	{
	public:
		HookArrow();
		~HookArrow();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

		void RegisterGiraffePoint(GiraffePoint* ptr);
		void UnregisterGiraffePoint(GiraffePoint* ptr);

		inline GiraffePoint* GetFoundGiraffePoint() { return foundGiraffePoint_; }

	private:
		Transform transform_;
		std::set<GiraffePoint*> giraffePoints_;
		Transform* giraffePointRoot_;
		GiraffePoint* foundGiraffePoint_;

		float animationTimer_;
		int hArrowImage_;
		int hExtendImage_;
		int hShrinkImage_;
		Vector2 arrowImageCenter_;
		float arrowAngle_;
		float arrowForce_;
		float extendShrinkForce_;  // �L�яk��
		Vector3 diff_;

		Player* player_;

		// MEMO: ��ʂ̃T�C�Y�͕ς�邱�ƂȂ�
		const Vector2 SCREEN_CENTER;
	};
}
