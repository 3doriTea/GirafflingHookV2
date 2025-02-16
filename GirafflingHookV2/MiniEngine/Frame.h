#pragma once

class FrameManager;

class Frame final
{
	friend FrameManager;
private:
	static float deltaTime;
	static int fps;
	static float timeScale;

public:
	/// <summary>
	/// �f���^�^�C��(�t���[���Ԏ���)���擾
	/// </summary>
	/// <returns>�f���^�^�C��(�b)</returns>
	static float GetDeltaTime();
	/// <summary>
	/// �^�C���X�P�[�����擾
	/// </summary>
	/// <returns>�^�C���X�P�[��</returns>
	static float GetTimeScale();
	/// <summary>
	/// �^�C���X�P�[����ݒ�
	/// </summary>
	static void SetTimeScale(const float& scale);
	/// <summary>
	/// �t���[�����[�g(�b�Ԃ�����̍X�V��)���擾
	/// </summary>
	/// <returns>FPS</returns>
	static int GetFPS();
};
