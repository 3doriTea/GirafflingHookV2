#pragma once
#include "GameObject.h"
#include "Vector3.h"
#include "Transform.h"
#include "AABBCollider.h"

namespace Play
{
	class Player;

	class GiraffePoint : public GameObject
	{
	public:
		GiraffePoint(const Vector3& position,
			Transform* _rootTransform,
			const int& _hTreeSource);
		~GiraffePoint();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		Player* player_;
		Transform transform_;
		AABBCollider collider_;

		int hTreeSource_;
		int hTreeModel_;
	};
}
