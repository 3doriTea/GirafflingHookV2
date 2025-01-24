#pragma once
#include "GameScene.h"

namespace Play
{
	class Player;
	class Goal;
}

class PlayScene : public GameScene
{
public:
	PlayScene();
	~PlayScene();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;

	/// <summary>
	/// プレイヤーがゴールしたかどうか
	/// </summary>
	/// <returns>ゴールした true / false</returns>
	inline bool IsPlayerGoaled() const { return isPlayerGoaled_; }
	
	/// <summary>
	/// ゴールアニメーションも終わった
	/// </summary>
	void FinishedGoalAnimation();

	/// <summary>
	/// ゴールした
	/// </summary>
	void GoalPlayer();

private:
	Play::Player* player_;
	Play::Goal* goal_;
	
	bool isPlayerGoaled_;
	//static int stageNumber;
};
