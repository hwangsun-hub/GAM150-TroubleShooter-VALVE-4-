#include "../Engine/Application.h"
#include "GameMode.h"
Game::GameMode::GameMode() {
	
}
#include <iostream>

std::string Game::GameMode::GetCurentMapNameForDialogue() const
{
	return std::string("Assets/Dialogue/") + MapNames[static_cast<int>(currentMapName)] + std::string(".dialogue");
	std::cout << MapNames[static_cast<int>(currentMapName)];
}
std::string Game::GameMode::GetCurrentMapName() const
{
	return MapNames[static_cast<int>(currentMapName)];
}
void Game::GameMode::ChangeMap(MapName newMap)
{
	currentMapName = newMap;
	ui.WhenMapChanged(GetCurrentMapName());
}
void Game::GameMode::Load() {
	currentMapName = MapNameMap[Engine::Application::GetSaveFile().GetCurrentGameMap()];
	gameMap.Load(player, currentMapName);
	player.Load(gameMap.GetStartPosition());
	dialogue.Load(GetCurentMapNameForDialogue().c_str());
	gamestate = gamestate::Dialogue;
	ChangeMap(currentMapName);
}

void Game::GameMode::Update([[maybe_unused]] double dt) {
	switch (gamestate) {
		case gamestate::Dialogue:
			dialogue.Update();
			player.SetTroubleBullet(max_trouble[currentMapName]);

			if (dialogue.IsFinished()) gamestate = gamestate::Playing;
			break;
		case gamestate::Playing:
			player.Update(dt);
			gameMap.Update(player, dialogue, dt);
			if (player.IsReadyToNextLevel || IsKeyPressed(KEY_F10))
			{
			    ChangeMap(static_cast<MapName>(static_cast<int>(currentMapName) + 1));
				gameMap.Unload();
				ClearBackground(Color{ 42, 79, 107, 255 });
				dialogue.Unload();
				player.Unload();

				gameMap.Load(player, currentMapName);
				player.Load(gameMap.GetStartPosition());
				player.SetTroubleBullet(max_trouble[currentMapName]);
				dialogue.Load(GetCurentMapNameForDialogue().c_str());
				player.IsReadyToNextLevel = false;
				gamestate = gamestate::Dialogue;
			}
			if (player.GetIsAlive() == false) {
				gameMap.Unload();
				
				dialogue.Unload();
				
				player.Unload();
				gameMap.Load(player, currentMapName);
				dialogue.Load(GetCurentMapNameForDialogue().c_str());
				player.Load(gameMap.GetStartPosition());
				player.SetTroubleBullet(max_trouble[currentMapName]);

			}
			break;

	}
	ui.Update(player);
	if (IsKeyPressed(KEY_ONE)) {
		Engine::Application::GetGameStateManager().SetNextGameState(0);  // mainmenu
	}
}

void Game::GameMode::Unload() {
	gameMap.Unload(); 
	player.Unload();
	dialogue.Unload();
}

void Game::GameMode::Draw() {
	Engine::Application::GetWindow().Clear(0x2A4F6BFF);
	gameMap.draw();
	player.Draw();
	if (gamestate == gamestate::Dialogue) {
		dialogue.Draw();
	}
	ui.Draw(player);
}