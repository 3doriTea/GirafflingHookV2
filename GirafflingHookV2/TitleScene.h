#pragma once
#include "GameScene.h"
#include <vector>

class TitleScene : public GameScene
{
public:
	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Draw() const override;
	void End() override;

private:
	int hPointLight_;
	int hDirectional_;

	int hPlayButtonModel_;
	int hInfoButtonModel_;
	int hQuitButtonModel_;

	enum TITLE_ELEMENT
	{
		TITLE_TEXT,
		PLAY_BUTTON,
		INFO_BUTTON,
		QUIT_BUTTON,
		MAX_ELEMENT
	};

	std::vector<const char*> titleElement = {"Giraffing Hook", "Play", "Info", "Quit"};
};
