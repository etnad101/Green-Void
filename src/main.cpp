#include <Game.h>
#include <iostream>

int main(int argc, char* argv[]) {
    Game game(800, 600, "Green Void");
    if (!game.init()) {
        return 1;
    }

    game.run();

    return 0;
}
