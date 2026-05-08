#include "Saw.h"
#include <iostream>

Saw::Saw(Vector2 pos, int tileid, bool isglitchmoded, Game::Player& player) :
	position(pos),
	tile_id(tileid),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::SAW),
	rotation(0),
	player_position(player)
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
	rotation += static_cast<float>(dt) * ROTATE_SPEED;
	if (isGlitchMode == true) {
		float dx = position.x - player_position.GetPosition().x;
		float dy = position.y - player_position.GetPosition().y;
		float length = sqrtf(dx * dx + dy * dy);
		if (length != 0) {
			dx /= length;
			dy /= length;
		}
		position.x -= dx * static_cast<float>(dt) * MOVING_SPEED;
		position.y -= dy * static_cast<float>(dt) * MOVING_SPEED;
		hitbox.x = position.x;
		hitbox.y = position.y;

		//std::cout << position.x << ',' << position.y<<'\n';
	}
}

void Saw::Draw() {
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode, rotation);
	//for debuging
	if (Engine::Application::DebugMode == true)
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}
