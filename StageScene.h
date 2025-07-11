#pragma once
#include "Enemy.h"
#include "Player.h"
#include "IScene.h"


class StageScene :public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;
};