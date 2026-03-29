#include "Player.h"
void Game::player::Load() {
	texture = LoadTexture("Assets/gam150-player.png");
	hitbox = Rectangle{ position.x, 
						position.y,
						static_cast<float>(texture.width),
						static_cast<float>(texture.height) };
}

void Game::player::Update(double dt) {
	//move
	if (IsKeyDown(KeyboardKey::KEY_LEFT)) {
		position.x -= SPEED * dt;

	}
	if (IsKeyDown(KeyboardKey::KEY_RIGHT)) {
		position.x += SPEED * dt;

	}
	hitbox.x = position.x;
	hitbox.y = position.y;
}
void Game::player::Draw() {
	DrawTexture(texture, position.x, position.y, WHITE);
}
Vector2 Game::player::GetPosition() {
	return position;
}
Rectangle Game::player::GetHitbox() {
	return hitbox;
}