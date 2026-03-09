#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>
#include "TextureManager.h"

class Game {
public:
    Game(int width = 800, int height = 600, const std::string& title = "Green Void");
    ~Game();

    void initTextures();

    bool init();

    void run();

    void clean();

    bool isRunning() const { return m_running; }

private:
    int m_width;
    int m_height;
    std::string m_title;

    SDL_Window* m_window;
    std::shared_ptr<SDL_Renderer> m_renderer;
    TextureManager m_textureManager;

    bool m_running;
};
