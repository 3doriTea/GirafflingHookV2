#pragma once
#include "Game.h"

enum struct PlayStyle
{
	KeyBoardAndMouse,
	GamePad,
};

class GirafflingHook : public Game
{
private:
	void Update() override;
	void Init() override;
	void End() override;

public:
	static inline void SetPlayStyle(const PlayStyle& _playStyle)
	{
		playStyle = _playStyle;
	}
	static inline PlayStyle GetPlayStyle()
	{
		return playStyle;
	}

private:
	static PlayStyle playStyle;
};
