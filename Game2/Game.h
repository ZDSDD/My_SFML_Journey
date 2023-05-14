//
// Created by User on 09.05.2023.
//

#ifndef GAME2_GAME_H
#define GAME2_GAME_H

#include <vector>

#include "Player.h"
#include "SwagBall.h"
#include <iostream>
#include <sstream>
class Game {
private:
    sf::VideoMode videoMode;
    sf::RenderWindow *window;
    sf::Event event;

    Player player;
    std::vector<SwagBall> swagBalls;

    int points;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;
    bool endGame;

    sf::Font font;
    sf::Text guiText;
    sf::Text endGameText;

    void initVariables();

    void initFont();

    void initText();

    void initWindow();

public:
    Game();

    ~Game();

    //Accessors
    const bool& getEndGame() const;

    //Modifiers

    //Functions
    [[nodiscard]] bool running() const;

    void pollEvents();

    void spawnSwagBalls();

    void update();

    void updateCollision();

    void render();

    void updateGui();

    void updatePlayer();

    void renderGui(sf::RenderTarget &target);

    int randomizeType() const;
};


#endif //GAME2_GAME_H
