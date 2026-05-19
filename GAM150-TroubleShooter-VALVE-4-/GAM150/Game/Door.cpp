#include "Door.h"

Door::Door(Vector2 pos, int tileid, bool isglitchmoded):
	position(pos),
	tile_id(tileid),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::DOOR)
{
}

void Door::Load()
{
}

void Door::Update(double dt)
{
}

void Door::Draw()
{
}

Vector2 Door::GetPosition()
{
	return Vector2();
}

Rectangle Door::GetHitbox()
{
	return Rectangle();
}

ObjectID::ID Door::GetObjectID()
{
	return ObjectID::ID();
}

bool Door::GetIsGlitchMode()
{
	return false;
}

bool Door::CheckCollision(Rectangle hibox)
{
	return false;
}
