#pragma once
#include <SDL.h>
#include <string>

class Renderable {
public:
    Renderable(int x, int y, int w, int h, std::string texHandle);

    void setTextureHandle(std::string handle);
    std::string getTextureHandle();
    SDL_Rect getRect();

private:
    std::string m_texHandle;
    int m_x;
    int m_y;
    int m_w;
    int m_h;
};