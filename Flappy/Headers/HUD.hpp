//
// Created by User on 24.06.2023.
//

#ifndef FLAPPY_HUD_HPP
#define FLAPPY_HUD_HPP

#include "DEFINITIONS.hpp"
#include "Game.hpp"

class HUD {
public:
    HUD( GameDataRef data);

    void draw();
    void updateScore(int score);
private:
    GameDataRef _data;
    sf::Text _scoreText;
};


#endif //FLAPPY_HUD_HPP
