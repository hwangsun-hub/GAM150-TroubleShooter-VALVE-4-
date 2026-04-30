#include "GameObject.h"
void Engine::GameObject::TroubleCollision() {
	if (isGlitchMode == false) {
		isGlitchMode = true;

	}
	else {
		isDead = true;
	}
}
void Engine::GameObject::SetDead(bool isdead) {
	isDead = isdead;
}

bool Engine::GameObject::GetDead() const {
	return isDead;
}

void  Engine::GameObject::SetActive(bool isactive) {
	isActive = isactive;
}
bool  Engine::GameObject::GetActive() const {
	return isActive;
}