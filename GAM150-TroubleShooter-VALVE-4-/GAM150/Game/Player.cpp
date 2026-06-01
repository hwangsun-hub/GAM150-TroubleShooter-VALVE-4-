#include "Player.h"
#include "Spike.h"
#include "Box.h"
#include "../Engine/Application.h"
/*#include "GameMode.h"*/
Game::Player::Player()  {

}
void Game::Player::Load(Vector2 start_position) {
	texture = Engine::Application::Gettextures()[static_cast<int>(ObjectID::ID::PLAYER)];
	SetTextureFilter(texture, TEXTURE_FILTER_POINT);
	position = start_position;

	hitbox = Rectangle{ position.x, 
						position.y,
						static_cast<float>(texture.width/2),
						static_cast<float>(texture.height/2) };
	IsAlive = true;
	IsJump = false;
	IsLookingRight = true;
	IsTroubleShoot = false;
	velocity = { 0,0 };
	trouble_bullet = 0;
	arrivedDoor = nullptr;
	IsCollisionWithGlitchedDoor = false;
	IsReadyToNextLevel = false;
}

void Game::Player::HandleCollision(Engine::GameObject* obj, double dt) {
	switch (obj->GetObjectID()) {
	case ObjectID::ID::NUMBER_BLOCK: [[fallthrough]];
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

		bool isUpsideDown = static_cast<Spike*>(obj)->IsUpsideDown();
		if (!isUpsideDown && velocity.y < 0) {  
			break;
		}
		if (isUpsideDown && velocity.y > 0) {   
			break;
		}

		if (obj->GetIsGlitchMode() == true) {
			velocity.y = 0;
			velocity.y += isUpsideDown ?  ( - JUMP_SPEED )  : JUMP_SPEED * 2;
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
	case ObjectID::ID::SAW: {
		if (!CheckCollisionRecs(hitbox, obj->GetHitbox())) {
			break;
		}
		IsAlive = false;
		break;
	}
	case ObjectID::ID::SELECTBOX: {
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
	case ObjectID::ID::DOOR: {
		Door* door = static_cast<Door*>(obj);

		if (arrivedDoor && !CheckCollisionRecs(hitbox, arrivedDoor->GetHitbox())) {
			arrivedDoor = nullptr;
		}
		if (door == arrivedDoor) break;
		if (!CheckCollisionRecs(hitbox, obj->GetHitbox())) {
			break;
		}


		double offsetX = position.x - door->GetPosition().x;
		double offsetY = position.y - door->GetPosition().y;
		if (obj->GetIsGlitchMode() == false) {


			arrivedDoor = door->GetAnotherDoor();
			position.x = arrivedDoor->GetPosition().x + offsetX;
			position.y = arrivedDoor->GetPosition().y + offsetY;

			hitbox.x = position.x;
			hitbox.y = position.y;


			
		
		}
		else {

			Door* exitDoor = door->GetAnotherDoor();
			player2Pos.x = exitDoor->GetPosition().x + offsetX;
			player2Pos.y = exitDoor->GetPosition().y + offsetY;
			door->GetAnotherDoor()->Unload(true);
			door->Unload(true);
			IsCollisionWithGlitchedDoor = true;

		}

		break;
	}
	}

}
void Game::Player::CheckOutOfScreen(void)
{
	if ( position.y > screen_height)
	{
		IsAlive = false;
	}
}

void Game::Player::CorrectCollision(Engine::GameObject* obj, double dt, std::vector<Engine::GameObject*>& objects) {
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
	case ObjectID::ID::NUMBER_BLOCK: [[fallthrough]];
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
	

	case ObjectID::ID::BOX:
	{
		if (!CheckCollisionRecs(hitbox, obj->GetHitbox())) {
			break;
		}
		Box* box = static_cast<Box*>(obj);
		Rectangle overlap = GetCollisionRec(hitbox, obj->GetHitbox());
		Rectangle boxHitbox = obj->GetHitbox();
		if (overlap.width < overlap.height) {
			float playerCenterX = position.x + hitbox.width * 0.5f;
			float boxCenterX = boxHitbox.x + boxHitbox.width * 0.5f;
			if (playerCenterX < boxCenterX) {
				position.x -= overlap.width;
				if (IsKeyDown(KEY_RIGHT)) box->Push(1.0f, objects);
			}
			else {
				position.x += overlap.width;
				if (IsKeyDown(KEY_LEFT)) box->Push(-1.0f, objects);
			}
		}
		else {
			float playerCenterY = position.y + hitbox.height * 0.5f;
			float boxCenterY = boxHitbox.y + boxHitbox.height * 0.5f;
			if (playerCenterY < boxCenterY) {
				position.y = boxHitbox.y - hitbox.height;
				if (velocity.y > 0) {
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

	default:
		break;
	}
	hitbox.x = position.x;
	hitbox.y = position.y;
}

void Game::Player::Update(double dt) {

	//move
	if (IsKeyDown(KeyboardKey::KEY_LEFT) == true) {
		position.x -= MOVE_SPEED * static_cast<float>(dt); //direct feedback
		IsLookingRight = false;
	}
	if (IsKeyDown(KeyboardKey::KEY_RIGHT) == true) {
		position.x += MOVE_SPEED * static_cast<float>(dt); //direct feedback
		IsLookingRight = true;
	}
	//jump
	if (IsKeyPressed(KeyboardKey::KEY_SPACE) == true) {
		if (IsOnGround == true &&
			CanJump == true
			) {
			Engine::Application::GetAudioManager().SoundPlay(SoundID::ID::JUMP);
			velocity.y += JUMP_SPEED;
			IsJump = true;
			IsOnGround = false;
		}

	}
	//can adjust jump
	if (IsKeyReleased(KeyboardKey::KEY_SPACE) == true &&
		IsJump == true
		) {
		if (velocity.y < 0) {
			velocity.y = 0;
		}
		IsJump = false;
	}
	//shoot trouble
	if (IsKeyPressed(KeyboardKey::KEY_Z)) {
		if (trouble_bullet) {
			IsTroubleShoot = true;
			trouble_bullet--;
		}
	}


	CheckOutOfScreen();

	//reset
	if (IsKeyPressed(KeyboardKey::KEY_R) == true) {
		IsAlive = false;
	 }
	
	//update

	velocity.y += GRAVITY * static_cast<float>(dt);
	
	position += velocity * static_cast<float>(dt);

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



bool Game::Player::CheckTroubleShoot()
{
	if (IsTroubleShoot == true) {
		IsTroubleShoot = false;
		Engine::Application::GetAudioManager().SoundPlay(SoundID::ID::SHOOT);
		return true;
	}
	return false;
}

bool Game::Player::GetIsLookingRight() const
{
	return IsLookingRight;
}

void Game::Player::SetTroubleBullet(int max)
{
	trouble_bullet = max;
}

Vector2 Game::Player::Getplayer2Pos()
{
	return player2Pos;
}

