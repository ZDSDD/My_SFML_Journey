//
// Created by User on 21.05.2023.
//

#include "Enemy.h"

Enemy::Enemy(float pos_x, float pos_y) {
    this->initVariables();
    this->initShape();
    this->shape.setPosition(pos_x,pos_y);
}

Enemy::~Enemy() {

}

void Enemy::initShape() {
    this->shape.setRadius(rand()%20 + 20);
    this->shape.setPointCount(rand()%3 + 4);
}

void Enemy::initVariables() {
    this->type = 0;
    this->hpMax = 10;
    this->hp = hpMax;
    this->damage = 1;
    this->points = 5;
}

void Enemy::update() {

}

void Enemy::render(sf::RenderTarget &target) {
    target.draw(this->shape);
}
