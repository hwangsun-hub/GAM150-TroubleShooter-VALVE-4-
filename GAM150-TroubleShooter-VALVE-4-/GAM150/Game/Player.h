#pragma once
#include <raylib.h>

namespace Game {
	class player
	{
	public:
		player();
		~player();
		void Load();
		void Update();
		void Draw();
		Vector2 GetPosition();
		Rectangle GetHitbox();


	private:
		Texture2D texture;
		Vector2 position;
		Rectangle hitbox;

	};
}