#pragma once
#include "IScene.h"
#include "InputHandler.h"
#include "Command.h"
#include "Player.h"
#include "Enemy.h"

class StageScene : public IScene {
public:
	StageScene();

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_;
	Enemy* enemy_;
	Vec2<int> kWindowSize = { 1280, 720 };
};