//
// Created by User on 14.05.2023.
//

#ifndef GAME3_GAME_H
#define GAME3_GAME_H

#include <Sfml/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include <map>
#include <vector>
#include "Bullet.h"
#include "Enemy.h"

class Game {
private:

    sf::RenderWindow *window;
    sf::Clock clock;

    float dt{0.f};

    float dtMultiplier{62.5f};
    //Resources
    std::map<std::string, sf::Texture *> textures;
    std::vector<Bullet *> bullets;
    //Player
    Player *player;

    //Player GUI
    sf::RectangleShape playerHpBar;
    sf::RectangleShape playerHpBarBack;

    //Enemies
    float spawnTimer;
    float timerMax;
    std::vector<Enemy *> enemies;
    //Systems
    unsigned points;
    //GUI
    sf::Font font;
    sf::Text pointText;
    sf::Text gameOverText;

    //World
    sf::Sprite worldBackground;
    sf::Texture backgroundTexture;

    //Private functions
    void initGUI();

    void initWindow();

    void initPlayer();

    void initEnemies();

    void initTextures();

    void initWorld();

    void initSystem();

public:



    Game();

    virtual ~Game();

    void run();

    void updatePollEvents();

    void updateInput();

    void updateBullet();

    void updateEnemies();

    void updateCombat();

    void updateWorld();

    void updateCollision();

    void updateGUI();

    void renderGUI();

    void update();

    void render();

    void renderWorld();


};


#endif //GAME3_GAME_H
