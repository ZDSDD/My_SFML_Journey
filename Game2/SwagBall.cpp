//
// Created by User on 09.05.2023.
//

#include "SwagBall.h"

SwagBall::~SwagBall() {

}

SwagBall::SwagBall(sf::RenderWindow &window, int type) : type(type) {
    this->initShape(window);
}

void SwagBall::initShape(sf::RenderWindow &window) {

    sf::Color color;
    switch (this->type) {
        case SwagBallTypes::Default:
            color = sf::Color((rand() % 155) + 1, (rand() % 155) + 1, (rand() % 155) + 1);
            this->shape.setFillColor(color);
            break;
        case SwagBallTypes::Damaging:
            color = sf::Color::Red;
            this->shape.setFillColor(color);
            this->shape.setOutlineColor(sf::Color::Magenta);
            this->shape.setOutlineThickness(2.f);
            break;
        case SwagBallTypes::Healing:
            color = sf::Color::Green;
            this->shape.setFillColor(color);
            this->shape.setOutlineColor(sf::Color::White);
            this->shape.setOutlineThickness(2.f);
            break;
    }
    this->shape.setRadius(static_cast<float>((rand() % 25) + 5));
    this->shape.setFillColor(color);
    this->shape.setPosition(sf::Vector2f(
            static_cast<float>(rand() % window.getSize().x),
            static_cast<float>(rand() % window.getSize().y))
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

const int &SwagBall::getType() const {
    return this->type;
}
