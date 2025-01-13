#pragma once
#include "GameObject.h"
#include "Transform.h"

namespace Play
{
	class Player;

	class Camera : public GameObject
	{
	public:
		Camera();
		~Camera();

		void Init() override;
		void Update() override;
		void End() override;

	private:
		float cameraMoveRate;
		float cameraDistance;
		float cameraDistanceZ;

		int hSoptLight_;

		Player* player_;
		Transform transform_;
	};
}
