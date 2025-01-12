#include "SelectButton.h"
#include <DxLib.h>
#include <cassert>
#include "TitleCamera.h"

Title::SelectButton::SelectButton(
	const std::string& buttonId,
	const Vector3& position) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name(buttonId)
			.Position(position)
	},
	buttonId_{ buttonId },
	transform_{ *this },
	hButtonModel_{ -1 },
	camera_{ nullptr }
{
}

Title::SelectButton::~SelectButton()
{
}

void Title::SelectButton::Init()
{
	hButtonModel_ = MV1LoadModel(("Assets/UI/" + buttonId_ + ".mv1").c_str());
	assert(hButtonModel_ != -1);

	camera_ = FindGameObject<TitleCamera>();
	assert(camera_ != nullptr);  // ƒJƒƒ‰‚Í•K‚¸Œ©‚Â‚©‚é
}

void Title::SelectButton::Update()
{
	MV1SetPosition(hButtonModel_, position);
	transform_.LookAt({ 0.f, 0.f, -1.f }, camera_->position);
	MV1SetRotationXYZ(hButtonModel_, transform_.GetRotateRadian());
}

void Title::SelectButton::Draw() const
{
	MV1DrawModel(hButtonModel_);
}

void Title::SelectButton::End()
{
	MV1DeleteModel(hButtonModel_);
}
