//
// Created by User on 17.05.2023.
//

#ifndef GAME3_BULLET_H
#define GAME3_BULLET_H
#include <SFML/Graphics.hpp>

class Bullet {
private:
    sf::Sprite shape;

    sf::Vector2f direction;
    float movementSpeed;



public:
    Bullet(sf::Texture* texture, float pos_x, float pos_y, float _dirX, float _dirY, float movementSpeed);
    virtual ~Bullet();

    void update();
    void render(sf::RenderTarget & target);

    //accessors
    sf::FloatRect getBounds()const;

};


#endif //GAME3_BULLET_H
