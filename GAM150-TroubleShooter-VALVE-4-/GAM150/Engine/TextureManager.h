#pragma once
#include <raylib.h>
#include <vector>
#include <array>
#include "ObjectID.h"

namespace Engine {
	class TextureManager {
	public:
		TextureManager();
		Rectangle GetTextureSourceRec(ObjectID::ID id, int map_num, bool isglitchedMode);
		void DrawTexure(ObjectID::ID id, int map_num, Vector2 position, Vector2 size, bool isglitchedMode);
		void DrawTexure(ObjectID::ID id, int map_num, Vector2 position, bool isglitchedMode);
		void DrawTexure(ObjectID::ID id, int map_num, Vector2 position, bool isglitchedMode, float rotation);
		void DrawTexure(ObjectID::ID id, Vector2 position);

	private:
		std::vector<std::vector<Rectangle>> textures;

		static constexpr int TILE_SIZE = 64;


	};
}