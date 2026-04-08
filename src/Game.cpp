#include "Game.h"

constexpr int windowWidth = tileSize * 16;
constexpr int windowHeight = tileSize * 10;

Game::Game() {
    m_player = Player(0, 0);
    m_world = World();
    m_engine = Engine(windowWidth, windowHeight, "Green Void");
}

Game::~Game() {

}

bool Game::init() {
    if (!m_engine.init()) {
        return false;
    }

    for (auto& tile : m_world.getTiles()) {
        m_engine.addRenderable(&tile);
    }

    m_engine.addRenderable(&m_player);

    return true;
}

void Game::run() {
    while (m_engine.isRunning()) {
        if (m_engine.isKeyPressed(SDLK_w)) {
            m_engine.camera.move(0, -1);
            m_player.move(-1, -1);
        }
        if (m_engine.isKeyPressed(SDLK_s)) {
            m_engine.camera.move(0, 1);
            m_player.move(1, 1);
        }
        if (m_engine.isKeyPressed(SDLK_a)) {
            m_engine.camera.move(-1, 0);
            m_player.move(-1, 1);
        }
        if (m_engine.isKeyPressed(SDLK_d)) {
            m_engine.camera.move(1, 0);
            m_player.move(1, -1);
        }
        m_engine.tick();
    }
}
