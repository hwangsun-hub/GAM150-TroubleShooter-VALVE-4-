#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"
class Trouble {
public:
	Trouble(Vector2 position, bool isgoingright);
	void Update(Engine::GameObject* obj, double dt);
	void Draw();
	bool GetUnload() const;
private:
	Vector2 position;
	bool isGoingRight;
	bool isUnload;
	Rectangle hibox;
	static constexpr int SPEED = 10;
	static constexpr int HITBOX_SIZE = 8;
};