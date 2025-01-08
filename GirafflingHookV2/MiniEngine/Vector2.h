#pragma once
#include "DirectXMath.h"

struct Vector2 : public DirectX::XMFLOAT2
{
	Vector2();
	Vector2(const float& x, const float& y);
	~Vector2();

	Vector2& operator*=(const float& scale);
	Vector2& operator/=(const float& scale);
	Vector2& operator%=(const float& scale);
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);

	float Length() const;
	Vector2& Normalize();
};

inline Vector2 operator*(const Vector2& v, const float& scale) { return Vector2{ v } *= scale; }
inline Vector2 operator/(const Vector2& v, const float& scale) { return Vector2{ v } /= scale; }
inline Vector2 operator%(const Vector2& v, const float& scale) { return Vector2{ v } %= scale; }
inline Vector2 operator+(const Vector2& v1, const Vector2& v2) { return Vector2{ v1 } += v2; }
inline Vector2 operator-(const Vector2& v1, const Vector2& v2) { return Vector2{ v1 } -= v2; }

inline float Length(const Vector2& v) { return v.Length(); }
inline Vector2 Normalize(const Vector2& v) { return Vector2{ v }.Normalize(); }
