#pragma once
#include "Trouble.h"
#include "Player.h"
#include <raylib.h>

class UI {
public:
	void Draw(Game::Player& player);
	void Update(Game::Player& player);
private:
	Vector2 troublePosition = { static_cast<float>(GetScreenWidth() - 200), 50};
	const char* troubleString;
	int lastTroubleBullet = -1;
};