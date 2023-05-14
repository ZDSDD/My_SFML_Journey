//
// Created by User on 14.05.2023.
//

#ifndef GAME3_GAME_H
#define GAME3_GAME_H
#include <Sfml/Graphics.hpp>
#include <iostream>
#include "Player.h"
class Game {
private:

    sf::RenderWindow* window;

    //Player
    Player * player;
    //Private functions
    void initWindow();
    void initPlayer();
public:
    Game();

    virtual ~Game();

    void run();

    void update();
    void render();
};


#endif //GAME3_GAME_H
