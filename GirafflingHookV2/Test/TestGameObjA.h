#pragma once
#include "GameObject.h"

namespace Test
{
	class TestGameObjA : public GameObject
	{
	public:
		TestGameObjA();
		~TestGameObjA();

		void Init();
		void Update();
		void End();
	};
}
