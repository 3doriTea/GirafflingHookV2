#include "GiraffePoint.h"
#include "Player.h"
#include "GiraffePointRoot.h"
#include "Screen.h"
#include "HookArrow.h"

Play::GiraffePoint::GiraffePoint(
	const Vector3& position) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("GiraffePoint")
			.Position({ position.x, Screen::HEIGHT - position.y, position.z })
			.Scale({ 100.f, 100.f, 100.f })
	},
	player_{ nullptr },
	transform_{ *this },
	collider_{ *this, transform_ },
	hTreeModel_{ -1 },
	hTreeSource_{ GiraffePointRoot::GetTreeModelSourceHandle() }
{
	transform_.SetParent(GiraffePointRoot::GetGroundTransform());
}

Play::GiraffePoint::GiraffePoint(
	const std::string& name,
	const Vector3& position) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name(name)
			.Position(position)
			.Scale({ 100.f, 100.f, 100.f })
	},
	player_{ nullptr },
	transform_{ *this },
	collider_{ *this, transform_ },
	hTreeModel_{ -1 },
	hTreeSource_{ GiraffePointRoot::GetTreeModelSourceHandle() }
{
}

Play::GiraffePoint::~GiraffePoint()
{
}

void Play::GiraffePoint::Init()
{
	FindGameObject<HookArrow>()->RegisterGiraffePoint(this);

	// MEMO: MV1LoadModelをすると無駄にメモリ領域食べちゃうため
	//     : 1度ロードしたモデルをそのまま、でも座標は別扱う
	hTreeModel_ = MV1DuplicateModel(hTreeSource_);
	assert(hTreeModel_ != -1);  // モデルのデュプリケートはできる
}

void Play::GiraffePoint::Update()
{
	MV1SetPosition(
		hTreeModel_,
		transform_.ToWorldPosition({ 0.f, 0.f, 0.f })
		+ Vector3{ 0.f, -150.f, 0.f });
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
	FindGameObject<HookArrow>()->UnregisterGiraffePoint(this);
	MV1DeleteModel(hTreeModel_);
}

Vector3 Play::GiraffePoint::GetHookPosition() const
{
	return transform_.ToWorldPosition(Vector3::Zero());
}
