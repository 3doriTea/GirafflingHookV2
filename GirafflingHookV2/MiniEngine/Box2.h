#pragma once
#include "Vector2.h"

struct Box2
{
	Vector2 min;
	Vector2 max;

	Box2();
	Box2(const Vector2& min, const Vector2& max);
	Box2(const float& a, const float& b, const float& c, const float& d);
	virtual ~Box2();

	Box2& operator+=(const Vector2& other);
	Box2& operator-=(const Vector2& other);
	Box2& operator*=(const float& scale);
	Box2& operator/=(const float& scale);
};

inline Box2 operator+(const Box2& v1, const Vector2& v2) { return Box2{ v1 } += v2; }
inline Box2 operator-(const Box2& v1, const Vector2& v2) { return Box2{ v1 } -= v2; }
inline Box2 operator*(const Box2& v, const float& scale) { return Box2{ v } *= scale; }
inline Box2 operator/(const Box2& v, const float& scale) { return Box2{ v } /= scale; }
