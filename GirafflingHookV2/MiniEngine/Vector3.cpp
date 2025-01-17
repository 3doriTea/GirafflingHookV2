#include "Vector3.h"
#include <cmath>
#include <cassert>
#include "Vector2.h"

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

Vector3& Vector3::Set(const Vector3& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

Vector3& Vector3::Set(Vector3 other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

Vector3& Vector3::Set(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	return *this;
}

float& Vector3::operator[](const size_t& index)
{
	assert(0 <= index && index < 3);

	switch (index)
	{
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	}
}

Vector3::operator VECTOR() const
{
	return VECTOR{ this->x, this->y, this->z };
}

Vector3::operator DirectX::XMVECTOR() const
{
	return DirectX::XMVECTOR{ this->x, this->y, this->z };
}

float Vector3::Length() const
{
	return std::sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector3& Vector3::Normalize()
{
	(*this) /= Length();

	return *this;
}

float Vector3::Distance(const Vector3& to) const
{
	return (to - (*this)).Length();
}

Vector3 Vector3::Abs() const
{
	return
	{
		std::fabsf(this->x),
		std::fabsf(this->y),
		std::fabsf(this->z)
	};
}

Vector3 Vector3::From(const Vector2& from, const float& z)
{
	return Vector3{ from.x, from.y, z };
}

Vector3 Vector3::From(const DirectX::XMFLOAT3& from)
{
	return Vector3{ from.x, from.y, from.z };
}

Vector3 Vector3::From(const DxLib::VECTOR& from)
{
	return Vector3{ from.x, from.y, from.z };
}
