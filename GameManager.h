#pragma once
#include <memory>
#include "IScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "EndingScene.h"

class GameManager {
private:
	std::unique_ptr<IScene> sceneArr_[3];
	int currentSceneNo_;
	int prevSceneNo_;

public:
	GameManager();
	~GameManager();

	int Run()
	{
		while (Novice::ProcessMessage() == 0) {
			Novice::BeginFrame();

			prevSceneNo_ = currentSceneNo_;
			currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

			if (prevSceneNo_ != currentSceneNo_) {
				sceneArr_[currentSceneNo_]->Init();
			}

			sceneArr_[currentSceneNo_]->Update();
			sceneArr_[currentSceneNo_]->Draw();

			Novice::EndFrame();
		}
		return 0;
	}

};
