#include "MainMenu.h"
#include "../Engine/Application.h"
Game::MainMenu::MainMenu()
{
}

void Game::MainMenu::Load()
{
    texture_mainmenu = LoadTexture("Assets/MainMenu.png");
    texture_choose = LoadTexture("Assets/choose.png");

}

void Game::MainMenu::Update(double dt)
{
    if (IsKeyPressed(KEY_DOWN)) {
        choose_index++;
        if (choose_index > 2) choose_index = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
        choose_index--;
        if (choose_index < 0) choose_index = 2;
    }

    choose_y = 420 + choose_index * 90;

    if (IsKeyPressed(KEY_ENTER)) {
        switch (choose_index) {
        case 0:  // Start Game
            Engine::Application::GetGameStateManager().SetNextGameState(1);  // gamemode 
            break;
        case 1:  // Option
            break;
        case 2:  // Exit
            Engine::Application::GetGameStateManager().ClearNextGameState();
            break;
        }
    }

}

void Game::MainMenu::Unload()
{
    UnloadTexture(texture_mainmenu);
    UnloadTexture(texture_choose);

}

void Game::MainMenu::Draw()
{
    DrawTexture(texture_mainmenu, 0, 0, WHITE);
    DrawTexture(texture_choose, 370, choose_y, WHITE);

}