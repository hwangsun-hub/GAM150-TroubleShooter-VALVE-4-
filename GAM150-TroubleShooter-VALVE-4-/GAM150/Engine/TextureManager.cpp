#include "TextureManager.h"
#include "Application.h"
#include <raymath.h>
namespace Engine {
    TextureManager::TextureManager()
    {

    }

    Rectangle TextureManager::GetTextureSourceRec(ObjectID::ID id, int map_num, bool isglitchedMode)
    {
        int width_num = Engine::Application::GetAssets()[static_cast<int>(id)].width / TILE_SIZE;

        int x = map_num % width_num;
        int y = map_num / width_num;

        return Rectangle{
            static_cast<float>(x * TILE_SIZE),
            static_cast<float>(
                isglitchedMode ?
                y * TILE_SIZE + (Engine::Application::GetAssets()[static_cast<int>(id)].height / 2) :
                y * TILE_SIZE
            ),
            TILE_SIZE,
            TILE_SIZE
        };
    }

    void TextureManager::DrawTexure(ObjectID::ID id, int map_num, Vector2 position, Vector2 size, bool isglitchedMode)
    {
        DrawTexturePro(
            Engine::Application::GetAssets()[static_cast<int>(id)],
            GetTextureSourceRec(id, map_num, isglitchedMode),
            Rectangle{ position.x, position.y, size.x, size.y },
            Vector2Zero(),
            0,
            WHITE);
    }

    void TextureManager::DrawTexure(ObjectID::ID id, int map_num, Vector2 position, bool isglitchedMode)
    {
        DrawTexturePro(
            Engine::Application::GetAssets()[static_cast<int>(id)],
            GetTextureSourceRec(id, map_num, isglitchedMode),
            Rectangle{ position.x, position.y, TILE_SIZE, TILE_SIZE },
            Vector2Zero(),
            0,
            WHITE);
    }

    void TextureManager::DrawTexure(ObjectID::ID id, int map_num, Vector2 position, bool isglitchedMode, float rotation)
    {
        DrawTexturePro(
            Engine::Application::GetAssets()[static_cast<int>(id)],
            GetTextureSourceRec(id, map_num, isglitchedMode),
            Rectangle{ position.x + TILE_SIZE / 2.0f, position.y + TILE_SIZE / 2.0f, TILE_SIZE, TILE_SIZE },
            Vector2{ TILE_SIZE /2.0f, TILE_SIZE /2.0f},
            rotation,
            WHITE);
    }

    void TextureManager::DrawTexure(ObjectID::ID id, Vector2 position)
    {
        DrawTextureV(
            Engine::Application::GetAssets()[static_cast<int>(id)],
            position,
            WHITE
        );
    }

}
