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
