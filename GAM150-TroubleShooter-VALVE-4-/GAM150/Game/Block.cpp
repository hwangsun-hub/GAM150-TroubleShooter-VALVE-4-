#include "Block.h"
#include <iostream>

Block::Block(Vector2 pos, Rectangle texture_source, bool isglitchmoded) :
	position(pos),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
	id(ObjectID::ID::BLOCK)
{}
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
	texture = LoadTexture("Assets/gam150-1.png");
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Block::Update(double dt) {

}

void Block::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
	//for debuging
	if (Engine::Application::DebugMode == true)
	DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}
