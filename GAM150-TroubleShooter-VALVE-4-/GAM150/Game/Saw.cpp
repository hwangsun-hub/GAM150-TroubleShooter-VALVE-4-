#include "Saw.h"
#include <iostream>

Saw::Saw(Vector2 pos, int tileid, bool isglitchmoded) :
	position(pos),
	tile_id(tileid),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::SAW),
	rotation(0)
{
}
Vector2  Saw::GetPosition() {
	return position;
}
Rectangle  Saw::GetHitbox() {
	return hitbox;
}
ObjectID::ID Saw::GetObjectID() {
	return id;
}
bool Saw::GetIsGlitchMode() {
	return isGlitchMode;
}

bool  Saw::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Saw::Load() {
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Saw::Update(double dt) {
	rotation+=dt*100;
}

void Saw::Draw() {
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode, rotation);
	//for debuging
	if (Engine::Application::DebugMode == true)
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}
