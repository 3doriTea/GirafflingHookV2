#pragma once
#include "GameObject.h"

namespace Test
{
	class TestGameObjB : public GameObject
	{
	public:
		TestGameObjB();
		~TestGameObjB();

		void Init();
		void Update();
		void End();
	};
}
