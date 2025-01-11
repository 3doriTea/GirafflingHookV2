#pragma once
#include "Vector3.h"

struct Box3
{
	Box3();
	Box3(const Vector3& a, const Vector3& b);

	Vector3 min;
	Vector3 max;
};
