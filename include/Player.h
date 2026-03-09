#pragma once
#include "Renderable.h"

constexpr int playerWidth = 64;
constexpr int playerHeight = 80;

class Player : public Renderable {
public:
    Player() : Renderable(0, 0, playerWidth, playerHeight, "robot"){};
    Player(float x, float y) : Renderable(x, y, playerWidth, playerHeight, "robot"){};
    
    void move(int xDir, int yDir);

private:
    float m_speed = 0.001;

};