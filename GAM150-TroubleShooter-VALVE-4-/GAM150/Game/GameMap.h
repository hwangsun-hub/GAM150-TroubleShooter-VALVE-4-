#pragma once
#include <raylib.h>
#include <vector>
#include "GameObject.h"
#include "Floor.h"

namespace Game {
	class GameMap
	{
	public:
		GameMap();
		~GameMap();
		enum class MapName
		{
			STAGE1_LEVEL1,
			STAGE1_LEVEL2,
			STAGE1_LEVEL3,
			STAGE2_LEVEL1,
			STAGE2_LEVEL2,
			STAGE2_LEVEL3,
			STAGE3_LEVEL1,
			STAGE3_LEVEL2,
			STAGE3_LEVEL3,
			STAGE4_LEVEL1,
			STAGE4_LEVEL2,
			STAGE4_LEVEL3,
			STAGE5_LEVEL1,
			STAGE5_LEVEL2,
			STAGE5_LEVEL3,
		};
		void LoadMap(MapName mapname);
		void Load(MapName mapname);
		void Update(double dt);
		void draw(MapName mapname);




	private:
		MapName currentMapName = STAGE3_LEVEL1;
		std::vector<std::vector<std::vector<int>>> maps;
		std::vector<GameObject*> objects;
	};

}