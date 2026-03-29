#include "TileMap.h"

void Engine::TileMap::Load() {
	for (float i = 0; i < FLOORTILE_WIDTH_NUMBER; ++i) {
		for (float j = 0; j < FLOORTILE_HEIGHT_NUMBER; ++j) {
			tileSources[static_cast<int>(ObjectID::ID::FLOOR)].push_back(Rectangle{ i * TILE_SIZE,
																					j * TILE_SIZE, 
																					TILE_SIZE ,
																					TILE_SIZE });
		}
		
	}
	tileSources[static_cast<int>(ObjectID::ID::SPIKE)].push_back(Rectangle(0, 0, TILE_SIZE, TILE_SIZE));
}

std::vector<std::vector<Rectangle>> Engine::TileMap::GetTileSources() {
	return tileSources;
}
std::vector<Texture2D> Engine::TileMap::GetTileTextures() {
	return textures;
}