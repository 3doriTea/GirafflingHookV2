#include "ClearUI.h"
#include <cassert>
#include <string>

Clear::ClearUI::ClearUI() :
	GameObject
	{
	GameObjectBuilder{}
		.Name("�N���A��ʂ̐�����")
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
		std::string path = "Assets/UI/numModel_"; // �������Ă�
		path.push_back('0' + i); // int�̐��l��char�ɃL���X�g����ƁA�����R�[�h�ɂȂ�̂ł���I
		hNumModel.push_back(MV1LoadModel(path.c_str()));
	}
}

void Clear::ClearUI::Draw() const
{
}

void Clear::ClearUI::End()
{
}