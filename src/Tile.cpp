#include "Tile.h"
#include <string>

std::string Tile::TypeToTextureHandle(TileType type) {
    switch (type) {
    case TileType::GRASS:
        return "grass_tile";
    default:
        return "";
    }
};
