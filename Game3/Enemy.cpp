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
void Enemy::initVariables() {
    this->pointCount = (rand()%8 + 3); //min = 3, max = 10
    this->type = 0;
    this->hpMax = static_cast<int>(pointCount);
    this->hp = this->hpMax;
    this->damage = 1;
    this->points = this->pointCount;

}
void Enemy::initShape() {
    this->shape.setRadius(this->pointCount*3.14);
    this->shape.setPointCount(this->pointCount);
    this->shape.setFillColor(sf::Color(rand()%200+55,rand()%200+55,rand()%255));
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

const int &Enemy::getPoints() const {
    return this->points;
}
