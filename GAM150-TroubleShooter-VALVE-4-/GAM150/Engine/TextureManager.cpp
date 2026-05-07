#include "TextureManager.h"
#include "Application.h"

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
