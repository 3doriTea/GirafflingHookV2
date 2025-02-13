#pragma once
#include "GameObject.h"
#include <set>

namespace Play
{
	class OccludableObject;
	class Player;

	class Occluder : public GameObject
	{
	public:
		Occluder();
		~Occluder();

		void Init();
		void Update();
		void End();

		void Register(OccludableObject* object);
		void Unregister(OccludableObject* object);

		const float OCCLUDE_PLAYER_DISTANCE;  // 非アクティブにするプレイヤーとの距離
	private:
		Player* player_;
		std::set<OccludableObject*> occludableObjects_;
	};
}
