//
// Created by User on 09.05.2023.
//

#ifndef GAME2_GAME_H
#define GAME2_GAME_H

#include <vector>

#include "Player.h"
#include "SwagBall.h"

class Game {
private:
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    sf::Event event;

    Player player;
    std::vector<SwagBall> swagBalls;

    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;
    bool endGame;

    void initVariables();

    void initWindow();

public:
    Game();

    ~Game();

    //Accessors

    //Modifiers

    //Functions
    [[nodiscard]] bool running() const;

    void pollEvents();

    void spawnSwagBalls();

    void update();

    void updateCollision();

    void render();
};


#endif //GAME2_GAME_H
