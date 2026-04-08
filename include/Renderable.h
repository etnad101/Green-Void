#pragma once
#include <SDL.h>
#include <string>

class Renderable {
  public:
    Renderable(float x, float y, int w, int h, std::string texHandle);

    void setTextureHandle(std::string handle);
    std::string getTextureHandle() const;
    SDL_Rect getRect() const;

    inline float getX() const { return m_x; }
    inline float getY() const { return m_y; }
    inline float getW() const { return m_w; }
    inline float getH() const { return m_h; }

  protected:
    float m_x;
    float m_y;

  private:
    std::string m_texHandle;
    float m_w;
    float m_h;
};
