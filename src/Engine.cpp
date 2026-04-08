#include "Engine.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "TextureManager.h"

Engine::Engine(int width, int height, const std::string& title)
    : m_width(width), m_height(height), m_title(title) {}

Engine::~Engine() {
    clean();
}

void Engine::initTextures() {
    m_textureManager = TextureManager(m_renderer);

    m_textureManager.loadTexture("test_tile", "./Assets/test_tile.png");
    m_textureManager.loadTexture("grass_tile", "./Assets/grass_tile.png");
    m_textureManager.loadTexture("robot", "./Assets/robot.png");
}

bool Engine::init() {
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

void Engine::addRenderable(const Renderable* r) {
    m_renderables.push_back(r);
}


void Engine::render(const Renderable *r) {
    SDL_Texture* tex = m_textureManager.getTexture(r->getTextureHandle());
    SDL_Rect dst = r->getRect();
    dst.x += (m_width / 2) - 32;

    dst.x -= camera.getX();
    dst.y -= camera.getY();

    SDL_RenderCopy(m_renderer.get(), tex, nullptr, &dst);
}

void Engine::render(std::vector<const Renderable*> renderables) {
    for (auto r : renderables) {
        render(r);
    }
}

bool Engine::isKeyPressed(SDL_Keycode key) const {
    auto it = m_keysPressed.find(key);
    return it != m_keysPressed.end() && it->second;
}

void Engine::tick() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_KEYDOWN:
                m_keysPressed[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                m_keysPressed[event.key.keysym.sym] = false;
                break;
        }
    }

    SDL_SetRenderDrawColor(m_renderer.get(), 0, 0, 0, 255);
    SDL_RenderClear(m_renderer.get());

    render(m_renderables);

    SDL_RenderPresent(m_renderer.get());
}

void Engine::clean() {
    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    SDL_Quit();
    m_running = false;
}
