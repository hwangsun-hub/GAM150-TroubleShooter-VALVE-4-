#pragma once
#include <raylib.h>
#include "../Engine/GameObject.h"

class Platform : public Engine::GameObject
{
public:
	Platform(Vector2 pos, Rectangle texture_source, bool isglitchmoded);
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool GetIsGlitchMode() override;
	bool CheckCollision(Rectangle hibox) override;

private:
	Vector2  position;
	Texture2D texture;
	bool isGlitchMode;
	bool isCollision;
	Rectangle hitbox;
	Rectangle textureSourceRectangle;
	ObjectID::ID id;

	static constexpr int SIZE = 64;
};

