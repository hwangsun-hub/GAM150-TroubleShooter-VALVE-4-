#include "Door.h"

Door::Door(Vector2 pos, int tileid, bool isglitchmoded):
	position(pos),
	tile_id(tileid),
	isglitchmoded(isglitchmoded),
	hitbox({ position.x, position.y,SIZE,SIZE }),
	id(ObjectID::ID::DOOR),
	isActive(false)
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
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode);
	//for debuging
	if (Engine::Application::DebugMode == true)
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}

Vector2 Door::GetPosition()
{
	return position;
}

Rectangle Door::GetHitbox()
{
	return hitbox;
}

ObjectID::ID Door::GetObjectID()
{
	return id;
}

bool Door::GetIsGlitchMode()
{
	return isglitchmoded;
}

bool Door::CheckCollision(Rectangle hibox)
{
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Door::SetAnotherDoor(Door* anotherDoor)
{
	this->anotherDoor = anotherDoor;
}




Door* Door::GetAnotherDoor()
{
	return anotherDoor;
}
