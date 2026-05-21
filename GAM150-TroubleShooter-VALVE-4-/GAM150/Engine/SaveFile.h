#pragma once
#include <filesystem>
#include <fstream>
#include <raylib.h>


class SaveFile {
public:
	SaveFile();
	SaveFile(const std::filesystem::path& save_file);
	void Load(const std::filesystem::path& save_file);
	void Save(std::string CurrentGameMap);
	void Unload();
	void Update();
	bool IsFinished() const { return !IsTalking; };
private:
	std::vector<std::string> savefile;
	int current_dialogue = 0;
	Font font = GetFontDefault();
	Vector2 name_position;
	Vector2 dialogue_position;
	float fontSize = 40.0f;
	float spacing = 2.0f;
	Color tint = BLACK;
	bool IsTalking = true;
	Texture2D dialogueTexture;
};
=======
namespace Engine {
	class SaveFile {
	public:
		SaveFile();
		void Load(const std::filesystem::path& save_file);
		void Save(std::string CurrentGameMap);
		void Unload();
		void Update();
		std::string GetCurrentGameMap() const { return savefile.back(); }
	private:
		std::filesystem::path save_file_path;
		std::vector<std::string> savefile;
		
	};
}
>>>>>>> Stashed changes
