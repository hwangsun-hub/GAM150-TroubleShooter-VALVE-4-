#include "Option.h"
#include "../Engine/Application.h"
#include "States.h"

float Game::Option::sound = 0.5f;
float Game::Option::sound2 = 0.5f;
float Game::Option::sound3 = 0.5f;

Game::Option::Option()
{
    
}

void Game::Option::Load()
{
    texture_background = LoadTexture("Assets/Texture/test.png");

	texture_option	  =   LoadTexture("Assets/Texture/option.png");
	texture_choose	  =   LoadTexture("Assets/Texture/Sprite-0001.png");
	texture_sound_bar =   LoadTexture("Assets/Texture/sound_bar.png");
	texture_sound	  =   LoadTexture("Assets/Texture/sound.png");
}

void Game::Option::Update(double dt)
{
    if (IsKeyPressed(KEY_DOWN)) {
        choose_index++;
        if (choose_index > 4) choose_index = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
        choose_index--;
        if (choose_index < 0) choose_index = 4;
    }
    switch (choose_index) {
    case 0: [[fallthrough]];
    case 1: [[fallthrough]];
    case 2:
        choose_y = 325 + choose_index * 95;
        break;
    case 3:  // DELETE SAVE FILE
        choose_y = 635;
        break;
    case 4:  // EXIT
        choose_y = 740;
        break;
    }

    if (IsKeyPressed(KEY_RIGHT)) {
        switch (choose_index) {
        case 0:  // MASTER
            if (sound < 1)
                sound += 0.1;
            SetMasterVolume(sound);
            break;
        case 1:  // BGM
            if (sound2 < 1)
                sound2 += 0.1;
            Engine::Application::GetAudioManager().SetMusicV(sound2);
            break;
        case 2:  // SFX
            if (sound3 < 1)
                sound3 += 0.1;
            Engine::Application::GetAudioManager().SetSoundV(sound3);
            break;
        }
    }

        if (IsKeyPressed(KEY_LEFT)) {
            switch (choose_index) {
            case 0:  // MASTER
                if (sound > 0)
                    sound -= 0.1;
                SetMasterVolume(sound);
                break;
            case 1:  // BGM
                if (sound2 > 0)
                    sound2 -= 0.1;
                Engine::Application::GetAudioManager().SetMusicV(sound2);
                break;
            case 2:  // SFX
                if (sound3 > 0)
                    sound3 -= 0.1;
                Engine::Application::GetAudioManager().SetSoundV(sound3);
                break;
            }
        }
        


        if (IsKeyPressed(KEY_ENTER)) {
            switch (choose_index) {
            case 0:  // MASTER
                break;
            case 1:  // BGM
                break;
            case 2:  // SFX
                break;
            case 3:  // DELETE SAVE FILE
                Engine::Application::GetSaveFile().Save("STAGE0_LEVEL1");
                break;
            case 4:  // EXIT
                Engine::Application::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));
                break;
            }
        }
    }


void Game::Option::Unload()
{
    UnloadTexture(texture_option);
    UnloadTexture(texture_choose);
    UnloadTexture(texture_sound_bar);
    UnloadTexture(texture_sound);
    UnloadTexture(texture_background);

}

void Game::Option::Draw()
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
        texture_option,

        Rectangle{
            0,
            0,
            (float)texture_option.width,
            (float)texture_option.height
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
        texture_sound,

        Rectangle{
            0,
            0,
            (float)texture_sound.width,
            (float)texture_sound.height
        },

        Rectangle{
            0,
            0,
              (float)texture_sound.width,
            (float)texture_sound.height
        },
        Vector2{ 0,0 },
        0.0f,
        WHITE
    );

    DrawTexture(texture_choose, choose_x, choose_y, WHITE);
    DrawRectangle(600, 325, 410 * sound, 45, GREEN);
    DrawRectangle(600, 325 + 1 * 95, 410 * sound2, 45, GREEN);
    DrawRectangle(600, 325 + 2 * 95, 410 * sound3, 45, GREEN);



}
