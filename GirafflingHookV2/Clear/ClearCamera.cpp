#include "ClearCamera.h"
#include "MiniEngine.h"

Clear::ClearCamera::ClearCamera() :
	GameObject
{
	GameObjectBuilder{}
		.Name("MainCamera")
		.Position(BASE_POSITION)
},
mouseX_{},
mouseY_{}
{
}

Clear::ClearCamera::~ClearCamera()
{
}

void Clear::ClearCamera::Init()
{
}

void Clear::ClearCamera::Update()
{
	GetMousePoint(&mouseX_, &mouseY_);

	Vector3 viewportMouse{ Vector3::From((Vector2)Screen::ToViewportPosition(mouseX_, mouseY_)) };
	viewportMouse -= { Screen::WIDTH / 2.f, Screen::HEIGHT / 2.f, 0.f };
	viewportMouse *= 0.1f;

	position = viewportMouse + BASE_POSITION;
	SetCameraPositionAndAngle(position, 0.f, 0.f, 0.f);
}

void Clear::ClearCamera::Draw() const
{
	DrawCircle(mouseX_, mouseY_, 30, 0xff00ff, TRUE);
}

const Vector3 Clear::ClearCamera::BASE_POSITION{ 0.f, 0.f, -500.f };