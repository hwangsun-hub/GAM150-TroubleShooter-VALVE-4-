#include "Flag.h"
#include <iostream>

Flag::Flag(Vector2 pos, Rectangle texture_source, bool isglitchmoded) :
	position(pos),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
	id(ObjectID::ID::FLAG)
{
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
	texture = Engine::Application::GetAssets()[1];
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Flag::Update(double dt) {

}

void Flag::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
	//for debuging
	if (Engine::Application::DebugMode == true) {
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? PINK : YELLOW);
	}
}
