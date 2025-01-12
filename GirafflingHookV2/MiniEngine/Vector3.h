#pragma once
#include <DirectXMath.h>
#include <DxLib.h>

/// <summary>
/// DirectX::XMFLOAT3�̌p���ADxLib::VECTOR�֕ϊ��\��3�����̃x�N�g��
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

	// DxLib��VECTOR�ւ̌^�ϊ�
	// MEMO: explicit��t�����A�ÖٓI�ȕϊ����\
	operator VECTOR() const;
	// DirectX��XMVECTOR�ւ̌^�ϊ�
	// MEMO: explicit��t�����A�ÖٓI�ȕϊ����\
	operator DirectX::XMVECTOR() const;

	float Length() const;
	Vector3& Normalize();

	/// <summary>
	/// DirectX::XMFLOAT3����Vector3�ɕϊ�
	/// </summary>
	/// <param name="from">�ϊ�������DirectX::XMFLOAT3</param>
	/// <returns>�ϊ����Vector3</returns>
	static Vector3 From(const DirectX::XMFLOAT3& from);
	/// <summary>
	/// DxLib::VECTOR����Vector3�ɕϊ�
	/// </summary>
	/// <param name="from">�ϊ�������DxLib::VECTOR</param>
	/// <returns>�ϊ����Vector3</returns>
	static Vector3 From(const DxLib::VECTOR& from);
	/// <summary>
	/// ��x�N�g�����擾
	/// </summary>
	/// <returns>��x�N�g��</returns>
	static inline Vector3 Zero() { return { 0.f, 0.f, 0.f }; }
	/// <summary>
	/// ���������ׂ�1�̃x�N�g�����擾
	/// </summary>
	/// <returns>���������ׂ�1�̃x�N�g��</returns>
	static inline Vector3 One() { return { 1.f, 1.f, 1.f }; }
};

inline Vector3 operator*(const Vector3& v, const float& scale) { return Vector3{ v } *= scale; }
inline Vector3 operator/(const Vector3& v, const float& scale) { return Vector3{ v } /= scale; }
inline Vector3 operator%(const Vector3& v, const float& scale) { return Vector3{ v } %= scale; }
inline Vector3 operator+(const Vector3& v1, const Vector3& v3) { return Vector3{ v1 } += v3; }
inline Vector3 operator-(const Vector3& v1, const Vector3& v3) { return Vector3{ v1 } -= v3; }

inline float Length(const Vector3& v) { return v.Length(); }
inline Vector3 Normalize(const Vector3& v) { return Vector3{ v }.Normalize(); }


