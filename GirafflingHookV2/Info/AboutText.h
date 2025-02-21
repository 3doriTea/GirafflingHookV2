#pragma once
#include "GameObject.h"

namespace Info
{
	class AboutText : public GameObject
	{
	public:
		AboutText();
		~AboutText();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		int hImage_;
	};
}
