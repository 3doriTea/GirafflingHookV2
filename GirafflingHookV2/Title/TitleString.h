#pragma once
#include "GameObject.h"

namespace Title
{
	class TitleString : public GameObject
	{
	public:
		TitleString();
		~TitleString();

		void Init() override;
		void Draw() const override;
		void End() override;

	private:
		int hTitleModel_;
	};
}
