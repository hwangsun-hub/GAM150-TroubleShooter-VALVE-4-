#include "UI.h"
#include "../Engine/Application.h"
#include "GameMode.h"
void UI::Draw(Game::Player& player)
{
	Engine::Application::GetTextureManager().DrawTexure(ObjectID::ID::TROUBLE, troublePosition);
	DrawText(troubleString, troublePosition.x + 50, troublePosition.y, 40, WHITE);
	DrawText(currentMapName.c_str(), currentMapNamePosition.x , currentMapNamePosition.y, currentMapNameFontSize, WHITE);
	
}

void UI::Update(Game::Player& player)
{
	int current = player.GetCurrentTroubleBullet();
	if (current != lastTroubleBullet)
	{
		troubleString = TextFormat("x %d", player.GetCurrentTroubleBullet());
		lastTroubleBullet = current;
	}
	if (currentMapName == "CLEAR") {
		currentMapNameFontSize = 200;
		currentMapNamePosition = { 480,500 };
	}
}

void UI::WhenMapChanged(const std::string& newMapName)
{
	currentMapName = newMapName;
}
