#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"
#include "MapName.h"

class SelectBox : public Engine::GameObject
{
public:
	SelectBox(Vector2 pos, int tileid, bool isglitchmoded, MapName mapName);
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool GetIsGlitchMode() override;
	bool CheckCollision(Rectangle hibox) override;
	MapName GetMapName();
private:
	MapName mapName;
	Vector2  position;
	Rectangle hitbox;
	ObjectID::ID id;
	int tile_id;

};

