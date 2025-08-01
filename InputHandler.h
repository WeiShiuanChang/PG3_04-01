#pragma once
#include "Command.h"
#include "Novice.h"

class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveUpCommand2PressKeyW();
	void AssignMoveDownCommand2PressKeyS();
	void AssignShootCommand2PressMouse();


private:

	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
	ICommand* pressMouse;
};

