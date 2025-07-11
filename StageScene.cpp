#include "StageScene.h"

void StageScene::Init() {
    // 初期化，例如初始化玩家、敵人等
}

void StageScene::Update() {
    // 按下 ESC 鍵進入 ENDING
    if (Novice::CheckHitKey(DIK_ESCAPE)) {
        sceneNo = ENDING;
    }
}

void StageScene::Draw() {
    Novice::ScreenPrintf(100, 100, "Stage Scene");
    Novice::ScreenPrintf(100, 120, "Press ESC to go to Ending");
}
