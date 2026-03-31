#include "GameMap.h"

Game::GameMap::GameMap()
{
	objects.push_back(new Floor);

}

Game::GameMap::~GameMap() {
	for (GameObject* obj : objects)
		delete obj;
}

void Game::GameMap::LoadMap(MapName mapname) {
	for (GameObject* obj : objects) {
		
	}
}