#pragma once
#include "Enemy.h"
#include "Player.h"

class StageScene :public IScene {
public:
	void init() override;
	void update() override;
	void draw() override;
};