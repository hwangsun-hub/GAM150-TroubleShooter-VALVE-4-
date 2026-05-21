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
		virtual void TroubleCollision();
		virtual bool CheckCollision(Rectangle hibox) = 0;
		void Unload(bool isUnload);
		bool GetUnload() const;
		void SetActive(bool isactive);
		bool GetActive() const;


	protected:
		static constexpr int SIZE = 64;
		Vector2  position = { 0, 0 };
		Texture2D texture = { 0 };
		bool isGlitchMode = false;
		Rectangle hitbox = { 0, 0, 0, 0 };
		ObjectID::ID id = ObjectID::ID::DEFAULT;

		TextureManager texturemanager;

		bool isUnload = false;
		bool isActive = false;

	};

}