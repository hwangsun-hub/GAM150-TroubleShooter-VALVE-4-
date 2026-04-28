#pragma once
#include <raylib.h>
#include "Engine/ObjectID.h"
#include "Game/GameObject.h"

class Trouble{
public:
	Trouble(Vector2 pos, Rectangle texture_source);
	void Load();
	void Update(Game::GameObject* objects, double dt);
	void Draw();
	Vector2 GetPosition();
	Rectangle GetHitbox();
	ObjectID::ID GetObjectID();
	bool GetDead() const;

private:
	Vector2  position;
	Texture2D texture;
	bool isCollision;
	bool isDead = false;
	bool isFlipped = false;
	Rectangle hitbox;
	Rectangle textureSourceRectangle;
	ObjectID::ID id;

	static constexpr int SIZE = 8;
	static constexpr int SPEED = 100;
};