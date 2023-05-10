//
// Created by User on 09.05.2023.
//

#ifndef GAME2_SWAGBALL_H
#define GAME2_SWAGBALL_H

#include <SFML/Graphics.hpp>

enum SwagBallTypes{
    Default = 0,
    Damaging,
    Healing,
    NROFTYPES
};

class SwagBall {
private:
    sf::CircleShape shape;
    int type;
    void initShape(sf::RenderWindow & window);


public:
    SwagBall(sf::RenderWindow & window, int type);
    virtual ~SwagBall();

    const sf::CircleShape& getShape()const;
    const int & getType()const;
    //Functions
    void update();
    void render(sf::RenderTarget& target);
};


#endif //GAME2_SWAGBALL_H
