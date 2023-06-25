//
// Created by User on 24.06.2023.
//

#ifndef FLAPPY_FLASH_H
#define FLAPPY_FLASH_H
#include "Game.hpp"
#include "DEFINITIONS.hpp"
class Flash {
private:
    GameDataRef _data;
    sf::RectangleShape _shape;

    bool _flashOn;
public:
    Flash( GameDataRef data );
    void show( float dt );
    void draw();
};


#endif //FLAPPY_FLASH_H
