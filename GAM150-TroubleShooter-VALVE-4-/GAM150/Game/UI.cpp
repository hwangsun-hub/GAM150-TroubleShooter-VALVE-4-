#include "UI.h"
#include "../Engine/Application.h"
void UI::Draw(Game::Player& player)
{
	Engine::Application::GetTextureManager().DrawTexure(ObjectID::ID::TROUBLE, troublePosition);
	DrawText(troubleString, troublePosition.x + 50, troublePosition.y, 40, WHITE);
		
}

void UI::Update(Game::Player& player)
{
	int current = player.GetCurrentTroubleBullet();

	if (current != lastTroubleBullet)
	{
		troubleString = TextFormat("x %d", player.GetCurrentTroubleBullet());
		lastTroubleBullet = current;
	}
}
