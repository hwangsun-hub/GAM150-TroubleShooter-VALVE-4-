#include "GameObjectManager.h"

void Engine::GameObjectManager::Add(GameObject* object)
{
	objects.push_back(object);
}

void Engine::GameObjectManager::Unload()
{
	for (GameObject* object : objects) {
		delete object;
	}
	objects.clear();
}

void Engine::GameObjectManager::UpdateAll(double dt)
{
	for (GameObject* object : objects) {
		object->Update(dt);
	}
}

void Engine::GameObjectManager::DrawAll()
{
	for (GameObject* object : objects) {
		object->Draw();
	}
}
