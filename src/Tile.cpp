#include "Tile.h"
#include <string>
#include "Renderable.h"

std::string Tile::TypeToTextureHandle(TileType type) {
    switch (type) {
        case TileType::GRASS:
            return "grass_tile";
        default:
            return "";
    }
};
