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
		/// �t�b�N�̃��[���h���W���擾����
		/// </summary>
		/// <returns>���[���h���W</returns>
		Vector3 GetHookPosition() const;

	private:
		Player* player_;
		Transform transform_;
		AABBCollider collider_;

		int hTreeSource_;
		int hTreeModel_;
	};
}
