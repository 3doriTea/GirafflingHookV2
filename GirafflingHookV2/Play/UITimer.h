#pragma once
#include "GameObject.h"

namespace Play
{
	class UITimer : public GameObject
	{
	public:
		UITimer();
		~UITimer();

		void Draw() const override;
	};
}
