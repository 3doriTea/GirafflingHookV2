#include "GirafflingHook.h"
#include "DxLibManager.h"
#include "FrameManager.h"
#include "InputManager.h"
#include "ImageManager.h"

#include "SceneManager.h"
#include "TitleScene.h"

void GirafflingHook::Update()
{
	Manager::UpdateCycle();
}

void GirafflingHook::Init()
{
	(new FrameManager{})->OnFrame([&]()
		{
			Manager::UpdateFrame();
		});
	new DxLibManager{};
	(new SceneManager{})->Move<TitleScene>();
	new InputManager{};
	new ImageManager{};
}

void GirafflingHook::End()
{
	Manager::ReleaseAll();
}
