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
		{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
		{ 10,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,14,-1,-1,-1,-1,-1,19 },
		{10,-1,-1,-1,51,-1,-1,-1,-1,22,-1,-1,-1,14,-1,-1,-1,-1,-1,9},
		{5,-1,-1,-1,14,-1,-1,-1,-1,60,-1,-1,-1,60,-1,-1,-1,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9},
		{5,-1,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19},
		{15,4,-1,-1,-1,-1,-1,0,1,2,3,4,-1,0,1,2,4,-1,0,9},
		{10,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,14,-1,-1,-1,14,-1,-1,-1,14},
		{5,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,24,-1,-1,-1,21,21,-1,-1,9},
		{5,-1,-1,-1,-1,-1,-1,60,-1,-1,-1,60,-1,-1,-1,60,-1,-1,-1,9},
		{5,-1,50,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,0,19},
		{20,23,21,23,22,23,23,21,22,23,23,22,22,22,22,21,22,22,23,24}


		};
		break;
	case MapName::STAGE3_LEVEL2:
		maps[static_cast<int>(MapName::STAGE3_LEVEL2)] =
		{
		{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
		{ 10,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,14,-1,-1,-1,-1,-1,19 },
		{ 10,-1,-1,-1,51,-1,-1,-1,-1,22,-1,-1,-1,14,-1,-1,-1,-1,-1,9 },
		{ 5,-1,-1,-1,14,-1,-1,-1,-1,60,-1,-1,-1,60,-1,-1,-1,-1,-1,19 },
		{ 15,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9 },
		{ 5,-1,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19 },
		{ 15,29,-1,-1,-1,-1,-1,25,1,2,3,4,-1,25,1,2,4,-1,0,9 },
		{ 10,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,14,-1,-1,-1,14,-1,-1,60,14 },
		{ 5,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,24,-1,-1,-1,21,21,-1,-1,9 },
		{ 5,-1,-1,-1,-1,-1,-1,60,-1,-1,-1,60,-1,-1,-1,60,-1,-1,-1,9 },
		{ 5,-1,50,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,0,19 },
		{ 20,23,21,23,46,23,23,21,47,23,23,22,47,22,22,21,22,22,23,24 }


		};
		break;
	case MapName::STAGE3_LEVEL3:
		maps[static_cast<int>(MapName::STAGE3_LEVEL3)] =
		{
		{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
		{10,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,14,-1,-1,60,-1,19},
		{10,-1,-1,-1,51,-1,-1,-1,-1,60,-1,-1,-1,-1,24,-1,-1,-1,-1,9},
		{5,-1,-1,-1,14,-1,-1,-1,50,-1,50,-1,-1,-1,60,-1,50,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,2,-1,2,-1,-1,-1,-1,-1,4,-1,0,9},
		{5,-1,-1,20,22,24,-1,25,1,1,2,29,-1,25,2,2,9,-1,-1,19},
		{15,29,-1,-1,-1,-1,-1,5,60,60,22,60,-1,60,-1,60,19,-1,-1,9},
		{10,-1,-1,-1,-1,-1,-1,60,-1,-1,60,-1,-1,-1,-1,-1,14,-1,0,14},
		{5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,60,9},
		{5,-1,-1,-1,-1,-1,50,-1,-1,55,-1,-1,-1,-1,-1,-1,9,-1,-1,9},
		{5,-1,50,-1,-1,50,1,-1,55,1,-1,50,-1,50,-1,55,-1,-1,55,19},
		{20,23,21,23,27,23,23,21,22,23,23,22,27,22,27,21,22,22,23,24}


		};
		break;
	case MapName::STAGE4_LEVEL1:
		maps[static_cast<int>(MapName::STAGE4_LEVEL1)] =
	{
		{ 0, 1, 2, 1, 1, 3, 2, 2, 2, 3, 1, 3, 3, 2, 1, 2, 1, 1, 1, 4 },
			{10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19 },
			{10, -1, -1, -1, 0, 1, 2, 3, 4, -1, -1, 0, 1, 2, 3, 4, -1, -1, -1, 9 },
			{5, -1, -1, -1, 5, 6, 7, 8, 9, -1, -1, 5, 6, 7, 8, 9, -1, -1, -1, 19 },
			{15, -1, -1, -1, 10, 11, 12, 13, 14, -1, -1, 10, 11, 12, 13, 14, -1, -1, -1, 9 },
			{5, -1, -1, -1, 15, 16, 17, 18, 19, -1, -1, 15, 16, 17, 18, 19, -1, -1, -1, 19 },
			{15, -1, -1, -1, 20, 21, 22, 23, 24, -1, -1, 20, 21, 22, 23, 24, -1, -1, -1, 9},
			{10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14 },
			{5, -1, -1, -1, -1, -1, -1, 25, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 9 },
			{5, -1, -1, -1, -1, -1, -1, 45, 46, 47, 48, 48, 49, -1, -1, -1, -1, -1, -1, 14 },
			{5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19 },
			{20, 23, 21, 23, 21, 23, 23, 21, 22, 23, 23, 22, 21, 22, 21, 21, 22, 22, 23, 24 }


	};
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
				maps[static_cast<int>(currentMapName)][y][x] <= 24) {
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
			else if (maps[static_cast<int>(currentMapName)][y][x] >= 25 && //Glitched Block
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
				int tileNum = 5;
				objects.push_back(
					new Spike(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{ static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] % tileNum) * TILE_SIZE,
									static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] / tileNum) * TILE_SIZE,
									TILE_SIZE,
									TILE_SIZE },
						false,
						false
						)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 55 //glitched Spike
				) {
				int tileNum = 5;
				objects.push_back(
					new Spike(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{ static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] % tileNum) * TILE_SIZE,
									static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] / tileNum) * TILE_SIZE,
									TILE_SIZE,
									TILE_SIZE },
						true,
						false)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 60 //upside down Spike
				) {
				int tileNum = 5;
				objects.push_back(
					new Spike(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{ static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] % tileNum) * TILE_SIZE,
									static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] / tileNum) * TILE_SIZE,
									TILE_SIZE,
									TILE_SIZE },
						false,
						true)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 51 //Flag
				) {
				int tileNum = 5;
				objects.push_back(
					new Flag(Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						Rectangle{ static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] % tileNum) * TILE_SIZE,
									static_cast<float>(maps[static_cast<int>(currentMapName)][y][x] / tileNum) * TILE_SIZE,
									TILE_SIZE,
									TILE_SIZE },
						false)
				);
			}
		
		}
	}
	for (GameObject* obj : objects) {
		obj->Load();
	}
}
void Game::GameMap::Unload() {
	for (Game::GameObject* obj : objects)
	{
		delete obj;
	}

	objects.clear();
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
	isGlitchPlateActive = false;

	if (player.IsReadyToNextLevel) {
		currentMapName = static_cast<MapName>(static_cast<int>(currentMapName) + 1);
		objects.clear();
		ClearBackground (Color{ 42, 79, 107, 255 });
		player.Load();
		Load();
		player.IsReadyToNextLevel = false;
	}
	for (int i = objects.size() - 1; i >= 0; i--)
	{
		if (objects[i]->GetDead())
		{
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}
	
	if (player.GetIsAlive() == false) {
		Unload();
		Load();
		player.Load();
	}

}


void Game::GameMap::draw() {
	for (GameObject* obj : objects) {
		obj->Draw();
	}
}