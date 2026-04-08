#pragma once
#include "Renderable.h"

class Camera {
public:
    Camera();
    Camera(int x, int y);

    inline float getX() const { return m_x; }
    inline float getY() const { return m_y; }

    void follow(const Renderable& target);;
private:
    float m_x = 0.0f;
    float m_y = 0.0f;
};
