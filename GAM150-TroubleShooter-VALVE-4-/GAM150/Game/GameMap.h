#pragma once
#include <raylib.h>
#include <vector>
#include "../Engine/GameObject.h"
#include "../Engine/TextureManager.h"
#include "Platform.h"
#include "MapName.h"
#include "Player.h"
#include "Block.h"
#include "Spike.h"
#include "Flag.h"
#include "Saw.h"
#include "Trouble.h"

namespace Game {
	class GameMap
	{
	public:
		GameMap();
		GameMap(MapName mapname);
		~GameMap();

		void LoadMap(MapName mapname);
		void Unload();
		void Load(Game::Player& player);
		void Update(Game::Player& player, double dt);
		void draw();
		MapName GetCuurentMapName();
		std::vector<Engine::GameObject*> GetGameObject();
		Vector2 GetStartPosition() const;



	private:
		MapName currentMapName = MapName::STAGE2_LEVEL1;
		std::vector<std::vector<std::vector<int>>> maps;
		std::vector<std::vector<std::vector<int>>> maps_for_saw;
		std::vector<Trouble*> troubles;

		std::vector<Engine::GameObject*> objects;
		static constexpr int TILE_SIZE = 64;
		bool isGlitchPlateActive = false;
		Vector2 player_start_position;
	};

}