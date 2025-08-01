#include "StageScene.h"
#include "EndingScene.h"

StageScene::StageScene()
{
}

void StageScene::Init()
{
        // 入力ハンドラーの生成
        inputHandler_ = new InputHandler();
        // コマンドを割り当てる
        inputHandler_->AssignMoveRightCommand2PressKeyD();
        inputHandler_->AssignMoveLeftCommand2PressKeyA();
        inputHandler_->AssignMoveUpCommand2PressKeyW();
        inputHandler_->AssignMoveDownCommand2PressKeyS();
        inputHandler_->AssignShootCommand2PressMouse();

        player_ = new Player();
        player_->Init();

        enemy_ = new Enemy();
        enemy_->Init();
        enemy_->SetPlayer(player_);
}


void StageScene::Update() {
    iCommand_ = inputHandler_->HandleInput();

    if (this->iCommand_) {
        iCommand_->Exec(*player_);
    }

    player_->Update();
    enemy_->Update();


    if (Novice::CheckHitKey(DIK_BACK) || player_->hp == 0) {

        sceneNo = ENDING;
    }
}

void StageScene::Draw() {
    //information
    Novice::DrawLine(0, kWindowSize.y/10*9, kWindowSize.x, kWindowSize.y / 10*9, WHITE);
    Novice::ScreenPrintf(50, kWindowSize.y / 10*9 + 20, "Score:%d", player_->score);

    enemy_->Draw();
    player_->Draw();

}