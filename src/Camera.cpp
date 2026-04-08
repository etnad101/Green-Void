#include "Camera.h"

Camera::Camera() {}

Camera::Camera(int x, int y) : m_x(x), m_y(y) {}

void Camera::follow(const Renderable& target) {
    m_x = target.getX();
    m_y = target.getY();
}
