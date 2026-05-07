#pragma once
#include <raylib.h>
#include <vector>
#include <array>
#include "ObjectID.h"

class TextureManager {
public:
	TextureManager();
	Rectangle GetTextureSourceRec(ObjectID::ID id, int map_num, bool isglitchedMode);

private:
	std::vector<std::vector<Rectangle>> textures;

	static constexpr int TILE_SIZE = 64;

	
};