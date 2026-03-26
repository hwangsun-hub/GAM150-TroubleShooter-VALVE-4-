#pragma once
#include "Window.h"
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
        void Start(std::string window_title);
        void Stop();
        void Update();
        //bool HasGameEnded();

    private:
        Application();

        std::chrono::system_clock::time_point last_tick;
        std::chrono::system_clock::time_point last_test;

        int frame_count = 0;

        static constexpr double TargetFPS = 30.0;
        static constexpr int FPSDuration = 5;
        static constexpr int FPSTargetFrames = static_cast<int>(FPSDuration * TargetFPS);

        Engine::Window window;
    };
}