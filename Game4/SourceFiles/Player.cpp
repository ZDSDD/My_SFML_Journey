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

void Player::initTexture() {
    this->textureSheet.loadFromFile("Textures/player_sheet.png");
}

void Player::initSprite() {
    this->sprite.setTexture(this->textureSheet);
    this->currentFrame = sf::IntRect(0,0,32,64);
    this->sprite.setTextureRect(currentFrame);
}

void Player::updateMovement() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))// left
        this->sprite.move(-5.f,0.f);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // right
        this->sprite.move(5.f,0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) // up
        this->sprite.move(0.f,-5.f);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) // down
        this->sprite.move(0.f,5.f);
}

void Player::update() {
    this->updateMovement();
}

void Player::render(sf::RenderTarget &renderTarget) {
    renderTarget.draw(this->sprite);
}
