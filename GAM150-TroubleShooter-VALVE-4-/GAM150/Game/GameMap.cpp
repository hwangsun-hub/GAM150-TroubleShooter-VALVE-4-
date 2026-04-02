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
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1,  1, 1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{  0,  1,  3,  3,  2,  1,  1,  2,  1,  1,  1,  3,  3,  1,  3,  2,  1,  1,  3,  4 },
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
			if (maps[static_cast<int>(currentMapName)][y][x] >= 0 && //Platform
				maps[static_cast<int>(currentMapName)][y][x] <= 25) {
				int tileNum = 5;
				objects.push_back(
					new Platform(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{  static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] % tileNum) * TILE_SIZE,
									static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] / tileNum) * TILE_SIZE,
									TILE_SIZE,
									TILE_SIZE }
					));
			}
		
		}
	}
	for (GameObject* obj : objects) {
		obj->Load();
	}
}

void Game::GameMap::Update(Game::Player& player, double dt) {
	bool isFirstTimePlatform = true;
	for (GameObject* obj : objects) {
		switch (obj->GetObjectID())
		{
		case ObjectID::ID::PLATFORM:
			//should update later
			if (obj->CheckCollision(player.GetHitbox()) == true &&
				isFirstTimePlatform == true
				) {
				player.SetIsOnGround(true);
				if (obj->GetIsGlitchMode() == true) {
					player.SetCanJump(false);
				}
				else {
					player.SetCanJump(true);
				}
				isFirstTimePlatform = false;
			}
			break;
		default:
			break;
		}
	}
	if (isFirstTimePlatform == true) {
		player.SetIsOnGround(false);
	}
}

void Game::GameMap::draw() {
	for (GameObject* obj : objects) {
		obj->Draw();
	}
}