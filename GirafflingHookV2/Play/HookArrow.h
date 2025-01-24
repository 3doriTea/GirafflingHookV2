#pragma once
#include "GameObject.h"
#include "Transform.h"
#include <set>

namespace Play
{
	class GiraffePoint;

	/// <summary>
	/// フックポイントを選ぶための矢印オブジェクト
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

		// MEMO: 画面のサイズは変わることない
		const Vector2 SCREEN_CENTER;
	};
}
