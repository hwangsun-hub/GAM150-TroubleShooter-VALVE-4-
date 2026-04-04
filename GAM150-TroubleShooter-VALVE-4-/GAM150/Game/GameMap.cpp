#include "GameMap.h"

Game::GameMap::GameMap()
{


}

Game::GameMap::~GameMap() {
	for (GameObject* obj : objects)
		delete obj;
}

void Game::GameMap::LoadMap(MapName mapname) {
	maps.resize(static_cast<int>(MapName::COUNT));
	switch (mapname)
	{
	case MapName::STAGE1_LEVEL1:
		break;
	case MapName::STAGE1_LEVEL2:
		break;
	case MapName::STAGE1_LEVEL3:
		break;
	case MapName::STAGE2_LEVEL1:
		break;
	case MapName::STAGE2_LEVEL2:
		break;
	case MapName::STAGE2_LEVEL3:
		break;
	case MapName::STAGE3_LEVEL1:
		maps[static_cast<int>(MapName::STAGE3_LEVEL1)] =
		{
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 1,60, 60, -1,  -1, -1, -1, -1, -1 },
		{ -1, -1, -1,  1, -1, -1, -1, 50, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{  0,  1,  3,  3,  2,  40,  26,  2,  1,  1,  1,  3,  3,  1,  3,  2,  1,  1,  3,  4 },
		{ 20, 21, 21, 23, 21, 22, 23, 22, 23, 22, 23, 23, 22, 22, 23, 22, 23, 23, 23, 24 }
		};
		break;
	case MapName::STAGE3_LEVEL2:
		break;
	case MapName::STAGE3_LEVEL3:
		break;
	case MapName::STAGE4_LEVEL1:
		break;
	case MapName::STAGE4_LEVEL2:
		break;
	case MapName::STAGE4_LEVEL3:
		break;
	case MapName::STAGE5_LEVEL1:
		break;
	case MapName::STAGE5_LEVEL2:
		break;
	case MapName::STAGE5_LEVEL3:
		break;
	default:
		break;
	}
	

}

void Game::GameMap::Load() {
	LoadMap(currentMapName);
	for (int y = 0; y < maps[static_cast<int>(currentMapName)].size(); y++) {
		for (int x = 0; x < maps[static_cast<int>(currentMapName)][y].size(); x++) {
			if (maps[static_cast<int>(currentMapName)][y][x] >= 0 && //Block
				maps[static_cast<int>(currentMapName)][y][x] <= 25) {
				int tileNum = 5;
				objects.push_back(
					new Block(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{ static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] % tileNum) * TILE_SIZE,
									static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] / tileNum) * TILE_SIZE,
									TILE_SIZE,
									TILE_SIZE },
						false
					));
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] >= 26 && //Glitched Block
				maps[static_cast<int>(currentMapName)][y][x] <= 49
				) {
				int tileNum = 5;
				objects.push_back(
					new Block(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{ static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] % tileNum) * TILE_SIZE,
									static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] / tileNum) * TILE_SIZE,
									TILE_SIZE,
									TILE_SIZE },
						true
					));
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 50 //Spike
				) {
				objects.push_back(
					new Spike(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{  0,
									0,
									TILE_SIZE,
									TILE_SIZE }, 
						true)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 60 //Platform
				) {
				objects.push_back(
					new Platform(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{ 0,
									0,
									TILE_SIZE,
									TILE_SIZE },
						true)
				);
			}
		
		}
	}
	for (GameObject* obj : objects) {
		obj->Load();
	}
}

void Game::GameMap::Update(Game::Player& player, double dt) {
	player.SetIsOnGround(false);
	player.SetCanJump(true);
	for (GameObject* obj : objects) {
		player.HandleCollision(obj, dt);
	}
	for (GameObject* obj : objects) {
		player.CorrectCollision(obj, dt);

	}
}


void Game::GameMap::draw() {
	for (GameObject* obj : objects) {
		obj->Draw();
	}
}