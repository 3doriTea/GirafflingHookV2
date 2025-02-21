#include "AboutText.h"
#include <DxLib.h>

Info::AboutText::AboutText() :
	hImage_{ -1 }
{
}

Info::AboutText::~AboutText()
{
}

void Info::AboutText::Init()
{
	hImage_ = LoadGraph("Assets/Info/InfoText1.png");
	assert(hImage_ > 0 && "‰æ‘œ‚ª³‚µ‚­“Ç‚İ‚Ü‚ê‚Ä‚¢‚È‚¢");
}

void Info::AboutText::Update()
{
}

void Info::AboutText::Draw() const
{
	DrawGraph(0, 0, hImage_, TRUE);
}

void Info::AboutText::End()
{
	DeleteGraph(hImage_);
}
