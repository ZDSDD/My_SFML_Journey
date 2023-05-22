//
// Created by User on 21.05.2023.
//

#include "Enemy.h"

Enemy::Enemy(float pos_x, float pos_y, float speed) {
    this->initVariables();
    this->initShape();
    this->shape.setPosition(pos_x,pos_y);
    this->speed = speed;
}

Enemy::~Enemy() {

}

void Enemy::initShape() {
    this->shape.setRadius(rand()%20 + 20);
    this->shape.setPointCount(rand()%3 + 4);
    this->shape.setFillColor(sf::Color(rand()%200+55,rand()%200+55,rand()%255));
}

void Enemy::initVariables() {
    this->type = 0;
    this->hpMax = 10;
    this->hp = hpMax;
    this->damage = 1;
    this->points = 5;

}

void Enemy::update() {
this->shape.move(0.f,this->speed);
this->shape.rotate(0.5f);
}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(this->shape);
}

sf::FloatRect Enemy::getBounds() {
    return this->shape.getGlobalBounds();
}
