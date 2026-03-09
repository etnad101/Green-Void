#include "Renderable.h"
#include "SDL.h"

Renderable::Renderable(int x, int y, int w, int h, std::string texHandle)
: m_x(x), m_y(y), m_w(w), m_h(h), m_texHandle(texHandle) {}

void Renderable::setTextureHandle(std::string handle) {
    m_texHandle = handle;
}

std::string Renderable::getTextureHandle() {
    return m_texHandle;
}

SDL_Rect Renderable::getRect() {
    SDL_Rect rect;
    rect.x = m_x;
    rect.y = m_y;
    rect.w = m_w;
    rect.h = m_h;

    return rect;
}