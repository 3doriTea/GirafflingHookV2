#pragma once
#include "Manager.h"
#include <functional>
#include <Windows.h>


/// <summary>
/// �t���[�����Ǘ�����N���X
/// </summary>
class FrameManager : public Manager
{
public:
	FrameManager();
	~FrameManager();

	void Init() override;
	void Update() override;
	void End() override;
	/// <summary>
	/// 1�t���[�����X�V���ꂽ�^�C�~���O�ŌĂ΂��R�[���o�b�N
	/// </summary>
	/// <param name="">�R�[���o�b�N</param>
	/// <returns>�t���[���}�l�[�W���̎Q��</returns>
	FrameManager& OnFrame(std::function<void()>);
	/// <summary>
	/// FPS������ݒ肷��
	/// </summary>
	/// <param name="fpsLimit">�ő�FPS</param>
	/// <returns>�t���[���}�l�[�W���̎Q��</returns>
	FrameManager& SetFPSLimit(const int& fpsLimit);

private:
	LARGE_INTEGER currentTime;  // ����̃T�C�N����
	LARGE_INTEGER previousTime;  // �O��̃T�C�N����
	LONGLONG differenceTime;  // �T�C�N���Ԃ̎��ԍ�
	LONGLONG frameDifferenceTime;  // �t���[���Ԃ̎��ԍ�
	int fpsCounter;
	int fpsLimit;  // FPS���� (���z��FPS)
	LONGLONG fpsUpdateTimeLeft;
	std::function<void()> onFrame;

	static FrameManager* instance;
};
