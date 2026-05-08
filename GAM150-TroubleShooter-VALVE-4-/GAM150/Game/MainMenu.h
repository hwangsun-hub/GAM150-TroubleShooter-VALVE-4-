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
        int choose_y = 420;
        int choose_index = 0;
    };
}