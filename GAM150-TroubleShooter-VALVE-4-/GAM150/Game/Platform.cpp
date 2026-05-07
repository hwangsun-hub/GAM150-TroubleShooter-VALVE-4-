#include "Platform.h"
#include <iostream>

Platform::Platform(Vector2 pos, int tileid, bool isglitchmoded) :
	position(pos),
	isGlitchMode(isglitchmoded),
	tile_id(tileid),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::PLATFORM)
{
}
Vector2  Platform::GetPosition() {
	return position;
}
Rectangle  Platform::GetHitbox() {
	return hitbox;
}
ObjectID::ID Platform::GetObjectID() {
	return id;
}
bool Platform::GetIsGlitchMode() {
	return isGlitchMode;
}

bool  Platform::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Platform::Load() {
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Platform::Update(double dt) {

}

void Platform::Draw() {
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode);
	//for debuging
	if (Engine::Application::DebugMode == true) {
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? YELLOW : PINK);
	}
}
