#pragma once
#include "Draw3D.h"
#include "AABBCollider.h"
#include <DxLib.h>

void Draw3D::Box(const AABBCollider& a, const Color& color)
{
#pragma region è„ï”
	/*Vector3 worldUA{ a.transform.ToWorldPosition({ a.max.x, a.max.y, a.max.z }) };
	Vector3 worldUB{ a.transform.ToWorldPosition({ a.min.x, a.max.y, a.max.z }) };
	Vector3 worldUC{ a.transform.ToWorldPosition({ a.min.x, a.max.y, a.min.z }) };
	Vector3 worldUD{ a.transform.ToWorldPosition({ a.max.x, a.max.y, a.min.z }) };*/

	Vector3 worldUA{ a.transform.ToWorldPosition({ 0.5f, 0.5f, 0.5f }) };
	Vector3 worldUB{ a.transform.ToWorldPosition({ -0.5f, 0.5f, 0.5f }) };
	Vector3 worldUC{ a.transform.ToWorldPosition({ -0.5f, 0.5f, -0.5f }) };
	Vector3 worldUD{ a.transform.ToWorldPosition({ 0.5f, 0.5f, -0.5f }) };

	DrawLine3D(worldUA, worldUB, color);
	DrawLine3D(worldUB, worldUC, color);
	DrawLine3D(worldUC, worldUD, color);
	DrawLine3D(worldUD, worldUA, color);
#pragma endregion

#pragma region â∫ï”
	/*Vector3 worldDA{ a.transform.ToWorldPosition({ a.max.x, a.min.y, a.max.z }) };
	Vector3 worldDB{ a.transform.ToWorldPosition({ a.min.x, a.min.y, a.max.z }) };
	Vector3 worldDC{ a.transform.ToWorldPosition({ a.min.x, a.min.y, a.min.z }) };
	Vector3 worldDD{ a.transform.ToWorldPosition({ a.max.x, a.min.y, a.min.z }) };*/

	Vector3 worldDA{ a.transform.ToWorldPosition({ 0.5f, -0.5f, 0.5f }) };
	Vector3 worldDB{ a.transform.ToWorldPosition({ -0.5f, -0.5f, 0.5f }) };
	Vector3 worldDC{ a.transform.ToWorldPosition({ -0.5f, -0.5f, -0.5f }) };
	Vector3 worldDD{ a.transform.ToWorldPosition({ 0.5f, -0.5f, -0.5f }) };

	DrawLine3D(worldDA, worldDB, color);
	DrawLine3D(worldDB, worldDC, color);
	DrawLine3D(worldDC, worldDD, color);
	DrawLine3D(worldDD, worldDA, color);
#pragma endregion

#pragma region ê⁄ë±4ï”
	DrawLine3D(worldDA, worldUA, color);
	DrawLine3D(worldDB, worldUB, color);
	DrawLine3D(worldDC, worldUC, color);
	DrawLine3D(worldDD, worldUD, color);
#pragma endregion
}
