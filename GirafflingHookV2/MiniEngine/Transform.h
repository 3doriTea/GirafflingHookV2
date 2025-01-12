#pragma once
#include "Attachment.h"
#include "Vector2.h"
#include <DirectXMath.h>
#include <set>
#include <cmath>
#include "Vector3.h"

class GameObject;

class Transform : public Attachment
{
public:
	/// <summary>
	/// 座標変換をするアタッチメント
	/// </summary>
	/// <param name="attachingGameObject">アタッチする対象のゲームオブジェクト</param>
	Transform(GameObject& attachingGameObject);
	~Transform();

	void Draw() const override;

	/// <summary>
	/// 座標、回転、大きさのパラメータを座標変換した行列を計算して更新
	/// </summary>
	void UpdateCalculate();
	/// <summary>
	/// ローカル座標をワールド座標に変換
	/// </summary>
	/// <param name="localPosition">アタッチされたゲームオブジェクト基準のローカル座標</param>
	/// <returns>ワールド座標</returns>
	Vector3 ToWorldPosition(const Vector3& localPosition);
	/// <summary>
	/// 任意の軸を指定座標の方向に向ける
	/// </summary>
	/// <param name="forwardDirection">向けたい任意の軸</param>
	/// <param name="targetPosition">向けたい座標</param>
	void LookAt(Vector3 forwardDirection, const Vector3& targetPosition);
	/// <summary>
	/// 親の座標変換系を設定
	/// </summary>
	/// <param name="parent">親の座標変換系 / 親無し nullptr</param>
	void SetParent(Transform* parent);
	/// <summary>
	/// 親の座標変換系を取得
	/// </summary>
	/// <returns>親の座標変換系 / 親無し nullptr</returns>
	inline Transform* GetParent() { return parent_; }
	/// <summary>
	/// 座標を取得する
	/// </summary>
	/// <returns>座標(コピー値)</returns>
	inline Vector3 GetPosition() const { return position; }
	/// <summary>
	/// 回転を取得する
	/// </summary>
	/// <returns>回転(コピー値)</returns>
	inline Vector3 GetRotate() const { return rotate; }
	/// <summary>
	/// 回転をラジアンで取得する
	/// </summary>
	/// <returns>ラジアンの回転(コピー値)</returns>
	inline Vector3 GetRotateRadian() const { return rotate * (std::acosf(-1.f) / 180.f); }
	/// <summary>
	/// 大きさを取得する
	/// </summary>
	/// <returns>大きさ(コピー値)</returns>
	inline Vector3 GetScale() const { return scale; }

private:
	DirectX::XMMATRIX GetWorldTranslateMatrix();

public:
	Vector3& position;
	Vector3& rotate;
	Vector3& scale;

private:
	DirectX::XMMATRIX positionMatrix_;
	DirectX::XMMATRIX rotateMatrix_;
	DirectX::XMMATRIX scaleMatrix_;

	Transform* parent_;
	std::set<Transform*> childs_;
};

