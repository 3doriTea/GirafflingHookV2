#pragma once
#include "GameScene.h"
#include <vector>

namespace Title
{
	class SelectButton;

	using ButtonNumber = unsigned char;
	
	enum ButtonType : ButtonNumber
	{
		BUTTON_PLAY,
		BUTTON_INFO,
		BUTTON_QUIT,
		BUTTON_MAX,
	};
}

class TitleScene : public GameScene
{
public:
	TitleScene();
	~TitleScene();

private:
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

	int hGiraffeImageBody_;
	int hGiraffeImageHead_;

	enum TITLE_ELEMENT
	{
		TITLE_TEXT,
		PLAY_BUTTON,
		INFO_BUTTON,
		QUIT_BUTTON,
		MAX_ELEMENT
	};

	Title::ButtonNumber selectionButton;
	std::vector<Title::SelectButton*> selectButtons;

	float giraffeLength_;

	std::vector<const char*> titleElement = {"Giraffing Hook", "Play", "Info", "Quit"};
};
