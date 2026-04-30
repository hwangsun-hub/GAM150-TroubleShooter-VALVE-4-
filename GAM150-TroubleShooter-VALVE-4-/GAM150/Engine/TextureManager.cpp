#include "TextureManager.h"
#include "Application.h"
#include "Texture.h"

Engine::Texture* Engine::TextureManager::Load(const std::filesystem::path& image_file)
{
    auto it = textures.find(image_file);
    if (it != textures.end()) {
        return it->second;
    }

    Texture* texture = new Texture(image_file);
    textures[image_file] = texture;
    return texture;
}

void Engine::TextureManager::Unload() {
    for (auto& pair : textures) {
        delete pair.second;
    }
    textures.clear();
}