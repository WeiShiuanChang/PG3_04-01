#pragma once
#include "IScene.h"

class EndingScene :public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;
};