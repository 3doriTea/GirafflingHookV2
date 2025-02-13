#include "TestGameObjA.h"
#include <DxLib.h>
#include "Input.h"

Test::TestGameObjA::TestGameObjA() :
	GameObject
	{
		GameObjectBuilder{}
			.LayerOrder(LayerOrderType::UI + 1)
	}
{
	printfDx("A const\n");
}

Test::TestGameObjA::~TestGameObjA()
{
	printfDx("A dest\n");
}

void Test::TestGameObjA::Init()
{
	printfDx("A init\n");
}

void Test::TestGameObjA::Update()
{
	if (Input::IsKeyDown(KeyCode::Space))
		printfDx("A update\n");
	if (Input::IsKeyDown(KeyCode::K))
		Destroy();
}

void Test::TestGameObjA::End()
{
	printfDx("A end\n");
}
