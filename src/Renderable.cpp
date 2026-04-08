#include "Renderable.h"

Renderable::Renderable(float x, float y, int w, int h, std::string texHandle)
    : m_x(x), m_y(y), m_w(w), m_h(h), m_texHandle(texHandle) {}

void Renderable::setTextureHandle(std::string handle) { m_texHandle = handle; }

std::string Renderable::getTextureHandle() const { return m_texHandle; }

SDL_Rect Renderable::getRect() const {
    SDL_Rect rect;
    rect.x = (int)((m_x - m_y) * m_w / 2);
    rect.y = (int)((m_x + m_y) * m_h / 4);
    rect.w = (int)m_w;
    rect.h = (int)m_h;

    return rect;
}
