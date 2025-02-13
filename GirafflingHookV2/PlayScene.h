#pragma once
#include "GameScene.h"
#include <random>

namespace Play
{
	class Player;
	class Goal;
}

using GenerateCloudIntervalRandom = std::uniform_real_distribution<float>;

class PlayScene : public GameScene
{
public:
	PlayScene();
	~PlayScene();

	/// <summary>
	/// �v���C���[���S�[���������ǂ���
	/// </summary>
	/// <returns>�S�[������ true / false</returns>
	inline bool IsPlayerGoaled() const { return isPlayerGoaled_; }
	
	/// <summary>
	/// �S�[���A�j���[�V�������I�����
	/// </summary>
	void FinishedGoalAnimation();

	/// <summary>
	/// �S�[������
	/// </summary>
	void GoalPlayer();

	static inline int GetScore() { return score; }
	static inline float GetPlayTimer() { return playTimer_; }
	void AddScore(const int& scorePoint);

private:
	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;

private:
	Play::Player* player_;
	Play::Goal* goal_;

	static float playTimer_;  // �J�E���g�A�b�v�^�C�}�[
	
	bool isPlayerGoaled_;
	//static int stageNumber;
	static int score;
};
