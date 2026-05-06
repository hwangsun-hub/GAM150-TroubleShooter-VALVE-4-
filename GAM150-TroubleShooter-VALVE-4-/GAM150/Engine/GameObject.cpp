#include "GameObject.h"
void Engine::GameObject::TroubleCollision() {
	if (isGlitchMode == false) {
		isGlitchMode = true;

	}
	else {
		isUnload = true;
	}
}
void Engine::GameObject::Unload(bool isUnload) {
	this->isUnload = isUnload;
}

bool Engine::GameObject::GetUnload() const {
	return isUnload;
}

void  Engine::GameObject::SetActive(bool isactive) {
	isActive = isactive;
}
bool  Engine::GameObject::GetActive() const {
	return isActive;
}