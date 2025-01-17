#pragma once
#include "Vector3.h"

using Color = unsigned int;

//class OBBCollider;
class AABBCollider;

class Draw3D
{
public:
	enum struct Type
	{
		Surface,  // サーフェスモデル
		WireFrame,  // ワイヤーフレームモデル
	};

	//static void Box(const OBBCollider& aABB, const Color& color);
	static void Box(const AABBCollider& aABB, const Color& color);
};
