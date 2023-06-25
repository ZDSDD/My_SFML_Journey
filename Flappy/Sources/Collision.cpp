//
// Created by User on 23.06.2023.
//

#include "Collision.hpp"

Collision::Collision() = default;

bool Collision::CheckSpriteCollision(const sf::Sprite &sprite1, const sf::Sprite &sprite2) {
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}

bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2) {
    sprite1.setScale(scale1,scale1);
    sprite2.setScale(scale2,scale2);
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}
