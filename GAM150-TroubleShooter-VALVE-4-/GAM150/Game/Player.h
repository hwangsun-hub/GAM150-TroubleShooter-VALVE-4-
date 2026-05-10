#pragma once
#include "../Engine/GameObject.h"
#include <raylib.h>
#include <raymath.h>

namespace Game {
	class Player
	{
	public:
		Player();
		void Load(Vector2 start_position);
		void Unload();
		void HandleCollision(Engine::GameObject* obj, double dt);
		void CorrectCollision(Engine::GameObject* obj, double dt);
		void Update(double dt);
		void Draw();
		Vector2 GetPosition() const;
		Vector2 GetVelocity() const;
		Rectangle GetHitbox() const;
		bool GetIsAlive() const;
		void SetCanJump(bool CanJump);
		void SetIsOnGround(bool IsOnGround);
		bool CheckTroubleShoot();
		bool GetIsLookingRight() const;
		bool IsReadyToNextLevel = false;
		void SetTroubleBullet(int max);
		int GetCurrentTroubleBullet() const { return trouble_bullet; }
	private:
		Texture2D texture;
		Vector2 position ;
		Vector2 velocity = { 0,0 };
		Rectangle hitbox;

		int trouble_bullet;

		bool CanJump;
		bool IsOnGround;
		bool IsJump;
		bool IsAlive;
		bool IsLookingRight;
		bool IsTroubleShoot;
		
		static constexpr int MOVE_SPEED = 250;
		static constexpr int JUMP_SPEED = -400;
		static constexpr int GRAVITY = 500;

	};
}