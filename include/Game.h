#pragma once
#include "Player.h"
#include "Engine.h"
#include "World.h"

class Game {
public:
    Game();
    ~Game();

    bool init();
    void run();

private:
    Engine m_engine;
    Player m_player;
    World m_world;
};
