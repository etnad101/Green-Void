#include "Game.h"

constexpr int windowWidth = tileSize * 16;
constexpr int windowHeight = tileSize * 10;

Game::Game() {
    m_player = Player(0, 0);
    m_world = World();
    m_engine = Engine(windowWidth, windowHeight, "Green Void");
}

Game::~Game() {}

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
        float deltaTime = m_engine.getDeltaTime();

        if (m_engine.isKeyPressed(SDLK_w)) {
            m_player.move(-1, -1, deltaTime);
        }
        if (m_engine.isKeyPressed(SDLK_s)) {
            m_player.move(1, 1, deltaTime);
        }
        if (m_engine.isKeyPressed(SDLK_a)) {
            m_player.move(-1, 1, deltaTime);
        }
        if (m_engine.isKeyPressed(SDLK_d)) {
            m_player.move(1, -1, deltaTime);
        }

        m_engine.camera.follow(m_player);
        m_engine.tick();
    }
}
