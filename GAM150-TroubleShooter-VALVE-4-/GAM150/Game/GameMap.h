#pragma once
#include <raylib.h>
#include <vector>
#include "GameObject.h"
#include "Platform.h"
#include "MapName.h"
#include "Player.h"

namespace Game {
	class GameMap
	{
	public:
		GameMap();
		GameMap(MapName mapname);
		~GameMap();
		
		void LoadMap(MapName mapname);
		void Load();
		void Update(Game::Player& player, double dt);
		void draw();
		MapName GetCuurentMapName();
		std::vector<GameObject*> GetGameObject();




	private:
		MapName currentMapName = MapName::STAGE3_LEVEL1;
		std::vector<std::vector<std::vector<int>>> maps;
		std::vector<GameObject*> objects;
		static constexpr int TILE_SIZE = 64;
	};

}