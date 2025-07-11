#include "TitleScene.h"

void TitleScene::Init() {
    // èâä˙âªô|óù
}

void TitleScene::Update()
{
    if (Novice::CheckHitKey(DIK_SPACE)) {
        sceneNo = STAGE;
    }
}

void TitleScene::Draw() {
    Novice::ScreenPrintf(100, 100, "Title Scene");
    Novice::ScreenPrintf(100, 120, "Press SPACE to start");
}