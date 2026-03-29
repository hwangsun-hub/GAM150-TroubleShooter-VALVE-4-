#pragma once
#include <raylib.h>
#include <vector>
#include "ObjectID.h"
namespace Engine {
	class TileMap
	{
	public:
		void Load();
		std::vector<std::vector<Rectangle>> GetTileSources();
		std::vector<Texture2D> GetTileTextures();

	private:
		std::vector<std::vector<Rectangle>> tileSources;
		std::vector<Texture2D> textures;
		static constexpr int FLOORTILE_WIDTH_NUMBER = 5;
		static constexpr int FLOORTILE_HEIGHT_NUMBER = 5;
		static constexpr int TILE_SIZE = 16;
	};

}