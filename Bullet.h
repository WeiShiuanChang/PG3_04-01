#pragma once
#include <vector>
#include "Vector2.h"
#include "Novice.h"

class Bullet {
public:
    Bullet(const Vec2<float>& pos,  float speed);

    void Update();
    void Draw() const;
    bool IsActive() const;
    void Deactivate();

    Vec2<float>  GetPosition() const { return pos_; }
    int GetSize() const { return size_; }

    int size_ = 10;
    Vec2<float>  pos_;

private:

    float  speed_;
    float lifetime_;
    static constexpr float kMaxLifetime_ = 2.0f; // 生存2秒
   
    bool active_ = true;
};

// 複数弾のコンテナクラス
class BulletManager {
public:
    void AddBullet(const Vec2<float>& pos, float speed);
    void Update();
    void Draw() const;

    std::vector<Bullet>& GetBullets() { return bullets_; }

private:
    std::vector<Bullet> bullets_;
};
