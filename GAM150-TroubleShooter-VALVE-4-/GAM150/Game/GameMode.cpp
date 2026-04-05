#include "../Engine/Application.h"
#include "GameMode.h"

Game::GameMode::GameMode() {

}

void Game::GameMode::Load() {
	gameMap.Load();
	player.Load();

}

void Game::GameMode::Update([[maybe_unused]] double dt) {
	player.Update(dt);
	gameMap.Update(player, dt);
}

void Game::GameMode::Unload() {
}

void Game::GameMode::Draw() {
	Engine::Application::GetWindow().Clear(0x2A4F6BFF);
	gameMap.draw();
	player.Draw();
}