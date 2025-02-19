#include "ClearUI.h"
#include <cassert>
#include <string>

Clear::ClearUI::ClearUI() :
	GameObject
	{
	GameObjectBuilder{}
		.Name("ƒNƒŠƒA‰æ–Ê‚Ì”š—Ş")
		.Position({ -600.f, 140.f, 0.f })
	},
hNumModel{0}
{
}

Clear::ClearUI::~ClearUI()
{
}

void Clear::ClearUI::Init()
{
	for (int i = 0; i < 10; i++)
	{
		std::string path = "Assets/UI/numModel_";
		path.push_back(i);
		hNumModel.push_back(MV1LoadModel(path.c_str()));
	}
}

void Clear::ClearUI::Draw() const
{
}

void Clear::ClearUI::End()
{
}