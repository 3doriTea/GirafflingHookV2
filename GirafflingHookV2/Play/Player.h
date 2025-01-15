#pragma once
#include "GameObject.h"
#include "MiniEngine.h"
#include "Transform.h"
#include "AABBCollider.h"

namespace Play
{
	class GiraffePoint;

	class Player : public GameObject
	{
		enum struct State : int
		{
			Defualt,  // 普通の移動
			Shooting,  // グラッフラー発射
			Hooking,  // グラッフリング中
		};

	public:
		Player();
		~Player();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

		inline bool IsHooking() const { return hookTarget_ != nullptr; }
		/// <summary>
		/// フッキングするターゲットの座標を試しに取得
		/// </summary>
		/// <param name="outPosition">ターゲット座標の参照(/ なければ無変更)</param>
		/// <returns>取得に成功 true / false</returns>
		bool TryGetHookTargetPosition(Vector3& outPosition);

	private:
		/// <summary>
		/// 移動の更新 キー入力を移動方向に更新
		/// </summary>
		void UpdateMove();

		/// <summary>
		/// 普通の移動
		/// </summary>
		void MoveDefault();
		/// <summary>
		/// 発射
		/// </summary>
		void Shooting();
		/// <summary>
		/// グラッフリング移動
		/// </summary>
		void MoveHooking();

		/// <summary>
		/// グラッフリング開始
		/// </summary>
		void StartHooking();
		/// <summary>
		/// グラッフリング終了
		/// </summary>
		void FinishHooking();

		/// <summary>
		/// 首の長さをアニメーション時間に変換する
		/// </summary>
		/// <param name="length">首の長さ</param>
		/// <returns>アニメーション時間</returns>
		float LengthToAnimationTime(float length);

	private:
		Transform transform_;
		OBBCollider collider_;
		Rigidbody rigidbody_;

		float animationTime_;     // グラッフリング中のアニメーション時間
		// MEMO: 距離によってアニメーションをストップさせる時間を変更している
		float animationTimeMax_;  // グラッフリング中のアニメーション時間最大
		int hGiraffeMV1_;
		float hookDistance_;
		int hTextureImage_;

		GiraffePoint* hookTarget_;  // グラッフリングするターゲット

		State state_;  // プレイヤーの状態
		Vector3 move_;
		int moveSign_;

	private:
		// MEMO: キリンの首は5000伸びる
		static const float NECK_LENGTH_MAX;
		static const float HOOKING_ANIMATION_TIME_MAX;
		// 1秒間あたり何アニメーション時間進めるか
		static const float HOOKING_ANIMATION_SPEED;
		// 何も動作しない空白の時間
		static const float HOOKING_ANIMATION_OFFSET_IDOL_TIME;
		// ズレを解消するための手作業オフセット
		static const float HOOKING_ANIMATION_OFFSET_TIME;

		// 移動する力
		static const float MOVE_FORCE;
	};
}
