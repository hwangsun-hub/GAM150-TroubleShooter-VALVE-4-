#pragma once
#include "../Engine/GameState.h"
#include "GameMap.h"
#include "Player.h"
#include "../Engine/GameObjectManager.h"
#include "dialogue.h"

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
        std::string GetCurentMapName() const;


    private:
        MapName currentMapName = MapName::STAGE2_LEVEL1;
        Game::GameMap gameMap;
        Game::Player player;
        Dialogue dialogue;
        enum class gamestate
        {
            Playing,
            Dialogue
        };
        gamestate gamestate;

    };
}
