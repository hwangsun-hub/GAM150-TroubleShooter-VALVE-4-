#pragma once
#include <filesystem>
#include <fstream>
#include <raylib.h>


namespace Engine {
	class SaveFile {
	public:
		SaveFile();
		void Load(const std::filesystem::path& save_file);
		void Save(std::string CurrentGameMap);
		void Unload();
		void Update();
		std::string GetMaxGameMap() const { return savefile.back(); }
	private:
		std::filesystem::path save_file_path;
		std::vector<std::string> savefile;
		
	};
}
