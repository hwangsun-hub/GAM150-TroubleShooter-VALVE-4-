#pragma once
#include <raylib.h>
#include "GameObject.h"
#include "Player.h"

class Floor : public Game::GameObject
{
public:
	Floor(Vector2 pos, Rectangle texture_source);
	void Load() override;
	void Update(Game::Player& player,double dt) override;
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
	Rectangle textureSourceRectangle;
	ObjectID::ID id;

	static constexpr int SIZE = 64;
};

