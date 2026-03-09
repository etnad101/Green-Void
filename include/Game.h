#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "Renderable.h"

class Game {
public:
    Game(int width = 800, int height = 600, const std::string& title = "Green Void");
    ~Game();


    bool init();

    void run();

    void clean();

    bool isRunning() const { return m_running; }

private:
    void initTextures();

    void render();

private:
    int m_width;
    int m_height;
    std::string m_title;

    SDL_Window* m_window;
    std::shared_ptr<SDL_Renderer> m_renderer;

    TextureManager m_textureManager;
    std::vector<Renderable> m_renderables;

    bool m_running;
};
