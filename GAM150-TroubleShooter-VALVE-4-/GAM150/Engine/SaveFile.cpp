#include "SaveFile.h"
#include <iostream>
#include <string>

Engine::SaveFile::SaveFile()
{
}



void Engine::SaveFile::Load(const std::filesystem::path& save_file)
{
    save_file_path = save_file;
    if (save_file_path.extension() != ".sav") {
        std::cout << std::string(save_file_path.generic_string() + " is not a .savefile file");
        return;
    }
    std::ifstream in_file(save_file_path);

    if (in_file.is_open() == false) {
        std::cout << std::string("Failed to load " + save_file_path.generic_string());
        return;
    }
    std::string text;

    while (in_file.eof() == false) {
        in_file >> text;
        if (text == "END") {
            break;
        }
        if (text == "CurrentGameMap") {
            in_file >> text;
            savefile.push_back(text);
        }
        else {
            std::cout << text<< " : Wrong name" << std::endl;
        }
    }

}

void Engine::SaveFile::Save(std::string CurrentGameMap)
{
    if (save_file_path.extension() != ".sav") {
        std::cout << std::string(save_file_path.generic_string() + " is not a .sav file");
        return;
    }
    std::ofstream out_file(save_file_path, std::ios::in | std::ios::out);
    if (out_file.is_open() == false) {
        std::cout << std::string("Failed to load " + save_file_path.generic_string());
        return;
    }
    out_file.seekp(15, std::ios::beg);

    out_file << CurrentGameMap << '\n'<<"END";
    savefile.push_back(CurrentGameMap);
}

void Engine::SaveFile::Unload()
{
}


void Engine::SaveFile::Update()
{
}
