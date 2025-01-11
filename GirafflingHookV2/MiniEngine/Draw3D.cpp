#pragma once
#include "Draw3D.h"
#include "AABBCollider.h"
#include <DxLib.h>

void Draw3D::Box(const AABBCollider& a, const Color& color)
{
	DrawLine3D({ a.max.x, a.max.y, a.max.z }, { a.min.x, a.max.y, a.max.z }, color);
	DrawLine3D({ a.min.x, a.max.y, a.max.z }, { a.min.x, a.max.y, a.min.z }, color);
	DrawLine3D({ a.min.x, a.max.y, a.min.z }, { a.max.x, a.max.y, a.min.z }, color);
	DrawLine3D({ a.max.x, a.max.y, a.min.z }, { a.max.x, a.max.y, a.max.z }, color);

	DrawLine3D({ a.max.x, a.min.y, a.max.z }, { a.min.x, a.min.y, a.max.z }, color);
	DrawLine3D({ a.min.x, a.min.y, a.max.z }, { a.min.x, a.min.y, a.min.z }, color);
	DrawLine3D({ a.min.x, a.min.y, a.min.z }, { a.max.x, a.min.y, a.min.z }, color);
	DrawLine3D({ a.max.x, a.min.y, a.min.z }, { a.max.x, a.min.y, a.max.z }, color);

	DrawLine3D({ a.max.x, a.min.y, a.max.z }, { a.max.x, a.max.y, a.max.z}, color);
	DrawLine3D({ a.min.x, a.min.y, a.max.z }, { a.min.x, a.max.y, a.max.z}, color);
	DrawLine3D({ a.min.x, a.min.y, a.min.z }, { a.min.x, a.max.y, a.min.z}, color);
	DrawLine3D({ a.max.x, a.min.y, a.min.z }, { a.max.x, a.max.y, a.min.z}, color);
}
