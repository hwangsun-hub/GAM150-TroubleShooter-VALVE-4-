#include "Window.h"



void Engine::Window::Start(std::string title) {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(default_width, default_height, title.c_str());
    size = { default_width, default_height };
    SetExitKey(KEY_NULL);
    BeginDrawing();
    Clear(default_background);
}


void Engine::Window::Update() {
    EndDrawing();

    float current_width = GetScreenWidth();
    float current_height = GetScreenHeight();
    if (current_width != size.x || current_height != size.y) {
        size = { current_width, current_height };
    }

    BeginDrawing();
}


bool Engine::Window::IsClosed() const {
    return WindowShouldClose();
}

Vector2 Engine::Window::GetSize() const {
    return size;
}

void Engine::Window::Clear(unsigned int rgba) {
    const Color rl_color = Color{
        static_cast<unsigned char>((rgba >> 24) & 0xFF),
        static_cast<unsigned char>((rgba >> 16) & 0xFF),
        static_cast<unsigned char>((rgba >> 8) & 0xFF),
        static_cast<unsigned char>(rgba & 0xFF)
    };

    ClearBackground(rl_color);
}