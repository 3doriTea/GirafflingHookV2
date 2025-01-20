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

	private:
		Transform transform_;
		int hTreeModel_;
	};
}
