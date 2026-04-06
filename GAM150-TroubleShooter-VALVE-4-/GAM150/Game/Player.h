#pragma once
#include "../Game/GameObject.h"
#include <raylib.h>
#include <raymath.h>

namespace Game {
	class Player
	{
	public:
		Player();
		void Load();
		void Unload();
		void HandleCollision(GameObject* obj, double dt);
		void CorrectCollision(GameObject* obj, double dt);
		void Update(double dt);
		void Draw();
		Vector2 GetPosition() const;
		Vector2 GetVelocity() const;
		Rectangle GetHitbox() const;
		bool GetIsAlive() const;
		void SetCanJump(bool CanJump);
		void SetIsOnGround(bool IsOnGround);
		bool IsReadyToNextLevel = false;


	private:
		Texture2D texture;
		Vector2 position = { 100,100 };
		Vector2 velocity = { 0,0 };
		Rectangle hitbox;


		bool CanJump;
		bool IsOnGround;
		bool IsAlive;
		static constexpr int MOVE_SPEED = 250;
		static constexpr int JUMP_SPEED = -400;
		static constexpr int GRAVITY = 500;

	};
}