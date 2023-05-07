//
// Created by User on 07.05.2023.
//

#ifndef CREATINGWINDOW_GAME_H
#define CREATINGWINDOW_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/*
    Class that acts as the game engine.
    Wrapper class.
*/

class Game {
private:
    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //private functions
    void initVariables();
    void initWindow();

public:
    //Constructors  / Destructors
    Game();
    virtual ~Game();

    //Accessors
    [[nodiscard]] bool isRunning()const;


    //Functions
    void pollEvents();
    void update();
    void render();
};


#endif //CREATINGWINDOW_GAME_H
