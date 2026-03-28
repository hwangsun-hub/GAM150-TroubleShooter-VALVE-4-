#pragma once
#include <raylib.h>
#include "../Engine/ObjectID.h"
namespace Game {
	class GameObject
	{
	public:
		void GetPosition();


	private:
		Vector2 position;
		Texture2D texture;
		bool HasGlitchMode;
		bool isGlitchMode;
		Rectangle hitbox;
		ObjectID::ID id;

	};

}