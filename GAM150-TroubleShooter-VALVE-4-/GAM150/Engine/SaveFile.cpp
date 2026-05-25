#include "SaveFile.h"
#include <iostream>

Engine::SaveFile::SaveFile()
{
}

void Engine::SaveFile::Load(const std::filesystem::path& save_file)
{
    save_file_path = save_file;
    if (save_file_path.extension() != ".sav") {
        std::cout << save_file_path.generic_string() + " is not a .savefile file";
        return;
    }
    std::ifstream in_file(save_file_path);

    if (in_file.is_open() == false) {
        std::cout << "Failed to open " + save_file_path.generic_string();
        return;
    }
    std::string text;
    while (in_file.eof() == false) {
        in_file >> text;
        if (text == "END") {
            break;
        }
        if (text == "CurrentGameMap") {
            in_file >> save_game_map;
        }
        else {
            std::cout << text<< " : Wrong name" << std::endl;
        }
    }

}

void Engine::SaveFile::Save(std::string CurrentGameMap)
{
    save_game_map = CurrentGameMap;
    if (save_file_path.extension() != ".sav") {
        std::cout << save_file_path.generic_string() + " is not a .sav file";
        return;
    }
    std::ofstream out_file(save_file_path, std::ios::trunc);
    if (out_file.is_open() == false) {
        std::cout << "Failed to open " + save_file_path.generic_string();
        return;
    }
    out_file << "CurrentGameMap " << CurrentGameMap << '\n' << "END" << '\n';

}

void Engine::SaveFile::Unload()
{
}


void Engine::SaveFile::Update()
{
}
