#pragma once

class Camera {
public:
    Camera();
    Camera(int x, int y);

    inline int getX() const { return m_x; }
    inline int getY() const { return m_y; }

    void move(int x, int y);
private:
    int m_x = 0;
    int m_y = 0;
};
