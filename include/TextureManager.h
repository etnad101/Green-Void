#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <memory>
#include <string>

class TextureManager {
public:
    TextureManager();
    TextureManager(std::shared_ptr<SDL_Renderer> renderer);
    ~TextureManager();

    bool loadTexture(std::string id, std::string path);
    SDL_Texture* getTexture(std::string id);

private:
    std::shared_ptr<SDL_Renderer> m_renderer;
    std::unordered_map<std::string, SDL_Texture*> m_textures;
};
