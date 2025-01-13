#pragma once

struct Vector2;

/// <summary>
/// 2�����̐����^�x�N�g��
/// </summary>
struct Vector2Int
{
	int x;  // x����
	int y;  // y����

	Vector2Int() :
		x{ 0 },
		y{ 0 }
	{}

	Vector2Int(const int& x, const int& y) :
		x{ x },
		y{ y }
	{}

#pragma region �l�����Z
	Vector2Int& operator*=(const int&);
	Vector2Int& operator/=(const int&);
	Vector2Int& operator+=(const Vector2Int&);
	Vector2Int& operator-=(const Vector2Int&);
#pragma endregion

#pragma region �L���X�g
	explicit operator Vector2() const noexcept;
#pragma endregion
};

#pragma region �O���[�o���I�y���[�^
Vector2Int operator*(const Vector2Int& v, const int& scalar);
Vector2Int operator*(const int& scalar, const Vector2Int& v);
Vector2Int operator/(const Vector2Int& v, const int& scalar);
Vector2Int operator/(const int& scalar, const Vector2Int& v);
Vector2Int operator+(const Vector2Int& v1, const Vector2Int& v2);
Vector2Int operator-(const Vector2Int& v1, const Vector2Int& v2);

bool operator==(const Vector2Int& v1, const Vector2Int& v2);
bool operator!=(const Vector2Int& v1, const Vector2Int& v2);
#pragma endregion
