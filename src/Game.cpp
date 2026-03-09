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

    int size = 32;
    for (int i = 0; i < m_width / size; i++) {
        for (int j = 0; j < m_height / size; j++) {
            m_renderables.push_back(Renderable(i * size, j * size, size, size, "test_tile"));
        }
    }

    m_running = true;
    return true;
}

void Game::render() {
    for (Renderable r : m_renderables) {
        SDL_Texture* tex = m_textureManager.getTexture(r.getTextureHandle());
        SDL_Rect dst = r.getRect();
        SDL_RenderCopy(m_renderer.get(), tex, nullptr, &dst);
    }
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

        render();

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
