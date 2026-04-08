#pragma once
#include "Renderable.h"
#include <string>

constexpr int tileSize = 64;

enum class TileType {
    GRASS,
};

class Tile : public Renderable {
  public:
    Tile(float x, float y, TileType type)
        : Renderable(x, y, tileSize, tileSize, TypeToTextureHandle(type)), m_type(type) {};

  private:
    std::string TypeToTextureHandle(TileType type);

  private:
    TileType m_type;
};
