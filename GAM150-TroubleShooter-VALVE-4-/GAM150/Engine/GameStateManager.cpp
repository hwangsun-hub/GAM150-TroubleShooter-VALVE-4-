#include "GameStateManager.h"
#include "Application.h"

Engine::GameStateManager::GameStateManager() :
    current_gamestate(nullptr),
    next_gamestate(nullptr),
    status(Status::STARTING)
{
}

void Engine::GameStateManager::AddGameState(GameState& gamestate) {
    gamestates.push_back(&gamestate);
}

void Engine::GameStateManager::SetNextGameState(int index) {
    next_gamestate = gamestates[index];
}

void Engine::GameStateManager::ReloadState() {
    status = Status::UNLOADING;
}

void Engine::GameStateManager::ClearNextGameState() {
    next_gamestate = nullptr;
    status = Status::UNLOADING;
}

bool Engine::GameStateManager::HasGameEnded() {
    return status == Status::EXIT;
}

void Engine::GameStateManager::Update(double _dt) {
    double dt = _dt;
    switch (status) {
    case Status::STARTING:
        if (gamestates.empty() == false) {
            next_gamestate = gamestates[0];
            status = Status::LOADING;
        }
        else {
            status = Status::STOPPING;
        }
        break;
    case Status::LOADING:
        current_gamestate = next_gamestate;
        current_gamestate->Load();
        status = Status::UPDATING;
        break;
    case Status::UPDATING:
        if (current_gamestate != next_gamestate) {    //If next_gamestate was changed to something else
            status = Status::UNLOADING;
        }
        else {
            current_gamestate->Update(dt);
            current_gamestate->Draw();
            
        }
        break;
    case Status::UNLOADING:
        current_gamestate->Unload();
        status = Status::LOADING;
        if (next_gamestate == nullptr) {
            status = Status::STOPPING;
        }
        break;
    case Status::STOPPING:
        status = Status::EXIT;
        break;
    case Status::EXIT:
        break;
    }

}


