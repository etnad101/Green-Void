#pragma once
#include "Tile.h"
#include <vector>

class World {
  public:
    World();
    ~World();

    std::vector<Tile>& getTiles();

  private:
    std::vector<Tile> m_tiles;
};
