#include "Door.h"

Door::Door(Vector2 pos, int tileid, bool isglitchmoded):
	position(pos),
	tile_id(tileid),
	isGlitchMode(isglitchmoded),
	hitbox({ position.x, position.y,SIZE,SIZE }),
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
	return isGlitchMode;
}

bool Door::CheckCollision(Rectangle hibox)
{
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Door::SetAnotherDoor(Door* anotherDoor)
{
	this->anotherDoor = anotherDoor;
}

void Door::SetIsGlitchemoded(bool isglitchmoded)
{
	isGlitchMode = isglitchmoded;
}

void Door::TroubleCollision()
{
	if (isGlitchMode == false) {
		isGlitchMode = true;
		anotherDoor->SetIsGlitchemoded(true);
	}
	else {
		isUnload = true;
		anotherDoor->Unload(true);
	}

}




Door*& Door::GetAnotherDoor()
{
	return anotherDoor;
}
