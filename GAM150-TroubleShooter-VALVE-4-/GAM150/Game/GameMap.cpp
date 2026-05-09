#include "GameMap.h"
#include <iostream>
Game::GameMap::GameMap()
{


}

Game::GameMap::~GameMap() {
	for (Engine::GameObject* obj : objects)
		delete obj;
}

void Game::GameMap::LoadMap(MapName mapname) {
	maps.resize(static_cast<int>(MapName::COUNT));
	maps_for_saw.resize(static_cast<int>(MapName::COUNT));

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
		{5,-1,70,72,14,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,75,-1,-1,9},
		{5,99,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19},
		{15,4,-1,-1,-1,-1,-1,0,1,2,3,4,-1,0,1,2,4,-1,0,9},
		{10,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,14,-1,-1,-1,14,-1,-1,-1,14},
		{5,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,24,-1,-1,-1,21,21,-1,-1,9},
		{5,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,9},
		{5,-1,50,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,0,19},
		{20,23,21,23,22,23,23,21,22,23,23,22,22,22,22,21,22,22,23,24}
		};
		maps_for_saw[static_cast<int>(MapName::STAGE3_LEVEL1)] =
		{
			{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
			{10,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,14,-1,-1,-1,-1,-1,19},
			{10,-1,-1,-1,54,-1,-1,-1,-1,22,-1,-1,-1,14,-1,-1,-1,-1,-1,9},
			{5,-1,70,71,14,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,-1,-1,19},
			{15,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,75,-1,-1,9},
			{5,99,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19},
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
		{5,99,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19},
		{15,29,-1,-1,-1,-1,-1,25,1,2,3,4,-1,25,1,2,4,-1,0,9},
		{10,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,14,-1,-1,-1,14,-1,-1,51,14},
		{5,-1,-1,-1,-1,-1,-1,20,-1,-1,-1,24,-1,-1,-1,21,21,-1,-1,9},
		{5,-1,-1,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,9},
		{5,-1,50,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,-1,-1,-1,50,0,19},
		{20,23,21,23,46,23,23,21,47,23,23,22,47,22,22,21,22,22,23,24}
		};
		maps_for_saw[static_cast<int>(MapName::STAGE3_LEVEL2)] =
		{
			{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
		{10,-1,-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,14,-1,-1,-1,-1,-1,19},
		{10,-1,70,73,54,-1,-1,-1,-1,22,-1,-1,-1,14,-1,-1,-1,-1,-1,9},
		{5,-1,-1,-1,14,-1,-1,-1,-1,51,-1,-1,-1,51,-1,-1,-1,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,9},
		{5,99,-1,-1,22,24,-1,-1,50,-1,50,-1,-1,-1,-1,50,-1,-1,-1,19},
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
		{5,99,-1,20,22,24,-1,25,1,1,2,29,-1,25,2,2,9,-1,-1,19},
		{15,29,-1,-1,-1,-1,-1,5,51,51,22,51,-1,51,-1,51,19,-1,-1,9},
		{10,-1,-1,-1,-1,-1,-1,51,-1,-1,51,-1,-1,-1,-1,-1,14,-1,0,14},
		{5,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,19,-1,51,9},
		{5,-1,-1,-1,-1,-1,50,-1,-1,52,-1,-1,-1,-1,-1,-1,9,-1,-1,9},
		{5,-1,50,-1,-1,50,1,-1,52,1,-1,50,-1,50,-1,52,-1,-1,52,19},
		{20,23,21,23,27,23,23,21,22,23,23,22,27,22,27,21,22,22,23,24}
		};
		maps_for_saw[static_cast<int>(MapName::STAGE3_LEVEL3)] =
		{
			{0,1,2,1,1,3,2,2,2,3,1,3,3,2,1,2,1,1,1,4},
		{10,-1,-1,-1,-1,-1,-1,-1,-1,22,-1,-1,-1,-1,14,-1,-1,51,-1,19},
		{10,-1,70,-1,54,-1,-1,-1,-1,51,-1,-1,-1,-1,24,-1,-1,-1,-1,9},
		{5,-1,-1,-1,14,-1,-1,-1,50,-1,50,-1,-1,-1,51,-1,50,-1,-1,19},
		{15,-1,-1,-1,14,-1,-1,-1,2,-1,2,-1,-1,-1,-1,-1,4,-1,0,9},
		{5,99,-1,20,22,24,-1,25,1,1,2,29,-1,25,2,2,9,-1,-1,19},
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
			{5, -1, 99, -1, 5, 6, 7, 8, 9, -1, -1, 5, 6, 7, 8, 9, -1, -1, -1, 19 },
			{15, -1, -1, -1, 10, 11, 12, 13, 14, -1, -1, 10, 11, 12, 13, 14, -1, -1, -1, 9 },
			{5, -1, -1, -1, 15, 16, 17, 18, 19, -1, -1, 15, 16, 17, 18, 19, -1, -1, -1, 19 },
			{15, -1, -1, -1, 20, 21, 22, 23, 24, -1, -1, 20, 21, 22, 23, 24, -1, -1, -1, 9},
			{10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14 },
			{5, -1, -1, -1, -1, -1, -1, 25, -1, -1, -1, -1, 29, -1, -1, -1, -1, -1, -1, 9 },
			{5, -1, -1, -1, -1, -1, -1, 45, 46, 47, 48, 48, 49, -1, -1, -1, -1, -1, -1, 14 },
			{5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19 },
			{20, 23, 21, 23, 21, 23, 23, 21, 22, 23, 23, 22, 21, 22, 21, 21, 22, 22, 23, 24 }


	};
		maps_for_saw[static_cast<int>(MapName::STAGE4_LEVEL1)] =
		{
		{ 0, 1, 2, 1, 1, 3, 2, 2, 2, 3, 1, 3, 3, 2, 1, 2, 1, 1, 1, 4 },
			{10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19 },
			{10, -1, -1, -1, 0, 1, 2, 3, 4, -1, -1, 0, 1, 2, 3, 4, -1, -1, -1, 9 },
			{5, -1, 99, -1, 5, 6, 7, 8, 9, -1, -1, 5, 6, 7, 8, 9, -1, -1, -1, 19 },
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
			
			if (maps_for_saw[static_cast<int>(currentMapName)][y][x] == 70 //Saw
				) {
				int x_for_row[4] = { 1,-1,0,0 };
				int y_for_column[4] = { 0,0,1,-1 };

				int sx = x;
				int sy = y;
				int size = 0;
				Vector2 direction{ 0,0 };
				for (int i = 0; i < 4; i++)
				{
					sx += x_for_row[i];
					sy += y_for_column[i];
					if (sx > 0 && sx < maps_for_saw[static_cast<int>(currentMapName)][y].size() && sy>0 && sy < maps_for_saw[static_cast<int>(currentMapName)].size())
					{
						if (maps_for_saw[static_cast<int>(currentMapName)][sy][sx] > 70 &&
							maps_for_saw[static_cast<int>(currentMapName)][sy][sx] < 75) {
							size = 75 - maps_for_saw[static_cast<int>(currentMapName)][sy][sx];
							direction = { float(x_for_row[i]) ,float(y_for_column[i]) };
							break;
						}
					}
					

				}
				
				objects.push_back(
					new Saw(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps_for_saw[static_cast<int>(currentMapName)][y][x] - 70),
						false,
						size,
						direction,
						player
					)
				);
			}
			else if (maps_for_saw[static_cast<int>(currentMapName)][y][x] == 75 //Glitched Saw
				) {
				
				objects.push_back(
					new Saw(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps_for_saw[static_cast<int>(currentMapName)][y][x] - 75),
						true,
						0,
						Vector2 {0,0},
						player
					)
				);
			}

			
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
/*			else if (maps[static_cast<int>(currentMapName)][y][x] == 70 //Saw
				) {
				objects.push_back(
					new Saw(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 70),
						false,
						player
					)
				);
			}
			else if (maps[static_cast<int>(currentMapName)][y][x] == 75 //Glitched Saw
				) {
				objects.push_back(
					new Saw(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(maps[static_cast<int>(currentMapName)][y][x] - 75),
						true,
						player
					)
				);
			}*/
			else if (maps[static_cast<int>(currentMapName)][y][x] == 99 //player_start_position
				) {
				player_start_position = { static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE };
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
	if (player.CheckTroubleShoot()) {
			//making touble
		troubles.push_back(
			new Trouble(
				player.GetPosition(),
				player.GetIsLookingRight()
			)
		);
	}

	
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

	for (Trouble* trouble : troubles) {
		for (Engine::GameObject* obj : objects) {
			trouble->Update(obj, dt);
		}
	}
	
	
	if (player.IsReadyToNextLevel || IsKeyPressed(KEY_F10)) {
		currentMapName = static_cast<MapName>(static_cast<int>(currentMapName) + 1);
		Unload();
		ClearBackground (Color{ 42, 79, 107, 255 });
		player.Load(player_start_position);
		Load(player);
		player.IsReadyToNextLevel = false;
	}
	for (int i = static_cast<int>(objects.size()) - 1; i >= 0; i--)
	{
		if (objects[i]->GetUnload())
		{
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}

	for (int i = static_cast<int>(troubles.size()) - 1; i >= 0; i--)
	{
		if (troubles[i]->GetUnload())
		{
			delete troubles[i];
			troubles.erase(troubles.begin() + i);
		}
	}
	
	if (player.GetIsAlive() == false) {
		Unload();
		Load(player);
		player.Load(player_start_position);
	}

}


void Game::GameMap::draw() {
	for (Engine::GameObject* obj : objects) {
		obj->Draw();
	}
	for (Trouble* trouble : troubles) {
		trouble->Draw();
	}
}

Vector2 Game::GameMap::GetStartPosition() const
{
	return player_start_position;
}
