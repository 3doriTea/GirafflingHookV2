#pragma once
#include "GameObject.h"

namespace Test
{
	class TestGameObjC : public GameObject
	{
	public:
		TestGameObjC();
		~TestGameObjC();

		void Init();
		void Update();
		void End();
	};
}
