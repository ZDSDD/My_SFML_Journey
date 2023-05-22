//
// Created by User on 21.05.2023.
//

#ifndef GAME3_ENEMY_H
#define GAME3_ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy {
private:
    sf::CircleShape shape;
    int type;
    int hp;
    int hpMax;
    int damage;
    int points;
    float speed;

    void initShape();
    void initVariables();
public:
    Enemy(float pos_x, float pos_y, float speed = 1.f);
    virtual ~Enemy();


    //Accesors
    sf::FloatRect  getBounds();
    //Functions
    void update();
    void render(sf::RenderTarget & target);
};


#endif //GAME3_ENEMY_H
