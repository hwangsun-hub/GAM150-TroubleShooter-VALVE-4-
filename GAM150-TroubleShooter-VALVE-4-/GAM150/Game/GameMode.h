#pragma once
#include "../Engine/GameState.h"
#include "GameMap.h"
#include "Player.h"
#include "../Engine/GameObjectManager.h"
namespace Game {
    class GameMode : public Engine::GameState {
    public:
        GameMode();
        void Load() override;
        void Update([[maybe_unused]] double dt) override;
        void Unload() override;
        void Draw() override;

        std::string GetName() override {
            return "GameMode";
        }



    private:
        Game::GameMap gameMap;
        Game::Player player;
    };
}
