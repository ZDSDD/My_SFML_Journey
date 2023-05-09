//
// Created by User on 09.05.2023.
//

#ifndef GAME2_PLAYER_H
#define GAME2_PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    sf::RectangleShape shape;

    void initVariables();

    void initShape();

    float movementSpeed;
    int hp;
    int hpMax;
    int points;

public:
    Player(float x = 0.5f, float y = 0.5f);
    virtual ~Player();

    const sf::RectangleShape& getShape()const;

    bool checkCollision()const;
    void update(const sf::RenderTarget* target);
    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};


#endif //GAME2_PLAYER_H
