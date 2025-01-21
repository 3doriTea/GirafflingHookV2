#pragma once
#include "GameObject.h"
#include "Transform.h"

namespace Play
{
	class GiraffePoint;

	/// <summary>
	/// グラッフポイントを総括するゲームオブジェクト
	/// </summary>
	class GiraffePointRoot : public GameObject
	{
		friend GiraffePoint;

	public:
		GiraffePointRoot(const float& _scale);
		~GiraffePointRoot();

		void Init() override;
		void End() override;

		static Transform* GetGroundTransform();
		static int GetTreeModelSourceHandle();
		static int GetBoxModelSourceHandle();

	private:
		Transform transform_;

		static Transform* groundTransform_;
		static int hTreeModel_;
		static int hBoxModel_;
	};
}
