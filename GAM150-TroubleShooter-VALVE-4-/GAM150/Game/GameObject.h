#pragma once
#include <raylib.h>
#include "../Engine/ObjectID.h"
namespace Game {
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		void Load();
		void Update();
		void Draw();
		void GetPosition();
		Rectangle GetHitbox();


	private:
		Vector2 position;
		Texture2D texture;
		bool isGlitchMode;
		Rectangle hitbox;
		ObjectID::ID id;

	};

}