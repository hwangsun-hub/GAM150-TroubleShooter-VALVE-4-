#pragma once
#include "GameObject.h"


namespace Engine {
    class GameObjectManager {
    public:
        void Add(GameObject* object);
        void Unload();

        void UpdateAll(double dt);
        void DrawAll();
    private:
        std::vector<GameObject*> objects;
    };
}