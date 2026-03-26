#include "Engine/Application.h"

int main() {


    Engine::Application& engine = Engine::Application::Instance();
    engine.Start("TroubleShooter");
    while (IsKeyPressed(KEY_A) == false) {
        engine.Update();
    }
    return 0;
}