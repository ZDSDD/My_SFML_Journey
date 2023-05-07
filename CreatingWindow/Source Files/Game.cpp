//
// Created by User on 07.05.2023.
//

#include "Game.h"

///Private functions
void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "My first game",sf::Style::Titlebar | sf::Style::Close);
}

///Constructors
Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

///accessors
bool Game::isRunning() const {
    return this->window->isOpen();
}


///Public functions
void Game::pollEvents() {
    while(this->window->pollEvent(this->ev)) {
        switch (ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    /*
     * @return void
     * - Clear old frame
     * - Render objects
     * - display frame in window
     * */

    this->window->clear(sf::Color(255,0,0,255));

    //draw game objects

    this->window->display();
}


