#pragma once
#include "../Engine/GameState.h"
#include "GameMap.h"
#include "Player.h"
#include "../Engine/GameObjectManager.h"
#include "dialogue.h"
#include "UI.h"
#include <map>
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
        std::string GetCurentMapNameForDialogue() const;
        std::string GetCurrentMapName() const;
        void ChangeMap(MapName newMap);
        static MapName selectedMap;
    private:
        MapName currentMapName = selectedMap;
        Game::GameMap gameMap;
        Game::Player player;
        UI ui;
        Dialogue dialogue;
        enum class gamestate
        {
            Playing,
            Dialogue,
            
        };
        gamestate gamestate;
        std::map<MapName, int> max_trouble = {
            { MapName::STAGE0_LEVEL1, 0 },
            { MapName::STAGE0_LEVEL2, 0 },
            { MapName::STAGE0_LEVEL3, 1 },

            { MapName::STAGE1_LEVEL1, 2 },
            { MapName::STAGE1_LEVEL2, 3 },
            { MapName::STAGE1_LEVEL3, 4 },

            { MapName::STAGE2_LEVEL1, 0 },
            { MapName::STAGE2_LEVEL2, 0 },
            { MapName::STAGE2_LEVEL3, 0 },

            { MapName::STAGE3_LEVEL1, 0 },
            { MapName::STAGE3_LEVEL2, 0 },
            { MapName::STAGE3_LEVEL3, 0 },

            { MapName::STAGE4_LEVEL1, 100 },
            { MapName::STAGE4_LEVEL2, 0 },
            { MapName::STAGE4_LEVEL3, 0 },

            { MapName::STAGE5_LEVEL1, 2 },
            { MapName::STAGE5_LEVEL2, 2 },
            { MapName::STAGE5_LEVEL3, 2 }
        };
    };
}
