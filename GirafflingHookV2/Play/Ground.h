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
		void Draw() const override;

	private:
		Transform transform_;
		AABBCollider collider_;
	};
}
