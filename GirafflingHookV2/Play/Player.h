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
	public:
		Player();
		~Player();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

		inline bool IsHooking() const { return isHooking_; }
		/// <summary>
		/// フッキングするターゲットの座標を試しに取得
		/// </summary>
		/// <param name="outPosition">ターゲット座標の参照(/ なければ無変更)</param>
		/// <returns>取得に成功 true / false</returns>
		bool TryGetHookTargetPosition(Vector3& outPosition);

	private:
		void MoveDefault();
		void MoveHooking();

	private:
		Transform transform_;
		AABBCollider collider_;
		float animationTime_;     // グラッフリング中のアニメーション時間
		// MEMO: 距離によってアニメーションをストップさせる時間を変更している
		float animationTimeMax_;  // グラッフリング中のアニメーション時間最大
		int hGiraffeMV1_;
		bool isHooking_;

		GiraffePoint* hookTarget_;  // グラッフリングするターゲット

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
	};
}
