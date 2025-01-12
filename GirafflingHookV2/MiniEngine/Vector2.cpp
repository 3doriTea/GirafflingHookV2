#include "Vector2.h"
#include <cmath>

Vector2::Vector2() :
	Vector2::Vector2{ 0.f, 0.f }
{
}

Vector2::Vector2(const float& x, const float& y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

Vector2& Vector2::operator*=(const float& scale)
{
	this->x *= scale;
	this->y *= scale;

	return *this;
}

Vector2& Vector2::operator/=(const float& scale)
{
	this->x /= scale;
	this->y /= scale;

	return *this;
}

Vector2& Vector2::operator%=(const float& scale)
{
	this->x = std::fmodf(this->x, scale);
	this->y = std::fmodf(this->y, scale);

	return *this;
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	this->x += other.x;
	this->y += other.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	this->x -= other.x;
	this->y -= other.y;

	return *this;
}

float Vector2::Length() const
{
	return std::sqrtf(this->x * this->x + this->y + this->y);
}

Vector2& Vector2::Normalize()
{
	(*this) /= Length();

	return *this;
}
