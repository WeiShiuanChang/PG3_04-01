#pragma once

struct Vector2 {
	float x;
	float y;
};

class Bullet {
	Vector2 pos;
	float speed;
	bool isShoot;
};