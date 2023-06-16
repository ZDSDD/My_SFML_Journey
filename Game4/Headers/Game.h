//
// Created by User on 16.06.2023.
//

#ifndef GAME4_GAME_H
#define GAME4_GAME_H

#include "../stdafx.h"
#include "../Headers/Player.h"
class Game {
private:
    sf::RenderWindow window;

    sf::Event ev;

    Player *player;

    void initWindow(const int & w,const int & h);
    void initPlayer();

public:
    Game(const int & w = 800,const int & h = 600);

    virtual ~Game();

    //Functions
    const sf::RenderWindow &getWindow()const;
    void render();
    void renderPlayer();
    void update();
    void updatePlayer();
};


#endif //GAME4_GAME_H
