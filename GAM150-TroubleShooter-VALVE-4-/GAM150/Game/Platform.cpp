#include "Platform.h"
#include <iostream>

Platform::Platform(Vector2 pos, Rectangle texture_source, bool isglitchmoded) :
	position(pos),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
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
	texture = Engine::Application::GetAssets()[1];
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Platform::Update(double dt) {

}

void Platform::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
	//for debuging
	if (Engine::Application::DebugMode == true) {
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? YELLOW : PINK);
	}
}
