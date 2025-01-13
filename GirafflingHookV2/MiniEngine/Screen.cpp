#include "Screen.h"

const int Screen::WIDTH{ 1280 };
const int Screen::HEIGHT{ 720 };
const int Screen::COLOR_DEPTH{ 32 };

Vector2Int Screen::ToViewportPosition(const int& screenX, const int& screenY)
{
	return Vector2Int{ screenX, HEIGHT - screenY };
}

Vector2Int Screen::ToViewportPosition(const Vector2Int& screen)
{
	return ToViewportPosition(screen.x, screen.y);
}
