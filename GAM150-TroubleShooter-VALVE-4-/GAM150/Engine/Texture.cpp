#include "Texture.h"
#include "Application.h"

Engine::Texture::Texture() : texture{ 0 } {}
Engine::Texture::Texture(const std::filesystem::path& file_name) {
    texture = LoadTexture(file_name.string().c_str());
    SetTextureWrap(texture, TEXTURE_WRAP_CLAMP);
}

Engine::Texture::~Texture() {
    UnloadTexture(texture);
}


Vector2 Engine::Texture::GetSize() const {
    return { (float)texture.width, (float)texture.height };
}

void Engine::Texture::Draw(Rectangle source, Rectangle destination, Vector2 origin, float rotation, Color tint) {
    DrawTexturePro(texture, source, destination, origin, rotation, tint);
}

void Engine::Texture::Load(const std::filesystem::path& file_name)
{
    texture = LoadTexture(file_name.string().c_str());
    SetTextureWrap(texture, TEXTURE_WRAP_CLAMP);
}

