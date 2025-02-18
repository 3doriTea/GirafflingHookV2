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
	hVS{ -1 },
	hPS{ -1 },
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
	assert(hSkySphere_ > 0);  // SkySphereモデルは読み込まれる

	//hVS = LoadVertexShader("Assets/Shader/NoShadePS.vso");
	////hVS = LoadVertexShader("./NoShadeVS.vso");
	//assert(hVS > 0);  // NoShadeVシェーダは読み込まれる
	//hPS = LoadPixelShader("Assets/Shader/NoShadePS.pso");
	////hPS = LoadPixelShader("./NoShadePS.pso");
	//assert(hPS > 0);  // NoShadeSシェーダは読み込まれる


	camera_ = FindGameObject<Camera>();
	assert(camera_ != nullptr);  // カメラは見つかる

	//MV1SetDifColorScale(hSkySphere_, GetColorF(1.0f, 1.0f, 1.0f, 1.0f));
	SetUseLighting(FALSE);

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
	/*MV1SetUseOrigShader(TRUE);
	SetUseVertexShader(hVS);
	SetUsePixelShader(hPS);*/

	MV1DrawModel(hSkySphere_);

	//MV1SetUseOrigShader(FALSE);
	//SetUseVertexShader(FALSE);
	//SetUsePixelShader(FALSE);
}

void Play::SkySphere::End()
{
	SetUseLighting(TRUE);
	MV1DeleteModel(hSkySphere_);
}
