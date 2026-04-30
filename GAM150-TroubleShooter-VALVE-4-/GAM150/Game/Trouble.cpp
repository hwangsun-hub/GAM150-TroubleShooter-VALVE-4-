#include "Trouble.h"

Trouble::Trouble(Vector2 pos, Rectangle texture_source) :
	position(pos),
	isCollision(false),
	hitbox({ position.x, position.y,0,0 }),
	textureSourceRectangle(texture_source),
	id(ObjectID::ID::TROUBLE)
{
}

void Trouble::Load()
{
}

void Trouble::Update(Game::GameObject* objects, double dt)
{
	if (objects->CheckCollision(this->GetHitbox()) == true) {
		objects->TroubleCollision();
		isDead = true;
	}

	if (isFlipped == false)
		position.x += SPEED * dt;
	else
		position.x -= SPEED * dt;

}

void Trouble::Draw()
{
}

Vector2 Trouble::GetPosition()
{
	return position;
}

Rectangle Trouble::GetHitbox()
{
	return hitbox;
}

ObjectID::ID Trouble::GetObjectID()
{
	return id;
}

bool Trouble::GetDead() const
{
	return isDead;
}
