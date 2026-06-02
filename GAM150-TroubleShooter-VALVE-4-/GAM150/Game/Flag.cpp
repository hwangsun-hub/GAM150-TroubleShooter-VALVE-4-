#include "Flag.h"
#include <iostream>

Flag::Flag(Vector2 pos, int tileid, bool isglitchmoded) :
	position(pos),
	tile_id(tileid),
	hitbox({ position.x + 12, position.y,40,SIZE }),
	id(ObjectID::ID::FLAG)
{
	isGlitchMode = isglitchmoded;
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
