#pragma once
#include <raylib.h>
#include <raymath.h>

namespace Game {
	class Player
	{
	public:
		Player();
		void Load();
		void Update(double dt);
		void Draw();
		Vector2 GetPosition() const;
		Rectangle GetHitbox() const;
		void SetCanJump(bool CanJump);
		void SetIsOnGround(bool IsOnGround);


	private:
		Texture2D texture;
		Vector2 position = { 0,500 };
		Vector2 velocity = { 0,0 };
		Rectangle hitbox;


		bool CanJump;
		bool IsOnGround;

		static constexpr int MOVE_SPEED = 250;
		static constexpr int JUMP_SPEED = -500;
		static constexpr int GRAVITY = 10;

	};
}