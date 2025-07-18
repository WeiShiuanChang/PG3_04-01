#include "Player.h"

Player::Player(){}

Player::~Player(){}

void Player::Init()
{
	pos_.x = 600;
	pos_.y = 360;
}

void Player::Update()
{
}

void Player::Draw()
{
	Novice::DrawBox(static_cast<int>(pos_.x), static_cast<int>(pos_.y), 50, 50, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight()
{
	this->pos_.x += this->speed_;
}

void Player::MoveLeft()
{
	this->pos_.x -= this->speed_;
}




