#include "SkySphere.h"
#include "Camera.h"
#include "Frame.h"

namespace
{
	static const float MOVE_SPEED{ 30.0f };
}

Play::SkySphere::SkySphere() :
	GameObject
	{
		GameObjectBuilder{}
			.LayerOrder(LayerOrderType::Background - 20)
			.Name("SkySphere")
			.Rotate({ -90.0f, 0.0f, 0.0f })
			.Scale({ 100.0f, 100.0f, 100.0f })
	},
	hSkySphere_{ -1 },
	transform_{ *this },
	camera_{ nullptr }
{
}

Play::SkySphere::~SkySphere()
{
}

void Play::SkySphere::Init()
{
	hSkySphere_ = MV1LoadModel("Assets/SkySphere.mv1");
	assert(hSkySphere_ > 0);  // SkySphereÉÇÉfÉãÇÕì«Ç›çûÇ‹ÇÍÇÈ

	camera_ = FindGameObject<Camera>();
	assert(camera_ != nullptr);  // ÉJÉÅÉâÇÕå©Ç¬Ç©ÇÈ

	MV1SetScale(hSkySphere_, scale);
}

void Play::SkySphere::Update()
{
	position = camera_->position;
	rotate.y += MOVE_SPEED * Frame::GetDeltaTime();

	MV1SetPosition(hSkySphere_, position);
	MV1SetRotationXYZ(hSkySphere_, transform_.GetRotateRadian());
}

void Play::SkySphere::Draw() const
{
	MV1DrawModel(hSkySphere_);
}

void Play::SkySphere::End()
{
	MV1DeleteModel(hSkySphere_);
}
