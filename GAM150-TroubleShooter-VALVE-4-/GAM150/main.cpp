#include "Engine/Application.h"
#include "Game/GameMode.h"
#include "Game/MainMenu.h"
int main() {


    Engine::Application& engine = Engine::Application::Instance();
    engine.Start("TroubleShooter");
    Game::MainMenu mainmenu;
    engine.GetGameStateManager().AddGameState(mainmenu);
    Game::GameMode gamemode;
    engine.GetGameStateManager().AddGameState(gamemode);
  

    while (engine.HasGameEnded() == false) {
        engine.Update();
    }
    return 0;
}