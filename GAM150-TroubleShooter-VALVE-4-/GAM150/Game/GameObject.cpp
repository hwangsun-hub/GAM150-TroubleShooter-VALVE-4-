#include "GameObject.h"
void Game::GameObject::ToggleIsGlitchMode() {
	isGlitchMode = !isGlitchMode;
}
void Game::GameObject::SetDead(bool isdead) {
	isDead = isdead;
}

bool Game::GameObject::GetDead() const {
	return isDead;
}

void  Game::GameObject::SetActive(bool isactive) {
	isActive = isactive;
}
bool  Game::GameObject::GetActive() const {
	return isActive;
}