#include "Source Files/Game.h"

int main() {

    //init srand
    srand(static_cast<unsigned>(time(nullptr)));
    Game game;
    while(game.isRunning() && !game.getEndGame()){

        game.update();

        game.render();
    }

    return 0;
}
