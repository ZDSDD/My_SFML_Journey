//
// Created by User on 09.05.2023.
//

#ifndef GAME2_SWAGBALL_H
#define GAME2_SWAGBALL_H

#include <SFML/Graphics.hpp>

class SwagBall {
private:
    sf::CircleShape shape;
    void initShape(sf::RenderWindow & window);
public:
    SwagBall(sf::RenderWindow & window);
    virtual ~SwagBall();

    const sf::CircleShape& getShape()const;

    //Functions
    void update();
    void render(sf::RenderTarget& target);
};


#endif //GAME2_SWAGBALL_H
