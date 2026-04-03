#include "Spike.h"

Spike::Spike(Vector2 pos, Rectangle texture_source) :
	position(pos),
	isGlitchMode(false),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
	id(ObjectID::ID::SPIKE)
{
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

bool  Spike::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Spike::Load() {
	texture = LoadTexture("Assets/gam150-1.png");
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Spike::Update(double dt) {

}

void Spike::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
	//for debuging
	//DrawRectangleLinesEx(hitbox, 5, RED);
}