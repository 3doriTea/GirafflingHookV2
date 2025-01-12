#include "GiraffePoint.h"
#include "Player.h"

Play::GiraffePoint::GiraffePoint(const Vector3& position) :
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
	hTreeModel_{ -1 }
{
}

Play::GiraffePoint::~GiraffePoint()
{
}

void Play::GiraffePoint::Init()
{
	hTreeModel_ = MV1LoadModel("Assets/Play/voxeltree.mv1");

	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // ÉvÉåÉCÉÑÅ[ÇÕå©Ç¬Ç©ÇÈ
}

void Play::GiraffePoint::Update()
{
	MV1SetPosition(hTreeModel_, transform_.ToWorldPosition({ 0.f, -1.5f, 0.f }));
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
