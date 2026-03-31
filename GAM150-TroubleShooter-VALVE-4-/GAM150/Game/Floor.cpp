#include "Floor.h"

Floor::Floor(Vector2 pos, Rectangle texture_source) :
	position(pos),
	isGlitchMode(false),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
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
void  Floor::Update(Game::Player& player, double dt) {
	if (CheckCollision(player.GetHitbox()) == true) {
		player.SetIsOnGround(true);
		if (isGlitchMode == true) {
			player.SetCanJump(false);
		}
		else {
			player.SetCanJump(true);
		}
	}


}

void Floor::Draw() {
	DrawTexturePro(texture, textureSourceRectangle, { position.x, position.y, SIZE, SIZE }, Vector2Zero(), 0, WHITE);
}
