//
// Created by User on 09.05.2023.
//

#include "SwagBall.h"

SwagBall::~SwagBall() {

}

SwagBall::SwagBall(sf::RenderWindow & window) {
    this->initShape(window);
}

void SwagBall::initShape(sf::RenderWindow & window) {
    this->shape.setRadius(static_cast<float>((rand()%25)+5));
    sf::Color color((rand()%255)+1,(rand() %255)+1,(rand()%255)+1);
    this->shape.setFillColor(color);
    this->shape.setPosition(sf::Vector2f(
            static_cast<float>(rand()%window.getSize().x),
            static_cast<float>(rand()%window.getSize().y))
            );
}

void SwagBall::update() {

}

void SwagBall::render(sf::RenderTarget &target) {
    target.draw(this->shape);
}

const sf::CircleShape &SwagBall::getShape() const {
    return this->shape;
}
