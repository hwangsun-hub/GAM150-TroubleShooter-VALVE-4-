#include "Dialogue.h"
#include <iostream>
#include <string>
Dialogue::Dialogue()
{
}

Dialogue::Dialogue(const std::filesystem::path& dialogue_file) : current_dialogue(0){
    Load(dialogue_file);
}

void Dialogue::Load(const std::filesystem::path& dialogue_file)
{
    font = GetFontDefault();
    dialogueTexture = LoadTexture("Assets/Dialogue/dialogue.png");
    if (dialogue_file.extension() != ".dialogue") {
        std::cout << std::string(dialogue_file.generic_string() + " is not a .dialogue file");
        return;
    }
    std::ifstream in_file(dialogue_file);


    if (in_file.is_open() == false) {
        std::cout << std::string("Failed to load " + dialogue_file.generic_string());
        return;
    }
    std::string name;
    std::string text;
    while (in_file >> name >> std::ws) {
        
        if (name == "END") {
            break;
        }
        std::getline(in_file, text);
        if (name == "I" || name == "Enemy") {
            dialogues.push_back({ name, text });
        }
        else if (name == "Plus") {
            dialogues.back().second += "\n"+text;
        }
        else {
            std::cout << "Wrong name" << std::endl;
        }
    }
    if (!dialogues.empty())
    {
        IsTalking = true;
        current_dialogue = 0;
    }
    else
    {
        IsTalking = false;
    }
    name_position = { ((float)GetScreenWidth() -  dialogueTexture.width)/2,600 };
    dialogue_position = { name_position.x, name_position.y + 50 };
}

void Dialogue::Unload()
{
    current_dialogue = 0;
    dialogues.clear();
}

void Dialogue::Draw()
{
    if (IsTalking) {
        DrawTextureEx(dialogueTexture, { name_position.x - 20 ,name_position.y - 10 }, 0.0f, 1.0f, WHITE);
        DrawTextEx(font, dialogues[current_dialogue].first.c_str(), name_position, fontSize, spacing, tint);
        DrawTextEx(font, dialogues[current_dialogue].second.c_str(), dialogue_position, fontSize-10.0f, spacing, tint);
    }
}

void Dialogue::Update()
{
    if (IsKeyPressed(KEY_ENTER)) {
        if (current_dialogue + 1 < dialogues.size()) {
            current_dialogue++;
        }
        else {
            IsTalking = false;
        }
    }

}
