#include "StageScene.h"

void StageScene::Init() {
    // �������C��@���n���߉ƁA�G�l��
}

void StageScene::Update() {
    // �� ESC ���i�� ENDING
    if (Novice::CheckHitKey(DIK_ESCAPE)) {
        sceneNo = ENDING;
    }
}

void StageScene::Draw() {
    Novice::ScreenPrintf(100, 100, "Stage Scene");
    Novice::ScreenPrintf(100, 120, "Press ESC to go to Ending");
}
