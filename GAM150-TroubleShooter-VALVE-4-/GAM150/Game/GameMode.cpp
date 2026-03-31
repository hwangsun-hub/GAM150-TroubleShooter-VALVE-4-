#include "../Engine/Application.h"
#include "GameMode.h"

Game::GameMode::GameMode() {

}

void Game::GameMode::Load() {
}

void Game::GameMode::Update([[maybe_unused]] double dt) {

}

void Game::GameMode::Unload() {
}

void Game::GameMode::Draw() {
	Engine::Application::GetWindow().Clear(0x0A0A23FF);
}