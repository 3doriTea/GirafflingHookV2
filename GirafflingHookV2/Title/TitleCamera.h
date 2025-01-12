#pragma once
#include "GameObject.h"

namespace Title
{
	class TitleCamera : public GameObject
	{
	public:
		TitleCamera();
		~TitleCamera();

		void Init() override;
	};
}
