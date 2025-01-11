#pragma once
#include "Vector3.h"

using Color = unsigned int;

class AABBCollider;

class Draw3D
{
	friend AABBCollider;

public:
	enum struct Type
	{
		Surface,  // サーフェスモデル
		WireFrame,  // ワイヤーフレームモデル
	};

	static void Box(AABBCollider& aABB, const Color& color);
};
