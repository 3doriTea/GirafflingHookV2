#pragma once
#include "GameObject.h"
#include "Vector3.h"
#include "Transform.h"
#include "AABBCollider.h"
#include <string>

namespace Play
{
	class Player;

	class GiraffePoint : public GameObject
	{
	public:
		GiraffePoint(const Vector3& position);
		GiraffePoint(const std::string& name, const Vector3& position);
		~GiraffePoint();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

		/// <summary>
		/// フックのワールド座標を取得する
		/// </summary>
		/// <returns>ワールド座標</returns>
		Vector3 GetHookPosition() const;

	private:
		Player* player_;
		Transform transform_;
		AABBCollider collider_;

		int hTreeSource_;
		int hTreeModel_;
	};
}
