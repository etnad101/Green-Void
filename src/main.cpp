#include <Engine.h>
#include <Tile.h>
#include <Player.h>


constexpr int windowWidth = tileSize * 16;
constexpr int windowHeight = tileSize * 10;

int main(int argc, char* argv[]) {
    Engine engine(windowWidth, windowHeight, "Green Void");

    if (!engine.init()) {
        return 1;
    }

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            engine.addRenderable(Tile(x, y, TileType::GRASS));
        }
    }

    engine.m_player = Player(0, 0);

    engine.run();

    return 0;
}
