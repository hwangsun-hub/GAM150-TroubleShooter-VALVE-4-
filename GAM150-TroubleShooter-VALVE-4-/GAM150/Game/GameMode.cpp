#include "../Engine/Application.h"
#include "GameMode.h"

Game::GameMode::GameMode() {

}
#include <iostream>

std::string Game::GameMode::GetCurentMapName() const
{
	return std::string("Assets/Dialogue/") + MapNames[static_cast<int>(currentMapName)] + std::string(".dialogue");
}
void Game::GameMode::Load() {
	gameMap.Load(player, currentMapName);
	player.Load(gameMap.GetStartPosition());
	dialogue.Load(GetCurentMapName().c_str());
	gamestate = gamestate::Dialogue;
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
				currentMapName = static_cast<MapName>(static_cast<int>(currentMapName) + 1);
				gameMap.Unload();
				ClearBackground(Color{ 42, 79, 107, 255 });
				dialogue.Unload();
				player.Unload();

				gameMap.Load(player, currentMapName);
				player.Load(gameMap.GetStartPosition());
				player.IsCollisionWithGlitchedDoor = false;
				player.SetTroubleBullet(max_trouble[currentMapName]);
				dialogue.Load(GetCurentMapName().c_str());
				player.IsReadyToNextLevel = false;
				gamestate = gamestate::Dialogue;
			}
			if (player.GetIsAlive() == false) {
				gameMap.Unload();
				
				dialogue.Unload();
				
				player.Unload();
				gameMap.Load(player, currentMapName);
				dialogue.Load(GetCurentMapName().c_str());
				player.Load(gameMap.GetStartPosition());
				player.IsCollisionWithGlitchedDoor = false;
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
	gameMap.Unload(); //game map에서 맵이 바뀌는거라 여기 unload는 선택창 갈때말고 실행 안됨
	
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