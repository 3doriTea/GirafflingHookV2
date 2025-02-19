#include "ClearUI.h"
#include <cassert>
#include <string>

Clear::ClearUI::ClearUI() :
	GameObject
	{
	GameObjectBuilder{}
		.Name("クリア画面の数字類")
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
		std::string path = "Assets/UI/num/numModel_"; // 分離してね
		//path.push_back(static_cast<char>(i)) ← 文字コードで突っ込んでる（しかも今回の場合は制御文字！）
		path.push_back('0' + i); // ← 考えたやつ頭いい
		path += ".mv1";
		hNumModel.push_back(MV1LoadModel(path.c_str()));
		assert(hNumModel[i] != -1);
	}
}

void Clear::ClearUI::Draw() const
{
	for (int i = 0; i < 10; i++)
	{
		MV1DrawModel(hNumModel[i]);
	}
}

void Clear::ClearUI::End()
{
}