#include "Spike.h"

Spike::Spike(Vector2 pos, Rectangle texture_source, bool isglitchmoded, bool isupsidedown) :
	position(pos),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x+10, position.y + 32,0,0 }),
	textureSourceRectangle(texture_source),
	id(ObjectID::ID::SPIKE),
	isUpsidedown(isupsidedown)
{
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

bool  Spike::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Spike::Load() {
	texture = Engine::Application::GetAssets()[0];
	hitbox.width = 44;
	hitbox.height = 32;
}
void  Spike::Update(double dt) {

}

void Spike::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
	//for debuging
	if (Engine::Application::DebugMode == true)
	DrawRectangleLinesEx(hitbox, 5, RED);
}