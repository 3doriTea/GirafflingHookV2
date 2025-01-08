#pragma once

class FrameManager;

class Frame final
{
	friend FrameManager;
private:
	static float deltaTime;
	static int fps;

public:
	/// <summary>
	/// �f���^�^�C��(�t���[���Ԏ���)���擾
	/// </summary>
	/// <returns>�f���^�^�C��(�b)</returns>
	static float GetDeltaTime();
	/// <summary>
	/// �t���[�����[�g(�b�Ԃ�����̍X�V��)���擾
	/// </summary>
	/// <returns>FPS</returns>
	static int GetFPS();
};
