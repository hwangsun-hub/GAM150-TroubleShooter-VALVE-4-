#include "Application.h"
#include "ObjectID.h"
#include "SoundID.h"

bool Engine::Application::DebugMode = false;

Engine::Application::Application()
    : last_tick(std::chrono::system_clock::now())
{
}

void Engine::Application::Start(std::string window_title) {

    window.Start(window_title);
    audiomanager.Start();
    LoadAssets();
    audiomanager.MusicChange(MusicID::ID::MAINMENU);
    //Start other services
    last_test = last_tick;
}

void Engine::Application::Stop()
{
}



void Engine::Application::Update() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double dt = std::chrono::duration<double>(now - last_tick).count();
    if (dt > 0.02) {
        dt = 0.02;
    }
    if (dt > 1 / TargetFPS) {
        last_tick = now;
        frame_count++;
        if (frame_count >= FPSTargetFrames) {
            double actual_time = std::chrono::duration<double>(now - last_test).count();
            frame_count = 0;
            last_test = now;

        }
        gamestatemanager.Update(dt);
        window.Update();
        audiomanager.MusicUpdate();
        //Update other services
        if (IsKeyReleased(KEY_F1)) {
            DebugMode = !DebugMode;
        }

    }

}

void Engine::Application::LoadAssets()
{
    textures.resize(static_cast<int>(ObjectID::ID::COUNT));
    sounds.resize(static_cast<int>(SoundID::ID::COUNT));
    musics.resize(static_cast<int>(MusicID::ID::COUNT));

    //textures
    textures[static_cast<int>(ObjectID::ID::BLOCK)] = LoadTexture("Assets/Texture/Block.png");
    textures[static_cast<int>(ObjectID::ID::FLAG)] = LoadTexture("Assets/Texture/Flag.png");
    textures[static_cast<int>(ObjectID::ID::PLAYER)] = LoadTexture("Assets/Texture/gam150-player.png");
    textures[static_cast<int>(ObjectID::ID::SAW)] = LoadTexture("Assets/Texture/Saw.png");
    textures[static_cast<int>(ObjectID::ID::SPIKE)] = LoadTexture("Assets/Texture/Spike.png");
    textures[static_cast<int>(ObjectID::ID::TROUBLE)] = LoadTexture("Assets/Texture/Trouble.png");
    textures[static_cast<int>(ObjectID::ID::SELECTBOX)] = LoadTexture("Assets/Texture/Flag.png");
    textures[static_cast<int>(ObjectID::ID::DOOR)] = LoadTexture("Assets/Texture/Door.png");
    textures[static_cast<int>(ObjectID::ID::BOX)] = LoadTexture("Assets/Texture/Box.png");
    textures[static_cast<int>(ObjectID::ID::GLITCHBOX)] = LoadTexture("Assets/Texture/GlitchBox.png");

    //sounds
    sounds[static_cast<int>(SoundID::ID::TestSound1)] = LoadSound("Assets/Sound/soundtest1.mp3");
    sounds[static_cast<int>(SoundID::ID::JUMP)] = LoadSound("Assets/Sound/Jump.wav");
    sounds[static_cast<int>(SoundID::ID::DEATH)] = LoadSound("Assets/Sound/Death.wav");
    sounds[static_cast<int>(SoundID::ID::SHOOT)] = LoadSound("Assets/Sound/Shoot.wav");

    //musics
    //musics[static_cast<int>(MusicID::ID::TestSound1)] = LoadMusicStream("Assets/BGM/test1.mp3");
    musics[static_cast<int>(MusicID::ID::MAINMENU)] = LoadMusicStream("Assets/BGM/Spamgon.mp3");
    musics[static_cast<int>(MusicID::ID::INGAME1)] = LoadMusicStream("Assets/BGM/umidk_2.mp3");
    musics[static_cast<int>(MusicID::ID::INGAME2)] = LoadMusicStream("Assets/BGM/TroubleShhoter.mp3");






}

bool Engine::Application::HasGameEnded()
{
    if (gamestatemanager.HasGameEnded() == true || window.IsClosed() == true) {
        return true;
    }
    return false;
}

