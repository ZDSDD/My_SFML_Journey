//
// Created by User on 14.05.2023.
//

#ifndef GAME3_PLAYER_H
#define GAME3_PLAYER_H

#include <Sfml/Graphics.hpp>

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;
    //Private functions

    void initTexture();
    void initSprite();
public:
    Player();

    virtual ~Player();

    ///     Functions     ////

    void move(float dirX, float dirY);

    void update();

    void render(sf::RenderTarget &renderTarget);
};


#endif //GAME3_PLAYER_H
