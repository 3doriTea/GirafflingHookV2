#include "GiraffePointRoot.h"
#include "GiraffePoint.h"
#include "StageBoard.h"
#include "Vector2.h"

Play::GiraffePointRoot::GiraffePointRoot(
	const float& _scale) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("GiraffePointRoot")
			.Tag("giraffe-point-root")
			.Scale(Vector3::From({_scale, _scale }, _scale))
	},
	transform_{ *this }
{
	groundTransform_ = &transform_;
}

Play::GiraffePointRoot::~GiraffePointRoot()
{
}

void Play::GiraffePointRoot::Init()
{
	hTreeModel_ = MV1LoadModel("Assets/Play/voxeltree.mv1");
	assert(hTreeModel_ != -1);  // ���f���͂���
	hBoxModel_ = MV1LoadModel("Assets/Play/testcube.mv1");
	assert(hBoxModel_ != -1);  // ���f���͂���

#pragma region �O���b�t�|�C���g����
	// NOTE: Draw.io�Ő݌v�������W�����̂܂ܓ��͂���
	Instantiate<GiraffePoint>(Vector3{ 0.f, 0.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 1400.f, 230.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 1890.f, 7.5f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 2509.59f, -490.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 1930.41f, -950.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 2509.59f, -1430.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 2989.f, -2120.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 3430.f, -2022.5f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 4519.f, -710.f, 0.f });
#pragma endregion

#pragma region �ǐ���
	/*Instantiate<StageBoard>(
		Vector2{ 1440.f, 240.f },
		Vector2{ 80.f, 440.f });
	Instantiate<StageBoard>(
		Vector2{ 0.f, 680.f },
		Vector2{ 15980.f, 40.f });*/

	Instantiate<StageBoard>(
		"Cube",
		Vector3{ 0.0000f, 0.0000f, 0.0000f },
		Vector3{ 3500.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (1)",
		Vector3{ -1700.0000f, 900.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (2)",
		Vector3{ 1700.0000f, 900.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (3)",
		Vector3{ 0.0000f, 1800.0000f, 0.0000f },
		Vector3{ 3500.0000f, 100.0000f, 100.0000f });

#pragma endregion
}

void Play::GiraffePointRoot::End()
{
	MV1DeleteModel(hTreeModel_);
	groundTransform_ = nullptr;
}

Transform* Play::GiraffePointRoot::GetGroundTransform()
{
	return groundTransform_;
}

int Play::GiraffePointRoot::GetTreeModelSourceHandle()
{
	return hTreeModel_;
}

int Play::GiraffePointRoot::GetBoxModelSourceHandle()
{
	return hBoxModel_;
}

Transform* Play::GiraffePointRoot::groundTransform_{ nullptr };
int Play::GiraffePointRoot::hTreeModel_{ -1 };
int Play::GiraffePointRoot::hBoxModel_{ -1 };
