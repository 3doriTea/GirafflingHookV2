#pragma once
#include "GameObject.h"
#include <list>

namespace Play
{
	class BackgroundCloud : public GameObject
	{
	public:
		BackgroundCloud();
		~BackgroundCloud();

		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		struct Cloud
		{
			Cloud(const Vector3& _position, const float& _startAngle) :
				position{ _position },
				angle{ _startAngle }
			{}

			Vector3 position;
			float angle;
		};

		float cloudShowTimeLeft_;  // ‰_•\Ž¦ŠÔŠu
		std::list<Cloud*> clouds_;
	};
}
