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
        static constexpr int default_width = 800;
        static constexpr int default_height = 600;
        static constexpr unsigned int default_background = 0xFFFFFFFF;
    };
}