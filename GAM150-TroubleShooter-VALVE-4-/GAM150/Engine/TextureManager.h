#pragma once
#include <filesystem>
#include <map>

namespace Engine {
    class Texture;

    class TextureManager {
    public:
        Texture* Load(const std::filesystem::path& image_file);
        void Unload();

    private:
        std::map<std::filesystem::path, Texture*> textures;
    };
}