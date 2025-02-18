#pragma once
#include <string>
#include <map>
#include <initializer_list>

using SoundHandle = int;

class SoundManager;

/// <summary>
/// �T�E���h���Đ����邽�߂ɓǂݍ��ރI�[�f�B�I�̏��
/// </summary>
struct AudioInfo
{
	AudioInfo() {}

	/// <summary>
	/// �t�@�C���p�X+���O���w�肷��
	/// </summary>
	/// <param name="_fileName">�t�@�C���p�X+���O</param>
	/// <returns></returns>
	inline AudioInfo& File(const std::string& _fileName)
	{
		fileName = _fileName;

		return *this;
	}

	/// <summary>
	/// �Đ�����Ƃ��̎��ʖ����w�肷��
	/// </summary>
	/// <param name="_name"></param>
	/// <returns></returns>
	inline AudioInfo& Name(const std::string& _name)
	{
		name = _name;

		return *this;
	}

	std::string fileName;  // �t�@�C���̃p�X�Ɩ��O
	std::string name;  // �Đ�����Ƃ��̎��ʃj�b�N�l�[��
};

class Sound  // static class
{
	friend SoundManager;

public:
	static void Load(const AudioInfo& info);
	static void Play(const std::string& name, const bool& isLoop = false);
	static void PlayBGM(const std::string& name);
	static void Stop(const std::string& name);

private:
	static void Release();

private:
	static std::map<std::string, SoundHandle> sounds;
	static std::string playingBGM;
	static unsigned char volumeBGM;
};
