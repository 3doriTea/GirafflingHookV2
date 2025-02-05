#include "TitleString.h"

Title::TitleString::TitleString() :
	GameObject
	{
		GameObjectBuilder{}
			.Name("ƒ^ƒCƒgƒ‹‚Ì•¶Žš")
			.Position({ -300.f, 140.f, 0.f })
	},
	hTitleModel_{ -1 }
{
}

Title::TitleString::~TitleString()
{
}

void Title::TitleString::Init()
{
	hTitleModel_ = MV1LoadModel("Assets/UI/Title.mv1");
	MV1SetPosition(hTitleModel_, position);
}

void Title::TitleString::Draw() const
{
	MV1DrawModel(hTitleModel_);
}

void Title::TitleString::End()
{
	MV1DeleteModel(hTitleModel_);
}
