//
// Created by User on 23.06.2023.
//

#ifndef FLAPPY_COLLISION_HPP
#define FLAPPY_COLLISION_HPP


class Collision {
public:
    Collision();

    static bool CheckSpriteCollision(const sf::Sprite & sprite1, const sf::Sprite & sprite2);
    static bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
private:
};


#endif //FLAPPY_COLLISION_HPP
