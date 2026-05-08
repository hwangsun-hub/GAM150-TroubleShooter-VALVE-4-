#include "MainMenu.h"
#include "../Engine/Application.h"
Game::MainMenu::MainMenu()
{
}

void Game::MainMenu::Load()
{
    texture_background = LoadTexture("Assets/test.png");
    texture_mainmenu = LoadTexture("Assets/Sprite-0002-Recovered.png");
    texture_choose = LoadTexture("Assets/Sprite-0001.png");
    texture_logo = LoadTexture("Assets/Timeline1-ezgif.com-optimize.png");

}

void Game::MainMenu::Update(double dt)
{
    timer += dt;
    if (timer >= 0.06) {
        frame++;
        if (frame == FRAME_WIDTH_NUM) {
            frame = 0;
        }
        timer = 0;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        choose_index++;
        if (choose_index > 2) choose_index = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
        choose_index--;
        if (choose_index < 0) choose_index = 2;
    }

    choose_y = 355 + choose_index * 65;

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
    DrawTexturePro(
        texture_background,

        Rectangle{
            0,
            0,
            (float)texture_background.width,
            (float)texture_background.height
        },

        Rectangle{
            0,
            0,
            Engine::Application::GetWindow().GetSize().x,
            Engine::Application::GetWindow().GetSize().y
        },
        Vector2{ 0,0 },
        0.0f,
        WHITE
    );

    DrawTexturePro(
        texture_logo,

        Rectangle{
            (float)FRAME_WIDTH * frame,
            0,
            (float)FRAME_WIDTH,
            (float)texture_logo.height
        },

        Rectangle{
            0,
            0,
            Engine::Application::GetWindow().GetSize().x,
            Engine::Application::GetWindow().GetSize().y
        },
        Vector2{ 0,0 },
        0.0f,
        WHITE
    );

    DrawTexturePro(
        texture_mainmenu,

        Rectangle{
            0,
            0,
            (float)texture_mainmenu.width,
            (float)texture_mainmenu.height
        },

        Rectangle{
            0,
            0,
            Engine::Application::GetWindow().GetSize().x,
            Engine::Application::GetWindow().GetSize().y
        },
        Vector2{ 0,0 },
        0.0f,
        WHITE
    );

    DrawTexture(texture_choose, 350, choose_y, WHITE);


}