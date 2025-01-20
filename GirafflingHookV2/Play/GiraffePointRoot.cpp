#include "GiraffePointRoot.h"
#include "GiraffePoint.h"

Play::GiraffePointRoot::GiraffePointRoot(
	const float& _scale) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("GiraffePointRoot")
			.Tag("giraffe-point-root")
			.Scale(Vector3::One() * _scale)
	},
	transform_{ *this },
	hTreeModel_{ -1 }
{
}

Play::GiraffePointRoot::~GiraffePointRoot()
{
}

void Play::GiraffePointRoot::Init()
{
	hTreeModel_ = MV1LoadModel("Assets/Play/voxeltree.mv1");
	assert(hTreeModel_ != -1);  // モデルはある

#pragma region グラッフポイント生成
	Instantiate<GiraffePoint>(Vector3{ 0.f, 0.f, 0.f }, &transform_, hTreeModel_);
	Instantiate<GiraffePoint>(Vector3{ 1400.f, 230.f, 0.f }, &transform_, hTreeModel_);
#pragma endregion
}

void Play::GiraffePointRoot::End()
{
	MV1DeleteModel(hTreeModel_);
}
