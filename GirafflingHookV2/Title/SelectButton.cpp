#include "SelectButton.h"
#include "MiniEngine.h"
#include <cassert>

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
	hButtonModel_{ -1 }
{
}

Title::SelectButton::~SelectButton()
{
}

void Title::SelectButton::Init()
{
	hButtonModel_ = MV1LoadModel(("Assets/UI/" + buttonId_).c_str());
	assert(hButtonModel_ != -1);

	MV1SetPosition(hButtonModel_, position);
	// TODO: transform_.LookAt()
}

void Title::SelectButton::Update()
{
}

void Title::SelectButton::Draw() const
{
	MV1DrawModel(hButtonModel_);
}

void Title::SelectButton::End()
{
	MV1DeleteModel(hButtonModel_);
}
