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

#pragma region 壁生成
	Instantiate<StageBoard>(
		Vector2{ 1440.f, 240.f },
		Vector2{ 80.f, 440.f },
		0.f);
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
