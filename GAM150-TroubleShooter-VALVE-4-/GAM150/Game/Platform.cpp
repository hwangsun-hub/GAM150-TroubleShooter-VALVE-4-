#include "Platform.h"
#include <iostream>

Platform::Platform(Vector2 pos, Rectangle texture_source, bool isglitchmoded) :
	position(pos),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
	id(ObjectID::ID::PLATFORM)
{}
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
	texture = LoadTexture("Assets/gam150-1.png");
	hitbox.width = 64;
	hitbox.height = 64;
}
void  Platform::Update(double dt) {

}

void Platform::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
	//for debuging
	DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}
