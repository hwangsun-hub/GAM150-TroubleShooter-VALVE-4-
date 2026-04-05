#include "Application.h"

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



void Engine::Application::Update() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    double dt = std::chrono::duration<double>(now - last_tick).count();
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
    assets.push_back(LoadTexture("Assets/gam150-1.png"));
    assets.push_back(LoadTexture("Assets/gam150-2.png"));
    assets.push_back(LoadTexture("Assets/gam150-player.png"));
}

