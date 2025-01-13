#pragma once
#include "Vector2Int.h"

class Screen final
{
public:
	static Vector2Int ToViewportPosition(const int& screenX, const int& screenY);
	static Vector2Int ToViewportPosition(const Vector2Int& screen);

public:
	static const int WIDTH;
	static const int HEIGHT;
	static const int COLOR_DEPTH;
};
