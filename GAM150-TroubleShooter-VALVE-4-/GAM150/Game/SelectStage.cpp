#include "SelectStage.h"
#include "Block.h"
#include "Flag.h"
#include "SelectBox.h"
#include "States.h"
#include "GameMode.h"
#include "../Engine/Application.h"
Game::SelectStage::SelectStage()
{
	 currentMapName = MapName::SelectStage;

}
Game::SelectStage::~SelectStage()
{
}

void Game::SelectStage::LoadMap()
{
	switch (currentMapName)
	{
	case MapName::SelectStage:
		maps[static_cast<int>(MapName::SelectStage)] =
		{
			{ 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 19,-1,101,-1,-1,102,-1,-1,103,-1,-1,104,-1,-1,105,-1,-1,106,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,99,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 0,2,1,3,1,3,1,1,1,2,3,3,1,3,2,2,1,1,1,4 }
		};

		break;
	case MapName::STAGE0:
		maps[static_cast<int>(MapName::STAGE0)] =
		{
			{ 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 19,-1,-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 19,-1,-1,-1,107,-1,108,-1,109,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1, - 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,99,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,100,-1,5 },
			{ 0,2,1,3,1,3,1,1,1,2,3,3,1,3,2,2,1,1,1,4 }
		};
		break;
	case MapName::STAGE1:
		maps[static_cast<int>(MapName::STAGE1)] =
		{
			 { 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 19,-1,-1,-1,110,-1,-1,111,-1,-1,112,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1, - 1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,99,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,100,-1,5 },
			{ 0,2,1,3,1,3,1,1,1,2,3,3,1,3,2,2,1,1,1,4 }
		};
		break;
	case MapName::STAGE2:
		maps[static_cast<int>(MapName::STAGE2)] =
		{
			{ 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 19,-1,-1,-1,113,-1,-1,114,-1,-1,115,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,0,1,2,4,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,99,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,100,-1,5 },
			{ 0,2,1,3,1,3,1,1,1,2,3,3,1,3,2,2,1,1,1,4 }
		};
		break;
	case MapName::STAGE3:
		maps[static_cast<int>(MapName::STAGE3)] =
		{
			{ 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 19,-1,-1,-1,116,-1,-1,117,-1,-1,118,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,99,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,100,-1,5 },
			{ 0,2,1,3,1,3,1,1,1,2,3,3,1,3,2,2,1,1,1,4 }
		};
		break;
	case MapName::STAGE4:
		maps[static_cast<int>(MapName::STAGE4)] =
		{
			{ 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 19,-1,-1,-1,119,-1,-1,120,-1,-1,121,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,99,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,100,-1,-1,5 },
			{ 0,2,1,3,1,3,1,1,1,2,3,3,1,3,2,2,1,1,1,4 }

		};
		break;
	case MapName::STAGE5:
		maps[static_cast<int>(MapName::STAGE5)] =
		{
			{ 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 19,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,10 },
			{ 14,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15 },
			{ 19,-1,-1,-1,122,-1,-1,123,-1,-1,124,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5 },
			{ 9,-1,99,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,100,-1,-1,5 },
			{ 0,2,1,3,1,3,1,1,1,2,3,3,1,3,2,2,1,1,1,4 }

		};
		break;
	}
}



void Game::SelectStage::Unload()
{
	player.Unload();
	for (Engine::GameObject* obj : objects)
	{
		delete obj;
	}

	objects.clear();
}

void Game::SelectStage::Load()
{
	maps.resize(static_cast<int>(MapName::COUNT));
	ChangeMap();
	LoadMap();
	std::vector<std::vector<int>>& currentMap = maps[static_cast<int>(currentMapName)];
	for (int y = 0; y < currentMap.size(); y++) {
		for (int x = 0; x < currentMap[y].size(); x++) {

		


			if (currentMap[y][x] >= 0 && //Block
				currentMap[y][x] <= 24) {
				objects.push_back(
					new Block(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(currentMap[y][x]),
						false
					));
			}

			else if (currentMap[y][x] >= 25 && //Glitched Block
				currentMap[y][x] <= 49
				) {
				objects.push_back(
					new Block(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(currentMap[y][x] - 25),
						true
					));

			}

			
			
			else if (currentMap[y][x] >= 100 &&//SelectBox
				currentMap[y][x] <= 124
				) {
				objects.push_back(
					new SelectBox(
						Vector2{ static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE },
						(currentMap[y][x] - 101),
						false,
						static_cast<MapName>((currentMap[y][x] - 100))
					)
				);
			}
		
			else if (currentMap[y][x] == 99 //player_start_position
				) {
				player_start_position = { static_cast<float>(x) * TILE_SIZE, static_cast<float>(y) * TILE_SIZE + TILE_SIZE / 2 };
			}
		}
	}
	for (Engine::GameObject* obj : objects) {
		obj->Load();
	}
	player.Load(player_start_position);
}
void Game::SelectStage::Update(double dt)
{
	player.Update(dt);
	player.SetIsOnGround(false);
	player.SetCanJump(true);

	UpdateObjects(dt);
	if (IsKeyPressed(KEY_ONE)) {
		Engine::Application::GetGameStateManager().SetNextGameState(static_cast<int>(States::MainMenu));  // mainmenu
	}
	
	ui.Update(player);

	if (player.IsReadyToNextLevel)
	{
		MapTransition();
	}
}

void Game::SelectStage::Draw()
{
	Engine::Application::GetWindow().Clear(0x2A4F6BFF);

	for (Engine::GameObject* obj : objects) {
		obj->Draw();
	}
	player.Draw();
	ui.Draw(player);

}

Vector2 Game::SelectStage::GetStartPosition() const
{
	return player_start_position;
}
#include <iostream>
void Game::SelectStage::MapTransition()
{
    if (player.IsReadyToNextLevel && static_cast<int>(currentMapName) > 6) {
		Engine::Application::GetGameStateManager().SetNextGameState(static_cast<int>(States::GameMode));
		static_cast<GameMode*>(Engine::Application::GetGameStateManager().GetGameState(static_cast<int>(States::GameMode)))->SetCurrentMap(currentMapName);
		player.IsReadyToNextLevel = false;
		currentMapName = MapName::SelectStage;
		return;
	}
	Unload();
	ClearBackground(Color{ 42, 79, 107, 255 });
	ChangeMap();
	Load();
	player.Load(GetStartPosition());
	player.IsReadyToNextLevel = false;
}

void Game::SelectStage::UpdateObjects(double dt)
{
	for (Engine::GameObject* obj : objects) {
		player.HandleCollision(obj, dt);
	}
	for (Engine::GameObject* obj : objects) {
		player.CorrectCollision(obj, dt, objects);

	}
	for (Engine::GameObject* obj : objects) {
		obj->Update(dt);
	}
	for (Engine::GameObject* obj : objects) {
		if (obj->GetObjectID() == ObjectID::ID::SELECTBOX &&
			CheckCollisionRecs(player.GetHitbox(), obj->GetHitbox())) 
		{
			player.IsReadyToNextLevel = false;

   			currentMapName = static_cast<SelectBox*>(obj)->GetMapName();
			int current = static_cast<int>(currentMapName);
			int maxMap = static_cast<int>(MapNameStringToMapName[Engine::Application::GetSaveFile().GetMaxGameMap()]);
			std::cout << "[LOG] current: " << current
				<< " / current+1: " << current + 1
				<< " / maxMap: " << maxMap
				<< " / condition: " << (current + 1 <= maxMap) << std::endl;
			if (static_cast<int>(currentMapName) < 6 ) {
				player.IsReadyToNextLevel = true;
				
        	}else if (static_cast<int>(currentMapName)  <= static_cast<int>(MapNameStringToMapName[Engine::Application::GetSaveFile().GetMaxGameMap()])) {
				player.IsReadyToNextLevel = true;
				

				
			}
		}
	}
}

void Game::SelectStage::ChangeMap()
{
	ui.WhenMapChanged(GetCurrentMapName());

}

std::string Game::SelectStage::GetCurrentMapName() const
{
	return MapNames[static_cast<int>(currentMapName)];
}

