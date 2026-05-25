#pragma once
#include <filesystem>
#include <fstream>
#include <raylib.h>
#include <string>

namespace Engine {
	class SaveFile {
	public:
		SaveFile();
		void Load(const std::filesystem::path& save_file);
		void Save(std::string CurrentGameMap);
		void Unload();
		void Update();
		std::string GetCurrentGameMap() const { return save_game_map; }
	private:
		std::filesystem::path save_file_path;
		std::string save_game_map = "SelectStage";
	};
}
