#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "TextureManager.h"

Game::Game(int width, int height, const std::string& title)
    : m_width(width), m_height(height), m_title(title),
      m_window(nullptr), m_renderer(nullptr), m_running(false) {}

Game::~Game() {
    clean();
}

void Game::initTextures() {
    m_textureManager = TextureManager(m_renderer);

    m_textureManager.loadTexture("test_tile", "./Assets/test_tile.png");
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    int img_flags = IMG_INIT_PNG;
    if ((IMG_Init(img_flags) & img_flags) == 0) {
        std::cerr << "IMG_Init Error: " << IMG_GetError() << std::endl;
        return false;
    }

    m_window = SDL_CreateWindow(m_title.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                m_width, m_height,
                                SDL_WINDOW_SHOWN);
    if (!m_window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }


    m_renderer = std::shared_ptr<SDL_Renderer>(
        SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer
    );

    if (!m_renderer.get()) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    initTextures();

    m_running = true;
    return true;
}

void Game::run() {
    SDL_Event event;

    while (m_running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                m_running = false;
            }
        }

        SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
        SDL_RenderClear(m_renderer.get());

        SDL_Rect dst;
        dst.x = 0;
        dst.y = 0;
        dst.w = 32;
        dst.h = 32;

        SDL_RenderCopy(m_renderer.get(), m_textureManager.getTexture("test_tile"), nullptr, &dst);

        SDL_RenderPresent(m_renderer.get());
    }
}

void Game::clean() {
    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    SDL_Quit();
    m_running = false;
}
