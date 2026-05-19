#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"

class Spike : public Engine::GameObject
{
public:
	Spike(Vector2 pos, int tileid, bool isglitchmoded, bool isupsidedown);
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool GetIsGlitchMode() override;
	bool CheckCollision(Rectangle hibox) override;
	bool IsUpsideDown();


private:
	Vector2  position;
	bool isCollision;
	Rectangle hitbox;
	ObjectID::ID id;
	bool isUpsidedown;
	int tile_id;

};