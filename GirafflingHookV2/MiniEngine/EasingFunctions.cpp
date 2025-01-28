#include "EasingFunctions.h"
#include <cmath>

namespace
{
	static const float PI{ std::acosf(-1.f) };
}

float Ease::OutBounce(float x)
{
	static const float n1 = 7.5625f;
	static const float d1 = 2.75f;

	if (x < 1.f / d1)
	{
		return n1 * x * x;
	}
	else if (x < 2.f / d1)
	{
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	}
	else if (x < 2.5f / d1)
	{
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	}
	else
	{
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}

float Ease::InOutExpo(float x)
{
	return x == 0.f
		? 0.f
		: x == 1.f
		? 1.f
		: x < 0.5f ? std::powf(2.f, 20.f * x - 10.f) / 2.f
		: (2.f - std::powf(2.f, -20.f * x + 10.f)) / 2.f;
}
