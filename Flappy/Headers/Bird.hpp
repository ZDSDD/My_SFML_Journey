//
// Created by User on 23.06.2023.
//

#ifndef FLAPPY_BIRD_HPP
#define FLAPPY_BIRD_HPP

#include "Game.hpp"
#include "DEFINITIONS.hpp"

class Bird {
public:
    explicit Bird(GameDataRef data);

    void drawBird();

    void animate(float dt);

    void update(float dt);

    void tap();

    const sf::Sprite &getSprite()const;

private:
    GameDataRef _data;

    sf::Sprite _birdSprite;

    std::vector<sf::Texture> _birdFrames;

    unsigned int _animationIterator;

    sf::Clock _clock;

    sf::Clock _movementClock;

    int _birdState;

    float _rotation;

    float acceleration;


};


#endif //FLAPPY_BIRD_HPP
