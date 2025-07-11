#pragma once
#include "Bullet.h"

struct Vector2 {
	float x;
	float y;
};

class Enemy {
	Vector2 pos;
	float speed;
	int isAlive;
	int respawnTimer;
};