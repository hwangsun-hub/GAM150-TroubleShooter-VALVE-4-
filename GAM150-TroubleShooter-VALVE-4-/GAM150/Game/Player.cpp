#include "Player.h"
#include "../Engine/Application.h"
#include <iostream>

Game::Player::Player()  {

}
void Game::Player::Load() {
	texture = Engine::Application::GetAssets()[2];
	SetTextureFilter(texture, TEXTURE_FILTER_POINT);
	hitbox = Rectangle{ position.x, 
						position.y,
						static_cast<float>(texture.width/2),
						static_cast<float>(texture.height/2) };
	IsAlive = true;
	position = { 80,320 };
	velocity = { 0,0 };
}

void Game::Player::HandleCollision(Engine::GameObject* obj, double dt) {
	switch (obj->GetObjectID()) {
	case ObjectID::ID::BLOCK: {
		if (obj->GetIsGlitchMode() == true &&
			CheckCollisionRecs(hitbox, obj->GetHitbox())
			) {
			CanJump = false;
		}
		break;
	}
	case ObjectID::ID::SPIKE:
	{
		if (!CheckCollisionRecs(hitbox, obj->GetHitbox())) {
			break;
		}

		if (obj->GetIsGlitchMode() == true) {
			velocity.y = 0;
			velocity.y += JUMP_SPEED * 2;
			obj->Unload(true);
		}

		else {
			IsAlive = false;
		}

		break;
	}
	case ObjectID::ID::FLAG: {
		if (!CheckCollisionRecs(hitbox, obj->GetHitbox())) {
			break;
		}
		if (obj->GetIsGlitchMode() == false) {
			IsReadyToNextLevel = true;
		}
		else {
			IsAlive = false;
		}

		break;
	}

	}
}


void Game::Player::CorrectCollision(Engine::GameObject* obj, double dt) {
	switch (obj->GetObjectID())
	{
	case ObjectID::ID::PLATFORM:
	{
		if (velocity.y < 0) break;

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
				if (velocity.y > 0)
				{
					velocity.y = 0;
					IsOnGround = true;
				}

			}
			else {
				position.y += overlap.height;
				velocity.y = 0.0f;

			}
		}
		break;
	}
	case ObjectID::ID::BLOCK:
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
		else if (overlap.width > overlap.height + 5.0f ) {
			float playerCenterY = position.y + hitbox.height * 0.5f;
			float floorCenterY = obj->GetHitbox().y + objHitbox.height * 0.5f;

			if (playerCenterY < floorCenterY) {
				position.y = objHitbox.y - hitbox.height;
				if (velocity.y > 0)
				{
					velocity.y = 0;
					IsOnGround = true;
				}

			}
			else {
				position.y += overlap.height;
				velocity.y = 0.0f;

			}
		}
		else if ((int)overlap.width - (int)overlap.height < 1) {
			float playerCenterX = position.x + hitbox.width * 0.5f;
			float floorCenterX = objHitbox.x + objHitbox.width * 0.5f;
			if (playerCenterX < floorCenterX)
				position.x -= overlap.width;
			else
				position.x += overlap.width;
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
	if (IsKeyPressed(KeyboardKey::KEY_R) == true) {
		IsAlive = false;
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
		Rectangle {position.x, position.y, static_cast<float>(texture.width/2), static_cast<float>(texture.height/2) },
		Vector2 {0, 0},
		0.0f,
		WHITE
	);
	//for debugging
	if (Engine::Application::DebugMode == true)
	DrawRectangleLinesEx(hitbox, 5, RED);

					
}

void Game::Player::Unload() {

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
bool Game::Player::GetIsAlive() const{
	return IsAlive;
}

void Game::Player::SetCanJump(bool CanJump) {
	this->CanJump = CanJump;
}

void Game::Player::SetIsOnGround(bool IsOnGround) {
	this->IsOnGround = IsOnGround;
}