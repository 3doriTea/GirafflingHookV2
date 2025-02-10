#pragma once
#include "GameObject.h"

namespace Clear
{
	class ClearString : public GameObject
	{
	public:
		ClearString();
		~ClearString();

		void Init() override;
		void Draw() const override;
		void End() override;

	private:
		int hClearModel_;
	};
}
