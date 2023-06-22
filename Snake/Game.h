//
// Created by User on 21.06.2023.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <valarray>
#include "../../Flappy/predefined.h"

class Game {
private:
    //  WINDOW  //
    int height, width;
    int cell_size;
    sf::RenderWindow * renderWindow;
    sf::View view;
private:
    //  SNAKE //
    struct point2d{
        int x;
        int y;
        bool operator == (const point2d & point2d) const;
        bool operator != (const point2d & point2d) const;
    };
    enum Direction{
        null,
        Up,
        Down,
        Left,
        Right
    } currentDirection,newDirection;

    sf::Texture snakeTexture;
    sf::Sprite snakeSprite;
    std::deque<point2d> snakeDeque;   //  STORES ALL CORDS OF SNAKE, EASY HEAD AND TAIL ACCESS
private:
    //  FRUIT   //

    point2d fruit;
    sf::Texture fruitTexture;
    sf::Sprite fruitSprite;

    void spawnFruit();
private:
    //   TIMER    //
    sf::Clock clock;
    float timer;
    float delay;
private:
    //  MAP //
    sf::Sprite mapSprite;
    sf::Texture mapTexture;
private:
    void initTextures();

    void initSprite();

public:
    explicit Game(int height = 30, int width = 30);

    virtual ~Game();

public:
    void run(); //GAME LOOP HERE

private:
    void update();  //UPDATE EVERYTHING BEFORE RENDER

    void updatePollEvents();

    void updateSnake(); //MOVE SNAKE AND CHECK IF COLLIDES

    void updateTime();  //UPDATES FOR CONSTANT TICS

/*  >Clear the window
    >Render map and snake
    >Display on the screen*/
    void render(sf::RenderTarget &renderTarget);

    void renderSnake(sf::RenderTarget & renderTarget);

    void renderFruit(sf::RenderTarget & renderTarget);

    void renderMap(sf::RenderTarget & renderTarget);

    bool CheckCollision(point2d & point2D)const;

    void updatePlayerInput();




};


#endif //SNAKE_GAME_H
