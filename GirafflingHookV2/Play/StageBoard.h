#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Vector3.h"
#include "AABBCollider.h"
#include "Transform.h"

namespace Play
{
	/// <summary>
	/// Draw.ioで設計したステージの簡易壁ゲームオブジェクト
	/// </summary>
	class StageBoard : public GameObject
	{
	public:
		/// <summary>
		/// Draw.ioの設計をそのままいれる
		/// </summary>
		/// <param name="topLeftDrawPosition">物体左上の座標</param>
		/// <param name="widthHeight">物体の幅</param>
		/// <param name="angle">物体の角度</param>
		StageBoard(
			const Vector2& topLeftDrawPosition,
			const Vector2& widthHeight,
			const float& angle = 0.f);
		/// <summary>
		/// Unityからのコンバート向けのコンストラクタ
		/// </summary>
		/// <param name="name">オブジェクト名</param>
		/// <param name="position">設置座標</param>
		/// <param name="scale">設置スケール</param>
		StageBoard(
			const std::string& _name,
			const Vector3& _position,
			const Vector3& _scale);
		~StageBoard();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		AABBCollider collider_;
		Transform transform_;

		int hBoxModel_;
	};
}
