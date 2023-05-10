//
// Created by User on 09.05.2023.
//

#ifndef GAME2_PLAYER_H
#define GAME2_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::RectangleShape shape;
    float movementSpeed;
    int hp;
    int hpMax;

    //PRIVATE FUNCTIONS
    void initVariables();
    void initShape();

public:
    //CONSTRUCTOR & DESTRUCTOR
    Player(float x = 0.5f, float y = 0.5f);
    virtual ~Player();

    //ACCESSORS
    const sf::RectangleShape& getShape()const { return this->shape; }
    const int & getHp()const { return this->hp; }
    const int & getHpMax()const { return this->hpMax; }

    //FUNCTIONS
    void takeDamage(const int &dmg);
    void takeHeal(const int &heal);
    void update(const sf::RenderTarget* target);
    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};


#endif //GAME2_PLAYER_H
