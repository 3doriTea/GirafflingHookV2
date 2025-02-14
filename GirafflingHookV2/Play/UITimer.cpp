#include "UITimer.h"
#include "../PlayScene.h"
#include "Screen.h"

Play::UITimer::UITimer() :
	GameObject
	{
		GameObjectBuilder{}
			.LayerOrder(LayerOrderType::UI)
	}
{
}

Play::UITimer::~UITimer()
{
}

void Play::UITimer::Draw() const
{
	float time{ GetGameScene<PlayScene>().GetPlayTime() };

	SetFontSize(30);
	int sizeX{}, sizeY{}, lineCount{};
	GetDrawFormatStringSize(&sizeX, &sizeY, &lineCount, "�^�C���F%f", time);
	DrawFormatString((Screen::WIDTH - sizeX) / 2, 0, 0xffffff, "�^�C���F%f", time);
	SetFontSize(DEFAULT_FONT_SIZE);
}
