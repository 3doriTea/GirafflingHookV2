#include "Frame.h"
#include "FrameManager.h"

float Frame::deltaTime{ 0.0f };
int Frame::fps{ 0 };
float Frame::timeScale{ 1.0f };

float Frame::GetDeltaTime()
{
	return deltaTime * timeScale;
}

float Frame::GetTimeScale()
{
	return timeScale;
}

void Frame::SetTimeScale(const float& _scale)
{
	timeScale = _scale;
}

int Frame::GetFPS()
{
	return fps;
}
