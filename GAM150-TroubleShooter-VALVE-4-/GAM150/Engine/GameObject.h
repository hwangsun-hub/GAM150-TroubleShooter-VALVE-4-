#pragma once
#include <raylib.h>
#include <raymath.h>
#include "Application.h"
#include "ObjectID.h"
namespace Engine {
	class GameObject
	{
	public:
		virtual void Load() = 0;
		virtual void Update(double dt) = 0;
		virtual void Draw() = 0;
		virtual Vector2 GetPosition() = 0;
		virtual Rectangle GetHitbox() = 0;
		virtual ObjectID::ID GetObjectID() = 0;
		virtual bool GetIsGlitchMode() = 0;
		void TroubleCollision();
		virtual bool CheckCollision(Rectangle hibox) = 0;
		void SetDead(bool isdead);
		bool GetDead() const;
		void SetActive(bool isactive);
		bool GetActive() const;


	private:
		Vector2  position;
		Texture2D texture;
		bool isGlitchMode;
		bool isCollision;
		Rectangle hitbox;
		ObjectID::ID id;

		bool isDead = false;
		bool isActive = false;


	};

}