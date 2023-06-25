//
// Created by User on 23.06.2023.
//

#ifndef FLAPPY_LAND_HPP
#define FLAPPY_LAND_HPP

#include "Game.hpp"

class Land {
private:
    GameDataRef _data;
    std::vector<sf::Sprite> _landSprite;
public:
    explicit Land(GameDataRef data);
    virtual ~Land() = default;

    void moveLand(float dt);

    void drawLand();

    const std::vector<sf::Sprite> &GetSprite() const;

};


#endif //FLAPPY_LAND_HPP
