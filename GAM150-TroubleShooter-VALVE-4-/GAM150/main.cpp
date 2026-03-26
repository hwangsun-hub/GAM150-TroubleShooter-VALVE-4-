#include "Engine/Application.h"

int main() {


    Engine::Application& engine = Engine::Application::Instance();
    engine.Start("Assignment 3 - sun.hwang@digipen.edu");
    while (IsKeyPressed(KEY_A) == false) {
        engine.Update();
    }
    return 0;
}