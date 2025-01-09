#pragma once
#include <DirectXMath.h>


struct Vector3 : public DirectX::XMFLOAT3
{
	Vector3();
	Vector3(const float& x, const float& y, const float& z);
	~Vector3();

	Vector3& operator*=(const float& scale);
	Vector3& operator/=(const float& scale);
	Vector3& operator%=(const float& scale);
	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	explicit operator VECTOR() const;

	float Length() const;
	Vector3& Normalize();
};

inline Vector3 operator*(const Vector3& v, const float& scale) { return Vector3{ v } *= scale; }
inline Vector3 operator/(const Vector3& v, const float& scale) { return Vector3{ v } /= scale; }
inline Vector3 operator%(const Vector3& v, const float& scale) { return Vector3{ v } %= scale; }
inline Vector3 operator+(const Vector3& v1, const Vector3& v3) { return Vector3{ v1 } += v3; }
inline Vector3 operator-(const Vector3& v1, const Vector3& v3) { return Vector3{ v1 } -= v3; }

inline float Length(const Vector3& v) { return v.Length(); }
inline Vector3 Normalize(const Vector3& v) { return Vector3{ v }.Normalize(); }


