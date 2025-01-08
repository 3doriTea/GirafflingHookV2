#include <Windows.h>
#include "GirafflingHook.h"

int WINAPI WinMain(
	_In_ HINSTANCE		hInstance,
	_In_opt_ HINSTANCE	hPrevInstance,
	_In_ LPSTR			lpCmdLine,
	_In_ int			nCmdShow)
{
	return Game::Run<GirafflingHook>();
}
