#include "Box2.h"

Box2::Box2() :
	Box2::Box2{ 0.f, 0.f, 0.f, 0.f }
{
}

Box2::Box2(const Vector2& _min, const Vector2& _max) :
	min{ _min },
	max{ _max }
{
}

Box2::Box2(const float& aX, const float& aY, const float& bX, const float& bY) :
	min{},
	max{}
{
	if (aX < bX)
	{
		min.x = aX;
		max.x = bX;
	}
	else
	{
		min.x = bX;
		max.x = aX;
	}

	if (aY < bY)
	{
		min.y = aY;
		max.y = bY;
	}
	else
	{
		min.y = bY;
		max.y = aY;
	}
}

Box2::~Box2()
{
}

Box2& Box2::operator+=(const Vector2& other)
{
	min += other;
	max += other;

	return *this;
}

Box2& Box2::operator-=(const Vector2& other)
{
	min -= other;
	max -= other;

	return *this;
}

Box2& Box2::operator*=(const float& scale)
{
	min *= scale;
	max *= scale;

	return *this;
}

Box2& Box2::operator/=(const float& scale)
{
	min /= scale;
	max /= scale;

	return *this;
}
