#pragma once
#include <raylib.h>

namespace Game {
	class player
	{
	public:
		void Load();
		void Update(double dt);
		void Draw();
		Vector2 GetPosition();
		Rectangle GetHitbox();


	private:
		Texture2D texture;
		Vector2 position = { 0,0 };
		Rectangle hitbox;

		static constexpr int SPEED = 50;

	};
}