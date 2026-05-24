#pragma once
#include <raylib.h>
#include <rlgl.h>
#include <vector>
#include "SoundID.h"
#include "MusicID.h"
namespace Engine {
	class AudioManager
	{
	public:
		AudioManager();
		void Start();
		void SoundPlay(SoundID::ID id);
		void MusicChange(MusicID::ID id);
		void MusicUpdate();

	private:
		Music bgm;
	};
}