#include "Draw2D.h"
#include <DxLib.h>
#include "Screen.h"

namespace
{
	static const Vector2Int SCREEN_CENTER
	{
		Vector2Int{ Screen::WIDTH, Screen::HEIGHT } / 2
	};
}

void Draw2D::Vector(const Vector3& v, const Color& color)
{
	Vector2Int point
	{
		static_cast<int>(v.x),
		Screen::HEIGHT - static_cast<int>(v.y)
	};
	
	DrawLine(
		SCREEN_CENTER.x, SCREEN_CENTER.y,
		point.x, point.y,
		color);
}
