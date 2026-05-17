#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"

class Block : public Engine::GameObject
{
public:
	Block(Vector2 pos, int tileid, bool isglitchmoded);
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool GetIsGlitchMode() override;
	bool CheckCollision(Rectangle hibox) override;

private:
	Vector2  position;
	bool isCollision;
	Rectangle hitbox;
	ObjectID::ID id;
	int tile_id;

	static constexpr int SIZE = 32;
};

