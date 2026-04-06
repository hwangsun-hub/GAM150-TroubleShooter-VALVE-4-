#include "GlitchPlate.h"
#include <iostream>

GlitchPlate::GlitchPlate(Vector2 pos, Rectangle texture_source, bool isglitchmoded) :
	position(pos),
	isGlitchMode(isglitchmoded),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
	id(ObjectID::ID::GLITCHPLATE)
{
}
Vector2  GlitchPlate::GetPosition() {
	return position;
}
Rectangle  GlitchPlate::GetHitbox() {
	return hitbox;
}
ObjectID::ID GlitchPlate::GetObjectID() {
	return id;
}
bool GlitchPlate::GetIsGlitchMode() {
	return isGlitchMode;
}

bool  GlitchPlate::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void GlitchPlate::Load() {
	texture = Engine::Application::GetAssets()[0];
	hitbox.width = 64;
	hitbox.height = 32;
}
void  GlitchPlate::Update(double dt) {

}

void GlitchPlate::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
	//for debuging
	if (Engine::Application::DebugMode == true) {
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? YELLOW : PINK);
	}
}
