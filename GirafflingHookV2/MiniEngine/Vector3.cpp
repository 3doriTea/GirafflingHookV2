#include "Vector3.h"
#include <cmath>
#include <DxLib.h>

Vector3::Vector3() :
	Vector3::Vector3{ 0.f, 0.f, 0.f }
{
}

Vector3::Vector3(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3& Vector3::operator*=(const float& scale)
{
	this->x *= scale;
	this->y *= scale;
	this->z *= scale;

	return *this;
}

Vector3& Vector3::operator/=(const float& scale)
{
	this->x /= scale;
	this->y /= scale;
	this->z /= scale;

	return *this;
}

Vector3& Vector3::operator%=(const float& scale)
{
	this->x = std::fmodf(this->x, scale);
	this->y = std::fmodf(this->y, scale);
	this->z = std::fmodf(this->z, scale);

	return *this;
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

Vector3::operator VECTOR() const
{
	return VECTOR{ this->x, this->y, this->z };
}

float Vector3::Length() const
{
	return std::sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector3& Vector3::Normalize()
{
	(*this) / Length();

	return *this;
}
