#include "Trouble.h"
#include "../Engine/Application.h"

Trouble::Trouble(Vector2 position, bool isgoingright) : position(position), isGoingRight(isgoingright), isUnload(false)
{
	hibox = { this->position.x, this->position.y, HITBOX_SIZE, HITBOX_SIZE };
}

void Trouble::Update(Engine::GameObject* obj, double dt)
{
	if (CheckCollisionRecs(obj->GetHitbox(), hibox)) {
		obj->TroubleCollision();
		isUnload = true;
	}
	position.x += isGoingRight ? SPEED * dt : -SPEED * dt;
	hibox.x += isGoingRight ? SPEED * dt : -SPEED * dt;

}

void Trouble::Draw()
{
	Engine::Application::GetTextureManager().DrawTexure(ObjectID::ID::TROUBLE, position);
}

bool Trouble::GetUnload() const
{
	return isUnload;
}
