#include "EndingScene.h"

void EndingScene::Init() {
    // 
}

void EndingScene::Update() {
 
    if (Novice::CheckHitKey(DIK_BACK)) {
        sceneNo = TITLE;
    }
}

void EndingScene::Draw() {
    Novice::ScreenPrintf(100, 100, "Ending Scene");
    Novice::ScreenPrintf(100, 120, "Press BACK SPACE to go back to Title");
}

