#pragma once
#include "GameObject.h"
#include "MiniEngine.h"
#include "Transform.h"
#include "AABBCollider.h"

namespace Play
{
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		void MoveDefault();
		void MoveHooking();

	private:
		Transform transform_;
		AABBCollider collider_;
		float animationTime_;
		int hGiraffeMV1_;
		bool isHooking_;
	};
}
