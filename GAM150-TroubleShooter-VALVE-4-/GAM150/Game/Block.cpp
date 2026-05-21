#include "Block.h"

Block::Block(Vector2 pos, int tileid, bool isglitchmoded) :
	position(pos),
	tile_id(tileid),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::BLOCK)
{
	isGlitchMode = isglitchmoded;
}
Vector2  Block::GetPosition() {
	return position;
}
Rectangle  Block::GetHitbox() {
	return hitbox;
}
ObjectID::ID Block::GetObjectID() {
	return id;
}
bool Block::GetIsGlitchMode() {
	return isGlitchMode;
}

bool  Block::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Block::Load() {
	hitbox.width = SIZE;
	hitbox.height = SIZE;
}
void  Block::Update(double dt) {

}

void Block::Draw() {
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode);
	//for debuging
	if (Engine::Application::DebugMode == true)
	DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}
