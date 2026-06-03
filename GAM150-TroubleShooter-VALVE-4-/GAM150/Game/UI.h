#pragma once
#include "Trouble.h"
#include "Player.h"
#include <raylib.h>
#include <string>
enum class MapName;

class UI {
public:
	void Draw(Game::Player& player);
	void Update(Game::Player& player);
	void WhenMapChanged(const std::string& newMapName);
private:
	Vector2 troublePosition = { static_cast<float>(GetScreenWidth() - 200), 50};
	const char* troubleString;
	int lastTroubleBullet = -1;

	Vector2 currentMapNamePosition = {  50 , 50 };
	int currentMapNameFontSize = 40;
	std::string currentMapName;

};