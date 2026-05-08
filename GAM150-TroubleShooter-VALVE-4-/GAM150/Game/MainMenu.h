#pragma once
#include "../Engine/GameState.h"
#include <raylib.h>

namespace Game {
    class MainMenu : public Engine::GameState {
    public:
        MainMenu();
        void Load() override;
        void Update([[maybe_unused]] double dt) override;
        void Unload() override;
        void Draw() override;
        std::string GetName() override {
            return "MainMenu";
        }



    private:
        Texture2D texture_mainmenu;
        Texture2D texture_choose;
        Texture2D texture_logo;
        Texture2D texture_background;
        int choose_y = 420;
        int choose_index = 0;
        int frame = 0;


        static constexpr int FRAME_WIDTH = 1920;
        static constexpr int FRAME_WIDTH_NUM = 8;

        double timer = 0;
    };
}