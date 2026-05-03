#pragma once
#include <raylib.h>
#include "../Engine/ObjectID.h"
#include "../Engine/GameObject.h"

class Trouble{
public:
	Trouble(Vector2 pos, Rectangle texture_source);
	void Load();
	void Update(Engine::GameObject* objects, double dt);
	void Draw();
	Vector2 GetPosition();
	Rectangle GetHitbox();
	ObjectID::ID GetObjectID();
	bool GetUnload() const;

private:
	Vector2  position;
	Texture2D texture;
	bool isCollision;
	bool isUnload = false;
	bool isFlipped = false;
	Rectangle hitbox;
	Rectangle textureSourceRectangle;
	ObjectID::ID id;

	static constexpr int SIZE = 8;
	static constexpr int SPEED = 100;
};