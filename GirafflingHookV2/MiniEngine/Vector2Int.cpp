#include "Vector2Int.h"
#include "Vector2.h"

#pragma region �l�����Z
Vector2Int& Vector2Int::operator*=(const int& scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}
Vector2Int& Vector2Int::operator/=(const int& scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}
Vector2Int& Vector2Int::operator+=(const Vector2Int& other)
{
	x += other.x;
	y += other.y;
	return *this;
}
Vector2Int& Vector2Int::operator-=(const Vector2Int& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}
#pragma endregion

#pragma region �L���X�g
Vector2Int::operator Vector2() const noexcept
{
	return Vector2
	{
		static_cast<float>(x),
		static_cast<float>(y)
	};
}
#pragma endregion

#pragma region �O���[�o���I�y���[�^
Vector2Int operator*(const Vector2Int& v, const int& scalar) { return Vector2Int(v) *= scalar; }
Vector2Int operator*(const int& scalar, const Vector2Int& v) { return Vector2Int(v) *= scalar; }
Vector2Int operator/(const Vector2Int& v, const int& scalar) { return Vector2Int(v) /= scalar; }
Vector2Int operator/(const int& scalar, const Vector2Int& v) { return Vector2Int(v) /= scalar; }
Vector2Int operator+(const Vector2Int& v1, const Vector2Int& v2) { return Vector2Int(v1) += v2; }
Vector2Int operator-(const Vector2Int& v1, const Vector2Int& v2) { return Vector2Int(v1) -= v2; }

bool operator==(const Vector2Int& v1, const Vector2Int& v2)
{
	return v1.x - v2.x == 0 && v1.y - v2.y == 0;
}
bool operator!=(const Vector2Int& v1, const Vector2Int& v2)
{
	return !(v1 == v2);
}
#pragma endregion
