#include "World.h"
#include "Tile.h"

World::World() {
    for (int i = -50; i < 100; i++) {
        for (int j = -50; j < 100; j++) {
            m_tiles.push_back(Tile(i, j, TileType::GRASS));
        }
    }
}

World::~World() {

}

std::vector<Tile>& World::getTiles() {
    return m_tiles;
}
