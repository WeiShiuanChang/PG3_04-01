#pragma once
#include "IScene.h"
#include "StageScene.h"

class TitleScene :public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	int kWindowWidth = 1280;
	int kWindowHeight = 720;

	int titleGraph = Novice::LoadTexture("./Resources/title.png");

};