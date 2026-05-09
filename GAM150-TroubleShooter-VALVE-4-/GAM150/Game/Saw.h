#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"
#include "Player.h"
class Saw : public Engine::GameObject
{
public:
	Saw(Vector2 start_pos, int tileid, bool isglitchmoded, int size, Vector2 direction,Game::Player& player);
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool GetIsGlitchMode() override;
	bool CheckCollision(Rectangle hibox) override;

private:
	Vector2  start_position;
	Vector2 position;
	Vector2 end_position;
	bool isCollision;
	Rectangle hitbox;
	ObjectID::ID id;
	int tile_id;
	float rotation;
	static constexpr int SIZE = 64;
	static constexpr int MOVING_SPEED = 50;
	static constexpr int ROTATE_SPEED = 200;
	int size;
	Vector2 direction;
	Game::Player& player_position;
	bool going_to_end;
};

