#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager()
{
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[ENDING] = std::make_unique<EndingScene>();

	currentSceneNo_ = STAGE;
}

GameManager::~GameManager(){}

