#include "Floor.h"

Floor::Floor() :
	position({ 0,0 }),
	isGlitchMode(false),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::FLOOR)
{}
Vector2  Floor::GetPosition() {
	return position;
}
Rectangle  Floor::GetHitbox() {
	return hitbox;
}
ObjectID::ID Floor::GetObjectID() {
	return id;
}

bool  Floor::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Floor::Load() {
	texture = LoadTexture("Assets/gam150-1.png");
	hitbox.width = texture.width;
	hitbox.height = texture.height;
}
void  Floor::Update(double dt) {
	
}

void Floor::Draw() {
	DrawTexture(texture, position.x, position.y, WHITE);
}
