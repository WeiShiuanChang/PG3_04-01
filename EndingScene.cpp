#include "EndingScene.h"
#include "Player.h"

void EndingScene::Init() {
    // 
}

void EndingScene::Update() {
 
    if (Novice::CheckHitKey(DIK_R)) {
        sceneNo = TITLE;
    }
}

void EndingScene::Draw() {
    Novice::DrawBox(0, 0, kWindowSize.x, kWindowSize.y, 0.0f, 0x191970ff, kFillModeSolid);
    Novice::DrawSprite((kWindowSize.x -505)/2, kWindowSize.y / 3, gameoverGraph, 1.0f, 1.0f, 0.0f, WHITE);
    Novice::ScreenPrintf(kWindowSize.x / 4 + 220, kWindowSize.y / 3 + 200, "Press [R] key to return");
}

