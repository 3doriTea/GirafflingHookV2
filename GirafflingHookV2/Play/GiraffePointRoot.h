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

	private:
		Transform transform_;
		int hTreeModel_;
	};
}
