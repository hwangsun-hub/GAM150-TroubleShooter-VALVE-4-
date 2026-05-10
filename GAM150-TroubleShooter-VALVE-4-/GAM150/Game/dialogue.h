#pragma once
#include <filesystem>
#include <fstream>
#include <raylib.h>

class Dialogue {
public:
	Dialogue();
	Dialogue(const std::filesystem::path& dialogue_file);
	void Load(const std::filesystem::path& dialogue_file);
	void Unload();
	void Draw();
	void Update();
	bool IsFinished() const { return !IsTalking; };
private:
	std::vector<std::pair<std::string, std::string>> dialogues;
	int current_dialogue = 0;
	Font font = GetFontDefault();
	Vector2 name_position{150,500};
	Vector2 dialogue_position{ 120,590 };
	float fontSize = 50.0f;
	float spacing = 2.0f;
	Color tint = BLACK;
	bool IsTalking = true;
};
