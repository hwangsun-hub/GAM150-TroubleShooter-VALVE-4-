#pragma once
#include <filesystem>
#include <raylib.h>

namespace Engine {
    class Texture {
    public:
        Texture();
        ~Texture();

        void Draw(Rectangle source, Rectangle destination, Vector2 origin, float rotation, Color tint);
        void Load(const std::filesystem::path& file_name);

        Vector2 GetSize() const;

    private:

        Texture2D texture;
        Texture(const std::filesystem::path& file_name);
       /* Rectangle source;
        Rectangle destination;
        Vector2 origin;
        float rotation;
        Color tint;*/
        friend class TextureManager;

    };
}