#include "Bullet.h"

Bullet::Bullet(const Vec2<float>& pos, float speed) : pos_(pos), speed_(speed), lifetime_(kMaxLifetime_) {
}

void Bullet::Update() {
    if (!active_) return;

    pos_.x += speed_;

    //有効時間
    lifetime_ -= 1.0f / 60.0f;
    if (lifetime_ <= 0.0f) {
        active_ = false;
    }
}

void Bullet::Draw() const {
    if (!active_) return;

    Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), size_, size_, 0.0, RED, kFillModeSolid);

}

bool Bullet::IsActive() const {
    return active_;
}

// 弾を無効化
void Bullet::Deactivate() {
    active_ = false;
}

// -------- BulletManager --------
void BulletManager::AddBullet(const Vec2<float>& pos,float speed) {
    bullets_.emplace_back(pos, speed);
}

void BulletManager::Update() {
    for (auto& bullet : bullets_) {
        bullet.Update();
    }

    // 無効な弾を削除
    bullets_.erase(
        std::remove_if(bullets_.begin(), bullets_.end(),
            [](const Bullet& b) { return !b.IsActive(); }),
        bullets_.end());
}

void BulletManager::Draw() const {
    for (const auto& bullet : bullets_) {
        bullet.Draw();
    }
}
