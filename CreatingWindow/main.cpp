#include <iostream>
#include "Source Files/Game.h"

int main() {

    Game game;

    while(game.isRunning()){

        game.update();

        game.render();
    }

    return 0;
}
