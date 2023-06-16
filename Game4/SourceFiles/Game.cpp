//
// Created by User on 16.06.2023.
//

#include "../Headers/Game.h"

void Game::initWindow() {
    this->window.create(sf::VideoMode(800, 600), "Game 4", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(1);
}

void Game::initPlayer() {
    if(this->player) {
        this->player = new Player();
    }

}

//DESTRUCTOR
Game::~Game() {
    delete this->player;
}
//CONSTRUCTOR
Game::Game() {
    initWindow();
    initPlayer();
}

const sf::RenderWindow &Game::getWindow() const {
    return this->window;
}

void Game::render() {
    //Clear the old frame
    this->window.clear(sf::Color(rand()%255,rand()%255,rand()%255,rand()%200));

    //Render stuff


    //Render stuff to the window
    this->window.display();
}

void Game::update() {

    //Polling events
    while (this->window.pollEvent(this->ev)) {
        if (this->ev.type == sf::Event::Closed) {
            this->window.close();
        } else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape) {
            this->window.close();
        }
    }
    void updatePlayer();
}

void Game::updatePlayer() {

}

