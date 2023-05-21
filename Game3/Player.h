//
// Created by User on 14.05.2023.
//

#ifndef GAME3_PLAYER_H
#define GAME3_PLAYER_H

#include <Sfml/Graphics.hpp>

class Player {
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;
    float attackCooldown;
    float attackCooldownMax;
    //Private functions

    void initTexture();
    void initSprite();
    void initVariables();
public:
    Player();

    virtual ~Player();

    ///     ACCESSORS    ///
    const sf::Vector2f & getPos() const;
    bool canAttack();

    ///     Functions     ////

    void move(float dirX, float dirY);

    void updateAttack();

    void update();

    void render(sf::RenderTarget &renderTarget);
};


#endif //GAME3_PLAYER_H
