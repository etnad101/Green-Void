#include "Player.h"

void Player::move(int xDir, int yDir) {
    m_x += m_speed * xDir;
    m_y += m_speed * yDir;
}
