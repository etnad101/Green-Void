#include "World.h"
#include "Tile.h"

World::World() {
    for (int i = -5; i < 10; i++) {
        for (int j = -5; j < 10; j++) {
            m_tiles.push_back(Tile(i, j, TileType::GRASS));
        }
    }
}

World::~World() {}

std::vector<Tile>& World::getTiles() { return m_tiles; }
