//
// Created by User on 17.05.2023.
//

#include "Bullet.h"

Bullet::Bullet(sf::Texture* texture, float pos_x, float pos_y, float _dirX, float _dirY, float movementSpeed)
:movementSpeed(movementSpeed), direction(_dirX,_dirY)
{
    this->shape.setTexture(*texture);
    this->shape.setPosition(pos_x,pos_y);
}

Bullet::~Bullet() {

}

void Bullet::update() {
    //movement
    this->shape.move(this->movementSpeed*this->direction);
}

void Bullet::render(sf::RenderTarget &target) {
target.draw(this->shape);
}

sf::FloatRect Bullet::getBounds() const {
    return this->shape.getGlobalBounds();
}
