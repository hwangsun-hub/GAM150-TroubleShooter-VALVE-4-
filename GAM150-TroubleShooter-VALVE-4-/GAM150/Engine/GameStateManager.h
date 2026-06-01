#pragma once
#include "GameState.h"
#include <vector>

namespace Engine {
    class GameStateManager {
    public:
        GameStateManager();

        void Update(double dt);

        void AddGameState(GameState& gamestate);
        void SetNextGameState(int index);
        void ReloadState();
        void ClearNextGameState();
        bool HasGameEnded();
        GameState* GetGameState(int index) { return gamestates[index]; }
    private:
        enum class Status {
            STARTING,
            LOADING,
            UPDATING,
            UNLOADING,
            STOPPING,
            EXIT
        };

        Status status;
        std::vector<GameState*> gamestates;
        GameState* current_gamestate;
        GameState* next_gamestate;
    };
}
