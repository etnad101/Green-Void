#include "TextureManager.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <string>

TextureManager::TextureManager()
: m_renderer(nullptr) {}

TextureManager::TextureManager(std::shared_ptr<SDL_Renderer> renderer)
: m_renderer(renderer) {}

TextureManager::~TextureManager() {
    for (auto [id, tex] : m_textures) {
        SDL_DestroyTexture(tex);
    }
}

bool TextureManager::loadTexture(std::string id, std::string path) {
    std::cout << "Loading texture '" << id << "' from '" << path << "'\n";

    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedImage = IMG_Load(path.c_str());
    if (loadedImage == nullptr) {
        std::cerr << "IMG_Load Error: " << IMG_GetError() << std::endl;
        return false;
    }

    if (!m_renderer.get()) {
        std::cerr << "bombo" << std::endl;
        return false;
    }

    newTexture = SDL_CreateTextureFromSurface(m_renderer.get(), loadedImage);
    if (newTexture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_FreeSurface(loadedImage);

    m_textures.insert({id, newTexture});

    return true;
}

SDL_Texture* TextureManager::getTexture(std::string id) {
    return m_textures.at(id);
}
