#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"

class Door : public Engine::GameObject {
public:
	Door(Vector2 pos, int tileid, bool isglitchmoded);
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool GetIsGlitchMode() override;
	bool CheckCollision(Rectangle hibox) override;
	void SetAnotherDoor(Door* anotherDoor);
	Door* GetAnotherDoor();
	bool isActive=false;
	bool wasOverlapping = false;

private:
	Vector2  position;
	Rectangle hitbox;
	ObjectID::ID id;
	int tile_id;
	bool isglitchmoded;
	Door* anotherDoor;

};