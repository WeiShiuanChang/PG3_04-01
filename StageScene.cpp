#include "StageScene.h"

void StageScene::Init() {
    // 
}

void StageScene::Update() {

    if (Novice::CheckHitKey(DIK_RETURN)) {
        sceneNo = ENDING;
    }
}

void StageScene::Draw() {
    Novice::ScreenPrintf(100, 100, "Stage Scene");
    Novice::ScreenPrintf(100, 120, "Press ENTER to EndingScene");
}