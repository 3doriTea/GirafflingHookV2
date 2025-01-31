#include "FrameManager.h"
#include "Frame.h"
#include <DxLib.h>

#pragma comment(lib, "Winmm.lib")

namespace
{
	const LONGLONG NANO_SEC_L{ 10000000LL };
	const double NANO_SEC_F{ 10000000. };
}

FrameManager::FrameManager() :
	Manager::Manager(CalledType::Cycle),
	currentTime{ 0 },
	previousTime{ 0 },
	differenceTime{ 0 },
	frameDifferenceTime{ 0 },
	fpsCounter{ 0 },
	fpsLimit{ 60 },
	fpsUpdateTimeLeft{ 0 }
{
}

FrameManager::~FrameManager()
{
}

void FrameManager::Init()
{
	QueryPerformanceCounter(&previousTime);
	QueryPerformanceCounter(&currentTime);
}

void FrameManager::End()
{
}

void FrameManager::Update()
{
	// MEMO: ���Ԍv���̐��x�A�b�v�J�n
	timeBeginPeriod(1);

	if (!QueryPerformanceCounter(&currentTime))
	{
		timeEndPeriod(1);
		return;
	}

	differenceTime = currentTime.QuadPart - previousTime.QuadPart;
	frameDifferenceTime += differenceTime;
	previousTime = currentTime;

	fpsUpdateTimeLeft -= differenceTime;
	if (fpsUpdateTimeLeft <= 0)
	{
		fpsUpdateTimeLeft += NANO_SEC_L;

		Frame::fps = fpsCounter;
		fpsCounter = 0;

		//FPS�̒l��\��
#if _DEBUG
		char string[40]{ 0 };
		sprintf_s(string, "dT:%f FPS:%d", Frame::deltaTime, Frame::fps);
		SetWindowText(GetActiveWindow(), string);
#endif
	}

	// MEMO: ���� 1 / {fps} �b�o�߂��Ă�����P�t���[��
//	if (frameDifferenceTime * fpsLimit >= NANO_SEC_L)
	{
		Frame::deltaTime = static_cast<float>(static_cast<double>(frameDifferenceTime) / NANO_SEC_F);

		onFrame();
		fpsCounter++;
		frameDifferenceTime = 0;

		// NOTE: ������Ƌx�܂��Ȃ��Ɠ��͓��󂯎��Ȃ��炵��?
		Sleep(1);
	}

	// MEMO: ���Ԍv���̐��x�A�b�v�I��
	timeEndPeriod(1);
}

FrameManager& FrameManager::OnFrame(std::function<void()> onFrame)
{
	this->onFrame = onFrame;
	return *this;
}

FrameManager& FrameManager::SetFPSLimit(const int& fpsLimit)
{
	this->fpsLimit = fpsLimit;
	return *this;
}
