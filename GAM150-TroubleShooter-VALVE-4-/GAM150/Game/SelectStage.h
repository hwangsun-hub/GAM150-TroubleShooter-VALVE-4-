#pragma once
#include "../Engine/GameState.h"
#include "../Engine/GameObject.h"
#include <raylib.h>
#include <vector>
#include "Player.h"
#include "MapName.h"
#include "UI.h"
#include <map>
namespace Game {
    class SelectStage : public Engine::GameState {
    public:
        SelectStage();
        ~SelectStage();

        void LoadMap() ;
        void Unload() override;
        void Load( ) override;
        void Update(double dt) override;
        void Draw() override;
        Vector2 GetStartPosition() const;
        std::string GetName() override {
            return "SelectStage";
        }

    private:
        void MapTransition();
        void UpdateObjects(double dt);
        Player player;
        UI ui;
        void ChangeMap();
		std::string GetCurrentMapName() const;
        MapName currentMapName = MapName::SelectStage;
        std::vector<std::vector<std::vector<int>>> maps;

        std::vector<Engine::GameObject*> objects;
        static constexpr int TILE_SIZE = 64;
        Vector2 player_start_position;
        std::map<std::string, MapName> MapNameStringToMapName = {
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