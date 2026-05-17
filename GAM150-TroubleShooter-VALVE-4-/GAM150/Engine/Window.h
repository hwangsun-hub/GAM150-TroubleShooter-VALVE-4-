#pragma once
#include <string>
#include <raylib.h>
#include <rlgl.h>

namespace Engine {
    class Window {
    public:
        void Start(std::string title);
        void Update();
        bool IsClosed() const;
        Vector2 GetSize() const;
        void Clear(unsigned int color);

    private:
        Vector2 size;
        static constexpr int TILE_SIZE = 64;
        static constexpr int default_width = TILE_SIZE * 25;
        static constexpr int default_height = TILE_SIZE * 15;
        static constexpr unsigned int default_background = 0xFFFFFFFF;
        
    };
}