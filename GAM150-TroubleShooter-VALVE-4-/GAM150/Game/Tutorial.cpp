#include "Tutorial.h"

void Tutorial::Draw(int quadrant, Vector2 position) {
    static Texture2D texture = LoadTexture("Assets/Texture/Tutorial.png");
    int halfW = texture.width / 2;
    int halfH = texture.height / 2;

    Rectangle source = {
        static_cast<float>((quadrant % 2) * halfW),
        static_cast<float>((quadrant / 2) * halfH),
        static_cast<float>(halfW),
        static_cast<float>(halfH)
    };
    Rectangle dest = {
        position.x, position.y,
        static_cast<float>(halfW), static_cast<float>(halfH)
    };

    DrawTexturePro(texture, source, dest, { 0, 0 }, 0.0f, WHITE);
}
