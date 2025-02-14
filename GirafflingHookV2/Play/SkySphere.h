#pragma once
#include "GameObject.h"
#include "Transform.h"

namespace Play
{
	class Camera;

	class SkySphere : public GameObject
	{
	public:
		SkySphere();
		~SkySphere();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		int hSkySphere_;

		Transform transform_;
		Camera* camera_;
	};
}
