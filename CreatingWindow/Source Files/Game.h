//
// Created by User on 07.05.2023.
//

#ifndef CREATINGWINDOW_GAME_H
#define CREATINGWINDOW_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
/*
    Class that acts as the game engine.
    Wrapper class.
*/

class Game {
private:
    //Variables
    //Window
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    //Resources
    sf::Font font;

    //Text
    sf::Text uiText;

    //Game logic
    bool endGame;
    unsigned points;
    int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;

    //Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    //private functions
    void initVariables();

    void initWindow();

    void initEnemies();

    void initFonts();

    void initText();

public:
    //Constructors  / Destructors
    Game();

    virtual ~Game();

    //Accessors
    [[nodiscard]] bool isRunning() const;

    bool getEndGame() const;

    //Functions
    void spawnEnemy();

    void pollEvents();

    void updateMousePositions();

    void updateText();

    void updateEnemies();

    void update();

    void renderEnemies(sf::RenderTarget &target);

    void renderText(sf::RenderTarget &target) const;

    void render();

    void showPoints() const;

    void ShowHealth() const;
};


#endif //CREATINGWINDOW_GAME_H
