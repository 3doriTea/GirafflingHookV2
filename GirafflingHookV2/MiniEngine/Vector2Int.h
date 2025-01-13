#pragma once

struct Vector2;

/// <summary>
/// 2次元の整数型ベクトル
/// </summary>
struct Vector2Int
{
	int x;  // x成分
	int y;  // y成分

	Vector2Int() :
		x{ 0 },
		y{ 0 }
	{}

	Vector2Int(const int& x, const int& y) :
		x{ x },
		y{ y }
	{}

#pragma region 四則演算
	Vector2Int& operator*=(const int&);
	Vector2Int& operator/=(const int&);
	Vector2Int& operator+=(const Vector2Int&);
	Vector2Int& operator-=(const Vector2Int&);
#pragma endregion

#pragma region キャスト
	explicit operator Vector2() const noexcept;
#pragma endregion
};

#pragma region グローバルオペレータ
Vector2Int operator*(const Vector2Int& v, const int& scalar);
Vector2Int operator*(const int& scalar, const Vector2Int& v);
Vector2Int operator/(const Vector2Int& v, const int& scalar);
Vector2Int operator/(const int& scalar, const Vector2Int& v);
Vector2Int operator+(const Vector2Int& v1, const Vector2Int& v2);
Vector2Int operator-(const Vector2Int& v1, const Vector2Int& v2);

bool operator==(const Vector2Int& v1, const Vector2Int& v2);
bool operator!=(const Vector2Int& v1, const Vector2Int& v2);
#pragma endregion
