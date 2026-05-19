#include "SaveFile.h"
#include <iostream>
#include <string>

SaveFile::SaveFile()
{
}

SaveFile::SaveFile(const std::filesystem::path& save_file)
{
	Load(save_file);
}

void SaveFile::Load(const std::filesystem::path& save_file)
{
    if (save_file.extension() != ".savefile") {
        std::cout << std::string(save_file.generic_string() + " is not a .savefile file");
        return;
    }
    std::ifstream in_file(save_file);


    if (in_file.is_open() == false) {
        std::cout << std::string("Failed to load " + save_file.generic_string());
        return;
    }
    std::string text;
    while (in_file >> text >> std::ws) {

        if (text == "END") {
            break;
        }
        std::getline(in_file, text);
        if (text == "CurrentGameMap") {
            savefile.push_back(text);
        }
        else {
            std::cout << "Wrong name" << std::endl;
        }
    }
}

void SaveFile::Save(std::string CurrentGameMap)
{

}

void SaveFile::Unload()
{
}


void SaveFile::Update()
{
}
