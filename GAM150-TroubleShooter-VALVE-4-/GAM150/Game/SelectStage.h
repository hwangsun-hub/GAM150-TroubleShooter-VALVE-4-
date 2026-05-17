#pragma once
#include "../Engine/GameState.h"
#include "../Engine/GameObject.h"
#include <raylib.h>
#include <vector>
#include "Player.h"
#include "MapName.h"
#include "UI.h"

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
        MapName currentMapName = MapName::SelectStage;
        std::vector<std::vector<std::vector<int>>> maps;

        std::vector<Engine::GameObject*> objects;
        static constexpr int TILE_SIZE = 64;
        Vector2 player_start_position;
    };
}