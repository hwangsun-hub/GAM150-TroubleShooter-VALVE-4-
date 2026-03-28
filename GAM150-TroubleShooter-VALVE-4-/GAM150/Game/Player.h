#pragma once
#include <raylib.h>

namespace Game {
	class player
	{
	public:
		player();
		~player();

	private:
		Texture2D texture;
		Vector2 position;
		Rectangle hitbox;

	};
}