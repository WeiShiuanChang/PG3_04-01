#include "EndingScene.h"

void EndingScene::Init() {
    // �������C��@���������`��
}

void EndingScene::Update() {
    // �C�ӌ��� TITLE
    if (Novice::CheckHitKey(DIK_SPACE)) {
        sceneNo = TITLE;
    }
}

void EndingScene::Draw() {
    Novice::ScreenPrintf(100, 100, "Ending Scene");
    Novice::ScreenPrintf(100, 120, "Press SPACE to go back to Title");
}