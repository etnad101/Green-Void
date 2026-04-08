#include "Camera.h"

Camera::Camera() {}

Camera::Camera(int x, int y) : m_x(x), m_y(y) {}

void Camera::move(int x, int y) {
    m_x += x;
    m_y += y;
}
