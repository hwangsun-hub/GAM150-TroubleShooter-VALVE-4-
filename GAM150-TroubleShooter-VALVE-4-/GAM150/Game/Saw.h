#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"
#include "Player.h"
class Saw : public Engine::GameObject
{
public:
	Saw(Vector2 pos, int tileid, bool isglitchmoded, Game::Player& player);
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
	bool isGlitchMode;
	bool isCollision;
	Rectangle hitbox;
	ObjectID::ID id;
	int tile_id;
	float rotation;
	static constexpr int SIZE = 64;
	static constexpr int SPEED = 50;

	Game::Player& player_position;
};

