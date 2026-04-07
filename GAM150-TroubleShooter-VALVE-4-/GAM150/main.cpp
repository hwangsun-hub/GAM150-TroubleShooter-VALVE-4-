#include "Engine/Application.h"
#include "Game/GameMode.h"

int main() {


    Engine::Application& engine = Engine::Application::Instance();
    engine.Start("TroubleShooter");
    Game::GameMode gamemode;
    engine.GetGameStateManager().AddGameState(gamemode);
    while (IsKeyPressed(KEY_ESCAPE) == false) {
        
        engine.Update();
    }
    return 0;
}