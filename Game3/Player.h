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

    int hp;
    int hpMax;
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
    sf::FloatRect getBounds()const;
    const int & getHp()const { return hp; };
    const int & getHpMax()const { return hpMax; };


    ///     MODIFIERS       ////
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    void setHp(const int & value);
    void loseHp(const int & value);

    ///     Functions     ////

    void move(float dirX, float dirY);

    void updateAttack();

    void update();

    void render(sf::RenderTarget &renderTarget);
};


#endif //GAME3_PLAYER_H
