#include "TitleScene.h"

void TitleScene::Init() {
    // 
}

void TitleScene::Update()
{
    if (Novice::CheckHitKey(DIK_RETURN)) {
        sceneNo = STAGE;
    }
}

void TitleScene::Draw() {
    Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight, 0.0f, 0x191970ff, kFillModeSolid);
    Novice::DrawSprite(kWindowWidth / 4, kWindowHeight / 3, titleGraph, 1.0f, 1.0f, 0.0f, WHITE);
    Novice::ScreenPrintf(kWindowWidth / 4 + 200, kWindowHeight / 3 + 200, "Press [ENTER] key to start");
}