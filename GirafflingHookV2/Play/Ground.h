#pragma once
#include "GameObject.h"
#include "AABBCollider.h"
#include "Transform.h"

namespace Play
{
	class Ground : public GameObject
	{
	public:
		Ground();
		~Ground();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		Transform transform_;
		AABBCollider collider_;
		int hBoxModel_;
		int hTestCube_;
	};
}
