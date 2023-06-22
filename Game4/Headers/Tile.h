//
// Created by User on 18.06.2023.
//

#ifndef GAME4_TILE_H
#define GAME4_TILE_H
#include "Game.h"

class Tile {
private:
    sf::Sprite sprite;
    bool damaging;

public:
    Tile(sf::Texture & texture, sf::IntRect texture_rect, bool damaging = false);
    virtual ~Tile();
    sf::FloatRect getGlobalBounds()const;

    void update();
    void render(sf::RenderTarget & renderTarget);
};


#endif //GAME4_TILE_H
