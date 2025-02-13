#pragma once
#include "GameObject.h"
#include "Transform.h"
#include "Occluder.h"

namespace Play
{
	class Player;

	/// <summary>
	/// カメラの視界にいなければ非アクティブになるゲームオブジェクト
	/// </summary>
	class OccludableObject :
		// MEMO: 仮想基底クラスにして派生クラスから基底クラスのコンストラクタを呼び出し可能にする
		virtual public GameObject
	{
		friend Occluder;

	public:
		OccludableObject();
		virtual ~OccludableObject();

		virtual void End() override;

	protected:
		void Init(const Transform& _transform);
	private:
		float occludeDistance;
	};
}
