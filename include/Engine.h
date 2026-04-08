#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <unordered_map>
#include <vector>
#include "Camera.h"
#include "TextureManager.h"
#include "Renderable.h"

class Engine {
public:
    Engine(int width = 800, int height = 600, const std::string& title = "Green Void");
    ~Engine();

    bool init();

    void tick();

    void clean();

    bool isRunning() const { return m_running; }

    void addRenderable(const Renderable *r);

    bool isKeyPressed(SDL_Keycode key) const;

public:
    Camera camera;

private:
    void initTextures();

    void render(const Renderable* r);
    void render(std::vector<const Renderable*> renderables);

private:
    int m_width;
    int m_height;
    std::string m_title;

    SDL_Window* m_window = nullptr;
    std::shared_ptr<SDL_Renderer> m_renderer = nullptr;

    TextureManager m_textureManager;
    std::vector<const Renderable*> m_renderables;

    std::unordered_map<SDL_Keycode, bool> m_keysPressed;

    bool m_running = false;
};
