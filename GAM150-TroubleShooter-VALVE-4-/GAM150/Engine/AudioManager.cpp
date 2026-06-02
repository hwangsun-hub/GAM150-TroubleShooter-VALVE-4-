#include "AudioManager.h"
#include "Application.h"

Engine::AudioManager::AudioManager()
{
}

void Engine::AudioManager::Start()
{
	InitAudioDevice();
    SetMasterVolume(0.01f);
}

void Engine::AudioManager::SoundPlay(SoundID::ID id)
{
	int idx = static_cast<int>(id);
    if (idx >= 0 &&
        idx < Engine::Application::GetSounds().size())
    {
        PlaySound(
            Engine::Application::GetSounds()[idx]
        );
    }
}

void Engine::AudioManager::MusicChange(MusicID::ID id)
{
    if (bgm.ctxData == Engine::Application::GetMusics()[static_cast<int>(id)].ctxData)
        return;
    if (bgm.ctxData != nullptr)
    {
        StopMusicStream(bgm);
    }

    bgm =
        Engine::Application::GetMusics()[
            static_cast<int>(id)];

    if (bgm.ctxData != nullptr)
    {
        PlayMusicStream(bgm);
    }
}

void Engine::AudioManager::MusicUpdate()
{
    if (bgm.ctxData != nullptr) {
        UpdateMusicStream(bgm);
    }
}
