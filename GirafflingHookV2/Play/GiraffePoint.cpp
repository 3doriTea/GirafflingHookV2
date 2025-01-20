#include "GiraffePoint.h"
#include "Player.h"
#include "GiraffePointRoot.h"

Play::GiraffePoint::GiraffePoint(
	const Vector3& position,
	Transform* _rootTransform,
	const int& _hTreeSource) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("GiraffePoint")
			.Position(position)
			.Scale({ 100.f, 100.f, 100.f })
	},
	player_{ nullptr },
	transform_{ *this },
	collider_{ *this, transform_ },
	hTreeModel_{ -1 },
	hTreeSource_{ _hTreeSource }
{
	transform_.SetParent(_rootTransform);
}

Play::GiraffePoint::~GiraffePoint()
{
}

void Play::GiraffePoint::Init()
{
	// MEMO: MV1LoadModelをすると無駄にメモリ領域食べちゃうため
	//     : 1度ロードしたモデルをそのまま、でも座標は別扱う
	hTreeModel_ = MV1DuplicateModel(hTreeSource_);
	assert(hTreeModel_ != -1);  // モデルのデュプリケートはできる
}

void Play::GiraffePoint::Update()
{
	MV1SetPosition(hTreeModel_,
		transform_.ToWorldPosition({ 0.f, 0.f, 0.f }) + Vector3{ 0.f, -150.f, 0.f });
	MV1SetRotationXYZ(hTreeModel_, transform_.GetRotateRadian());
	MV1SetScale(hTreeModel_, scale * 0.002f);
}

void Play::GiraffePoint::Draw() const
{
	MV1DrawModel(hTreeModel_);
	collider_.Draw();
}

void Play::GiraffePoint::End()
{
	MV1DeleteModel(hTreeModel_);
}
