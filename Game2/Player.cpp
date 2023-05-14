//
// Created by User on 09.05.2023.
//

#include "Player.h"

void Player::initVariables() {
    this->movementSpeed = 9.f;
    this->hpMax = 3;
    this->hp = hpMax;
}

void Player::initShape() {
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(33.f, 33.f));
}

Player::~Player() {

}

Player::Player(float x, float y) {

    this->shape.setPosition(x, y);
    initVariables();
    initShape();
}


void Player::update(const sf::RenderTarget *target) {


    //Keyboard input
    this->updateInput();
    //Window bounds collision
    this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

void Player::updateInput() {

    ////     LEFT and RIGHT  ////

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->shape.move(-this->movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->shape.move(this->movementSpeed, 0.f);
    }
    ////     UP and DOWN    ////

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->shape.move(0.f, -this->movementSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        this->shape.move(0.f, this->movementSpeed);
    }
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget *target) {
    //Left
    sf::Vector2f playerPos = this->shape.getPosition();
    if (this->shape.getGlobalBounds().left <= 0.f) {
        this->shape.setPosition(0.f, playerPos.y);
    }
    //Right
    if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x) {
        this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width,
                                this->shape.getGlobalBounds().top);
    }
    //Top
    if (this->shape.getGlobalBounds().top <= 0.f) {
        this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
    }
    //Bottom
    if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y) {
        this->shape.setPosition(this->shape.getGlobalBounds().left,
                                target->getSize().y - this->shape.getGlobalBounds().height);
    }
}


void Player::takeDamage(const int &dmg) {
    if (this->hp > dmg) {
        this->hp -= dmg;
    } else {
        hp = 0;
    }
}

void Player::takeHeal(const int &heal) {
    if (this->hp + heal < this->hpMax) {
        this->hp += heal;
    } else {
        this->hp = hpMax;
    }
}
