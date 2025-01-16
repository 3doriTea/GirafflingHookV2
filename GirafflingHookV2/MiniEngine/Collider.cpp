#include "Collider.h"
#include "Vector3.h"
#include <cfloat>
#include <DirectXMath.h>
#include "OBBCollider.h"

#pragma region �R�s�y����1
	//// OBB v.s. OBB
	//bool ColOBBs(OBB& obb1, OBB& obb2)
	//{
	//	// �e�����x�N�g���̊m��
	//	// �iN***:�W���������x�N�g���j
	//	D3DXVECTOR3 NAe1 = obb1.GetDirect(0), Ae1 = NAe1 * obb1.GetLen_W(0);
	//	D3DXVECTOR3 NAe2 = obb1.GetDirect(1), Ae2 = NAe2 * obb1.GetLen_W(1);
	//	D3DXVECTOR3 NAe3 = obb1.GetDirect(2), Ae3 = NAe3 * obb1.GetLen_W(2);
	//	D3DXVECTOR3 NBe1 = obb2.GetDirect(0), Be1 = NBe1 * obb2.GetLen_W(0);
	//	D3DXVECTOR3 NBe2 = obb2.GetDirect(1), Be2 = NBe2 * obb2.GetLen_W(1);
	//	D3DXVECTOR3 NBe3 = obb2.GetDirect(2), Be3 = NBe3 * obb2.GetLen_W(2);
	//	D3DXVECTOR3 Interval = obb1.GetPos_W() - obb2.GetPos_W();

	//	// ������ : Ae1
	//	FLOAT rA = D3DXVec3Length(&Ae1);
	//	FLOAT rB = LenSegOnSeparateAxis(&NAe1, &Be1, &Be2, &Be3);
	//	FLOAT L = fabs(D3DXVec3Dot(&Interval, &NAe1));
	//	if (L > rA + rB)
	//		return false; // �Փ˂��Ă��Ȃ�

	//	// ������ : Ae2
	//	rA = D3DXVec3Length(&Ae2);
	//	rB = LenSegOnSeparateAxis(&NAe2, &Be1, &Be2, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &NAe2));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : Ae3
	//	rA = D3DXVec3Length(&Ae3);
	//	rB = LenSegOnSeparateAxis(&NAe3, &Be1, &Be2, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &NAe3));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : Be1
	//	rA = LenSegOnSeparateAxis(&NBe1, &Ae1, &Ae2, &Ae3);
	//	rB = D3DXVec3Length(&Be1);
	//	L = fabs(D3DXVec3Dot(&Interval, &NBe1));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : Be2
	//	rA = LenSegOnSeparateAxis(&NBe2, &Ae1, &Ae2, &Ae3);
	//	rB = D3DXVec3Length(&Be2);
	//	L = fabs(D3DXVec3Dot(&Interval, &NBe2));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : Be3
	//	rA = LenSegOnSeparateAxis(&NBe3, &Ae1, &Ae2, &Ae3);
	//	rB = D3DXVec3Length(&Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &NBe3));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C11
	//	D3DXVECTOR3 Cross;
	//	D3DXVec3Cross(&Cross, &NAe1, &NBe1);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C12
	//	D3DXVec3Cross(&Cross, &NAe1, &NBe2);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C13
	//	D3DXVec3Cross(&Cross, &NAe1, &NBe3);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae2, &Ae3);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C21
	//	D3DXVec3Cross(&Cross, &NAe2, &NBe1);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C22
	//	D3DXVec3Cross(&Cross, &NAe2, &NBe2);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C23
	//	D3DXVec3Cross(&Cross, &NAe2, &NBe3);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae3);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C31
	//	D3DXVec3Cross(&Cross, &NAe3, &NBe1);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be2, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C32
	//	D3DXVec3Cross(&Cross, &NAe3, &NBe2);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be3);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// ������ : C33
	//	D3DXVec3Cross(&Cross, &NAe3, &NBe3);
	//	rA = LenSegOnSeparateAxis(&Cross, &Ae1, &Ae2);
	//	rB = LenSegOnSeparateAxis(&Cross, &Be1, &Be2);
	//	L = fabs(D3DXVec3Dot(&Interval, &Cross));
	//	if (L > rA + rB)
	//		return false;

	//	// �������ʂ����݂��Ȃ��̂Łu�Փ˂��Ă���v
	//	return true;
	//}


	//// �������ɓ��e���ꂽ���������瓊�e���������Z�o
	//float LenSegOnSeparateAxis(D3DXVECTOR3* Sep, D3DXVECTOR3* e1, D3DXVECTOR3* e2, D3DXVECTOR3* e3 = 0)
	//{
	//	// 3�̓��ς̐�Βl�̘a�œ��e���������v�Z
	//	// ������Sep�͕W��������Ă��邱��
	//	float r1 = fabs(D3DXVec3Dot(Sep, e1));
	//	float r2 = fabs(D3DXVec3Dot(Sep, e2));
	//	float r3 = e3 ? (fabs(D3DXVec3Dot(Sep, e3))) : 0;
	//	return r1 + r2 + r3;
	//}
#pragma endregion

#pragma region �R�s�y�b�^2

// TODO: �����Ə������� OBB�ւ̗���������Ȃ�

using namespace DirectX;



struct OBB
{
	Vector3 c;     // ���S�_�̍��W
	Vector3 u[3];  // XYZ �̊e���W���̌X����\�������x�N�g��
	Vector3 e;     // OBB �̊e���W���ɉ����������̔����i���S�_����ʂ܂ł̒����j
};

bool TestOBBOBB(OBB& a, OBB& b)
{
	const float EPSILON = 1.175494e-37;

	float R[3][3], AbsR[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			R[i][j] = XMVectorGetX(XMVector3Dot(a.u[i], b.u[j]));
			AbsR[i][j] = fabsf(R[i][j]) + EPSILON;
		}
	}

	Vector3 t = b.c - a.c;
	t = Vector3
	{
		XMVectorGetX(XMVector3Dot(t, a.u[0])),
		XMVectorGetX(XMVector3Dot(t, a.u[1])),
		XMVectorGetX(XMVector3Dot(t, a.u[2]))
	};

	//��L=A0, L=A1, L=A2����
	float ra, rb;

	for (int i = 0; i < 3; i++)
	{
		ra = a.e[i];
		rb = b.e[0] * AbsR[i][0] + b.e[1] * AbsR[i][1] + b.e[2] * AbsR[i][2];
		if (fabsf(t[i]) > ra + rb)return 0;
	}
	//��L=B0, L=B1, L=B2����
	for (int i = 0; i < 3; i++)
	{
		ra = a.e[0] * AbsR[0][i] + a.e[1] * AbsR[1][i] + a.e[2] * AbsR[2][i];
		rb = b.e[i];
		if (fabsf(t[0] * R[0][i] + t[1] * R[1][i] + t[2] * R[2][i]) > ra + rb)return 0;
	}

	//��L=A0 X B0����
	ra = a.e[1] * AbsR[2][0] + a.e[2] * AbsR[1][0];
	rb = b.e[1] * AbsR[0][2] + b.e[2] * AbsR[0][1];
	if (fabsf(t[2] * R[1][0] - t[1] * R[2][0]) > ra + rb)return 0;

	//��L=A0 X B1����
	ra = a.e[1] * AbsR[2][1] + a.e[2] * AbsR[1][1];
	rb = b.e[0] * AbsR[0][2] + b.e[2] * AbsR[0][0];
	if (fabsf(t[2] * R[1][1] - t[1] * R[2][1]) > ra + rb)return 0;

	//��L=A0 X B2����
	ra = a.e[1] * AbsR[2][2] + a.e[2] * AbsR[1][2];
	rb = b.e[0] * AbsR[0][1] + b.e[1] * AbsR[0][0];
	if (fabsf(t[2] * R[1][2] - t[1] * R[2][2]) > ra + rb)return 0;

	//��L=A1 X B0����
	ra = a.e[0] * AbsR[2][0] + a.e[2] * AbsR[0][0];
	rb = b.e[1] * AbsR[1][2] + b.e[2] * AbsR[1][1];
	if (fabsf(t[0] * R[2][0] - t[2] * R[0][0]) > ra + rb)return 0;

	//��L=A1 X B1����
	ra = a.e[0] * AbsR[2][1] + a.e[2] * AbsR[0][1];
	rb = b.e[0] * AbsR[1][2] + b.e[2] * AbsR[1][0];
	if (fabsf(t[0] * R[2][1] - t[2] * R[0][1]) > ra + rb)return 0;

	//��L=A1 X B2����
	ra = a.e[0] * AbsR[2][2] + a.e[2] * AbsR[0][2];
	rb = b.e[0] * AbsR[1][1] + b.e[1] * AbsR[1][0];
	if (fabsf(t[0] * R[2][2] - t[2] * R[0][2]) > ra + rb)return 0;

	//��L=A2 X B0����
	ra = a.e[0] * AbsR[1][0] + a.e[1] * AbsR[0][0];
	rb = b.e[1] * AbsR[2][2] + b.e[2] * AbsR[2][1];
	if (fabsf(t[1] * R[0][0] - t[0] * R[1][0]) > ra + rb)return 0;

	//��L=A2 X B1����
	ra = a.e[0] * AbsR[1][1] + a.e[1] * AbsR[0][1];
	rb = b.e[0] * AbsR[2][2] + b.e[2] * AbsR[2][0];
	if (fabsf(t[1] * R[0][1] - t[0] * R[1][1]) > ra + rb)return 0;

	//��L=A2 X B2����
	ra = a.e[0] * AbsR[1][2] + a.e[1] * AbsR[0][2];
	rb = b.e[0] * AbsR[2][1] + b.e[1] * AbsR[2][0];
	if (fabsf(t[1] * R[0][2] - t[0] * R[1][2]) > ra + rb)return 0;

	return 1;
}
#pragma endregion

bool Collider::IsHit_OBB2OBB(OBBCollider& colliderA, OBBCollider& colliderB)
{
	

	return TestOBBOBB(
		);
}
