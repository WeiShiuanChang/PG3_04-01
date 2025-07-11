#pragma once
#include <Novice.h>

enum SCENE {TITLE, STAGE, ENDING};

class IScene {
protected:
	static int sceneNo;
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	int GetSceneNo();
};