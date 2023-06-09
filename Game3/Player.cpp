//
// Created by User on 14.05.2023.
//

#include <iostream>
#include "Player.h"

Player::Player() {

    this->movementSpeed = 5.f;
    this->initTexture();
    this->initSprite();
    this->initVariables();
}

Player::~Player() {

}

////  public  Functions ////
void Player::update() {
    this->updateAttack();
}

void Player::render(sf::RenderTarget &renderTarget) {
    renderTarget.draw(this->sprite);
}

////  private functions ////
void Player::initTexture() {
    //set the texture to the sprite
    if (!this->texture.loadFromFile("textures/ship.png")) {
        std::cout << "Couldn't load ship.png texture\n";
    } else {
        std::cout << "ship.png texture loaded successfully\n";
    }
}

void Player::initSprite() {
    //Load a texture from file
    this->sprite.setTexture(this->texture);

    //resize the sprite
    this->sprite.scale(0.07f, 0.07f);
}

void Player::move(const float dirX, const float dirY) {
    this->sprite.move(dirX * this->movementSpeed,
                      dirY * this->movementSpeed);
}

const sf::Vector2f &Player::getPos() const {
    return this->sprite.getPosition();
}

void Player::updateAttack() {
    if (this->attackCooldown < this->attackCooldownMax)
        this->attackCooldown += 1.f;
}

bool Player::canAttack() {
    if (this->attackCooldown >= attackCooldownMax) {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::initVariables() {
    this->hpMax = 10;
    this->hp = hpMax;
    this->movementSpeed = 5.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
}

sf::FloatRect Player::getBounds() const {
    return this->sprite.getGlobalBounds();
}

void Player::setPosition(const sf::Vector2f pos) {
    this->sprite.setPosition(pos.x, pos.y);
}

void Player::setPosition(float x, const float y) {
    this->sprite.setPosition(x, y);
}

void Player::setHp(const int &value) {
    this->hp = value;
}

void Player::loseHp(const int &value) {
    this->hp -= value;
    if (this->hp < 0) {
        this->hp = 0;
    }
}
