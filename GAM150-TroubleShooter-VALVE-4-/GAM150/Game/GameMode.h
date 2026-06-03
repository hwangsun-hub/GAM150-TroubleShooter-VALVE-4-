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
        void SetCurrentMap(MapName map) { currentMapName = map; }
    private:
        MapName currentMapName;
        Game::GameMap gameMap;
        Game::Player player;
        Game::Player player2;
        bool IsPlayer2Maked = false;
        
        UI ui;
        Dialogue dialogue;
        enum class gamestate
        {
            Playing,
            Dialogue,

        };
        gamestate gamestate;
        std::map<MapName, int> max_trouble = {
            { MapName::STAGE0_LEVEL1, 10 },
            { MapName::STAGE0_LEVEL2, 1 },
            { MapName::STAGE0_LEVEL3, 1 },

            { MapName::STAGE1_LEVEL1, 0 },
            { MapName::STAGE1_LEVEL2, 0 },
            { MapName::STAGE1_LEVEL3, 0 },

            { MapName::STAGE2_LEVEL1, 0 },
            { MapName::STAGE2_LEVEL2, 6 },
            { MapName::STAGE2_LEVEL3, 6 },

            { MapName::STAGE3_LEVEL1, 0 },
            { MapName::STAGE3_LEVEL2, 0 },
            { MapName::STAGE3_LEVEL3, 4 },

            { MapName::STAGE4_LEVEL1, 0 },
            { MapName::STAGE4_LEVEL2, 4 },
            { MapName::STAGE4_LEVEL3, 3 },

            { MapName::STAGE5_LEVEL1, 0 },
            { MapName::STAGE5_LEVEL2, 0 },
            { MapName::STAGE5_LEVEL3, 1 }
        };
        std::map<std::string, MapName> MapNameMap = {
            {"SelectStage", MapName::SelectStage},
            {"STAGE0", MapName::STAGE0},
            {"STAGE1", MapName::STAGE1},
            {"STAGE2", MapName::STAGE2},
            {"STAGE3", MapName::STAGE3},
            {"STAGE4", MapName::STAGE4},
            {"STAGE5", MapName::STAGE5},
            {"STAGE0_LEVEL1", MapName::STAGE0_LEVEL1},
            {"STAGE0_LEVEL2", MapName::STAGE0_LEVEL2},
            {"STAGE0_LEVEL3", MapName::STAGE0_LEVEL3},
            {"STAGE1_LEVEL1", MapName::STAGE1_LEVEL1},
            {"STAGE1_LEVEL2", MapName::STAGE1_LEVEL2},
            {"STAGE1_LEVEL3", MapName::STAGE1_LEVEL3},
            {"STAGE2_LEVEL1", MapName::STAGE2_LEVEL1},
            {"STAGE2_LEVEL2", MapName::STAGE2_LEVEL2},
            {"STAGE2_LEVEL3", MapName::STAGE2_LEVEL3},
            {"STAGE3_LEVEL1", MapName::STAGE3_LEVEL1},
            {"STAGE3_LEVEL2", MapName::STAGE3_LEVEL2},
            {"STAGE3_LEVEL3", MapName::STAGE3_LEVEL3},
            {"STAGE4_LEVEL1", MapName::STAGE4_LEVEL1},
            {"STAGE4_LEVEL2", MapName::STAGE4_LEVEL2},
            {"STAGE4_LEVEL3", MapName::STAGE4_LEVEL3},
            {"STAGE5_LEVEL1", MapName::STAGE5_LEVEL1},
            {"STAGE5_LEVEL2", MapName::STAGE5_LEVEL2},
            {"STAGE5_LEVEL3", MapName::STAGE5_LEVEL3}
        };
    };
}
