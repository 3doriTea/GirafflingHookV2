#pragma once
#include "Vector3.h"

using Color = unsigned int;

class OBBCollider;

class Draw3D
{
public:
	enum struct Type
	{
		Surface,  // �T�[�t�F�X���f��
		WireFrame,  // ���C���[�t���[�����f��
	};

	static void Box(const OBBCollider& aABB, const Color& color);
};
