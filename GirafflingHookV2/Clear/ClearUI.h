#pragma once
#include "GameObject.h"
#include <vector>

namespace Clear
{
	class ClearUI : public GameObject
	{
	public:
		ClearUI();
		~ClearUI();

		void Init() override;
		void Draw() const override;
		void End() override;

	private:
		std::vector<int> hNumModel;
	};
}