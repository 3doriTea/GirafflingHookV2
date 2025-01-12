#pragma once
#include <DirectXMath.h>
#include <DxLib.h>

/// <summary>
/// DirectX::XMFLOAT3の継承、DxLib::VECTORへ変換可能な3次元のベクトル
/// </summary>
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

	float& operator[](const size_t& index);

	// DxLibのVECTORへの型変換
	// MEMO: explicitを付けず、暗黙的な変換が可能
	operator VECTOR() const;
	// DirectXのXMVECTORへの型変換
	// MEMO: explicitを付けず、暗黙的な変換が可能
	operator DirectX::XMVECTOR() const;

	float Length() const;
	Vector3& Normalize();

	/// <summary>
	/// DirectX::XMFLOAT3からVector3に変換
	/// </summary>
	/// <param name="from">変換したいDirectX::XMFLOAT3</param>
	/// <returns>変換後のVector3</returns>
	static Vector3 From(const DirectX::XMFLOAT3& from);
	/// <summary>
	/// DxLib::VECTORからVector3に変換
	/// </summary>
	/// <param name="from">変換したいDxLib::VECTOR</param>
	/// <returns>変換後のVector3</returns>
	static Vector3 From(const DxLib::VECTOR& from);
	/// <summary>
	/// 零ベクトルを取得
	/// </summary>
	/// <returns>零ベクトル</returns>
	static inline Vector3 Zero() { return { 0.f, 0.f, 0.f }; }
	/// <summary>
	/// 成分がすべて1のベクトルを取得
	/// </summary>
	/// <returns>成分がすべて1のベクトル</returns>
	static inline Vector3 One() { return { 1.f, 1.f, 1.f }; }
};

inline Vector3 operator*(const Vector3& v, const float& scale) { return Vector3{ v } *= scale; }
inline Vector3 operator/(const Vector3& v, const float& scale) { return Vector3{ v } /= scale; }
inline Vector3 operator%(const Vector3& v, const float& scale) { return Vector3{ v } %= scale; }
inline Vector3 operator+(const Vector3& v1, const Vector3& v3) { return Vector3{ v1 } += v3; }
inline Vector3 operator-(const Vector3& v1, const Vector3& v3) { return Vector3{ v1 } -= v3; }

inline float Length(const Vector3& v) { return v.Length(); }
inline Vector3 Normalize(const Vector3& v) { return Vector3{ v }.Normalize(); }


