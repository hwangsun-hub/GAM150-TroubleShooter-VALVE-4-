#include "Player.h"
#include "../Engine/Application.h"
Game::Player::Player()  {

}
void Game::Player::Load() {
	texture = LoadTexture("Assets/gam150-player.png");
	SetTextureFilter(texture, TEXTURE_FILTER_POINT);
	hitbox = Rectangle{ position.x, 
						position.y,
						static_cast<float>(texture.width),
						static_cast<float>(texture.height) };
}

void Game::Player::Update(double dt) {
	//move
	if (IsKeyDown(KeyboardKey::KEY_LEFT) == true) {
		position.x -= MOVE_SPEED * dt; //direct feedback

	}
	if (IsKeyDown(KeyboardKey::KEY_RIGHT) == true) {
		position.x += MOVE_SPEED * dt; //direct feedback

	}
	//jump
	if (IsKeyPressed(KeyboardKey::KEY_SPACE) == true) {
		if (IsOnGround == true &&
			CanJump == true) {
			velocity.y += JUMP_SPEED;
			IsOnGround = false;
		}

	}

	//update
	if (IsOnGround == true) {
		velocity.y = 0;
	}
	else {
		velocity.y += GRAVITY * dt;
	}
	position += velocity * dt;

	//if collision with wall(floor's left/right side)
	//then position.x -/+= velocity * dt;

	//if collision with ceiling(floor's down side)
	//then position.y += velocity * dt;
	

	//hitbox update
	hitbox.x = position.x;
	hitbox.y = position.y;
}
void Game::Player::Draw() {
	DrawTexturePro(
		texture,
		Rectangle{0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)},
		Rectangle {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height) },
		Vector2 {0, 0},
		0.0f,
		WHITE
	);
	//for debugging
	DrawRectangleLinesEx(hitbox, 5, RED);

					
}
Vector2 Game::Player::GetPosition() const {
	return position;
}
Rectangle Game::Player::GetHitbox() const {
	return hitbox;
}

void Game::Player::SetCanJump(bool CanJump) {
	this->CanJump = CanJump;
}

void Game::Player::SetIsOnGround(bool IsOnGround) {
	this->IsOnGround = IsOnGround;
}