#include "Player.h"

void Player::setSpeed(float speed) { m_speed = speed; }

void Player::move(int xDir, int yDir, float deltaTime) {
    m_x += m_speed * xDir * deltaTime;
    m_y += m_speed * yDir * deltaTime;
}
