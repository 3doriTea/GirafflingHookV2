#include "Ground.h"
#include <DxLib.h>
#include <cassert>

Play::Ground::Ground() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("Ground")
			.Position({ 0.f, -400.f, 0.f })
			.Scale({ 3000.f, 30000.f, 1000.f })
			.Rotate({0, 90, 0})
	/*
	* .Name("Ground")
			.Position({ 0.f, -400.f, 0.f })
			.Scale({ 3000.f, 100.f, 1000.f })
	*/
	},
	//transform_{ *this },
	//collider_{ *this, transform_ },
	hBoxModel_{ -1 },
	hTestCube_{ -1 }
{
}

Play::Ground::~Ground()
{
}

void Play::Ground::Init()
{
	hBoxModel_ = MV1LoadModel("Assets/Play/ground.mv1");
	assert(hBoxModel_ != -1);
	hTestCube_ = MV1LoadModel("Assets/Play/testcube.mv1");
	assert(hTestCube_ != -1);
}

void Play::Ground::Update()
{
	//MV1SetPosition(hBoxModel_, transform_.ToWorldPosition({}));
	//MV1SetScale(hBoxModel_, scale * 0.005f);

	//DxLib::MV1SetRotationXYZ(hBoxModel_, transform_.GetRotateRadian());
	//DxLib::MV1SetPosition(hBoxModel_, position);
	//DxLib::MV1SetScale(hBoxModel_, scale * 0.002f);

	//MV1SetPosition(hTestCube_, transform_.ToWorldPosition({}));
	//MV1SetRotationXYZ(hTestCube_, transform_.GetRotateRadian());
	//MV1SetScale()
}

void Play::Ground::Draw() const
{
	//collider_.Draw();
	MV1DrawModel(hBoxModel_);
	MV1DrawModel(hTestCube_);
}

void Play::Ground::End()
{
	MV1DeleteModel(hBoxModel_);
	MV1DeleteModel(hTestCube_);
}
