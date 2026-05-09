#include "Saw.h"
#include <iostream>

Saw::Saw(Vector2 start_pos, int tileid, bool isglitchmoded, int size, Vector2 direction, Game::Player& player) :
	start_position(start_pos),
	position(start_pos),
	tile_id(tileid),
	isCollision(false),
	hitbox({ start_position.x, start_position.y,0,0 }),
	id(ObjectID::ID::SAW),
	rotation(0),
	player_position(player),
	size(size),
	direction(direction),
	going_to_end(true)
{
	isGlitchMode = isglitchmoded;
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
	
	going_to_end = true;
	end_position = { position.x + SIZE * direction.x*size,position.y + SIZE * direction.y*size };
}
void  Saw::Update(double dt) {
	rotation += static_cast<float>(dt) * ROTATE_SPEED;
	rotation += dt * ROTATE_SPEED;

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


	}
	else {
		Vector2 target = going_to_end ? end_position : start_position;

		float dx = target.x - position.x;
		float dy = target.y - position.y;
		float length = sqrtf(dx * dx + dy * dy);

		if (length < 2.0f) {
			going_to_end = !going_to_end;
		}
		else {
			dx /= length;
			dy /= length;
			position.x += dx * dt * MOVING_SPEED;
			position.y += dy * dt * MOVING_SPEED;
		}

	}
	hitbox.x = position.x;
	hitbox.y = position.y;
}

void Saw::Draw() {
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode, rotation);
	//for debuging
	if (Engine::Application::DebugMode == true)
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}
