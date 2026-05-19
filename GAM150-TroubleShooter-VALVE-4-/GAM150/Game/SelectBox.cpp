#include "SelectBox.h"

SelectBox::SelectBox(Vector2 pos, int tileid, bool isglitchmoded, MapName mapName) :
	position(pos),
	tile_id(tileid),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	id(ObjectID::ID::SELECTBOX),
	mapName(mapName)
{
	isGlitchMode = isglitchmoded;
}
Vector2  SelectBox::GetPosition() {
	return position;
}
Rectangle  SelectBox::GetHitbox() {
	return hitbox;
}
ObjectID::ID SelectBox::GetObjectID() {
	return id;
}
bool SelectBox::GetIsGlitchMode() {
	return isGlitchMode;
}

bool  SelectBox::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

MapName SelectBox::GetMapName()
{
	return mapName;
}

void SelectBox::Load() {
	hitbox.width = SIZE;
	hitbox.height = SIZE;
}
void  SelectBox::Update(double dt) {

}

void SelectBox::Draw() {
	Engine::Application::GetTextureManager().DrawTexure(id, tile_id, position, isGlitchMode);
	//for debuging
	if (Engine::Application::DebugMode == true)
		DrawRectangleLinesEx(hitbox, 5, isGlitchMode ? RED : BLACK);
}
