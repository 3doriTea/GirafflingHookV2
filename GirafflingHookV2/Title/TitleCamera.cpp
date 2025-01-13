#include "TitleCamera.h"
#include "MiniEngine.h"

Title::TitleCamera::TitleCamera() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("MainCamera")
			.Position(BASE_POSITION)
	},
	mouseX_{},
	mouseY_{}
{
}

Title::TitleCamera::~TitleCamera()
{
}

void Title::TitleCamera::Init()
{
}

void Title::TitleCamera::Update()
{
	GetMousePoint(&mouseX_, &mouseY_);

	Vector3 viewportMouse{ Vector3::From((Vector2)Screen::ToViewportPosition(mouseX_, mouseY_)) };
	viewportMouse -= { Screen::WIDTH / 2.f, Screen::HEIGHT / 2.f, 0.f };
	viewportMouse *= 0.1f;

	position = viewportMouse + BASE_POSITION;
	SetCameraPositionAndAngle(position, 0.f, 0.f, 0.f);
}

void Title::TitleCamera::Draw() const
{
	DrawCircle(mouseX_, mouseY_, 30, 0xff00ff, TRUE);
}

const Vector3 Title::TitleCamera::BASE_POSITION{ 0.f, 0.f, -500.f };
