#include "Sound.h"
#include <cassert>
#include <DxLib.h>
#include <string>
#include "SoundManager.h"

void Sound::Load(const AudioInfo& info)
{
	// ���łɃ��[�h����Ă���Ȃ��A
	if (sounds.count(info.name) != 0)
	{
		return;
	}
	//assert(sounds.count(info.name) == 0 && "���Ƀ��[�h����Ă����I");

	SoundHandle hSound = LoadSoundMem(info.fileName.c_str());
	assert(hSound > 0 && (std::string{ "�����̧�ق��߽���������m�F���Ă݂�:" }.append(info.fileName)).c_str());

	sounds.insert({ info.name, hSound });
}

void Sound::Play(const std::string& name)
{
	PlaySoundMem(sounds[name], DX_PLAYTYPE_BACK);
}

void Sound::Stop(const std::string& name)
{
	StopSoundMem(sounds[name]);
}

void Sound::Release()
{
	for (auto&& sound : sounds)
	{
		DeleteSoundMem(sound.second);
	}
}

std::map<std::string, SoundHandle> Sound::sounds{};
