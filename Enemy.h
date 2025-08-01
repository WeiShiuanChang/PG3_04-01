#pragma once
#include <algorithm>
#include <Novice.h>
#include "Player.h"
#include <stdlib.h> 

class Enemy
{
public:
	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw();

	int size = 50;

	// プレイヤーの参照を設定する
	void SetPlayer(Player* player) { player_ = player; }

	// 当たり判定
	bool isConflictPlayer(const Player* player);
	bool isConflictBullet(const Bullet& bullet);

private:
	Vec2<float> pos_{};
	Vec2<float> speed_ = { -5.0f, -7.0f };
	// 移動範囲
	const Vec2<int> kWindowSize = { 1280, 720 };
	Vec2<float> posX_limit = { static_cast<float>(size), static_cast<float>(kWindowSize.x - size) };
	Vec2<float> posY_limit = { static_cast<float>(size), static_cast<float>(kWindowSize.y / 10 * 9 - size) };

	Player* player_ = nullptr;
	Bullet* bullet_ = nullptr;

	// プレイヤーと衝突済みかどうか
	bool hasCollided_ = false;
};