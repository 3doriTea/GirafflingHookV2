#pragma once
#include <string>
#include <map>
#include <initializer_list>

class SoundManager;

/// <summary>
/// サウンドを再生するために読み込むオーディオの情報
/// </summary>
struct AudioInfo
{
	AudioInfo() {}

	/// <summary>
	/// ファイルパス+名前を指定する
	/// </summary>
	/// <param name="_fileName">ファイルパス+名前</param>
	/// <returns></returns>
	inline AudioInfo& File(const std::string& _fileName)
	{
		fileName = _fileName;

		return *this;
	}

	/// <summary>
	/// 再生するときの識別名を指定する
	/// </summary>
	/// <param name="_name"></param>
	/// <returns></returns>
	inline AudioInfo& Name(const std::string& _name)
	{
		name = _name;

		return *this;
	}

	std::string fileName;  // ファイルのパスと名前
	std::string name;  // 再生するときの識別ニックネーム
};

using SoundHandle = int;
using AudioVolume = unsigned char;

class Sound  // static class
{
	friend SoundManager;

public:
	static void Load(const AudioInfo& info);
	static void Play(const std::string& name, const bool& isLoop = false);
	static void PlayBGM(const std::string& name);
	static void Stop(const std::string& name);
	/// <summary>
	/// BGMの音量をセット
	/// </summary>
	/// <param name="_volume">ボリューム 0..255</param>
	static void SetVolumeBGM(const AudioVolume& _volume);
	/// <summary>
	/// 現在セットされているBGMの音量を取得
	/// </summary>
	/// <returns>ボリューム 0..255</returns>
	static inline AudioVolume SetVolumeBGM() { return volumeBGM; }

private:
	/// <summary>
	/// BGMのボリュームを適用する
	/// </summary>
	static void RefleshVolumeBGM();
	/// <summary>
	/// ハンドルをすべて解放する
	/// </summary>
	static void Release();

private:
	static std::map<std::string, SoundHandle> sounds;
	static std::string playingBGM;
	static AudioVolume volumeBGM;
};
