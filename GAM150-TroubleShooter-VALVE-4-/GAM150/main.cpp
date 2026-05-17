#include "Engine/Application.h"
#include "Game/GameMode.h"
#include "Game/MainMenu.h"
#include "Game/States.h"
#include "Game/SelectStage.h"
#include "Game/Option.h"
int main() {


    Engine::Application& engine = Engine::Application::Instance();
    engine.Start("TroubleShooter");
    Game::MainMenu mainmenu;
    engine.GetGameStateManager().AddGameState(mainmenu);
    Game::SelectStage selectstage;
    engine.GetGameStateManager().AddGameState(selectstage);
    Game::GameMode Option;
    engine.GetGameStateManager().AddGameState(Option);
    Game::GameMode gamemode;
    engine.GetGameStateManager().AddGameState(gamemode);
    

    while (engine.HasGameEnded() == false) {
        engine.Update();
    }
    return 0;
}