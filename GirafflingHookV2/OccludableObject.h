#pragma once
#include "GameObject.h"

namespace Play
{
	/// <summary>
	/// カメラの視界にいなければ非アクティブになるゲームオブジェクト
	/// </summary>
	class OccludableObject : public GameObject
	{
	};
}
