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
	assert(hTreeModel_ != -1);  // モデルはある
	hBoxModel_ = MV1LoadModel("Assets/Play/testcube.mv1");
	assert(hBoxModel_ != -1);  // モデルはある

#pragma region グラッフポイント生成
	// NOTE: Draw.ioで設計した座標をそのまま入力する
	/*Instantiate<GiraffePoint>(Vector3{ 0.f, 0.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 1400.f, 230.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 1890.f, 7.5f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 2509.59f, -490.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 1930.41f, -950.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 2509.59f, -1430.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 2989.f, -2120.f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 3430.f, -2022.5f, 0.f });
	Instantiate<GiraffePoint>(Vector3{ 4519.f, -710.f, 0.f });*/
#pragma endregion

#pragma region 壁生成
	Instantiate<StageBoard>(
		"Cube (0)",
		Vector3{ 0.0000f, -100.0000f, 0.0000f },
		Vector3{ 3500.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (6)",
		Vector3{ 4000.0000f, 400.0000f, 0.0000f },
		Vector3{ 3500.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (8)",
		Vector3{ 4300.0000f, -100.0000f, 0.0000f },
		Vector3{ 5100.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (16)",
		Vector3{ 9400.0000f, -100.0000f, 0.0000f },
		Vector3{ 5100.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (17)",
		Vector3{ 14500.0000f, -100.0000f, 0.0000f },
		Vector3{ 5100.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (15)",
		Vector3{ 7500.0000f, 6900.0000f, 0.0000f },
		Vector3{ 5100.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (22)",
		Vector3{ 12600.0000f, 6900.0000f, 0.0000f },
		Vector3{ 5100.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (1)",
		Vector3{ -1700.0000f, 800.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (9)",
		Vector3{ 6800.0000f, 800.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (18)",
		Vector3{ 17000.0000f, 800.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (19)",
		Vector3{ 17000.0000f, 2500.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (20)",
		Vector3{ 17000.0000f, 4200.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (21)",
		Vector3{ 17000.0000f, 5900.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (10)",
		Vector3{ 6800.0000f, 2550.0000f, 0.0000f },
		Vector3{ 100.0000f, 1800.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (11)",
		Vector3{ 5000.0000f, 2600.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (12)",
		Vector3{ 5000.0000f, 4300.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (14)",
		Vector3{ 5000.0000f, 6000.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (13)",
		Vector3{ 6800.0000f, 4300.0000f, 0.0000f },
		Vector3{ 100.0000f, 1700.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (2)",
		Vector3{ 1700.0000f, 200.0000f, 0.0000f },
		Vector3{ 100.0000f, 500.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (7)",
		Vector3{ 3900.0000f, 700.0000f, 0.0000f },
		Vector3{ 100.0000f, 500.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (3)",
		Vector3{ -500.0000f, 1700.0000f, 0.0000f },
		Vector3{ 2500.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (4)",
		Vector3{ 2000.0000f, 1700.0000f, 0.0000f },
		Vector3{ 2500.0000f, 100.0000f, 100.0000f });
	Instantiate<StageBoard>(
		"Cube (5)",
		Vector3{ 4400.0000f, 1700.0000f, 0.0000f },
		Vector3{ 2300.0000f, 100.0000f, 100.0000f });
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
