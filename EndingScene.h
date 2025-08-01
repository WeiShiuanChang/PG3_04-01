#pragma once
#include "IScene.h"
#include "Vector2.h"

class EndingScene :public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

	void SetScore(int score) { score_ = score; }

private:
	int score_ = 0;
	Vec2<int> kWindowSize = { 1280, 720 };

	int gameoverGraph = Novice::LoadTexture("./Resources/gameover.png");

};