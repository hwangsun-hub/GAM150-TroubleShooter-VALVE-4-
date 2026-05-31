#pragma once
#include <raylib.h>
#include <vector>
#include "../Engine/GameObject.h"

class Box : public Engine::GameObject {
public:
	Box(Vector2 pos);
	void Load() override;
	void Update(double dt) override;
	void Draw() override;
	Vector2 GetPosition() override;
	Rectangle GetHitbox() override;
	ObjectID::ID GetObjectID() override;
	bool GetIsGlitchMode() override;
	bool CheckCollision(Rectangle hibox) override;
	void Push(float direction, std::vector<Engine::GameObject*>& objects);
	void SetGround();
	void SetPositionFromHitbox(Rectangle newHitbox);
	bool CanPush(float direction, std::vector<Engine::GameObject*>& objects, const Box* caller = nullptr);

	static void ResolveCollisions(std::vector<Engine::GameObject*>& objects);

private:
	Vector2 position;
	Vector2 velocity = { 0, 0 };
	Rectangle hitbox;
	ObjectID::ID id;
	bool isGlitchMode = false;
	Texture2D texture;

	static constexpr int SIZE = 64;
	static constexpr float PUSH_SPEED = 150.0f;
	static constexpr int GRAVITY = 500;
};
