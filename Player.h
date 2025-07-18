#pragma once
#include <Novice.h>

struct Vector2 {
	float x;
	float y;
};

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

private:
	Vector2 pos_ = {};
	const float speed_ = 5.0f;
};