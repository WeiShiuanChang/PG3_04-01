#pragma once
#include "IScene.h"
#include "InputHandler.h"
#include "Command.h"
#include "Player.h"

class StageScene : public IScene {
public:
	StageScene();

	void Init() override {
		// ���̓n���h���[�̐���
		inputHandler_ = new InputHandler();
		// �R�}���h�����蓖�Ă�
		inputHandler_->AssignMoveRightCommand2PressKeyD();
		inputHandler_->AssignMoveLeftCommand2PressKeyA();

		player_ = new Player();
		player_->Init();
	}
	void Update() override;
	void Draw() override;

private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_;
};