#pragma once
#include <Novice.h>
#include "Vector2.h"
#include <vector>
#include "Bullet.h"

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw();

	// 移動処理
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void Shoot();

	void TakeDamage();  
	bool IsInvincible() const;  // 無敵状態

	// 弾のマネージャーを取得
	BulletManager& GetBulletManager(); 

	void AddScore(int points);

	int hp = 5;
	int score = 0;
	int size = 50;
	Vec2<float> pos_ = { 200.0f, 350.0f };

	// 弾の管理クラス
	BulletManager bulletManager_;

private:
	float invincibleTimer_ = 0.0f;            // 無敵時間のタイマー
	const float kInvincibleDuration_ = 1.0f;  // 無敵状態の継続時間（秒）
	
	const float speed_ = 5.0f;

	// 移動可能な範囲
	Vec2<int> kWindowSize = { 1280, 720 };
	Vec2<float> posX_limit = { 0, static_cast<float>(kWindowSize.x - 100.0f) };
	Vec2<float> posY_limit = { 0, static_cast<float>(kWindowSize.y / 10 * 9 - size) };

	float shootCooldown_ = 0.0f; // 弾のクールダウン
	const float kShootCooldownTime_ = 0.25f; //弾を連射できる間隔（秒）

	// 弾の届く最大距離
	float bullet_reach = static_cast<float>(kWindowSize.x);
};
