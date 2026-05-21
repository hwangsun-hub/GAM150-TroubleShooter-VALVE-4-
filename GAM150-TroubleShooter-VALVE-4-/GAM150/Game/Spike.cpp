#include "Spike.h"
#include <iostream>

Spike::Spike(Vector2 pos, int tileid, bool isglitchmoded, bool isupsidedown) :
	position(pos),
	tile_id(tileid),
	hitbox({ position.x+10, position.y + 32,0,0 }),
	id(ObjectID::ID::SPIKE),
	isUpsidedown(isupsidedown)
{
	isGlitchMode = isglitchmoded;
	if (isUpsidedown) {
		hitbox.y -= 32;
	}
}
Vector2  Spike::GetPosition() {
	return position;
}
Rectangle  Spike::GetHitbox() {
	return hitbox;
}
ObjectID::ID Spike::GetObjectID() {
	return id;
}
bool Spike::GetIsGlitchMode() {
	return isGlitchMode;
}

bool Spike::IsUpsideDown() {
	return isUpsidedown;
}

bool  Spike::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Spike::Load() {
	hitbox.width = 44;
	hitbox.height = 32;

}
void  Spike::Update(double dt) {
}

void Spike::Draw() {
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode);
	//for debuging
	if (Engine::Application::DebugMode == true)
	DrawRectangleLinesEx(hitbox, 5, RED);
}