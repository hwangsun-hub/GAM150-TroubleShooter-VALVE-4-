#include "dialogue.h"
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
        
        else {
            std::cout << "Wrong name" << std::endl;
        }
    }
    if (!dialogues.empty())
    {
        IsTalking = true;
        current_dialogue = 0;
        std::cout << "size: " << dialogues.size() << std::endl;
    }
    else
    {
        std::cout << "EMpty: " << dialogues.size() << std::endl;
        IsTalking = false;
    }
}

void Dialogue::Unload()
{
    std::cout << "Unload: " << dialogues.size() << std::endl;
    current_dialogue = 0;
    dialogues.clear();
}

void Dialogue::Draw()
{
    if (IsTalking) {
        DrawRectangle(name_position.x -10, name_position.y-10 , 100, fontSize+10, WHITE);
        DrawRectangle(dialogue_position.x-10 , dialogue_position.y-10 , 300, fontSize + 10, WHITE);
        DrawTextEx(font, dialogues[current_dialogue].first.c_str(), name_position, fontSize, spacing, tint);
        DrawTextEx(font, dialogues[current_dialogue].second.c_str(), dialogue_position, fontSize, spacing, tint);
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
