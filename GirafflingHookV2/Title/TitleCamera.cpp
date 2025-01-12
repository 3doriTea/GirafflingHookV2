#include "TitleCamera.h"
#include "MiniEngine.h"

Title::TitleCamera::TitleCamera() :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name("MainCamera")
			.Position({ 0.f, 0.f, -500.f })
	}
{
}

Title::TitleCamera::~TitleCamera()
{
}

void Title::TitleCamera::Init()
{
	SetCameraPositionAndAngle(position, 0.f, 0.f, 0.f);
}
