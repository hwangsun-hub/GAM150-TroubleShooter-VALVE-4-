#pragma once
#include <raylib.h>
#include "../Engine/ObjectID.h"
#include "Player.h"
namespace Game {
	class GameObject
	{
	public:
		virtual void Load() = 0;
		virtual void Update(double dt) = 0;
		virtual void Draw() = 0;
		virtual Vector2 GetPosition() = 0;
		virtual Rectangle GetHitbox() = 0;
		virtual ObjectID::ID GetObjectID() = 0;
		virtual bool CheckCollision(Rectangle hibox) = 0;


	private:
		Game::Player* player;
		Vector2  position;
		Texture2D texture;
		bool isGlitchMode;
		bool isCollision;
		Rectangle hitbox;
		ObjectID::ID id;

	};

}