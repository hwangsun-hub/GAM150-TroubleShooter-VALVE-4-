#pragma once
#include <raylib.h>
#include "GameObject.h"
#include "Player.h"

class Floor : public Game::GameObject
{
public:
	Floor();
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool CheckCollision(Rectangle hibox) override;

private:
	Vector2  position;
	Texture2D texture;
	bool isGlitchMode;
	bool isCollision;
	Rectangle hitbox;
	ObjectID::ID id;
};

