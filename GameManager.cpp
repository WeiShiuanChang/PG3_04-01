#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager()
{
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[ENDING] = std::make_unique<EndingScene>();

	currentSceneNo_ = TITLE;
}

GameManager::~GameManager(){}

int GameManager::Run()
{
	while (Novice::ProcessMessage() == 0){
		Novice::BeginFrame();

		prevSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		sceneArr_[currentSceneNo_]->Update();
		sceneArr_[currentSceneNo_]->Draw();

		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Novice::CheckHitKey(DIK_ESCAPE)) {
			break;
		}
	}
	return 0;
}
