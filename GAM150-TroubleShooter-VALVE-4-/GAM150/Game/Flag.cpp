#include "Flag.h"
#include <iostream>

Flag::Flag(Vector2 pos, int tileid, bool isglitchmoded) :
	position(pos),
	isGlitchMode(isglitchmoded),
	tile_id(tileid),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::FLAG)
{
}
Vector2  Flag::GetPosition() {
	return position;
}
Rectangle  Flag::GetHitbox() {
	return hitbox;
}
ObjectID::ID Flag::GetObjectID() {
	return id;
}
bool Flag::GetIsGlitchMode() {
	return isGlitchMode;
}

bool  Flag::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Flag::Load() {
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Flag::Update(double dt) {

}

void Flag::Draw() {

	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode);
	//for debuging
	if (Engine::Application::DebugMode == true) {
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? PINK : YELLOW);
	}
}
