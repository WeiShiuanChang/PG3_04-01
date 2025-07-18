#include "StageScene.h"

StageScene::StageScene()
{
}

void StageScene::Update() {
    iCommand_ = inputHandler_->HandleInput();

    if (this->iCommand_) {
        iCommand_->Exec(*player_);
    }

    player_->Update();


    if (Novice::CheckHitKey(DIK_RETURN)) {
        sceneNo = ENDING;
    }
}

void StageScene::Draw() {
    Novice::ScreenPrintf(100, 100, "Stage Scene");
    Novice::ScreenPrintf(100, 120, "Press ENTER to EndingScene");

    player_->Draw();
}