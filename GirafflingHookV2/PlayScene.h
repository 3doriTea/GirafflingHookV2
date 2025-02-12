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

	inline int GetScore() const { return score_; }
	void AddScore(const int& scorePoint);

private:
	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;

private:
	Play::Player* player_;
	Play::Goal* goal_;

	float playTimer_;  // カウントアップタイマー
	
	bool isPlayerGoaled_;
	int score_;
	//static int stageNumber;
};
