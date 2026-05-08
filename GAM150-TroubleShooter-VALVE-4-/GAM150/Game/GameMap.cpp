#include "GameMap.h"

Game::GameMap::GameMap()
{


}

Game::GameMap::~GameMap() {
	for (Engine::GameObject* obj : objects)
		delete obj;
}

void Game::GameMap::LoadMap(MapName mapname) {
	maps.resize(static_cast<int>(MapName::COUNT));
	switch (mapname)
	{
	case MapName::STAGE1_LEVEL1:
		maps[static_cast<int>(MapName::STAGE1_LEVEL1)] =
		{
		{ 0, 1, 2, 3, 4,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{ 5, 6, 7, 8, 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{10,11,12,13,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{15,16,17,18,19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{20,21,22,23,24,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{25,26,27,28,29,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{30,31,32,33,34,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{35,36,37,38,39,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{40,41,42,43,44,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{45,46,47,48,49,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}


		};
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
		{10,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,14,-1,-1,-1,-1,-1,19},
		{10,-1,-1,-1,54,-1,-1,-1,-1,22,-1,-1,-1,14,-1,-1,-1,-1,-1,9},
		{5,-1,55,-1,14,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,56,-1,-1,9},
		{5,-1,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19},
		{15,4,-1,-1,-1,-1,-1,0,1,2,3,4,-1,0,1,2,4,-1,0,9},
		{10,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,14,-1,-1,-1,14,-1,-1,-1,14},
		{5,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,24,-1,-1,-1,21,21,-1,-1,9},
		{5,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,9},
		{5,-1,50,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,0,19},
		{20,23,21,23,22,23,23,21,22,23,23,22,22,22,22,21,22,22,23,24}
		};
		break;

	case MapName::STAGE3_LEVEL2:
		maps[static_cast<int>(MapName::STAGE3_LEVEL2)] =
		{
		{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
		{10,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,14,-1,-1,-1,-1,-1,19},
		{10,-1,-1,-1,54,-1,-1,-1,-1,22,-1,-1,-1,14,-1,-1,-1,-1,-1,9},
		{5,-1,-1,-1,14,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9},
		{5,-1,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19},
		{15,29,-1,-1,-1,-1,-1,25,1,2,3,4,-1,25,1,2,4,-1,0,9},
		{10,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,14,-1,-1,-1,14,-1,-1,51,14},
		{5,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,24,-1,-1,-1,21,21,-1,-1,9},
		{5,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,9},
		{5,-1,50,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,0,19},
		{20,23,21,23,46,23,23,21,47,23,23,22,47,22,22,21,22,22,23,24}
		};
		break;

	case MapName::STAGE3_LEVEL3:
		maps[static_cast<int>(MapName::STAGE3_LEVEL3)] =
		{
		{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
		{10,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,14,-1,-1,51,-1,19},
		{10,-1,-1,-1,54,-1,-1,-1,-1,51,-1,-1,-1,-1,24,-1,-1,-1,-1,9},
		{5,-1,-1,-1,14,-1,-1,-1,50,-1,50,-1,-1,-1,51,-1,50,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,2,-1,2,-1,-1,-1,-1,-1,4,-1,0,9},
		{5,-1,-1,20,22,24,-1,25,1,1,2,29,-1,25,2,2,9,-1,-1,19},
		{15,29,-1,-1,-1,-1,-1,5,51,51,22,51,-1,51,-1,51,19,-1,-1,9},
		{10,-1,-1,-1,-1,-1,-1,51,-1,-1,51,-1,-1,-1,-1,-1,14,-1,0,14},
		{5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,51,9},
		{5,-1,-1,-1,-1,-1,50,-1,-1,52,-1,-1,-1,-1,-1,-1,9,-1,-1,9},
		{5,-1,50,-1,-1,50,1,-1,52,1,-1,50,-1,50,-1,52,-1,-1,52,19},
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

void Game::GameMap::Load(Game::Player& player) {
	LoadMap(currentMapName);
	for (int y = 0; y < maps[static_cast<int>(currentMapName)].size(); y++) {
		for (int x = 0; x < maps[static_cast<int>(currentMapName)][y].size(); x++) {
			if (maps[static_cast<int>(currentMapName)][y][x] >= 0 && //Block
				maps[static_cast<int>(currentMapName)][y][x] <= 24) {
				objects.push_back(
					new Block(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x]),
						false
					));
			}

			else if (maps[static_cast<int>(currentMapName)][y][x] >= 25 && //Glitched Block
				maps[static_cast<int>(currentMapName)][y][x] <= 49
				) {
				objects.push_back(
					new Block(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 25),
						true
					));

			}

			else if (maps[static_cast<int>(currentMapName)][y][x] == 50 //Spike
				) {
				objects.push_back(
					new Spike(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 50),
						false,
						false
						)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 51 //upside down Spike
				) {
				objects.push_back(
					new Spike(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 50),
						false,
						true
					)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 52 //Glitched Spike
				) {
				objects.push_back(
					new Spike(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 52),
						true,
						false
					)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 53 //Glitched upsidedown Spike
				) {
				objects.push_back(
					new Spike(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 52),
						true,
						true
					)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 54 //Flag
				) {
				objects.push_back(
					new Flag(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 54),
						false
					)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 55 //Saw
				) {
				objects.push_back(
					new Saw(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 55),
						false,
						player
					)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 56 //Glitched Saw
				) {
				objects.push_back(
					new Saw(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 56),
						true,
						player
					)
				);
			}
		}
	}
	for (Engine::GameObject* obj : objects) {
		obj->Load();
	}
}
void Game::GameMap::Unload() {
	for (Engine::GameObject* obj : objects)
	{
		delete obj;
	}

	objects.clear();
}
void Game::GameMap::Update(Game::Player& player, double dt) {

	player.SetIsOnGround(false);
	player.SetCanJump(true);

	for (Engine::GameObject* obj : objects) {
		player.HandleCollision(obj, dt);
	}
	for (Engine::GameObject* obj : objects) {
		player.CorrectCollision(obj, dt);

	}
	for (Engine::GameObject* obj : objects) {
		obj->Update(dt);
	}
	isGlitchPlateActive = false;
	
	if (player.IsReadyToNextLevel || IsKeyPressed(KEY_F10)) {
		currentMapName = static_cast<MapName>(static_cast<int>(currentMapName) + 1);
		objects.clear();
		ClearBackground (Color{ 42, 79, 107, 255 });
		player.Load();
		Load(player);
		player.IsReadyToNextLevel = false;
	}
	for (int i = objects.size() - 1; i >= 0; i--)
	{
		if (objects[i]->GetUnload())
		{
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}
	
	if (player.GetIsAlive() == false) {
		Unload();
		Load(player);
		player.Load();
	}

}


void Game::GameMap::draw() {
	for (Engine::GameObject* obj : objects) {
		obj->Draw();
	}
}