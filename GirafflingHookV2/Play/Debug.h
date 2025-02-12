#pragma once
#include "GameObject.h"

namespace Play
{
	class Player;
	
	class Debug :
		public GameObject
	{
	public:
		Debug();
		~Debug();
	
		void Init() override;
		void Update() override;
		void Draw() const override;
	
	private:
		Player* player_;
	};
}
