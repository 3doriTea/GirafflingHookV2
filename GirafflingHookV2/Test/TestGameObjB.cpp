#include "TestGameObjB.h"
#include <DxLib.h>
#include "Input.h"

Test::TestGameObjB::TestGameObjB() :
	GameObject
	{
		GameObjectBuilder{}
			.LayerOrder(2)
	}
{
	printfDx("B const\n");
}

Test::TestGameObjB::~TestGameObjB()
{
	printfDx("B dest\n");
}

void Test::TestGameObjB::Init()
{
	printfDx("B init\n");
}

void Test::TestGameObjB::Update()
{
	if (Input::IsKeyDown(KeyCode::Space))
		printfDx("B update\n");
}

void Test::TestGameObjB::End()
{
	printfDx("B end\n");
}
