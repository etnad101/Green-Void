#pragma once
#include <SDL.h>
#include <string>

class Renderable {
public:
    Renderable(float x, float y, int w, int h, std::string texHandle);

    void setTextureHandle(std::string handle);
    std::string getTextureHandle();
    SDL_Rect getRect();

protected:
    float m_x;
    float m_y;

private:
    std::string m_texHandle;
    int m_w;
    int m_h;
};