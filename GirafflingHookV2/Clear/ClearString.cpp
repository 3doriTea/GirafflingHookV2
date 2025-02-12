#include "ClearString.h"
#include <cassert>

Clear::ClearString::ClearString() :
	GameObject
	{
		GameObjectBuilder{}
			.Name("ƒNƒŠƒA‰æ–Ê‚Ì•¶Žš")
			.Position({ -600.f, 140.f, 0.f })
	},
hClearModel_{ -1 }
{
}

Clear::ClearString::~ClearString()
{
}

void Clear::ClearString::Init()
{
	hClearModel_ = MV1LoadModel("Assets/UI/Clear.mv1");
	assert(hClearModel_ > 0);
	MV1SetPosition(hClearModel_, position);
}

void Clear::ClearString::Draw() const
{
	MV1DrawModel(hClearModel_);
}

void Clear::ClearString::End()
{
	MV1DeleteModel(hClearModel_);
}
