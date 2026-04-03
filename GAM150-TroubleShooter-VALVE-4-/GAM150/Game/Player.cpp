#include "Player.h"
#include "../Engine/Application.h"
#include <iostream>
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

void Game::Player::HandleCollision(GameObject* obj, double dt) {
	switch (obj->GetObjectID()) {
	case ObjectID::ID::PLATFORM: {
		if (obj->GetIsGlitchMode() == true &&
			CheckCollisionRecs(hitbox, obj->GetHitbox())
			) {
			CanJump = false;
		}
		break;
	}

	}
}

void Game::Player::CorrectCollision(GameObject* obj, double dt) {
	switch (obj->GetObjectID())
	{
	case ObjectID::ID::PLATFORM:
	{
		if (!CheckCollisionRecs(hitbox, obj->GetHitbox())) {
			break;
		}


		Rectangle overlap = GetCollisionRec(hitbox, obj->GetHitbox());
		Rectangle objHitbox = obj->GetHitbox();
		if (overlap.width < overlap.height) {
			float playerCenterX = position.x + hitbox.width * 0.5f;
			float floorCenterX = objHitbox.x + objHitbox.width * 0.5f;

			if (playerCenterX < floorCenterX) {
				position.x -= overlap.width;
			}
			else {
				position.x += overlap.width;
			}
		}
		else {
			float playerCenterY = position.y + hitbox.height * 0.5f;
			float floorCenterY = obj->GetHitbox().y + objHitbox.height * 0.5f;

			if (playerCenterY < floorCenterY) {
				position.y = objHitbox.y - hitbox.height;
				velocity.y = 0;
				IsOnGround = true;

				
			}
			else {
				position.y += overlap.height;
				velocity.y = 0.0f;

			}
		}
		break;

	}
	default:
		break;
	}
	hitbox.x = position.x;
	hitbox.y = position.y;
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
			CanJump == true
			) {
			velocity.y += JUMP_SPEED;
			IsOnGround = false;
		}

	}


	//update

	velocity.y += GRAVITY * dt;
	
	position += velocity * dt;

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
	//DrawRectangleLinesEx(hitbox, 5, RED);

					
}
Vector2 Game::Player::GetPosition() const {
	return position;
}
Vector2 Game::Player::GetVelocity() const {
	return velocity;
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