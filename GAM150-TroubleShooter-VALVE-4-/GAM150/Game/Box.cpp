#include "Box.h"
#include "../Engine/Application.h"

Box::Box(Vector2 pos, bool glitch) :
	position(pos),
	hitbox({ position.x, position.y, 0, 0 }),
	id(ObjectID::ID::BOX),
	isGlitchMode(glitch)
{
}

void Box::Load() {
	if (isGlitchMode)
		texture = Engine::Application::Gettextures()[static_cast<int>(ObjectID::ID::GLITCHBOX)];
	else
		texture = Engine::Application::Gettextures()[static_cast<int>(ObjectID::ID::BOX)];
	hitbox.width = static_cast<float>(SIZE);
	hitbox.height = static_cast<float>(SIZE);
}

void Box::Update(double dt) {
	velocity.y += GRAVITY * dt;
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;

	velocity.x = 0;

	hitbox.x = position.x;
	hitbox.y = position.y;
}

void Box::Draw() {
	DrawTexturePro(
		texture,
		Rectangle{ 0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height) },
		hitbox,
		Vector2{ 0, 0 },
		0.0f,
		WHITE
	);
	if (Engine::Application::DebugMode == true)
		DrawRectangleLinesEx(hitbox, 5, RED);
}

void Box::Push(float direction, std::vector<Engine::GameObject*>& objects) {
	float dir;
	if (isGlitchMode) {
		dir = -direction;
	}
	else {
		dir = direction;
	}
	if (!CanPush(dir, objects)) return;
	velocity.x = dir * PUSH_SPEED;
}

void Box::SetGround() {
	velocity.y = 0;
}

void Box::SetPositionFromHitbox(Rectangle newHitbox) {
	position.x = newHitbox.x;
	position.y = newHitbox.y;
	hitbox = newHitbox;
}

Vector2 Box::GetPosition() {
	return position;
}

Rectangle Box::GetHitbox() {
	return hitbox;
}

ObjectID::ID Box::GetObjectID() {
	return id;
}

bool Box::GetIsGlitchMode() {
	return isGlitchMode;
}

bool Box::CheckCollision(Rectangle hibox) {
	return CheckCollisionRecs(hibox, this->hitbox);
}

void Box::TroubleCollision() {
	if (!isGlitchMode) {
		isGlitchMode = true;
		texture = Engine::Application::Gettextures()[static_cast<int>(ObjectID::ID::GLITCHBOX)];
	}
	else {
		Engine::Application::Gettextures();
		isUnload = true;
	}
}

bool Box::CanPush(float direction, std::vector<Engine::GameObject*>& objects, const Box* caller) {
	Rectangle checkRect = hitbox;
	checkRect.x += direction * 1.0f;
	for (Engine::GameObject* other : objects) {
		if (other == this || other == caller) continue;
		if (other->GetObjectID() != ObjectID::ID::NUMBER_BLOCK &&
			other->GetObjectID() != ObjectID::ID::BLOCK &&
			other->GetObjectID() != ObjectID::ID::PLATFORM &&
			other->GetObjectID() != ObjectID::ID::BOX) continue;
		if (CheckCollisionRecs(checkRect, other->GetHitbox())) {
			if (other->GetObjectID() == ObjectID::ID::BOX) {
				Box* nextBox = static_cast<Box*>(other);
				if (!nextBox->CanPush(direction, objects, this)) return false;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

void Box::ResolveCollisions(std::vector<Engine::GameObject*>& objects) {
	for (Engine::GameObject* obj : objects) {
	if (obj->GetObjectID() != ObjectID::ID::BOX) continue;
	Box* box = static_cast<Box*>(obj);
	Rectangle boxHitbox = box->GetHitbox();

	for (Engine::GameObject* other : objects) {
		if (other == obj) continue;
		if (other->GetObjectID() != ObjectID::ID::NUMBER_BLOCK &&
			other->GetObjectID() != ObjectID::ID::BLOCK &&
			other->GetObjectID() != ObjectID::ID::PLATFORM &&
			other->GetObjectID() != ObjectID::ID::BOX) continue;
			if (!CheckCollisionRecs(boxHitbox, other->GetHitbox())) continue;

			Rectangle overlap = GetCollisionRec(boxHitbox, other->GetHitbox());
			Rectangle otherHitbox = other->GetHitbox();

			if (overlap.width < overlap.height) {
				float boxCenterX = boxHitbox.x + boxHitbox.width * 0.5f;
				float otherCenterX = otherHitbox.x + otherHitbox.width * 0.5f;
				if (boxCenterX < otherCenterX) {
					box->Push(0, objects);
					boxHitbox.x -= overlap.width;
				}
				else {
					box->Push(0, objects);
					boxHitbox.x += overlap.width;
				}
			}
			else {
				float boxCenterY = boxHitbox.y + boxHitbox.height * 0.5f;
				float otherCenterY = otherHitbox.y + otherHitbox.height * 0.5f;
				if (boxCenterY < otherCenterY) {
					boxHitbox.y = otherHitbox.y - boxHitbox.height;
					box->SetGround();
				}
				else {
					boxHitbox.y += overlap.height;
					box->SetGround();
				}
			}
		}
		box->SetPositionFromHitbox(boxHitbox);
	}
}
