#include "Game.h"

int main() {
    srand(time(nullptr));

    //Initialize game objects

    Game game;
    //Game loop
    while(game.running()){
        game.update();
        game.render();
    }

    return 0;
}
