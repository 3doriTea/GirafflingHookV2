#include "Frame.h"
#include "FrameManager.h"

float Frame::deltaTime{ 0.f };

int Frame::fps{ 0 };

float Frame::GetDeltaTime()
{
	return deltaTime;
}

int Frame::GetFPS()
{
	return fps;
}
