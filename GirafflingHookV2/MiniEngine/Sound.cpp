#include "Sound.h"
#include <cassert>
#include <DxLib.h>
#include <string>
#include "SoundManager.h"

void Sound::Load(const AudioInfo& info)
{
	// すでにロードされているなら回帰
	if (sounds.count(info.name) != 0)
	{
		return;
	}
	//assert(sounds.count(info.name) == 0 && "既にロードされているよ！");

	SoundHandle hSound = LoadSoundMem(info.fileName.c_str());
	assert(hSound > 0 && (std::string{ "ｻｳﾝﾄﾞﾌｧｲﾙのﾊﾟｽが正しか確認してみて:" }.append(info.fileName)).c_str());

	sounds.insert({ info.name, hSound });
}

void Sound::Play(const std::string& name, const bool& isLoop)
{
	PlaySoundMem(
		sounds[name],
		isLoop
		? DX_PLAYTYPE_LOOP
		: DX_PLAYTYPE_BACK);
}

void Sound::PlayBGM(const std::string& name)
{
	if (playingBGM.length() > 0)
	{
		Stop(playingBGM);
	}

	Play(name, true);
	playingBGM = name;
	RefleshVolumeBGM();
}

void Sound::Stop(const std::string& name)
{
	StopSoundMem(sounds[name]);

	// BGMなら再生BGMを解放
	if (playingBGM == name)
	{
		playingBGM = "";
	}
}

void Sound::SetVolumeBGM(const AudioVolume& _volume)
{
	volumeBGM = _volume;
	RefleshVolumeBGM();
}

void Sound::RefleshVolumeBGM()
{
	ChangeVolumeSoundMem(volumeBGM, sounds[playingBGM]);
}

void Sound::Release()
{
	for (auto&& sound : sounds)
	{
		DeleteSoundMem(sound.second);
	}
}

std::map<std::string, SoundHandle> Sound::sounds{};
std::string Sound::playingBGM{};
AudioVolume Sound::volumeBGM{ 255 };
