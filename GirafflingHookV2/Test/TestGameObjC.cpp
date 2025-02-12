#include "TestGameObjC.h"
#include <DxLib.h>
#include "Input.h"

Test::TestGameObjC::TestGameObjC() :
	GameObject
	{
		GameObjectBuilder{}
			.LayerOrder(3)
	}
{
	printfDx("C const\n");
}

Test::TestGameObjC::~TestGameObjC()
{
	printfDx("C dest\n");
}

void Test::TestGameObjC::Init()
{
	printfDx("C init\n");
}

void Test::TestGameObjC::Update()
{
	if (Input::IsKeyDown(KeyCode::Space))
		printfDx("C update\n");
}

void Test::TestGameObjC::End()
{
	printfDx("C end\n");
}
