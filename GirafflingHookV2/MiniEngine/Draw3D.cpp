#pragma once
#include "Draw3D.h"
//#include "OBBCollider.h"
#include "AABBCollider.h"
#include <DxLib.h>

//void Draw3D::Box(const OBBCollider& a, const Color& color)
//{
//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
//
//#pragma region è„ï”
//	/*Vector3 worldUA{ a.transform.ToWorldPosition({ aMax.x, aMax.y, aMax.z }) };
//	Vector3 worldUB{ a.transform.ToWorldPosition({ aMin.x, aMax.y, aMax.z }) };
//	Vector3 worldUC{ a.transform.ToWorldPosition({ aMin.x, aMax.y, aMin.z }) };
//	Vector3 worldUD{ a.transform.ToWorldPosition({ aMax.x, aMax.y, aMin.z }) };*/
//
//	Vector3 worldUA{ a.transform_.ToWorldPosition({ 0.5f, 0.5f, 0.5f }) };
//	Vector3 worldUB{ a.transform_.ToWorldPosition({ -0.5f, 0.5f, 0.5f }) };
//	Vector3 worldUC{ a.transform_.ToWorldPosition({ -0.5f, 0.5f, -0.5f }) };
//	Vector3 worldUD{ a.transform_.ToWorldPosition({ 0.5f, 0.5f, -0.5f }) };
//
//	DrawLine3D(worldUA, worldUB, color);
//	DrawLine3D(worldUB, worldUC, color);
//	DrawLine3D(worldUC, worldUD, color);
//	DrawLine3D(worldUD, worldUA, color);
//#pragma endregion
//
//#pragma region â∫ï”
//	/*Vector3 worldDA{ a.transform.ToWorldPosition({ aMax.x, aMin.y, aMax.z }) };
//	Vector3 worldDB{ a.transform.ToWorldPosition({ aMin.x, aMin.y, aMax.z }) };
//	Vector3 worldDC{ a.transform.ToWorldPosition({ aMin.x, aMin.y, aMin.z }) };
//	Vector3 worldDD{ a.transform.ToWorldPosition({ aMax.x, aMin.y, aMin.z }) };*/
//
//	Vector3 worldDA{ a.transform_.ToWorldPosition({ 0.5f, -0.5f, 0.5f }) };
//	Vector3 worldDB{ a.transform_.ToWorldPosition({ -0.5f, -0.5f, 0.5f }) };
//	Vector3 worldDC{ a.transform_.ToWorldPosition({ -0.5f, -0.5f, -0.5f }) };
//	Vector3 worldDD{ a.transform_.ToWorldPosition({ 0.5f, -0.5f, -0.5f }) };
//
//	DrawLine3D(worldDA, worldDB, color);
//	DrawLine3D(worldDB, worldDC, color);
//	DrawLine3D(worldDC, worldDD, color);
//	DrawLine3D(worldDD, worldDA, color);
//#pragma endregion
//
//#pragma region ê⁄ë±4ï”
//	DrawLine3D(worldDA, worldUA, color);
//	DrawLine3D(worldDB, worldUB, color);
//	DrawLine3D(worldDC, worldUC, color);
//	DrawLine3D(worldDD, worldUD, color);
//#pragma endregion
//
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
//}

void Draw3D::Box(const AABBCollider& a, const Color& color)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);

	Vector3 aMax{ a.Max() };
	Vector3 aMin{ a.Min() };

#pragma region è„ï”
	Vector3 worldUA{ aMax.x, aMax.y, aMax.z };
	Vector3 worldUB{ aMin.x, aMax.y, aMax.z };
	Vector3 worldUC{ aMin.x, aMax.y, aMin.z };
	Vector3 worldUD{ aMax.x, aMax.y, aMin.z };

	DrawLine3D(worldUA, worldUB, color);
	DrawLine3D(worldUB, worldUC, color);
	DrawLine3D(worldUC, worldUD, color);
	DrawLine3D(worldUD, worldUA, color);
#pragma endregion

#pragma region â∫ï”
	Vector3 worldDA{ aMax.x, aMin.y, aMax.z };
	Vector3 worldDB{ aMin.x, aMin.y, aMax.z };
	Vector3 worldDC{ aMin.x, aMin.y, aMin.z };
	Vector3 worldDD{ aMax.x, aMin.y, aMin.z };

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

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}
