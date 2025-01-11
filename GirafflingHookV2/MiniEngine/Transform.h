#pragma once
#include "Attachment.h"
#include "Vector2.h"
#include <DirectXMath.h>
#include <set>
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
	/// 親の座標変換系を設定
	/// </summary>
	/// <param name="parent">親の座標変換系 / 親無し nullptr</param>
	void SetParent(Transform* parent);
	/// <summary>
	/// 親の座標変換系を取得
	/// </summary>
	/// <returns>親の座標変換系 / 親無し nullptr</returns>
	inline Transform* GetParent() { return parent_; }

private:
	DirectX::XMMATRIX GetWorldMatrix();

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

