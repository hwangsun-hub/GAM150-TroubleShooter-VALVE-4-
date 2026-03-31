#pragma once
#include <raylib.h>
#include <vector>
#include "GameObject.h"
#include "Floor.h"
#include "MapName.h"

namespace Game {
	class GameMap
	{
	public:
		GameMap();
		~GameMap();
		
		void LoadMap(MapName mapname);
		void Load(MapName mapname);
		void Update(double dt);
		void draw(MapName mapname);




	private:
		MapName currentMapName = MapName::STAGE3_LEVEL1;
		std::vector<std::vector<std::vector<int>>> maps;
		std::vector<GameObject*> objects;
	};

}