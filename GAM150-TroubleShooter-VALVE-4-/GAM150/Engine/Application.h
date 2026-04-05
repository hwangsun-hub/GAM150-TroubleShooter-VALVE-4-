#pragma once
#include <vector>
#include <raylib.h>
#include "Window.h"
#include "GameStateManager.h"
#include <chrono>

namespace Engine {
    class Application {
    public:
        static Application& Instance() {
            static Application instance;
            return instance;
        }

        static Engine::Window& GetWindow() {
            return Instance().window;
        }

        static Engine::GameStateManager& GetGameStateManager() {
            return Instance().gamestatemanager;
        }

        static std::vector<Texture>& GetAssets() {
            return Instance().assets;
        }
        void Start(std::string window_title);
        void Stop();
        void Update();
        void LoadAssets();
        //bool HasGameEnded();
        static bool DebugMode;

    private:
        Application();

        std::chrono::system_clock::time_point last_tick;
        std::chrono::system_clock::time_point last_test;

        int frame_count = 0;

        static constexpr double TargetFPS = 60.0;
        static constexpr int FPSDuration = 5;
        static constexpr int FPSTargetFrames = static_cast<int>(FPSDuration * TargetFPS);

        Engine::Window window;
        Engine::GameStateManager gamestatemanager;
        
        std::vector<Texture> assets;


    };
}