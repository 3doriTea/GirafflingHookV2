#pragma once
#include "GameObject.h"
#include "OBBCollider.h"
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
		OBBCollider collider_;
		int hBoxModel_;
	};
}
