#include "Application.h"
#include "ObjectID.h"

bool Engine::Application::DebugMode = false;

Engine::Application::Application()
    : last_tick(std::chrono::system_clock::now())
{
}

void Engine::Application::Start(std::string window_title) {

    window.Start(window_title);
    LoadAssets();
    //Start other services
    last_test = last_tick;
}

void Engine::Application::Stop()
{
}



void Engine::Application::Update() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double dt = std::chrono::duration<double>(now - last_tick).count();
    if (dt > 0.02)dt = 0.02;
    if (dt > 1 / TargetFPS) {
        last_tick = now;
        frame_count++;
        if (frame_count >= FPSTargetFrames) {
            double actual_time = std::chrono::duration<double>(now - last_test).count();
            frame_count = 0;
            last_test = now;

        }
        gamestatemanager.Update(dt);
        //input.Update();
        window.Update();
        //Update other services
        if (IsKeyReleased(KEY_F1)) {
            DebugMode = !DebugMode;
        }

    }

}

void Engine::Application::LoadAssets()
{
    assets.resize(static_cast<int>(ObjectID::ID::COUNT)+2);
    assets[static_cast<int>(ObjectID::ID::BLOCK)] = LoadTexture("Assets/Block.png");
    assets[static_cast<int>(ObjectID::ID::FLAG)] = LoadTexture("Assets/Flag.png");
    assets[static_cast<int>(ObjectID::ID::PLAYER)] = LoadTexture("Assets/gam150-player.png");
    assets[static_cast<int>(ObjectID::ID::SAW)] = LoadTexture("Assets/Saw.png");
    assets[static_cast<int>(ObjectID::ID::SPIKE)] = LoadTexture("Assets/Spike.png");
}

bool Engine::Application::HasGameEnded()
{
    if (gamestatemanager.HasGameEnded() == true || window.IsClosed() == true) {
        return true;
    }
    return false;
}

