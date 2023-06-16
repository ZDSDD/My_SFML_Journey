//
// Created by User on 16.06.2023.
//

#include "../Headers/Player.h"

Player::Player() {
    initTexture();
    initSprite();
}

Player::~Player() {

}

void Player::update() {

}

void Player::render(sf::RenderTarget &renderTarget) {
    renderTarget.draw(this->sprite);
}

void Player::initSprite() {

}

void Player::initTexture() {

}
