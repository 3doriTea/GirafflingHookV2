#pragma once
#include "GameObject.h"
#include "Transform.h"

namespace Play
{
	class GiraffePoint;

	/// <summary>
	/// �O���b�t�|�C���g�𑍊�����Q�[���I�u�W�F�N�g
	/// </summary>
	class GiraffePointRoot : public GameObject
	{
		friend GiraffePoint;

	public:
		GiraffePointRoot(const float& _scale);
		~GiraffePointRoot();

		void Init() override;
		void End() override;

		static Transform* GetGroundTransform();
		static int GetTreeModelSourceHandle();
		static int GetBoxModelSourceHandle();

	private:
		Transform transform_;

		static Transform* groundTransform_;
		static int hTreeModel_;
		static int hBoxModel_;
	};
}
