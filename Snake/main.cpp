#include "Game.h"

int main() {

    srand(time(nullptr));

    Game game(25,25);

    game.run();


    return 0;
}
