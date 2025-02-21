#include "Projector.h"
#include <DxLib.h>
#include <cassert>
#include <cmath>
#include <imgui.h>

Projector::Projector() :
	hImage_{ -1 }
{
}

Projector::~Projector()
{
}

void Projector::Init()
{
	hImage_ = LoadGraph("Assets/Info/computer_projector.png");
	assert(hImage_ > 0 && "‰æ‘œ‚ª³‚µ‚­“Ç‚İ‚Ü‚ê‚Ä‚¢‚È‚¢");
}

void Projector::Update()
{
}

void Projector::Draw() const
{
	DrawRotaGraph(POSITION_X, POSITION_Y, SIZE, 0.0f, hImage_, TRUE, TRUE, FALSE);


	static int posX{}, posY{};

	for (float radian = 0.0f; radian <= DX_PI_F * 2.0f; radian += DX_PI_F / 2.0f)
	{
		DrawLine(
			RAY_ORIGIN_X, RAY_ORIGIN_Y,
			RAY_TARGET_X + std::cosf(radian) * RAY_RADIUS, RAY_TARGET_Y + std::sinf(radian) * RAY_RADIUS,
			0xffffff, 1);
	}

	ImGui::Begin("Projector");
	ImGui::DragInt("posX", &posX);
	ImGui::DragInt("posY", &posY);
	ImGui::End();
}

void Projector::End()
{
	DeleteGraph(hImage_);
}

const int Projector::POSITION_X{ 94 };
const int Projector::POSITION_Y{ 360 };
const float Projector::SIZE{ 0.74f };
const int Projector::RAY_ORIGIN_X{ 94 };
const int Projector::RAY_ORIGIN_Y{ 360 };
const int Projector::RAY_TARGET_X{ 1094 };
const int Projector::RAY_TARGET_Y{ 360 };
const float Projector::RAY_RADIUS{ 100 };
float Projector::offsetRadian{ 0.0f };
