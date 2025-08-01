#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	pos_ = { static_cast<float>(kWindowSize.x / 3 * 2), static_cast<float>(kWindowSize.y / 2) };
	hasCollided_ = false; // プレイヤーと衝突したかどうかのフラグ
}

void Enemy::Update()
{
	//移動
	pos_ += speed_;

	if (pos_.x < posX_limit.x || pos_.x > posX_limit.y) {
		speed_.x *= -1;
	}
	if (pos_.y < posY_limit.x || pos_.y > posY_limit.y) {
		speed_.y *= -1;
	}

	// プレイヤーと衝突
	if (player_ && isConflictPlayer(player_) && !player_->IsInvincible()) {
		player_->TakeDamage();
	}

	// プレイヤーの弾との当たり判定
	if (player_) {
		auto& bullets = player_->GetBulletManager().GetBullets();
		for (auto& bullet : bullets) {
			if (isConflictBullet(bullet)) {
				bullet.Deactivate();       
				player_->AddScore(200);   
			}
		}
	}
	
}

void Enemy::Draw()
{
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), size, size, 0.0, WHITE, kFillModeSolid);
}
// プレイヤーとの当たり判定
bool Enemy::isConflictPlayer(const Player* player)
{
	const float pPlusE = static_cast<float>(player->size / 2 + this->size);		
	const auto p2eDelta = player->pos_ - this->pos_;
	return (hypotf(p2eDelta.x, p2eDelta.y) <= pPlusE);
}

// 弾との当たり判定
bool Enemy::isConflictBullet(const Bullet& bullet)
{
	const float bPlusE = static_cast<float>(bullet.size_ + this->size);
	const auto b2eDelta = bullet.pos_ - this->pos_;
	return (hypotf(b2eDelta.x, b2eDelta.y) <= bPlusE);
}


