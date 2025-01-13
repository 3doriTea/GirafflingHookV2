#pragma once
#include "GameObject.h"

namespace Play
{
	class Goal : public GameObject
	{
	public:
		Goal();
		~Goal();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		int hRocketModel_;
	};
}
