//
// Created by User on 16.06.2023.
//

#include "../Headers/Game.h"

void Game::initWindow(const int & w,const int & h) {
    this->window.create(sf::VideoMode(w, h), "Game 4", sf::Style::Close | sf::Style::Titlebar);
    this->window.setFramerateLimit(60);
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
Game::Game(const int & w,const int & h) {
    initWindow(w,h);
    initPlayer();
}

const sf::RenderWindow &Game::getWindow() const {
    return this->window;
}

void Game::render() {
    //Clear the old frame
    this->window.clear();

    //Render stuff

    this->renderPlayer();

    //Render stuff to the window
    this->window.display();
}

void Game::renderPlayer() {
    this->player->render(this->window);
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
    updatePlayer();
}

void Game::updatePlayer() {
this->player->update();
}

