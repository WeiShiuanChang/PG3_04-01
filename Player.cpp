#include "Player.h"
#include<algorithm>


Player::Player(){}

Player::~Player(){
}

void Player::Init()
{
	pos_.x = 200;
	pos_.y = 350;

	hp = 5;
	score = 0;
}

void Player::Update()
{
	// 位置制限
	this->pos_.x = std::clamp(this->pos_.x, this->posX_limit.x, this->posX_limit.y);
	this->pos_.y = std::clamp(this->pos_.y, this->posY_limit.x, this->posY_limit.y);

	// 無敵時間の更新
	if (invincibleTimer_ > 0.0f) {
		invincibleTimer_ -= 1.0f / 60.0f; 
		if (invincibleTimer_ < 0.0f) invincibleTimer_ = 0.0f;
	}
	// 弾の発射クールダウンの更新
	if (shootCooldown_ > 0.0f) {
		shootCooldown_ -= 1.0f / 60.0f;
		if (shootCooldown_ < 0.0f) shootCooldown_ = 0.0f;
	}

	bulletManager_.Update();

}

void Player::Draw()
{
	for (int i = 0; i < hp; i++) {
		Novice::DrawBox(15 + i * 40, 20, 20, 20, 0.0f, 0xff8c00ff, kFillModeSolid);
	}
	Novice::DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), size, size, 0.0f, 0xff8c00ff, kFillModeSolid);

	bulletManager_.Draw();
}

void Player::MoveRight()
{
	this->pos_.x += this->speed_;
}

void Player::MoveLeft()
{
	this->pos_.x -= this->speed_;
}

void Player::MoveUp()
{
	this->pos_.y -= this->speed_;
}

void Player::MoveDown()
{
	this->pos_.y += this->speed_;
}

void Player::Shoot()
{
	if (shootCooldown_ > 0.0f) {
		return; // クールダウン中は発射できない
	}
	// 弾の速度と初期位置を設定
	float  bulletSpeed = 7.0f;
	Vec2<float>  bulletPos = pos_;
	bulletPos.x += size / 2.0f - 5;
	bulletPos.y += size / 2.0f;
	// 弾を追加
	bulletManager_.AddBullet(bulletPos, bulletSpeed);
}

void Player::TakeDamage()
{
	if (invincibleTimer_ <= 0.0f) {
		hp -= 1;
		invincibleTimer_ = kInvincibleDuration_;
	}
}

bool Player::IsInvincible() const
{
	return invincibleTimer_ > 0.0f;
}

BulletManager& Player::GetBulletManager()
{
	return bulletManager_;
}

void Player::AddScore(int points)
{
	score += points;
}




