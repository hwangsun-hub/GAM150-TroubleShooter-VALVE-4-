#pragma once
#include "../Engine/GameState.h"
#include <raylib.h>

namespace Game {
    class Option : public Engine::GameState {
    public:
        Option();
        void Load() override;
        void Update([[maybe_unused]] double dt) override;
        void Unload() override;
        void Draw() override;
        std::string GetName() override {
            return "MainMenu";
        }



    private:
      
    };
}